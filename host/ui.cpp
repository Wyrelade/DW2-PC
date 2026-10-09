/* PR.2 ImGui layer (release and dev): one Dear ImGui context (host/imgui/, pinned in README.txt)
 * with the SDL3 platform backend and the SDL_Renderer backend, on the renderer host/sdl.c
 * presents with (the SDL_GPU renderer or the default one). Main thread only. It draws the F1
 * settings window (host/settingsui.cpp) and, in dev builds, the F2 overlay (host/devui.cpp, PD.1);
 * both are windows in this one context and can be open together. ImGui draws in window pixels
 * over the picture: the renderer's logical presentation is switched off around it. */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

#include "host/ui.h"
#if DW2_DEV
#include "host/devui.h"
#endif

extern "C" int Host_WritePng(const char *path, const uint32_t *pixels, int w, int h);

namespace {

SDL_Renderer *g_renderer;
bool g_ready;
bool g_headless;
bool g_settings_at_start;

/* headless shots: requested on the game side, written at the next render */
SDL_AtomicInt g_shot_pending;
char g_shot_path[1024];

bool dev_open(void) {
#if DW2_DEV
    return DevUi_IsOpen() != 0;
#else
    return false;
#endif
}

void write_shot(void) {
    SDL_Surface *s = SDL_RenderReadPixels(g_renderer, NULL);
    SDL_Surface *c;

    if (s == NULL) {
        printf("[ui] shot: read failed (%s)\n", SDL_GetError());
        return;
    }
    c = SDL_ConvertSurface(s, SDL_PIXELFORMAT_XRGB8888);
    SDL_DestroySurface(s);
    if (c == NULL) {
        return;
    }
    /* rows into one block (pitch may be padded) */
    uint32_t *px = (uint32_t *)malloc((size_t)c->w * c->h * 4);
    if (px != NULL) {
        for (int y = 0; y < c->h; y++) {
            memcpy(px + (size_t)y * c->w, (const uint8_t *)c->pixels + (size_t)y * c->pitch, (size_t)c->w * 4);
        }
        if (Host_WritePng(g_shot_path, px, c->w, c->h)) {
            printf("[shot] %s (%dx%d)\n", g_shot_path, c->w, c->h);
        } else {
            printf("[shot] cannot write %s\n", g_shot_path);
        }
        free(px);
    }
    SDL_DestroySurface(c);
    fflush(stdout);
}

bool is_hotkey(SDL_Scancode sc) {
    return sc == SDL_SCANCODE_F5 || sc == SDL_SCANCODE_F6 || sc == SDL_SCANCODE_F7 || sc == SDL_SCANCODE_F12;
}

} // namespace

extern "C" {

void Ui_SetSettingsAtStart(int on) {
    g_settings_at_start = on != 0;
}

int Ui_Headless(void) {
#if DW2_DEV
    if (DevUi_Headless()) {
        return 1;
    }
#endif
    return g_headless && g_settings_at_start;
}

void Ui_Init(SDL_Window *window, SDL_Renderer *renderer, int headless) {
    float dpi;

    g_renderer = renderer;
    g_headless = headless != 0;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = NULL; /* no imgui.ini in the working folder */
    io.LogFilename = NULL;
    ImGui::StyleColorsDark();
    dpi = SDL_GetDisplayContentScale(SDL_GetDisplayForWindow(window));
    if (!(dpi > 0.5f && dpi < 8.0f)) {
        dpi = 1.0f;
    }
    ImGui::GetStyle().ScaleAllSizes(dpi);
    ImGui::GetStyle().FontScaleDpi = dpi;
    if (!ImGui_ImplSDL3_InitForSDLRenderer(window, renderer) || !ImGui_ImplSDLRenderer3_Init(renderer)) {
        printf("[ui] ImGui backend init failed: no settings window\n");
        return;
    }
    g_ready = true;
#if DW2_DEV
    DevUi_Init(window, renderer, headless);
#endif
    if (g_settings_at_start) {
        SettingsUi_SetOpen(1);
    }
    printf("[ui] Dear ImGui %s ready (F1 settings%s), display scale %.2f%s\n", IMGUI_VERSION,
           DW2_DEV ? ", F2 dev overlay" : "", dpi, g_settings_at_start ? ", settings open" : "");
    fflush(stdout);
}

int Ui_Active(void) {
    return g_ready && (SettingsUi_IsOpen() || dev_open());
}

int Ui_BlocksGameInput(void) {
    if (g_ready && SettingsUi_IsOpen()) {
        return 1;
    }
#if DW2_DEV
    if (DevUi_WantsKeyboard()) {
        return 1; /* PD.1: the keyboard types into an ImGui field */
    }
#endif
    return 0;
}

int Ui_Event(const SDL_Event *e) {
    bool key = e->type == SDL_EVENT_KEY_DOWN || e->type == SDL_EVENT_KEY_UP || e->type == SDL_EVENT_TEXT_INPUT;

    if (!g_ready) {
        return 0;
    }
    if (SettingsUi_Capture(e)) {
        return 1;
    }
    if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == SDL_SCANCODE_F1) {
        if (!e->key.repeat) {
            SettingsUi_SetOpen(!SettingsUi_IsOpen());
        }
        return 1;
    }
#if DW2_DEV
    if (DevUi_Event(e)) {
        return 1; /* F2 */
    }
#endif
    if (!Ui_Active()) {
        return 0;
    }
    if (SettingsUi_IsOpen() && e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == SDL_SCANCODE_ESCAPE) {
        if (!e->key.repeat) {
            SettingsUi_SetOpen(0); /* Esc closes the settings window instead of quitting */
        }
        return 1;
    }
    ImGui_ImplSDL3_ProcessEvent(e);
    if (key && e->type != SDL_EVENT_TEXT_INPUT && is_hotkey(e->key.scancode)) {
        return 0; /* F5 / F6 / F7 / F12 work with the windows open */
    }
    if (key && ImGui::GetIO().WantCaptureKeyboard) {
        return 1;
    }
    return 0;
}

void Ui_Render(void) {
    int lw, lh;
    SDL_RendererLogicalPresentation mode;

    if (!Ui_Active()) {
        return;
    }
    ImGuiIO &io = ImGui::GetIO();
    /* the F1 window is driven by keyboard and gamepad too; the dev overlay alone is not */
    io.ConfigFlags &= ~(ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad);
    if (SettingsUi_IsOpen()) {
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        if (SettingsUi_PadNavOk()) {
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        }
    }
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
#if DW2_DEV
    if (DevUi_IsOpen()) {
        DevUi_Draw();
    }
#endif
    if (SettingsUi_IsOpen()) {
        SettingsUi_Draw();
    }
    ImGui::Render();
    /* window pixels for ImGui: the logical presentation off around it */
    SDL_GetRenderLogicalPresentation(g_renderer, &lw, &lh, &mode);
    SDL_SetRenderLogicalPresentation(g_renderer, 0, 0, SDL_LOGICAL_PRESENTATION_DISABLED);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), g_renderer);
    if (SDL_GetAtomicInt(&g_shot_pending)) {
        write_shot();
        SDL_SetAtomicInt(&g_shot_pending, 0);
    }
    SDL_SetRenderLogicalPresentation(g_renderer, lw, lh, mode);
}

void Ui_Shot(const char *dir, const char *tag) {
    if (!Ui_Headless() || SDL_GetAtomicInt(&g_shot_pending)) {
        return;
    }
#if DW2_DEV
    snprintf(g_shot_path, sizeof(g_shot_path), "%s/%s_%s.png", dir, tag, DevUi_Headless() ? "devui" : "ui");
#else
    snprintf(g_shot_path, sizeof(g_shot_path), "%s/%s_ui.png", dir, tag);
#endif
    SDL_SetAtomicInt(&g_shot_pending, 1);
}

void Ui_Shutdown(void) {
    if (!g_ready) {
        return;
    }
#if DW2_DEV
    DevUi_Shutdown();
#endif
    g_ready = false;
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

} // extern "C"
