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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80064B08);

void func_80064E44(void) {
}

void func_80064E4C(s16 arg0) {
    Stg00Work *w = D_80069360;
    if (arg0 < 6) {
        w->field_8D4 = arg0;
    } else {
        w->field_8D4 = 0;
    }
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80064E78);

void func_80065114(void) {
    Gfx_ReleaseTexSlot(D_80069360->field_8D0);
    Mem_Free((ActorWork *)D_80069360);
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80065150);

void func_80065374(void) {
    Stg00PolyFT4 *p = (Stg00PolyFT4 *)D_8005F770.packet.work;
    u32 *ot = D_8005F770.otLayers.u[0];
    Stg00Work *w;
    Stg00TexSlot *t;
    s32 h;

    p->tag.b.len = 9;
    p->code = 0x2C;
    p->r0 = 0xFF;
    p->g0 = 0xFF;
    p->b0 = 0xFF;
    w = D_80069360;
    t = (Stg00TexSlot *)w->field_8D0;
    p->tpage = (0 << 7) | (1 << 5) | ((t->y & 0x100) >> 4) | ((t->x & 0x3FF) >> 6) | ((t->y & 0x200) << 2);
    p->clut = (w->field_8C2 << 6) | ((w->field_8C0 >> 4) & 0x3F);
    p->u0 = ((Stg00TexSlot *)w->field_8D0)->u;
    p->v0 = 0;
    p->u1 = ((Stg00TexSlot *)D_80069360->field_8D0)->u + 0x40;
    p->v1 = 0;
    p->u2 = ((Stg00TexSlot *)D_80069360->field_8D0)->u;
    p->v2 = h = 0x40;
    p->u3 = ((Stg00TexSlot *)D_80069360->field_8D0)->u + h;
    p->v3 = h;
    p->x0 = -0x20;
    p->y0 = -0x20;
    p->x1 = 0x20;
    p->y1 = -0x20;
    p->x2 = -0x20;
    p->y2 = 0x20;
    p->x3 = 0x20;
    p->y3 = 0x20;
    p->code &= ~2;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    p++;
    D_8005F770.packet.work = (ActorWork *)p;
}

void func_800654F4(s32 arg0, s32 arg1) {
    func_80065150(arg0, arg1, D_8006935C);
}

void func_8006551C(s32 arg0, s32 arg1) {
    func_80065150(arg0 + D_8005F770.centerX.s, arg1 + D_8005F770.centerY.s, D_8006935C);
}

void func_80065558(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Actor_InitTransform(arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, 0x78)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void func_800655B8(Actor *arg0) {
    Gfx_AttachModel(arg0, 0x78);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void func_800655FC(Actor *arg0) {
    Stg00NameWork *w = (Stg00NameWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    Stg00TaskArgs5 args;
    TextOpenArgs t;

    while ((id = func_8001E8F4(w->field_10)) == -1) {
        w->field_10 = 0;
    }
    Task_Destroy(slot);
    args.field_0 = id;
    args.field_10 = 0;
    args.field_4 = 0;
    args.field_8 = 0;
    args.field_C = 0;
    Task_Create(0x105, slot, (s32)&args);
    Text_Close(&w->field_14);
    Text_Close(&w->field_18);
    t.text = (s32)Digi_GetDefaultName(func_8001E8F4(w->field_10));
    t.bigFont = 1;
    t.color = 0;
    t.x = 0x10;
    t.y = 0xD0;
    t.charDelay = 0xE;
    t.charAdvance = 0;
    t.lineAdvance = 0;
    Text_Open(&w->field_14, &t);
    t.y = 0xC6;
    t.charDelay = 8;
    t.bigFont = 0;
    t.charAdvance = 9;
    Text_Open(&w->field_18, &t);
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_8006571C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80065E24);

void func_80066084(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->field_0) {
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        break;
    case 2:
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        break;
    case 1:
        Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
        break;
    case 0:
        Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
        break;
    }
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x100);
}

void func_80066130(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 i;

    for (i = 0; i < 9; i++) {
        Task_Destroy(slot);
        args.field_0 = w->field_330[i + w->field_654];
        args.field_10 = 0x400;
        args.field_4 = D_80068E18[w->field_658][i].field_0;
        args.field_8 = 0;
        args.field_C = D_80068E18[w->field_658][i].field_2;
        Task_Create(0x105, slot, (s32)&args);
        slot++;
    }
}

void func_8006620C(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 i;
    s32 id;
    s32 v;
    s32 j;
    s32 k;

    for (i = 0; (id = func_8001E8F4(i)) < 0x12D; i++) {
        v = func_8001E79C(id);
        j = 0;
        if (w->field_650 != 0) {
            for (k = j; k < w->field_650; k++) {
                if (v < w->field_10[k]) {
                    break;
                }
            }
            j = k;
            for (k = w->field_650; k >= j; k--) {
                w->field_10[k] = w->field_10[k - 1];
                w->field_330[k] = w->field_330[k - 1];
            }
        }
        w->field_10[j] = v;
        w->field_330[j] = id;
        w->field_650++;
    }
}

void func_80066318(Actor *arg0) {
    Stg00ListWork *w;
    Actor *cam;
    s32 i;
    s32 redraw;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ModeWork *)arg0->work)->field_0 = 2;
        Gpu_AllocPacketBufs(0x25800);
        Gfx_InitLights();
        func_80066084(arg0);
        func_8006620C(arg0);
        func_80066130(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ListWork *)arg0->work;
        cam = (Actor *)func_80068930();
        for (i = 0; i < D_8005F770.frameDelta; i++) {
            if (D_8005F6F0[0].right) {
                func_80068A44(cam, 0, 0x20, 0);
            } else if (D_8005F6F0[0].left) {
                func_80068A44(cam, 0, -0x20, 0);
            }
            if (D_8005F6F0[0].up) {
                func_80068958(cam, 0, 0, -0x20);
                func_8006899C(cam, 0, 0, -0x20);
            } else if (D_8005F6F0[0].down) {
                func_80068958(cam, 0, 0, 0x20);
                func_8006899C(cam, 0, 0, 0x20);
            }
            if (D_8005F6F0[0].triangle) {
                func_80068958(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].cross) {
                func_80068958(cam, 0, 0x20, 0);
            }
            if (D_8005F6F0[0].r1) {
                func_8006899C(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].l1) {
                func_8006899C(cam, 0, 0x20, 0);
            }
        }
        if (D_8005F720 > 0) {
            if (((Stg00ModeWork *)w)->field_0 != 3) {
                ((Stg00ModeWork *)w)->field_0++;
            } else {
                ((Stg00ModeWork *)w)->field_0 = 0;
            }
            func_80066084(arg0);
        }
        redraw = 0;
        if (D_8005F724 > 0) {
            if (++w->field_658 == 3) {
                w->field_658 = 0;
            }
            redraw = 1;
        }
        if (D_8005F72C & 0x20) {
            if (w->field_654 != 0) {
                w->field_654--;
                redraw = 1;
            }
        }
        if (D_8005F72C & 0x80) {
            if (w->field_654 + 9 != w->field_650) {
                w->field_654++;
                redraw = 1;
            }
        }
        if (redraw) {
            func_80066130(arg0);
        }
        if (D_8005F714 > 0) {
            D_8005F78C = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void func_80066618(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, D_80068E84[((Stg00PartsWork *)arg0->work)->field_C]);
    Gfx_DrawParts(e);
}

void func_80066678(Actor *arg0) {
    Stg00ModeWork *w;
    Stg00ModeWork *w2;

    switch (arg0->stateLevel0) {
    case 0:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Gpu_AllocPacketBufs(0x25800);
            Gfx_InitLights();
        case 1:
            break;
        }
        w = (Stg00ModeWork *)arg0->work;
        Sys_SetFrameRate60();
        switch (w->field_0) {
        case 1:
        default:
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            break;
        case 0:
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
            break;
        case 3:
            Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
            break;
        case 2:
            Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
            break;
        }
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Task_NextState1(arg0);
        case 1:
            break;
        }
        w2 = (Stg00ModeWork *)arg0->work;
        if (D_8005F720 > 0) {
            if (w2->field_0 != 3) {
                w2->field_0++;
            } else {
                w2->field_0 = 0;
            }
            Task_SetState0(arg0, 2);
        }
        break;
    case 2:
        Task_SetState01(arg0, 0, 1);
        break;
    }
}

void func_80066828(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->field_0) {
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        break;
    case 2:
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        break;
    case 1:
        Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
        break;
    case 0:
        Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
        break;
    }
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x100);
}

void func_800668D4(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 r;
    s32 c;
    s32 k;
    s32 base;
    s32 idx;
    s32 x;
    s32 y;
    s32 z;

    for (r = 0, z = -0x1400, y = 0x800, base = 0; r < 2; r++, base += 3) {
        for (c = 0, k = base, x = -0xA00; c < 3; k++, c++, x += 0xA00) {
            Task_Destroy(&slot[k]);
            do {
                idx = (Rand_Next() & 0xFFFF) % func_8001E938();
            } while (func_8001E8F4(idx) >= 0xF0);
            args.field_0 = func_8001E8F4(idx);
            args.field_10 = y;
            args.field_4 = x;
            args.field_8 = 0;
            args.field_C = z;
            Task_Create(0x105, &slot[k], (s32)&args);
        }
        z += 0x2800;
        y += 0x800;
    }
}

void func_800669F4(Actor *arg0) {
    Stg00ViewWork *w;
    Actor *cam;
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ViewWork *)arg0->work)->field_0 = 2;
        Gpu_AllocPacketBufs(0x25800);
        func_80066828(arg0);
        func_800668D4(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ViewWork *)arg0->work;
        cam = (Actor *)func_80068930();
        for (i = 0; i < D_8005F770.frameDelta; i++) {
            if (D_8005F6F0[0].right) {
                func_80068A44(cam, 0, 0x20, 0);
            } else if (D_8005F6F0[0].left) {
                func_80068A44(cam, 0, -0x20, 0);
            }
            if (D_8005F6F0[0].up) {
                func_80068958(cam, 0, 0, -0x20);
                func_8006899C(cam, 0, 0, -0x20);
            } else if (D_8005F6F0[0].down) {
                func_80068958(cam, 0, 0, 0x20);
                func_8006899C(cam, 0, 0, 0x20);
            }
            if (D_8005F6F0[0].triangle) {
                func_80068958(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].cross) {
                func_80068958(cam, 0, 0x20, 0);
            }
            if (D_8005F6F0[0].r1) {
                func_8006899C(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].l1) {
                func_8006899C(cam, 0, 0x20, 0);
            }
        }
        if (D_8005F708 > 0) {
            if (++w->field_8 == 7) {
                w->field_8 = 0;
            }
            switch (w->field_8) {
            case 0:
            default:
                func_80068A00(cam, 0xA00, 0, -0x1400);
                break;
            case 1:
                func_80068A00(cam, -0xA00, 0, -0x1400);
                break;
            case 2:
                func_80068A00(cam, 0xA00, 0, 0);
                break;
            case 3:
                func_80068A00(cam, 0xA00, 0, 0);
                break;
            case 4:
                func_80068A00(cam, 0, 0, 0x2800);
                break;
            case 5:
            case 6:
                func_80068A00(cam, -0xA00, 0, 0);
                break;
            }
        }
        if (D_8005F720 > 0) {
            if (w->field_0 != 3) {
                w->field_0++;
            } else {
                w->field_0 = 0;
            }
            func_80066828(arg0);
        }
        if (D_8005F6F0[0].start > 0) {
            func_800668D4(arg0);
        }
        if (D_8005F6F0[0].circle > 0) {
            if (++w->field_C == 4) {
                w->field_C = 0;
            }
        }
        if (D_8005F714 > 0) {
            D_8005F78C = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void func_80066D50(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, D_80068EC4[((Stg00PartsWork *)arg0->work)->field_C]);
    Gfx_DrawParts(e);
}

void func_80066DB0(Actor *arg0, Stg00ModelArg *arg1) {
    Stg00ModelWork *w;

    arg0->digiId = arg1->field_0;
    w = (Stg00ModelWork *)arg0->work;
    w->field_14 = Digi_GetModelFile(arg1->field_0);
    w->field_4 = arg1->field_4;
    w->field_10 = arg1->field_10;
}

void func_80066E1C(Actor *arg0, s32 arg1) {
    Stg00SpawnWork *w = (Stg00SpawnWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs args;
    s16 a[3];
    s16 b[3];
    Row6 rows[3];
    Stg00TaskArgs3 args2;
    Row6 *r;
    s32 i;

    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(arg0->digiId, rows);
    r = &rows[arg1];
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.field_14 = w->field_10;
            args.field_8 = w->field_4;
            args.field_C = w->field_8;
            args.field_10 = w->field_C;
            args.field_18 = 0x78;
            switch (i) {
            case 0:
                args.field_C -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.field_C -= r->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += r->data[0];
                    args.field_10 -= 0x100 + r->data[2];
                } else {
                    args.field_8 -= r->data[0];
                    args.field_10 += 0x100 + r->data[2];
                }
                break;
            case 2:
                break;
            }
            Task_Create(7, &slot[i + 1], (s32)&args);
        }
    }
    args2.field_4 = w->field_2C;
    args2.field_0 = 0;
    args2.field_8 = 0;
    Task_Create(0x10B, &slot[4], (s32)&args2);
}

void func_80066FE8(Actor *arg0) {
    Stg00SpawnWork *w = (Stg00SpawnWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs args;
    s16 a[3];
    s16 b[3];
    s32 i;

    func_8001EEA4(w->field_2C, 1, a, b);
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.field_14 = w->field_10;
            args.field_8 = w->field_4;
            args.field_C = w->field_8;
            args.field_10 = w->field_C;
            args.field_18 = 0x3C;
            switch (i) {
            case 0:
                args.field_C -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.field_C -= func_8001E7C0(arg0->digiId);
                break;
            case 2:
                break;
            }
            Task_Create(7, &slot[i + 1], (s32)&args);
        }
    }
}

void func_80067120(Actor *arg0, s32 arg1, s32 arg2) {
    Stg00Xform *t = (Stg00Xform *)arg0->u38.ptr38;

    if (arg0->stateLevel3 == 0 && arg0->stateLevel4 == 0) {
        Actor_StopAxisMotion(arg0, 1);
    } else {
        func_80020D54(arg0, 1);
        func_80020E00(arg0, 2);
    }
    switch (arg0->stateLevel3) {
    case 0:
    default:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            if (arg2) {
                Actor_SetAxisMotion(arg0, 2, &D_80068F04);
            }
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            Anim_SetModelAnim(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &D_80068EEC);
            Task_NextState4(arg0);
            return;
        case 1:
            if (t->field_34 > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->field_34 = 0;
                t->field_4C = 0;
                Task_NextState3(arg0);
            }
            return;
        }
    case 1:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            Anim_SetModelAnim(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &D_80068EF8);
            Task_NextState4(arg0);
            return;
        case 1:
            if (t->field_34 > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->field_34 = 0;
                t->field_4C = 0;
                Task_NextState3(arg0);
            }
            return;
        }
    case 2:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Anim_SetModelAnim(arg0, 0x16);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                if (arg1 == 0) {
                    Task_NextState3(arg0);
                }
                Task_NextState3(arg0);
            }
            break;
        }
        break;
    case 3:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Anim_SetModelAnim(arg0, 0x64);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone == 0) {
                break;
            }
            arg0->elapsed = 0;
            Task_NextState4(arg0);
        case 2:
            if (arg0->elapsed >= 0x5A) {
                Task_NextState3(arg0);
            }
            break;
        }
        break;
    case 4:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Anim_SetModelAnim(arg0, 0x5A);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    }
}

void func_800673FC(Actor *arg0) {
    Stg00Work73FC *w = (Stg00Work73FC *)arg0->work;
    ActorTransformView *t = arg0->u38.ptr38;
    t->posX = w->field_4;
    t->posY = w->field_8;
    t->posZ = w->field_C;
}

void func_80067428(Actor *arg0) {
    Stg00ModelWorkX *w = (Stg00ModelWorkX *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00ModelFade *m;
    Stg00TaskArg1 a1;
    Stg00TaskArgs3 a3;
    s32 *p;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, (s32 *)&w->field_4, (u16)w->field_10);
        Gfx_AttachModel(arg0, w->field_14)->otIndex = 3;
        Anim_SetModelAnim(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, (s32 *)arg0->u34.children, (s32)&a1);
        w->field_20 = 1;
        w->field_24 = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        default:
            Anim_SetModelAnim(arg0, arg0->stateLevel2);
            Task_SetState0(arg0, 1);
            break;
        case 0:
            switch (arg0->stateLevel2) {
            case 0:
                Anim_SetModelAnim(arg0, 0);
            default:
                arg0->stateLevel2++;
                break;
            case 0x28:
                func_800673FC(arg0);
                Task_SetState0(arg0, 1);
                break;
            }
            break;
        case 1:
            func_800673FC(arg0);
            Anim_SetModelAnim(arg0, 0x32);
            Task_SetState0(arg0, 1);
            break;
        case 2:
            func_800673FC(arg0);
            Anim_SetModelAnim(arg0, 0x3C);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            func_800673FC(arg0);
            Anim_SetModelAnim(arg0, 0x46);
            Task_SetState0(arg0, 1);
            break;
        case 4:
            func_800673FC(arg0);
            Anim_SetModelAnim(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 5:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Anim_SetModelAnim(arg0, 0xA);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 6:
        case 7:
            w = (Stg00ModelWorkX *)arg0->work;
            w->field_1C += D_8005F778;
            while (w->field_1C >= 2) {
                w->field_1C -= 2;
                func_80067120(arg0, arg0->stateLevel1 - 6, 0);
            }
            break;
        case 8:
            m = (Stg00ModelFade *)arg0->model;
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_24 = 1;
                m->field_34 = 1;
                m->field_36 = 0x20;
                m->field_38 = m->field_39 = m->field_3A = 0x7C;
                w->field_28.r = w->field_28.g = w->field_28.b = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (m->field_38 == 0) {
                    m->field_34 = 0;
                    m->field_36 = 0;
                    w->field_20 = 0;
                    w->field_28.g = 0xFF;
                    Task_SetState0(arg0, 1);
                } else {
                    m->field_39 = m->field_3A = (m->field_38 -= 4);
                    w->field_28.g += 8;
                }
                break;
            }
            break;
        case 9:
            m = (Stg00ModelFade *)arg0->model;
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_20 = 1;
                m->field_34 = 1;
                m->field_36 = 0x20;
                m->field_38 = m->field_39 = m->field_3A = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (m->field_38 == 0x7C) {
                    m->field_34 = 0;
                    m->field_36 = 0;
                    w->field_24 = 0;
                    Task_SetState0(arg0, 1);
                } else {
                    m->field_39 = m->field_3A = (m->field_38 += 4);
                    w->field_28.g -= 8;
                }
                break;
            }
            break;
        case 10:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                switch (arg0->stateLevel3) {
                case 0:
                default:
                    w->field_2C = arg0->stateLevel4;
                    func_800673FC(arg0);
                    p = func_8001EFF0(w->field_2C);
                    a3.field_0 = p[0];
                    a3.field_4 = p[1];
                    a3.field_8 = 1;
                    Task_Create(0x10C, &slot[5], (s32)&a3);
                    Task_NextState3(arg0);
                case 1:
                    if (((Actor *)slot[5])->stateLevel0 == 1) {
                        Task_NextState0((Actor *)slot[5]);
                        k = func_8001EE10(w->field_2C);
                        func_80066E1C(arg0, k);
                        switch (k) {
                        case 0:
                        default:
                            Anim_SetModelAnim(arg0, 0x32);
                            break;
                        case 1:
                            Anim_SetModelAnim(arg0, 0x3C);
                            break;
                        case 2:
                            Anim_SetModelAnim(arg0, 0x46);
                            break;
                        }
                        Task_NextState2(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                }
                break;
            case 1:
                if (arg0->elapsed < 0x96) {
                    break;
                }
                Anim_SetModelAnim(arg0, 0);
                Task_NextState2(arg0);
                arg0->elapsed = 0;
            case 2:
                if (arg0->elapsed < 0x1E) {
                    break;
                }
                func_80066FE8(arg0);
                Task_NextState2(arg0);
                if (func_8001EF64(w->field_2C) == 0) {
                    Task_NextState2(arg0);
                    break;
                }
            case 3:
                w = (Stg00ModelWorkX *)arg0->work;
                w->field_1C += D_8005F778;
                while (w->field_1C >= 2) {
                    w->field_1C -= 2;
                    func_80067120(arg0, 0, 1);
                }
                break;
            case 4:
                break;
            }
            break;
        }
        break;
    }
}

void func_800679C8(Actor *arg0) {
    Stg00ModelWork *w = (Stg00ModelWork *)arg0->work;

    Gfx_AttachModel(arg0, w->field_14);
    Anim_StepModelAnim(arg0);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    if (w->field_20 != 0) {
        Gfx_DrawTexModel(arg0, 0);
    }
    if (w->field_24 != 0) {
        Gfx_DrawWireModel(arg0, 0, &w->field_28);
    }
}

void func_80067A50(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void func_80067A70(Actor *arg0) {
    Stg00FadeWork *w = (Stg00FadeWork *)arg0->work;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_10++;
            w->field_C += 0x200;
            if (w->field_10 != 7) {
                break;
            }
            arg0->elapsed = 0;
            w->field_C = 0x1000;
            Task_NextState1(arg0);
        case 1:
            v = w->field_0;
            if (v != 7) {
                if (arg0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->field_10 = Math_CycleRange(arg0->elapsed, 2, 8, 0xF);
                if (arg0->elapsed < 0x90) {
                    break;
                }
                w->field_10 = v;
            }
            Task_NextState1(arg0);
        case 2:
            if (--w->field_10 < 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_80067BAC(Actor *arg0) {
    Stg00PanelWork *w = (Stg00PanelWork *)arg0->work;
    EntA0 *e = NULL;
    s32 draw = 1;
    Stg00PartScale *p;
    s32 id;

    switch (w->field_0) {
    case 0:
    default:
        e = Cd_GetFileEntry(func_8001EE5C(w->field_4));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        e = Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask(e, D_80068F28[w->field_0 - 4]);
        break;
    case 1:
    case 2:
    case 3:
        e = Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber(e, D_80068F44[w->field_0 - 1], 3, w->field_4);
        Gfx_HidePartsByMask(e, D_80068F38[w->field_0 - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->field_C != 0x1000) {
                p->field_E = 0;
                p->field_10 = w->field_C;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->field_10;
        }
        Gfx_DrawParts(e);
    }
    if (w->field_8 != 0) {
        switch (w->field_8 >> 8) {
        case 0:
        default:
            id = 0x1A10026;
            break;
        case 1:
            id = 0x1A10027;
            break;
        case 2:
            id = 0x1A10028;
            break;
        }
        e = Cd_GetFileEntry(id);
        Gfx_HidePartsByMask(e, ~(1 << ((u8)w->field_8 - 1)));
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->field_C != 0x1000) {
                p->field_E = 0;
                p->field_10 = w->field_C;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->field_10;
        }
        Gfx_DrawParts(e);
    }
}

void func_80067DFC(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void func_80067E1C(Actor *arg0) {
    Stg00CdWork *w = (Stg00CdWork *)arg0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_C = Cd_GetFileLba(w->field_0) + D_80068FA0[w->field_8 - 1];
            w->field_10 = w->field_C + D_80068FB8[w->field_8 - 1];
            param[0] = 1;
            param[1] = w->field_4;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->field_C, loc);
            CdControlF(0x15, (s32)loc);
            Task_NextState1(arg0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(arg0, 0);
                break;
            case 2:
                Task_NextState0(arg0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->field_C, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((Stg00ActorTimer *)arg0)->field_24 & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->field_10) {
                        Task_SetState0(arg0, 3);
                    } else {
                        CdControlF(0x11, 0);
                    }
                    break;
                }
            }
            break;
        }
        break;
    }
}

void func_80068050(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

u8 *func_80068084(s32 arg0, s32 arg1) {
    u8 *s = D_8006925C[arg0][arg1];
    s32 i = 0;
    s32 row = (arg1 != 0);

    for (; s[i] != 0; i++) {
        u8 c = s[i];
        if (c < 0x3A) {
            D_80069364[row][i] = c - 0x30;
        } else if (c == 0x5F) {
            D_80069364[row][i] = 0x24;
        } else {
            D_80069364[row][i] = c + 0xC9;
        }
    }
    D_80069364[row][i] = 0xFF;
    return D_80069364[row];
}

u8 *func_80068150(s32 arg0) {
    return func_80068084(arg0, 0);
}

u8 *func_80068170(s32 arg0, s32 arg1) {
    return func_80068084(arg0, arg1 + 1);
}

s32 func_80068190(void) {
    s32 i;

    for (i = 0; D_8006925C[i] != NULL; i++) {
    }
    return i;
}

s32 func_800681C4(s32 arg0) {
    u8 **p = D_8006925C[arg0];
    s32 i;

    for (i = 0; p[i] != NULL; i++) {
    }
    return i - 1;
}

void func_80068208(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    s32 i;
    s32 n;

    switch (arg0->stateLevel0) {
    case 0:
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        if (D_8005F6F0[0].up > 0) {
            if (w->field_0 == 0) {
                break;
            }
            w->field_0--;
            w->field_4 = 0x3C;
        } else if (D_8005F6F0[0].down > 0) {
            if (w->field_0 == 2) {
                break;
            }
            w->field_0++;
            w->field_4 = 0x3C;
        } else {
            n = 5;
            for (i = 5; i >= 0; i--) {
                if (i == 5) {
                    w->field_8[n]++;
                }
                if (w->field_8[i] >= 10) {
                    w->field_8[i] -= 10;
                    if (i != 0) {
                        w->field_8[i - 1]++;
                    }
                }
            }
        }
        break;
    case 2:
        break;
    }
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_8006835C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800684E4);

void func_800687E8(void) {
}

void func_800687F0(Actor *arg0, Stg00Blk1C *arg1) {
    *(Stg00Blk1C *)arg0->work = *arg1;
}

void func_80068830(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        GsInitCoordinate2(NULL, &w->field_1C);
        w->field_84 = 1;
        Task_NextState0(arg0);
    }
}

void func_80068884(Actor *arg0) {
    Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
    Stg00RefView rv;

    RotMatrixYXZ(&w->field_7C, &w->field_1C.coord);
    w->field_1C.coord.t[0] = w->field_6C;
    w->field_1C.coord.t[1] = w->field_70;
    w->field_1C.coord.t[2] = w->field_74;
    w->field_1C.flg = 0;
    rv.field_0 = w->field_0;
    rv.field_4 = w->field_4;
    rv.field_8 = w->field_8;
    rv.field_C = w->field_C;
    rv.field_10 = w->field_10;
    rv.field_14 = w->field_14;
    rv.field_18 = 0;
    rv.field_1C = &w->field_1C;
    GsSetProjection(w->field_18);
    GsSetRefView2(&rv);
}

TaskEntry *func_80068930(void) {
    return Task_FindFirst(0x109, -1, -1);
}

void func_80068958(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_0 += arg1;
        w->field_4 += arg2;
        w->field_8 += arg3;
    }
}

void func_8006899C(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_C += arg1;
        w->field_10 += arg2;
        w->field_14 += arg3;
    }
}

void func_800689E0(Actor *arg0, s32 arg1) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_18 = arg1;
        w->field_84 = 1;
    }
}

void func_80068A00(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_6C += arg1;
        w->field_70 += arg2;
        w->field_74 += arg3;
    }
}

void func_80068A44(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_7C += arg1;
        w->field_7E += arg2;
        w->field_80 += arg3;
    }
}
