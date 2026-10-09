#ifndef HOST_DEVSNAP_H
#define HOST_DEVSNAP_H

/* PD.1 dev overlay (DW2_DEV only): a copy of the game state the overlay shows. The game thread
 * fills it at its VBlank wait while the overlay is open (host/devsnap.c, plain reads of game
 * memory, no game call); the overlay (host/devui.cpp, main thread) draws from its own copy. Plain
 * fixed-width types only, so C and C++ share it without the game headers. */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEVSNAP_TASKS 100 /* Task_List entries */
#define DEVSNAP_TAGS 16   /* heap tags 0..14 one by one, 15 = 15 and up */
#define DEVSNAP_ROSTER 0x24
#define DEVSNAP_BAG 0x30
#define DEVSNAP_PARTS 0x13
#define DEVSNAP_STORAGE 0x100 /* storageCounts: count per item id */
#define DEVSNAP_GAME_SIZE 0x1058 /* sizeof(GameState) */
#define DEVSNAP_FLIPS 240       /* frame intervals kept for the timing plot */

typedef struct {
    uint32_t addr;        /* the task header (game address, below 2 GB) */
    int32_t id;           /* Task_DescTable row << 8 | index */
    int32_t parent;       /* index in DevSnap.tasks of the task holding it in a child slot, -1 none */
    int32_t listIndex;    /* Task_List.entries index */
    int32_t state[5];     /* stateLevel0..4 */
    int32_t elapsed;
    int32_t workSize;     /* TaskDesc.workSize / auxSize (PS1 bytes) */
    int32_t auxSize;
    int32_t workBytes;    /* heap block holding the work buffer, header included (0: none) */
    int32_t childCount;
    uint64_t desc;        /* TaskDesc address, update / draw callbacks (for the map file names) */
    uint64_t update;
    uint64_t draw;
} DevSnapTask;

typedef struct {
    uint8_t state, digiId, level, maxLevel, dp;
    int32_t exp;
    int16_t hp, maxHp, mp, maxMp, attack, defense, speed;
    uint8_t name[14];       /* nickname, game text (0xFF ends) */
    uint8_t skills[12];     /* skill ids, 0 none */
    uint8_t learnable[0x18]; /* learnableSkills (DNA parents' skills, learnable by rank) */
    uint8_t pendingSkill, parent0, parent1, isTransferred;
} DevSnapDigi;

typedef struct {
    int32_t held, pressed, repeat; /* PadState held / pressed / repeat (u16 masks) */
    int32_t connected;
} DevSnapPad;

typedef struct {
    /* capture */
    uint64_t seq;          /* captures so far */
    uint64_t ns;           /* SDL_GetTicksNS of this capture */
    uint64_t captureNs;    /* time this capture took on the game thread */
    /* host clock */
    uint64_t vblanks;      /* VBlanks run (Host_VBlankCount) */
    uint64_t flips;        /* buffer flips presented */
    uint32_t restarts;     /* VBlank clock restarts */
    float flipMs[DEVSNAP_FLIPS]; /* the last frame intervals (flip to flip), oldest first */
    /* Sys_State */
    int32_t frameCount, frameDelta, vsyncWait, drawPass;
    int32_t gameMode, nextGameMode, prevGameMode, modeArg;
    int32_t ovl;           /* Ovl_CurrentId (-1 none) */
    int32_t randIndex;     /* Rand_Index */
    int32_t randValue;     /* Rand_Table[Rand_Index] */
    /* input */
    DevSnapPad pad[2];         /* Pad_State[0..1] (the game's view) */
    uint16_t hostButtons[2];   /* Host_PadButtons (the host's latch, before the game reads it) */
    /* heap (Mem_HeapHead list) */
    int32_t heapSize, heapUsed, heapFree, heapLargest, heapBlocks, heapFreeBlocks;
    int32_t heapBad;           /* 1: the list walk stopped at a block outside the heap */
    int32_t tagBytes[DEVSNAP_TAGS], tagBlocks[DEVSNAP_TAGS];
    /* tasks */
    int32_t taskListCount;     /* Task_List.count */
    int32_t taskCount;
    DevSnapTask tasks[DEVSNAP_TASKS];
    /* Save_GameState */
    int32_t playTime, bits, rank, rankTitleSet;
    uint8_t playerName[0x10];
    int16_t beetleHp, beetleMaxHp, beetleMp, beetleMaxMp;
    uint16_t partItems[DEVSNAP_PARTS];
    uint8_t partBroken[DEVSNAP_PARTS];
    uint16_t bag[DEVSNAP_BAG];
    uint16_t storage[DEVSNAP_STORAGE];
    uint8_t beetleName[0x13];
    DevSnapDigi roster[DEVSNAP_ROSTER];
    int32_t progress;          /* eventFlags.progress */
    uint8_t game[DEVSNAP_GAME_SIZE]; /* the whole block, for DevSnap_FlagTest */
} DevSnap;

/* Main thread, before the game thread runs (Host_InitWindow): the lock. */
void DevSnap_Init(void);
/* Game thread, at each VBlank wait (Host_GameEvents): fills the shared snapshot while the overlay
 * is open. Never waits: when the main thread holds the snapshot, this capture is skipped. */
void DevSnap_Capture(void);
/* Main thread: the overlay is open (captures run) or not. */
void DevSnap_SetOpen(int on);
int DevSnap_Open(void);
/* Main thread: copy the newest snapshot into *out; 0 when there is none yet. */
int DevSnap_Get(DevSnap *out);
/* Flag_Test (main/flags.c) on the snapshot's Save_GameState: 1 / 0, or -1 for ids it cannot
 * answer (>= 4000: the city's special flags read live overlay state). *what: the id range. */
int DevSnap_FlagTest(const DevSnap *s, int id, const char **what);

#ifdef __cplusplus
}
#endif

#endif /* HOST_DEVSNAP_H */
