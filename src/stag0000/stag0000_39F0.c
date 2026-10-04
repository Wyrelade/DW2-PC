#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/stag0000_1AE4_funcs.h"

void Stg00_GroupViewDraw(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, Stg00_GroupWinMasks[((Stg00PartsWork *)arg0->work)->field_C]);
    Gfx_DrawParts(e);
}

void Stg00_DigiModelInit(Actor *arg0, Stg00ModelArg *arg1) {
    Stg00ModelWork *w;

    arg0->digiId = arg1->field_0;
    w = (Stg00ModelWork *)arg0->work;
    w->field_14 = Digi_GetModelFile(arg1->field_0);
    w->field_4 = arg1->field_4;
    w->field_10 = arg1->field_10;
}

void Stg00_SpawnSkillCastFx(Actor *arg0, s32 arg1) {
    Stg00SpawnWork *w = (Stg00SpawnWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs args;
    s16 a[3];
    s16 b[3];
    Row6 rows[3];
    Stg00TaskArgs3 args2;
    Row6 *r;
    s32 i;

    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(arg0->digiId, rows);
    r = &rows[arg1];
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
                args.field_C -= r->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += r->data[0];
                    args.field_10 -= 0x100 + r->data[2];
                } else {
                    args.field_8 -= r->data[0];
                    args.field_10 += 0x100 + r->data[2];
                }
                break;
            case 2:
                break;
            }
            Task_Create(7, &slot[i + 1], (s32)&args);
        }
    }
    args2.field_4 = w->field_2C;
    args2.field_0 = 0;
    args2.field_8 = 0;
    Task_Create(0x10B, &slot[4], (s32)&args2);
}

void func_80066FE8(Actor *arg0) {
    Stg00SpawnWork *w = (Stg00SpawnWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs args;
    s16 a[3];
    s16 b[3];
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
                break;
            }
            Task_Create(7, &slot[i + 1], (s32)&args);
        }
    }
}

void func_80067120(Actor *arg0, s32 arg1, s32 arg2) {
    Stg00Xform *t = (Stg00Xform *)arg0->u38.ptr38;

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
            if (arg2) {
                Actor_SetAxisMotion(arg0, 2, &D_80068F04);
            }
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            Anim_SetModelAnim(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &D_80068EEC);
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
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            Anim_SetModelAnim(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &D_80068EF8);
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
            Anim_SetModelAnim(arg0, 0x16);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                if (arg1 == 0) {
                    Task_NextState3(arg0);
                }
                Task_NextState3(arg0);
            }
            break;
        }
        break;
    case 3:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Anim_SetModelAnim(arg0, 0x64);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone == 0) {
                break;
            }
            arg0->elapsed = 0;
            Task_NextState4(arg0);
        case 2:
            if (arg0->elapsed >= 0x5A) {
                Task_NextState3(arg0);
            }
            break;
        }
        break;
    case 4:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Anim_SetModelAnim(arg0, 0x5A);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    }
}

void Stg00_ResetToHomePos(Actor *arg0) {
    Stg00Work73FC *w = (Stg00Work73FC *)arg0->work;
    ActorTransformView *t = arg0->u38.ptr38;
    t->posX = w->field_4;
    t->posY = w->field_8;
    t->posZ = w->field_C;
}

void Stg00_DigiModelTask(Actor *arg0) {
    Stg00ModelWorkX *w = (Stg00ModelWorkX *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00ModelFade *m;
    Stg00TaskArg1 a1;
    Stg00TaskArgs3 a3;
    s32 *p;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, (s32 *)&w->field_4, (u16)w->field_10);
        Gfx_AttachModel(arg0, w->field_14)->otIndex = 3;
        Anim_SetModelAnim(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, (s32 *)arg0->u34.children, (s32)&a1);
        w->field_20 = 1;
        w->field_24 = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        default:
            Anim_SetModelAnim(arg0, arg0->stateLevel2);
            Task_SetState0(arg0, 1);
            break;
        case 0:
            switch (arg0->stateLevel2) {
            case 0:
                Anim_SetModelAnim(arg0, 0);
            default:
                arg0->stateLevel2++;
                break;
            case 0x28:
                Stg00_ResetToHomePos(arg0);
                Task_SetState0(arg0, 1);
                break;
            }
            break;
        case 1:
            Stg00_ResetToHomePos(arg0);
            Anim_SetModelAnim(arg0, 0x32);
            Task_SetState0(arg0, 1);
            break;
        case 2:
            Stg00_ResetToHomePos(arg0);
            Anim_SetModelAnim(arg0, 0x3C);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            Stg00_ResetToHomePos(arg0);
            Anim_SetModelAnim(arg0, 0x46);
            Task_SetState0(arg0, 1);
            break;
        case 4:
            Stg00_ResetToHomePos(arg0);
            Anim_SetModelAnim(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 5:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Anim_SetModelAnim(arg0, 0xA);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 6:
        case 7:
            w = (Stg00ModelWorkX *)arg0->work;
            w->field_1C += Sys_FrameDelta;
            while (w->field_1C >= 2) {
                w->field_1C -= 2;
                func_80067120(arg0, arg0->stateLevel1 - 6, 0);
            }
            break;
        case 8:
            m = (Stg00ModelFade *)arg0->model;
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_24 = 1;
                m->field_34 = 1;
                m->field_36 = 0x20;
                m->field_38 = m->field_39 = m->field_3A = 0x7C;
                w->field_28.r = w->field_28.g = w->field_28.b = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (m->field_38 == 0) {
                    m->field_34 = 0;
                    m->field_36 = 0;
                    w->field_20 = 0;
                    w->field_28.g = 0xFF;
                    Task_SetState0(arg0, 1);
                } else {
                    m->field_39 = m->field_3A = (m->field_38 -= 4);
                    w->field_28.g += 8;
                }
                break;
            }
            break;
        case 9:
            m = (Stg00ModelFade *)arg0->model;
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_20 = 1;
                m->field_34 = 1;
                m->field_36 = 0x20;
                m->field_38 = m->field_39 = m->field_3A = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (m->field_38 == 0x7C) {
                    m->field_34 = 0;
                    m->field_36 = 0;
                    w->field_24 = 0;
                    Task_SetState0(arg0, 1);
                } else {
                    m->field_39 = m->field_3A = (m->field_38 += 4);
                    w->field_28.g -= 8;
                }
                break;
            }
            break;
        case 10:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                switch (arg0->stateLevel3) {
                case 0:
                default:
                    w->field_2C = arg0->stateLevel4;
                    Stg00_ResetToHomePos(arg0);
                    p = Skill_GetShotXa(w->field_2C);
                    a3.field_0 = p[0];
                    a3.field_4 = p[1];
                    a3.field_8 = 1;
                    Task_Create(0x10C, &slot[5], (s32)&a3);
                    Task_NextState3(arg0);
                case 1:
                    if (((Actor *)slot[5])->stateLevel0 == 1) {
                        Task_NextState0((Actor *)slot[5]);
                        k = func_8001EE10(w->field_2C);
                        Stg00_SpawnSkillCastFx(arg0, k);
                        switch (k) {
                        case 0:
                        default:
                            Anim_SetModelAnim(arg0, 0x32);
                            break;
                        case 1:
                            Anim_SetModelAnim(arg0, 0x3C);
                            break;
                        case 2:
                            Anim_SetModelAnim(arg0, 0x46);
                            break;
                        }
                        Task_NextState2(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                }
                break;
            case 1:
                if (arg0->elapsed < 0x96) {
                    break;
                }
                Anim_SetModelAnim(arg0, 0);
                Task_NextState2(arg0);
                arg0->elapsed = 0;
            case 2:
                if (arg0->elapsed < 0x1E) {
                    break;
                }
                func_80066FE8(arg0);
                Task_NextState2(arg0);
                if (Skill_GetPower(w->field_2C) == 0) {
                    Task_NextState2(arg0);
                    break;
                }
            case 3:
                w = (Stg00ModelWorkX *)arg0->work;
                w->field_1C += Sys_FrameDelta;
                while (w->field_1C >= 2) {
                    w->field_1C -= 2;
                    func_80067120(arg0, 0, 1);
                }
                break;
            case 4:
                break;
            }
            break;
        }
        break;
    }
}
