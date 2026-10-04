<p align="center">
  <a href="https://nyen.cc/"><img src="https://nyen.cc/favicon.svg" alt="NYEN logo" width="56" height="56"></a>
  <br>
  <sub>Powered by</sub>
  <br>
  <a href="https://nyen.cc/"><b>NYEN</b></a>
</p>

# Digimon World 2 Decompilation

<!-- PROGRESS:BADGE -->
![matched](https://img.shields.io/badge/matched-1089%2F1089%20(100.00%25)-1f6feb)
<!-- /PROGRESS:BADGE -->
![build](https://img.shields.io/badge/build-byte--identical-2ea043)
![platform](https://img.shields.io/badge/platform-PS1%20(SLUS--01193)-8957e5)

A **matching decompilation** of *Digimon World 2* for the Sony PlayStation.

The goal is to recover readable C that, when compiled with a period-correct toolchain,
produces a binary **byte-identical** to the original executable, then a moddable full-source
tree.

| Item | Value |
|---|---|
| Platform | PlayStation (PSX / PS1) |
| Target | USA main executable `SLUS_011.93` + 7 stage overlays |
| Disc (USA) | `SLUS-01193` |
| Exe SHA-1 | `e55ed5bf354def07f0cbf4e1fb7fb5f99204f220` (651264 bytes) |
| Overlays | `STAG0000/1000/1100/2000/3000/3500/4000.PRO`, loaded at `0x80063360` |
| Compiler | GCC 2.8.1 (PSX `cc1`) + maspsx |
| Structure | main exe + 7 stage overlays (`AAA/3.PRO/STAG*.PRO`) |
| License (project code) | CC0 1.0 |

> **You must own the game.** This repository contains no ROMs, disc images, or copyrighted
> assets. `rom/ assets/ build/` are made from *your own* disc and are gitignored. Obtain a
> legal dump of your own disc.
>
> `asm/` and `linkers/` are splat output. They are still committed today so the progress CI
> can build without a disc. That covers the PsyQ library asm, the `.data` sections and a few
> `.rodata` tables that are not C yet. They will move out of the repo (see
> [issue #6](https://github.com/Wyrelade/Digimon-World-2-Decomp/issues/6)).

## Status

**All 1089 game functions are matched C.** The C rebuilds the retail executable and all 7
stage overlays byte-identical. The work now is naming and cleanup (most of the main exe and
the small overlays have real names; the battle, dungeon, city and VS overlays are next), then
a non-matching build for modding and ports.

The last two functions:

- `Task_Run` (the task scheduler) runs every update and draw callback on a stack in the
  scratchpad RAM. C cannot move the stack pointer, so the switch is two small `__asm__`
  statements around the calls, the rest is plain C. The original most likely did the same.
- `stag4000:func_8006D418` returns the same field on both sides of a flag test. The test does
  nothing, but GCC 2.8.1 only merges the two arms after register allocation, and retail's
  code has exactly that allocation. No form without the test produces it.

A function counts as **matched** only when its C reproduces the retail bytes with the compiler
setup of its translation unit and no asm rewrites: GCC 2.8.1-psx `-O2`, main game `-G8` with
maspsx `--aspsx-version=2.81`, overlays `-G0` with 2.77, plus a few per-unit flags in
`tools/build_dw2.py`. Functions that still need a per-function flag set or asm rewrites are
listed separately and are not counted. PsyQ library code (PsyQ 4.7 in the exe, libpress 4.6 in
`STAG1000.PRO`) is not game code and is excluded from progress
(`configs/USA/psyq_funcs.txt`). Counts come from `tools/strict_report.py`, which builds each
function with and without the post-processing and compares it against the target. See
[issue #5](https://github.com/Wyrelade/Digimon-World-2-Decomp/issues/5).

### Progress by component

<!-- PROGRESS:TABLE -->
| Component | Functions | Matched | Progress | Flags per function | Asm rewrites | Asm |
|---|---:|---:|---|---:|---:|---:|
| **Main executable** (`SLUS_011.93`, game code) | 369 | 369 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| **Stage overlays** (`AAA/3.PRO`) | 720 | 720 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG0000.PRO` | 69 | 69 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG1000.PRO` | 17 | 17 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG1100.PRO` | 55 | 55 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG2000.PRO` | 133 | 133 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG3000.PRO` | 123 | 123 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG3500.PRO` | 108 | 108 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| &nbsp;&nbsp;└ `STAG4000.PRO` | 215 | 215 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| **Total (game code)** | 1089 | 1089 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% | 0 | 0 | 0 |
| PsyQ libraries (not counted) | 558 | | | | | |
<!-- /PROGRESS:TABLE -->

DW2 has the main exe plus 7 stage overlays on the disc, `AAA/3.PRO/STAG0000.PRO` to
`STAG4000.PRO`. The main exe loads one at a time to `0x80063360` (`func_80013308`, indexed by
the game mode), so they share one address range. Each overlay is split into its own unit
(`src/stagXXXX`, `asm/USA/stagXXXX`) and relinks byte-identical to the retail file.

The `AAA` directory is left out of the disc's root directory record, so a plain ISO extract
only shows `SLUS_011.93` and `SYSTEM.CNF`. `dumpsxiso -pt` (path table walk) extracts the full
tree.

PsyQ library code stays as split asm, as in other PS1 decomps. The crt0 startup is the PsyQ
`SNMAIN` hand asm.

## Layout

| Path | What |
|------|------|
| `src/` / `include/` | decompiled C and headers |
| `configs/` | splat config + symbol maps |
| `tools/` | gcc-psx, maspsx, m2c, decomp-permuter, asm-differ, mkpsxiso, build scripts |

## Quick start

Supply your own Digimon World 2 (SLUS-01193) disc and extract it with `dumpsxiso -pt` to
`dumps/disc/` (`SLUS_011.93` plus `AAA/3.PRO/STAG*.PRO`). Then:

```
python3 -m venv venv                                # venv\Scripts on Windows
pip install -r requirements.txt
python3 -m splat split configs/USA/SLUS_011.93.yaml # regenerate asm/ and linkers/
python3 -m splat split configs/USA/stag1000.yaml    # same for each stagXXXX.yaml
python3 tools/build_dw2.py                          # expect: SLUS_011.93: OK + 7x STAGxxxx.PRO: OK
```

`tools/build_dw2.py` preprocesses and compiles `src/**/*.c` through the PSX `cc1` + maspsx
pipeline, assembles the remaining split asm, links with the splat linker script plus the
auto-detected hardware and kernel symbols, then checks the SHA-1 against your disc's exe.
`build/USA/out/SLUS_011.93: OK` means the whole exe still reproduces byte-for-byte. Each
overlay is then linked with its own script and checked the same way
(`build/USA/out/STAGxxxx.PRO: OK`); `--overlays-only` builds just the overlays.

## Contributing names

1. `python3 tools/rename.py func_XXXXXXXX Module_VerbNoun` renames a main exe function or
   global everywhere (`--unit stagXXXX` for an overlay, `--batch file` for many).
   `python3 tools/rename_field.py --batch file` renames struct fields with the compiler as
   the checker.
2. Only name what the code proves. A wrong name is worse than `func_`.
3. Verify with `python3 tools/build_dw2.py`. Only `OK` for every file counts as done.

## Credits

Workflow and toolchain derived from the Parasite Eve 2 decomp. DW2 file-format
documentation by RmBeastbow. Thanks to ThirstyWraith for pointing out the stage overlays
(issue #3) and for their STAG3000 battle notes and decomp.me scratches (issue #4), which
seeded the matches of the battle status and item functions.
