#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_FighterInit(Actor *arg0, Stg35Vec3 *arg1);
void Stg35_FighterTask(Actor *arg0);
void Stg35_FighterDestroy(Actor *arg0);
void Stg35_FighterDraw(Actor *arg0);

Elem12 Stg35_HitReactHop1Motion = { -0x18000, 0x2666, 0x320000 };
Elem12 Stg35_HitReactHop2Motion = { -0x14000, 0x2666, 0x320000 };
Elem12 Stg35_HitReactPushMotion = { 0x18000, -0x2000, 0x320000 };
TaskDesc Stg35_FighterDesc = {
    (TaskInitFn)Stg35_FighterInit, Stg35_FighterTask, Stg35_FighterDestroy, Stg35_FighterDraw, 0x3C, 0x10,
};

void Stg35_FighterSetAnim(Actor *arg0, s32 arg1) {
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;

    if (w->curAnim != arg1) {
        w->curAnim = arg1;
        Anim_SetModelAnim(arg0, arg1);
    }
}

void Stg35_FighterInit(Actor *arg0, Stg35Vec3 *arg1) {
    s32 i = arg1->field_4;
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;
    s32 n;

    arg0->param = i;
    arg0->digiId = Stg35_Battle.rec[i].digiId;
    w->modelFile = Digi_GetModelFile(arg0->digiId);
    if (arg0->param < 3) {
        w->facing = 0x800;
    } else {
        w->facing = 0;
    }
    n = arg0->param;
    w->homeY = 0;
    w->homeX = (n % 3) * 0xA00 - 0xA00;
    w->homeZ = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = arg1->field_8;
}

void Stg35_SpawnSkillCastFx(Actor *arg0, s32 arg1) {
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    Row6 ofs[3];
    Row6 *o;
    s32 i;

    Skill_GetFxSet(w->skillId, 0, a, b);
    Digi_GetCastFxOffsets(arg0->digiId, ofs);
    o = &ofs[arg1];
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.facing = w->facing;
            args.posX = w->homeX;
            args.posY = w->homeY;
            args.posZ = w->homeZ;
            args.field_18 = 0x78;
            switch (i) {
            case 0:
                args.posY -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.posY -= o->data[1];
                if (args.facing == 0) {
                    args.posX += o->data[0];
                    args.posZ -= 0x100 + o->data[2];
                } else {
                    args.posX -= o->data[0];
                    args.posZ += 0x100 + o->data[2];
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
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    s32 i;

    Skill_GetFxSet(w->skillId, 1, a, b);
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.facing = w->facing;
            args.posX = w->homeX;
            args.posY = w->homeY;
            args.posZ = w->homeZ;
            args.field_18 = 0x3C;
            switch (i) {
            case 0:
                args.posY -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.posY -= func_8001E7C0(arg0->digiId);
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
            if (t->posY > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->posY = 0;
                t->moveDeltaY = 0;
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
            if (t->posY > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->posY = 0;
                t->moveDeltaY = 0;
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
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;
    Stg35ModelFade *m = (Stg35ModelFade *)arg0->model;
    Stg35Arg1 a1;
    Stg35Xform *t;
    Stg35ModelFade *m0;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, &w->homeX, (u16)w->facing);
        Gfx_AttachModel(arg0, w->modelFile)->otIndex = 3;
        w->curAnim = -1;
        Stg35_FighterSetAnim(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, &((s32 *)arg0->u34.children)[3], (s32)&a1);
        m0 = (Stg35ModelFade *)arg0->model;
        w->drawTex = 1;
        w->drawWire = 0;
        m0->flatR = m0->flatG = m0->flatB = 0x80;
        w->wireColor.r = w->wireColor.g = w->wireColor.b = 0;
        w->visible = 1;
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
                w->skillId = arg0->stateLevel4;
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
            w->skillId = arg0->stateLevel4;
            k = Skill_GetCastAnim(w->skillId);
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
                w->skillId = arg0->stateLevel4;
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
                w->skillId = arg0->stateLevel4;
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
            w->skillId = arg0->stateLevel4;
            Stg35_SpawnSkillHitFx(arg0);
            if (arg0->model->animId != 0) {
                Stg35_FighterSetAnim(arg0, 0);
            }
            Task_SetState0(arg0, 1);
            break;
        case 7:
            w->drawTex = 1;
            w->drawWire = 1;
            m->field_34 = 1;
            m->tpageBits = 0x20;
            if (m->flatR > 8) {
                m->flatR -= 8;
            } else {
                m->flatR = 0;
            }
            m->flatG = m->flatB = m->flatR;
            if (w->wireColor.g < 0xEF) {
                w->wireColor.g += 0x10;
            } else {
                w->wireColor.g = 0xFF;
            }
            if (m->flatR == 0 && w->wireColor.g == 0xFF) {
                m->field_34 = 0;
                m->tpageBits = 0;
                w->drawTex = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 8:
            w->drawTex = 1;
            w->drawWire = 1;
            m->field_34 = 1;
            m->tpageBits = 0x20;
            if (m->flatR < 0x78) {
                m->flatR += 8;
            } else {
                m->flatR = 0x80;
            }
            m->flatG = m->flatB = m->flatR;
            if (w->wireColor.g > 0x10) {
                w->wireColor.g -= 0x10;
            } else {
                w->wireColor.g = 0;
            }
            if (m->flatR == 0x80 && w->wireColor.g == 0) {
                m->field_34 = 0;
                m->tpageBits = 0;
                w->drawWire = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 10:
            w->visible = 0;
            break;
        case 9:
            m->flatR = m->flatG = m->flatB = 0x80;
            m->field_34 = 0;
            m->tpageBits = 0;
            w->drawTex = 1;
            w->drawWire = 0;
            w->visible = 1;
            Task_SetState0(arg0, 1);
            break;
        }
        break;
    }
    if (w->visible != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
    if (w->homeResetTimer != 0 && --w->homeResetTimer == 1) {
        t = (Stg35Xform *)arg0->u38.ptr38;
        t->posX = w->homeX;
        t->posZ = w->homeZ;
        t->moveDeltaZ = 0;
        t->moveDeltaX = 0;
        Actor_StopAxisMotion(arg0, 2);
    }
}

void Stg35_FighterDestroy(Actor *arg0) {
    arg0->childCount = 4;
    Task_DefaultDestroy(arg0);
}

void Stg35_FighterDraw(Actor *arg0) {
    Stg35FighterWork *w = (Stg35FighterWork *)arg0->work;
    CVECTOR c;

    if (w->visible != 0) {
        Gfx_AttachModel(arg0, w->modelFile);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        if (w->drawTex != 0) {
            Gfx_DrawTexModel(arg0, 0);
        }
        if (w->drawWire != 0) {
            if (arg0->param < 3) {
                c = w->wireColor;
            } else {
                c.r = w->wireColor.g;
                c.g = w->wireColor.r;
                c.b = w->wireColor.b;
            }
            Gfx_DrawWireModel(arg0, 0, &c);
        }
    }
}

void Stg35_FighterSetVisible(Actor *arg0, s32 arg1) {
    ((Stg35FighterWork *)arg0->work)->visible = arg1;
    if (arg1 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
}

void Stg35_FighterQueueHomeReset(Actor *arg0) {
    ((Stg35FighterWork *)arg0->work)->homeResetTimer = 2;
}
