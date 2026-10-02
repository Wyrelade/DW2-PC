#!/usr/bin/env python3
"""Rename struct fields (and struct types) with the compiler as the type checker.

    python tools/rename_field.py --batch fields.txt

fields.txt lines:
    STRUCT old_field new_field      rename a field inside `typedef struct {...} STRUCT;`
    type OldType NewType            rename a typedef name (whole word, everywhere)
    # comments

Field names repeat across structs (field_4 is in hundreds of them), so a text replace cannot
tell which accesses belong to STRUCT. This tool renames the field in STRUCT's definition in
include/main/156C.h, compiles src/main/156C.c and every stage overlay source that uses the
main header (src/stagXXXX/*.c; cpp + cc1, with and without -DNON_MATCHING), and fixes exactly the lines the compiler reports as "structure has no member named `old'",
repeating until the file compiles clean. A batch must not rename the same old field name in
two structs (the error would not say which one it means).

Names never change bytes; run `python tools/build_dw2.py` afterwards.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
HDR = os.path.join(ROOT, "include", "main", "156C.h")
SRC = os.path.join(ROOT, "src", "main", "187C.c")
MAIN_SRCS = [os.path.join(ROOT, "src", "main", f) for f in ("156C.c", "187C.c")]


def sources():
    """Main game sources plus the overlay sources (they include main/156C.h through their headers)."""
    import glob
    out = list(MAIN_SRCS)
    for c in sorted(glob.glob(os.path.join(ROOT, "src", "stag*", "*.c"))):
        out.append(c)
    return out


def overlay_headers():
    import glob
    return sorted(glob.glob(os.path.join(ROOT, "include", "stag*", "*.h")))
IDENT = re.compile(r"[A-Za-z_]\w*$")


def read(p):
    return open(p, encoding="latin1", newline="").read()


def write(p, t):
    with open(p, "w", encoding="latin1", newline="") as f:
        f.write(t)


def struct_span(text, name):
    """(start, end) of the `typedef struct|union {...} name;` block."""
    m = re.search(r"\}\s*%s\s*;" % re.escape(name), text)
    if not m:
        sys.exit("struct %s not found in %s" % (name, HDR))
    depth, i = 0, m.start()
    while i >= 0:
        c = text[i]
        if c == "}":
            depth += 1
        elif c == "{":
            depth -= 1
            if depth == 0:
                break
        i -= 1
    j = text.rfind("typedef", 0, i)
    return j, m.end()


def compile_errors(extra):
    import build_dw2 as B
    d = tempfile.mkdtemp()
    try:
        i = os.path.join(d, "x.i")
        flags = [x for x in B.CPP_FLAGS if x != "-P"]  # keep line markers to map errors back
        r = subprocess.run([B.cpp_bin()] + flags + extra + ["-o", i, SRC], capture_output=True, text=True)
        if r.returncode:
            sys.exit("cpp failed:\n" + r.stderr[-2000:])
        r = subprocess.run([B.cc1_bin()] + B.CC1_FLAGS + ["-o", os.path.join(d, "x.s"), i],
                           capture_output=True, text=True)
    finally:
        shutil.rmtree(d, ignore_errors=True)
    # cc1 reports source file:line through cpp's line markers
    errs = []
    for l in r.stderr.split("\n"):
        m = re.match(r"(.*?):(\d+): (.*)$", l)
        if m and "warning" not in m.group(3):
            errs.append((m.group(1), int(m.group(2)), m.group(3)))
    return r.returncode, errs


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--batch", required=True)
    a = ap.parse_args()
    fields, types = [], []
    for line in open(a.batch, encoding="utf-8"):
        p = line.split("#", 1)[0].split()
        if not p:
            continue
        if len(p) != 3 or not all(IDENT.match(x) for x in p):
            sys.exit("bad line: %s" % line.strip())
        (types if p[0] == "type" else fields).append(tuple(p[1:] if p[0] == "type" else p))
    olds = [o for _s, o, _n in fields]
    dup = {o for o in olds if olds.count(o) > 1}
    if dup:
        sys.exit("same old field in two structs of one batch: %s" % ", ".join(sorted(dup)))
    hdr = read(HDR)
    for s, old, new in fields:
        a0, b0 = struct_span(hdr, s)
        blk = hdr[a0:b0]
        if not re.search(r"\b%s\b" % re.escape(old), blk):
            sys.exit("%s has no field %s" % (s, old))
        if re.search(r"\b%s\b" % re.escape(new), blk):
            sys.exit("%s already has a field %s" % (s, new))
        hdr = hdr[:a0] + re.sub(r"\b%s\b" % re.escape(old), new, blk) + hdr[b0:]
    write(HDR, hdr)
    ren = {o: n for _s, o, n in fields}
    fixed = 0
    global SRC
    for SRC, flags in [(c, f) for c in sources() for f in ([], ["-DNON_MATCHING"])]:
        for _round in range(50):
            rc, errs = compile_errors(flags)
            miss = [(f, n, e) for f, n, e in errs if "has no member named" in e]
            other = [(f, n, e) for f, n, e in errs if "has no member named" not in e]
            if not miss:
                if rc and other:
                    sys.exit("compile errors not caused by the renames:\n" +
                             "\n".join("%s:%d: %s" % x for x in other[:20]))
                break
            src = read(SRC).split("\n")
            done = False
            ambiguous = []
            for f, n, e in miss:
                m = re.search(r"named `(\w+)'", e)
                if not m or m.group(1) not in ren or not re.sub(r"[\\/]+", "/", f).endswith(os.path.relpath(SRC, ROOT).replace("\\", "/")):
                    sys.exit("unexpected: %s:%d: %s" % (f, n, e))
                old = m.group(1)
                occ = list(re.finditer(r"(->|\.)(\s*)%s\b" % re.escape(old), src[n - 1]))
                if len(occ) == 1:
                    q = occ[0]
                    src[n - 1] = src[n - 1][:q.start()] + q.group(1) + q.group(2) + ren[old] + src[n - 1][q.end():]
                    done = True
                    fixed += 1
                elif len(occ) > 1 and (n, old) not in ambiguous:
                    ambiguous.append((n, old))
            write(SRC, "\n".join(src))
            for n, old in ambiguous:
                # several accesses of `old` on one line, of different structs: rename one
                # occurrence at a time and keep the choice that clears the line
                base = read(SRC).split("\n")
                occ = list(re.finditer(r"(->|\.)(\s*)%s\b" % re.escape(old), base[n - 1]))
                ok = False
                pat_o = r"(->|\.)(\s*)%s\b" % re.escape(old)
                cands = [re.sub(pat_o, lambda z: z.group(1) + z.group(2) + ren[old], base[n - 1])]
                cands += [base[n - 1][:q.start()] + q.group(1) + q.group(2) + ren[old] + base[n - 1][q.end():]
                          for q in occ]
                for cand in cands:
                    trial = list(base)
                    trial[n - 1] = cand
                    write(SRC, "\n".join(trial))
                    _rc, errs2 = compile_errors(flags)
                    bad = [x for x in errs2 if x[1] == n and "has no member named" in x[2]
                           and re.search(r"named `(%s|%s)'" % (re.escape(old), re.escape(ren[old])), x[2])]
                    wrong = [x for x in errs2 if x[1] == n and ren[old] in x[2]]
                    if not wrong and len(bad) < len([x for x in miss if x[1] == n]):
                        ok = True
                        done = True
                        fixed += 1
                        break
                if not ok:
                    write(SRC, "\n".join(base))
                    sys.exit("could not resolve line %d (%s)" % (n, old))
            src = read(SRC).split("\n")
            if not done:
                sys.exit("could not fix: " + "; ".join("%s:%d: %s" % x for x in miss[:5]))
            write(SRC, "\n".join(src))
        else:
            sys.exit("did not converge")
    if types:
        pat = re.compile(r"\b(%s)\b" % "|".join(re.escape(o) for o, _n in types))
        tmap = dict(types)
        for p in [HDR] + sources() + overlay_headers():
            write(p, pat.sub(lambda q: tmap[q.group(1)], read(p)))
    print("renamed %d fields (%d access lines fixed), %d types" % (len(fields), fixed, len(types)))


if __name__ == "__main__":
    main()
