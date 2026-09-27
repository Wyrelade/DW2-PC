#include "common.h"
#include "stag1000/stag1000.h"

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800633B0);

void func_8006359C(void) {
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800635A4);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800638D4);

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

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064454);

void func_800646C0(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    func_80064980(arg0);
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800646F4);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064780);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_80064818);

void func_80064894(u32 *buf, s32 size) {
    func_80064B00(buf, size);
}

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800648B4);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000", func_800648F0);

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
