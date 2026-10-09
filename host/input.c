#include <stdio.h>
#include <string.h>

#include "host/host.h"
#include "host/host_sdl.h"
#if DW2_DEV
#include "host/devui.h"
#endif

/* Host input state: keyboard and SDL gamepads as PS1 digital pad button masks, per port. Read
 * after each event pump; changes are logged. P1.7 turns them into pad replies in Pad_RecvBufs.
 * PG.10 b3: the window side (events, device state: Host_InputDevice / Press / Poll) runs on the
 * main thread, the game's view (Host_InputLatch, Host_PadButtons, scripts) on the game thread;
 * held and tapped buttons pass between them under a lock, latched once per VBlank. */

#define PORTS 2
#define TRIGGER_ON 16384 /* trigger axis 0..32767: L2 / R2 held past half */

typedef struct {
    int key; /* SDL_Scancode or SDL_GamepadButton */
    unsigned short bit;
} ButtonMap;

/* Keyboard (port 0). Esc quits (host/sdl.c). */
static const ButtonMap key_map[] = {
    { SDL_SCANCODE_UP, PAD_UP },         { SDL_SCANCODE_DOWN, PAD_DOWN },
    { SDL_SCANCODE_LEFT, PAD_LEFT },     { SDL_SCANCODE_RIGHT, PAD_RIGHT },
    { SDL_SCANCODE_Z, PAD_CROSS },       { SDL_SCANCODE_X, PAD_CIRCLE },
    { SDL_SCANCODE_A, PAD_SQUARE },      { SDL_SCANCODE_S, PAD_TRIANGLE },
    { SDL_SCANCODE_Q, PAD_L1 },          { SDL_SCANCODE_W, PAD_R1 },
    { SDL_SCANCODE_E, PAD_L2 },          { SDL_SCANCODE_R, PAD_R2 },
    { SDL_SCANCODE_RETURN, PAD_START },  { SDL_SCANCODE_BACKSPACE, PAD_SELECT },
    { SDL_SCANCODE_RSHIFT, PAD_SELECT },
};

/* Gamepad, by position (south = Cross). Triggers are axes (L2 / R2 below). */
static const ButtonMap pad_map[] = {
    { SDL_GAMEPAD_BUTTON_SOUTH, PAD_CROSS },        { SDL_GAMEPAD_BUTTON_EAST, PAD_CIRCLE },
    { SDL_GAMEPAD_BUTTON_WEST, PAD_SQUARE },        { SDL_GAMEPAD_BUTTON_NORTH, PAD_TRIANGLE },
    { SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, PAD_L1 },   { SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, PAD_R1 },
    { SDL_GAMEPAD_BUTTON_BACK, PAD_SELECT },        { SDL_GAMEPAD_BUTTON_START, PAD_START },
    { SDL_GAMEPAD_BUTTON_LEFT_STICK, PAD_L3 },      { SDL_GAMEPAD_BUTTON_RIGHT_STICK, PAD_R3 },
    { SDL_GAMEPAD_BUTTON_DPAD_UP, PAD_UP },         { SDL_GAMEPAD_BUTTON_DPAD_DOWN, PAD_DOWN },
    { SDL_GAMEPAD_BUTTON_DPAD_LEFT, PAD_LEFT },     { SDL_GAMEPAD_BUTTON_DPAD_RIGHT, PAD_RIGHT },
};

static const char *const bit_names[16] = {
    "Select", "L3", "R3", "Start", "Up", "Right", "Down", "Left",
    "L2", "R2", "L1", "R1", "Triangle", "Circle", "Cross", "Square",
};

static SDL_Gamepad *pads[PORTS];
static SDL_AtomicInt pad_on[PORTS]; /* pads[p] != NULL, for the game thread */
static unsigned short buttons[PORTS]; /* the game's view, latched per VBlank */
static SDL_Mutex *lock;
static unsigned short held[PORTS];    /* keyboard + gamepads at the last poll (under lock) */
static unsigned short pressed[PORTS]; /* pressed since the last latch: a tap shorter than one
                                       * VBlank still shows for one latch (under lock) */

/* --press / --press2: scripted button holds on port 0 / 1 by VBlank wait. */
#define SCRIPT_MAX 4096
static struct {
    unsigned int at, len;
    unsigned short bits;
    int port;
} script[SCRIPT_MAX];
static int script_count;
static unsigned short script_bits[PORTS];
static int script_port1; /* a --press2 entry exists: port 1 is a scripted pad */
static int pad2_keys;    /* --pad2-keys: port 1 connected, Tab moves the keyboard between ports */
static int kbd_port;     /* port the keyboard drives */

unsigned short Host_PadButtons(int port) {
    return port >= 0 && port < PORTS ? buttons[port] : 0;
}

int Host_PadConnected(int port) {
    return port == 0 || (port == 1 && (SDL_GetAtomicInt(&pad_on[1]) || script_port1 || pad2_keys));
}

void Host_InputPad2Keys(void) {
    pad2_keys = 1;
}

int Host_InputScriptAdd(int port, unsigned int at, unsigned short bits, unsigned int len) {
    if (script_count == SCRIPT_MAX || port < 0 || port >= PORTS) {
        return 0;
    }
    if (port == 1) {
        script_port1 = 1;
    }
    script[script_count].port = port;
    script[script_count].at = at;
    script[script_count].len = len;
    script[script_count].bits = bits;
    script_count++;
    return 1;
}

void Host_InputScriptTick(unsigned int wait) {
    int i;

    script_bits[0] = script_bits[1] = 0;
    for (i = 0; i < script_count; i++) {
        if (wait >= script[i].at && wait < script[i].at + script[i].len) {
            script_bits[script[i].port] |= script[i].bits;
        }
    }
}

unsigned short Host_PadParseButtons(const char *names) {
    unsigned short m = 0;
    const char *s = names;

    while (*s != 0) {
        size_t n = strcspn(s, "+");
        int i;

        for (i = 0; i < 16; i++) {
            if (strlen(bit_names[i]) == n && SDL_strncasecmp(s, bit_names[i], n) == 0) {
                break;
            }
        }
        if (i == 16) {
            return 0;
        }
        m |= (unsigned short)(1 << i);
        s += n;
        if (*s == '+') {
            s++;
        }
    }
    return m;
}

void Host_InputDevice(const SDL_Event *e) {
    SDL_JoystickID id = e->gdevice.which;
    int p;

    if (e->type == SDL_EVENT_GAMEPAD_ADDED) {
        for (p = 0; p < PORTS; p++) {
            if (pads[p] != NULL && SDL_GetGamepadID(pads[p]) == id) {
                return;
            }
        }
        for (p = 0; p < PORTS && pads[p] != NULL; p++) {
        }
        if (p == PORTS) {
            printf("[input] gamepad %u ignored (both ports taken)\n", (unsigned)id);
            return;
        }
        pads[p] = SDL_OpenGamepad(id);
        if (pads[p] == NULL) {
            printf("[input] gamepad %u open failed: %s\n", (unsigned)id, SDL_GetError());
            return;
        }
        SDL_SetAtomicInt(&pad_on[p], 1);
        printf("[input] gamepad %u on port %d: %s\n", (unsigned)id, p, SDL_GetGamepadName(pads[p]));
    } else {
        for (p = 0; p < PORTS; p++) {
            if (pads[p] != NULL && SDL_GetGamepadID(pads[p]) == id) {
                SDL_CloseGamepad(pads[p]);
                pads[p] = NULL;
                SDL_SetAtomicInt(&pad_on[p], 0);
                printf("[input] gamepad %u removed from port %d\n", (unsigned)id, p);
            }
        }
    }
    fflush(stdout);
}

static unsigned short map_bit(const ButtonMap *map, size_t n, int key) {
    size_t i;

    for (i = 0; i < n; i++) {
        if (map[i].key == key) {
            return map[i].bit;
        }
    }
    return 0;
}

static void lock_init(void) {
    if (lock == NULL) {
        lock = SDL_CreateMutex();
    }
}

void Host_InputInit(void) {
    lock_init();
}

void Host_InputPress(const SDL_Event *e) {
    unsigned short bits[PORTS] = { 0, 0 };
    int p;

    if (e->type == SDL_EVENT_KEY_DOWN) {
        if (e->key.scancode == SDL_SCANCODE_TAB && pad2_keys && !e->key.repeat) {
            kbd_port ^= 1;
            printf("[input] keyboard on port %d\n", kbd_port);
            fflush(stdout);
            return;
        }
        bits[kbd_port] = map_bit(key_map, sizeof(key_map) / sizeof(key_map[0]), e->key.scancode);
    } else {
        for (p = 0; p < PORTS; p++) {
            if (pads[p] != NULL && SDL_GetGamepadID(pads[p]) == e->gbutton.which) {
                bits[p] = map_bit(pad_map, sizeof(pad_map) / sizeof(pad_map[0]), e->gbutton.button);
            }
        }
    }
    lock_init();
    SDL_LockMutex(lock);
    for (p = 0; p < PORTS; p++) {
        pressed[p] |= bits[p];
    }
    SDL_UnlockMutex(lock);
}

static void log_buttons(int port, unsigned short b) {
    int i;

    printf("[input] port %d: %04X", port, b);
    for (i = 0; i < 16; i++) {
        if (b & (1 << i)) {
            printf(" %s", bit_names[i]);
        }
    }
    printf("\n");
    fflush(stdout);
}

void Host_InputPoll(void) {
    const bool *keys = SDL_GetKeyboardState(NULL);
    unsigned short b[PORTS] = { 0, 0 };
    size_t i;
    int p;

    for (i = 0; i < sizeof(key_map) / sizeof(key_map[0]); i++) {
#if DW2_DEV
        if (DevUi_WantsKeyboard()) {
            break; /* PD.1: the keyboard types into an ImGui field, the game sees no keys */
        }
#endif
        if (keys[key_map[i].key]) {
            b[kbd_port] |= key_map[i].bit;
        }
    }
    for (p = 0; p < PORTS; p++) {
        if (pads[p] == NULL) {
            continue;
        }
        for (i = 0; i < sizeof(pad_map) / sizeof(pad_map[0]); i++) {
            if (SDL_GetGamepadButton(pads[p], (SDL_GamepadButton)pad_map[i].key)) {
                b[p] |= pad_map[i].bit;
            }
        }
        if (SDL_GetGamepadAxis(pads[p], SDL_GAMEPAD_AXIS_LEFT_TRIGGER) >= TRIGGER_ON) {
            b[p] |= PAD_L2;
        }
        if (SDL_GetGamepadAxis(pads[p], SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) >= TRIGGER_ON) {
            b[p] |= PAD_R2;
        }
    }
    lock_init();
    SDL_LockMutex(lock);
    for (p = 0; p < PORTS; p++) {
        held[p] = b[p];
    }
    SDL_UnlockMutex(lock);
}

void Host_InputLatch(void) {
    unsigned short b[PORTS];
    int p;

    lock_init();
    SDL_LockMutex(lock);
    for (p = 0; p < PORTS; p++) {
        b[p] = held[p] | pressed[p];
        pressed[p] = 0;
    }
    SDL_UnlockMutex(lock);
    for (p = 0; p < PORTS; p++) {
        b[p] |= script_bits[p];
        if (b[p] != buttons[p]) {
            buttons[p] = b[p];
            log_buttons(p, b[p]);
        }
    }
}

void Host_InputClose(void) {
    int p;

    for (p = 0; p < PORTS; p++) {
        if (pads[p] != NULL) {
            SDL_CloseGamepad(pads[p]);
            pads[p] = NULL;
        }
    }
}
