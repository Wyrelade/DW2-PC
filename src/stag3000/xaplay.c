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
void Stg30_XaPlayInit(Actor *a0, Vec3 *args);
void Stg30_XaPlayTask(Stg30TaskHead *a0);
void Stg30_XaPlayDestroy(Actor *a0);

s32 Stg30_XaTrackStart[] = { 0, 0x546, 0xB22, 0x10FE, 0x1770, 0x1F0E };
s32 Stg30_XaTrackLength[] = { 0x2EE, 0x3A2, 0x456, 0x474, 0x528, 0x672 };
TaskDesc Stg30_XaPlayDesc = {
    (TaskInitFn)Stg30_XaPlayInit, (TaskFn)Stg30_XaPlayTask, Stg30_XaPlayDestroy, 0, 0x14, 0,
};

void Stg30_XaPlayInit(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void Stg30_XaPlayTask(Stg30TaskHead *a0) {
    Stg30CdWork *w = (Stg30CdWork *)a0->work;
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
            lba = Cd_GetFileLba(w->file) + Stg30_XaTrackStart[w->track - 1];
            w->start = lba;
            w->end = lba + Stg30_XaTrackLength[w->track - 1];
            param[0] = 1;
            param[1] = w->channel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, loc);
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
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            if (a0->frameCount & 0x1F) {
                break;
            }
            switch (CdSync(1, res2)) {
            case 5:
                Task_SetState0((Actor *)a0, 3);
                break;
            case 2:
                if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
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

void Stg30_XaPlayDestroy(Actor *a0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a0);
}
