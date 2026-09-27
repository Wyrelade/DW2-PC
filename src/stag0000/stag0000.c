#include "common.h"
#include "stag0000/stag0000.h"

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80063A74);

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

void func_80063E34(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s16 arg2, s16 arg3) {
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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80063E9C);

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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800642BC);

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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80065374);

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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_8006620C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066318);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066618);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066678);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066828);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800668D4);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800669F4);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066D50);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066DB0);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066E1C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066FE8);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80067120);

void func_800673FC(Actor *arg0) {
    Stg00Work73FC *w = (Stg00Work73FC *)arg0->work;
    ActorTransformView *t = arg0->u38.ptr38;
    t->posX = w->field_4;
    t->posY = w->field_8;
    t->posZ = w->field_C;
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80067428);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800679C8);

void func_80067A50(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80067A70);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80067BAC);

void func_80067DFC(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80067E1C);

void func_80068050(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80068084);

void func_80068150(s32 arg0) {
    func_80068084(arg0, 0);
}

void func_80068170(s32 arg0, s32 arg1) {
    func_80068084(arg0, arg1 + 1);
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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80068208);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_8006835C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800684E4);

void func_800687E8(void) {
}

void func_800687F0(Actor *arg0, Stg00Blk1C *arg1) {
    *(Stg00Blk1C *)arg0->work = *arg1;
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80068830);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80068884);

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
