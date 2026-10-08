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
 * the surfaces changed. PG.2 (--pgxp, F6): precise GTE vertices for the HD output. PG.3 (--wide,
 * F7): 16:9 picture (427x240 logical), the 4:3 one pillarboxed in it. PG.10b GPU renderer
 * (--renderer gpu, the default with a window): an SDL_GPU device (Vulkan, SPIR-V) draws the HD
 * surfaces (backend/psxgpu_hw.c) and the SDL renderer runs on the same device, showing the
 * surface texture directly (no readback); --renderer soft keeps the software HD rasterizer. */

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
static int logical_w = 320; /* 427 in 16:9 */
static int initialized;
static int renderer_choice; /* 0 automatic (GPU with a window), 1 soft, 2 GPU */
static SDL_GPUDevice *gpudev;
static SDL_Texture *gpu_wrap; /* the display surface's GPU texture as a renderer texture */
static void *wrap_src;
static int wrap_w, wrap_h;

static void fail(const char *what) {
    fprintf(stderr, "[host] %s failed: %s\n", what, SDL_GetError());
    exit(1);
}

void Host_SetRenderer(int choice) {
    renderer_choice = choice;
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

void Host_Init(int no_window) {
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
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, 640, 480);
    if (texture == NULL) {
        fail("SDL_CreateTexture");
    }
    printf("[host] window %dx%d (%dx240 logical), renderer %s, vsync off\n", logical_w * WINDOW_SCALE,
           240 * WINDOW_SCALE, logical_w, SDL_GetRendererName(renderer));
    Host_Present();
    Host_AudioOpen();
    Host_ClockStart();
    fflush(stdout);
}

void Host_SetPgxp(int on) {
    PsxHd_SetPgxp(on);
    Gte_PreciseHook = on ? Pgxp_Record : NULL;
}

void Host_SetWide(int on) {
    PsxHd_SetWide(on);
    logical_w = on ? 427 : 320;
    if (renderer != NULL) {
        SDL_SetRenderLogicalPresentation(renderer, logical_w, 240, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    }
}

int Host_WideMargin(int width) {
    return PsxHd_Margin(width);
}

void Host_PillarboxFrame(void) {
    PsxHd_PillarboxFrame();
}

/* GPU renderer: the display surface texture drawn as it is. */
static int present_gpu(void) {
    void *tex;
    int tw, th, sx, sy, sw, sh;

    if (!PsxGpu_DisplayTexture(&tex, &tw, &th, &sx, &sy, &sw, &sh)) {
        return 0;
    }
    if (headless) {
        return 1;
    }
    if (gpu_wrap == NULL || tex != wrap_src || tw != wrap_w || th != wrap_h) {
        SDL_PropertiesID props = SDL_CreateProperties();

        if (gpu_wrap != NULL) {
            SDL_DestroyTexture(gpu_wrap);
        }
        SDL_SetPointerProperty(props, SDL_PROP_TEXTURE_CREATE_GPU_TEXTURE_POINTER, tex);
        SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_FORMAT_NUMBER, SDL_PIXELFORMAT_ABGR8888);
        SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_ACCESS_NUMBER, SDL_TEXTUREACCESS_TARGET);
        SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_WIDTH_NUMBER, tw);
        SDL_SetNumberProperty(props, SDL_PROP_TEXTURE_CREATE_HEIGHT_NUMBER, th);
        gpu_wrap = SDL_CreateTextureWithProperties(renderer, props);
        SDL_DestroyProperties(props);
        if (gpu_wrap == NULL) {
            fail("GPU surface texture");
        }
        SDL_SetTextureBlendMode(gpu_wrap, SDL_BLENDMODE_NONE);
        SDL_SetTextureScaleMode(gpu_wrap, SDL_SCALEMODE_LINEAR);
        wrap_src = tex;
        wrap_w = tw;
        wrap_h = th;
    }
    {
        float k = 320.0f / (float)(sw - 2 * PsxHd_LastMargin());
        SDL_FRect src = { (float)sx, (float)sy, (float)sw, (float)sh };
        SDL_FRect dst = { ((float)logical_w - sw * k) / 2, 0, sw * k, 240 };
        SDL_RenderTexture(renderer, gpu_wrap, &src, &dst);
    }
    return 1;
}

/* HD picture into hd_texture; 0 when there is none (the 1x picture is shown then). */
static int present_hd(void) {
    int w, h;

    if (PsxHd_Gpu()) {
        return present_gpu();
    }
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
        /* the 4:3 part of the picture is 320 logical pixels wide, the margins beside it */
        float k = 320.0f / (float)(w - 2 * PsxHd_LastMargin());
        SDL_FRect dst = { ((float)logical_w - w * k) / 2, 0, w * k, 240 };
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
        SDL_FRect dst = { (float)(logical_w - 320) / 2, 0, 320, 240 };

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
            if (e.key.scancode == SDL_SCANCODE_F7 && !e.key.repeat) {
                Host_SetWide(!PsxHd_Wide());
                printf("[gpu] 16:9 %s (F7)\n", PsxHd_Wide() ? "on" : "off");
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
    if (gpu_wrap != NULL) {
        SDL_DestroyTexture(gpu_wrap);
        gpu_wrap = NULL;
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
    Host_Shutdown();
    exit(0);
}
