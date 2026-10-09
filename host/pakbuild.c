#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host/host.h"
#include "host/host_sdl.h"
#include "host/sha256.h"

/* First-start pack build (PR.1): finds the player's Digimon World 2 disc image and writes dw2.pak
 * from it, step for step as tools/dw2pack.py does (the reference; both give the same bytes).
 * Runs on the main thread before the game thread and the game window exist.
 *
 * Images: raw 2352-byte sectors (.img, .bin, a raw .iso) or a .cue naming one (its TRACK 01 must
 * be MODE2/2352 at the start of the file). A 2048-byte .iso is detected and explained: it has lost
 * the Form 2 sectors (XA audio, movies). The game data lies outside the ISO9660 tree: the files
 * are found through the game's own file table in SLUS_011.93, which must match the manifest
 * first; then every file's SHA-256 must match, or no pack is written. */

#define RAW 2352 /* raw sector: sync 12, header 4, subheader 8, data 2328 */
#define EXE_LBA_TABLE 0x33F94    /* Cd_FileLba s32[0xE5B] in SLUS_011.93 */
#define EXE_SECTOR_TABLE 0x37900 /* Cd_FileSectors u16[0xE5B] */
#define ALIGN 0x800
#define CHUNK 512 /* sectors per read (progress and event pumping between reads) */

typedef struct {
    SDL_IOStream *io;
    char path[1024]; /* the raw data file (the .bin of a .cue) */
    Sint64 sectors;
} Disc;

static char *err_;
static size_t errlen_;

static int fail(const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vsnprintf(err_, errlen_, fmt, ap);
    va_end(ap);
    return -1;
}

static const char *base_name(const char *path) {
    const char *b = path;
    const char *p;

    for (p = path; *p != 0; p++) {
        if (*p == '/' || *p == '\\') {
            b = p + 1;
        }
    }
    return b;
}

static int has_ext(const char *path, const char *ext) {
    size_t n = strlen(path);
    size_t e = strlen(ext);

    return n > e && SDL_strcasecmp(path + n - e, ext) == 0;
}

static int bcd(int v) {
    return v / 10 * 16 + v % 10;
}

/* ---- progress: a small window of its own, or stdout lines headless ---- */

static int no_window;
static SDL_Window *pwin;
static SDL_Renderer *pren;
static int video_up;
static Uint64 last_draw;
static int last_pct = -1;
static int cancelled;
static char pimage[64];

static void video_init(void) {
    if (!no_window && !video_up && SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        video_up = 1;
    }
}

static void progress_open(const char *image) {
    SDL_strlcpy(pimage, base_name(image), sizeof(pimage));
    if (strlen(base_name(image)) >= sizeof(pimage)) {
        memcpy(pimage + sizeof(pimage) - 4, "...", 4);
    }
    last_pct = -1;
    last_draw = 0;
    cancelled = 0;
    video_init();
    if (video_up && SDL_CreateWindowAndRenderer("Digimon World 2", 640, 160, 0, &pwin, &pren)) {
        SDL_SetRenderScale(pren, 2.0f, 2.0f);
    }
}

static void progress_close(void) {
    if (pren != NULL) {
        SDL_DestroyRenderer(pren);
        pren = NULL;
    }
    if (pwin != NULL) {
        SDL_DestroyWindow(pwin);
        pwin = NULL;
    }
}

/* done / total of `what`; returns -1 when the player closed the window (cancel). */
static int progress(const char *what, Uint64 done, Uint64 total) {
    int pct = total != 0 ? (int)(done * 100 / total) : 100;
    SDL_Event e;

    if (pwin == NULL) {
        if (pct / 10 != last_pct / 10) {
            printf("[pak] %s: %d%%\n", what, pct);
            fflush(stdout);
        }
        last_pct = pct;
        return 0;
    }
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT || e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
            cancelled = 1;
        }
    }
    if (cancelled) {
        return -1;
    }
    if (pct != last_pct || SDL_GetTicks() - last_draw > 100) {
        SDL_FRect bar = { 10, 52, 300, 14 };
        char line[64];

        last_pct = pct;
        last_draw = SDL_GetTicks();
        SDL_SetRenderDrawColor(pren, 16, 20, 32, 255);
        SDL_RenderClear(pren);
        SDL_SetRenderDrawColor(pren, 230, 230, 230, 255);
        SDL_RenderDebugText(pren, 10, 10, "Building dw2.pak from your disc");
        SDL_RenderDebugText(pren, 10, 24, pimage);
        snprintf(line, sizeof(line), "%s %3d%%", what, pct);
        SDL_RenderDebugText(pren, 10, 38, line);
        SDL_RenderRect(pren, &bar);
        bar.x += 2;
        bar.y += 2;
        bar.h -= 4;
        bar.w = (bar.w - 4) * pct / 100;
        SDL_SetRenderDrawColor(pren, 90, 170, 255, 255);
        SDL_RenderFillRect(pren, &bar);
        SDL_RenderPresent(pren);
    }
    return 0;
}

/* ---- disc image access ---- */

static void disc_close(Disc *d) {
    if (d->io != NULL) {
        SDL_CloseIO(d->io);
        d->io = NULL;
    }
}

/* Next whitespace-separated or "quoted" token of a .cue line. */
static const char *cue_token(const char *p, char *out, size_t n) {
    size_t k = 0;

    while (*p == ' ' || *p == '\t') {
        p++;
    }
    if (*p == '"') {
        p++;
        while (*p != 0 && *p != '"' && *p != '\n' && *p != '\r') {
            if (k + 1 < n) {
                out[k++] = *p;
            }
            p++;
        }
        if (*p == '"') {
            p++;
        }
    } else {
        while (*p != 0 && *p != ' ' && *p != '\t' && *p != '\n' && *p != '\r') {
            if (k + 1 < n) {
                out[k++] = *p;
            }
            p++;
        }
    }
    out[k] = 0;
    return p;
}

/* The data file of a .cue: its first FILE, whose TRACK 01 must be MODE2/2352 starting at 00:00:00. */
static int cue_data_file(const char *cue, char *bin, size_t n) {
    size_t size = 0;
    char *text = SDL_LoadFile(cue, &size);
    const char *p;
    char tok[1024];
    int file_seen = 0;
    int track = 0;

    if (text == NULL) {
        return fail("cannot read the .cue (%s)", SDL_GetError());
    }
    p = text;
    if ((Uint8)p[0] == 0xEF && (Uint8)p[1] == 0xBB && (Uint8)p[2] == 0xBF) {
        p += 3;
    }
    while (*p != 0) {
        const char *q = cue_token(p, tok, sizeof(tok));

        if (SDL_strcasecmp(tok, "FILE") == 0 && !file_seen) {
            char name[1024];
            char type[32];

            q = cue_token(q, name, sizeof(name));
            cue_token(q, type, sizeof(type));
            if (SDL_strcasecmp(type, "BINARY") != 0) {
                SDL_free(text);
                return fail("the .cue's first file \"%s\" is %s, not a BINARY raw dump", name, type);
            }
            /* A relative name is relative to the .cue's folder. */
            if (name[0] == '/' || name[0] == '\\' || (name[0] != 0 && name[1] == ':')) {
                SDL_strlcpy(bin, name, n);
            } else if (snprintf(bin, n, "%.*s%s", (int)(base_name(cue) - cue), cue, name) >= (int)n) {
                SDL_free(text);
                return fail("the .cue's file path is too long");
            }
            file_seen = 1;
        } else if (SDL_strcasecmp(tok, "TRACK") == 0 && file_seen && track == 0) {
            char num[16];
            char mode[32];

            q = cue_token(q, num, sizeof(num));
            cue_token(q, mode, sizeof(mode));
            track = atoi(num);
            if (track != 1) {
                SDL_free(text);
                return fail("the .cue's first track is track %d, want track 1", track);
            }
            if (SDL_strcasecmp(mode, "MODE2/2352") != 0) {
                SDL_free(text);
                return fail("track 1 is %s; the Digimon World 2 data track is MODE2/2352 (raw dump needed)", mode);
            }
        } else if (SDL_strcasecmp(tok, "INDEX") == 0 && track == 1) {
            char num[16];
            char at[32];

            q = cue_token(q, num, sizeof(num));
            cue_token(q, at, sizeof(at));
            if (atoi(num) == 1) {
                if (strcmp(at, "00:00:00") != 0) {
                    SDL_free(text);
                    return fail("track 1 starts at %s in the .bin, not at its start", at);
                }
                SDL_free(text);
                return 0;
            }
        }
        while (*p != 0 && *p != '\n') {
            p++;
        }
        if (*p == '\n') {
            p++;
        }
    }
    SDL_free(text);
    return fail(file_seen ? "the .cue has no TRACK 01 / INDEX 01" : "the .cue names no FILE");
}

/* Opens an image: a .cue's data file, or the file itself; checks it holds raw 2352-byte sectors. */
static int disc_open(Disc *d, const char *path) {
    Uint8 s[RAW];
    Sint64 size;

    memset(d, 0, sizeof(*d));
    if (has_ext(path, ".cue")) {
        if (cue_data_file(path, d->path, sizeof(d->path)) != 0) {
            return -1;
        }
    } else {
        SDL_strlcpy(d->path, path, sizeof(d->path));
    }
    d->io = SDL_IOFromFile(d->path, "rb");
    if (d->io == NULL) {
        return fail("cannot open %s (%s)", d->path, SDL_GetError());
    }
    size = SDL_GetIOSize(d->io);
    /* A 2048-byte ISO: the ISO9660 descriptor right at 16 * 2048, no sync pattern at sector 16. */
    if (size >= 17 * 2048 && SDL_SeekIO(d->io, 16 * 2048, SDL_IO_SEEK_SET) >= 0 &&
        SDL_ReadIO(d->io, s, 6) == 6 && memcmp(s + 1, "CD001", 5) == 0) {
        disc_close(d);
        return fail("this is a 2048-byte ISO image. It keeps only the Form 1 data of each sector; the\n"
                    "34 files with Form 2 sectors (XA audio, movies) are lost. Make a raw dump\n"
                    "(.bin + .cue or .img, 2352-byte sectors) of the disc instead");
    }
    if (size <= 0 || size % RAW != 0) {
        static const Uint8 sync[12] = { 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0 };
        int raw_start = size > 17 * RAW && SDL_SeekIO(d->io, 16 * RAW, SDL_IO_SEEK_SET) >= 0 &&
                        SDL_ReadIO(d->io, s, 12) == 12 && memcmp(s, sync, 12) == 0;

        disc_close(d);
        if (raw_start) {
            return fail("size %lld is not a multiple of %d: the image is truncated or damaged", (long long)size, RAW);
        }
        return fail("size %lld is not a multiple of %d: not a raw 2352-byte-sector disc image", (long long)size, RAW);
    }
    d->sectors = size / RAW;
    return 0;
}

/* count raw sectors from lba into buf, each checked: sync pattern, header MSF = lba, mode 2. */
static int disc_raw(Disc *d, int lba, int count, Uint8 *buf) {
    static const Uint8 sync[12] = { 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0 };
    int i;

    if (lba < 0 || (Sint64)lba + count > d->sectors) {
        return fail("sectors %d..%d are past the end of the image (%lld sectors): the image is truncated", lba,
                    lba + count, (long long)d->sectors);
    }
    if (SDL_SeekIO(d->io, (Sint64)lba * RAW, SDL_IO_SEEK_SET) < 0 ||
        SDL_ReadIO(d->io, buf, (size_t)count * RAW) != (size_t)count * RAW) {
        return fail("cannot read sectors %d..%d (%s)", lba, lba + count, SDL_GetError());
    }
    for (i = 0; i < count; i++) {
        const Uint8 *s = buf + (size_t)i * RAW;
        int a = lba + i + 150;

        if (memcmp(s, sync, 12) != 0 || s[12] != bcd(a / 4500) || s[13] != bcd(a / 75 % 60) || s[14] != bcd(a % 75) ||
            s[15] != 2) {
            return fail("sector %d: bad sync / header (not a raw Mode 2 image, or damaged)", lba + i);
        }
    }
    return 0;
}

/* Form 1 user data of count sectors from lba (malloc'd, count * 2048 bytes). */
static Uint8 *disc_data(Disc *d, int lba, int count) {
    Uint8 *buf = malloc((size_t)count * RAW);
    int i;

    if (buf == NULL) {
        fail("out of memory");
        return NULL;
    }
    if (disc_raw(d, lba, count, buf) != 0) {
        free(buf);
        return NULL;
    }
    for (i = 0; i < count; i++) {
        memmove(buf + (size_t)i * 2048, buf + (size_t)i * RAW + 24, 2048);
    }
    return buf;
}

static Uint32 rd32(const Uint8 *p) {
    return p[0] | p[1] << 8 | p[2] << 16 | (Uint32)p[3] << 24;
}

/* SLUS_011.93 from the ISO9660 root directory (malloc'd, *size bytes). */
static Uint8 *disc_exe(Disc *d, Uint32 *size) {
    Uint8 *pvd = disc_data(d, 16, 1);
    Uint8 *dir;
    Uint32 lba, dsize, pos = 0;

    if (pvd == NULL) {
        return NULL;
    }
    if (memcmp(pvd + 1, "CD001", 5) != 0) {
        free(pvd);
        fail("no ISO9660 volume descriptor at sector 16 (not a PlayStation disc)");
        return NULL;
    }
    lba = rd32(pvd + 156 + 2);
    dsize = rd32(pvd + 156 + 10);
    free(pvd);
    if (dsize == 0 || dsize > 1 << 20 || (dir = disc_data(d, (int)lba, (int)((dsize + 2047) / 2048))) == NULL) {
        if (dsize == 0 || dsize > 1 << 20) {
            fail("bad ISO9660 root directory");
        }
        return NULL;
    }
    while (pos < dsize) {
        Uint32 n = dir[pos];
        char ident[256];
        Uint32 k, len;

        if (n == 0) { /* records do not cross sectors */
            pos = (pos / 2048 + 1) * 2048;
            continue;
        }
        if (pos + 33 > dsize || pos + 33 + dir[pos + 32] > dsize) {
            break;
        }
        len = dir[pos + 32];
        for (k = 0; k < len && dir[pos + 33 + k] != ';'; k++) {
            ident[k] = (char)dir[pos + 33 + k];
        }
        ident[k] = 0;
        if (SDL_strcasecmp(ident, "SLUS_011.93") == 0) {
            Uint32 flba = rd32(dir + pos + 2);
            Uint8 *exe;

            *size = rd32(dir + pos + 10);
            free(dir);
            if (*size > 4 << 20) {
                fail("SLUS_011.93 has a bad size");
                return NULL;
            }
            exe = disc_data(d, (int)flba, (int)((*size + 2047) / 2048));
            return exe;
        }
        pos += n;
    }
    free(dir);
    fail("SLUS_011.93 is not on this disc: not Digimon World 2 USA (SLUS-01193); other games and other\n"
         "regions are not supported");
    return NULL;
}

/* The disc's exe, checked against the manifest's exe hash: a Digimon World 2 USA image. */
static Uint8 *disc_identify(Disc *d, const char *path, Uint32 *size) {
    static Uint8 manifest[PAK_FILES][32];
    Uint8 exe_sha[32];
    Uint8 digest[32];
    Sha256 s;
    Uint8 *exe;

    if (disc_open(d, path) != 0) {
        return NULL;
    }
    exe = disc_exe(d, size);
    if (exe == NULL) {
        disc_close(d);
        return NULL;
    }
    Pak_ParseManifest(exe_sha, manifest);
    Sha256_Init(&s);
    Sha256_Update(&s, exe, *size);
    Sha256_Final(&s, digest);
    if (memcmp(digest, exe_sha, 32) != 0 || *size < EXE_SECTOR_TABLE + PAK_FILES * 2) {
        free(exe);
        disc_close(d);
        fail("SLUS_011.93 differs from the retail USA disc (modified, a patch, or another version)");
        return NULL;
    }
    return exe;
}

/* ---- finding the image ---- */

static char *found_;          /* identified image */
static char reasons_[1536];   /* why candidates were skipped (for the error text) */

static void note_skip(const char *path, const char *reason) {
    size_t n = strlen(reasons_);
    const char *nl = strchr(reason, '\n');

    printf("[pak] skipped %s: %s\n", path, reason);
    if (n + 8 < sizeof(reasons_)) {
        snprintf(reasons_ + n, sizeof(reasons_) - n, "\n  %s: %.*s", base_name(path),
                 nl != NULL ? (int)(nl - reason) : (int)strlen(reason), reason);
    }
}

/* Identifies one candidate; 1 when it is the disc (found_ set). */
static int try_image(const char *path) {
    char why[1024];
    Disc d;
    Uint32 size;
    Uint8 *exe;

    err_ = why;
    errlen_ = sizeof(why);
    exe = disc_identify(&d, path, &size);
    if (exe == NULL) {
        note_skip(path, why);
        return 0;
    }
    free(exe);
    disc_close(&d);
    found_ = SDL_strdup(path);
    printf("[pak] disc image: %s\n", path);
    return 1;
}

static int cmp_name(const void *a, const void *b) {
    return strcmp(*(char *const *)a, *(char *const *)b);
}

/* The first Digimon World 2 image in `dir` (ending with a separator). */
static int search_dir(const char *dir) {
    static const char *exts[] = { ".cue", ".img", ".bin", ".iso" };
    char claimed[16][1024]; /* data files named by a .cue: not tried again on their own */
    int nclaimed = 0;
    int count = 0;
    char **names = SDL_GlobDirectory(dir, "*", SDL_GLOB_CASEINSENSITIVE, &count);
    char *sorted[256];
    int n = 0;
    int i, k, hit = 0;

    if (names == NULL) {
        return 0;
    }
    for (i = 0; i < count && n < 256; i++) {
        for (k = 0; k < 4; k++) {
            if (has_ext(names[i], exts[k])) {
                sorted[n++] = names[i];
                break;
            }
        }
    }
    SDL_qsort(sorted, n, sizeof(sorted[0]), cmp_name);
    for (i = 0; i < n && nclaimed < 16; i++) {
        char path[1024];
        char why[512];

        if (has_ext(sorted[i], ".cue")) {
            snprintf(path, sizeof(path), "%s%s", dir, sorted[i]);
            err_ = why;
            errlen_ = sizeof(why);
            if (cue_data_file(path, claimed[nclaimed], sizeof(claimed[0])) == 0) {
                nclaimed++;
            }
        }
    }
    /* .cue files first (they say how to read their .bin), then the other images. */
    for (k = 0; k < 2 && !hit; k++) {
        for (i = 0; i < n && !hit; i++) {
            char path[1024];
            int j, skip = 0;

            if (has_ext(sorted[i], ".cue") != (k == 0)) {
                continue;
            }
            snprintf(path, sizeof(path), "%s%s", dir, sorted[i]);
            for (j = 0; j < nclaimed && k == 1; j++) {
                skip |= SDL_strcasecmp(base_name(claimed[j]), sorted[i]) == 0;
            }
            if (!skip) {
                hit = try_image(path);
            }
        }
    }
    SDL_free(names);
    return hit;
}

static SDL_AtomicInt dlg_state; /* 0 open, 1 picked, 2 cancelled, 3 failed */
static char dlg_path[1024];
static char dlg_error[256];

static void SDLCALL dialog_done(void *userdata, const char *const *list, int filter) {
    (void)userdata;
    (void)filter;
    if (list == NULL) {
        SDL_strlcpy(dlg_error, SDL_GetError(), sizeof(dlg_error));
        SDL_SetAtomicInt(&dlg_state, 3);
    } else if (list[0] == NULL) {
        SDL_SetAtomicInt(&dlg_state, 2);
    } else {
        SDL_strlcpy(dlg_path, list[0], sizeof(dlg_path));
        SDL_SetAtomicInt(&dlg_state, 1);
    }
}

/* The SDL file dialog; 1 with dlg_path set, 0 cancelled or no dialog available. */
static int pick_file(void) {
    static const SDL_DialogFileFilter filters[] = {
        { "Disc images (.cue, .bin, .img, .iso)", "cue;bin;img;iso" },
        { "All files", "*" },
    };
    SDL_PropertiesID props = SDL_CreateProperties();
    const char *base = SDL_GetBasePath();

    video_init();
    if (!video_up) {
        return 0;
    }
    SDL_SetAtomicInt(&dlg_state, 0);
    SDL_SetPointerProperty(props, SDL_PROP_FILE_DIALOG_FILTERS_POINTER, (void *)filters);
    SDL_SetNumberProperty(props, SDL_PROP_FILE_DIALOG_NFILTERS_NUMBER, 2);
    SDL_SetStringProperty(props, SDL_PROP_FILE_DIALOG_TITLE_STRING, "Select your Digimon World 2 (USA) disc image");
    if (base != NULL) {
        SDL_SetStringProperty(props, SDL_PROP_FILE_DIALOG_LOCATION_STRING, base);
    }
    SDL_ShowFileDialogWithProperties(SDL_FILEDIALOG_OPENFILE, dialog_done, NULL, props);
    while (SDL_GetAtomicInt(&dlg_state) == 0) {
        SDL_Event e;
        SDL_WaitEventTimeout(&e, 50);
    }
    SDL_DestroyProperties(props);
    if (SDL_GetAtomicInt(&dlg_state) == 3) {
        printf("[pak] file dialog: %s\n", dlg_error);
    }
    return SDL_GetAtomicInt(&dlg_state) == 1;
}

char *Host_DiscFind(const char *disc, int no_win, char *err, size_t errlen) {
    const char *base = SDL_GetBasePath();
    char *pref = SDL_GetPrefPath("", "DW2-Online");

    no_window = no_win;
    found_ = NULL;
    reasons_[0] = 0;
    if (disc != NULL) {
        try_image(disc);
    } else {
        if (base != NULL) {
            search_dir(base);
        }
        if (found_ == NULL && pref != NULL) {
            search_dir(pref);
        }
        /* None found: ask, until an image passes or the player cancels. */
        while (found_ == NULL && !no_window) {
            char msg[2048];

            if (!pick_file()) {
                break;
            }
            if (!try_image(dlg_path)) {
                snprintf(msg, sizeof(msg), "%s is not a usable Digimon World 2 USA disc image:%s",
                         base_name(dlg_path), strrchr(reasons_, '\n') != NULL ? strrchr(reasons_, '\n') : "");
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Digimon World 2: disc image", msg, NULL);
            }
        }
    }
    if (found_ == NULL) {
        if (disc != NULL) {
            snprintf(err, errlen, "the disc image cannot be used:%s", reasons_);
        } else {
            snprintf(err, errlen, "no dw2.pak and no Digimon World 2 USA disc image found next to the exe (%s)%s%s%s",
                     base != NULL ? base : "?", pref != NULL ? " or in " : "", pref != NULL ? pref : "",
                     reasons_[0] != 0 ? "\nImages looked at:" : "");
            SDL_strlcat(err, reasons_, errlen);
        }
    }
    SDL_free(pref);
    return found_;
}

/* ---- the build ---- */

static int write_all(SDL_IOStream *io, const void *p, size_t n) {
    return SDL_WriteIO(io, p, n) == n ? 0 : -1;
}

static void wr32(Uint8 *p, Uint32 v) {
    p[0] = (Uint8)v;
    p[1] = (Uint8)(v >> 8);
    p[2] = (Uint8)(v >> 16);
    p[3] = (Uint8)(v >> 24);
}

static void wr64(Uint8 *p, Uint64 v) {
    wr32(p, (Uint32)v);
    wr32(p + 4, (Uint32)(v >> 32));
}

typedef struct {
    Uint32 lba, sectors, format;
    Uint64 offset, size;
    Uint8 sha[32];
} Entry;

static int build(Disc *d, const Uint8 *exe, SDL_IOStream *out, const char *tmp) {
    static Uint8 manifest[PAK_FILES][32];
    static Uint8 index[PAK_FILES * PAK_ENTRY_SIZE];
    static Entry ent[PAK_FILES];
    static const Uint8 zero[ALIGN];
    Uint8 exe_sha[32];
    Uint8 header[PAK_HEADER_SIZE];
    Uint8 content[32];
    Uint8 *buf;
    Sha256 all;
    Uint64 offset = (PAK_HEADER_SIZE + PAK_ENTRY_SIZE * PAK_FILES + ALIGN - 1) / ALIGN * ALIGN;
    Uint64 total = 0, done = 0;
    Uint32 maxsec = 0;
    int nbad = 0, firstbad[12];
    int i;

    Pak_ParseManifest(exe_sha, manifest);
    for (i = 0; i < PAK_FILES; i++) {
        Uint32 n = exe[EXE_SECTOR_TABLE + i * 2] | exe[EXE_SECTOR_TABLE + i * 2 + 1] << 8;
        ent[i].lba = rd32(exe + EXE_LBA_TABLE + i * 4);
        ent[i].sectors = n;
        total += n;
        maxsec = n > maxsec ? n : maxsec;
    }
    buf = malloc((size_t)maxsec * RAW);
    if (buf == NULL) {
        return fail("out of memory (%u sectors)", maxsec);
    }
    /* Header and index are written last; their space first. */
    for (i = 0; (Uint64)i < offset / ALIGN; i++) {
        if (write_all(out, zero, ALIGN) != 0) {
            free(buf);
            return fail("cannot write %s (%s)", tmp, SDL_GetError());
        }
    }
    for (i = 0; i < PAK_FILES; i++) {
        Entry *e = &ent[i];
        int form2 = 0;
        Uint32 k;
        size_t bytes, pad;
        Sha256 s;

        for (k = 0; k < e->sectors; k += CHUNK) {
            int n = e->sectors - k < CHUNK ? (int)(e->sectors - k) : CHUNK;
            if (disc_raw(d, (int)(e->lba + k), n, buf + (size_t)k * RAW) != 0) {
                free(buf);
                return -1;
            }
            done += n;
            if (progress("Reading", done, total) != 0) {
                free(buf);
                return fail("cancelled");
            }
        }
        for (k = 0; k < e->sectors; k++) {
            form2 |= buf[(size_t)k * RAW + 18] & 0x20;
        }
        /* In place: each body moves down to its slot. */
        e->format = form2 ? 1 : 0;
        bytes = form2 ? 2336 : 2048;
        for (k = 0; k < e->sectors; k++) {
            memmove(buf + (size_t)k * bytes, buf + (size_t)k * RAW + (form2 ? 16 : 24), bytes);
        }
        e->size = (Uint64)e->sectors * bytes;
        e->offset = offset;
        Sha256_Init(&s);
        Sha256_Update(&s, buf, (size_t)e->size);
        Sha256_Final(&s, e->sha);
        if (memcmp(e->sha, manifest[i], 32) != 0) {
            if (nbad < 12) {
                firstbad[nbad] = i;
            }
            nbad++;
        }
        if (nbad != 0) {
            continue; /* keep checking for the count, write nothing more */
        }
        pad = (size_t)((ALIGN - e->size % ALIGN) % ALIGN);
        if (write_all(out, buf, (size_t)e->size) != 0 || write_all(out, zero, pad) != 0) {
            free(buf);
            return fail("cannot write %s (%s; disk full?)", tmp, SDL_GetError());
        }
        offset += e->size + pad;
    }
    free(buf);
    if (nbad != 0) {
        char list[128] = "";

        for (i = 0; i < nbad && i < 12; i++) {
            size_t n = strlen(list);
            snprintf(list + n, sizeof(list) - n, "%s0x%03X", i ? ", " : "", firstbad[i]);
        }
        return fail("%d file(s) do not match the manifest: %s%s\n"
                    "This is not an unmodified Digimon World 2 USA (SLUS-01193) disc image (modified or damaged).",
                    nbad, list, nbad > 12 ? " ..." : "");
    }
    Sha256_Init(&all);
    for (i = 0; i < PAK_FILES; i++) {
        Uint8 *x = index + i * PAK_ENTRY_SIZE;
        wr32(x, (Uint32)i);
        wr32(x + 0x04, ent[i].lba);
        wr32(x + 0x08, ent[i].sectors);
        wr32(x + 0x0C, ent[i].format);
        wr64(x + 0x10, ent[i].offset);
        wr64(x + 0x18, ent[i].size);
        memcpy(x + 0x20, ent[i].sha, 32);
        Sha256_Update(&all, ent[i].sha, 32);
    }
    Sha256_Final(&all, content);
    memset(header, 0, sizeof(header));
    memcpy(header, PAK_MAGIC, 8);
    wr32(header + 0x08, PAK_VERSION);
    wr32(header + 0x0C, PAK_HEADER_SIZE);
    wr32(header + 0x10, PAK_FILES);
    wr32(header + 0x14, PAK_HEADER_SIZE);
    wr32(header + 0x18, PAK_ENTRY_SIZE);
    wr32(header + 0x1C, 0);
    wr64(header + 0x20, ent[0].offset);
    wr64(header + 0x28, offset);
    memcpy(header + 0x30, content, 32);
    if (SDL_SeekIO(out, 0, SDL_IO_SEEK_SET) != 0 || write_all(out, header, sizeof(header)) != 0 ||
        write_all(out, index, sizeof(index)) != 0) {
        return fail("cannot write %s (%s)", tmp, SDL_GetError());
    }
    if (!SDL_FlushIO(out)) {
        return fail("cannot write %s (%s; disk full?)", tmp, SDL_GetError());
    }
    return 0;
}

/* Reads every file of the written pack back and checks its hash, before it takes its name. */
static int read_back(const char *tmp) {
    static Uint8 index[PAK_FILES * PAK_ENTRY_SIZE];
    SDL_IOStream *io = SDL_IOFromFile(tmp, "rb");
    Uint8 *buf = malloc(1 << 20);
    Uint64 total = 0, done = 0;
    int i, r = 0;

    last_pct = -1;
    if (io == NULL || buf == NULL || SDL_SeekIO(io, PAK_HEADER_SIZE, SDL_IO_SEEK_SET) < 0 ||
        SDL_ReadIO(io, index, sizeof(index)) != sizeof(index)) {
        r = fail("cannot read %s back (%s)", tmp, SDL_GetError());
    }
    for (i = 0; r == 0 && i < PAK_FILES; i++) {
        total += (Uint64)rd32(index + i * PAK_ENTRY_SIZE + 0x18);
    }
    for (i = 0; r == 0 && i < PAK_FILES; i++) {
        const Uint8 *e = index + i * PAK_ENTRY_SIZE;
        Uint64 left = rd32(e + 0x18);
        Uint8 digest[32];
        Sha256 s;

        Sha256_Init(&s);
        if (SDL_SeekIO(io, (Sint64)(rd32(e + 0x10) | (Uint64)rd32(e + 0x14) << 32), SDL_IO_SEEK_SET) < 0) {
            r = fail("cannot read %s back", tmp);
        }
        while (r == 0 && left != 0) {
            size_t n = left < (1 << 20) ? (size_t)left : (1 << 20);
            if (SDL_ReadIO(io, buf, n) != n) {
                r = fail("cannot read %s back (%s)", tmp, SDL_GetError());
                break;
            }
            Sha256_Update(&s, buf, n);
            left -= n;
            done += n;
            if (progress("Checking", done, total) != 0) {
                r = fail("cancelled");
            }
        }
        Sha256_Final(&s, digest);
        if (r == 0 && memcmp(digest, e + 0x20, 32) != 0) {
            r = fail("%s: file 0x%03X does not read back (disk error?)", tmp, i);
        }
    }
    free(buf);
    if (io != NULL) {
        SDL_CloseIO(io);
    }
    return r;
}

int Host_PakBuild(const char *image, const char *out, const char *fallback, int no_win, char *built, size_t builtlen,
                  char *err, size_t errlen) {
    char tmp[1100];
    SDL_IOStream *io;
    Disc d;
    Uint32 size;
    Uint8 *exe;
    Uint64 t0 = SDL_GetTicksNS();
    int r;

    no_window = no_win;
    err_ = err;
    errlen_ = errlen;
    exe = disc_identify(&d, image, &size);
    if (exe == NULL) {
        return -1;
    }
    snprintf(tmp, sizeof(tmp), "%s.tmp", out);
    io = SDL_IOFromFile(tmp, "wb");
    if (io == NULL && fallback != NULL) {
        printf("[pak] cannot write %s (%s), using %s\n", tmp, SDL_GetError(), fallback);
        out = fallback;
        snprintf(tmp, sizeof(tmp), "%s.tmp", out);
        io = SDL_IOFromFile(tmp, "wb");
    }
    if (io == NULL) {
        free(exe);
        disc_close(&d);
        return fail("cannot create %s (%s)", tmp, SDL_GetError());
    }
    printf("[pak] building %s from %s\n", out, image);
    progress_open(image);
    r = build(&d, exe, io, tmp);
    free(exe);
    disc_close(&d);
    if (!SDL_CloseIO(io) && r == 0) {
        r = fail("cannot write %s (%s; disk full?)", tmp, SDL_GetError());
    }
    if (r == 0) {
        r = read_back(tmp);
    }
    progress_close();
    if (video_up) {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        video_up = 0;
    }
    if (r == 0 && !SDL_RenamePath(tmp, out)) {
        r = fail("cannot rename %s to %s (%s)", tmp, out, SDL_GetError());
    }
    if (r != 0) {
        SDL_RemovePath(tmp);
        if (cancelled) {
            printf("[pak] build cancelled, no pack written\n");
            exit(1);
        }
        return -1;
    }
    SDL_strlcpy(built, out, builtlen);
    printf("[pak] wrote %s in %.1f s\n", out, (SDL_GetTicksNS() - t0) / 1e9);
    return 0;
}
