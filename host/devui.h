#ifndef HOST_DEVUI_H
#define HOST_DEVUI_H

/* PD.1 dev overlay (DW2_DEV only): Dear ImGui over the game picture, toggled with F2. Runs on the
 * main thread (the window side) and draws from the game-state snapshot (host/devsnap.h); it never
 * calls into the game or writes game memory. Release builds (DW2_DEV=0) have none of this. */

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Options before the window exists: --devui (overlay open at start; headless it also renders into
 * the hidden window and the shots add <tag>_devui.png), --window-size W H. */
void DevUi_SetOpenAtStart(int on);
void DevUi_SetTab(const char *name); /* --devui-tab NAME: the tab shown first (headless checks) */
int DevUi_Headless(void); /* --devui with --no-window */
void DevUi_SetWindowSize(int w, int h);
void DevUi_WindowSize(int *w, int *h); /* unchanged when not set */

/* Main thread (Host_InitWindow): ImGui context and backends on the window's renderer. */
void DevUi_Init(SDL_Window *window, SDL_Renderer *renderer, int headless);
/* Main thread, each event before the host sees it: F2 toggles; with the overlay open the event
 * goes to ImGui too. 1 = consumed (F2, or a key while an ImGui text field has the keyboard). */
int DevUi_Event(const SDL_Event *e);
/* Main thread: an ImGui text field has the keyboard (the game's keyboard buttons read as up). */
int DevUi_WantsKeyboard(void);
int DevUi_IsOpen(void);
/* Main thread, in Host_Present before SDL_RenderPresent: the overlay on top of the picture. */
void DevUi_Render(void);
/* Any thread (Host_SaveShot): with --devui headless, the next render also writes
 * <dir>/<tag>_devui.png (the window picture with the overlay). */
void DevUi_Shot(const char *dir, const char *tag);
void DevUi_Shutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* HOST_DEVUI_H */
