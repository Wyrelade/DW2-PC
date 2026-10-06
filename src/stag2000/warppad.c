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
#include "stag2000/warppad.h"

Stg20Warp Stg20_WarpPads[] = {
    { { 0xB, 0xC }, 0x326, 1 },
    { { 0x11, 0xB }, 0x327, 1 },
    { { 0xB, 0xD }, 0x31D, 1 },
    { { 0xB, 0xC }, 0x320, 1 },
};
TaskDesc Stg20_WarpPadDesc = { (TaskInitFn)Stg20_WarpPadInit, Stg20_WarpPadUpdate, Task_DefaultDestroy, 0, 4, 4 };

Stg20FileRec *Stg20_GetMapDest(s32 i) {
    Stg20FileRec *r = (Stg20FileRec *)Cd_GetFileEntry(Sys_GameMode[0] + 0xD28FCD6);

    if (r[i].relocated == 0) {
        s32 base = Cd_GetFileOrNull(0xD29);

        r[i].relocated = 1;
        r[i].text += base;
    }
    return &r[i];
}

void Stg20_WarpPadInit(Actor *a, s32 v) {
    a->param = v;
}

void Stg20_WarpPadUpdate(Actor *a) {
    Stg20LinkWork *w = (Stg20LinkWork *)a->work;
    Stg20Cell c;
    Stg20WarpFx args;
    Stg20Rot *o;
    s32 ok;
    s32 *slot;
    s32 v;

    switch (a->stateLevel0) {
    case 0:
        if (++a->stateLevel1 >= 5) {
            Cd_QueueFile(0xE45);
            Cd_QueueFile(0xE46);
            w->target = (Actor *)Task_FindFirst(0x302, 0, -1);
            ok = 0;
            c = *Stg20_GetActorCell(w->target);
            if (c.x == Stg20_WarpPads[a->param].cell.x && c.y == Stg20_WarpPads[a->param].cell.y) {
                ok = Stg20_IsOnCellCenter(w->target) != 0;
            }
            if (ok == 0) {
                Task_NextState0(a);
            }
        }
        break;
    case 1:
        c = *Stg20_GetActorCell(w->target);
        if (c.x == Stg20_WarpPads[a->param].cell.x && c.y == Stg20_WarpPads[a->param].cell.y
            && Stg20_IsOnCellCenter(w->target) != 0) {
            Stg20_WalkerHalt(w->target);
            Stg20_TalkActive = 1;
            Task_NextState0(a);
        }
        break;
    case 2:
        o = (Stg20Rot *)w->target->u38.ptr38;
        o->rotY += 0x177;
        o->scaleY += 0x190;
        if (o->scaleX > 100) {
            o->scaleX -= 100;
        } else {
            o->scaleX = 0;
        }
        v = o->scaleZ;
        if (v > 100) {
            o->scaleZ -= 100;
        } else {
            o->scaleZ = 0;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            Snd_PlayById(0x32, 0);
            o = (Stg20Rot *)w->target->u38.ptr38;
            slot = (s32 *)a->u34.children;
            args.animFileId = 0xE45;
            args.modelFileId = 0xE46;
            args.rotY = 0;
            args.duration = 0x78;
            args.x = o->posX;
            args.y = o->posY;
            args.z = o->posZ;
            Task_Create(7, slot, (s32)&args);
            Task_NextState1(a);
            a->elapsed = 0;
        case 1:
            if (a->elapsed < 0x5A) {
                break;
            }
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 2:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = Stg20_WarpPads[a->param].nextMode;
                Sys_State.modeArg = Stg20_WarpPads[a->param].modeArg;
            }
            break;
        }
        break;
    }
}
