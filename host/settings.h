#ifndef HOST_SETTINGS_H
#define HOST_SETTINGS_H

/* PR.2 settings file (host/settings.c): settings.ini in the user data folder, or --settings PATH.
 * Plain `key = value` lines; unknown lines are kept, bad values fall back to the default. Read
 * once at start, written (temp file + rename) only when a setting changes. Headless runs use
 * the file only with --settings. Release and dev builds alike. */

#ifdef __cplusplus
extern "C" {
#endif

enum {
    SET_SCALE,      /* 1..8 */
    SET_WIDE,       /* 0 / 1 */
    SET_PGXP,       /* 0 / 1 */
    SET_RENDERER,   /* SET_RENDERER_GPU / SET_RENDERER_SOFT, used at the next start */
    SET_VOLUME,     /* 0..100 */
    SET_STICK_DPAD, /* 0 / 1 */
    SET_WINDOW_MODE, /* SET_WINDOW_* (PR.3) */
    SET_FS_DISPLAY, /* 0 = the display the window is on, N = the Nth display */
    SET_WIN_MAX,    /* 0 / 1: the window was maximized */
    SET_SHARPEN,    /* 0..100 (PR.2b, 0 = off) */
    SET_TITLE_HINT, /* 0 / 1: "Press F1 for settings" on the title (PR.10) */
    SET_SPEED,      /* PR.28 speed-up while unlocked (F3): 2..8 x, 0 = no limit */
    SET_COUNT
};
enum { SET_RENDERER_GPU, SET_RENDERER_SOFT };
enum { SET_WINDOW_WINDOWED, SET_WINDOW_BORDERLESS, SET_WINDOW_EXCLUSIVE };

#define SET_KEY_SLOTS 2   /* keyboard keys per pad button */
#define SET_PAD_NONE -1   /* gamepad binding: SDL_GamepadButton, a trigger code, or none */
#define SET_PAD_LTRIGGER 1000
#define SET_PAD_RTRIGGER 1001

/* Before Settings_Load (main thread, option parsing). */
void Settings_SetPath(const char *path);   /* --settings PATH */
void Settings_Override(int id, int value); /* a command line option: this run only, not saved */
int Settings_AddSet(const char *kv);       /* --settings-set KEY=VALUE: applied after the load */
/* main(), once: reads the file (no_window without --settings: no file), applies --settings-set. */
void Settings_Load(int no_window);

/* Any thread. */
int Settings_Get(int id);
/* Any thread: a changed setting (F1, F5 / F6 / F7): ends its override, the file is saved by the
 * main thread (Settings_SaveIfDirty). */
void Settings_Set(int id, int value);
int Settings_Overridden(int id);

/* PR.3 window values, main thread. fullscreen_mode: w = 0 is the desktop mode, hz100 = refresh
 * rate x 100 (0 = any). window_size / window_pos: 0 = not set (default size, centred). */
void Settings_FsMode(int *w, int *h, int *hz100);
void Settings_SetFsMode(int w, int h, int hz100);
int Settings_WindowSize(int *w, int *h);
void Settings_SetWindowSize(int w, int h);
int Settings_WindowPos(int *x, int *y);
void Settings_SetWindowPos(int x, int y);
const char *Settings_WindowModeName(int mode); /* "windowed", "borderless", "exclusive" */
int Settings_ParseWindowMode(const char *s);   /* -1 if not a mode name */

/* Bindings, main thread. `bit` is the PS1 pad bit number 0..15 (PAD_SELECT = bit 0 ...). */
int Settings_Key(int bit, int slot); /* SDL_Scancode, 0 = none */
void Settings_SetKey(int bit, int slot, int scancode);
int Settings_Pad(int bit);
void Settings_SetPad(int bit, int code);
void Settings_ResetControls(void);
int Settings_KeyReserved(int scancode); /* Esc, Tab, F1, F2, F5, F6, F7, F8, F11, F12 */
const char *Settings_ButtonName(int bit); /* "Cross", ... */
const char *Settings_PadName(int code);   /* "a", "lefttrigger", "none" */
/* The UI's button order (up, down, left, right, cross, ...): bit numbers, 16 entries. */
extern const int Settings_ButtonOrder[16];

/* Main thread: write the file if a setting changed (0.4 s after the last change). */
void Settings_SaveIfDirty(void);
/* Main thread, at shutdown: write a pending change now. */
void Settings_Flush(void);
const char *Settings_FilePath(void); /* NULL when no file is used (headless without --settings) */

#ifdef __cplusplus
}
#endif

#endif /* HOST_SETTINGS_H */
