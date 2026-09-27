#!/usr/bin/env python3
"""Restore a hand-written assembly function as readable source.

    python tools/asm_restore.py LIB NAME [NAME...] [--doc "one line"]
    python tools/asm_restore.py --batch FILE        (lines: `LIB NAME [# doc]`)
    python tools/asm_restore.py --unit stag1000 LIB NAME   (a stage overlay: src/stag1000/asm/LIB)

Some functions were assembly in the original build (Psy-Q libapi BIOS stubs, libgte register
helpers, setjmp, exception handlers): no C compiles to them, so they are restored in their
source form instead. For each NAME this:
  1. reads the split asm/USA/main/nonmatchings/<unit>/NAME.s,
  2. writes src/main/asm/LIB/NAME.s: a header comment (C prototype from include/, the doc line),
     `glabel`/`endlabel`, one instruction per line without address/byte comments, the BIOS
     table call spelled out (`# B0(0x32)`), the alignment padding kept after `endlabel`,
  3. replaces `INCLUDE_ASM("<dir>", NAME);` in src/ with `ASM_SOURCE("src/main/asm/LIB", NAME);`.
ASM_SOURCE (include/include_asm.h) includes the file in place, so the function keeps its address,
and it is not skipped under SKIP_ASM and has no `nonmatching` marker: progress tools count it as
matched. Run `python tools/build_dw2.py` afterwards; the image must stay byte-identical.
"""
import argparse
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BYTES = re.compile(r"^\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+[0-9A-Fa-f]{8}\s*\*/\s?")


def split_file(name, unit="*"):
    hits = glob.glob(os.path.join(ROOT, "asm", "USA", unit, "nonmatchings", "*", name + ".s"))
    if len(hits) != 1:
        sys.exit("%s: expected one split .s, found %d" % (name, len(hits)))
    return hits[0]


def prototype(name):
    pat = re.compile(r"^[^\n;{}()]*\b%s\s*\([^;{}]*\)\s*;" % re.escape(name), re.M)
    for g in ("include/**/*.h", "src/**/*.c"):
        for p in glob.glob(os.path.join(ROOT, g), recursive=True):
            m = pat.search(open(p, encoding="latin1").read())
            if m:
                return re.sub(r"^\s*extern\s+", "", m.group(0).strip())
    return None


def restore(lib, name, doc, unit="main"):
    src = open(split_file(name, unit), encoding="latin1").read().replace("\r\n", "\n").split("\n")
    body, pad, state = [], [], 0
    for line in src:
        s = line.strip()
        if s.startswith("nonmatching ") or s.startswith("/* Handwritten"):
            continue
        if s.startswith("glabel "):
            state = 1
            body.append(s)
            continue
        if s.startswith("endlabel "):
            body.append(s)
            state = 2
            continue
        if state == 0 or not s:
            continue
        ins = BYTES.sub("", line).rstrip()
        ins = re.sub(r"\s*/\* handwritten instruction \*/", "", ins)
        if state == 2:
            pad.append(ins.strip())
            continue
        if re.match(r"\s*\.?L\w+:", ins):
            body.append(ins.strip())
            continue
        dslot = ins.startswith("  ") and not ins.startswith("   ")
        ins = re.sub(r"\s+", " ", ins.strip())
        mn, _, ops = ins.partition(" ")
        text = "    %s%-10s %s" % (" " if dslot else "", mn, ops)
        body.append(text.rstrip())
    # name the BIOS call: `li t2,0xA0/B0/C0` + `li t1,N` right next to the `jr/jalr t2`
    for k, line in enumerate(body):
        m = re.match(r"\s+addiu\s+\$t1, \$zero, (0x[0-9A-Fa-f]+)$", line)
        if not m:
            continue
        near = body[max(0, k - 2):k + 3]
        tab = [re.match(r"\s+addiu\s+\$t2, \$zero, 0x([ABC])0$", x) for x in near]
        tab = [x.group(1) for x in tab if x]
        if tab and any(re.match(r"\s+(jr|jalr)\s+\$t2$", x) for x in near):
            body[k] = "%-40s # %s0(0x%02X)" % (line, tab[0], int(m.group(1), 16))
    proto = prototype(name)
    head = ["/*", " * %s" % (proto or name + "()")]
    if doc:
        head.append(" * %s" % doc)
    head.append(" * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).")
    head.append(" */")
    out = head + [""] + body + [""]
    if pad:
        out += ["    # alignment padding up to the next function"] + ["    %s" % p for p in pad] + [""]
    d = os.path.join(ROOT, "src", unit, "asm", lib)
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, name + ".s"), "w", encoding="latin1", newline="\r\n") as f:
        f.write("\n".join(out))
    n = 0
    for p in glob.glob(os.path.join(ROOT, "src", unit, "**", "*.c"), recursive=True):
        t = open(p, encoding="latin1", newline="").read()
        t2_, k = re.subn(r'INCLUDE_ASM\("[^"]+",\s*%s\);' % re.escape(name),
                         'ASM_SOURCE("src/%s/asm/%s", %s);' % (unit, lib, name), t)
        if k:
            with open(p, "w", encoding="latin1", newline="") as f:
                f.write(t2_)
            n += k
    if n == 0:
        # already restored: only the source file was regenerated
        n = sum(len(re.findall(r'ASM_SOURCE\("[^"]+",\s*%s\);' % re.escape(name),
                               open(p, encoding="latin1").read()))
                for p in glob.glob(os.path.join(ROOT, "src", unit, "**", "*.c"), recursive=True))
    if n != 1:
        sys.exit("%s: replaced %d INCLUDE_ASM lines (want 1)" % (name, n))
    print("%s -> src/%s/asm/%s/%s.s" % (name, unit, lib, name))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("lib", nargs="?")
    ap.add_argument("names", nargs="*")
    ap.add_argument("--doc", default="")
    ap.add_argument("--batch")
    ap.add_argument("--unit", default="main", help="split unit (main, stag1000, ...)")
    a = ap.parse_args()
    jobs = []
    if a.batch:
        for line in open(a.batch, encoding="utf-8"):
            code, _, doc = line.partition("#")
            p = code.split()
            if len(p) == 2:
                jobs.append((p[0], p[1], doc.strip()))
    else:
        jobs = [(a.lib, n, a.doc) for n in a.names]
    for lib, name, doc in jobs:
        restore(lib, name, doc, a.unit)


if __name__ == "__main__":
    main()
