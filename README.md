<p align="center">
  <a href="https://nyen.cc/"><img src="https://nyen.cc/favicon.svg" alt="NYEN logo" width="56" height="56"></a>
  <br>
  <sub>Powered by</sub>
  <br>
  <a href="https://nyen.cc/"><b>NYEN</b></a>
</p>

# Digimon World 2 PC Port

![platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-8957e5)
![status](https://img.shields.io/badge/status-work%20in%20progress-d29922)

A native PC port of *Digimon World 2* (PlayStation, USA, `SLUS-01193`). The game's own C code
from the [matching decompilation](https://github.com/Wyrelade/Digimon-World-2-Decomp) is
compiled for the PC; the PlayStation libraries are replaced by a PC layer on SDL3. It is not an
emulator and not a remake: the game logic is the original code, so it plays like the PS1
version.

> **You need your own copy of the game.** This repository and its builds contain no disc
> image, no game data and no copyrighted assets. The port reads its data from a pack file
> that is built on your PC from your own disc image and checked against a list of file
> hashes. A disc that does not match is rejected.

## Status

Work in progress. The game boots, the title, city, domains, battles, menus, saving and
loading run, and the VS mode works with two pads.

| Part | State |
|---|---|
| Game logic (all 1088 game functions, all 7 stage overlays) | compiled from the decomp C |
| Graphics | software PS1 GPU, plus an HD path: render scale 1x to 8x, 16:9, no wobble (precise vertices, perspective-correct textures), GPU renderer (SDL_GPU) |
| Sound | SPU (music and effects) |
| Saves | memory card images `card1.mcd` / `card2.mcd` (raw `.mcd` / `.mcr` from emulators load as is) |
| Input | keyboard and SDL gamepads, two ports |
| Builds | Windows x86 / x64 (MinGW-w64), Linux x64 |

Still to do for the first release:

- start with no setup: the exe finds your disc image (`.cue` / `.bin` / `.iso` / `.img`) and
  builds its data pack on the first start
- F1 settings window: key and pad remap, render scale, 16:9, no wobble, sharpening, renderer,
  window mode (windowed, borderless, fullscreen), saved to a settings file
- intro and ending movies (skipped today)
- streamed CD audio (XA)
- a full playthrough check from start to ending, every scene on 64-bit

## Running it (today)

Until the first-start setup is done, the data pack is built with a script:

```
python3 tools/dw2pack.py "path/to/Digimon World 2.img" -o dw2.pak
dw2.exe --pak dw2.pak
```

The image must be a raw 2352-byte-sector dump of the USA disc (a CloneCD `.img` or a
single-track `.bin`). Saves go to `%APPDATA%\DW2-Online\saves\` on Windows and
`~/.local/share/DW2-Online/saves/` on Linux.

Keyboard: arrows = D-pad, Z = Cross, X = Circle, A = Square, S = Triangle, Q / W = L1 / R1,
E / R = L2 / R2, Enter = Start, Backspace = Select, Esc = quit. F5 render scale, F6 no wobble,
F7 16:9, F12 screenshot. Gamepads map by button position (south = Cross).

Command line options: `dw2 --help` lists them (`--scale N`, `--wide`, `--pgxp`,
`--renderer gpu|soft`, `--save-dir DIR`, ...).

## Building

Windows (Git Bash or any shell):

- MinGW-w64 GCC (WinLibs, x86_64 or i686), set `DW2_MINGW` to its root
- SDL3 MinGW development release, set `DW2_SDL3` to its root
- Python 3 with `pip install -r requirements.txt` (Ninja comes from there)

```
python tools/build_native.py --arch x64 --release   # build/native64_rel/dw2.exe
```

Linux: gcc, CMake, Ninja and `libsdl3-dev`, then `python3 tools/build_native.py --release`.

A few data tables are copied from your disc at build time (`configs/USA/include_bin.txt`), so
the build also needs your disc's files extracted to `dumps/disc/` (`dumpsxiso -pt`). Builds
without `--release` add developer tools (an ImGui overlay on F2).

The matching PS1 build (byte-identical to the retail disc) is still here:
`python3 tools/build_dw2.py`. See the decomp repository for how that works.

## Layout

| Path | What |
|------|------|
| `src/` / `include/` | the game's C (from the decomp) and headers |
| `psyq/` | PC replacements for the PlayStation libraries |
| `backend/` | emulated PS1 GPU and SPU, HD renderer |
| `host/` | SDL3 window, input, audio, saves, data pack |
| `tools/` | build scripts, `dw2pack.py`, decomp tools |
| `doc/` | state map, pack format, Psy-Q API notes |

## Credits

Built on the [Digimon World 2 decompilation](https://github.com/Wyrelade/Digimon-World-2-Decomp).
Workflow and toolchain derived from the Parasite Eve 2 decomp. DW2 file-format documentation
by RmBeastbow. Thanks to ThirstyWraith for the stage overlay and battle notes. Uses SDL3
(zlib license) and Dear ImGui (MIT license, `host/imgui/LICENSE.txt`).

## License

The project code is CC0 1.0 (`LICENSE`). Digimon World 2 and its data belong to their owners;
none of it is in this repository.
