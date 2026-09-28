#ifndef STAG3000_H
#define STAG3000_H

#include "common.h"
#include "main/156C.h"

/* STAG3000 (Ovl_FileIds id 4, gameMode 0x5xx). */

/* Actor viewed with its (main-header padded) word at 0x04: func_8006F674 writes it. */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg30TaskHead;

/* Work of task D_80073040 (init func_80063B70) and D_800730D0 (init func_80065584). */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg30WorkWord;

/* Work of task D_80073078 (destroy func_80064FBC). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 text[4];
} Stg30Work73078;

/* Work of task D_800732B8 (func_8006F530, func_8006F640, func_8006F664, func_8006E850). */
typedef struct {
    u8 _pad00[0x28];
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x04];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 anim;
} Stg30Work732B8;

/* Work of tasks D_80073328 (init func_8006F8CC) and D_800733F0 (init func_800702A8). */
typedef struct {
    /* 0x00 */ Vec3 pos;
} Stg30WorkVec3;

/* Init arg of task D_800734F8: a pointer whose field_8 is copied to Actor.field_8. */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ s32 field_8;
} Stg30Ref;

/* Work of task D_800734F8 (func_80070D68, func_8007100C). */
typedef struct {
    /* 0x00 */ Stg30Ref *ref;
    u8 _pad04[0x08];
    /* 0x0C */ s32 text[2];
} Stg30Work734F8;

/* Two-word init arg of task D_80073718. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Stg30Pair;

/* Work of task D_80073718 (func_80071470, func_80071BDC). */
typedef struct {
    /* 0x00 */ Stg30Pair pair;
    u8 _pad08[0x1C];
    /* 0x24 */ s32 text[14];
} Stg30Work73718;

/* Work of task D_800737C8 (func_800728A0, func_80072F84). */
typedef struct {
    /* 0x00 */ s32 index;
    u8 _pad04[0x0C];
    /* 0x10 */ s32 field_10;
} Stg30Work737C8;

/* 0x5C-stride table D_80073CC0 (index = Stg30Work737C8.index). */
typedef struct {
    u8 _pad00[0x19];
    /* 0x19 */ u8 field_19;
    u8 _pad1A[0x42];
} Stg30Entry5C; /* size 0x5C */

/* Struct passed as arg0 of func_8006767C: 12 byte ids at 0x22. */
typedef struct {
    u8 _pad00[0x22];
    /* 0x22 */ u8 ids[12];
} Stg30IdSet;

/* Main-exe global read at 0x103D by func_8006A118. */
typedef struct {
    u8 _pad0000[0x103D];
    /* 0x103D */ u8 field_103D;
} Stg30Glob5D5A0;

extern Stg30Glob5D5A0 D_8005D5A0;
extern s32 D_80073A20[12];
extern Stg30Entry5C D_80073CC0[];

/* main exe */
extern void Task_DefaultDestroy(Actor *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 CdControlF(s32, s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern s32 func_8001E8D0(s32 id);
extern s32 func_8001F0C0(s32 id);
extern void Snd_PlayById(s32, s32);
extern void Gfx_DrawParts(EntA0 *);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

#endif
