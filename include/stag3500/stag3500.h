#ifndef STAG3500_H
#define STAG3500_H

#include "common.h"
#include "main/156C.h"

/* STAG3500 (Ovl_FileIds id 6, gameMode 0x7xx). */

/* File-load request: field_0 is a Cd file id (func_800661B0 passes it to Cd_GetFileEntry),
   field_4 the load mode (1 or 2, switched on by func_800661B0). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 mode;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    u8 _pad10[0x14];
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
    u8 _pad3;
} Stg35Rgb;

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
    u8 _pad04[0x24];
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x04];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
} Stg35Work;

/* Actor.work of the task at func_80067748: a 12-byte vector at 0. */
typedef struct {
    /* 0x00 */ Stg35Vec3 field_0;
} Stg35VecWork;


/* Work of the task 0x708 read by func_80068B10 .. func_80068CA0. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8;
} Stg35Work708Ent;

typedef struct {
    u8 _pad00[0x54];
    /* 0x54 */ s32 field_54[2];
    /* 0x5C */ s32 field_5C[6];
    /* 0x74 */ s32 field_74;
    /* 0x78 */ s32 field_78;
    u8 _pad7C[0x04];
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
    u8 _pad2C[0x08];
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
} Stg35Work4;

/* Work with 1 load handle and 14 text handles (func_80064AF0 destroy). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[1];
    /* 0x04 */ Stg35TextHandle text[14];
} Stg35Work1;

/* Sorted list work (func_80063694 inserts, func_80063E00 frees files). */
typedef struct {
    u8 _pad00[0x08];
    /* 0x008 */ s32 field_8[60];
    /* 0x0F8 */ s32 field_F8[60];
    u8 _pad1E8[0x78];
    /* 0x260 */ s32 field_260[30];
    /* 0x2D8 */ s32 field_2D8;
    u8 _pad2DC[0x04];
    /* 0x2E0 */ s32 field_2E0;
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

/* 0x5C-byte records at D_8006AA88. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
    u8 _pad28[0x34];
} Stg35Rec5C;

/* 6-byte entries of the lists pointed to by D_8006AA24 (end at field_0 == 0). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
} Stg35Rec6;

/* Camera work (func_80069FD4), same layout as STAG0000 Stg00ObjWork. */
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

extern s32 D_8006AA58[];
extern Stg35Rec5C D_8006AA88[];
extern Stg35Rec6 *D_8006AA24[6];
extern s32 D_80043704[];

extern void Actor_InitTransform(Actor *, s32 *, s32);
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

extern void Text_Close(Stg35TextObj *);
extern void Mem_Zero(void *a0, s32 a1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void func_800661B0(Stg35LoadHandle *arg0);
extern void func_8006926C(s32 arg0);
extern s32 Mem_Alloc(s32, s32);
extern void Mem_Free(void *);
extern s32 func_8001ED84(s32 arg0);
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


#endif
