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
void Stg35_XaPlayInit(Actor *arg0, Stg35Vec3 *arg1);
void Stg35_XaPlayTask(Actor *arg0);
void Stg35_XaPlayDestroy(Actor *arg0);

s32 Stg35_XaTrackStart[] = { 0, 0x546, 0xB22, 0x10FE, 0x1770, 0x1F0E };
s32 Stg35_XaTrackLength[] = { 0x2EE, 0x3A2, 0x456, 0x50A, 0x5BE, 0x672 };
TaskDesc Stg35_XaPlayDesc = {
    (TaskInitFn)Stg35_XaPlayInit, Stg35_XaPlayTask, Stg35_XaPlayDestroy, 0, 0x14, 0,
};

void Stg35_XaPlayInit(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

void Stg35_XaPlayTask(Actor *arg0) {
    Stg35CdWork *w = (Stg35CdWork *)arg0->work;
    u8 filter[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 r;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId) + Stg35_XaTrackStart[w->track - 1];
            w->end = w->start + Stg35_XaTrackLength[w->track - 1];
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, loc);
            CdControlF(0x15, (s32)loc);
            Task_NextState1(arg0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(arg0, 0);
                break;
            case 2:
                Task_NextState0(arg0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((ActorAllocView *)arg0)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                        Task_SetState0(arg0, 3);
                    } else {
                        CdControlF(0x11, 0);
                    }
                    break;
                }
            }
            break;
        }
        break;
    }
}

void Stg35_XaPlayDestroy(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}
