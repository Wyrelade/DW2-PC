#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host/host.h"
#include "host/host_sdl.h"
#include "host/sha256.h"

/* dw2.pak: the game's disc files, built by tools/dw2pack.py from the player's own disc image
 * (format: doc/PACK_FORMAT.md). Opened and checked once at start against the manifest compiled
 * in from configs/USA/pack_manifest.txt; any difference stops the program before Sys_Main. libcd
 * reads sectors through Host_PakSector. */

#define PAK_FILES 0xE5B
#define PAK_VERSION 1
#define PAK_HEADER_SIZE 0x50
#define PAK_ENTRY_SIZE 0x40
#define FORMAT_DATA 0 /* Form 1 only: 2048 bytes per sector */
#define FORMAT_RAW 1  /* has Form 2 sectors: 2336-byte sector body per sector */

/* The game's file table (main/cd.c, INCLUDE_BIN of the exe's table). */
extern int Cd_FileLba[];
extern unsigned short Cd_FileSectors[];

/* configs/USA/pack_manifest.txt, NUL-terminated. */
#define PAK_ASM_STR_(x) #x
#define PAK_ASM_XSTR_(x) PAK_ASM_STR_(x)
__asm__(".data\n"
        "    .globl " PAK_ASM_XSTR_(__USER_LABEL_PREFIX__) "Pak_Manifest\n"
        PAK_ASM_XSTR_(__USER_LABEL_PREFIX__) "Pak_Manifest:\n"
        "    .incbin \"configs/USA/pack_manifest.txt\"\n"
        "    .byte 0\n"
        ".text");
extern const char Pak_Manifest[];

typedef struct {
    int lba;
    int sectors;
    int format;
    Uint64 offset;
    Uint64 size;
    Uint8 sha[32];
} PakFile;

static SDL_IOStream *pak;
static PakFile files[PAK_FILES];
static unsigned short by_lba[PAK_FILES]; /* file ids sorted by LBA */
static int no_window;
#if DW2_DEV
static char pak_path[1024]; /* Host_PakReadFile opens its own stream on it */
#endif

static Uint32 rd32(const Uint8 *p) {
    return p[0] | p[1] << 8 | p[2] << 16 | (Uint32)p[3] << 24;
}

static Uint64 rd64(const Uint8 *p) {
    return rd32(p) | (Uint64)rd32(p + 4) << 32;
}

static int hexbyte(const char *s) {
    int v = 0;
    int i;

    for (i = 0; i < 2; i++) {
        char c = s[i];
        v <<= 4;
        if (c >= '0' && c <= '9') {
            v |= c - '0';
        } else if (c >= 'a' && c <= 'f') {
            v |= c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            v |= c - 'A' + 10;
        } else {
            return -1;
        }
    }
    return v;
}

/* Stops the program with the message, the pack path and how to build the pack. */
static void refuse(const char *path, const char *fmt, ...) {
    char why[512];
    char msg[1536];
    va_list ap;

    va_start(ap, fmt);
    vsnprintf(why, sizeof(why), fmt, ap);
    va_end(ap);
    snprintf(msg, sizeof(msg),
             "%s: %s\n\n"
             "dw2.exe needs dw2.pak, built from your own Digimon World 2 (USA, SLUS-01193) disc image:\n"
             "  venv/Scripts/python.exe tools/dw2pack.py \"<your image>.img\" -o build/native/dw2.pak\n"
             "Then run dw2.exe again, or pass the pack with --pak <path>.\n",
             path, why);
    fprintf(stderr, "[pak] %s", msg);
    if (!no_window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon World 2: data pack", msg, NULL);
    }
    exit(1);
}

/* The manifest's 0xE5B file hashes (the exe line is for dw2pack only). */
static void parse_manifest(Uint8 (*sha)[32]) {
    const char *p = Pak_Manifest;
    int seen = 0;

    while (*p != 0) {
        const char *line = p;
        const char *end = strchr(p, '\n');
        char *after;
        unsigned long id;
        int i;

        p = end != NULL ? end + 1 : line + strlen(line);
        if (*line == '#' || *line == '\n' || *line == '\r' || strncmp(line, "exe ", 4) == 0) {
            continue;
        }
        id = strtoul(line, &after, 16);
        if (after == line || *after != ' ' || id >= PAK_FILES) {
            fprintf(stderr, "[pak] bad manifest line: %.40s\n", line);
            exit(1);
        }
        for (i = 0; i < 32; i++) {
            int v = hexbyte(after + 1 + i * 2);
            if (v < 0) {
                fprintf(stderr, "[pak] bad manifest hash for 0x%03lX\n", id);
                exit(1);
            }
            sha[id][i] = (Uint8)v;
        }
        seen++;
    }
    if (seen != PAK_FILES) {
        fprintf(stderr, "[pak] manifest has %d files, want %d\n", seen, PAK_FILES);
        exit(1);
    }
}

static int cmp_lba(const void *a, const void *b) {
    return files[*(const unsigned short *)a].lba - files[*(const unsigned short *)b].lba;
}

static void open_pak(const char *path) {
    static Uint8 manifest[PAK_FILES][32];
    static Uint8 index[PAK_FILES * PAK_ENTRY_SIZE];
    Uint8 header[PAK_HEADER_SIZE];
    Uint8 digest[32];
    Uint8 *buf;
    Sha256 all;
    Uint64 size;
    Uint64 total = 0;
    Uint64 t0 = SDL_GetTicksNS();
    int i;

    parse_manifest(manifest);
    pak = SDL_IOFromFile(path, "rb");
    if (pak == NULL) {
        refuse(path, "cannot open (%s)", SDL_GetError());
    }
    size = (Uint64)SDL_GetIOSize(pak);
    if (SDL_ReadIO(pak, header, sizeof(header)) != sizeof(header) || memcmp(header, "DW2PAK\x1a\0", 8) != 0) {
        refuse(path, "not a dw2.pak file");
    }
    if (rd32(header + 0x08) != PAK_VERSION || rd32(header + 0x0C) != PAK_HEADER_SIZE ||
        rd32(header + 0x10) != PAK_FILES || rd32(header + 0x18) != PAK_ENTRY_SIZE || rd32(header + 0x1C) != 0) {
        refuse(path, "pack version %u with %u files, this build reads version %d with %d files (rebuild the pack)",
               rd32(header + 0x08), rd32(header + 0x10), PAK_VERSION, PAK_FILES);
    }
    if (rd64(header + 0x28) != size) {
        refuse(path, "size %llu, the header says %llu (truncated?)", (unsigned long long)size,
               (unsigned long long)rd64(header + 0x28));
    }
    if (SDL_SeekIO(pak, rd32(header + 0x14), SDL_IO_SEEK_SET) < 0 ||
        SDL_ReadIO(pak, index, sizeof(index)) != sizeof(index)) {
        refuse(path, "cannot read the index");
    }
    Sha256_Init(&all);
    for (i = 0; i < PAK_FILES; i++) {
        const Uint8 *e = index + i * PAK_ENTRY_SIZE;
        PakFile *f = &files[i];

        f->lba = (int)rd32(e + 0x04);
        f->sectors = (int)rd32(e + 0x08);
        f->format = (int)rd32(e + 0x0C);
        f->offset = rd64(e + 0x10);
        f->size = rd64(e + 0x18);
        memcpy(f->sha, e + 0x20, 32);
        if (rd32(e) != (Uint32)i || f->lba != Cd_FileLba[i] || f->sectors != Cd_FileSectors[i] ||
            (f->format != FORMAT_DATA && f->format != FORMAT_RAW) ||
            f->size != (Uint64)f->sectors * (f->format == FORMAT_RAW ? 2336 : 2048) || f->offset > size ||
            f->size > size - f->offset) {
            refuse(path, "index entry 0x%03X does not fit the game's file table", i);
        }
        if (memcmp(f->sha, manifest[i], 32) != 0) {
            refuse(path, "file 0x%03X does not match the manifest (modified or other disc)", i);
        }
        Sha256_Update(&all, f->sha, 32);
        by_lba[i] = (unsigned short)i;
        total += f->size;
    }
    Sha256_Final(&all, digest);
    if (memcmp(digest, header + 0x30, 32) != 0) {
        refuse(path, "content hash does not match the index");
    }

    /* Hash every file's data: a pack whose bytes were altered after dw2pack wrote it. */
    buf = malloc(1 << 20);
    for (i = 0; i < PAK_FILES; i++) {
        PakFile *f = &files[i];
        Uint64 left = f->size;
        Sha256 s;

        Sha256_Init(&s);
        if (SDL_SeekIO(pak, (Sint64)f->offset, SDL_IO_SEEK_SET) < 0) {
            refuse(path, "cannot seek to file 0x%03X", i);
        }
        while (left != 0) {
            size_t n = left < (1 << 20) ? (size_t)left : (1 << 20);
            if (SDL_ReadIO(pak, buf, n) != n) {
                refuse(path, "cannot read file 0x%03X", i);
            }
            Sha256_Update(&s, buf, n);
            left -= n;
        }
        Sha256_Final(&s, digest);
        if (memcmp(digest, f->sha, 32) != 0) {
            refuse(path, "file 0x%03X is damaged or altered (SHA-256 differs)", i);
        }
    }
    free(buf);
    qsort(by_lba, PAK_FILES, sizeof(by_lba[0]), cmp_lba);
#if DW2_DEV
    SDL_strlcpy(pak_path, path, sizeof(pak_path));
#endif
    printf("[pak] %s: %d files, %.1f MB, all match the manifest (checked in %.2f s)\n", path, PAK_FILES,
           total / 1e6, (SDL_GetTicksNS() - t0) / 1e9);
}

void Host_PakOpen(const char *path, int no_win) {
    char *exe_dir_pak = NULL;
    const char *base;

    no_window = no_win;
    if (path != NULL) {
        open_pak(path);
        return;
    }
    /* Default: dw2.pak next to the exe, then build/native/dw2.pak from the current directory
     * (the repo root, where tools/build_native.py --run starts it). */
    base = SDL_GetBasePath();
    if (base != NULL) {
        SDL_asprintf(&exe_dir_pak, "%sdw2.pak", base);
    }
    if (exe_dir_pak != NULL) {
        SDL_IOStream *probe = SDL_IOFromFile(exe_dir_pak, "rb");
        if (probe != NULL) {
            SDL_CloseIO(probe);
            open_pak(exe_dir_pak);
            SDL_free(exe_dir_pak);
            return;
        }
    }
    {
        SDL_IOStream *probe = SDL_IOFromFile("build/native/dw2.pak", "rb");
        if (probe != NULL) {
            SDL_CloseIO(probe);
            SDL_free(exe_dir_pak);
            open_pak("build/native/dw2.pak");
            return;
        }
    }
    refuse(exe_dir_pak != NULL ? exe_dir_pak : "dw2.pak", "not found (also looked for build/native/dw2.pak)");
}

/* The file holding sector `lba` (binary search over the LBA-sorted index), or -1. */
static int file_at(int lba) {
    int lo = 0;
    int hi = PAK_FILES - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        const PakFile *f = &files[by_lba[mid]];
        if (lba < f->lba) {
            hi = mid - 1;
        } else if (lba >= f->lba + f->sectors) {
            lo = mid + 1;
        } else {
            return by_lba[mid];
        }
    }
    return -1;
}

int Host_PakFileAt(int lba, int *sectors) {
    int id = file_at(lba);

    *sectors = id < 0 ? 0 : files[id].sectors;
    return id;
}

int Host_PakSector(int lba, unsigned char *body) {
    static const unsigned char form1_subheader[8] = { 0, 0, 0x08, 0, 0, 0, 0x08, 0 };
    int id = file_at(lba);
    const PakFile *f;
    Uint64 at;

    memset(body, 0, 2336);
    if (id < 0) {
        return -1;
    }
    f = &files[id];
    if (f->format == FORMAT_RAW) {
        at = f->offset + (Uint64)(lba - f->lba) * 2336;
        SDL_SeekIO(pak, (Sint64)at, SDL_IO_SEEK_SET);
        SDL_ReadIO(pak, body, 2336);
    } else {
        at = f->offset + (Uint64)(lba - f->lba) * 2048;
        memcpy(body, form1_subheader, 8);
        SDL_SeekIO(pak, (Sint64)at, SDL_IO_SEEK_SET);
        SDL_ReadIO(pak, body + 8, 2048);
    }
    return id;
}

#if DW2_DEV
/* Dev tools (PD.7), main thread: the whole Form 1 file `id` in a malloc'd buffer (*size bytes),
 * read through a stream of its own, so the game thread's sector reads are not disturbed. NULL
 * before Host_PakOpen, for Form 2 files and on read errors. The pack was checked at open. */
void *Host_PakReadFile(int id, int *size) {
    SDL_IOStream *io;
    const PakFile *f;
    void *buf;

    *size = 0;
    if (pak_path[0] == 0 || id < 0 || id >= PAK_FILES || files[id].format != FORMAT_DATA) {
        return NULL;
    }
    f = &files[id];
    io = SDL_IOFromFile(pak_path, "rb");
    if (io == NULL) {
        return NULL;
    }
    buf = malloc((size_t)f->size + 1);
    if (buf != NULL && (SDL_SeekIO(io, (Sint64)f->offset, SDL_IO_SEEK_SET) < 0 ||
                        SDL_ReadIO(io, buf, (size_t)f->size) != (size_t)f->size)) {
        free(buf);
        buf = NULL;
    }
    SDL_CloseIO(io);
    if (buf != NULL) {
        ((Uint8 *)buf)[f->size] = 0xFF; /* a text walk off the end stops here */
        *size = (int)f->size;
    }
    return buf;
}
#endif
