/* PR.2 F1 settings window (release and dev; host/ui.cpp runs the ImGui frame). Main thread.
 * Display settings go to the game thread as requests (Host_RequestSetting: it applies them at its
 * next VBlank wait and updates the settings, as F5 / F6 / F7 do), so the window always shows the
 * live values. Bindings, stick to D-pad and volume belong to the main thread and change here.
 * Every change marks the settings file for saving (host/settings.c). */

#include <SDL3/SDL.h>
#include <stdio.h>

#include "imgui.h"

#include "host/settings.h"
#include "host/ui.h"

extern "C" void Host_RequestSetting(int id, int value);
extern "C" void Host_AudioSetVolume(int volume);
extern "C" const char *Host_RendererName(void);
extern "C" int Host_WindowMode(void);
extern "C" int Host_WindowHeadless(void);
extern "C" void Host_SetWindowMode(int mode);
extern "C" void Host_WindowModeRefresh(void);

namespace {

bool g_open;
/* remap waiting for input: bit, slot 0 / 1 = keyboard key, 2 = gamepad */
int g_cap_bit = -1, g_cap_slot;
bool g_pad_quiet; /* no gamepad navigation until every pad button is up again */
char g_msg[96];
char g_start_tab[16]; /* --settings-tab: selected in the first frame (headless shots) */

const char *key_label(int sc) {
    const char *n = sc != 0 ? SDL_GetScancodeName((SDL_Scancode)sc) : "";
    return n[0] != 0 ? n : "-";
}

/* Gamepad slots by position, with the Xbox and PlayStation names. */
const char *pad_label(int code) {
    switch (code) {
    case SET_PAD_NONE: return "-";
    case SET_PAD_LTRIGGER: return "LT / L2";
    case SET_PAD_RTRIGGER: return "RT / R2";
    case SDL_GAMEPAD_BUTTON_SOUTH: return "A / Cross";
    case SDL_GAMEPAD_BUTTON_EAST: return "B / Circle";
    case SDL_GAMEPAD_BUTTON_WEST: return "X / Square";
    case SDL_GAMEPAD_BUTTON_NORTH: return "Y / Triangle";
    case SDL_GAMEPAD_BUTTON_LEFT_SHOULDER: return "LB / L1";
    case SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER: return "RB / R1";
    case SDL_GAMEPAD_BUTTON_LEFT_STICK: return "L stick / L3";
    case SDL_GAMEPAD_BUTTON_RIGHT_STICK: return "R stick / R3";
    case SDL_GAMEPAD_BUTTON_BACK: return "Back / Select";
    case SDL_GAMEPAD_BUTTON_START: return "Start";
    case SDL_GAMEPAD_BUTTON_DPAD_UP: return "D-pad Up";
    case SDL_GAMEPAD_BUTTON_DPAD_DOWN: return "D-pad Down";
    case SDL_GAMEPAD_BUTTON_DPAD_LEFT: return "D-pad Left";
    case SDL_GAMEPAD_BUTTON_DPAD_RIGHT: return "D-pad Right";
    default: return Settings_PadName(code);
    }
}

bool any_pad_button(void) {
    int n = 0;
    SDL_JoystickID *ids = SDL_GetGamepads(&n);
    bool held = false;

    for (int i = 0; i < n && !held; i++) {
        SDL_Gamepad *g = SDL_GetGamepadFromID(ids[i]);

        for (int b = 0; g != NULL && b < SDL_GAMEPAD_BUTTON_COUNT && !held; b++) {
            held = SDL_GetGamepadButton(g, (SDL_GamepadButton)b);
        }
        if (g != NULL && !held) {
            held = SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > 8000 ||
                   SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > 8000;
        }
    }
    SDL_free(ids);
    return held;
}

void end_capture(void) {
    g_cap_bit = -1;
    g_pad_quiet = true;
}

/* PR.3: the Window section. Changes apply at once (main thread) and are saved. */
void window_section(void) {
    int mode = Host_WindowMode();
    int disp = Settings_Get(SET_FS_DISPLAY);
    int n = 0;
    SDL_DisplayID *ids = SDL_GetDisplays(&n);
    const char *modes[] = { "Windowed", "Borderless fullscreen", "Exclusive fullscreen" };
    char label[128];

    ImGui::SeparatorText("Window");
    if (ImGui::Combo("Window mode (F11)", &mode, modes, 3)) {
        Settings_Set(SET_WINDOW_MODE, mode);
        Host_SetWindowMode(mode);
    }
    /* display: 0 = the one the window is on */
    if (disp > n) {
        snprintf(label, sizeof(label), "Display %d (not connected)", disp);
    } else if (disp > 0) {
        snprintf(label, sizeof(label), "%d: %s", disp, SDL_GetDisplayName(ids[disp - 1]));
    } else {
        snprintf(label, sizeof(label), "Current display");
    }
    if (ImGui::BeginCombo("Fullscreen display", label)) {
        for (int i = 0; i <= n; i++) {
            char item[128];

            if (i == 0) {
                snprintf(item, sizeof(item), "Current display");
            } else {
                snprintf(item, sizeof(item), "%d: %s", i, SDL_GetDisplayName(ids[i - 1]));
            }
            ImGui::PushID(i);
            if (ImGui::Selectable(item, i == disp)) {
                Settings_Set(SET_FS_DISPLAY, i);
                Host_WindowModeRefresh();
            }
            ImGui::PopID();
        }
        ImGui::EndCombo();
    }
    /* exclusive fullscreen resolution: the desktop mode or one of the display's modes */
    SDL_DisplayID id = disp > 0 && disp <= n ? ids[disp - 1] : 0;
    SDL_Window *win = SDL_GetKeyboardFocus();
    if (id == 0) {
        id = win != NULL ? SDL_GetDisplayForWindow(win) : SDL_GetPrimaryDisplay();
    }
    int fw, fh, fhz;
    Settings_FsMode(&fw, &fh, &fhz);
    const SDL_DisplayMode *desk = id != 0 ? SDL_GetDesktopDisplayMode(id) : NULL;
    char desk_label[64];
    if (desk != NULL) {
        snprintf(desk_label, sizeof(desk_label), "Desktop (%dx%d @ %.0f Hz)", desk->w, desk->h, desk->refresh_rate);
    } else {
        snprintf(desk_label, sizeof(desk_label), "Desktop");
    }
    if (fw == 0) {
        SDL_strlcpy(label, desk_label, sizeof(label));
    } else if (fhz != 0) {
        snprintf(label, sizeof(label), "%dx%d @ %.2f Hz", fw, fh, fhz / 100.0);
    } else {
        snprintf(label, sizeof(label), "%dx%d", fw, fh);
    }
    ImGui::BeginDisabled(mode != SET_WINDOW_EXCLUSIVE);
    if (ImGui::BeginCombo("Fullscreen resolution", label)) {
        if (ImGui::Selectable(desk_label, fw == 0)) {
            Settings_SetFsMode(0, 0, 0);
            Host_WindowModeRefresh();
        }
        int count = 0;
        SDL_DisplayMode **list = id != 0 ? SDL_GetFullscreenDisplayModes(id, &count) : NULL;
        for (int i = 0; i < count; i++) {
            const SDL_DisplayMode *m = list[i];
            int hz = (int)(m->refresh_rate * 100 + 0.5f);
            bool dup = m->pixel_density != 1.0f;

            for (int j = 0; j < i && !dup; j++) {
                dup = list[j]->pixel_density == 1.0f && list[j]->w == m->w && list[j]->h == m->h &&
                      (int)(list[j]->refresh_rate * 100 + 0.5f) == hz;
            }
            if (dup) {
                continue;
            }
            char item[64];
            snprintf(item, sizeof(item), "%dx%d @ %.2f Hz", m->w, m->h, m->refresh_rate);
            ImGui::PushID(i);
            if (ImGui::Selectable(item, fw == m->w && fh == m->h && fhz == hz)) {
                Settings_SetFsMode(m->w, m->h, hz);
                Host_WindowModeRefresh();
            }
            ImGui::PopID();
        }
        SDL_free(list);
        ImGui::EndCombo();
    }
    ImGui::EndDisabled();
    SDL_free(ids);
    if (Host_WindowHeadless()) {
        ImGui::TextDisabled("Headless run: the window mode is not applied.");
    } else {
        ImGui::TextDisabled("F11 switches between windowed and fullscreen.");
    }
}

ImGuiTabItemFlags tab_flags(const char *name) {
    return SDL_strcasecmp(g_start_tab, name) == 0 ? ImGuiTabItemFlags_SetSelected : 0;
}

void display_tab(void) {
    int scale = Settings_Get(SET_SCALE);
    bool wide = Settings_Get(SET_WIDE) != 0;
    bool pgxp = Settings_Get(SET_PGXP) != 0;
    int renderer = Settings_Get(SET_RENDERER);

    ImGui::SeparatorText("Picture");
    if (ImGui::SliderInt("Resolution scale (F5)", &scale, 1, 8, "%dx")) {
        Host_RequestSetting(SET_SCALE, scale);
    }
    ImGui::TextDisabled("1x = the PS1's own 320x240. Higher draws 3D sharper (%dx%d).", 320 * scale, 240 * scale);
    if (ImGui::Checkbox("16:9 widescreen (F7)", &wide)) {
        Host_RequestSetting(SET_WIDE, wide);
    }
    if (ImGui::Checkbox("No wobble (F6)", &pgxp)) {
        Host_RequestSetting(SET_PGXP, pgxp);
    }
    ImGui::TextDisabled("Removes the PS1 vertex jitter and texture warp (PGXP).");

    ImGui::SeparatorText("Renderer");
    const char *names[] = { "GPU (Vulkan)", "Software" };
    if (ImGui::Combo("Renderer", &renderer, names, 2)) {
        Settings_Set(SET_RENDERER, renderer);
    }
    ImGui::TextDisabled("Takes effect at the next start. Running now: %s.", Host_RendererName());
    window_section();
    for (int id = SET_SCALE; id <= SET_WINDOW_MODE; id++) {
        if (Settings_Overridden(id)) {
            ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.3f, 1.0f),
                               "Some values come from the command line for this run and are not saved.");
            break;
        }
    }
}

void bind_button(int bit, int slot, const char *label) {
    char id[64];
    bool waiting = g_cap_bit == bit && g_cap_slot == slot;

    snprintf(id, sizeof(id), "%s##b%d_%d", waiting ? "press..." : label, bit, slot);
    if (ImGui::Button(id, ImVec2(-1, 0))) {
        g_cap_bit = bit;
        g_cap_slot = slot;
        g_msg[0] = 0;
    }
    if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
        if (slot < 2) {
            Settings_SetKey(bit, slot, 0);
        } else {
            Settings_SetPad(bit, SET_PAD_NONE);
        }
    }
}

void controls_tab(void) {
    bool stick = Settings_Get(SET_STICK_DPAD) != 0;

    if (ImGui::Checkbox("Left stick moves like the D-pad", &stick)) {
        Settings_Set(SET_STICK_DPAD, stick);
    }
    ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
    ImGui::TextWrapped("Click a slot, then press the key or gamepad button. Right click clears it.");
    ImGui::PopStyleColor();
    if (g_msg[0] != 0) {
        ImGui::TextColored(ImVec4(1.0f, 0.6f, 0.4f, 1.0f), "%s", g_msg);
    } else if (g_cap_bit >= 0) {
        ImGui::TextColored(ImVec4(0.5f, 0.9f, 1.0f, 1.0f), "%s: press a %s (Esc cancels)",
                           Settings_ButtonName(g_cap_bit), g_cap_slot < 2 ? "key" : "gamepad button");
    } else {
        ImGui::TextDisabled("Esc, Tab, F1, F2, F5, F6, F7, F11 and F12 are reserved.");
    }
    if (ImGui::BeginTable("binds", 4, ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg)) {
        ImGui::TableSetupColumn("PS1 button", ImGuiTableColumnFlags_WidthStretch, 1.0f);
        ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthStretch, 1.2f);
        ImGui::TableSetupColumn("Key 2", ImGuiTableColumnFlags_WidthStretch, 1.2f);
        ImGui::TableSetupColumn("Gamepad", ImGuiTableColumnFlags_WidthStretch, 1.2f);
        ImGui::TableHeadersRow();
        for (int i = 0; i < 16; i++) {
            int bit = Settings_ButtonOrder[i];

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::AlignTextToFramePadding();
            ImGui::TextUnformatted(Settings_ButtonName(bit));
            for (int slot = 0; slot < 2; slot++) {
                ImGui::TableNextColumn();
                bind_button(bit, slot, key_label(Settings_Key(bit, slot)));
            }
            ImGui::TableNextColumn();
            bind_button(bit, 2, pad_label(Settings_Pad(bit)));
        }
        ImGui::EndTable();
    }
    if (ImGui::Button("Reset controls")) {
        Settings_ResetControls();
        g_cap_bit = -1;
    }
}

void sound_tab(void) {
    int v = Settings_Get(SET_VOLUME);

    if (ImGui::SliderInt("Volume", &v, 0, 100, "%d%%")) {
        Settings_Set(SET_VOLUME, v);
        Host_AudioSetVolume(v);
    }
}

} // namespace

extern "C" {

void SettingsUi_SetTab(const char *name) {
    SDL_strlcpy(g_start_tab, name, sizeof(g_start_tab));
}

int SettingsUi_IsOpen(void) {
    return g_open;
}

void SettingsUi_SetOpen(int on) {
    g_open = on != 0;
    g_cap_bit = -1;
    g_msg[0] = 0;
    g_pad_quiet = true;
    printf("[ui] settings %s (F1)\n", g_open ? "open" : "closed");
    fflush(stdout);
}

int SettingsUi_Capturing(void) {
    return g_open && g_cap_bit >= 0;
}

int SettingsUi_PadNavOk(void) {
    if (g_cap_bit >= 0) {
        return 0;
    }
    if (g_pad_quiet && !any_pad_button()) {
        g_pad_quiet = false;
    }
    return !g_pad_quiet;
}

int SettingsUi_Capture(const SDL_Event *e) {
    if (!SettingsUi_Capturing()) {
        return 0;
    }
    if (e->type == SDL_EVENT_KEY_DOWN) {
        SDL_Scancode sc = e->key.scancode;

        if (e->key.repeat) {
            return 1;
        }
        if (sc == SDL_SCANCODE_ESCAPE) {
            end_capture();
        } else if (g_cap_slot == 2) {
            /* waiting for a gamepad button: keys other than Esc are ignored */
        } else if (Settings_KeyReserved(sc)) {
            snprintf(g_msg, sizeof(g_msg), "%s is reserved, pick another key.", SDL_GetScancodeName(sc));
        } else {
            Settings_SetKey(g_cap_bit, g_cap_slot, sc);
            g_msg[0] = 0;
            end_capture();
        }
        return 1;
    }
    if (e->type == SDL_EVENT_KEY_UP || e->type == SDL_EVENT_TEXT_INPUT) {
        return 1;
    }
    if (g_cap_slot == 2 && e->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN) {
        Settings_SetPad(g_cap_bit, e->gbutton.button);
        end_capture();
        return 1;
    }
    if (g_cap_slot == 2 && e->type == SDL_EVENT_GAMEPAD_AXIS_MOTION && e->gaxis.value > 16384 &&
        (e->gaxis.axis == SDL_GAMEPAD_AXIS_LEFT_TRIGGER || e->gaxis.axis == SDL_GAMEPAD_AXIS_RIGHT_TRIGGER)) {
        Settings_SetPad(g_cap_bit, e->gaxis.axis == SDL_GAMEPAD_AXIS_LEFT_TRIGGER ? SET_PAD_LTRIGGER : SET_PAD_RTRIGGER);
        end_capture();
        return 1;
    }
    return 0;
}

void SettingsUi_Draw(void) {
    ImGuiIO &io = ImGui::GetIO();
    ImVec2 ds = io.DisplaySize;
    float k = ImGui::GetStyle().FontScaleMain * ImGui::GetStyle().FontScaleDpi;
    float w = 520.0f * k, h = 640.0f * k;
    bool open = true;

    w = w < ds.x * 0.95f ? w : ds.x * 0.95f;
    h = h < ds.y * 0.95f ? h : ds.y * 0.95f;
    ImGui::SetNextWindowPos(ImVec2(ds.x * 0.5f, ds.y * 0.5f), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_Appearing);
    ImGui::SetNextWindowBgAlpha(0.94f);
    if (ImGui::Begin("Settings (F1)", &open, ImGuiWindowFlags_NoCollapse)) {
        if (ImGui::BeginTabBar("tabs")) {
            if (ImGui::BeginTabItem("Display", NULL, tab_flags("Display"))) {
                display_tab();
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Controls", NULL, tab_flags("Controls"))) {
                controls_tab();
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Sound", NULL, tab_flags("Sound"))) {
                sound_tab();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
            g_start_tab[0] = 0;
        }
        ImGui::Separator();
        const char *path = Settings_FilePath();
        if (path != NULL) {
            ImGui::TextDisabled("Settings file: %s", path);
        } else {
            ImGui::TextDisabled("Not saved (no settings file in this run).");
        }
        if (ImGui::Button("Close (F1 / Esc)")) {
            open = false;
        }
    }
    ImGui::End();
    if (!open) {
        SettingsUi_SetOpen(0);
    }
}

} // extern "C"
