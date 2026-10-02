#include "common.h"
#include "main/game.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
s32 D_8005075C;
u8 D_80050760;
s32 D_80050764;
MenuCtx *Menu_Ctx;
s32 Ovl_CurrentId;

void Task_Create(u32 id, s32 *slot, s32 arg) {
    TaskDesc *d;
    ActorAllocView *o;

    if (*slot != 0) {
        Task_Destroy(slot);
    }
    d = D_80040D50[id >> 8][id & 0xFF];
    o = Task_AllocWithBuffers(d->workSize, d->auxSize);
    o->id = id;
    o->frameCount = 0;
    if (arg != 0 && d->init != 0) {
        d->init(o, arg);
    }
    *slot = (s32)o;
}

void func_80011140(void) {
    Task_NextState0();
}

void func_80011160(void) {
}

void func_80011168(void) {
}

void Task_DefaultDestroy(Actor *arg0) {
    Task_Free();
}

void Task_ClearList(void) {
    s16 i;
    for (i = 0; i < 100; i++) {
        Task_List.entries[i] = 0;
    }
    Task_List.count = 0;
}

ActorAllocView *Task_Alloc(void) {
    ActorAllocView *s0 = (ActorAllocView *)Mem_Alloc(0x40, 2);
    s32 i;
    Mem_Zero(s0, 0x40);
    for (i = 0; i < 0x64; i++) {
        if (Task_List.entries[i] == 0) {
            Task_List.entries[i] = (s32)s0;
            break;
        }
    }
    if (Task_List.count < i + 1) {
        Task_List.count = i + 1;
    }
    return s0;
}

void Task_Free(arg0)
TaskFreeView *arg0;
{
    ActorModelFreeView *sub;
    s32 i;
    s32 *p;
    s32 j;

    if (arg0->childCount != 0) {
        s32 *fp = arg0->children;
        i = 0;
        if (arg0->childCount > 0) {
            p = fp;
            do {
                Task_Destroy(p);
                p++;
            } while (++i < arg0->childCount);
            fp = arg0->children;
        }
        Mem_Free((ActorWork *)fp);
    }

    if (arg0->work != 0) {
        Mem_Free(arg0->work);
    }
    if (arg0->transform != 0) {
        Mem_Free(arg0->transform);
    }

    sub = arg0->model;
    if (sub != 0) {
        if (sub->screenXY != 0) {
            Mem_Free(sub->screenXY);
        }
        if (sub->vertOtz != 0) {
            Mem_Free(sub->vertOtz);
        }
        i = sub->vertColors != 0;
        if (i) {
            Mem_Free(sub->vertColors);
        }
        if (sub->bones != 0) {
            Mem_Free(sub->bones);
        }
        Mem_Free((ActorWork *)arg0->model);
    }

    for (j = 0; j < 100; j++) {
        if (Task_List.entries[j] == (s32)arg0) {
            Task_List.entries[j] = 0;
            break;
        }
    }

    Mem_Free((ActorWork *)arg0);
}

ActorAllocView *Task_AllocWithBuffers(s32 a0, s32 a1) {
    ActorAllocView *s0 = Task_Alloc();
    if (a0 != 0) {
        s32 x = Mem_Alloc(a0, 2);
        s0->work = x;
        Mem_Zero((void *)x, a0);
    }
    if (a1 != 0) {
        s32 y = Mem_Alloc(a1, 2);
        s0->children = y;
        Mem_Zero((void *)y, a1);
        s0->childCount = a1 >> 2;
    }
    return s0;
}

TaskEntry *Task_FindNext(void) {
    s32 i;
    TaskEntry *e;

    i = Task_FindFilter.nextIndex;
    while (i < Task_List.count) {
        e = (TaskEntry *)Task_List.entries[i];
        if (e != 0
            && (Task_FindFilter.key0 == -1 || e->id == Task_FindFilter.key0)
            && (Task_FindFilter.key1 == -1 || e->field_4 == Task_FindFilter.key1)
            && (Task_FindFilter.key2 == -1 || e->field_8 == Task_FindFilter.key2)) {
            Task_FindFilter.nextIndex = i + 1;
            return (TaskEntry *)Task_List.entries[i];
        }
        i++;
    }
    return 0;
}

extern TaskEntry *Task_FindNext(void);

TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2) {
    Task_FindFilter.key0 = arg0;
    Task_FindFilter.key1 = arg1;
    Task_FindFilter.key2 = arg2;
    Task_FindFilter.nextIndex = 0;
    return Task_FindNext();
}

void Task_NextState0(Actor *arg0) {
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1 = 0;
    arg0->stateLevel0++;
}

void Task_NextState1(Actor *arg0) {
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1++;
}

void Task_NextState2(Actor *arg0) {
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2++;
}

void Task_NextState3(Actor *arg0) {
    arg0->stateLevel4 = 0;
    arg0->stateLevel3++;
}

void Task_NextState4(Actor *arg0) {
    arg0->stateLevel4++;
}

void Task_SetState0(Actor *arg0, u32 arg1) {
    arg0->stateLevel0 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1 = 0;
}

void Task_SetState1(Actor *arg0, u32 arg1) {
    arg0->stateLevel1 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
}

void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2) {
    arg0->stateLevel0 = arg1 & 0xFF;
    arg0->stateLevel1 = arg2 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
}

void Task_SetState2(Actor *arg0, u32 arg1) {
    arg0->stateLevel2 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
}

void Task_SetState3(Actor *arg0, u32 arg1) {
    arg0->stateLevel3 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
}

void Task_SetState4(Actor *arg0, u32 arg1) {
    arg0->stateLevel4 = arg1 & 0xFF;
}

void func_80011644(void) {
    s32 *p;
    s32 i;

    p = D_80050948;
    Cd_QueueFile(0x19A);
    for (i = 0; i < D_8005075C; i++) {
        Cd_QueueFile(*p);
        p++;
    }
}


void func_800116A8(void) {
}

void func_800116B0(Actor *arg0, s32 *arg1) {
    ActorWork *w = arg0->work;
    w->field_0 = arg1[0];
    w->field_4 = arg1[1];
}

void func_800116CC(Actor *a0) {
    Wk116CC *w = (Wk116CC *)a0->work;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
            break;
        case 1:
            return;
        }
        if (w->delay == 0) {
            switch (w->step) {
            case 0:
                v = 0xE;
                goto set;
            case 1:
                v = 0xD;
                goto set;
            case 2:
                v = 0xB;
            set:
                w->hideMask = v;
                w->palette = 0;
                w->delay = 0;
                break;
            default:
                w->hideMask = 7;
                w->delay = 2;
                w->palette = w->step - 3;
                break;
            }
            w->step++;
            if (w->step == 0x12) {
                w->step = 0xF;
            }
        } else {
            w->delay--;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 1:
            w->hideMask = 0xD;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 2:
            w->hideMask = 0xE;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 0:
        default:
            w->hideMask = 0xB;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 3:
            Task_SetState0(a0, 3);
            break;
        }
        break;
    }
}

void func_80011854(Actor *a0) {
    ActorWork *w = a0->work;
    Part11854 *e;
    Part11854 *q;
    GfxVramPos pos;
    GfxVramPos clut;
    GfxImageInfo tex;
    s32 s;
    s32 i;
    s32 j;
    u8 u;
    u8 v;
    SysState *g;
    Ft4_11854 *p;

    e = (Part11854 *)Cd_GetFileEntry(0x3120002);
    for (q = e; q->fileId != 0; q++) {
        if (q->partMask & w->field_C) {
            q->visible = 0;
        } else {
            q->visible = 1;
            q->palette = w->field_14;
            if (w->field_4 != 0) {
                q->scaleX = -0x1000;
                q->unscaled = 0;
            } else {
                q->scaleX = 0x1000;
                q->unscaled = 1;
            }
        }
    }
    Gfx_DrawParts((s32)e);
    Gfx_FindOrLoadImageSlot(w->field_0, &tex, &pos, &clut);
    s = 1;
    if (w->field_4 != 0) {
        s = -1;
    }
    g = &D_8005F770;
    p = (Ft4_11854 *)g->packet.work;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            p->c.rgb = D_8005074C[0];
            p->tag.len = 9;
            p->c.b.code = 0x2C;
            p->x0 = D_80040D70[j][i].field_0 * s;
            p->x1 = D_80040D70[j][i + 1].field_0 * s;
            p->x2 = D_80040D70[j + 1][i].field_0 * s;
            p->x3 = D_80040D70[j + 1][i + 1].field_0 * s;
            p->y0 = D_80040D70[j][i].field_2;
            p->y1 = D_80040D70[j][i + 1].field_2;
            p->y2 = D_80040D70[j + 1][i].field_2;
            p->y3 = D_80040D70[j + 1][i + 1].field_2;
            u = pos.x + (tex.uBase + i * 20);
            p->u0 = p->u2 = u;
            p->u1 = p->u3 = u + 20;
            v = pos.y + j * 20;
            p->v0 = p->v1 = v;
            p->v2 = p->v3 = v + 20;
            p->tpage = tex.tpage;
            p->clut = ((tex.vramY + clut.y) << 6) | (((tex.vramX + clut.x) >> 4) & 0x3F);
            p->tag.addr = ((PTag11854 *)g->otLayers.s[0])->addr;
            ((PTag11854 *)g->otLayers.s[0])->addr = (u32)p;
            p++;
        }
    }
    D_8005F770.packet.addr = (s32)p;
}

void func_80011B58(Actor *arg0, s32 arg1) {
    arg0->work->field_0 = arg1;
}

void Gfx_TexSlotTaskInit(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->stateLevel0 == 0) {
        w->field_0 = Gfx_ReserveTexSlot();
        Task_NextState0(arg0);
    }
}

void Gfx_TexSlotTaskKill(Actor *arg0) {
    Gfx_ReleaseTexSlot(arg0->work->field_0);
    Task_DefaultDestroy(arg0);
}

void Gfx_FindOrLoadImageSlot(s32 id, GfxImageInfo *out, GfxVramPos *pos, GfxVramPos *clut) {
    GfxImageCache *t;
    s32 i;
    s32 k;
    s32 *p;
    RECT r;
    RECT r2;

    t = (GfxImageCache *)Task_FindFirst(10, -1, -1)->work;
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == id) {
            goto found;
        }
    }
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == 0) {
            goto load;
        }
    }
    {
        s32 m = 0;
        s32 bi = 0;
        for (i = 0; i < 18; i++) {
            if (m < t->slot[i].t) {
                m = t->slot[i].t;
                bi = i;
            }
        }
        i = bi;
    }
load:
    for (k = 0; D_80040DAC[k] != -1; k++) {
        if (D_80040DAC[k] == id) {
            break;
        }
    }
    p = (s32 *)Cd_GetFileEntry(k + 0x3250000);
    p++;
    if (*p++ & 8) {
        r.x = t->sheet->vramX + i / 16 * 16;
        r.y = t->sheet->vramY + 0xF0;
        r.y += i % 16;
        r.w = 16;
        r.h = 1;
        LoadImage(&r, ((TimBlkData *)p)->data);
    }
    p = (s32 *)((u8 *)p + *p);
    r2.x = t->sheet->vramX + i % 3 * 10;
    r2.y = t->sheet->vramY + i / 3 * 40;
    r2.w = ((TimBlkData *)p)->w;
    r2.h = ((TimBlkData *)p)->h;
    LoadImage(&r2, ((TimBlkData *)p)->data);
    t->slot[i].id = D_80040DAC[k];
found:
    t->slot[i].t = D_8005F770.vsyncWait;
    *out = *t->sheet;
    pos->x = i % 3 * 40;
    pos->y = i / 3 * 40;
    clut->x = i / 16 * 16;
    clut->y = i % 16 + 0xF0;
}

void func_80011F04(void) {
    s32 i;
    s32 j;
    s32 v;

    i = 0;
    j = i;
    do {
        v = D_8005071C->field_BA9[i];
        D_8005071C->field_BA9[i] = 0;
        if (v != 0) {
            D_8005071C->field_BA9[j++] = v;
        }
        i++;
    } while (i < 12);
}

s32 *Item_GetEffectRec(s32 id) {
    s32 *base = 0;
    u32 i;
    s32 key;

    if ((i = id - 0x78) < 0x10) {
        key = 0x5130000;
    } else if ((i = id - 0xD0) < 0x1A) {
        key = 0x5130001;
    } else if ((i = id - 0x97) < 0xF) {
        key = 0x5130002;
    } else {
        goto end;
    }
    base = (s32 *)Cd_GetFileEntry(key);
    id = i;
end:
    if (base != 0) {
        base = &base[id];
    }
    return base;
}

s32 Item_GetUseKind(s32 arg0) {
    s32 r = 0;
    if (func_8001E134() != 0) {
        u8 *p = Item_GetEffectRec(arg0);
        if (p != 0) {
            u8 b = *p;
            if (b != 0) {
                if (b < 5) {
                    r = 1;
                } else {
                    r = 2;
                }
            }
        }
    }
    return r;
}

s32 func_8001204C(s32 a0, s32 a1, s32 a2, s32 a3) {
    ItemEffect *rec;
    s32 r;
    s16 *p;
    s16 *q;
    u8 v;
    s32 c;
    s32 i;
    s32 j;
    s32 best;
    s32 max;
    s32 n;
    s32 cnt;

    rec = (ItemEffect *)Item_GetEffectRec(a0);
    r = 0;
    switch (rec->effectType) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    default:
        if (rec->effectType == 0) {
            p = &D_80050720->hp;
            q = &D_80050720->maxHp;
        } else {
            p = &D_80050720->mp;
            q = &D_80050720->maxMp;
        }
        if (*p >= *q) {
            return r;
        }
        *p = (*q < *p + rec->amount) ? *q : (s16)(*p + rec->amount);
        r = 1;
        break;
    case 0xB:
        if (func_80022518(a2) < 0) {
            func_8002254C(a2, 0);
            r = 1;
        }
    case 0xC:
    case 0xD:
    case 0xE:
        c = D_8005071C->field_BA5[rec->effectType - 0xC];
        v = c;
        if (c != 0) {
            r = 2;
            if (rec->amount >= v) {
                D_8005071C->field_BA5[rec->effectType - 0xC] = 0;
                r = 1;
            }
        }
        break;
    case 0xF:
        if (D_8005071C->field_BA8 != 0) {
            best = -1;
            max = 0;
            for (j = 0; j < D_8005071C->field_BA8; j++) {
                v = D_8005071C->field_BA9[j];
                if (rec->amount >= v && max < v) {
                    best = j;
                    max = v;
                }
            }
            r = 1;
            if (best == -1) {
                goto none;
            }
            D_8005071C->field_BA8--;
            D_8005071C->field_BA9[best] = 0;
            func_80011F04();
            D_80050760 = max;
            break;
        }
        break;
    case 0x10:
        if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (D_8005071C->field_BA5[i] != 0 && rec->amount >= D_8005071C->field_BA5[i]) {
                    D_8005071C->field_BA5[i] = 0;
                    cnt++;
                }
            }
            n = D_8005071C->field_BA8;
            for (i = 0; i < n; i++) {
                if (rec->amount >= D_8005071C->field_BA9[i]) {
                    D_8005071C->field_BA9[i] = 0;
                    D_8005071C->field_BA8--;
                    cnt++;
                }
            }
            func_80011F04();
            r = 1;
            if (cnt == 0) {
            none:
                r = 2;
            }
        }
        break;
    }
    return r;
}


s32 Item_ApplyToDigi(s32 a0, s32 a1, s32 a2, s32 a3) {
    DigiRosterItemView *o = (DigiRosterItemView *)a3;
    ItemEffect *r = (ItemEffect *)Item_GetEffectRec(a0);
    s16 *cur;
    s16 *lim;
    s16 step;

    if (r->useType == 3 && r->amount != ((s32 (*)(s32))func_8001D934)(o->digiId)) {
        return 0;
    }
    if (r->effectType == 3) {
        if (o->hp != 0) {
            return 0;
        }
        o->hp = o->maxHp;
        return 1;
    }
    if (o->hp == 0) {
        return 0;
    }
    if (r->effectType == 0) {
        cur = &o->hp;
        lim = &o->maxHp;
    } else {
        cur = &o->mp;
        lim = &o->maxMp;
    }
    if (*cur == *lim) {
        return 0;
    }
    if (r->useType == 3) {
        step = *lim - *cur;
    } else {
        step = r->amount;
    }
    *cur = (*lim < *cur + step) ? *lim : (s16)(*cur + step);
    return 1;
}

s32 Item_UseStatBoost(s32 a0, s32 a1, s32 a2, s32 a3) {
    DigiRosterBoostView *dg = (DigiRosterBoostView *)a3;
    ItemStatEffect *rec;
    s16 *p;
    s32 d;
    s32 n;
    s32 inc;

    rec = (ItemStatEffect *)Item_GetEffectRec(a0);
    if (dg->hp == 0) {
        return 0;
    }
    switch (rec->effectType) {
    case 9:
        d = rec->amount;
        if (d > 0 && d + dg->field_E >= 100) {
            return 0;
        }
        if (d < 0 && d + dg->field_E < 0) {
            return 0;
        }
        dg->field_E += rec->amount;
        return 1;
    case 10:
        if (dg->exp == 99999999) {
            return 0;
        }
        d = dg->exp += rec->amount;
        if (d > 99999999) {
            d = 99999999;
        }
        dg->exp = d;
        return 1;
    case 4:
    default:
        p = &dg->maxHp;
        break;
    case 5:
        p = &dg->maxMp;
        break;
    case 6:
        p = &dg->field_1C;
        break;
    case 7:
        p = &dg->field_1E;
        break;
    case 8:
        p = &dg->field_20;
        break;
    }
    if (*p == 999) {
        return 0;
    }
    n = (Rand_Next() & 0xFFF) * 100 / 0x21000;
    inc = 3;
    if (n < 3) {
        inc = n + 1;
    }
    n = inc;
    *p = (*p + n < 1000) ? (s16)(*p + n) : 999;
    return 1;
}


s32 Item_UseRecoverAll(s32 a0, s32 a1) {
    DigiRosterEntry *e = D_80050720->elems;
    ItemRecoverEffect *c = (ItemRecoverEffect *)Item_GetEffectRec(a0);
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x24; i++, e++) {
        s16 cur;
        s16 max;
        if (e->state < 2) continue;
        cur = e->hp;
        if (cur == 0) continue;
        if (c->effectType == 0 || c->effectType == 2) {
            max = e->maxHp;
            if (cur != max) {
                if (c->amount == 0) {
                    e->hp = max;
                } else {
                    e->hp = max < cur + c->amount ? max : e->hp + c->amount;
                }
                n++;
            }
        }
        if ((u8)(c->effectType - 1) < 2) {
            cur = e->mp;
            max = e->maxMp;
            if (cur != max) {
                if (c->amount == 0) {
                    e->mp = max;
                } else {
                    e->mp = max < cur + c->amount ? max : e->mp + c->amount;
                }
                n++;
            }
        }
    }
    return n != 0;
}


s32 Item_Use(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p;
    s32 r;

    p = (u8 *)Item_GetEffectRec(a0);
    r = 0;
    if (p != NULL) {
        switch (*p) {
        case 5:
            r = func_8001204C(a0, a1, a2, a3);
            break;
        case 1:
        case 3:
            r = Item_ApplyToDigi(a0, a1, a2, a3);
            break;
        case 4:
            r = Item_UseStatBoost(a0, a1, a2, a3);
            break;
        case 2:
            r = Item_UseRecoverAll(a0, a1);
            break;
        }
        if (r != 0) {
            Item_RemoveFromBag(a1);
        }
    }
    return r;
}


u8 Menu_NameEntryGetChar(Actor *a0) {
    ActorWork *w;
    s32 base;
    s32 k;
    u8 *p;

    w = a0->work;
    base = w->field_C;
    base += 0x1FD00D4;
    k = w->field_2C >= 10;
    if (w->field_2C >= 5) {
        k++;
    }
    p = (u8 *)Cd_GetFileEntry(base + k);
    return p[w->field_2E * D_80040E38[k] + w->field_2C - D_80040E44[k]];
}


void func_8001291C(Actor *a, Pair1291C *v) {
    ActorWork *w = a->work;

    *(Pair1291C *)w = *v;
    switch (w->field_0) {
    case 0:
    default:
        w->field_8 = 0xD;
        break;
    case 1:
        w->field_8 = 5;
        break;
    case 2:
        w->field_8 = 7;
        break;
    }
}
extern u8 Menu_NameEntryGetChar(Actor *);
extern void Snd_SaveCurrentId(void);
extern void Snd_RestoreSavedId(void);

void Menu_NameEntryTask(Actor *a0) {
    Wk12974 *w = (Wk12974 *)a0->work;
    u8 *p;
    u8 *src;
    s32 i;
    u16 k;
    TextOpenArgs arg;
    TextOpenArgs arg2;

    switch (w->field_0) {
    default:
    case 0:
        p = D_8005E750[w->field_4].name;
        break;
    case 1:
        p = D_8005E634;
        break;
    case 2:
        p = D_8005E6F1;
        break;
    }
    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->field_10, 5);
        for (i = 0; i < w->field_8; i++) {
            p[i] = 0xFD;
        }
        p[i] = 0xFF;
        switch (w->field_0) {
        default:
        case 0:
            src = Digi_GetDefaultName(D_8005E620.elems[w->field_4].digiId);
            for (i = 0; i < 14; i++) {
                if (src[i] == 0xFF) {
                    break;
                }
                p[i] = src[i];
            }
            break;
        case 1:
            p[0] = 0xA;
            p[1] = 0x2E;
            p[2] = 0x2C;
            p[3] = 0x35;
            p[4] = 0x24;
            break;
        case 2:
            p[0] = 0x10;
            p[1] = 0x38;
            p[2] = 0x31;
            p[3] = 0x31;
            p[4] = 0x28;
            p[5] = 0x35;
            break;
        }
        Snd_SaveCurrentId();
        Snd_PlayById(0x22, 1);
        w->field_C = 6;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_Close(&w->field_10);
            Text_Close(&w->field_14);
            Text_Close(&w->field_18);
            Text_Close(&w->field_20);
            arg.text = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D4);
            arg.x = 0x28;
            arg.y = 0x42;
            arg.charAdvance = 0x13;
            arg.bigFont = 1;
            arg.color = 0;
            arg.lineAdvance = 0x12;
            arg.charDelay = 0;
            Text_Open(&w->field_10, &arg);
            arg.text = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D5);
            arg.x += 0x65;
            Text_Open(&w->field_14, &arg);
            arg.text = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D6);
            arg.x += 0x65;
            Text_Open(&w->field_18, &arg);
            arg.x = 0x26;
            arg.text = (s32)p;
            arg.y = 0x20;
            arg.charAdvance = 0;
            arg.lineAdvance = 0;
            arg.charDelay = 0;
            Text_Open(&w->field_20, &arg);
            switch (w->field_0) {
            default:
            case 0:
                arg2.text = (s32)Digi_GetDefaultName(D_8005E620.elems[w->field_4].digiId);
                break;
            case 1:
                arg2.text = (s32)Cd_GetFileEntry(0x1FD0074);
                break;
            L34:
                w->field_2C = 10;
                w->field_2E = 7;
                Snd_PlayById(0x12, 0);
                goto keys_done;
            Lnone:
                Snd_PlayById(0x10, 0);
                goto keys_done;
            case 2:
                arg2.text = (s32)Cd_GetFileEntry(0x1FD0072);
                break;
            }
            arg2.color = 4;
            arg2.x = 0x23;
            arg2.bigFont = 0;
            arg2.y = 0x13;
            arg2.charAdvance = 0;
            arg2.lineAdvance = 0;
            arg2.charDelay = 0;
            Text_Open(&w->field_1C, &arg2);
            Task_NextState1(a0);
        case 1:
            k = D_8005F6F0[0].repeat;
            if (k & 0x2000) {
                if (w->field_2C != 10) {
                    if (++w->field_2C == 10) {
                        w->field_2E = 7;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x8000) {
                if (w->field_2C != 0) {
                    w->field_2C--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x1000) {
                if (w->field_2E != 0) {
                    w->field_2E--;
                    if (w->field_2C == 10) {
                        w->field_2C--;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x4000) {
                if (w->field_2E != 7) {
                    w->field_2E++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].r1 > 0) {
                if (w->field_24 != w->field_8) {
                    w->field_24++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].l1 > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].triangle > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    p[w->field_24] = 0xFD;
                    Snd_PlayById(0xB, 0);
                }
            } else if (D_8005F6F0[0].start > 0) {
                goto L34;
            } else if (D_8005F6F0[0].cross > 0) {
                if (w->field_2C < 10 || w->field_2E < 4) {
                    if (w->field_24 != w->field_8) {
                        p[w->field_24] = Menu_NameEntryGetChar(a0);
                        w->field_24++;
                        Snd_PlayById(0xE, 0);
                    }
                } else if (w->field_2E == 7) {
                    for (i = 0; i < w->field_8; i++) {
                        if (p[i] != 0xFD) {
                            break;
                        }
                    }
                    if (i != w->field_8) {
                        for (i = w->field_8 - 1; i >= 0; i--) {
                            if (p[i] != 0xFD) {
                                break;
                            }
                            p[i] = 0xFF;
                        }
                        Task_NextState0(a0);
                        Snd_PlayById(0xE, 0);
                    } else {
                        goto Lnone;
                    }
                }
            }
        keys_done:
            if (w->field_24 == w->field_8) {
                w->field_2C = 10;
                w->field_2E = 7;
            }
            if (D_8005F6F0[0].repeat & 0xF000) {
                w->field_28 = 0;
            }
            break;
        }
        break;
    case 2:
        if (D_8005F788[0] != 0x500) {
            Snd_RestoreSavedId();
        }
        Text_CloseArray(&w->field_10, 5);
        Task_NextState0(a0);
        break;
    }
}


void Menu_NameEntryDrawParts(Actor *a) {
    ActorWork *w = a->work;
    GfxPart *base = (GfxPart *)Cd_GetFileEntry(0x1A10018);
    GfxPart *p;
    s32 k;
    s32 v;
    s32 x;

    w->field_28 += D_8005F770.frameDelta;
    for (p = base; p->fileId != 0; p++) {
        if (p->groupMask & 0x20) {
            v = w->field_24;
            p->y = -0x48;
            p->x = v * 9 - 0x71;
            if (w->field_24 == w->field_8) {
                p->visible = 0;
            } else {
                p->visible = 1;
            }
        } else if (p->groupMask & 0x40) {
            v = w->field_2C;
            x = -0x73;
            if (v >= 10) {
                x = -0x6D;
            }
            if (v >= 5) {
                x += 6;
            }
            p->x = x + v * 19;
            p->y = w->field_2E * 18 - 0x2F;
        }
        k = 0;
        if (w->field_2C >= 10 && w->field_2E >= 4) {
            k = w->field_2E - 3;
        }
        if (p->groupMask & 0x7DC) {
            p->visible = 0;
        }
        if (!(w->field_28 & 0x10)) {
            switch (k) {
            case 0:
                if (p->groupMask & 0x40) {
                    p->visible = 1;
                }
                break;
            case 1:
                if (p->groupMask & 0x80) {
                    p->visible = 1;
                }
                break;
            case 2:
                if (p->groupMask & 0x100) {
                    p->visible = 1;
                }
                break;
            case 3:
                if (p->groupMask & 0x200) {
                    p->visible = 1;
                }
                break;
            case 4:
                if (p->groupMask & 0x400) {
                    p->visible = 1;
                }
                break;
            }
        }
        if (w->field_0 == 0 && (p->groupMask & 4)) {
            p->visible = 1;
        }
        if (w->field_0 == 1 && (p->groupMask & 8)) {
            p->visible = 1;
        }
        if (w->field_0 == 2 && (p->groupMask & 0x10)) {
            p->visible = 1;
        }
    }
    Gfx_DrawParts((s32)base);
}


/* Ovl_FileIds[id] (Cd file ids, matched by LBA + sector count):
 * 0 STAG0000, 1 STAG4000, 2 STAG2000, 3 STAG1000, 4 STAG3000, 5 STAG1100, 6 STAG3500.
 * Sys_GameModeTask loads id (gameMode >> 8) - 1. */
void Ovl_Load(s32 id) {
    s32 *p;
    u8 *src;
    u8 *dst;

    if (Ovl_CurrentId != id) {
        p = &Ovl_FileIds[id];
        Ovl_CurrentId = id;
        src = (u8 *)Cd_GetFileSync(*p);
        dst = D_80010000[0];
        memcpy(dst, src, Cd_GetFileSectors(*p) << 11);
    }
}

s32 Ovl_GetCurrentId(void) {
    return Ovl_CurrentId;
}


extern void Ovl_Load(s32);
extern void Task_Create(u32, s32 *, s32);
extern s32 Snd_AnySlotLoading(void);

void Sys_GameModeTask(Actor *a0) {
    s32 st = a0->stateLevel0;
    s32 t = a0->u34.children;
    switch (st) {
    case 0:
    default:
        Ovl_Load((D_8005F770.gameMode >> 8) - 1);
        Task_Create(D_8005F770.gameMode & 0xFF00, t, 0);
        Task_NextState0(a0);
        break;
    case 1:
        if (D_8005F770.nextGameMode != 0) {
            Task_SetState0(a0, 2);
        }
        break;
    case 2:
        if (Snd_AnySlotLoading() == 0) {
            Task_SetState0(a0, 3);
        }
        break;
    }
}

void Task_DefaultDestroy2(void) {
    Task_Free();
}

void Text_OpenDesc(void *arg0, TextDesc *arg1) {
    TextOpenArgs local;
    local.text = arg1->text;
    local.bigFont = arg1->packedStyle >> 7;
    local.color = arg1->color;
    local.x = arg1->x;
    local.y = arg1->y;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = arg1->packedStyle & 0x7F;
    local.strArg0 = arg1->strArg0;
    local.strArg1 = arg1->strArg1;
    Text_Open(arg0, &local);
}

void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3) {
    TextOpenArgs local;
    local.bigFont = (arg2 >> 7) & 1;
    local.text = arg1;
    local.color = (arg2 >> 2) & 0xF;
    local.x = arg3.lo;
    local.y = arg3.hi;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = arg2 & 3;
    Text_Open(arg0, &local);
}

s32 Text_PrintIdList(s32 *a0, TextIdListEntry *a1, u32 a2) {
    s32 n = 0;

    while (a1->key != 0) {
        n++;
        Text_OpenPacked(a0, (s32)Cd_GetFileEntry((a1->key & 0xFFF) | 0x1FD0000),
                      a2 | ((a1->key & 0xF000) >> 10), a1->h);
        a1++;
        a0++;
    }
    return n;
}

void Text_PrintList(s32 *a0, Halves *a1, s32 *a2, u32 a3) {
    while (*a2 != 0) {
        Text_OpenPacked(a0, *a2, a3, *a1);
        a2++;
        a1++;
        a0++;
    }
}

s32 func_800136A4() {
    s32 result = Text_IsFinished();
    if (result != 0) {
        result = Flag_Test(0x11) == 0 ? 1 : -1;
    }
    return result;
}

s32 Math_RampToOne(s32 arg0, s32 *arg1) {
    s32 v = *arg1 + 0x333;
    *arg1 = v;
    if (v >= 0x1000) {
        *arg1 = 0x1000;
        return 0;
    }
    return 1;
}

s32 Math_RampToZero(s32 arg0, s32 *arg1) {
    s32 v = *arg1 - 0x333;
    *arg1 = v;
    if (v <= 0) {
        *arg1 = 0;
        return 0;
    }
    return 1;
}

void Menu_SetPartsGridPos(void *arg0, s32 mask, s32 *arg2, s16 *arg3) {
    GfxPart *p = arg0;
    GfxPart *q = p;
    s32 x = arg3[2] + ((s16 *)arg2)[0] * arg3[4];
    s32 y = arg3[3] + ((s16 *)arg2)[1] * arg3[5];

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = x;
                q->y = y;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}


void Gfx_SetPartsPalette(GfxPart *p, s32 mask, s32 v) {
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->palette = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Menu_SetPartsPos(GfxPart *p, s32 mask, u16 *xy) {
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = xy[0];
                q->y = xy[1];
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

s32 Menu_BlinkOrHideParts(GfxPart *p, s32 mask, s32 n) {
    GfxPart *q;
    s32 r = 0;

    if (n <= 0) {
        r = mask;
    } else {
        q = p;
        if (p->fileId != 0) {
            do {
                if (q->groupMask & mask) {
                    q->palette = (Menu_Ctx->elapsed >> 2) & 3;
                }
                p++;
                q++;
            } while (p->fileId != 0);
        }
    }
    return r;
}

s32 Menu_MoveGridCursor(s32 a0, s32 a1, s32 a2) {
    Coord138C0 *p0 = (Coord138C0 *)a0;
    Coord138C0 *p1 = (Coord138C0 *)a1;
    Copy138C0 saved;
    s32 changed;

    changed = 0;
    saved = *(Copy138C0 *)p0;

    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x8000) {
        if (p0->field_0 > 0) {
            p0->field_0 = p0->field_0 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x2000) {
        if (p0->field_0 < p1->field_0 - 1) {
            p0->field_0 = p0->field_0 + 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x1000) {
        if (p0->field_2 > 0) {
            p0->field_2 = p0->field_2 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x4000) {
        if (p0->field_2 < p1->field_2 - 1) {
            p0->field_2 = p0->field_2 + 1;
        }
    }

tail:
    if (saved.h[0] != p0->field_0 || saved.h[1] != p0->field_2) {
        changed = -1;
    }
    return changed;
}

s32 Menu_MoveGridCursorP1(s32 arg0, s32 arg1) {
    return Menu_MoveGridCursor(arg0, arg1, 0);
}

s32 Menu_ScrollToShow(s32 *arg0, s32 arg1, s32 arg2) {
    s32 old = *arg0;

    if (arg2 - 1 < arg1 - old) {
        *arg0 = arg1 - (arg2 - 1);
    } else if (arg1 < old) {
        *arg0 = arg1;
    }
    return *arg0 - old;
}

s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1) {
    return arg1[1] * arg0[0] + arg0[1];
}

s32 Menu_GridIndexRowMajor(s16 *arg0, s16 *arg1) {
    return arg1[0] * arg0[1] + arg0[0];
}

s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)Cd_GetFileEntry(arg0);
    s32 r = Cd_GetFileOrNull(arg0 >> 16);
    return p[arg1] + r;
}

void Text_FormatNumber(u8 *out, s32 val, s32 width) {
    u8 buf[8];
    s32 sign = 0;
    s32 done = 0;
    s32 i;

    if (width < 0) {
        width = -width;
        sign = 1;
    }
    if (val > 99999999) {
        val = 99999999;
    }
    for (i = 0; i < width; i++) {
        u8 *p = &buf[i];
        if (!done) {
            *p = val % 10;
        } else {
            *p = 0xFD;
        }
        val = val / 10;
        done = (val == 0);
    }
    for (i = width - 1; i >= 0; i--) {
        if (sign && buf[i] == 0xFD) {
            continue;
        }
        *out++ = buf[i];
    }
    *out = 0xFF;
}

void func_80013BF8(Actor *arg0, s16 arg1) {
    arg0->work->field_30 = arg1;
}

void Menu_TopMenuTask(Actor *a0) {
    MenuTopWork *w = (MenuTopWork *)a0->work;
    s32 *slot = (s32 *)a0->u34.children;
    Pair54 *tbl;
    s32 v;
    s32 k;
    s32 snd;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Menu_Ctx = (MenuCtx *)Mem_Alloc(0x364, 2);
        Menu_Ctx->field_360 = 0;
        D_80050764 = 0;
        *(Layout8C *)w->gridSize = *(Layout8C *)Cd_GetFileEntry(0x5130005);
        Menu_Ctx->flags = 0;
        v = D_8005F788[0];
        if (v / 256 != 2) {
            switch (v) {
            default:
                Menu_Ctx->flags = 2;
                break;
            case 0x32D ... 0x32E:
                Menu_Ctx->flags = 6;
                break;
            case 0x32A ... 0x32C:
                Menu_Ctx->flags = 4;
                break;
            }
        } else {
            Menu_Ctx->flags = 1;
            if (Flag_Test(0x67) == 0) {
                Menu_Ctx->flags |= 8;
            }
        }
        if (Digi_CountByState(0) == 0x24) {
            Menu_Ctx->flags = (Menu_Ctx->flags | 0x10) & ~2;
        }
        Menu_Ctx->elapsed = 0;
        Mem_FillWordsNeg1(&w->option0Text, 8);
        Task_NextState0(a0);
        Gfx_FadeInFromBlack(0x20);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntry(0x5130006);
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList(&w->option0Text, (TextIdListEntry *)Cd_GetFileEntry(0x5130003), 2);
            Text_Close((Menu_Ctx->flags & 1) ? &w->option5Text : &w->option6Text);
            Text_SetColor(w->option1Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option2Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option3Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option4Text, !(Menu_Ctx->flags & 2));
            Text_SetColor(w->option5Text, !(Menu_Ctx->flags & 4));
            Text_SetColor(w->option6Text, !(Menu_Ctx->flags & 8));
            Task_NextState1(a0);
            break;
        case 1:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->gridSize) != 0) {
                snd = 0xC;
            } else if (D_8005F6F0[0].cross > 0) {
                k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
                if (k == 5 && (Menu_Ctx->flags & 1)) {
                    k = 6;
                }
                if ((u32)(k - 1) < 3 && (Menu_Ctx->flags & 0x10)) {
                    snd = 0x10;
                } else if (k == 4 && !(Menu_Ctx->flags & 2)) {
                    snd = 0x10;
                } else if (k == 5 && !(Menu_Ctx->flags & 4)) {
                    snd = 0x10;
                } else if (k == 6 && !(Menu_Ctx->flags & 8)) {
                    snd = 0x10;
                } else if (k == 5) {
                    Menu_Ctx->field_360 = 1;
                    Task_SetState0(a0, 2);
                    snd = 0xA;
                } else {
                    w->selection = k;
                    Task_NextState1(a0);
                    snd = 0xA;
                }
            } else {
                if (D_8005F6F0[0].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(a0, 2);
                }
                break;
            }
            Snd_PlayById(snd, 0);
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(&w->option0Text, 8);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->ramp) == 0) {
                    Task_NextState1(a0);
                }
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Task_Create(tbl[w->selection].field_0, slot, tbl[w->selection].field_2);
                Task_NextState2(a0);
                break;
            case 1:
                if (*slot == 0) {
                    if (Menu_Ctx->field_360 != 0) {
                        Task_SetState0(a0, 2);
                    } else {
                        Task_SetState1(a0, 0);
                    }
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->option0Text, 8);
            D_80050764 = Menu_Ctx->field_360;
            Task_NextState1(a0);
            Gfx_FadeOutToBlack(0x20);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->ramp) == 0) {
                Task_SetState0(a0, 3);
                Mem_Free((ActorWork *)Menu_Ctx);
            }
            break;
        }
        break;
    }
    if (Menu_Ctx != NULL) {
        Menu_Ctx->elapsed = a0->elapsed;
    }
}


void Menu_TopMenuDraw(Actor *actor) {
    MenuTopDrawWork *w = (MenuTopDrawWork *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    GfxPart *base;
    GfxPart *q;
    GfxPart *r;

    if (w->ramp != 0) {
        p = (s32 *)Cd_GetFileEntry(0x5130004);
        if (*p != 0) {
            i = 0;
            list = p;
            do {
                obj = Cd_GetFileEntry(*list);
                switch (i) {
                case 0:
                default:
                    Menu_SetPartsGridPos(obj, 2, &w->cursor, &w->gridSize);
                    Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
                    break;
                case 1:
                    Gfx_SetPartsNumber(obj, 2, 8, D_80050720->field_8);
                    break;
                }
                Gfx_SetPartsScale(obj, 0x1000, w->ramp);
                list++;
                Gfx_DrawParts((s32)obj);
                i++;
            } while (*list != 0);
        }
    }
    base = (GfxPart *)Cd_GetFileEntry(0x459000C);
    for (q = base; q->fileId != 0; q++) {
        switch (q->groupMask) {
        case 2:
            q->palette = Math_CycleRange(actor->elapsed, 0xA, 0, 7);
            break;
        case 8:
            q->x -= 2;
            if (q->x == -0x168) {
                q->x = 0;
            }
            break;
        case 0x10:
            q->x += 1;
            if (q->x == 0xD8) {
                q->x = 0;
            }
            break;
        case 0x20:
            q->x -= 2;
            if (q->x == -0x1C0) {
                q->x = 0;
            }
            break;
        }
    }
    Gfx_DrawParts((s32)base);
}
