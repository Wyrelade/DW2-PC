#ifndef HOST_DEVDATA_H
#define HOST_DEVDATA_H

/* PD.7 / PD.3 dev overlay data (DW2_DEV only): the game's Digimon, item and skill tables and their
 * names, read from dw2.pak on the main thread (Host_PakReadFile, no game call, no game state) and
 * decoded from the game's text encoding (doc: PLAN.md PD Findings, "PD.7 table formats"). Nothing
 * from the disc is stored in the repo: every name comes from the player's pack at run time. */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEVDATA_DIGI_IDS 0x400 /* Digimon ids 0..0x3FF (MODELDT names reach 645) */
#define DEVDATA_ITEM_IDS 0x200 /* ITEMDATA ids reach 0x108 (storageCounts covers 0..0xFF) */
#define DEVDATA_SKILL_IDS 0x200

typedef struct {
    int16_t id;
    uint8_t hasBase;      /* has a DIGIMNDT record (the fields below) */
    uint8_t learnedSkill; /* skill id */
    uint8_t dnaGroup;
    uint8_t type, rank, specialty; /* indexes for DevData_TypeName / RankName / SpecialtyName */
    uint8_t growth[5];    /* growth class: HP, MP, attack, defense, speed */
    uint8_t dpBounds[5];  /* Digi_GetEvolutionTarget: DP ranges ... */
    uint8_t dpTargets[4]; /* ... and the digivolve target per range (0 none) */
    int16_t modelFile;
    char name[32];        /* UTF-8 */
    uint8_t rawName[14];  /* the default name in game text (0xFF ends), as Digi_GetDefaultName */
} DevDigi;

/* A scene the PD.4 warp may switch to (city areas and domains), from the game's own lists:
 * area select records (file 0xD29) and map exits (file 0x309). PLAN.md PD Findings "PD.4 warp". */
typedef struct {
    int16_t mode;  /* game mode: 0x301..0x32E city, 0x200 domain */
    uint8_t arg;   /* modeArg: start record, cursor or domain index */
    uint8_t named; /* 1: from an area select record (its name), 0: a map exit */
    char name[40];
} DevDest;

typedef struct {
    int16_t id;
    uint8_t category, level, useKind, bodyMask;
    int32_t price;
    char name[32];
    char desc[96];
} DevItem;

typedef struct {
    int16_t id, power;
    uint8_t mp, castAnim, type, target, specialty, rank;
    char name[40];
    char desc[96];
} DevSkill;

/* Main thread, before the game thread starts (DevUi_Init): copies the game's constant tables the
 * overlay needs from game C data (text dictionary, DNA tables). */
void DevData_InitConst(void);
/* Read and decode the tables from the pack once. 1 = loaded (now or before), 0 = not (pack not
 * open yet: try again later, or a file did not parse). Any thread: one load runs at a time
 * (SDL_InitState); the tables are read only afterwards, so the game thread may use them too
 * (PD.4 checks) once DevData_Ready says so. */
int DevData_Load(void);
int DevData_Ready(void);

/* Lists in file order, and lookups by id (NULL: no such id). */
int DevData_DigiCount(void);
const DevDigi *DevData_DigiAt(int i);
const DevDigi *DevData_Digi(int id);
int DevData_ItemCount(void);
const DevItem *DevData_ItemAt(int i);
const DevItem *DevData_Item(int id);
int DevData_SkillCount(void);
const DevSkill *DevData_SkillAt(int i);
const DevSkill *DevData_Skill(int id);

/* Warp destinations, sorted by mode and arg. */
int DevData_DestCount(void);
const DevDest *DevData_DestAt(int i);
int DevData_IsDest(int mode, int arg);
const char *DevData_DestName(int mode, int arg); /* "?" when unknown */

/* Name of an id, or a fallback "?" (never NULL). */
const char *DevData_DigiName(int id);
const char *DevData_ItemName(int id);
const char *DevData_SkillName(int id);

/* Labels from the game's system text (file 0x1FD, as the status screen shows them). */
const char *DevData_TypeName(int type);
const char *DevData_RankName(int rank);
const char *DevData_SpecialtyName(int specialty);
/* Beetle part slot 0..18 (slot k holds item category k - 1, slot 0 the body). */
const char *DevData_SlotName(int slot);
/* Item category -> slot name for part categories 0..19, else a short use label. */
const char *DevData_CategoryName(int category);

/* Decode game text (0xFF ends, at most max bytes) into UTF-8 in out[n]. playerName: what F0 00
 * shows (NULL: "<tamer>"). Returns out. */
char *DevData_Text(const uint8_t *src, int max, const uint8_t *playerName, char *out, int n);

/* DNA digivolution (stag2000 dna.c Stg20_GetDnaResult, on the copied table): result Digimon id,
 * 0 when there is none (a parent without base data, a Rookie: the lab takes Champions and up, or
 * DNA group 8: only the boss forms, past the [8][8] table).
 * *level: the level it starts at (digilab.c: its rank * 10 + 1). */
int DevData_DnaResult(int a, int b, int *level);

#ifdef __cplusplus
}
#endif

#endif /* HOST_DEVDATA_H */
