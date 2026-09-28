#ifndef STAG4000_H
#define STAG4000_H

#include "common.h"
#include "main/156C.h"

/* STAG4000 (Ovl_FileIds id 1, gameMode 0x2xx). */

/* View of *D_8005071C (main Blk5071C) as this overlay uses it. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
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
    u8 _pad04[0x08];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg40Loc;

/* Element of Stg40Blk5071C.field_18 (stride 0x48, 41 entries; func_8006E278). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    u8 _pad06[0x01];
    /* 0x07 */ u8 field_7;
    u8 _pad08[0x10];
    /* 0x18 */ Stg40Loc field_18;
    u8 _pad2C[0x1C];
} Stg40Ent48;

/* Element of the grid behind Stg40Blk5071C.field_E58 (field_E54 dims; func_800703E0). */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u8 field_2;
    u8 _pad03[0x01];
} Stg40Cell;

typedef struct {
    u8 _pad000[0x04];
    /* 0x004 */ u8 field_4;
    u8 _pad005[0x07];
    /* 0x00C */ s16 field_C;       /* count of live field_18 entries (func_800689E0) */
    u8 _pad00E[0x0A];
    /* 0x018 */ Stg40Ent48 field_18[41];
    u8 _padBA0[0xE34 - 0xBA0];
    /* 0xE34 */ Stg40E34 field_E34;
    u8 _padE38[0x1C];
    /* 0xE54 */ Stg40E34 *field_E54;
    /* 0xE58 */ ActorWork *field_E58;
    /* 0xE5C */ s32 field_E5C[8];
    /* 0xE7C */ u8 field_E7C[0x180];
    /* 0xFFC */ Stg40FFC field_FFC;
    u8 _pad1018[0x4C];
    /* 0x1064 */ Stg40Loc *field_1064;
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

/* Work of the task initialised by func_80064970. */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u16 field_24;
} Stg40InitWork;

/* Actor.work of the objects driven by func_80067880 / func_8006E4DC. */
typedef struct {
    u8 _pad00[0x26];
    /* 0x26 */ u8 field_26;
    /* 0x27 */ u8 field_27;
    u8 _pad28[0x04];
    /* 0x2C */ Stg40Ent48 *field_2C;
    /* 0x30 */ s16 field_30;
    /* 0x32 */ s16 field_32;
} Stg40ActWork;

/* Actor.model viewed with the bytes func_80067894 sets. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    u8 _pad36[0x02];
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg40ModelView;

/* Image work: pixel data, its VRAM rect, a texture slot (func_8006F168 / func_8006F38C). */
typedef struct {
    /* 0x000 */ u32 data[0x748 / 4];
    /* 0x748 */ RECT rect;
    u8 _pad750[0x08];
    /* 0x758 */ s32 *field_758;
} Stg40ImgWork;

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
    u8 _pad762[0x04];
    /* 0x766 */ s16 field_766;
    /* 0x768 */ s16 field_768;
    /* 0x76A */ s16 field_76A;
} Stg40TileWork;

typedef struct {
    /* 0x000 */ s32 field_0;
    u8 _pad004[0x28];
    /* 0x02C */ s32 field_2C;
    /* 0x030 */ s32 field_30;
    /* 0x034 */ s32 field_34;
    /* 0x038 */ s32 field_38;
    u8 _pad03C[0x08];
    /* 0x044 */ s32 field_44;
    /* 0x048 */ s32 field_48;
    /* 0x04C */ s32 field_4C;
    u8 _pad050[0x2E];
    /* 0x07E */ s16 field_7E;
    u8 _pad080[0x100];
    /* 0x180 */ s16 field_180;
} Stg40B60;

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

/* Work of the task initialised by func_80072418 (D_80072BC0). */
typedef struct {
    /* 0x00 */ Block1C field_0;
    u8 _pad1C[0x6C];
    /* 0x88 */ Stg40Blk20 field_88;
    /* 0xA8 */ s32 field_A8;
    /* 0xAC */ s32 field_AC;
    /* 0xB0 */ s32 field_B0;
    /* 0xB4 */ Stg40Cmd *field_B4;
    /* 0xB8 */ s32 field_B8;
} Stg40BC0Work;

/* Three halfwords written by func_80065BF8 (SVECTOR-like). */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
    /* 0x4 */ s16 field_4;
} Stg40Vec3;

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
void func_8006E764(s32 a0, s32 a1, s32 a2);
s16 *func_80070AD0(s16 v);
s16 func_80070C94(void);
void func_8007212C(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);

#endif
