#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_ItemShopUpdate(Actor *a);

TaskDesc Stg20_ItemShopDesc = { 0, Stg20_ItemShopUpdate, Task_DefaultDestroy, 0, 0, 0x10 };

void Stg20_ItemShopUpdate(Actor *a) {
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Task_Create(0x312, &slot[0], 0);
        Task_Create(0x315, &slot[1], 0);
        Stg20_MenuState.menuChoice = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x316, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else if (Stg20_MenuState.menuChoice == 0) {
                        Task_SetState1(a, 1);
                    } else {
                        Task_SetState1(a, 2);
                    }
                }
                break;
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                Stg20_MenuState.sellMode = 0;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                Stg20_MenuState.sellMode = 1;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
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
                Sys_State.nextGameMode = Sys_State.prevGameMode;
                Sys_State.modeArg = Sys_State.gameMode == 0x330 ? 5 : 6;
            }
            break;
        }
        break;
    }
}
