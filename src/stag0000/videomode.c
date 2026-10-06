#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_VideoModeTask(Actor *arg0);

TaskDesc Stg00_VideoModeDesc = { 0, Stg00_VideoModeTask, Task_DefaultDestroy, 0, 8, 0x18 };

void Stg00_VideoModeTask(Actor *arg0) {
    Stg00ModeWork *w;
    Stg00ModeWork *w2;

    switch (arg0->stateLevel0) {
    case 0:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Gpu_AllocPacketBufs(0x25800);
            Gfx_InitLights();
        case 1:
            break;
        }
        w = (Stg00ModeWork *)arg0->work;
        Sys_SetFrameRate60();
        switch (w->videoMode) {
        case 1:
        default:
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            break;
        case 0:
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
            break;
        case 3:
            Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
            break;
        case 2:
            Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
            break;
        }
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Task_NextState1(arg0);
        case 1:
            break;
        }
        w2 = (Stg00ModeWork *)arg0->work;
        if (Pad_State[0].select > 0) {
            if (w2->videoMode != 3) {
                w2->videoMode++;
            } else {
                w2->videoMode = 0;
            }
            Task_SetState0(arg0, 2);
        }
        break;
    case 2:
        Task_SetState01(arg0, 0, 1);
        break;
    }
}
