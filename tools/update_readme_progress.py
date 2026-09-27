#!/usr/bin/env python3
"""Regenerate the README progress badge and table from PROGRESS.md.

PROGRESS.md is the single source of truth. Its header line
    **Main exe functions identified: 907 . matched: 55 (6.06%)** ...
gives the total and matched counts. This script recomputes the percentage,
draws the bars, and rewrites the marked regions in README.md so the two files
never drift. Run it after bumping the matched count in PROGRESS.md.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROGRESS = os.path.join(ROOT, "PROGRESS.md")
README = os.path.join(ROOT, "README.md")

BAR_SEGMENTS = 20


def read_counts():
    with open(PROGRESS, encoding="utf-8") as f:
        text = f.read()
    m = re.search(r"functions identified:\s*(\d+)\s*.\s*matched:\s*(\d+)", text)
    if not m:
        sys.exit("could not find 'functions identified: N . matched: M' in PROGRESS.md")
    total, matched = int(m.group(1)), int(m.group(2))
    a = re.search(r"asm restored:\s*(\d+)", text)
    return total, matched, int(a.group(1)) if a else 0


def bar(pct):
    filled = int(round(pct / 100.0 * BAR_SEGMENTS))
    filled = max(0, min(BAR_SEGMENTS, filled))
    return "▰" * filled + "▱" * (BAR_SEGMENTS - filled)


def replace_region(text, tag, body):
    pat = re.compile(r"<!-- %s -->.*?<!-- /%s -->" % (tag, tag), re.DOTALL)
    repl = "<!-- %s -->\n%s\n<!-- /%s -->" % (tag, body, tag)
    if not pat.search(text):
        sys.exit("marker %s not found in README.md" % tag)
    return pat.sub(lambda _: repl, text)


def main():
    total, matched, asm = read_counts()
    pct = 100.0 * matched / total if total else 0.0
    pct_s = "%.2f%%" % pct
    b = bar(pct)

    badge = (
        "![matched](https://img.shields.io/badge/matched-"
        "%d%%2F%d%%20(%s)-1f6feb)" % (matched, total, pct_s.replace("%", "%25"))
    )
    table = "\n".join([
        "| Component | Functions | Matched | Progress |",
        "|---|---:|---:|---|",
        "| **Main executable** (`SLUS_011.93`) | %d | %d | `%s` %s |"
        % (total, matched, b, pct_s),
    ] + ([
        "| &nbsp;&nbsp;└ decompiled to C | | %d | |" % (matched - asm),
        "| &nbsp;&nbsp;└ hand-written assembly, restored as source | | %d | |" % asm,
    ] if asm else [
        "| &nbsp;&nbsp;└ `src/main/156C.c` (text unit) | %d | %d | `%s` %s |"
        % (total, matched, b, pct_s),
    ]))

    with open(README, encoding="utf-8") as f:
        text = f.read()
    text = replace_region(text, "PROGRESS:BADGE", badge)
    text = replace_region(text, "PROGRESS:TABLE", table)
    with open(README, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    print("README progress updated: %d/%d (%s)" % (matched, total, pct_s))


if __name__ == "__main__":
    main()
