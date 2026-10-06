#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"
#include "stag0000/font.h"
#include "stag0000/fightbg.h"
#include "stag0000/digiview.h"
#include "stag0000/lineup.h"
#include "stag0000/videomode.h"
#include "stag0000/groupview.h"
#include "stag0000/digimodel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_XaPlayInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_XaPlayTask(Actor *arg0);
void Stg00_XaPlayDestroy(Actor *arg0);

s32 Stg00_XaTrackStart[] = { 0, 0x546, 0xB22, 0x10FE, 0x1770, 0x1F0E };
s32 Stg00_XaTrackLength[] = { 0x2EE, 0x3A2, 0x456, 0x474, 0x528, 0x672 };
TaskDesc Stg00_XaPlayDesc = {
    (TaskInitFn)Stg00_XaPlayInit, Stg00_XaPlayTask, Stg00_XaPlayDestroy, 0, 0x14, 0,
};

void Stg00_XaPlayInit(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void Stg00_XaPlayTask(Actor *arg0) {
    Stg00CdWork *w = (Stg00CdWork *)arg0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->startSector = Cd_GetFileLba(w->fileId) + Stg00_XaTrackStart[w->track - 1];
            w->endSector = w->startSector + Stg00_XaTrackLength[w->track - 1];
            param[0] = 1;
            param[1] = w->xaChannel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->startSector, loc);
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
            CdIntToPos(w->startSector, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((Stg00ActorTimer *)arg0)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->endSector) {
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

void Stg00_XaPlayDestroy(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}
