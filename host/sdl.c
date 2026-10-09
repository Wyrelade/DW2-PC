#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "backend/psxgpu.h"
#include "backend/pgxp.h"
#include "backend/psxgpu_hd.h"
#include "host/host.h"
#include "host/host_sdl.h"
#ifndef _WIN32
#include "host/icon_rgba.h"
#endif
#include "host/settings.h"
#include "host/ui.h"
#include "psyq/gte_core.h"
#if DW2_DEV
#include "host/devsnap.h"
#include "host/devui.h"
#endif

/* SDL3 host: one window (320x240 logical, letterboxed, resizable) showing the emulated GPU's
 * display area (P1.4), stretched to the 4:3 picture: 240-line modes scale by whole pixels
 * (nearest), 480-line modes linear. Black while the display is off. Display vsync is off. HD
 * output (PG.1, --scale N, F5): the display area from the HD surface, w*S x h*S, filtered linear
 * to the window. PG.2 (--pgxp, F6): precise GTE vertices for the HD output. PG.3 (--wide, F7):
 * 16:9 picture (427x240 logical), the 4:3 one pillarboxed in it. PG.10b GPU renderer
 * (--renderer gpu, the default with a window): an SDL_GPU device (Vulkan, SPIR-V) draws the HD
 * surfaces (backend/psxgpu_hw.c) and the SDL renderer runs on the same device, showing GPU
 * textures directly (no readback); --renderer soft keeps the software HD rasterizer.
 *
 * PG.10 b3: with a visible window the game runs on its own thread (host/main.c) and the window
 * stays on the main thread (SDL video is main-thread only), so a title-bar drag or a slow present
 * no longer stops the game or the sound. The game thread publishes the displayed picture at each
 * VBlank wait (Host_Publish: GPU: a copy of the display area into a slot texture; soft: the 1x or
 * HD picture into a slot buffer); the main thread shows the newest one (Host_Present), never the
 * one being written (3 slots: newest, shown, written). Hotkeys and quit go to the game thread as
 * requests (Host_GameEvents at its next VBlank wait). Headless runs keep one thread, no present.
 *
 * PR.2: the ImGui layer (host/ui.cpp: the F1 settings window, in dev builds also the PD.1 dev
 * overlay, F2) draws last in Host_Present; the game thread fills the dev snapshot in
 * Host_GameEvents (host/devsnap.c). With both windows closed nothing of this runs.
 * --settings-ui (or dev --devui) with --no-window: the UI also runs headless (publish and present
 * into the hidden window, shots add the UI picture). Display settings changed in F1 reach the game
 * thread as requests (Host_RequestSetting), like F5 / F6 / F7; both update the settings file.
 *
 * PR.3 window modes (windowed, borderless fullscreen, exclusive fullscreen; F11, F1, settings
 * window_mode / fullscreen_display / fullscreen_mode): main thread only, the game thread never
 * sees a mode change (the logical presentation letterboxes the picture into any window size, the
 * GPU renderer's swapchain follows the window). The windowed size, position and maximized state
 * are saved when the player changes them. Headless runs keep the hidden window windowed.
 *
 * PR.2b sharpening (F8, F1, settings sharpen): the game thread sharpens the HD picture when it
 * publishes it (GPU: PsxHw_Sharpen instead of the copy; soft: PsxHd_ReadDisplay). PR.10: the game
 * thread notes at each VBlank wait whether the title runs, for the host's F1 hint (host/ui.cpp). */

#define WINDOW_SCALE 3
#define SLOTS 3

enum { REQ_SCALE = 1, REQ_WIDE = 2, REQ_PGXP = 4, REQ_SHOT = 8, REQ_QUIT = 16, REQ_SETTING = 32, REQ_SHARPEN = 64,
       REQ_SPEED = 128 };

typedef struct {
    int kind;      /* 0 black, 1 1x picture, 2 software HD picture, 3 GPU texture */
    int w, h;      /* picture size */
    int margin;    /* 16:9 margin of the picture (PsxHd_LastMargin), output pixels */
    int logical_w; /* window picture width: 320, 427 in 16:9 */
    Uint32 *px;    /* kinds 1, 2 */
    size_t cap;
    void *tex;     /* kind 3: GPU texture tex_w x tex_h */
    int tex_w, tex_h;
    unsigned gen;  /* changes when tex is replaced */
    unsigned seq;  /* publish number */
} Frame;

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture; /* 640x480 streaming, the display area in its top-left corner */
static SDL_Texture *hd_texture;
static int hd_w, hd_h;
static int headless;
static int threaded;
static int logical_w = 320; /* 427 in 16:9 (game side) */
static int shown_logical_w; /* the window's logical presentation (main thread) */
static int initialized;
static int renderer_choice; /* 0 automatic (GPU with a window), 1 soft, 2 GPU */
static SDL_GPUDevice *gpudev;

static Frame frames[SLOTS];
static int latest = -1, in_use = -1; /* under frame_lock */
static unsigned pub_seq;
static unsigned pub_serial; /* PsxHd_Serial of the newest HD picture */
static int pub_valid;       /* the newest picture is an HD one with that serial */
static SDL_Mutex *frame_lock;
static SDL_Semaphore *frame_sem;
static SDL_Texture *wraps[SLOTS]; /* main thread: the slot textures as renderer textures */
static unsigned wrap_gen[SLOTS];
static unsigned shown_seq[SLOTS];
static SDL_AtomicInt requests;
static SDL_AtomicInt wanted[SET_COUNT]; /* REQ_SETTING: F1's values (+1) for scale, wide, pgxp, sharpen */
static SDL_AtomicInt game_done;
static SDL_AtomicInt on_title; /* PR.10: the game thread saw the title scene at its last VBlank wait */
static int last_sharpen = 50;  /* F8 turns sharpening back on at this strength */
static const char *volatile quit_why = "window closed";

/* PR.3, main thread */
static int win_mode;         /* the mode applied to the window */
static int last_fs = SET_WINDOW_BORDERLESS; /* F11 from windowed goes here */
static int geo_x, geo_y, geo_w, geo_h, geo_max; /* the windowed rect last seen */
static int moved_for_display; /* the window was moved to fullscreen_display: */
static int pre_x, pre_y;      /* where it was before */
static int cursor_hidden;
static void saved_geometry(int *w, int *h, int *x, int *y);
static void remember_geometry(void);

/* Headless runs publish and present only for the headless UI checks (--settings-ui, --devui). */
static int no_present(void) {
    return headless && !Ui_Headless();
}

static void fail(const char *what) {
    char msg[512];

    snprintf(msg, sizeof(msg), "%s failed: %s", what, SDL_GetError());
    fprintf(stderr, "[host] %s\n", msg);
    /* Windows release builds have no console (host/winconsole.c): say it in a box too */
    if (!headless) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon World 2", msg, NULL);
    }
    exit(1);
}

void Host_SetRenderer(int choice) {
    renderer_choice = choice;
}

const char *Host_RendererName(void) {
    return gpudev != NULL ? "GPU (Vulkan)" : "Software";
}

void Host_SetThreaded(int on) {
    threaded = on;
}

int Host_Threaded(void) {
    return threaded;
}

/* GPU device + renderer on it, or 0 (the caller falls back to the default renderer). */
static int init_gpu(void) {
    gpudev = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, NULL);
    if (gpudev == NULL) {
        printf("[host] GPU renderer unavailable (%s), software HD output\n", SDL_GetError());
        return 0;
    }
    if (!PsxHw_Init(gpudev)) {
        SDL_DestroyGPUDevice(gpudev);
        gpudev = NULL;
        return 0;
    }
    renderer = SDL_CreateGPURenderer(gpudev, window);
    if (renderer == NULL) {
        printf("[host] GPU renderer: SDL_CreateGPURenderer failed (%s), software HD output\n", SDL_GetError());
        PsxHw_Shutdown();
        SDL_DestroyGPUDevice(gpudev);
        gpudev = NULL;
        return 0;
    }
    PsxHd_SetGpu(1);
    return 1;
}

/* Main thread: SDL, window, renderer, gamepads, audio device. */
void Host_InitWindow(int no_window) {
    int v = SDL_GetVersion();
    int want_gpu = renderer_choice == 2 || (renderer_choice == 0 && !no_window);
    int win_w = logical_w * WINDOW_SCALE, win_h = 240 * WINDOW_SCALE;
    int win_x = SDL_WINDOWPOS_CENTERED, win_y = SDL_WINDOWPOS_CENTERED;
    SDL_PropertiesID props;

    if (no_window) {
        headless = 1;
        if (!want_gpu) {
            SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "dummy");
        }
        SDL_SetHint(SDL_HINT_AUDIO_DRIVER, "dummy");
    }
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        fail("SDL_Init");
    }
    initialized = 1;
    printf("[host] SDL %d.%d.%d, video driver %s\n", SDL_VERSIONNUM_MAJOR(v), SDL_VERSIONNUM_MINOR(v),
           SDL_VERSIONNUM_MICRO(v), SDL_GetCurrentVideoDriver());
    if (!no_window) {
        saved_geometry(&win_w, &win_h, &win_x, &win_y);
    }
#if DW2_DEV
    DevUi_WindowSize(&win_w, &win_h);
#endif
    props = SDL_CreateProperties();
    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, "DW2-Online");
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_X_NUMBER, win_x);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, win_y);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, win_w);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, win_h);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER,
                          SDL_WINDOW_RESIZABLE | (no_window ? SDL_WINDOW_HIDDEN : 0) |
                              (!no_window && Settings_Get(SET_WIN_MAX) ? SDL_WINDOW_MAXIMIZED : 0));
    window = SDL_CreateWindowWithProperties(props);
    SDL_DestroyProperties(props);
    if (window == NULL) {
        fail("SDL_CreateWindow");
    }
    remember_geometry();
#ifndef _WIN32
    /* Windows takes the icon from the exe (host/dw2.rc); elsewhere it comes from here. */
    {
        SDL_Surface *icon = SDL_CreateSurfaceFrom(DW2_ICON_W, DW2_ICON_H, SDL_PIXELFORMAT_RGBA32,
                                                  (void *)dw2_icon_rgba, DW2_ICON_W * 4);
        if (icon != NULL) {
            SDL_SetWindowIcon(window, icon);
            SDL_DestroySurface(icon);
        }
    }
#endif
    if (!want_gpu || !init_gpu()) {
        renderer = SDL_CreateRenderer(window, NULL);
    }
    if (renderer == NULL) {
        fail("SDL_CreateRenderer");
    }
    SDL_SetRenderVSync(renderer, 0);
    SDL_SetRenderLogicalPresentation(renderer, logical_w, 240, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    shown_logical_w = logical_w;
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, 640, 480);
    if (texture == NULL) {
        fail("SDL_CreateTexture");
    }
    frame_lock = SDL_CreateMutex();
    frame_sem = SDL_CreateSemaphore(0);
    if (frame_lock == NULL || frame_sem == NULL) {
        fail("SDL_CreateMutex");
    }
    Host_InputInit();
    printf("[host] window %dx%d (%dx240 logical), renderer %s, vsync off%s\n", win_w, win_h, logical_w,
           SDL_GetRendererName(renderer), threaded ? ", game thread" : "");
    Ui_Init(window, renderer, no_window);
    Host_AudioOpen();
    win_mode = SET_WINDOW_WINDOWED;
    if (Settings_Get(SET_WINDOW_MODE) != SET_WINDOW_WINDOWED) {
        last_fs = Settings_Get(SET_WINDOW_MODE);
        Host_SetWindowMode(Settings_Get(SET_WINDOW_MODE));
    }
    fflush(stdout);
}

/* ---- PR.3 window modes, main thread ---- */

/* window_size / window_pos from the settings, if the saved rect still lies on a display. */
static void saved_geometry(int *w, int *h, int *x, int *y) {
    int sw, sh, sx, sy, n = 0, i, on = 0;
    SDL_DisplayID *ids;

    if (Settings_WindowSize(&sw, &sh)) {
        *w = sw;
        *h = sh;
    }
    if (!Settings_WindowPos(&sx, &sy)) {
        return;
    }
    /* the title bar must be on a display (a monitor may be gone since) */
    ids = SDL_GetDisplays(&n);
    for (i = 0; i < n && !on; i++) {
        SDL_Rect b, bar = { sx, sy, *w, 32 }, cut;

        on = SDL_GetDisplayBounds(ids[i], &b) && SDL_GetRectIntersection(&b, &bar, &cut) && cut.w >= 64;
    }
    SDL_free(ids);
    if (on) {
        *x = sx;
        *y = sy;
    } else {
        printf("[host] saved window position %d,%d is on no display: centred\n", sx, sy);
    }
}

static void remember_geometry(void) {
    SDL_GetWindowPosition(window, &geo_x, &geo_y);
    SDL_GetWindowSize(window, &geo_w, &geo_h);
    geo_max = (SDL_GetWindowFlags(window) & SDL_WINDOW_MAXIMIZED) != 0;
}

/* A move / resize / maximize while windowed: saved when it differs from what was seen last, so
 * the events of the window's own creation or of a return from fullscreen save nothing. */
static void geometry_event(void) {
    SDL_WindowFlags fl;
    int x, y, w, h, max;

    if (headless || window == NULL) {
        return;
    }
    fl = SDL_GetWindowFlags(window);
    if (fl & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_MINIMIZED)) {
        return;
    }
    max = (fl & SDL_WINDOW_MAXIMIZED) != 0;
    if (max != geo_max) {
        geo_max = max;
        Settings_Set(SET_WIN_MAX, max);
    }
    if (max) {
        return; /* the normal rect stays the saved one */
    }
    SDL_GetWindowPosition(window, &x, &y);
    SDL_GetWindowSize(window, &w, &h);
    if (x != geo_x || y != geo_y) {
        geo_x = x;
        geo_y = y;
        Settings_SetWindowPos(x, y);
    }
    if (w != geo_w || h != geo_h) {
        geo_w = w;
        geo_h = h;
        Settings_SetWindowSize(w, h);
    }
}

/* fullscreen_display: 0 = the display the window is on, N = the Nth display. */
static SDL_DisplayID fullscreen_display(void) {
    int want = Settings_Get(SET_FS_DISPLAY), n = 0;
    SDL_DisplayID *ids, id = 0;

    if (want > 0) {
        ids = SDL_GetDisplays(&n);
        if (ids != NULL && want <= n) {
            id = ids[want - 1];
        } else {
            printf("[host] fullscreen_display %d: only %d display(s), using the window's\n", want, n);
        }
        SDL_free(ids);
    }
    return id != 0 ? id : SDL_GetDisplayForWindow(window);
}

int Host_WindowMode(void) {
    return win_mode;
}

int Host_WindowHeadless(void) {
    return headless;
}

void Host_SetWindowMode(int mode) {
    SDL_DisplayID id;
    SDL_DisplayMode m;
    const SDL_DisplayMode *dm;
    int fw, fh, fhz;

    if (headless || window == NULL) {
        win_mode = mode;
        printf("[host] window mode %s (headless: not applied)\n", Settings_WindowModeName(mode));
        fflush(stdout);
        return;
    }
    if (mode == SET_WINDOW_WINDOWED) {
        SDL_SetWindowFullscreen(window, false);
        SDL_SyncWindow(window);
        if (moved_for_display) {
            SDL_SetWindowPosition(window, pre_x, pre_y);
            moved_for_display = 0;
        }
        win_mode = mode;
        Ui_Notice("Windowed (F11)");
        printf("[host] window mode windowed\n");
        fflush(stdout);
        return;
    }
    id = fullscreen_display();
    if (id != SDL_GetDisplayForWindow(window)) {
        /* to the chosen display first, out of fullscreen if needed */
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
            SDL_SetWindowFullscreen(window, false);
            SDL_SyncWindow(window);
        }
        if (!moved_for_display) {
            SDL_GetWindowPosition(window, &pre_x, &pre_y);
            moved_for_display = 1;
        }
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED_DISPLAY(id), SDL_WINDOWPOS_CENTERED_DISPLAY(id));
        SDL_SyncWindow(window);
    }
    if (mode == SET_WINDOW_EXCLUSIVE) {
        Settings_FsMode(&fw, &fh, &fhz);
        dm = SDL_GetDesktopDisplayMode(id);
        if (fw != 0 && SDL_GetClosestFullscreenDisplayMode(id, fw, fh, fhz / 100.0f, false, &m)) {
            dm = &m;
        } else if (fw != 0) {
            printf("[host] fullscreen_mode %dx%d not offered by the display: desktop mode\n", fw, fh);
        }
        if (dm == NULL || !SDL_SetWindowFullscreenMode(window, dm)) {
            printf("[host] exclusive fullscreen: no display mode (%s), borderless\n", SDL_GetError());
            SDL_SetWindowFullscreenMode(window, NULL);
            mode = SET_WINDOW_BORDERLESS;
        }
    } else {
        SDL_SetWindowFullscreenMode(window, NULL);
    }
    if (!SDL_SetWindowFullscreen(window, true)) {
        printf("[host] fullscreen failed: %s\n", SDL_GetError());
    }
    SDL_SyncWindow(window);
    win_mode = mode;
    last_fs = mode;
    dm = SDL_GetWindowFullscreenMode(window);
    {
        char note[128];

        if (dm != NULL) {
            snprintf(note, sizeof(note), "Exclusive fullscreen %dx%d @ %.0f Hz (F11)", dm->w, dm->h, dm->refresh_rate);
        } else {
            snprintf(note, sizeof(note), "Borderless fullscreen (F11)");
        }
        Ui_Notice(note);
    }
    if (dm != NULL) {
        printf("[host] window mode exclusive, display %u \"%s\", %dx%d @ %.2f Hz\n", (unsigned)id,
               SDL_GetDisplayName(id), dm->w, dm->h, dm->refresh_rate);
    } else {
        int w = 0, h = 0;

        SDL_GetWindowSizeInPixels(window, &w, &h);
        printf("[host] window mode %s, display %u \"%s\", %dx%d\n", Settings_WindowModeName(mode), (unsigned)id,
               SDL_GetDisplayName(id), w, h);
    }
    fflush(stdout);
}

/* F1: the display or the exclusive mode changed: applied again if fullscreen. */
void Host_WindowModeRefresh(void) {
    if (win_mode != SET_WINDOW_WINDOWED) {
        Host_SetWindowMode(win_mode);
    }
}

/* F11: windowed <-> the last fullscreen kind; saved like an F1 change. */
static void toggle_fullscreen(void) {
    int mode = win_mode == SET_WINDOW_WINDOWED ? last_fs : SET_WINDOW_WINDOWED;

    Settings_Set(SET_WINDOW_MODE, mode);
    Host_SetWindowMode(mode);
}

/* Fullscreen: no cursor over the picture while F1 / F2 are closed. */
static void update_cursor(void) {
    int hide = !headless && win_mode != SET_WINDOW_WINDOWED && !Ui_Active();

    if (hide != cursor_hidden) {
        cursor_hidden = hide;
        if (hide) {
            SDL_HideCursor();
        } else {
            SDL_ShowCursor();
        }
    }
}

void Host_SetPgxp(int on) {
    PsxHd_SetPgxp(on);
    Gte_PreciseHook = on ? Pgxp_Record : NULL;
}

/* PR.2b, game side (or before the game runs). */
void Host_SetSharpen(int strength) {
    PsxHd_SetSharpen(strength);
    if (PsxHd_Sharpen() != 0) {
        last_sharpen = PsxHd_Sharpen();
    }
}

/* PR.10, main thread: the title hint may show. */
int Host_TitleHint(void) {
    return SDL_GetAtomicInt(&on_title);
}

/* Game side (or before the window exists); the window follows with the next picture. */
void Host_SetWide(int on) {
    PsxHd_SetWide(on);
    logical_w = on ? 427 : 320;
}

int Host_WideMargin(int width) {
    return PsxHd_Margin(width);
}

void Host_PillarboxFrame(void) {
    PsxHd_PillarboxFrame();
}

/* ---- game thread: the displayed picture into a free slot ---- */

static int ensure_px(Frame *f, size_t n) {
    if (f->cap < n) {
        Uint32 *p = realloc(f->px, n * sizeof(Uint32));

        if (p == NULL) {
            return 0;
        }
        f->px = p;
        f->cap = n;
    }
    return 1;
}

void Host_Publish(void) {
    Frame *f;
    void *tex;
    int tw, th, sx, sy, sw, sh, w, h, i;

    if (no_present()) {
        /* no window: only what showing the picture does to the HD side (the queue drawn, the
         * display surface made), as before PG.10 b3; the queue must not grow between transfers */
        if (PsxHd_Gpu()) {
            PsxGpu_DisplayTexture(&tex, &tw, &th, &sx, &sy, &sw, &sh);
        } else {
            PsxGpu_ReadDisplayHd(NULL, &w, &h);
        }
        return;
    }
    if (pub_valid && PsxHd_On() && PsxHd_Serial() == pub_serial && logical_w == frames[latest].logical_w) {
        return; /* the HD picture has not changed */
    }
    SDL_LockMutex(frame_lock);
    for (i = 0; i < SLOTS && (i == latest || i == in_use); i++) {
    }
    SDL_UnlockMutex(frame_lock);
    f = &frames[i];
    f->kind = 0;
    if (PsxHd_Gpu() && PsxGpu_DisplayTexture(&tex, &tw, &th, &sx, &sy, &sw, &sh)) {
        if (f->tex == NULL || f->tex_w != sw || f->tex_h != sh) {
            if (f->tex != NULL) {
                PsxHw_Release(f->tex);
            }
            f->tex = PsxHw_Create(sw, sh);
            f->tex_w = sw;
            f->tex_h = sh;
            f->gen++;
        }
        if (f->tex != NULL && PsxHd_SharpenActive()) {
            PsxHw_Sharpen(tex, sx, sy, sw, sh, f->tex, PsxHd_SharpenActive());
        } else if (f->tex != NULL) {
            PsxHw_Copy(tex, sx, sy, sw, sh, f->tex);
        }
        if (f->tex != NULL) {
            f->kind = 3;
            f->w = sw;
            f->h = sh;
        }
    } else if (!PsxHd_Gpu() && PsxGpu_ReadDisplayHd(NULL, &w, &h)) {
        if (ensure_px(f, (size_t)w * h) && PsxGpu_ReadDisplayHd(f->px, &w, &h)) {
            f->kind = 2;
            f->w = w;
            f->h = h;
        }
    } else if (ensure_px(f, 640 * 480) && PsxGpu_ReadDisplay(f->px, &w, &h)) {
        f->kind = 1;
        f->w = w;
        f->h = h;
    }
    f->margin = PsxHd_LastMargin();
    f->logical_w = logical_w;
    pub_serial = PsxHd_Serial();
    pub_valid = f->kind >= 2;
    SDL_LockMutex(frame_lock);
    f->seq = ++pub_seq;
    latest = i;
    SDL_UnlockMutex(frame_lock);
    SDL_SignalSemaphore(frame_sem);
}

/* ---- main thread: the newest picture to the window ---- */

static void draw_hd(SDL_Texture *t, const Frame *f) {
    /* the 4:3 part of the picture is 320 logical pixels wide, the margins beside it */
    float k = 320.0f / (float)(f->w - 2 * f->margin);
    SDL_FRect src = { 0, 0, (float)f->w, (float)f->h };
    SDL_FRect dst = { ((float)f->logical_w - f->w * k) / 2, 0, f->w * k, 240 };

    SDL_RenderTexture(renderer, t, &src, &dst);
}

static void wrap_slot(int slot, const Frame *f) {
    SDL_PropertiesID props;

    if (wraps[slot] != NULL && wrap_gen[slot] == f->gen) {
        return;
    }
    if (wraps[slot] != NULL) {
        SDL_DestroyTexture(wraps[slot]); /* does not release the GPU texture */
    }
    props = SDL_CreateProperties();
    SDL_SetPointerProperty(props, SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_POINTER, f->tex);
    SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_FORMAT_NUMBER, SDL_PIXELFORMAT_ABGR8888);
    SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_ACCESS_NUMBER, SDL_TEXTUREACCESS_TARGET);
    SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_WIDTH_NUMBER, f->tex_w);
    SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_HEIGHT_NUMBER, f->tex_h);
    wraps[slot] = SDL_CreateTextureWithProperties(renderer, props);
    SDL_DestroyProperties(props);
    if (wraps[slot] == NULL) {
        fail("GPU picture texture");
    }
    SDL_SetTextureBlendMode(wraps[slot], SDL_BLENDMODE_NONE);
    SDL_SetTextureScaleMode(wraps[slot], SDL_SCALEMODE_LINEAR);
    wrap_gen[slot] = f->gen;
}

/* host/shot.c: pixels w * h words 0x00RRGGBB as a compressed PNG; 0 on failure. */
int Host_WritePngPacked(const char *path, const uint32_t *pixels, int w, int h);

/* PR.22 F12: requested from the game thread, read back by the next Host_Present */
static SDL_AtomicInt shot_wanted;
static char shot_path[1200];
/* PR.23: the PNG is converted, compressed and written by a thread per shot, so F12 costs the
 * render thread only the read back; the result notice comes back through shot_note */
static SDL_AtomicInt shots_busy;
static SDL_SpinLock shot_lock;
static char shot_note[1300];
static int shot_note_set;

typedef struct {
    SDL_Surface *s;
    char path[1200];
} ShotJob;

void Host_WindowShot(const char *path) {
    if (SDL_GetAtomicInt(&shot_wanted)) {
        return;
    }
    SDL_strlcpy(shot_path, path, sizeof(shot_path));
    SDL_SetAtomicInt(&shot_wanted, 1);
}

static int SDLCALL shot_thread(void *data) {
    ShotJob *job = (ShotJob *)data;
    SDL_Surface *c = SDL_ConvertSurface(job->s, SDL_PIXELFORMAT_XRGB8888);
    SDL_PathInfo info;
    Uint64 t0 = SDL_GetTicksNS();
    int ok = 0, w = 0, h = 0, y;

    if (c != NULL) {
        uint32_t *px = (uint32_t *)SDL_malloc((size_t)c->w * c->h * 4);

        w = c->w;
        h = c->h;
        if (px != NULL) {
            for (y = 0; y < c->h; y++) {
                SDL_memcpy(px + (size_t)y * c->w, (const Uint8 *)c->pixels + (size_t)y * c->pitch, (size_t)c->w * 4);
            }
            ok = Host_WritePngPacked(job->path, px, c->w, c->h);
            SDL_free(px);
        }
        SDL_DestroySurface(c);
    }
    if (ok && SDL_GetPathInfo(job->path, &info)) {
        printf("[shot] F12 %s (%dx%d, %llu bytes, %.0f ms)\n", job->path, w, h,
               (unsigned long long)info.size, (double)(SDL_GetTicksNS() - t0) / 1e6);
    } else {
        printf("[shot] cannot write %s (%dx%d)\n", job->path, w, h);
    }
    fflush(stdout);
    SDL_LockSpinlock(&shot_lock);
    SDL_snprintf(shot_note, sizeof(shot_note), ok ? "Screenshot saved: %s" : "Screenshot failed: %s", job->path);
    shot_note_set = 1;
    SDL_UnlockSpinlock(&shot_lock);
    SDL_DestroySurface(job->s);
    SDL_free(job);
    SDL_AddAtomicInt(&shots_busy, -1);
    return 0;
}

/* the game picture in output pixels (the logical presentation's letterbox rect), before the UI
 * layer draws; read with the logical presentation off so the rect is in window pixels */
static void window_shot(void) {
    SDL_FRect fr;
    SDL_Rect r;
    SDL_Surface *s;
    SDL_Thread *t;
    ShotJob *job;
    int lw, lh;
    SDL_RendererLogicalPresentation mode;
    char text[1300];

    if (!SDL_GetRenderLogicalPresentationRect(renderer, &fr)) {
        return;
    }
    r.x = (int)(fr.x + 0.5f);
    r.y = (int)(fr.y + 0.5f);
    r.w = (int)(fr.w + 0.5f);
    r.h = (int)(fr.h + 0.5f);
    SDL_GetRenderLogicalPresentation(renderer, &lw, &lh, &mode);
    SDL_SetRenderLogicalPresentation(renderer, 0, 0, SDL_LOGICAL_PRESENTATION_DISABLED);
    s = SDL_RenderReadPixels(renderer, r.w > 0 && r.h > 0 ? &r : NULL);
    SDL_SetRenderLogicalPresentation(renderer, lw, lh, mode);
    job = s != NULL ? (ShotJob *)SDL_malloc(sizeof(ShotJob)) : NULL;
    if (job == NULL) {
        printf("[shot] F12 read failed: %s\n", SDL_GetError());
        SDL_DestroySurface(s);
        SDL_snprintf(text, sizeof(text), "Screenshot failed: %s", shot_path);
        Ui_Notice(text);
        return;
    }
    job->s = s;
    SDL_strlcpy(job->path, shot_path, sizeof(job->path));
    SDL_AddAtomicInt(&shots_busy, 1);
    t = SDL_CreateThread(shot_thread, "dw2 shot", job);
    if (t != NULL) {
        SDL_DetachThread(t);
    } else {
        shot_thread(job); /* no thread: write it here */
    }
}

/* PR.23: the shot thread's notice, shown from the render thread */
static void shot_notice(void) {
    char text[1300];
    int set;

    SDL_LockSpinlock(&shot_lock);
    set = shot_note_set;
    if (set) {
        SDL_strlcpy(text, shot_note, sizeof(text));
        shot_note_set = 0;
    }
    SDL_UnlockSpinlock(&shot_lock);
    if (set) {
        Ui_Notice(text);
    }
}

void Host_Present(void) {
    const Frame *f = NULL;
    int slot;

    if (no_present()) {
        return;
    }
    SDL_LockMutex(frame_lock);
    if (latest >= 0) {
        in_use = latest;
    }
    slot = in_use;
    SDL_UnlockMutex(frame_lock);
    if (slot >= 0) {
        f = &frames[slot];
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (f != NULL && f->logical_w != shown_logical_w) {
        shown_logical_w = f->logical_w;
        SDL_SetRenderLogicalPresentation(renderer, shown_logical_w, 240, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    }
    if (f != NULL && f->kind == 3) {
        wrap_slot(slot, f);
        draw_hd(wraps[slot], f);
    } else if (f != NULL && f->kind == 2) {
        if (f->w != hd_w || f->h != hd_h || hd_texture == NULL) {
            if (hd_texture != NULL) {
                SDL_DestroyTexture(hd_texture);
            }
            hd_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, f->w, f->h);
            if (hd_texture == NULL) {
                fail("HD texture");
            }
            SDL_SetTextureScaleMode(hd_texture, SDL_SCALEMODE_LINEAR);
            hd_w = f->w;
            hd_h = f->h;
            SDL_memset(shown_seq, 0, sizeof(shown_seq));
        }
        if (shown_seq[slot] != f->seq) {
            SDL_memset(shown_seq, 0, sizeof(shown_seq));
            shown_seq[slot] = f->seq;
            SDL_UpdateTexture(hd_texture, NULL, f->px, f->w * 4);
        }
        draw_hd(hd_texture, f);
    } else if (f != NULL && f->kind == 1) {
        SDL_Rect r = { 0, 0, f->w, f->h };
        SDL_FRect src = { 0, 0, (float)f->w, (float)f->h };
        SDL_FRect dst = { (float)(f->logical_w - 320) / 2, 0, 320, 240 };

        SDL_UpdateTexture(texture, &r, f->px, f->w * 4);
        SDL_SetTextureScaleMode(texture, f->h > 256 ? SDL_SCALEMODE_LINEAR : SDL_SCALEMODE_NEAREST);
        SDL_RenderTexture(renderer, texture, &src, &dst);
    }
    if (SDL_GetAtomicInt(&shot_wanted)) {
        window_shot();
        SDL_SetAtomicInt(&shot_wanted, 0);
    }
    shot_notice();
    Ui_Render();
    SDL_RenderPresent(renderer);
}

static void request(int bits) {
    int old;

    do {
        old = SDL_GetAtomicInt(&requests);
    } while (!SDL_CompareAndSwapAtomicInt(&requests, old, old | bits));
}

/* Main thread (PR.15 quit box): quit at the game thread's next VBlank wait. */
void Host_RequestQuit(const char *why) {
    quit_why = why;
    request(REQ_QUIT);
}

/* Main thread (F1 window): a display setting for the game thread (scale, wide, pgxp). */
void Host_RequestSetting(int id, int value) {
    SDL_SetAtomicInt(&wanted[id], value + 1); /* 0 = nothing wanted */
    request(REQ_SETTING);
}

/* Main thread (the one thread when headless): window and device events, then the input state. */
void Host_PumpEvents(void) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (Ui_Event(&e)) {
            continue; /* F1 / F2, a remap key, or a key for an ImGui field */
        }
        switch (e.type) {
        case SDL_EVENT_QUIT:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            quit_why = "window closed";
            request(REQ_QUIT);
            break;
        case SDL_EVENT_KEY_DOWN:
            if (!e.key.repeat) {
                if (e.key.scancode == SDL_SCANCODE_ESCAPE) {
                    /* only without the ImGui layer: it asks first (PR.15) */
                    quit_why = "Esc";
                    request(REQ_QUIT);
                }
                if (e.key.scancode == SDL_SCANCODE_F12) {
                    request(REQ_SHOT);
                }
                if (e.key.scancode == SDL_SCANCODE_F5) {
                    request(REQ_SCALE);
                }
                if (e.key.scancode == SDL_SCANCODE_F7) {
                    request(REQ_WIDE);
                }
                if (e.key.scancode == SDL_SCANCODE_F6) {
                    request(REQ_PGXP);
                }
                if (e.key.scancode == SDL_SCANCODE_F8) {
                    request(REQ_SHARPEN);
                }
                if (e.key.scancode == SDL_SCANCODE_F3) {
                    request(REQ_SPEED);
                }
                if (e.key.scancode == SDL_SCANCODE_F11) {
                    toggle_fullscreen();
                }
            }
            Host_InputPress(&e);
            break;
        case SDL_EVENT_WINDOW_MOVED:
        case SDL_EVENT_WINDOW_RESIZED:
        case SDL_EVENT_WINDOW_MAXIMIZED:
        case SDL_EVENT_WINDOW_RESTORED:
            geometry_event();
            break;
        case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
            Host_InputPress(&e);
            break;
        case SDL_EVENT_GAMEPAD_ADDED:
        case SDL_EVENT_GAMEPAD_REMOVED:
            Host_InputDevice(&e);
            break;
        default:
            break;
        }
    }
    Host_InputPoll();
    update_cursor();
    Settings_SaveIfDirty();
}

/* A hotkey's new value as a notice (F5 / F6 / F7: game thread; the window shows it). */
static void notice(const char *fmt, ...) {
    char text[128];
    va_list ap;

    if (headless) {
        return;
    }
    va_start(ap, fmt);
    vsnprintf(text, sizeof(text), fmt, ap);
    va_end(ap);
    Ui_Notice(text);
}

/* Game thread, once per VBlank wait: the window's requests, then the pad state. A key hit twice
 * between two VBlank waits counts once. */
void Host_GameEvents(void) {
    int r = SDL_SetAtomicInt(&requests, 0);

    if (r & REQ_SHOT) {
        Host_ShotKey();
    }
    if (r & REQ_SETTING) {
        int v;

        if ((v = SDL_SetAtomicInt(&wanted[SET_SCALE], 0)) != 0 && v - 1 != PsxHd_Scale()) {
            PsxHd_SetScale(v - 1);
            printf("[gpu] scale %dx (F1)\n", PsxHd_Scale());
            Settings_Set(SET_SCALE, PsxHd_Scale());
        }
        if ((v = SDL_SetAtomicInt(&wanted[SET_WIDE], 0)) != 0 && v - 1 != PsxHd_Wide()) {
            Host_SetWide(v - 1);
            printf("[gpu] 16:9 %s (F1)\n", PsxHd_Wide() ? "on" : "off");
            Settings_Set(SET_WIDE, PsxHd_Wide());
        }
        if ((v = SDL_SetAtomicInt(&wanted[SET_PGXP], 0)) != 0 && v - 1 != PsxHd_Pgxp()) {
            Host_SetPgxp(v - 1);
            printf("[gpu] no wobble (PGXP) %s (F1)\n", PsxHd_Pgxp() ? "on" : "off");
            Settings_Set(SET_PGXP, PsxHd_Pgxp());
        }
        if ((v = SDL_SetAtomicInt(&wanted[SET_SHARPEN], 0)) != 0 && v - 1 != PsxHd_Sharpen()) {
            Host_SetSharpen(v - 1);
            printf("[gpu] sharpen %d (F1)\n", PsxHd_Sharpen());
            Settings_Set(SET_SHARPEN, PsxHd_Sharpen());
        }
        fflush(stdout);
    }
    if (r & REQ_SHARPEN) {
        Host_SetSharpen(PsxHd_Sharpen() != 0 ? 0 : last_sharpen);
        printf("[gpu] sharpen %d (F8)\n", PsxHd_Sharpen());
        if (PsxHd_Sharpen() == 0) {
            notice("Sharpening off (F8)");
        } else {
            notice("Sharpening %d (F8)%s", PsxHd_Sharpen(), PsxHd_Scale() > 1 ? "" : ", needs scale 2x or more");
        }
        Settings_Set(SET_SHARPEN, PsxHd_Sharpen());
        fflush(stdout);
    }
    if (r & REQ_SPEED) {
        Host_SpeedSet(!Host_SpeedOn());
        if (!Host_SpeedOn()) {
            printf("[host] speed-up off (F3)\n");
            notice("Speed locked (F3)");
        } else if (Settings_Get(SET_SPEED) == 0) {
            printf("[host] speed-up on, no limit (F3)\n");
            notice("Speed unlocked: no limit (F3)");
        } else {
            printf("[host] speed-up on, %dx (F3)\n", Settings_Get(SET_SPEED));
            notice("Speed unlocked: %dx (F3)", Settings_Get(SET_SPEED));
        }
        fflush(stdout);
    }
    if (r & REQ_SCALE) {
        PsxHd_SetScale(PsxHd_Scale() % 8 + 1);
        printf("[gpu] scale %dx (F5)\n", PsxHd_Scale());
        notice("Resolution scale %dx (F5)", PsxHd_Scale());
        Settings_Set(SET_SCALE, PsxHd_Scale());
        fflush(stdout);
    }
    if (r & REQ_WIDE) {
        Host_SetWide(!PsxHd_Wide());
        printf("[gpu] 16:9 %s (F7)\n", PsxHd_Wide() ? "on" : "off");
        notice("16:9 widescreen %s (F7)", PsxHd_Wide() ? "on" : "off");
        Settings_Set(SET_WIDE, PsxHd_Wide());
        fflush(stdout);
    }
    if (r & REQ_PGXP) {
        Host_SetPgxp(!PsxHd_Pgxp());
        printf("[gpu] no wobble (PGXP) %s (F6)\n", PsxHd_Pgxp() ? "on" : "off");
        notice("No wobble %s (F6)", PsxHd_Pgxp() ? "on" : "off");
        Settings_Set(SET_PGXP, PsxHd_Pgxp());
        fflush(stdout);
    }
    if (r & REQ_QUIT) {
        Host_Quit(quit_why);
    }
    SDL_SetAtomicInt(&on_title, Host_OnTitle());
    Host_InputLatch();
#if DW2_DEV
    DevSnap_Capture();
#endif
    if (!threaded && Ui_Headless()) {
        Host_Present(); /* --settings-ui / --devui headless: the UI into the hidden window */
    }
}

/* Main thread while the game thread runs: events and present until the game has quit. */
void Host_WindowLoop(void) {
    while (!SDL_GetAtomicInt(&game_done)) {
        Host_PumpEvents();
        if (SDL_WaitSemaphoreTimeout(frame_sem, 4)) {
            Host_Present();
        }
        else if (Ui_Drawing()) {
            Host_Present(); /* ImGui needs frames while the game picture stays the same */
        }
    }
    Host_Shutdown();
    exit(0);
}

void Host_Shutdown(void) {
    int i;

    if (!initialized) {
        return;
    }
    initialized = 0;
    while (SDL_GetAtomicInt(&shots_busy) > 0) {
        SDL_Delay(5); /* PR.23: let F12 shots finish writing */
    }
    Settings_Flush();
    Ui_Shutdown();
    Host_AudioClose();
    Host_InputClose();
    for (i = 0; i < SLOTS; i++) {
        if (wraps[i] != NULL) {
            SDL_DestroyTexture(wraps[i]);
            wraps[i] = NULL;
        }
        if (frames[i].tex != NULL) {
            PsxHw_Release(frames[i].tex);
            frames[i].tex = NULL;
        }
        free(frames[i].px);
        frames[i].px = NULL;
    }
    if (hd_texture != NULL) {
        SDL_DestroyTexture(hd_texture);
        hd_texture = NULL;
    }
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    if (gpudev != NULL) {
        PsxHd_SetGpu(0);
        PsxHw_Shutdown();
    }
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (gpudev != NULL) {
        SDL_DestroyGPUDevice(gpudev);
        gpudev = NULL;
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    SDL_Quit();
    printf("[host] shutdown\n");
    fflush(stdout);
}

void Host_Quit(const char *why) {
    printf("[host] quit (%s)\n", why);
    Host_LogRate("run");
    if (threaded) {
        /* the game thread stops here; the main thread shuts SDL down and exits */
        SDL_SetAtomicInt(&game_done, 1);
        SDL_SignalSemaphore(frame_sem);
        for (;;) {
            SDL_Delay(1000);
        }
    }
    Host_Shutdown();
    exit(0);
}
