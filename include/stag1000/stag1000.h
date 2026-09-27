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

/* The movie task's work area (Actor.work). */
typedef union {
    /* 0x00 */ s32 count;
    /* 0x00 */ u8 byte;
} StgWork;

/* main exe */
extern void DMACallback();
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
extern s32 D_80065220;
extern s32 D_80065224;
extern s32 D_80065228;
extern s32 *D_8006539C;
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
void func_80064B00(u32 *buf, s32 size);
void func_80064D80(u32 *, u32 *, u32 *);

#endif
