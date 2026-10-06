#include "common.h"
#include "stag1000/stag1000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg10_MovieInit(s32 arg0, s32 *arg1);
void Stg10_MovieUpdate(Actor *a0);
void Stg10_MovieDestroy(Actor *arg0);

s32 Stg10_StrWidth = 0;
s32 Stg10_StrHeight = 0;
RECT Stg10_VramClearRect2 = { 0, 0, 0x400, 0x200 };
TaskDesc Stg10_MovieDesc = {
    (TaskInitFn)Stg10_MovieInit, Stg10_MovieUpdate, Stg10_MovieDestroy, 0, 0xC, 0,
};
/* Task_DescTable[4]: task ids 0x400-0x403. */
TaskDesc *Stg10_TaskDescs[] = { &Stg10_StageSetupDesc, &Stg10_TitleDesc, &Stg10_MovieDesc, &Stg10_EndScreenDesc };

u32 *Stg10_StrRingBuf;
u32 *Stg10_VlcBuf0;
u32 *Stg10_VlcBuf1;
u32 *Stg10_ImgBuf0;
u32 *Stg10_ImgBuf1;
s32 Stg10_StrEndFlag;
s32 Stg10_MovieFileId;
s32 Stg10_MovieEndFrame;
StrDecEnv Stg10_DecEnv;
u32 *Stg10_VlcTable;

void Stg10_MovieInit(s32 arg0, s32 *arg1) {
    D_80050741 = 1;
    Stg10_MovieFileId = arg1[0];
    Stg10_MovieEndFrame = arg1[1];
}

void Stg10_StrSetDefDecEnv(StrDecEnv *dec, s16 x0, s16 y0, s16 x1, s16 y1) {
    dec->vlcbuf[0] = Stg10_VlcBuf0;
    dec->vlcbuf[1] = Stg10_VlcBuf1;
    dec->vlcid = Sys_State.bufIndex ^ 1;
    dec->imgbuf[0] = Stg10_ImgBuf0;
    dec->imgbuf[1] = Stg10_ImgBuf1;
    dec->imgid = Sys_State.bufIndex ^ 1;
    dec->rect[0].x = x0;
    dec->rect[0].y = y0;
    dec->rect[1].x = x1;
    dec->rect[1].y = y1;
    dec->rectid = Sys_State.bufIndex ^ 1;
    dec->slice.x = x0;
    dec->slice.y = y0;
    dec->slice.w = 0x18;
    dec->isdone = 0;
}

void Stg10_StrKickCd(u8 *arg0) {
    u8 mode = 0x80;

    do {
        while (CdControl(2, arg0, 0) == 0) {
        }
        while (CdControl(0xE, &mode, 0) == 0) {
        }
    } while (CdRead2(0x1E0) == 0);
}

void Stg10_StrInit(u8 *arg0, void (*arg1)()) {
    DecDCTReset(0);
    DecDCToutCallback(arg1);
    StSetRing((s32)Stg10_StrRingBuf, 0x20);
    StSetStream(1, 1, -1, 0, 0);
    Stg10_StrKickCd(arg0);
}

u32 *Stg10_StrNext(StrDecEnv *dec) {
    u32 *addr;
    StrHeader *sector;
    s32 cnt = 2000;

    while (StGetNext(&addr, &sector) != 0) {
        if (--cnt == 0) {
            return 0;
        }
    }
    if (sector->frameCount >= Stg10_MovieEndFrame) {
        Stg10_StrEndFlag = 1;
    }
    if (Stg10_StrWidth != sector->width || Stg10_StrHeight != sector->height) {
        Gpu_ClearScreens();
        Stg10_StrWidth = sector->width;
        Stg10_StrHeight = sector->height;
    }
    dec->rect[0].w = dec->rect[1].w = Stg10_StrWidth * 3 / 2;
    dec->rect[0].h = dec->rect[1].h = Stg10_StrHeight;
    dec->slice.h = Stg10_StrHeight;
    return addr;
}

s32 Stg10_StrNextVlc(StrDecEnv *dec) {
    s32 cnt = 2000;
    u32 *next;

    while ((next = Stg10_StrNext(dec)) == 0) {
        if (--cnt == 0) {
            return -1;
        }
    }
    dec->vlcid = dec->vlcid == 0;
    DecDCTvlc2(next, dec->vlcbuf[dec->vlcid], Stg10_VlcTable);
    StFreeRing(next);
    return 0;
}

void Stg10_StrCallback(void) {
    RECT snap;
    s32 id;

    if (StCdIntrFlag != 0) {
        StCdInterrupt();
        StCdIntrFlag = 0;
    }
    id = Stg10_DecEnv.imgid;
    snap = Stg10_DecEnv.slice;
    Stg10_DecEnv.imgid = Stg10_DecEnv.imgid ? 0 : 1;
    Stg10_DecEnv.slice.x += Stg10_DecEnv.slice.w;
    if (Stg10_DecEnv.rectid) {
        snap.x += 0x1E0;
    }
    snap.y = 0x24;
    if (Stg10_DecEnv.slice.x < Stg10_DecEnv.rect[Stg10_DecEnv.rectid].x + Stg10_DecEnv.rect[Stg10_DecEnv.rectid].w) {
        DecDCTout(Stg10_DecEnv.imgbuf[Stg10_DecEnv.imgid], Stg10_DecEnv.slice.w * Stg10_DecEnv.slice.h / 2);
    } else {
        Stg10_DecEnv.isdone = 1;
        Stg10_DecEnv.rectid = Stg10_DecEnv.rectid == 0;
        Stg10_DecEnv.slice.x = Stg10_DecEnv.rect[Stg10_DecEnv.rectid].x;
        Stg10_DecEnv.slice.y = Stg10_DecEnv.rect[Stg10_DecEnv.rectid].y;
    }
    DrawSync(0);
    LoadImage(&snap, Stg10_DecEnv.imgbuf[id]);
}

void Stg10_StrSync(StrDecEnv *dec, s32 mode) {
    volatile s32 cnt = 0x800000;

    while (dec->isdone == 0) {
        if (--cnt == 0) {
            dec->isdone = 1;
            dec->rectid = dec->rectid == 0;
            dec->slice.x = dec->rect[dec->rectid].x;
            dec->slice.y = dec->rect[dec->rectid].y;
        }
    }
    dec->isdone = 0;
}

void Stg10_MovieDestroy(Actor *arg0) {
    CdControlB(9, 0, 0);
    DecDCToutCallback(0);
    StUnSetRing();
    Mem_Free(Stg10_StrRingBuf);
    Mem_Free(Stg10_VlcBuf0);
    Mem_Free(Stg10_VlcBuf1);
    Mem_Free(Stg10_ImgBuf0);
    Mem_Free(Stg10_ImgBuf1);
    Mem_Free(Stg10_VlcTable);
    D_80050741 = 0;
    Task_DefaultDestroy(arg0);
    ResetGraph(1);
    ClearImage2(&Stg10_VramClearRect2, 0, 0, 0);
    DrawSync(0);
}

void Stg10_MovieUpdate(Actor *a0) {
    s32 st = a0->stateLevel0;
    ActorWork *work = a0->work;

    switch (st) {
    case 0:
        while (Cd_PollRead() != 0) {
        }
        Stg10_StrRingBuf = (u32 *)Mem_Alloc(0x10000, 2);
        Stg10_VlcBuf0 = (u32 *)Mem_Alloc(0x28000, 2);
        Stg10_VlcBuf1 = (u32 *)Mem_Alloc(0x28000, 2);
        Stg10_ImgBuf0 = (u32 *)Mem_Alloc(0x4E00, 2);
        Stg10_ImgBuf1 = (u32 *)Mem_Alloc(0x4E00, 2);
        Stg10_VlcTable = (u32 *)Mem_Alloc(0x11000, 2);
        Stg10_StrSetDefDecEnv(&Stg10_DecEnv, 0, 0, 0, 0x1A0);
        Cd_GetFilePos(Stg10_MovieFileId, work);
        Stg10_StrInit(work, Stg10_StrCallback);
        Stg10_BuildVlcTable(Stg10_VlcTable);
        Stg10_StrNextVlc(&Stg10_DecEnv);
        Stg10_StrEndFlag = 0;
        Task_NextState0(a0);
    case 1:
        DecDCTin(Stg10_DecEnv.vlcbuf[Stg10_DecEnv.vlcid], 3);
        DecDCTout(Stg10_DecEnv.imgbuf[Stg10_DecEnv.imgid],
                      Stg10_DecEnv.slice.w * Stg10_DecEnv.slice.h / 2);
        Stg10_StrNextVlc(&Stg10_DecEnv);
        Stg10_StrSync(&Stg10_DecEnv, 0);
        if (Stg10_StrEndFlag == 1 || Pad_State[0].start > 0) {
            switch (Sys_State.gameMode) {
            case 0x404:
                Sys_State.nextGameMode = 0x325;
                Sys_State.modeArg = 2;
                break;
            case 0x405:
                Sys_State.nextGameMode = 0x327;
                Sys_State.modeArg = 2;
                break;
            case 0x406:
                Sys_State.nextGameMode = 0x408;
                break;
            case 0x407:
                Sys_State.nextGameMode = 0x301;
                Sys_State.modeArg = 2;
                break;
            default:
                Sys_State.nextGameMode = 0x401;
                Sys_State.modeArg = 0;
                break;
            }
        }
        break;
    }
}
