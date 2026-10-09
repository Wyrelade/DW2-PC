#!/usr/bin/env python3
"""Player zips: DW2-PC-windows-x64.zip and DW2-PC-linux-x64.zip in build/dist.

Takes the release builds as they are (build them first):
  Windows: tools/build_native.py --arch x64 --release  -> build/native64_rel/dw2.exe
  Linux:   tools/build_native.py --release (in WSL)    -> build/linux64_rel/dw2
Each zip holds the program (debug info stripped from a copy), SDL3.dll on Windows,
README.txt (misc/release/README.txt, with the Dear ImGui MIT notice) and LICENSE.txt
(CC0). No licenses/ folder (user 2026-10-09). No game data. The zips stay in build/ (never in git).
"""

import argparse
import os
import shutil
import subprocess
import sys
import time
import zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DIST = os.path.join(ROOT, "build", "dist")
WINDOWS = sys.platform == "win32"
SDL_WIN = os.environ.get("SDL3_DIR", "D:/tools/SDL3") + "/x86_64-w64-mingw32"
STRIP_WIN = "D:/tools/winlibs-x86_64/mingw64/bin/strip.exe"


def common_files():
    return [
        (os.path.join(ROOT, "misc", "release", "README.txt"), "README.txt"),
        (os.path.join(ROOT, "LICENSE"), "LICENSE.txt"),
    ]


def strip(src, dst, elf):
    shutil.copy2(src, dst)
    if elf and WINDOWS:
        rel = os.path.relpath(dst, ROOT).replace("\\", "/")
        cmd = ["wsl.exe", "--cd", ROOT, "-e", "strip", "--strip-debug", rel]
    else:
        cmd = [STRIP_WIN if WINDOWS else "strip", "--strip-debug", dst]
    subprocess.run(cmd, check=True)


def text_lines(path, crlf):
    data = open(path, "rb").read().replace(b"\r\n", b"\n")
    return data.replace(b"\n", b"\r\n") if crlf else data


def make_zip(name, entries, crlf):
    path = os.path.join(DIST, name)
    if os.path.exists(path):
        os.remove(path)
    with zipfile.ZipFile(path, "w", zipfile.ZIP_DEFLATED, compresslevel=9) as z:
        for src, arc, kind in entries:
            info = zipfile.ZipInfo("DW2-PC/" + arc, date_time=time.localtime(os.path.getmtime(src))[:6])
            info.compress_type = zipfile.ZIP_DEFLATED
            info.create_system = 3  # Unix: unzip keeps the modes below
            if kind == "exe":
                info.external_attr = (0o100755 << 16)
                z.writestr(info, open(src, "rb").read())
            else:
                info.external_attr = (0o100644 << 16)
                z.writestr(info, text_lines(src, crlf) if kind == "text" else open(src, "rb").read())
    print("%s (%d bytes)" % (os.path.relpath(path, ROOT), os.path.getsize(path)))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--only", choices=["windows", "linux"], help="make one zip")
    args = ap.parse_args()
    os.makedirs(DIST, exist_ok=True)
    stage = os.path.join(DIST, "stage")
    os.makedirs(stage, exist_ok=True)
    texts = [(s, a, "text") for s, a in common_files()]

    if args.only in (None, "windows"):
        exe = os.path.join(ROOT, "build", "native64_rel", "dw2.exe")
        if not os.path.exists(exe):
            sys.exit("missing %s (build --arch x64 --release first)" % exe)
        out = os.path.join(stage, "dw2.exe")
        strip(exe, out, False)
        make_zip("DW2-PC-windows-x64.zip",
                 [(out, "dw2.exe", "bin"), (os.path.join(SDL_WIN, "bin", "SDL3.dll"), "SDL3.dll", "bin")]
                 + texts, True)
    if args.only in (None, "linux"):
        elf = os.path.join(ROOT, "build", "linux64_rel", "dw2")
        if not os.path.exists(elf):
            sys.exit("missing %s (build --release in Linux / WSL first)" % elf)
        out = os.path.join(stage, "dw2")
        strip(elf, out, True)
        make_zip("DW2-PC-linux-x64.zip", [(out, "dw2", "exe")] + texts, False)


if __name__ == "__main__":
    main()
