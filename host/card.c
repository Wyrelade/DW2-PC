#include <stdio.h>
#include <string.h>

#include "host/host_sdl.h"
#include "host/host.h"

/* Memory card files (P1.9, user decisions 2026-10-07): one raw 128 KB PS1 card image per port,
 * card1.mcd and card2.mcd (the raw format of DuckStation / PCSX-Redux .mcd and ePSXe .mcr, so an
 * emulator card copied in is imported as is), in the user data folder: SDL_GetPrefPath ->
 * %APPDATA%\DW2-Online\saves\ on Windows. --save-dir DIR overrides the folder (dev / tests).
 * The card file system itself (directory, blocks, libmcrd) is psyq/libmcrd.c. */

static char *dir_;

void Host_CardSetDir(const char *dir) {
    size_t n = strlen(dir);
    SDL_free(dir_);
    SDL_asprintf(&dir_, "%s%s", dir, (n > 0 && (dir[n - 1] == '/' || dir[n - 1] == '\\')) ? "" : "/");
}

static const char *card_dir(void) {
    static int made;
    if (dir_ == NULL) {
        char *pref = SDL_GetPrefPath("", "DW2-Online");
        if (pref != NULL) {
            /* pref ends with the platform's separator; keep it for the subfolder. */
            SDL_asprintf(&dir_, "%ssaves%c", pref, pref[strlen(pref) - 1]);
            SDL_free(pref);
        } else {
            printf("[card] no user data folder (%s), using saves/ in the current folder\n", SDL_GetError());
            SDL_asprintf(&dir_, "saves/");
        }
    }
    if (!made) {
        made = 1;
        if (!SDL_CreateDirectory(dir_)) {
            printf("[card] cannot create %s (%s)\n", dir_, SDL_GetError());
        }
    }
    return dir_;
}

static char *card_path(int port, const char *suffix) {
    char *path = NULL;
    SDL_asprintf(&path, "%scard%d.mcd%s", card_dir(), port + 1, suffix);
    return path;
}

int Host_CardLoad(int port, unsigned char *buf, int size) {
    char *path = card_path(port, "");
    SDL_IOStream *io = SDL_IOFromFile(path, "rb");
    int r = -1;
    if (io == NULL) {
        printf("[card] port %d: no card file %s\n", port + 1, path);
        SDL_free(path);
        return 0;
    }
    if (SDL_GetIOSize(io) != size) {
        printf("[card] port %d: %s is %lld bytes, a raw card image has %d\n", port + 1, path,
               (long long)SDL_GetIOSize(io), size);
    } else if (SDL_ReadIO(io, buf, (size_t)size) != (size_t)size) {
        printf("[card] port %d: cannot read %s (%s)\n", port + 1, path, SDL_GetError());
    } else {
        printf("[card] port %d: %s loaded\n", port + 1, path);
        r = 1;
    }
    SDL_CloseIO(io);
    SDL_free(path);
    return r;
}

int Host_CardStore(int port, const unsigned char *buf, int size) {
    char *tmp = card_path(port, ".tmp");
    char *path = card_path(port, "");
    SDL_IOStream *io = SDL_IOFromFile(tmp, "wb");
    int ok = 0;
    if (io == NULL) {
        printf("[card] port %d: cannot write %s (%s)\n", port + 1, tmp, SDL_GetError());
    } else {
        ok = SDL_WriteIO(io, buf, (size_t)size) == (size_t)size;
        ok = SDL_FlushIO(io) && ok;
        ok = SDL_CloseIO(io) && ok;
        /* Whole new image first, then the rename, so a crash never leaves half a card. */
        if (ok && !SDL_RenamePath(tmp, path)) {
            printf("[card] port %d: cannot replace %s (%s)\n", port + 1, path, SDL_GetError());
            ok = 0;
        }
        if (!ok) {
            SDL_RemovePath(tmp);
        } else {
            printf("[card] port %d: %s written\n", port + 1, path);
        }
    }
    SDL_free(tmp);
    SDL_free(path);
    return ok;
}
