#include "common.h"
#include "stag0000/stag0000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_DungSelInit(void);
void Stg00_DungSelTask(Actor *arg0);
void Stg00_DungSelDestroy(Actor *arg0);
void Stg00_DungSelDraw(void);

TaskDesc Stg00_DungSelDesc = {
    (TaskInitFn)Stg00_DungSelInit, Stg00_DungSelTask, Stg00_DungSelDestroy, (TaskFn)Stg00_DungSelDraw, 0x94, 0,
};

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
        Dung_StatePtr->floor = arg1->floor;
        Dung_StatePtr->floorLayout = arg1->layout;
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

const Stg00BitTbl Stg00_LayoutMaskBits = {{
    { 0x00000000, 0x00000020, 0x00000040, 0x00000080, 0x00000100, 0x00000200 },
    { 0x00000000, 0x00100000, 0x00200000, 0x00400000, 0x00400000, 0x00400000 },
    { 0x00000000, 0x00800000, 0x01000000, 0x02000000, 0x02000000, 0x02000000 },
    { 0x00000000, 0x20000000, 0x40000000, 0x80000000, 0x80000000, 0x80000000 },
    { 0x00000000, 0x04000000, 0x08000000, 0x10000000, 0x10000000, 0x10000000 },
}};
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
