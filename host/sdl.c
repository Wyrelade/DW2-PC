#include <stdio.h>
#include <stdlib.h>

#include "backend/psxgpu.h"
#include "host/host.h"
#include "host/host_sdl.h"

/* SDL3 host: one window (320x240 logical, letterboxed, resizable) showing the emulated GPU's
 * display area (P1.4), stretched to the 4:3 picture: 240-line modes scale by whole pixels
 * (nearest), 480-line modes linear. Black while the display is off. Display vsync is off; the
 * VBlank clock paces and presents once per VBlank wait. */

#define WINDOW_SCALE 3

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture; /* 640x480 streaming, the display area in its top-left corner */
static Uint32 frame[640 * 480];
static int initialized;

static void fail(const char *what) {
    fprintf(stderr, "[host] %s failed: %s\n", what, SDL_GetError());
    exit(1);
}

void Host_Init(int no_window) {
    int v = SDL_GetVersion();

    if (no_window) {
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

void Host_Present(void) {
    int w, h;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (PsxGpu_ReadDisplay(frame, &w, &h)) {
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
