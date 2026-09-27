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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80064084);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80064190);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800641E0);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800642BC);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800648BC);

void func_800649D0(void) {
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800649D8);

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

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80065558);

void func_800655B8(Actor *arg0) {
    Gfx_AttachModel(arg0, 0x78);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_800655FC);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_8006571C);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80065E24);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066084);

INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000", func_80066130);

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
