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

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063360);
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063A34);

void func_80063EF8(void) {
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063384);
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

INCLUDE_RODATA("asm/USA/stag4000/rodata", jtbl_80063398);
INCLUDE_RODATA("asm/USA/stag4000/rodata", jtbl_800633B0);
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

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_800633C4);
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064BD8);
