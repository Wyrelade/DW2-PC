#include "common.h"
#include "stag0000/stag0000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_StageSetup(Actor *arg0);

TaskDesc Stg00_StageSetupDesc = { 0, Stg00_StageSetup, Task_DefaultDestroy, 0, 4, 0x20 };

void Stg00_StageSetup(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs a1;
    Stg00TaskArgs a2;
    Stg00TaskArgs a3;

    if (arg0->stateLevel0 == 0) {
        Task_Create(9, &slot[5], 0);
        switch (Sys_GameMode) {
        case 0x101:
        default:
            a1.field_0 = 0;
            a1.field_4 = -0xF00;
            a1.field_8 = -0x1900;
            a1.field_C = 0;
            a1.field_10 = 0;
            a1.field_14 = 0;
            a1.field_18 = 0x230;
            Task_Create(0x109, &slot[0], (s32)&a1);
            Task_Create(0x106, &slot[1], 0);
            Task_Create(0x108, &slot[2], 0);
            break;
        case 0x102:
            a2.field_0 = 0;
            a2.field_4 = -0xF00;
            a2.field_8 = -0x1900;
            a2.field_C = 0;
            a2.field_10 = 0;
            a2.field_14 = 0;
            a2.field_18 = 0x230;
            Task_Create(0x109, &slot[0], (s32)&a2);
            Task_Create(0x103, &slot[1], 0);
            Task_Create(0x106, &slot[2], 0);
            Task_Create(0x102, &slot[3], 0);
            break;
        case 0x103:
            a3.field_0 = 0;
            a3.field_4 = -0x1770;
            a3.field_8 = 0x5208;
            a3.field_C = 0;
            a3.field_10 = -0x2BC;
            a3.field_14 = 0;
            a3.field_18 = 0x5DC;
            Task_Create(0x109, &slot[0], (s32)&a3);
            Task_Create(0x106, &slot[1], 0);
            Task_Create(0x104, &slot[2], 0);
            break;
        case 0x104:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x107, &slot[6], 0);
            break;
        case 0x105:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x10A, &slot[7], 0);
            break;
        case 0x106:
            Sys_SetFrameRate60();
            Gpu_AllocPacketBufs(0x25800);
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x1E);
            Task_Create(0x10D, &slot[7], 0);
            break;
        }
        Task_NextState0(arg0);
    }
}
