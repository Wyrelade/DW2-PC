#!/usr/bin/env python3
"""Build dw2.pak (the native game's data pack) from your own Digimon World 2 disc image.

    venv/Scripts/python.exe tools/dw2pack.py <image.img> [-o build/native/dw2.pak]

The image is a raw 2352-byte-sector dump of the USA disc (SLUS-01193), e.g. a CloneCD .img or a
single-track .bin. The game data (0xE5B files) lies outside the ISO9660 tree; it is found through
the game's own file table (Cd_FileLba / Cd_FileSectors in SLUS_011.93, read from the image).
Every file is checked against configs/USA/pack_manifest.txt (SHA-256 per file, no game data); a
disc that does not match is rejected and no pack is written. Pack format: doc/PACK_FORMAT.md.

    --write-manifest   (once, from a verified dump) write configs/USA/pack_manifest.txt instead
                       of checking against it. Needs the checks against the retail SHA-1s of
                       SLUS_011.93 and the 7 STAG*.PRO (configs/USA/*.yaml) and dumps/disc.
"""

import argparse
import glob
import hashlib
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MANIFEST = os.path.join(ROOT, "configs", "USA", "pack_manifest.txt")

RAW = 2352                 # raw sector: sync 12, header 4, subheader 8, data 2328
FILE_COUNT = 0xE5B
# File table in SLUS_011.93 (file offsets, as in configs/USA/include_bin.txt and
# include_bin_native.txt): Cd_FileLba s32[0xE5B], Cd_FileSectors u16[0xE5B].
EXE_LBA_TABLE = 0x33F94
EXE_SECTOR_TABLE = 0x37900
EXE_BOOT_TIM = 0x53B60     # Ovl_LoadArea: the exe's initial overlay area (boot TIM)

PAK_MAGIC = b"DW2PAK\x1a\x00"
PAK_VERSION = 1
HEADER_SIZE = 0x50
ENTRY_SIZE = 0x40
ALIGN = 0x800
FORMAT_DATA = 0            # Form 1 only: 2048 bytes of user data per sector
FORMAT_RAW = 1             # has Form 2 sectors (XA / STR): 2336-byte sector body per sector
BYTES_PER_SECTOR = {FORMAT_DATA: 2048, FORMAT_RAW: 2336}

# Retail SHA-1s (configs/USA/*.yaml, tools/build_dw2.py) and Ovl_FileIds (main/gamemode.c).
EXE_SHA1 = "e55ed5bf354def07f0cbf4e1fb7fb5f99204f220"
OVERLAYS = [  # (file id, name, sha1)
    (0x190, "STAG0000.PRO", "ff37a7c6bb5fa96da2887731fac1ea52c6033a6d"),
    (0x191, "STAG1000.PRO", "ba428a84fbe2b2084ca6e12fd88067790e43fd7f"),
    (0xD1E, "STAG1100.PRO", "24b68697c3b018fc1795d0ea57c845b92e298612"),
    (0x192, "STAG2000.PRO", "9e8f8a1f1eb3aacda2b4a3492abce26264ee9029"),
    (0x193, "STAG3000.PRO", "6aaf6f61f2af3d9b7379764912cf09b42c2af52b"),
    (0xD4D, "STAG3500.PRO", "79b8c96b9ea1c11b45ebc223eeb14bf5a5f54812"),
    (0x19A, "STAG4000.PRO", "2623a98843a5943269af3c06fc20cb54a3bd23ca"),
]


class DiscError(Exception):
    pass


def bcd(v):
    return (v // 10) * 16 + v % 10


class Image:
    def __init__(self, path):
        self.f = open(path, "rb")
        size = os.path.getsize(path)
        if size % RAW != 0:
            raise DiscError("%s: size %d is not a multiple of %d (need a raw 2352-byte-sector image)"
                            % (path, size, RAW))
        self.sectors = size // RAW

    def raw(self, lba, count):
        """count raw sectors from lba, each checked: sync pattern, header MSF = lba, mode 2."""
        if lba + count > self.sectors:
            raise DiscError("sectors %d..%d past the end of the image (%d)" % (lba, lba + count, self.sectors))
        self.f.seek(lba * RAW)
        data = self.f.read(count * RAW)
        for i in range(count):
            s = data[i * RAW:i * RAW + 16]
            a = lba + i + 150
            if s[:12] != b"\x00" + b"\xff" * 10 + b"\x00" or \
                    s[12:16] != bytes((bcd(a // 4500), bcd(a // 75 % 60), bcd(a % 75), 2)):
                raise DiscError("sector %d: bad sync / header %s (not a raw Mode 2 image?)" % (lba + i, s.hex()))
        return data

    def data(self, lba, count):
        """Form 1 user data (2048 bytes per sector)."""
        raw = self.raw(lba, count)
        return b"".join(raw[i * RAW + 24:i * RAW + 24 + 2048] for i in range(count))

    def iso_file(self, name):
        """A file in the ISO9660 root directory."""
        pvd = self.data(16, 1)
        if pvd[1:6] != b"CD001":
            raise DiscError("no ISO9660 volume descriptor at sector 16")
        root = pvd[156:156 + 34]
        lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
        d = self.data(lba, (size + 2047) // 2048)
        pos = 0
        while pos < size:
            n = d[pos]
            if n == 0:  # records do not cross sectors
                pos = (pos // 2048 + 1) * 2048
                continue
            ident = d[pos + 33:pos + 33 + d[pos + 32]].decode("latin-1").split(";")[0]
            if ident.upper() == name.upper():
                flba, fsize = struct.unpack_from("<I", d, pos + 2)[0], struct.unpack_from("<I", d, pos + 10)[0]
                return self.data(flba, (fsize + 2047) // 2048)[:fsize]
            pos += n
        raise DiscError("%s not found in the disc's root directory" % name)


def read_files(img):
    """Yield (id, lba, sectors, format, bytes) for every file of the game's file table."""
    exe = img.iso_file("SLUS_011.93")
    lbas = struct.unpack_from("<%di" % FILE_COUNT, exe, EXE_LBA_TABLE)
    counts = struct.unpack_from("<%dH" % FILE_COUNT, exe, EXE_SECTOR_TABLE)
    yield ("exe", 0, 0, FORMAT_DATA, exe)
    for i in range(FILE_COUNT):
        raw = img.raw(lbas[i], counts[i])
        form2 = any(raw[k * RAW + 18] & 0x20 for k in range(counts[i]))
        if form2:
            body = b"".join(raw[k * RAW + 16:(k + 1) * RAW] for k in range(counts[i]))
            yield (i, lbas[i], counts[i], FORMAT_RAW, body)
        else:
            body = b"".join(raw[k * RAW + 24:k * RAW + 24 + 2048] for k in range(counts[i]))
            yield (i, lbas[i], counts[i], FORMAT_DATA, body)


def read_manifest():
    if not os.path.exists(MANIFEST):
        raise DiscError("%s missing" % MANIFEST)
    m = {}
    for line in open(MANIFEST):
        line = line.split("#", 1)[0].split()
        if not line:
            continue
        key = "exe" if line[0] == "exe" else int(line[0], 16)
        m[key] = line[1]
    if len(m) != FILE_COUNT + 1:
        raise DiscError("%s: %d entries, want %d" % (MANIFEST, len(m), FILE_COUNT + 1))
    return m


def check_known_content(files, dumps):
    """--write-manifest only: the dump must be the retail disc. Exe and overlays against the
    retail SHA-1s, against the dumps/disc copies, the boot TIM and a sound bank header."""
    problems = []
    exe = files["exe"][3]
    if hashlib.sha1(exe).hexdigest() != EXE_SHA1:
        problems.append("SLUS_011.93 SHA-1 is not the retail one")
    p = os.path.join(dumps, "SLUS_011.93")
    if not os.path.exists(p) or open(p, "rb").read() != exe:
        problems.append("SLUS_011.93 differs from %s" % p)
    for fid, name, sha in OVERLAYS:
        p = os.path.join(dumps, "AAA", "3.PRO", name)
        ref = open(p, "rb").read() if os.path.exists(p) else None
        data = files[fid][3]
        if ref is None:
            problems.append("%s missing" % p)
            continue
        if data[:len(ref)] != ref or data[len(ref):].strip(b"\x00") or (len(data) + 2047) // 2048 != (len(ref) + 2047) // 2048:
            problems.append("file 0x%03X differs from %s" % (fid, p))
        if hashlib.sha1(data[:len(ref)]).hexdigest() != sha:
            problems.append("file 0x%03X (%s) SHA-1 is not the retail one" % (fid, name))
    tim = exe[EXE_BOOT_TIM:]
    ola = os.path.join(ROOT, "assets", "Ovl_LoadArea.bin")
    if struct.unpack_from("<II", tim) != (0x10, 2):
        problems.append("no 16 bpp TIM at the exe's overlay area (boot TIM)")
    if os.path.exists(ola) and not tim.startswith(open(ola, "rb").read()):
        problems.append("boot TIM differs from assets/Ovl_LoadArea.bin")
    vh = files[0xE35][3]
    if struct.unpack_from("<I", vh)[0] != 8 or vh[8:12] != b"pBAV" or struct.unpack_from("<I", vh, 12)[0] != 7:
        problems.append("file 0xE35 is not the expected sound bank header (offset 8, pBAV version 7)")
    return problems


def write_pack(out, files):
    ids = list(range(FILE_COUNT))
    index = bytearray()
    offset = (HEADER_SIZE + ENTRY_SIZE * FILE_COUNT + ALIGN - 1) // ALIGN * ALIGN
    layout = []
    for i in ids:
        lba, count, fmt, data, digest = files[i]
        index += struct.pack("<IIIIQQ32s", i, lba, count, fmt, offset, len(data), digest)
        layout.append(offset)
        offset = (offset + len(data) + ALIGN - 1) // ALIGN * ALIGN
    content = hashlib.sha256(b"".join(files[i][4] for i in ids)).digest()
    header = struct.pack("<8sIIIIII QQ32s", PAK_MAGIC, PAK_VERSION, HEADER_SIZE, FILE_COUNT, HEADER_SIZE,
                         ENTRY_SIZE, 0, layout[0], offset, content)
    assert len(header) == HEADER_SIZE
    tmp = out + ".tmp"
    with open(tmp, "wb") as f:
        f.write(header)
        f.write(index)
        for i, off in zip(ids, layout):
            f.seek(off)
            f.write(files[i][3])
        f.truncate(offset)
    # Read back and verify every file before the pack takes its name.
    with open(tmp, "rb") as f:
        for i, off in zip(ids, layout):
            f.seek(off)
            if hashlib.sha256(f.read(len(files[i][3]))).digest() != files[i][4]:
                raise DiscError("%s: file 0x%03X does not read back (disk error?)" % (tmp, i))
    os.replace(tmp, out)
    return offset, content


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("image", help="raw 2352-byte-sector disc image (.img / .bin), or its folder")
    ap.add_argument("-o", "--out", default=os.path.join(ROOT, "build", "native", "dw2.pak"),
                    help="pack to write (default build/native/dw2.pak, next to dw2.exe)")
    ap.add_argument("--write-manifest", action="store_true",
                    help="write configs/USA/pack_manifest.txt from this (verified) dump")
    ap.add_argument("--dumps", default=os.path.join(ROOT, "dumps", "disc"),
                    help="with --write-manifest: the dumpsxiso tree to compare with")
    args = ap.parse_args()

    image = args.image
    if os.path.isdir(image):
        found = sorted(glob.glob(os.path.join(glob.escape(image), "*.img")) + glob.glob(os.path.join(glob.escape(image), "*.bin")))
        if len(found) != 1:
            sys.exit("dw2pack: %s: want exactly one .img / .bin, found %d" % (image, len(found)))
        image = found[0]
    try:
        img = Image(image)
        manifest = None if args.write_manifest else read_manifest()
        files = {}
        bad = []
        for fid, lba, count, fmt, data in read_files(img):
            digest = hashlib.sha256(data).digest()
            files[fid] = (lba, count, fmt, data, digest)
            if manifest is not None and manifest[fid] != digest.hex():
                bad.append(fid)
                if fid == "exe":
                    break  # the file table itself is not the retail one
        if bad:
            names = ", ".join("SLUS_011.93" if b == "exe" else "0x%03X" % b for b in bad[:12])
            raise DiscError("%d file(s) do not match the manifest: %s%s\n"
                            "This is not an unmodified Digimon World 2 USA (SLUS-01193) disc image."
                            % (len(bad), names, " ..." if len(bad) > 12 else ""))
        if args.write_manifest:
            problems = check_known_content(files, args.dumps)
            if problems:
                raise DiscError("not writing the manifest:\n  " + "\n  ".join(problems))
            with open(MANIFEST, "w", newline="\n") as f:
                f.write("# DW2-Online pack manifest: SHA-256 of every file of the USA disc (SLUS-01193)\n"
                        "# as tools/dw2pack.py extracts it (doc/PACK_FORMAT.md). Hashes only, no game data.\n"
                        "# exe = SLUS_011.93 (holds the file table; not in the pack). Then one line per\n"
                        "# file id (Cd_FileLba index).\n")
                f.write("exe %s\n" % files["exe"][4].hex())
                for i in range(FILE_COUNT):
                    f.write("0x%03X %s\n" % (i, files[i][4].hex()))
            print("dw2pack: wrote %s (%d files)" % (os.path.relpath(MANIFEST, ROOT), FILE_COUNT))
        out = os.path.abspath(args.out)
        os.makedirs(os.path.dirname(out), exist_ok=True)
        size, content = write_pack(out, files)
    except DiscError as e:
        sys.exit("dw2pack: %s" % e)
    raw = sum(1 for i in range(FILE_COUNT) if files[i][2] == FORMAT_RAW)
    print("dw2pack: all %d files match the manifest (%d with Form 2 sectors kept raw)" % (FILE_COUNT, raw))
    print("dw2pack: wrote %s (%.1f MB, content %s)" % (out, size / 1e6, content.hex()[:16]))


if __name__ == "__main__":
    main()
