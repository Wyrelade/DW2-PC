#include "common.h"
#include "stag1000/stag1000.h"

void func_800633B0(Actor *a0) {
    s32 args[2];
    s32 *slot = (s32 *)a0->u34.children;

    if (a0->stateLevel0 != 0) {
        return;
    }
    switch (D_8005F770.gameMode) {
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
        ClearImage2((s32)&D_800651C0, 0, 0, 0);
        DrawSync(0);
        D_8005F770.bufIndex = 0;
        Snd_StopAll();
        args[0] = D_800651C8[D_8005F770.gameMode - 0x402];
        args[1] = Cd_GetFileSectors(args[0]) / 10 - 10;
        Task_Create(0x402, slot + 2, (s32)args);
        break;
    }
    Task_NextState0(a0);
}

void func_8006359C(void) {
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800635A4);

void func_800638D4(Actor *a0) {
    Stag1000Menu *w = (Stag1000Menu *)a0->work;
    Stag1000Part *list = (Stag1000Part *)Cd_GetFileEntry(0x1840000);
    Stag1000Part *p = list;

    if (p->fileId != 0) {
        do {
            if (p->partMask & 0x2) {
                p->field_6 = p->field_6 < -0x1D9 ? 0 : p->field_6 - 1;
            }
            if (p->partMask & 0x100) {
                p->field_6 = p->field_6 < -0x1C9 ? 0 : p->field_6 - 2;
            }
            if (p->partMask & 0x200) {
                p->field_6 = p->field_6 < 3 ? 0x1CC : p->field_6 - 2;
            }
            if (p->partMask & 0x400) {
                p->field_6 = p->field_6 < 0x1CF ? 0x398 : p->field_6 - 2;
            }
            if (D_8005F770.frameCount & 1) {
                if (p->partMask & 0x800) {
                    p->field_6 = p->field_6 < -0x2CE ? 0 : p->field_6 - 1;
                }
                if (p->partMask & 0x1000) {
                    p->field_6 = p->field_6 < 2 ? 0x2D0 : p->field_6 - 1;
                }
                if (p->partMask & 0x2000) {
                    p->field_6 = p->field_6 < 0x2D2 ? 0x5A0 : p->field_6 - 1;
                }
            }
            if (p->partMask & 0x3F00) {
                p->palette = Math_CycleRange(a0->elapsed, 6, 0, 0xF);
            }
            switch (w->field_8) {
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
                if (w->field_10 == 0) {
                switch (w->field_C) {
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
    func_8001D8A4((s32)list);
}

void func_80063D34(Actor *arg0) {
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
            if (D_8005F6F0[0].cross > 0 || D_8005F6F0[0].start > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 2:
            if (--w->count == 0) {
                D_8005F78C = 0x407;
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

void func_80063E24(Actor *arg0) {
    StgWork *w = (StgWork *)arg0->work;
    StgFileEntry *e = (StgFileEntry *)Cd_GetFileEntry(0xD760000);
    StgFileEntry *p;

    for (p = e; p->field_0 != 0; p++) {
        p->field_C = w->byte;
    }
    func_8001D8A4((s32)e);
}

void func_80063E88(s32 arg0, s32 *arg1) {
    D_80050741 = 1;
    D_80066200 = arg1[0];
    D_80066204 = arg1[1];
}

void func_80063EB0(StrDecEnv *dec, s16 x0, s16 y0, s16 x1, s16 y1) {
    dec->vlcbuf[0] = D_800661EC;
    dec->vlcbuf[1] = D_800661F0;
    dec->vlcid = D_8005F770.bufIndex ^ 1;
    dec->imgbuf[0] = D_800661F4;
    dec->imgbuf[1] = D_800661F8;
    dec->imgid = D_8005F770.bufIndex ^ 1;
    dec->rect[0].x = x0;
    dec->rect[0].y = y0;
    dec->rect[1].x = x1;
    dec->rect[1].y = y1;
    dec->rectid = D_8005F770.bufIndex ^ 1;
    dec->slice.x = x0;
    dec->slice.y = y0;
    dec->slice.w = 0x18;
    dec->isdone = 0;
}

void func_80063F38(u8 *arg0) {
    u8 mode = 0x80;

    do {
        while (CdControl(2, arg0, 0) == 0) {
        }
        while (CdControl(0xE, &mode, 0) == 0) {
        }
    } while (CdRead2(0x1E0) == 0);
}

void func_80063FA0(u8 *arg0, void (*arg1)()) {
    func_800646C0(0);
    func_8006495C(arg1);
    StSetRing((s32)D_800661E8, 0x20);
    StSetStream(1, 1, -1, 0, 0);
    func_80063F38(arg0);
}

u32 *func_8006400C(StrDecEnv *dec) {
    u32 *addr;
    StrHeader *sector;
    s32 cnt = 2000;

    while (StGetNext(&addr, &sector) != 0) {
        if (--cnt == 0) {
            return 0;
        }
    }
    if (sector->frameCount >= D_80066204) {
        D_800661FC = 1;
    }
    if (D_80065220 != sector->width || D_80065224 != sector->height) {
        Gpu_ClearScreens();
        D_80065220 = sector->width;
        D_80065224 = sector->height;
    }
    dec->rect[0].w = dec->rect[1].w = D_80065220 * 3 / 2;
    dec->rect[0].h = dec->rect[1].h = D_80065224;
    dec->slice.h = D_80065224;
    return addr;
}

s32 func_80064110(StrDecEnv *dec) {
    s32 cnt = 2000;
    u32 *next;

    while ((next = func_8006400C(dec)) == 0) {
        if (--cnt == 0) {
            return -1;
        }
    }
    dec->vlcid = dec->vlcid == 0;
    func_80064D80(next, dec->vlcbuf[dec->vlcid], D_80066240);
    StFreeRing(next);
    return 0;
}

void func_80064198(void) {
    RECT snap;
    s32 id;

    if (D_80061B04 != 0) {
        func_8002E2C4();
        D_80061B04 = 0;
    }
    id = D_80066208.imgid;
    snap = D_80066208.slice;
    D_80066208.imgid = D_80066208.imgid ? 0 : 1;
    D_80066208.slice.x += D_80066208.slice.w;
    if (D_80066208.rectid) {
        snap.x += 0x1E0;
    }
    snap.y = 0x24;
    if (D_80066208.slice.x < D_80066208.rect[D_80066208.rectid].x + D_80066208.rect[D_80066208.rectid].w) {
        func_80064894(D_80066208.imgbuf[D_80066208.imgid], D_80066208.slice.w * D_80066208.slice.h / 2);
    } else {
        D_80066208.isdone = 1;
        D_80066208.rectid = D_80066208.rectid == 0;
        D_80066208.slice.x = D_80066208.rect[D_80066208.rectid].x;
        D_80066208.slice.y = D_80066208.rect[D_80066208.rectid].y;
    }
    DrawSync(0);
    LoadImage(&snap, D_80066208.imgbuf[id]);
}

void func_800642E8(StrDecEnv *dec, s32 mode) {
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

void func_8006437C(Actor *arg0) {
    CdControlB(9, 0, 0);
    func_8006495C(0);
    StUnSetRing();
    Mem_Free(D_800661E8);
    Mem_Free(D_800661EC);
    Mem_Free(D_800661F0);
    Mem_Free(D_800661F4);
    Mem_Free(D_800661F8);
    Mem_Free(D_80066240);
    D_80050741 = 0;
    Task_DefaultDestroy(arg0);
    ResetGraph(1);
    ClearImage2(&D_80065228, 0, 0, 0);
    DrawSync(0);
}

void func_80064454(Actor *a0) {
    s32 st = a0->stateLevel0;
    ActorWork *work = a0->work;

    switch (st) {
    case 0:
        while (Cd_PollRead() != 0) {
        }
        D_800661E8 = (u32 *)Mem_Alloc(0x10000, 2);
        D_800661EC = (u32 *)Mem_Alloc(0x28000, 2);
        D_800661F0 = (u32 *)Mem_Alloc(0x28000, 2);
        D_800661F4 = (u32 *)Mem_Alloc(0x4E00, 2);
        D_800661F8 = (u32 *)Mem_Alloc(0x4E00, 2);
        D_80066240 = (u32 *)Mem_Alloc(0x11000, 2);
        func_80063EB0(&D_80066208, 0, 0, 0, 0x1A0);
        Cd_GetFilePos(D_80066200, work);
        func_80063FA0(work, func_80064198);
        func_800650D0(D_80066240);
        func_80064110(&D_80066208);
        D_800661FC = 0;
        Task_NextState0(a0);
    case 1:
        func_80064818(D_80066208.vlcbuf[D_80066208.vlcid], 3);
        func_80064894(D_80066208.imgbuf[D_80066208.imgid],
                      D_80066208.slice.w * D_80066208.slice.h / 2);
        func_80064110(&D_80066208);
        func_800642E8(&D_80066208, 0);
        if (D_800661FC == 1 || D_8005F724 > 0) {
            switch (D_8005F770.gameMode) {
            case 0x404:
                D_8005F770.nextGameMode = 0x325;
                D_8005F770.field_24 = 2;
                break;
            case 0x405:
                D_8005F770.nextGameMode = 0x327;
                D_8005F770.field_24 = 2;
                break;
            case 0x406:
                D_8005F770.nextGameMode = 0x408;
                break;
            case 0x407:
                D_8005F770.nextGameMode = 0x301;
                D_8005F770.field_24 = 2;
                break;
            default:
                D_8005F770.nextGameMode = 0x401;
                D_8005F770.field_24 = 0;
                break;
            }
        }
        break;
    }
}

void func_800646C0(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    func_80064980(arg0);
}

DecDCTEnv *func_800646F4(DecDCTEnv *env) {
    u32 *dst;
    u32 *src;
    s32 i;

    dst = (u32 *)env->iq_y;
    src = D_8006525C;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = (u32 *)env->iq_c;
    src = D_8006529C;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = (u32 *)env->dct;
    src = D_800652E0;
    for (i = 31; i != -1; i--) {
        *dst++ = *src++;
    }
    return env;
}

DecDCTEnv *func_80064780(DecDCTEnv *env) {
    u32 *dst;
    u32 *src;
    s32 i;

    dst = D_8006525C;
    src = (u32 *)env->iq_y;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    dst = D_8006529C;
    src = (u32 *)env->iq_c;
    for (i = 15; i != -1; i--) {
        *dst++ = *src++;
    }
    func_80064A70(&D_80065258, 0x20);
    func_80064A70(&D_800652DC, 0x20);
    return env;
}

void func_80064818(u32 *arg0, s32 arg1) {
    if (arg1 & 1) {
        *arg0 &= ~0x08000000;
    } else {
        *arg0 |= 0x08000000;
    }
    if (arg1 & 2) {
        *arg0 |= 0x02000000;
    } else {
        *arg0 &= ~0x02000000;
    }
    func_80064A70(arg0, *arg0 & 0xFFFF);
}

void func_80064894(u32 *buf, s32 size) {
    func_80064B00(buf, size);
}

s32 func_800648B4(s32 arg0) {
    if (arg0 != 0) {
        return ((u32)func_80064CB4() >> 29) & 1;
    }
    return func_80064B8C();
}

s32 func_800648F0(s32 arg0) {
    if (arg0 != 0) {
        return (*D_8006537C >> 24) & 1;
    }
    return func_80064C20();
}

void func_80064938(void (*func)()) {
    DMACallback(0, func);
}

void func_8006495C(void (*func)()) {
    DMACallback(1, func);
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064980);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064A70);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064B00);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064B8C);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064C20);

s32 func_80064CB4(void) {
    return *D_8006539C;
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064CCC);

ASM_SOURCE("src/stag1000/asm/libpress", func_80064D50);

ASM_SOURCE("src/stag1000/asm/libpress", func_80064D80);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800650D0);
