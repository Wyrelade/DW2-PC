#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/stag3500_funcs.h"

void Stg35_BattleDestroy(Actor *arg0) {
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(arg0);
}

void Stg35_TextAlloc(Stg35TextHandle *arg0) {
    Stg35TextObj *p = (Stg35TextObj *)Mem_Alloc(0x1C, 2);

    arg0->text = p;
    Mem_Zero(p, 0x1C);
    arg0->text->field_0 = -1;
}

void Stg35_TextFree(Stg35TextHandle *arg0) {
    if (arg0->text != NULL) {
        Text_Close(arg0->text);
        Mem_Free(arg0->text);
        arg0->text = NULL;
    }
}

void Stg35_TextSetLayout(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->text->field_8 = arg1 >> 8;
    arg0->text->field_C = 0;
    arg0->text->field_10 = arg2;
    arg0->text->field_14 = arg3;
    arg0->text->field_18 = arg1 & 0xFF;
}

void Stg35_TextSetString(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->mode = arg1;
}

void Stg35_TextSetColor(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->u.field_C = arg1;
}

void Stg35_TextSetSysMsg(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
}

void Stg35_TextSetSkillName(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = Skill_GetNameText(arg1);
}

void Stg35_TextOpen(Stg35TextHandle *arg0) {
    Stg35TextObj *t = arg0->text;
    TextOpenArgs a;

    a.text = t->field_4;
    a.bigFont = t->field_8;
    a.color = t->field_C;
    a.x = t->field_10;
    a.y = t->field_14;
    a.charAdvance = 0;
    a.lineAdvance = 0;
    a.charDelay = t->field_18;
    Text_Open(t, &a);
}

void Stg35_TextClose(Stg35TextHandle *arg0) {
    Text_Close(arg0->text);
}

void Stg35_RectAlloc(Stg35SpriteHandle *arg0) {
    arg0->sprite = (Stg35Sprite *)Mem_Alloc(0x20, 2);
    Mem_Zero(arg0->sprite, 0x20);
}

void Stg35_RectFree(Stg35SpriteHandle *arg0) {
    if (arg0->sprite != NULL) {
        Mem_Free(arg0->sprite);
        arg0->sprite = NULL;
    }
}

void Stg35_RectDraw(Stg35SpriteHandle *arg0) {
    Stg35Sprite *s = arg0->sprite;
    SysState *g;
    Stg35PolyG4 *p;
    u32 *ot;

    if (s->field_1C != 0 && s->field_1E != 0) {
        g = &Sys_State;
        p = (Stg35PolyG4 *)g->packet.work;
        ot = g->otLayers.u[s->field_0];
        p->c0 = s->field_4[0];
        p->c1 = s->field_4[1];
        p->c2 = s->field_4[2];
        p->c3 = s->field_4[3];
        p->tag.b.len = 8;
        p->c0.code = 0x38;
        if (s->field_14 != 0) {
            p->c0.code = 0x3A;
        }
        p->x0 = p->x2 = s->field_18;
        p->x1 = p->x3 = s->field_18 + s->field_1C;
        p->y0 = p->y1 = s->field_1A;
        p->y2 = p->y3 = s->field_1A + s->field_1E;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        p++;
        if (s->field_14 != 0) {
            SetDrawMode((Stg35DrMode *)p, 0, 0, (s->field_16 & 3) << 5, 0);
            ((Stg35DrMode *)p)->tag = (((Stg35DrMode *)p)->tag & 0xFF000000) | (*ot & 0xFFFFFF);
            *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
            p = (Stg35PolyG4 *)((Stg35DrMode *)p + 1);
        }
        g->packet.work = (ActorWork *)p;
    }
}

void Stg35_RectSetDrawMode(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3) {
    Stg35Sprite *s = arg0->sprite;
    s->field_0 = arg1;
    s->field_14 = arg2;
    s->field_16 = arg3;
}

void Stg35_RectSetColor(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_4[arg1].r = arg2;
    s->field_4[arg1].g = arg3;
    s->field_4[arg1].b = arg4;
}

void Stg35_RectSetWidth(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1C = arg1;
}

void Stg35_RectSetHeight(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1E = arg1;
}

void Stg35_RectSetX(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_18 = arg1;
}

void Stg35_RectSetY(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1A = arg1;
}

void Stg35_RectSetBounds(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_18 = arg1;
    s->field_1A = arg2;
    s->field_1C = arg3;
    s->field_1E = arg4;
}

s32 Stg35_ScaleBarLen(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;

    if (arg2 >= arg1) {
        return arg0;
    }
    r = arg0 * arg2 / arg1;
    if (arg2 != 0 && r == 0) {
        r = 1;
    }
    if (r == arg1 && r != arg2) {
        r--;
    }
    return r;
}

s32 Stg35_ApplySkillDamage(s32 arg0, s32 arg1, s32 arg2) {
    Stg35Rec5C *rec0 = &D_8006AA98[arg0];
    Stg35Rec5C *rec1 = &D_8006AA98[arg1];
    s32 a;
    s32 b;
    s32 prod;
    s32 c;
    s32 d;
    s32 num;
    s32 idx;
    s32 denom;
    s32 result;

    b = Skill_GetPower(arg2);
    a = rec0->field_1C;
    Skill_GetSpecialty(arg2);
    c = rec1->field_1E;
    idx = Stg35_HudPeekGaugeLevel(arg1 >= 3);
    d = Stg35_GaugeDefPercent[idx];
    num = a * b;
    prod = c * d;
    c = prod / 100;
    denom = c * 2;
    result = num / denom;
    if (result < rec1->hp) {
        rec1->hp = rec1->hp - result;
    } else {
        rec1->hp = 0;
    }
    return result;
}

void Stg35_TurnOrderClear(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        Stg35_TurnOrder[i] = v;
    }
}

void Stg35_TurnOrderInsert(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 10; i >= arg0; i--) {
        Stg35_TurnOrder[i + 1] = Stg35_TurnOrder[i];
    }
    Stg35_TurnOrder[arg0] = arg1;
}

void Stg35_TurnOrderRemove(s32 arg0) {
    for (; arg0 < 11; arg0++) {
        Stg35_TurnOrder[arg0] = Stg35_TurnOrder[arg0 + 1];
    }
}

s32 Stg35_TurnOrderFind(s32 arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (arg0 == Stg35_TurnOrder[i]) {
            return i;
        }
    }
    return -1;
}

s32 Stg35_TurnOrderFreeIndex(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (Stg35_TurnOrder[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 Stg35_TurnOrderGet(s32 arg0) {
    return Stg35_TurnOrder[arg0];
}

void Stg35_BuildTurnOrder(void) {
    s32 v[6];
    s32 i;
    s32 j;
    s32 best;
    s32 max;

    for (i = 0; i < 6; i++) {
        if (Stg35_Battle.rec[i].hp != 0) {
            v[i] = Stg35_Battle.rec[i].field_20 + (u16)((u16)Rand_Next() % 11);
        } else {
            v[i] = 0;
        }
    }
    Stg35_TurnOrderClear();
    for (i = 0; i < 6; i++) {
        max = 0;
        best = 0;
        for (j = 0; j < 6; j++) {
            if (v[j] != 0 && max < v[j]) {
                max = v[j];
                best = j;
            }
        }
        if (max == 0) {
            break;
        }
        Stg35_TurnOrderInsert(Stg35_TurnOrderFreeIndex(), best);
        v[best] = 0;
    }
}

void Stg35_SetChosenAction(s32 arg0, s32 arg1) {
    Stg35Rec2C *b = &Stg35_Battle.field_238[arg0];
    s32 t;
    s32 base;
    s32 n;

    b->field_0 = 1;
    b->field_8 = b->field_C[arg1];
    switch (b->field_12[arg1]) {
    case 0:
    default:
        t = Stg35_DefaultTargets[arg0];
        if (Stg35_Battle.rec[t].hp != 0) {
            b->field_4 = t;
            break;
        }
    case 1:
        if (arg0 < 3) {
            base = 3;
        } else {
            base = 0;
        }
        for (n = 0; n < 100; n++) {
            t = (u16)((u16)Rand_Next() % 3) + base;
            if (Stg35_Battle.rec[t].hp != 0) {
                break;
            }
        }
        if (n == 100) {
            t = arg0;
        }
        b->field_4 = t;
        break;
    case 2:
        if (arg0 < 3) {
            b->field_4 = 8;
        } else {
            b->field_4 = 7;
        }
        break;
    }
}

void Stg35_PartsAlloc(Stg35LoadHandle *arg0) {
    Stg35Load *p = (Stg35Load *)Mem_Alloc(0x24, 2);

    arg0->load = p;
    Mem_Zero(p, 0x24);
    arg0->load->field_8 = 0x1000;
}

void Stg35_PartsFree(Stg35LoadHandle *arg0) {
    if (arg0->load != NULL) {
        Mem_Free(arg0->load);
        arg0->load = NULL;
    }
}

void Stg35_PartsSetFile(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->fileId = arg1;
}

void Stg35_PartsDraw(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    Stg35Part *p = (Stg35Part *)Cd_GetFileEntry(l->fileId);
    Stg35Part *q;
    Stg35Part *r;
    Stg35Slide *s;
    s32 f;
    s32 c;
    s16 t;
    s32 k;

    switch (l->mode) {
    case 1:
        l->field_8 += 0x200;
        f = l->field_8 >= 0x1000;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->field_E = f;
                r->field_14 = l->field_8;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (f) {
            l->mode = 0;
        }
        break;
    case 2:
        l->field_8 -= 0x200;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->field_E = 0;
                r->field_14 = l->field_8;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (l->field_8 == 0) {
            l->mode = 0;
        }
        break;
    }
    for (k = 0; k < 2; k++) {
        if (l->u.slide[k].active != 0) {
            q = p;
            if (q->fileId != 0) {
                r = q;
                do {
                    if (r->groupMask & l->u.slide[k].mask) {
                        if (l->u.slide[k].dir != 0) {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x += (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = l->u.slide[k].target > r->x;
                        } else {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x -= (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = r->x > l->u.slide[k].target;
                        }
                        t = l->u.slide[k].target;
                        if (!c) {
                            r->x = t;
                            l->u.slide[k].active = 0;
                        }
                    }
                    q++;
                    r++;
                } while (q->fileId != 0);
            }
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg35_PartsHideByMask(Stg35LoadHandle *arg0, s32 arg1) {
    Gfx_HidePartsByMask((GfxPartMaskView *)Cd_GetFileEntry(arg0->load->fileId), arg1);
}

void Stg35_PartsShowGroup(Stg35LoadHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 1;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsHideGroup(Stg35LoadHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 0;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsStartOpen(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 1;
    l->field_8 = 0;
}

void Stg35_PartsStartScaleOut(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 2;
    l->field_8 = 0x1000;
}

void Stg35_PartsSetPalette(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
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

void Stg35_PartsSetX(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsSetY(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->y = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsStartSlideX(Stg35LoadHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed) {
    Stg35Load *l = arg0->load;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(l->fileId);
    GfxPart *q;

    l->u.slide[idx].mask = mask;
    l->u.slide[idx].active = 1;
    l->u.slide[idx].target = target;
    if (speed < 0) {
        l->u.slide[idx].dir = 0;
        l->u.slide[idx].speed = -speed;
    } else {
        l->u.slide[idx].dir = 1;
        l->u.slide[idx].speed = speed;
    }
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsSetNumber(Stg35LoadHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_SetPartsNumber((GfxPart *)Cd_GetFileEntry(arg0->load->fileId), arg1, arg2, arg3);
}

void Stg35_FighterSetAnim(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;

    if (w->field_34 != arg1) {
        w->field_34 = arg1;
        Anim_SetModelAnim(arg0, arg1);
    }
}

void Stg35_FighterInit(Actor *arg0, Stg35Vec3 *arg1) {
    s32 i = arg1->field_4;
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 n;

    arg0->param = i;
    arg0->digiId = Stg35_Battle.rec[i].digiId;
    w->field_14 = Digi_GetModelFile(arg0->digiId);
    if (arg0->param < 3) {
        w->field_10 = 0x800;
    } else {
        w->field_10 = 0;
    }
    n = arg0->param;
    w->field_8 = 0;
    w->field_4 = (n % 3) * 0xA00 - 0xA00;
    w->field_C = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = arg1->field_8;
}

void Stg35_SpawnSkillCastFx(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    Row6 ofs[3];
    Row6 *o;
    s32 i;

    Skill_GetFxSet(w->field_2C, 0, a, b);
    Digi_GetCastFxOffsets(arg0->digiId, ofs);
    o = &ofs[arg1];
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
                args.field_C -= o->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += o->data[0];
                    args.field_10 -= 0x100 + o->data[2];
                } else {
                    args.field_8 -= o->data[0];
                    args.field_10 += 0x100 + o->data[2];
                }
                break;
            case 2:
            default:
                break;
            }
            Task_Create(7, &slot[i], (s32)&args);
        }
    }
}

void Stg35_SpawnSkillHitFx(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    s32 i;

    Skill_GetFxSet(w->field_2C, 1, a, b);
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
            default:
                break;
            }
            Task_Create(7, &slot[i], (s32)&args);
        }
    }
}

void Stg35_PlayHitReactSound(Actor *arg0) {
    Snd_PlayById(!func_8001E8D0(arg0->digiId) ? 0x204 : 0x205, 0);
}

void Stg35_HitReactUpdate(Actor *arg0, s32 arg1) {
    Stg35Xform *t = (Stg35Xform *)arg0->u38.ptr38;

    if (arg0->stateLevel3 == 0 && arg0->stateLevel4 == 0) {
        Actor_StopAxisMotion(arg0, 1);
    } else {
        Actor_ApplyAxisMotion(arg0, 1);
        Actor_ApplyAxisMotionRev(arg0, 2);
    }
    switch (arg0->stateLevel3) {
    case 0:
    default:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Actor_SetAxisMotion(arg0, 2, &Stg35_HitReactPushMotion);
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            Stg35_FighterSetAnim(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &Stg35_HitReactHop1Motion);
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
            Stg35_PlayHitReactSound(arg0);
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            Stg35_FighterSetAnim(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &Stg35_HitReactHop2Motion);
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
            Stg35_PlayHitReactSound(arg0);
            Stg35_FighterSetAnim(arg0, 0x16);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_NextState3(arg0);
                if (arg1 != 0) {
                    Task_NextState3(arg0);
                }
            }
            break;
        }
        break;
    case 3:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Stg35_FighterSetAnim(arg0, 0x5A);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    case 4:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Stg35_FighterSetAnim(arg0, 0x64);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone != 0) {
                Task_SetState0(arg0, 1);
            }
            break;
        }
        break;
    }
}

void Stg35_FighterTask(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    Stg35ModelFade *m = (Stg35ModelFade *)arg0->model;
    Stg35Arg1 a1;
    Stg35Xform *t;
    Stg35ModelFade *m0;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, &w->field_4, (u16)w->field_10);
        Gfx_AttachModel(arg0, w->field_14)->otIndex = 3;
        w->field_34 = -1;
        Stg35_FighterSetAnim(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, &((s32 *)arg0->u34.children)[3], (s32)&a1);
        m0 = (Stg35ModelFade *)arg0->model;
        w->field_18 = 1;
        w->field_1C = 0;
        m0->field_38 = m0->field_39 = m0->field_3A = 0x80;
        w->field_20.r = w->field_20.g = w->field_20.b = 0;
        w->field_28 = 1;
        if (w->field_38 != 0) {
            Stg35_FighterSetAnim(arg0, 0x64);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Stg35_FighterSetAnim(arg0, 0);
            Task_SetState0(arg0, 1);
            break;
        case 6:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                Stg35_SpawnSkillHitFx(arg0);
                arg0->elapsed = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->elapsed >= 0x78) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 1:
            w->field_2C = arg0->stateLevel4;
            k = Skill_GetCastAnim(w->field_2C);
            Stg35_SpawnSkillCastFx(arg0, k);
            switch (k) {
            case 0:
            default:
                Stg35_FighterSetAnim(arg0, 0x32);
                break;
            case 1:
                Stg35_FighterSetAnim(arg0, 0x3C);
                break;
            case 2:
                Stg35_FighterSetAnim(arg0, 0x46);
                break;
            }
            Task_SetState0(arg0, 1);
            break;
        case 2:
            Stg35_FighterSetAnim(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                Stg35_SpawnSkillHitFx(arg0);
                Stg35_FighterSetAnim(arg0, 0xA);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 4:
        case 5:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                Stg35_SpawnSkillHitFx(arg0);
                Task_NextState2(arg0);
            case 1:
                Stg35_HitReactUpdate(arg0, arg0->stateLevel1 - 4);
                break;
            }
            break;
        case 11:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg35_FighterSetAnim(arg0, 0x5A);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 12:
            w->field_2C = arg0->stateLevel4;
            Stg35_SpawnSkillHitFx(arg0);
            if (arg0->model->animId != 0) {
                Stg35_FighterSetAnim(arg0, 0);
            }
            Task_SetState0(arg0, 1);
            break;
        case 7:
            w->field_18 = 1;
            w->field_1C = 1;
            m->field_34 = 1;
            m->field_36 = 0x20;
            if (m->field_38 > 8) {
                m->field_38 -= 8;
            } else {
                m->field_38 = 0;
            }
            m->field_39 = m->field_3A = m->field_38;
            if (w->field_20.g < 0xEF) {
                w->field_20.g += 0x10;
            } else {
                w->field_20.g = 0xFF;
            }
            if (m->field_38 == 0 && w->field_20.g == 0xFF) {
                m->field_34 = 0;
                m->field_36 = 0;
                w->field_18 = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 8:
            w->field_18 = 1;
            w->field_1C = 1;
            m->field_34 = 1;
            m->field_36 = 0x20;
            if (m->field_38 < 0x78) {
                m->field_38 += 8;
            } else {
                m->field_38 = 0x80;
            }
            m->field_39 = m->field_3A = m->field_38;
            if (w->field_20.g > 0x10) {
                w->field_20.g -= 0x10;
            } else {
                w->field_20.g = 0;
            }
            if (m->field_38 == 0x80 && w->field_20.g == 0) {
                m->field_34 = 0;
                m->field_36 = 0;
                w->field_1C = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 10:
            w->field_28 = 0;
            break;
        case 9:
            m->field_38 = m->field_39 = m->field_3A = 0x80;
            m->field_34 = 0;
            m->field_36 = 0;
            w->field_18 = 1;
            w->field_1C = 0;
            w->field_28 = 1;
            Task_SetState0(arg0, 1);
            break;
        }
        break;
    }
    if (w->field_28 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
    if (w->field_30 != 0 && --w->field_30 == 1) {
        t = (Stg35Xform *)arg0->u38.ptr38;
        t->field_30 = w->field_4;
        t->field_38 = w->field_C;
        t->field_50 = 0;
        t->field_48 = 0;
        Actor_StopAxisMotion(arg0, 2);
    }
}

void Stg35_FighterDestroy(Actor *arg0) {
    arg0->childCount = 4;
    Task_DefaultDestroy(arg0);
}

void Stg35_FighterDraw(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    CVECTOR c;

    if (w->field_28 != 0) {
        Gfx_AttachModel(arg0, w->field_14);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        if (w->field_18 != 0) {
            Gfx_DrawTexModel(arg0, 0);
        }
        if (w->field_1C != 0) {
            if (arg0->param < 3) {
                c = w->field_20;
            } else {
                c.r = w->field_20.g;
                c.g = w->field_20.r;
                c.b = w->field_20.b;
            }
            Gfx_DrawWireModel(arg0, 0, &c);
        }
    }
}

void Stg35_FighterSetVisible(Actor *arg0, s32 arg1) {
    ((Stg35Work *)arg0->work)->field_28 = arg1;
    if (arg1 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
}

void Stg35_FighterQueueHomeReset(Actor *arg0) {
    ((Stg35Work *)arg0->work)->field_30 = 2;
}

void Stg35_RoundBannerInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

INCLUDE_RODATA("asm/USA/stag3500/rodata", Stg35_RoundBannerMasks);
void Stg35_RoundBannerTask(Actor *arg0) {
    Stg35FadeWork *w = (Stg35FadeWork *)arg0->work;

    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        Stg35_PartsSetFile(w->load, 0xD3F0009);
        {
            Stg35Masks masks = Stg35_RoundBannerMasks;

            Stg35_PartsHideByMask(w->load, ~masks.v[arg0->param]);
        }
        Snd_PlayById(0x24, 0);
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_4++;
            Stg35_PartsSetPalette(w->load, 0x1F, w->field_4 >> 1);
            if (w->field_4 != 14) {
                break;
            }
            Task_NextState1(arg0);
        case 1:
            if (((ActorAllocView *)arg0)->frameCount < 8) {
                break;
            }
            Task_NextState1(arg0);
        case 2:
            w->field_4--;
            Stg35_PartsSetPalette(w->load, 0x1F, w->field_4 >> 1);
            if (w->field_4 == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void Stg35_RoundBannerDestroy(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_RoundBannerDraw(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsDraw(&w[i]);
    }
}

void Stg35_ClearBattle(void) {
    Mem_Zero(&Stg35_Battle, 0x358);
}

void Stg35_XaPlayInit(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

void Stg35_XaPlayTask(Actor *arg0) {
    Stg35CdWork *w = (Stg35CdWork *)arg0->work;
    u8 filter[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 r;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId) + Stg35_XaTrackStart[w->track - 1];
            w->end = w->start + Stg35_XaTrackLength[w->track - 1];
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, loc);
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
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((ActorAllocView *)arg0)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
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

void Stg35_XaPlayDestroy(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

void Stg35_HudUpdateSkillList(Actor *arg0) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 sel = 6 - w->field_54[arg0->param] / 4096;
    Stg35TextHandle *t;
    s32 i;

    for (i = 0; i < 7; i++) {
        t = &w->text[i];
        if (arg0->param == 0) {
            Stg35_TextSetLayout(t, 0, 0xB8, i * 14 + 0x49);
        } else {
            Stg35_TextSetLayout(t, 0, 0x1C, i * 14 + 0x49);
        }
        if (i == 0) {
            Stg35_TextSetSysMsg(t, 1);
        } else if (w->field_5C[i - 1] != 0) {
            Stg35_TextSetSkillName(t, w->field_5C[i - 1]);
        } else {
            Stg35_TextSetSysMsg(t, 0x1C3);
        }
        if (i == sel) {
            Stg35_TextSetColor((Stg35LoadHandle *)t, 4);
        } else {
            Stg35_TextSetColor((Stg35LoadHandle *)t, 1);
        }
        Stg35_TextOpen(t);
    }
}

void Stg35_HudUpdateGaugeColumn(Actor *arg0, s32 arg1) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 s = Stg35_ScaleBarLen(0xC4, 0x7000, w->field_54[arg0->param]);
    Stg35SpriteHandle *sp;

    if (arg0->param == 0) {
        sp = &w->sprite[2];
    } else {
        sp = &w->sprite[3];
    }
    Stg35_RectSetHeight(sp, s);
    Stg35_RectSetY(sp, 0x60 - s);
    if (w->field_54[arg0->param] >= 0x6000) {
        Stg35_RectSetColor(sp, 0, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 1, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    } else {
        Stg35_RectSetColor(sp, 0, 0xAE, 0x7E, 0x11);
        Stg35_RectSetColor(sp, 1, 0xAE, 0x7E, 0x11);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    }
}

void Stg35_HudUpdateGaugeBar(Actor *arg0, s32 arg1) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 s = Stg35_ScaleBarLen(0x70, 0x6000, w->field_54[arg0->param]);
    Stg35SpriteHandle *sp;

    if (arg0->param == 0) {
        sp = &w->sprite[0];
    } else {
        sp = &w->sprite[1];
    }
    if (arg0->param == 0) {
        Stg35_RectSetWidth(sp, s);
        Stg35_RectSetX(sp, -0x16 - s);
    } else {
        Stg35_RectSetWidth(sp, s);
    }
    if (s == 0x70) {
        Stg35_RectSetColor(sp, 0, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 1, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    } else if (arg0->param == 0) {
        Stg35_RectSetColor(sp, 0, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 1, 0, 0, 0xFC);
        Stg35_RectSetColor(sp, 2, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 3, 0, 0, 0xFC);
    } else {
        Stg35_RectSetColor(sp, 1, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 0, 0, 0, 0xFC);
        Stg35_RectSetColor(sp, 3, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 2, 0, 0, 0xFC);
    }
}

void Stg35_BattleHudTask(Actor *arg0) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 i;
    s32 j;
    s32 order[6];
    Stg35SpriteHandle *sp;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 3; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 7; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        for (i = 0; i < 10; i++) {
            Stg35_RectAlloc(&w->sprite[i]);
        }
        Stg35_PartsSetFile(&w->load[0], 0xD3F0005);
        Stg35_PartsSetFile(&w->load[1], 0xD3F0006);
        Stg35_PartsSetFile(&w->load[2], 0xD3F0007);
        sp = &w->sprite[0];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, -0x86, -0xC4, 0x70, 0x12);
        sp = &w->sprite[1];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, 0x15, -0xC4, 0x70, 0x12);
        sp = &w->sprite[3];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, -0x84, -0x64, 0x6B, 0xC4);
        sp = &w->sprite[2];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, 0x18, -0x64, 0x6B, 0xC4);
        for (i = 0; i < 3; i++) {
            sp = &w->sprite[4 + i];
            Stg35_RectSetDrawMode(sp, 0, 0, 0);
            Stg35_RectSetColor(sp, 0, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 2, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 1, 0xEB, 0xEE, 6);
            Stg35_RectSetColor(sp, 3, 0xEB, 0xEE, 6);
            Stg35_RectSetBounds(sp, Stg35_HpBarPosP1[i].x, Stg35_HpBarPosP1[i].y, 0x70, 0xC);
        }
        for (i = 0; i < 3; i++) {
            sp = &w->sprite[7 + i];
            Stg35_RectSetDrawMode(sp, 0, 0, 0);
            Stg35_RectSetColor(sp, 1, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 3, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 0, 0xEB, 0xEE, 6);
            Stg35_RectSetColor(sp, 2, 0xEB, 0xEE, 6);
            Stg35_RectSetBounds(sp, Stg35_HpBarPosP2[i].x, Stg35_HpBarPosP2[i].y, 0x70, 0xC);
        }
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        default:
        case 0:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                Stg35_PartsHideByMask(&w->load[0], -2);
                Stg35_PartsHideByMask(&w->load[1], -0xE1);
                Stg35_PartsHideByMask(&w->load[2], -0xE1);
                Stg35_RectSetHeight(&w->sprite[3], 0);
                Stg35_RectSetHeight(&w->sprite[2], 0);
                break;
            case 1:
                break;
            }
            break;
        case 1:
            for (j = 0; j < 6; j++) {
                order[j] = 0;
            }
            for (j = 0; j < 6; j++) {
                s32 r = Stg35_TurnOrderGet(j);
                if (r != -1) {
                    order[r] = j + 1;
                }
            }
            Stg35_PartsSetNumber(&w->load[1], 0x20, 1, order[0]);
            Stg35_PartsSetNumber(&w->load[1], 0x40, 1, order[1]);
            Stg35_PartsSetNumber(&w->load[1], 0x80, 1, order[2]);
            Stg35_PartsSetNumber(&w->load[2], 0x20, 1, order[3]);
            Stg35_PartsSetNumber(&w->load[2], 0x40, 1, order[4]);
            Stg35_PartsSetNumber(&w->load[2], 0x80, 1, order[5]);
            break;
        case 2: {
            s32 *gauge = &w->field_54[arg0->param];
            Stg35LoadHandle *load = &w->load[arg0->param + 1];
            Stg35LoadHandle *base = w->load;
            s32 pressed = Pad_State[arg0->param].pressed & 0xFFFF;
            s32 r;

            switch (arg0->stateLevel2) {
            default:
            case 0:
                switch (arg0->stateLevel3) {
                default:
                case 0:
                    Snd_PlayById(0x25, 0);
                    w->field_78 = 0;
                    Stg35_PartsShowGroup(load, 2);
                    Task_NextState3(arg0);
                    arg0->elapsed = 0;
                case 1: {
                    s32 frame = Math_CycleRange(arg0->elapsed, 2, 0, 7);
                    Stg35_PartsSetPalette(load, 2, frame);
                    if (frame == 7) {
                        arg0->elapsed = 0;
                        Task_NextState3(arg0);
                    }
                    break;
                }
                case 2:
                    if (arg0->elapsed < 0x78) {
                        break;
                    }
                    Task_NextState3(arg0);
                    arg0->elapsed = 0;
                case 3: {
                    s32 frame = Math_CycleRange(arg0->elapsed, 2, 7, 0);
                    Stg35_PartsSetPalette(load, 2, frame);
                    if (frame == 0) {
                        arg0->elapsed = 0;
                        Task_NextState2(arg0);
                    }
                    break;
                }
                }
                break;
            case 1:
                switch (arg0->stateLevel3) {
                case 0:
                    arg0->elapsed = 0;
                    w->field_54[arg0->param] = 0;
                    Stg35_PartsHideGroup(load, 2);
                    Stg35_PartsShowGroup(base, 2);
                    if (arg0->param == 0) {
                        Stg35_PartsShowGroup(base, 8);
                        Stg35_PartsShowGroup(base, 0x20);
                    } else {
                        Stg35_PartsShowGroup(base, 4);
                        Stg35_PartsShowGroup(base, 0x10);
                    }
                    Task_NextState3(arg0);
                case 1:
                    if (pressed & 0x40) {
                        *gauge += 0xD00;
                        Snd_PlayById(0x100, 0);
                    } else {
                        *gauge = (*gauge < 0x1F9) ? 0 : *gauge - 0x1F8;
                    }
                    *gauge = (*gauge >= 0x7000) ? 0x6FFF : *gauge;
                    Stg35_HudUpdateGaugeColumn(arg0, 0);
                    Stg35_HudUpdateGaugeBar(arg0, 0);
                    Stg35_HudUpdateSkillList(arg0);
                    if (arg0->param == 0) {
                        Stg35_PartsSetX(&w->load[0], 0x20, 0x4F);
                        Stg35_PartsSetY(&w->load[0], 0x20, 0x2B - (w->field_54[0] / 0x1000) * 14);
                    } else {
                        Stg35_PartsSetX(&w->load[0], 0x10, -0x4D);
                        Stg35_PartsSetY(&w->load[0], 0x10, 0x2B - (w->field_54[1] / 0x1000) * 14);
                    }
                    if (((ActorAllocView *)arg0)->frameCount & 4) {
                        Stg35_PartsShowGroup(load, 4);
                    } else {
                        Stg35_PartsHideGroup(load, 4);
                    }
                    {
                        s32 pct = (0x12C - arg0->elapsed) / 3;
                        if (pct == 100) {
                            pct = 99;
                        }
                        Stg35_PartsSetNumber(base, 2, 2, pct);
                    }
                    if (arg0->elapsed >= 0x12C) {
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                case 2:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(0xE, 0);
                        Stg35_HudUpdateGaugeBar(arg0, 1);
                        Stg35_HudUpdateGaugeColumn(arg0, 1);
                        arg0->elapsed = 0;
                        Task_NextState4(arg0);
                    case 1:
                        r = Math_CycleRange(arg0->elapsed, 2, 0, 7);
                        if (arg0->param == 0) {
                            Stg35_PartsSetPalette(&w->load[0], 0x20, r);
                        } else {
                            Stg35_PartsSetPalette(&w->load[0], 0x10, r);
                        }
                        if (r == 7) {
                            Task_NextState4(arg0);
                        }
                        break;
                    case 2:
                        if (arg0->elapsed >= 0x3C) {
                            s32 level = w->field_54[arg0->param] / 0x1000;
                            w->field_74 = level;
                            w->field_7C = w->field_5C[5 - level];
                            Task_NextState3(arg0);
                        }
                        break;
                    }
                    break;
                case 3:
                    for (i = 0; i < 7; i++) {
                        Stg35_TextClose(&w->text[i]);
                    }
                    Stg35_RectSetHeight(&w->sprite[arg0->param + 2], 0);
                    Stg35_PartsHideGroup(load, 6);
                    Stg35_PartsHideGroup(base, 0x3E);
                    if (w->field_74 == 6) {
                        w->field_78 = 1;
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    } else if (w->field_5C[5 - w->field_74] != 0) {
                        goto done;
                    } else {
                        w->field_78 = 1;
                        Task_NextState3(arg0);
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                case 4:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(7, 0);
                        Task_NextState4(arg0);
                    case 1:
                        Stg35_PartsShowGroup(base, 0x40);
                        Stg35_PartsSetPalette(base, 0x40, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
                        if (arg0->elapsed >= 0xB4) {
                            Stg35_PartsHideGroup(base, 0x40);
                            goto done;
                        }
                        break;
                    }
                    break;
                case 5:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(0x1C, 0);
                        Task_NextState4(arg0);
                    case 1:
                        Stg35_PartsShowGroup(base, 0x80);
                        Stg35_PartsSetPalette(base, 0x80, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
                        if (arg0->elapsed >= 0xB4) {
                            Stg35_PartsHideGroup(base, 0x80);
                        done:
                            Task_SetState1(arg0, 1);
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        }
        for (i = 0; i < 6; i++) {
            if (w->field_80[i].field_4 != w->field_80[i].field_0) {
                if (w->field_80[i].field_4 < w->field_80[i].field_0) {
                    w->field_80[i].field_4 += arg0->elapsed;
                    if (w->field_80[i].field_0 < w->field_80[i].field_4) {
                        w->field_80[i].field_4 = w->field_80[i].field_0;
                    }
                } else {
                    w->field_80[i].field_4 -= arg0->elapsed;
                    if (w->field_80[i].field_4 < w->field_80[i].field_0) {
                        w->field_80[i].field_4 = w->field_80[i].field_0;
                    }
                }
            }
            Stg35_RectSetWidth(&w->sprite[4 + i], Stg35_ScaleBarLen(0x70, w->field_80[i].field_8, w->field_80[i].field_4));
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        default:
        case 0:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
            break;
        case 1:
            break;
        }
        break;
    }
}

void Stg35_BattleHudDestroy(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    for (i = 0; i < 10; i++) {
        Stg35_RectFree(&w->sprite[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_BattleHudDraw(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Stg35_PartsDraw(&w->load[i]);
    }
    for (i = 0; i < 10; i++) {
        Stg35_RectDraw(&w->sprite[i]);
    }
}

void Stg35_HudStartGauge(s32 arg0, s32 *arg1) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        Task_SetState1(e, 2);
        e->param = arg0;
        for (i = 0; i < 6; i++) {
            w->field_5C[i] = arg1[i];
        }
    }
}

s32 Stg35_HudGetGaugeStatus(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);

    if (e != NULL && e->stateLevel1 == 2) {
        return 1;
    }
    return (((Stg35Work708 *)e->work)->field_78 != 0) * 2;
}

void Stg35_HudSyncHp(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        for (i = 0; i < 6; i++) {
            w->field_80[i].field_0 = Stg35_Battle.rec[i].hp;
            w->field_80[i].field_8 = Stg35_Battle.rec[i].maxHp;
        }
    }
}

s32 Stg35_HudGetGaugeLevel(void) {
    TaskEntry *e = Task_FindFirst(0x708, -1, -1);

    if (e != NULL) {
        return ((Stg35Work708 *)e->work)->field_74;
    }
    return 1;
}

s32 Stg35_HudPeekGaugeLevel(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 n;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        n = w->field_54[arg0] / 4096;
        if (w->field_5C[5 - n] != 0) {
            if (n == 6) {
                return 6;
            }
            return n;
        }
    }
    return 0;
}

void Stg35_BattleScriptTask(Actor *arg0) {
    Stg35ScriptWork *w = (Stg35ScriptWork *)arg0->work;
    Actor **children = (Actor **)arg0->u34.children;
    Actor *e;
    s32 *q;
    s32 cont;
    Stg35Arg1 a1;
    Stg35Arg3 a3;

    switch (arg0->stateLevel0) {
    case 0:
        w->script = Stg35_BattleScript;
        Task_NextState0(arg0);
        break;
    case 1:
        cont = 1;
        do {
            switch (w->script[0]) {
            case 0:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    arg0->elapsed = 0;
                    arg0->stateLevel1++;
                case 1:
                    break;
                }
                if (w->script[1] < arg0->elapsed) {
                    arg0->stateLevel1 = 0;
                    w->script += 2;
                } else {
                    cont = 0;
                }
                break;
            case 1:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                if (e->stateLevel0 == 2) {
                    cont = 0;
                } else {
                    w->script += 2;
                }
                break;
            case 2:
                Stg35_SetCameraShot(w->script[1]);
                cont = 0;
                w->script += 2;
                break;
            case 3:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param == w->script[1]) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    } else {
                        Stg35_FighterSetVisible(e, 0);
                    }
                }
                w->script += 2;
                break;
            case 4:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param < 3) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    }
                }
                w->script += 1;
                break;
            case 5:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param >= 3) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    }
                }
                w->script += 1;
                break;
            case 6:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    Stg35_FighterSetVisible(e, 1);
                    Stg35_FighterQueueHomeReset(e);
                }
                w->script += 1;
                break;
            case 7:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 0);
                w->script += 2;
                break;
            case 8:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 1);
                Task_SetState4(e, (u8)w->script[2]);
                w->script += 3;
                break;
            case 9:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_SetDigiAction(e, 3, w->script[2]);
                w->script += 3;
                break;
            case 10:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_HudSyncHp();
                Stg35_SetDigiAction(e, 4, w->script[2]);
                w->script += 3;
                break;
            case 11:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_HudSyncHp();
                Stg35_SetDigiAction(e, 5, w->script[2]);
                w->script += 3;
                break;
            case 12:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_SetDigiAction(e, 6, w->script[2]);
                w->script += 3;
                break;
            case 13:
                w->script += 3;
                break;
            case 14:
            case 15:
                w->script += 2;
                break;
            case 16:
                break;
            case 17:
                a1.field_0 = (s32)Stg35_BattleScript;
                Task_Create(0x70A, (s32 *)&children[3], (s32)&a1);
                w->script += 1;
                break;
            case 18:
                if (children[3]->stateLevel0 == 1) {
                    w->script += 1;
                } else {
                    cont = 0;
                }
                break;
            case 19:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    q = Skill_GetShotXa(w->script[1]);
                    a3.field_0 = q[0];
                    a3.field_4 = q[1];
                    a3.field_8 = w->script[2];
                    Task_Create(0x70B, (s32 *)&children[4], (s32)&a3);
                    Task_NextState1(arg0);
                case 1:
                    break;
                }
                if (children[4]->stateLevel0 == 1) {
                    Task_SetState0(children[4], 2);
                    w->script += 3;
                    Task_SetState1(arg0, 0);
                } else {
                    cont = 0;
                }
                break;
            case 20:
                Task_SetState0(arg0, 3);
                cont = 0;
                break;
            }
        } while (cont);
        break;
    }
}
