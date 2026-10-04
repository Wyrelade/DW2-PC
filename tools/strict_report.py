#!/usr/bin/env python3
"""Per-function match accounting under the strict standard (issue #5).

Builds three object sets (objects only, no link):
  target   build/strict/target   full build, byte-identical to retail
  none     build/strict/none     --strict none     (base cc1 flags only)
  flavors  build/strict/flavors  --strict flavors  (alt flag sets, no rewrites)
and compares every function symbol of the decompiled objects against the target
(objdump words + relocation type/symbol per offset; section-relative addends are
ignored because rodata layout shifts between builds).

Classes per function:
  natural     matches with the base flags, no asm_normalizer involvement
  flavor      matches only with a per-function alternate cc1 flag set
  normalized  matches only through target-guided asm rewrites (not a match)
  asm         INCLUDE_ASM stub (not decompiled)
  asm_source  ASM_SOURCE / hand asm (not decompiled C)
PsyQ functions (configs/USA/psyq_funcs.txt, one name per line, overlay ones as
unit:name) are
reported separately and never counted.

Writes tools/match_status.json and prints a summary per unit.
  --reuse   skip the builds, compare existing objects."""
import glob
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import build_dw2 as B  # noqa: E402

DIRS = {"target": "build/strict/target", "none": "build/strict/none",
        "flavors": "build/strict/flavors"}
BUILDS = {"target": [], "none": ["--strict", "none"], "flavors": ["--strict", "flavors"]}
FUNC_DEF = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\([^;{}]*\)[ \t]*(?:\n[ \t]+[^\n{}()]*;[ \t]*)*\s*\{", re.M)


def build(tag):
    r = subprocess.run([sys.executable, "tools/build_dw2.py", "--objects-only", "--skip-verify",
                        "--build-dir", DIRS[tag]] + BUILDS[tag], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("build %s failed:\n%s%s" % (tag, r.stdout[-3000:], r.stderr[-3000:]))


def funcs_of(obj):
    """{name: [word+reloc keys]} for every function symbol in .text.

    MIPS ELF32 relocations are REL: the addend sits in the instruction word. For
    relocations against a section symbol (.text local jumps / static calls,
    .rodata jump tables and constants) the field is masked, and a .text target
    is replaced by (function, offset in function), so layout shifts between the
    builds do not count as mismatches."""
    syms = subprocess.run([B.tool("objdump"), "-t", obj], capture_output=True, text=True).stdout
    starts = sorted((int(a, 16), n) for a, n in
                    re.findall(r"^([0-9a-f]+)\s.*\sF\s+\.text\s+[0-9a-f]+\s+(\S+)$", syms, re.M))
    fsyms = {n for _a, n in starts}
    # retail jlabels (.L<address>): absolute address -> (function, offset) via the symbol map
    # (a jlabel is a jump-table target inside the function that jumps to it)
    def label_where(name, func):
        fa = func_vram(unit_of(obj), func)
        return "%s+%x" % (func, int(name[2:], 16) - fa) if fa else name

    def where(off):
        best = None
        for a, n in starts:
            if a <= off:
                best = (n, off - a)
        return "%s+%x" % best if best else "?%x" % off

    out = subprocess.run([B.tool("objdump"), "-d", "-r", "-z", "--section=.text", obj],
                         capture_output=True, text=True).stdout
    res, cur = {}, None
    for line in out.splitlines():
        m = re.match(r"^([0-9a-f]+) <([^>]+)>:$", line)
        if m:
            # cc1 line-number (LMn) and .L labels split the listing; only function
            # symbols start a new function
            if m.group(2) in fsyms:
                cur = res.setdefault(m.group(2), [])
                curname = m.group(2)
            continue
        if cur is None:
            continue
        m = re.match(r"^\s+[0-9a-f]+:\s+([0-9a-f]{8})\s", line)
        if m:
            cur.append([int(m.group(1), 16), ""])
            continue
        m = re.match(r"^\s+[0-9a-f]+:\s+(R_MIPS_\w+)\s+(\S+)", line)
        if m and cur:
            typ, sym = m.group(1), m.group(2)
            w = cur[-1][0]
            if typ == "R_MIPS_26" and re.match(r"^\.L[0-9A-F]{8}$", sym) and not (w & 0x3FFFFFF):
                # retail jlabels are global symbols: a j to one relocates against the
                # label, ours against .text; compare the target location instead
                cur[-1][0] = w & ~0x3FFFFFF
                sym = ".text:" + label_where(sym, curname)
            elif sym.startswith("."):
                if typ == "R_MIPS_26":
                    tgt = (w & 0x3FFFFFF) << 2
                    cur[-1][0] = w & ~0x3FFFFFF
                    sym = sym + ":" + (where(tgt) if sym == ".text" else "")
                elif typ in ("R_MIPS_HI16", "R_MIPS_LO16", "R_MIPS_GPREL16"):
                    cur[-1][0] = w & ~0xFFFF
            cur[-1][1] += "%s:%s;" % (typ, sym)
            if not sym.startswith(".") and typ in ("R_MIPS_HI16", "R_MIPS_LO16", "R_MIPS_GPREL16", "R_MIPS_32"):
                cur[-1].append((typ, sym))
            elif typ == "R_MIPS_PC16" and re.match(r"^\.L[0-9A-F]{8}$", sym):
                cur[-1].append((typ, sym))
    addr = sym_addrs(unit_of(obj))
    for name, v in res.items():
        resolve_data_relocs(v, addr, rodata_range(unit_of(obj)), name)
    return {k: [(w[0], w[1]) for w in v] for k, v in res.items()}


_SYMS = {}
_VRAM = {}


def func_vram(unit, func):
    """Retail address of a function, from the first instruction comment of its asm file."""
    if (unit, func) not in _VRAM:
        fs = glob.glob(os.path.join(ROOT, "asm", "USA", unit, "**", func + ".s"), recursive=True)
        m = re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ", open(fs[0], encoding="latin-1").read()) if fs else None
        _VRAM[(unit, func)] = int(m.group(1), 16) if m else None
    return _VRAM[(unit, func)]


def unit_of(obj):
    m = re.search(r"[\\/]src[\\/]([^\\/]+)[\\/]", obj)
    return m.group(1) if m else "main"


def sym_addrs(unit):
    """{name: address} from configs/USA/sym.<unit>.txt and the splat undefined_*_auto lists."""
    if unit not in _SYMS:
        d = {}
        for p in ("configs/USA/sym.%s.txt" % unit, "linkers/USA/undefined_syms_auto.%s.txt" % unit,
                  "linkers/USA/undefined_funcs_auto.%s.txt" % unit):
            p = os.path.join(ROOT, p)
            if os.path.exists(p):
                for n, a in re.findall(r"^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)", open(p).read(), re.M):
                    d.setdefault(n, int(a, 16))
        _SYMS[unit] = d
    return _SYMS[unit]


_RODATA = {}


def rodata_range(unit):
    """[lo, hi) vram of the unit's split .rodata subsegment (from its splat yaml)."""
    if unit not in _RODATA:
        y = "SLUS_011.93.yaml" if unit == "main" else unit + ".yaml"
        t = open(os.path.join(ROOT, "configs", "USA", y)).read()
        seg = re.search(r"- name: %s\b.*?start: (0x[0-9A-Fa-f]+).*?vram: (0x[0-9A-Fa-f]+)"
                        r"(.*?)(?:\n  - |\Z)" % unit, t, re.S)
        rng = (0, 0)
        if seg:
            start, vram = int(seg.group(1), 16), int(seg.group(2), 16)
            subs = re.findall(r"- \[(0x[0-9A-Fa-f]+), (\w+)", seg.group(3))
            for i, (off, kind) in enumerate(subs[:-1]):
                if kind == "rodata":
                    rng = (vram + int(off, 16) - start, vram + int(subs[i + 1][0], 16) - start)
        _RODATA[unit] = rng
    return _RODATA[unit]


def resolve_data_relocs(v, addr, rodata=(0, 0), fname=None):
    """Data references compare by the address they resolve to, not by symbol name:
    splat names every referenced address (D_8005F774) while C reaches the same
    word as a struct field (D_8005F770 + 4). Linked bytes are identical either way.
    HI16 takes its low half from the next LO16 against the same symbol (MIPS ABI AHL)."""
    def base(sym):
        if sym in addr:
            return addr[sym]
        m = re.match(r"^(?:D|jtbl|func)_([0-9A-F]{8})$", sym)
        return int(m.group(1), 16) if m else None

    orig = [w[0] for w in v]
    for i, w in enumerate(v):
        if len(w) < 3:
            continue
        typ, sym = w[2]
        if typ == "R_MIPS_PC16":
            # a branch to a global jump-table label (splat jlabel) keeps a reloc in the
            # retail-asm object; resolve it to the branch offset the C object encodes
            fa = base(fname) if fname else None
            if fa is not None:
                off = ((int(sym[2:], 16) - (fa + 4 * i + 4)) >> 2) & 0xFFFF
                w[0] = (w[0] & ~0xFFFF) | off
                w[1] = w[1].replace("%s:%s;" % (typ, sym), "")
            continue
        b = base(sym)
        if b is None:
            continue
        word = w[0]
        if typ == "R_MIPS_HI16":
            lo = next((x for x in v[i + 1:] if len(x) > 2 and x[2] == ("R_MIPS_LO16", sym)), None)
            if lo is None:
                continue
            slo = lo[0] & 0xFFFF
            slo = slo - 0x10000 if slo & 0x8000 else slo
            full = (b + ((word & 0xFFFF) << 16) + slo) & 0xFFFFFFFF
            w[0] = word & ~0xFFFF
        elif typ in ("R_MIPS_LO16", "R_MIPS_GPREL16"):
            slo = word & 0xFFFF
            slo = slo - 0x10000 if slo & 0x8000 else slo
            # AHL: the high part of the addend sits in the paired HI16 (sym+0x8000 forms)
            hi = 0
            if typ == "R_MIPS_LO16":
                j = next((k for k in range(i - 1, -1, -1)
                          if len(v[k]) > 2 and v[k][2] == ("R_MIPS_HI16", sym)), None)
                if j is not None:
                    hi = (orig[j] & 0xFFFF) << 16
            full = (b + hi + slo) & 0xFFFFFFFF
            w[0] = word & ~0xFFFF
        else:
            full = (b + word) & 0xFFFFFFFF
            w[0] = 0
        # A literal or table in the split asm .rodata is the C object's own .rodata in a
        # base build (layout differs, bytes do not): compare it like a .rodata section reloc.
        key = "%s:.rodata;" % typ if rodata[0] <= full < rodata[1] else "%s:@%08x;" % (typ, full)
        w[1] = w[1].replace("%s:%s;" % (typ, sym), key)


def src_info():
    """{unit: {"c": set, "asm": set, "asm_source": set}} from src/<unit>/*.c."""
    info = {}
    for unit in sorted(os.listdir(os.path.join(ROOT, "src"))):
        d = os.path.join(ROOT, "src", unit)
        if not os.path.isdir(d):
            continue
        u = info.setdefault(unit, {"c": set(), "asm": set(), "asm_source": set()})
        for dp, _ds, fs in os.walk(d):
            for f in fs:
                if not f.endswith(".c"):
                    continue
                t = open(os.path.join(dp, f), encoding="latin-1").read()
                u["asm"] |= set(re.findall(r"^INCLUDE_ASM\([^,]*,\s*(\w+)\)", t, re.M))
                u["asm_source"] |= set(re.findall(r"^ASM_SOURCE\([^,]*,\s*(\w+)\)", t, re.M))
                u["c"] |= {m.group(1) for m in FUNC_DEF.finditer(t)} - {"if", "while", "for", "switch"}
    return info


def objs(tag, unit):
    d = os.path.join(ROOT, DIRS[tag], "src", unit)
    return sorted(os.path.join(dp, f) for dp, _ds, fs in os.walk(d) for f in fs if f.endswith(".c.o"))


def main():
    if "--reuse" not in sys.argv:
        for tag in DIRS:
            build(tag)
    psyq = set()
    pf = os.path.join(ROOT, "configs/USA/psyq_funcs.txt")
    if os.path.exists(pf):
        psyq = {l.split()[0] for l in open(pf) if l.strip() and not l.startswith("#")}
    status, summary = {}, {}
    for unit, si in src_info().items():
        tgt, fns = {}, {}
        for tag in DIRS:
            fns[tag] = {}
            for o in objs(tag, unit):
                fns[tag].update(funcs_of(o))
        tgt = fns["target"]
        for name in sorted(tgt):
            if name.startswith("D_"):
                continue  # code labels inside hand asm, not functions
            if name in si["asm_source"]:
                cls = "asm_source"
            elif name in si["asm"] and name not in si["c"]:
                cls = "asm"
            elif fns["none"].get(name) == tgt[name]:
                cls = "natural"
            elif fns["flavors"].get(name) == tgt[name]:
                cls = "flavor"
            else:
                cls = "normalized"
            key = name if unit == "main" else "%s:%s" % (unit, name)
            status[key] = cls
            grp = unit + ("/psyq" if key in psyq else "")
            summary.setdefault(grp, {}).setdefault(cls, 0)
            summary[grp][cls] += 1
    with open(os.path.join(ROOT, "tools/match_status.json"), "w") as f:
        json.dump(status, f, indent=1, sort_keys=True)
    cols = ("natural", "flavor", "normalized", "asm", "asm_source")
    print("%-14s %6s " % ("unit", "total") + " ".join("%10s" % c for c in cols))
    for grp in sorted(summary):
        s = summary[grp]
        print("%-14s %6d " % (grp, sum(s.values())) + " ".join("%10d" % s.get(c, 0) for c in cols))


if __name__ == "__main__":
    main()
