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

/* Cd_GetFileEntry(0xD760000) record, stride 0x28, list ends at fileId == 0. */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x08];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x1B];
} Stg10EndPart; /* size 0x28 */

/* libpress DECDCTENV: quantization tables and DCT matrix (DecDCTGetEnv/PutEnv). */
typedef struct {
    /* 0x00 */ u8 iq_y[64];
    /* 0x40 */ u8 iq_c[64];
    /* 0x80 */ s16 dct[64];
} DecDCTEnv; /* size 0x100 */

/* Work of the title menu task (Stg10_TitleUpdate, Stg10_TitleDraw). */
typedef struct {
    /* 0x00 */ s32 field_0;         /* only cleared at task start, never read */
    u8 _pad04[0x04];
    /* 0x08 */ s32 menuOpen;
    /* 0x0C */ s32 cursor;          /* 0 new game, 1 -> gameMode 0x602, 2 -> 0x701 (two pads) */
    /* 0x10 */ s32 padWarning;
} Stg10TitleWork;

/* 0x28-stride part record of resource 0x1840000 (zero fileId ends the list). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x2];
    /* 0x06 */ s16 scrollX;
    u8 _pad08[0x4];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x1];
    /* 0x0E */ u8 unscaled;
    /* 0x0F */ u8 visible;
    u8 _pad10[0xC];
    /* 0x1C */ s32 partMask;
    u8 _pad20[0x8];
} Stg10TitlePart; /* size 0x28 */

/* The movie task's work area (Actor.work). */
typedef union {
    /* 0x00 */ s32 count;
    /* 0x00 */ u8 byte;
} StgWork;

/* main exe */
extern void DMACallback();
extern void printf();
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
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void ResetCallback(void);
#endif
extern u8 Sys_MovieActive;
extern PadState Pad_State[];
extern SysState Sys_State;
#ifdef DW2_NATIVE
/* stag1000 reads the libcd stream flag (psyq/libcd.h) as a byte. */
#define StCdIntrFlag (*(u8 *)&StCdIntrFlag)
#else
extern u8 StCdIntrFlag;              /* s32 in the main exe; read as a byte here (StCdIntrFlag) */
#endif
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdRead2(s32);           /* void in the main exe; returns CdControl's result */
extern void StSetRing(s32, s32);
extern void StSetStream(s32, s32, s32, s32, s32);
extern s32 StFreeRing(u32 *);
extern s32 StGetNext(u32 **, StrHeader **);
extern s32 CdControlB(u8, u8 *, u8 *);
extern void StUnSetRing(void);
#endif
extern void Mem_Free(ActorWork *arg0);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Task_NextState0(Actor *arg0);
extern void Task_NextState1(Actor *arg0);
extern void Task_NextState2(Actor *arg0);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Snd_PlayById(s32 id, s32 set);
extern void Snd_StopById(s32 id);
extern void Gfx_FadeOutToBlack(s32 arg0);
extern void Save_ResetGameState(void);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 ResetGraph(s32);
extern void ClearImage2();
extern void DrawSync();
extern void LoadImage();
#endif
extern void Gpu_ClearScreens(void);
extern void Gfx_DrawPartsNoResScale(s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void StCdInterrupt(void);
#endif

/* this overlay */
extern s32 Stg10_AttractCount;
extern void func_8006359C(void);
extern char D_80063360[];
extern char D_8006337C[];
extern char D_8006338C[];
extern char D_8006339C[];
extern RECT Stg10_VramClearRect;
extern s16 Stg10_MovieFileIds[];
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
extern u8 Stg10_VlcTablePacked[];
extern s32 Stg10_StrWidth;
extern s32 Stg10_StrHeight;
extern RECT Stg10_VramClearRect2;
extern volatile u32 *D_8006539C;
extern u32 *Stg10_StrRingBuf;
extern u32 *Stg10_VlcBuf0;
extern u32 *Stg10_VlcBuf1;
extern u32 *Stg10_ImgBuf0;
extern u32 *Stg10_ImgBuf1;
extern s32 Stg10_StrEndFlag;
extern s32 Stg10_MovieFileId;
extern s32 Stg10_MovieEndFrame;
extern StrDecEnv Stg10_DecEnv;
extern u32 *Stg10_VlcTable;

u32 *Stg10_StrNext(StrDecEnv *dec);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
void DecDCTReset(s32 arg0);
void DecDCTout(u32 *buf, s32 size);
void DecDCToutCallback(void (*func)());
#endif
void MDEC_reset(s32 arg0);
void MDEC_in(u32 *buf, u32 size);
void MDEC_out(u32 *buf, u32 size);
s32 MDEC_in_sync(void);
s32 MDEC_out_sync(void);
s32 func_80064CB4(void);
s32 func_80064CCC(char *msg);
void Stg10_StrSetDefDecEnv(StrDecEnv *dec, s16 x0, s16 y0, s16 x1, s16 y1);
void Stg10_StrInit(u8 *arg0, void (*arg1)());
s32 Stg10_StrNextVlc(StrDecEnv *dec);
void Stg10_StrCallback(void);
void Stg10_StrSync(StrDecEnv *dec, s32 mode);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
void DecDCTin(u32 *buf, s32 mode);
#endif
void Stg10_BuildVlcTable(u8 *dst);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
void DecDCTvlc2(u32 *, u32 *, u32 *);
#endif

/* Data one module defines and another uses (R3a split of stag1000.c). */
extern TaskDesc Stg10_EndScreenDesc;
extern TaskDesc Stg10_StageSetupDesc;
extern TaskDesc Stg10_TitleDesc;

#endif
