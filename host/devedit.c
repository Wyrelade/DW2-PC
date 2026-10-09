#include "common.h"

#if DW2_DEV

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL3/SDL.h>

#include "host/devdata.h"
#include "host/devedit.h"
#include "host/host.h"
#include "main/156C.h"

/* PD.4 dev state edit (host/devedit.h). Edits come from the overlay (main thread) and the
 * --devedit script into one queue; the game thread applies them in DevEdit_Apply, called from
 * Host_WaitVBlank: the Sys_Main spin on Sys_FlipPending, after the frame's update and draw passes
 * and before Sys_Main reads nextGameMode. Not in Host_GameEvents: libetc VSync waits inside game
 * code run that too, mid-frame. With nothing queued DevEdit_Apply reads one atomic and returns.
 *
 * Only setters that touch Save_GameState and nothing else are called (Flag_Set for ids below
 * 1000, Beetle_SetPart, Beetle_SetPartBroken, Item_AddToBag, Digi_GetExpToNextLevel); the rest
 * are direct writes. Why the others are not used: PLAN.md PD Findings "PD.4 setters". */

/* game C (main/game.h does not go together with the host headers) */
extern SysState Sys_State;
extern GameState Save_GameState;
extern DungState *Dung_StatePtr;
extern TaskList Task_List;
extern s32 Ovl_CurrentId;
extern s32 Flag_Test(s32 id);
extern void Flag_Set(s32 id, s32 val);
extern void Beetle_SetPart(s32 i, s32 v, s32 flag);
extern void Beetle_SetPartBroken(s32 i, s32 v);
extern s32 Item_AddToBag(s32 id);
extern s32 Item_GetBagCapacity(void);
extern s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur);
extern int DevEdit_FloorCount(void); /* host/devedit40.c */

#define QUEUE 64
#define SCRIPT_MAX 256
#define DOMAINS 33 /* area select domain records: modeArg 0..32 (file 0xD29) */

static SDL_Mutex *lock;
static DevEdit queue[QUEUE]; /* under lock */
static int q_head, q_count;  /* under lock */
static SDL_AtomicInt pending; /* q_count, read without the lock */
static SDL_AtomicInt allowed = { 1 };

typedef struct {
    unsigned int wait;
    DevEdit e;
} ScriptEdit;
static ScriptEdit script[SCRIPT_MAX]; /* filled before the game runs, then game thread only */
static int script_count, script_next;

static const char *const kind_names[DEVEDIT_KINDS] = {
    "flag", "progress", "bits", "rank", "digi", "skill", "name", "adddigi", "bag", "bagadd",
    "storage", "part", "broken", "beetle", "warp", "floor", "dump",
};
static const char *const field_names[DEVDIGI_FIELDS] = {
    "species", "level", "maxlevel", "exp", "dp", "hp", "maxhp", "mp", "maxmp", "attack", "defense", "speed",
};
static const char *const beetle_names[4] = { "hp", "maxhp", "ep", "maxep" };

const char *DevEdit_KindName(int kind) {
    return kind >= 0 && kind < DEVEDIT_KINDS ? kind_names[kind] : "?";
}

const char *DevEdit_DigiFieldName(int field) {
    return field >= 0 && field < DEVDIGI_FIELDS ? field_names[field] : "?";
}

void DevEdit_Init(void) {
    if (lock == NULL) {
        lock = SDL_CreateMutex();
    }
}

void DevEdit_SetAllowed(int on) {
    SDL_SetAtomicInt(&allowed, on != 0);
}

int DevEdit_Allowed(void) {
    return SDL_GetAtomicInt(&allowed);
}

int DevEdit_Push(const DevEdit *e) {
    int ok = 0;

    if (lock == NULL || !SDL_GetAtomicInt(&allowed)) {
        return 0;
    }
    SDL_LockMutex(lock);
    if (q_count < QUEUE) {
        queue[(q_head + q_count) % QUEUE] = *e;
        q_count++;
        SDL_SetAtomicInt(&pending, q_count);
        ok = 1;
    }
    SDL_UnlockMutex(lock);
    return ok;
}

/* ---- text ---- */

int DevEdit_EncodeText(const char *s, uint8_t *out, int max) {
    static const char punct[] = "&?!/-,.'\";:%+=#";
    static const uint8_t punct_glyph[] = { 0x42, 0x44, 0x45, 0x46, 0x49, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
                                           0x5A, 0x5B, 0x5C, 0x5D };
    int n = 0;

    for (; *s != 0 && n < max - 1; s++) {
        char c = *s;
        const char *p;

        if (c >= '0' && c <= '9') {
            out[n++] = (uint8_t)(c - '0');
        } else if (c >= 'A' && c <= 'Z') {
            out[n++] = (uint8_t)(0x0A + c - 'A');
        } else if (c >= 'a' && c <= 'z') {
            out[n++] = (uint8_t)(0x24 + c - 'a');
        } else if (c == ' ' || c == '_') {
            out[n++] = 0xFD; /* the name entry's blank */
        } else if (c != 0 && (p = strchr(punct, c)) != NULL) {
            out[n++] = punct_glyph[p - punct];
        } else {
            return -1;
        }
    }
    if (*s != 0) {
        return -1; /* too long */
    }
    out[n] = 0xFF;
    return n;
}

/* game text bytes as hex for the log ("0A 2E FF") */
static const char *hex_text(const uint8_t *p, int n, char *out, int size) {
    int i, len = 0;

    out[0] = 0;
    for (i = 0; i < n && len + 4 < size; i++) {
        len += snprintf(out + len, (size_t)(size - len), "%s%02X", i ? " " : "", p[i]);
        if (p[i] == 0xFF) {
            break;
        }
    }
    return out;
}

/* ---- checks ---- */

static Actor *find_task(int id) {
    int i;

    for (i = 0; i < 100; i++) {
        Actor *a = (Actor *)(uintptr_t)(uint32_t)Task_List.entries[i];

        if (a != NULL && a->id == id) {
            return a;
        }
    }
    return NULL;
}

static int need_tables(const char **why) {
    if (!DevData_Ready() && !DevData_Load()) {
        *why = "game tables not loaded (dw2.pak)";
        return 0;
    }
    return 1;
}

static int in_battle(void) {
    int hi = Sys_State.gameMode >> 8;

    return hi == 5 || hi == 7;
}

/* City (walkable area or area select, top menu closed) or domain (walking): a scene change now
 * is what a retail exit does at the end of its fade. */
int DevEdit_CanWarp(const char **why) {
    int hi = Sys_State.gameMode >> 8;
    Actor *root;

    if (Sys_State.nextGameMode != 0) {
        *why = "a scene switch is pending";
        return 0;
    }
    if (Sys_State.fadeLevel != 0) {
        *why = "a fade is running";
        return 0;
    }
    if (hi == 3) {
        if (Sys_State.gameMode >= 0x32F) {
            *why = "city screen (shop / lab): leave it first";
            return 0;
        }
        root = find_task(0x300);
        if (root == NULL || root->stateLevel0 != 1 || root->stateLevel1 != 0) {
            *why = "city: menu open or scene starting";
            return 0;
        }
        return 1;
    }
    if (hi == 2) {
        return DevEdit_CanFloor(why);
    }
    *why = hi == 5 || hi == 7 ? "in battle"
           : hi == 4          ? "title / movie"
           : hi == 6          ? "memory card screen"
                              : "not in the city or a domain";
    return 0;
}

int DevEdit_CanFloor(const char **why) {
    Actor *root;

    if ((Sys_State.gameMode >> 8) != 2 || Ovl_CurrentId != 1) {
        *why = "not in a domain";
        return 0;
    }
    if (Sys_State.nextGameMode != 0 || Sys_State.fadeLevel != 0) {
        *why = "a scene switch or fade is running";
        return 0;
    }
    root = find_task(0x200);
    if (root == NULL || root->stateLevel0 != 1 || root->stateLevel1 != 1 || Dung_StatePtr->freeze != 0) {
        *why = "domain: not walking (menu, event, battle start or stairs)";
        return 0;
    }
    return 1;
}

/* ---- apply ---- */

static unsigned long long vb;

/* the last results for the overlay (DevEdit_Results), under lock */
#define RESULTS 8
static char results[RESULTS][DEVEDIT_RESULT_LEN];
static int result_count;

/* one log line: printed and kept for the overlay */
static void note(const char *fmt, ...) {
    char line[DEVEDIT_RESULT_LEN];
    va_list ap;
    size_t n;

    va_start(ap, fmt);
    vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    fputs(line, stdout);
    n = strlen(line);
    if (n > 0 && line[n - 1] == '\n') {
        line[n - 1] = 0;
    }
    SDL_LockMutex(lock);
    memmove(results[1], results[0], sizeof(results[0]) * (RESULTS - 1));
    memcpy(results[0], line, sizeof(line));
    result_count++;
    SDL_UnlockMutex(lock);
}

#define LOG(...) note("[devedit] vb %llu " __VA_ARGS__)

static void refuse(const DevEdit *e, const char *why) {
    note("[devedit] vb %llu refused %s %d %d %d: %s\n", vb, DevEdit_KindName(e->kind), e->a, e->b, e->c, why);
}

int DevEdit_Results(char (*out)[DEVEDIT_RESULT_LEN], int max) {
    int n;

    if (lock == NULL) {
        return 0;
    }
    SDL_LockMutex(lock);
    n = result_count < RESULTS ? result_count : RESULTS;
    n = n < max ? n : max;
    memcpy(out, results, sizeof(results[0]) * (size_t)n);
    SDL_UnlockMutex(lock);
    return n;
}

static int clamp_ok(int v, int lo, int hi) {
    return v >= lo && v <= hi;
}

static int16_t *digi_s16(DigiRosterEntry *d, int field) {
    switch (field) {
    case DEVDIGI_HP: return &d->hp;
    case DEVDIGI_MAXHP: return &d->maxHp;
    case DEVDIGI_MP: return &d->mp;
    case DEVDIGI_MAXMP: return &d->maxMp;
    case DEVDIGI_ATTACK: return &d->attack;
    case DEVDIGI_DEFENSE: return &d->defense;
    case DEVDIGI_SPEED: return &d->speed;
    }
    return NULL;
}

static int digi_slot(const DevEdit *e, const char **why) {
    if (e->a < 0 || e->a >= 0x24 || Save_GameState.elems[e->a].state == 0) {
        *why = "no Digimon in that roster slot";
        return 0;
    }
    if (e->a < 3 && in_battle()) {
        *why = "party slot in battle (Stg30_BattleDestroy copies the party back)";
        return 0;
    }
    return 1;
}

static int species_ok(int id, const char **why) {
    const DevDigi *d;

    if (!need_tables(why)) {
        return 0;
    }
    d = DevData_Digi(id);
    if (id <= 0 || id > 0xFF || d == NULL || !d->hasBase) {
        *why = "species: not a DIGIMNDT Digimon id 1..255";
        return 0;
    }
    return 1;
}

static int item_ok(int id, const char **why) {
    if (!need_tables(why)) {
        return 0;
    }
    if (id <= 0 || DevData_Item(id) == NULL) {
        *why = "not an ITEMDATA item id";
        return 0;
    }
    return 1;
}

static void compact_bag(void) {
    int i, n = 0;

    for (i = 0; i < 0x30; i++) {
        u16 v = Save_GameState.bagItems[i];

        Save_GameState.bagItems[i] = 0;
        if (v != 0) {
            Save_GameState.bagItems[n++] = v;
        }
    }
}

static void apply_digi(const DevEdit *e) {
    DigiRosterEntry *d;
    const char *why = "";
    int old;

    if (!digi_slot(e, &why)) {
        refuse(e, why);
        return;
    }
    d = &Save_GameState.elems[e->a];
    switch (e->b) {
    case DEVDIGI_SPECIES:
        if (!species_ok(e->c, &why)) {
            refuse(e, why);
            return;
        }
        old = d->digiId;
        d->digiId = (u8)e->c;
        LOG("digi %d species: 0x%02X %s -> 0x%02X %s\n", vb, e->a, old, DevData_DigiName(old), e->c,
            DevData_DigiName(e->c));
        return;
    case DEVDIGI_LEVEL:
        if (!clamp_ok(e->c, 1, 99)) {
            refuse(e, "level 1..99");
            return;
        }
        old = d->level;
        d->level = (u8)e->c;
        /* the exp of a fresh Digimon at that level (Digi_InitFromTable) */
        {
            s32 old_exp = d->exp;

            d->exp = e->c == 1 ? 0 : Digi_GetExpToNextLevel(e->c - 1, 100, 0);
            LOG("digi %d level: %d -> %d (exp %d -> %d)\n", vb, e->a, old, e->c, old_exp, d->exp);
        }
        if (d->maxLevel < d->level) {
            LOG("digi %d note: max level %d is below the level\n", vb, e->a, d->maxLevel);
        }
        return;
    case DEVDIGI_MAXLEVEL:
        if (!clamp_ok(e->c, 1, 99)) {
            refuse(e, "max level 1..99");
            return;
        }
        old = d->maxLevel;
        d->maxLevel = (u8)e->c;
        break;
    case DEVDIGI_EXP:
        if (!clamp_ok(e->c, 0, 99999999)) {
            refuse(e, "exp 0..99999999");
            return;
        }
        old = d->exp;
        d->exp = e->c;
        break;
    case DEVDIGI_DP:
        if (!clamp_ok(e->c, 0, 255)) {
            refuse(e, "DP 0..255");
            return;
        }
        old = d->dp;
        d->dp = (u8)e->c;
        break;
    default: {
        int16_t *p = digi_s16(d, e->b);

        if (p == NULL) {
            refuse(e, "unknown field");
            return;
        }
        if (!clamp_ok(e->c, 0, 9999)) {
            refuse(e, "stat 0..9999");
            return;
        }
        old = *p;
        *p = (int16_t)e->c;
        break;
    }
    }
    LOG("digi %d %s: %d -> %d\n", vb, e->a, DevEdit_DigiFieldName(e->b), old, e->c);
}

static void apply_add_digi(const DevEdit *e) {
    const char *why = "";
    DigiRosterEntry *d = NULL;
    const DevDigi *s;
    char hex[64];
    int i, skill;

    if (!species_ok(e->a, &why)) {
        refuse(e, why);
        return;
    }
    if (!clamp_ok(e->b, 1, 99) || !clamp_ok(e->c, 1, 99)) {
        refuse(e, "level and max level 1..99");
        return;
    }
    for (i = 0; i < 5; i++) {
        if (!clamp_ok(e->v[i], 0, 9999)) {
            refuse(e, "stat 0..9999");
            return;
        }
    }
    s = DevData_Digi(e->a);
    skill = e->d < 0 ? s->learnedSkill : e->d; /* -1: the species' own skill (DIGIMNDT) */
    if (skill != 0 && DevData_Skill(skill) == NULL) {
        refuse(e, "not a WAZADATA skill id");
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state == 0) {
            d = &Save_GameState.elems[i];
            break;
        }
    }
    if (d == NULL) {
        refuse(e, "roster full (36)");
        return;
    }
    memset(d, 0, sizeof(*d));
    d->digiId = (u8)e->a;
    d->level = (u8)e->b;
    d->maxLevel = (u8)e->c;
    d->exp = e->b == 1 ? 0 : Digi_GetExpToNextLevel(e->b - 1, 100, 0);
    d->hp = d->maxHp = e->v[0];
    d->mp = d->maxMp = e->v[1];
    d->attack = e->v[2];
    d->defense = e->v[3];
    d->speed = e->v[4];
    d->skills[0] = (u8)skill;
    if (e->text[0] != 0xFF && e->text[0] != 0) {
        memcpy(d->name, e->text, sizeof(d->name));
    } else {
        memcpy(d->name, s->rawName, sizeof(d->name));
    }
    d->name[sizeof(d->name) - 1] = 0xFF;
    /* last: the slot is in use from here on. State 1 = at the Digimon server (no beetle capacity
     * limit, Beetle_GetDigiCapacity); 2 = carried, 3..5 = party place. */
    d->state = 1;
    LOG("adddigi slot %d: empty -> 0x%02X %s level %d / %d HP %d MP %d A %d D %d S %d skill 0x%02X name %s\n", vb,
        i, e->a, DevData_DigiName(e->a), e->b, e->c, e->v[0], e->v[1], e->v[2], e->v[3], e->v[4], skill,
        hex_text(d->name, (int)sizeof(d->name), hex, (int)sizeof(hex)));
}

static void apply_part(const DevEdit *e) {
    const char *why = "";
    int cat, old = 0, old_st = 0;

    if (!clamp_ok(e->a, 0, 18)) {
        refuse(e, "part slot 0..18");
        return;
    }
    old = Save_GameState.slotItems[e->a];
    old_st = Save_GameState.slotStatus[e->a];
    if (e->b == 0) {
        /* remove as the beetle shop does (beetleparts.c): no item, status 0 */
        Save_GameState.slotItems[e->a] = 0;
        Save_GameState.slotStatus[e->a] = 0;
    } else {
        if (!item_ok(e->b, &why)) {
            refuse(e, why);
            return;
        }
        cat = DevData_Item(e->b)->category;
        if (cat != (e->a == 0 ? 19 : e->a - 1)) {
            refuse(e, "item category does not fit the slot");
            return;
        }
        Beetle_SetPart(e->a, e->b, 0);
    }
    LOG("part %d %s: 0x%03X %s (status %d) -> 0x%03X %s (status %d)\n", vb, e->a, DevData_SlotName(e->a), old,
        old ? DevData_ItemName(old) : "-", old_st, e->b, e->b ? DevData_ItemName(e->b) : "-",
        Save_GameState.slotStatus[e->a]);
    if (e->a == 4) {
        LOG("bag size now %d\n", vb, Item_GetBagCapacity());
    }
}

static void dump(void) {
    const GameState *g = &Save_GameState;
    char hex[64];
    int i, n;

    printf("[devstate] vb %llu mode 0x%X arg %d bits %d rank %d progress %d beetle HP %d / %d EP %d / %d\n", vb,
           Sys_State.gameMode, Sys_State.modeArg, g->bits, g->rank, g->eventFlags.progress, g->hp, g->maxHp, g->mp,
           g->maxMp);
    if ((Sys_State.gameMode >> 8) == 2 && Dung_StatePtr != NULL) {
        printf("[devstate] domain %d floor %d of %d\n", Dung_StatePtr->dungeonIdx, Dung_StatePtr->floor,
               DevEdit_FloorCount());
    }
    printf("[devstate] flags set:");
    for (i = 0, n = 0; i < 1000; i++) {
        if (Flag_Test(i)) {
            printf(" %d", i);
            n++;
        }
    }
    printf(" (%d)\n[devstate] parts:", n);
    for (i = 0; i < 0x13; i++) {
        if (g->slotItems[i] != 0 || g->slotStatus[i] != 0) {
            printf(" %d=0x%03X/%d", i, g->slotItems[i], g->slotStatus[i]);
        }
    }
    printf("\n[devstate] bag:");
    for (i = 0; i < 0x30; i++) {
        if (g->bagItems[i] != 0) {
            printf(" %d=0x%03X", i, g->bagItems[i]);
        }
    }
    printf("\n[devstate] storage:");
    for (i = 0; i < 0x100; i++) {
        if (g->storageCounts[i] != 0) {
            printf(" 0x%02X=%d", i, g->storageCounts[i]);
        }
    }
    printf("\n");
    for (i = 0; i < 0x24; i++) {
        const DigiRosterEntry *d = &g->elems[i];
        int k;

        if (d->state == 0) {
            continue;
        }
        printf("[devstate] digi %d state %d 0x%02X lv %d/%d exp %d dp %d HP %d/%d MP %d/%d A %d D %d S %d skills",
               i, d->state, d->digiId, d->level, d->maxLevel, d->exp, d->dp, d->hp, d->maxHp, d->mp, d->maxMp,
               d->attack, d->defense, d->speed);
        for (k = 0; k < 12; k++) {
            printf(" %02X", d->skills[k]);
        }
        printf(" name %s\n", hex_text(d->name, (int)sizeof(d->name), hex, (int)sizeof(hex)));
    }
}

static void apply(const DevEdit *e) {
    const char *why = "";
    char h0[64], h1[64];
    int old;

    switch (e->kind) {
    case DEVEDIT_FLAG:
        if (!clamp_ok(e->a, 0, 999) || !clamp_ok(e->b, 0, 1)) {
            refuse(e, "flag ids 0..999, value 0 / 1 (other ranges: progress, bag, storage, roster)");
            return;
        }
        old = Flag_Test(e->a);
        Flag_Set(e->a, e->b);
        LOG("flag %d: %d -> %d%s\n", vb, e->a, old, e->b,
            e->a == 0x10 && e->b == 0 ? " (Flag_Set also clears 17)" : "");
        return;
    case DEVEDIT_PROGRESS:
        if (!clamp_ok(e->a, 0, 999)) {
            refuse(e, "progress 0..999");
            return;
        }
        old = Save_GameState.eventFlags.progress;
        Save_GameState.eventFlags.progress = e->a;
        LOG("progress: %d -> %d\n", vb, old, e->a);
        return;
    case DEVEDIT_BITS:
        if (!clamp_ok(e->a, 0, 99999999)) {
            refuse(e, "bits 0..99999999");
            return;
        }
        old = Save_GameState.bits;
        Save_GameState.bits = e->a;
        LOG("bits: %d -> %d\n", vb, old, e->a);
        return;
    case DEVEDIT_RANK:
        if (!clamp_ok(e->a, 0, 255)) {
            refuse(e, "rank 0..255");
            return;
        }
        old = Save_GameState.rank;
        Save_GameState.rank = (u8)e->a;
        LOG("rank: %d -> %d\n", vb, old, e->a);
        return;
    case DEVEDIT_DIGI:
        apply_digi(e);
        return;
    case DEVEDIT_SKILL:
        if (!digi_slot(e, &why)) {
            refuse(e, why);
            return;
        }
        if (!clamp_ok(e->b, 0, 11) || !clamp_ok(e->c, 0, 255)) {
            refuse(e, "skill index 0..11, id 0..255");
            return;
        }
        if (e->c != 0 && (!need_tables(&why) || DevData_Skill(e->c) == NULL)) {
            refuse(e, *why ? why : "not a WAZADATA skill id");
            return;
        }
        old = Save_GameState.elems[e->a].skills[e->b];
        Save_GameState.elems[e->a].skills[e->b] = (u8)e->c;
        LOG("digi %d skill %d: 0x%02X %s -> 0x%02X %s\n", vb, e->a, e->b, old, old ? DevData_SkillName(old) : "-",
            e->c, e->c ? DevData_SkillName(e->c) : "-");
        return;
    case DEVEDIT_NAME: {
        DigiRosterEntry *d;

        if (!digi_slot(e, &why)) {
            refuse(e, why);
            return;
        }
        d = &Save_GameState.elems[e->a];
        if (memchr(e->text, 0xFF, sizeof(e->text)) == NULL || e->text[0] == 0xFF) {
            refuse(e, "name: 1..13 glyphs");
            return;
        }
        hex_text(d->name, (int)sizeof(d->name), h0, (int)sizeof(h0));
        memcpy(d->name, e->text, sizeof(d->name));
        LOG("digi %d name: %s -> %s\n", vb, e->a, h0, hex_text(d->name, (int)sizeof(d->name), h1, (int)sizeof(h1)));
        return;
    }
    case DEVEDIT_ADD_DIGI:
        apply_add_digi(e);
        return;
    case DEVEDIT_BAG:
        if (!clamp_ok(e->a, 0, 0x2F) || (e->b != 0 && !item_ok(e->b, &why))) {
            refuse(e, *why ? why : "bag slot 0..47");
            return;
        }
        if (e->b != 0 && e->a >= Item_GetBagCapacity()) {
            refuse(e, "slot past the bag size (tool box part)");
            return;
        }
        old = Save_GameState.bagItems[e->a];
        Save_GameState.bagItems[e->a] = (u16)e->b;
        compact_bag(); /* no holes, as Item_CompactBag (without its CD-cache id check) */
        LOG("bag %d: 0x%03X %s -> 0x%03X %s\n", vb, e->a, old, old ? DevData_ItemName(old) : "-", e->b,
            e->b ? DevData_ItemName(e->b) : "-");
        return;
    case DEVEDIT_BAG_ADD: {
        int slot;

        if (!item_ok(e->a, &why)) {
            refuse(e, why);
            return;
        }
        slot = Item_AddToBag(e->a);
        if (slot < 0) {
            refuse(e, "bag full");
            return;
        }
        LOG("bag %d: - -> 0x%03X %s\n", vb, slot, e->a, DevData_ItemName(e->a));
        return;
    }
    case DEVEDIT_STORAGE:
        if (!clamp_ok(e->a, 1, 0xFF) || !item_ok(e->a, &why) || !clamp_ok(e->b, 0, 999)) {
            refuse(e, *why ? why : "storage: item id 1..255, count 0..999");
            return;
        }
        old = Save_GameState.storageCounts[e->a];
        Save_GameState.storageCounts[e->a] = (u16)e->b;
        LOG("storage 0x%02X %s: %d -> %d\n", vb, e->a, DevData_ItemName(e->a), old, e->b);
        return;
    case DEVEDIT_PART:
        apply_part(e);
        return;
    case DEVEDIT_BROKEN:
        if (!clamp_ok(e->a, 0, 18) || !clamp_ok(e->b, 0, 1)) {
            refuse(e, "part slot 0..18, value 0 / 1");
            return;
        }
        if (Save_GameState.slotItems[e->a] == 0) {
            refuse(e, "no part in that slot");
            return;
        }
        old = Save_GameState.slotStatus[e->a];
        Beetle_SetPartBroken(e->a, e->b);
        LOG("part %d %s broken: %d -> %d\n", vb, e->a, DevData_SlotName(e->a), old, Save_GameState.slotStatus[e->a]);
        return;
    case DEVEDIT_BEETLE: {
        s16 *p[4] = { &Save_GameState.hp, &Save_GameState.maxHp, &Save_GameState.mp, &Save_GameState.maxMp };

        if (!clamp_ok(e->a, 0, 3) || !clamp_ok(e->b, 0, 9999)) {
            refuse(e, "beetle field hp / maxhp / ep / maxep, value 0..9999");
            return;
        }
        old = *p[e->a];
        *p[e->a] = (s16)e->b;
        LOG("beetle %s: %d -> %d\n", vb, beetle_names[e->a], old, e->b);
        return;
    }
    case DEVEDIT_WARP: {
        int from = Sys_State.gameMode, from_arg = Sys_State.modeArg;

        if (!DevEdit_CanWarp(&why)) {
            refuse(e, why);
            return;
        }
        if (e->a == 0x200) {
            if ((from >> 8) != 3) {
                refuse(e, "domains are entered from the city only (Stg40_SetupStage entryMode 0)");
                return;
            }
            if (!clamp_ok(e->b, 0, DOMAINS - 1)) {
                refuse(e, "domain 0..32");
                return;
            }
        } else if (!need_tables(&why) || !DevData_IsDest(e->a, e->b)) {
            refuse(e, *why ? why : "not a city destination of the game (area select record or map exit)");
            return;
        }
        Sys_State.nextGameMode = e->a;
        Sys_State.modeArg = e->b;
        LOG("warp: mode 0x%X arg %d -> mode 0x%X arg %d (%s)\n", vb, from, from_arg, e->a, e->b,
            DevData_DestName(e->a, e->b));
        return;
    }
    case DEVEDIT_FLOOR: {
        int n;

        if (!DevEdit_CanFloor(&why)) {
            refuse(e, why);
            return;
        }
        n = DevEdit_FloorCount();
        if (!clamp_ok(e->a, 0, n - 1)) {
            refuse(e, "floor past the domain's last floor");
            return;
        }
        old = Dung_StatePtr->floor;
        Dung_StatePtr->floor = (u8)e->a;
        Sys_State.nextGameMode = Sys_State.gameMode; /* the stairs path, Stg40_BeginTransition case 2 */
        LOG("floor (domain %d, %d floors): %d -> %d\n", vb, Dung_StatePtr->dungeonIdx, n, old, e->a);
        return;
    }
    case DEVEDIT_DUMP:
        dump();
        return;
    }
    refuse(e, "unknown edit");
}

void DevEdit_ScriptTick(unsigned int wait) {
    while (script_next < script_count && script[script_next].wait <= wait) {
        if (!DevEdit_Push(&script[script_next].e)) {
            printf("[devedit] script edit at wait %u dropped (queue full or edits off)\n", script[script_next].wait);
        }
        script_next++;
    }
}

void DevEdit_Apply(void) {
    DevEdit batch[QUEUE];
    int i, n = 0;

    if (SDL_GetAtomicInt(&pending) == 0) {
        return; /* the normal case: nothing queued, nothing read or written */
    }
    if (!SDL_TryLockMutex(lock)) {
        return; /* the main thread is queueing: next VBlank */
    }
    while (q_count > 0) {
        batch[n++] = queue[q_head];
        q_head = (q_head + 1) % QUEUE;
        q_count--;
    }
    SDL_SetAtomicInt(&pending, 0);
    SDL_UnlockMutex(lock);
    vb = Host_VBlankCount();
    for (i = 0; i < n; i++) {
        if (!SDL_GetAtomicInt(&allowed)) {
            refuse(&batch[i], "edits are off (online mode)");
            continue;
        }
        apply(&batch[i]);
    }
    fflush(stdout);
}

/* ---- --devedit WAIT:KIND=ARGS ---- */

static int parse_ints(const char *s, int *v, int max) {
    int n = 0;

    while (*s != 0 && n < max) {
        char *end;

        v[n++] = (int)strtol(s, &end, 0);
        if (end == s) {
            return -1;
        }
        s = end;
        if (*s == ',') {
            s++;
        } else if (*s != 0) {
            return -1;
        }
    }
    return *s == 0 ? n : -1;
}

static int find_name(const char *s, const char *const *names, int count) {
    int i;

    for (i = 0; i < count; i++) {
        if (SDL_strcasecmp(s, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int DevEdit_Script(const char *arg) {
    char kind[16], rest[96];
    const char *colon = strchr(arg, ':'), *eq;
    DevEdit e;
    int v[10], n = 0, k;
    char *end;
    unsigned long wait;

    memset(&e, 0, sizeof(e));
    memset(e.text, 0xFF, sizeof(e.text));
    wait = strtoul(arg, &end, 0);
    if (colon == NULL || end != colon || script_count >= SCRIPT_MAX) {
        goto bad;
    }
    eq = strchr(colon + 1, '=');
    SDL_strlcpy(kind, colon + 1, eq != NULL && eq - colon < (int)sizeof(kind) ? (size_t)(eq - colon) : sizeof(kind));
    SDL_strlcpy(rest, eq != NULL ? eq + 1 : "", sizeof(rest));
    e.kind = find_name(kind, kind_names, DEVEDIT_KINDS);
    switch (e.kind) {
    case DEVEDIT_DIGI: {
        /* digi=SLOT,FIELD,VALUE with FIELD a name */
        char *c1 = strchr(rest, ','), *c2 = c1 ? strchr(c1 + 1, ',') : NULL;

        if (c2 == NULL) {
            goto bad;
        }
        *c1 = *c2 = 0;
        e.a = (int)strtol(rest, NULL, 0);
        e.b = find_name(c1 + 1, field_names, DEVDIGI_FIELDS);
        e.c = (int)strtol(c2 + 1, &end, 0);
        if (e.b < 0 || *end != 0) {
            goto bad;
        }
        break;
    }
    case DEVEDIT_NAME: {
        char *c1 = strchr(rest, ',');

        if (c1 == NULL) {
            goto bad;
        }
        *c1 = 0;
        e.a = (int)strtol(rest, NULL, 0);
        if (DevEdit_EncodeText(c1 + 1, e.text, (int)sizeof(e.text)) <= 0) {
            goto bad;
        }
        break;
    }
    case DEVEDIT_BEETLE: {
        char *c1 = strchr(rest, ',');

        if (c1 == NULL) {
            goto bad;
        }
        *c1 = 0;
        e.a = find_name(rest, beetle_names, 4);
        e.b = (int)strtol(c1 + 1, &end, 0);
        if (e.a < 0 || *end != 0) {
            goto bad;
        }
        break;
    }
    case DEVEDIT_ADD_DIGI:
        /* adddigi=SPECIES,LEVEL[,MAXLEVEL,HP,MP,ATTACK,DEFENSE,SPEED,SKILL] */
        n = parse_ints(rest, v, 9);
        if (n < 2) {
            goto bad;
        }
        e.a = v[0];
        e.b = v[1];
        e.c = n > 2 ? v[2] : (v[1] < 28 ? v[1] + 10 : v[1] + 2);
        for (k = 0; k < 5; k++) {
            static const int16_t defaults[5] = { 100, 50, 30, 30, 30 };

            e.v[k] = n > 3 + k ? (int16_t)v[3 + k] : defaults[k];
        }
        e.d = n > 8 ? v[8] : -1; /* -1: the species' learned skill (resolved at apply) */
        break;
    case DEVEDIT_DUMP:
        if (rest[0] != 0) {
            goto bad;
        }
        break;
    default:
        if (e.kind < 0) {
            goto bad;
        }
        n = parse_ints(rest, v, 3);
        if (n < 1) {
            goto bad;
        }
        e.a = v[0];
        e.b = n > 1 ? v[1] : 0;
        e.c = n > 2 ? v[2] : 0;
        break;
    }
    /* keep the list in wait order (same wait: command line order) */
    for (k = script_count; k > 0 && script[k - 1].wait > wait; k--) {
        script[k] = script[k - 1];
    }
    script[k].wait = (unsigned int)wait;
    script[k].e = e;
    script_count++;
    return 1;
bad:
    printf("[devedit] bad --devedit %s (WAIT:KIND=ARGS, kinds flag progress bits rank digi skill name adddigi bag "
           "bagadd storage part broken beetle warp floor dump)\n", arg);
    return 0;
}

#endif /* DW2_DEV */
