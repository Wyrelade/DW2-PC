#include "common.h"
#include "main/game.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
s32 Cd_PreloadCount;
u8 Bug_LastZappedLevel;

/* Task callbacks the descriptors below name (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Text_PortraitInit(Actor *arg0, s32 *arg1);
void Text_PortraitTask(Actor *a0);
void Text_PortraitDraw(Actor *a0);
void Gfx_TexSlotTaskInit(Actor *arg0);
void Gfx_TexSlotTaskKill(Actor *arg0);

/* Portrait quad mesh: 3x3 grid points (x scaled by the portrait width, y). */
Pair54 Text_PortraitQuadGrid[3][3] = {
    { { 0x2E, -90 }, { 0x51, -96 }, { 0x79, -103 } },
    { { 0x3A, -55 }, { 0x5C, -56 }, { 0x87, -57 } },
    { { 0x44, -26 }, { 0x65, -21 }, { 0x95, -13 } },
};
TaskDesc D_80040D94 = {
    (TaskInitFn)Text_PortraitInit, Text_PortraitTask, Task_DefaultDestroy, Text_PortraitDraw, 0x18, 0,
};
/* Image ids Gfx_FindOrLoadImageSlot keeps in the face texture slots, -1 ends the list. */
s16 Gfx_FaceImageIds[] = {
    0x003, 0x014, 0x01F, 0x02D, 0x02E, 0x030, 0x075, 0x07C, 0x095, 0x096, 0x097, 0x0D9,
    0x0F7, 0x0F9, 0x0FA, 0x0FB, 0x0FE, 0x194, 0x195, 0x196, 0x197, 0x198, 0x199, 0x19E,
    0x19F, 0x1A2, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1A8, 0x1A9, 0x1AA, 0x1AB, 0x1AC,
    0x1AD, 0x1AE, 0x1AF, 0x1B0, 0x1B1, 0x1B2, 0x1B3, 0x1B4, 0x1B5, 0x1B6, 0x1B7, 0x1B8,
    0x1BC, 0x1BD, 0x1C2, 0x1F4, 0x212, 0x192, 0x191, 0x190, -1,
};
TaskDesc D_80040E20 = { 0, Gfx_TexSlotTaskInit, Gfx_TexSlotTaskKill, 0, 0x94, 0 };

void Task_Create(u32 id, s32 *slot, s32 arg) {
    TaskDesc *d;
    ActorAllocView *o;

    if (*slot != 0) {
        Task_Destroy(slot);
    }
    d = Task_DescTable[id >> 8][id & 0xFF];
    o = Task_AllocWithBuffers(d->workSize, d->auxSize);
    o->id = id;
    o->frameCount = 0;
    if (arg != 0 && d->init != 0) {
        d->init(o, arg);
    }
    *slot = (s32)o;
}

/* Unnamed: calls Task_NextState0() with no argument, no callers, no table ref (dead). */
void func_80011140(void) {
    Task_NextState0();
}

/* Unnamed: empty stub, no callers, no table ref. */
void func_80011160(void) {
}

/* Unnamed: empty stub, no callers, no table ref. */
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
        do {
            e = (TaskEntry *)Task_List.entries[i];
            if (e != 0) {
                if (Task_FindFilter.key0 != -1) {
                    if (e->id != Task_FindFilter.key0) break;
                }
                if (Task_FindFilter.key1 != -1) {
                    if (e->field_4 != Task_FindFilter.key1) break;
                }
                if (Task_FindFilter.key2 != -1) {
                    if (e->param != Task_FindFilter.key2) break;
                }
                Task_FindFilter.nextIndex = i + 1;
                return (TaskEntry *)Task_List.entries[i];
            }
        } while (0);
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

void Cd_QueueStag4000Files(void) {
    s32 *p;
    s32 i;

    p = Cd_PreloadIds;
    Cd_QueueFile(0x19A);
    for (i = 0; i < Cd_PreloadCount; i++) {
        Cd_QueueFile(*p);
        p++;
    }
}


/* Unnamed: empty stub, no callers, no table ref. */
void func_800116A8(void) {
}

void Text_PortraitInit(Actor *arg0, s32 *arg1) {
    ActorWork *w = arg0->work;
    w->field_0 = arg1[0];
    w->field_4 = arg1[1];
}

void Text_PortraitTask(Actor *a0) {
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

void Text_PortraitDraw(Actor *a0) {
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

    p = (Ft4_11854 *)Sys_State.packet.work;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            p->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
            p->tag.len = 9;
            p->c.code = 0x2C;
            p->x0 = Text_PortraitQuadGrid[j][i].field_0 * s;
            p->x1 = Text_PortraitQuadGrid[j][i + 1].field_0 * s;
            p->x2 = Text_PortraitQuadGrid[j + 1][i].field_0 * s;
            p->x3 = Text_PortraitQuadGrid[j + 1][i + 1].field_0 * s;
            p->y0 = Text_PortraitQuadGrid[j][i].field_2;
            p->y1 = Text_PortraitQuadGrid[j][i + 1].field_2;
            p->y2 = Text_PortraitQuadGrid[j + 1][i].field_2;
            p->y3 = Text_PortraitQuadGrid[j + 1][i + 1].field_2;
            u = pos.x + (tex.uBase + i * 20);
            p->u0 = p->u2 = u;
            p->u1 = p->u3 = u + 20;
            v = pos.y + j * 20;
            p->v0 = p->v1 = v;
            p->v2 = p->v3 = v + 20;
            p->tpage = tex.tpage;
            p->clut = ((tex.vramY + clut.y) << 6) | (((tex.vramX + clut.x) >> 4) & 0x3F);
            p->tag.addr = ((PTag11854 *)Sys_State.otLayers.s[0])->addr;
            ((PTag11854 *)Sys_State.otLayers.s[0])->addr = (u32)p;
            p++;
        }
    }
    Sys_State.packet.addr = (s32)p;
}

void Text_PortraitSetImage(Actor *arg0, s32 arg1) {
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
    for (k = 0; Gfx_FaceImageIds[k] != -1; k++) {
        if (Gfx_FaceImageIds[k] == id) {
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
    t->slot[i].id = Gfx_FaceImageIds[k];
found:
    t->slot[i].t = Sys_State.vsyncWait;
    *out = *t->sheet;
    pos->x = i % 3 * 40;
    pos->y = i / 3 * 40;
    clut->x = i / 16 * 16;
    clut->y = i % 16 + 0xF0;
}

void Bug_CompactMemBugs(void) {
    s32 i;
    s32 j;
    s32 v;

    i = 0;
    j = i;
    do {
        v = Dung_StatePtr->memBugLevels[i];
        Dung_StatePtr->memBugLevels[i] = 0;
        if (v != 0) {
            Dung_StatePtr->memBugLevels[j++] = v;
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
/* Unnamed: ITEMDATA word0 bits 30-31, gates Item_GetUseKind; set/clear pattern across items
 * (disks/chips set, antidotes/gifts/parts clear) does not prove "usable". */
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

s32 Item_UseOnBeetle(s32 a0, s32 a1, s32 a2, s32 a3) {
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
    s32 k;
    DungState *b;

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
            p = &Save_GameStatePtr->hp;
            q = &Save_GameStatePtr->maxHp;
        } else {
            p = &Save_GameStatePtr->mp;
            q = &Save_GameStatePtr->maxMp;
        }
        if (*p >= *q) {
            return r;
        }
        *p = (*q < *p + rec->amount) ? *q : (s16)(*p + rec->amount);
        r = 1;
        break;
    case 0xB:
        if (Beetle_GetPart(a2) < 0) {
            Beetle_SetPartBroken(a2, 0);
            r = 1;
        }
    case 0xC:
    case 0xD:
    case 0xE:
        k = rec->effectType - 0xC;
        b = Dung_StatePtr;
        c = b->bugLevels[k];
        v = c;
        if (c != 0) {
            r = 2;
            if (rec->amount >= v) {
                b->bugLevels[k] = 0;
                r = 1;
            }
        }
        break;
    case 0xF:
        if (Dung_StatePtr->memBugCount != 0) {
            best = -1;
            max = 0;
            for (j = 0; j < Dung_StatePtr->memBugCount; j++) {
                v = Dung_StatePtr->memBugLevels[j];
                if (rec->amount >= v && max < v) {
                    best = j;
                    max = v;
                }
            }
            r = 1;
            if (best == -1) {
                goto none;
            }
            Dung_StatePtr->memBugCount--;
            Dung_StatePtr->memBugLevels[best] = 0;
            Bug_CompactMemBugs();
            Bug_LastZappedLevel = max;
            break;
        }
        break;
    case 0x10:
        if (Dung_StatePtr->bugLevels[0] + Dung_StatePtr->bugLevels[1] + Dung_StatePtr->bugLevels[2] + Dung_StatePtr->memBugCount != 0) {
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (Dung_StatePtr->bugLevels[i] != 0 && rec->amount >= Dung_StatePtr->bugLevels[i]) {
                    Dung_StatePtr->bugLevels[i] = 0;
                    cnt++;
                }
            }
            n = Dung_StatePtr->memBugCount;
            for (i = 0; i < n; i++) {
                if (rec->amount >= Dung_StatePtr->memBugLevels[i]) {
                    Dung_StatePtr->memBugLevels[i] = 0;
                    b = Dung_StatePtr;
                    b->memBugCount--;
                    cnt++;
                }
            }
            Bug_CompactMemBugs();
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

    if (r->useType == 3 && r->amount != ((s32 (*)(s32))Digi_GetType)(o->digiId)) {
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
        if (d > 0 && d + dg->dp >= 100) {
            return 0;
        }
        if (d < 0 && d + dg->dp < 0) {
            return 0;
        }
        dg->dp += rec->amount;
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
        p = &dg->attack;
        break;
    case 7:
        p = &dg->defense;
        break;
    case 8:
        p = &dg->speed;
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
    DigiRosterEntry *e = Save_GameStatePtr->elems;
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
            s32 m;

            max = m = e->maxHp;
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
            r = Item_UseOnBeetle(a0, a1, a2, a3);
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
