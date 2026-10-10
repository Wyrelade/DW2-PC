/* PR.30 update check, PR.31 updater.
 *
 * Check: one HTTPS GET of the GitHub API's latest release on a background thread at start,
 * "tag_name" compared with DW2_VERSION. Windows asks through WinHTTP (system library); Linux
 * loads libcurl.so.4 at run time, so the program does not need it: without it there is no
 * check. The check starts before the pack check and the window; the start waits up to WAIT_MS
 * for it. A later answer still shows on the title and in F1. Any failure (offline, timeout, rate
 * limit, odd answer) only logs a line and shows "Could not check" in F1.
 *
 * Updater: with a newer release, a box offers Update now / Download page / Not now. Update now
 * downloads the release zip for this platform and its .sig (Ed25519 over the zip, made by
 * tools/package_release.py), checks the signature with the public key below, unpacks the files
 * of the zip's DW2-PC/ folder next to the program as <name>.new, then swaps them in (the old
 * ones become <name>.old: Windows cannot overwrite a running exe or a loaded DLL but can rename
 * them), starts the new program with the same arguments and quits. Any failure puts the old
 * files back and offers the download page. The next start deletes the .old files. */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host/miniz/miniz.h"
#include "host/monocypher/monocypher-ed25519.h"
#include "host/settings.h"
#include "host/update.h"

#ifdef _WIN32
#include <windows.h>
#include <winhttp.h>
#else
#include <dlfcn.h>
#include <sys/stat.h>
#endif

#define API_HOST "api.github.com"
#define API_PATH "/repos/Wyrelade/DW2-PC/releases/latest"
#define DL_HOST "github.com"
#define DL_PATH "/Wyrelade/DW2-PC/releases/download/"
#define USER_AGENT "DW2-PC/" DW2_VERSION
#define API_MAX (256 * 1024)
#define ZIP_MAX (64 * 1024 * 1024)
#define TIMEOUT_MS 8000
#define WAIT_MS 3000 /* how long the start waits for the answer before it goes on */

/* The release zip this build updates from (NULL: no updater, only the download page). */
#if defined(_WIN32) && defined(_WIN64)
#define ASSET "DW2-PC-windows-x64.zip"
#define EXE_NAME "dw2.exe"
#elif defined(__linux__) && defined(__x86_64__)
#define ASSET "DW2-PC-linux-x64.zip"
#define EXE_NAME "dw2"
#else
#define ASSET NULL
#define EXE_NAME ""
#endif

/* Public half of the release signing key (the private half is never in the repo). */
static const uint8_t update_pubkey[32] = {
    0x6e, 0xef, 0x9d, 0xc2, 0xdf, 0x88, 0xb2, 0xfa, 0x23, 0xb8, 0x08, 0x7a, 0xc3, 0x81, 0xd1, 0xa4,
    0x7d, 0xe7, 0x13, 0x66, 0x5c, 0xf8, 0xeb, 0x96, 0xb6, 0xa6, 0xa7, 0xa7, 0xe4, 0x3f, 0xee, 0x22,
};

enum { ST_OFF, ST_CHECKING, ST_CURRENT, ST_NEWER, ST_FAILED };

static SDL_AtomicInt g_state; /* ST_*; g_tag is written before ST_NEWER */
static SDL_Semaphore *g_done;  /* signalled when the check thread has its answer */
static char g_tag[32];
static int g_disabled;
static int g_auto; /* --update-auto: "Update now" without the box (tests) */
static const char *g_local = DW2_VERSION;

typedef struct {
    char *data;
    size_t len;
    size_t max;
} Reply;

/* download progress: 0 = go on, nonzero = cancel */
typedef int (*ProgressFn)(Uint64 done, Uint64 total);

static int reply_add(Reply *r, const void *p, size_t n) {
    if (r->len + n > r->max) {
        return 0;
    }
    char *d = (char *)realloc(r->data, r->len + n + 1);
    if (d == NULL) {
        return 0;
    }
    memcpy(d + r->len, p, n);
    r->data = d;
    r->len += n;
    r->data[r->len] = 0;
    return 1;
}

#ifdef _WIN32
static wchar_t *widen(const char *s) {
    int n = MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);
    wchar_t *w = n > 0 ? (wchar_t *)malloc(n * sizeof(wchar_t)) : NULL;

    if (w != NULL) {
        MultiByteToWideChar(CP_UTF8, 0, s, -1, w, n);
    }
    return w;
}

/* WinHTTP: system proxy settings, TLS by the system, redirects followed. 1 = HTTP 200. */
static int http_get(const char *host, const char *path, int api, Reply *r, ProgressFn prog) {
    HINTERNET s = NULL, c = NULL, q = NULL;
    DWORD status = 0, total = 0, size, n;
    wchar_t *whost = widen(host), *wpath = widen(path);
    char buf[16384];
    int ok = 0;

    if (whost == NULL || wpath == NULL) {
        goto done;
    }
    s = WinHttpOpen(L"DW2-PC/" DW2_VERSION, WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME,
                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (s == NULL) {
        goto done;
    }
    WinHttpSetTimeouts(s, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS);
    c = WinHttpConnect(s, whost, INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (c == NULL) {
        goto done;
    }
    q = WinHttpOpenRequest(c, L"GET", wpath, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
                           WINHTTP_FLAG_SECURE);
    size = sizeof(status);
    if (q == NULL ||
        !WinHttpSendRequest(q, api ? L"Accept: application/vnd.github+json\r\n" : WINHTTP_NO_ADDITIONAL_HEADERS,
                            api ? (DWORD)-1L : 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) ||
        !WinHttpReceiveResponse(q, NULL) ||
        !WinHttpQueryHeaders(q, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, WINHTTP_HEADER_NAME_BY_INDEX,
                             &status, &size, WINHTTP_NO_HEADER_INDEX)) {
        goto done;
    }
    if (status != 200) {
        printf("[update] %s%s: HTTP %lu\n", host, path, (unsigned long)status);
        goto done;
    }
    size = sizeof(total);
    if (!WinHttpQueryHeaders(q, WINHTTP_QUERY_CONTENT_LENGTH | WINHTTP_QUERY_FLAG_NUMBER, WINHTTP_HEADER_NAME_BY_INDEX,
                             &total, &size, WINHTTP_NO_HEADER_INDEX)) {
        total = 0;
    }
    for (;;) {
        if (!WinHttpReadData(q, buf, sizeof(buf), &n)) {
            goto done;
        }
        if (n == 0) {
            break;
        }
        if (!reply_add(r, buf, n) || (prog != NULL && prog(r->len, total) != 0)) {
            goto done;
        }
    }
    ok = r->len > 0;
done:
    if (!ok && status == 0) {
        printf("[update] %s%s: request failed (WinHTTP error %lu)\n", host, path, (unsigned long)GetLastError());
    }
    if (q != NULL) {
        WinHttpCloseHandle(q);
    }
    if (c != NULL) {
        WinHttpCloseHandle(c);
    }
    if (s != NULL) {
        WinHttpCloseHandle(s);
    }
    free(whost);
    free(wpath);
    return ok;
}
#else
/* libcurl through dlopen: only the stable easy interface, option numbers from curl.h (fixed by
 * libcurl's ABI). */
#define CURLOPT_TIMEOUT_MS 155
#define CURLOPT_FOLLOWLOCATION 52
#define CURLOPT_NOSIGNAL 99
#define CURLOPT_WRITEDATA 10001
#define CURLOPT_URL 10002
#define CURLOPT_USERAGENT 10018
#define CURLOPT_WRITEFUNCTION 20011
#define CURLINFO_RESPONSE_CODE 0x200002
#define CURLINFO_CONTENT_LENGTH_DOWNLOAD_T 0x60000F

typedef struct {
    Reply *r;
    void *h;
    int (*getinfo)(void *, int, ...);
    ProgressFn prog;
    int cancelled;
} CurlCtx;

static size_t curl_write(char *p, size_t size, size_t n, void *user) {
    CurlCtx *c = (CurlCtx *)user;
    long long total = 0;

    if (!reply_add(c->r, p, size * n)) {
        return 0;
    }
    if (c->prog != NULL) {
        c->getinfo(c->h, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &total);
        if (c->prog(c->r->len, total > 0 ? (Uint64)total : 0) != 0) {
            c->cancelled = 1;
            return 0;
        }
    }
    return size * n;
}

static int http_get(const char *host, const char *path, int api, Reply *r, ProgressFn prog) {
    void *lib = dlopen("libcurl.so.4", RTLD_NOW | RTLD_LOCAL);
    void *(*easy_init)(void);
    int (*easy_setopt)(void *, int, ...);
    int (*easy_perform)(void *);
    void (*easy_cleanup)(void *);
    CurlCtx ctx = { r, NULL, NULL, prog, 0 };
    char url[512];
    long status = 0;
    int res, ok = 0;

    (void)api;
    if (lib == NULL) {
        printf("[update] no libcurl.so.4, no update check\n");
        return 0;
    }
    *(void **)&easy_init = dlsym(lib, "curl_easy_init");
    *(void **)&easy_setopt = dlsym(lib, "curl_easy_setopt");
    *(void **)&easy_perform = dlsym(lib, "curl_easy_perform");
    *(void **)&ctx.getinfo = dlsym(lib, "curl_easy_getinfo");
    *(void **)&easy_cleanup = dlsym(lib, "curl_easy_cleanup");
    if (!easy_init || !easy_setopt || !easy_perform || !ctx.getinfo || !easy_cleanup || !(ctx.h = easy_init())) {
        printf("[update] libcurl unusable, no update check\n");
        dlclose(lib);
        return 0;
    }
    snprintf(url, sizeof(url), "https://%s%s", host, path);
    easy_setopt(ctx.h, CURLOPT_URL, url);
    easy_setopt(ctx.h, CURLOPT_USERAGENT, USER_AGENT);
    easy_setopt(ctx.h, CURLOPT_TIMEOUT_MS, (long)(api ? TIMEOUT_MS : 10 * 60 * 1000));
    easy_setopt(ctx.h, CURLOPT_NOSIGNAL, 1L);
    easy_setopt(ctx.h, CURLOPT_FOLLOWLOCATION, 1L);
    easy_setopt(ctx.h, CURLOPT_WRITEFUNCTION, curl_write);
    easy_setopt(ctx.h, CURLOPT_WRITEDATA, (void *)&ctx);
    res = easy_perform(ctx.h);
    if (res != 0) {
        printf("[update] %s: request failed (curl error %d)\n", url, res);
    } else {
        ctx.getinfo(ctx.h, CURLINFO_RESPONSE_CODE, &status);
        if (status != 200) {
            printf("[update] %s: HTTP %ld\n", url, status);
        } else {
            ok = r->len > 0;
        }
    }
    easy_cleanup(ctx.h);
    dlclose(lib);
    return ok;
}
#endif

/* ---- the check ---- */

/* "v0.1.12" or "0.1.12" -> 1 and the three numbers */
static int parse_version(const char *s, int v[3]) {
    char end;

    if (*s == 'v' || *s == 'V') {
        s++;
    }
    v[0] = v[1] = v[2] = 0;
    return sscanf(s, "%d.%d.%d%c", &v[0], &v[1], &v[2], &end) >= 2;
}

static int newer(const int a[3], const int b[3]) {
    for (int i = 0; i < 3; i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return 0;
}

/* the "tag_name": "..." value of the reply, 1 = found */
static int find_tag(const char *json, char *out, size_t out_size) {
    const char *p = strstr(json, "\"tag_name\"");
    size_t n = 0;

    if (p == NULL || (p = strchr(p + 10, ':')) == NULL) {
        return 0;
    }
    p++;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
        p++;
    }
    if (*p++ != '"') {
        return 0;
    }
    while (p[n] != '"' && p[n] != 0 && n + 1 < out_size) {
        n++;
    }
    if (p[n] != '"' || n == 0) {
        return 0;
    }
    memcpy(out, p, n);
    out[n] = 0;
    return 1;
}

static int SDLCALL check_thread(void *unused) {
    Reply r = { NULL, 0, API_MAX };
    char tag[sizeof(g_tag)];
    int remote[3], local[3];
    int state = ST_FAILED;

    (void)unused;
    if (!parse_version(g_local, local)) {
        printf("[update] bad local version \"%s\"\n", g_local);
    } else if (http_get(API_HOST, API_PATH, 1, &r, NULL)) {
        if (!find_tag(r.data, tag, sizeof(tag)) || !parse_version(tag, remote)) {
            printf("[update] no release tag in GitHub's answer\n");
        } else if (newer(remote, local)) {
            SDL_strlcpy(g_tag, tag, sizeof(g_tag));
            state = ST_NEWER;
            printf("[update] %s is available (this is v%s): %s\n", tag, g_local, DW2_RELEASES_URL);
        } else {
            state = ST_CURRENT;
            printf("[update] up to date (v%s, latest release %s)\n", g_local, tag);
        }
    }
    free(r.data);
    SDL_SetAtomicInt(&g_state, state);
    if (g_done != NULL) {
        SDL_SignalSemaphore(g_done);
    }
    return 0;
}

/* ---- progress: a small window of its own, or stdout lines headless ---- */

static SDL_Window *pwin;
static SDL_Renderer *pren;
static char pline[64];
static int plast = -1;
static Uint64 pdraw;

static void progress_open(int no_window) {
    plast = -1;
    pdraw = 0;
    SDL_snprintf(pline, sizeof(pline), "Updating to DW2-PC %s", g_tag);
    if (!no_window && SDL_InitSubSystem(SDL_INIT_VIDEO) &&
        SDL_CreateWindowAndRenderer("Digimon World 2", 640, 160, 0, &pwin, &pren)) {
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

static void progress_draw(const char *line, int pct) {
    SDL_FRect bar = { 10, 52, 300, 14 };

    SDL_SetRenderDrawColor(pren, 16, 20, 32, 255);
    SDL_RenderClear(pren);
    SDL_SetRenderDrawColor(pren, 230, 230, 230, 255);
    SDL_RenderDebugText(pren, 10, 10, pline);
    SDL_RenderDebugText(pren, 10, 30, line);
    SDL_RenderRect(pren, &bar);
    bar.x += 2;
    bar.y += 2;
    bar.h -= 4;
    bar.w = (bar.w - 4) * pct / 100;
    SDL_SetRenderDrawColor(pren, 90, 170, 255, 255);
    SDL_RenderFillRect(pren, &bar);
    SDL_RenderPresent(pren);
}

static int progress(Uint64 done, Uint64 total) {
    int pct = total != 0 ? (int)(done * 100 / total) : 0;
    SDL_Event e;
    int cancel = 0;

    if (pwin == NULL) {
        if (total != 0 && pct / 25 != plast / 25) {
            printf("[update] downloading %d%%\n", pct);
        }
        plast = pct;
        return 0;
    }
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT || e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
            cancel = 1;
        }
    }
    if (pct != plast || SDL_GetTicks() - pdraw > 100) {
        char line[64];

        plast = pct;
        pdraw = SDL_GetTicks();
        if (total != 0) {
            SDL_snprintf(line, sizeof(line), "Downloading %3d%%", pct);
        } else {
            SDL_snprintf(line, sizeof(line), "Downloading %u KB", (unsigned)(done / 1024));
        }
        progress_draw(line, pct);
    }
    return cancel;
}

/* a step without a byte count (connecting, checking, installing) */
static void progress_step(const char *line, int pct) {
    if (pwin == NULL) {
        printf("[update] %s\n", line);
        return;
    }
    SDL_PumpEvents();
    progress_draw(line, pct);
}

/* ---- install ---- */

#define MAX_FILES 8

typedef struct {
    char name[64];  /* plain file name next to the program */
    void *data;
    size_t size;
    int swapped;    /* the old file was renamed to .old (or there was none) and the new one is in */
    int had_old;
} NewFile;

static char g_err[160];

static int fail(const char *fmt, const char *arg) {
    SDL_snprintf(g_err, sizeof(g_err), fmt, arg);
    printf("[update] failed: %s\n", g_err);
    return 0;
}

static int hex_byte(const char *p) {
    int v = 0;

    for (int i = 0; i < 2; i++) {
        char c = p[i];
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

static int sig_ok(const Reply *zip, const Reply *sig) {
    uint8_t s[64];

    if (sig->len < 128) {
        return 0;
    }
    for (int i = 0; i < 64; i++) {
        int b = hex_byte(sig->data + i * 2);
        if (b < 0) {
            return 0;
        }
        s[i] = (uint8_t)b;
    }
    return crypto_ed25519_check(s, update_pubkey, (const uint8_t *)zip->data, zip->len) == 0;
}

/* a file name the zip may put next to the program: no folders, no "..", nothing hidden */
static int plain_name(const char *n) {
    if (n[0] == 0 || n[0] == '.' || strlen(n) >= 64) {
        return 0;
    }
    for (; *n; n++) {
        if (*n == '/' || *n == '\\' || *n == ':') {
            return 0;
        }
    }
    return 1;
}

/* the files under DW2-PC/ in the zip; 0 on a bad zip */
static int unpack(const Reply *zip, NewFile *files, int *count) {
    mz_zip_archive za;
    int n = 0, has_exe = 0;

    *count = 0;
    memset(&za, 0, sizeof(za));
    if (!mz_zip_reader_init_mem(&za, zip->data, zip->len, 0)) {
        return fail("the download is not a zip%s", "");
    }
    for (mz_uint i = 0; i < mz_zip_reader_get_num_files(&za); i++) {
        mz_zip_archive_file_stat st;
        const char *name;

        if (!mz_zip_reader_file_stat(&za, i, &st) || st.m_is_directory) {
            continue;
        }
        if (strncmp(st.m_filename, "DW2-PC/", 7) != 0 || !plain_name(name = st.m_filename + 7)) {
            mz_zip_reader_end(&za);
            return fail("unexpected file %s in the zip", st.m_filename);
        }
        if (n == MAX_FILES) {
            mz_zip_reader_end(&za);
            return fail("too many files in the zip%s", "");
        }
        memset(&files[n], 0, sizeof(files[n]));
        SDL_strlcpy(files[n].name, name, sizeof(files[n].name));
        files[n].data = mz_zip_reader_extract_to_heap(&za, i, &files[n].size, 0);
        if (files[n].data == NULL) {
            mz_zip_reader_end(&za);
            return fail("cannot unpack %s", name);
        }
        has_exe |= strcmp(name, EXE_NAME) == 0;
        *count = ++n;
    }
    mz_zip_reader_end(&za);
    if (!has_exe) {
        return fail("no %s in the zip", EXE_NAME);
    }
    return 1;
}

static char *path_of(const char *dir, const char *name, const char *ext) {
    char *p = NULL;

    SDL_asprintf(&p, "%s%s%s", dir, name, ext);
    return p;
}

static int exists(const char *path) {
    return SDL_GetPathInfo(path, NULL);
}

static int write_file(const char *path, const void *data, size_t size) {
    SDL_IOStream *io = SDL_IOFromFile(path, "wb");
    int ok;

    if (io == NULL) {
        return 0;
    }
    ok = SDL_WriteIO(io, data, size) == size;
    ok &= SDL_CloseIO(io);
    return ok;
}

/* .new files, then rename old -> .old and .new -> name for each; any failure undoes it all */
static int install(const char *dir, NewFile *files, int count) {
    int i, ok = 1;

    for (i = 0; i < count && ok; i++) {
        char *nw = path_of(dir, files[i].name, ".new");
        ok = nw != NULL && write_file(nw, files[i].data, files[i].size);
#ifndef _WIN32
        if (ok && strcmp(files[i].name, EXE_NAME) == 0) {
            chmod(nw, 0755);
        }
#endif
        if (!ok) {
            fail("cannot write %s (is the folder read-only?)", nw != NULL ? nw : files[i].name);
        }
        SDL_free(nw);
    }
    for (i = 0; i < count && ok; i++) {
        char *cur = path_of(dir, files[i].name, ""), *old = path_of(dir, files[i].name, ".old");
        char *nw = path_of(dir, files[i].name, ".new");

        if (exists(old)) {
            SDL_RemovePath(old);
        }
        files[i].had_old = exists(cur);
        if (files[i].had_old && !SDL_RenamePath(cur, old)) {
            ok = fail("cannot move %s aside", cur);
        } else if (!SDL_RenamePath(nw, cur)) {
            if (files[i].had_old) {
                SDL_RenamePath(old, cur);
            }
            ok = fail("cannot put %s in place", cur);
        } else {
            files[i].swapped = 1;
        }
        SDL_free(cur);
        SDL_free(old);
        SDL_free(nw);
    }
    if (!ok) {
        /* undo: the swapped files back, the .new files away */
        for (i = 0; i < count; i++) {
            char *cur = path_of(dir, files[i].name, ""), *old = path_of(dir, files[i].name, ".old");
            char *nw = path_of(dir, files[i].name, ".new");

            if (files[i].swapped) {
                SDL_RemovePath(cur);
                if (files[i].had_old) {
                    SDL_RenamePath(old, cur);
                }
            }
            SDL_RemovePath(nw);
            SDL_free(cur);
            SDL_free(old);
            SDL_free(nw);
        }
    }
    return ok;
}

/* the new program with this run's arguments, minus the update test options */
static int restart(const char *dir, int argc, char **argv) {
    const char **args = (const char **)SDL_calloc((size_t)argc + 2, sizeof(char *));
    char *exe = path_of(dir, EXE_NAME, "");
    SDL_Process *p;
    int n = 0;

    if (args == NULL || exe == NULL) {
        return 0;
    }
    args[n++] = exe;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--update-as") == 0 && i + 1 < argc) {
            i++;
        } else if (strcmp(argv[i], "--update-auto") != 0 && strcmp(argv[i], "--update-check") != 0) {
            args[n++] = argv[i];
        }
    }
    args[n] = NULL;
    p = SDL_CreateProcess(args, false);
    if (p == NULL) {
        printf("[update] cannot start %s: %s\n", exe, SDL_GetError());
    } else {
        printf("[update] started %s\n", exe);
        SDL_DestroyProcess(p); /* frees the handle; the new program runs on */
    }
    SDL_free(args);
    SDL_free(exe);
    return p != NULL;
}

/* download, check, unpack, swap; 1 = done (the new files are in place) */
static int update_now(int no_window) {
    Reply zip = { NULL, 0, ZIP_MAX }, sig = { NULL, 0, 4096 };
    NewFile files[MAX_FILES];
    char path[256];
    const char *dir = SDL_GetBasePath();
    int count = 0, ok = 0;

    g_err[0] = 0;
    if (ASSET == NULL) {
        return fail("no updater for this build%s", "");
    }
    if (dir == NULL) {
        return fail("no program folder%s", "");
    }
    printf("[update] updating %s to %s\n", dir, g_tag);
    progress_open(no_window);
    progress_step("Connecting...", 0);
    SDL_snprintf(path, sizeof(path), DL_PATH "%s/%s", g_tag, ASSET);
    if (!http_get(DL_HOST, path, 0, &zip, progress)) {
        fail("could not download %s", ASSET);
        goto done;
    }
    SDL_snprintf(path, sizeof(path), DL_PATH "%s/%s.sig", g_tag, ASSET);
    if (!http_get(DL_HOST, path, 0, &sig, NULL)) {
        fail("this release has no signature file (%s.sig)", ASSET);
        goto done;
    }
    progress_step("Checking...", 100);
    if (!sig_ok(&zip, &sig)) {
        fail("the download's signature does not match%s", "");
        goto done;
    }
    printf("[update] %s: %u bytes, signature OK\n", ASSET, (unsigned)zip.len);
    if (!unpack(&zip, files, &count)) {
        goto done;
    }
    progress_step("Installing...", 100);
    ok = install(dir, files, count);
done:
    progress_close();
    for (int i = 0; i < count; i++) {
        mz_free(files[i].data);
    }
    free(zip.data);
    free(sig.data);
    return ok;
}

/* the last update's .old files; on Windows the old program may still be closing */
static void cleanup(void) {
    static const char *const names[] = { "dw2.exe", "dw2", "SDL3.dll", "README.txt", "LICENSE.txt" };
    const char *dir = SDL_GetBasePath();

    if (dir == NULL) {
        return;
    }
    for (int i = 0; i < (int)SDL_arraysize(names); i++) {
        char *old = path_of(dir, names[i], ".old");

        for (int tries = 0; old != NULL && exists(old) && tries < 10; tries++) {
            if (SDL_RemovePath(old)) {
                printf("[update] removed %s\n", old);
                break;
            }
            SDL_Delay(200);
        }
        SDL_free(old);
    }
}

/* ---- the start ---- */

void Update_Disable(void) {
    g_disabled = 1;
}

void Update_SetLocalVersion(const char *version) {
    g_local = version;
}

void Update_SetAuto(void) {
    g_auto = 1;
}

void Update_Start(int no_window, int force) {
    SDL_Thread *t;

    cleanup();
    if (!force && (g_disabled || no_window || !Settings_Get(SET_UPDATE_CHECK))) {
        return;
    }
    SDL_SetAtomicInt(&g_state, ST_CHECKING);
    g_done = SDL_CreateSemaphore(0);
    t = SDL_CreateThread(check_thread, "update", NULL);
    if (t == NULL) {
        SDL_SetAtomicInt(&g_state, ST_FAILED);
        return;
    }
    SDL_DetachThread(t);
}

static int ask(const char *title, const char *text, const SDL_MessageBoxButtonData *buttons, int n) {
    SDL_MessageBoxData box = { 0 };
    int pick = -1;

    box.flags = SDL_MESSAGEBOX_INFORMATION | SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT;
    box.title = title;
    box.message = text;
    box.numbuttons = n;
    box.buttons = buttons;
    if (!SDL_ShowMessageBox(&box, &pick)) {
        printf("[update] message box failed: %s\n", SDL_GetError());
        return -1;
    }
    return pick;
}

static int open_page(void) {
    printf("[update] opening %s and quitting\n", DW2_RELEASES_URL);
    if (!SDL_OpenURL(DW2_RELEASES_URL)) {
        printf("[update] could not open %s: %s\n", DW2_RELEASES_URL, SDL_GetError());
        return 0;
    }
    return 1;
}

enum { PICK_PLAY, PICK_PAGE, PICK_UPDATE };

int Update_AskAtStart(int no_window, int argc, char **argv) {
    static const SDL_MessageBoxButtonData found[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, PICK_UPDATE, "Update now" },
        { 0, PICK_PAGE, "Download page" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, PICK_PLAY, "Not now" },
    };
    static const SDL_MessageBoxButtonData failed[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, PICK_PAGE, "Download page" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, PICK_PLAY, "Play now" },
    };
    char text[320];
    int pick;

    if (g_done == NULL || (no_window && !g_auto)) {
        return 0;
    }
    if (!SDL_WaitSemaphoreTimeout(g_done, WAIT_MS)) {
        printf("[update] no answer within %d ms, starting (the result shows on the title and in F1)\n", WAIT_MS);
        return 0;
    }
    if (Update_NewerTag() == NULL) {
        return 0;
    }
    if (g_auto) {
        pick = ASSET != NULL ? PICK_UPDATE : PICK_PLAY;
    } else {
        SDL_snprintf(text, sizeof(text), "DW2-PC %s is out (you have v%s).", g_tag, g_local);
        /* without a zip for this build: no "Update now" */
        pick = ASSET != NULL ? ask("Update found", text, found, 3) : ask("Update found", text, found + 1, 2);
    }
    if (pick == PICK_PAGE) {
        return open_page();
    }
    if (pick != PICK_UPDATE) {
        printf("[update] not now\n");
        return 0;
    }
    if (update_now(no_window)) {
        printf("[update] installed %s\n", g_tag);
        return restart(SDL_GetBasePath(), argc, argv);
    }
    if (g_auto) {
        return 0;
    }
    SDL_snprintf(text, sizeof(text), "The update did not work: %s.\n\nThe game files were not changed.", g_err);
    return ask("Update failed", text, failed, 2) == PICK_PAGE ? open_page() : 0;
}

const char *Update_LocalVersion(void) {
    return g_local;
}

const char *Update_NewerTag(void) {
    return SDL_GetAtomicInt(&g_state) == ST_NEWER ? g_tag : NULL;
}

const char *Update_StatusText(void) {
    switch (SDL_GetAtomicInt(&g_state)) {
    case ST_CHECKING:
        return "Checking for updates...";
    case ST_CURRENT:
        return "Up to date.";
    case ST_NEWER:
        return "A new version is available.";
    case ST_FAILED:
        return "Could not check for updates (offline?).";
    default:
        return "Not checked in this run.";
    }
}
