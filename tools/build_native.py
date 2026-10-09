#!/usr/bin/env python3
"""Native PC build (DW2_NATIVE): configure CMakeLists.txt with Ninja and GCC, build dw2, count
the compiler warnings.

    venv/Scripts/python.exe tools/build_native.py            # configure if needed, build
    venv/Scripts/python.exe tools/build_native.py --rebuild  # clean build (full warning count)
    venv/Scripts/python.exe tools/build_native.py --run [--vblanks N] [--no-window]
    venv/Scripts/python.exe tools/build_native.py --test     # also run gte_test
    venv/Scripts/python.exe tools/build_native.py --arch x64 # 64-bit Windows build
    venv/Scripts/python.exe tools/build_native.py --release  # release client (DW2_DEV=OFF)

Dev builds (the default) have the ImGui dev overlay and the PD dev tools (C++ with g++ from the
same toolchain); --release builds the client without them into build/<dir>_rel.

Targets (--arch): on Windows x86 (default; MinGW-w64 i686, build/native/dw2.exe) or x64
(MinGW-w64 x86_64, build/native64/dw2.exe); on Linux x64 only (system gcc, build/linux64/dw2),
run as `python3 tools/build_native.py` there.

Toolchain: DW2_MINGW = the MinGW-w64 root holding bin/gcc.exe (default
D:/tools/winlibs-i686/mingw32 for x86, D:/tools/winlibs-x86_64/mingw64 for x64); Ninja from the
venv (pip install ninja) or PATH; DW2_SDL3 = the SDL3 MinGW development release root (default
D:/tools/SDL3, SDL3-devel-3.x-mingw unpacked); Linux uses the system SDL3 (libsdl3-dev). The
INCLUDE_BIN assets come from the user's disc dump like in tools/build_dw2.py
(configs/USA/include_bin.txt); assets/Ovl_LoadArea.bin comes from splat."""

import argparse
import collections
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WINDOWS = os.name == "nt"
BUILD_DIRS = {"x86": "native", "x64": "native64"} if WINDOWS else {"x64": "linux64"}
MINGW_DEFAULT = {"x86": "D:/tools/winlibs-i686/mingw32", "x64": "D:/tools/winlibs-x86_64/mingw64"}
SDL3_TRIPLET = {"x86": "i686-w64-mingw32", "x64": "x86_64-w64-mingw32"}
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
    ap.add_argument("--arch", choices=sorted(BUILD_DIRS), default="x86" if WINDOWS else "x64",
                    help="target (Windows: x86 or x64; Linux: x64)")
    ap.add_argument("--rebuild", action="store_true", help="delete the build directory first")
    ap.add_argument("--run", action="store_true", help="run build/native/dw2 after the build")
    ap.add_argument("--vblanks", type=int, default=0, help="with --run: stop after N VBlank waits")
    ap.add_argument("--no-window", action="store_true", help="with --run: SDL dummy video / audio")
    ap.add_argument("--test", action="store_true", help="run build/native/gte_test (GTE model test)")
    ap.add_argument("--release", action="store_true",
                    help="release client: DW2_DEV=OFF (no ImGui, no dev tools), build/<dir>_rel")
    args = ap.parse_args()

    build = os.path.join(ROOT, "build", BUILD_DIRS[args.arch] + ("_rel" if args.release else ""))
    rel_build = os.path.relpath(build, ROOT).replace("\\", "/")
    if WINDOWS:
        mingw = os.environ.get("DW2_MINGW", MINGW_DEFAULT[args.arch])
        gcc = os.path.join(mingw, "bin", "gcc.exe")
        gxx = os.path.join(mingw, "bin", "g++.exe")
        ld = os.path.join(mingw, "bin", "ld.exe")
        if not os.path.exists(gcc):
            sys.exit("BUILD FAILED: no gcc at %s (set DW2_MINGW)" % gcc)
        sdl3 = os.environ.get("DW2_SDL3", "D:/tools/SDL3")
        if not os.path.exists(os.path.join(sdl3, SDL3_TRIPLET[args.arch], "lib", "cmake", "SDL3", "SDL3Config.cmake")):
            sys.exit("BUILD FAILED: no SDL3 MinGW release at %s (set DW2_SDL3)" % sdl3)
    else:
        mingw = None
        gcc = shutil.which("gcc")
        gxx = shutil.which("g++")
        ld = shutil.which("ld")
        if gcc is None or ld is None:
            sys.exit("BUILD FAILED: no gcc / ld in PATH")
    if not args.release and (gxx is None or not os.path.exists(gxx)):
        sys.exit("BUILD FAILED: no g++ next to gcc (the dev build has C++; --release has none)")
    ninja = find_ninja()
    if ninja is None:
        sys.exit("BUILD FAILED: no ninja (venv/Scripts/python.exe -m pip install ninja)")

    import build_dw2
    if build_dw2.extract_bins(allow_missing=False) != 0 or extract_native_bins() != 0:
        sys.exit(1)
    if not os.path.exists(os.path.join(ROOT, "assets", "Ovl_LoadArea.bin")):
        sys.exit("BUILD FAILED: assets/Ovl_LoadArea.bin missing (run splat on configs/USA/main.yaml)")

    if args.rebuild and os.path.isdir(build):
        # Keep dw2.pak (tools/dw2pack.py output, slow to rebuild and not a build product).
        for name in os.listdir(build):
            path = os.path.join(build, name)
            if name.endswith(".pak"):
                continue
            if os.path.isdir(path):
                shutil.rmtree(path)
            else:
                os.remove(path)
    env = dict(os.environ)
    if mingw:
        env["PATH"] = os.path.join(mingw, "bin") + os.pathsep + env.get("PATH", "")
    if not os.path.exists(os.path.join(build, "build.ninja")):
        cmd = ["cmake", "-G", "Ninja", "-S", ROOT, "-B", build,
               "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
               "-DCMAKE_C_COMPILER=" + gcc.replace("\\", "/"),
               "-DCMAKE_LINKER=" + ld.replace("\\", "/"),
               "-DCMAKE_MAKE_PROGRAM=" + ninja.replace("\\", "/"),
               "-DDW2_DEV=" + ("OFF" if args.release else "ON")]
        if not args.release:
            cmd.append("-DCMAKE_CXX_COMPILER=" + gxx.replace("\\", "/"))
        if WINDOWS:
            cmd.append("-DDW2_SDL3=" + sdl3.replace("\\", "/"))
        if subprocess.call(cmd, env=env) != 0:
            sys.exit("BUILD FAILED: cmake configure")

    proc = subprocess.run(["cmake", "--build", build, "--", "-k", "0"], env=env,
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors="replace")
    out = proc.stdout
    with open(os.path.join(build, "build.log"), "w") as f:
        f.write(out)
    warnings = re.findall(r"^(.+?):\d+:\d+: warning: .*\[(-W[^\]]+)\]$", out, re.M)
    errors = re.findall(r"^(.+?):\d+:\d+: (?:fatal )?error: ", out, re.M)
    by_flag = collections.Counter(w[1] for w in warnings)
    by_file = collections.Counter(os.path.relpath(w[0], ROOT).replace("\\", "/") if os.path.isabs(w[0]) else w[0]
                                  for w in warnings)
    with open(os.path.join(build, "warnings.txt"), "w") as f:
        f.write("%d warnings (this build's compiles only; --rebuild for all)\n\n" % len(warnings))
        for flag, n in by_flag.most_common():
            f.write("%6d %s\n" % (n, flag))
        f.write("\n")
        for name, n in by_file.most_common():
            f.write("%6d %s\n" % (n, name))
    if proc.returncode != 0:
        print("\n".join(l for l in out.splitlines() if "error" in l or "undefined reference" in l)[-6000:])
        sys.exit("BUILD FAILED: %d errors (%s/build.log)" % (len(errors), rel_build))
    exe = "dw2.exe" if WINDOWS else "dw2"
    print("native build OK: %s/%s" % (rel_build, exe))
    print("%d warnings in %d files (%s/warnings.txt)" % (len(warnings), len(by_file), rel_build))
    for flag, n in by_flag.most_common(12):
        print("  %6d %s" % (n, flag))

    if args.test:
        if subprocess.call([os.path.join(build, "gte_test.exe" if WINDOWS else "gte_test")], cwd=ROOT) != 0:
            sys.exit("TEST FAILED: gte_test")

    if args.run:
        cmd = [os.path.join(build, exe)]
        if args.vblanks:
            cmd += ["--vblanks", str(args.vblanks)]
        if args.no_window:
            cmd += ["--no-window"]
        sys.exit(subprocess.call(cmd, cwd=ROOT, env=env))


if __name__ == "__main__":
    main()
