#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "host/settings.h"

/* PR.2 settings file (design: PLAN.md PR Findings "PR.2 design"). settings.ini in the user data
 * folder (%APPDATA%\DW2-Online\, ~/.local/share/DW2-Online/), or --settings PATH. One
 * `key = value` per line, `#` comments. Every line of the file is kept in order: known keys are
 * rewritten with the current value on save, unknown keys and comments go back unchanged, keys
 * the file lacks are added at the end. A bad value logs and keeps the default. The file is
 * written only when a setting changes (temp file + rename), on the main thread.
 *
 * PR.3 adds the window keys (window_mode, fullscreen_display, fullscreen_mode, window_size,
 * window_pos, window_maximized; PLAN.md PR Findings "PR.3 design").
 *
 * Command line options (--scale, --wide, --pgxp, --renderer, --window-mode) override a value for this run
 * only: the file keeps its own value for those keys until the setting is changed in F1 or by
 * hotkey. Headless runs (--no-window) read and write a file only when --settings names it. */

#define MAX_FILE (64 * 1024)
#define MAX_LINES 1024
#define MAX_SETS 32

/* Pad bit numbers (PAD_SELECT is bit 0 ... PAD_SQUARE bit 15, host/host.h). */
enum {
    B_SELECT, B_L3, B_R3, B_START, B_UP, B_RIGHT, B_DOWN, B_LEFT,
    B_L2, B_R2, B_L1, B_R1, B_TRIANGLE, B_CIRCLE, B_CROSS, B_SQUARE
};

static const char *const button_keys[16] = {
    "select", "l3", "r3", "start", "up", "right", "down", "left",
    "l2", "r2", "l1", "r1", "triangle", "circle", "cross", "square",
};
static const char *const button_names[16] = {
    "Select", "L3", "R3", "Start", "Up", "Right", "Down", "Left",
    "L2", "R2", "L1", "R1", "Triangle", "Circle", "Cross", "Square",
};
const int Settings_ButtonOrder[16] = {
    B_UP, B_DOWN, B_LEFT, B_RIGHT, B_CROSS, B_CIRCLE, B_SQUARE, B_TRIANGLE,
    B_L1, B_R1, B_L2, B_R2, B_START, B_SELECT, B_L3, B_R3,
};

static const char *const int_keys[SET_COUNT] = {
    "scale", "wide", "pgxp", "renderer", "volume", "stick_dpad", "window_mode", "fullscreen_display", "window_maximized",
    "sharpen", "title_hint", "speed", "update_check",
};
static const int int_default[SET_COUNT] = { 1, 0, 0, SET_RENDERER_GPU, 100, 1, SET_WINDOW_WINDOWED, 0, 0, 0, 1, 3, 1 };
static const int int_min[SET_COUNT] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const int int_max[SET_COUNT] = { 8, 1, 1, 1, 100, 1, 2, 16, 1, 100, 1, 8, 1 };
static const char *const renderer_names[] = { "gpu", "soft", NULL };
static const char *const window_names[] = { "windowed", "borderless", "exclusive", NULL };
/* values written as names instead of numbers */
static const char *const *const int_names[SET_COUNT] = {
    [SET_RENDERER] = renderer_names, [SET_WINDOW_MODE] = window_names,
};

/* Known keys: 0..SET_COUNT-1 the values, then the PR.3 window keys with two or three numbers,
 * then key.<button> (16), then pad.<button> (16). */
#define K_FSMODE SET_COUNT
#define K_WINSIZE (SET_COUNT + 1)
#define K_WINPOS (SET_COUNT + 2)
#define K_KEY (SET_COUNT + 3)
#define K_PAD (K_KEY + 16)
#define K_COUNT (K_KEY + 32)
static const char *const window_keys[3] = { "fullscreen_mode", "window_size", "window_pos" };

/* Defaults = the tables host/input.c had before PR.2. */
static const int key_default[16][SET_KEY_SLOTS] = {
    [B_UP] = { SDL_SCANCODE_UP },         [B_DOWN] = { SDL_SCANCODE_DOWN },
    [B_LEFT] = { SDL_SCANCODE_LEFT },     [B_RIGHT] = { SDL_SCANCODE_RIGHT },
    [B_CROSS] = { SDL_SCANCODE_Z },       [B_CIRCLE] = { SDL_SCANCODE_X },
    [B_SQUARE] = { SDL_SCANCODE_A },      [B_TRIANGLE] = { SDL_SCANCODE_S },
    [B_L1] = { SDL_SCANCODE_Q },          [B_R1] = { SDL_SCANCODE_W },
    [B_L2] = { SDL_SCANCODE_E },          [B_R2] = { SDL_SCANCODE_R },
    [B_START] = { SDL_SCANCODE_RETURN },  [B_SELECT] = { SDL_SCANCODE_BACKSPACE, SDL_SCANCODE_RSHIFT },
};
static const int pad_default[16] = {
    [B_CROSS] = SDL_GAMEPAD_BUTTON_SOUTH,          [B_CIRCLE] = SDL_GAMEPAD_BUTTON_EAST,
    [B_SQUARE] = SDL_GAMEPAD_BUTTON_WEST,          [B_TRIANGLE] = SDL_GAMEPAD_BUTTON_NORTH,
    [B_L1] = SDL_GAMEPAD_BUTTON_LEFT_SHOULDER,     [B_R1] = SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER,
    [B_L2] = SET_PAD_LTRIGGER,                     [B_R2] = SET_PAD_RTRIGGER,
    [B_SELECT] = SDL_GAMEPAD_BUTTON_BACK,          [B_START] = SDL_GAMEPAD_BUTTON_START,
    [B_L3] = SDL_GAMEPAD_BUTTON_LEFT_STICK,        [B_R3] = SDL_GAMEPAD_BUTTON_RIGHT_STICK,
    [B_UP] = SDL_GAMEPAD_BUTTON_DPAD_UP,           [B_DOWN] = SDL_GAMEPAD_BUTTON_DPAD_DOWN,
    [B_LEFT] = SDL_GAMEPAD_BUTTON_DPAD_LEFT,       [B_RIGHT] = SDL_GAMEPAD_BUTTON_DPAD_RIGHT,
};

static SDL_AtomicInt value[SET_COUNT];     /* live value */
static SDL_AtomicInt file_value[SET_COUNT]; /* what a save writes */
static SDL_AtomicInt overridden[SET_COUNT];
static SDL_AtomicInt dirty;
static SDL_AtomicInt dirty_at; /* SDL_GetTicks of the last change (low 31 bits) */
static int keys[16][SET_KEY_SLOTS];
static int pads[16];
static int fs_w, fs_h, fs_hz;     /* fullscreen_mode, fs_w 0 = desktop, fs_hz = Hz x 100 */
static int win_w, win_h;          /* window_size, 0 = auto */
static int win_pos, win_x, win_y; /* window_pos, win_pos 0 = center */

static char *path_; /* NULL: no file */
static char *lines[MAX_LINES];
static int line_key[MAX_LINES]; /* known key index, or -1 */
static int line_count;
static const char *sets[MAX_SETS];
static int set_count;

static void mark_dirty(void) {
    SDL_SetAtomicInt(&dirty_at, (int)(SDL_GetTicks() & 0x7FFFFFFF));
    SDL_SetAtomicInt(&dirty, 1);
}

static void reset_controls(void) {
    memcpy(keys, key_default, sizeof(keys));
    memcpy(pads, pad_default, sizeof(pads));
}

void Settings_ResetControls(void) {
    reset_controls();
    mark_dirty();
}

void Settings_SetPath(const char *path) {
    SDL_free(path_);
    path_ = SDL_strdup(path);
}

void Settings_Override(int id, int v) {
    SDL_SetAtomicInt(&overridden[id], 1);
    SDL_SetAtomicInt(&value[id], v);
}

int Settings_Overridden(int id) {
    return SDL_GetAtomicInt(&overridden[id]);
}

int Settings_AddSet(const char *kv) {
    if (set_count == MAX_SETS || strchr(kv, '=') == NULL) {
        return 0;
    }
    sets[set_count++] = kv;
    return 1;
}

int Settings_Get(int id) {
    return SDL_GetAtomicInt(&value[id]);
}

void Settings_Set(int id, int v) {
    v = v < int_min[id] ? int_min[id] : v > int_max[id] ? int_max[id] : v;
    SDL_SetAtomicInt(&value[id], v);
    SDL_SetAtomicInt(&overridden[id], 0);
    if (SDL_GetAtomicInt(&file_value[id]) != v) {
        SDL_SetAtomicInt(&file_value[id], v);
        mark_dirty();
    }
}

void Settings_FsMode(int *w, int *h, int *hz100) {
    *w = fs_w;
    *h = fs_h;
    *hz100 = fs_hz;
}

void Settings_SetFsMode(int w, int h, int hz100) {
    if (w <= 0 || h <= 0) {
        w = h = hz100 = 0;
    }
    if (w != fs_w || h != fs_h || hz100 != fs_hz) {
        fs_w = w;
        fs_h = h;
        fs_hz = hz100;
        mark_dirty();
    }
}

int Settings_WindowSize(int *w, int *h) {
    *w = win_w;
    *h = win_h;
    return win_w != 0;
}

void Settings_SetWindowSize(int w, int h) {
    if (w != win_w || h != win_h) {
        win_w = w;
        win_h = h;
        mark_dirty();
    }
}

int Settings_WindowPos(int *x, int *y) {
    *x = win_x;
    *y = win_y;
    return win_pos;
}

void Settings_SetWindowPos(int x, int y) {
    if (!win_pos || x != win_x || y != win_y) {
        win_pos = 1;
        win_x = x;
        win_y = y;
        mark_dirty();
    }
}

const char *Settings_WindowModeName(int mode) {
    return mode >= 0 && mode <= SET_WINDOW_EXCLUSIVE ? window_names[mode] : "?";
}

static int find_name(const char *const *names, const char *s) {
    int i;

    for (i = 0; names[i] != NULL; i++) {
        if (SDL_strcasecmp(s, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int Settings_ParseWindowMode(const char *s) {
    return find_name(window_names, s);
}

int Settings_Key(int bit, int slot) {
    return keys[bit][slot];
}

void Settings_SetKey(int bit, int slot, int sc) {
    int b, s;

    if (sc != 0) {
        /* a key drives one button: taken from where it was */
        for (b = 0; b < 16; b++) {
            for (s = 0; s < SET_KEY_SLOTS; s++) {
                if (keys[b][s] == sc) {
                    keys[b][s] = 0;
                }
            }
        }
    }
    keys[bit][slot] = sc;
    mark_dirty();
}

int Settings_Pad(int bit) {
    return pads[bit];
}

void Settings_SetPad(int bit, int code) {
    int b;

    if (code != SET_PAD_NONE) {
        for (b = 0; b < 16; b++) {
            if (pads[b] == code) {
                pads[b] = SET_PAD_NONE;
            }
        }
    }
    pads[bit] = code;
    mark_dirty();
}

int Settings_KeyReserved(int sc) {
    return sc == SDL_SCANCODE_ESCAPE || sc == SDL_SCANCODE_TAB || sc == SDL_SCANCODE_F1 || sc == SDL_SCANCODE_F2 ||
           sc == SDL_SCANCODE_F3 || sc == SDL_SCANCODE_F5 || sc == SDL_SCANCODE_F6 || sc == SDL_SCANCODE_F7 || sc == SDL_SCANCODE_F8 ||
           sc == SDL_SCANCODE_F11 || sc == SDL_SCANCODE_F12;
}

const char *Settings_ButtonName(int bit) {
    return button_names[bit];
}

const char *Settings_PadName(int code) {
    const char *s;

    if (code == SET_PAD_LTRIGGER) {
        return "lefttrigger";
    }
    if (code == SET_PAD_RTRIGGER) {
        return "righttrigger";
    }
    s = code >= 0 ? SDL_GetGamepadStringForButton((SDL_GamepadButton)code) : NULL;
    return s != NULL ? s : "none";
}

const char *Settings_FilePath(void) {
    return path_;
}

static void format_value(int k, char *out, size_t len);

/* ---- parsing ---- */

static char *trim(char *s) {
    char *e;

    while (*s == ' ' || *s == '\t') {
        s++;
    }
    e = s + strlen(s);
    while (e > s && (e[-1] == ' ' || e[-1] == '\t' || e[-1] == '\r')) {
        *--e = 0;
    }
    return s;
}

static int find_key(const char *k) {
    int i;

    for (i = 0; i < SET_COUNT; i++) {
        if (SDL_strcasecmp(k, int_keys[i]) == 0) {
            return i;
        }
    }
    for (i = 0; i < 3; i++) {
        if (SDL_strcasecmp(k, window_keys[i]) == 0) {
            return K_FSMODE + i;
        }
    }
    for (i = 0; i < 16; i++) {
        if (SDL_strncasecmp(k, "key.", 4) == 0 && SDL_strcasecmp(k + 4, button_keys[i]) == 0) {
            return K_KEY + i;
        }
        if (SDL_strncasecmp(k, "pad.", 4) == 0 && SDL_strcasecmp(k + 4, button_keys[i]) == 0) {
            return K_PAD + i;
        }
    }
    return -1;
}

static int parse_scancode(const char *s) {
    SDL_Scancode sc;

    if (s[0] == '#') {
        char *end;
        long n = strtol(s + 1, &end, 10);

        return *end == 0 && n > 0 && n < SDL_SCANCODE_COUNT ? (int)n : -1;
    }
    sc = SDL_GetScancodeFromName(s);
    return sc != SDL_SCANCODE_UNKNOWN ? (int)sc : -1;
}

static int parse_pad(const char *s) {
    SDL_GamepadButton b;

    if (SDL_strcasecmp(s, "none") == 0) {
        return SET_PAD_NONE;
    }
    if (SDL_strcasecmp(s, "lefttrigger") == 0) {
        return SET_PAD_LTRIGGER;
    }
    if (SDL_strcasecmp(s, "righttrigger") == 0) {
        return SET_PAD_RTRIGGER;
    }
    b = SDL_GetGamepadButtonFromString(s);
    return b != SDL_GAMEPAD_BUTTON_INVALID ? (int)b : -2;
}

/* One `key = value` for known key k: 1 applied, 0 bad value (why set). `as_change` = set as a
 * change (--settings-set, saved) rather than as the file's value. */
static int apply_kv(int k, char *v, int as_change, char *why, size_t whylen) {
    if (k < SET_COUNT) {
        long n;
        char *end;

        if (int_names[k] != NULL) {
            n = find_name(int_names[k], v);
            end = v + strlen(v);
        } else {
            n = strtol(v, &end, 10);
        }
        if (*v == 0 || *end != 0 || n < int_min[k] || n > int_max[k]) {
            snprintf(why, whylen, "%s: \"%s\" is not %s", int_keys[k], v,
                     k == SET_RENDERER        ? "gpu or soft"
                     : k == SET_WINDOW_MODE ? "windowed, borderless or exclusive"
                                            : "a number in range");
            return 0;
        }
        if (as_change) {
            Settings_Set(k, (int)n);
        } else {
            SDL_SetAtomicInt(&file_value[k], (int)n);
            if (!SDL_GetAtomicInt(&overridden[k])) {
                SDL_SetAtomicInt(&value[k], (int)n);
            }
        }
        return 1;
    }
    if (k < K_KEY) {
        /* fullscreen_mode = desktop | WxH@HZ, window_size = auto | WxH, window_pos = center | X,Y */
        long a = 0, b = 0;
        double hz = 0;
        char *end = v;
        int ok;

        if (k == K_WINPOS) {
            ok = SDL_strcasecmp(v, "center") == 0;
            if (ok) {
                win_pos = 0;
            } else {
                a = strtol(v, &end, 10);
                ok = end != v && *end == ',';
                if (ok) {
                    char *p = end + 1;

                    b = strtol(p, &end, 10);
                    ok = end != p && *end == 0 && a > -100000 && a < 100000 && b > -100000 && b < 100000;
                }
                if (ok) {
                    win_pos = 1;
                    win_x = (int)a;
                    win_y = (int)b;
                }
            }
        } else {
            ok = SDL_strcasecmp(v, k == K_FSMODE ? "desktop" : "auto") == 0;
            if (!ok) {
                a = strtol(v, &end, 10);
                ok = end != v && (*end == 'x' || *end == 'X');
                if (ok) {
                    char *p = end + 1;

                    b = strtol(p, &end, 10);
                    ok = end != p && a >= 320 && b >= 240 && a <= 16384 && b <= 16384;
                }
                if (ok && k == K_FSMODE && *end == '@') {
                    char *p = end + 1;

                    hz = strtod(p, &end);
                    ok = end != p && hz >= 1 && hz <= 1000;
                }
                ok = ok && *end == 0;
            }
            if (ok && k == K_FSMODE) {
                fs_w = (int)a;
                fs_h = (int)b;
                fs_hz = (int)(hz * 100 + 0.5);
            } else if (ok) {
                win_w = (int)a;
                win_h = (int)b;
            }
        }
        if (!ok) {
            snprintf(why, whylen, "%s: \"%s\" is not %s", window_keys[k - K_FSMODE], v,
                     k == K_FSMODE    ? "desktop or WxH@HZ"
                     : k == K_WINSIZE ? "auto or WxH (at least 320x240)"
                                      : "center or X,Y");
            return 0;
        }
        if (as_change) {
            mark_dirty();
        }
        return 1;
    }
    if (k < K_PAD) {
        int sc[SET_KEY_SLOTS] = { 0 };
        int n = 0, s;
        char *tok = v;

        if (SDL_strcasecmp(v, "none") != 0) {
            while (tok != NULL) {
                char *comma = strchr(tok, ',');
                char *name;

                if (comma != NULL) {
                    *comma = 0;
                }
                name = trim(tok);
                if (n == SET_KEY_SLOTS) {
                    snprintf(why, whylen, "key.%s: more than %d keys", button_keys[k - K_KEY], SET_KEY_SLOTS);
                    return 0;
                }
                sc[n] = parse_scancode(name);
                if (sc[n] < 0) {
                    snprintf(why, whylen, "key.%s: unknown key \"%s\"", button_keys[k - K_KEY], name);
                    return 0;
                }
                if (Settings_KeyReserved(sc[n])) {
                    snprintf(why, whylen, "key.%s: %s is reserved", button_keys[k - K_KEY], name);
                    return 0;
                }
                n++;
                tok = comma != NULL ? comma + 1 : NULL;
            }
        }
        for (s = 0; s < SET_KEY_SLOTS; s++) {
            keys[k - K_KEY][s] = sc[s];
        }
        if (as_change) {
            mark_dirty();
        }
        return 1;
    }
    {
        int code = parse_pad(v);

        if (code == -2) {
            snprintf(why, whylen, "pad.%s: unknown gamepad button \"%s\"", button_keys[k - K_PAD], v);
            return 0;
        }
        pads[k - K_PAD] = code;
        if (as_change) {
            mark_dirty();
        }
        return 1;
    }
}

static void read_file(void) {
    size_t size = 0;
    char *data = SDL_LoadFile(path_, &size);
    char *p;
    int n = 0;

    if (data == NULL) {
        printf("[settings] no file %s: defaults\n", path_);
        return;
    }
    if (size > MAX_FILE || memchr(data, 0, size) != NULL) {
        printf("[settings] %s is not a settings file (%s): ignored, defaults; the next change replaces it\n",
               path_, size > MAX_FILE ? "over 64 KB" : "binary data");
        SDL_free(data);
        return;
    }
    p = data;
    while (*p != 0 && line_count < MAX_LINES) {
        char *nl = strchr(p, '\n');
        char *eq;
        char why[160];
        int k = -1;

        if (nl != NULL) {
            *nl = 0;
        }
        n++;
        if (nl != NULL && nl > p && nl[-1] == '\r') {
            nl[-1] = 0;
        }
        lines[line_count] = SDL_strdup(p);
        eq = strchr(p, '=');
        if (eq != NULL && *trim(p) != '#') {
            char *key, *val;
            int i;

            *eq = 0;
            key = trim(p);
            val = trim(eq + 1);
            k = find_key(key);
            for (i = 0; k >= 0 && i < line_count; i++) {
                if (line_key[i] == k) {
                    printf("[settings] line %d: %s given twice, the first one counts\n", n, key);
                    k = -2;
                }
            }
            if (k >= 0 && !apply_kv(k, val, 0, why, sizeof(why))) {
                printf("[settings] line %d: %s, ignored (default kept)\n", n, why);
            }
        }
        line_key[line_count++] = k >= 0 ? k : k == -2 ? -2 : -1;
        if (nl == NULL) {
            break;
        }
        p = nl + 1;
    }
    SDL_free(data);
    printf("[settings] %s read (%d lines)\n", path_, n);
}

void Settings_Load(int no_window) {
    char why[160];
    int i;

    for (i = 0; i < SET_COUNT; i++) {
        SDL_SetAtomicInt(&file_value[i], int_default[i]);
        if (!SDL_GetAtomicInt(&overridden[i])) {
            SDL_SetAtomicInt(&value[i], int_default[i]);
        }
    }
    reset_controls();
    fs_w = fs_h = fs_hz = win_w = win_h = win_pos = win_x = win_y = 0;
    if (path_ == NULL && !no_window) {
        char *pref = SDL_GetPrefPath("", "DW2-Online");

        if (pref != NULL) {
            SDL_asprintf(&path_, "%ssettings.ini", pref);
            SDL_free(pref);
        } else {
            printf("[settings] no user data folder (%s): defaults, not saved\n", SDL_GetError());
        }
    }
    if (path_ != NULL) {
        read_file();
    } else if (no_window) {
        printf("[settings] headless without --settings: defaults, no file\n");
    }
    for (i = 0; i < set_count; i++) {
        char buf[256];
        char *eq;
        int k;

        SDL_strlcpy(buf, sets[i], sizeof(buf));
        eq = strchr(buf, '=');
        *eq = 0;
        k = find_key(trim(buf));
        if (k < 0) {
            printf("[settings] --settings-set %s: unknown key\n", sets[i]);
        } else if (!apply_kv(k, trim(eq + 1), 1, why, sizeof(why))) {
            printf("[settings] --settings-set: %s\n", why);
        }
    }
    printf("[settings] scale %d, wide %d, pgxp %d, renderer %s, volume %d, stick_dpad %d%s\n", Settings_Get(SET_SCALE),
           Settings_Get(SET_WIDE), Settings_Get(SET_PGXP), Settings_Get(SET_RENDERER) == SET_RENDERER_SOFT ? "soft" : "gpu",
           Settings_Get(SET_VOLUME), Settings_Get(SET_STICK_DPAD), set_count != 0 ? " (with --settings-set)" : "");
    printf("[settings] sharpen %d, title_hint %d, speed %d, update_check %d\n", Settings_Get(SET_SHARPEN),
           Settings_Get(SET_TITLE_HINT), Settings_Get(SET_SPEED), Settings_Get(SET_UPDATE_CHECK));
    {
        char fm[32], ws[32], wp[32];

        format_value(K_FSMODE, fm, sizeof(fm));
        format_value(K_WINSIZE, ws, sizeof(ws));
        format_value(K_WINPOS, wp, sizeof(wp));
        printf("[settings] window_mode %s, fullscreen_display %d, fullscreen_mode %s, window_size %s, window_pos %s, "
               "window_maximized %d\n",
               Settings_WindowModeName(Settings_Get(SET_WINDOW_MODE)), Settings_Get(SET_FS_DISPLAY), fm, ws, wp,
               Settings_Get(SET_WIN_MAX));
    }
    fflush(stdout);
}

/* ---- writing ---- */

static void format_value(int k, char *out, size_t len) {
    if (k < SET_COUNT) {
        int v = SDL_GetAtomicInt(&file_value[k]);

        if (int_names[k] != NULL) {
            SDL_strlcpy(out, int_names[k][v], len);
        } else {
            snprintf(out, len, "%d", v);
        }
    } else if (k == K_FSMODE) {
        if (fs_w == 0) {
            SDL_strlcpy(out, "desktop", len);
        } else if (fs_hz == 0) {
            snprintf(out, len, "%dx%d", fs_w, fs_h);
        } else if (fs_hz % 100 == 0) {
            snprintf(out, len, "%dx%d@%d", fs_w, fs_h, fs_hz / 100);
        } else {
            snprintf(out, len, "%dx%d@%d.%02d", fs_w, fs_h, fs_hz / 100, fs_hz % 100);
        }
    } else if (k == K_WINSIZE) {
        if (win_w == 0) {
            SDL_strlcpy(out, "auto", len);
        } else {
            snprintf(out, len, "%dx%d", win_w, win_h);
        }
    } else if (k == K_WINPOS) {
        if (!win_pos) {
            SDL_strlcpy(out, "center", len);
        } else {
            snprintf(out, len, "%d,%d", win_x, win_y);
        }
    } else if (k < K_PAD) {
        int s, n = 0;

        out[0] = 0;
        for (s = 0; s < SET_KEY_SLOTS; s++) {
            int sc = keys[k - K_KEY][s];
            const char *name;
            char num[16];

            if (sc == 0) {
                continue;
            }
            name = SDL_GetScancodeName((SDL_Scancode)sc);
            if (name == NULL || name[0] == 0 || strchr(name, ',') != NULL || parse_scancode(name) != sc) {
                snprintf(num, sizeof(num), "#%d", sc);
                name = num;
            }
            if (n++ != 0) {
                SDL_strlcat(out, ", ", len);
            }
            SDL_strlcat(out, name, len);
        }
        if (n == 0) {
            SDL_strlcpy(out, "none", len);
        }
    } else {
        SDL_strlcpy(out, Settings_PadName(pads[k - K_PAD]), len);
    }
}

static void key_name(int k, char *out, size_t len) {
    if (k < SET_COUNT) {
        SDL_strlcpy(out, int_keys[k], len);
    } else if (k < K_KEY) {
        SDL_strlcpy(out, window_keys[k - K_FSMODE], len);
    } else {
        snprintf(out, len, "%s.%s", k < K_PAD ? "key" : "pad", button_keys[(k - K_KEY) % 16]);
    }
}

static int write_line(SDL_IOStream *io, const char *s) {
    size_t n = strlen(s);

    return SDL_WriteIO(io, s, n) == n && SDL_WriteIO(io, "\n", 1) == 1;
}

static int save(void) {
    static const int order[K_KEY] = {
        SET_SCALE, SET_WIDE, SET_PGXP, SET_SHARPEN, SET_RENDERER, SET_VOLUME, SET_STICK_DPAD, SET_TITLE_HINT,
        SET_SPEED, SET_UPDATE_CHECK, SET_WINDOW_MODE, SET_FS_DISPLAY, K_FSMODE, K_WINSIZE, K_WINPOS, SET_WIN_MAX,
    };
    char seen[K_COUNT] = { 0 };
    char *tmp = NULL;
    SDL_IOStream *io;
    int ok = 1, i;

    SDL_asprintf(&tmp, "%s.tmp", path_);
    io = SDL_IOFromFile(tmp, "wb");
    if (io == NULL) {
        printf("[settings] cannot write %s (%s)\n", tmp, SDL_GetError());
        SDL_free(tmp);
        return 0;
    }
    if (line_count == 0) {
        ok = write_line(io, "# DW2-PC settings (F1 in the game). Unknown lines are kept.");
    }
    for (i = 0; i < line_count && ok; i++) {
        int k = line_key[i];

        if (k == -2) {
            continue; /* a repeated key: the first one holds the value */
        }
        if (k >= 0) {
            char name[24], v[96], line[160];

            key_name(k, name, sizeof(name));
            format_value(k, v, sizeof(v));
            snprintf(line, sizeof(line), "%s = %s", name, v);
            seen[k] = 1;
            ok = write_line(io, line);
        } else {
            ok = write_line(io, lines[i]);
        }
    }
    for (i = 0; i < K_COUNT && ok; i++) {
        int k = i < K_KEY ? order[i] : i;

        if (k >= K_KEY && k < K_COUNT) {
            /* key.* and pad.* in the UI's button order */
            int bit = Settings_ButtonOrder[(k - K_KEY) % 16];

            k = (k < K_PAD ? K_KEY : K_PAD) + bit;
        }
        if (!seen[k]) {
            char name[24], v[96], line[160];

            key_name(k, name, sizeof(name));
            format_value(k, v, sizeof(v));
            snprintf(line, sizeof(line), "%s = %s", name, v);
            ok = write_line(io, line);
            seen[k] = 1;
            /* remember it as a line, so the next save keeps the order */
            if (line_count < MAX_LINES) {
                lines[line_count] = SDL_strdup(line);
                line_key[line_count++] = k;
            }
        }
    }
    ok = SDL_FlushIO(io) && ok;
    ok = SDL_CloseIO(io) && ok;
    if (ok && !SDL_RenamePath(tmp, path_)) {
        printf("[settings] cannot replace %s (%s)\n", path_, SDL_GetError());
        ok = 0;
    }
    if (!ok) {
        SDL_RemovePath(tmp);
    } else {
        printf("[settings] %s written\n", path_);
    }
    fflush(stdout);
    SDL_free(tmp);
    return ok;
}

/* A slider drag changes the value every frame: the file is written 0.4 s after the last change. */
void Settings_SaveIfDirty(void) {
    if (path_ == NULL || !SDL_GetAtomicInt(&dirty) ||
        (((int)(SDL_GetTicks() & 0x7FFFFFFF) - SDL_GetAtomicInt(&dirty_at)) & 0x7FFFFFFF) < 400) {
        return;
    }
    SDL_SetAtomicInt(&dirty, 0);
    save();
}

void Settings_Flush(void) {
    if (path_ != NULL && SDL_GetAtomicInt(&dirty)) {
        SDL_SetAtomicInt(&dirty, 0);
        save();
    }
}
