#include <stdio.h>
#include <stdlib.h>

#include "backend/psxgpu.h"
#include "backend/pgxp.h"
#include "backend/psxgpu_hd.h"
#include "host/host.h"
#include "host/host_sdl.h"
#include "psyq/gte_core.h"

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
 * requests (Host_GameEvents at its next VBlank wait). Headless runs keep one thread, no present. */

#define WINDOW_SCALE 3
#define SLOTS 3

enum { REQ_SCALE = 1, REQ_WIDE = 2, REQ_PGXP = 4, REQ_SHOT = 8, REQ_QUIT = 16 };

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
static SDL_AtomicInt game_done;
static const char *volatile quit_why = "window closed";

static void fail(const char *what) {
    fprintf(stderr, "[host] %s failed: %s\n", what, SDL_GetError());
    exit(1);
}

void Host_SetRenderer(int choice) {
    renderer_choice = choice;
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
    window = SDL_CreateWindow("DW2-Online", logical_w * WINDOW_SCALE, 240 * WINDOW_SCALE,
                              SDL_WINDOW_RESIZABLE | (no_window ? SDL_WINDOW_HIDDEN : 0));
    if (window == NULL) {
        fail("SDL_CreateWindow");
    }
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
    printf("[host] window %dx%d (%dx240 logical), renderer %s, vsync off%s\n", logical_w * WINDOW_SCALE,
           240 * WINDOW_SCALE, logical_w, SDL_GetRendererName(renderer), threaded ? ", game thread" : "");
    Host_AudioOpen();
    fflush(stdout);
}

void Host_SetPgxp(int on) {
    PsxHd_SetPgxp(on);
    Gte_PreciseHook = on ? Pgxp_Record : NULL;
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

    if (headless) {
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
        if (f->tex != NULL) {
            PsxHw_Copy(tex, sx, sy, sw, sh, f->tex);
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

void Host_Present(void) {
    const Frame *f = NULL;
    int slot;

    if (headless) {
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
    SDL_RenderPresent(renderer);
}

static void request(int bits) {
    int old;

    do {
        old = SDL_GetAtomicInt(&requests);
    } while (!SDL_CompareAndSwapAtomicInt(&requests, old, old | bits));
}

/* Main thread (the one thread when headless): window and device events, then the input state. */
void Host_PumpEvents(void) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_EVENT_QUIT:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            quit_why = "window closed";
            request(REQ_QUIT);
            break;
        case SDL_EVENT_KEY_DOWN:
            if (!e.key.repeat) {
                if (e.key.scancode == SDL_SCANCODE_ESCAPE) {
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
            }
            Host_InputPress(&e);
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
}

/* Game thread, once per VBlank wait: the window's requests, then the pad state. A key hit twice
 * between two VBlank waits counts once. */
void Host_GameEvents(void) {
    int r = SDL_SetAtomicInt(&requests, 0);

    if (r & REQ_SHOT) {
        Host_ShotKey();
    }
    if (r & REQ_SCALE) {
        PsxHd_SetScale(PsxHd_Scale() % 8 + 1);
        printf("[gpu] scale %dx (F5)\n", PsxHd_Scale());
        fflush(stdout);
    }
    if (r & REQ_WIDE) {
        Host_SetWide(!PsxHd_Wide());
        printf("[gpu] 16:9 %s (F7)\n", PsxHd_Wide() ? "on" : "off");
        fflush(stdout);
    }
    if (r & REQ_PGXP) {
        Host_SetPgxp(!PsxHd_Pgxp());
        printf("[gpu] no wobble (PGXP) %s (F6)\n", PsxHd_Pgxp() ? "on" : "off");
        fflush(stdout);
    }
    if (r & REQ_QUIT) {
        Host_Quit(quit_why);
    }
    Host_InputLatch();
}

/* Main thread while the game thread runs: events and present until the game has quit. */
void Host_WindowLoop(void) {
    while (!SDL_GetAtomicInt(&game_done)) {
        Host_PumpEvents();
        if (SDL_WaitSemaphoreTimeout(frame_sem, 4)) {
            Host_Present();
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
