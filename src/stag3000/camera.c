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
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"
#include "stag3000/interruptselect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_CameraUpdate(Actor *arg0);
void Stg30_CameraDraw(Actor *a0);

s16 Stg30_CloseUpRotY[] = { 682, 0, -682, 1365, 2048, 2730 };
s16 Stg30_CloseUpVpz[] = { 7495, 7595, 8620, 9064, 9944, 11496, 12728, 14424, 17096 };
s16 Stg30_CloseUpVry[] = { -304, -304, -572, -596, -728, -832, -888, -1008, -1176 };
TaskDesc Stg30_CameraDesc = { 0, Stg30_CameraUpdate, Task_DefaultDestroy, Stg30_CameraDraw, 0x84, 0 };

s32 Stg30_CamShotVariant;

s32 Stg30_CamEaseStep(s32 a, s32 b) {
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

void Stg30_CamEaseToward(Stg30CamWork *w, Stg30CamGoal *g) {
    s32 i;

    for (i = 0; i < Sys_State.frameDelta; i++) {
        w->rotY += Stg30_CamEaseStep(g->rotY, w->rotY);
        w->vpx += Stg30_CamEaseStep(g->vpx, w->vpx);
        w->vpy += Stg30_CamEaseStep(g->vpy, w->vpy);
        w->vpz += Stg30_CamEaseStep(g->vpz, w->vpz);
        w->vry += Stg30_CamEaseStep(g->vry, w->vry);
        w->originX += Stg30_CamEaseStep(g->originX, w->originX);
        w->originZ += Stg30_CamEaseStep(g->originZ, w->originZ);
    }
}

void Stg30_CameraUpdate(Actor *arg0) {
    Stg30CamWork *w = (Stg30CamWork *)arg0->work;
    s32 i;
    s32 h;

    switch (arg0->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->coord);
        w->vpy = -0x4E20;
        w->vry = 0x12C;
        w->projection = 0x5DC;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->vpy += 0xE9;
                w->vpz -= 0x15E;
                w->rotY += 0x44;
                if (w->rotY > 0x1000) {
                    w->rotY = 0;
                    Task_NextState2(arg0);
                }
                break;
            case 1:
                w->vry -= 0x21;
                if (++arg0->stateLevel3 == 0x1E) {
                    w->vry = -0x2BC;
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            {
                Stg30CamGoal g;

                g.vpy = -0x169B;
                g.vpz = -0x5366;
                g.originX = 0;
                g.originZ = 0;
                g.rotY = 0;
                g.vpx = 0;
                g.vry = -0x2BC;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            {
                Stg30CamGoal g;

                i = arg0->stateLevel1 - 2;
                h = func_8001E79C(Stg30_Battle.digis[i].digiId);
                h = h < 0x300 ? 0 : h - 0x300;
                h /= 256;
                g.originX = (i % 3) * 0xA00 - 0xA00;
                g.originZ = (i / 3) * 0x2800 - 0x1400;
                g.rotY = Stg30_CloseUpRotY[i];
                g.vpx = 0;
                g.vpy = -0xC30;
                g.vpz = Stg30_CloseUpVpz[h];
                g.vry = Stg30_CloseUpVry[h];
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 8:
            {
                Stg30CamGoal g;

                g.originZ = -0x1400;
                g.rotY = 0x238;
                g.vpy = -0x91C;
                g.vpz = 0x33FC;
                g.originX = 0;
                g.vpx = 0;
                g.vry = -0x36C;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 9:
            {
                Stg30CamGoal g;

                g.originZ = 0x1400;
                g.rotY = 0x5C7;
                g.vpy = -0x91C;
                g.vpz = 0x33FC;
                g.originX = 0;
                g.vpx = 0;
                g.vry = -0x36C;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 22:
            w->originZ = -0x1E00;
            w->vpy = -0x1F40;
            w->originX = 0;
            w->rotY = 0;
            w->vpx = 0;
            w->vpz = 0x4E20;
            w->vrx = 0;
            w->vry = 0;
            w->vrz = 0;
            break;
        case 23:
            w->originZ = 0x1E00;
            w->rotY = 0x800;
            w->vpy = -0x1F40;
            w->originX = 0;
            w->vpx = 0;
            w->vpz = 0x4E20;
            w->vrx = 0;
            w->vry = 0;
            w->vrz = 0;
            break;
        case 24:
            {
                Stg30CamGoal g;

                g.rotY = -0x400;
                g.vpy = -0x50FB;
                g.vpz = -0x6EC6;
                g.originX = 0;
                g.originZ = 0;
                g.vpx = 0;
                g.vry = -0x29C;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg30_CamShotVariant = Rand_Next() & 3;
                Task_NextState2(arg0);
            case 1:
                break;
            }
            w->vpy = -0x514;
            w->vpz = 0x2EE0;
            w->vry = -0x578;
            w->vpx = 0;
            w->vrx = 0;
            w->vrz = 0;
            w->rotY = 0xAA;
            w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xC80;
            w->originZ = -0x1400;
            switch (Stg30_CamShotVariant) {
            case 1:
                w->rotY = 0x38;
                w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->vpz = 0x34BC;
                break;
            case 2:
                w->vpy = -0x1914;
                w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->originZ = -0xF00;
                w->vpz = 0x34BC;
                break;
            }
            if (arg0->stateLevel1 >= 13) {
                w->rotY = 0x800 - w->rotY;
                w->originX -= 0x1E00;
                w->originZ = -w->originZ;
            }
            break;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            w->vpy = -0x5DC;
            w->vpz = 0x2EE0;
            w->vpx = 0;
            w->vrx = 0;
            w->vry = -0x640;
            w->vrz = 0;
            if (arg0->stateLevel1 < 19) {
                w->rotY = 0xAA;
                w->originX = (arg0->stateLevel1 - 16) * 0xA00 - 0xA00;
                w->originZ = -0x1400;
            } else {
                w->rotY = 0x755;
                w->originX = (arg0->stateLevel1 - 19) * 0xA00 - 0xA00;
                w->originZ = 0x1400;
            }
            break;
        case 25:
            w->originZ = -0x1400;
            w->rotY = 0x238;
            w->vpy = -0x1388;
            w->vpz = 0x3A98;
            w->originX = 0;
            w->originY = 0;
            w->vpx = 0;
            w->vrx = 0;
            w->vry = -0x3E8;
            w->vrz = 0;
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void Stg30_CameraDraw(Actor *a0) {
    Stg30CamWork *w = (Stg30CamWork *)a0->work;
    Stg30RefView rv;

    RotMatrixYXZ(&w->rotX, &w->coord.coord);
    w->coord.coord.t[0] = w->originX;
    w->coord.coord.t[1] = w->originY;
    w->coord.coord.t[2] = w->originZ;
    w->coord.flg = 0;
    rv.vpx = w->vpx;
    rv.vpy = w->vpy;
    rv.vpz = w->vpz;
    rv.vrx = w->vrx;
    rv.vry = w->vry;
    rv.vrz = w->vrz;
    rv.rz = 0;
    rv.super = &w->coord;
    GsSetProjection(w->projection);
    GsSetRefView2(&rv);
}

void Stg30_SetCameraShot(u8 state) {
    Actor *t = (Actor *)Task_FindFirst(0x503, -1, -1);

    if (t != NULL && t->stateLevel0 == 1) {
        Task_SetState1(t, state);
    }
}
