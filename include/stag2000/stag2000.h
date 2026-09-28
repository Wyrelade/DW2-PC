#ifndef STAG2000_H
#define STAG2000_H

#include "common.h"
#include "main/156C.h"

/* STAG2000 (Ovl_FileIds id 2, gameMode 0x3xx). */

/* Work whose first word is set by func_80063CD0 / func_80063760 / func_8006A248. */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg20Work;

/* Work of task 0x30D (func_80068CF8 closes it with Text_Close, func_80068E6C reads 0x1C). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    u8 _pad08[0x10];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Stg20TextWork;

/* Three words copied into a task work by func_8006B840. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg20Vec3;

/* Model task work (func_8006A9F8, func_8006AA0C). */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ s32 anim;
    u8 _pad30[0x44];
    /* 0x74 */ s32 field_74;
} Stg20ModelWork;

/* Actor viewed with the word at 0x04 (func_8006AA0C reads it before the work). */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 field_4;
    u8 _pad08[0x24];
    /* 0x2C */ Stg20ModelWork *work;
} Stg20ModelTask;

/* Work holding a 0x43-entry s16 list at 0x60 (func_8006D484, func_8006D4BC). */
typedef struct {
    u8 _pad00[0x60];
    /* 0x60 */ s16 field_60[0x43];
} Stg20ListWork;

/* Actor.u38.ptr38 viewed with the s16 at 0x42 (func_8006AD6C). */
typedef struct {
    u8 _pad00[0x42];
    /* 0x42 */ s16 field_42;
    u8 _pad44[0x40];
    /* 0x84 */ Stg20Vec3 field_84;
} Stg20Rot;

/* Map position: two s16 indices into D_80070768 (func_800636A8). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg20Cell;

/* D_8005E620 viewed with the u16 list at 0x2C scanned by func_8006C18C. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ u16 field_24;
    /* 0x26 */ u16 field_26;
    /* 0x28 */ u16 field_28;
    /* 0x2A */ u16 field_2A;
    /* 0x2C */ u16 field_2C[0x13];
    /* 0x52 */ u8 field_52[0x14];
    /* 0x66 */ u16 field_66[0x30];
    u8 _padC6[0xD0E];
    /* 0xDD4 */ u16 field_DD4[1];
} Stg20GameState;

/* overlay data */
extern s16 D_800703D8[4];
extern u8 D_80070768[24][24];

/* main exe */
extern GameState D_8005E620;
extern s32 D_8005E628;             /* D_8005E620.field_8 as a scalar reloc */
extern void Task_DefaultDestroy(Actor *);
extern void Task_NextState0(Actor *);
extern TaskEntry *Task_FindFirst(s32, s32, s32);
extern void Text_Close(s32 *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 CdControlF(s32, s32);
extern void Gfx_DrawParts(s32);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

/* overlay */
extern void func_80063610(Actor *);

/* ---- added by p35 agent o ---- */
extern u8 D_8007012C[3][3];
extern u16 D_8006FCCC[];
extern u16 D_8006FD28[];
extern s32 D_800709B4;
extern Stg20Cell D_800709A8;
extern Stg20Cell D_8006FF34[4];
extern Stg20Vec3 D_8006FF1C[];
extern CVECTOR D_80063584;
extern Halves D_80063564;
extern s32 D_80043704[];

extern void Task_SetState1(Actor *arg0, u32 arg1);
extern TaskEntry *Task_FindNext(void);
extern s32 func_8001D934(s32);
extern s32 func_8001EDD4(s32);
extern void Digi_SortRoster(void);
extern void Anim_StepModelAnim(Actor *);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3);
extern void Actor_InitTransform(Actor *, s32 *, s32);
extern void Gfx_ResetModelBones(Actor *);

extern s32 func_800636A8(Stg20Cell *c);
extern Stg20Cell *func_80067504(Actor *a);
extern Stg20Cell *func_80067714(Actor *a, s32 dir);

/* Text work with records (func_80068134). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x14];
} Stg20TextRec; /* size 0x18 */

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 index;
    u8 _pad0C[0x04];
    /* 0x10 */ Stg20TextRec recs[1];
} Stg20PickWork;

/* Model draw work (func_8006A6DC). */
typedef struct {
    u8 _pad00[0x18];
    /* 0x18 */ s32 modelId;
    u8 _pad1C[0x10];
    /* 0x2C */ s32 visible;
} Stg20DrawWork;

/* Work with a direction flag word at 0x24 (func_8006AD14). */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s32 field_24;
} Stg20FlagWork;

/* GsSetRefView2 block + coordinate at the head of a camera work (func_8006FBF0). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 *field_1C;
} Stg20RefView;

typedef struct {
    /* 0x00 */ Stg20RefView view;
    /* 0x20 */ Coord1F668 coord;
    /* 0x70 */ s32 proj;
    /* 0x74 */ s32 tx;
    /* 0x78 */ s32 ty;
    /* 0x7C */ s32 tz;
    u8 _pad80[0x04];
    /* 0x84 */ s16 rot[3];
} Stg20CamWork;

extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg20RefView *);

/* Work of the cursor/marker task (func_8006AD8C). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    u8 _pad0C[0x0C];
    /* 0x18 */ s32 field_18;
    u8 _pad1C[0x40];
    /* 0x5C */ s32 field_5C;
    u8 _pad60[0x14];
    /* 0x74 */ s32 field_74;
} Stg20CursorWork;

/* 0x28-stride parts record viewed with the byte at 0x0E (func_80068C84). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x0A];
    /* 0x0E */ u8 field_E;
    u8 _pad0F[0x19];
} Stg20Part; /* size 0x28 */

/* Model work (func_8006B7C8). */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s32 modelId;
    u8 _pad24[0x40];
    /* 0x64 */ s32 visible;
} Stg20Draw2Work;

/* 0xC-stride slot record at 0x48 of the roster menu work (func_800685C4). */
typedef struct {
    /* 0x00 */ s32 used;
    /* 0x04 */ s32 enabled;
    /* 0x08 */ s32 slot;
} Stg20Slot;

typedef struct {
    u8 _pad00[0x48];
    /* 0x48 */ Stg20Slot slots[4];
} Stg20SlotWork;

typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x08];
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x08];
    /* 0x20 */ s32 field_20;
    u8 _pad24[0x10];
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x14];
    /* 0x50 */ s32 field_50;
} Stg20MenuState;

/* 0x18-byte record of file 0xD28xxxx (func_8006F360). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    u8 _pad08[0x0B];
    /* 0x13 */ u8 field_13;
    u8 _pad14[0x04];
} Stg20FileRec; /* size 0x18 */

/* Five map cells with their countdown timers (func_800678A8). */
typedef struct {
    /* 0x00 */ Stg20Cell cell[5];
    /* 0x14 */ s32 timer[5];
} Stg20Marks;

/* Text_Open parameter block with a 4-byte copied position (func_80067480). */
typedef struct {
    /* 0x00 */ s32 bigFont;
    /* 0x04 */ s32 color;
    /* 0x08 */ Stg20Cell pos;
    /* 0x0C */ s32 charAdvance;
    /* 0x10 */ s32 lineAdvance;
    /* 0x14 */ s32 text;
    /* 0x18 */ s32 charDelay;
    /* 0x1C */ s32 strArg0;
    /* 0x20 */ s32 strArg1;
    u8 _pad24[0x8];
} Stg20TextArgs;

extern Halves D_80063588;
extern Stg20MenuState D_800709B0;
extern s32 D_8005F788[];
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3);
extern s32 Actor_ProjectToScreen(Actor *);
extern s32 Cd_GetFileOrNull(s32 arg0);
extern void Item_SortList(void);
extern void Text_Open(void *, Stg20TextArgs *);
extern void func_800636D8(Stg20Cell *c, s32 set, s32 flag);

/* ---- added by p35 agent v ---- */
/* D_8005F788 (game mode word) viewed as its low byte (func_80066714). */
typedef struct {
    /* 0x00 */ u8 lo;
} Stg20Mode;

/* Map file 0x309xxxx header; offsets relocated by the file base on first use (func_80066714). */
typedef struct {
    /* 0x00 */ s32 loaded;
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ u8 *bits;
    u8 _pad14[0x04];
    /* 0x18 */ s32 field_18;
} Stg20MapFile;

/* Work of task 0x30D viewed with the 14-byte name at 0x08 (func_80068DD8). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u8 name[0x0E];
    u8 _pad16[0x02];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Stg20NameWork;

extern Stg20MapFile *func_80066714(void);
/* Actor viewed with the word at 0x24 (func_80068364). */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ u32 field_24;
    u8 _pad28[0x04];
    /* 0x2C */ Stg20Work *work;
} Stg20BlinkTask;

/* Spawn record (func_8006AA4C). */
typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 field_1C;
} Stg20Spawn;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 field_1C;
    u8 _pad20[0x44];
    /* 0x64 */ s32 visible;
} Stg20SpawnWork;

/* Four words at 0x30 of Actor.u38.ptr38 copied as one block (func_8006A254). */
typedef struct {
    /* 0x00 */ s32 v[4];
} Stg20Pos4;

typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ Stg20Pos4 pos;
} Stg20PosView;

/* Work whose first word links to another actor (func_8006A254). */
typedef struct {
    /* 0x00 */ Actor *target;
} Stg20LinkWork;

/* Work with a row index at 0x30 (func_8006F28C). */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
} Stg20RowWork;

/* Map position as two words (func_8006A920). */
typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
} Stg20Pos2;

/* 0x20-byte record at 0x38 of the item list work (func_8006ED24). */
typedef struct {
    /* 0x00 */ u8 name[0x1C];
    /* 0x1C */ s32 item;
} Stg20ItemRec;

typedef struct {
    u8 _pad00[0x10];
    /* 0x10 */ s32 texts[6];
    /* 0x28 */ s32 descText;
    u8 _pad2C[0x04];
    /* 0x30 */ s32 index;
    /* 0x34 */ s32 dirty;
    /* 0x38 */ Stg20ItemRec recs[6];
} Stg20ItemWork;

/* D_8005E620.elems[] viewed from its own symbol with the 12 skill bytes at 0x22 (func_800697AC). */
typedef struct {
    u8 _pad00[0x22];
    /* 0x22 */ u8 skills[12];
    u8 _pad2E[0x2E];
} Stg20Roster; /* size 0x5C */

/* D_8005E620.elems[].name viewed from its own symbol (stride 0x5C, func_8006A000). */
typedef struct {
    /* 0x00 */ u8 name[0x5C];
} Stg20RosterName;

/* 14-byte skill group at 0x70 of the skill menu work (func_800697AC). */
typedef struct {
    /* 0x00 */ u8 list[13];
    /* 0x0D */ u8 count;
} Stg20SkillGroup;

typedef struct {
    u8 _pad00[0x70];
    /* 0x70 */ Stg20SkillGroup groups[4];
} Stg20SkillWork;

/* Work of the stage loader task (func_80063CDC). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 ids[10];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
} Stg20LoadWork;

/* Roster entry viewed with signed stats (func_8006964C). */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 level;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
} Stg20DigiStats;

typedef struct {
    u8 _pad00[0x5C];
    /* 0x5C */ Stg20DigiStats *digi;
} Stg20StatusWork;

/* Item list work (func_8006D7DC). */
typedef struct {
    u8 _pad00[0x1C];
    /* 0x1C */ s32 descText;
    /* 0x20 */ s32 texts[10];
    u8 _pad48[0x14];
    /* 0x5C */ s32 dirty;
    u8 _pad60[0x8C];
    /* 0xEC */ s16 items[0x43];
    /* 0x172 */ u8 colors[0x43];
    u8 _pad1B5[0x0B];
    /* 0x1C0 */ s32 cursor;
    /* 0x1C4 */ s32 top;
} Stg20ItemListWork;

extern Halves D_800705DC[];
extern s32 Item_GetNameText(s32);
extern void func_8006D2C0(void *t, s32 id, Halves pos, s32 arg);
extern Stg20Pos2 D_8006FC4C[4];
extern Halves D_8006358C;
extern Halves D_80063590;
extern PadState D_8005F6F0[];
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
extern void Snd_PlayById(s32, s32);
extern void Task_SetState0(Actor *, u32);
extern void Task_NextState2(Actor *);

extern Stg20Roster D_8005E704[];
extern Stg20RosterName D_8005E750[];
extern Stg20Cell D_8007010C[2];
extern SysState D_8005F770;
extern s32 func_8001EE34(s32);
extern void SetGeomOffset(s32, s32);
extern void Task_NextState1(Actor *);
extern void Gfx_FadeOutToBlack(s32);
extern void func_80067480(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color);
extern s32 D_80070A04;
extern s32 D_800709D0;
extern Halves D_8007001C[3];
extern Halves D_800706A4[];
extern s32 func_8001E180(s32);
extern s32 Flag_Test(s32);
extern void Flag_Set(s32, s32);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern s32 Item_GetDescText(s32);
extern u8 *Digi_GetDefaultName(s32);

#endif
