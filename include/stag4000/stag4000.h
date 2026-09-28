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
    /* 0x00 */ s16 field_0[13];
    /* 0x1A */ s16 field_1A;       /* index into field_0 */
} Stg40FFC;

typedef struct {
    u8 _pad000[0xE34];
    /* 0xE34 */ Stg40E34 field_E34;
    u8 _padE38[0x1C];
    /* 0xE54 */ Stg40E34 *field_E54;
    /* 0xE58 */ ActorWork *field_E58;
    u8 _padE5C[0x20];
    /* 0xE7C */ u8 field_E7C[0x180];
    /* 0xFFC */ Stg40FFC field_FFC;
    u8 _pad1018[0x4C];
    /* 0x1064 */ s32 field_1064;
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
    u8 _pad28[0x08];
    /* 0x30 */ s16 field_30;
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

typedef struct {
    u8 _pad000[0x180];
    /* 0x180 */ s16 field_180;
} Stg40B60;

typedef struct {
    u8 _pad00[0x14];
    /* 0x14 */ s32 field_14;
} Stg40BC0;

/* main exe */
extern Stg40Blk5071C *D_8005071C;
extern GameStateView *D_80050720;
extern s32 D_80050948[];
extern s32 D_8005075C;
extern void LoadImage(RECT *rect, u32 *p);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
extern void Text_Close(s32 *);
extern s32 Text_IsFinished(s32 id);
extern s32 func_800136A4(s32 arg0);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Task_DefaultDestroy(Actor *arg0);

/* overlay data */
extern s32 D_80072944;
extern Stg40B60 *D_80072B60;
extern Actor *D_80072B68;
extern Actor *D_80072B70;
extern s32 *D_80072B84;
extern Stg40BC0 *D_80072BC0;

/* overlay functions */
void func_8006ED5C(void);
void func_8006ED88(s32 arg0);
s32 func_8006E820(void);
void func_8006F38C(Stg40ImgWork *arg0);

#endif
