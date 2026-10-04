#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"
#include "stag3000/stag3000_96DC_funcs.h"
#include "stag3000/stag3000_9F8C_funcs.h"

s32 func_8006E2BC(s32 id) {
    s32 r = Skill_GetPower(id);

    if (r > 0) {
        return 0;
    }
    if (r < 0) {
        return 1;
    }
    if (Skill_GetCureFlags(id) & 0x20000) {
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

void func_8006EC94(Actor *arg0, s32 arg1) {
    Stg30Xform *t = (Stg30Xform *)arg0->u38.ptr38;

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
            Actor_SetAxisMotion(arg0, 2, &D_800732AC);
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            func_8006E850(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &D_80073294);
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
            func_8006EC5C(arg0);
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            func_8006E850(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &D_800732A0);
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
            func_8006EC5C(arg0);
            func_8006E850(arg0, 0x16);
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
            func_8006E850(arg0, 0x5A);
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
            func_8006E850(arg0, 0x64);
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

void func_8006EF50(Actor *arg0) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)arg0->work;
    Stg30ModelTint *m = (Stg30ModelTint *)arg0->model;
    Stg30WorkWord a1;
    s32 a2;
    Stg30Xform *t;
    Stg30ModelTint *m0;
    Actor **ch;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, &w->field_4, (u16)w->field_10);
        ((Stg30ModelTint *)Gfx_AttachModel(arg0, w->field_14))->otIndex = 3;
        w->anim = -1;
        func_8006E850(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, &((s32 *)arg0->u34.children)[4], (s32)&a1);
        a2 = (s32)arg0;
        Task_Create(0x501, (s32 *)arg0->u34.children, (s32)&a2);
        m0 = (Stg30ModelTint *)arg0->model;
        w->field_18 = 1;
        w->field_1C = 0;
        m0->field_38 = m0->field_39 = m0->field_3A = 0x80;
        w->color.r = w->color.g = w->color.b = 0;
        w->field_28 = 1;
        if (w->field_38 != 0) {
            func_8006E850(arg0, 0x64);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            func_8006E850(arg0, 0);
            Task_SetState0(arg0, 1);
            break;
        case 6:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_8006EB24(arg0);
                arg0->elapsed = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->elapsed >= 0x78) {
                    Task_SetState0(arg0, 1);
                }
                break;
            }
            break;
        case 11:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                func_8006E850(arg0, 0x5A);
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
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_8006EB24(arg0);
                if (w->anim == 0) {
                    Task_SetState0(arg0, 1);
                    break;
                }
                func_8006E850(arg0, 0x5A);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 1:
            w->field_2C = arg0->stateLevel4;
            k = func_8001EE10(w->field_2C);
            func_8006E978(arg0, k);
            switch (k) {
            case 0:
            default:
                func_8006E850(arg0, 0x32);
                break;
            case 1:
                func_8006E850(arg0, 0x3C);
                break;
            case 2:
                func_8006E850(arg0, 0x46);
                break;
            }
            Task_SetState0(arg0, 1);
            break;
        case 2:
            func_8006E850(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_8006EB24(arg0);
                func_8006E850(arg0, 0xA);
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
                func_8006EB24(arg0);
                Task_NextState2(arg0);
            case 1:
                func_8006EC94(arg0, arg0->stateLevel1 - 4);
                break;
            }
            break;
        case 13:
            w->field_2C = arg0->stateLevel4;
            func_8006EB24(arg0);
            if (arg0->model->animId != 0) {
                func_8006E850(arg0, 0);
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
            if (w->color.g < 0xEF) {
                w->color.g += 0x10;
            } else {
                w->color.g = 0xFF;
            }
            if (m->field_38 == 0 && w->color.g == 0xFF) {
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
            if (w->color.g > 0x10) {
                w->color.g -= 0x10;
            } else {
                w->color.g = 0;
            }
            if (m->field_38 == 0x80 && w->color.g == 0) {
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
        arg0->childCount = 5;
    } else {
        arg0->childCount = 4;
    }
    if (w->field_24 != D_80074094) {
        ch = (Actor **)arg0->u34.children;
        if (D_80074094 != 0) {
            if (ch[0]->stateLevel0 == 2) {
                Task_SetState1(ch[0], 1);
            }
        } else {
            if (ch[0]->stateLevel0 == 1) {
                Task_SetState0(ch[0], 2);
            }
        }
        w->field_24 = D_80074094;
    }
    if (w->field_30 != 0 && --w->field_30 == 1) {
        t = (Stg30Xform *)arg0->u38.ptr38;
        t->field_30 = w->field_4;
        t->field_38 = w->field_C;
        t->field_50 = 0;
        t->field_48 = 0;
        Actor_StopAxisMotion(arg0, 2);
    }
}

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

void func_8006FA28(Actor *a0) {
    Stg30WorkVec3 *w = (Stg30WorkVec3 *)a0->work;
    Stg30Part *p = NULL;
    Stg30Part *q;
    s32 draw = 1;
    s32 id;

    switch (w->pos.x) {
    case 0:
    default:
        p = (Stg30Part *)Cd_GetFileEntry(Skill_GetPartsEntry(w->pos.y));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        p = (Stg30Part *)Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, D_80073300[w->pos.x - 4]);
        break;
    case 1:
    case 2:
    case 3:
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber((GfxPart *)p, D_8007331C[w->pos.x - 1], 3, w->pos.y);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, D_80073310[w->pos.x - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (q = p; q->fileId != 0; q++) {
            if (w->field_C != 0x1000) {
                q->field_E = 0;
                q->field_10 = w->field_C;
            } else {
                q->field_E = 1;
            }
            q->palette = w->field_10;
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    if (w->pos.z != 0) {
        switch (w->pos.z >> 8) {
        case 0:
        default:
            id = 0x1A10026;
            break;
        case 1:
            id = 0x1A10027;
            break;
        case 2:
            id = 0x1A10028;
            break;
        }
        p = (Stg30Part *)Cd_GetFileEntry(id);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, ~(1 << ((u8)w->pos.z - 1)));
        for (q = p; q->fileId != 0; q++) {
            if (w->field_C != 0x1000) {
                q->field_E = 0;
                q->field_10 = w->field_C;
            } else {
                q->field_E = 1;
            }
            q->palette = w->field_10;
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}
