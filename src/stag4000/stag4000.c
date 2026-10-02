#include "common.h"
#include "stag4000/stag4000.h"

void func_80063758(void) {
    Blk16 *l;
    Stg40Rgb *c;

    Sys_SetFrameRate30();
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x20);
    Gpu_AllocPacketBufs(0x19000);
    l = (Blk16 *)Cd_GetFileEntry(0xE200001);
    c = (Stg40Rgb *)Cd_GetFileEntry(0xE200002);
    func_800677FC(l, c->r, c->g, c->b);
}

void func_800637E8(void) {
    Stg40Blk5071C *b = D_8005071C;

    b->field_E54 = &b->field_E34;
    b->field_E34.field_0 = 0x40;
    b->field_E54->field_2 = 0x30;
}

void func_80063814(void) {
    Stg40Stage14 *tbl;
    s32 i;
    Stg40Ent48 *e;

    D_8005071C->field_0 = 1;
    D_8005071C->field_5 = 0;
    D_8005071C->field_3 = 0;
    D_8005071C->field_6 = 0;
    D_8005071C->field_7 = 0;
    if (D_8005F770.prevGameMode == 0x32B) {
        D_8005071C->field_6 = 1;
    }
    if (D_8005F770.gameMode != 0x200) {
        D_8005071C->field_1058 = (u16)D_8005F770.gameMode - 0x201;
    } else {
        D_8005071C->field_1058 = D_8005F770.field_24;
    }
    tbl = (Stg40Stage14 *)Cd_GetFileEntry(0xE20000A);
    D_8005071C->field_1044 = tbl[D_8005071C->field_1058];
    D_8005071C->field_105C = tbl[D_8005071C->field_1058].field_C;
    D_8005071C->field_1060 = tbl[D_8005071C->field_1058].field_10;
    e = D_8005071C->field_18;
    for (i = 0; i < 41; i++, e++) {
        e->field_0 = 0;
    }
    D_8005071C->field_BA5 = D_8005071C->field_BA6 = D_8005071C->field_BA7 = D_8005071C->field_BA8 = 0;
    for (i = 0; i < 12; i++) {
        D_8005071C->field_BA9[i] = 0;
    }
    D_8005071C->field_8 = D_8005071C->field_1044.field_0;
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        if (D_80050720->elems[i].state < 2) {
            break;
        }
        D_80050720->elems[i].state = i + 3;
    }
}

void func_800639FC(void) {
    func_80070DC0();
    func_8006FED4();
    func_8006FFCC();
    func_800707D0();
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063A34);

void func_80063EF8(void) {
}

s32 func_80063F00(Actor *arg0) {
    Blk13 sp10;
    Stg40Ent48 *e;
    ActorWork *w = arg0->work;
    s16 q;
    s32 a0v;
    s32 a1v;
    s32 ret;
    u8 **slot;

    if (D_8005071C->field_1 == 0) {
        return 0;
    }
    switch (D_8005071C->field_1) {
    case 1:
    default:
        func_800721A8(Cd_GetFileEntry(0xE200003));
        D_8005071C->field_2 = 1;
        w->field_0 = 0x500;
        e = D_8005071C->field_1018.field_0[0];
        sp10 = D_80063384;
        D_8005071C->field_103D = sp10.b[func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0xF];
        slot = &e->field_10;
        D_8005071C->field_103E = ((Stg40SlotInfo *)e->field_10)->field_E;
        q = ((Stg40SlotInfo *)*slot)->field_C / (s16)((Stg40SlotInfo *)*slot)->field_E;
        D_8005071C->field_1040 = q;
        if ((s16)q >= 4) {
            q = 3;
        }
        D_8005071C->field_1040 = q;
        D_8005F794 = ((Stg40SlotInfo *)*slot)->field_0;
        if (((Stg40SlotInfo *)*slot)->field_2 != 0) {
            if (Flag_Test(0x88) != 0 && D_8005071C->field_1044.field_8 == 0x100) {
                a0v = 0x101;
                a1v = 1;
            } else {
                a0v = D_8005071C->field_1044.field_8;
                a1v = D_8005071C->field_1044.field_A;
            }
        } else {
            a0v = 0x200;
            a1v = 1;
        }
        ret = 1;
        Snd_PlayById(a0v, a1v);
        Snd_PlayById(0x206, 0);
        Task_SetState1(arg0, 3);
        Gfx_FadeOutToBlack(8);
        Cd_QueueFile(0x193);
        break;

    case 2:
        func_800721A8(Cd_GetFileEntry(0xE200004));
        w->field_0 = D_8005F788;
        Task_SetState1(arg0, 3);
        ret = 1;
        D_8005071C->field_3 = D_8005071C->field_3 + ret;
        break;

    case 3:
    case 4:
        if (D_8005071C->field_6 == 0) {
            w->field_0 = 0x301;
            D_8005F770.field_24 = D_8005071C->field_7 ? 3 : 4;
        } else if (!Flag_Test(0x81)) {
            w->field_0 = 0x301;
            D_8005F770.field_24 = D_8005071C->field_7 ? 3 : 4;
        } else {
            w->field_0 = 0x321;
            D_8005F770.field_24 = D_8005071C->field_7 ? 2 : 3;
        }
        if (D_8005071C->field_7 != 0) {
            func_800721A8(Cd_GetFileEntry(0xE200009));
        } else {
            func_800721A8(Cd_GetFileEntry(0xE200004));
        }
        ret = 1;
        Task_SetState1(arg0, 3);
        break;
    }
    return ret;
}

#ifdef NORMALIZED
void func_8006424C(Actor *arg0) {
    ActorWork *work = arg0->work;
    s32 st = arg0->stateLevel0;
    Stg40AA4 *ctx = (Stg40AA4 *)arg0->u34.children;
    Actor *bt;
    s32 a0v;
    switch (st) {
    default:
    case 0:
        D_80072AA0 = arg0;
        D_80072AA4 = ctx;
        D_80072B60 = (Stg40B60 *)Mem_Alloc(0x190, 2);
        func_80063A34(arg0);
        Task_NextState0(arg0);
        D_80072B60->field_7E = 0;
        Snd_SetSlotContent(1, D_8005071C->field_1044.field_2);
        work->field_8 = 0;
        break;
    case 1:
        if (work->field_8 == 0 && Snd_AnySlotLoading() == 0) {
            work->field_8 = st;
            Snd_PlayById(D_8005071C->field_1044.field_4, D_8005071C->field_1044.field_6);
            Snd_SetSlotContent(2, 0x19);
        }
        switch (arg0->stateLevel1) {
        default:
        case 0:
            st = arg0->stateLevel2;
            switch (st) {
            default:
            case 0:
                a0v = D_8005071C->field_0;
                if (a0v >= 3) {
                    goto setSt;
                }
                if (a0v != 0) {
                    goto load;
                }
            setSt:
                Task_SetState1(arg0, 1);
                goto done0;
            load:
                if (a0v == 1) {
                    a0v = 0xE200006;
                } else {
                    a0v = 0xE200005;
                }
                func_800721A8(Cd_GetFileEntry(a0v));
                Task_NextState2(arg0);
                D_8005071C->field_2 = 1;
            done0:
                D_8005071C->field_2 = 1;
                D_80072B60->field_7E = 0;
                break;
            case 1:
                if (func_80072114() == 0) {
                    bt = D_80072B60->field_8;
                    if (func_8006E6CC() != 0) {
                        Task_SetState1(bt, 0x1E);
                        Task_SetState1(arg0, 2);
                    } else if (func_8006E330() != 0) {
                        Task_SetState1(bt, 4);
                        D_8005071C->field_1 = st;
                        D_8005071C->field_2 = st;
                        func_80063F00(arg0);
                    } else {
                        Task_SetState1(arg0, 1);
                    }
                } else {
                    if (++arg0->stateLevel3 == 6) {
                        Cd_QueueFile(0x1FD);
                        Cd_QueueFile(0x315);
                        Cd_QueueFile(0x7D4);
                        Cd_QueueFile(0x457);
                        Cd_QueueFile(0x6B5);
                        Cd_QueueFile(0x312);
                    }
                }
                break;
            case 2:
                break;
            }
            break;
        case 1:
            st = arg0->stateLevel2;
            switch (st) {
            default:
            case 0:
                Task_Create(0x209, &ctx->field_8, 0);
                D_8005071C->field_2 = 0;
                D_80072B60->field_7E = D_80050720->field_0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (D_8005071C->field_2 == 2) {
                    Task_SetState0((Actor *)ctx->field_8, 2);
                    D_80072B60->field_7E = 0;
                    Task_SetState1(arg0, 2);
                } else if (func_80063F00(arg0) == st) {
                    D_80072B60->field_7E = 0;
                }
                break;
            }
            break;
        case 2:
            if (D_8005071C->field_2 != 2) {
                if (D_8005071C->field_2 == 0) {
                    Task_SetState1(arg0, 1);
                } else if (func_80063F00(arg0) != 1) {
                    Task_SetState1(arg0, 1);
                }
            }
            break;
        case 4:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                Task_SetState0((Actor *)ctx->field_8, 2);
                D_80072B60->field_7E = 0;
                Gfx_FadeOutToBlack(0x20);
                Task_NextState2(arg0);
                break;
            case 1:
                if (ctx->field_8 == 0) {
                    if (arg0->stateLevel4++ >= 0xF) {
                        Task_Create(0xB, &ctx->field_4, 0);
                        arg0->childCount = 2;
                        Task_NextState2(arg0);
                    }
                }
                break;
            case 2:
                if (ctx->field_4 == 0) {
                    arg0->childCount = 0x38;
                    Gfx_FadeInFromBlack(0x20);
                    if (D_80050764 == 1) {
                        Task_SetState1(D_80072B60->field_8, 0x1D);
                        Task_SetState2(arg0, 4);
                    } else {
                        Task_Create(0x209, &ctx->field_8, 0);
                        D_80072B60->field_7E = D_80050720->field_0;
                        Task_NextState2(arg0);
                    }
                }
                break;
            case 3:
                if (arg0->stateLevel4++ >= 8) {
                    D_8005071C->field_2 = 0;
                    Task_SetState1(arg0, 1);
                    Task_SetState2(arg0, 1);
                }
                break;
            case 4:
                if (arg0->stateLevel4++ >= 8) {
                    D_8005071C->field_1 = 4;
                    Task_SetState1(D_80072B60->field_8, 0x17);
                    func_80063F00(arg0);
                }
                break;
            }
            break;
        case 3:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                D_8005071C->field_2 = 1;
                Task_SetState0((Actor *)ctx->field_8, 2);
                Task_NextState2(arg0);
                break;
            case 1:
                if (func_80072114() == 0) {
                    D_8005F78C = work->field_0;
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006424C);
void func_8006424C(Actor *arg0);
#endif

void func_80064830(void) {
}

void func_80064838(Actor *a0) {
    func_8006ED88(0);
    func_8006FF28();
    Mem_Free((ActorWork *)D_80072B60);
    Task_DefaultDestroy(a0);
}

void func_80064880(void) {
    s32 i;

    for (i = 0x3F; i >= 0; i--) {
        D_80050948[i] = 0;
    }
    D_8005075C = 0;
}

#ifdef NORMALIZED
s32 func_800648AC(s32 val) {
    s32 i;
    s32 *p;
    s32 count;
    s32 ret;

    i = 0;
    ret = 0;
    p = &D_80050948[0];
    if (D_8005075C > 0) {
        do {
            if (*p == val) {
                return 1;
            }
            i++;
            if (i >= D_8005075C) {
                break;
            }
            p++;
        } while (1);
    }
    count = D_8005075C;
    if (count < 0x40) {
        ret = 1;
        D_80050948[count] = val;
        D_8005075C = count + 1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800648AC);
s32 func_800648AC(s32 val);
#endif

void func_80064930(Actor *a0, s32 a1) {
    Task_SetState0(a0, 2);
    Task_SetState1(a0, (u8)a1);
}

void func_80064970(Actor *a0, Stg40InitArg *a1) {
    Stg40InitWork *w = (Stg40InitWork *)a0->work;

    w->field_20 = a1->field_0;
    w->field_24 = a1->field_4;
}

void func_8006498C(Actor *a0) {
    Stg40InitWork *w = (Stg40InitWork *)a0->work;
    Stg40Model25DC *ent;
    ActorModel *m;

    switch (a0->stateLevel0) {
    case 0:
    default:
        ent = &D_800725DC[(s16)w->field_24];
        Actor_InitTransform(a0, w->field_4, w->field_10);
        w->field_4[2] = 0;
        w->field_4[1] = 0;
        w->field_4[0] = 0;
        w->field_10 = 0;
        a0->digiId = w->field_0 = ent->field_0;
        w->field_14 = Digi_GetModelFile(a0->digiId);
        w->field_18 = Anim_GetModelAnimFile(a0->digiId, 4);
        Gfx_AttachModel(a0, w->field_14)->otIndex = 3;
        Task_NextState0(a0);
        if (ent->field_2 != 1) {
            Anim_SetModelAnim(a0, 0x28);
            w->field_28 = 0;
            break;
        }
        Anim_SetModelAnim(a0, 0x2C);
        w->field_28 = -0xA80;
        Task_NextState1(a0);
        break;
    case 1:
        m = a0->model;
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (m->animDone < 0) {
                Task_SetState0(a0, 3);
            }
            break;
        case 1:
            if (m->animDone < 0) {
                Anim_SetModelAnim(a0, 0x28);
                Task_NextState1(a0);
            }
            break;
        case 2:
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_80064AFC(Actor *a0) {
    Stg40ChildWork *w = (Stg40ChildWork *)a0->work;
    Actor *p = w->field_20;
    Stg40Xform *x;

    if (((Stg40ActWork *)p->work)->field_34 != 0) {
        x = (Stg40Xform *)a0->u38.ptr38;
        *x = *(Stg40Xform *)p->u38.ptr38;
        x->field_44 = 0;
        x->field_40 = 0;
        x->field_42 = 0;
        x->field_34 += w->field_28;
        Gfx_AttachModel(a0, w->field_14)->otIndex = 3;
        Anim_StepModelAnim(a0);
        Actor_UpdateTransform(a0);
        Gfx_CalcModelBoneMatrices(a0);
        Gfx_DrawTexModel(a0, 0);
    }
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064BD8);

void func_80065134(Stg40Loc *loc) {
    D_8005071C->field_1064 = loc;
    Task_SetState1(D_80072B68, 0);
}

void func_80065168(s32 a0, s32 a1, s32 a2) {
    Actor *t = D_80072B68;
    Stg40B60 *b = D_80072B60;
    Stg40B68Work *w = (Stg40B68Work *)t->work;

    w->field_1E90 = a0;
    w->field_1E94 = a1;
    w->field_1E98 = b->field_2C;
    w->field_1E9C = b->field_30;
    w->field_1EA0 = a2;
    Task_SetState1(t, 1);
}

void func_800651C0(Stg40Loc *loc, s32 a1) {
    Actor *t = D_80072B68;
    Stg40B68Work *w = (Stg40B68Work *)t->work;
    Stg40B60 *b;

    w->field_1E90 = loc->field_C;
    w->field_1E94 = loc->field_10;
    b = D_80072B60;
    w->field_1E98 = b->field_2C;
    w->field_1E9C = b->field_30;
    w->field_1EA0 = a1;
    D_8005071C->field_1064 = loc;
    Task_SetState1(t, 2);
}

s32 func_80065230(void) {
    Stg40B68Work *w = (Stg40B68Work *)D_80072B68->work;
    s32 r = 0;

    if (D_80072B60->field_2C == w->field_1E90 && D_80072B60->field_30 == w->field_1E94) {
        r = -1;
    }
    return r;
}

void func_80065278(Actor *a0) {
    Stg40B68Work *w = (Stg40B68Work *)a0->work;
    s32 x0 = w->field_1E90;
    s32 y0 = w->field_1E94;
    s32 n = w->field_1EA0;
    s32 k = n - a0->stateLevel2;
    s32 dx = (x0 - w->field_1E98) * k / n;
    s32 dy = (y0 - w->field_1E9C) * k / n;
    Stg40B60 *b = D_80072B60;

    b->field_2C = x0 - dx;
    b->field_30 = y0 - dy;
    a0->stateLevel2++;
}

void func_80065300(Actor *a0) {
    Stg40B68Work *w = (Stg40B68Work *)a0->work;

    switch (a0->stateLevel1) {
    case 0:
    default:
        D_80072B60->field_2C = D_8005071C->field_1064->field_C;
        D_80072B60->field_30 = D_8005071C->field_1064->field_10;
        break;
    case 1:
        if (a0->stateLevel2 < w->field_1EA0) {
            func_80065278(a0);
        } else {
            D_80072B60->field_2C = w->field_1E90;
            D_80072B60->field_30 = w->field_1E94;
        }
        break;
    case 2:
        if (a0->stateLevel2 < w->field_1EA0) {
            func_80065278(a0);
        } else {
            D_80072B60->field_2C = w->field_1E90;
            D_80072B60->field_30 = w->field_1E94;
            Task_SetState1(a0, 0);
        }
        break;
    }
}

s32 func_800653EC(s32 a, s32 b, s32 c, s32 d) {
    if (a >= b) {
        b = a;
    }
    a = b;
    if (a >= c) {
        c = a;
    }
    a = c;
    if (a >= d) {
        d = a;
    }
    return d;
}

s32 func_80065424(s32 a, s32 b, s32 c, s32 d) {
    if (b >= a) {
        b = a;
    }
    a = b;
    if (c >= a) {
        c = a;
    }
    a = c;
    if (d >= a) {
        d = a;
    }
    return d;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006545C);

#ifdef NORMALIZED
void func_80065890(ActorWork *arg0)
{
    Stg40Cell *grid;
    s32 rowCount;
    s32 colCount;
    s32 gridCols;
    s32 gridRows;
    Stg40E34 *e54;
    s32 mapRow;
    s32 row;
    s32 col;
    s32 mapCol;
    Stg40Tile *tp;
    Stg40Vtx *v0p;
    Stg40Vtx *v1p;
    s32 r;
    s32 k;
    s32 a;
    s32 lt400;
    s32 n;
    Stg40Cell *cell;

    e54 = D_8005071C->field_E54;
    grid = (Stg40Cell *)D_8005071C->field_E58;
    rowCount = 9;
    gridCols = e54->field_0;
    gridRows = e54->field_2;
    if (D_80072B60->field_30 & 0x3F) {
        rowCount = 0xA;
    }
    colCount = 9;
    if (D_80072B60->field_2C & 0x3F) {
        colCount = 0xA;
    }
    mapRow = D_80072B60->field_30 / 64 - 4;
    for (row = 0; row < rowCount; row++) {
        tp = ((Stg40W667C *)arg0)->field_F20[row];
        v0p = ((Stg40W667C *)arg0)->field_0[row];
        v1p = ((Stg40W667C *)arg0)->field_0[row + 1];
        mapCol = D_80072B60->field_2C / 64 - 4;
        for (col = 0; col < colCount; col++) {
            tp->field_4 = func_800653EC(v0p[0].s[0].field_4, v0p[1].s[0].field_4, v1p[0].s[0].field_4, v1p[1].s[0].field_4);
            tp->field_8 = func_80065424(v0p[0].s[1].field_4, v0p[1].s[1].field_4, v1p[0].s[1].field_4, v1p[1].s[1].field_4);
            if (mapCol < 0 || mapRow < 0 || mapCol >= gridCols || mapRow >= gridRows) {
                tp->field_0 = 0;
                tp->field_2 = 0;
                tp->field_3 = 0;
            } else {
                r = Rand_GetAt(mapCol + (mapRow << 6));
                cell = &grid[mapRow * gridCols + mapCol];
                tp->field_0 = cell->field_0;
                tp->field_2 = cell->field_3;
                k = tp->field_0 & 0xF;
                switch (k) {
                case 0:
                    tp->field_3 = 0;
                    break;
                case 1:
                case 2:
                    n = 0;
                    if (k == 1) {
                        n = 0x18;
                    }
                    tp->field_3 = n;
                    a = tp->field_3 + ((tp->field_0 >> 9) & 1);
                    tp->field_3 = a;
                    a = tp->field_3;
                    if (tp->field_0 & 0x80) {
                        a += 2;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if (tp->field_0 & 0x800) {
                        a += 4;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x200) {
                        a += 8;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a += 8;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->field_3 = a;
                    break;
                default:
                    tp->field_3 = (tp->field_0 & 0xF) + 0x2D;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->field_3 = a;
                    break;
                }
            }
            mapCol++;
            v0p++;
            v1p++;
            tp++;
        }
        mapRow++;
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065890);
void func_80065890(ActorWork *arg0);
#endif

void func_80065BF8(s32 x, s32 z, s32 y, Stg40Vec3 *out) {
    Stg40B60 *b = D_80072B60;
    s32 t;

    out->field_4 = -(((z - b->field_30) << 11) / 64);
    t = x - b->field_2C;
    out->field_2 = -y;
    out->field_0 = t * 40;
}

s32 func_80065C50(Stg40W667C *w, s32 pkt, s32 x, s32 y)
{
    Stg40Tile *tile = &w->field_F20[y][x];
    Stg40Rec10 *rec;
    u8 *base;
    s32 i;
    Stg40Vtx *a;
    Stg40Vtx *b;
    s32 k;
    u32 *ot;
    s32 ax;
    s32 ay;
    s32 n;
    s32 m;
    Stg40FT4 *src;

    base = &D_8007265C[(u16)D_8005071C->field_E54->field_A * 5];

    for (i = 0; i < 4; i++) {
        rec = &D_80072670[i];
        if ((tile->field_0 & rec->field_0) == 0) {
            continue;
        }
        a = &w->field_0[y + rec->field_4][x + rec->field_3];
        b = &w->field_0[y + rec->field_6][x + rec->field_5];
        if (a->s[0].flag + b->s[0].flag + a->s[1].flag + b->s[1].flag == 0) {
            continue;
        }
        ax = a->s[0].x;
        ay = a->s[0].y;
        n = (b->s[0].x - ax) * (b->s[1].y - ay);
        m = b->s[0].y - ay;
        if (n - (b->s[1].x - ax) * m > 0) {
            continue;
        }
        k = (tile->field_2 >> rec->field_2) & 3;
        if (k == 0 && (tile->field_3 & 0x80)) {
            k = 4;
        }
        ot = &D_8005F770.otLayers.u[3][w->field_0[y + rec->field_8][x + rec->field_7].field_1C];
        src = &w->field_143C[base[k]];
        *(Stg40FT4 *)pkt = *src;
        ((Stg40FT4 *)pkt)->x0 = a->s[1].x;
        ((Stg40FT4 *)pkt)->y0 = a->s[1].y;
        ((Stg40FT4 *)pkt)->x1 = b->s[1].x;
        ((Stg40FT4 *)pkt)->y1 = b->s[1].y;
        ((Stg40FT4 *)pkt)->x2 = a->s[0].x;
        ((Stg40FT4 *)pkt)->y2 = a->s[0].y;
        ((Stg40FT4 *)pkt)->x3 = b->s[0].x;
        ((Stg40FT4 *)pkt)->y3 = b->s[0].y;
        ((Stg40FT4 *)pkt)->r0 = rec->field_9;
        ((Stg40FT4 *)pkt)->g0 = rec->field_9;
        ((Stg40FT4 *)pkt)->b0 = rec->field_9;
        ((Stg40OTag *)pkt)->addr = ((Stg40OTag *)ot)->addr;
        ((Stg40OTag *)ot)->addr = pkt;
        pkt += sizeof(Stg40FT4);
    }
    return pkt;
}

s32 func_80065F94(Stg40W667C *w, s32 pkt, s32 x, s32 y) {
    Stg40Vtx *a = &w->field_0[y][x];
    Stg40Vtx *b = &w->field_0[y + 1][x];
    Stg40Tile *t = &w->field_F20[y][x];
    s32 k = t->field_0 == 0;
    u32 *ot;

    if (a[0].s[k].flag + a[1].s[k].flag + b[0].s[k].flag + b[1].s[k].flag == 0) {
        return pkt;
    }
    if (t->field_0 != 0) {
        ot = D_8005F8C0;
        *(Stg40FT4 *)pkt = w->field_143C[D_80072620[t->field_3 & 0x7F]];
        ((Stg40FT4 *)pkt)->x0 = a[0].s[0].x;
        ((Stg40FT4 *)pkt)->y0 = a[0].s[0].y;
        ((Stg40FT4 *)pkt)->x1 = a[1].s[0].x;
        ((Stg40FT4 *)pkt)->y1 = a[1].s[0].y;
        ((Stg40FT4 *)pkt)->x2 = b[0].s[0].x;
        ((Stg40FT4 *)pkt)->y2 = b[0].s[0].y;
        ((Stg40FT4 *)pkt)->x3 = b[1].s[0].x;
        ((Stg40FT4 *)pkt)->y3 = b[1].s[0].y;
        ((Stg40FT4 *)pkt)->tag.word = (((Stg40FT4 *)pkt)->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += sizeof(Stg40FT4);
    } else {
        ot = &D_8005F8B4[w->field_F20[y][x].field_8];
        ((Stg40F4 *)pkt)->tag.b.len = 5;
        ((Stg40F4 *)pkt)->code = 0x28;
        ((Stg40F4 *)pkt)->r0 = 0;
        ((Stg40F4 *)pkt)->g0 = 0;
        ((Stg40F4 *)pkt)->b0 = 0;
        ((Stg40F4 *)pkt)->x0 = a[0].s[1].x;
        ((Stg40F4 *)pkt)->y0 = a[0].s[1].y;
        ((Stg40F4 *)pkt)->x1 = a[1].s[1].x;
        ((Stg40F4 *)pkt)->y1 = a[1].s[1].y;
        ((Stg40F4 *)pkt)->x2 = b[0].s[1].x;
        ((Stg40F4 *)pkt)->y2 = b[0].s[1].y;
        ((Stg40F4 *)pkt)->x3 = b[1].s[1].x;
        ((Stg40F4 *)pkt)->y3 = b[1].s[1].y;
        ((Stg40F4 *)pkt)->tag.word = (((Stg40F4 *)pkt)->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += sizeof(Stg40F4);
    }
    return pkt;
}

void func_8006620C(Stg40W667C *w) {
    s32 rows;
    s32 cols;
    s32 y;
    s32 x;
    s32 pkt;

    rows = (D_80072B60->field_30 & 0x3F) ? 10 : 9;
    cols = (D_80072B60->field_2C & 0x3F) ? 10 : 9;
    pkt = D_8005F79C;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            pkt = func_80065F94(w, pkt, x, y);
            if (w->field_F20[y][x].field_0 & 0xF00) {
                pkt = func_80065C50(w, pkt, x, y);
            }
        }
    }
    D_8005F79C = pkt;
}

void func_80066318(Actor *a0, s32 *ids) {
    Stg40W667C *w = (Stg40W667C *)a0->work;
    GfxTexSlot *slot;
    Stg40TexRec *e;
    Stg40FT4 *p;
    Stg40FT4 *q;
    s32 i;

    D_80072B68 = a0;
    D_80072B6C = w;
    w->field_1414 = 0;
    w->field_1438 = 0;
    for (i = 0; i < 2; i++) {
        slot = Gfx_FindOrLoadTexSlot(*ids);
        e = (Stg40TexRec *)Cd_GetFileEntry(*ids + 1);
        w->field_13D4[w->field_1414] = slot;
        w->field_13F4[w->field_1414] = e;
        w->field_1418[w->field_1414] = *ids;
        for (; e->u != 0xFF; e++) {
            p = &w->field_143C[w->field_1438];
            p->tag.b.len = 9;
            p->code = 0x2C;
            p->r0 = 0x7F;
            p->g0 = 0x7F;
            p->b0 = 0x7F;
            if (w->field_1438 != 26) {
                p->code &= ~2;
                p->tpage = ((slot->vramY & 0x100) >> 4) | ((slot->vramX & 0x3FF) >> 6) | ((slot->vramY & 0x200) << 2);
            } else {
                p->code |= 2;
                p->tpage = 0x40 | ((slot->vramY & 0x100) >> 4) | ((slot->vramX & 0x3FF) >> 6) | ((slot->vramY & 0x200) << 2);
            }
            p->clut = ((slot->vramY + e->cy) << 6) | (((slot->vramX + (e->cx >> 2)) >> 4) & 0x3F);
            p->u0 = slot->uOffset + e->u;
            p->v0 = e->v;
            p->u1 = slot->uOffset + e->u + (e->w * 4 - 1);
            p->v1 = e->v;
            p->u2 = slot->uOffset + e->u;
            p->v2 = e->v + (e->h - 1);
            p->u3 = slot->uOffset + e->u + (e->w * 4 - 1);
            p->v3 = e->v + (e->h - 1);
            w->field_1438++;
        }
        ids++;
        w->field_1414++;
    }
    w->field_1418[w->field_1414] = -1;
    q = &w->field_143C[26];
    q->code |= 2;
}

void func_800665E0(Actor *a0) {
    ActorWork *w = a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072B60->field_2C = D_8005071C->field_1064->field_C;
        D_80072B60->field_30 = D_8005071C->field_1064->field_10;
        Task_NextState0(a0);
        break;
    case 1:
        func_80065300(a0);
        func_8006545C(w);
        func_80065890(w);
        break;
    case 2:
        break;
    }
}

void func_8006667C(Actor *a0) {
    Stg40W667C *w = (Stg40W667C *)a0->work;
    s32 f = 1;
    s32 n = func_80022518(0x11);
    s32 *p;

    if (n <= 0 || (D_8005071C->field_1058 == 0x10 && n == 0x75)) {
        f = 0;
    }
    if (f) {
        func_8006620C(w);
    }
    for (p = w->field_1418; *p != -1; p++) {
        Gfx_FindOrLoadTexSlot(*p);
    }
}

#ifdef NORMALIZED
void func_80066720(Actor *a0) {
    Stg40W6720 *w = (Stg40W6720 *)a0->work;
    Stg40Slot34 *s3 = (Stg40Slot34 *)a0->u34.children;
    TextOpenArgs args;
    Stg40E34 *fe;
    s32 n;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->field_0, 3);
        w->field_C = 0;
        s3->field_0 = 0;
        n = D_8005071C->field_E54->field_D - 6;
        w->field_10 = ~(1 << ((n < 7) ? n : 6));
        w->field_12 = D_80050720->hp;
        w->field_14 = D_80050720->mp;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_C) == 0) {
                fe = D_8005071C->field_E54;
                args.x = 0x12;
                args.y = 0x16;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                args.text = (s32)fe->field_E;
                Text_Open(&w->field_8, &args);
                Text_SetOtLayer(w->field_8, 2);
                Text_OpenById(&w->field_0, D_800726B0[0].id, 0, D_800726B0[0].pos);
                Text_OpenById(&w->field_4, D_800726B0[1].id, 0, D_800726B0[1].pos);
                Text_SetOtLayer(w->field_0, 2);
                Text_SetOtLayer(w->field_4, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->field_12 > D_80050720->hp) {
                w->field_12 = (w->field_12 - 0x21 < D_80050720->hp) ? D_80050720->hp : (u16)w->field_12 - 0x21;
            }
            if (w->field_12 < D_80050720->hp) {
                w->field_12 = (D_80050720->hp < w->field_12 + 0x21) ? D_80050720->hp : (u16)w->field_12 + 0x21;
            }
            if (D_80050720->hp == 0) {
                w->field_12 = 0;
            }
            if (w->field_14 > D_80050720->mp) {
                w->field_14 = (w->field_14 - 1 < D_80050720->mp) ? D_80050720->mp : (u16)w->field_14 - 1;
            }
            if (w->field_14 < D_80050720->mp) {
                w->field_14 = (D_80050720->mp < w->field_14 + 1) ? D_80050720->mp : (u16)w->field_14 + 1;
            }
            if (D_80050720->mp == 0) {
                w->field_14 = 0;
            }
            break;
        }
        if (s3->field_0 != 0) {
            if (D_8005071C->field_BA5 == 0 && s3->field_0->stateLevel0 != 2) {
                Task_SetState0(s3->field_0, 2);
            }
        } else {
            if (D_8005071C->field_BA5 != 0) {
                Task_Create(0x20A, (s32 *)s3, 0);
            }
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->field_0, 3);
            if (s3->field_0 != 0) {
                Task_SetState0(s3->field_0, 2);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_C) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066720);
void func_80066720(Actor *a0);
#endif

void func_80066AD0(Actor *a0) {
    Stg40W6AD0 *w = (Stg40W6AD0 *)a0->work;
    EntA0 *p;
    s32 i;

    if (w->field_C != 0) {
        for (i = 0; i < 2; i++) {
            p = Cd_GetFileEntry(D_800726C0[i]);
            switch (i) {
            case 0:
            default:
                Gfx_SetPartsNumber((GfxPart *)p, 2, 4, D_8005E620.maxHp);
                Gfx_SetPartsNumber((GfxPart *)p, 4, 4, w->field_12);
                Gfx_SetPartsNumber((GfxPart *)p, 8, 4, D_8005E620.maxMp);
                Gfx_SetPartsNumber((GfxPart *)p, 0x10, 4, w->field_14);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, w->field_10);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_C);
            Gfx_DrawParts((s32)p);
        }
    }
}

void func_80066BE4(Actor *a0) {
    Stg40W6BE4 *w = (Stg40W6BE4 *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->field_0, 1);
        w->field_4 = 0;
        w->field_8 = D_80050720->field_8;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_4) == 0) {
                Text_OpenById(w, D_800726E0.id, 0, D_800726E0.pos);
                Text_SetOtLayer(w->field_0, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (D_80050720->field_8 < w->field_8) {
                w->field_8 = (w->field_8 - 10 < D_80050720->field_8) ? D_80050720->field_8 : w->field_8 - 10;
            }
            if (w->field_8 < D_80050720->field_8) {
                w->field_8 = (w->field_8 + 10 > D_80050720->field_8) ? D_80050720->field_8 : w->field_8 + 10;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->field_0, 1);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_4) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80066D78(Actor *a0) {
    ActorWork *w = a0->work;
    EntA0 *p;

    if (w->field_4 != 0) {
        p = Cd_GetFileEntry(0x7D40002);
        Gfx_SetPartsNumber((GfxPart *)p, 2, 8, w->field_8);
        Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_4);
        Gfx_DrawParts((s32)p);
    }
}

void func_80066DF0(a0, a1, a2)
    u8 a0;
    u8 a1;
    u8 a2;
{
    Stg40ObjWork *w = (Stg40ObjWork *)D_80072B70->work;

    w->field_46 = a0;
    w->field_44 = a1;
    w->field_45 = a2;
    w->field_24 = -1;
}

s32 *func_80066E18(void) {
    return ((Stg40ObjWork *)D_80072B70->work)->field_28;
}

void func_80066E30(Actor *a0, s32 *a1) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;

    D_80072B70 = a0;
    w->field_20 = *a1;
}

void func_80066E48(Actor *a0) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;
    TextOpenArgs args;
    s32 n;
    s32 i;

    n = 6;
    if (w->field_20 != 0) {
        n = 7;
    }
    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(w->field_0, n);
        w->field_1C = 0;
        D_80072B70 = a0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_1C) == 0) {
                args.x = 0x1B;
                args.y = 0x33;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                for (i = 0; i < w->field_44; i++) {
                    args.text = w->field_28[i];
                    Text_Open(&w->field_0[i], &args);
                    Text_SetOtLayer(w->field_0[i], 2);
                    args.y += 0xC;
                }
                if (w->field_20 != 0) {
                    args.bigFont = 1;
                    args.text = w->field_40;
                    args.x = 0x10;
                    args.y = 0x8A;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(&w->field_18, &args);
                    Text_SetOtLayer(w->field_18, 2);
                }
                w->field_24 = 0;
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->field_24 != 0) {
                Task_SetState1(a0, 0);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->field_0, n);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_1C) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80067044(Actor *a0) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 n;
    s32 i;
    s32 mask;

    if (w->field_1C != 0) {
        n = 1;
        if (w->field_20 != 0) {
            n = 2;
        }
        for (i = 0; i < n; i++) {
            p = (GfxPart *)Cd_GetFileEntry(D_80072700[i]);
            switch (i) {
            case 0:
            default:
                mask = ((w->field_45 & 1) == 0) << 2;
                if (!(w->field_45 & 2)) {
                    mask |= 8;
                }
                for (q = p; q->fileId != 0; q++) {
                    if (q->groupMask & 2) {
                        q->x = -0x90;
                        q->y = w->field_46 * 12 - 0x46;
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                    if (q->groupMask & 0xC) {
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)p, mask);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_1C);
            Gfx_DrawParts((s32)p);
        }
    }
}

void func_800671E8(void) {
}

void func_800671F0(Actor *a0) {
    Stg40W71F0 *w = (Stg40W71F0 *)a0->work;
    Stg40SlotInfo *info;
    TextOpenArgs args;
    u16 *pos;
    s32 i;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072B78 = a0;
        Mem_FillWordsNeg1(w->field_8, 12);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_0) == 0) {
                pos = D_80072720;
                info = (Stg40SlotInfo *)D_80072B60->field_80[D_80072B60->field_AC]->field_10;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 1;
                Text_CloseArray(w->field_8, 12);
                for (i = 0; i < info->field_B * 4; i++) {
                    args.x = *pos++;
                    args.y = *pos++;
                    k = info->field_10[i / 4];
                    switch (i % 4) {
                    case 0:
                    default:
                        args.text = (s32)Cd_GetFileEntry(0x1FD0081);
                        break;
                    case 1:
                        args.text = (s32)Digi_GetDefaultName(k);
                        break;
                    case 2:
                        args.text = (s32)Cd_GetFileEntry(func_8001D934(k) + 0x1FD00C3);
                        break;
                    case 3:
                        args.text = (s32)Cd_GetFileEntry(func_8001D958(k) + 0x1FD00C6);
                        break;
                    }
                    Text_Open(&w->field_8[i], &args);
                    Text_SetOtLayer(w->field_8[i], 2);
                }
                Task_NextState1(a0);
            }
            break;
        case 1:
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->field_8, 12);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_0) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        case 100:
            Task_SetState0(a0, 1);
            break;
        }
        break;
    }
}

void func_80067454(Actor *a0) {
    ActorWork *w = a0->work;
    Stg40SlotInfo *info;
    EntA0 *p;
    s32 i;

    if (w->field_0 != 0) {
        info = (Stg40SlotInfo *)D_80072B60->field_80[D_80072B60->field_AC]->field_10;
        for (i = 0; i < 3; i++) {
            p = Cd_GetFileEntry(D_80072750[i]);
            if (i >= info->field_B) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, -1);
            } else {
                Gfx_SetPartsNumber((GfxPart *)p, 2, 2, info->field_16[i]);
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_0);
            }
            Gfx_DrawParts((s32)p);
        }
    }
}

#ifdef NORMALIZED
u8 *func_8006755C(s32 i, s32 v) {
    s32 d = 10000;
    s32 nz = 0;
    u8 *p = D_80072B90[i];
    s32 k;
    s32 q;

    v = (v > 99999) ? 99999 : v;
    for (k = 3; k >= 0; k--) {
        q = v / d;
        *p = q;
        if (*p != 0) {
            nz = -1;
        }
        v -= q * d;
        p -= nz;
        d /= 10;
    }
    p[1] = 0xFF;
    p[0] = v;
    return D_80072B90[i];
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006755C);
u8 *func_8006755C(s32 i, s32 v);
#endif

void func_80067610(s32 i, s32 file, s32 a2, s32 a3) {
    TextOpenArgs arg;
    s32 *p;

    arg.bigFont = 1;
    arg.color = 0;
    arg.x = 0;
    arg.y = 0;
    arg.charAdvance = 0;
    arg.lineAdvance = 0xF;
    arg.text = (s32)Cd_GetFileEntry(file);
    arg.charDelay = 1;
    p = &D_80072B84[i];
    p[5] = 0;
    arg.strArg0 = a2;
    arg.strArg1 = a3;
    Text_Open(p, &arg);
}

void func_800676A4(s32 i) {
    Text_Close(&D_80072B84[i]);
}

s32 func_800676D0(s32 i) {
    s32 *p = &D_80072B84[i];

    return Text_IsFinished(*p);
}

s32 func_80067704(s32 i) {
    s32 r = 0;

    if (func_800676D0(i) == 1) {
        func_800676A4(i);
        r = 1;
    }
    return r;
}

s32 func_80067750(s32 i) {
    s32 *p = &D_80072B84[i];

    return func_800136A4(*p);
}

void func_80067784(void) {
}

void func_8006778C(Actor *a0) {
    s32 *w = (s32 *)a0->work;
    s32 i;
    s32 m;

    switch (a0->stateLevel0) {
    case 1:
    case 2:
        break;
    case 0:
    default:
        m = -1;
        D_80072B80 = a0;
        D_80072B84 = w;
        for (i = 4; i >= 0; i--) {
            w[i] = m;
        }
        Task_NextState0(a0);
        break;
    }
}

void func_800677F4(void) {
}

void func_800677FC(Blk16 *l, s32 r, s32 g, s32 b) {
    s32 i;
    Blk16 *p;

    for (i = 0, p = l; i < 3; i++, p++) {
        GsSetFlatLight(i, p);
    }
    GsSetAmbient(r, g, b);
    GsSetLightMode(0);
}

void func_80067880(Actor *a0, u8 a1) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    w->field_26 = a1;
    w->field_27 = 0;
}

void func_80067894(Actor *a0, u8 on, u8 r, u8 g, u8 b) {
    Stg40ModelView *m = (Stg40ModelView *)a0->model;

    if (on == 0) {
        m->field_34 = 0;
        return;
    }
    m->field_34 = 2;
    m->field_38 = r;
    m->field_39 = g;
    m->field_3A = b;
}

s32 func_800678C4(Actor *a0) {
    return a0->model->animDone < 0;
}

s32 func_800678D8(Stg40Ent48 *e) {
    s32 d;
    Stg40Loc *loc = &e->field_18;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 c;

    if ((s16)e->field_E != e->field_C) {
        c = e->field_C;
        if (((s16)(e->field_E - ((u16)e->field_C - 0x1000)) / 0x800) & 1) {
            e->field_C = c - 0x100;
        } else {
            e->field_C = c + 0x100;
        }
        e->field_C &= 0xFFF;
        d = (s16)e->field_E - e->field_C;
        if ((d >= 0) ? (d < 0x100) : ((e->field_C - (s16)e->field_E) < 0x100)) {
            e->field_C = e->field_E;
        }
    }
    e->field_B = (s16)e->field_E / 512;
    if ((s16)e->field_E == e->field_C && loc->field_8 != 0 && --loc->field_8 == 0 && loc->field_1C == 1) {
        loc->field_1C = 0;
    }
    x = loc->u0.pair.field_0 << 6;
    dx = ((x - (loc->field_4.field_0 << 6)) * loc->field_8) / loc->field_A;
    y = loc->u0.pair.field_2 << 6;
    dy = ((y - (loc->field_4.field_2 << 6)) * loc->field_8) / loc->field_A;
    loc->field_C = x - dx;
    loc->field_10 = y - dy;
    e->field_A = func_80070438(loc->u0.pair.field_0, loc->u0.pair.field_2)->field_2;
    return loc->field_8 != 0;
}

void func_80067A80(Actor *a0, Stg40Ent48 *e)
{
  Stg40ActWork *w = (Stg40ActWork *) a0->work;
  Stg40Ent48 *new_var;
  Stg40Loc *loc;
  w->field_2C = e;
  e->field_14 = a0;
  if (e->field_4 != (-1))
  {
    a0->digiId = e->field_4;
    w->field_14 = Digi_GetModelFile(a0->digiId);
    w->field_18 = Anim_GetModelAnimFile(a0->digiId, 4);
    w->field_C = 0;
    w->field_8 = 0;
    w->field_4 = 0;
    w->field_10 = (s16) e->field_E;
    w->field_20 = 0;
    w->field_22 = (w->field_23 = (w->field_24 = 0x80));
    w->field_26 = 0;
    w->field_27 = 0;
    w->field_28 = 0;
  }
  loc = &e->field_18;
  e->field_18.u0.pair.field_0 = (loc->field_4.field_0 = e->field_18.u0.pair.field_0);
  loc->u0.pair.field_2 = (loc->field_4.field_2 = e->field_18.u0.pair.field_2);
  loc->field_8 = 0;
  loc->field_A = 1;
  loc->field_1C = 0;
  loc->field_C = loc->u0.pair.field_0 << 6;
  loc->field_10 = loc->u0.pair.field_2 << 6;
  if (e->field_0 & 1)
  {
    D_8005071C->field_1064 = loc;
    D_8005071C->field_1068 = loc;
    new_var = w->field_2C;
    D_80072B60->field_8 = a0;
    D_80072B60->field_4 = new_var;
    func_80070B2C(e->field_7);
  }
  w->field_34 = 0;
}

void func_80067BA8(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Arg207 arg;
    s32 *slot;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Task_NextState0(a0);
        if (w->field_2C->field_0 & 0x100) {
            if (w->field_2C->field_0 & 1) {
                Task_SetState1(a0, 5);
            }
            if (w->field_2C->field_0 & 2) {
                if (w->field_2C->field_0 & 0x800) {
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 3);
                }
            }
            if (w->field_2C->field_0 & 0x200) {
                Task_SetState1(a0, 0);
                w->field_2C->field_0 &= ~0x200;
            }
            w->field_2C->field_0 &= ~0x900;
        }
        Actor_InitTransform(a0, &w->field_4, w->field_10);
        w->field_30 = 0x28;
        w->field_32 = -1;
        w->field_36 = -1;
        w->field_38 = -1;
        break;
    case 1:
        func_800678D8(w->field_2C);
        if (w->field_2C->field_0 & 1) {
            func_8006B420(a0);
        }
        if (w->field_2C->field_0 & 2) {
            func_8006BFB0(a0);
        }
        if (w->field_2C->field_0 & 4) {
            func_8006D418(a0);
        }
        if (w->field_36 != -1) {
            slot = (s32 *)a0->u34.children;
            if (*slot != 0) {
                Task_SetState0((Actor *)*slot, 3);
            } else {
                arg.field_0 = a0;
                arg.field_4 = w->field_36;
                Task_Create(0x207, slot, (s32)&arg);
                w->field_38 = w->field_36;
                w->field_36 = -1;
            }
        }
        break;
    case 2:
        break;
    }
}

void func_80067DB4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40Xform *x;
    s32 dx;
    s32 dy;
    s32 vis;
    s32 r;
    u8 k;

    w->field_34 = 0;
    if (e->field_4 == -1) {
        return;
    }
    dx = e->field_18.field_C - D_80072B60->field_2C;
    if (dx < 0) {
        dx = D_80072B60->field_2C - e->field_18.field_C;
    }
    dy = e->field_18.field_10 - D_80072B60->field_30;
    if (dy < 0) {
        dy = D_80072B60->field_30 - e->field_18.field_10;
    }
    if (dx < 0x1C0 && dy < 0x1C0) {
        Cd_QueueFile(w->field_14);
        Cd_QueueFile(w->field_18);
    }
    if (dx < 0x140 && dy < 0x140) {
        vis = 1;
        r = func_80022518(0x11);
        if (r <= 0 || (D_8005071C->field_1058 == 0x10 && r == 0x75)) {
            vis = 0;
        }
        if (e->field_0 & 1) {
            vis = 1;
        }
        Gfx_AttachModel(a0, w->field_14)->otIndex = 3;
        if (w->field_30 != -1) {
            Anim_SetModelAnim(a0, w->field_30);
            w->field_32 = w->field_30;
            w->field_30 = -1;
        }
        x = (Stg40Xform *)a0->u38.ptr38;
        x->field_30 = (s16)((e->field_18.field_C - D_80072B60->field_2C) * 40);
        x->field_38 = (s16)-(((e->field_18.field_10 - D_80072B60->field_30) << 11) / 64);
        x->field_34 = -(s16)e->field_18.field_14;
        x->field_42 = e->field_C;
        x->field_58 = e->field_38;
        x->field_5C = e->field_3C;
        x->field_60 = e->field_40;
        if ((e->field_0 & 0x4000) && vis) {
            if (!(e->field_0 & 0x80)) {
                func_80064BD8(&e->field_18);
            }
            if (!(e->field_0 & 0x400)) {
                Anim_StepModelAnim(a0);
                Actor_UpdateTransform(a0);
                Gfx_CalcModelBoneMatrices(a0);
                Gfx_DrawTexModel(a0, 0);
            }
        }
        w->field_34 = 1;
    }
    if (w->field_26 != 0) {
        k = D_8007278C[w->field_27];
        if (k == 0xFF) {
            w->field_26 = 0;
            func_80067894(a0, 0, 0, 0, 0);
        } else {
            func_80067894(a0, k, D_8007279C[w->field_26 - 1].r, D_8007279C[w->field_26 - 1].g,
                          D_8007279C[w->field_26 - 1].b);
            w->field_27++;
        }
    }
}

void func_800680B0(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    func_8006E4DC(a0, a1);
    Task_SetState1(a0, 9);
    D_80072B60->field_34 = a2;
    D_80072B60->field_38 = a3;
    D_80072B60->field_44 = a4;
    D_80072B60->field_48 = a5;
    D_80072B60->field_4C = a6;
}

void func_8006813C(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_8006E4DC(a0, a1);
    Task_SetState1(a0, 0xB);
    D_80072B60->field_38 = a2;
    func_80067610(1, a3, a4, a5);
}

s32 func_800681BC(Actor *a0) {
    Stg40Ent48 *self = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40Ent48 *e;
    s32 i;

    if (D_8005F708 > 0 && self->field_A != 0xFF) {
        e = D_8005071C->field_18;
        D_80072B60->field_A8 = 0;
        D_80072B60->field_AC = 0;
        for (i = 0; i < D_8005071C->field_C; e++, i++) {
            if ((e->field_0 & 0x8000) && e->field_8 == 1 && e->field_A == self->field_A) {
                D_80072B60->field_80[D_80072B60->field_A8++] = e;
            }
        }
        if (D_80072B60->field_A8 != 0) {
            Task_SetState1(a0, 0x1A);
            D_80072B60->field_7E = 0;
            return -1;
        }
    }
    return 0;
}

s32 func_800682DC(Actor *a0)
{
    Stg40Ent48 *e;
    Stg40Ent48 *found;
    s32 snd;
    s32 r;
    s32 idx;
    s32 lim;
    s32 snd2;
    Actor *child;
    s32 r2;
    s32 r3;

    e = ((Stg40ActWork *)a0->work)->field_2C;
    if (D_8005F704 <= 0) {
        return 0;
    }
    found = func_8006E200(e->field_18.u0.pair.field_0 + ((s16 *)D_800727C0)[(e->field_B + 1) << 1],
                          e->field_18.u0.pair.field_2 + ((s16 *)D_800727C0)[((e->field_B + 1) << 1) | 1]);
    if (found == 0) {
        snd2 = 0x1FD000F;
        r2 = func_800703E0(e->field_18.u0.pair.field_0 + ((s16 *)D_800727C0)[(e->field_B + 1) << 1],
                          e->field_18.u0.pair.field_2 + ((s16 *)D_800727C0)[((e->field_B + 1) << 1) | 1]) & 0xF;
        if (r2 >= 3) {
            snd2 = r2 + 0x1FD0194;
        }
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, snd2, 0, 0);
        goto end;
    }
    child = found->field_14;
    D_80072B60->field_3C = child;
    D_80072B60->field_40 = found;
    switch (found->field_8) {
    default:
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, 0x1FD000F, 0, 0);
        return -1;
    case 2:
    case 3:
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, (found->field_8 == 2) ? 0x1FD0195 : 0x1FD0196, 0, 0);
        return -1;
    case 4:
        Task_SetState1(a0, 0x13);
        return -1;
    case 8:
        snd = -1;
        if (!(found->field_0 & 0x1000)) {
            break;
        }
        r = func_8006E820(6);
        if (r == -1) {
            snd = 0x1FD0019;
        } else if (r == 0) {
            snd = 0x1FD001A;
        } else {
            lim = found->field_10[1];
            if (func_8006E858(6) < lim) {
                snd = 0x1FD0018;
            }
        }
        if (snd != -1) {
            func_8006813C(a0, 0x28, 1, snd, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0xE);
        return -1;
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
        idx = found->field_8 - 6;
        if (!(found->field_0 & 0x1000)) {
            break;
        }
        Item_CheckId(0);
        r3 = func_8006E920(&D_800727E8[idx]);
        if (r3 != 0) {
            func_8006813C(a0, 0x28, 1, r3, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0x11);
        D_80072B60->field_7E = 0;
        D_80072B60->field_E4 = 0;
        D_80072B60->field_E0 = D_80072B60->field_B0[0];
        goto end;
    }
    Task_SetState1(a0, 0xC);
end:
    return -1;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068604);

Stg40Ent48 *func_800689E0(Stg40Ent48 *a0) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Ent48 *e = b->field_18;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < b->field_C; i++, e++) {
        if ((e->field_0 & 0x8000) && e != a0 && e->field_18.u0.field_0 == a0->field_18.u0.field_0) {
            r = e;
            break;
        }
    }
    return r;
}

s32 func_80068A54(Actor *task) {
    Stg40ActWork *w = (Stg40ActWork *)task->work;
    Stg40Ent48 *ent = w->field_2C;
    Stg40Ent48 *other;
    GameStateView *gs;
    u16 dir;
    s32 n;
    s32 hp;
    s32 state;
    s32 ret;
    Actor *child;

    ret = 0;
    if ((u32)((dir = func_800703E0(ent->field_18.u0.pair.field_0, ent->field_18.u0.pair.field_2) & 0xF) - 8) < 5) {
        n = dir - 7;
        if (func_8006E858(5) < n) {
            n *= 50;
            gs = D_80050720;
            hp = gs->hp - n;
            if (hp < 0) {
                hp = ret;
            }
            gs->hp = hp;
            Task_SetState1(task, 0xD);
            return 1;
        }
    }
    other = func_800689E0(ent);
    if (other != NULL) {
        child = other->field_14;
        D_80072B60->field_3C = child;
        D_80072B60->field_40 = other;
        switch (other->field_8) {
        default:
            break;
        case 8:
            Task_SetState1(task, 0x16);
            ret = 1;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            Task_SetState1(task, 0x10);
            ret = 1;
            break;
        }
    }
    return ret;
}

s32 func_80068B8C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    s32 r = 0;
    Stg40Ent48 *f;
    Stg40B60 *b;
    Actor *t;

    if (func_8006E6CC()) {
        Task_SetState1(a0, 0x1E);
        return 1;
    }
    f = func_800689E0(e);
    if (f == NULL) {
        return 0;
    }
    t = f->field_14;
    b = D_80072B60;
    b->field_3C = t;
    b->field_40 = f;
    switch (f->field_8) {
    case 2:
    case 3:
        D_8005071C->field_1 = (f->field_8 != 2) ? 3 : 2;
        Task_SetState1(a0, 0x17);
        r = 1;
        break;
    }
    return r;
}

s32 func_80068C60(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40Loc *l = &e->field_18;
    s32 r = 0;
    s16 t;

    if (l->field_8 == l->field_A / 2 && (l->field_1E & 1)) {
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        t = e->field_18.u0.pair.field_0;
        e->field_18.u0.pair.field_0 = e->field_18.field_4.field_0;
        e->field_18.field_4.field_0 = t;
        t = e->field_18.u0.pair.field_2;
        e->field_18.u0.pair.field_2 = e->field_18.field_4.field_2;
        e->field_18.field_4.field_2 = t;
        e->field_18.field_8 = 0xC;
        e->field_18.field_A = 0x18;
        func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
        Task_SetState1(a0, 0xF);
        r = -1;
    }
    return r;
}

void func_80068D3C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;

    func_8006E4E8(a0, 0x28);
    if (func_80070C94() == e->field_7) {
        func_80065134(&e->field_18);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        } else {
            Task_SetState1(a0, 1);
        }
    }
}

void func_80068DC0(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_8006E4E8(a0, 0x29);
    if (e->field_18.field_8 == 0xB) {
        Snd_PlayById(0x2C, 0);
    }
    if (func_80068C60(a0) != 0) {
        return;
    }
    if (w->field_2C->field_18.field_8 >= 2) {
        return;
    }
    D_80050720->mp = (D_80050720->mp - 1 < 0) ? 0 : (u16)D_80050720->mp - 1;
    if (func_80068A54(a0) != 0) {
        return;
    }
    if (func_800716EC(a0)) {
        Task_SetState1(a0, 8);
        return;
    }
    if (Flag_Test(0x68) && D_80050720->mp == 0) {
        D_80050720->mp = 1;
    }
    if (D_80050720->mp == 0 || D_80050720->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (func_80068B8C(a0) == 0) {
        Task_SetState1(a0, 3);
    }
}

void func_80068F20(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    if (func_80070C48() == e->field_7) {
        if (func_80068604(w->field_2C) == 1) {
            Task_SetState1(a0, 2);
        } else {
            Task_SetState1(a0, 0);
        }
    } else if (func_8006E330()) {
        Task_SetState1(a0, 4);
    } else {
        Task_SetState1(a0, 0);
    }
}

void func_80068FBC(Actor *a0) {
    if (func_800716EC(a0)) {
        Task_SetState1(a0, 8);
    } else {
        Task_SetState1(a0, 7);
    }
}

void func_80068FFC(Actor *a0) {
    if (Flag_Test(0x68) && D_80050720->mp == 0) {
        D_80050720->mp = 1;
    }
    if (D_80050720->mp == 0 || D_80050720->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (func_80068B8C(a0) == 0) {
        func_80070C48();
        Task_SetState1(a0, 0);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        }
    }
}

void func_800690CC(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    s32 arg = 0;
    s32 k;

    if (b->field_68 == 0) {
        Task_SetState1(a0, 7);
        return;
    }
    b->field_68--;
    k = b->field_60[b->field_68];
    if (k >= 2 && k < 6) {
        arg = (s32)D_80050720->field_D1;
    }
    if (k == 6) {
        arg = b->field_78;
    }
    if (k == 7) {
        arg = (s32)b->field_6A;
    }
    func_8006813C(a0, 0x28, 8, D_80072868[k], arg, 0);
}

void func_80069188(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    s32 v;
    s32 n;

    func_8006E4E8(a0, 0x28);
    if (D_8005071C->field_2 != 0) {
        return;
    }
    if (D_8005F700 > 0 && D_80072AA0->stateLevel0 == 1 && D_80072AA0->stateLevel1 == 1 && D_80072AA0->stateLevel2 == 1) {
        Task_SetState1(D_80072AA0, 4);
        D_8005071C->field_2 = 1;
        return;
    }
    if (func_80068604(w->field_2C) == 1) {
        if (D_8005071C->field_BA0 & 1) {
            func_8006813C(a0, 0x28, 6, 0x1FD001D, 0, 0);
        } else {
            Task_SetState1(a0, 2);
        }
        return;
    }
    if (func_800682DC(a0) == 0 && func_800681BC(a0) == 0 && func_80022518(0x12) > 0 && D_8005F720 > 0) {
        v = D_80050720->field_0 + 1;
        n = (v < 3) ? v : 0;
        D_80050720->field_0 = n;
        D_80072B60->field_7E = D_80050720->field_0;
    }
}

void func_8006932C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2D);
        Task_SetState2(a0, 1);
        break;
    case 1:
        if (func_800678C4(a0) == 1) {
            Task_SetState2(a0, 2);
        }
        break;
    case 2:
        if (D_8005071C->field_2 == 0) {
            if (func_80070C94() == e->field_7) {
                Task_SetState1(a0, 1);
            } else {
                Task_SetState1(a0, 0);
            }
        }
        break;
    }
}

void func_8006940C(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        if (func_8006E588(a0) == 1) {
            if (D_80072B60->field_34 != -1) {
                func_8006E4DC(a0, D_80072B60->field_34);
            }
            func_80067610(1, D_80072B60->field_44, D_80072B60->field_48, D_80072B60->field_4C);
            Task_NextState2(a0);
        }
        break;
    case 1:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, (u8)D_80072B60->field_38);
        }
        break;
    }
}

void func_800694D0(Actor *a0) {
    if (func_8006E588(a0) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->field_38);
    }
}

void func_80069514(Actor *a0) {
    if (func_80067704(1) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->field_38);
    }
}

void func_8006955C(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Stg40Ent48 *e = b->field_40;
    Actor *t = b->field_3C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        func_8006E4DC(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            Task_SetState1(t, 5);
            func_80067610(1, 0x1FD0010, (s32)Cd_GetFileEntry(e->field_8 + 0x1FD0064), 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006965C(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2F, 0);
        func_8006E4DC(a0, 0x2C);
        func_80067880(a0, 1);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_800678C4(a0) == 1 || a0->stateLevel4++ >= 11) {
            func_8006E4DC(a0, 0x28);
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_80069714(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 msg;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2A);
        Snd_PlayById(0x2E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            r = func_80022518(6);
            n = e->field_10[1];
            if (func_8001E0E4(r) >= n) {
                Task_SetState1(t, 6);
                msg = 0x1FD0017;
            } else {
                msg = 0x1FD0018;
            }
            func_80067610(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_80069830(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2C);
        func_80067880(a0, 2);
        Task_SetState1(t, 4);
        D_80072B60->field_58 = e->field_10[1] * 200;
        func_8006E8F4(D_80072B60->field_58);
        Snd_PlayById(0x33, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            func_80067610(1, 0x1FD001F, (s32)D_80050720->field_D1, (s32)func_8006755C(0, D_80072B60->field_58));
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

#ifdef NORMALIZED
void func_8006997C(Actor *arg0)
{
    Stg40Ent48 *e;
    Actor *t;
    s32 idx;
    s32 bit;
    s32 r;
    s32 n;

    e = D_80072B60->field_40;
    t = D_80072B60->field_3C;
    idx = e->field_8 - 9;
    bit = 0x100 << idx;
    switch (arg0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(arg0, 0x28);
        Task_SetState1(t, 4);
        Task_NextState2(arg0);
        break;
    case 1:
        if (t->stateLevel1 != 1) {
            return;
        }
        r = 0;
        switch (e->field_8) {
        default:
            if (((Stg40BA5View *)D_8005071C)->field_BA5[idx] == 0) {
                ((Stg40BA5View *)D_8005071C)->field_BA5[idx] = e->field_10[1];
                r = -1;
            }
            break;
        case 9:
            if (D_8005071C->field_BA5 == 0) {
                if (D_80050720->field_8 != 0 || func_80071608() != -1) {
                    r = -1;
                    ((Stg40StatusView *)D_8005071C)->field_B9C[e->field_8] = e->field_10[1];
                }
            }
            break;
        case 0xB:
            if (D_8005071C->field_BA7 != 0 || ((s32 (*)(s32))func_8006EA84)(1) < 2 || Digi_CountByState(1) >= 0x18) {
                r = 0;
            } else {
                r = -1;
                ((Stg40StatusView *)D_8005071C)->field_B9C[e->field_8] = e->field_10[1];
            }
            break;
        case 0xC:
            n = ((s32 (*)(void))func_80022578)();
            n -= ((s32 (*)(s32))func_8006EA84)(0);
            if (n != D_8005071C->field_BA8) {
                D_8005071C->field_BA9[D_8005071C->field_BA8] = e->field_10[1];
                r = -1;
                D_8005071C->field_BA8++;
            }
            break;
        }
        if (r == 0) {
            func_80067610(1, e->field_8 + 0x1FD0022, (s32)D_80050720 + 0xD1, 0);
            Task_SetState2(arg0, 3);
        } else {
            D_8005071C->field_BA0 &= ~bit;
            func_8006E4DC(arg0, 0x2A);
            func_80067880(arg0, 2);
            Task_NextState2(arg0);
            Snd_PlayById(0x2F, 0);
        }
        break;
    case 2:
        if (func_8006E588(arg0) == 1) {
            func_8006E4DC(arg0, 0x28);
            func_80067610(1, e->field_8 + 0x1FD001E, 0, 0);
            Task_NextState2(arg0);
        }
        break;
    case 3:
        if (func_80067704(1) == 1) {
            Task_SetState1(arg0, 6);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006997C);
void func_8006997C(Actor *arg0);
#endif

void func_80069C94(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40B60 *g = D_80072B60;
    Stg40Ent48 *t;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_Create(0x20C, &D_80072AA4->field_14, 0);
        func_8006E4DC(a0, 0x28);
        Task_NextState2(a0);
        break;
    case 1:
        t = g->field_80[g->field_AC];
        g->field_3C = t->field_14;
        g->field_40 = t;
        func_800651C0(&t->field_18, 0x10);
        Task_SetState0((Actor *)D_80072AA4->field_14, 2);
        Task_SetState1((Actor *)D_80072AA4->field_14, 0x64);
        Task_NextState2(a0);
        break;
    case 2:
        if (a0->stateLevel3 == 0) {
            if (func_80065230() != 0) {
                Snd_PlayById(0x12, 0);
                Task_SetState3(a0, 1);
            }
        }
        if (D_8005F6F0[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 0x64);
        } else if (D_8005F6F0[0].square > 0 && D_80072B60->field_A8 >= 2) {
            n = D_80072B60->field_AC + 1;
            D_80072B60->field_AC = (n < D_80072B60->field_A8) ? n : 0;
            Task_SetState2(a0, 1);
        } else if (D_8005F704 > 0) {
            r = func_8006E920(&D_80072858);
            if (r != 0) {
                func_80067610(1, r, 0, 0);
                Task_SetState2(a0, 0x3C);
            } else {
                Task_SetState1(a0, 0x11);
                D_80072B60->field_E4 = 1;
                D_80072B60->field_E0 = D_80072B60->field_B0[0];
            }
        }
        break;
    case 0x3C:
        if (func_80067704(1) == 1) {
            Task_SetState2(a0, 2);
            Task_SetState3(a0, 1);
        }
        break;
    case 0x64:
        func_80065134(&e->field_18);
        Task_SetState0((Actor *)D_80072AA4->field_14, 2);
        Task_NextState2(a0);
        break;
    case 0x65:
        if (D_80072AA4->field_14 == 0) {
            g->field_7E = D_80050720->field_0;
            Task_SetState1(a0, 1);
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069F84);

void func_8006A498(Actor *a0) {
    u8 *d = D_80072B60->field_40->field_10;
    s32 r;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        func_8006E4DC(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (d[1] == 0) {
            Task_SetState1(a0, 0x14);
        } else {
            D_80072B60->field_50 = func_80071204(d[1]);
            r = func_800715DC(7);
            msg = D_80072B60->field_50 + 0x1FD0040;
            if (r == -1) {
                msg = 0x1FD0045;
            }
            if (r == 0) {
                msg = 0x1FD0046;
            }
            func_80067610(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 3:
        switch (func_80067750(1)) {
        case -1:
            Task_SetState1(a0, 6);
            break;
        case 1:
            Task_SetState1(a0, 0x14);
            break;
        }
        break;
    }
}

void func_8006A614(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Actor *t = b->field_3C;
    u8 *d = b->field_40->field_10;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_SetState1(t, 4);
        Task_NextState2(a0);
        break;
    case 1:
        if (t->stateLevel1 == 3) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0 || d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (func_80071258(b->field_50) == 1) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 0x16);
        }
        break;
    }
}

void func_8006A6EC(Actor *a0) {
    Actor *t = D_80072B60->field_3C;
    u8 *d = D_80072B60->field_40->field_10;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (d[0] == 0) {
            func_80067610(1, 0x1FD004E, 0, 0);
            Task_SetState1(t, 5);
        } else if (Item_AddToBag(d[0]) == -1) {
            func_80067610(1, 0x1FD0055, Item_GetNameText(d[0]), 0);
            d[1] = 0xFF;
            Snd_PlayById(0x1C, 0);
        } else {
            func_80067610(1, 0x1FD004D, Item_GetNameText(d[0]), 0);
            Task_SetState1(t, 5);
            Snd_PlayById(0x19, 0);
            Item_SortList();
        }
        Task_NextState2(a0);
        break;
    case 1:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006A848(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 nc = e->field_8 != 4;
    u8 *d = e->field_10;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->field_54 = func_80071294();
        if (D_80072B60->field_54 != 0x10) {
            func_8006E4DC(a0, 0x2C);
            func_80067880(a0, 1);
            func_8007142C(D_80072B60->field_54, d[1]);
        }
        if (nc) {
            Task_SetState1(t, 4);
        }
        ((Stg40ActWork *)a0->work)->field_36 = d[1] + 1;
        Snd_PlayById(0x34, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            func_80071310(nc, D_80072B60->field_54);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_NextState2(a0);
        }
        break;
    case 3:
        Task_NextState2(a0);
        break;
    case 4:
        if (nc == 0) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006A9CC(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40ModelFade *m = (Stg40ModelFade *)a0->model;
    s32 v;
    switch (a0->stateLevel2) {
        case 0:
        default:
        {
            u8 k = D_8005071C->field_1;
            if (k == 2) {
                Snd_PlayById(0x23, 0);
                w->field_36 = 0;
            } else {
                if (k == 3)
                    Snd_PlayById(0x18, 0);
                else
                    Snd_PlayById(0x1F, 0);
                w->field_36 = 1;
            }
            m->field_34 = 1;
            m->field_36 = 0x20;
            m->field_38 = D_80063438;
            func_8006E4DC(a0, 0x28);
            e->field_0 |= 0x80;
            w->field_26 = 0;
            Task_NextState2(a0);
            break;
        }
        case 1:
            if (a0->stateLevel3++ >= 0x3C) {
                Gfx_FadeOutToBlack(8);
                Task_NextState2(a0);
            }
            break;
        case 2:
            break;
    }

    v = e->field_38 - 0x51;
    if (v < 0) {
        v = 0;
    }
    e->field_38 = v;
    e->field_40 = v;
    if (m->field_38.r != 0xFF) {
        m->field_38.r++;
        m->field_38.g++;
        m->field_38.b++;
    }
}

void func_8006AB48(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 k = e->field_8 - 6;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2A);
        Snd_PlayById(k < 3 ? 0x2D : 0x1E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            if (func_8001E0E4(D_80072B60->field_E0) >= e->field_10[1]) {
                Task_SetState1(t, 6);
                msg = D_8007289C[k * 2];
                Task_SetState2(a0, 3);
            } else {
                msg = D_8007289C[k * 2 + 1];
                Task_NextState2(a0);
            }
            func_80067610(1, msg, 0, 0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
            D_80072B60->field_7E = D_80050720->field_0;
        }
        break;
    case 3:
        if (func_80067704(1) == 1 && e->field_0 == 0) {
            Task_SetState1(a0, 6);
            D_80072B60->field_7E = D_80050720->field_0;
        }
        break;
    }
}

void func_8006AD10(void) {
    s32 s3;
    s32 s0;
    s32 s1;
    s32 e1;
    s32 e3;
    s32 v1;
    s32 *dst;
    s32 *p;

    s3 = 0;
    s0 = D_80072B60->field_E2 - D_80072B60->field_E3;
    dst = func_80066E18();
    p = dst;
    if (s0 >= 6) {
        D_80072B60->field_E3 = D_80072B60->field_E2 - 5;
    }
    if (s0 < 0) {
        D_80072B60->field_E3 = D_80072B60->field_E2;
    }
    e1 = D_80072B60->field_E1;
    e3 = D_80072B60->field_E3;
    s1 = e1;
    v1 = e3 + 6;
    if (s1 >= v1) {
        s1 = v1;
    }
    s0 = e3;
    while (s0 < s1) {
        *p = Item_GetNameText(D_80072B60->field_B0[s0]);
        s0++;
        p++;
    }
    s3 |= D_80072B60->field_E3 != 0;
    if (s1 < D_80072B60->field_E1) {
        s3 |= 2;
    }
    func_80066DF0(D_80072B60->field_E2 - D_80072B60->field_E3, s1 - D_80072B60->field_E3, s3);
    dst[6] = Item_GetDescText(D_80072B60->field_B0[D_80072B60->field_E2]);
    s1 = e1;
}

void func_8006AE74(void) {
    s32 old = D_80072B60->field_E2;
    s32 n;

    if (D_8005F72C & 0x1000) {
        if (old != 0) {
            D_80072B60->field_E2 = old - 1;
        }
    }
    if (D_8005F72C & 0x4000) {
        n = D_80072B60->field_E2 + 1;
        if (n < D_80072B60->field_E1) {
            D_80072B60->field_E2 = n;
        }
    }
    if (old != D_80072B60->field_E2) {
        Snd_PlayById(D_80072B60->field_E4 ? 0xD : 0xC, 0);
        func_8006AD10();
    }
}

void func_8006AF34(Actor *a0) {
    s32 arg;
    s32 i;
    u16 *bag;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->field_E2 = 0;
        D_80072B60->field_E3 = 0;
        func_8006E4DC(a0, 0x28);
        arg = D_80072B60->field_E4 != 0;
        Task_Create(0x20B, &D_80072AA4->field_10, (s32)&arg);
        Snd_PlayById(0x37, 0);
        func_8006AD10();
        Task_NextState2(a0);
        break;
    case 1:
        if (a0->stateLevel3++ >= 9) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        func_8006AE74();
        if (D_8005F6F0[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 4);
        } else if (D_8005F6F0[0].cross > 0) {
            D_80072B60->field_E0 = D_80072B60->field_B0[D_80072B60->field_E2];
            for (i = 0, bag = D_80050720->bagItems; i < 0x30; i++, bag++) {
                if (*bag == D_80072B60->field_E0) {
                    *bag = 0;
                    Item_CompactBag();
                    break;
                }
            }
            if (D_80072B60->field_E4 != 0) {
                func_800651C0(&((Stg40ActWork *)a0->work)->field_2C->field_18, 8);
                Snd_PlayById(0xE, 0);
            } else {
                Snd_PlayById(0xA, 0);
            }
            Task_NextState2(a0);
        }
        if (a0->stateLevel2 != 2) {
            Task_SetState0((Actor *)D_80072AA4->field_10, 2);
        }
        break;
    case 3:
        if (D_80072AA4->field_10 == 0) {
            if (D_80072B60->field_E4 == 0) {
                Task_SetState1(a0, 0x12);
            } else {
                Task_SetState1(a0, 0x1B);
            }
        }
        break;
    case 4:
        if (D_80072AA4->field_10 == 0) {
            if (D_80072B60->field_E4 == 0) {
                Task_SetState1(a0, 1);
                D_80072B60->field_7E = D_80050720->field_0;
            } else {
                Task_SetState1(a0, 0x1A);
                Task_SetState2(a0, 2);
                Task_SetState3(a0, 1);
            }
        }
        break;
    }
}

void func_8006B20C(Actor *a0) {
    s32 r;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x30, 1);
        func_8006E4DC(a0, 0x2B);
        break;
    case 1:
        if (func_8006E588(a0) != 1) {
            return;
        }
        func_80067610(1, 0x1FD0054, (s32)D_80050720->field_D1, 0);
        break;
    case 2:
        r = func_80067704(1);
        if (r != 1) {
            return;
        }
        D_8005071C->field_1 = 3;
        D_8005071C->field_7 = r;
        Snd_PlayById(0x1F, 0);
        break;
    case 3:
        if (a0->stateLevel3++ < 30) {
            return;
        }
        Gfx_FadeOutToBlack(0x10);
        break;
    case 4:
        return;
    }
    Task_NextState2(a0);
}

void func_8006B320(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x28);
        D_80072B60->field_178 = 0;
        D_80072B60->field_174 = -1;
        func_8001C038(&D_80072B60->field_174, Flag_SelectBranch(D_80072B60->field_170));
        Task_NextState2(a0);
        break;
    case 1:
        if (Text_IsFinished(D_80072B60->field_174)) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        func_80070C48();
        Task_SetState1(a0, 0);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        } else {
            D_8005071C->field_2 = 0;
        }
        break;
    }
}

void func_8006B420(Actor *a0) {
    Stg40Ent48 *e;

    func_800708FC(((Stg40ActWork *)a0->work)->field_2C->field_18.u0.pair.field_0, ((Stg40ActWork *)a0->work)->field_2C->field_18.u0.pair.field_2, 1);
    switch (a0->stateLevel1) {
    case 0:
    case 24:
    case 25:
    default:
        func_80068D3C(a0);
        break;
    case 1:
        func_80069188(a0);
        break;
    case 2:
        func_80068DC0(a0);
        break;
    case 3:
        func_80068F20(a0);
        break;
    case 6:
        func_80068FBC(a0);
        break;
    case 7:
        func_80068FFC(a0);
        break;
    case 8:
        func_800690CC(a0);
        break;
    case 4:
        if (a0->stateLevel2 != 1) {
            D_8005071C->field_1 = 1;
            D_8005071C->field_2 = 1;
            Task_NextState2(a0);
        }
        break;
    case 5:
        func_8006932C(a0);
        break;
    case 9:
        func_8006940C(a0);
        break;
    case 10:
        func_800694D0(a0);
        break;
    case 11:
        func_80069514(a0);
        break;
    case 12:
        func_8006955C(a0);
        break;
    case 13:
        func_8006965C(a0);
        break;
    case 14:
        func_80069714(a0);
        break;
    case 15:
        func_80069830(a0);
        break;
    case 16:
        func_8006997C(a0);
        break;
    case 19:
        func_8006A498(a0);
        break;
    case 20:
        func_8006A614(a0);
        break;
    case 21:
        func_8006A6EC(a0);
        break;
    case 22:
        func_8006A848(a0);
        break;
    case 23:
        func_8006A9CC(a0);
        break;
    case 18:
        func_8006AB48(a0);
        break;
    case 17:
        func_8006AF34(a0);
        break;
    case 26:
        func_80069C94(a0);
        break;
    case 27:
        func_80069F84(a0);
        break;
    case 28:
        func_8006B20C(a0);
        break;
    case 30:
        func_8006B320(a0);
        break;
    case 29:
        break;
    }
    e = ((Stg40ActWork *)a0->work)->field_2C;
    func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_18.field_4.field_0, e->field_18.field_4.field_2, e->field_8);
}

s32 func_8006B698(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;
    s32 n;
    s32 i;

    if (abs(dx) >= 3 || abs(dy) >= 3) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        c[0].field_0 = dx >= 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[0].field_2 = loc->u0.pair.field_2;
        if (dy == 0) {
            switch (e->field_B) {
            case 0:
            case 1:
            case 7:
                dy--;
                break;
            }
        }
        c[1].field_0 = loc->u0.pair.field_0;
        c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 + 1 : loc->u0.pair.field_2 - 1;
        c[2].field_0 = loc->u0.pair.field_0;
        c[2].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
    } else {
        c[0].field_2 = dy >= 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[0].field_0 = loc->u0.pair.field_0;
        if (dx == 0) {
            switch (e->field_B) {
            case 5:
            case 6:
            case 7:
                dx--;
                break;
            }
        }
        c[1].field_2 = loc->u0.pair.field_2;
        c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 + 1 : loc->u0.pair.field_0 - 1;
        c[2].field_2 = loc->u0.pair.field_2;
        c[2].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
    }
    for (i = 0, n = 0; i < 3; i++) {
        out[n].field_0 = c[i].field_0;
        out[n].field_2 = c[i].field_2;
        n++;
    }
    return n;
}

s32 func_8006B8C8(Stg40Ent48 *e, Pair54 *out) {
    Pair54 *p = &e->field_18.u0.pair;
    s16 dx = D_80072B60->field_17C.field_0 - p->field_0;
    s16 dy = D_80072B60->field_17C.field_2 - p->field_2;

    if (dx == 0 && dy == 0) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        out->field_0 = dx < 0 ? p->field_0 - 1 : p->field_0 + 1;
        out->field_2 = p->field_2;
    } else {
        out->field_0 = p->field_0;
        out->field_2 = dy < 0 ? p->field_2 - 1 : p->field_2 + 1;
    }
    return 1;
}

s32 func_8006B9A8(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;
    s32 n;
    s32 i;

    if (abs(dx) + abs(dy) < 2) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[0].field_2 = loc->u0.pair.field_2;
        c[1].field_0 = loc->u0.pair.field_0;
        c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[2].field_0 = loc->u0.pair.field_0;
        c[2].field_2 = dy >= 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
    } else {
        c[0].field_0 = loc->u0.pair.field_0;
        c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[1].field_2 = loc->u0.pair.field_2;
        c[2].field_0 = dx >= 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[2].field_2 = loc->u0.pair.field_2;
    }
    n = 0;
    for (i = 0; i < 3; i++) {
        if (c[i].field_0 != loc->field_4.field_0 || c[i].field_2 != loc->field_4.field_2) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    if (n != 3) {
        out[n].field_0 = loc->field_4.field_0;
        out[n].field_2 = loc->field_4.field_2;
        n++;
    }
    return n;
}

s32 func_8006BBBC(Stg40Ent48 *e, Pair54 *out) {
    s16 k = e->field_10[4];
    s32 i;
    s32 n;
    s32 m = 0;
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;

    if (dx != 0) {
        if (dy != 0) {
            if (abs(dx) >= abs(dy)) {
                c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
                c[0].field_2 = loc->u0.pair.field_2;
                c[1].field_0 = loc->u0.pair.field_0;
                c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
            } else {
                c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
                c[1].field_2 = loc->u0.pair.field_2;
                c[0].field_0 = loc->u0.pair.field_0;
                c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
            }
            m = 2;
        } else {
            c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
            c[0].field_2 = loc->u0.pair.field_2;
            m = 1;
        }
    } else if (dy != 0) {
        c[0].field_0 = loc->u0.pair.field_0;
        c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        m = 1;
    }
    for (i = 0, n = 0; i < m; i++) {
        if (k == (s16)(func_800703E0(c[i].field_0, c[i].field_2) & 0xF)) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    return n;
}

s32 func_8006BDEC(Stg40Ent48 *e, s32 mode) {
    Pair54 buf[3];
    Pair54 *sel = NULL;
    Stg40Loc *loc = &e->field_18;
    s32 i;
    s32 n;

    for (i = 0; i < 3; i++) {
        buf[i].field_0 = buf[i].field_2 = -1;
    }
    switch (mode) {
    case 0:
    default:
        n = func_8006B9A8(e, buf);
        break;
    case 1:
        n = func_8006B698(e, buf);
        break;
    case 2:
        n = func_8006BBBC(e, buf);
        break;
    case 4:
        n = func_8006B8C8(e, buf);
        break;
    case 3:
        return 0;
    }
    for (i = 0; i < n; i++) {
        if ((func_800703E0(buf[i].field_0, buf[i].field_2) & 0x4020) == 0x4000) {
            sel = &buf[i];
            break;
        }
    }
    if (sel == NULL) {
        return 0;
    }
    e->field_E = (func_8006E490(sel->field_0 - loc->u0.pair.field_0, sel->field_2 - loc->u0.pair.field_2) << 16) >> 7;
    loc->field_4.field_0 = loc->u0.pair.field_0;
    loc->field_4.field_2 = loc->u0.pair.field_2;
    loc->u0.pair.field_0 = sel->field_0;
    loc->u0.pair.field_2 = sel->field_2;
    loc->field_8 = loc->field_A = 12;
    func_80070974(loc->field_4.field_0, loc->field_4.field_2);
    func_800708FC(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->field_1C = 1;
    return 1;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006BFB0);

void func_8006C6C4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_8 == 2) {
        func_8006E764((Stg40E764 *)w, 0xDF0, 0xDF1);
    } else {
        func_8006E764((Stg40E764 *)w, 0xDF2, 0xDF3);
    }
    if (a0->stateLevel1 != 1 && (a0->stateLevel1 < 2 || (a0->stateLevel1 != 4 && a0->stateLevel1 != 9))) {
        Task_SetState1(a0, 1);
    }
}

void func_8006C7CC(Stg40E764 *a0, s32 a1) {
    s32 x;
    s32 y;

    switch (a1) {
    case 0:
    default:
        x = 0xDE3;
        y = 0xDE2;
        break;
    case 1:
        x = 0xDE1;
        y = 0xDDE;
        break;
    case 2:
        x = 0xDDF;
        y = 0xDE0;
        break;
    case 3:
        x = 0xDE4;
        y = 0xDE5;
        break;
    case 4:
        x = 0xDDC;
        y = 0xDDD;
        break;
    }
    func_8006E764(a0, x, y);
}

s32 func_8006C84C(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_10[1] >= 1 && e->field_10[1] <= 5) {
        func_8006C7CC((Stg40E764 *)w, e->field_10[1] - 1);
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        if (e->field_10[1] == 0xFF) {
            func_8006E4DC(a0, 0x29);
        } else {
            func_8006E4DC(a0, 0x28);
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        if (e->field_10[1] == 0xFF) {
            func_8006E4DC(a0, 0x29);
        } else {
            func_8006E4DC(a0, 0x28);
        }
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 3:
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2A);
            Task_NextState2(a0);
            Snd_PlayById(2, 0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x29);
                Task_SetState1(a0, 3);
            }
            break;
        }
        break;
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            if (a0->stateLevel4++ >= 11) {
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CAD4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    func_8006C7CC((Stg40E764 *)w, e->field_10[1] - 1);
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_0 &= ~0x4000;
        if (e->field_0 & 0x1000) {
            e->field_0 |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
            func_8006E4DC(a0, 0x28);
            Task_NextState2(a0);
            break;
        case 1:
            if (a0->stateLevel3++ >= 6) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
            func_8006E4DC(a0, 0x2C);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x36, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CD1C(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40Cell *c;

    c = func_800708A4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    c->field_0 |= 0x10;
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    e->field_C = e->field_E += 0x155;
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_0 &= ~0x4000;
        if (e->field_0 & 0x1000) {
            e->field_0 |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        c->field_0 &= ~0x10;
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
            if (a0->stateLevel1 == 4) {
                func_8006E4DC(a0, 0x2A);
            } else {
                func_8006E4DC(a0, 0x2C);
            }
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CF54(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        func_8006E4DC(a0, 0x28);
        e->field_0 |= 0x4000;
        Task_SetState1(a0, 1);
        break;
    case 1:
    case 4:
    case 5:
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006D0E8(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_18.field_14 = 0x2800;
        e->field_0 = (e->field_0 & 0x1000) ? (e->field_0 | 0x4400) : (e->field_0 & ~0x4000);
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 = (e->field_0 | 0x5000) & ~0x400;
            func_8006E4DC(a0, 0x28);
            e->field_18.field_18 = 0;
            e->field_18.field_14 = 0x2800;
            Snd_PlayById(4, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0x500) {
                e->field_18.field_14 = 0x500;
                e->field_18.field_18 = -(e->field_18.field_18 / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_18 > 0) {
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (func_8006E588(a0) == 1) {
                e->field_0 |= 0x400;
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 5:
        e->field_0 |= 0x5400;
        Task_SetState1(a0, 1);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 = (e->field_0 | 0x5000) & ~0x400;
            func_8006E4DC(a0, 0x28);
            e->field_18.field_18 = 0;
            e->field_18.field_14 = 0x2800;
            Snd_PlayById(5, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0) {
                e->field_18.field_14 = 0;
                e->field_18.field_18 = -(e->field_18.field_18 / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0) {
                e->field_18.field_14 = 0;
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

#ifdef NORMALIZED
s32 func_8006D418(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    switch (w->field_2C->field_8) {
    case 5:
    default:
        return w->field_2C->field_E;
    case 6:
        return func_8006CD1C(a0);
    case 7:
        return func_8006CF54(a0);
    case 8:
        return func_8006CAD4(a0);
    case 9:
    case 10:
    case 11:
    case 12:
        return func_8006D0E8(a0);
    case 4:
        return func_8006C84C(a0);
    case 2:
    case 3:
        return ((s32 (*)(Actor *))func_8006C6C4)(a0);
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006D418);
s32 func_8006D418(Actor *a0);
#endif

s32 func_8006D4E0(kind, a1, a2, a3, x, y)
    s32 kind;
    s32 a1;
    s32 a2;
    s16 a3;
    s16 x;
    s16 y;
{
    Stg40Ent48 *e;
    s32 flag = 0;
    s32 n;
    s16 h;

    e = &D_8005071C->field_18[D_8005071C->field_C];
    if (D_8005071C->field_C >= 41) {
        return -1;
    }
    e->field_7 = D_8005071C->field_C;
    e->field_6 = 0;
    e->field_0 = 0xC000;
    e->field_8 = kind;
    e->field_9 = a1;
    e->field_4 = a2;
    h = (a3 << 12) / 360;
    e->field_C = h;
    e->field_E = h;
    e->field_B = h / 512;
    e->field_18.u0.pair.field_0 = x;
    e->field_18.u0.pair.field_2 = y;
    e->field_18.field_14 = 0;
    if (a2 >= 500 && a2 <= 532) {
        e->field_38 = e->field_3C = e->field_40 = 0xD99;
    } else {
        e->field_38 = e->field_3C = e->field_40 = 0x1000;
    }
    switch (e->field_8) {
    case 0:
        flag = 1;
        e->field_0 |= flag;
        e->field_10 = (u8 *)&D_8005071C->field_BA0;
        D_80072B60->field_4 = e;
        D_8005071C->field_BA0 = 0;
        D_8005071C->field_BA4 = 0;
        break;
    case 1:
        flag = 1;
        e->field_10 = D_8005071C->field_BB8[D_8005071C->field_E++];
        e->field_0 |= 2;
        break;
    case 4:
        flag = 1;
        n = D_8005071C->field_10++;
        e->field_10 = D_8005071C->field_CCE[n + 1];
        e->field_0 |= 4;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        flag = 0;
        n = D_8005071C->field_12++;
        e->field_10 = D_8005071C->field_CE8[n];
        e->field_0 |= 4;
        break;
    case 2:
    case 3:
        flag = 0;
        e->field_0 |= 4;
        break;
    }
    func_800708FC(x, y, flag);
    D_8005071C->field_C++;
    return 0;
}

void func_8006D738(void) {
    Stg40Drop *r;
    Stg40SlotInfo *s;
    Out1DB68 out;
    s32 k;
    s32 id;
    s32 i;
    s16 t;
    s32 m;
    s32 c;
    Stg40Map *map;

    for (r = D_80072B60->field_14->field_10; r->x != 0xFF; r++) {
        if (D_8005071C->field_E >= 10) {
            break;
        }
        switch (func_800711C4(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            id = k[((Stg40Map *)D_80072B60->field_10)->field_2F];
            func_8001DB68(id, &out);
            c = out.field_0;
            func_8006D4E0(1, 0, c, 0, r->x, r->y);
            s = (Stg40SlotInfo *)D_8005071C->field_BB8[D_8005071C->field_E - 1];
            s->field_0 = id;
            s->field_2 = out.field_10 != 0;
            s->field_3 = out.field_C;
            s->field_E = out.field_18;
            t = s->field_E;
            if (t == 0) {
                t = 1;
            }
            s->field_E = t;
            s->field_A = 0;
            s->field_C = 0;
            s->field_7 = D_80072904[out.field_8 * 2];
            s->field_6 = D_80072904[out.field_8 * 2 + 1];
            s->field_4 = D_800728F4[out.field_4 * 2];
            m = s->field_5 = D_800728F4[out.field_4 * 2 + 1];
            if (m == 2) {
                if (s->field_4 != (func_800703E0(r->x, r->y) & 0xF)) {
                    s->field_4 = m;
                    s->field_5 = 0;
                }
            }
            s->field_B = 0;
            for (i = 0; i < 3; i++) {
                if ((s16)out.digiIds[i] == 0) {
                    break;
                }
                s->field_10[i] = out.digiIds[i];
                s->field_16[i] = out.levels[i];
                s->field_B++;
            }
        }
    }
}

void func_8006DA18(void) {
    Stg40MapPos *pos = ((Stg40Map *)D_80072B60->field_10)->field_34;
    Stg40Drop *r;
    s32 k;
    u8 *d;

    for (r = D_80072B60->field_14->field_8; r->x != 0xFF; r++) {
        if (D_8005071C->field_10 >= 12) {
            break;
        }
        switch (func_800711C4(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            func_8006D4E0(4, 0, 0x276, 0, r->x, r->y);
            k--;
            d = D_8005071C->field_CCE[D_8005071C->field_10];
            d[0] = pos[k].field_0;
            d[1] = pos[k].field_1;
        }
    }
}

#ifdef NORMALIZED
s32 func_8006DB68(a0, a1, a2, a3)
    s32 a0;
    s32 a1;
    s16 a2;
    s16 a3;
{
    Stg40Ids4 tbl;
    s32 lvl;
    s32 t;
    s32 u;
    s32 m;
    s32 kind;
    s32 model;
    s32 bit;
    Stg40Rec3 *r;
    u8 *d;

    lvl = a1;
    u = lvl;
    if (lvl == 0) {
        u = 1;
    }
    lvl = u;
    switch (a0) {
    case 0:
    default:
        return 0;
    case 2:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25A;
        kind = 6;
        bit = lvl - 1;
        break;
    case 3:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25F;
        kind = 7;
        bit = lvl + 4;
        break;
    case 4:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x270;
        kind = 8;
        bit = lvl + 9;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        tbl = D_8006362C;
        t = 3;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        kind = a0 + 4;
        model = tbl.id[a0 - 5];
        t = lvl + 5;
        bit = kind + t;
        model = model + lvl - 1;
        break;
    case 1:
        m = 5;
        m = (lvl < m) ? lvl : m;
        lvl = m;
        if (D_8005071C->field_14 >= 100) {
            return -1;
        }
        r = &D_8005071C->field_D08[D_8005071C->field_14];
        r->field_0 = a2;
        r->field_1 = a3;
        r->field_2 = lvl;
        D_8005071C->field_14++;
        return 0;
    }
    if (!(bit & D_80072B60->field_188)) {
        if (D_80072B60->field_18C >= 12) {
            return -1;
        }
        D_80072B60->field_188 |= bit;
        D_80072B60->field_18C++;
    }
    if (D_8005071C->field_12 < 16) {
        func_8006D4E0(kind, a0, model, 0, a2, a3);
        d = D_8005071C->field_CE8[D_8005071C->field_12 - 1];
        d[0] = a0;
        d[1] = lvl;
        return 0;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DB68);
s32 func_8006DB68();
#endif

void func_8006DDDC(void) {
    Stg40Spawn *e;
    s32 kind;
    s32 val;

    for (e = D_80072B60->field_14->field_C; e->x != 0xFF; e++) {
        switch (func_800711C4(4)) {
        case 0:
        default:
            kind = e->kind0;
            val = e->val0;
            break;
        case 1:
            kind = e->kind1;
            val = e->val1;
            break;
        case 2:
            kind = e->kind2;
            val = e->val2;
            break;
        case 3:
            kind = e->kind3;
            val = e->val3;
            break;
        }
        if (kind != 0) {
            func_8006DB68(kind, val + D_8005071C->field_E54->field_C, e->x, e->y);
        }
    }
}

s32 func_8006DEF0(u8 (*tbl)[2], s32 v) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Cell *cells = (Stg40Cell *)b->field_E58;
    s32 h = b->field_E54->field_2;
    s32 w = b->field_E54->field_0;
    s32 n = 0;
    s32 x;
    s32 y;
    Stg40Cell *c;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            c = &cells[y * w + x];
            if (c->field_2 == v && !(c->field_0 & 0x40) && (c->field_0 & 0xF) < 8) {
                tbl[n][0] = x;
                tbl[n][1] = y;
                n++;
            }
        }
    }
    return n;
}

void func_8006DFA4(u8 (*tbl)[2], s32 a1, s32 a2) {
    s32 n = func_8006DEF0(tbl, func_800711C4(D_80072B60->field_0));

    if (n != 0) {
        n = func_800711C4(n);
        func_8006DB68(a1, a2, tbl[n][0], tbl[n][1]);
    }
}

void func_8006E024(void) {
    Stg40Map *m = (Stg40Map *)D_80072B60->field_10;
    Stg40Ids5 ids = D_80063664;
    Stg40MapGen *g = m->field_54;
    s32 buf;
    s32 i;
    s32 j;
    s32 n;
    s32 v;

    if (D_80072B60->field_0 == 0) {
        return;
    }
    buf = Mem_Alloc(0x1800, 2);
    for (i = 0; i < 5; g++, i++) {
        switch (func_800711C4(4)) {
        case 0:
        default:
            n = g->cnt0;
            break;
        case 1:
            n = g->cnt1;
            break;
        case 2:
            n = g->cnt2;
            break;
        case 3:
            n = g->cnt3;
            break;
        }
        for (j = 0; j < n; j++) {
            switch (func_800711C4(4)) {
            case 0:
            default:
                v = g->val0;
                break;
            case 1:
                v = g->val1;
                break;
            case 2:
                v = g->val2;
                break;
            case 3:
                v = g->val3;
                break;
            }
            func_8006DFA4((u8 (*)[2])buf, ids.id[i], v);
        }
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Ent48 *func_8006E200(s16 x, s16 y) {
    Stg40Ent48 *e = D_8005071C->field_18;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < 41; i++, e++) {
        if (e->field_18.u0.pair.field_0 == x && e->field_18.u0.pair.field_2 == y && (e->field_0 & 0x8000)) {
            r = e;
            break;
        }
    }
    return r;
}

void func_8006E278(void) {
    s32 i;
    Stg40Ent48 *e = D_8005071C->field_18;

    for (i = 0; i < 41; i++, e++) {
        if (e->field_0 & 0x8000) {
            e->field_0 |= 0x5000;
        }
    }
}

s32 func_8006E2B8(Stg40Ent48 *a, Stg40Ent48 *b) {
    s16 dx;
    s16 dy;

    if (a->field_18.u0.pair.field_0 - b->field_18.u0.pair.field_0 >= 0) {
        dx = a->field_18.u0.pair.field_0 - b->field_18.u0.pair.field_0;
    } else {
        dx = b->field_18.u0.pair.field_0 - a->field_18.u0.pair.field_0;
    }
    if (a->field_18.u0.pair.field_2 - b->field_18.u0.pair.field_2 >= 0) {
        dy = a->field_18.u0.pair.field_2 - b->field_18.u0.pair.field_2;
    } else {
        dy = b->field_18.u0.pair.field_2 - a->field_18.u0.pair.field_2;
    }
    return dx < 2 && dy < 2;
}

s32 func_8006E330(void) {
    Stg40List *l = &D_8005071C->field_1018;
    Stg40Ent48 *e = D_8005071C->field_18;
    s32 i;
    s32 r;

    l->field_20 = 0;
    for (i = 0; i < D_8005071C->field_C; i++, e++) {
        if ((e->field_0 & 0x8002) == 0x8002 && e->field_14->stateLevel1 != 4) {
            r = func_8006E2B8(e, D_80072B60->field_4);
            if (r == 1) {
                l->field_0[l->field_20++] = e;
                e->field_0 |= 0x100;
                Task_SetState1(e->field_14, 3);
                e->field_0 |= (l->field_20 == r) ? 0x800 : 0;
            }
        }
    }
    if (l->field_20 != 0) {
        D_80072B60->field_4->field_0 |= 0x100;
    }
    return l->field_20;
}

s32 func_8006E490(s32 dx, s32 dy) {
    s32 idx = 0;
    s32 r;
    s32 v;

    if (dx < 0) {
        idx |= 8;
    }
    if (dx > 0) {
        idx |= 4;
    }
    if (dy < 0) {
        idx |= 2;
    }
    idx |= dy > 0;
    v = D_800728D4[idx];
    r = 0;
    if (v != -1) {
        r = v;
    }
    return r;
}

void func_8006E4DC(a0, a1)
    Actor *a0;
    s16 a1;
{
    ((Stg40ActWork *)a0->work)->field_30 = a1;
}

void func_8006E4E8(Actor *a0, s32 a1) {
    if (((Stg40ActWork *)a0->work)->field_32 != a1) {
        func_8006E4DC(a0, a1);
    }
}

s32 func_8006E520(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (func_800678C4(a0) == 1 || a0->stateLevel4 >= 31) {
        r = 1;
    }
    return r;
}

s32 func_8006E588(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (func_800678C4(a0) == 1 || a0->stateLevel4 >= 31 || (a0->stateLevel4 >= 11 && D_8005F704 != 0)) {
        r = 1;
    }
    return r;
}

void func_8006E60C(s32 a0) {
    s32 n;
    Blk12 *e;
    Stg40B60 *b;

    D_80072B60->field_16C = 0;
    if (a0 != 0) {
        func_8001E28C(a0);
        for (n = func_8001E480(); n != -1; n = Flag_NextPassingEntry()) {
            e = func_8001E5E8(n);
            b = D_80072B60;
            b->field_144[b->field_16C].u0.pair.field_0 = e->data[0] - 1;
            b->field_144[b->field_16C].u0.pair.field_2 = e->data[1] - 1;
            b->field_144[b->field_16C].field_4 = n;
            b->field_16C++;
        }
    }
}

s32 func_8006E6CC(void) {
    u32 i = 0;
    s32 r = 0;
    Stg40B60Ent *e = D_80072B60->field_144;

    for (; i < D_80072B60->field_16C; e++) {
        Stg40B60 *b = D_80072B60;
        i++;
        if (b->field_4->field_18.u0.field_0 == e->u0.field_0) {
            b->field_170 = e->field_4;
            e->u0.pair.field_2 = -1;
            e->u0.pair.field_0 = -1;
            r = -1;
            D_8005071C->field_2 = 2;
            break;
        }
    }
    return r;
}

void func_8006E764(Stg40E764 *a0, s32 a1, s32 a2) {
    if (a0->field_34 == 0) {
        a0->field_28 = 0;
        return;
    }
    if (a0->field_28 == 0) {
        if (a1 != 0) {
            Cd_QueueFile(a1);
        }
        if (a2 != 0) {
            Cd_QueueFile(a2);
        }
        a0->field_28 = 16;
    }
    a0->field_28--;
}

void func_8006E7F0(s32 i, s32 item, u8 status) {
    GameStateView *g = D_80050720;

    g->slotItems[i] = item;
    g->slotStatus[i] = item ? status : 1;
}

s32 func_8006E820(i)
    s32 i;
{
    GameStateView *g = D_80050720;

    if (g->slotStatus[i] == 1) {
        return -1;
    }
    return g->slotItems[i];
}

s32 func_8006E858(s32 slot) {
    GameStateView *gs = D_80050720;
    s32 r;

    if (gs->slotItems[slot] == 0) {
        return 0;
    }
    if (gs->slotStatus[slot] == 1) {
        return -1;
    }
    r = func_8001E0E4(gs->slotItems[slot]);
    r = r ? r : 1;
    return r;
}

void func_8006E8C4(s32 i, u8 status) {
    GameStateView *g = D_80050720;

    g->slotStatus[i] = g->slotItems[i] ? status : 0;
}

void func_8006E8F4(s32 n) {
    GameStateView *g = D_80050720;

    g->hp = (g->hp - n < 0) ? 0 : g->hp - n;
}

s32 func_8006E920(Stg40Shop *a) {
    s32 ret;
    s32 j;
    s32 i;
    s32 key;
    u16 *bag;
    u16 *items;

    D_80072B60->field_E1 = 0;
    switch (func_8006E820(a->field_0)) {
    case -1:
        ret = a->field_C;
        break;
    case 0:
        ret = a->field_C + 1;
        break;
    default:
        for (j = 0; j < 4; j++) {
            key = a->field_2[j];
            items = D_80050720->bagItems;
            if (key != -1) {
                for (i = 0, bag = items; i < 0x30; i++, bag++) {
                    if (*bag != 0 && key == func_8001E0C0(*bag)) {
                        D_80072B60->field_B0[D_80072B60->field_E1] = *bag;
                        D_80072B60->field_E1++;
                    }
                }
            }
        }
        if (D_80072B60->field_E1 == 0) {
            ret = a->field_C + 2;
        } else {
            ret = 0;
        }
        break;
    }
    return ret;
}

#ifdef NORMALIZED
s16 func_8006EA84(s32 mode) {
    DigiRosterEntry *e = D_80050720->elems;
    Stg40B60 *b;
    s32 *pi;
    s32 i;

    D_80072B60->field_140 = 0;
    b = D_80072B60;
    for (i = 0; i < 36; e++, i++) {
        if (e->state >= 2) {
            switch (mode) {
            case 1:
                if ((s16)e->hp == 0) {
                    continue;
                }
                b->field_128[b->field_140++] = i;
                break;
            case 2:
                if ((s16)e->hp == 0) {
                    b->field_128[b->field_140++] = i;
                }
                break;
            case 3:
                if ((s16)e->hp >= 2) {
                    b->field_128[b->field_140++] = i;
                }
                break;
            default:
                b->field_128[b->field_140++] = *(pi = &i);
                break;
            }
        }
    }
    return D_80072B60->field_140;
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006EA84);
s16 func_8006EA84(s32 mode);
#endif

void func_8006EB84(s32 idx, s32 row, s32 val) {
    Stg40TileGrid *t = D_80072BB0;
    s32 sh = (idx % 4) * 4;
    u16 *p = &t->pix[(row + 1) * 18 + idx / 4 + 1];
    *p = (*p & ~(0xF << sh)) | (val << sh);
    t->field_760 = -1;
}

void func_8006EBF4(s32 x, s32 y, s32 ox, s32 oy, s32 dir) {
    s32 v;

    if (ox != -1) {
        func_8006EB84(ox, oy, (func_800703E0(ox, oy) >> 13) & 1);
    }
    if (x != -1) {
        switch (dir) {
        case 0:
            v = 14;
            break;
        case 1:
            v = 13;
            break;
        case 2:
        case 3:
            v = 10;
            break;
        case 4:
            v = 11;
            break;
        default:
            v = 12;
            break;
        }
        func_8006EB84(x, y, v);
    }
}

void func_8006ECD0(Stg40TileWork *a0) {
    s32 h = a0->field_768;
    s32 w = a0->field_766;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            func_8006EB84(x, y, (func_800703E0(x, y) >> 13) & 1);
        }
    }
}

void func_8006ED5C(void) {
    s32 i;
    u8 *p = D_8005071C->field_E7C;

    i = 0x17F;
    do {
        i--;
        *p++ = 0;
    } while (i >= 0);
    D_80072944 = 0;
}

void func_8006ED88(s32 arg0) {
    s32 n;
    u8 *p;
    Stg40Cell *c;
    s32 i;

    p = D_8005071C->field_E7C;
    c = (Stg40Cell *)D_8005071C->field_E58;
    n = D_8005071C->field_E54->field_0 * D_8005071C->field_E54->field_2 / 8;

    for (i = 0; i < n; i++) {
        if (arg0 == 0) {
            *p = 0;
            *p = (c->field_0 >> 13) & 1;
            c++;
            *p |= (c->field_0 & 0x2000) ? 2 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 4 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 8 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x10 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x20 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x40 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x80 : 0;
            c++;
        } else {
            if (*p & 1) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 2) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 4) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 8) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x10) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x20) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x40) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x80) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
        }
        p++;
    }
}

void func_8006F06C(void) {
    func_8006ED5C();
    func_8006ED88(1);
}

void func_8006F094(void) {
    Stg40TileWork *t = (Stg40TileWork *)D_80072BB0;
    s32 x;
    s32 y;

    for (y = 0; y < D_8005071C->field_E54->field_2; y++) {
        for (x = 0; x < D_8005071C->field_E54->field_0; x++) {
            func_8006F62C(t, x, y);
        }
    }
}

void func_8006F168(Stg40ImgWork *a0) {
    LoadImage(&a0->rect, a0->data);
}

void func_8006F18C(Stg40TileWork *a0) {
    if (a0->field_760 != 0) {
        LoadImage(&a0->rect, a0->data);
        a0->field_760 = 0;
    }
}

void func_8006F1C8(Stg40ImgWork *a0) {
    Stg40ImgClut *p = (Stg40ImgClut *)a0;
    s32 c;
    s32 v;
    s32 h;
    s32 g;
    s32 b;

    p->field_75C++;
    c = 15 - ((p->field_75C & 0xF) >> 1);
    v = c & 0x1F;
    b = v << 10;
    g = (v << 5) | 0x8000;
    p->clut[4] = b | g;
    p->clut[3] = v | 0x8000;
    p->clut[2] = (v << 5) | 0x8000 | v;
    p->clut[1] = g;
    h = (c / 2) & 0x1F;
    p->clut[0] = b | ((h << 5) | 0x8000) | h;
    if (D_8005F6F0[0].start != 0) {
        p->clut[6] = 0xA94A;
        p->clut[7] = 0xE318;
    } else {
        p->clut[6] = 0x8000;
        p->clut[7] = 0xA94A;
    }
    func_8006F168(a0);
}

void func_8006F290(Stg40TileWork *w) {
    GfxTexSlot *s;
    RECT *r;
    u16 *d;
    u16 *src;
    s32 i;
    s32 n;
    s32 j;
    s32 k;

    ((Stg40ImgWork *)w)->field_758 = Gfx_ReserveTexSlot();
    s = (GfxTexSlot *)((Stg40ImgWork *)w)->field_758;
    r = &((Stg40ImgWork *)w)->rect;
    r->x = s->vramX;
    r->y = s->vramY + 0xFE;
    r->w = 0x10;
    r->h = 2;
    d = (u16 *)((Stg40ImgWork *)w)->data;
    src = D_80072948;
    for (j = 0; j < 32; j++) {
        *d++ = *src++;
    }
    func_8006F168((Stg40ImgWork *)w);
    r = &w->rect;
    r->x = s->vramX;
    r->y = s->vramY;
    r->w = 0x12;
    r->h = 0x32;
    n = 0x12 * 0x32;
    d = ((Stg40TileGrid *)w)->pix;
    for (i = 0; i < n; i++) {
        *d++ = 0;
    }
    w->field_760 = -1;
    func_8006F18C(w);
    for (k = 1; k >= 0; k--) {
        w->field_762[k] = 0;
    }
}

void func_8006F38C(Stg40ImgWork *a0) {
    Gfx_ReleaseTexSlot(a0->field_758);
}

s16 func_8006F3B0(Stg40TileWork *a0) {
    Stg40Blk5071C *b = D_8005071C;

    a0->field_766 = b->field_E54->field_0;
    a0->field_768 = b->field_E54->field_2;
    return a0->field_76A = a0->field_766 / 8;
}

#ifdef NORMALIZED
void func_8006F3F4(Stg40TileWork *w, s32 x, s32 y)
{
    s32 group;
    s32 row;
    s32 n;
    s32 mask;
    u8 kind;
    s32 dim1;
    Stg40E34 *dims;
    s32 count;
    Stg40Cell *grid;
    s32 col;

    dims = D_8005071C->field_E54;
    dim1 = dims->field_0;
    count = dims->field_2;
    kind = func_80070438(x, y)->field_2;
    if (kind == 0xFF) {
        return;
    }
    group = kind >> 5;
    mask = 1 << (kind % 32);
    if (group < 8) {
        if (D_8005071C->field_E5C[group] & mask) {
            return;
        }
        D_8005071C->field_E5C[group] |= mask;
    }
    grid = (Stg40Cell *)D_8005071C->field_E58;
    for (row = 0; row < count; row++) {
        for (col = 0; col < dim1; col++) {
            if (grid[col + row * dim1].field_2 == kind) {
                grid[col + row * dim1].field_0 |= 0x2000;
                func_8006EB84(col, row, 1);
                {
                    Stg40Offs8 o = D_8006368C;

                    for (n = 0; n < 4; n++) {
                        s32 nx = col + o.v[n * 2];
                        s32 ny = row + o.v[n * 2 + 1];

                        if ((func_800703E0(nx, ny) & 0xC000) == 0x8000) {
                            do {
                                do {
                                    grid[nx + dim1 * ny].field_0 |= 0x2000;
                                    func_8006EB84(nx, ny, 1);
                                } while (0);
                            } while (0);
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F3F4);
void func_8006F3F4(Stg40TileWork *w, s32 x, s32 y);
#endif

void func_8006F62C(Stg40TileWork *a0, s32 x, s32 y) {
    if (func_800703E0(x, y) & 0x8000) {
        ((Stg40Cell *)D_8005071C->field_E58)[a0->field_766 * y + x].field_0 |= 0x2000;
        func_8006EB84(x, y, 1);
    }
}

void func_8006F6BC(Stg40TileWork *w) {
    s32 x = D_8005071C->field_1068->u0.pair.field_0;
    s32 y = D_8005071C->field_1068->u0.pair.field_2;
    s32 dx = w->field_76C - x;
    s32 dy = w->field_76E - y;

    if (dx == 0 && dy == 0) {
        return;
    }
    func_8006F3F4(w, x, y);
    if (dx > 0) {
        func_8006F62C(w, x - 1, y - 1);
        func_8006F62C(w, x - 1, y);
        func_8006F62C(w, x - 1, y + 1);
    }
    if (dx < 0) {
        func_8006F62C(w, x + 1, y - 1);
        func_8006F62C(w, x + 1, y);
        func_8006F62C(w, x + 1, y + 1);
    }
    if (dy > 0) {
        func_8006F62C(w, x - 1, y - 1);
        func_8006F62C(w, x, y - 1);
        func_8006F62C(w, x + 1, y - 1);
    }
    if (dy < 0) {
        func_8006F62C(w, x - 1, y + 1);
        func_8006F62C(w, x, y + 1);
        func_8006F62C(w, x + 1, y + 1);
    }
    func_8006F62C(w, x, y);
    w->field_76C = D_8005071C->field_1068->u0.pair.field_0;
    w->field_76E = D_8005071C->field_1068->u0.pair.field_2;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F86C);

void func_8006FC54(ActorWork *w) {
    Stg40TileWork *t = (Stg40TileWork *)w;
    Stg40Loc *loc;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == D_80072B60->field_7E - 1) {
            t->field_762[i] = (t->field_762[i] + 0x20 < 0x100) ? (u16)t->field_762[i] + 0x20 : 0xFF;
        } else {
            t->field_762[i] = (t->field_762[i] - 0x20 >= 0) ? (u16)t->field_762[i] - 0x20 : 0;
        }
        if (t->field_762[i] != 0) {
            switch (i) {
            case 0:
                loc = D_8005071C->field_1068;
                func_8006F86C(t, 0x50, 0, loc->u0.pair.field_0, loc->u0.pair.field_2, 0x11, 0x11, 3, t->field_762[0]);
                break;
            case 1:
                func_8006F86C(t, 0, 0, 0x20, 0x18, 0x41, 0x31, 4, t->field_762[1]);
                break;
            }
        }
    }
}

void func_8006FDAC(void) {
}

void func_8006FDB4(Actor *a0) {
    Stg40TileWork *w = (Stg40TileWork *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072BB0 = (Stg40TileGrid *)w;
        func_8006F3B0(w);
        func_8006F290(w);
        func_8006ECD0(w);
        func_8006F18C(w);
        D_80072B60->field_7E = 0;
        Task_NextState0(a0);
        break;
    case 1:
        func_8006F6BC(w);
        func_8006F18C(w);
        func_8006F1C8((Stg40ImgWork *)w);
        break;
    case 2:
        break;
    }
}

void func_8006FE5C(Actor *a0) {
    func_8006F38C((Stg40ImgWork *)a0->work);
    Task_DefaultDestroy(a0);
}

void func_8006FE90(Actor *a0) {
    ActorWork *w = a0->work;

    if (func_80022518(0x12) <= 0) {
        D_80072B60->field_7E = 0;
    }
    func_8006FC54(w);
}

void func_8006FED4(void) {
    Stg40E34 *d = D_8005071C->field_E54;

    D_8005071C->field_E58 = (ActorWork *)Mem_Alloc(d->field_0 * (d->field_2 << 2), 2);
}

void func_8006FF28(void) {
    Mem_Free(D_8005071C->field_E58);
}

u16 func_8006FF54(u16 *pal, u32 *bits, s32 x, s32 y) {
    s32 w = D_8005071C->field_E54->field_0 / 8;

    return pal[(bits[w * y + x / 8] >> ((x % 8) * 4)) & 0xF];
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FFCC);

u16 func_800703E0(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    Stg40Cell *cells = (Stg40Cell *)b->field_E58;
    s32 w = d->field_0;
    s32 h = d->field_2;
    u16 r = 0;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = cells[w * y + x].field_0;
    }
    return r;
}

Stg40Cell *func_80070438(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void func_80070490(s32 buf, s32 p1, s32 x, s32 y, s32 fill)
{
    Stg40Cell *grid = (Stg40Cell *)D_8005071C->field_E58;
    s32 width = D_8005071C->field_E54->field_0;
    s32 maxRun = 0;
    s32 count;
    s32 k;
    s32 nx;
    s32 ny;
    s32 r;

    if (!(func_800703E0(x, y) & 0x4000)) {
        return;
    }
    count = 1;
    ((Stg40FillPt *)buf)[0].x = x;
    ((Stg40FillPt *)buf)[0].y = y;
    grid[width * y + x].field_0 |= fill;
    do {
        if (maxRun < count) {
            maxRun = count;
        }
        count--;
        x = ((Stg40FillPt *)buf)[count].x;
        y = ((Stg40FillPt *)buf)[count].y;
        for (k = 0; k < 4; k++) {
            nx = D_800729C0[k * 2] + x;
            ny = D_800729C0[k * 2 + 1] + y;
            r = func_800703E0(nx, ny);
            if ((r & (fill | 0x8000)) != 0x8000) {
                continue;
            }
            if (p1 != 0) {
                grid[width * ny + nx].field_0 |= fill;
            }
            if (!(r & 0x4000)) {
                continue;
            }
            grid[width * ny + nx].field_0 |= fill;
            ((Stg40FillPt *)buf)[count].x = nx;
            ((Stg40FillPt *)buf)[count].y = ny;
            count++;
        }
    } while (count != 0);
}

s32 func_800706C8(void) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 h = b->field_E54->field_2;
    s32 w = b->field_E54->field_0;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++, c++) {
            if ((c->field_0 & 0x4000) && c->field_2 == 0xFF) {
                return y * w + x;
            }
        }
    }
    return -1;
}

void func_80070754(void) {
    Stg40Blk5071C *b = D_8005071C;
    s32 n = b->field_E54->field_0 * b->field_E54->field_2;
    u8 v = D_80072B60->field_0;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 i;

    for (i = 0; i < n; i++, c++) {
        if (c->field_0 & 0x2000) {
            c->field_2 = v;
            c->field_0 &= ~0x2000;
        }
    }
}

void func_800707D0(void) {
    s32 w = D_8005071C->field_E54->field_0;
    s32 buf = Mem_Alloc(0x3FF8, 2);
    s32 i;

    D_80072B60->field_0 = 0;
    while ((D_80072BB8 = i = func_800706C8()) != -1) {
        func_80070490(buf, 0, i % w, i / w, 0x2000);
        func_80070754();
        D_80072B60->field_0++;
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Cell *func_800708A4(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void func_800708FC(s32 x, s32 y, s32 flag) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 |= flag == 0 ? 0x40 : 0x60;
    }
}

void func_80070974(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 &= ~0x60;
    }
}

void func_800709DC(void) {
    Stg40Rec3 *r = D_8005071C->field_D08;
    Stg40Cell *c;
    s32 i;

    for (i = 0; i < D_8005071C->field_14; r++, i++) {
        c = func_800708A4(r->field_0, r->field_1);
        c->field_0 &= 0xFFF0;
        c->field_0 |= r->field_2 + 7;
    }
}

void func_80070A7C(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;
    s16 *q = p->field_0;
    s32 i;

    p->field_18 = 10;
    p->field_16 = 0;
    p->field_1A = 0;
    for (i = 0; i < p->field_18; i++) {
        *q++ = -1;
    }
    *q = -2;
}

s16 *func_80070AD0(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = f->field_0;

    while (*p != -2) {
        if (*p == v) {
            return p;
        }
        p++;
    }
    return NULL;
}

void func_80070B2C(s32 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;

    if (func_80070AD0(v) == NULL && f->field_16 < f->field_18) {
        f->field_0[f->field_16] = v;
        f->field_16++;
    }
}

void func_80070BA4(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = func_80070AD0(v);
    s16 *q;

    if (p != NULL) {
        for (q = p + 1; *q != -2;) {
            *p++ = *q++;
        }
        *p = -1;
        f->field_16--;
        if (f->field_0[f->field_1A] == -1) {
            f->field_1A = 0;
        }
    }
}

s16 func_80070C48(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    p->field_1A = (p->field_1A + 1 < p->field_16) ? p->field_1A + 1 : 0;
    return p->field_0[p->field_1A];
}

s16 func_80070C94(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    return p->field_0[p->field_1A];
}

void func_80070CC0(s32 id) {
    s32 *p;

    p = (s32 *)Cd_GetFileOrNull(id);
    func_80070EE0(p);
    D_80072B60->field_1C = id;
    D_80072B60->field_C = p;
    D_80072B60->field_10 = p[D_8005071C->field_3];
    D_80072B60->field_18 = 0;
    while (D_80072B60->field_C[D_80072B60->field_18] != 0) {
        D_80072B60->field_18++;
    }
}

void func_80070D74(void) {
    s32 i;

    D_8005071C->field_4 = func_800711C4(8);
    for (i = 7; i >= 0; i--) {
        D_8005071C->field_E5C[i] = 0;
    }
}

void func_80070DC0(void) {
    Stg40B60 *b = D_80072B60;
    Stg40Blk5071C *g = D_8005071C;
    Stg40Map *m = (Stg40Map *)b->field_10;
    u8 *src;
    u8 *dst;

    b->field_14 = m->field_8[g->field_4];
    g->field_E54->field_A = m->field_28;
    g->field_E54->field_4 = 1;
    g->field_E54->field_C = m->field_2E;
    src = m->field_0;
    dst = D_8005071C->field_E54->field_E;
    memset(dst, 0xFF, 16);
    D_8005071C->field_E54->field_D = 0;
    while (*src != 0xFF) {
        *dst = *src;
        D_8005071C->field_E54->field_D++;
        src++;
        dst++;
    }
}

void func_80070EC0(u32 *p, u32 n) {
    if (*p < n) {
        *p += n;
    }
}

s32 func_80070EE0(s32 *p) {
    u32 *tbl = (u32 *)p;
    u32 base = (u32)p;
    s32 n = 0;
    s32 i;
    Stg40MapRel *m;
    Stg40MapRoomRel *r;
    u32 *q;

    while (*tbl != 0) {
        if (*tbl < base) {
            *tbl += base;
            m = (Stg40MapRel *)*tbl;
            m->field_0 += base;
            for (i = 0; i < 8; i++) {
                q = &m->field_8[i];
                *q += base;
                r = (Stg40MapRoomRel *)*q;
                func_80070EC0(&r->field_0[0], base);
                func_80070EC0(&r->field_0[1], base);
                func_80070EC0(&r->field_0[2], base);
                func_80070EC0(&r->field_0[3], base);
                func_80070EC0(&r->field_0[4], base);
            }
        }
        tbl++;
        n++;
    }
    return n;
}

s32 func_80070FEC(Stg40Pick *out, Stg40Rec3 *e, u8 key) {
    s32 r = -1;
    s32 n = 0;

    for (; e->field_0 != 0xFF; e++) {
        if (e->field_2 == key) {
            out->field_0 = e->field_0;
            out->field_2 = e->field_1;
            n++;
            out++;
        }
    }
    if (n != 0) {
        r = func_800711C4(n);
    }
    return r;
}

void func_8007107C(void) {
    Stg40Pick buf[20];
    Stg40Rec3 *list = D_80072B60->field_14->field_4;
    s32 r;

    r = func_80070FEC(buf, list, 0);
    D_80072B60->field_20.field_0 = buf[r].field_0;
    D_80072B60->field_20.field_2 = buf[r].field_2;
    r = func_80070FEC(buf, list, 1);
    D_80072B60->field_24.field_2 = -1;
    D_80072B60->field_24.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_24.field_0 = buf[r].field_0;
        D_80072B60->field_24.field_2 = buf[r].field_2;
    }
    r = func_80070FEC(buf, list, 2);
    D_80072B60->field_28.field_2 = -1;
    D_80072B60->field_28.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_28.field_0 = buf[r].field_0;
        D_80072B60->field_28.field_2 = buf[r].field_2;
    }
}

s32 func_80071180(void) {
    return (Rand_Next() & 0xFFF) * 100 / 4096;
}

s32 func_800711C4(s32 n) {
    return (Rand_Next() & 0xFFF) * n / 4096;
}

s32 func_80071204(s32 i) {
    s32 r = func_8006E858(7);
    r = r < 0 ? 0 : r;
    return D_800729F8[r][i];
}

s32 func_80071258(s32 i) {
    return func_80071180() < D_80072A1C[i];
}

s32 func_80071294(void) {
    s32 r = D_80072A30[func_80071180() / 4];

    if (r >= 4 && r < 16) {
        if (func_8006E820(D_800729E0[r - 4]) <= 0) {
            r = 16;
        }
    }
    return r;
}

#ifdef NORMALIZED
void func_80071310(s32 a0, s32 a1) {
    s32 base = 0x1FD0011;

    if (a0 == 0) {
        base = 0x1FD0047;
    }
    switch (a1) {
    case 0:
        func_80067610(1, base, (s32)D_80050720->field_D1, (s32)func_8006755C(0, D_80072B60->field_58));
        break;
    case 1:
        func_80067610(1, base + 1, (s32)func_8006755C(0, D_80072B60->field_58), 0);
        break;
    case 2:
    case 3:
        func_80067610(1, base + a1, 0, 0);
        break;
    case 16:
        func_80067610(1, base + 5, 0, 0);
        break;
    default:
        func_80067610(1, base + 4, Item_GetNameText(*(D_80050720->slotItems + D_800729E0[a1 - 4])), 0);
        break;
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071310);
void func_80071310(s32 a0, s32 a1);
#endif

void func_8007142C(s32 a0, s32 a1) {
    s32 i;
    s32 k;
    DigiRosterEntry *r;
    Stg40Blk5071C *g;

    switch (a0) {
    case 0:
        D_80072B60->field_58 = a1 * 400;
        func_8006E8F4(D_80072B60->field_58);
        break;
    case 1:
        D_80072B60->field_58 = a1 * 10;
        func_8006EA84(3);
        for (i = 0; i < D_80072B60->field_140; i++) {
            r = &D_80050720->elems[D_80072B60->field_128[i]];
            r->hp = ((s16)r->hp - D_80072B60->field_58 > 0) ? (u16)r->hp - (u16)D_80072B60->field_58 : 1;
        }
        break;
    case 2:
        D_8005071C->field_BA0 = (D_8005071C->field_BA0 | 2) & ~0x80;
        D_8005071C->field_BA4 = func_800711C4(4) + 1;
        break;
    case 3:
        g = D_8005071C;
        g->field_BB5 = 0;
        g->field_BA0 = (g->field_BA0 | 1) & ~0x40;
        break;
    default:
        k = D_800729E0[a0 - 4];
        D_80050720->slotStatus[k] = 1;
        break;
    case 16:
        break;
    }
}

s32 func_800715DC(void) {
    s32 r = func_8006E820();

    if (r > 0) {
        r = 1;
    }
    return r;
}

s32 func_80071608(void) {
    u8 buf[16];
    s32 n = 0;
    s32 r = -1;
    u32 i;

    for (i = 0; i < 12; i++) {
        if (func_80022518(D_80072A4C[i]) > 0) {
            buf[n++] = D_80072A4C[i];
        }
    }
    if (n != 0) {
        r = func_80071180() / (100 / n);
        r = buf[r > n - 1 ? n - 1 : r];
    }
    return r;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800716EC);

void func_80071DB4(void) {
    Stg40Ent48 *e = D_8005071C->field_18;
    s32 a;
    s32 b;
    s32 i;
    s32 v;

    a = func_8006E858(13);
    a = a < 0 ? 0 : a;
    b = func_8006E858(14);
    b = b < 0 ? 0 : b;
    for (i = 0; i < D_8005071C->field_C; e++, i++) {
        if (e->field_0 & 0x8000) {
            switch (e->field_8) {
            case 6:
            case 8:
                v = D_80072A58[e->field_10[1] - 1 + a * 5];
                if (func_80071180() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                v = D_80072A78[e->field_10[1] - 1 + b * 3];
                if (func_80071180() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            }
        }
    }
}

Stg40Ent48 *func_80071F50(s32 id) {
    Stg40Ent48 *e;
    s32 i;

    for (i = 0, e = D_8005071C->field_18; i < 41; i++, e++) {
        if (e->field_0 & 0x8000) {
            if ((id != 0 && id == e->field_4) || (id == 0 && (e->field_0 & 1))) {
                return e;
            }
        }
    }
    return NULL;
}

void func_80071FBC(s32 *arg) {
    Stg40Ent48 *e;
    Actor *t;
    s32 st;

    st = -1;
    D_80072B60->field_178 = *arg++;
    D_80072B60->field_17C.field_0 = arg[0] - 1;
    D_80072B60->field_17C.field_2 = arg[1] - 1;
    D_80072B60->field_180 = 0;
    D_80072B60->field_184 = NULL;
    e = func_80071F50(D_80072B60->field_178);
    if (e != NULL) {
        t = e->field_14;
        D_80072B60->field_180 = 1;
        switch (D_80072B60->field_17C.field_0) {
        default:
            st = 5;
            break;
        case 0x62:
            if (D_80072B60->field_17C.field_2 == -1) {
                st = 4;
                D_80072B60->field_184 = t;
            } else {
                st = 6;
                D_80072B60->field_180 = 0;
            }
            break;
        case 0x61:
            e->field_E = (D_80072B60->field_17C.field_2 << 12) / 360;
            D_80072B60->field_180 = 0;
            break;
        case 0x60:
            e->field_0 |= 0x200;
            D_80072B60->field_180 = 0;
            break;
        }
        if (st != -1) {
            Task_SetState1(t, (u8)st);
        }
    }
}

void func_800720EC(void) {
    D_80072B60->field_180 = 0;
}

s16 func_800720FC(void) {
    return D_80072B60->field_180;
}

s32 func_80072114(void) {
    return D_80072BC0->stateLevel1;
}

void func_8007212C(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3) {
    Actor *t = D_80072BC0;
    Stg40BC0Work *w = (Stg40BC0Work *)t->work;

    w->field_88 = *blk;
    w->field_A8 = a1;
    w->field_AC = a2;
    w->field_B0 = a3;
    Task_SetState1(t, 1);
}

void func_800721A8(Stg40Cmd *src) {
    Stg40BC0Work *w = (Stg40BC0Work *)D_80072BC0->work;
    s32 i;

    w->field_B4 = w->field_BC;
    w->field_B8 = 0;
    for (i = 0; src->field_0 != 0; i++, src++) {
        w->field_BC[i] = *src;
        w->field_B8++;
    }
}

void func_80072250(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40Cmd *c;

    if (w->field_B8 != 0) {
        c = w->field_B4;
        func_8007212C(&c->field_C, c->field_0, c->field_4, c->field_8);
        w->field_B8--;
        w->field_B4++;
    }
}

#ifdef NORMALIZED
void func_800722B8(Actor *task) {
    Stg40BC0Work *w = (Stg40BC0Work *)task->work;
    s32 dx;
    s32 x0;
    s32 y0;
    s32 z0;

    if (task->stateLevel2 >= w->field_A8) {
        do {
            w->field_0.words[0] = w->field_88.words[4];
            w->field_0.words[1] = w->field_88.words[5];
            w->field_0.words[2] = w->field_88.words[6];
            w->field_7C[1] = (u16)w->field_AC;
            if (w->field_B8 != 0) {
                func_80072250(task);
            } else {
                Task_SetState1(task, 0);
            }
        } while (0);
        return;
    }
    x0 = w->field_88.words[0];
    dx = (x0 - w->field_88.words[4]) / w->field_A8;
    y0 = w->field_88.words[1];
    z0 = w->field_88.words[2];
    w->field_0.words[0] = x0 - dx * task->stateLevel2;
    w->field_0.words[1] = y0 - ((y0 - w->field_88.words[5]) / w->field_A8) * task->stateLevel2;
    w->field_0.words[2] = z0 - ((z0 - w->field_88.words[6]) / w->field_A8) * task->stateLevel2;
    w->field_84 = 1;
    w->field_7C[1] = (u16)w->field_AC + (w->field_B0 / w->field_A8) * (w->field_A8 - task->stateLevel2);
    task->stateLevel2 = task->stateLevel2 + 1;
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800722B8);
void func_800722B8(Actor *task);
#endif

void func_80072418(Actor *a0, Block1C *a1) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;

    D_80072BC0 = a0;
    w->field_0 = *a1;
    w->field_B4 = 0;
    w->field_B8 = 0;
}

void func_80072468(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40RView v;

    switch (a0->stateLevel0) {
    case 0:
    default:
        GsInitCoordinate2(0, &w->field_1C);
        w->field_84 = 1;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->field_B8 != 0) {
                func_80072250(a0);
            }
            break;
        case 1:
            func_800722B8(a0);
            break;
        }
        w->field_84 = 0;
        RotMatrixYXZ(w->field_7C, &w->field_1C.coord);
        w->field_1C.coord.t[0] = w->field_6C;
        w->field_1C.coord.t[1] = w->field_70;
        w->field_1C.coord.t[2] = w->field_74;
        w->field_1C.flg = 0;
        v.field_0[0] = w->field_0.words[0];
        v.field_0[1] = w->field_0.words[1];
        v.field_0[2] = w->field_0.words[2];
        v.field_0[3] = w->field_0.words[3];
        v.field_0[4] = w->field_0.words[4];
        v.field_0[5] = w->field_0.words[5];
        v.field_18 = 0;
        v.field_1C = &w->field_1C;
        GsSetProjection(w->field_0.words[6]);
        GsSetRefView2(&v);
        break;
    case 2:
        break;
    }
}

void func_800725A8(void) {
}
