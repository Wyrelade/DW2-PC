#!/usr/bin/env python3
"""Fail when game code under src/ pulls in assembly.

Game code must be C. Allowed:
  * PsyQ library code: src/main/psyq.c, src/stag1000/stag1000_libpress.c
    (INCLUDE_ASM / INCLUDE_RODATA of the split library asm).
  * The crt0 startup, hand asm in the original: ASM_SOURCE("src/main/asm/crt0", ...)
    and the .s files in src/main/asm/crt0/.
  * stag0000 D_800634A8: cc1's string pool for the stag0000 .data pointer tables.
    It goes away when those tables become C (.data split, issue #6).

Usage: python3 tools/check_asm_guard.py   (exit 1 on a violation)
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

PSYQ_FILES = {"src/main/psyq.c", "src/stag1000/stag1000_libpress.c"}
CRT0_DIR = "src/main/asm/crt0"
ALLOWED = {
    ("src/stag0000/stag0000_4668.c", "INCLUDE_RODATA", "D_800634A8"),
}
MACRO = re.compile(r"\b(INCLUDE_ASM|INCLUDE_RODATA|ASM_SOURCE)\s*\(\s*\"([^\"]*)\"\s*,\s*(\w+)\s*\)")


def main():
    bad = []
    src = os.path.join(ROOT, "src")
    for dirpath, _dirs, files in os.walk(src):
        for name in sorted(files):
            path = os.path.relpath(os.path.join(dirpath, name), ROOT).replace("\\", "/")
            if name.endswith((".s", ".S")):
                if os.path.dirname(path) != CRT0_DIR:
                    bad.append("%s: assembly file in src/" % path)
                continue
            if not name.endswith((".c", ".h")):
                continue
            with open(os.path.join(ROOT, path), encoding="latin-1") as f:
                for n, line in enumerate(f, 1):
                    for m in MACRO.finditer(line):
                        kind, folder, sym = m.groups()
                        if path in PSYQ_FILES and kind in ("INCLUDE_ASM", "INCLUDE_RODATA"):
                            continue
                        if kind == "ASM_SOURCE" and folder == CRT0_DIR:
                            continue
                        if (path, kind, sym) in ALLOWED:
                            continue
                        bad.append("%s:%d: %s(%s) in game code" % (path, n, kind, sym))
    for b in bad:
        print(b)
    if bad:
        print("asm guard: %d violation(s). Game code must be C (see tools/check_asm_guard.py)." % len(bad))
        return 1
    print("asm guard: OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
