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

/* Work of the task 0x708 found by func_80068C5C. */
typedef struct {
    u8 _pad00[0x74];
    /* 0x74 */ s32 field_74;
} Stg35Work708;

extern s32 D_8006AA58[];
extern u8 D_8006AA88[];

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
