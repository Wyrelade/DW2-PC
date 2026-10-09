Digimon World 2 PC port (DW2-PC)
================================

A native PC port of Digimon World 2 (PS1, USA, SLUS-01193), built from the decompiled game
code. Project page: https://github.com/Wyrelade/DW2-PC

You need your own copy of the game. This download has no game data in it. The port builds its
data pack from your own disc image on the first start.


Getting started
---------------

1. Unpack this zip anywhere.
2. Put your disc image in the same folder as the program. It must be a raw dump with
   2352-byte sectors: .bin + .cue, a CloneCD .img, or a raw .iso. A 2048-byte .iso does not
   work (it has lost the audio and movie sectors); the game tells you if you have one.
3. Start dw2.exe (Windows) or ./dw2 (Linux). On the first start the game checks your image,
   writes its data pack dw2.pak next to the program (a few seconds) and starts. If it finds
   no image, it asks for one. After that the image is not needed any more.

You can also drop the image onto dw2.exe, or start the game with --disc PATH.


Keys
----

Arrow keys = D-pad, Z = Cross, X = Circle, A = Square, S = Triangle, Q / W = L1 / R1,
E / R = L2 / R2, Enter = Start, Backspace = Select. Gamepads work out of the box.

F1   settings (render scale, 16:9, no wobble, sharpening, window mode, key and gamepad
     remap, speed-up multiplier, volume)
F3   speed-up on / off (battles, domains and menus 2x to 8x faster; movies stay at
     normal speed)
F5   render scale 1x .. 8x
F6   no wobble on / off
F7   16:9 on / off
F8   sharpening on / off
F11  windowed / fullscreen
F12  screenshot
Esc  quit (asks first)

dw2 --help lists the command line options.


Files and folders
-----------------

Screenshots: F12 saves a PNG in the "screenshots" folder next to the program.

Saves (memory cards card1.mcd and card2.mcd) and settings.ini are in the user data folder:
  Windows: %APPDATA%\DW2-Online\
  Linux:   ~/.local/share/DW2-Online/
Saves are in its "saves" folder. A raw memory card file from DuckStation, PCSX-Redux or
ePSXe works: copy it there as card1.mcd.


Linux
-----

The Linux build needs SDL3 3.4 or newer from your distribution (package libsdl3-0 on
Debian / Ubuntu, SDL3 on Fedora and Arch) and glibc 2.43 or newer (built on Ubuntu 26.04).
A libSDL3.so.0 placed next to dw2 is used before the system one. On older systems, build
from source (see the project page).


Problems and reports
--------------------

Please report crashes, glitches and anything that plays differently from the PS1 version:
https://github.com/Wyrelade/DW2-PC/issues

Say what you did, what happened and what you expected. A screenshot (F12) helps, and so does
the save (card1.mcd) from just before the problem.


Licenses
--------

The port is released under CC0 1.0 (LICENSE.txt). It uses SDL3 (zlib license)
and Dear ImGui (MIT license, notice below).
Digimon World 2 and its data belong to their owners.

Dear ImGui:

Copyright (c) 2014-2026 Omar Cornut

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
