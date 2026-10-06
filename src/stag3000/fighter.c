#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_FighterInit(Actor *a0, s32 *args);
void Stg30_FighterTask(Actor *arg0);
void Stg30_FighterDestroy(Actor *a0);
void Stg30_FighterDraw(Actor *a0);

Elem12 Stg30_HitReactHop1Motion = { -0x18000, 0x2666, 0x320000 };
Elem12 Stg30_HitReactHop2Motion = { -0x14000, 0x2666, 0x320000 };
Elem12 Stg30_HitReactPushMotion = { 0x18000, -0x2000, 0x320000 };
TaskDesc Stg30_FighterDesc = {
    (TaskInitFn)Stg30_FighterInit, Stg30_FighterTask, Stg30_FighterDestroy, Stg30_FighterDraw, 0x3C, 0x14,
};

void Stg30_FighterSetAnim(Actor *a0, s32 anim) {
    Stg30FighterWork *w = (Stg30FighterWork *)a0->work;

    if (w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a0, anim);
    }
}

void Stg30_FighterInit(Actor *a0, s32 *args) {
    Stg30FighterWork *w = (Stg30FighterWork *)a0->work;
    s32 idx = args[1];
    s32 n;

    a0->param = idx;
    a0->digiId = Stg30_Battle.entries[idx].digiId;
    w->modelFile = Digi_GetModelFile(a0->digiId);
    if (a0->param < 3) {
        w->facing = 0x800;
    } else {
        w->facing = 0;
    }
    n = a0->param;
    w->homeY = 0;
    w->homeX = (n % 3) * 0xA00 - 0xA00;
    w->homeZ = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = args[2];
}

void Stg30_SpawnSkillCastFx(Actor *a0, s32 k) {
    Stg30FighterWork *w = (Stg30FighterWork *)a0->work;
    Stg30SpawnArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    Row6 rows[4];
    Row6 *r;
    s32 i;

    slots = (s32 *)a0->u34.children;
    Skill_GetFxSet(w->skillId, 0, a, b);
    Digi_GetCastFxOffsets(a0->digiId, rows);
    r = &rows[k];
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
                args.posY += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.posY -= r->data[1];
                if (args.facing == 0) {
                    args.posX += r->data[0];
                    args.posZ += -0x100 - r->data[2];
                } else {
                    args.posX -= r->data[0];
                    args.posZ += 0x100 + r->data[2];
                }
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void Stg30_SpawnSkillHitFx(Actor *a0) {
    Stg30FighterWork *w = (Stg30FighterWork *)a0->work;
    Stg30SpawnArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    s32 i;

    slots = (s32 *)a0->u34.children;
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
                args.posY += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.posY -= func_8001E7C0(a0->digiId);
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void Stg30_PlayHitReactSound(Actor *a0) {
    Snd_PlayById(func_8001E8D0(a0->digiId) == 0 ? 0x204 : 0x205, 0);
}

void Stg30_HitReactUpdate(Actor *arg0, s32 arg1) {
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
            Actor_SetAxisMotion(arg0, 2, &Stg30_HitReactPushMotion);
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            Stg30_FighterSetAnim(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &Stg30_HitReactHop1Motion);
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
            Stg30_PlayHitReactSound(arg0);
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            Stg30_FighterSetAnim(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &Stg30_HitReactHop2Motion);
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
            Stg30_PlayHitReactSound(arg0);
            Stg30_FighterSetAnim(arg0, 0x16);
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
            Stg30_FighterSetAnim(arg0, 0x5A);
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
            Stg30_FighterSetAnim(arg0, 0x64);
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

void Stg30_FighterTask(Actor *arg0) {
    Stg30FighterWork *w = (Stg30FighterWork *)arg0->work;
    Stg30ModelTint *m = (Stg30ModelTint *)arg0->model;
    Stg30WorkWord a1;
    s32 a2;
    Stg30Xform *t;
    Stg30ModelTint *m0;
    Actor **ch;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, &w->homeX, (u16)w->facing);
        ((Stg30ModelTint *)Gfx_AttachModel(arg0, w->modelFile))->otIndex = 3;
        w->anim = -1;
        Stg30_FighterSetAnim(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, &((s32 *)arg0->u34.children)[4], (s32)&a1);
        a2 = (s32)arg0;
        Task_Create(0x501, (s32 *)arg0->u34.children, (s32)&a2);
        m0 = (Stg30ModelTint *)arg0->model;
        w->drawTex = 1;
        w->drawWire = 0;
        m0->flatR = m0->flatG = m0->flatB = 0x80;
        w->color.r = w->color.g = w->color.b = 0;
        w->visible = 1;
        if (w->field_38 != 0) {
            Stg30_FighterSetAnim(arg0, 0x64);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Stg30_FighterSetAnim(arg0, 0);
            Task_SetState0(arg0, 1);
            break;
        case 6:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->skillId = arg0->stateLevel4;
                Stg30_SpawnSkillHitFx(arg0);
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
                Stg30_FighterSetAnim(arg0, 0x5A);
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
                w->skillId = arg0->stateLevel4;
                Stg30_SpawnSkillHitFx(arg0);
                if (w->anim == 0) {
                    Task_SetState0(arg0, 1);
                    break;
                }
                Stg30_FighterSetAnim(arg0, 0x5A);
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
            w->skillId = arg0->stateLevel4;
            k = Skill_GetCastAnim(w->skillId);
            Stg30_SpawnSkillCastFx(arg0, k);
            switch (k) {
            case 0:
            default:
                Stg30_FighterSetAnim(arg0, 0x32);
                break;
            case 1:
                Stg30_FighterSetAnim(arg0, 0x3C);
                break;
            case 2:
                Stg30_FighterSetAnim(arg0, 0x46);
                break;
            }
            Task_SetState0(arg0, 1);
            break;
        case 2:
            Stg30_FighterSetAnim(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->skillId = arg0->stateLevel4;
                Stg30_SpawnSkillHitFx(arg0);
                Stg30_FighterSetAnim(arg0, 0xA);
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
                Stg30_SpawnSkillHitFx(arg0);
                Task_NextState2(arg0);
            case 1:
                Stg30_HitReactUpdate(arg0, arg0->stateLevel1 - 4);
                break;
            }
            break;
        case 13:
            w->skillId = arg0->stateLevel4;
            Stg30_SpawnSkillHitFx(arg0);
            if (arg0->model->animId != 0) {
                Stg30_FighterSetAnim(arg0, 0);
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
            if (w->color.g < 0xEF) {
                w->color.g += 0x10;
            } else {
                w->color.g = 0xFF;
            }
            if (m->flatR == 0 && w->color.g == 0xFF) {
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
            if (w->color.g > 0x10) {
                w->color.g -= 0x10;
            } else {
                w->color.g = 0;
            }
            if (m->flatR == 0x80 && w->color.g == 0) {
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
        arg0->childCount = 5;
    } else {
        arg0->childCount = 4;
    }
    if (w->lastHudFlag != Stg30_Battle.interruptActive) {
        ch = (Actor **)arg0->u34.children;
        if (Stg30_Battle.interruptActive != 0) {
            if (ch[0]->stateLevel0 == 2) {
                Task_SetState1(ch[0], 1);
            }
        } else {
            if (ch[0]->stateLevel0 == 1) {
                Task_SetState0(ch[0], 2);
            }
        }
        w->lastHudFlag = Stg30_Battle.interruptActive;
    }
    if (w->homeResetTimer != 0 && --w->homeResetTimer == 1) {
        t = (Stg30Xform *)arg0->u38.ptr38;
        t->posX = w->homeX;
        t->posZ = w->homeZ;
        t->moveDeltaZ = 0;
        t->moveDeltaX = 0;
        Actor_StopAxisMotion(arg0, 2);
    }
}

void Stg30_FighterDestroy(Actor *a0) {
    a0->childCount = 5;
    Task_DefaultDestroy(a0);
}

void Stg30_FighterDraw(Actor *a0) {
    Stg30FighterWork *w = (Stg30FighterWork *)a0->work;
    CVECTOR c;

    if (w->visible != 0) {
        Gfx_AttachModel(a0, w->modelFile);
        Anim_StepModelAnim(a0);
        Actor_UpdateTransform(a0);
        Gfx_CalcModelBoneMatrices(a0);
        if (w->drawTex != 0) {
            Gfx_DrawTexModel(a0, 0);
        }
        if (w->drawWire != 0) {
            if (a0->param < 3) {
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

void Stg30_FighterSetVisible(Actor *a0, s32 a1) {
    ((Stg30FighterWork *)a0->work)->visible = a1;
    if (a1 != 0) {
        a0->childCount = 5;
    } else {
        a0->childCount = 4;
    }
}

void Stg30_FighterQueueHomeReset(Actor *a0) {
    ((Stg30FighterWork *)a0->work)->homeResetTimer = 2;
}
