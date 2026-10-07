#include <stdio.h>
#include <stdlib.h>

#include "host/host.h"
#include "host/host_sdl.h"

/* SDL3 host: one window (320x240 logical, letterboxed, resizable), black until the emulated GPU
 * (P1.4) has a frame to show. Display vsync is off; the VBlank clock paces and presents once per
 * buffer flip. */

#define WINDOW_SCALE 3

static SDL_Window *window;
static SDL_Renderer *renderer;
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
    printf("[host] window %dx%d (320x240 logical), renderer %s, vsync off\n", 320 * WINDOW_SCALE,
           240 * WINDOW_SCALE, SDL_GetRendererName(renderer));
    Host_Present();
    Host_AudioOpen();
    Host_ClockStart();
    fflush(stdout);
}

void Host_Present(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
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
