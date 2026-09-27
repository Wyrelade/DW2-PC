#ifndef STAG1000_H
#define STAG1000_H

#include "common.h"
#include "main/156C.h"

/* STAG1000: the movie stage (Psy-Q movie sample STR player + libpress). */

/* STR movie decode environment (the Psy-Q movie sample's DECENV). */
typedef struct {
    /* 0x00 */ u32 *vlcbuf[2];
    /* 0x08 */ s32 vlcid;
    /* 0x0C */ u32 *imgbuf[2];
    /* 0x14 */ s32 imgid;
    /* 0x18 */ RECT rect[2];
    /* 0x28 */ s32 rectid;
    /* 0x2C */ RECT slice;
    /* 0x34 */ s32 isdone;
} StrDecEnv; /* size 0x38 */

/* STR sector header returned by StGetNext. */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ u32 frameCount;
    u8 _pad0C[0x04];
    /* 0x10 */ u16 width;
    /* 0x12 */ u16 height;
} StrHeader;

/* Cd_GetFileEntry(0xD760000) record, stride 0x28, list ends at field_0 == 0. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x08];
    /* 0x0C */ u8 field_C;
    u8 _pad0D[0x1B];
} StgFileEntry; /* size 0x28 */

/* libpress DECDCTENV: quantization tables and DCT matrix (DecDCTGetEnv/PutEnv). */
typedef struct {
    /* 0x00 */ u8 iq_y[64];
    /* 0x40 */ u8 iq_c[64];
    /* 0x80 */ s16 dct[64];
} DecDCTEnv; /* size 0x100 */

/* Work of the title menu task (func_800635A4, func_800638D4). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;          /* menu cursor */
    /* 0x10 */ s32 field_10;
} Stag1000Menu;

/* 0x28-stride part record of resource 0x1840000 (zero fileId ends the list). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x2];
    /* 0x06 */ s16 field_6;
    u8 _pad08[0x4];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x1];
    /* 0x0E */ u8 unscaled;
    /* 0x0F */ u8 visible;
    u8 _pad10[0xC];
    /* 0x1C */ s32 partMask;
    u8 _pad20[0x8];
} Stag1000Part; /* size 0x28 */

/* The movie task's work area (Actor.work). */
typedef union {
    /* 0x00 */ s32 count;
    /* 0x00 */ u8 byte;
} StgWork;

/* main exe */
extern void DMACallback();
extern void printf();
extern s32 D_8005F724;             /* D_8005F6F0[0].start as a scalar reloc */
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Sys_SetFrameRate60(void);
extern void Gfx_InitTexSlots(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeClear(void);
extern void Task_Create(u32, s32 *, s32);
extern void Snd_StopAll(void);
extern s32 Cd_GetFileSectors(s32 arg0);
extern s32 Cd_PollRead(void);
extern s32 Mem_Alloc(s32, s32);
extern void Cd_GetFilePos(s32 arg0, void *arg1);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void ResetCallback(void);
extern u8 D_80050741;
extern PadState D_8005F6F0[];
extern s32 D_8005F78C;
extern SysState D_8005F770;
extern u8 D_80061B04;              /* s32 in the main exe; read as a byte here (StCdIntrFlag) */
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdRead2(s32);           /* void in the main exe; returns CdControl's result */
extern void StSetRing(s32, s32);
extern void StSetStream(s32, s32, s32, s32, s32);
extern s32 StFreeRing(u32 *);
extern s32 StGetNext(u32 **, StrHeader **);
extern s32 CdControlB(u8, u8 *, u8 *);
extern void StUnSetRing(void);
extern void Mem_Free();
extern void Task_DefaultDestroy();
extern void Task_NextState0();
extern void Task_NextState1();
extern s32 ResetGraph(s32);
extern void ClearImage2();
extern void DrawSync();
extern void LoadImage();
extern void Gpu_ClearScreens(void);
extern void func_8001D8A4(s32);
extern void func_8002E2C4(void);

/* this overlay */
extern char D_80063360[];
extern char D_8006337C[];
extern char D_8006338C[];
extern char D_8006339C[];
extern RECT D_800651C0;
extern s16 D_800651C8[];
extern u32 D_80065258;
extern u32 D_8006525C[16];
extern u32 D_8006529C[16];
extern u32 D_800652DC;
extern u32 D_800652E0[32];
extern volatile u32 *D_80065368;
extern volatile u32 *D_8006536C;
extern volatile u32 *D_80065370;
extern volatile u32 *D_80065374;
extern volatile u32 *D_80065378;
extern volatile u32 *D_8006537C;
extern volatile u32 *D_80065398;
extern volatile u32 *D_800653A0;
extern u8 D_800653D8[];
extern s32 D_80065220;
extern s32 D_80065224;
extern s32 D_80065228;
extern volatile u32 *D_8006539C;
extern u32 *D_800661E8;
extern u32 *D_800661EC;
extern u32 *D_800661F0;
extern u32 *D_800661F4;
extern u32 *D_800661F8;
extern s32 D_800661FC;
extern s32 D_80066200;
extern s32 D_80066204;
extern StrDecEnv D_80066208;
extern u32 *D_80066240;

u32 *func_8006400C(StrDecEnv *dec);
void func_800646C0(s32 arg0);
void func_80064894(u32 *buf, s32 size);
void func_8006495C(void (*func)());
void func_80064980(s32 arg0);
void func_80064A70(u32 *buf, u32 size);
void func_80064B00(u32 *buf, u32 size);
s32 func_80064B8C(void);
s32 func_80064C20(void);
s32 func_80064CB4(void);
s32 func_80064CCC(char *msg);
void func_80063EB0(StrDecEnv *dec, s16 x0, s16 y0, s16 x1, s16 y1);
void func_80063FA0(u8 *arg0, void (*arg1)());
s32 func_80064110(StrDecEnv *dec);
void func_80064198(void);
void func_800642E8(StrDecEnv *dec, s32 mode);
void func_80064818(u32 *buf, s32 mode);
void func_800650D0(u8 *dst);
void func_80064D80(u32 *, u32 *, u32 *);

#endif
