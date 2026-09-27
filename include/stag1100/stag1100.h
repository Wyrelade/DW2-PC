#ifndef STAG1100_H
#define STAG1100_H

#include "common.h"
#include "main/156C.h"

/* STAG1100 (Ovl_FileIds id 5, gameMode 0x6xx): save and menu tasks. */

/* Save/load work area of the task held in D_800685D0 (Actor.work). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
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
    /* 0x4034 */ u8 field_4034[0x1E000];
    /* 0x22034 */ s32 field_22034;
    /* 0x22038 */ s32 field_22038;
    /* 0x2203C */ s32 field_2203C;
    /* 0x22040 */ s32 field_22040;
} Stg11SaveWork;

/* Task work passed as the second argument of the menu handlers (Actor.work of the menu task). */
/* Five 0x20-byte party rows in Stg11MenuWork at 0x98. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    u8 _pad04[0x1C];
} Stg11MenuRow;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10[9];
    u8 _pad34[0x04];
    /* 0x38 */ s32 field_38[11];
    u8 _pad64[0x14];
    /* 0x78 */ s16 field_78;
    /* 0x7A */ s16 field_7A;
    /* 0x7C */ s16 field_7C;
    /* 0x7E */ s16 field_7E;
    /* 0x80 */ s16 field_80;
    u8 _pad82[0x02];
    /* 0x84 */ s16 field_84;
    /* 0x86 */ s16 field_86;
    /* 0x88 */ s16 field_88;
    u8 _pad8A[0x06];
    /* 0x90 */ u8 *field_90;
    /* 0x94 */ s16 field_94;
    /* 0x96 */ s16 field_96;
    /* 0x98 */ Stg11MenuRow field_98[5];
    /* 0x138 */ s16 field_138;
} Stg11MenuWork;

typedef struct {
    u8 _pad00[0x10];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s16 field_14;
    u8 _pad16[0x0A];
    /* 0x20 */ s16 field_20;
    u8 _pad22[0x02];
    /* 0x24 */ s16 field_24;
    u8 _pad26[0x02];
    /* 0x28 */ s32 field_28;
} Stg11Work63894;

/* Party-select slot (stride 8) in Stg11Work66C04. */
typedef struct {
    /* 0x0 */ u8 field_0;
    u8 _pad1[0x1];
    /* 0x2 */ u8 field_2;
    u8 _pad3[0x1];
    /* 0x4 */ DigiRosterEntry *field_4;
} Stg11Slot;

typedef struct {
    /* 0x00 */ s32 field_0[16];
    u8 _pad40[0x10];
    /* 0x50 */ s16 field_50[2];
    /* 0x54 */ s16 field_54[2];
    u8 _pad58[0x08];
    /* 0x60 */ s16 field_60;
    u8 _pad62[0x02];
    /* 0x64 */ s16 field_64;
    /* 0x66 */ s16 field_66;
    /* 0x68 */ s16 field_68;
    /* 0x6A */ s16 field_6A;
    /* 0x6C */ Stg11Slot field_6C[0x26];
    u8 _pad19C[0x04];
    /* 0x1A0 */ s16 field_1A0;
    /* 0x1A2 */ s16 field_1A2[3];
} Stg11Work66C04;

/* D_800684A8: a save's GameState pointer followed by the three chosen party entries. */
typedef struct {
    /* 0x00 */ GameState *field_0;
    /* 0x04 */ DigiRosterEntry field_4[3];
    u8 _pad118[0x08];
} Stg11Party;

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
extern ActorWork *D_800685D4;
extern Stg11Party D_800684A8;

s32 func_80067818(void);

/* added by agent e */
extern void Task_NextState2(Actor *arg0);
extern void Task_SetState2(Actor *arg0, u32 arg1);
extern s32 func_800136A4(s32 arg0);
extern u8 D_80063454[];
extern u8 D_80063464[];
void func_800648E4(Stg11MenuWork *arg0, s32 arg1);
void func_800648B4(Actor *arg0, Stg11MenuWork *arg1);
void func_8006495C(Stg11MenuWork *arg0, s32 arg1, s32 arg2);
s32 func_800649F8(Actor *arg0, Stg11MenuWork *arg1);
void func_80067838(u8 *arg0, u8 arg1);
u8 *func_800676F4(void);
s32 func_80067880(s32 arg0);
void func_800673FC(void);
extern u8 *Digi_GetDefaultName(s32);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Task_Create(u32, s32 *, s32);
extern void Snd_StopAll(void);
extern void Snd_UnloadSlot(s32);
extern void Snd_SetSlotContent(s32, s32);
extern s32 Snd_AnySlotLoading(void);
extern void Task_NextState1(Actor *arg0);
extern SysState D_8005F770;
extern s16 D_80050780;
extern Halves D_800681DC;
s32 func_80067B54(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
s32 func_80067938(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gfx_DrawParts(void *);
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1);
typedef struct {
    /* 0x0 */ s32 field_0;
} Stg11MainWork;


#endif
