#ifndef STAG4000_H
#define STAG4000_H

#include "common.h"
#include "main/156C.h"

/* STAG4000 (Ovl_FileIds id 1, gameMode 0x2xx). */

/* View of *D_8005071C (main Blk5071C) as this overlay uses it. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    u8 _pad06[0x04];
    /* 0x0A */ s16 field_A;
    /* 0x0C */ u8 field_C;
    /* 0x0D */ u8 field_D;      /* count of field_E bytes (Stg40_ApplyFloorLayout) */
    /* 0x0E */ u8 field_E[16];
    u8 _pad1E[0x02];
} Stg40E34;

typedef struct {
    /* 0x00 */ s16 field_0[11];
    /* 0x16 */ s16 field_16;       /* count used by Stg40_TurnQueueNext */
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;       /* index into field_0 */
} Stg40FFC;

/* Map position block inside Stg40Ent48 (at 0x18); the x/y pair is also compared as one word
 * (Stg40_FindObjAtSameTile). Passed to Stg40_ScrollFollow / Stg40_ScrollToFollow. */
typedef struct {
    union {
        /* 0x00 */ s32 field_0;
        /* 0x00 */ Pair54 pair;
    } u0;
    /* 0x04 */ Pair54 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ u16 field_1E;
} Stg40Loc;

/* Element of Stg40Blk5071C.field_18 (stride 0x48, 41 entries; Stg40_RevealAllEnts). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 field_7;
    /* 0x08 */ u8 field_8;         /* kind, switched on by Stg40_FixtureUpdate */
    /* 0x09 */ u8 field_9;
    /* 0x0A */ u8 field_A;
    /* 0x0B */ u8 field_B;         /* heading octant (Stg40_ObjStepMove) */
    /* 0x0C */ s16 field_C;        /* current heading, turns toward field_E */
    /* 0x0E */ u16 field_E;
    /* 0x10 */ u8 *field_10;
    /* 0x14 */ Actor *field_14;
    /* 0x18 */ Stg40Loc field_18;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ s32 field_40;
    u8 _pad44[0x04];
} Stg40Ent48;

/* x, y, value byte triple (Stg40Blk5071C.field_D08; Stg40_ApplyTrapCells, Stg40_PickRandomPoint). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
} Stg40Rec3;

/* Output pair written by Stg40_PickRandomPoint. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Stg40Pick;

/* 4-byte record of Stg40MapRoom.field_8 (Stg40_SpawnChests): cell x, y, four 1-based picks into Stg40Map.field_34. */
typedef struct {
    /* 0x0 */ u32 x : 8;           /* 0xFF terminates the list */
    u32 y : 8;
    u32 pick0 : 4;
    u32 pick1 : 4;
    u32 pick2 : 4;
    u32 pick3 : 4;
} Stg40Drop;

/* Element of Stg40Map.field_34 (stride 4). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    u8 _pad2[0x02];
} Stg40MapPos;

/* 8-byte spawn record (Stg40_SpawnFixedHazards): cell x, y, then four (kind, offset) nibble pairs. */
typedef struct {
    /* 0x0 */ u32 x : 8;           /* 0xFF terminates the list */
    u32 y : 8;
    u32 kind0 : 4;
    u32 val0 : 4;
    u32 kind1 : 4;
    u32 val1 : 4;
    /* 0x4 */ u32 kind2 : 4;
    u32 val2 : 4;
    u32 kind3 : 4;
    u32 val3 : 4;
    u32 _rest : 16;
} Stg40Spawn;

/* Element picked from Stg40Map.field_8 into Stg40B60.field_14 (Stg40_PickSpawnPoints). */
typedef struct {
    /* 0x00 */ u32 *field_0;      /* 4-bit cell codes, 8 per word (Stg40_ReadFloorBits) */
    /* 0x04 */ Stg40Rec3 *field_4;  /* 0xFF-terminated, passed to Stg40_PickRandomPoint */
    /* 0x08 */ Stg40Drop *field_8;  /* 0xFF-terminated (Stg40_SpawnChests) */
    /* 0x0C */ Stg40Spawn *field_C; /* 0xFF-terminated (Stg40_SpawnFixedHazards) */
    /* 0x10 */ Stg40Drop *field_10; /* 0xFF-terminated (Stg40_SpawnEnemyParties) */
} Stg40MapRoom;

/* Stg40Ent48.field_10 viewed as the info block Stg40_EnemyInfoDraw draws. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 field_5;
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 field_7;
    /* 0x08 */ u8 field_8;
    /* 0x09 */ u8 field_9;
    /* 0x0A */ u8 field_A;
    /* 0x0B */ u8 field_B;          /* count of used field_16 entries */
    /* 0x0C */ s16 field_C;
    /* 0x0E */ u16 field_E;
    /* 0x10 */ s16 field_10[3];     /* digimon ids (Stg40_EnemyInfoUpdate) */
    /* 0x16 */ s16 field_16[3];
} Stg40SlotInfo;

/* Stg40MapRoom / Stg40Map as file offsets before Stg40_RelocDungFile relocates them. */
typedef struct {
    /* 0x00 */ u32 field_0[5];
} Stg40MapRoomRel;

typedef struct {
    /* 0x00 */ u32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ u32 field_8[8];
} Stg40MapRel;

/* Actor.work of the draw task Stg40_HudDraw. */
typedef struct {
    u8 _pad00[0x0C];
    /* 0x0C */ s32 field_C;        /* scale; 0 = hidden */
    /* 0x10 */ s16 field_10;       /* part mask */
    /* 0x12 */ s16 field_12;
    /* 0x14 */ s16 field_14;
} Stg40W6AD0;

/* Element of Stg40Map.field_54 (Stg40_SpawnRandomHazards): four random value nibbles, four random count nibbles. */
typedef struct {
    /* 0x0 */ u32 val0 : 4;
    u32 val1 : 4;
    u32 val2 : 4;
    u32 val3 : 4;
    u32 _rest0 : 16;
    /* 0x4 */ u32 cnt0 : 4;
    u32 cnt1 : 4;
    u32 cnt2 : 4;
    u32 cnt3 : 4;
    u32 _rest1 : 16;
} Stg40MapGen;

/* Five ids copied from Stg40_RandomHazardKinds (Stg40_SpawnRandomHazards). */
typedef struct {
    s32 id[5];
} Stg40Ids5;

/* Map header behind Stg40B60.field_10 (Stg40_ApplyFloorLayout). */
typedef struct {
    /* 0x00 */ u8 *field_0;       /* 0xFF-terminated byte list */
    /* 0x04 */ s32 field_4;       /* flag script (Stg40_LoadEventTiles) */
    /* 0x08 */ Stg40MapRoom *field_8[8];
    /* 0x28 */ u16 field_28;
    u8 _pad2A[0x02];
    /* 0x2C */ s16 field_2C;      /* index into D_800729B4 */
    /* 0x2E */ u8 field_2E;
    /* 0x2F */ u8 field_2F[5];     /* 1-based ids picked by Stg40_SpawnEnemyParties */
    /* 0x34 */ Stg40MapPos field_34[8];
    /* 0x54 */ Stg40MapGen field_54[5];
} Stg40Map;

/* Entries collected by Stg40_CheckEncounter (Stg40Blk5071C.field_1018). */
typedef struct {
    /* 0x00 */ Stg40Ent48 *field_0[8];
    /* 0x20 */ s16 field_20;       /* count */
} Stg40List;

/* 0x14-byte row of file 0xE20000A (Stg40_InitDungeonEntry). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;      /* sound id (Stg40_BeginTransition) */
    /* 0x0A */ s16 field_A;      /* sound arg (Stg40_BeginTransition) */
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg40Stage14;

/* Element of the grid behind Stg40Blk5071C.field_E58 (field_E54 dims; Stg40_GetCellFlags). */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
} Stg40Cell;

typedef struct {
    /* 0x000 */ u8 field_0;
    /* 0x001 */ u8 field_1;
    /* 0x002 */ u8 field_2;
    /* 0x003 */ u8 field_3;
    /* 0x004 */ u8 field_4;
    /* 0x005 */ u8 field_5;
    /* 0x006 */ u8 field_6;
    /* 0x007 */ u8 field_7;
    /* 0x008 */ s32 field_8;
    /* 0x00C */ s16 field_C;       /* count of live field_18 entries (Stg40_FindObjAtSameTile) */
    /* 0x00E */ s16 field_E;       /* count of field_BB8 records (Stg40_AddEntity) */
    /* 0x010 */ s16 field_10;      /* count of field_CCE pairs (Stg40_SpawnChests) */
    /* 0x012 */ s16 field_12;      /* count of field_CE8 pairs (Stg40_AddEntity) */
    /* 0x014 */ s16 field_14;      /* count of live field_D08 entries (Stg40_ApplyTrapCells) */
    u8 _pad016[0x02];
    /* 0x018 */ Stg40Ent48 field_18[41];
    /* 0xBA0 */ s32 field_BA0;     /* bit 0 tested by Stg40_PlayerInput */
    /* 0xBA4 */ u8 field_BA4;
    /* 0xBA5 */ u8 field_BA5;
    /* 0xBA6 */ u8 field_BA6;
    /* 0xBA7 */ u8 field_BA7;
    /* 0xBA8 */ u8 field_BA8;      /* count of field_BA9 */
    /* 0xBA9 */ u8 field_BA9[12];
    /* 0xBB5 */ u8 field_BB5;
    u8 _padBB6[0x02];
    /* 0xBB8 */ u8 field_BB8[9][0x1C]; /* per-entry data of kind 1 (Stg40_AddEntity) */
    u8 _padCB4[0xCCE - 0xCB4];
    /* 0xCCE */ u8 field_CCE[12][2];
    u8 _padCE6[0x02];
    /* 0xCE8 */ u8 field_CE8[16][2]; /* per-entry data of kinds 5..12 (Stg40_AddEntity) */
    /* 0xD08 */ Stg40Rec3 field_D08[100];
    /* 0xE34 */ Stg40E34 field_E34;
    /* 0xE54 */ Stg40E34 *field_E54;
    /* 0xE58 */ ActorWork *field_E58;
    /* 0xE5C */ s32 field_E5C[8];
    /* 0xE7C */ u8 field_E7C[0x180];
    /* 0xFFC */ Stg40FFC field_FFC;
    /* 0x1018 */ Stg40List field_1018;
    u8 _pad103C[0x01];
    /* 0x103D */ u8 field_103D;
    /* 0x103E */ u16 field_103E;
    /* 0x1040 */ s16 field_1040;
    u8 _pad1042[0x02];
    /* 0x1044 */ Stg40Stage14 field_1044; /* row of file 0xE20000A picked by field_1058 */
    /* 0x1058 */ s16 field_1058;
    u8 _pad105A[0x02];
    /* 0x105C */ s32 field_105C;
    /* 0x1060 */ s32 field_1060;
    /* 0x1064 */ Stg40Loc *field_1064;
    /* 0x1068 */ Stg40Loc *field_1068;
} Stg40Blk5071C;

/* Work of the task behind Stg40_ItemMenuTask (init Stg40_ItemMenuInit). */
typedef struct {
    /* 0x00 */ s32 field_0[6];     /* text handles of the list rows */
    /* 0x18 */ s32 field_18;       /* text handle of the description */
    /* 0x1C */ s32 field_1C;       /* scale; 0 = hidden (Stg40_ItemMenuDraw) */
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28[6];    /* row text ids (filled through Stg40_ItemMenuGetTextIds) */
    /* 0x40 */ s32 field_40;       /* description text id */
    /* 0x44 */ u8 field_44;
    /* 0x45 */ u8 field_45;
    /* 0x46 */ u8 field_46;
} Stg40ObjWork;

/* Init args of Stg40_LinkedModelInit. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u16 field_4;
} Stg40InitArg;

/* Element of Stg40_LinkedModelTable (Stg40_LinkedModelUpdate): model id and an animation flag. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Stg40Model25DC;

/* Work of the task initialised by Stg40_LinkedModelInit. */
typedef struct {
    /* 0x00 */ s32 field_0;        /* model id */
    /* 0x04 */ s32 field_4[3];     /* position (Actor_InitTransform) */
    /* 0x10 */ s32 field_10;       /* rotation, read as u16 */
    /* 0x14 */ s32 field_14;       /* model file */
    /* 0x18 */ s32 field_18;       /* anim file */
    u8 _pad1C[0x04];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u16 field_24;       /* index into Stg40_LinkedModelTable */
    u8 _pad26[0x02];
    /* 0x28 */ s32 field_28;
} Stg40InitWork;

/* Actor.work of the objects driven by Stg40_ObjStartFlash / Stg40_ObjSetAnim. */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;       /* model file */
    /* 0x18 */ s32 field_18;       /* anim file */
    u8 _pad1C[0x04];
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 field_22;
    /* 0x23 */ u8 field_23;
    /* 0x24 */ u8 field_24;
    u8 _pad25[0x01];
    /* 0x26 */ u8 field_26;
    /* 0x27 */ u8 field_27;
    /* 0x28 */ u8 field_28;
    u8 _pad29[0x03];
    /* 0x2C */ Stg40Ent48 *field_2C;
    /* 0x30 */ s16 field_30;
    /* 0x32 */ s16 field_32;
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;       /* pending child task arg, -1 = none (Stg40_ObjUpdate) */
    /* 0x38 */ s16 field_38;       /* last child task arg */
} Stg40ActWork;

/* 0x90-byte transform block behind Actor.u38 (copied whole by Stg40_LinkedModelDraw). */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x04];
    /* 0x40 */ s16 field_40;
    /* 0x42 */ s16 field_42;
    /* 0x44 */ s16 field_44;
    u8 _pad46[0x12];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
    u8 _pad64[0x2C];
} Stg40Xform;

/* Work of the child object drawn by Stg40_LinkedModelDraw. */
typedef struct {
    u8 _pad00[0x14];
    /* 0x14 */ s32 field_14;       /* model file */
    u8 _pad18[0x08];
    /* 0x20 */ Actor *field_20;    /* parent */
    u8 _pad24[0x04];
    /* 0x28 */ s32 field_28;
} Stg40ChildWork;

/* Actor.model viewed with the bytes Stg40_SetModelTint sets. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    u8 _pad36[0x02];
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg40ModelView;

/* 4-byte colour (copied whole from D_80063438 by Stg40_PlayerExitFloor). */
typedef struct {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 x;
} Stg40Col;

/* Actor.model viewed with the fade fields Stg40_PlayerExitFloor sets. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ Stg40Col field_38;
} Stg40ModelFade;

/* Image work: pixel data, its VRAM rect, a texture slot (Stg40_AutomapLoadClut / Stg40_AutomapReleaseTex). */
typedef struct {
    /* 0x000 */ u32 data[0x748 / 4];
    /* 0x748 */ RECT rect;
    u8 _pad750[0x08];
    /* 0x758 */ s32 *field_758;
    /* 0x75C */ s32 field_75C;
} Stg40ImgWork;

/* Stg40ImgWork viewed with the 16-colour CLUT Stg40_AutomapCycleClut animates at 0x14. */
typedef struct {
    u8 _pad000[0x14];
    /* 0x014 */ u16 clut[8];
    u8 _pad024[0x75C - 0x24];
    /* 0x75C */ s32 field_75C;     /* frame counter */
} Stg40ImgClut;

/* Stg40TileWork viewed as 4bpp pixels, 18 halfwords per row (Stg40_AutomapSetCell). */
typedef struct {
    u8 _pad000[0x40];
    /* 0x040 */ u16 pix[50 * 18];
    u8 _pad748[0x18];
    /* 0x760 */ s16 field_760;
} Stg40TileGrid;

/* Tile image work: pixel data at 0x40, its VRAM rect, a dirty flag (Stg40_AutomapFlush / Stg40_AutomapInitDims). */
typedef struct {
    u8 _pad000[0x40];
    /* 0x040 */ u32 data[(0x748 - 0x40) / 4];
    /* 0x748 */ RECT clut;
    /* 0x750 */ RECT rect;
    /* 0x758 */ GfxTexSlot *slot;
    u8 _pad75C[0x04];
    /* 0x760 */ s16 field_760;
    /* 0x762 */ s16 field_762[2];
    /* 0x766 */ s16 field_766;
    /* 0x768 */ s16 field_768;
    /* 0x76A */ s16 field_76A;
    /* 0x76C */ s16 field_76C;     /* last drawn player cell x (Stg40_AutomapRevealAround) */
    /* 0x76E */ s16 field_76E;     /* last drawn player cell y */
} Stg40TileWork;

/* Element of Stg40B60.field_144 (stride 8, 5 entries; Stg40_CheckEventTile). */
typedef struct {
    union {
        /* 0x0 */ s32 field_0;
        /* 0x0 */ Pair54 pair;
    } u0;
    /* 0x4 */ s32 field_4;
} Stg40B60Ent;

typedef struct {
    /* 0x000 */ s32 field_0;
    /* 0x004 */ Stg40Ent48 *field_4;
    /* 0x008 */ Actor *field_8;
    /* 0x00C */ s32 *field_C;      /* Cd_GetFileOrNull table (Stg40_LoadDungFile) */
    /* 0x010 */ s32 field_10;      /* Stg40Map * (Stg40_ApplyFloorLayout) */
    /* 0x014 */ Stg40MapRoom *field_14;
    /* 0x018 */ s16 field_18;      /* count of non-zero field_C words */
    u8 _pad01A[0x02];
    /* 0x01C */ s32 field_1C;
    /* 0x020 */ Stg40Pick field_20;
    /* 0x024 */ Stg40Pick field_24;
    /* 0x028 */ Stg40Pick field_28;
    /* 0x02C */ s32 field_2C;
    /* 0x030 */ s32 field_30;
    /* 0x034 */ s32 field_34;
    /* 0x038 */ s32 field_38;
    /* 0x03C */ Actor *field_3C;
    /* 0x040 */ Stg40Ent48 *field_40;
    /* 0x044 */ s32 field_44;
    /* 0x048 */ s32 field_48;
    /* 0x04C */ s32 field_4C;
    /* 0x050 */ s32 field_50;
    /* 0x054 */ s32 field_54;      /* Stg40_RollTrapEffect result (Stg40_PlayerTriggerTrap) */
    /* 0x058 */ s32 field_58;
    u8 _pad05C[0x04];
    /* 0x060 */ u8 field_60[8];    /* stack indexed by field_68 (Stg40_PlayerShowStatusMsgs) */
    /* 0x068 */ s16 field_68;
    /* 0x06A */ u8 field_6A[0x0E];
    /* 0x078 */ s32 field_78;
    u8 _pad07C[0x02];
    /* 0x07E */ s16 field_7E;
    /* 0x080 */ Stg40Ent48 *field_80[10]; /* matching entries (Stg40_PlayerCheckEnemyInfo) */
    /* 0x0A8 */ s32 field_A8;      /* count of field_80 */
    /* 0x0AC */ s32 field_AC;      /* index into field_80 */
    /* 0x0B0 */ u8 field_B0[0x30]; /* item ids listed by Stg40_ItemMenuRefresh */
    /* 0x0E0 */ u8 field_E0;       /* item id counted by Stg40_PlayerShootObstacle */
    /* 0x0E1 */ u8 field_E1;
    /* 0x0E2 */ u8 field_E2;       /* cursor, 0..field_E1-1 (Stg40_ItemMenuMoveCursor) */
    /* 0x0E3 */ u8 field_E3;       /* first visible row (Stg40_ItemMenuRefresh) */
    /* 0x0E4 */ u8 field_E4;
    u8 _pad0E5[0x03];
    /* 0x0E8 */ s32 field_E8;      /* heading to the target (Stg40_PlayerShootGift) */
    /* 0x0EC */ s32 field_EC;      /* step x */
    /* 0x0F0 */ s32 field_F0;      /* step y */
    /* 0x0F4 */ s32 field_F4;      /* position x << 14 */
    /* 0x0F8 */ s32 field_F8;
    /* 0x0FC */ s32 field_FC;      /* target x << 14 */
    /* 0x100 */ s32 field_100;
    u8 _pad104[0x04];
    /* 0x108 */ Stg40Loc field_108;
    /* 0x128 */ s16 field_128[12]; /* roster indices picked by Stg40_ListPartyDigi */
    /* 0x140 */ s16 field_140;
    u8 _pad142[0x02];
    /* 0x144 */ Stg40B60Ent field_144[5];
    /* 0x16C */ u32 field_16C;
    /* 0x170 */ s32 field_170;
    /* 0x174 */ s32 field_174;     /* text handle (Stg40_PlayerRunEvent) */
    /* 0x178 */ s32 field_178;
    /* 0x17C */ Pair54 field_17C;  /* target cell (Stg40_AiPathToTarget) */
    /* 0x180 */ s16 field_180;
    u8 _pad182[0x02];
    /* 0x184 */ Actor *field_184;
    /* 0x188 */ s32 field_188;     /* spawned object mask (Stg40_SpawnHazard) */
    /* 0x18C */ s16 field_18C;     /* spawned object count, max 12 */
} Stg40B60;

/* Argument of Stg40_ListUsableItems: an event id, up to 4 item-category keys (-1 = unused), a result base. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2[4];
    u8 _padA[0x02];
    /* 0xC */ s32 field_C;
} Stg40Shop;

/* Work of the task behind Stg40_FloorTask. */
typedef struct {
    u8 _pad0000[0x1E90];
    /* 0x1E90 */ s32 field_1E90;
    /* 0x1E94 */ s32 field_1E94;
    /* 0x1E98 */ s32 field_1E98;
    /* 0x1E9C */ s32 field_1E9C;
    /* 0x1EA0 */ s32 field_1EA0;
} Stg40B68Work;

/* 0x20-byte block copied by Stg40_CamStartMove. */
typedef struct {
    s32 words[8];
} Stg40Blk20;

/* Command record walked by Stg40_CamNextCommand (stride 0x2C). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ Stg40Blk20 field_C;
} Stg40Cmd;

/* GsRVIEW2-shaped view passed to GsSetRefView2 (Stg40_CameraUpdate). */
typedef struct {
    /* 0x00 */ s32 field_0[6];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 *field_1C;
} Stg40RView;

/* Work of the task initialised by Stg40_CameraInit (Stg40_CameraTask). */
typedef struct {
    /* 0x00 */ Block1C field_0;    /* view: words 0..5 = vp/vr, word 6 = projection */
    /* 0x1C */ Coord1F668 field_1C;
    /* 0x6C */ s32 field_6C;
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s32 field_74;
    u8 _pad78[0x04];
    /* 0x7C */ s16 field_7C[4];     /* rotation (RotMatrixYXZ) */
    /* 0x84 */ s32 field_84;
    /* 0x88 */ Stg40Blk20 field_88;
    /* 0xA8 */ s32 field_A8;
    /* 0xAC */ s32 field_AC;
    /* 0xB0 */ s32 field_B0;
    /* 0xB4 */ Stg40Cmd *field_B4;
    /* 0xB8 */ s32 field_B8;
    /* 0xBC */ Stg40Cmd field_BC[1]; /* filled by Stg40_CamLoadScript up to a zero field_0 record; count unknown */
} Stg40BC0Work;

/* Three halfwords written by Stg40_MapPosToWorld (SVECTOR-like). */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
    /* 0x4 */ s16 field_4;
} Stg40Vec3;

/* Three words at Cd_GetFileEntry(0xE200002): ambient r, g, b (Stg40_InitDisplay). */
typedef struct {
    /* 0x0 */ s32 r;
    /* 0x4 */ s32 g;
    /* 0x8 */ s32 b;
} Stg40Rgb;

/* Element of Stg40W667C.field_F20 (stride 0xC; Stg40_DrawFloorTiles / Stg40_DrawTileTop). */
typedef struct {
    /* 0x0 */ u16 field_0;         /* 0 = untextured floor */
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;          /* template index (low 7 bits) into Stg40_FloorPrimIdx */
    /* 0x4 */ s32 field_4;
    /* 0x8 */ s32 field_8;         /* ordering table index of the flat quad */
} Stg40Tile;

/* One projected corner (Stg40_DrawTileTop): screen x/y and a visibility weight. */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s32 field_4;
    u8 _pad8[0x02];
    /* 0xA */ s16 flag;
} Stg40VSet;

/* Grid vertex of Stg40W667C.field_0 (stride 0x20): set 0 textured, set 1 flat. */
typedef struct {
    /* 0x00 */ Stg40VSet s[2];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Stg40Vtx;

/* GPU packet tag word; byte 3 is the packet length. */
typedef union {
    u32 word;
    struct {
        u8 addr[3];
        u8 len;
    } b;
    struct {
        u32 addr : 24;
        u32 len : 8;
    } f;
} Stg40Tag;

/* POLY_FT4-shaped packet (0x28), copied whole from Stg40W667C.field_143C. */
typedef struct {
    /* 0x00 */ Stg40Tag tag;
    /* 0x04 */ u8 r0, g0, b0, code;
    /* 0x08 */ s16 x0, y0;
    /* 0x0C */ u8 u0, v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ s16 x1, y1;
    /* 0x14 */ u8 u1, v1;
    /* 0x16 */ u16 tpage;
    /* 0x18 */ s16 x2, y2;
    /* 0x1C */ u8 u2, v2;
    u16 _pad1E;
    /* 0x20 */ s16 x3, y3;
    /* 0x24 */ u8 u3, v3;
    u16 _pad26;
} Stg40FT4;

/* POLY_F4-shaped packet (0x18). */
typedef struct {
    /* 0x00 */ Stg40Tag tag;
    /* 0x04 */ u8 r0, g0, b0, code;
    /* 0x08 */ s16 x0, y0;
    /* 0x0C */ s16 x1, y1;
    /* 0x10 */ s16 x2, y2;
    /* 0x14 */ s16 x3, y3;
} Stg40F4;

/* 8-byte sprite record of a texture's table (Cd_GetFileEntry(id + 1)); u 0xFF ends it (Stg40_FloorInit). */
typedef struct {
    /* 0x0 */ u8 u;
    /* 0x1 */ u8 v;
    /* 0x2 */ u8 w;                /* width / 4 */
    /* 0x3 */ u8 h;
    /* 0x4 */ u8 cx;               /* clut x * 4 */
    /* 0x5 */ u8 cy;
    u8 _pad6[0x02];
} Stg40TexRec;

/* Actor.work of the task driven by Stg40_FloorDraw. */
typedef struct {
    /* 0x0000 */ Stg40Vtx field_0[11][11];
    /* 0x0F20 */ Stg40Tile field_F20[10][10];
    /* 0x13D0 */ s16 field_13D0;   /* columns built by Stg40_ProjectGrid */
    /* 0x13D2 */ s16 field_13D2;   /* rows */
    /* 0x13D4 */ GfxTexSlot *field_13D4[8]; /* texture slots (Stg40_FloorInit) */
    /* 0x13F4 */ Stg40TexRec *field_13F4[8]; /* sprite tables of those textures */
    /* 0x1414 */ s32 field_1414;   /* count of the three arrays above */
    /* 0x1418 */ s32 field_1418[8]; /* texture ids, -1 terminated */
    /* 0x1438 */ s32 field_1438;   /* count of field_143C */
    /* 0x143C */ Stg40FT4 field_143C[27]; /* textured tile templates; [26] is semi-transparent */
} Stg40W667C;

/* arg0 of Stg40_ObjQueueFiles: a file-queue countdown (0x28) gated by 0x34. */
typedef struct {
    u8 _pad00[0x28];
    /* 0x28 */ u8 field_28;
    u8 _pad29[0x0B];
    /* 0x34 */ s16 field_34;
} Stg40E764;

/* main exe */
extern Stg40Blk5071C *D_8005071C;

/* 13-byte const table copied to a stack local (Stg40_BeginTransition). */
typedef struct { u8 b[13]; } Blk13;
extern Blk13 D_80063384;
extern s32 Sys_GameMode;
extern s32 D_8005F794;
extern GameStateView *Save_GameStatePtr;
extern s32 Cd_PreloadIds[];
extern s32 Cd_PreloadCount;
extern s32 D_8005F704;
extern void LoadImage(RECT *rect, u32 *p);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
extern void Text_Close(s32 *);
extern s32 Text_IsFinished(s32 id);
extern s32 Text_WaitYesNo(s32 arg0);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern s32 Rand_Next(void);
extern s32 Mem_Alloc(s32 arg0, s32 arg1);
extern s32 Beetle_GetPart(s32 i);
extern s32 Item_GetLevel(s32 item); /* main defines it (void); the overlay passes an item id */
extern void Task_NextState0(Actor *arg0);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern void Gfx_DrawParts(s32);
extern s32 GsSetFlatLight(s32, Blk16 *);
extern void GsSetAmbient(s32, s32, s32);
extern void GsSetLightMode(s32);

extern void Cd_QueueFile(s32);
extern void Sys_SetFrameRate30(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Text_Open(void *, TextOpenArgs *);
extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern u16 Pad_Repeat;
extern void Snd_PlayById(s32, s32);
extern void Task_NextState2(Actor *arg0);
extern s32 Cd_GetFileOrNull(s32 arg0);
extern void Flag_SetTableFile(s32 arg0);
extern s32 Flag_FirstPassingEntry(void); /* main defines it void; its tail call leaves Flag_NextPassingEntry's result in v0 */
extern Blk12 *Flag_GetEntryPosList(); /* main defines it (void); the overlay passes the entry index */
extern s32 Flag_NextPassingEntry(void);
extern PadState Pad_State[];
extern s32 Flag_Test(s32 arg0);

/* overlay data */
extern s32 D_80072944;
extern Stg40B60 *D_80072B60;
extern Actor *Stg40_FloorTask;
extern Actor *Stg40_ItemMenuTask;
extern s32 *Stg40_MsgWinTexts;
extern Actor *Stg40_CameraTask;
extern Actor *Stg40_MsgWinTask;
extern Stg40TileGrid *Stg40_AutomapWork;
extern u8 Stg40_TrapEffectTable[];
extern s16 Stg40_TrapPartSlots[];
extern s16 Stg40_PadDirTable[];
extern u8 Stg40_TrapDisarmRanks[][6];
extern s32 Stg40_TrapDisarmChance[];
extern u8 Stg40_DigitBufs[][8];
extern s32 Stg40_StatusMsgIds[];
extern s32 D_80072BB8;
extern u8 Stg40_RandomPartSlots[];
extern u8 D_80072A58[];
extern u8 D_80072A78[];
extern u8 *memset(u8 *s, s32 c, s32 n);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern s32 Stg40_EnemyInfoParts[];
void Stg40_AutomapMoveMarker(s32 x, s32 y, s32 ox, s32 oy, s32 dir);
extern s32 Sys_PacketCursor;
extern GameStateView Save_GameState;
extern s32 Stg40_HudParts[];
extern void Gfx_FadeOutToBlack(s32 arg0);
extern s32 Item_GetNameText(s32 arg0);
extern s32 Item_AddToBag(s32 id);
extern void Item_SortList(void);
extern s32 Pad_Square;
extern s32 Digi_GetModelFile(s32 id);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
void Stg40_TurnQueueAdd(s32 a0);
Stg40Ent48 *Stg40_FindEntByDigiId(s32 id);
extern void RotMatrixYXZ(void *, Mat1F668 *);
extern Mat1F668 GsWSMATRIX;
extern void PushMatrix(void);
extern void SetRotMatrix(Mat1F668 *m);
extern void SetTransMatrix(Mat1F668 *m);
extern s32 RotTransPers(Stg40Vec3 *v, s16 *out, s32 *dtz, s32 *flag);
extern void PopMatrix(void);

/* Four ground-quad corner offsets (x, z) read by Stg40_DrawEntityShadow. */
typedef struct {
    s16 v[8];
} Stg40Quad;

extern u8 Stg40_ShadowPrimIdx;          /* tile template index into Stg40W667C.field_143C */
extern Stg40Quad D_800633C4;
extern void GsSetProjection(s32);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern s32 GsSetRefView2(Stg40RView *);
void Stg40_CamNextCommand(Actor *a0);
void Stg40_CamMoveStep(Actor *a0);
void Stg40_DamageBeetle(s32 n);
s32 Stg40_AddEntity(s32 kind, s32 a1, s32 a2, s32 a3, s32 x, s32 y); /* K&R definition (a3, x, y are s16) */
void Stg40_AutomapDrawWindow(Stg40TileWork *w, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);
u8 *Stg40_NumToDigits(s32 i, s32 v);
s32 Stg40_DrawTileTop(Stg40W667C *w, s32 pkt, s32 x, s32 y);
s32 Stg40_DrawTileWalls(Stg40W667C *w, s32 pkt, s32 x, s32 y);
s32 Stg40_PickRandomPoint(Stg40Pick *out, Stg40Rec3 *e, u8 key);

/* overlay functions */
void Stg40_ClearVisitedBits(void);
void Stg40_SyncVisitedBits(s32 arg0);
s32 Stg40_GetBeetlePart();
void Stg40_AutomapReleaseTex(Stg40ImgWork *arg0);
void Stg40_ObjSetAnim(); /* K&R definition: callers pass an int unconverted */
s32 Stg40_ObjWaitAnimOrSkip(Actor *a0);
s32 Stg40_GetPartLevel(s32 i);
void Stg40_AutomapDrawModes(ActorWork *w);
void Stg40_AllocCellGrid(void);
void Stg40_FreeCellGrid(void);
void Stg40_FillCellGrid(void);
void Stg40_LabelRooms(void);
void Stg40_ApplyFloorLayout(void);
s32 Stg40_MsgWinIsFinished(s32 i);
void Stg40_MsgWinClose(s32 i);
s32 Stg40_MsgWinCloseIfDone(s32 i);
s32 Stg40_RandPercent(void);
s32 Stg40_RandInt(s32 n);
s32 Stg40_TickStatusEffects(Actor *a0);
void Stg40_ScrollFollow(Stg40Loc *loc);
s32 Stg40_ObjAnimDone(Actor *a0);
void Stg40_MsgWinOpen(s32 a0, s32 a1, s32 a2, s32 a3);
s32 Stg40_SpawnHazard(s32 a0, s32 a1, s32 a2, s32 a3); /* K&R definition (a2, a3 are s16) */
s32 Stg40_GetRegionCells(u8 (*tbl)[2], s32 n);
s32 Stg40_CheckEncounter(void);
void Stg40_ObjSetAnimIfNew(Actor *a0, s32 a1);
void Stg40_ObjQueueFiles(Stg40E764 *a0, s32 a1, s32 a2);
s16 *Stg40_TurnQueueFind(s16 v);
s16 Stg40_TurnQueueCurrent(void);
void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);
void Stg40_SetLights(Blk16 *l, s32 r, s32 g, s32 b);
u16 Stg40_GetCellFlags(s32 x, s32 y);
void Stg40_AutomapSetCell(s32 idx, s32 row, s32 val);
void Stg40_ScrollUpdate(Actor *a0);
void Stg40_ProjectGrid(Stg40W667C *w);
void Stg40_FillTileCache(ActorWork *w);
s32 Stg40_PlayerTryMove(Stg40Ent48 *e);
s16 Stg40_TurnQueueNext(void);
void Stg40_AutomapInitTex(Stg40TileWork *w);
void Stg40_AutomapRevealAround(Stg40TileWork *w);
void Stg40_AutomapCycleClut(Stg40ImgWork *a0);
void Stg40_AutomapFlush(Stg40TileWork *a0);
s16 Stg40_AutomapInitDims(Stg40TileWork *a0);
void Stg40_AutomapRedraw(Stg40TileWork *a0);
Stg40Cell *Stg40_GetCell2(s32 x, s32 y);
void Stg40_DrawFloorTiles(Stg40W667C *w);
s32 Stg40_RelocDungFile(s32 *p);
void Stg40_RelocPtr(u32 *p, u32 n);
void Stg40_ObjStartFlash(Actor *a0, u8 a1);
void Stg40_PlayerShowMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
void Stg40_ItemMenuRefresh(void);
void Stg40_AutomapLoadClut(Stg40ImgWork *a0);
s32 Stg40_PlayerCheckTileEvent(Actor *a0);
s32 Stg40_PlayerCheckSporeBounce(Actor *a0);
s32 Stg40_PlayerCheckStepHazard(Actor *a0);
s32 Stg40_IsEntAdjacent(Stg40Ent48 *a, Stg40Ent48 *b);
void Stg40_ItemMenuSetCursor(); /* K&R definition: Stg40_ItemMenuRefresh passes ints unconverted */
s32 *Stg40_ItemMenuGetTextIds(void);
extern s32 Item_GetDescText(s32 arg0);
extern s32 Item_GetCategory(s32 id);
extern s32 ratan2(s32 y, s32 x);
extern s32 rsin(s32 a);
extern s32 rcos(s32 a);
extern u8 Stg40_GiftTakeChance[];
extern u8 Stg40_GiftPointsByLevel[];
extern void Actor_InitTransform(Actor *a0, s32 *a1, u16 a2); /* main: ContC40 * */
extern void Anim_SetModelAnim(Actor *, s32);
extern void Task_NextState1(Actor *arg0);
s32 Stg40_GetTrapDisarmRank(s32 i);
s32 Stg40_GetPartState(); /* defined (void); Stg40_PlayerChestTrapPrompt passes 7 (forwarded to Stg40_GetBeetlePart) */
s32 Stg40_MsgWinGetChoice(s32 i);
extern Stg40Model25DC Stg40_LinkedModelTable[];
extern Stg40Col D_80063438;
extern Stg40Col D_800634FC;
s32 Stg40_ListUsableItems(Stg40Shop *a);
void Stg40_GateUpdate(Actor *a0); /* void: Stg40_FixtureUpdate returns its leftover v0 through a cast */
s32 Stg40_ChestUpdate(Actor *a0);
s32 Stg40_MineUpdate(Actor *a0);
s32 Stg40_SporeUpdate(Actor *a0);
s32 Stg40_RockUpdate(Actor *a0);
s32 Stg40_BugUpdate(Actor *a0);
Stg40Ent48 *Stg40_FindObjAtSameTile(Stg40Ent48 *a0);
s32 Stg40_RollTrapDisarm(s32 i);
/* Flood-fill queue entry in Stg40_FloodFillRoom's work buffer. */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Stg40FillPt;

extern s32 Stg40_FillNeighbours[8]; /* 4 neighbour (dx, dy) pairs */

/* 4 neighbour (dx, dy) pairs as s16, copied whole to the stack by Stg40_RevealRoom. */
typedef struct {
    s16 v[8];
} Stg40Offs8;
extern Stg40Offs8 D_8006368C;

/* Ordering-table link word (24-bit next pointer, 8-bit length). */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} Stg40OTag;

/* Per-face record of Stg40_WallSides (Stg40_DrawTileWalls): corner indices and shift per side. */
typedef struct {
    /* 0x0 */ u16 field_0;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
    /* 0x5 */ u8 field_5;
    /* 0x6 */ u8 field_6;
    /* 0x7 */ u8 field_7;
    /* 0x8 */ u8 field_8;
    /* 0x9 */ u8 field_9;
} Stg40Rec10;
extern Stg40Rec10 Stg40_WallSides[];
extern u8 Stg40_WallPrimIdx[];

typedef struct {
    s16 x;
    s16 y;
} Stg40XY16;
extern Stg40XY16 Stg40_DirOffsets[];
extern Stg40Shop D_800727E8[];
extern s32 Item_CheckId(s32 arg0);
extern Stg40Ent48 *Stg40_FindEntAt(s16 x, s16 y);

/* Byte views of the status block Stg40_PlayerBugInvade indexes. */
typedef struct {
    u8 _pad000[0xB9C];
    u8 field_B9C[13];
} Stg40StatusView;
typedef struct {
    u8 _pad000[0xBA5];
    u8 field_BA5[3];
} Stg40BA5View;
/* Status flags at Stg40Blk5071C.field_BA0 and the bytes after them, through one pointer
 * (Stg40_TickStatusEffects). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 field_5;
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 field_7;
    u8 _pad08[0x0D];
    /* 0x15 */ u8 field_15;
} Stg40BA0View;
/* 14-byte, 2-aligned record copied whole (DigiRosterEntry.name -> Stg40B60.field_6A). */
typedef struct {
    /* 0x0 */ s16 field_0[7];
} Stg40Agg14;
void Stg40_FloodFillRoom(s32 buf, s32 a1, s32 x, s32 y, s32 flag);
void Stg40_LabelFilledCells(void);

/* part 36 salvage */
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern void Anim_StepModelAnim(Actor *);
void Stg40_ClearCellOccupied(s32 x, s32 y);
void Stg40_SetCellOccupied(s32 x, s32 y, s32 flag);
extern void Task_SetState2(Actor *arg0, u32 arg1);
void Stg40_ScrollStep(Actor *a0);
extern s32 Gfx_ReserveTexSlot(void);
extern u16 Stg40_AutomapClut[];
extern s32 Flag_SelectBranch(s32 arg0);
extern void Text_OpenMsgClearChoice(void *arg0, s32 arg1);

/* p36 agent d */
s32 Stg40_RollTrapEffect(void);
void Stg40_ApplyTrapEffect(s32 a0, s32 a1);
void Stg40_ShowTrapEffectMsg(s32 a0, s32 a1);

typedef struct {
    /* 0x0 */ s32 field_0;         /* text handle */
    /* 0x4 */ s32 field_4;         /* scale ramp */
    /* 0x8 */ s32 field_8;         /* shown value, follows Save_GameStatePtr->field_8 */
} Stg40W6BE4;

typedef struct {
    /* 0x0 */ s32 id;
    /* 0x4 */ Halves pos;
} Stg40TextPos;

extern Stg40TextPos Stg40_BitsLabelText;
extern Stg40TextPos Stg40_HudLabels[];

/* Actor.work of the HP/MP status task Stg40_HudUpdate. */
typedef struct {
    /* 0x00 */ s32 field_0;   /* text handle */
    /* 0x04 */ s32 field_4;   /* text handle */
    /* 0x08 */ s32 field_8;   /* text handle */
    /* 0x0C */ s32 field_C;   /* scale ramp */
    /* 0x10 */ s16 field_10;  /* part mask */
    /* 0x12 */ s16 field_12;  /* cursor x */
    /* 0x14 */ s16 field_14;  /* cursor y */
} Stg40W6720;

/* Actor.u34.children container of Stg40_HudUpdate: a child task handle at 0. */
typedef struct {
    /* 0x0 */ Actor *field_0;
} Stg40Slot34;

extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 Math_RampToOne(s32 arg0, s32 *arg1);
extern s32 Math_RampToZero(s32 arg0, s32 *arg1);
extern void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3);
extern void Text_SetOtLayer(s32 a0, s32 a1);

extern s32 Stg40_ItemMenuParts[];

extern s32 Pad_Circle; /* Pad_State[0].circle as a scalar reloc */
extern s32 D_8005F710; /* Pad_State[0].r1 as a scalar reloc */
extern s32 Pad_Select; /* Pad_State[0].select as a scalar reloc */
extern Actor *Stg40_RootTask;
s32 Stg40_PlayerInteract(Actor *a0);
s32 Stg40_PlayerCheckEnemyInfo(Actor *a0);

void Stg40_RevealRoom(Stg40TileWork *w, s32 x, s32 y);
void Stg40_RevealCell(Stg40TileWork *w, s32 x, s32 y);

s16 Stg40_ListPartyDigi(s32 mode);

s32 Stg40_AiPathChase(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathFlee(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathChaseInRoom(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathToTarget(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_DeltaToOctant(s32 dx, s32 dy);

extern s32 Stg40_ShootMsgIds[];

extern Stg40Ids5 Stg40_RandomHazardKinds;
void Stg40_SpawnHazardAtRandom(u8 (*tbl)[2], s32 a1, s32 a2);

extern SysState Sys_State;
extern void Digi_SortRoster(void);

/* Task_Create arg block of task 0x207 (Stg40_ObjUpdate). */
typedef struct {
    /* 0x0 */ Actor *field_0;
    /* 0x4 */ s16 field_4;
} Stg40Arg207;

extern void Task_Create(u32, s32 *, s32);
void Stg40_PlayerUpdate(Actor *a0);
void Stg40_EnemyUpdate(Actor *a0);
s32 Stg40_ObjStepMove(Stg40Ent48 *e);
Stg40Cell *Stg40_GetCell(s32 x, s32 y);

void Stg40_ChestQueueModel(Stg40E764 *a0, s32 a1);

/* Actor.work of the task behind Stg40_EnemyInfoTask (Stg40_EnemyInfoUpdate). */
typedef struct {
    /* 0x00 */ s32 field_0;        /* scale ramp */
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8[12];    /* text handles */
} Stg40W71F0;

extern Actor *Stg40_EnemyInfoTask;
extern u16 Stg40_EnemyInfoTextPos[];
extern u8 *Digi_GetDefaultName(s32);
extern s32 Digi_GetType(s32);
extern s32 Digi_GetRank(s32);

/* Four model ids copied from Stg40_BugModelIds (Stg40_SpawnHazard). */
typedef struct {
    s32 id[4];
} Stg40Ids4;

extern Stg40Ids4 Stg40_BugModelIds;

extern u32 *D_8005F8C0;
extern u32 *D_8005F8B4;
extern u8 Stg40_FloorPrimIdx[];

void Stg40_PlayerWaitTurn(Actor *a0);
void Stg40_PlayerMoveEnd(Actor *a0);
void Stg40_PlayerAfterAction(Actor *a0);
void Stg40_PlayerEndTurn(Actor *a0);
void Stg40_PlayerShowStatusMsgs(Actor *a0);
void Stg40_PlayerResumeAfterBattle(Actor *a0);
void Stg40_PlayerAnimThenMsgUpdate(Actor *a0);
void Stg40_PlayerWaitAnim(Actor *a0);
void Stg40_PlayerWaitMsg(Actor *a0);
void Stg40_PlayerFoundObject(Actor *a0);
void Stg40_PlayerHurtAnim(Actor *a0);
void Stg40_PlayerBugInvade(Actor *a0);
void Stg40_PlayerOpenChest(Actor *a0);
void Stg40_PlayerExitFloor(Actor *a0);
void Stg40_PlayerItemMenu(Actor *a0);
void Stg40_PlayerEnemyInfo(Actor *a0);
void Stg40_PlayerShootGift(Actor *a0);
void Stg40_PlayerRunEvent(Actor *a0);
void Stg40_PlayerMoveStep(Actor *a0);
void Stg40_PlayerDestroyMine(Actor *a0);
void Stg40_PlayerSporeDamage(Actor *a0);
void Stg40_PlayerChestTrapPrompt(Actor *a0);
void Stg40_PlayerTakeChestItem(Actor *a0);
void Stg40_PlayerBeetleDown(Actor *a0);
void Stg40_PlayerInput(Actor *a0);
void Stg40_PlayerTriggerTrap(Actor *a0);
void Stg40_PlayerShootObstacle(Actor *a0);

extern Stg40W667C *Stg40_FloorWork;

/* Object behind Stg40_RootChildren: a Task_Create slot at 0x10 (Stg40_PlayerItemMenu). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;        /* child task (Actor *) (Stg40_RootUpdate) */
    /* 0x08 */ s32 field_8;        /* child task (Actor *) (Stg40_RootUpdate) */
    u8 _pad0C[0x04];
    /* 0x10 */ s32 field_10;       /* child task (Actor *) */
    /* 0x14 */ s32 field_14;       /* child task (Actor *) (Stg40_PlayerEnemyInfo) */
} Stg40AA4;

extern Stg40AA4 *Stg40_RootChildren;
extern s32 Sys_NextGameMode;  /* Sys_State.nextGameMode as a scalar reloc */
extern u16 Stg40_FloorBitsPal[10];
extern u16 D_800729B4[6];
extern s32 D_8005F790;  /* Sys_State.prevGameMode as a scalar reloc */

/* Base levels by slot item (D_80063360, Stg40_SetupStage). */
typedef struct {
    s16 field_0[18];
} Stg40Buf24;
extern Stg40Buf24 D_80063360;
extern s32 Menu_TopMenuResult;
extern void Item_CompactBag(void);
extern void Task_SetState3(Actor *arg0, u32 arg1);
void Stg40_ScrollToFollow(Stg40Loc *loc, s32 a1);
void Stg40_ItemMenuMoveCursor(void);

/* p36 agent g */
extern void Enemy_GetSetSummary(void *a0, Out1DB68 *out);
extern u8 Stg40_EnemyAiTable[];
extern u8 Stg40_EnemyPaceTable[];
s32 Stg40_IsScrollDone(void);
extern Stg40Shop Stg40_GiftGunReq;
void Stg40_DrawEntityShadow(Stg40Loc *loc);
void Stg40_SetModelTint(Actor *a0, u8 on, u8 r, u8 g, u8 b);
extern u8 Stg40_FlashPattern[];
extern Stg40Col Stg40_FlashColors[];
s32 Stg40_PickRandomPart(void);
void Beetle_SetPartBroken(s32 i, s32 v);
extern s32 Digi_CountByState(s32 mode);
extern u8 Beetle_GetDigiCapacity(void);

#endif
