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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800635D4);

void func_8006363C(Actor *arg0) {
    Gfx_AttachModel(arg0, arg0->digiId);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void func_80063684(Actor *arg0, s32 *arg1) {
    ((Stg35Work *)arg0->work)->field_0 = *arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063694);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063758);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063E00);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063E74);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063F38);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800645B4);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80064638);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800646C0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80064AF0);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80064BB0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80064C54);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065824);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065B88);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065BE0);

void func_80065D00(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_8006AA58[i] = v;
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065D2C);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065E04);

s32 func_80065E44(s32 arg0) {
    return D_8006AA58[arg0];
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065E60);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80065F8C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066120);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066168);

void func_800661A4(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->fileId = arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800661B0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800663CC);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800667D0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066808);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800668F8);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066A9C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80066BC8);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800676E0);

void func_80067720(void) {
    Mem_Zero(D_8006AA88, 0x358);
}

void func_80067748(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067768);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006799C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800679D0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067B18);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067C74);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067E48);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_800689FC);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068AA0);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068B10);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068B9C);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068BF8);

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80068C5C);

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

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_8006A40C);
