#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/stag1100_funcs.h"
#include "stag1100/stag1100_301C_funcs.h"

TaskDesc Stg11_RootDesc = { 0, Stg11_RootUpdate, Task_DefaultDestroy, 0, 4, 0x10 };

void Stg11_RootUpdate(Actor *arg0) {
    Stg11MainWork *w = (Stg11MainWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;

    switch (arg0->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        Task_Create(9, slot, 0);
        Task_Create(0x601, slot + 2, 0);
        Task_Create(0x602, slot + 3, 0);
        D_80050780 = 0;
        Task_Create(0x603, slot + 1, Sys_State.gameMode - 0x600);
        if (Sys_State.gameMode != 0x603 && Sys_State.gameMode != 0x604) {
            Snd_StopAll();
            Snd_UnloadSlot(2);
            Snd_SetSlotContent(1, 0xE);
            w->bgmStarted = 0;
        } else {
            w->bgmStarted = 1;
        }
        Task_NextState0(arg0);
        break;
    case 1:
        if (arg0->stateLevel1 != 1) {
            if (w->bgmStarted == 0 && Snd_AnySlotLoading() == 0) {
                w->bgmStarted = 1;
                Snd_PlayById(0x100, 1);
            }
            if (slot[1] == 0) {
                Sys_State.nextGameMode = Sys_State.prevGameMode;
                if (Sys_State.gameMode == 0x605) {
                    Sys_State.modeArg = 1;
                }
                Task_NextState1(arg0);
            }
        }
        break;
    case 2:
        break;
    }
}
