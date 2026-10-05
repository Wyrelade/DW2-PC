#include "common.h"
#include "stag1000/stag1000.h"

/* small: STAG1000.PRO has 0x11C bytes free in its last disc sector */
SHIFT_TEST_PAD(0x10);

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg10_StageSetup(Actor *a0);

/* Unreferenced. */
s32 D_800651B4[3] = { 0 };
RECT Stg10_VramClearRect = { 0, 0, 0x400, 0x200 };
/* by game mode 0x402.. */
s16 Stg10_MovieFileIds[] = { 0x282, 0xE2F, 0x510, 0x511, 0xE28, 0xD4E };
TaskDesc Stg10_StageSetupDesc = { 0, Stg10_StageSetup, Task_DefaultDestroy, 0, 0, 0xC };

void Stg10_StageSetup(Actor *a0) {
    s32 args[2];
    s32 *slot = (s32 *)a0->u34.children;

    if (a0->stateLevel0 != 0) {
        return;
    }
    switch (Sys_State.gameMode) {
    case 0x401:
    default:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gfx_InitTexSlots();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        Task_Create(0x401, slot + 1, 0);
        Snd_StopAll();
        break;
    case 0x408:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeClear();
        Task_Create(0x403, slot + 1, 0);
        break;
    case 0x402:
    case 0x403:
    case 0x404:
    case 0x405:
    case 0x406:
    case 0x407:
        Gpu_AllocPacketBufs(0x400);
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 1);
        ResetGraph(1);
        ClearImage2((s32)&Stg10_VramClearRect, 0, 0, 0);
        DrawSync(0);
        Sys_State.bufIndex = 0;
        Snd_StopAll();
        args[0] = Stg10_MovieFileIds[Sys_State.gameMode - 0x402];
        args[1] = Cd_GetFileSectors(args[0]) / 10 - 10;
        Task_Create(0x402, slot + 2, (s32)args);
        break;
    }
    Task_NextState0(a0);
}

/* Unnamed: empty stub, called only from Stg10_TitleUpdate cursor case 3, no other ref. */
void func_8006359C(void) {
}
