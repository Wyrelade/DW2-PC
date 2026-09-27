# Digimon World 2 Decompilation

<!-- PROGRESS:BADGE -->
![matched](https://img.shields.io/badge/matched-907%2F907%20(100.00%25)-1f6feb)
<!-- /PROGRESS:BADGE -->
![build](https://img.shields.io/badge/build-byte--identical-2ea043)
![platform](https://img.shields.io/badge/platform-PS1%20(SLUS--01193)-8957e5)

A work-in-progress **matching decompilation** of *Digimon World 2* for the Sony PlayStation.

The goal is to recover readable C that, when compiled with a period-correct toolchain,
produces a binary **byte-identical** to the original executable, then a moddable full-source
tree.

| Item | Value |
|---|---|
| Platform | PlayStation (PSX / PS1) |
| Target | USA main executable `SLUS_011.93` |
| Disc (USA) | `SLUS-01193` |
| Exe SHA-1 | `e55ed5bf354def07f0cbf4e1fb7fb5f99204f220` (651264 bytes) |
| Compiler | GCC 2.8.1 (PSX `cc1`) + maspsx |
| Structure | single main exe, no overlays |
| License (project code) | CC0 1.0 |

> **You must own the game.** This repository contains no ROMs, disc images, or copyrighted
> assets. Everything under `rom/ assets/ asm/ linkers/ build/` is regenerated from *your own*
> disc and is gitignored. Obtain a legal dump of your own disc.

## Status

Phase 0 is complete: the split relinks **byte-identical** to the retail executable, and the
text segment is compiled per-function so matching is underway. Each matched function is
verified by the full relink still producing `SLUS_011.93: OK` (SHA-1 match) - a scratch
match alone is never enough.

### Progress by component

<!-- PROGRESS:TABLE -->
| Component | Functions | Matched | Progress |
|---|---:|---:|---|
| **Main executable** (`SLUS_011.93`) | 907 | 907 | `▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰` 100.00% |
| &nbsp;&nbsp;└ decompiled to C | | 830 | |
| &nbsp;&nbsp;└ hand-written assembly, restored as source | | 77 | |
<!-- /PROGRESS:TABLE -->

DW2 is a single main executable with no overlays, so the main exe is the whole target for
now. As the text unit is split into per-file units, this table grows a row per unit.

Some functions cannot yet be reproduced byte-for-byte by the current toolchain (gp-relative
accesses under `-G0`, `$at` high-scratch stores, BIOS syscall thunks, and a handful of GCC
reassociation / delay-slot codegen choices); those keep their `INCLUDE_ASM` stub until the
toolchain covers them.

## Layout

| Path | What |
|------|------|
| `src/` / `include/` | decompiled C and headers |
| `configs/` | splat config + symbol maps |
| `tools/` | gcc-psx, maspsx, m2c, decomp-permuter, asm-differ, mkpsxiso, build scripts |

## Quick start

Supply your own Digimon World 2 (SLUS-01193) disc and extract `SLUS_011.93` to
`dumps/disc/`. Then:

```
python3 -m venv venv                                # venv\Scripts on Windows
pip install -r requirements.txt
python3 -m splat split configs/USA/SLUS_011.93.yaml # regenerate asm/ and linkers/
python3 tools/build_dw2.py                          # expect: build/USA/out/SLUS_011.93: OK
```

`tools/build_dw2.py` preprocesses and compiles `src/**/*.c` through the PSX `cc1` + maspsx
pipeline, assembles the remaining split asm, links with the splat linker script plus the
auto-detected hardware and kernel symbols, then checks the SHA-1 against your disc's exe.
`build/USA/out/SLUS_011.93: OK` means the whole exe still reproduces byte-for-byte.

## Contributing a match

1. `python3 tools/score_functions.py --exhaustive asm/USA/main/nonmatchings` ranks the
   easiest unmatched functions.
2. Replace a function's `INCLUDE_ASM` in `src/main/156C.c` with C. Prefer proper structs
   over pointer arithmetic (`field_[offset]` names are fine) defined in the module header
   (see `include/main/156C.h`).
3. Verify with `python3 tools/build_dw2.py`. Only `SLUS_011.93: OK` counts as done.
4. One matched function is one commit.

## Credits

Workflow and toolchain derived from the Parasite Eve 2 decomp. DW2 file-format
documentation by RmBeastbow.
