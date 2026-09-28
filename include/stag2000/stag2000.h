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
    u8 _pad00[0x1C];
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
} Stg20Rot;

/* Map position: two s16 indices into D_80070768 (func_800636A8). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg20Cell;

/* D_8005E620 viewed with the u16 list at 0x2C scanned by func_8006C18C. */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ u16 field_2C[0x13];
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

#endif
