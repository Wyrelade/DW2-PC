#include "common.h"
#include "stag2000/stag2000.h"

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063610);

s32 func_800636A8(Stg20Cell *c) {
    return D_80070768[c->x][c->y];
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800636D8);

void func_80063760(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
    func_80063610(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063784);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800638E8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063C84);

void func_80063CD0(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063CDC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063E38);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80064008);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800650BC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065774);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065960);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065AF4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065D1C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065D74);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065FB8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066714);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800667AC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066A4C);

void func_80066A9C(s32 d) {
    GameState *g = &D_8005E620;

    g->field_8 += d;
    if (g->field_8 < 0) {
        g->field_8 = 0;
    }
    if (g->field_8 > 99999999) {
        g->field_8 = 99999999;
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066AE0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066B48);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066F34);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067480);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067504);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067568);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067604);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800676A8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067714);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067770);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800677C8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800678A8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067928);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067978);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067B20);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067E9C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068134);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800681A0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068364);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068420);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800685C4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006863C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800688E4);

void func_80068B3C(Actor *a, s32 v) {
    a->field_8 = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068B44);

void func_80068C50(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068C84);

void func_80068CF8(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Text_Close((s32 *)e->work);
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068D34);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068D84);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068DD8);

s32 func_80068E6C(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        return ((Stg20TextWork *)e->work)->field_1C;
    }
    return 0;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068EB0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068FB8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069068);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006964C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800697AC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800698F4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069AAC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069D98);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A000);

void func_8006A118(void) {
    Gfx_DrawParts((s32)Cd_GetFileEntry(0xD120007));
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A144);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A190);

void func_8006A248(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A254);

void func_8006A320(Actor *a) {
    Gfx_AttachModel(a, 0x2F7);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    Gfx_DrawTexModel(a, 1);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A364);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A3D0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A434);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A6DC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A744);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A8C0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A920);

s32 func_8006A9F8(Actor *a) {
    return ((Stg20ModelWork *)a->work)->field_74;
}

void func_8006AA0C(Actor *a, s32 anim) {
    Stg20ModelTask *t = (Stg20ModelTask *)a;
    Stg20ModelWork *w = t->work;

    if (t->field_4 >= 0 && w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a, anim);
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006AA4C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006AB0C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006AD14);

void func_8006AD6C(Actor *a, s32 i) {
    ((Stg20Rot *)a->u38.ptr38)->field_42 = D_800703D8[i];
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006AD8C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006ADF8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006B7C8);

void func_8006B840(Actor *a, Stg20Vec3 *v) {
    *(Stg20Vec3 *)a->work = *v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006B860);

void func_8006BA5C(Actor *a) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a);
}

void func_8006BA90(Actor *a) {
    if (a->stateLevel0 == 0) {
        Task_NextState0(a);
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BAC0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BB7C);

void func_8006BBF0(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

void func_8006BC24(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60000);

    Gfx_SetPartsNumber(p, 2, 8, D_8005E628);
    Gfx_DrawParts((s32)p);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BC6C);

void func_8006BDD0(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BE04);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BEDC);

void func_8006C040(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C074);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C14C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C18C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C1C4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C3B8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C420);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C514);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C6F0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C8BC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006CB58);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D0F0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D124);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D2C0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D350);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D3CC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D484);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D4BC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D4F4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D53C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D7DC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D93C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006DCCC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E720);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E754);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E9E8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EA90);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006ED24);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EE24);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F258);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F28C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F360);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F3D8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F3E0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F730);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006FBF0);
