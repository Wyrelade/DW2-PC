#include "common.h"
#include "stag3500/stag3500.h"

void func_800634FC(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;

    if (arg0->stateLevel0 == 0) {
        func_80066120(w);
        func_800661A4(w, 0xD3F0000);
        Task_NextState0(arg0);
    }
}

void func_80063550(Actor *arg0) {
    func_80066168((Stg35LoadHandle *)arg0->work);
    Task_DefaultDestroy(arg0);
}

void func_80063584(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;

    func_80066520(w, 2, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    func_800661B0(w);
}

void func_800635D4(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        arg0->digiId = 0xD77;
        Actor_InitTransform(arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, arg0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void func_8006363C(Actor *arg0) {
    Gfx_AttachModel(arg0, arg0->digiId);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void func_80063684(Actor *arg0, s32 *arg1) {
    ((Stg35Work *)arg0->work)->field_0 = *arg1;
}

void func_80063694(Actor *arg0, s32 arg1, s32 arg2) {
    Stg35ListWork *w = (Stg35ListWork *)arg0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->field_2D8; i++) {
        if (arg2 < w->field_F8[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->field_2D8; i < j; j--) {
            w->field_8[j] = w->field_8[j - 1];
            w->field_F8[j] = w->field_F8[j - 1];
        }
    }
    w->field_8[i] = arg1;
    w->field_F8[i] = arg2;
    w->field_2D8++;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063758);

void func_80063E00(Actor *arg0) {
    Stg35ListWork *w = (Stg35ListWork *)arg0->work;
    s32 i;

    for (i = 0; i < w->field_2E0; i++) {
        if (w->field_260[i] != 0) {
            Cd_FreeFile(w->field_260[i]);
        }
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063E74);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063F38);

void func_800645B4(Actor *arg0) {
    Stg35Work4 *w = (Stg35Work4 *)arg0->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        func_80065718(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80064638(Actor *arg0) {
    Stg35Work4 *w = (Stg35Work4 *)arg0->work;

    func_80066520(&w->load[0], 0x2A, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    func_800661B0(&w->load[0]);
    func_800661B0(&w->load[1]);
    if (w->field_34 != 0) {
        func_800661B0(&w->load[2]);
    }
    if (w->field_38 != 0) {
        func_800661B0(&w->load[3]);
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800646C0);

void func_80064AF0(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 14; i++) {
        func_80065718(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80064B70(Actor *arg0) {
    func_800661B0((Stg35LoadHandle *)arg0->work);
}

void func_80064B94(Actor *arg0, s32 arg1, s32 arg2) {
    arg0->stateLevel0 = 2;
    arg0->stateLevel1 = arg1;
    arg0->stateLevel2 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel4 = arg2;
}

void func_80064BB0(Stg35ChildOwner *arg0, s32 arg1) {
    Stg35ChildList *l = arg0->field_34;
    s32 i;

    for (i = 0; i < 6; i++) {
        Actor *a = l->field_2C[i];

        if (a != NULL) {
            if (arg1 == 0) {
                if (i < 3) {
                    func_800674D4(a, 1);
                    func_800674F8(l->field_2C[i]);
                } else {
                    func_800674D4(a, 0);
                }
            } else {
                if (i >= 3) {
                    func_800674D4(a, 1);
                    func_800674F8(l->field_2C[i]);
                } else {
                    func_800674D4(a, 0);
                }
            }
        }
    }
}

void func_80064C54(Stg35ChildOwner *arg0) {
    Stg35ChildList *l = arg0->field_34;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (l->field_2C[i] != NULL) {
            func_800674D4(l->field_2C[i], 1);
            func_800674F8(l->field_2C[i]);
        }
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80064CB8);

void func_80065694(Actor *arg0) {
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(arg0);
}

void func_800656D0(Stg35TextHandle *arg0) {
    Stg35TextObj *p = (Stg35TextObj *)Mem_Alloc(0x1C, 2);

    arg0->text = p;
    Mem_Zero(p, 0x1C);
    arg0->text->field_0 = -1;
}

void func_80065718(Stg35TextHandle *arg0) {
    if (arg0->text != NULL) {
        Text_Close(arg0->text);
        Mem_Free(arg0->text);
        arg0->text = NULL;
    }
}

void func_80065760(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->text->field_8 = arg1 >> 8;
    arg0->text->field_C = 0;
    arg0->text->field_10 = arg2;
    arg0->text->field_14 = arg3;
    arg0->text->field_18 = arg1 & 0xFF;
}

void func_800657A0(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->mode = arg1;
}

void func_800657AC(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->u.field_C = arg1;
}

void func_800657B8(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
}

void func_800657F0(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = func_8001ED84(arg1);
}

void func_80065824(Stg35TextHandle *arg0) {
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

void func_80065894(Stg35TextHandle *arg0) {
    Text_Close(arg0->text);
}

void func_800658B8(Stg35SpriteHandle *arg0) {
    arg0->sprite = (Stg35Sprite *)Mem_Alloc(0x20, 2);
    Mem_Zero(arg0->sprite, 0x20);
}

void func_800658F4(Stg35SpriteHandle *arg0) {
    if (arg0->sprite != NULL) {
        Mem_Free(arg0->sprite);
        arg0->sprite = NULL;
    }
}

void func_80065930(Stg35SpriteHandle *arg0) {
    Stg35Sprite *s = arg0->sprite;
    SysState *g;
    Stg35PolyG4 *p;
    u32 *ot;

    if (s->field_1C != 0 && s->field_1E != 0) {
        g = &D_8005F770;
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

void func_80065B04(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3) {
    Stg35Sprite *s = arg0->sprite;
    s->field_0 = arg1;
    s->field_14 = arg2;
    s->field_16 = arg3;
}

void func_80065B1C(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_4[arg1].r = arg2;
    s->field_4[arg1].g = arg3;
    s->field_4[arg1].b = arg4;
}

void func_80065B3C(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1C = arg1;
}

void func_80065B48(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1E = arg1;
}

void func_80065B54(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_18 = arg1;
}

void func_80065B60(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1A = arg1;
}

void func_80065B6C(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_18 = arg1;
    s->field_1A = arg2;
    s->field_1C = arg3;
    s->field_1E = arg4;
}

s32 func_80065B88(s32 arg0, s32 arg1, s32 arg2) {
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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065BE0);

void func_80065D00(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_8006AA58[i] = v;
    }
}

void func_80065D2C(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 10; i >= arg0; i--) {
        D_8006AA58[i + 1] = D_8006AA58[i];
    }
    D_8006AA58[arg0] = arg1;
}

void func_80065D84(s32 arg0) {
    for (; arg0 < 11; arg0++) {
        D_8006AA58[arg0] = D_8006AA58[arg0 + 1];
    }
}

s32 func_80065DC8(s32 arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (arg0 == D_8006AA58[i]) {
            return i;
        }
    }
    return -1;
}

s32 func_80065E04(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_8006AA58[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 func_80065E44(s32 arg0) {
    return D_8006AA58[arg0];
}

void func_80065E60(void) {
    s32 v[6];
    s32 i;
    s32 j;
    s32 best;
    s32 max;

    for (i = 0; i < 6; i++) {
        if (D_8006AA88.rec[i].hp != 0) {
            v[i] = D_8006AA88.rec[i].field_20 + (u16)((u16)Rand_Next() % 11);
        } else {
            v[i] = 0;
        }
    }
    func_80065D00();
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
        func_80065D2C(func_80065E04(), best);
        v[best] = 0;
    }
}

void func_80065F8C(s32 arg0, s32 arg1) {
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s32 t;
    s32 base;
    s32 n;

    b->field_0 = 1;
    b->field_8 = b->field_C[arg1];
    switch (b->field_12[arg1]) {
    case 0:
    default:
        t = D_8006A55C[arg0];
        if (D_8006AA88.rec[t].hp != 0) {
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
            if (D_8006AA88.rec[t].hp != 0) {
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

void func_80066120(Stg35LoadHandle *arg0) {
    Stg35Load *p = (Stg35Load *)Mem_Alloc(0x24, 2);

    arg0->load = p;
    Mem_Zero(p, 0x24);
    arg0->load->field_8 = 0x1000;
}

void func_80066168(Stg35LoadHandle *arg0) {
    if (arg0->load != NULL) {
        Mem_Free(arg0->load);
        arg0->load = NULL;
    }
}

void func_800661A4(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->fileId = arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800661B0);

void func_800663CC(Stg35LoadHandle *arg0, s32 arg1) {
    Gfx_HidePartsByMask((GfxPartMaskView *)Cd_GetFileEntry(arg0->load->fileId), arg1);
}

void func_80066408(Stg35LoadHandle *arg0, s32 mask) {
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

void func_80066480(Stg35LoadHandle *arg0, s32 mask) {
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

void func_800664F4(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 1;
    l->field_8 = 0;
}

void func_80066508(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 2;
    l->field_8 = 0x1000;
}

void func_80066520(Stg35LoadHandle *arg0, s32 mask, s32 v) {
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

void func_8006659C(Stg35LoadHandle *arg0, s32 mask, s32 v) {
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

void func_80066618(Stg35LoadHandle *arg0, s32 mask, s32 v) {
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

void func_80066694(Stg35LoadHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed) {
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

void func_80066778(Stg35LoadHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_SetPartsNumber((GfxPart *)Cd_GetFileEntry(arg0->load->fileId), arg1, arg2, arg3);
}

void func_800667D0(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;

    if (w->field_34 != arg1) {
        w->field_34 = arg1;
        Anim_SetModelAnim(arg0, arg1);
    }
}

void func_80066808(Actor *arg0, Stg35Vec3 *arg1) {
    s32 i = arg1->field_4;
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 n;

    arg0->field_8 = i;
    arg0->digiId = D_8006AA88.rec[i].digiId;
    w->field_14 = Digi_GetModelFile(arg0->digiId);
    if (arg0->field_8 < 3) {
        w->field_10 = 0x800;
    } else {
        w->field_10 = 0;
    }
    n = arg0->field_8;
    w->field_8 = 0;
    w->field_4 = (n % 3) * 0xA00 - 0xA00;
    w->field_C = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = arg1->field_8;
}

void func_800668F8(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    Row6 ofs[3];
    Row6 *o;
    s32 i;

    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(arg0->digiId, ofs);
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

void func_80066A9C(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    s32 i;

    func_8001EEA4(w->field_2C, 1, a, b);
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

void func_80066BC8(Actor *arg0) {
    Snd_PlayById(!func_8001E8D0(arg0->digiId) ? 0x204 : 0x205, 0);
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066C00);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066EBC);

void func_800673C4(Actor *arg0) {
    arg0->childCount = 4;
    Task_DefaultDestroy(arg0);
}

void func_800673E8(Actor *arg0) {
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
            if (arg0->field_8 < 3) {
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

void func_800674D4(Actor *arg0, s32 arg1) {
    ((Stg35Work *)arg0->work)->field_28 = arg1;
    if (arg1 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
}

void func_800674F8(Actor *arg0) {
    ((Stg35Work *)arg0->work)->field_30 = 2;
}

void func_80067508(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_80067510(Actor *arg0) {
    Stg35FadeWork *w = (Stg35FadeWork *)arg0->work;

    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            func_80066120(&w->load[i]);
        }
        func_800661A4(w->load, 0xD3F0009);
        {
            Stg35Masks masks = D_80063418;

            func_800663CC(w->load, ~masks.v[arg0->field_8]);
        }
        Snd_PlayById(0x24, 0);
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_4++;
            func_80066520(w->load, 0x1F, w->field_4 >> 1);
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
            func_80066520(w->load, 0x1F, w->field_4 >> 1);
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

void func_8006768C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_800676E0(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}

void func_80067720(void) {
    Mem_Zero(&D_8006AA88, 0x358);
}

void func_80067748(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067768);

void func_8006799C(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

void func_800679D0(Actor *arg0) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 sel = 6 - w->field_54[arg0->field_8] / 4096;
    Stg35TextHandle *t;
    s32 i;

    for (i = 0; i < 7; i++) {
        t = &w->text[i];
        if (arg0->field_8 == 0) {
            func_80065760(t, 0, 0xB8, i * 14 + 0x49);
        } else {
            func_80065760(t, 0, 0x1C, i * 14 + 0x49);
        }
        if (i == 0) {
            func_800657B8(t, 1);
        } else if (w->field_5C[i - 1] != 0) {
            func_800657F0(t, w->field_5C[i - 1]);
        } else {
            func_800657B8(t, 0x1C3);
        }
        if (i == sel) {
            func_800657AC((Stg35LoadHandle *)t, 4);
        } else {
            func_800657AC((Stg35LoadHandle *)t, 1);
        }
        func_80065824(t);
    }
}

void func_80067B18(Actor *arg0, s32 arg1) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 s = func_80065B88(0xC4, 0x7000, w->field_54[arg0->field_8]);
    Stg35SpriteHandle *sp;

    if (arg0->field_8 == 0) {
        sp = &w->sprite[2];
    } else {
        sp = &w->sprite[3];
    }
    func_80065B48(sp, s);
    func_80065B60(sp, 0x60 - s);
    if (w->field_54[arg0->field_8] >= 0x6000) {
        func_80065B1C(sp, 0, 0xA4, 0x19, 2);
        func_80065B1C(sp, 1, 0xA4, 0x19, 2);
        func_80065B1C(sp, 2, 0xA4, 0x19, 2);
        func_80065B1C(sp, 3, 0xA4, 0x19, 2);
    } else {
        func_80065B1C(sp, 0, 0xAE, 0x7E, 0x11);
        func_80065B1C(sp, 1, 0xAE, 0x7E, 0x11);
        func_80065B1C(sp, 2, 0xA4, 0x19, 2);
        func_80065B1C(sp, 3, 0xA4, 0x19, 2);
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067C74);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067E48);

void func_800689FC(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        func_80065718(&w->text[i]);
    }
    for (i = 0; i < 10; i++) {
        func_800658F4(&w->sprite[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80068AA0(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_800661B0(&w->load[i]);
    }
    for (i = 0; i < 10; i++) {
        func_80065930(&w->sprite[i]);
    }
}

void func_80068B10(s32 arg0, s32 *arg1) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        Task_SetState1(e, 2);
        e->field_8 = arg0;
        for (i = 0; i < 6; i++) {
            w->field_5C[i] = arg1[i];
        }
    }
}

s32 func_80068B9C(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);

    if (e != NULL && e->stateLevel1 == 2) {
        return 1;
    }
    return (((Stg35Work708 *)e->work)->field_78 != 0) * 2;
}

void func_80068BF8(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        for (i = 0; i < 6; i++) {
            w->field_80[i].field_0 = D_8006AA88.rec[i].hp;
            w->field_80[i].field_8 = D_8006AA88.rec[i].maxHp;
        }
    }
}

s32 func_80068C5C(void) {
    TaskEntry *e = Task_FindFirst(0x708, -1, -1);

    if (e != NULL) {
        return ((Stg35Work708 *)e->work)->field_74;
    }
    return 1;
}

s32 func_80068CA0(s32 arg0) {
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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068D34);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006926C);

s32 func_80069850(s32 arg0) {
    func_8006926C(arg0);
    return 1;
}

s32 func_80069870(s32 arg0, s32 arg1) {
    s32 neg = 0;
    s32 r;

    arg0 -= arg1;
    if (arg0 == 0) {
        return neg;
    }
    if (arg0 < 0) {
        neg = 1;
        arg0 = -arg0;
    }
    r = arg0 / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void func_800698C8(Stg35CamWork *w, s32 *t) {
    s32 i;

    for (i = 0; i < D_8005F770.frameDelta; i++) {
        w->field_7E += func_80069870(t[0], w->field_7E);
        w->field_0 += func_80069870(t[1], w->field_0);
        w->field_4 += func_80069870(t[2], w->field_4);
        w->field_8 += func_80069870(t[3], w->field_8);
        w->field_10 += func_80069870(t[4], w->field_10);
        w->field_6C += func_80069870(t[5], w->field_6C);
        w->field_74 += func_80069870(t[6], w->field_74);
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800699FC);

void func_80069FD4(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    Stg35RefView rv;

    RotMatrixYXZ(&w->field_7C, &w->field_1C.coord);
    w->field_1C.coord.t[0] = w->field_6C;
    w->field_1C.coord.t[1] = w->field_70;
    w->field_1C.coord.t[2] = w->field_74;
    w->field_1C.flg = 0;
    rv.field_0 = w->field_0;
    rv.field_4 = w->field_4;
    rv.field_8 = w->field_8;
    rv.field_C = w->field_C;
    rv.field_10 = w->field_10;
    rv.field_14 = w->field_14;
    rv.field_18 = 0;
    rv.field_1C = &w->field_1C;
    GsSetProjection(w->field_18);
    GsSetRefView2(&rv);
}

void func_8006A080(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x706, -1, -1);

    if (e != NULL && e->stateLevel0 == 1) {
        Task_SetState1(e, (u8)arg0);
    }
}

void func_8006A0D4(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    Stg35Rec6 *p;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        p = D_8006AA24[i];
        j = 0;
        while (p->field_0 != 0) {
            if (p->field_0 == arg0) {
                goto found;
            }
            p++;
            j++;
        }
        continue;
    found:
        *arg1 = i;
        *arg2 = j;
        *arg3 = p->field_4;
        *arg4 = p->field_2;
        return;
    }
    *arg1 = -1;
    *arg2 = 100;
}

void func_8006A168(s32 arg0) {
    u8 *ids = D_8006AA88.rec[arg0].field_22;
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s32 best[6];
    s32 grp;
    s32 idx;
    s32 v4;
    s32 v2;
    s32 found;
    s32 i;

    for (i = 0; i < 6; i++) {
        b->field_C[i] = 0;
        best[i] = 100;
    }
    found = 0;
    for (i = 0; i < 12; i++) {
        if (ids[i] != 0) {
            func_8006A0D4(ids[i], &grp, &idx, &v4, &v2);
            if (grp != -1 && best[grp] > idx) {
                best[grp] = idx;
                found = 1;
                b->field_C[grp] = ids[i];
                b->field_1E[grp] = v2;
                b->field_12[grp] = v4;
            }
        }
    }
    if (!found) {
        b->field_C[0] = D_8006A6DC[1].field_0;
        b->field_1E[0] = D_8006A6DC[1].field_2;
        b->field_12[0] = D_8006A6DC[1].field_4;
    }
}

void func_8006A2D0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_8006A2D8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 masks[2];
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            func_80066120(&w[i]);
        }
        func_800661A4(w, 0xD3F0008);
        masks[0] = 2;
        masks[1] = 4;
        func_800663CC(w, ~masks[arg0->field_8]);
        Task_NextState0(arg0);
    case 1:
        func_80066520(w, 6, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
        break;
    case 2:
    default:
        break;
    }
}

void func_8006A3B8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_8006A40C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}
