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
 * (nearest), 480-line modes linear. Black while the display is off. Display vsync is off; the
 * VBlank clock paces and presents once per VBlank wait. HD output (PG.1, --scale N, F5): the
 * display area from the HD surface, w*S x h*S, filtered linear to the window; uploaded only when
 * the surfaces changed. PG.2 (--pgxp, F6): precise GTE vertices for the HD output. */

#define WINDOW_SCALE 3

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture; /* 640x480 streaming, the display area in its top-left corner */
static Uint32 frame[640 * 480];
static SDL_Texture *hd_texture;
static Uint32 *hd_frame;
static int hd_w, hd_h;
static unsigned hd_serial;
static int headless;
static int initialized;

static void fail(const char *what) {
    fprintf(stderr, "[host] %s failed: %s\n", what, SDL_GetError());
    exit(1);
}

void Host_Init(int no_window) {
    int v = SDL_GetVersion();

    if (no_window) {
        headless = 1;
        SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "dummy");
        SDL_SetHint(SDL_HINT_AUDIO_DRIVER, "dummy");
    }
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        fail("SDL_Init");
    }
    initialized = 1;
    printf("[host] SDL %d.%d.%d, video driver %s\n", SDL_VERSIONNUM_MAJOR(v), SDL_VERSIONNUM_MINOR(v),
           SDL_VERSIONNUM_MICRO(v), SDL_GetCurrentVideoDriver());
    window = SDL_CreateWindow("DW2-Online", 320 * WINDOW_SCALE, 240 * WINDOW_SCALE, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fail("SDL_CreateWindow");
    }
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        fail("SDL_CreateRenderer");
    }
    SDL_SetRenderVSync(renderer, 0);
    SDL_SetRenderLogicalPresentation(renderer, 320, 240, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, 640, 480);
    if (texture == NULL) {
        fail("SDL_CreateTexture");
    }
    printf("[host] window %dx%d (320x240 logical), renderer %s, vsync off\n", 320 * WINDOW_SCALE,
           240 * WINDOW_SCALE, SDL_GetRendererName(renderer));
    Host_Present();
    Host_AudioOpen();
    Host_ClockStart();
    fflush(stdout);
}

void Host_SetPgxp(int on) {
    PsxHd_SetPgxp(on);
    Gte_PreciseHook = on ? Pgxp_Record : NULL;
}

/* HD picture into hd_texture; 0 when there is none (the 1x picture is shown then). */
static int present_hd(void) {
    int w, h;

    if (!PsxGpu_ReadDisplayHd(NULL, &w, &h)) {
        return 0;
    }
    if (headless) {
        return 1; /* nothing to see; screenshots read the surfaces themselves */
    }
    if (w != hd_w || h != hd_h || hd_texture == NULL) {
        if (hd_texture != NULL) {
            SDL_DestroyTexture(hd_texture);
        }
        free(hd_frame);
        hd_frame = malloc((size_t)w * h * sizeof(Uint32));
        hd_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
        if (hd_frame == NULL || hd_texture == NULL) {
            fail("HD texture");
        }
        SDL_SetTextureScaleMode(hd_texture, SDL_SCALEMODE_LINEAR);
        hd_w = w;
        hd_h = h;
        hd_serial = PsxHd_Serial() - 1;
    }
    if (hd_serial != PsxHd_Serial()) {
        hd_serial = PsxHd_Serial();
        PsxGpu_ReadDisplayHd(hd_frame, &w, &h);
        SDL_UpdateTexture(hd_texture, NULL, hd_frame, w * 4);
    }
    {
        SDL_FRect dst = { 0, 0, 320, 240 };
        SDL_RenderTexture(renderer, hd_texture, NULL, &dst);
    }
    return 1;
}

void Host_Present(void) {
    int w, h;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (present_hd()) {
    } else if (PsxGpu_ReadDisplay(frame, &w, &h)) {
        SDL_Rect r = { 0, 0, w, h };
        SDL_FRect src = { 0, 0, (float)w, (float)h };
        SDL_FRect dst = { 0, 0, 320, 240 };

        SDL_UpdateTexture(texture, &r, frame, w * 4);
        SDL_SetTextureScaleMode(texture, h > 256 ? SDL_SCALEMODE_LINEAR : SDL_SCALEMODE_NEAREST);
        SDL_RenderTexture(renderer, texture, &src, &dst);
    }
    SDL_RenderPresent(renderer);
}

void Host_PumpEvents(void) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_EVENT_QUIT:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            Host_Quit("window closed");
            break;
        case SDL_EVENT_KEY_DOWN:
            if (e.key.scancode == SDL_SCANCODE_ESCAPE) {
                Host_Quit("Esc");
            }
            if (e.key.scancode == SDL_SCANCODE_F12 && !e.key.repeat) {
                Host_ShotKey();
            }
            if (e.key.scancode == SDL_SCANCODE_F5 && !e.key.repeat) {
                PsxHd_SetScale(PsxHd_Scale() % 8 + 1);
                printf("[gpu] scale %dx (F5)\n", PsxHd_Scale());
                fflush(stdout);
            }
            if (e.key.scancode == SDL_SCANCODE_F6 && !e.key.repeat) {
                Host_SetPgxp(!PsxHd_Pgxp());
                printf("[gpu] no wobble (PGXP) %s (F6)\n", PsxHd_Pgxp() ? "on" : "off");
                fflush(stdout);
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
    Host_InputUpdate();
}

void Host_Shutdown(void) {
    if (!initialized) {
        return;
    }
    initialized = 0;
    Host_AudioClose();
    Host_InputClose();
    if (hd_texture != NULL) {
        SDL_DestroyTexture(hd_texture);
        hd_texture = NULL;
    }
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
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
    Host_Shutdown();
    exit(0);
}
