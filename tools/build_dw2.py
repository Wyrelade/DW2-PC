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
MASPSX_FLAGS = ["--aspsx-version=2.77", "--run-assembler", "--expand-div"]
# as flags maspsx forwards to the assembler when it runs it.
MASPSX_AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-G0", "-I", "include",
]


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


def normalize_ctx(as_bin):
    """Toolchain paths the .s normalizer needs. No function names or unit paths
    are baked into the normalizer; they come from the manifest and from here."""
    return {
        "python": sys.executable,
        "maspsx_py": maspsx_py(),
        "maspsx_flags": MASPSX_FLAGS,
        "as_bin": as_bin,
        "maspsx_as_flags": MASPSX_AS_FLAGS,
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
    for dirpath, _dirs, files in os.walk(asm_root):
        if "nonmatchings" in dirpath.replace("\\", "/").split("/"):
            continue
        if dirpath != asm_root and not _in_units(dirpath, asm_root, units):
            continue
        for name in files:
            if not name.endswith(".s"):
                continue
            src = os.path.join(dirpath, name)
            obj = obj_for(src)
            cmd = [as_bin] + AS_FLAGS + ["-I", CONFIG["include"], "-o", obj, src]
            if run(cmd) != 0:
                print("BUILD FAILED: assembling %s" % os.path.relpath(src, ROOT))
                return -1
            count += 1
    return count


def compile_c(cpp, cc1, as_bin, skip_asm=False, units=None):
    """Preprocess + cc1 + maspsx(->as) every .c under src/.

    skip_asm defines SKIP_ASM so INCLUDE_ASM stubs expand to nothing (see
    include/include_asm.h): the object then holds only the hand-decompiled C
    functions -- this is the objdiff "current" object, whose matched functions
    are all that differ from the full "target" object built without it."""
    cpp_flags = CPP_FLAGS + (["-DSKIP_ASM"] if skip_asm else [])
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

            if run([cpp] + cpp_flags + ["-o", i_file, src]) != 0:
                print("BUILD FAILED: preprocessing %s" % os.path.relpath(src, ROOT))
                return -1
            if run([cc1] + CC1_FLAGS + ["-o", s_file, i_file]) != 0:
                print("BUILD FAILED: cc1 %s" % os.path.relpath(src, ROOT))
                return -1

            # Deterministic, target-guided .s normalization for the manifest's
            # functions (between cc1 and the assembler). No-op if the normalizer
            # or its manifest is absent. The linked SHA-1 is the ground gate.
            if asm_normalizer is not None:
                ctx = normalize_ctx(as_bin)
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
                unit = os.path.relpath(dirpath, src_root).replace("\\", "/").split("/")[0]
                manifest = dict((k.split(":", 1)[1] if ":" in k else k, v)
                                for k, v in manifest.items()
                                if ":" not in k or k.split(":", 1)[0] == unit)
                ctx["alt_s"] = {}
                for flavor in asm_normalizer.alt_flavors(manifest):
                    alt_file = "%s.%s.s" % (stem, flavor)
                    if run([cc1] + CC1_FLAGS + asm_normalizer.ALT_FLAVORS[flavor]
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

            cmd = [sys.executable, maspsx_py()] + MASPSX_FLAGS + [
                "--gnu-as-path=%s" % as_bin,
            ] + MASPSX_AS_FLAGS + ["-o", obj, s_file]
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
    args = ap.parse_args()
    units = OVERLAY_DIRS if args.overlays_only else None

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

    n_asm = assemble_asm(as_bin, units)
    if n_asm < 0:
        return 1
    n_c = compile_c(cpp, cc1, as_abs, skip_asm=args.skip_asm, units=units)
    if n_c < 0:
        return 1
    if n_asm == 0 and n_c == 0:
        print("BUILD FAILED: no .s or .c sources found")
        return 1

    if args.objects_only:
        print("objects built (asm=%d, c=%d)" % (n_asm, n_c))
        return 0

    rc = 0 if args.overlays_only else link_main(ld_bin, objcopy_bin, args.skip_verify)
    for unit, want in OVERLAYS:
        if link_overlay(unit, want, ld_bin, objcopy_bin, args.skip_verify) != 0:
            rc = 1
    return rc


def link_overlay(unit, want, ld_bin, objcopy_bin, skip_verify):
    """Link one stage overlay with its own splat script; skipped when not split yet."""
    ld_script = "linkers/USA/%s.ld" % unit
    if not os.path.exists(os.path.join(ROOT, ld_script)):
        return 0
    elf = os.path.join(CONFIG["build_dir"], unit + ".elf")
    out = os.path.join(os.path.dirname(CONFIG["out"]), unit.upper() + ".PRO").replace("\\", "/")
    cmd = [ld_bin, "-EL"]
    for kind in ("syms", "funcs"):
        p = "linkers/USA/undefined_%s_auto.%s.txt" % (kind, unit)
        if os.path.exists(os.path.join(ROOT, p)):
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
    got = sha1(path)
    if got != want:
        print("%s: MISMATCH" % out)
        print("  built  %s" % got)
        print("  want   %s" % want)
        return 1
    print("%s: OK" % out)
    return 0


def link_main(ld_bin, objcopy_bin, skip_verify):
    # Link: symbol script first so the auto hardware/kernel syms resolve.
    os.makedirs(os.path.join(ROOT, CONFIG["build_dir"]), exist_ok=True)
    cmd = [
        ld_bin, "-EL",
        "-T", CONFIG["sym_script"],
        "-T", CONFIG["ld_script"],
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

    if skip_verify:
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
