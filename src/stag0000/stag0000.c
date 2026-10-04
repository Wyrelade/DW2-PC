#include "common.h"
#include "stag0000/stag0000.h"

void Stg00_StageSetup(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs a1;
    Stg00TaskArgs a2;
    Stg00TaskArgs a3;

    if (arg0->stateLevel0 == 0) {
        Task_Create(9, &slot[5], 0);
        switch (Sys_GameMode) {
        case 0x101:
        default:
            a1.field_0 = 0;
            a1.field_4 = -0xF00;
            a1.field_8 = -0x1900;
            a1.field_C = 0;
            a1.field_10 = 0;
            a1.field_14 = 0;
            a1.field_18 = 0x230;
            Task_Create(0x109, &slot[0], (s32)&a1);
            Task_Create(0x106, &slot[1], 0);
            Task_Create(0x108, &slot[2], 0);
            break;
        case 0x102:
            a2.field_0 = 0;
            a2.field_4 = -0xF00;
            a2.field_8 = -0x1900;
            a2.field_C = 0;
            a2.field_10 = 0;
            a2.field_14 = 0;
            a2.field_18 = 0x230;
            Task_Create(0x109, &slot[0], (s32)&a2);
            Task_Create(0x103, &slot[1], 0);
            Task_Create(0x106, &slot[2], 0);
            Task_Create(0x102, &slot[3], 0);
            break;
        case 0x103:
            a3.field_0 = 0;
            a3.field_4 = -0x1770;
            a3.field_8 = 0x5208;
            a3.field_C = 0;
            a3.field_10 = -0x2BC;
            a3.field_14 = 0;
            a3.field_18 = 0x5DC;
            Task_Create(0x109, &slot[0], (s32)&a3);
            Task_Create(0x106, &slot[1], 0);
            Task_Create(0x104, &slot[2], 0);
            break;
        case 0x104:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x107, &slot[6], 0);
            break;
        case 0x105:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x10A, &slot[7], 0);
            break;
        case 0x106:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x10D, &slot[7], 0);
            break;
        }
        Task_NextState0(arg0);
    }
}

void Stg00_ScrollViewTask(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        w->scrollX = 0;
        w->scrollY = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        if (Pad_State[0].up) {
            w->scrollY += 4;
        }
        if (Pad_State[0].down) {
            w->scrollY -= 4;
        }
        if (Pad_State[0].right) {
            w->scrollX -= 4;
        }
        if (Pad_State[0].left) {
            w->scrollX += 4;
        }
        if (w->scrollX > 0) {
            w->scrollX = 0;
        }
        if (w->scrollX < -0x3C0) {
            w->scrollX = -0x3C0;
        }
        if (w->scrollY > 0) {
            w->scrollY = 0;
        }
        if (w->scrollY < -0x300) {
            w->scrollY = -0x300;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_InitTileSprt(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3) {
    arg0->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
    arg0->tag.len = 4;
    arg0->c.code = 0x64;
    arg0->x0 = arg2;
    arg0->u0 = arg1->u;
    arg0->w = 0x40;
    arg0->y0 = arg3;
    arg0->v0 = 0;
    arg0->h = 0x100;
    arg0->clut = (arg1->index + 0x1E0) << 6;
}

void Stg00_ScrollViewDraw(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;
    GfxPartOTag *ot = (GfxPartOTag *)Sys_State.otLayers.addr[6];
    GfxPartPkt *p = (GfxPartPkt *)Sys_State.packet.addr;
    GfxPartTexSlot *t;
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(Stg00_ScrollTileTex[j % 10 + (i % 2) * 10]);
            x = w->scrollX - 0xA0;
            y = w->scrollY - 0x78;
            Stg00_InitTileSprt((Stg00Sprt *)&p->s, t, j * 64 + x, i * 256 + y);
            p->s.tag.addr = ot->addr;
            ot->addr = (u32)p;
            p = (GfxPartPkt *)(&p->s + 1);
            p->t.tag.len = 1;
            p->t.code = 0xE1000600 | (t->tpage & 0x9FF);
            p->t.tag.addr = ot->addr;
            ot->addr = (u32)p;
            p = (GfxPartPkt *)(&p->t + 1);
        }
    }
    Sys_PacketCursor = (s32)p;
}

void Stg00_RelocPtr(u32 *arg0, u32 arg1) {
    if (*arg0 < arg1) {
        *arg0 += arg1;
    }
}

s32 Stg00_RelocDungFile(u32 *arg0) {
    u32 base = (u32)arg0;
    s32 n = 0;

    while (*arg0 != 0) {
        if (*arg0 < base) {
            Stg00DungFloor *h;
            s32 i;

            *arg0 += base;
            h = (Stg00DungFloor *)*arg0;
            h->field_0 += base;
            for (i = 0; i < 8; i++) {
                Stg00DungLayout **pe = &h->layouts[i];
                Stg00DungLayout *e = (Stg00DungLayout *)((u32)*pe + base);
                *pe = e;
                Stg00_RelocPtr(&e->field_0, base);
                Stg00_RelocPtr(&e->field_4, base);
                Stg00_RelocPtr(&e->field_8, base);
                Stg00_RelocPtr(&e->cmdList, base);
                Stg00_RelocPtr(&e->field_10, base);
            }
        }
        arg0++;
        n++;
    }
    return n;
}

void Stg00_LoadDungFile(Actor *arg0, Stg00SelWork *arg1, s32 arg2) {
    u32 *f = (u32 *)Cd_GetFileOrNull(arg2);

    arg1->floorCount = Stg00_RelocDungFile(f);
    arg1->floorTable = f;
    arg1->firstFloor = f[0];
}

void Stg00_DungSelPickDungeon(Actor *arg0, Stg00SelWork *arg1) {
    Stg00DungEntry *e;

    if (Pad_Repeat & 0x8000) {
        if (arg1->dungeonIdx > 0) {
            arg1->dungeonIdx--;
        }
    }
    if (Pad_Repeat & 0x2000) {
        if (arg1->dungeonIdx + 1 < 0x23) {
            arg1->dungeonIdx++;
        }
    }
    if (Pad_Circle > 0) {
        arg1->floor = 0;
        arg1->lastFloor = -1;
        e = (Stg00DungEntry *)Cd_GetFileEntry(0xE20000A);
        Stg00_LoadDungFile(arg0, arg1, e[arg1->dungeonIdx].dungFileId);
        Task_SetState1(arg0, 1);
    }
}

void Stg00_DungSelPickFloor(Actor *arg0, Stg00SelWork *arg1_) {
    Stg00SelWorkX *arg1 = (Stg00SelWorkX *)arg1_;
    s32 i;
    s32 j;
    s32 bit;

    if (Pad_Repeat & 0x8000) {
        if (arg1->floor > 0) {
            arg1->floor--;
        }
    }
    if (Pad_Repeat & 0x2000) {
        if (arg1->floor + 1 < arg1->floorCount) {
            arg1->floor++;
        }
    }
    if (Pad_Repeat & 0x1000) {
        if (arg1->layout > 0) {
            arg1->layout--;
        }
    }
    if (Pad_Repeat & 0x4000) {
        if (arg1->layout + 1 < 8) {
            arg1->layout++;
        }
    }
    if (Pad_State[0].cross > 0) {
        Task_SetState1(arg0, 0);
        return;
    }
    if (Pad_State[0].circle > 0) {
        Task_SetState1(arg0, 2);
        return;
    }
    if (arg1->floor == arg1->lastFloor) {
        return;
    }
    for (i = 0; i < 8; i++) {
        arg1->layoutMasks[i] = Stg00_CalcLayoutMask((Stg00DungFloor *)arg1->floorTable[arg1->floor], i);
        arg1->maskBitCounts[i] = 0;
        for (j = 0; j < 32; j++) {
            bit = 1 << j;
            if (arg1->layoutMasks[i] & bit) {
                arg1->maskBitCounts[i]++;
            }
        }
        arg1->maskGroupCounts[i][7] = 0;
        arg1->maskGroupCounts[i][6] = 0;
        arg1->maskGroupCounts[i][5] = 0;
        arg1->maskGroupCounts[i][4] = 0;
        arg1->maskGroupCounts[i][3] = 0;
        arg1->maskGroupCounts[i][2] = 0;
        arg1->maskGroupCounts[i][1] = 0;
        arg1->maskGroupCounts[i][0] = 0;
        if (arg1->layoutMasks[i] & 1) {
            arg1->maskGroupCounts[i][0] = 1;
        }
        if (arg1->layoutMasks[i] & 0x20) {
            arg1->maskGroupCounts[i][1]++;
        }
        if (arg1->layoutMasks[i] & 0x40) {
            arg1->maskGroupCounts[i][1]++;
        }
        if (arg1->layoutMasks[i] & 0x80) {
            arg1->maskGroupCounts[i][1]++;
        }
        if (arg1->layoutMasks[i] & 0x100) {
            arg1->maskGroupCounts[i][1]++;
        }
        if (arg1->layoutMasks[i] & 0x200) {
            arg1->maskGroupCounts[i][1]++;
        }
        if (arg1->layoutMasks[i] & 0x400) {
            arg1->maskGroupCounts[i][2]++;
        }
        if (arg1->layoutMasks[i] & 0x800) {
            arg1->maskGroupCounts[i][2]++;
        }
        if (arg1->layoutMasks[i] & 0x1000) {
            arg1->maskGroupCounts[i][2]++;
        }
        if (arg1->layoutMasks[i] & 0x2000) {
            arg1->maskGroupCounts[i][2]++;
        }
        if (arg1->layoutMasks[i] & 0x4000) {
            arg1->maskGroupCounts[i][2]++;
        }
        if (arg1->layoutMasks[i] & 0x8000) {
            arg1->maskGroupCounts[i][3]++;
        }
        if (arg1->layoutMasks[i] & 0x10000) {
            arg1->maskGroupCounts[i][3]++;
        }
        if (arg1->layoutMasks[i] & 0x20000) {
            arg1->maskGroupCounts[i][3]++;
        }
        if (arg1->layoutMasks[i] & 0x40000) {
            arg1->maskGroupCounts[i][3]++;
        }
        if (arg1->layoutMasks[i] & 0x80000) {
            arg1->maskGroupCounts[i][3]++;
        }
        if (arg1->layoutMasks[i] & 0x100000) {
            arg1->maskGroupCounts[i][4]++;
        }
        if (arg1->layoutMasks[i] & 0x200000) {
            arg1->maskGroupCounts[i][4]++;
        }
        if (arg1->layoutMasks[i] & 0x400000) {
            arg1->maskGroupCounts[i][4]++;
        }
        if (arg1->layoutMasks[i] & 0x800000) {
            arg1->maskGroupCounts[i][5]++;
        }
        if (arg1->layoutMasks[i] & 0x1000000) {
            arg1->maskGroupCounts[i][5]++;
        }
        if (arg1->layoutMasks[i] & 0x2000000) {
            arg1->maskGroupCounts[i][5]++;
        }
        if (arg1->layoutMasks[i] & 0x4000000) {
            arg1->maskGroupCounts[i][6]++;
        }
        if (arg1->layoutMasks[i] & 0x8000000) {
            arg1->maskGroupCounts[i][6]++;
        }
        if (arg1->layoutMasks[i] & 0x10000000) {
            arg1->maskGroupCounts[i][6]++;
        }
        if (arg1->layoutMasks[i] & 0x20000000) {
            arg1->maskGroupCounts[i][7]++;
        }
        if (arg1->layoutMasks[i] & 0x40000000) {
            arg1->maskGroupCounts[i][7]++;
        }
        if (arg1->layoutMasks[i] & 0x80000000) {
            arg1->maskGroupCounts[i][7]++;
        }
    }
    arg1->lastFloor = arg1->floor;
}

void Stg00_DungSelPickFlag(Actor *arg0, Stg00SelWork *arg1) {
    if (Pad_Repeat & 0x8000) {
        if (arg1->flagIdx > 0) {
            arg1->flagIdx--;
        }
    }
    if (Pad_Repeat & 0x2000) {
        if (arg1->flagIdx + 1 < 0x1E) {
            arg1->flagIdx++;
        }
    }
    if (Pad_State[0].cross > 0) {
        Task_SetState1(arg0, 1);
    } else if (Pad_State[0].circle > 0) {
        func_80064E44();
        Sys_NextGameMode = arg1->dungeonIdx + 0x201;
        D_8005071C->floor = arg1->floor;
        D_8005071C->floorLayout = arg1->layout;
        Flag_Set(arg1->flagIdx + 0x76C, 1);
        Task_SetState0(arg0, 2);
    }
}

void Stg00_DungSelInit(void) {
}

void Stg00_DungSelTask(Actor *arg0) {
    Stg00SelWork *w = (Stg00SelWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        Stg00_FontInit();
        Stg00_FontSetColor(0);
        w->dungeonIdx = 0;
        w->floor = 0;
        w->floorCount = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Stg00_DungSelPickDungeon(arg0, w);
            break;
        case 1:
            Stg00_DungSelPickFloor(arg0, w);
            break;
        case 2:
            Stg00_DungSelPickFlag(arg0, w);
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_DungSelDraw(void) {
}

void Stg00_DungSelDestroy(Actor *arg0) {
    Stg00_FontFree();
    Task_DefaultDestroy(arg0);
}

INCLUDE_RODATA("asm/USA/stag0000/rodata", Stg00_LayoutMaskBits);
s32 Stg00_CalcLayoutMask(Stg00DungFloor *arg0, s32 arg1) {
    s32 result = 0;
    Stg00BitTbl tbl = Stg00_LayoutMaskBits;
    s32 i;
    s32 code;
    s32 val;
    s32 n;
    Stg00RelocCmd *cmd;

    for (i = 0; i < 8; i++) {
        code = arg0->field_34[i].field_0;
        if (code != 0) {
            result |= 1;
        }
    }
    for (i = 0; i < 5; i++) {
        u32 chk = arg0->field_54[i].chk;
        code = (chk & 0xF) + ((chk >> 4) & 0xF) + ((chk >> 8) & 0xF) + ((chk >> 12) & 0xF);
        if (code != 0) {
            u32 sel = arg0->field_54[i].sel;
            val = sel & 0xF;
            result |= tbl.bits[i][val];
            val = (sel >> 4) & 0xF;
            result |= tbl.bits[i][val];
            val = (sel >> 8) & 0xF;
            result |= tbl.bits[i][val];
            val = (sel >> 12) & 0xF;
            result |= tbl.bits[i][val];
        }
    }
    cmd = (Stg00RelocCmd *)arg0->layouts[arg1]->cmdList;
    while (cmd->field_0.tag != 0xFF) {
        for (i = 0; i < 4; i++) {
            switch (i) {
            case 0:
            default:
                code = cmd->field_0.bits >> 16;
                code &= 0xF;
                val = cmd->field_0.bits >> 20;
                val &= 0xF;
                break;
            case 1:
                code = cmd->field_0.bits >> 24;
                code &= 0xF;
                val = cmd->field_0.bits >> 28;
                break;
            case 2:
                code = cmd->field_4 & 0xF;
                val = cmd->field_4 >> 4;
                val &= 0xF;
                break;
            case 3:
                code = cmd->field_4 >> 8;
                code &= 0xF;
                val = cmd->field_4 >> 12;
                val &= 0xF;
                break;
            }
            val += arg0->field_2E;
            switch (code - 2) {
            case 0:
                n = val >= 5 ? 5 : val;
                result |= 0x8000 << (n - 1);
                break;
            case 1:
                n = val >= 5 ? 5 : val;
                result |= 0x400 << (n - 1);
                break;
            case 2:
                n = val >= 5 ? 5 : val;
                result |= 0x20 << (n - 1);
                break;
            case 3:
                n = val >= 3 ? 3 : val;
                result |= 0x100000 << (n - 1);
                break;
            case 4:
                n = val >= 3 ? 3 : val;
                result |= 0x800000 << (n - 1);
                break;
            case 5:
                n = val >= 3 ? 3 : val;
                result |= 0x20000000 << (n - 1);
                break;
            case 6:
                n = val >= 3 ? 3 : val;
                result |= 0x4000000 << (n - 1);
                break;
            }
        }
        cmd++;
    }
    return result;
}
