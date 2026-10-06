#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_RootUpdate(Actor *arg0);

TaskDesc Stg35_RootDesc = { 0, Stg35_RootUpdate, Task_DefaultDestroy, 0, 0, 4 };

void Stg35_RootUpdate(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    SysState *s;
    SysState *t;

    if (arg0->stateLevel0 != 0) {
        return;
    }
    s = &Sys_State;
    switch (s->gameMode) {
    case 0x701:
    default:
        t = s;
        switch (t->prevGameMode) {
        case 0x603:
            t->modeArg = Sys_VsPartyConfirmed != 0;
            break;
            do {
            } while (0);
        case 0x604:
            s->modeArg = (Sys_VsPartyConfirmed != 0) ? 2 : 1;
            break;
        default:
            t->modeArg = 0;
            break;
        }
        id = 0x701;
        break;
    case 0x703:
        id = 0x705;
        break;
    case 0x702:
        id = 0x703;
        break;
    }
    Task_Create(id, slot, 0);
    Task_NextState0(arg0);
}
