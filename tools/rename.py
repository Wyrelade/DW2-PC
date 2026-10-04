#!/usr/bin/env python3
"""Give a function or data symbol its real name, everywhere, in one step.

    python tools/rename.py func_80032CD4 Text_SetToneAttr
    python tools/rename.py D_80061BF4 Snd_ToneHandlers
    python tools/rename.py OldName NewName          (fix an earlier name)
    python tools/rename.py --batch renames.txt      (lines: `old new`, `#` comments)
    python tools/rename.py --unit stag3000 func_8006AAA8 Btl_CalcDamage   (stage overlay symbol)

What it does:
  1. configs/USA/sym.main.txt: adds `NewName = 0xVA; // type:func` (or rewrites the line of an
     existing name), so a fresh splat split emits the new name.
  2. Rewrites the identifier (whole word) in src/, include/, the normalizer manifest,
     tools/difficult_functions and the split asm/ tree, and renames the function's
     asm/USA/main/nonmatchings/<unit>/<old>.s. The asm rewrite is exactly what a re-split with
     the new sym.main.txt would produce, without re-running splat.

Stage overlays (--unit stagXXXX): all overlays load at the same address, so their func_/D_ names
overlap each other and must never go into sym.main.txt. With --unit the name goes into
configs/USA/sym.stagXXXX.txt and only that overlay's files are rewritten (src/ and include/ of the
unit, its asm/ tree and linker script, manifest keys `stagXXXX:old`, difficult_functions lines
`stagXXXX:old`). A new name must still be unique in the whole tree (overlay C includes main headers).

Names never change bytes. Run `python tools/build_dw2.py` afterwards: a rename must keep the
build OK.
"""
import argparse
import glob
import os
import re
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYMS = os.path.join(ROOT, "configs", "USA", "sym.main.txt")
SYM_LINE = re.compile(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;(.*)$")
PLACEHOLDER = re.compile(r"(func|D|jtbl)_([0-9A-Fa-f]{8})$")
IDENT = re.compile(r"[A-Za-z_]\w*$")
C_WORDS = set("""auto break case char const continue default do double else enum extern float for
goto if int long register return short signed sizeof static struct switch typedef union unsigned
void volatile while u8 s8 u16 s16 u32 s32 main""".split())


UNIT = None  # stage overlay unit for --unit (stag0000 ...), None = main exe


def sym_path():
    return os.path.join(ROOT, "configs", "USA", "sym.%s.txt" % UNIT) if UNIT else SYMS


def load_symbols():
    by_name = {}
    if os.path.exists(sym_path()):
        for line in open(sym_path(), encoding="utf-8"):
            m = SYM_LINE.match(line)
            if m:
                by_name[m.group(1)] = (int(m.group(2), 16), m.group(3))
    return by_name


def resolve(old, syms):
    """(address, kind, already in sym.main.txt)."""
    if old in syms:
        va, rest = syms[old]
        m = re.search(r"type:(\w+)", rest)
        return va, (m.group(1) if m else None), True
    m = PLACEHOLDER.match(old)
    if not m:
        sys.exit("%s: not a placeholder (func_/D_XXXXXXXX) and not in sym.main.txt" % old)
    va = int(m.group(2), 16)
    if UNIT and not unit_has(old):
        sys.exit("%s is not a symbol of %s" % (old, UNIT))
    taken = [n for n, (v, _r) in syms.items() if v == va]
    if taken:
        sys.exit("%s is already named %s (rename that instead)" % (old, taken[0]))
    return va, ("func" if m.group(1) == "func" else None), False


def unit_has(name):
    """name appears in the overlay's split asm (function file or data label)."""
    root = os.path.join(ROOT, "asm", "USA", UNIT)
    if glob.glob(os.path.join(root, "nonmatchings", UNIT, name + ".s")):
        return True
    pat = re.compile(r"(?<![\w$.])%s(?!\w)" % re.escape(name))
    for p in glob.glob(os.path.join(root, "**", "*.s"), recursive=True):
        if pat.search(open(p, encoding="latin1").read()):
            return True
    return False


def defined_words():
    """Identifiers already used in src/ and include/ (a new name must not collide)."""
    words = set()
    for p in source_files():
        text = open(p, encoding="latin1").read()
        text = re.sub(r"/\*.*?\*/|//[^\n]*", " ", text, flags=re.S)
        words.update(re.findall(r"[A-Za-z_]\w*", text))
    return words


def check_new(new, syms, words, va=None):
    if not IDENT.match(new) or new in C_WORDS:
        sys.exit("%s is not a usable C identifier" % new)
    m = PLACEHOLDER.match(new)
    if m and (va is None or int(m.group(2), 16) != va):
        sys.exit("%s looks like a placeholder; give a real name" % new)
    if new in syms or new in words:
        sys.exit("%s is already in use" % new)


def update_symbols(old, new, va, kind, existing):
    SYMS = sym_path()
    raw = open(SYMS, "rb").read() if os.path.exists(SYMS) else b""
    nl = "\r\n" if b"\r\n" in raw else "\n"
    lines = raw.decode("utf-8").splitlines()
    entry = "%s = 0x%08X;%s" % (new, va, " // type:%s" % kind if kind else "")
    if existing and PLACEHOLDER.match(new):
        # back to the placeholder: the symbol file no longer names this address
        lines = [l for l in lines if not (SYM_LINE.match(l) and SYM_LINE.match(l).group(1) == old)]
    elif existing:
        out = []
        for l in lines:
            m = SYM_LINE.match(l)
            out.append("%s = %s;%s" % (new, m.group(2), m.group(3)) if m and m.group(1) == old else l)
        lines = out
    else:
        lines.append(entry)
    with open(SYMS, "w", encoding="utf-8", newline="") as f:
        f.write(nl.join(lines) + nl)


def source_files(unit_only=False):
    if unit_only and UNIT:
        files = []
        for g in ("src/%s/**/*.c" % UNIT, "src/%s/**/*.h" % UNIT, "include/%s/**/*.h" % UNIT):
            files += glob.glob(os.path.join(ROOT, g), recursive=True)
        return files
    files = []
    for g in ("src/**/*.c", "src/**/*.h", "src/**/*.s", "include/**/*.h"):
        files += glob.glob(os.path.join(ROOT, g), recursive=True)
    return files


def _write(p, text):
    """Write with retries: an indexer or scanner can hold a file open for a moment on Windows."""
    for k in range(50):
        try:
            with open(p, "w", encoding="latin1", newline="") as f:
                f.write(text)
            return
        except OSError:
            if k == 49:
                raise
            time.sleep(0.2)


def rewrite_tree(mapping):
    """Rewrite every old name of `mapping` (old -> new) in one pass over the tree."""
    pat = re.compile(r"(?<![\w$.])(%s)(?!\w)" % "|".join(re.escape(o) for o in sorted(mapping, key=len, reverse=True)))
    if UNIT:
        return rewrite_unit(mapping, pat)
    files = source_files()
    files += glob.glob(os.path.join(ROOT, "asm", "USA", "**", "*.s"), recursive=True)
    files += glob.glob(os.path.join(ROOT, "linkers", "USA", "*.txt"))
    # overlay symbol files carry the main exe's names (tools/ovl_setup.py)
    files += glob.glob(os.path.join(ROOT, "configs", "USA", "sym.stag*.txt"))
    files.append(os.path.join(ROOT, "tools", "asm_normalizer_manifest.json"))
    files.append(os.path.join(ROOT, "tools", "difficult_functions"))
    changed = []
    for p in files:
        if not os.path.exists(p):
            continue
        text = open(p, encoding="latin1", newline="").read()
        new_text, n = pat.subn(lambda m: mapping[m.group(1)], text)
        if n:
            _write(p, new_text)
            if not p.endswith(".s"):
                changed.append((os.path.relpath(p, ROOT), n))
    for old, new in mapping.items():
        for s in glob.glob(os.path.join(ROOT, "asm", "USA", "*", "nonmatchings", "*", old + ".s")):
            os.replace(s, os.path.join(os.path.dirname(s), new + ".s"))
        # restored hand-written asm sources: ASM_SOURCE("src/main/asm/LIB", NAME) includes LIB/NAME.s
        for s in glob.glob(os.path.join(ROOT, "src", "main", "asm", "**", old + ".s"), recursive=True):
            os.replace(s, os.path.join(os.path.dirname(s), new + ".s"))
    return changed


def rewrite_unit(mapping, pat):
    """--unit: rewrite only the overlay's own files; manifest / difficult_functions by `unit:` key."""
    files = source_files(unit_only=True)
    files += glob.glob(os.path.join(ROOT, "asm", "USA", UNIT, "**", "*.s"), recursive=True)
    files += glob.glob(os.path.join(ROOT, "linkers", "USA", "%s.ld" % UNIT))
    changed = []
    for p in files:
        text = open(p, encoding="latin1", newline="").read()
        new_text, n = pat.subn(lambda m: mapping[m.group(1)], text)
        if n:
            _write(p, new_text)
            if not p.endswith(".s"):
                changed.append((os.path.relpath(p, ROOT), n))
    upat = re.compile(r"(?<![\w$.])%s:(%s)(?!\w)" % (UNIT, "|".join(re.escape(o) for o in mapping)))
    for p in (os.path.join(ROOT, "tools", "asm_normalizer_manifest.json"),
              os.path.join(ROOT, "tools", "difficult_functions")):
        if os.path.exists(p):
            text = open(p, encoding="latin1", newline="").read()
            new_text, n = upat.subn(lambda m: "%s:%s" % (UNIT, mapping[m.group(1)]), text)
            if n:
                _write(p, new_text)
                changed.append((os.path.relpath(p, ROOT), n))
    for old, new in mapping.items():
        for s in glob.glob(os.path.join(ROOT, "asm", "USA", UNIT, "nonmatchings", "*", old + ".s")):
            os.replace(s, os.path.join(os.path.dirname(s), new + ".s"))
    return changed


def rename(old, new, syms, words):
    va, kind, existing = resolve(old, syms)
    check_new(new, syms, words, va)
    update_symbols(old, new, va, kind, existing)
    syms.pop(old, None)
    words.discard(old)
    if not PLACEHOLDER.match(new):
        syms[new] = (va, " // type:%s" % kind if kind else "")
    words.add(new)
    print("%s -> %s (0x%08X)" % (old, new, va))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("old", nargs="?")
    ap.add_argument("new", nargs="?")
    ap.add_argument("--batch", help="file of `old new` lines")
    ap.add_argument("--unit", help="stage overlay (stag0000 ...): rename that overlay's symbol")
    a = ap.parse_args()
    global UNIT
    if a.unit:
        if not re.match(r"stag\d{4}$", a.unit) or not os.path.isdir(os.path.join(ROOT, "src", a.unit)):
            sys.exit("unknown overlay unit %s" % a.unit)
        UNIT = a.unit
    pairs = []
    if a.batch:
        for line in open(a.batch, encoding="utf-8"):
            line = line.split("#", 1)[0].split()
            if line:
                if len(line) != 2:
                    sys.exit("bad batch line: %s" % " ".join(line))
                pairs.append(tuple(line))
    elif a.old and a.new:
        pairs.append((a.old, a.new))
    else:
        ap.error("give OLD NEW or --batch FILE")
    olds = [o for o, _n in pairs]
    news = [n for _o, n in pairs]
    if len(set(olds)) != len(olds) or len(set(news)) != len(news):
        sys.exit("batch renames one symbol twice or reuses a new name")
    syms, words = load_symbols(), defined_words()
    for old, new in pairs:
        rename(old, new, syms, words)
    for p, n in rewrite_tree(dict(pairs)):
        print("  %s (%d)" % (p, n))
    print("now run: python tools/build_dw2.py")


if __name__ == "__main__":
    main()
