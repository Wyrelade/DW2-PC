/* PR.2 ImGui layer (release and dev): one Dear ImGui context (host/imgui/, pinned in README.txt)
 * with the SDL3 platform backend and the SDL_Renderer backend, on the renderer host/sdl.c
 * presents with (the SDL_GPU renderer or the default one). Main thread only. It draws the F1
 * settings window (host/settingsui.cpp) and, in dev builds, the F2 overlay (host/devui.cpp, PD.1);
 * both are windows in this one context and can be open together. ImGui draws in window pixels
 * over the picture: the renderer's logical presentation is switched off around it.
 * PR.3: a short notice top left (Ui_Notice: window mode after F11 / F1, F5 / F6 / F7 values),
 * drawn by the same layer for 2 s, with or without the windows open.
 * PR.10: "Press F1 for settings" at the bottom left of the picture while the title runs.
 * PR.15: Esc opens a "Quit?" box (Quit / Cancel) instead of quitting at once. */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

#include "host/settings.h"
#include "host/ui.h"
#include "host/update.h"
#if DW2_DEV
#include "host/devui.h"
#endif

extern "C" int Host_WritePng(const char *path, const uint32_t *pixels, int w, int h);
extern "C" int Host_TitleHint(void);
extern "C" void Host_RequestQuit(const char *why);

namespace {

SDL_Renderer *g_renderer;
bool g_ready;
bool g_headless;
bool g_settings_at_start;
bool g_shots; /* --ui-shots */
/* PR.15 quit question: wanted (Esc toggles it), shown (the ImGui popup is open) */
bool g_quit_want, g_quit_shown;

/* PR.3 notice: any thread posts, the main thread draws */
SDL_Mutex *g_notice_lock;
char g_notice[128];
Uint64 g_notice_until; /* SDL_GetTicks */
#define NOTICE_MS 2000

bool notice_live(void) {
    Uint64 until;

    SDL_LockMutex(g_notice_lock);
    until = g_notice_until;
    SDL_UnlockMutex(g_notice_lock);
    return until != 0 && SDL_GetTicks() < until;
}

void draw_notice(void) {
    char text[128];
    Uint64 now = SDL_GetTicks(), until;

    SDL_LockMutex(g_notice_lock);
    SDL_strlcpy(text, g_notice, sizeof(text));
    until = g_notice_until;
    SDL_UnlockMutex(g_notice_lock);
    if (until == 0 || now >= until) {
        return;
    }
    float k = ImGui::GetStyle().FontScaleDpi;
    float a = until - now < 400 ? (float)(until - now) / 400.0f : 1.0f; /* fade out */
    ImGui::SetNextWindowPos(ImVec2(12.0f * k, 12.0f * k));
    ImGui::SetNextWindowBgAlpha(0.7f * a);
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, a);
    ImGui::Begin("##notice", NULL,
                 ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_AlwaysAutoResize |
                     ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoSavedSettings);
    ImGui::TextUnformatted(text);
    ImGui::End();
    ImGui::PopStyleVar();
}

/* PR.15: Esc asks before quitting (a modal box in the window centre; Cancel has the focus, so
 * Enter or the gamepad's confirm button on a stray press does not quit). The game keeps running
 * behind it without input, as with F1 open. */
void draw_quit(void) {
    static const char id[] = "Quit##quit";
    float k = ImGui::GetStyle().FontScaleDpi;

    if (g_quit_want && !ImGui::IsPopupOpen(id)) {
        ImGui::OpenPopup(id);
    }
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal(id, NULL,
                               ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoSavedSettings)) {
        g_quit_shown = true;
        ImGui::TextUnformatted("Quit Digimon World 2?");
        ImGui::TextDisabled("Progress since your last save will be lost.");
        ImGui::Spacing();
        if (ImGui::Button("Quit", ImVec2(110.0f * k, 0))) {
            Host_RequestQuit("Esc, confirmed");
            g_quit_want = false;
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(110.0f * k, 0))) {
            g_quit_want = false;
        }
        if (ImGui::IsWindowAppearing()) {
            ImGui::SetKeyboardFocusHere(-1); /* Cancel */
        }
        if (!g_quit_want) {
            ImGui::CloseCurrentPopup();
            g_quit_shown = false;
        }
        ImGui::EndPopup();
    } else {
        g_quit_shown = false;
    }
}

/* PR.10: "Press F1 for settings" at the bottom left of the picture while the title runs (the
 * game thread's flag), unless switched off or the F1 window is open. Drawn with each presented
 * picture only: it does not keep the window loop presenting. PR.30: with a newer release found,
 * the line says so instead (also when the hint is switched off). */
bool title_hint_shown(void) {
    return g_ready && Host_TitleHint() && (Settings_Get(SET_TITLE_HINT) || Update_NewerTag() != NULL) &&
           !SettingsUi_IsOpen() && !g_quit_want && !g_quit_shown;
}

void draw_title_hint(void) {
    const char *tag = Update_NewerTag();
    char text[96];
    SDL_FRect r;

    if (tag != NULL) {
        SDL_snprintf(text, sizeof(text), "Update %s available: press F1", tag);
    } else {
        SDL_strlcpy(text, "Press F1 for settings", sizeof(text));
    }

    if (!SDL_GetRenderLogicalPresentationRect(g_renderer, &r) || r.h <= 0) {
        return;
    }
    /* about 1/32 of the picture height, never below the UI's own text size */
    float size = r.h / 32.0f;
    float min = 13.0f * ImGui::GetStyle().FontScaleDpi;
    size = size < min ? min : size;
    float pad = r.h / 60.0f, in = size * 0.35f;
    ImVec2 ts = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.0f, text);
    ImVec2 pos(r.x + pad + in, r.y + r.h - pad - in - ts.y);
    ImDrawList *dl = ImGui::GetForegroundDrawList();

    /* a dark box behind it: the title background is busy */
    dl->AddRectFilled(ImVec2(pos.x - in, pos.y - in * 0.6f), ImVec2(pos.x + ts.x + in, pos.y + ts.y + in * 0.6f),
                      IM_COL32(0, 0, 0, 150), in * 0.6f);
    dl->AddText(ImGui::GetFont(), size, pos, tag != NULL ? IM_COL32(255, 214, 90, 235) : IM_COL32(255, 255, 255, 220),
                text);
}

/* the style for the display's content scale (again when the window moves to another display) */
void apply_scale(SDL_Window *window) {
    float dpi = SDL_GetDisplayContentScale(SDL_GetDisplayForWindow(window));

    if (!(dpi > 0.5f && dpi < 8.0f)) {
        dpi = 1.0f;
    }
    ImGui::GetStyle() = ImGuiStyle();
    ImGui::StyleColorsDark();
    ImGui::GetStyle().ScaleAllSizes(dpi);
    ImGui::GetStyle().FontScaleDpi = dpi;
}

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
    return sc == SDL_SCANCODE_F3 || sc == SDL_SCANCODE_F5 || sc == SDL_SCANCODE_F6 || sc == SDL_SCANCODE_F7 || sc == SDL_SCANCODE_F8 ||
           sc == SDL_SCANCODE_F11 || sc == SDL_SCANCODE_F12;
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
    return g_headless && (g_settings_at_start || g_shots);
}

void Ui_SetShots(int on) {
    g_shots = on != 0;
}

void Ui_Notice(const char *text) {
    if (g_notice_lock == NULL) {
        return;
    }
    SDL_LockMutex(g_notice_lock);
    SDL_strlcpy(g_notice, text, sizeof(g_notice));
    g_notice_until = SDL_GetTicks() + NOTICE_MS;
    SDL_UnlockMutex(g_notice_lock);
}

int Ui_Drawing(void) {
    return Ui_Active() || (g_ready && notice_live());
}

void Ui_Init(SDL_Window *window, SDL_Renderer *renderer, int headless) {
    float dpi;

    g_renderer = renderer;
    g_notice_lock = SDL_CreateMutex();
    g_headless = headless != 0;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = NULL; /* no imgui.ini in the working folder */
    io.LogFilename = NULL;
    apply_scale(window);
    dpi = ImGui::GetStyle().FontScaleDpi;
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
    return g_ready && (SettingsUi_IsOpen() || dev_open() || g_quit_want || g_quit_shown);
}

void Ui_SetQuitAtStart(int on) {
    g_quit_want = on != 0;
}

int Ui_BlocksGameInput(void) {
    if (g_ready && (SettingsUi_IsOpen() || g_quit_want || g_quit_shown)) {
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
    if (e->type == SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED || e->type == SDL_EVENT_WINDOW_DISPLAY_CHANGED) {
        SDL_Window *w = SDL_GetWindowFromID(e->window.windowID);

        if (w != NULL) {
            apply_scale(w);
        }
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
    if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == SDL_SCANCODE_ESCAPE) {
        if (!e->key.repeat) {
            if (SettingsUi_IsOpen()) {
                SettingsUi_SetOpen(0); /* Esc closes the settings window instead of quitting */
            } else {
                g_quit_want = !g_quit_want; /* PR.15: Esc asks first, Esc again cancels */
            }
        }
        return 1;
    }
    if (!Ui_Active()) {
        return 0;
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

    bool hint = title_hint_shown();

    if (!Ui_Drawing() && !hint && !SDL_GetAtomicInt(&g_shot_pending)) {
        return;
    }
    ImGuiIO &io = ImGui::GetIO();
    /* the F1 window is driven by keyboard and gamepad too; the dev overlay alone is not */
    io.ConfigFlags &= ~(ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad);
    if (SettingsUi_IsOpen() || g_quit_want || g_quit_shown) {
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
    if (hint) {
        draw_title_hint();
    }
    if (g_quit_want || g_quit_shown) {
        draw_quit();
    }
    draw_notice();
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
    SDL_DestroyMutex(g_notice_lock);
    g_notice_lock = NULL;
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

} // extern "C"
