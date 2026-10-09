#ifndef HOST_UI_H
#define HOST_UI_H

/* PR.2 ImGui layer (host/ui.cpp, release and dev): one Dear ImGui context on the present renderer
 * for the F1 settings window (host/settingsui.cpp) and, in dev builds, the F2 overlay
 * (host/devui.cpp). Main thread only, except Ui_Shot. */

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --settings-ui: the F1 window open at start; with --no-window it renders into the hidden
 * window and each shot adds <tag>_ui.png. */
void Ui_SetSettingsAtStart(int on);
/* --ui-shots: with --no-window the window picture is rendered headless (F1 closed) and each shot
 * adds <tag>_ui.png (PR.10 hint and PR.2b checks). */
void Ui_SetShots(int on);
/* --quit-dialog: the PR.15 quit question open at start (headless shot with --ui-shots). */
void Ui_SetQuitAtStart(int on);
/* A UI renders headless (--settings-ui, --ui-shots or dev --devui with --no-window). */
int Ui_Headless(void);
void Ui_Init(SDL_Window *window, SDL_Renderer *renderer, int headless);
/* Each event before the host sees it: F1 / F2, key capture, ImGui. 1 = consumed. */
int Ui_Event(const SDL_Event *e);
/* The game sees no keyboard or gamepad: F1 open, or an ImGui text field types. */
int Ui_BlocksGameInput(void);
/* A UI window is open: the window loop presents while the game picture stays the same. */
int Ui_Active(void);
/* PR.3: a short notice top left for 2 s (window mode, F5 / F6 / F7). Any thread. */
void Ui_Notice(const char *text);
/* Something to draw: a window open or a notice showing (the window loop keeps presenting). */
int Ui_Drawing(void);
/* In Host_Present before SDL_RenderPresent. */
void Ui_Render(void);
/* Any thread (Host_SaveShot): with a headless UI, the next render writes the window picture. */
void Ui_Shot(const char *dir, const char *tag);
void Ui_Shutdown(void);

/* host/settingsui.cpp */
int SettingsUi_IsOpen(void);
void SettingsUi_SetOpen(int on);
void SettingsUi_SetTab(const char *name); /* --settings-tab: Display, Controls, Sound */
int SettingsUi_Capture(const SDL_Event *e); /* a remap waiting for a key / button: 1 consumed */
int SettingsUi_Capturing(void);
int SettingsUi_PadNavOk(void); /* gamepad navigation allowed (no capture, buttons up since) */
void SettingsUi_Draw(void);

#ifdef __cplusplus
}
#endif

#endif /* HOST_UI_H */
