#include "common.h"
#include "stag0000/stag0000.h"

void func_80063A74(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs a1;
    Stg00TaskArgs a2;
    Stg00TaskArgs a3;

    if (arg0->stateLevel0 == 0) {
        Task_Create(9, &slot[5], 0);
        switch (D_8005F788) {
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

void func_80063D04(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        w->field_0 = 0;
        w->field_4 = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        if (D_8005F6F0[0].up) {
            w->field_4 += 4;
        }
        if (D_8005F6F0[0].down) {
            w->field_4 -= 4;
        }
        if (D_8005F6F0[0].right) {
            w->field_0 -= 4;
        }
        if (D_8005F6F0[0].left) {
            w->field_0 += 4;
        }
        if (w->field_0 > 0) {
            w->field_0 = 0;
        }
        if (w->field_0 < -0x3C0) {
            w->field_0 = -0x3C0;
        }
        if (w->field_4 > 0) {
            w->field_4 = 0;
        }
        if (w->field_4 < -0x300) {
            w->field_4 = -0x300;
        }
        break;
    case 2:
        break;
    }
}

void func_80063E34(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3) {
    arg0->c = *(Col1A9C8 *)&D_8005074C;
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

void func_80063E9C(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;
    GfxPartOTag *ot = (GfxPartOTag *)D_8005F770.otLayers.addr[6];
    GfxPartPkt *p = (GfxPartPkt *)D_8005F770.packet.addr;
    GfxPartTexSlot *t;
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(D_80068AA0[j % 10 + (i % 2) * 10]);
            x = w->field_0 - 0xA0;
            y = w->field_4 - 0x78;
            func_80063E34((Stg00Sprt *)&p->s, t, j * 64 + x, i * 256 + y);
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
    D_8005F79C = (s32)p;
}

void func_80064064(u32 *arg0, u32 arg1) {
    if (*arg0 < arg1) {
        *arg0 += arg1;
    }
}

s32 func_80064084(u32 *arg0) {
    u32 base = (u32)arg0;
    s32 n = 0;

    while (*arg0 != 0) {
        if (*arg0 < base) {
            Stg00RelocHdr *h;
            s32 i;

            *arg0 += base;
            h = (Stg00RelocHdr *)*arg0;
            h->field_0 += base;
            for (i = 0; i < 8; i++) {
                Stg00RelocEnt **pe = &h->field_8[i];
                Stg00RelocEnt *e = (Stg00RelocEnt *)((u32)*pe + base);
                *pe = e;
                func_80064064(&e->field_0, base);
                func_80064064(&e->field_4, base);
                func_80064064(&e->field_8, base);
                func_80064064(&e->field_C, base);
                func_80064064(&e->field_10, base);
            }
        }
        arg0++;
        n++;
    }
    return n;
}

void func_80064190(Actor *arg0, Stg00SelWork *arg1, s32 arg2) {
    u32 *f = (u32 *)Cd_GetFileOrNull(arg2);

    arg1->field_6 = func_80064084(f);
    arg1->field_C = f;
    arg1->field_10 = f[0];
}

void func_800641E0(Actor *arg0, Stg00SelWork *arg1) {
    Stg00SelEnt *e;

    if (D_8005F72C & 0x8000) {
        if (arg1->field_0 > 0) {
            arg1->field_0--;
        }
    }
    if (D_8005F72C & 0x2000) {
        if (arg1->field_0 + 1 < 0x23) {
            arg1->field_0++;
        }
    }
    if (D_8005F700 > 0) {
        arg1->field_2 = 0;
        arg1->field_4 = -1;
        e = (Stg00SelEnt *)Cd_GetFileEntry(0xE20000A);
        func_80064190(arg0, arg1, e[arg1->field_0].field_0);
        Task_SetState1(arg0, 1);
    }
}

void func_800642BC(Actor *arg0, Stg00SelWork *arg1_) {
    Stg00SelWorkX *arg1 = (Stg00SelWorkX *)arg1_;
    s32 i;
    s32 j;
    s32 bit;

    if (D_8005F72C & 0x8000) {
        if (arg1->field_2 > 0) {
            arg1->field_2--;
        }
    }
    if (D_8005F72C & 0x2000) {
        if (arg1->field_2 + 1 < arg1->field_6) {
            arg1->field_2++;
        }
    }
    if (D_8005F72C & 0x1000) {
        if (arg1->field_8 > 0) {
            arg1->field_8--;
        }
    }
    if (D_8005F72C & 0x4000) {
        if (arg1->field_8 + 1 < 8) {
            arg1->field_8++;
        }
    }
    if (D_8005F6F0[0].cross > 0) {
        Task_SetState1(arg0, 0);
        return;
    }
    if (D_8005F6F0[0].circle > 0) {
        Task_SetState1(arg0, 2);
        return;
    }
    if (arg1->field_2 == arg1->field_4) {
        return;
    }
    for (i = 0; i < 8; i++) {
        arg1->field_14[i] = func_80064B08((Stg00RelocHdr *)arg1->field_C[arg1->field_2], i);
        arg1->field_34[i] = 0;
        for (j = 0; j < 32; j++) {
            bit = 1 << j;
            if (arg1->field_14[i] & bit) {
                arg1->field_34[i]++;
            }
        }
        arg1->field_44[i][7] = 0;
        arg1->field_44[i][6] = 0;
        arg1->field_44[i][5] = 0;
        arg1->field_44[i][4] = 0;
        arg1->field_44[i][3] = 0;
        arg1->field_44[i][2] = 0;
        arg1->field_44[i][1] = 0;
        arg1->field_44[i][0] = 0;
        if (arg1->field_14[i] & 1) {
            arg1->field_44[i][0] = 1;
        }
        if (arg1->field_14[i] & 0x20) {
            arg1->field_44[i][1]++;
        }
        if (arg1->field_14[i] & 0x40) {
            arg1->field_44[i][1]++;
        }
        if (arg1->field_14[i] & 0x80) {
            arg1->field_44[i][1]++;
        }
        if (arg1->field_14[i] & 0x100) {
            arg1->field_44[i][1]++;
        }
        if (arg1->field_14[i] & 0x200) {
            arg1->field_44[i][1]++;
        }
        if (arg1->field_14[i] & 0x400) {
            arg1->field_44[i][2]++;
        }
        if (arg1->field_14[i] & 0x800) {
            arg1->field_44[i][2]++;
        }
        if (arg1->field_14[i] & 0x1000) {
            arg1->field_44[i][2]++;
        }
        if (arg1->field_14[i] & 0x2000) {
            arg1->field_44[i][2]++;
        }
        if (arg1->field_14[i] & 0x4000) {
            arg1->field_44[i][2]++;
        }
        if (arg1->field_14[i] & 0x8000) {
            arg1->field_44[i][3]++;
        }
        if (arg1->field_14[i] & 0x10000) {
            arg1->field_44[i][3]++;
        }
        if (arg1->field_14[i] & 0x20000) {
            arg1->field_44[i][3]++;
        }
        if (arg1->field_14[i] & 0x40000) {
            arg1->field_44[i][3]++;
        }
        if (arg1->field_14[i] & 0x80000) {
            arg1->field_44[i][3]++;
        }
        if (arg1->field_14[i] & 0x100000) {
            arg1->field_44[i][4]++;
        }
        if (arg1->field_14[i] & 0x200000) {
            arg1->field_44[i][4]++;
        }
        if (arg1->field_14[i] & 0x400000) {
            arg1->field_44[i][4]++;
        }
        if (arg1->field_14[i] & 0x800000) {
            arg1->field_44[i][5]++;
        }
        if (arg1->field_14[i] & 0x1000000) {
            arg1->field_44[i][5]++;
        }
        if (arg1->field_14[i] & 0x2000000) {
            arg1->field_44[i][5]++;
        }
        if (arg1->field_14[i] & 0x4000000) {
            arg1->field_44[i][6]++;
        }
        if (arg1->field_14[i] & 0x8000000) {
            arg1->field_44[i][6]++;
        }
        if (arg1->field_14[i] & 0x10000000) {
            arg1->field_44[i][6]++;
        }
        if (arg1->field_14[i] & 0x20000000) {
            arg1->field_44[i][7]++;
        }
        if (arg1->field_14[i] & 0x40000000) {
            arg1->field_44[i][7]++;
        }
        if (arg1->field_14[i] & 0x80000000) {
            arg1->field_44[i][7]++;
        }
    }
    arg1->field_4 = arg1->field_2;
}

void func_800648BC(Actor *arg0, Stg00SelWork *arg1) {
    if (D_8005F72C & 0x8000) {
        if (arg1->field_A > 0) {
            arg1->field_A--;
        }
    }
    if (D_8005F72C & 0x2000) {
        if (arg1->field_A + 1 < 0x1E) {
            arg1->field_A++;
        }
    }
    if (D_8005F6F0[0].cross > 0) {
        Task_SetState1(arg0, 1);
    } else if (D_8005F6F0[0].circle > 0) {
        func_80064E44();
        D_8005F78C = arg1->field_0 + 0x201;
        D_8005071C->field_3 = arg1->field_2;
        D_8005071C->field_4 = arg1->field_8;
        Flag_Set(arg1->field_A + 0x76C, 1);
        Task_SetState0(arg0, 2);
    }
}

void func_800649D0(void) {
}

void func_800649D8(Actor *arg0) {
    Stg00SelWork *w = (Stg00SelWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        func_80064E78();
        func_80064E4C(0);
        w->field_0 = 0;
        w->field_2 = 0;
        w->field_6 = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            func_800641E0(arg0, w);
            break;
        case 1:
            func_800642BC(arg0, w);
            break;
        case 2:
            func_800648BC(arg0, w);
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_80064AD4(void) {
}

void func_80064ADC(Actor *arg0) {
    func_80065114();
    Task_DefaultDestroy(arg0);
}

INCLUDE_RODATA("asm/USA/stag0000/rodata", D_80063378);
INCLUDE_RODATA("asm/USA/stag0000/rodata", jtbl_800633F0);
INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80064B08);
