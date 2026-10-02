#!/usr/bin/env python3
"""Regenerate the README progress badge and table from tools/match_status.json.

tools/strict_report.py writes match_status.json (one class per function, see its
docstring). Only "natural" functions count as matched: C that reproduces the
retail bytes with the base compiler flags and no target-guided asm rewrites.
"flavor" (needs a per-function alternate flag set) and "normalized" (needs asm
rewrites) are shown but not counted. PsyQ library functions
(configs/USA/psyq_funcs.txt) are listed separately and never counted.
"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STATUS = os.path.join(ROOT, "tools", "match_status.json")
PSYQ = os.path.join(ROOT, "configs", "USA", "psyq_funcs.txt")
README = os.path.join(ROOT, "README.md")

BAR_SEGMENTS = 20
CLASSES = ("natural", "flavor", "normalized", "asm", "asm_source")


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


def counts():
    status = json.load(open(STATUS, encoding="utf-8"))
    psyq = set()
    if os.path.exists(PSYQ):
        psyq = {l.split()[0] for l in open(PSYQ) if l.strip() and not l.startswith("#")}
    groups = {}
    for key, cls in status.items():
        unit = key.split(":")[0] if ":" in key else "main"
        grp = "psyq" if key in psyq else unit
        g = groups.setdefault(grp, dict.fromkeys(CLASSES, 0))
        g[cls] += 1
    return groups


def row(label, g):
    total = sum(g.values())
    m = g["natural"]
    pct = 100.0 * m / total if total else 0.0
    return "| %s | %d | %d | `%s` %.2f%% | %d | %d | %d |" % (
        label, total, m, bar(pct), pct, g["flavor"], g["normalized"], g["asm"] + g["asm_source"])


def add(*gs):
    out = dict.fromkeys(CLASSES, 0)
    for g in gs:
        for c in CLASSES:
            out[c] += g[c]
    return out


def main():
    groups = counts()
    stags = sorted(u for u in groups if u.startswith("stag"))
    ovl = add(*[groups[u] for u in stags])
    game = add(groups["main"], ovl)
    total, matched = sum(game.values()), game["natural"]
    pct_s = "%.2f%%" % (100.0 * matched / total if total else 0.0)
    badge = ("![matched](https://img.shields.io/badge/matched-%d%%2F%d%%20(%s)-1f6feb)"
             % (matched, total, pct_s.replace("%", "%25")))
    lines = [
        "| Component | Functions | Matched | Progress | Flags per function | Asm rewrites | Asm |",
        "|---|---:|---:|---|---:|---:|---:|",
        row("**Main executable** (`SLUS_011.93`, game code)", groups["main"]),
        row("**Stage overlays** (`AAA/3.PRO`)", ovl),
    ] + [row("&nbsp;&nbsp;└ `%s.PRO`" % u.upper(), groups[u]) for u in stags] + [
        row("**Total (game code)**", game),
    ]
    if "psyq" in groups:
        lines.append("| PsyQ libraries (not counted) | %d | | | | | |" % sum(groups["psyq"].values()))
    with open(README, encoding="utf-8") as f:
        text = f.read()
    text = replace_region(text, "PROGRESS:BADGE", badge)
    text = replace_region(text, "PROGRESS:TABLE", "\n".join(lines))
    with open(README, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    print("README progress updated: game code %d/%d (%s), byte-perfect build %d/%d"
          % (matched, total, pct_s, total - game["asm"], total))


if __name__ == "__main__":
    main()
