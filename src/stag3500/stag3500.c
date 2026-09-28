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
    arg0->load->field_C = arg1;
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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065930);

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

void func_80065B3C(Stg35SpriteHandle *arg0, s16 arg1) {
    arg0->sprite->field_1C = arg1;
}

void func_80065B48(Stg35SpriteHandle *arg0, s16 arg1) {
    arg0->sprite->field_1E = arg1;
}

void func_80065B54(Stg35SpriteHandle *arg0, s16 arg1) {
    arg0->sprite->field_18 = arg1;
}

void func_80065B60(Stg35SpriteHandle *arg0, s16 arg1) {
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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065E60);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065F8C);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066408);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066480);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066520);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006659C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066618);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066694);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066778);

void func_800667D0(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;

    if (w->field_34 != arg1) {
        w->field_34 = arg1;
        Anim_SetModelAnim(arg0, arg1);
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066808);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800668F8);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066A9C);

void func_80066BC8(Actor *arg0) {
    Snd_PlayById(!func_8001E8D0(arg0->digiId) ? 0x204 : 0x205, 0);
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066C00);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066EBC);

void func_800673C4(Actor *arg0) {
    arg0->childCount = 4;
    Task_DefaultDestroy(arg0);
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800673E8);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067510);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006768C);

void func_800676E0(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}

void func_80067720(void) {
    Mem_Zero(D_8006AA88, 0x358);
}

void func_80067748(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067768);

void func_8006799C(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800679D0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067B18);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067C74);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067E48);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800689FC);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068AA0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068B10);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068B9C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068BF8);

s32 func_80068C5C(void) {
    TaskEntry *e = Task_FindFirst(0x708, -1, -1);

    if (e != NULL) {
        return ((Stg35Work708 *)e->work)->field_74;
    }
    return 1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068CA0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068D34);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006926C);

s32 func_80069850(s32 arg0) {
    func_8006926C(arg0);
    return 1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80069870);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800698C8);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800699FC);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80069FD4);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A080);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A0D4);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A168);

void func_8006A2D0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A2D8);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A3B8);

void func_8006A40C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}
