#!/usr/bin/env python3
"""Build and verify the DW2 USA executable (SLUS_011.93).

Single-exe relink. Two kinds of translation unit:

  * asm data/rodata/header (asm/USA/**/*.s outside nonmatchings/) -> assembled
    straight with mips-linux-gnu-as.
  * C source (src/**/*.c) -> preprocess (mingw gcc -E) -> PSY-Q cc1 -> maspsx ->
    mips-linux-gnu-as. A c file's INCLUDE_ASM stubs pull the per-function
    nonmatchings .s in through the assembler, so nonmatchings/ is never
    assembled on its own.

Then link with the splat linker script plus the auto symbol file, objcopy to a
raw image, and check the SHA-1 against the retail target. Prints
"build/USA/out/SLUS_011.93: OK" on success.

The 7 stage overlays (AAA/3.PRO/STAGxxxx.PRO, all loaded at 0x80063360) are
split into asm/USA/stagxxxx + src/stagxxxx and linked one by one with their
own linker script; each prints "build/USA/out/STAGxxxx.PRO: OK".
--overlays-only builds just those.
"""
import argparse
import hashlib
import os
import platform
import re
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

CONFIG = {
    "target": "dumps/disc/SLUS_011.93",
    "target_sha1": "e55ed5bf354def07f0cbf4e1fb7fb5f99204f220",
    "asm_dir": "asm/USA",
    "src_dir": "src",
    "ld_script": "linkers/USA/main.ld",
    "sym_script": "linkers/USA/undefined_syms_auto.main.txt",
    "build_dir": "build/USA",
    "elf": "build/USA/main.elf",
    "out": "build/USA/out/SLUS_011.93",
    "include": "include",
    "entry": "Sys_Start",   # crt0 entry (PS-X EXE header pc0)
}

# Stage overlays: (unit, retail SHA-1). Target dumps/disc/AAA/3.PRO/<UNIT>.PRO,
# linker scripts linkers/USA/<unit>.ld + undefined_{funcs,syms}_auto.<unit>.txt.
OVERLAYS = [
    ("stag0000", "ff37a7c6bb5fa96da2887731fac1ea52c6033a6d"),
    ("stag1000", "ba428a84fbe2b2084ca6e12fd88067790e43fd7f"),
    ("stag1100", "24b68697c3b018fc1795d0ea57c845b92e298612"),
    ("stag2000", "9e8f8a1f1eb3aacda2b4a3492abce26264ee9029"),
    ("stag3000", "6aaf6f61f2af3d9b7379764912cf09b42c2af52b"),
    ("stag3500", "79b8c96b9ea1c11b45ebc223eeb14bf5a5f54812"),
    ("stag4000", "2623a98843a5943269af3c06fc20cb54a3bd23ca"),
]
OVERLAY_DIRS = [u for u, _ in OVERLAYS]
# Units whose .rodata comes from their C objects (issue #5 E2.2): cc1 emits the jump
# tables of decompiled functions, every other item is an INCLUDE_RODATA of the per-item
# split tools/rodata_own.py writes to asm/USA/<unit>/rodata/. The unit's splat rodata
# file is then assembled empty and no jump table is bound by the normalizer.
RODATA_IN_C = {"main", "stag0000", "stag1100", "stag2000", "stag3000", "stag3500", "stag4000"}
# Retail sizes that are not a multiple of 4 (the linker pads the image).
OVERLAY_SIZES = {"stag2000": 0xDBEE}


def _in_units(path, root, units):
    """True when path (under root) lies in one of the given top-level unit dirs."""
    if units is None:
        return True
    top = os.path.relpath(path, root).replace("\\", "/").split("/")[0]
    return top in units

# Flags for hand-written asm TUs (data/rodata/header). These are already final
# machine asm; -O0 keeps as from reordering.
AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-O0", "-G0",
]

# Flags for the C pipeline, minus the scratch-only -DNON_MATCHING / -DSKIP_ASM
# (we want the INCLUDE_ASM stubs to actually pull their nonmatchings in) and the
# scoring-only -fverbose-asm / -dp comment annotations.
CPP_FLAGS = [
    "-E", "-P", "-undef", "-nostdinc",
    "-D_LANGUAGE_C", "-DVER_USA",
    "-I", "include", "-I", "build/USA",
]
CC1_FLAGS = [
    "-O2", "-mips1", "-mcpu=3000", "-w",
    "-funsigned-char", "-fpeephole", "-ffunction-cse",
    "-fpcc-struct-return", "-fcommon",
    "-msoft-float", "-mgas", "-fgnu-linker",
    "-gcoff", "-G0", "-quiet",
]
MASPSX_FLAGS = ["--aspsx-version=2.77", "--run-assembler"]
# as flags maspsx forwards to the assembler when it runs it.
MASPSX_AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-G0", "-I", "include",
]
# Per-unit small-data threshold (issue #5 Phase D). Retail main game code was built
# with -G8 (gp-relative scalars up to 8 bytes); the stage overlays with -G0. Keys are a
# unit or a unit/file.c; the file entry wins. psyq.c stays -G0: it is INCLUDE_ASM
# library code, and with -G > 0 cc1 writes C function text after the top-level asm,
# which would move its one C stub.
UNIT_G = {"main": "8", "main/psyq.c": "0", "main/156C.c": "0"}
UNIT_ASPSX = {"main": "2.81"}
# Extra cc1 flags per unit or unit/file (one flag set per translation unit).
UNIT_CC1 = {
    # the game function after libpress in STAG1000 is its own object, built without split addresses
    "stag1000/stag1000_tail.c": ["-mno-split-addresses"],
    # event flag reset unit before Mem_TestBit (func_80021D60, Save_ClearEventFlags)
    "main/12550.c": ["-fno-cse-skip-blocks", "-fno-strength-reduce"],
}
AS_G_OVERRIDE = None    # --as-g: one -G for every unit (flag experiments)


def unit_flags(unit, name=None):
    """(cc1 flags, maspsx flags, maspsx as flags) for a src/ unit (and file name)."""
    g = UNIT_G.get("%s/%s" % (unit, name), UNIT_G.get(unit, "0"))
    if AS_G_OVERRIDE is not None:
        g = AS_G_OVERRIDE
    extra = UNIT_CC1.get("%s/%s" % (unit, name), UNIT_CC1.get(unit, []))
    if g == "0":
        return CC1_FLAGS + extra, MASPSX_FLAGS, MASPSX_AS_FLAGS
    cc1 = CC1_FLAGS[:CC1_FLAGS.index("-G0")] + ["-G" + g] + CC1_FLAGS[CC1_FLAGS.index("-G0") + 1:] + extra
    as_flags = [("-G" + g) if f == "-G0" else f for f in MASPSX_AS_FLAGS]
    # maspsx decides gp-relative access like aspsx: only for symbols this file defines
    # (.comm/.lcomm/.sdata), and it hands GNU as -G0. Tentative definitions stay COMMON
    # (--use-comm-section), so they bind to the data asm's labels instead of taking space.
    flags = [f for f in MASPSX_FLAGS if not f.startswith("--aspsx-version")]
    flags.append("--aspsx-version=" + UNIT_ASPSX.get(unit, "2.77"))
    return cc1, flags + ["--use-comm-section"], as_flags


def binutils_dir():
    env = os.environ.get("DW2_BINUTILS")
    if env:
        return env
    system = platform.system()
    if system == "Windows":
        return os.path.join(ROOT, "tools", "windows", "binutils")
    if system == "Darwin":
        return os.path.join(ROOT, "tools", "macos", "binutils")
    return os.path.join(ROOT, "tools", "linux", "binutils")


def tool(name):
    d = binutils_dir()
    exe = os.path.join(d, "mips-linux-gnu-%s.exe" % name)
    if not os.path.exists(exe):
        exe = os.path.join(d, "mips-linux-gnu-%s" % name)
    return exe


def cpp_bin():
    env = os.environ.get("DW2_CPP")
    if env:
        return env
    if platform.system() == "Windows":
        return os.path.join(ROOT, "tools", "windows", "gcc-win", "bin", "gcc.exe")
    return "cpp"


def cc1_bin():
    env = os.environ.get("DW2_CC1")
    if env:
        return env
    if platform.system() == "Windows":
        return os.path.join(ROOT, "tools", "windows", "gcc-psx", "CC1PSX.EXE")
    return os.path.join(ROOT, "tools", "linux", "gcc-2.8.1-psx", "cc1")


def maspsx_py():
    return os.path.join(ROOT, "tools", "maspsx", "maspsx.py")


try:
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import asm_normalizer
except Exception:               # optional: build works without it (pure no-op)
    asm_normalizer = None


def normalize_ctx(as_bin, maspsx_flags=None, maspsx_as_flags=None):
    """Toolchain paths the .s normalizer needs. No function names or unit paths
    are baked into the normalizer; they come from the manifest and from here."""
    return {
        "python": sys.executable,
        "maspsx_py": maspsx_py(),
        "maspsx_flags": maspsx_flags or MASPSX_FLAGS,
        "as_bin": as_bin,
        "maspsx_as_flags": maspsx_as_flags or MASPSX_AS_FLAGS,
        "objdump": tool("objdump"),
        "asm_root": os.path.join(ROOT, CONFIG["asm_dir"]),
        "run": lambda cmd: (lambda r: (r.returncode, r.stdout, r.stderr))(
            subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           stdin=subprocess.DEVNULL)),
    }


def run(cmd, stdin_devnull=False):
    kwargs = dict(cwd=ROOT, capture_output=True, text=True)
    if stdin_devnull:
        kwargs["stdin"] = subprocess.DEVNULL
    r = subprocess.run(cmd, **kwargs)
    if r.returncode != 0:
        sys.stderr.write(" ".join(cmd) + "\n")
        sys.stderr.write(r.stdout)
        sys.stderr.write(r.stderr)
    return r.returncode


def sha1(path):
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for block in iter(lambda: f.read(1 << 16), b""):
            h.update(block)
    return h.hexdigest()


def obj_for(src):
    """build/USA/<relpath of src under ROOT>.o"""
    rel = os.path.relpath(src, ROOT)
    obj = os.path.join(ROOT, CONFIG["build_dir"], rel + ".o")
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    return obj


def assemble_asm(as_bin, units=None):
    """Assemble every .s under asm/USA except the per-function nonmatchings/
    (those are pulled in by the C files' INCLUDE_ASM stubs)."""
    asm_root = os.path.join(ROOT, CONFIG["asm_dir"])
    count = 0
    for u in sorted(RODATA_IN_C):
        if units is None or u in units:
            subprocess.run([sys.executable, os.path.join(ROOT, "tools", "rodata_own.py"), u, "--split"],
                           cwd=ROOT, capture_output=True, text=True, check=True)
    for dirpath, _dirs, files in os.walk(asm_root):
        parts = os.path.relpath(dirpath, asm_root).replace("\\", "/").split("/")
        if "nonmatchings" in parts or (len(parts) > 1 and parts[1] == "rodata"):
            continue
        if dirpath != asm_root and not _in_units(dirpath, asm_root, units):
            continue
        for name in files:
            if not name.endswith(".s"):
                continue
            src = os.path.join(dirpath, name)
            obj = obj_for(src)
            if parts[0] in RODATA_IN_C and name.endswith(".rodata.s"):
                # the C objects carry this unit's .rodata; keep the object the
                # linker script names, empty or with the PsyQ items only
                import rodata_own
                cwd = os.getcwd()
                os.chdir(ROOT)
                try:
                    keep = rodata_own.keep_asm_text(parts[0])
                finally:
                    os.chdir(cwd)
                stub = obj[:-2] + ".keep.s"
                with open(stub, "w") as f:
                    f.write(keep or '.section .rodata, "a"\n')
                src = stub
            cmd = [as_bin] + AS_FLAGS + ["-I", CONFIG["include"], "-o", obj, src]
            if run(cmd) != 0:
                print("BUILD FAILED: assembling %s" % os.path.relpath(src, ROOT))
                return -1
            count += 1
    return count


def strict_manifest(manifest, strict):
    """--strict filter. asm (default): functions that only match through rewrites are
    INCLUDE_ASM (their C sits under #ifdef NORMALIZED), so only the entries without
    passes stay: they bind literals and jump tables to the split .rodata (link layout).
    off: the full manifest, C for every function (byte-perfect C build for modding).
    flavors: only the alternate cc1 flag sets. none: no manifest at all."""
    if strict == "none":
        return {}
    if strict == "asm":
        return dict((k, v) for k, v in manifest.items() if not v.get("passes"))
    if strict == "flavors":
        out = {}
        for k, v in manifest.items():
            keep = [p for p in v.get("passes", []) if p in asm_normalizer.ALT_FLAVORS]
            if keep:
                out[k] = dict(v, passes=keep)
        return out
    return manifest


def compile_c(cpp, cc1, as_bin, skip_asm=False, units=None, strict="off"):
    """Preprocess + cc1 + maspsx(->as) every .c under src/.

    skip_asm defines SKIP_ASM so INCLUDE_ASM stubs expand to nothing (see
    include/include_asm.h): the object then holds only the hand-decompiled C
    functions -- this is the objdiff "current" object, whose matched functions
    are all that differ from the full "target" object built without it."""
    cpp_flags = CPP_FLAGS + (["-DSKIP_ASM"] if skip_asm else []) + (
        [] if strict == "asm" else ["-DNORMALIZED"])
    src_root = os.path.join(ROOT, CONFIG["src_dir"])
    if not os.path.isdir(src_root):
        return 0
    count = 0
    for dirpath, _dirs, files in os.walk(src_root):
        if dirpath != src_root and not _in_units(dirpath, src_root, units):
            continue
        for name in files:
            if not name.endswith(".c"):
                continue
            src = os.path.join(dirpath, name)
            obj = obj_for(src)
            stem = obj[:-2]  # drop trailing ".o"
            i_file = stem + ".i"
            s_file = stem + ".s"
            unit = os.path.relpath(dirpath, src_root).replace("\\", "/").split("/")[0]
            cc1_flags, maspsx_flags, maspsx_as_flags = unit_flags(unit, name)

            # with -G > 0 cc1 writes function text after file-scope asm, so INCLUDE_ASM
            # goes inside a function maspsx strips (include/include_asm.h)
            in_func = ["-DINCLUDE_ASM_IN_FUNC"] if cc1_flags is not CC1_FLAGS and "-G0" not in cc1_flags else []
            if run([cpp] + cpp_flags + in_func + ["-o", i_file, src]) != 0:
                print("BUILD FAILED: preprocessing %s" % os.path.relpath(src, ROOT))
                return -1
            if run([cc1] + cc1_flags + ["-o", s_file, i_file]) != 0:
                print("BUILD FAILED: cc1 %s" % os.path.relpath(src, ROOT))
                return -1

            # Deterministic, target-guided .s normalization for the manifest's
            # functions (between cc1 and the assembler). No-op if the normalizer
            # or its manifest is absent. The linked SHA-1 is the ground gate.
            if asm_normalizer is not None:
                ctx = normalize_ctx(as_bin, maspsx_flags, maspsx_as_flags)
                # The stage overlays share one address range, so two overlays can
                # hold a func_XXXXXXXX of the same name: look targets up in this
                # unit's asm tree first (callees in the main exe still resolve).
                unit_asm = os.path.join(ctx["asm_root"],
                                        os.path.relpath(dirpath, src_root).replace("\\", "/").split("/")[0])
                if dirpath != src_root and os.path.isdir(unit_asm):
                    ctx["asm_unit_root"] = unit_asm
                # Functions from translation units retail built without split
                # addresses are taken from a second cc1 compile of the same file.
                manifest = asm_normalizer.load_manifest()
                # "unit:func" keys (stage overlays, whose func names can repeat across
                # overlays) apply only to that unit; plain keys apply everywhere.
                manifest = dict((k.split(":", 1)[1] if ":" in k else k, v)
                                for k, v in manifest.items()
                                if ":" not in k or k.split(":", 1)[0] == unit)
                manifest = strict_manifest(manifest, strict)
                if unit in RODATA_IN_C:
                    # tables of decompiled functions stay where cc1 put them
                    manifest = dict((k, v) for k, v in manifest.items() if v.get("passes"))
                ctx["alt_s"] = {}
                for flavor in asm_normalizer.alt_flavors(manifest):
                    alt_file = "%s.%s.s" % (stem, flavor)
                    if run([cc1] + cc1_flags + asm_normalizer.ALT_FLAVORS[flavor]
                           + ["-o", alt_file, i_file]) != 0:
                        print("BUILD FAILED: cc1 (%s) %s"
                              % (flavor, os.path.relpath(src, ROOT)))
                        return -1
                    ctx["alt_s"][flavor] = alt_file
                try:
                    rewrote = asm_normalizer.normalize_s(s_file, ctx, manifest)
                except Exception as e:
                    print("BUILD FAILED: normalize %s: %s"
                          % (os.path.relpath(s_file, ROOT), e))
                    return -1
                if rewrote:
                    print("  normalized: %s" % ", ".join(rewrote))

            cmd = [sys.executable, maspsx_py()] + maspsx_flags + [
                "--gnu-as-path=%s" % as_bin,
            ] + maspsx_as_flags + ["-o", obj, s_file]
            if run(cmd, stdin_devnull=True) != 0:
                print("BUILD FAILED: maspsx/as %s" % os.path.relpath(src, ROOT))
                return -1
            count += 1
    return count


def main():
    ap = argparse.ArgumentParser(description="Build/verify DW2 SLUS_011.93.")
    ap.add_argument("--skip-asm", action="store_true",
                    help="define SKIP_ASM: drop INCLUDE_ASM stubs (objdiff base object)")
    ap.add_argument("--objects-only", action="store_true",
                    help="assemble/compile objects but do not link/objcopy/verify")
    ap.add_argument("--skip-verify", action="store_true",
                    help="link + objcopy but do not SHA-1 check against the retail exe "
                         "(the retail exe is not present in CI)")
    ap.add_argument("--overlays-only", action="store_true",
                    help="build, link and verify only the stage overlays")
    ap.add_argument("--strict", choices=("asm", "off", "flavors", "none"), default="asm",
                    help="asm (default): natural C, INCLUDE_ASM for functions that need asm "
                         "rewrites (byte-perfect, no rewrite passes); off: C everywhere "
                         "(-DNORMALIZED) + full asm_normalizer manifest (byte-perfect C build); "
                         "flavors: -DNORMALIZED, alternate cc1 flag sets only; none: "
                         "-DNORMALIZED, base flags only. flavors/none are for match accounting.")
    ap.add_argument("--build-dir", help="object/output dir (default build/USA)")
    ap.add_argument("--units", help="comma list of src/ units to build (objects only)")
    ap.add_argument("--cc1-extra", default="",
                    help="extra cc1 flags for every C unit (flag-set experiments, e.g. -G8)")
    ap.add_argument("--tu-flags", action="append", default=[],
                    help="UNIT[/FILE.c]=FLAGS: extra cc1 flags for one unit or file (experiments)")
    ap.add_argument("--as-g", help="-G value cc1/maspsx/as use for every unit instead of UNIT_G")
    ap.add_argument("--shift-test", action="store_true",
                    help="define SHIFT_TEST: SHIFT_TEST_PAD() pads main and STAG1000 so every "
                         "address moves (no SHA check; boot it to prove the build is shiftable)")
    args = ap.parse_args()
    if args.shift_test:
        CPP_FLAGS.append("-DSHIFT_TEST")
        args.skip_verify = True
    if args.build_dir:
        CONFIG["build_dir"] = args.build_dir
    if args.cc1_extra:
        CC1_FLAGS.extend(args.cc1_extra.split())
    for tf in args.tu_flags:
        k, v = tf.split("=", 1)
        UNIT_CC1[k] = v.split()
    if args.as_g is not None:
        global AS_G_OVERRIDE
        AS_G_OVERRIDE = args.as_g
    units = OVERLAY_DIRS if args.overlays_only else None
    if args.units:
        units = args.units.split(",")

    as_bin = tool("as")
    ld_bin = tool("ld")
    objcopy_bin = tool("objcopy")

    needed = [("as", as_bin)]
    if not args.objects_only:
        needed += [("ld", ld_bin), ("objcopy", objcopy_bin)]
    for name, path in needed:
        if not os.path.exists(path):
            print("BUILD FAILED: mips-linux-gnu-%s not found at %s" % (name, path))
            print("Set DW2_BINUTILS to a directory holding the mips binutils.")
            return 1

    cpp, cc1 = cpp_bin(), cc1_bin()
    for name, path in (("cpp", cpp), ("cc1", cc1)):
        if os.path.sep in path and not os.path.exists(path):
            print("BUILD FAILED: %s not found at %s" % (name, path))
            print("Set DW2_CPP / DW2_CC1 to override.")
            return 1

    # maspsx passes an absolute --gnu-as-path to subprocess.Popen; a relative
    # one fails to launch under Windows CreateProcess.
    as_abs = os.path.abspath(as_bin)

    if extract_bins(args.skip_verify or args.objects_only) != 0:
        return 1
    n_asm = assemble_asm(as_bin, units)
    if n_asm < 0:
        return 1
    n_c = compile_c(cpp, cc1, as_abs, skip_asm=args.skip_asm, units=units,
                    strict=args.strict)
    if n_c < 0:
        return 1
    if n_asm == 0 and n_c == 0:
        print("BUILD FAILED: no .s or .c sources found")
        return 1

    if args.objects_only:
        print("objects built (asm=%d, c=%d)" % (n_asm, n_c))
        return 0

    # Main and the overlays refer to each other by name: link main with the retail numbers
    # for its overlay references, the overlays against that main.elf, then main again with
    # the overlay ELFs' values. Main's layout does not depend on those values, so two links
    # settle (and a build that moves code still resolves every cross reference).
    rc = 0
    if not args.overlays_only and link_main(ld_bin, objcopy_bin, True, quiet=True) != 0:
        return 1
    main_syms = main_exports()
    base = main_ovl_base()
    for unit, want in OVERLAYS:
        if link_overlay(unit, want, ld_bin, objcopy_bin, args.skip_verify, main_syms, base) != 0:
            rc = 1
    if not args.overlays_only and link_main(ld_bin, objcopy_bin, args.skip_verify,
                                            ovl_syms=overlay_exports()) != 0:
        rc = 1
    return rc


def elf_globals(elf, defined_only=False):
    """{name: value} of the global symbols of an ELF; defined_only drops the absolute ones
    (linker script assignments such as the auto lists)."""
    out = subprocess.run([tool("objdump"), "-t", elf], cwd=ROOT, capture_output=True, text=True).stdout
    return dict((m.group(3), int(m.group(1), 16)) for m in
                re.finditer(r"^([0-9a-f]{8}) g.{6} (\S+)\s+[0-9a-f]+\s+(\S+)$", out, re.M)
                if not (defined_only and m.group(2) == "*ABS*"))


def write_sym_script(path, syms):
    with open(os.path.join(ROOT, path), "w") as f:
        for n in sorted(syms):
            f.write("%s = 0x%08X;\n" % (n, syms[n]))


def auto_scripts(unit, drop):
    """The splat undefined_{syms,funcs}_auto lists of a unit as PROVIDE()s, without the names
    in `drop` (those come from another ELF of this build instead of the retail numbers).
    splat also lists names the asm defines as labels; a plain assignment would override the
    label with the retail number, PROVIDE only fills in names no object defines."""
    paths = []
    for kind in ("syms", "funcs"):
        p = "linkers/USA/undefined_%s_auto.%s.txt" % (kind, unit)
        if not os.path.exists(os.path.join(ROOT, p)):
            continue
        q = os.path.join(CONFIG["build_dir"], "undefined_%s_auto.%s.txt" % (kind, unit))
        with open(os.path.join(ROOT, q), "w") as f:
            for line in open(os.path.join(ROOT, p)):
                m = re.match(r"\s*(\w+)\s*=\s*([^;]+);", line)
                if m and m.group(1) not in drop:
                    f.write("PROVIDE(%s = %s);\n" % (m.group(1), m.group(2).strip()))
        paths.append(q)
    return paths


# splat's per-segment linker symbols; every image has its own
SEGMENT_SYM = re.compile(r"^(_gp|\w+_(ROM_START|ROM_END|VRAM|VRAM_END|"
                         r"(TEXT|DATA|RODATA|BSS)_(START|END|SIZE)))$")


def main_exports():
    """Main's global symbols for the overlay links (overlays refer to main by name, so they
    follow main when it moves). Main's own references into the overlay area are left out."""
    elf = os.path.join(ROOT, CONFIG["elf"])
    if not os.path.exists(elf):
        return {}
    g = elf_globals(elf)
    base = g.get("Ovl_LoadArea", 0x80063360)
    return dict((n, v) for n, v in g.items()
                if not SEGMENT_SYM.match(n) and not base <= v < 0x80200000)


def main_ovl_base():
    """Ovl_LoadArea (where Ovl_Load reads the overlays) in this build's main.elf, or None."""
    elf = os.path.join(ROOT, CONFIG["elf"])
    return elf_globals(elf).get("Ovl_LoadArea") if os.path.exists(elf) else None


def overlay_exports():
    """Values of the overlay symbols main refers to (Task_DescTable rows, overlay functions
    main calls), taken from the overlay ELFs of this build."""
    want = set()
    for kind in ("syms", "funcs"):
        p = os.path.join(ROOT, "linkers/USA/undefined_%s_auto.main.txt" % kind)
        if os.path.exists(p):
            want.update(m.group(1) for m in re.finditer(r"^\s*(\w+)\s*=", open(p).read(), re.M))
    got = {}
    for unit, _sha in OVERLAYS:
        elf = os.path.join(ROOT, CONFIG["build_dir"], unit + ".elf")
        if os.path.exists(elf):
            for n, v in elf_globals(elf, defined_only=True).items():
                if n in want:
                    got[n] = v
    return got


def link_overlay(unit, want, ld_bin, objcopy_bin, skip_verify, main_syms=None, base=None):
    """Link one stage overlay with its own splat script; skipped when not split yet.
    main_syms: main's symbols from this build's main.elf (instead of the retail numbers).
    base: main's Ovl_LoadArea in this build; the overlay is linked to run from there."""
    ld_script = "linkers/USA/%s.ld" % unit
    if not os.path.exists(os.path.join(ROOT, ld_script)):
        return 0
    if base is not None:
        text, n = re.subn(r"(\.%s )0x[0-9A-Fa-f]+( :)" % unit, r"\g<1>0x%08X\g<2>" % base,
                          open(os.path.join(ROOT, ld_script)).read())
        assert n == 1, "%s: overlay section address not found" % ld_script
        ld_script = os.path.join(CONFIG["build_dir"], "%s.link.ld" % unit)
        open(os.path.join(ROOT, ld_script), "w").write(text)
    elf = os.path.join(CONFIG["build_dir"], unit + ".elf")
    out = os.path.join(os.path.dirname(CONFIG["out"]), unit.upper() + ".PRO").replace("\\", "/")
    cmd = [ld_bin, "-EL"]
    if main_syms:
        p = os.path.join(CONFIG["build_dir"], "main_syms.%s.ld" % unit)
        write_sym_script(p, main_syms)
        cmd += ["-T", p]
    for p in auto_scripts(unit, set(main_syms or ())):
        cmd += ["-T", p]
    cmd += ["-T", ld_script, "-Map", os.path.join(CONFIG["build_dir"], unit + ".map"),
            "-o", elf, "--no-check-sections"]
    if run(cmd) != 0:
        print("BUILD FAILED: linking %s" % unit)
        return 1
    os.makedirs(os.path.join(ROOT, os.path.dirname(out)), exist_ok=True)
    if run([objcopy_bin, "-O", "binary", elf, out]) != 0:
        print("BUILD FAILED: objcopy %s" % unit)
        return 1
    if patch_image_bytes(unit, elf, os.path.join(ROOT, out)) != 0:
        return 1
    if skip_verify:
        print("%s: built (verify skipped)" % out)
        return 0
    # STAG2000.PRO is 0xDBEE bytes: drop the linker's zero ALIGN(4) pad after
    # the last .short so the image has the retail length.
    path = os.path.join(ROOT, out)
    img = open(path, "rb").read()
    size = OVERLAY_SIZES.get(unit)
    if size and len(img) > size and not img[size:].strip(b"\x00"):
        open(path, "wb").write(img[:size])
    elif size and len(img) < size:
        # splat drops the odd zero tail (.short 0) from the data asm: pad it back
        open(path, "wb").write(img + b"\x00" * (size - len(img)))
    got = sha1(path)
    if got != want:
        print("%s: MISMATCH" % out)
        print("  built  %s" % got)
        print("  want   %s" % want)
        return 1
    print("%s: OK" % out)
    return 0


def assemble_bins(ld_script, as_bin):
    """Assemble the splat `bin` subsegments a linker script names (build/USA/assets/X.bin.o).

    The bytes are opaque game content extracted from the disc by splat into assets/ (not
    committed). Each object holds the file in .data under a global label named after the
    segment, so code can refer to the start of the area by that name."""
    for line in open(os.path.join(ROOT, ld_script)).read().split("\n"):
        line = line.strip()
        if not (line.startswith("build/") and ".bin.o(" in line):
            continue
        obj = line[:line.index("(")]
        name = os.path.basename(obj)[:-len(".bin.o")]
        src = os.path.join(ROOT, "assets", name + ".bin")
        if not os.path.exists(src):
            print("BUILD FAILED: %s missing (run splat on the yaml to extract it)" % os.path.relpath(src, ROOT))
            return 1
        stub = os.path.join(ROOT, obj[:-2] + ".s")
        os.makedirs(os.path.dirname(stub), exist_ok=True)
        with open(stub, "w") as f:
            f.write('.section .data, "wa"\n.global %s\n%s:\n.incbin "%s"\n'
                    % (name, name, src.replace("\\", "/")))
        if run([as_bin] + AS_FLAGS + ["-o", os.path.join(ROOT, obj), stub]) != 0:
            print("BUILD FAILED: assembling %s" % os.path.relpath(stub, ROOT))
            return 1
    return 0


def extract_bins(allow_missing):
    """Write the INCLUDE_BIN assets that configs/USA/include_bin.txt lists.

    Each line is `asset source offset size`: the bytes come from the user's disc files
    (not committed). When a source file is absent and allow_missing is set (a build
    without a disc, e.g. the progress CI, which does not link), the asset is zero-filled
    so the objects still assemble."""
    listing = os.path.join(ROOT, "configs/USA/include_bin.txt")
    if not os.path.exists(listing):
        return 0
    for line in open(listing):
        line = line.split("#", 1)[0].split()
        if not line:
            continue
        asset, source, offset, size = line[0], line[1], int(line[2], 0), int(line[3], 0)
        src = os.path.join(ROOT, source)
        if os.path.exists(src):
            with open(src, "rb") as f:
                f.seek(offset)
                data = f.read(size)
            if len(data) != size:
                print("BUILD FAILED: %s is too short for %s" % (source, asset))
                return 1
        elif allow_missing:
            print("  warning: %s missing, %s zero-filled" % (source, asset))
            data = bytes(size)
        else:
            print("BUILD FAILED: %s missing (needed for %s)" % (source, asset))
            return 1
        dst = os.path.join(ROOT, asset)
        if os.path.exists(dst) and open(dst, "rb").read() == data:
            continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as f:
            f.write(data)
    return 0


def patch_image_bytes(unit, elf, image):
    """Copy the padding bytes configs/USA/image_bytes.txt lists for this unit from the disc
    into the linked image, at their symbol's place (a C .bss is zero; retail's padding is not)."""
    listing = os.path.join(ROOT, "configs/USA/image_bytes.txt")
    if not os.path.exists(listing):
        return 0
    rows = [l.split("#", 1)[0].split() for l in open(listing)]
    rows = [r for r in rows if r and r[0] == unit]
    if not rows:
        return 0
    syms = elf_globals(elf)
    base = syms.get(unit + "_VRAM")
    data = bytearray(open(image, "rb").read())
    for _unit, sym, size, source, offset in rows:
        size, offset = int(size, 0), int(offset, 0)
        src = os.path.join(ROOT, source)
        if not os.path.exists(src):
            print("  warning: %s missing, %s left zero" % (source, sym))
            continue
        if sym not in syms or base is None:
            print("BUILD FAILED: %s: symbol %s not in %s" % (unit, sym, elf))
            return 1
        at = syms[sym] - base
        with open(src, "rb") as f:
            f.seek(offset)
            data[at:at + size] = f.read(size)
    open(image, "wb").write(bytes(data))
    return 0


def gp_label():
    """Name of the main symbol at the yaml's gp_value (sym.main.txt), or None."""
    yml = open(os.path.join(ROOT, "configs/USA/SLUS_011.93.yaml")).read()
    m = re.search(r"^\s*gp_value:\s*(0x[0-9A-Fa-f]+)", yml, re.M)
    if not m:
        return None
    gp = int(m.group(1), 16)
    for line in open(os.path.join(ROOT, "configs/USA/sym.main.txt")):
        s = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if s and int(s.group(2), 16) == gp:
            return s.group(1)
    return None


def fix_exe_header(path, syms):
    """Fill the PS-X EXE header fields that depend on the link: initial pc (entry symbol),
    text address and text size. splat's header.s holds the retail numbers; computing them
    keeps a build that moves code bootable (the retail build gets the same values)."""
    img = bytearray(open(path, "rb").read())
    struct.pack_into("<I", img, 0x10, syms[CONFIG["entry"]])
    struct.pack_into("<I", img, 0x18, syms["main_VRAM"])
    struct.pack_into("<I", img, 0x1C, len(img) - 0x800)
    open(path, "wb").write(bytes(img))


def link_main(ld_bin, objcopy_bin, skip_verify, ovl_syms=None, quiet=False):
    """ovl_syms: values of the overlay symbols main refers to, from this build's overlay
    ELFs (second link); None links with the retail numbers of the splat auto lists."""
    # Link: symbol script first so the auto hardware/kernel syms resolve.
    os.makedirs(os.path.join(ROOT, CONFIG["build_dir"]), exist_ok=True)
    ld_script = CONFIG["ld_script"]
    if assemble_bins(ld_script, tool("as")) != 0:
        return 1
    lines = open(os.path.join(ROOT, ld_script)).read().split("\n")
    if "main" in RODATA_IN_C:
        # game .rodata comes from the C objects; the asm rodata object keeps only the
        # PsyQ items, which retail places after the game units: link it last
        asm = [l for l in lines if "/asm/USA/main/data/" in l and l.strip().endswith(".rodata.s.o(.rodata);")]
        assert len(asm) == 1, asm
        lines.remove(asm[0])
        last = max(i for i, l in enumerate(lines) if l.strip().endswith(".c.o(.rodata);"))
        lines.insert(last + 1, asm[0])
    # splat writes _gp as the yaml's gp_value; retail $gp is the address of the first small
    # data object, so bind it to that label and let it move with the data
    gp_sym = gp_label()
    lines = [("    _gp = %s;" % gp_sym) if gp_sym and l.strip().startswith("_gp = 0x") else l
             for l in lines]
    ld_script = os.path.join(CONFIG["build_dir"], "main.link.ld")
    open(os.path.join(ROOT, ld_script), "w").write("\n".join(lines))
    cmd = [ld_bin, "-EL"]
    if ovl_syms:
        p = os.path.join(CONFIG["build_dir"], "ovl_syms.main.ld")
        write_sym_script(p, ovl_syms)
        cmd += ["-T", p]
    for p in auto_scripts("main", set(ovl_syms or ())):
        cmd += ["-T", p]
    cmd += [
        "-T", ld_script,
        "-Map", os.path.join(CONFIG["build_dir"], "main.map"),
        "-o", CONFIG["elf"],
        "--no-check-sections",
    ]
    if run(cmd) != 0:
        print("BUILD FAILED: linking")
        return 1

    # Objcopy to a raw image.
    os.makedirs(os.path.join(ROOT, os.path.dirname(CONFIG["out"])), exist_ok=True)
    if run([objcopy_bin, "-O", "binary", CONFIG["elf"], CONFIG["out"]]) != 0:
        print("BUILD FAILED: objcopy")
        return 1
    fix_exe_header(os.path.join(ROOT, CONFIG["out"]), elf_globals(os.path.join(ROOT, CONFIG["elf"])))

    if skip_verify:
        if not quiet:
            print("%s: built (verify skipped)" % CONFIG["out"])
        return 0

    # Verify against the retail target.
    got = sha1(os.path.join(ROOT, CONFIG["out"]))
    want = CONFIG["target_sha1"]
    if got != want:
        target = os.path.join(ROOT, CONFIG["target"])
        target_sha = sha1(target) if os.path.exists(target) else "(target missing)"
        print("%s: MISMATCH" % CONFIG["out"])
        print("  built  %s" % got)
        print("  want   %s" % want)
        print("  target %s" % target_sha)
        return 1

    print("%s: OK" % CONFIG["out"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
