#!/usr/bin/env python3
"""Native PC build (DW2_NATIVE): configure CMakeLists.txt with Ninja and the i686 MinGW-w64 GCC,
build build/native/dw2.exe, count the compiler warnings.

    venv/Scripts/python.exe tools/build_native.py            # configure if needed, build
    venv/Scripts/python.exe tools/build_native.py --rebuild  # clean build (full warning count)
    venv/Scripts/python.exe tools/build_native.py --run [--vblanks N] [--no-window]
    venv/Scripts/python.exe tools/build_native.py --test     # also run build/native/gte_test

Toolchain: DW2_MINGW = the MinGW-w64 root holding bin/gcc.exe (default
D:/tools/winlibs-i686/mingw32); Ninja from the venv (pip install ninja) or PATH; DW2_SDL3 = the
SDL3 MinGW development release root (default D:/tools/SDL3, SDL3-devel-3.x-mingw unpacked). The INCLUDE_BIN
assets come from the user's disc dump like in tools/build_dw2.py (configs/USA/include_bin.txt);
assets/Ovl_LoadArea.bin comes from splat."""

import argparse
import collections
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILD = os.path.join(ROOT, "build", "native")
sys.path.insert(0, os.path.join(ROOT, "tools"))


def find_ninja():
    exe = "ninja.exe" if os.name == "nt" else "ninja"
    local = os.path.join(os.path.dirname(sys.executable), exe)
    return local if os.path.exists(local) else shutil.which("ninja")


def extract_native_bins():
    """configs/USA/include_bin_native.txt: native-only INCLUDE_BIN assets, same format as
    include_bin.txt (asset, source, offset, size)."""
    for line in open(os.path.join(ROOT, "configs/USA/include_bin_native.txt")):
        line = line.split("#", 1)[0].split()
        if not line:
            continue
        asset, source, offset, size = line[0], line[1], int(line[2], 0), int(line[3], 0)
        src = os.path.join(ROOT, source)
        if not os.path.exists(src):
            print("BUILD FAILED: %s missing (needed for %s)" % (source, asset))
            return 1
        with open(src, "rb") as f:
            f.seek(offset)
            data = f.read(size)
        if len(data) != size:
            print("BUILD FAILED: %s is too short for %s" % (source, asset))
            return 1
        dst = os.path.join(ROOT, asset)
        if os.path.exists(dst) and open(dst, "rb").read() == data:
            continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as f:
            f.write(data)
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--rebuild", action="store_true", help="delete build/native first")
    ap.add_argument("--run", action="store_true", help="run build/native/dw2 after the build")
    ap.add_argument("--vblanks", type=int, default=0, help="with --run: stop after N VBlank waits")
    ap.add_argument("--no-window", action="store_true", help="with --run: SDL dummy video / audio")
    ap.add_argument("--test", action="store_true", help="run build/native/gte_test (GTE model test)")
    args = ap.parse_args()

    mingw = os.environ.get("DW2_MINGW", "D:/tools/winlibs-i686/mingw32")
    gcc = os.path.join(mingw, "bin", "gcc.exe" if os.name == "nt" else "gcc")
    ld = os.path.join(mingw, "bin", "ld.exe" if os.name == "nt" else "ld")
    ninja = find_ninja()
    if not os.path.exists(gcc):
        sys.exit("BUILD FAILED: no gcc at %s (set DW2_MINGW)" % gcc)
    if ninja is None:
        sys.exit("BUILD FAILED: no ninja (venv/Scripts/python.exe -m pip install ninja)")
    sdl3 = os.environ.get("DW2_SDL3", "D:/tools/SDL3")
    if not os.path.exists(os.path.join(sdl3, "i686-w64-mingw32", "lib", "cmake", "SDL3", "SDL3Config.cmake")):
        sys.exit("BUILD FAILED: no SDL3 MinGW release at %s (set DW2_SDL3)" % sdl3)

    import build_dw2
    if build_dw2.extract_bins(allow_missing=False) != 0 or extract_native_bins() != 0:
        sys.exit(1)
    if not os.path.exists(os.path.join(ROOT, "assets", "Ovl_LoadArea.bin")):
        sys.exit("BUILD FAILED: assets/Ovl_LoadArea.bin missing (run splat on configs/USA/main.yaml)")

    if args.rebuild and os.path.isdir(BUILD):
        # Keep dw2.pak (tools/dw2pack.py output, slow to rebuild and not a build product).
        for name in os.listdir(BUILD):
            path = os.path.join(BUILD, name)
            if name.endswith(".pak"):
                continue
            if os.path.isdir(path):
                shutil.rmtree(path)
            else:
                os.remove(path)
    env = dict(os.environ)
    env["PATH"] = os.path.join(mingw, "bin") + os.pathsep + env.get("PATH", "")
    if not os.path.exists(os.path.join(BUILD, "build.ninja")):
        cmd = ["cmake", "-G", "Ninja", "-S", ROOT, "-B", BUILD,
               "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
               "-DCMAKE_C_COMPILER=" + gcc.replace("\\", "/"),
               "-DCMAKE_LINKER=" + ld.replace("\\", "/"),
               "-DCMAKE_MAKE_PROGRAM=" + ninja.replace("\\", "/"),
               "-DDW2_SDL3=" + sdl3.replace("\\", "/")]
        if subprocess.call(cmd, env=env) != 0:
            sys.exit("BUILD FAILED: cmake configure")

    proc = subprocess.run(["cmake", "--build", BUILD, "--", "-k", "0"], env=env,
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors="replace")
    out = proc.stdout
    with open(os.path.join(BUILD, "build.log"), "w") as f:
        f.write(out)
    warnings = re.findall(r"^(.+?):\d+:\d+: warning: .*\[(-W[^\]]+)\]$", out, re.M)
    errors = re.findall(r"^(.+?):\d+:\d+: (?:fatal )?error: ", out, re.M)
    by_flag = collections.Counter(w[1] for w in warnings)
    by_file = collections.Counter(os.path.relpath(w[0], ROOT).replace("\\", "/") if os.path.isabs(w[0]) else w[0]
                                  for w in warnings)
    with open(os.path.join(BUILD, "warnings.txt"), "w") as f:
        f.write("%d warnings (this build's compiles only; --rebuild for all)\n\n" % len(warnings))
        for flag, n in by_flag.most_common():
            f.write("%6d %s\n" % (n, flag))
        f.write("\n")
        for name, n in by_file.most_common():
            f.write("%6d %s\n" % (n, name))
    if proc.returncode != 0:
        print("\n".join(l for l in out.splitlines() if "error" in l or "undefined reference" in l)[-6000:])
        sys.exit("BUILD FAILED: %d errors (build/native/build.log)" % len(errors))
    print("native build OK: build/native/dw2.exe")
    print("%d warnings in %d files (build/native/warnings.txt)" % (len(warnings), len(by_file)))
    for flag, n in by_flag.most_common(12):
        print("  %6d %s" % (n, flag))

    if args.test:
        if subprocess.call([os.path.join(BUILD, "gte_test.exe" if os.name == "nt" else "gte_test")], cwd=ROOT) != 0:
            sys.exit("TEST FAILED: gte_test")

    if args.run:
        cmd = [os.path.join(BUILD, "dw2.exe" if os.name == "nt" else "dw2")]
        if args.vblanks:
            cmd += ["--vblanks", str(args.vblanks)]
        if args.no_window:
            cmd += ["--no-window"]
        sys.exit(subprocess.call(cmd, cwd=ROOT, env=env))


if __name__ == "__main__":
    main()
