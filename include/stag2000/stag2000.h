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
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x06];
    /* 0x42 */ s16 field_42;
    u8 _pad44[0x14];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
    u8 _pad64[0x20];
    /* 0x84 */ Stg20Vec3 field_84;
} Stg20Rot;

/* Map position: two s16 indices into D_80070768 (func_800636A8). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg20Cell;

/* D_8005E620 viewed with the u16 list at 0x2C scanned by func_8006C18C. */
typedef struct {
    u8 _pad00[0x01];
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x22];
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
extern u8 D_8005E6F1;
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
extern u8 D_80070138[][3][8][8];
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
extern s32 func_8001D910(s32);
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
    u8 _pad00[0x04];
    /* 0x04 */ s32 pos[3];
    u8 _pad10[0x04];
    /* 0x14 */ u16 rot;
    u8 _pad16[0x02];
    /* 0x18 */ s32 modelId;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u8 field_24;
    /* 0x25 */ u8 field_25;
    /* 0x26 */ u8 field_26;
    u8 _pad27[0x05];
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
    u8 _pad8A[0x02];
    /* 0x8C */ s32 timer;
    /* 0x90 */ s32 speed;
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
    /* 0x00 */ s32 count;
    /* 0x04 */ u32 timer;
    /* 0x08 */ s32 texts[16];
    /* 0x48 */ Stg20Slot slots[4];
} Stg20SlotWork;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x04];
    /* 0x40 */ s32 field_40;
    /* 0x44 */ s32 field_44;
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54;
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

/* func_800681A0 yes/no prompt */
typedef struct {
    /* 0x00 */ s32 sel;
    /* 0x04 */ s32 texts[2];
} Stg20YesNoWork;
extern s32 D_800709BC; /* D_800709B0.field_C as a scalar reloc */
extern Halves D_80063568;
extern Halves D_8006356C;

/* func_8006AB0C waypoint walker */
typedef struct {
    u8 _pad00[0x04];
    Stg20Cell path[5];
    s32 index;
    u8 _pad1C[0x08];
    s32 input;
    s32 held;
    u8 _pad2C[0x30];
    s32 wait;
    u8 _pad60[0x14];
    s32 done;
} Stg20WalkWork;
extern u16 D_8005F728; /* D_8005F6F0[0].held as a scalar reloc */
extern s32 Rand_Next();

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
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ u8 *bits;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
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
    /* 0x00 */ u8 name[0x18];
    /* 0x18 */ s32 price;
    /* 0x1C */ s32 item;
} Stg20ItemRec;

typedef struct {
    /* 0x00 */ s32 hdr[4];
    /* 0x10 */ s32 texts[6];
    /* 0x28 */ s32 descText;
    /* 0x2C */ s32 msgText;
    /* 0x30 */ s32 index;
    /* 0x34 */ s32 dirty;
    /* 0x38 */ Stg20ItemRec recs[6];
    /* 0xF8 */ s32 shownMsg;
    /* 0xFC */ s32 msg;
    /* 0x100 */ s32 msgArg;
} Stg20ItemWork;

/* D_8005E620.elems[] viewed from its own symbol with the 12 skill bytes at 0x22 (func_800697AC). */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 level;
    u8 _pad0E[0x14];
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
    /* 0x00 */ s32 texts[19];
    /* 0x4C */ s32 col;
    /* 0x50 */ s32 cursor[4];
    /* 0x60 */ s32 top[4];
    /* 0x70 */ Stg20SkillGroup groups[4];
    /* 0xA8 */ s32 skill;
} Stg20SkillWork;

/* Work of the stage loader task (func_80063CDC). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 ids[10];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
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
    /* 0x00 */ s32 hdr[7];
    /* 0x1C */ s32 descText;
    /* 0x20 */ s32 texts[10];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54;
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 dirty;
    /* 0x60 */ s16 inv[0x43];
    u8 _padE6[0x02];
    /* 0xE8 */ s32 count;
    /* 0xEC */ s16 items[0x43];
    /* 0x172 */ u8 colors[0x43];
    u8 _pad1B5[0x03];
    /* 0x1B8 */ s32 field_1B8;
    /* 0x1BC */ s32 field_1BC;
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

/* part 36 salvage */
typedef struct {
    /* 0x00 */ s16 items[50];
    /* 0x64 */ u8 names[50][25];
} Stg20ShopList;
typedef struct {
    /* 0x00 */ s32 hdr[4];
    /* 0x10 */ s32 descText;
    /* 0x14 */ s32 text14;
    /* 0x18 */ s32 text18;
    /* 0x1C */ s32 texts[8];
    /* 0x3C */ s32 dirty;
    /* 0x40 */ s32 cursor;
    /* 0x44 */ s32 page;
    /* 0x48 */ s32 count;
    /* 0x4C */ s32 pages;
    /* 0x50 */ u8 field_50;
    /* 0x51 */ u8 field_51;
    u8 _pad52[0x06];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
} Stg20ShopListWork;
extern Stg20ShopList D_80070A08;
extern u16 D_8005E686[0x30];
/* D_8005E620.field_66 as a scalar reloc */
extern void func_8006C420(u8 *out, s32 v);
extern void Task_Create(u32, s32 *, s32);
extern void func_80068D84(s32 id);
extern void func_800650BC(Actor *a);
extern void func_80064008(Actor *a);
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ TaskEntry *menu;
    /* 0x08 */ s32 timer;
    /* 0x0C */ s32 field_C;
} Stg20CtrlWork;
extern s32 func_8006C14C(u8 *s, s32 c);
extern s32 func_8006C18C(s32 id);
extern u8 D_800704FC[];
extern u8 D_80070530[];
extern u8 D_80070548[];
extern u8 D_80070554[];
extern u8 D_80070570[];
extern u8 D_80070580[];
extern u8 D_80070588[];
extern u8 D_80070594[];
extern u8 D_800705A4[];
extern u8 D_800705B4[];
extern u16 D_8005E64C;
/* D_8005E620.field_2C[0] as a scalar reloc */
extern u16 D_8005E65C;
/* D_8005E620.field_2C[8] */
extern u16 D_8005E65E;
/* D_8005E620.field_2C[9] */
extern u16 D_8005E660;
/* D_8005E620.field_2C[10] */
extern u16 D_8005E662;
extern s32 Cd_GetFileLba(s32 arg0);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern void CdIntToPos(s32, u8 *);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ u8 channel;
    u8 _pad05[0x03];
    /* 0x08 */ s32 len;
    /* 0x0C */ s32 start;
    /* 0x10 */ s32 end;
} Stg20XaWork;
extern s32 D_80070A00;
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
    /* 0x02 */ u8 mode;
    /* 0x03 */ u8 arg;
} Stg20Exit;
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ s32 arg;
} Stg20ExitWork;
typedef struct {
    /* 0x00 */ s32 scroll;
    u8 _pad04[0x08];
    /* 0x0C */ s32 on;
    /* 0x10 */ s32 level;
} Stg20ScrollWork;
typedef struct {
    u8 _pad00[0x40];
    /* 0x40 */ s32 row;
    /* 0x44 */ s32 field_44;
    u8 _pad48[0x04];
    /* 0x4C */ s32 field_4C;
    u8 _pad50[0x08];
    /* 0x58 */ s32 field_58;
} Stg20ShopWork;
extern Halves D_8006FF9C[4][4];
extern s32 func_8001D958(s32);

/* ---- added by p36 agent b ---- */
extern s32 func_80067928(Stg20Cell *c, s32 x, s32 y, s32 flag);

/* 0x18-byte pick record (func_80067978). */
typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 flag;
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 fileId;
    /* 0x0C */ s32 altFileId;
    /* 0x10 */ s16 mode;
    /* 0x12 */ u8 arg;
    u8 _pad13[0x01];
    /* 0x14 */ Stg20Cell cell;
} Stg20PickRec; /* size 0x18 */

typedef struct {
    /* 0x00 */ s32 redraw;
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 index;
    /* 0x0C */ Stg20PickRec recs[1];
} Stg20NavWork;

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern Halves D_8005074C;
extern s32 D_8005F79C;

extern s32 D_8006FFDC[4];

extern Halves D_8007009C[];
extern s32 D_800700D4[4];
extern s32 D_800700E4[4];
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);

extern s32 D_80070674[2][3];
extern void func_8006D93C(Actor *a);

extern s32 D_800706D4[6];
extern s32 func_8006E9E8(s32 item);

extern s32 D_8006FF44[];
extern s32 D_8006FF58[];

extern Stg20Cell D_800704E4[6];
extern s32 func_8006C3B8(s32 id);

/* 0xBE-byte new-game block copied to D_8005E620+0x24 (func_800667AC). */
typedef struct {
    /* 0x00 */ u16 data[0x5F];
} Stg20StartBlock;

/* D_8005E620 viewed with the start block at 0x24. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ Stg20StartBlock start;
} Stg20GameInit;

extern Stg20StartBlock D_8006FD84;
extern Stg20StartBlock D_8006FE44;
extern u8 D_8006FF04[3][8];
extern void Digi_InitFromTable(s32, s32, DigiRosterEntry *);

extern s32 func_8001E0C0(s32 id);
extern s32 func_8001E1AC(s32 id);
extern void func_8006D4F4(s16 *list, s32 n, s32 v);

/* ActorModel viewed with the three tint bytes at 0x38 (func_8006A434). */
typedef struct {
    u8 _pad00[0x38];
    /* 0x38 */ u8 r;
    /* 0x39 */ u8 g;
    /* 0x3A */ u8 b;
} Stg20ModelTint;

extern s32 D_800709F4;
extern s32 Digi_GetModelFile(s32 id);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);

/* Warp point: map cell, next game mode and field_24 value (func_8006F3E0). */
typedef struct {
    /* 0x00 */ Stg20Cell cell;
    /* 0x04 */ s32 nextMode;
    /* 0x08 */ s32 field_8;
} Stg20Warp; /* size 0xC */

/* Task 7 creation args (func_8006F3E0). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 z;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg20WarpFx;

extern Stg20Warp D_80070704[];
extern void func_8006AD8C(Actor *a);

extern u8 D_8005F794; /* D_8005F770.field_24 low byte as a scalar reloc */
extern Stg20FileRec *func_8006F360(s32 i);

/* Roster entry viewed with a signed word at 0x16 (func_80066B48). */
typedef struct {
    /* 0x00 */ u8 state;
    u8 _pad01[0x15];
    /* 0x16 */ s16 field_16;
    u8 _pad18[0x44];
} Stg20RosterHp; /* size 0x5C */

/* D_8005E620 viewed with the roster at 0xE4 as Stg20RosterHp (func_80066B48). */
typedef struct {
    u8 _pad00[0xE4];
    /* 0xE4 */ Stg20RosterHp elems[0x24];
} Stg20GameRoster;

extern u16 D_8005E64E; /* D_8005E620.field_2C[1] as a scalar reloc */
extern u8 D_8005E632;  /* D_8005E620 byte 0x12 as a scalar reloc */
extern s32 D_8005F790; /* D_8005F770.prevGameMode as a scalar reloc */
extern s32 Item_GetBagCapacity(void);
extern s32 func_80066A4C(s32 id);

/* ---- added by p36 agent e ---- */
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern void Gfx_FadeOutToWhite(s32);
extern void Gfx_FadeInFromWhite(s32);
extern s32 D_800709EC[];

extern void Digi_AddNew(s32);
extern u16 D_8005E66E; /* D_8005E620.field_66[4] as a scalar reloc */
extern u8 D_8005E631;  /* D_8005E620 byte 0x11 as a scalar reloc */


/* D_800709B0 viewed from its field_8 (func_8006CB58 addresses D_800709B0.field_54 as 0x4C from it). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x44];
    /* 0x48 */ s32 field_48; /* = D_80070A00 (func_8006BEDC addresses field_0 as -0x48 from it) */
    /* 0x4C */ s32 field_4C;
} Stg20MenuSub;
extern Stg20MenuSub D_800709B8;
extern s32 func_8001ED84(s32);
extern Halves D_80063594;
extern Halves D_80063598;
extern s32 D_8005F70C; /* D_8005F6F0[0].triangle as a scalar reloc */
extern void Item_RemoveFromBag(s32 i);

/* Digimon info page work: 13 texts and the roster entry shown (func_80069068). */
typedef struct {
    /* 0x00 */ s32 texts[13];
    u8 _pad34[0x28];
    /* 0x5C */ DigiRosterEntry *digi;
} Stg20InfoWork;

extern Stg20Cell D_80070040[13];
extern u8 D_80070074[4][4];
extern s32 D_800709D4;
extern s32 D_800709D8;
extern s32 D_800709DC;
extern s32 D_800709E4;
extern s32 func_8001D980(s32);
extern s32 func_8001DA80(s32 id, s32 val);

extern void Task_NextState3(Actor *);
extern void Task_NextState4(Actor *);
extern void Task_SetState2(Actor *, u32);
extern void Task_SetState3(Actor *, u32);
extern void Snd_StopById(s32);
extern u8 func_8001D9A8(s32);

/* Roster entry viewed with signed HP/MP words and the byte at 0x46 (func_800650BC). */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x12];
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    u8 _pad1C[0x2A];
    /* 0x46 */ u8 field_46;
    u8 _pad47[0x15];
} Stg20DigiBoost; /* size 0x5C */

extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeSetBlack(void);
extern void Gfx_InitLights(void);
extern void func_8001E28C(s32 arg0);
extern s32 func_8001E480(void); /* main defines it void; its tail call leaves Flag_NextPassingEntry's result in v0 */
extern Blk12 *func_8001E5E8(s32 id);
extern s16 func_8001E634(s32 id);
extern s16 func_8001E658(s32 id);
extern s32 Flag_NextPassingEntry(void);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Mem_Zero(void *a0, s32 a1);
extern s32 Snd_AnySlotLoading(void);
extern s32 D_80050764;
extern s32 D_8005F700; /* D_8005F6F0[0].circle as a scalar reloc */

/* Work of the stage main task (func_80065FB8). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 bgmOn;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Stg20MainWork;

/* 4-byte start position record at Stg20MapFile.field_8 (func_80065FB8). */
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
    /* 0x02 */ u16 dir;
} Stg20Start;

/* Byte pair of the 0xC-byte NPC block (func_80065FB8). */
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
} Stg20BytePair;

extern void func_80067604(Actor *a, s32 doX, s32 doZ);
extern void func_800676A8(Actor *a, s32 i);
extern s32 func_80067568(Actor *a);
extern s32 func_80067770(Actor *a, s32 dir);
extern void func_800677C8(Actor *a, Stg20Marks *m, s32 dir, s32 timer);
extern void func_800678A8(Actor *a, Stg20Marks *m);
extern void func_8006AA0C(Actor *a, s32 anim);
extern void func_8006AB0C(Actor *a);
extern s32 func_8006AD14(Actor *a);
extern void func_8006AD6C(Actor *a, s32 i);

extern s32 Flag_SelectBranch(s32 arg0);
extern void func_8001C038(void *arg0, s32 arg1);
extern s32 Text_IsFinished(s32 id);
extern s32 func_8001E5C0(void);
extern void Actor_StopAxisMotion(Actor *a, s32 axis);
extern s32 func_80020D54(Actor *a, s32 i);

/* Work of the map walker/NPC model task (func_8006ADF8). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 modelId;
    /* 0x24 */ s32 input;
    /* 0x28 */ s32 held;
    /* 0x2C */ s32 anim;
    /* 0x30 */ s32 dir;
    /* 0x34 */ Stg20Marks marks;
    /* 0x5C */ s32 wait;
    /* 0x60 */ s32 counter;
    /* 0x64 */ s32 visible;
    /* 0x68 */ Actor *target;
    /* 0x6C */ s32 text;
    /* 0x70 */ s32 timer;
} Stg20NpcWork;

extern s32 D_8005F704; /* D_8005F6F0[0].cross as a scalar reloc */
extern s32 D_80070624[10];
extern s32 D_8007064C[10];

extern s32 func_8001F0C0(s32 id);
extern s32 func_8001EF64(s32 id);
extern s32 D_800709FC;

/* Roster entry as the jogress code builds and reads it (func_80064008). */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0B];
    /* 0x0D */ u8 level;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 skills[12];
    /* 0x2E */ u8 learned[0x19];
    /* 0x47 */ u8 parent0;
    /* 0x48 */ u8 parent1;
    u8 _pad49[0x13];
} Stg20Digi; /* size 0x5C */

extern void func_80068DD8(s32 text, s32 digi);

extern s32 D_800709E0;
extern Stg20Cell D_800700AC[10];
extern void func_800698F4(Actor *a);

#endif
