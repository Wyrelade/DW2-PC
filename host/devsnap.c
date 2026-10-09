#include "common.h"

#if DW2_DEV

#include <stddef.h>
#include <string.h>
#include <SDL3/SDL.h>

#include "host/devedit.h"
#include "host/devsnap.h"
#include "host/host.h"
#include "host/host_sdl.h"
#include "main/156C.h"

/* PD.1 dev overlay, game side: the snapshot of game state (host/devsnap.h). Runs on the game
 * thread at each VBlank wait while the overlay is open and only reads game memory: no game
 * function is called, no game variable is written, so the game runs exactly as with the overlay
 * closed. The shared copy is guarded by a lock the game thread only tries (SDL_TryLockMutex): when
 * the main thread is copying it out, this capture is skipped and the game goes on. */

extern SysState Sys_State;
extern GameState Save_GameState;
extern PadState Pad_State[];
extern TaskList Task_List;
extern TaskDesc **Task_DescTable[];
extern MemBlock *Mem_HeapHead;
extern s32 Mem_HeapSize;
extern s32 Rand_Index;
extern u16 Rand_Table[];
extern s32 Ovl_CurrentId;
extern DungState *Dung_StatePtr;
extern int DevEdit_FloorCount(void);

static SDL_Mutex *lock;
static SDL_AtomicInt open_flag;
static DevSnap shared;  /* under lock */
static int shared_valid; /* under lock */
static DevSnap work;    /* game thread only */
static uint64_t seq;
static uint64_t last_flips, last_flip_ns;
static float flip_ring[DEVSNAP_FLIPS];
static int flip_at;

void DevSnap_Init(void) {
    if (lock == NULL) {
        lock = SDL_CreateMutex();
    }
}

void DevSnap_SetOpen(int on) {
    SDL_SetAtomicInt(&open_flag, on);
}

int DevSnap_Open(void) {
    return SDL_GetAtomicInt(&open_flag);
}

/* A heap block header address inside the heap (the walk must not leave it on a broken list). */
static int in_heap(const void *p, uintptr_t lo, uintptr_t hi) {
    return (uintptr_t)p >= lo && (uintptr_t)p < hi;
}

static void capture_heap(DevSnap *s) {
    const MemBlock *b = Mem_HeapHead;
    uintptr_t lo = (uintptr_t)Mem_HeapHead;
    uintptr_t hi = lo + (uintptr_t)Mem_HeapSize;
    int n = 0;

    s->heapSize = Mem_HeapSize;
    if (b == NULL) {
        return;
    }
    /* Mem_InitHeap: blocks from Mem_HeapHead to the end marker (tag 1); a block's size is the
     * distance to the next header, header included. */
    while (b->tag != 1) {
        const MemBlock *nx = b->next;
        int32_t size;
        int t;

        if (!in_heap(nx, lo, hi + 1) || (uintptr_t)nx <= (uintptr_t)b || ++n > 0x40000) {
            s->heapBad = 1;
            break;
        }
        size = (int32_t)((uintptr_t)nx - (uintptr_t)b);
        s->heapBlocks++;
        if (b->tag == 0) {
            s->heapFree += size;
            s->heapFreeBlocks++;
            if (size > s->heapLargest) {
                s->heapLargest = size;
            }
        } else {
            s->heapUsed += size;
        }
        t = b->tag >= 0 && b->tag < DEVSNAP_TAGS ? b->tag : DEVSNAP_TAGS - 1;
        s->tagBytes[t] += size;
        s->tagBlocks[t]++;
        b = nx;
    }
}

static void capture_tasks(DevSnap *s) {
    uintptr_t lo = (uintptr_t)Mem_HeapHead;
    uintptr_t hi = lo + (uintptr_t)Mem_HeapSize;
    int i, j, k;

    s->taskListCount = Task_List.count;
    for (i = 0; i < 100 && s->taskCount < DEVSNAP_TASKS; i++) {
        const Actor *a = (const Actor *)(uintptr_t)(uint32_t)Task_List.entries[i];
        DevSnapTask *t;
        const TaskDesc *d = NULL;
        int row, idx;

        if (a == NULL) {
            continue;
        }
        t = &s->tasks[s->taskCount++];
        t->addr = (uint32_t)(uintptr_t)a;
        t->id = a->id;
        t->parent = -1;
        t->listIndex = i;
        t->state[0] = a->stateLevel0;
        t->state[1] = a->stateLevel1;
        t->state[2] = a->stateLevel2;
        t->state[3] = a->stateLevel3;
        t->state[4] = a->stateLevel4;
        t->elapsed = a->elapsed;
        t->childCount = a->childCount;
        row = (a->id >> 8) & 0xFF;
        idx = a->id & 0xFF;
        if (row < 8 && Task_DescTable[row] != NULL) {
            d = Task_DescTable[row][idx];
        }
        if (d != NULL) {
            t->desc = (uint64_t)(uintptr_t)d;
            t->workSize = d->workSize;
            t->auxSize = d->auxSize;
            t->update = (uint64_t)(uintptr_t)d->update;
            t->draw = (uint64_t)(uintptr_t)d->draw;
        }
        if (a->work != NULL && in_heap((const MemBlock *)a->work - 1, lo, hi)) {
            const MemBlock *h = (const MemBlock *)a->work - 1;

            if (in_heap(h->next, lo, hi + 1) && (uintptr_t)h->next > (uintptr_t)h) {
                t->workBytes = (int32_t)((uintptr_t)h->next - (uintptr_t)h);
            }
        }
    }
    /* parents: the task whose child slots (32-bit task slots) hold this one */
    for (i = 0; i < s->taskCount; i++) {
        const Actor *a = (const Actor *)(uintptr_t)s->tasks[i].addr;
        const s32 *slots = (const s32 *)a->u34.children;

        if (slots == NULL || a->childCount <= 0 || a->childCount > 0x400 ||
            !in_heap(slots, lo, hi)) {
            continue;
        }
        for (j = 0; j < a->childCount; j++) {
            if (slots[j] == 0) {
                continue;
            }
            for (k = 0; k < s->taskCount; k++) {
                if (s->tasks[k].addr == (uint32_t)slots[j] && k != i) {
                    s->tasks[k].parent = i;
                    break;
                }
            }
        }
    }
}

static void capture_save(DevSnap *s) {
    const GameState *g = &Save_GameState;
    int i;

    s->playTime = g->playTime;
    s->bits = g->bits;
    s->rank = g->rank;
    s->rankTitleSet = g->rankTitleSet;
    memcpy(s->playerName, g->playerName, sizeof(s->playerName));
    s->beetleHp = g->hp;
    s->beetleMaxHp = g->maxHp;
    s->beetleMp = g->mp;
    s->beetleMaxMp = g->maxMp;
    for (i = 0; i < DEVSNAP_PARTS; i++) {
        s->partItems[i] = g->slotItems[i];
        s->partBroken[i] = g->slotStatus[i];
    }
    for (i = 0; i < DEVSNAP_BAG; i++) {
        s->bag[i] = g->bagItems[i];
    }
    for (i = 0; i < DEVSNAP_STORAGE; i++) {
        s->storage[i] = g->storageCounts[i];
    }
    memcpy(s->beetleName, g->beetleName, sizeof(s->beetleName));
    for (i = 0; i < DEVSNAP_ROSTER; i++) {
        const DigiRosterEntry *e = &g->elems[i];
        DevSnapDigi *d = &s->roster[i];

        d->state = e->state;
        d->digiId = e->digiId;
        d->level = e->level;
        d->maxLevel = e->maxLevel;
        d->dp = e->dp;
        d->exp = e->exp;
        d->hp = e->hp;
        d->maxHp = e->maxHp;
        d->mp = e->mp;
        d->maxMp = e->maxMp;
        d->attack = e->attack;
        d->defense = e->defense;
        d->speed = e->speed;
        memcpy(d->name, e->name, sizeof(d->name));
        memcpy(d->skills, e->skills, sizeof(d->skills));
        memcpy(d->learnable, e->learnableSkills, sizeof(d->learnable));
        d->pendingSkill = e->pendingSkill;
        d->parent0 = e->parent0;
        d->parent1 = e->parent1;
        d->isTransferred = e->isTransferred;
    }
    s->progress = g->eventFlags.progress;
    memcpy(s->game, g, sizeof(s->game));
}

/* PD.4: what the Save tab's edit controls may offer now (plain reads, as above) */
static void capture_edit(DevSnap *s) {
    unsigned box = Save_GameState.slotItems[4];

    s->bagCapacity = box - 0x4B < 5 ? (int32_t)(box - 0x49) * 8 : 8; /* Item_GetBagCapacity */
    s->warpWhy = s->floorWhy = "";
    s->canWarp = DevEdit_CanWarp(&s->warpWhy);
    s->canFloor = DevEdit_CanFloor(&s->floorWhy);
    s->editsAllowed = DevEdit_Allowed();
    if ((Sys_State.gameMode >> 8) == 2 && Ovl_CurrentId == 1) {
        s->dungeonIdx = Dung_StatePtr->dungeonIdx;
        s->floor = Dung_StatePtr->floor;
        s->floorCount = DevEdit_FloorCount();
    }
}

void DevSnap_Capture(void) {
    DevSnap *s = &work;
    uint64_t t0;
    int p;

    if (!SDL_GetAtomicInt(&open_flag) || lock == NULL) {
        last_flips = 0;
        return;
    }
    t0 = SDL_GetTicksNS();
    memset(s, 0, sizeof(*s));
    s->ns = t0;
    Host_ClockStats(&s->vblanks, &s->flips, &s->restarts);
    if (last_flips != 0 && s->flips > last_flips) {
        float ms = (float)((t0 - last_flip_ns) / 1e6 / (double)(s->flips - last_flips));

        flip_ring[flip_at] = ms;
        flip_at = (flip_at + 1) % DEVSNAP_FLIPS;
    }
    if (last_flips == 0 || s->flips != last_flips) {
        last_flips = s->flips;
        last_flip_ns = t0;
    }
    for (p = 0; p < DEVSNAP_FLIPS; p++) {
        s->flipMs[p] = flip_ring[(flip_at + p) % DEVSNAP_FLIPS];
    }
    s->frameCount = Sys_State.frameCount;
    s->frameDelta = Sys_State.frameDelta;
    s->vsyncWait = Sys_State.vsyncWait;
    s->drawPass = Sys_State.drawPass;
    s->gameMode = Sys_State.gameMode;
    s->nextGameMode = Sys_State.nextGameMode;
    s->prevGameMode = Sys_State.prevGameMode;
    s->modeArg = Sys_State.modeArg;
    s->ovl = Ovl_CurrentId;
    s->randIndex = Rand_Index;
    s->randValue = Rand_Table[Rand_Index & 0xFFF];
    for (p = 0; p < 2; p++) {
        s->pad[p].held = Pad_State[p].held;
        s->pad[p].pressed = Pad_State[p].pressed;
        s->pad[p].repeat = Pad_State[p].repeat;
        s->pad[p].connected = Pad_State[p].connected;
        s->hostButtons[p] = Host_PadButtons(p);
    }
    capture_heap(s);
    capture_tasks(s);
    capture_save(s);
    capture_edit(s);
    s->seq = ++seq;
    s->captureNs = SDL_GetTicksNS() - t0;
    if (SDL_TryLockMutex(lock)) {
        memcpy(&shared, s, sizeof(shared));
        shared_valid = 1;
        SDL_UnlockMutex(lock);
    }
}

int DevSnap_Get(DevSnap *out) {
    int ok;

    if (lock == NULL) {
        return 0;
    }
    SDL_LockMutex(lock);
    ok = shared_valid;
    if (ok) {
        memcpy(out, &shared, sizeof(*out));
    }
    SDL_UnlockMutex(lock);
    return ok;
}

static int test_bit(const u8 *bits, int i) {
    return (bits[i >> 3] >> (i & 7)) & 1;
}

/* The same ranges as Flag_Test (main/flags.c), read from the snapshot's copy. */
int DevSnap_FlagTest(const DevSnap *s, int id, const char **what) {
    const GameState *g = (const GameState *)s->game;
    const char *dummy;
    int i;

    if (what == NULL) {
        what = &dummy;
    }
    if (id < 0) {
        *what = "negative id";
        return -1;
    }
    if (id < 0x258) {
        *what = "event bit (flags0, 0..599)";
        return test_bit(g->eventFlags.flags0, id);
    }
    if (id < 0x2BC) {
        *what = "event bit (flags600, 600..699)";
        return test_bit(g->eventFlags.flags600, id - 0x258);
    }
    if (id < 0x320) {
        *what = "event bit (flags700, 700..799)";
        return test_bit(g->eventFlags.flags700, id - 0x2BC);
    }
    if (id < 0x3E8) {
        *what = "event bit (flags800, 800..999)";
        return test_bit(g->eventFlags.flags800, id - 0x320);
    }
    if (id < 0x44C) {
        *what = "progress >= id - 1000 (1000..1099)";
        return g->eventFlags.progress >= id - 0x3E8;
    }
    if (id < 0x640) {
        *what = "progress < id - 1500 (1100..1599)";
        return g->eventFlags.progress < id - 0x5DC;
    }
    if (id < 0x8BD) {
        *what = "item id - 2000 in the bag (1600..2236)";
        for (i = 0; i < 0x30; i++) {
            if (g->bagItems[i] == id - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (id < 0xBB8) {
        /* retail reads storageCounts[id - 2000] past its 0x100 entries for ids from 2256 on */
        *what = "storageCounts[id - 2000] != 0 (2237..2999)";
        if (offsetof(GameState, storageCounts) + (size_t)(id - 0x7D0 + 1) * 2 > sizeof(*g)) {
            *what = "storageCounts[id - 2000]: past Save_GameState (not in the snapshot)";
            return -1;
        }
        return g->storageCounts[id - 0x7D0] != 0;
    }
    if (id < 0xFA0) {
        *what = "Digimon id - 3000 in the roster, state >= 2 (3000..3999)";
        for (i = 0; i < 0x24; i++) {
            if (g->elems[i].digiId == id - 0xBB8 && g->elems[i].state >= 2) {
                return 1;
            }
        }
        return 0;
    }
    *what = s->ovl == 2 ? "city special flag (Stg20_TestSpecialFlag, not read)" : "0 outside the city (4000 up)";
    return s->ovl == 2 ? -1 : 0;
}

#endif /* DW2_DEV */
