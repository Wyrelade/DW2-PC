#ifndef STAG1100_H
#define STAG1100_H

#include "common.h"
#include "main/156C.h"

/* STAG1100 (Ovl_FileIds id 5, gameMode 0x6xx): save and menu tasks. */

/* Save/load work area of the task held in D_800685D0 (Actor.work). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    u8 _pad08[0x04];
    /* 0x0C */ u8 field_C[0x15];
    /* 0x21 */ u8 field_21;
    u8 _pad22[0x02];
    /* 0x24 */ s32 field_24[2][2];
    union {
        /* 0x34 */ u16 sum[0x2000];
        struct {
            u8 _pad34[0x04];
            /* 0x38 */ u8 field_38[0x40];
            u8 _pad78[0x1BC];
            /* 0x234 */ u8 field_234[0x3E00];
        } s;
    } u34;
    /* 0x4034 */ u8 field_4034[0x1E004];
    /* 0x22038 */ s32 field_22038;
    /* 0x2203C */ s32 field_2203C;
    /* 0x22040 */ s32 field_22040;
} Stg11SaveWork;

/* Task work passed as the second argument of the menu handlers. */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x04];
    /* 0x10 */ s32 field_10[9];
    u8 _pad34[0x4A];
    /* 0x7E */ s16 field_7E;
    u8 _pad80[0x04];
    /* 0x84 */ s16 field_84;
    /* 0x86 */ s16 field_86;
} Stg11MenuWork;

typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s16 field_20;
    u8 _pad22[0x02];
    /* 0x24 */ s16 field_24;
} Stg11Work63894;

typedef struct {
    u8 _pad00[0x60];
    /* 0x60 */ s16 field_60;
    u8 _pad62[0x02];
    /* 0x64 */ s16 field_64;
    u8 _pad66[0x02];
    /* 0x68 */ s16 field_68;
} Stg11Work66C04;

extern PadState D_8005F6F0[];
extern void Snd_PlayById(s32, s32);
extern void Text_Close(s32 *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 Text_IsFinished(s32 id);
extern void Text_OpenDesc(void *arg0, TextDesc *arg1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Task_NextState0(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern u8 *memset(u8 *s, s32 c, s32 n);
extern u8 *strcpy(u8 *dst, u8 *src);

extern Halves D_800681D4;
extern Halves D_800681D8;
extern s16 D_800685C8;
extern Actor *D_800685D0;

s32 func_80067818(void);
void func_800677AC(u8 arg0, s32 arg1);


#endif
