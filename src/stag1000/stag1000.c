#include "common.h"
#include "stag1000/stag1000.h"

void Stg10_StageSetup(Actor *a0) {
    s32 args[2];
    s32 *slot = (s32 *)a0->u34.children;

    if (a0->stateLevel0 != 0) {
        return;
    }
    switch (Sys_State.gameMode) {
    case 0x401:
    default:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gfx_InitTexSlots();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        Task_Create(0x401, slot + 1, 0);
        Snd_StopAll();
        break;
    case 0x408:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeClear();
        Task_Create(0x403, slot + 1, 0);
        break;
    case 0x402:
    case 0x403:
    case 0x404:
    case 0x405:
    case 0x406:
    case 0x407:
        Gpu_AllocPacketBufs(0x400);
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 1);
        ResetGraph(1);
        ClearImage2((s32)&Stg10_VramClearRect, 0, 0, 0);
        DrawSync(0);
        Sys_State.bufIndex = 0;
        Snd_StopAll();
        args[0] = Stg10_MovieFileIds[Sys_State.gameMode - 0x402];
        args[1] = Cd_GetFileSectors(args[0]) / 10 - 10;
        Task_Create(0x402, slot + 2, (s32)args);
        break;
    }
    Task_NextState0(a0);
}

/* Unnamed: empty stub, called only from Stg10_TitleUpdate cursor case 3, no other ref. */
void func_8006359C(void) {
}

void Stg10_TitleUpdate(Actor *a0) {
    Stg10TitleWork *w = (Stg10TitleWork *)a0->work;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        do {
            Snd_PlayById(0x31, 1);
            w->field_0 = 0;
            w->cursor = 1;
            Task_NextState0(a0);
        } while (0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->menuOpen = 0;
            if (Pad_State[0].start > 0) {
                Snd_PlayById(0x11, 0);
                Task_NextState1(a0);
            }
            switch (a0->stateLevel2) {
            case 0:
            default:
                if (a0->elapsed >= 600) {
                    if (Stg10_AttractCount == 0) {
                        Sys_NextGameMode = 0x403;
                    } else {
                        Sys_NextGameMode = 0x402;
                    }
                    if (++Stg10_AttractCount == 20) {
                        Stg10_AttractCount = 0;
                    }
                    Task_NextState2(a0);
                }
                break;
            case 1:
                break;
            }
            break;
        case 1:
            w->menuOpen = 1;
            {
                PadState *pad;
                PadState *p;

                do {
                    pad = Pad_State;
                    if (pad[0].down > 0 && w->cursor != 2) {
                        v = w->cursor + 1;
                        goto snd;
                    }
                } while (0);
                p = pad;
                if (pad[0].up > 0 && w->cursor != 0) {
                    v = w->cursor - 1;
                    goto snd;
                }
                if (p->start > 0 || p->cross > 0) {
                    Snd_PlayById(0x11, 0);
                    if (w->cursor == 2 && (pad[0].connected == 0 || pad[1].connected == 0)) {
                        Task_NextState1(a0);
                    } else {
                        Task_NextState0(a0);
                    }
                }
            }
            break;
        case 2:
            do {
                w->padWarning = 1;
                if (Pad_State[0].start > 0) {
                    w->padWarning = 0;
                    Task_SetState1(a0, 1);
                }
            } while (0);
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Snd_StopById(0x31);
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(a0);
        case 1:
            if (++a0->stateLevel4 >= 20) {
                switch (w->cursor) {
                case 0:
                default:
                    Save_ResetGameState();
                    Sys_State.nextGameMode = 0x307;
                    Sys_State.modeArg = 4;
                    break;
                case 1:
                    Sys_State.nextGameMode = 0x602;
                    Sys_State.modeArg = 0;
                    break;
                case 2:
                    Sys_State.nextGameMode = 0x701;
                    Sys_State.modeArg = 0;
                    break;
                snd:
                    w->cursor = v;
                    Snd_PlayById(0xC, 0);
                    break;
                case 3:
                    func_8006359C();
                    Task_NextState2(a0);
                    break;
                }
            }
            break;
        case 2:
            break;
        }
        break;
    }
}

void Stg10_TitleDraw(Actor *a0) {
    Stg10TitleWork *w = (Stg10TitleWork *)a0->work;
    Stg10TitlePart *list = (Stg10TitlePart *)Cd_GetFileEntry(0x1840000);
    Stg10TitlePart *p = list;

    if (p->fileId != 0) {
        do {
            if (p->partMask & 0x2) {
                p->scrollX = p->scrollX < -0x1D9 ? 0 : p->scrollX - 1;
            }
            if (p->partMask & 0x100) {
                p->scrollX = p->scrollX < -0x1C9 ? 0 : p->scrollX - 2;
            }
            if (p->partMask & 0x200) {
                p->scrollX = p->scrollX < 3 ? 0x1CC : p->scrollX - 2;
            }
            if (p->partMask & 0x400) {
                p->scrollX = p->scrollX < 0x1CF ? 0x398 : p->scrollX - 2;
            }
            if (Sys_State.frameCount & 1) {
                if (p->partMask & 0x800) {
                    p->scrollX = p->scrollX < -0x2CE ? 0 : p->scrollX - 1;
                }
                if (p->partMask & 0x1000) {
                    p->scrollX = p->scrollX < 2 ? 0x2D0 : p->scrollX - 1;
                }
                if (p->partMask & 0x2000) {
                    p->scrollX = p->scrollX < 0x2D2 ? 0x5A0 : p->scrollX - 1;
                }
            }
            if (p->partMask & 0x3F00) {
                p->palette = Math_CycleRange(a0->elapsed, 6, 0, 0xF);
            }
            switch (w->menuOpen) {
            case 0:
            default:
                if (p->partMask & 0x10) {
                    p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                }
                if (p->partMask & 0xEC) {
                    p->visible = 0;
                } else {
                    p->visible = 1;
                }
                break;
            case 1:
                if (w->padWarning == 0) {
                switch (w->cursor) {
                case 0:
                default:
                    if (p->partMask & 0x20) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 1:
                    if (p->partMask & 0x40) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 2:
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 3:
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    break;
                }
                if (p->partMask & 0x18) {
                    p->visible = 0;
                } else {
                    p->visible = 1;
                }
                } else {
                    Gfx_HidePartsByMask((GfxPartMaskView *)list, 0xF4);
                }
                break;
            }
            p->unscaled = 1;
            p++;
        } while (p->fileId != 0);
    }
    Gfx_DrawPartsNoResScale((s32)list);
}

void Stg10_EndScreenUpdate(Actor *arg0) {
    StgWork *w = (StgWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (++w->count != 7) {
                break;
            }
            Task_NextState1(arg0);
        case 1:
            if (Pad_State[0].cross > 0 || Pad_State[0].start > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 2:
            if (--w->count == 0) {
                Sys_NextGameMode = 0x407;
                Task_NextState1(arg0);
            }
            break;
        case 3:
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg10_EndScreenDraw(Actor *arg0) {
    StgWork *w = (StgWork *)arg0->work;
    Stg10EndPart *e = (Stg10EndPart *)Cd_GetFileEntry(0xD760000);
    Stg10EndPart *p;

    for (p = e; p->fileId != 0; p++) {
        p->palette = w->byte;
    }
    Gfx_DrawPartsNoResScale((s32)e);
}

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
        if (Stg10_StrEndFlag == 1 || D_8005F724 > 0) {
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
