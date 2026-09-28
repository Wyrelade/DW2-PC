#include "common.h"
#include "stag3000/stag3000.h"

void func_80063898(Actor *a0, s32 a1) {
    a0->field_8 = a1;
}

void func_800638A0(Actor *a0) {
    switch (a0->stateLevel0) {
    case 0:
        if (a0->field_8 == 1) Snd_PlayById(0x24, 0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_8) {
        case 0:
        default:
            if (a0->elapsed >= 0x100) Task_SetState0(a0, 3);
            break;
        case 1:
        case 2:
            if (a0->elapsed >= 0x80) Task_SetState0(a0, 3);
            break;
        case 3:
            if (a0->elapsed >= 0x12D && (D_8005F72A & 0x840)) Task_SetState0(a0, 3);
            break;
        }
        break;
case 2: break;
    }
}

void func_8006399C(Actor *a0) {
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(D_80072FC8[a0->field_8]);
    Stg30Part *q;

    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_CycleRange(a0->elapsed, 4, 0, 7);
    }
    if (a0->field_8 == 3) {
        if (D_80073CC0.entries[0].field_0 != 0) {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 1);
        } else {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 2);
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_80063A6C(Actor *a0) {
    if (a0->stateLevel0 == 0) {
        if (D_80073CC0.entries[0].field_0 != 0) {
            a0->digiId = D_80073008;
        } else {
            a0->digiId = D_80072FF0[D_8007300C[D_8005E5DD]];
        }
        Actor_InitTransform(a0, D_80043704, 0);
        Gfx_AttachModel(a0, a0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(a0);
        Task_NextState0(a0);
    }
}

void func_80063B28(Actor *a0) {
    Gfx_AttachModel(a0, a0->digiId);
    Actor_UpdateTransform(a0);
    Gfx_CalcModelBoneMatrices(a0);
    Gfx_DrawTexModel(a0, 1);
}

void func_80063B70(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

void func_80063B80(Actor *a0, s32 file, s32 lba) {
    Stg30Work73040 *w = (Stg30Work73040 *)a0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->count; i++) {
        if (lba < w->lbas[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->count; i < j; j--) {
            w->files[j] = w->files[j - 1];
            w->lbas[j] = w->lbas[j - 1];
        }
    }
    w->files[i] = file;
    w->lbas[i] = lba;
    w->count++;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80063C44);

void func_8006436C(Actor *a0) {
    Stg30Work73040 *w = (Stg30Work73040 *)a0->work;
    s32 i;

    for (i = 0; i < w->field_2E0; i++) {
        if (w->field_260[i] != 0) {
            Cd_FreeFile(w->field_260[i]);
        }
    }
}

void func_800643E0(s32 sel, s32 from, s32 to) {
    s32 i;
    TaskEntry *t;

    for (i = from; i <= to; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            if (sel == -1 || i == sel) {
                Task_SetState01((Actor *)t, 2, 8);
            } else {
                Task_SetState01((Actor *)t, 2, 7);
            }
        }
    }
}

void func_80064480(void) {
    s32 i;
    TaskEntry *t;

    for (i = 0; i < 3; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            Task_SetState01((Actor *)t, 2, 8);
        }
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800644D4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80064B30);

void func_80064FBC(Actor *a0) {
    Text_CloseArray(((Stg30Work73078 *)a0->work)->text, 4);
    Task_DefaultDestroy(a0);
}

void func_80064FF4(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;

    p = (Stg30Part *)Cd_GetFileEntry(0x1A10009);
    Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = -0x92;
            q->y = D_800737E0 * 11 - 0x33;
            while (1) {
                if (a0->elapsed < 0x18) break;
                a0->elapsed = a0->elapsed - 0x18;
            }
            q->palette = D_80073070[a0->elapsed / 4];
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_80065100(Actor *a0) {
    Stg30Work730D0 *w = (Stg30Work730D0 *)a0->work;
    s32 i;
    s32 n;
    s32 id;

    if (w->field_40[0] != 0 && w->field_4C[0] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            switch (func_8001E0C0(id)) {
            case 0x14:
            case 0x1D:
            case 0x1E:
                w->field_58[0][n++] = id;
                break;
            }
        }
        w->field_E8[0] = n;
    } else {
        w->field_E8[0] = 0;
    }
    if (w->field_40[1] != 0 && w->field_4C[1] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            if (func_8001E0C0(id) == 0x1A) {
                w->field_58[1][n++] = id;
            }
        }
        w->field_E8[1] = n;
    } else {
        w->field_E8[1] = 0;
    }
    if (w->field_40[2] != 0 && w->field_4C[2] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            if (func_8001E0C0(id) == 0x19) {
                w->field_58[2][n++] = id;
            }
        }
        w->field_E8[2] = n;
    } else {
        w->field_E8[2] = 0;
    }
}

void func_800652C8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = Item_GetDescText(id);
    } else {
        args.text = Item_GetNameText(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065354);

s32 func_80065540(s32 c) {
    if (c >= 0xE1) {
        return c + 0x2E;
    }
    if (c >= 0xD9) {
        return c + 0x2E;
    }
    if (c >= 0xB0) {
        return c + 0x68;
    }
    if (c >= 0xA6) {
        return c + 0x7E;
    }
    return c + 0x85;
}

void func_80065584(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065594);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065A98);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066000);

void func_800663F8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = func_8001EDD4(id);
    } else {
        args.text = func_8001ED84(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066484);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066698);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066AE0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066DB0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800672B0);

void func_80067530(Actor *a0, s32 a1, s32 a2) {
    a0->stateLevel0 = 2;
    a0->stateLevel1 = a1;
    a0->stateLevel2 = 0;
    a0->stateLevel3 = 0;
    a0->stateLevel4 = a2;
}

void func_8006754C(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            if (i < 3) {
                func_8006F640(l->actors[i], 1);
                func_8006F664(l->actors[i]);
            } else {
                func_8006F640(l->actors[i], 0);
            }
        }
    }
}

void func_800675CC(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            func_8006F640(l->actors[i], 1);
        }
    }
}

void func_80067624(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            func_8006F664(l->actors[i]);
        }
    }
}

s32 func_8006767C(Stg30IdSet *a0, s16 *a1, u8 id) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (a0->ids[i] == id) {
            return 1;
        }
        if (a1[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 func_800676C4(s32 a0, u8 a1) {
    return a0 >= func_8001F0C0(a1);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800676F4);

void func_80067DB4(Stg30ListOwner *a0) {
    Stg30ActorList *l = a0->list;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x203, 1);
        func_8006754C(a0);
        Task_Create(0x505, &l->field_24, 3);
        func_80070D14(0x19);
        Task_NextState2((Actor *)a0);
    case 1:
        if (l->field_24 != 0) {
            break;
        }
        Task_NextState2((Actor *)a0);
    case 2:
        switch (a0->stateLevel3) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState3((Actor *)a0);
        case 1:
            if (D_8005F770.fadeLevel == 0xFF) {
                if (D_80073CC0.entries[0].field_0 != 0) {
                    D_8005F770.field_24 = 2;
                    D_8005F770.nextGameMode = D_8005F770.prevGameMode;
                } else {
                    D_8005F770.nextGameMode = 0x401;
                }
                Task_NextState3((Actor *)a0);
            }
        case 2:
            break;
        }
        break;
    }
}

void func_80067EC4(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_80073CC0.entries[i].field_18 >= 3) {
            D_80073CC0.entries[i].field_34 = D_8005E620.elems[i].field_1C;
            D_80073CC0.entries[i].field_36 = D_8005E620.elems[i].field_1E;
            D_80073CC0.entries[i].field_38 = D_8005E620.elems[i].field_20;
        }
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067F2C);

void func_80068CE0(Actor *a0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (((Stg30StateDigis *)&D_80073CC0)->digis[i].state >= 3) {
            D_8005E620.elems[i] = ((Stg30StateDigis *)&D_80073CC0)->digis[i];
        }
    }
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(a0);
}

s32 func_80068DA4(s32 idx, s32 i, Stg30ByteLists *p) {
    s32 v = p->field_9[i];

    switch (v) {
    case 1:
    case 2:
    case 3:
        if (D_80073CC0.entries[idx].field_32 >= func_8001EE80(p->field_2[i])) {
            return 1;
        }
    case 4:
        return 1;
    default:
        return 0;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80068E34);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800692A4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069594);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800696E8);

s32 func_800699F8(s32 a, s32 b) {
    if (a == b) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 0) {
        return 1;
    }
    return -1;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069A44);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069DE8);

s32 func_8006A030(s32 a, s32 b) {
    if (a == 5) {
        return 0;
    }
    if (b == 5) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 3) {
        return 1;
    }
    if (a == 3 && b == 4) {
        return 1;
    }
    if (a == 4 && b == 0) {
        return 1;
    }
    if (a == 0 && b == 2) {
        return -1;
    }
    if (a == 1 && b == 3) {
        return -1;
    }
    if (a == 2 && b == 4) {
        return -1;
    }
    if (a == 3 && b == 0) {
        return -1;
    }
    if (a == 4 && b == 1) {
        return -1;
    }
    return 0;
}

s32 func_8006A118(void) {
    if (D_8005D5A0.field_103D == 0) {
        return 5;
    }
    return D_8005D5A0.field_103D - 2;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006A140);

void func_8006A968(s16 *max, s16 *b, s16 *c) {
    s16 half = *max / 2;

    *c = *c * 90 / 128;
    if (*c < half) {
        *c = half;
    }
    *b = *b * 90 / 128;
    if (*b < half) {
        *b = half;
    }
}

void func_8006AA18(s16 *max, s16 *b, s16 *c) {
    s16 lim;
    s16 t;

    t = *c + *c / 2;
    lim = *max * 2;
    *c = t;
    if (*c > lim) {
        *c = lim;
    }
    *b += *b / 2;
    if (*b > lim) {
        *b = lim;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006AAA8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006B950);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006BBD8);

void func_8006CA3C(s32 idx) {
    s16 *p = D_80073890;

    *p++ = 2;
    *p++ = idx + 10;
    *p++ = 3;
    *p++ = idx;
    *p++ = 0xE;
    *p++ = 4;
    *p++ = 1;
    *p++ = 0;
    p[0] = 0x78;
    p[1] = 0x18;
    D_80073CC0.entries[idx].field_32 += D_80073CC0.entries[idx].field_30 / 10;
    if (D_80073CC0.entries[idx].field_30 < D_80073CC0.entries[idx].field_32) {
        D_80073CC0.entries[idx].field_32 = D_80073CC0.entries[idx].field_30;
    }
}

s32 func_8006CB28(s32 idx) {
    switch (D_80073CC0.field_2AC[idx].field_0) {
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        func_8006BBD8(idx);
        return 1;
    case 5:
        func_8006CA3C(idx);
        return 1;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006CB8C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006D2EC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006D4D8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006DB90);

s32 func_8006E2BC(s32 id) {
    s32 r = func_8001EF64(id);

    if (r > 0) {
        return 0;
    }
    if (r < 0) {
        return 1;
    }
    if (func_8001F094(id) & 0x20000) {
        return 3;
    }
    return 2;
}

s32 func_8006E31C(s32 team, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = lo; i < lo + 3; i++) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return lo;
}

s32 func_8006E3D0(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = cur - 1; i >= lo; i--) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

s32 func_8006E47C(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;

    for (i = cur + 1; i < team * 3 + 3; i++) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

void func_8006E530(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_80073A20[i] = v;
    }
}

void func_8006E55C(s32 idx, s32 v) {
    s32 i;

    for (i = 10; i >= idx; i--) {
        D_80073A20[i + 1] = D_80073A20[i];
    }
    D_80073A20[idx] = v;
}

void func_8006E5B4(s32 i) {
    for (; i < 11; i++) {
        D_80073A20[i] = D_80073A20[i + 1];
    }
}

s32 func_8006E5F8(s32 v) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (v == D_80073A20[i]) {
            return i;
        }
    }
    return -1;
}

s32 func_8006E634(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_80073A20[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 func_8006E674(s32 i) {
    return D_80073A20[i];
}

void func_8006E690(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_80073A50.digis[i] = ((Stg30StateDigis *)&D_80073CC0)->digis[i];
        D_80073A50.field_228[i] = D_80073CC0.field_31C[i];
        D_80073A50.field_240[i] = D_80073CC0.field_340[i];
        D_80073A50.field_246[i] = D_80073CC0.field_346[i];
        D_80073A50.field_24C[i] = D_80073CC0.field_356[i];
        D_80073A50.field_258[i] = D_80073CC0.field_362[i];
        D_80073A50.field_264[i] = D_80073CC0.field_36E[i];
    }
}

void func_8006E770(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ((Stg30StateDigis *)&D_80073CC0)->digis[i] = D_80073A50.digis[i];
        D_80073CC0.field_31C[i] = D_80073A50.field_228[i];
        D_80073CC0.field_340[i] = D_80073A50.field_240[i];
        D_80073CC0.field_346[i] = D_80073A50.field_246[i];
        D_80073CC0.field_356[i] = D_80073A50.field_24C[i];
        D_80073CC0.field_362[i] = D_80073A50.field_258[i];
        D_80073CC0.field_36E[i] = D_80073A50.field_264[i];
    }
}

void func_8006E850(Actor *a0, s32 anim) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;

    if (w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a0, anim);
    }
}

void func_8006E888(Actor *a0, s32 *args) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    s32 idx = args[1];
    s32 n;

    a0->field_8 = idx;
    a0->digiId = D_80073CC0.entries[idx].field_19;
    w->field_14 = Digi_GetModelFile(a0->digiId);
    if (a0->field_8 < 3) {
        w->field_10 = 0x800;
    } else {
        w->field_10 = 0;
    }
    n = a0->field_8;
    w->field_8 = 0;
    w->field_4 = (n % 3) * 0xA00 - 0xA00;
    w->field_C = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = args[2];
}

void func_8006E978(Actor *a0, s32 k) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    Stg30FxArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    Row6 rows[4];
    Row6 *r;
    s32 i;

    slots = (s32 *)a0->u34.children;
    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(a0->digiId, rows);
    r = &rows[k];
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
                args.field_C += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.field_C -= r->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += r->data[0];
                    args.field_10 += -0x100 - r->data[2];
                } else {
                    args.field_8 -= r->data[0];
                    args.field_10 += 0x100 + r->data[2];
                }
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void func_8006EB24(Actor *a0) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    Stg30FxArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    s32 i;

    slots = (s32 *)a0->u34.children;
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
                args.field_C += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.field_C -= func_8001E7C0(a0->digiId);
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void func_8006EC5C(Actor *a0) {
    Snd_PlayById(func_8001E8D0(a0->digiId) == 0 ? 0x204 : 0x205, 0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EC94);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EF50);

void func_8006F530(Actor *a0) {
    a0->childCount = 5;
    Task_DefaultDestroy(a0);
}

void func_8006F554(Actor *a0) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    CVECTOR c;

    if (w->field_28 != 0) {
        Gfx_AttachModel(a0, w->field_14);
        Anim_StepModelAnim(a0);
        Actor_UpdateTransform(a0);
        Gfx_CalcModelBoneMatrices(a0);
        if (w->field_18 != 0) {
            Gfx_DrawTexModel(a0, 0);
        }
        if (w->field_1C != 0) {
            if (a0->field_8 < 3) {
                c = w->color;
            } else {
                c.r = w->color.g;
                c.g = w->color.r;
                c.b = w->color.b;
            }
            Gfx_DrawWireModel(a0, 0, &c);
        }
    }
}

void func_8006F640(Actor *a0, s32 a1) {
    ((Stg30Work732B8 *)a0->work)->field_28 = a1;
    if (a1 != 0) {
        a0->childCount = 5;
    } else {
        a0->childCount = 4;
    }
}

void func_8006F664(Actor *a0) {
    ((Stg30Work732B8 *)a0->work)->field_30 = 2;
}

void func_8006F674(Stg30TaskHead *a0, s32 *args) {
    a0->field_8 = args[0];
    a0->field_4 = args[1] ? 2 : 4;
}

void func_8006F69C(Stg30TaskHead *a0) {
    Stg30Work732E8 *w = (Stg30Work732E8 *)a0->work;
    s32 snd;

    switch (a0->stateLevel0) {
    case 0:
        switch (a0->field_8) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        default:
            snd = 0x25;
            break;
        case 5:
            if (a0->field_4 == 2) {
                snd = 0x26;
            } else {
                snd = 0x1C;
            }
            break;
        }
        Snd_PlayById(snd, 0);
        Task_NextState0((Actor *)a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->field_4 != 7) {
                w->field_4++;
            }
            w->field_0 += 0x200;
            if (w->field_0 >= 0x1000) {
                w->field_0 = 0x1000;
                w->field_4 = 7;
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                a0->elapsed = 0;
                Task_NextState2((Actor *)a0);
                break;
            case 1:
                if (a0->elapsed >= 0x3C) {
                    Task_NextState0((Actor *)a0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        if (w->field_4 != 0) {
            w->field_4--;
        } else {
            Task_SetState0((Actor *)a0, 3);
        }
        break;
    }
}

void func_8006F820(Stg30TaskHead *a0) {
    Stg30Work732E8 *w = (Stg30Work732E8 *)a0->work;
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(D_800732D0[a0->field_8]);
    Stg30Part *q;
    s32 vis;

    for (q = p; q->fileId != 0; q++) {
        vis = q->groupMask == a0->field_4;
        q->field_E = 0;
        q->visible = vis;
        q->field_10 = w->field_0;
        q->palette = w->field_4;
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_8006F8CC(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void func_8006F8EC(Actor *a0) {
    Stg30WorkVec3 *w = (Stg30WorkVec3 *)a0->work;
    s32 t;

    switch (a0->stateLevel0) {
    case 0:
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->field_10++;
            w->field_C += 0x200;
            if (w->field_10 != 7) {
                break;
            }
            a0->elapsed = 0;
            w->field_C = 0x1000;
            Task_NextState1(a0);
        case 1:
            t = w->pos.x;
            if (t != 7) {
                if (a0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->field_10 = Math_CycleRange(a0->elapsed, 2, 8, 0xF);
                if (a0->elapsed < 0x90) {
                    break;
                }
                w->field_10 = t;
            }
            Task_NextState1(a0);
        case 2:
            if (--w->field_10 < 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FA28);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FC78);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FFD0);

void func_800701FC(void) {
    Mem_Zero(&D_80073CC0, 0x3E0);
    D_80073CC0.field_3D4 = 1;
    if ((D_8005F770.prevGameMode & 0xFF00) == 0x300) {
        D_8005D5A0.field_103D = 0;
        D_8005D5A0.field_1040 = 0;
        D_80073CC0.entries[0].field_0 = 1;
    }
    if (D_8005F770.field_24 == 0x97 && Flag_Test(0x88)) {
        D_8005F770.field_24++;
    }
    D_80074098 = 4;
}

void func_800702A8(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void func_800702C8(Stg30TaskHead *a0) {
    Stg30Work733F0 *w = (Stg30Work733F0 *)a0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 lba;
    s32 r;

    switch (a0->stateLevel0) {
    case 0:
    default:
        switch (a0->stateLevel1) {
        case 0:
        default:
            lba = Cd_GetFileLba(w->file) + D_800733C0[w->track - 1];
            w->field_C = lba;
            w->field_10 = lba + D_800733D8[w->track - 1];
            param[0] = 1;
            param[1] = w->channel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->field_C, loc);
            CdControlF(0x15, loc);
            Task_NextState1((Actor *)a0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0((Actor *)a0, 0);
                break;
            case 2:
                Task_NextState0((Actor *)a0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->field_C, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            if (a0->field_24 & 0x1F) {
                break;
            }
            switch (CdSync(1, res2)) {
            case 5:
                Task_SetState0((Actor *)a0, 3);
                break;
            case 2:
                if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->field_10) {
                    Task_SetState0((Actor *)a0, 3);
                } else {
                    CdControlF(0x11, 0);
                }
                break;
            }
            break;
        }
        break;
    }
}

void func_800704FC(Actor *a0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a0);
}

s32 func_80070530(s32 a, s32 b) {
    s32 neg = 0;
    s32 r;
    a -= b;
    if (a == 0) {
        return neg;
    }
    if (a < 0) {
        neg = 1;
        a = -a;
    }
    r = a / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void func_80070588(Stg30Work7343C *w, Stg30CamGoal *g) {
    s32 i;

    for (i = 0; i < D_8005F770.frameDelta; i++) {
        w->field_7E += func_80070530(g->field_0, w->field_7E);
        w->field_0 += func_80070530(g->field_4, w->field_0);
        w->field_4 += func_80070530(g->field_8, w->field_4);
        w->field_8 += func_80070530(g->field_C, w->field_8);
        w->field_10 += func_80070530(g->field_10, w->field_10);
        w->field_6C += func_80070530(g->field_14, w->field_6C);
        w->field_74 += func_80070530(g->field_18, w->field_74);
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800706BC);

void func_80070C68(Actor *a0) {
    Stg30Work7343C *w = (Stg30Work7343C *)a0->work;
    Stg30RefView rv;

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

void func_80070D14(u8 state) {
    Actor *t = (Actor *)Task_FindFirst(0x503, -1, -1);

    if (t != NULL && t->stateLevel0 == 1) {
        Task_SetState1(t, state);
    }
}

void func_80070D68(Actor *a0, Stg30Ref **args) {
    ((Stg30Work734F8 *)a0->work)->ref = args[0];
    a0->field_8 = args[0]->field_8;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070D8C);

void func_8007100C(Actor *a0) {
    Text_CloseArray(((Stg30Work734F8 *)a0->work)->text, 2);
    Task_DefaultDestroy(a0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071044);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007118C);

void func_80071470(Actor *a0, Stg30Pair *args) {
    ((Stg30Work73718 *)a0->work)->pair = *args;
}

u8 *func_80071488(u8 *out, s32 n) {
    u8 buf[8];
    s32 i;
    s32 lead;
    s32 k;

    for (i = 7; i != -1; i--) {
        buf[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    k = 0;
    for (i = 0; i < 8; i++) {
        if (!lead || buf[i] != 0) {
            out[k++] = buf[i];
            lead = 0;
        }
    }
    out[k] = 0xFF;
    return out;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071538);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007191C);

void func_80071BDC(Actor *a0) {
    Text_CloseArray(((Stg30Work73718 *)a0->work)->text, 14);
    Task_DefaultDestroy(a0);
}

void func_80071C14(Actor *a0) {
    Stg30Work73718 *w = (Stg30Work73718 *)a0->work;
    GfxPart *p;
    s32 i;
    s32 draw;

    for (i = 0; i < 6; i++) {
        draw = 1;
        p = (GfxPart *)Cd_GetFileEntry(D_80073700[i]);
        switch (i) {
        case 0:
        case 1:
        case 2:
            if (D_80073CC0.entries[i].field_19 == 0) {
                draw = 0;
                break;
            }
            if (D_80073CC0.field_34C[i] != 0) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0x10);
            }
            Gfx_SetPartsNumber(p, 1, 8, D_80073CC0.entries[i].field_28);
            Gfx_SetPartsNumber(p, 4, 8, w->field_18[i]);
            Gfx_SetPartsNumber(p, 8, 2, D_80073CC0.entries[i].field_25);
            break;
        case 4:
            Gfx_SetPartsNumber(p, 1, 8, D_8005E620.field_8);
            break;
        }
        if (draw) {
            Gfx_DrawParts((EntA0 *)p);
        }
    }
}

void func_80071D70(Actor *a0, Stg30Init737A0 *args) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;

    w->field_0 = args->field_0;
    for (i = 0; i < 12; i++) {
        w->field_74[0][i] = args->field_4[i];
    }
    Snd_PlayById(0x2B, 0);
}

void func_80071DC4(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 row;
    s32 col;
    s32 k;
    s32 *slot;
    s32 item;
    s32 id;
    s32 scroll;

    for (row = 0; row < 2; row++) {
        scroll = w->field_B0[row];
        for (col = 0; col < 10; col++) {
            k = row * 10 + col;
            slot = &w->texts[k];
            Text_Close(slot);
            item = w->field_74[row][col + scroll];
            if (item != 0) {
                Text_OpenPacked(slot, func_8001ED84(item), 0, D_80073730[k + 4]);
            }
        }
    }
    Text_Close(&w->field_70);
    id = w->field_74[w->field_A4][w->field_B0[w->field_A4] + w->field_A8[w->field_A4]];
    if (id != 0 && w->field_C8 == 0) {
        Text_OpenPacked(&w->field_70, func_8001EDD4(id), 0, D_80073730[27]);
        w->field_C0 = func_8001EE80(id);
    } else {
        w->field_C0 = 0;
    }
}

void func_80071F9C(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Text_Close(&w->text[i]);
        if (w->field_C8 == 0 || w->field_C4 != i || !(a0->elapsed & 0x10)) {
            s32 c;
            if (w->field_C4 == i) c = 4; else c = 5;
            Text_OpenById(&w->text[i], i + 0x188, c, D_80073730[i + 24]);
        }
    }
}

void func_80072080(Actor *a0, s32 row) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;
    s32 n;

    i = 0;
    n = i;
    for (; i < 12; i++) {
        if (w->field_74[row][i] != 0) {
            w->field_74[row][n] = w->field_74[row][i];
            if (i != n) {
                w->field_74[row][i] = 0;
            }
            n++;
        }
    }
    w->field_B8[row] = n;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800720E4);

void func_800726E8(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;

    p = (GfxPart *)Cd_GetFileEntry(0x1A1001B);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001C);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001D);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 0x4000) {
            if (w->field_C8 != 0) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->field_A4 != 0 ? 3 : -0x85;
                q->y = w->field_A8[w->field_A4] * 11 - 0x15;
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
    }
    Gfx_SetPartsNumber(p, 0x800, 3, w->field_C0);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001E);
    m = (w->field_B0[0] == 0) << 1;
    if (w->field_B0[0] + 10 >= w->field_B8[0]) {
        m |= 8;
    }
    if (w->field_B0[1] == 0) {
        m |= 0x20;
    }
    if (w->field_B0[1] + 10 >= w->field_B8[1]) {
        m |= 0x80;
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    Gfx_DrawParts((EntA0 *)p);
}

void func_800728A0(Actor *a0, s32 *args) {
    s32 idx = args[0];

    ((Stg30Work737C8 *)a0->work)->index = idx;
    a0->digiId = D_80073CC0.entries[idx].field_19;
}

void func_800728D8(Actor *a0, s32 a1) {
    DigiRosterEntry *e = &D_8005F398;

    Digi_InitFromTable(D_8005F794, ((Stg30WorkWord *)a0->work)->field_0 - 3, e);
    if (a1 != 0) {
        e->state = 1;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007292C);

void func_80072F84(Actor *a0) {
    if (((Stg30Work737C8 *)a0->work)->field_10 != 0) {
        Gfx_DrawParts(Cd_GetFileEntry(0x1A10017));
    }
}
