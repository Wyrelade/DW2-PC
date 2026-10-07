#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_BeetleShopUpdate(Actor *a);
/* by engine level */
u16 Stg20_EngineHpTbl[] = {
    800, 900, 1000, 1100, 1200, 1200, 1300, 1400, 1500, 1600, 1600, 1700,
    1800, 1900, 2000, 2000, 2100, 2200, 2300, 2400, 2400, 2500, 2600, 2700,
    2800, 2800, 2900, 3000, 3100, 3200, 3200, 3300, 3400, 3500, 3600, 3600,
    3700, 3800, 3900, 4000, 4000, 4100, 4200, 4300, 4400, 9999,
};
/* by battery level */
u16 Stg20_BatteryEpTbl[] = {
    100, 200, 300, 400, 500, 1000, 1200, 1400, 1600, 1800, 2000, 2200,
    2400, 2600, 2800, 3000, 3200, 3400, 3600, 3800, 9999,
};
TaskDesc Stg20_BeetleShopDesc = { 0, Stg20_BeetleShopUpdate, Task_DefaultDestroy, 0, 0, 0xC };

void Stg20_RefillBeetleHpEp(void) {
    GameState *g = &Save_GameState;

    g->maxHp = g->hp = Stg20_EngineHpTbl[g->slotItems[1] - 1];
    g->maxMp = g->mp = Stg20_BatteryEpTbl[g->slotItems[3] - 0x35];
}

void Stg20_BeetleShopUpdate(Actor *a) {
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Stg20_MenuState.menuChoice = 0;
        Task_Create(0x312, &slot[0], 0);
        Task_Create(0x315, &slot[1], 0);
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (slot[1] == 0) {
                    Task_Create(0x315, &slot[1], 0);
                }
                Task_Create(0x318, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else if (Stg20_MenuState.menuChoice == 0) {
                        Task_SetState0((Actor *)slot[1], 3);
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
                Task_Create(0x31A, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x31B, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
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
            Stg20_RefillBeetleHpEp();
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.modeArg = 7;
                Sys_State.nextGameMode = Sys_State.prevGameMode;
            }
            break;
        }
        break;
    }
}
