#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/mapbg.h"
#include "stag2000/staticbg.h"
#include "stag2000/digilab.h"
#include "stag2000/itemshop.h"
#include "stag2000/beetleshop.h"
#include "stag2000/stag2000_funcs.h"
#include "stag2000/areaselect.h"
#include "stag2000/labmodesel.h"
#include "stag2000/labroster.h"
#include "stag2000/msgwin.h"
#include "stag2000/labcaption.h"
#include "stag2000/labinfo.h"
#include "stag2000/labskills.h"
#include "stag2000/labpair.h"
#include "stag2000/dna.h"
#include "stag2000/shadow.h"
#include "stag2000/labjogbg.h"
#include "stag2000/labdigimodel.h"
#include "stag2000/mapexit.h"
#include "stag2000/walker.h"
#include "stag2000/xastream.h"
#include "stag2000/shopbg.h"
#include "stag2000/shopbits.h"
#include "stag2000/itemshopmenu.h"
#include "stag2000/beetleshopmenu.h"
#include "stag2000/camera.h"

TaskDesc Stg20_CameraDesc = { 0, Stg20_CameraUpdate, Task_DefaultDestroy, Stg20_CameraDraw, 0x94, 0 };
/* Unreferenced: the word before .bss (garbage text in retail). */
u8 D_80070764[4] = "1660";

void Stg20_CameraUpdate(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;
    Actor *e;

    switch (a->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->coord);
        if (Sys_State.gameMode < 0x32F) {
            w->proj = 0x5A0;
            w->view.vpy = -0x5D00;
            w->view.vpx = 0;
            w->view.vpz = -0x5A00;
            w->view.vrx = 0;
            w->view.vry = 0;
            w->view.vrz = 0;
        } else {
            w->proj = 0x5DC;
            w->view.vpy = -0xFA0;
            w->view.vpz = -0x3578;
            w->view.vpx = 0;
            w->view.vrx = 0;
            w->view.vry = -0x3E8;
            w->view.vrz = 0;
        }
        w->view.rz = 0;
        w->view.super = &w->coord;
        w->rot[2] = 0;
        w->rot[1] = 0;
        w->rot[0] = 0;
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        if (Sys_State.gameMode < 0x32F) {
            break;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            w->view.vpy = -0xFA0;
            w->view.vpz = -0x3578;
            w->speed = 0;
            return;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->view.vpy >= -0x270F) {
                    w->view.vpy -= 0x1F4;
                    break;
                }
                w->view.vpy = -0x2710;
                Task_NextState2(a);
                w->timer = 0x7B;
            case 1:
                w->speed += 0x840;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeOutToWhite(0x14);
            case 2:
                w->speed += 0x840;
                w->view.vpz += 0x390;
                w->view.vpy += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x1080;
                w->view.vpz -= 0x390;
                w->view.vpy -= 0x10A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0x78;
            case 4:
                if (w->speed > 0) {
                    w->speed -= 0x1080;
                } else {
                    w->speed = 0;
                }
                if (--w->timer == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            w->rot[1] -= w->speed / 256;
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->view.vpy >= -0x270F) {
                    w->view.vpy -= 0x1F4;
                    break;
                }
                w->view.vpy = -0x2710;
                Task_NextState2(a);
                w->timer = 0x7B;
            case 1:
                w->speed += 0x840;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeOutToWhite(0x14);
            case 2:
                w->speed += 0x840;
                w->view.vpz += 0x390;
                w->view.vpy += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x840;
                w->view.vpz -= 0x390;
                w->view.vpy -= 0x10A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0x78;
            case 4:
                w->speed -= 0x840;
                if (--w->timer == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            e = (Actor *)Task_FindFirst(0x30A, -1, 0);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->rotY += w->speed / 256;
            }
            e = (Actor *)Task_FindFirst(0x30A, -1, 1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->rotY -= w->speed / 256;
            }
            break;
        }
        if (Stg20_MenuState.labIsDna == 0) {
            e = (Actor *)Task_FindFirst(7, -1, -1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->rotY = w->rot[1];
            }
        }
        break;
    }
}

void Stg20_CameraDraw(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;

    RotMatrixYXZ(w->rot, &w->coord.coord);
    w->coord.coord.t[0] = w->tx;
    w->coord.coord.t[1] = w->ty;
    w->coord.coord.t[2] = w->tz;
    w->coord.flg = 0;
    GsSetProjection(w->proj);
    GsSetRefView2(&w->view);
}
