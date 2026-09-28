#include "common.h"
#include "stag3000/stag3000.h"

void func_80063898(Actor *a0, s32 a1) {
    a0->field_8 = a1;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800638A0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006399C);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80064FF4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065100);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067DB4);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006A030);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006CA3C);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E690);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E770);

void func_8006E850(Actor *a0, s32 anim) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;

    if (w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a0, anim);
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E888);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E978);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EB24);

void func_8006EC5C(Actor *a0) {
    Snd_PlayById(func_8001E8D0(a0->digiId) == 0 ? 0x204 : 0x205, 0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EC94);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EF50);

void func_8006F530(Actor *a0) {
    a0->childCount = 5;
    Task_DefaultDestroy(a0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F554);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F69C);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F8EC);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800702C8);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070588);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071C14);

void func_80071D70(Actor *a0, Stg30Init737A0 *args) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;

    w->field_0 = args->field_0;
    for (i = 0; i < 12; i++) {
        w->field_74[0][i] = args->field_4[i];
    }
    Snd_PlayById(0x2B, 0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071DC4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071F9C);

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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800726E8);

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
