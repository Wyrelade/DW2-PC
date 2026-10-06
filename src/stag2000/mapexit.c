#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/mapbg.h"
#include "stag2000/stag2000_funcs.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_MapExitUpdate(Actor *a);

TaskDesc Stg20_MapExitDesc = { 0, Stg20_MapExitUpdate, Task_DefaultDestroy, 0, 8, 0 };

void Stg20_MapExitUpdate(Actor *a) {
    Stg20ExitWork *w = (Stg20ExitWork *)a->work;
    Stg20Exit *e;
    Stg20Cell c;

    switch (a->stateLevel0) {
    case 0:
        Task_NextState0(a);
        break;
    case 1:
        for (e = (Stg20Exit *)Stg20_GetMapInfo()->exits; e->x != 0; e++) {
            c.x = e->x;
            c.y = e->y;
            if (Stg20_GetGridCell(&c) & 0x80) {
                Task_FindFirst(0x302, 0, -1)->param = 1;
                w->mode = e->mode + 0x300;
                w->arg = e->arg;
                Task_NextState0(a);
                break;
            }
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = w->mode;
                Sys_State.modeArg = w->arg;
            }
            break;
        }
        break;
    }
}
