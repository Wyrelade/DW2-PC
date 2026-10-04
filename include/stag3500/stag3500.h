#ifndef STAG3500_H
#define STAG3500_H

#include "common.h"
#include "main/156C.h"

/* STAG3500 (Ovl_FileIds id 6, gameMode 0x7xx). */

/* Part-slide slot (func_80066694 sets, func_800661B0 steps): parts matching mask
   move by speed (8.8 fixed, accum carries the fraction) towards target. */
typedef struct {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 dir;
    /* 0x02 */ s16 target;
    /* 0x04 */ u16 accum;
    /* 0x06 */ s16 speed;
    /* 0x08 */ s32 mask;
} Stg35Slide;

/* File-load request: field_0 is a Cd file id (func_800661B0 passes it to Cd_GetFileEntry),
   field_4 the load mode (1 or 2, switched on by func_800661B0), field_C the two
   part-slide slots (func_800657AC writes the first word directly). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 mode;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ union {
        s32 field_C;
        Stg35Slide slide[2];
    } u;
} Stg35Load; /* size 0x24 (func_80066120 allocates 0x24) */

/* Handle whose first word points at a Stg35Load (func_800661B0 argument). */
typedef struct {
    /* 0x00 */ Stg35Load *load;
} Stg35LoadHandle;

/* Four-byte colour entries at 0x04 of Stg35Sprite. */
typedef struct {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 code;
} Stg35Rgb;

/* Gouraud quad packet (PsyQ POLY_G4 shape) built by func_80065930. */
typedef struct {
    /* 0x00 */ union {
        u32 word;
        struct {
            u8 _pad0[3];
            /* 0x03 */ u8 len;
        } b;
    } tag;
    /* 0x04 */ Stg35Rgb c0;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ Stg35Rgb c1;
    /* 0x10 */ s16 x1;
    /* 0x12 */ s16 y1;
    /* 0x14 */ Stg35Rgb c2;
    /* 0x18 */ s16 x2;
    /* 0x1A */ s16 y2;
    /* 0x1C */ Stg35Rgb c3;
    /* 0x20 */ s16 x3;
    /* 0x22 */ s16 y3;
} Stg35PolyG4; /* size 0x24 */

/* Draw-mode packet (PsyQ DR_MODE shape). */
typedef struct {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u32 code[2];
} Stg35DrMode; /* size 0xC */

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Stg35Rgb field_4[4];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
} Stg35Sprite;

typedef struct {
    /* 0x00 */ Stg35Sprite *sprite;
} Stg35SpriteHandle;

/* 0x1C-byte object allocated by func_800656D0 (field_0 = -1), closed by Text_Close. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg35TextObj;

typedef struct {
    /* 0x00 */ Stg35TextObj *text;
} Stg35TextHandle;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg35Vec3;

/* Actor.work of the stage tasks. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;          /* model file (Digi_GetModelFile) */
    /* 0x18 */ s32 field_18;          /* draw textured */
    /* 0x1C */ s32 field_1C;          /* draw wireframe */
    /* 0x20 */ CVECTOR field_20;      /* wireframe colour */
    u8 _pad24[0x04];
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
} Stg35Work;

/* Actor.work of the task at func_80067748: a 12-byte vector at 0. */
typedef struct {
    /* 0x00 */ Stg35Vec3 field_0;
} Stg35VecWork;


/* Work of the task 0x708 read by func_80068B10 .. func_80068CA0. */
typedef struct {
    /* 0x00 */ s32 field_0;           /* target */
    /* 0x04 */ s32 field_4;           /* shown value */
    /* 0x08 */ s32 field_8;           /* max */
} Stg35Work708Ent;

typedef struct {
    /* 0x00 */ Stg35LoadHandle load[3];
    /* 0x0C */ Stg35TextHandle text[7];
    /* 0x28 */ Stg35SpriteHandle sprite[10];
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54[2];
    /* 0x5C */ s32 field_5C[6];
    /* 0x74 */ s32 field_74;
    /* 0x78 */ s32 field_78;
    /* 0x7C */ s32 field_7C;
    /* 0x80 */ Stg35Work708Ent field_80[6];
} Stg35Work708;

/* Work with 3 load handles, 7 text handles and 10 sprite handles
   (func_800689FC destroy, func_80068AA0 draw). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[3];
    /* 0x0C */ Stg35TextHandle text[7];
    /* 0x28 */ Stg35SpriteHandle sprite[10];
} Stg35Work3;

/* Work with 4 load handles and 7 text handles (func_800645B4 destroy,
   func_80064638 draw). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[4];
    /* 0x10 */ Stg35TextHandle text[7];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ s32 field_40;
} Stg35Work4;

/* Work with 1 load handle and 14 text handles (func_80064AF0 destroy). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[1];
    /* 0x04 */ Stg35TextHandle text[14];
} Stg35Work1;

/* Sorted list work (func_80063694 inserts, func_80063E00 frees files).
   func_80063758 fills it from the battle script: field_1E8/field_2DC and
   field_260/field_2E0 are the two file-id lists, field_8/field_F8 the
   (file id, LBA) list sorted by LBA. */
typedef struct {
    /* 0x000 */ s16 *field_0;         /* battle script */
    /* 0x004 */ s32 field_4;          /* wait timer */
    /* 0x008 */ s32 field_8[60];
    /* 0x0F8 */ s32 field_F8[60];
    /* 0x1E8 */ s32 field_1E8[30];
    /* 0x260 */ s32 field_260[30];
    /* 0x2D8 */ s32 field_2D8;
    /* 0x2DC */ s32 field_2DC;
    /* 0x2E0 */ s32 field_2E0;
    u8 _pad2E4[0x04];
    /* 0x2E8 */ s32 field_2E8;        /* player digi id */
    /* 0x2EC */ s32 field_2EC[6];     /* enemy digi ids */
    /* 0x304 */ s32 field_304[6];     /* enemy kinds */
    /* 0x31C */ s32 field_31C;
} Stg35ListWork;

/* Object holding six child actors at 0x2C (func_80064BB0, func_80064C54). */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ Actor *field_2C[6];
} Stg35ChildList;

typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ Stg35ChildList *field_34;
} Stg35ChildOwner;

/* 0x5C-byte battle copy of a party digimon (D_8006AA88.rec[6], at 0x8006AA98);
   shares the leading fields of the main-exe DigiRosterEntry. */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0E];
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    u8 _pad1A[0x02];
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 field_22[12];
    u8 _pad2E[0x1E];
    /* 0x4C */ u8 name[14];
    u8 _pad5A[0x02];
} Stg35Rec5C; /* size 0x5C */

/* Save_GameState (main GameState) viewed with the party slots as Stg35Rec5C. */
typedef struct {
    u8 _pad00[0xE4];
    /* 0xE4 */ Stg35Rec5C elems[0x24];
} Stg35GameState;

extern Stg35GameState Save_GameState;

/* 6-byte entries of the lists pointed to by D_8006AA24 (end at field_0 == 0). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
} Stg35Rec6;

/* Per-party-slot pick table filled by func_8006A168. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u8 field_C[6];
    /* 0x12 */ s16 field_12[6];
    /* 0x1E */ s16 field_1E[6];
    u8 _pad2A[0x02];
} Stg35Rec2C;

/* D_8006AA88 (func_80067720 zeroes all 0x358 bytes). */
typedef struct {
    u8 _pad000[0x10];
    /* 0x010 */ Stg35Rec5C rec[6];
    /* 0x238 */ Stg35Rec2C field_238[6];
    /* 0x340 */ s32 field_340[6];
} Stg35Battle; /* size 0x358 */

/* Camera work (func_80069FD4), same layout as STAG0000 Stg00CameraWork. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 field_1C;
    /* 0x6C */ s32 field_6C;
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s32 field_74;
    u8 _pad78[0x04];
    /* 0x7C */ s16 field_7C;
    /* 0x7E */ s16 field_7E;
    /* 0x80 */ s16 field_80;
    u8 _pad82[0x02];
} Stg35CamWork;

/* Stack block passed to GsSetRefView2. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 *field_1C;
} Stg35RefView;

/* 7-word argument block passed to Task_Create(7, ...) (func_80066A9C, func_800668F8). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg35SpawnArgs;

/* One- and three-word Task_Create argument blocks. */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg35Arg1;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg35Arg3;

/* Actor.work of func_80067510: one load handle and a fade counter. */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[1];
    /* 0x04 */ s32 field_4;
} Stg35FadeWork;

/* Actor.work of the CD stream task func_80067768. */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 channel;
    /* 0x08 */ s32 track;             /* 1-based index into D_8006A600/D_8006A618 */
    /* 0x0C */ s32 start;             /* start sector */
    /* 0x10 */ s32 end;               /* end sector */
} Stg35CdWork;

/* Actor.u38 transform viewed with the position / vertical speed words. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x0C];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
} Stg35Xform;

/* ActorModel viewed with the fade colour bytes at 0x38 (as STAG0000 Stg00ModelFade). */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg35ModelFade;

/* Actor.work of the battle script runner func_80068D34. */
typedef struct {
    /* 0x00 */ s16 *script;
} Stg35ScriptWork;

/* Actor.work of the battle main task func_80064CB8. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;           /* turn count */
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;           /* winning side */
} Stg35BattleWork;

/* GfxPart with the fade fields func_800661B0 writes (0x0E, 0x14). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    u8 _pad8[4];
    /* 0x0C */ u8 palette;
    /* 0x0D */ u8 frame;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 visible;
    u8 _pad10[4];
    /* 0x14 */ s32 field_14;
    u8 _pad18[4];
    /* 0x1C */ s32 groupMask;
    u8 _pad20[8];
} Stg35Part; /* size 0x28 */

/* s16 screen position pairs (D_8006A4DC, D_8006A500, D_8006A508, D_8006A648, D_8006A654). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg35XY;

extern s32 D_8006AA58[];
extern Stg35Battle D_8006AA88;
extern Stg35Rec6 D_8006A6DC[];
extern s32 D_8006A55C[];
extern Stg35Rec6 *D_8006AA24[6];
extern s32 Gfx_ZeroVector[];

extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
extern void Gfx_ResetModelBones(Actor *);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Cd_FreeFile(s32 fileId);
extern void Text_Open(void *, TextOpenArgs *);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg35RefView *);
extern void func_80065718(Stg35TextHandle *arg0);
extern void func_800658F4(Stg35SpriteHandle *arg0);
extern void func_80065930(Stg35SpriteHandle *arg0);
extern void func_800674D4(Actor *arg0, s32 arg1);
extern void func_800674F8(Actor *arg0);

extern void Text_Close(s32 *slot);
extern void Mem_Zero(void *a0, s32 a1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void func_800661B0(Stg35LoadHandle *arg0);
extern void func_8006926C(s32 arg0);
extern s32 Mem_Alloc(s32, s32);
extern void Mem_Free(ActorWork *arg0);
extern s32 Skill_GetNameText(s32 arg0);
extern s32 func_8001E8D0(s32 id);
extern s32 CdControlF(s32, s32);
extern void Snd_PlayById(s32, s32);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Task_NextState0(Actor *arg0);
extern TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
extern void func_80066120(Stg35LoadHandle *arg0);
extern void func_80066168(Stg35LoadHandle *arg0);
extern void func_800661A4(Stg35LoadHandle *arg0, s32 arg1);
extern void func_80066520(Stg35LoadHandle *arg0, s32 arg1, s32 arg2);
extern void func_800663CC(Stg35LoadHandle *arg0, s32 arg1);
extern void func_80065760(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800657AC(Stg35LoadHandle *arg0, s32 arg1);
extern void func_800657B8(Stg35TextHandle *arg0, s32 arg1);
extern void func_800657F0(Stg35TextHandle *arg0, s32 arg1);
extern void func_80065824(Stg35TextHandle *arg0);
extern s32 func_80069870(s32 arg0, s32 arg1);
extern void func_80065B1C(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void func_80065B3C(Stg35SpriteHandle *arg0, s32 arg1);
extern void func_80065B48(Stg35SpriteHandle *arg0, s32 arg1);
extern void func_80065B54(Stg35SpriteHandle *arg0, s32 arg1);
extern void func_80065B60(Stg35SpriteHandle *arg0, s32 arg1);
extern void func_80065B04(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3);
extern void func_80065B6C(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 func_80065B88(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_80065BE0(s32 arg0, s32 arg1, s32 arg2);
extern void func_8006A0D4(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
extern void func_800656D0(Stg35TextHandle *arg0);
extern void func_800657A0(Stg35LoadHandle *arg0, s32 arg1);
extern void func_80065894(Stg35TextHandle *arg0);
extern void func_800658B8(Stg35SpriteHandle *arg0);
extern void func_80065D00(void);
extern void func_80065D2C(s32 arg0, s32 arg1);
extern void func_80065D84(s32 arg0);
extern s32 func_80065E04(void);
extern s32 func_80065E44(s32 arg0);
extern void func_80065E60(void);
extern void func_80065F8C(s32 arg0, s32 arg1);
extern void func_80066408(Stg35LoadHandle *arg0, s32 mask);
extern void func_80066480(Stg35LoadHandle *arg0, s32 mask);
extern void func_800664F4(Stg35LoadHandle *arg0);
extern void func_80066508(Stg35LoadHandle *arg0);
extern void func_8006659C(Stg35LoadHandle *arg0, s32 mask, s32 v);
extern void func_80066618(Stg35LoadHandle *arg0, s32 mask, s32 v);
extern void func_80066694(Stg35LoadHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed);
extern void func_80066778(Stg35LoadHandle *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800667D0(Actor *arg0, s32 arg1);
extern void func_800668F8(Actor *arg0, s32 arg1);
extern void func_80066A9C(Actor *arg0);
extern void func_80066BC8(Actor *arg0);
extern void func_80066C00(Actor *arg0, s32 arg1);
extern void func_80067720(void);
extern void func_800679D0(Actor *arg0);
extern void func_80067B18(Actor *arg0, s32 arg1);
extern void func_80067C74(Actor *arg0, s32 arg1);
extern void func_80068B10(s32 arg0, s32 *arg1);
extern s32 func_80068B9C(void);
extern void func_80068BF8(void);
extern s32 func_80068C5C(void);
extern s32 func_80068CA0(s32 arg0);
extern s32 func_80069850(s32 arg0);
extern void func_800698C8(Stg35CamWork *arg0, s32 *arg1);
extern void func_8006A080(s32 arg0);
extern void func_8006A168(s32 arg0);
extern void func_80063694(Actor *arg0, s32 arg1, s32 arg2);
extern void func_80064B94(Actor *arg0, s32 arg1, s32 arg2);
extern void func_80064BB0(Stg35ChildOwner *arg0, s32 arg1);
extern void func_80064C54(Stg35ChildOwner *arg0);

/* Main-exe functions, declared the way this overlay calls them. */
extern void Task_Create(u32 id, s32 *slot, s32 arg);
extern void Task_NextState1(Actor *arg0);
extern void Task_NextState2(Actor *arg0);
extern void Task_NextState3(Actor *arg0);
extern void Task_NextState4(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState4(Actor *arg0, u32 arg1);
extern void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2);
extern TaskEntry *Task_FindNext(void);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeOutToBlack(s32 arg0);
extern void Gfx_InitLights(void);
extern void Gfx_DrawParts(s32);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void SetDrawMode(Stg35DrMode *p, s32 dfe, s32 dtd, s32 tpage, s32 tw);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern void Anim_StepModelAnim(Actor *);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2);
extern s32 Digi_GetModelFile(s32 id);
extern u8 *Digi_GetDefaultName(s32);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);
extern s32 Rand_Next();
extern u8 *memset(u8 *s, s32 c, s32 n);
extern s32 Snd_AnySlotLoading(void);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Cd_FreeUnlockedFiles(void);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);
extern s32 Cd_GetFileLba(s32 arg0);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(u8 com, u8 *param, u8 *result);
extern u8 *CdIntToPos(s32 i, u8 *p);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32 mode, u8 *result);    /* the main C stub is void(void) */
extern s32 CdLastCom(void);                 /* main: u8 */
extern s32 func_8001E79C(s32 id);           /* main: s16 */
extern s32 func_8001E7C0(s32 id);           /* main: s16 */
extern void Digi_GetCastFxOffsets(s32 a0, void *a1);
extern void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
extern s32 Skill_GetCastAnim(s32 id);
extern s32 Skill_GetPartsEntry(s32 id);
extern s32 *Skill_GetShotXa(s32 id);
extern s32 Skill_GetPower(s32 id);           /* main: s16 */
extern u16 Skill_GetSpecialty(s32 id);

extern SysState Sys_State;
extern PadState Pad_State[];
extern s16 D_80050780;

extern s32 D_8006A4AC[];
extern s32 D_8006A4B8[];
extern Stg35XY D_8006A4DC[];
extern s16 D_8006A4F4[];
extern Stg35XY D_8006A500[];
extern Stg35XY D_8006A508[];
extern s32 D_8006A540[];
extern Stg35Rec5C D_8006AA98[];
extern Elem12 D_8006A574;
extern Elem12 D_8006A580;
extern Elem12 D_8006A58C;
extern s32 D_8006A600[];
extern s32 D_8006A618[];
extern Stg35XY D_8006A648[];
extern Stg35XY D_8006A654[];
extern s16 D_8006A690[];
extern s16 D_8006A69C[];
extern s16 D_8006A6B0[];
extern s16 D_8006ADE0[];              /* battle script buffer (bss) */
extern s32 D_8006AF70;


/* rodata {1, 2, 0x10}: func_80067510 copies it to the stack as a whole (the local's initializer) */
typedef struct {
    /* 0x0 */ s32 v[3];
} Stg35Masks;
extern Stg35Masks D_80063418;

#endif
