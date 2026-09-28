#include "common.h"
#include "stag2000/stag2000.h"

void func_80063610(Actor *a) {
    s32 x, y;
    u8 *p;
    s32 bit = 0;
    p = func_80066714()->bits;
    p--;
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x18; y++) {
            bit <<= 1;
            if (!(y & 7)) {
                bit = 1;
                p++;
            }
            if (*p & bit) {
                D_80070768[y][x] = 1;
            } else {
                D_80070768[y][x] = 0;
            }
        }
    }
}

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

void func_80063784(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        w->field_2C = 0;
        w->field_30 = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                a->elapsed = 0;
                Task_NextState2(a);
            case 1:
                w->field_2C += D_8006FC4C[((Stg20BlinkTask *)a)->field_24 & 3].x;
                w->field_30 += D_8006FC4C[((Stg20BlinkTask *)a)->field_24 & 3].y;
                if (a->elapsed >= 0x78) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

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

void func_80063CDC(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        SetGeomOffset(0, 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState1(a);
        case 1:
            if (D_8005F770.fadeLevel == 0xFF) {
                switch (w->field_2C) {
                case 0:
                default:
                    D_8005F770.nextGameMode = 0x303;
                    D_8005F770.field_24 = 3;
                    break;
                case 1:
                    D_8005F770.nextGameMode = 0x200;
                    break;
                }
                Task_NextState1(a);
            }
            break;
        case 2:
            break;
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80063E38);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80064008);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800650BC);

void func_80065774(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        D_800709B0.field_C = 0;
        Task_Create(0x30D, &slot[5], 0);
        w->menu = Task_FindFirst(0x308, -1, -1);
        D_800709B0.field_0 = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_SetState0((Actor *)w->menu, 0);
                Task_Create(0x30B, &slot[3], 0);
                func_80068D84(0x115);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    if (D_800709B0.field_8 != 0) {
                        Task_NextState0(a);
                    } else {
                        if (D_800709B0.field_C != 0) {
                            Task_NextState1(a);
                        }
                        Task_NextState1(a);
                    }
                }
                break;
            }
            break;
        case 1:
            func_800650BC(a);
            break;
        case 2:
            func_80064008(a);
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                D_8005F770.field_24 = 1;
                D_8005F770.nextGameMode = D_8005F770.prevGameMode;
            }
            break;
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065960);

void func_80065AF4(Actor *a) {
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Task_Create(0x312, &slot[0], 0);
        Task_Create(0x315, &slot[1], 0);
        D_80070A00 = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x316, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    if (D_800709B0.field_8 != 0) {
                        Task_NextState0(a);
                    } else if (D_800709B0.field_50 == 0) {
                        Task_SetState1(a, 1);
                    } else {
                        Task_SetState1(a, 2);
                    }
                }
                break;
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                D_80070A04 = 0;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                D_80070A04 = 1;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                D_8005F770.nextGameMode = D_8005F770.prevGameMode;
                D_8005F770.field_24 = D_8005F770.gameMode == 0x330 ? 5 : 6;
            }
            break;
        }
        break;
    }
}

void func_80065D1C(void) {
    Stg20GameState *g = (Stg20GameState *)&D_8005E620;

    g->field_26 = g->field_24 = D_8006FCCC[g->field_2C[1] - 1];
    g->field_2A = g->field_28 = D_8006FD28[g->field_2C[3] - 0x35];
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065D74);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80065FB8);

Stg20MapFile *func_80066714(void) {
    Stg20MapFile *f = (Stg20MapFile *)Cd_GetFileEntry(((Stg20Mode *)D_8005F788)->lo + 0x308FFFF);
    s32 base;

    if (f->loaded == 0) {
        base = Cd_GetFileOrNull(0x309);
        f->loaded = 1;
        f->field_C += base;
        f->field_8 += base;
        f->bits += base;
        f->field_18 = f->field_18 != 0 ? f->field_18 + base : 0;
    }
    return f;
}

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

s32 func_80067568(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;
    s32 m = 0xE6; s32 r; s32 v; v = (t->posX + 0x12C73) % 0x600; if (v > m) goto zero; r = 1; v = (t->posZ + 0x12C73) % 0x600; if (v > m) { zero: r = 0; } return r;
}

void func_80067604(Actor *a, s32 doX, s32 doZ) {
    ActorTransformView *t = a->u38.ptr38;

    if (doX) {
        t->posX = (t->posX + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
    if (doZ) {
        t->posZ = (t->posZ + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
}

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

void func_800677C8(Actor *a, Stg20Marks *m, s32 dir, s32 timer) {
    Stg20Cell *c;
    s32 i;

    if (dir == -1) {
        c = func_80067504(a);
    } else {
        c = func_80067714(a, dir);
    }
    for (i = 0; i < 5; i++) {
        if (m->cell[i].x == c->x && m->cell[i].y == c->y) {
            goto found;
        }
    }
    for (i = 0; i < 5; i++) {
        if (m->timer[i] == 0) {
            goto found;
        }
    }
    return;
found:
    m->cell[i] = *c;
    m->timer[i] = timer;
}

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

void func_80068364(Actor *a) {
    Stg20BlinkTask *t = (Stg20BlinkTask *)a;
    Stg20Work *w = t->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = w->field_0 * 0x36 - 0x8E;
            q->y = -0x60;
            q->visible = ((t->field_24 >> 4) ^ 1) & 1;
        }
    }
    Gfx_DrawParts((s32)p);
}

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

void func_80068B44(Actor *a) {
    Stg20NameWork *w = (Stg20NameWork *)a->work;
    Stg20TextArgs args;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1((s32 *)w, 1);
        Flag_Set(0x10, 0);
        Task_NextState0(a);
        break;
    case 1:
        if (w->field_18 != 0) {
            args.text = w->field_4;
            args.bigFont = 1;
            args.color = 0;
            args.pos.x = 0x10;
            args.pos.y = 0xBA;
            args.charAdvance = 0;
            args.lineAdvance = 0x10;
            args.charDelay = 3;
            args.strArg0 = (s32)w->name;
            Text_Open(w, &args);
            Flag_Set(0x10, 0);
            w->field_1C = -1;
            w->field_18 = 0;
        }
        if (w->field_1C == -1 && Flag_Test(0x10) != 0) {
            w->field_1C = Flag_Test(0x11);
        }
        break;
    case 2:
        break;
    }
}

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

void func_80068DD8(s32 text, s32 digi) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20NameWork *w = (Stg20NameWork *)e->work;
        u8 *name = Digi_GetDefaultName(digi);
        s32 i;

        for (i = 0; i < 0xE; i++) {
            w->name[i] = name[i];
        }
        w->field_4 = (s32)Cd_GetFileEntry(text + 0x1FD0000);
        w->field_18 = 1;
    }
}

s32 func_80068E6C(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        return ((Stg20TextWork *)e->work)->field_1C;
    }
    return 0;
}

void func_80068EB0(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        if (D_800709D0 == 0) {
            Text_OpenById(w, 0x102, 0, D_8007001C[0]);
        } else {
            Text_OpenById(w, 0x103, 0, D_8007001C[1]);
            Text_OpenById(&w[1], 0x104, 0, D_8007001C[2]);
        }
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

void func_80068FB8(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120001);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 6) {
            switch (D_800709B0.field_20) {
            case 0:
            default:
                q->visible = 0;
                break;
            case 1:
                q->visible = ((u32)q->groupMask >> 1) & 1;
                break;
            case 2:
                q->visible = ((u32)q->groupMask >> 2) & 1;
                break;
            }
        }
    }
    Gfx_DrawParts((s32)p);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069068);

void func_8006964C(Actor *a) {
    Stg20StatusWork *w = (Stg20StatusWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120008);

    Gfx_SetPartsNumber(p, 2, 3, w->digi->field_14);
    Gfx_SetPartsNumber(p, 4, 3, w->digi->field_16);
    Gfx_SetPartsNumber(p, 8, 3, w->digi->field_18);
    Gfx_SetPartsNumber(p, 0x10, 3, w->digi->field_1A);
    Gfx_SetPartsNumber(p, 0x20, 2, w->digi->level);
    Gfx_SetPartsNumber(p, 0x40, 3, w->digi->field_1C);
    Gfx_SetPartsNumber(p, 0x80, 3, w->digi->field_1E);
    Gfx_SetPartsNumber(p, 0x100, 3, w->digi->field_20);
    Gfx_SetPartsNumber(p, 0x200, 8, w->digi->exp);
    Gfx_SetPartsNumber(p, 0x400, 8, Digi_GetExpToNextLevel(w->digi->level, w->digi->maxLevel, w->digi->exp));
    Gfx_SetPartsNumber(p, 0x800, 2, w->digi->field_E);
    Gfx_DrawParts((s32)p);
}

void func_800697AC(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    Stg20Roster *e = &D_8005E704[a->field_8];
    s32 cnt[4];
    s32 i;
    s32 j;
    s32 s;
    s32 k;

    for (i = 0; i < 4; i++) {
        cnt[i] = 0;
        w->groups[i].count = 0;
        for (j = 0; j < 12; j++) {
            w->groups[i].list[j] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        s = e->skills[i];
        if (s != 0) {
            k = func_8001EE34(s);
            w->groups[k].list[cnt[k]] = s;
            cnt[k]++;
        }
    }
    for (i = 0; i < 4; i++) {
        w->groups[i].count = cnt[i];
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_800698F4);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069AAC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_80069D98);

void func_8006A000(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        func_80067480(w, (s32)D_8005E750[D_800709B0.field_34].name, 0, &D_8007010C[0], 0);
        func_80067480(&w[1], (s32)D_8005E750[D_800709B0.field_38].name, 0, &D_8007010C[1], 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

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

void func_8006A254(Actor *a) {
    Actor *t;

    switch (a->stateLevel0) {
    case 0:
        Actor_InitTransform(a, D_80043704, 0);
        Gfx_AttachModel(a, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(a);
        Task_NextState0(a);
        break;
    case 1:
        t = ((Stg20LinkWork *)a->work)->target;
        if (t != NULL && t->stateLevel0 != 0) {
            ((Stg20PosView *)a->u38.ptr38)->pos = ((Stg20PosView *)t->u38.ptr38)->pos;
        }
        break;
    case 2:
        break;
    }
}

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

void func_8006A744(Actor *a) {
    Stg20ExitWork *w = (Stg20ExitWork *)a->work;
    Stg20Exit *e;
    Stg20Cell c;

    switch (a->stateLevel0) {
    case 0:
        Task_NextState0(a);
        break;
    case 1:
        for (e = (Stg20Exit *)func_80066714()->field_C; e->x != 0; e++) {
            c.x = e->x;
            c.y = e->y;
            if (func_800636A8(&c) & 0x80) {
                Task_FindFirst(0x302, 0, -1)->field_8 = 1;
                w->mode = e->mode + 0x300;
                w->arg = e->arg;
                Task_NextState0(a);
                break;
            }
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                D_8005F770.nextGameMode = w->mode;
                D_8005F770.field_24 = w->arg;
            }
            break;
        }
        break;
    }
}

Actor *func_8006A8C0(s32 id) {
    Actor *e;

    for (e = (Actor *)Task_FindFirst(0x302, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
        if (e->digiId == id) {
            return e;
        }
    }
    return NULL;
}

void func_8006A920(Actor *a, Stg20Pos2 *pos) {
    Stg20CursorWork *w = (Stg20CursorWork *)a->work;
    ActorTransformView *t = a->u38.ptr38;
    Stg20Cell c = *func_80067504(a);

    if (c.x != pos->x && c.y != pos->y) {
        t->posX = (pos->x - 11) * 0x600;
        t->posY = 0;
        t->posZ = -((pos->y - 11) * 0x600);
    }
    w->x = pos->x;
    w->y = pos->y;
    w->field_8 = w->field_A = 1;
    w->field_74 = 0;
    w->field_5C = 0;
    w->field_18 = 0;
}

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

void func_8006AA4C(Actor *a, Stg20Spawn *s) {
    Stg20SpawnWork *w = (Stg20SpawnWork *)a->work;
    s32 i;

    a->digiId = s->id;
    w->field_0 = s->field_2;
    w->field_1C = s->field_1C;
    for (i = 0; i < 6; i++) {
        w->blk[i] = s->blk[i];
    }
    ((Stg20ModelTask *)a)->field_4 = 1;
    if (s->id == 0x1F2) {
        ((Stg20ModelTask *)a)->field_4 = -3;
    } else if (s->id == 0x1F3) {
        ((Stg20ModelTask *)a)->field_4 = -2;
    } else if (s->id == 0x1F4) {
        ((Stg20ModelTask *)a)->field_4 = 0;
    }
    w->visible = 1;
    if (s->id >= 0x1F1 && s->id <= 0x1F3) {
        w->visible = 0;
    }
}

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

void func_8006B7C8(Actor *a) {
    Stg20Draw2Work *w = (Stg20Draw2Work *)a->work;

    if (w->visible != 0) {
        Gfx_AttachModel(a, w->modelId);
        Anim_StepModelAnim(a);
        Actor_UpdateTransform(a);
        if (Actor_ProjectToScreen(a) == 0) {
            Gfx_CalcModelBoneMatrices(a);
            Gfx_DrawTexModel(a, 0);
        }
    }
}

void func_8006B840(Actor *a, Stg20Vec3 *v) {
    *(Stg20Vec3 *)a->work = *v;
}

void func_8006B860(Actor *a) {
    Stg20XaWork *w = (Stg20XaWork *)a->work;
    u8 filter[8];
    u8 mode[8];
    u8 pos[8];
    u8 res[8];
    u8 res2[8];

    switch (a->stateLevel0) {
    case 0:
    default:
        switch (a->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId);
            w->end = w->start + w->len;
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, pos);
            CdControlF(0x15, (s32)pos);
            Task_NextState1(a);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(a, 0);
                break;
            case 2:
                Task_NextState0(a);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(a);
            }
            break;
        case 1:
            if ((((Stg20BlinkTask *)a)->field_24 & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(a, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                        Task_SetState0(a, 3);
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

void func_8006BA5C(Actor *a) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a);
}

void func_8006BA90(Actor *a) {
    if (a->stateLevel0 == 0) {
        Task_NextState0(a);
    }
}

void func_8006BAC0(Actor *a) {
    GfxPart *p;
    GfxPart *q;

    if (D_8005F788[0] < 0x333) {
        p = (GfxPart *)Cd_GetFileEntry(0xDD60001);
    } else {
        p = (GfxPart *)Cd_GetFileEntry(0xC930001);
    }
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask == 2) {
            q->palette = Math_CycleRange(a->elapsed, 6, 0, 7);
        }
    }
    Gfx_DrawParts((s32)p);
}

void func_8006BB7C(Actor *a) {
    s32 *w = (s32 *)a->work;

    if (a->stateLevel0 == 0) {
        Mem_FillWordsNeg1(w, 1);
        Text_OpenById(w, 0x5F, 0, D_80063588);
        Task_NextState0(a);
    }
}

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

void func_8006BE04(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60004);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = D_800709B0.field_50 != 0 ? -0x6C : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006BEDC);

void func_8006C040(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void func_8006C074(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930008);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = D_800709B0.field_50 != 0 ? -0x57 : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}

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

s32 func_8006C1C4(s32 id) {
    if (func_8006C18C(id)) {
        return 0x132;
    }
    if (func_8006C14C(D_800704FC, id)) {
        return 0x131;
    }
    if (func_8006C14C(D_80070530, id)) {
        if (D_8005E65C != 0) {
            return 0x12F;
        }
        return 0x130;
    }
    if (func_8006C14C(D_80070548, id)) {
        if (D_8005E65E != 0) {
            return 0x12F;
        }
        return 0x133;
    }
    if (func_8006C14C(D_800705A4, id)) {
        if (D_8005E662 != 0) {
            return 0x12F;
        }
        return 0x135;
    }
    if (func_8006C14C(D_800705B4, id)) {
        if (D_8005E660 != 0) {
            return 0x12F;
        }
        return 0x136;
    }
    if (func_8006C14C(D_80070554, id)) {
        if (D_8005E64C == 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070570, id)) {
        if (D_8005E64C == 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070588, id)) {
        if (D_8005E64C == 0xEB) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070580, id)) {
        if (D_8005E64C != 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070594, id)) {
        if (D_8005E64C != 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    return 0;
}

s32 func_8006C3B8(s32 id) {
    s32 n;
    s32 i;
    s32 r;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&D_8005E620)->field_66[i] == id) {
            n++;
        }
    }
    n += ((Stg20GameState *)&D_8005E620)->field_DD4[id];
    r = 99;
    if (n < 100) {
        r = n;
    }
    return r;
}

void func_8006C420(u8 *out, s32 v) {
    u8 d[5];
    s32 n;
    s32 i;
    s32 lead;

    n = func_8001E180(v);
    if (D_80070A04 != 0) {
        n /= 2;
    }
    n = n < 0 ? 0 : n;
    for (i = 4; i != -1; i--) {
        d[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    for (i = 0; i < 5; i++) {
        if (i == 4 || lead == 0 || d[i] != 0) {
            lead = 0;
            out[i] = d[i];
        }
    }
}

void func_8006C514(Actor *a, s32 id) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 i;
    s32 j;
    u8 *name;
    u8 *list = (u8 *)Cd_GetFileEntry(id + 0x3CF0000);

    w->count = 0;
    for (i = 0; i < 50; i++) {
        D_80070A08.items[i] = 0;
        for (j = 0; j < 25; j++) {
            D_80070A08.names[i][j] = 0xFD;
        }
        D_80070A08.names[i][24] = 0xFF;
    }
    for (i = 0; i < 50; i++) {
        if (list[i] == 0) {
            break;
        }
        D_80070A08.items[i] = list[i];
        name = (u8 *)Item_GetNameText(list[i]);
        for (j = 0; j < 10; j++) {
            if (*name == 0xFF) {
                break;
            }
            D_80070A08.names[i][j] = *name++;
        }
        func_8006C420(&D_80070A08.names[i][14], list[i]);
        D_80070A08.names[i][19] = 0xB;
        D_80070A08.names[i][20] = 0x12;
        D_80070A08.names[i][21] = 0x1D;
        D_80070A08.names[i][22] = 0x36;
        w->count++;
    }
    w->pages = w->count != 0 ? (w->count - 1) / 8 : 0;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C6F0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006C8BC);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006CB58);

void func_8006D0F0(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xF);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D124);

void func_8006D2C0(void *t, s32 id, Halves pos, s32 arg) {
    Stg20TextArgs args;

    if (id < 1000) {
        args.text = (s32)Cd_GetFileEntry(id + 0x1FD0000);
    } else {
        args.text = Item_GetDescText(id - 1000);
    }
    args.bigFont = 1;
    args.color = 0;
    args.pos.x = pos.lo;
    args.pos.y = pos.hi;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = 0;
    args.strArg0 = arg;
    Text_Open(t, &args);
}

void func_8006D350(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    for (i = 0x2F; i >= 0; i--) {
        ((Stg20GameState *)&D_8005E620)->field_66[i] = 0;
    }
    n = 0;
    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] != 0) {
            ((Stg20GameState *)&D_8005E620)->field_66[n++] = w->field_60[i];
        }
    }
    Item_SortList();
}

void func_8006D3CC(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&D_8005E620)->field_66[i] != 0) {
            w->field_60[n++] = ((Stg20GameState *)&D_8005E620)->field_66[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        if (((Stg20GameState *)&D_8005E620)->field_2C[i] != 0) {
            w->field_60[n++] = ((Stg20GameState *)&D_8005E620)->field_2C[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        ((Stg20GameState *)&D_8005E620)->field_2C[i] = 0;
        ((Stg20GameState *)&D_8005E620)->field_52[i] = 0;
    }
}

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

void func_8006D7DC(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    s32 i;
    s32 id;

    if (w->dirty != 0) {
        w->dirty = 0;
        for (i = 0; i < 10; i++) {
            Text_Close(&w->texts[i]);
        }
        for (i = 0; i < 10; i++) {
            if (w->items[i + w->top] == 0) {
                break;
            }
            Text_OpenPacked(&w->texts[i], Item_GetNameText(w->items[i + w->top]), w->colors[i + w->top] << 2, D_800705DC[i + 8]);
        }
        if (a->stateLevel2 == 2) {
            Text_Close(&w->descText);
            id = w->items[w->top + w->cursor];
            if (id != 0) {
                func_8006D2C0(&w->descText, id + 1000, D_800705DC[7], 0);
            }
        }
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006D93C);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006DCCC);

void func_8006E720(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0x12);
    Task_DefaultDestroy(a);
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E754);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006E9E8);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EA90);

void func_8006ED24(Actor *a) {
    Stg20ItemWork *w = (Stg20ItemWork *)a->work;
    s32 i;

    if (w->dirty != 0) {
        w->dirty = 0;
        for (i = 0; i < 6; i++) {
            Text_OpenPacked(&w->texts[i], (s32)w->recs[i].name, 0, D_800706A4[i + 4]);
        }
        Text_Close(&w->descText);
        if (w->recs[w->index].item != 0) {
            Text_OpenPacked(&w->descText, Item_GetDescText(w->recs[w->index].item), 0, D_800706A4[10]);
        }
    }
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006EE24);

void func_8006F258(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xC);
    Task_DefaultDestroy(a);
}

void func_8006F28C(Actor *a) {
    Stg20RowWork *w = (Stg20RowWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = -0x56;
            q->y = w->field_30 * 12 - 0x34;
        }
    }
    Gfx_DrawParts((s32)p);
}

Stg20FileRec *func_8006F360(s32 i) {
    Stg20FileRec *r = (Stg20FileRec *)Cd_GetFileEntry(D_8005F788[0] + 0xD28FCD6);

    r = &r[i];

    if (r->field_13 == 0) {
        s32 base = Cd_GetFileOrNull(0xD29);

        r->field_13 = 1;
        r->field_4 += base;
    }
    return r;
}

void func_8006F3D8(Actor *a, s32 v) {
    a->field_8 = v;
}

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F3E0);

INCLUDE_ASM("asm/USA/stag2000/nonmatchings/stag2000", func_8006F730);

void func_8006FBF0(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;

    RotMatrixYXZ(w->rot, &w->coord.coord);
    w->coord.coord.t[0] = w->tx;
    w->coord.coord.t[1] = w->ty;
    w->coord.coord.t[2] = w->tz;
    w->coord.flg = 0;
    GsSetProjection(w->proj);
    GsSetRefView2(&w->view);
}
