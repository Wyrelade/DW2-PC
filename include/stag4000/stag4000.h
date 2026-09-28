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
    /* 0x0D */ u8 field_D;      /* count of field_E bytes (func_80070DC0) */
    /* 0x0E */ u8 field_E[16];
    u8 _pad1E[0x02];
} Stg40E34;

typedef struct {
    /* 0x00 */ s16 field_0[11];
    /* 0x16 */ s16 field_16;       /* count used by func_80070C48 */
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;       /* index into field_0 */
} Stg40FFC;

/* Map position block inside Stg40Ent48 (at 0x18); the x/y pair is also compared as one word
 * (func_800689E0). Passed to func_80065134 / func_800651C0. */
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
    u8 _pad14[0x08];
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ u16 field_1E;
} Stg40Loc;

/* Element of Stg40Blk5071C.field_18 (stride 0x48, 41 entries; func_8006E278). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    u8 _pad06[0x01];
    /* 0x07 */ u8 field_7;
    /* 0x08 */ u8 field_8;         /* kind, switched on by func_8006D418 */
    u8 _pad09[0x01];
    /* 0x0A */ u8 field_A;
    u8 _pad0B[0x03];
    /* 0x0E */ u16 field_E;
    /* 0x10 */ u8 *field_10;
    /* 0x14 */ Actor *field_14;
    /* 0x18 */ Stg40Loc field_18;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x04];
    /* 0x40 */ s32 field_40;
    u8 _pad44[0x04];
} Stg40Ent48;

/* x, y, value byte triple (Stg40Blk5071C.field_D08; func_800709DC, func_80070FEC). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
} Stg40Rec3;

/* Output pair written by func_80070FEC. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Stg40Pick;

/* 4-byte record of Stg40MapRoom.field_8 (func_8006DA18): cell x, y, four 1-based picks into Stg40Map.field_34. */
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

/* 8-byte spawn record (func_8006DDDC): cell x, y, then four (kind, offset) nibble pairs. */
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

/* Element picked from Stg40Map.field_8 into Stg40B60.field_14 (func_8007107C). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ Stg40Rec3 *field_4;  /* 0xFF-terminated, passed to func_80070FEC */
    /* 0x08 */ Stg40Drop *field_8;  /* 0xFF-terminated (func_8006DA18) */
    /* 0x0C */ Stg40Spawn *field_C; /* 0xFF-terminated (func_8006DDDC) */
} Stg40MapRoom;

/* Stg40Ent48.field_10 viewed as the info block func_80067454 draws. */
typedef struct {
    u8 _pad00[0x0B];
    /* 0x0B */ u8 field_B;          /* count of used field_16 entries */
    u8 _pad0C[0x0A];
    /* 0x16 */ s16 field_16[3];
} Stg40SlotInfo;

/* Stg40MapRoom / Stg40Map as file offsets before func_80070EE0 relocates them. */
typedef struct {
    /* 0x00 */ u32 field_0[5];
} Stg40MapRoomRel;

typedef struct {
    /* 0x00 */ u32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ u32 field_8[8];
} Stg40MapRel;

/* Actor.work of the draw task func_80066AD0. */
typedef struct {
    u8 _pad00[0x0C];
    /* 0x0C */ s32 field_C;        /* scale; 0 = hidden */
    /* 0x10 */ s16 field_10;       /* part mask */
    /* 0x12 */ s16 field_12;
    /* 0x14 */ s16 field_14;
} Stg40W6AD0;

/* Map header behind Stg40B60.field_10 (func_80070DC0). */
typedef struct {
    /* 0x00 */ u8 *field_0;       /* 0xFF-terminated byte list */
    u8 _pad04[0x04];
    /* 0x08 */ Stg40MapRoom *field_8[8];
    /* 0x28 */ u16 field_28;
    u8 _pad2A[0x04];
    /* 0x2E */ u8 field_2E;
    u8 _pad2F[0x05];
    /* 0x34 */ Stg40MapPos field_34[15];
} Stg40Map;

/* Entries collected by func_8006E330 (Stg40Blk5071C.field_1018). */
typedef struct {
    /* 0x00 */ Stg40Ent48 *field_0[8];
    /* 0x20 */ s16 field_20;       /* count */
} Stg40List;

/* Element of the grid behind Stg40Blk5071C.field_E58 (field_E54 dims; func_800703E0). */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u8 field_2;
    u8 _pad03[0x01];
} Stg40Cell;

typedef struct {
    u8 _pad000[0x01];
    /* 0x001 */ u8 field_1;
    /* 0x002 */ u8 field_2;
    /* 0x003 */ u8 field_3;
    /* 0x004 */ u8 field_4;
    u8 _pad005[0x02];
    /* 0x007 */ u8 field_7;
    u8 _pad008[0x04];
    /* 0x00C */ s16 field_C;       /* count of live field_18 entries (func_800689E0) */
    u8 _pad00E[0x02];
    /* 0x010 */ s16 field_10;      /* count of field_CCE pairs (func_8006DA18) */
    u8 _pad012[0x02];
    /* 0x014 */ s16 field_14;      /* count of live field_D08 entries (func_800709DC) */
    u8 _pad016[0x02];
    /* 0x018 */ Stg40Ent48 field_18[41];
    u8 _padBA0[0xCCE - 0xBA0];
    /* 0xCCE */ u8 field_CCE[12][2];
    u8 _padCE6[0xD08 - 0xCE6];
    /* 0xD08 */ Stg40Rec3 field_D08[100];
    /* 0xE34 */ Stg40E34 field_E34;
    /* 0xE54 */ Stg40E34 *field_E54;
    /* 0xE58 */ ActorWork *field_E58;
    /* 0xE5C */ s32 field_E5C[8];
    /* 0xE7C */ u8 field_E7C[0x180];
    /* 0xFFC */ Stg40FFC field_FFC;
    /* 0x1018 */ Stg40List field_1018;
    u8 _pad103C[0x1C];
    /* 0x1058 */ s16 field_1058;
    u8 _pad105A[0x0A];
    /* 0x1064 */ Stg40Loc *field_1064;
    /* 0x1068 */ Stg40Loc *field_1068;
} Stg40Blk5071C;

/* Work of the task behind D_80072B70 (init func_80066E30). */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x18];
    /* 0x44 */ u8 field_44;
    /* 0x45 */ u8 field_45;
    /* 0x46 */ u8 field_46;
} Stg40ObjWork;

/* Init args of func_80064970. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u16 field_4;
} Stg40InitArg;

/* Element of D_800725DC (func_8006498C): model id and an animation flag. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Stg40Model25DC;

/* Work of the task initialised by func_80064970. */
typedef struct {
    /* 0x00 */ s32 field_0;        /* model id */
    /* 0x04 */ s32 field_4[3];     /* position (Actor_InitTransform) */
    /* 0x10 */ s32 field_10;       /* rotation, read as u16 */
    /* 0x14 */ s32 field_14;       /* model file */
    /* 0x18 */ s32 field_18;       /* anim file */
    u8 _pad1C[0x04];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u16 field_24;       /* index into D_800725DC */
    u8 _pad26[0x02];
    /* 0x28 */ s32 field_28;
} Stg40InitWork;

/* Actor.work of the objects driven by func_80067880 / func_8006E4DC. */
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
    /* 0x36 */ s16 field_36;
} Stg40ActWork;

/* 0x90-byte transform block behind Actor.u38 (copied whole by func_80064AFC). */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s32 field_34;
    u8 _pad38[0x08];
    /* 0x40 */ s16 field_40;
    /* 0x42 */ s16 field_42;
    /* 0x44 */ s16 field_44;
    u8 _pad46[0x4A];
} Stg40Xform;

/* Work of the child object drawn by func_80064AFC. */
typedef struct {
    u8 _pad00[0x14];
    /* 0x14 */ s32 field_14;       /* model file */
    u8 _pad18[0x08];
    /* 0x20 */ Actor *field_20;    /* parent */
    u8 _pad24[0x04];
    /* 0x28 */ s32 field_28;
} Stg40ChildWork;

/* Actor.model viewed with the bytes func_80067894 sets. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    u8 _pad36[0x02];
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg40ModelView;

/* 4-byte colour (copied whole from D_80063438 by func_8006A9CC). */
typedef struct {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 x;
} Stg40Col;

/* Actor.model viewed with the fade fields func_8006A9CC sets. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ Stg40Col field_38;
} Stg40ModelFade;

/* Image work: pixel data, its VRAM rect, a texture slot (func_8006F168 / func_8006F38C). */
typedef struct {
    /* 0x000 */ u32 data[0x748 / 4];
    /* 0x748 */ RECT rect;
    u8 _pad750[0x08];
    /* 0x758 */ s32 *field_758;
    /* 0x75C */ s32 field_75C;
} Stg40ImgWork;

/* Stg40ImgWork viewed with the 16-colour CLUT func_8006F1C8 animates at 0x14. */
typedef struct {
    u8 _pad000[0x14];
    /* 0x014 */ u16 clut[8];
    u8 _pad024[0x75C - 0x24];
    /* 0x75C */ s32 field_75C;     /* frame counter */
} Stg40ImgClut;

/* Stg40TileWork viewed as 4bpp pixels, 18 halfwords per row (func_8006EB84). */
typedef struct {
    u8 _pad000[0x40];
    /* 0x040 */ u16 pix[50 * 18];
    u8 _pad748[0x18];
    /* 0x760 */ s16 field_760;
} Stg40TileGrid;

/* Tile image work: pixel data at 0x40, its VRAM rect, a dirty flag (func_8006F18C / func_8006F3B0). */
typedef struct {
    u8 _pad000[0x40];
    /* 0x040 */ u32 data[(0x750 - 0x40) / 4];
    /* 0x750 */ RECT rect;
    u8 _pad758[0x08];
    /* 0x760 */ s16 field_760;
    /* 0x762 */ s16 field_762[2];
    /* 0x766 */ s16 field_766;
    /* 0x768 */ s16 field_768;
    /* 0x76A */ s16 field_76A;
} Stg40TileWork;

/* Element of Stg40B60.field_144 (stride 8, 5 entries; func_8006E6CC). */
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
    /* 0x00C */ s32 *field_C;      /* Cd_GetFileOrNull table (func_80070CC0) */
    /* 0x010 */ s32 field_10;      /* Stg40Map * (func_80070DC0) */
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
    u8 _pad054[0x04];
    /* 0x058 */ s32 field_58;
    u8 _pad05C[0x04];
    /* 0x060 */ u8 field_60[8];    /* stack indexed by field_68 (func_800690CC) */
    /* 0x068 */ s16 field_68;
    /* 0x06A */ u8 field_6A[0x0E];
    /* 0x078 */ s32 field_78;
    u8 _pad07C[0x02];
    /* 0x07E */ s16 field_7E;
    /* 0x080 */ Stg40Ent48 *field_80[10]; /* matching entries (func_800681BC) */
    /* 0x0A8 */ s32 field_A8;      /* count of field_80 */
    /* 0x0AC */ s32 field_AC;      /* index into field_80 */
    /* 0x0B0 */ u8 field_B0[0x31]; /* item ids listed by func_8006AD10 */
    /* 0x0E1 */ u8 field_E1;
    /* 0x0E2 */ u8 field_E2;       /* cursor, 0..field_E1-1 (func_8006AE74) */
    /* 0x0E3 */ u8 field_E3;       /* first visible row (func_8006AD10) */
    /* 0x0E4 */ u8 field_E4;
    u8 _pad0E5[0x43];
    /* 0x128 */ s16 field_128[12]; /* roster indices picked by func_8006EA84 */
    /* 0x140 */ s16 field_140;
    u8 _pad142[0x02];
    /* 0x144 */ Stg40B60Ent field_144[5];
    /* 0x16C */ u32 field_16C;
    /* 0x170 */ s32 field_170;
    /* 0x174 */ s32 field_174;     /* text handle (func_8006B320) */
    /* 0x178 */ s32 field_178;
    /* 0x17C */ Pair54 field_17C;  /* target cell (func_8006B8C8) */
    /* 0x180 */ s16 field_180;
    u8 _pad182[0x02];
    /* 0x184 */ Actor *field_184;
} Stg40B60;

/* Argument of func_8006E920: an event id, up to 4 item-category keys (-1 = unused), a result base. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2[4];
    u8 _padA[0x02];
    /* 0xC */ s32 field_C;
} Stg40Shop;

/* Work of the task behind D_80072B68. */
typedef struct {
    u8 _pad0000[0x1E90];
    /* 0x1E90 */ s32 field_1E90;
    /* 0x1E94 */ s32 field_1E94;
    /* 0x1E98 */ s32 field_1E98;
    /* 0x1E9C */ s32 field_1E9C;
    /* 0x1EA0 */ s32 field_1EA0;
} Stg40B68Work;

/* 0x20-byte block copied by func_8007212C. */
typedef struct {
    s32 words[8];
} Stg40Blk20;

/* Command record walked by func_80072250 (stride 0x2C). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ Stg40Blk20 field_C;
} Stg40Cmd;

/* GsRVIEW2-shaped view passed to GsSetRefView2 (func_80072468). */
typedef struct {
    /* 0x00 */ s32 field_0[6];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 *field_1C;
} Stg40RView;

/* Work of the task initialised by func_80072418 (D_80072BC0). */
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
    /* 0xBC */ Stg40Cmd field_BC[1]; /* filled by func_800721A8 up to a zero field_0 record; count unknown */
} Stg40BC0Work;

/* Three halfwords written by func_80065BF8 (SVECTOR-like). */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
    /* 0x4 */ s16 field_4;
} Stg40Vec3;

/* Three words at Cd_GetFileEntry(0xE200002): ambient r, g, b (func_80063758). */
typedef struct {
    /* 0x0 */ s32 r;
    /* 0x4 */ s32 g;
    /* 0x8 */ s32 b;
} Stg40Rgb;

/* Element of Stg40W667C.field_F20 (stride 0xC; func_8006620C / func_80065F94). */
typedef struct {
    /* 0x0 */ u16 field_0;
    u8 _pad2[0x0A];
} Stg40Tile;

/* Actor.work of the task driven by func_8006667C. */
typedef struct {
    u8 _pad0000[0xF20];
    /* 0x0F20 */ Stg40Tile field_F20[10][10];
    u8 _pad13D0[0x1418 - 0x13D0];
    /* 0x1418 */ s32 field_1418[1]; /* texture ids, -1 terminated */
} Stg40W667C;

/* arg0 of func_8006E764: a file-queue countdown (0x28) gated by 0x34. */
typedef struct {
    u8 _pad00[0x28];
    /* 0x28 */ u8 field_28;
    u8 _pad29[0x0B];
    /* 0x34 */ s16 field_34;
} Stg40E764;

/* main exe */
extern Stg40Blk5071C *D_8005071C;
extern GameStateView *D_80050720;
extern s32 D_80050948[];
extern s32 D_8005075C;
extern s32 D_8005F704;
extern void LoadImage(RECT *rect, u32 *p);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
extern void Text_Close(s32 *);
extern s32 Text_IsFinished(s32 id);
extern s32 func_800136A4(s32 arg0);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern s32 Rand_Next(void);
extern s32 Mem_Alloc(s32 arg0, s32 arg1);
extern s32 func_80022518(s32 i);
extern s32 func_8001E0E4(s32 item); /* main defines it (void); the overlay passes an item id */
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
extern u16 D_8005F72C;
extern void Snd_PlayById(s32, s32);
extern void Task_NextState2(Actor *arg0);
extern s32 Cd_GetFileOrNull(s32 arg0);
extern void func_8001E28C(s32 arg0);
extern s32 func_8001E480(void); /* main defines it void; its tail call leaves Flag_NextPassingEntry's result in v0 */
extern Blk12 *func_8001E5E8(); /* main defines it (void); the overlay passes the entry index */
extern s32 Flag_NextPassingEntry(void);
extern PadState D_8005F6F0[];
extern s32 Flag_Test(s32 arg0);

/* overlay data */
extern s32 D_80072944;
extern Stg40B60 *D_80072B60;
extern Actor *D_80072B68;
extern Actor *D_80072B70;
extern s32 *D_80072B84;
extern Actor *D_80072BC0;
extern Actor *D_80072B80;
extern Stg40TileGrid *D_80072BB0;
extern u8 D_80072A30[];
extern s16 D_800729E0[];
extern s16 D_800728D4[];
extern u8 D_800729F8[][6];
extern s32 D_80072A1C[];
extern u8 D_80072B90[][8];
extern s32 D_80072868[];
extern s32 D_80072BB8;
extern u8 D_80072A4C[];
extern u8 *memset(u8 *s, s32 c, s32 n);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern s32 D_80072750[];
void func_8006EBF4(s32 x, s32 y, s32 ox, s32 oy, s32 dir);
extern s32 D_8005F79C;
extern GameStateView D_8005E620;
extern s32 D_800726C0[];
extern void Gfx_FadeOutToBlack(s32 arg0);
extern s32 Item_GetNameText(s32 arg0);
extern s32 Item_AddToBag(s32 id);
extern void Item_SortList(void);
extern s32 D_8005F708;
extern s32 Digi_GetModelFile(s32 id);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
void func_80070B2C(s32 a0);
Stg40Ent48 *func_80071F50(s32 id);
extern void RotMatrixYXZ(void *, Mat1F668 *);
extern void GsSetProjection(s32);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern s32 GsSetRefView2(Stg40RView *);
void func_80072250(Actor *a0);
void func_800722B8(Actor *a0);
void func_8006E8F4(s32 n);
s32 func_8006D4E0(s32 kind, s32 a1, s32 a2, s32 a3, s32 x, s32 y);
void func_8006F86C(Stg40TileWork *w, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);
u8 *func_8006755C(s32 i, s32 v);
s32 func_80065F94(Stg40W667C *w, s32 pkt, s32 x, s32 y);
s32 func_80065C50(Stg40W667C *w, s32 pkt, s32 x, s32 y);
s32 func_80070FEC(Stg40Pick *out, Stg40Rec3 *e, u8 key);

/* overlay functions */
void func_8006ED5C(void);
void func_8006ED88(s32 arg0);
s32 func_8006E820();
void func_8006F38C(Stg40ImgWork *arg0);
void func_8006E4DC(); /* K&R definition: callers pass an int unconverted */
s32 func_8006E588(Actor *a0);
s32 func_8006E858(s32 i);
void func_8006FC54(ActorWork *w);
void func_8006FED4(void);
void func_8006FF28(void);
void func_8006FFCC(void);
void func_800707D0(void);
void func_80070DC0(void);
s32 func_800676D0(s32 i);
void func_800676A4(s32 i);
s32 func_80067704(s32 i);
s32 func_80071180(void);
s32 func_800711C4(s32 n);
s32 func_800716EC(Actor *a0);
void func_80065134(Stg40Loc *loc);
s32 func_800678C4(Actor *a0);
void func_80067610(s32 a0, s32 a1, s32 a2, s32 a3);
void func_8006DB68(s32 a0, s32 a1, s32 a2, s32 a3);
s32 func_8006DEF0(u8 (*tbl)[2], s32 n);
s32 func_8006E330(void);
void func_8006E4E8(Actor *a0, s32 a1);
void func_8006E764(Stg40E764 *a0, s32 a1, s32 a2);
s16 *func_80070AD0(s16 v);
s16 func_80070C94(void);
void func_8007212C(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);
void func_800677FC(Blk16 *l, s32 r, s32 g, s32 b);
u16 func_800703E0(s32 x, s32 y);
void func_8006EB84(s32 idx, s32 row, s32 val);
void func_80065300(Actor *a0);
void func_8006545C(ActorWork *w);
void func_80065890(ActorWork *w);
s32 func_80068604(Stg40Ent48 *e);
s16 func_80070C48(void);
void func_8006F290(Stg40TileWork *w);
void func_8006F6BC(Stg40TileWork *w);
void func_8006F1C8(Stg40ImgWork *a0);
void func_8006F18C(Stg40TileWork *a0);
s16 func_8006F3B0(Stg40TileWork *a0);
void func_8006ECD0(Stg40TileWork *a0);
Stg40Cell *func_800708A4(s32 x, s32 y);
void func_8006620C(Stg40W667C *w);
s32 func_80070EE0(s32 *p);
void func_80070EC0(u32 *p, u32 n);
void func_80067880(Actor *a0, u8 a1);
void func_8006813C(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
void func_8006AD10(void);
void func_8006F168(Stg40ImgWork *a0);
s32 func_80068B8C(Actor *a0);
s32 func_80068C60(Actor *a0);
s32 func_80068A54(Actor *a0);
s32 func_8006E2B8(Stg40Ent48 *a, Stg40Ent48 *b);
void func_80066DF0(); /* K&R definition: func_8006AD10 passes ints unconverted */
s32 *func_80066E18(void);
extern s32 Item_GetDescText(s32 arg0);
extern s32 func_8001E0C0(s32 id);
extern void Actor_InitTransform(Actor *a0, s32 *a1, u16 a2); /* main: ContC40 * */
extern void Anim_SetModelAnim(Actor *, s32);
extern void Task_NextState1(Actor *arg0);
s32 func_80071204(s32 i);
s32 func_800715DC(); /* defined (void); func_8006A498 passes 7 (forwarded to func_8006E820) */
s32 func_80067750(s32 i);
extern Stg40Model25DC D_800725DC[];
extern Stg40Col D_80063438;
s32 func_8006E920(Stg40Shop *a);
void func_8006C6C4(Actor *a0); /* void: func_8006D418 returns its leftover v0 through a cast */
s32 func_8006C84C(Actor *a0);
s32 func_8006CAD4(Actor *a0);
s32 func_8006CD1C(Actor *a0);
s32 func_8006CF54(Actor *a0);
s32 func_8006D0E8(Actor *a0);
Stg40Ent48 *func_800689E0(Stg40Ent48 *a0);
s32 func_80071258(s32 i);
void func_80070490(s32 buf, s32 a1, s32 x, s32 y, s32 flag);
void func_80070754(void);

/* part 36 salvage */
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern void Anim_StepModelAnim(Actor *);
void func_80070974(s32 x, s32 y);
void func_800708FC(s32 x, s32 y, s32 flag);
extern void Task_SetState2(Actor *arg0, u32 arg1);
void func_80065278(Actor *a0);
extern s32 *Gfx_ReserveTexSlot(void);
extern u16 D_80072948[];
extern s32 Flag_SelectBranch(s32 arg0);
extern void func_8001C038(void *arg0, s32 arg1);

#endif
