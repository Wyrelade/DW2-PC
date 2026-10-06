#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_XaStreamInit(Actor *a, Stg20Vec3 *v);
void Stg20_XaStreamUpdate(Actor *a);
void Stg20_XaStreamDestroy(Actor *a);

TaskDesc Stg20_XaStreamDesc = {
    (TaskInitFn)Stg20_XaStreamInit, Stg20_XaStreamUpdate, Stg20_XaStreamDestroy, 0, 0x14, 0,
};

void Stg20_XaStreamInit(Actor *a, Stg20Vec3 *v) {
    *(Stg20Vec3 *)a->work = *v;
}

void Stg20_XaStreamUpdate(Actor *a) {
    Stg20XaWork *w = (Stg20XaWork *)a->work;
    u8 filter[8];
    u8 mode[8];
    u8 pos[8];
    u8 res[8];
    u8 res2[8];

    switch (a->stateLevel0) {
    case 0:
    default:
        switch (a->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId);
            w->end = w->start + w->len;
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, pos);
            CdControlF(0x15, (s32)pos);
            Task_NextState1(a);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(a, 0);
                break;
            case 2:
                Task_NextState0(a);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(a);
            }
            break;
        case 1:
            if ((((Stg20BlinkTask *)a)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(a, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                        Task_SetState0(a, 3);
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

void Stg20_XaStreamDestroy(Actor *a) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a);
}
