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


# a definition, ANSI or K&R (parameter declarations between `)` and `{`)
FUNC_DEF = re.compile(r"^[A-Za-z_][\w \t\*]*?\b\w+\s*\([^;{}]*\)[ \t]*(?:\n[ \t]+[^\n{}()]*;[ \t]*)*\s*\{", re.M)


def overlay_counts():
    """[(unit, total, matched)] for src/stagXXXX/*.c: an INCLUDE_ASM stub is an
    unmatched function, a C definition or a restored ASM_SOURCE is a matched one."""
    rows = []
    src = os.path.join(ROOT, "src")
    for unit in sorted(os.listdir(src)) if os.path.isdir(src) else []:
        d = os.path.join(src, unit)
        if not unit.startswith("stag") or not os.path.isdir(d):
            continue
        asm = c = 0
        for name in os.listdir(d):
            if name.endswith(".c"):
                with open(os.path.join(d, name), encoding="latin-1") as f:
                    text = f.read()
                asm += len(re.findall(r"^INCLUDE_ASM\(", text, re.M))
                c += len(FUNC_DEF.findall(text))
                c += len(re.findall(r"^ASM_SOURCE\(", text, re.M))
        rows.append((unit, asm + c, c))
    return rows


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

    ovl = overlay_counts()
    o_total = sum(r[1] for r in ovl)
    o_matched = sum(r[2] for r in ovl)
    g_total, g_matched = total + o_total, matched + o_matched
    g_pct_s = "%.2f%%" % (100.0 * g_matched / g_total if g_total else 0.0)

    badge = (
        "![matched](https://img.shields.io/badge/matched-"
        "%d%%2F%d%%20(%s)-1f6feb)" % (g_matched, g_total, g_pct_s.replace("%", "%25"))
    )
    ovl_rows = []
    if ovl:
        o_pct = 100.0 * o_matched / o_total if o_total else 0.0
        ovl_rows.append("| **Stage overlays** (`AAA/3.PRO`) | %d | %d | `%s` %.2f%% |"
                        % (o_total, o_matched, bar(o_pct), o_pct))
        for unit, t, m in ovl:
            p = 100.0 * m / t if t else 0.0
            ovl_rows.append("| &nbsp;&nbsp;└ `%s.PRO` | %d | %d | `%s` %.2f%% |"
                            % (unit.upper(), t, m, bar(p), p))
        ovl_rows.append("| **Total** | %d | %d | `%s` %s |"
                        % (g_total, g_matched, bar(100.0 * g_matched / g_total), g_pct_s))
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
    ]) + ovl_rows)

    with open(README, encoding="utf-8") as f:
        text = f.read()
    text = replace_region(text, "PROGRESS:BADGE", badge)
    text = replace_region(text, "PROGRESS:TABLE", table)
    with open(README, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    print("README progress updated: main %d/%d (%s), overlays %d/%d, total %d/%d (%s)"
          % (matched, total, pct_s, o_matched, o_total, g_matched, g_total, g_pct_s))


if __name__ == "__main__":
    main()
