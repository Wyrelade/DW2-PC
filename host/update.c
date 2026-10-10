/* PR.30 update check: one HTTPS GET of the GitHub API's latest release on a background thread
 * at start, "tag_name" compared with DW2_VERSION. Windows asks through WinHTTP (system library);
 * Linux loads libcurl.so.4 at run time, so the program does not need it: without it there is no
 * check. The check starts before the pack check and the window; the start waits up to WAIT_MS
 * for it and, with a newer release, asks "Update found" (download page and quit, or play). A
 * later answer still shows on the title and in F1. Any failure (offline, timeout, rate limit, odd
 * answer) only logs a line and shows "Could not check" in F1. */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host/settings.h"
#include "host/update.h"

#ifdef _WIN32
#include <windows.h>
#include <winhttp.h>
#else
#include <dlfcn.h>
#endif

#define API_HOST "api.github.com"
#define API_PATH "/repos/Wyrelade/DW2-PC/releases/latest"
#define USER_AGENT "DW2-PC/" DW2_VERSION
#define REPLY_MAX (256 * 1024)
#define TIMEOUT_MS 8000
#define WAIT_MS 3000 /* how long the start waits for the answer before it goes on */

enum { ST_OFF, ST_CHECKING, ST_CURRENT, ST_NEWER, ST_FAILED };

static SDL_AtomicInt g_state; /* ST_*; g_tag is written before ST_NEWER */
static SDL_Semaphore *g_done;  /* signalled when the check thread has its answer */
static char g_tag[32];
static int g_disabled;
static const char *g_local = DW2_VERSION;

typedef struct {
    char *data;
    size_t len;
} Reply;

static int reply_add(Reply *r, const void *p, size_t n) {
    if (r->len + n > REPLY_MAX) {
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
/* WinHTTP: system proxy settings, TLS by the system. 1 = HTTP 200 with a body. */
static int fetch(Reply *r) {
    HINTERNET s = NULL, c = NULL, q = NULL;
    DWORD status = 0, size = sizeof(status), n;
    char buf[4096];
    int ok = 0;

    s = WinHttpOpen(L"DW2-PC/" DW2_VERSION, WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME,
                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (s == NULL) {
        goto done;
    }
    WinHttpSetTimeouts(s, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS);
    c = WinHttpConnect(s, L"" API_HOST, INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (c == NULL) {
        goto done;
    }
    q = WinHttpOpenRequest(c, L"GET", L"" API_PATH, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
                           WINHTTP_FLAG_SECURE);
    if (q == NULL ||
        !WinHttpSendRequest(q, L"Accept: application/vnd.github+json\r\n", (DWORD)-1L, WINHTTP_NO_REQUEST_DATA, 0,
                            0, 0) ||
        !WinHttpReceiveResponse(q, NULL) ||
        !WinHttpQueryHeaders(q, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, WINHTTP_HEADER_NAME_BY_INDEX,
                             &status, &size, WINHTTP_NO_HEADER_INDEX)) {
        goto done;
    }
    if (status != 200) {
        printf("[update] GitHub answered HTTP %lu\n", (unsigned long)status);
        goto done;
    }
    for (;;) {
        if (!WinHttpReadData(q, buf, sizeof(buf), &n)) {
            goto done;
        }
        if (n == 0) {
            break;
        }
        if (!reply_add(r, buf, n)) {
            goto done;
        }
    }
    ok = r->len > 0;
done:
    if (!ok && status == 0) {
        printf("[update] request failed (WinHTTP error %lu)\n", (unsigned long)GetLastError());
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

static size_t curl_write(char *p, size_t size, size_t n, void *user) {
    return reply_add((Reply *)user, p, size * n) ? size * n : 0;
}

static int fetch(Reply *r) {
    void *lib = dlopen("libcurl.so.4", RTLD_NOW | RTLD_LOCAL);
    void *(*easy_init)(void);
    int (*easy_setopt)(void *, int, ...);
    int (*easy_perform)(void *);
    int (*easy_getinfo)(void *, int, ...);
    void (*easy_cleanup)(void *);
    void *h;
    long status = 0;
    int res, ok = 0;

    if (lib == NULL) {
        printf("[update] no libcurl.so.4, no update check\n");
        return 0;
    }
    *(void **)&easy_init = dlsym(lib, "curl_easy_init");
    *(void **)&easy_setopt = dlsym(lib, "curl_easy_setopt");
    *(void **)&easy_perform = dlsym(lib, "curl_easy_perform");
    *(void **)&easy_getinfo = dlsym(lib, "curl_easy_getinfo");
    *(void **)&easy_cleanup = dlsym(lib, "curl_easy_cleanup");
    if (!easy_init || !easy_setopt || !easy_perform || !easy_getinfo || !easy_cleanup || !(h = easy_init())) {
        printf("[update] libcurl unusable, no update check\n");
        dlclose(lib);
        return 0;
    }
    easy_setopt(h, CURLOPT_URL, "https://" API_HOST API_PATH);
    easy_setopt(h, CURLOPT_USERAGENT, USER_AGENT);
    easy_setopt(h, CURLOPT_TIMEOUT_MS, (long)TIMEOUT_MS);
    easy_setopt(h, CURLOPT_NOSIGNAL, 1L);
    easy_setopt(h, CURLOPT_FOLLOWLOCATION, 1L);
    easy_setopt(h, CURLOPT_WRITEFUNCTION, curl_write);
    easy_setopt(h, CURLOPT_WRITEDATA, (void *)r);
    res = easy_perform(h);
    if (res != 0) {
        printf("[update] request failed (curl error %d)\n", res);
    } else {
        easy_getinfo(h, CURLINFO_RESPONSE_CODE, &status);
        if (status != 200) {
            printf("[update] GitHub answered HTTP %ld\n", status);
        } else {
            ok = r->len > 0;
        }
    }
    easy_cleanup(h);
    dlclose(lib);
    return ok;
}
#endif

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
    Reply r = { NULL, 0 };
    char tag[sizeof(g_tag)];
    int remote[3], local[3];
    int state = ST_FAILED;

    (void)unused;
    if (!parse_version(g_local, local)) {
        printf("[update] bad local version \"%s\"\n", g_local);
    } else if (fetch(&r)) {
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

void Update_Disable(void) {
    g_disabled = 1;
}

void Update_SetLocalVersion(const char *version) {
    g_local = version;
}

void Update_Start(int no_window, int force) {
    SDL_Thread *t;

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

int Update_AskAtStart(int no_window) {
    static const SDL_MessageBoxButtonData buttons[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "No, play now" },
    };
    SDL_MessageBoxData box = { 0 };
    char text[256];
    int pick = 0;

    if (g_done == NULL || no_window) {
        return 0;
    }
    if (!SDL_WaitSemaphoreTimeout(g_done, WAIT_MS)) {
        printf("[update] no answer within %d ms, starting (the result shows on the title and in F1)\n", WAIT_MS);
        return 0;
    }
    if (Update_NewerTag() == NULL) {
        return 0;
    }
    SDL_snprintf(text, sizeof(text),
                 "DW2-PC %s is available (you have v%s).\n\n"
                 "Go to the download page? The game closes so you can unpack the new version over this "
                 "folder; your saves and settings stay.",
                 g_tag, g_local);
    box.flags = SDL_MESSAGEBOX_INFORMATION;
    box.title = "Update found";
    box.message = text;
    box.numbuttons = 2;
    box.buttons = buttons;
    if (!SDL_ShowMessageBox(&box, &pick)) {
        printf("[update] message box failed: %s\n", SDL_GetError());
        return 0;
    }
    if (pick != 1) {
        printf("[update] player chose to play now\n");
        return 0;
    }
    printf("[update] opening %s and quitting\n", DW2_RELEASES_URL);
    if (!SDL_OpenURL(DW2_RELEASES_URL)) {
        printf("[update] could not open %s: %s\n", DW2_RELEASES_URL, SDL_GetError());
        return 0;
    }
    return 1;
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
