"""Reference values for tests/gte_test.c from the GTE of PCSX-Redux.

    venv/Scripts/python.exe tools/gte_probe.py [--redux PATH] [--bios PATH]

1. build/native/gte_test.exe --write-cases writes the command cases (64 words each: control
   registers 0..30, data registers 0..30, command word, op index).
2. A small PS-X EXE (MIPS asm below, assembled with tools/windows/binutils) loads each case into
   the GTE with ctc2 / mtc2, runs the command word, and stores data registers 0..31 and FLAG.
3. PCSX-Redux runs it (-loadexe) with a Lua script that waits for the done marker and writes the
   results; they become tests/gte_ref.bin (33 words per case).

No game data is involved: the EXE holds only this code and the generated cases. The BIOS image
is the user's (default D:/wc3maps/dw2test/scph1001.bin).
"""

import argparse
import glob
import os
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BIN = os.path.join(ROOT, "tools", "windows", "binutils")
WORK = os.path.join(ROOT, "build", "gte_probe")

CASE_WORDS = 64
OUT_WORDS = 33
LOAD = 0x80010000
CASES = 0x80020000
MARK = 0x80100000
RESULTS = 0x80110000
DONE = 0x600DC0DE


def asm_source(ncases, ops):
    out = [
        ".set noreorder", ".set noat", ".text", ".globl _start", "_start:",
        "mfc0 $8, $12", "lui $9, 0x4000", "or $8, $8, $9", "mtc0 $8, $12", "nop", "nop",
        "li $16, 0x%08X" % CASES, "li $17, 0x%08X" % RESULTS, "li $18, %d" % ncases,
        "loop:", "beqz $18, done", "nop",
    ]
    for i in range(31):
        out += ["lw $8, %d($16)" % (i * 4), "nop", "ctc2 $8, $%d" % i]
    for i in range(31):
        if i in (15, 28, 29):
            continue
        out += ["lw $8, %d($16)" % ((31 + i) * 4), "nop", "mtc2 $8, $%d" % i]
    out += [
        "lw $25, %d($16)" % ((CASE_WORDS - 1) * 4), "nop", "sll $25, $25, 5",
        "la $24, ops", "addu $24, $24, $25", "jr $24", "nop",
        ".balign 32", "ops:",
    ]
    for op in ops:
        out += ["nop", "nop", ".word 0x%08X" % op, "nop", "nop", "j after", "nop", "nop"]
    out += ["after:"]
    for i in range(32):
        out += ["mfc2 $8, $%d" % i, "nop", "sw $8, %d($17)" % (i * 4)]
    out += [
        "cfc2 $8, $31", "nop", "sw $8, 128($17)",
        "addiu $16, $16, %d" % (CASE_WORDS * 4), "addiu $17, $17, %d" % (OUT_WORDS * 4),
        "addiu $18, $18, -1", "j loop", "nop",
        "done:", "li $8, 0x%08X" % MARK, "li $9, 0x%08X" % DONE, "sw $9, 0($8)",
        "spin:", "j spin", "nop",
    ]
    return "\n".join(out) + "\n"


LUA = r"""
local ffi = require('ffi')
local MARK = %d
local RES = %d
local LEN = %d
local OUT = '%s'
local frames = 0
listener = PCSX.Events.createEventListener('GPU::Vsync', function()
  frames = frames + 1
  local mem = PCSX.getMemPtr()
  local m = ffi.cast('uint32_t *', mem + MARK)[0]
  if m == 0x%08X then
    local f = io.open(OUT, 'wb')
    f:write(ffi.string(mem + RES, LEN))
    f:close()
    PCSX.quit(0)
  elseif frames > 3000 then
    local f = io.open(OUT .. '.timeout', 'w')
    f:write('no done marker after 3000 frames\n')
    f:close()
    PCSX.quit(1)
  end
end)
"""


def run(cmd, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, **kw)
    if r.returncode != 0:
        sys.exit("FAILED: %s\n%s%s" % (" ".join(cmd), r.stdout, r.stderr))
    return r


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--redux", help="pcsx-redux.exe (default: the WinGet package)")
    ap.add_argument("--bios", default="D:/wc3maps/dw2test/scph1001.bin")
    args = ap.parse_args()
    redux = args.redux
    if not redux:
        pk = os.path.join(os.environ.get("LOCALAPPDATA", ""), "Microsoft", "WinGet", "Packages")
        hits = glob.glob(os.path.join(pk, "*PCSX-Redux*", "**", "pcsx-redux.exe"), recursive=True)
        if not hits:
            sys.exit("pcsx-redux.exe not found; pass --redux")
        redux = hits[0]
    os.makedirs(WORK, exist_ok=True)
    cases = os.path.join(WORK, "cases.bin")
    run([os.path.join(ROOT, "build", "native", "gte_test.exe"), "--write-cases", cases])
    data = open(cases, "rb").read()
    ncases = len(data) // (CASE_WORDS * 4)
    if ncases * OUT_WORDS * 4 > 0x80200000 - RESULTS or CASES + len(data) > MARK:
        sys.exit("cases do not fit the probe memory map")

    s = os.path.join(WORK, "probe.s")
    # Word 62 of each case is the command word, word 63 its index (the ops[] table of gte_test.c).
    ops = {}
    for k in range(ncases):
        word, index = struct.unpack_from("<II", data, k * CASE_WORDS * 4 + (CASE_WORDS - 2) * 4)
        ops[index] = word
    ops = [ops[i] for i in range(len(ops))]
    open(s, "w").write(asm_source(ncases, ops))
    o = os.path.join(WORK, "probe.o")
    elf = os.path.join(WORK, "probe.elf")
    code = os.path.join(WORK, "probe.bin")
    run([os.path.join(BIN, "mips-linux-gnu-as.exe"), "-EL", "-march=r3000", "-mabi=32", "-no-pad-sections",
         "-o", o, s])
    run([os.path.join(BIN, "mips-linux-gnu-ld.exe"), "-EL", "-Ttext", "0x%08X" % LOAD, "-e", "_start",
         "-o", elf, o])
    run([os.path.join(BIN, "mips-linux-gnu-objcopy.exe"), "-O", "binary", "-j", ".text", elf, code])
    text = open(code, "rb").read()
    if LOAD + len(text) > CASES:
        sys.exit("probe code too large")
    body = text + b"\0" * (CASES - LOAD - len(text)) + data
    body += b"\0" * (-len(body) % 0x800)
    hdr = bytearray(0x800)
    hdr[0:8] = b"PS-X EXE"
    struct.pack_into("<IIII", hdr, 0x10, LOAD, 0, LOAD, len(body))
    struct.pack_into("<II", hdr, 0x30, 0x801FFFF0, 0)
    exe = os.path.join(WORK, "gteprobe.exe")
    open(exe, "wb").write(bytes(hdr) + body)

    out = os.path.join(WORK, "results.bin").replace("\\", "/")
    for p in (out, out + ".timeout"):
        if os.path.exists(p):
            os.remove(p)
    lua = os.path.join(WORK, "probe.lua")
    open(lua, "w").write(LUA % (MARK & 0x1FFFFF, RESULTS & 0x1FFFFF, ncases * OUT_WORDS * 4, out, DONE))
    subprocess.run([redux, "-run", "-bios", os.path.abspath(args.bios), "-loadexe", exe, "-dofile", lua,
                    "-fastboot"], cwd=WORK, timeout=300)
    if not os.path.exists(out):
        sys.exit("FAILED: no results (%s)" % ("timeout" if os.path.exists(out + ".timeout") else "Redux exit"))
    res = open(out, "rb").read()
    ref = os.path.join(ROOT, "tests", "gte_ref.bin")
    open(ref, "wb").write(res)
    print("%d cases run on PCSX-Redux: %s (%d bytes)" % (ncases, os.path.relpath(ref, ROOT), len(res)))


if __name__ == "__main__":
    main()
