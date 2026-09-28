#include "common.h"
#include "stag2000/stag2000.h"

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063610);

s32 func_800636A8(Stg20Cell *c) {
    return D_80070768[c->x][c->y];
}

void func_800636D8(Stg20Cell *c, s32 set, s32 flag) {
    s32 bit = 0x40;
    s32 m;

    if (flag) {
        bit = 0x80;
    }
    if (set) {
        D_80070768[c->x][c->y] |= bit;
    } else {
        m = 0xFF;
        D_80070768[c->x][c->y] &= m - bit;
    }
}

void func_80063760(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
    func_80063610(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063784);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800638E8);

void func_80063C84(void) {
    Actor *a = (Actor *)Task_FindFirst(0x301, -1, -1);

    if (a != NULL && a->stateLevel0 == 1) {
        Task_SetState1(a, 1);
    }
}

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

void func_80065D1C(void) {
    Stg20GameState *g = (Stg20GameState *)&D_8005E620;

    g->field_26 = g->field_24 = D_8006FCCC[g->field_2C[1] - 1];
    g->field_2A = g->field_28 = D_8006FD28[g->field_2C[3] - 0x35];
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065D74);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065FB8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066714);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800667AC);

s32 func_80066A4C(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (D_8005E620.elems[i].state >= 2 && D_8005E620.elems[i].digiId == id) {
            return 1;
        }
    }
    return 0;
}

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

void func_80066AE0(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (D_8005E620.elems[i].state >= 2 && D_8005E620.elems[i].digiId == id) {
            D_8005E620.elems[i].state = 0;
            break;
        }
    }
    Digi_SortRoster();
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066B48);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80066F34);

void func_80067480(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color) {
    Stg20TextArgs args;

    if (id == 0) {
        args.text = text;
    } else {
        args.text = (s32)Cd_GetFileEntry(id + 0x1FD0000);
    }
    args.bigFont = 0;
    args.color = color;
    args.pos = *pos;
    args.charAdvance = 0;
    args.lineAdvance = 0xC;
    args.charDelay = 0;
    Text_Open(t, &args);
}

Stg20Cell *func_80067504(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;

    D_800709A8.x = (t->posX + 0x4500) / 0x600;
    D_800709A8.y = 0x16 - (t->posZ + 0x4500) / 0x600;
    return &D_800709A8;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067568);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067604);

void func_800676A8(Actor *a, s32 i) {
    Stg20Vec3 *v = &((Stg20Rot *)a->u38.ptr38)->field_84;

    if (v->field_0 == 0) {
        v->field_0 = D_8006FF1C[i].field_0;
    }
    v->field_4 = D_8006FF1C[i].field_4;
    v->field_8 = D_8006FF1C[i].field_8;
}

Stg20Cell *func_80067714(Actor *a, s32 dir) {
    Stg20Cell *c = func_80067504(a);

    c->x += D_8006FF34[dir].x;
    c->y += D_8006FF34[dir].y;
    return c;
}

s32 func_80067770(Actor *a, s32 dir) {
    s32 mask;

    if (D_800709B4 != 0) {
        return 0;
    }
    mask = 0xBF;
    if (((Stg20ModelTask *)a)->field_4 == 0) {
        mask = 0x7F;
    }
    return func_800636A8(func_80067714(a, dir)) & mask;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800677C8);

void func_800678A8(Actor *a, Stg20Marks *m) {
    s32 i;
    s32 flag = ((Stg20ModelTask *)a)->field_4 == 0;

    for (i = 0; i < 5; i++) {
        if (m->timer[i] != 0) {
            if (--m->timer[i] == 0) {
                func_800636D8(&m->cell[i], 0, flag);
            } else {
                func_800636D8(&m->cell[i], 1, flag);
            }
        }
    }
}

s32 func_80067928(Stg20Cell *c, s32 x, s32 y, s32 flag) {
    s32 dx = c->x - x;
    s32 dy;

    if (dx < 0) {
        dx = -dx;
    }
    dy = c->y - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (flag) {
        dx *= 3;
    } else {
        dy *= 3;
    }
    return dx + dy;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067978);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067B20);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80067E9C);

void func_80068134(Actor *a, s32 open) {
    Stg20PickWork *w = (Stg20PickWork *)a->work;

    if (open == 0) {
        Text_Close(&w->text);
    } else {
        Text_OpenPacked(&w->text, w->recs[w->index].field_0, 0, D_80063564);
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800681A0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068364);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80068420);

void func_800685C4(Actor *a) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        w->slots[i].used = D_8005E620.elems[i + D_800709B0.field_14].state != 0;
        w->slots[i].enabled = 1;
        w->slots[i].slot = i + D_800709B0.field_14;
    }
}

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

void func_80068C84(Actor *a) {
    Stg20Part *p;
    Stg20Part *q;
    s32 id;

    id = 0x3120003;
    if (a->field_8 != 0) {
        id = 0x3120001;
    }
    p = (Stg20Part *)Cd_GetFileEntry(id);
    for (q = p; q->fileId != 0; q++) {
        q->field_E = 1;
    }
    Gfx_DrawParts((s32)p);
}

void func_80068CF8(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Text_Close((s32 *)e->work);
    }
}

void func_80068D34(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->field_4 = func_8001EDD4(id);
        w->field_18 = 1;
    }
}

void func_80068D84(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->field_4 = (s32)Cd_GetFileEntry(id + 0x1FD0000);
        w->field_18 = 1;
    }
}

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

u8 func_8006A144(s32 a, s32 b) {
    a = func_8001D934(a);
    b = func_8001D934(b);
    return D_8007012C[a][b];
}

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

void func_8006A364(Actor *a) {
    if (a->stateLevel0 == 0) {
        Actor_InitTransform(a, D_80043704, 0);
        Gfx_AttachModel(a, 0xD14)->otIndex = 5;
        Gfx_ResetModelBones(a);
        ((Stg20Rot *)a->u38.ptr38)->field_42 = 0x200;
        Task_NextState0(a);
    }
}

void func_8006A3D0(Actor *a) {
    CVECTOR c;

    Gfx_AttachModel(a, 0xD14);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    c = D_80063584;
    Gfx_DrawWireModel(a, 1, &c);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A434);

void func_8006A6DC(Actor *a) {
    Stg20DrawWork *w = (Stg20DrawWork *)a->work;

    if (w->visible != 0) {
        Gfx_AttachModel(a, w->modelId);
        Anim_StepModelAnim(a);
        Actor_UpdateTransform(a);
        Gfx_CalcModelBoneMatrices(a);
        Gfx_DrawTexModel(a, 0);
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006A744);

Actor *func_8006A8C0(s32 id) {
    Actor *e;

    for (e = (Actor *)Task_FindFirst(0x302, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
        if (e->digiId == id) {
            return e;
        }
    }
    return NULL;
}

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

s32 func_8006AD14(Actor *a) {
    u16 m = 0x1000;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (((Stg20FlagWork *)a->work)->field_24 & m) {
            return (i + 2) % 4;
        }
        m <<= 1;
    }
    return -1;
}

void func_8006AD6C(Actor *a, s32 i) {
    ((Stg20Rot *)a->u38.ptr38)->field_42 = D_800703D8[i];
}

void func_8006AD8C(Actor *a) {
    Stg20CursorWork *w = (Stg20CursorWork *)a->work;
    Stg20Cell c = *func_80067504(a);

    w->x = c.x;
    w->y = c.y;
    w->field_8 = w->field_A = 1;
    w->field_74 = 1;
    w->field_5C = 0;
    w->field_18 = 0;
}

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

s32 func_8006C14C(u8 *s, s32 c) {
    for (; *s != 0; s++) {
        if (*s == c) {
            return 1;
        }
    }
    return 0;
}

s32 func_8006C18C(s32 id) {
    s32 i;

    for (i = 0; i < 0x13; i++) {
        if (((Stg20GameState *)&D_8005E620)->field_2C[i] == id) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C1C4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C3B8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C420);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C514);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C6F0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C8BC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006CB58);

void func_8006D0F0(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xF);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D124);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D2C0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D350);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D3CC);

s32 func_8006D484(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] == v) {
            return 1;
        }
    }
    return 0;
}

void func_8006D4BC(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] == v) {
            w->field_60[i] = 0;
            return;
        }
    }
}

void func_8006D4F4(s16 *list, s32 n, s32 v) {
    s32 i;
    s32 t;

    for (i = 0; i < n; i++) {
        t = list[i];
        if (t < v) {
            list[i] = v;
            v = t;
        }
    }
    list[i] = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D53C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D7DC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D93C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006DCCC);

void func_8006E720(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0x12);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E754);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E9E8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EA90);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006ED24);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EE24);

void func_8006F258(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xC);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F28C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F360);

void func_8006F3D8(Actor *a, s32 v) {
    a->field_8 = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F3E0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F730);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006FBF0);
