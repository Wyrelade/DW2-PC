#ifndef HOST_DEVEDIT_H
#define HOST_DEVEDIT_H

/* PD.4 dev state edit (DW2_DEV only): edits of Save_GameState and the scene switch, queued by the
 * dev overlay (main thread) or the --devedit script and applied by the game thread at its VBlank
 * wait (DevEdit_Apply in Host_GameEvents), never mid-frame. The main thread never writes game
 * memory. Design: PLAN.md PD Findings "PD.4 design / setters / warp". Release builds have none
 * of this. */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DEVEDIT_FLAG,      /* a id 0..999, b 0 / 1 (Flag_Set) */
    DEVEDIT_PROGRESS,  /* a value (eventFlags.progress) */
    DEVEDIT_BITS,      /* a value */
    DEVEDIT_RANK,      /* a value 0..255 */
    DEVEDIT_DIGI,      /* a roster slot, b DevEditDigiField, c value */
    DEVEDIT_SKILL,     /* a roster slot, b skill index 0..11, c skill id (0 none) */
    DEVEDIT_NAME,      /* a roster slot, text: nickname in game text (0xFF ends) */
    DEVEDIT_ADD_DIGI,  /* a species, b level, c max level, v[] hp mp attack defense speed, d skill (-1:
                          the species' own), into the first empty slot at the Digimon server (state 1),
                          text: name (empty: the species' default name) */
    DEVEDIT_BAG,       /* a bag slot, b item id (0: clear, the bag closes the hole) */
    DEVEDIT_BAG_ADD,   /* a item id (Item_AddToBag: the first free slot within the bag size) */
    DEVEDIT_STORAGE,   /* a item id 0..0xFF, b count */
    DEVEDIT_PART,      /* a part slot 0..18, b item id of that slot's category (0: remove) */
    DEVEDIT_BROKEN,    /* a part slot, b 0 / 1 (Beetle_SetPartBroken) */
    DEVEDIT_BEETLE,    /* a 0 HP, 1 max HP, 2 EP, 3 max EP; b value */
    DEVEDIT_WARP,      /* a game mode (0x301..0x32E city, 0x200 domain), b modeArg */
    DEVEDIT_FLOOR,     /* a floor of the current domain */
    DEVEDIT_DUMP,      /* log the edited state ([devstate] lines), changes nothing */
    DEVEDIT_KINDS
} DevEditKind;

typedef enum {
    DEVDIGI_SPECIES, DEVDIGI_LEVEL, DEVDIGI_MAXLEVEL, DEVDIGI_EXP, DEVDIGI_DP,
    DEVDIGI_HP, DEVDIGI_MAXHP, DEVDIGI_MP, DEVDIGI_MAXMP, DEVDIGI_ATTACK, DEVDIGI_DEFENSE, DEVDIGI_SPEED,
    DEVDIGI_FIELDS
} DevEditDigiField;

typedef struct {
    int32_t kind;
    int32_t a, b, c, d;
    int16_t v[5];
    uint8_t text[14];
} DevEdit;

/* Main thread, before the game thread runs. */
void DevEdit_Init(void);
/* Any thread but the game thread's apply: queue one edit. 0 when the queue is full or edits are
 * off (DevEdit_SetAllowed). */
int DevEdit_Push(const DevEdit *e);
/* --devedit VBLANK:SPEC (main.c): queue SPEC when the game reaches that VBlank. 0 = bad spec
 * (message printed). Specs: PLAN.md PD Findings "PD.4 script". */
int DevEdit_Script(const char *arg);
/* Game thread, Host_WaitVBlank (the Sys_Main spin): queue the script edits due at this wait. */
void DevEdit_ScriptTick(unsigned int wait);
/* Game thread, Host_WaitVBlank (the Sys_Main spin, between frames; not the libetc VSync waits
 * inside game code): apply what is queued. Nothing queued: returns at once, touches nothing. */
void DevEdit_Apply(void);
/* Online mode (P3.14) turns edits off: queued and new edits are refused. */
void DevEdit_SetAllowed(int on);
int DevEdit_Allowed(void);

/* Game thread (DevSnap_Capture): may a warp / floor edit run now? 0 with *why set when not. */
int DevEdit_CanWarp(const char **why);
int DevEdit_CanFloor(const char **why);

/* Main thread: the last applied / refused edits as logged, newest first. Returns the count. */
#define DEVEDIT_RESULT_LEN 192
int DevEdit_Results(char (*out)[DEVEDIT_RESULT_LEN], int max);

/* Short name of an edit kind / roster field (log, overlay). */
const char *DevEdit_KindName(int kind);
const char *DevEdit_DigiFieldName(int field);
/* Text (ASCII letters, digits, space and the punctuation the font has) to game text, 0xFF ends,
 * at most max - 1 glyphs. Returns the glyph count, -1 for a character the font lacks. */
int DevEdit_EncodeText(const char *s, uint8_t *out, int max);

#ifdef __cplusplus
}
#endif

#endif /* HOST_DEVEDIT_H */
