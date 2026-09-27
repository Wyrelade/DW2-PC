#ifndef STAG0000_H
#define STAG0000_H

#include "common.h"
#include "main/156C.h"

/* STAG0000 (Ovl_FileIds id 0, gameMode 0x1xx). */

/* Work area pointed to by D_80069360. */
typedef struct {
    u8 _pad000[0x8C0];
    /* 0x8C0 */ u16 field_8C0;
    /* 0x8C2 */ u16 field_8C2;
    u8 _pad8C4[0x0C];
    /* 0x8D0 */ s32 *field_8D0;
    /* 0x8D4 */ s16 field_8D4;
} Stg00Work;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg00Vec3;

typedef struct {
    /* 0x00 */ s32 field_0[7];
} Stg00Blk1C;

/* Actor.work of the objects moved by func_80068958 family. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    u8 _pad1C[0x50];
    /* 0x6C */ s32 field_6C;
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s32 field_74;
    u8 _pad78[0x04];
    /* 0x7C */ s16 field_7C;
    /* 0x7E */ s16 field_7E;
    /* 0x80 */ s16 field_80;
    u8 _pad82[0x02];
    /* 0x84 */ s32 field_84;
} Stg00ObjWork;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Stg00Work73FC;

extern SysState D_8005F770;
extern u8 **D_8006925C[];
extern u8 *D_8006935C;
extern Stg00Work *D_80069360;

extern void Task_DefaultDestroy(Actor *arg0);
extern TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
extern s32 CdControlF(s32, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

void func_80065114(void);
void func_80065150(s32 arg0, s32 arg1, u8 *arg2);
void func_80068084(s32 arg0, s32 arg1);


#endif
