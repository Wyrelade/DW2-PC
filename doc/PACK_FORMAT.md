# dw2.pak format (version 1)

The native build reads the game's disc files from `dw2.pak`, never from a disc image. Players
build the pack from their own Digimon World 2 USA (SLUS-01193) disc image:

```
venv/Scripts/python.exe tools/dw2pack.py "<path to image>.img" [-o build/native/dw2.pak]
```

`tools/dw2pack.py` reads the raw image (2352-byte sectors), takes SLUS_011.93 from the ISO9660
root, reads the game's file table from it (`Cd_FileLba` s32[0xE5B] at file offset 0x33F94,
`Cd_FileSectors` u16[0xE5B] at 0x37900) and extracts every file id by LBA and sector count. The
game data is outside the ISO9660 tree, so a file-system extract cannot replace this. Nothing
from the disc is committed or shipped.

## Integrity

`configs/USA/pack_manifest.txt` holds one SHA-256 per file (and one for SLUS_011.93, which only
supplies the file table). Hashes only, no game data. dw2pack rejects an image whose exe or any
file does not match and writes no pack. dw2.exe checks the pack against the same manifest
(compiled in) at start and refuses to run on any difference. There are no override folders or
mod layers. The manifest was written once from a dump checked against the retail SHA-1s of
SLUS_011.93 and the 7 STAG*.PRO (`dw2pack.py --write-manifest`).

## Layout

All integers little endian. Offsets are absolute file offsets.

Header (0x50 bytes):

| Offset | Type      | Field                                                     |
|--------|-----------|-----------------------------------------------------------|
| 0x00   | u8[8]     | magic `"DW2PAK\x1a\0"`                                    |
| 0x08   | u32       | version = 1                                               |
| 0x0C   | u32       | header size = 0x50                                        |
| 0x10   | u32       | file count = 0xE5B                                        |
| 0x14   | u32       | index offset = 0x50                                       |
| 0x18   | u32       | index entry size = 0x40                                   |
| 0x1C   | u32       | flags = 0 (no compression)                                |
| 0x20   | u64       | data offset (first file)                                  |
| 0x28   | u64       | pack size in bytes                                        |
| 0x30   | u8[32]    | content hash: SHA-256 of the 0xE5B file SHA-256s in id order |

Index: file count entries of 0x40 bytes, in file id order (entry i is file id i):

| Offset | Type   | Field                                                         |
|--------|--------|---------------------------------------------------------------|
| 0x00   | u32    | file id (Cd_FileLba index)                                    |
| 0x04   | u32    | disc LBA of the first sector (= Cd_FileLba[id])               |
| 0x08   | u32    | sectors (= Cd_FileSectors[id])                                |
| 0x0C   | u32    | format (below)                                                |
| 0x10   | u64    | data offset                                                   |
| 0x18   | u64    | data size = sectors * bytes per sector                        |
| 0x20   | u8[32] | SHA-256 of the data                                           |

Formats:

- 0: every sector is Mode 2 Form 1. Data = the 2048 user bytes of each sector.
- 1: the file has Form 2 sectors (XA audio, STR movies; 34 files). Data = the 2336-byte sector
  body of each sector after the 16-byte sync + header: subheader (8), then 2328 bytes (Form 1:
  2048 data + EDC / ECC; Form 2: 2324 data + EDC). Kept raw for the XA / STR work (P1.8, P1.10).

File data starts at 0x800-aligned offsets (zero padding between files). The content hash
identifies the pack contents independent of the layout (online: sent at login, P3).

## Game side

`dw2.exe [--pak <path>]` (default: `dw2.pak` next to the exe, then `build/native/dw2.pak`).
At start it checks magic, version, count, and for each entry: id, LBA and sectors against the
game's own table, size against the format, the SHA-256 against the manifest, then hashes all
file data. libcd serves sectors from the pack: a read at an LBA maps to the file holding it and
the sector inside it; the CdGetSector header (MSF, mode) is synthesized from the LBA, the
subheader too for format 0 (Form 1 data), format 1 sectors use their stored subheader.

Compression is not in version 1 (flags = 0); a later version may add it.
