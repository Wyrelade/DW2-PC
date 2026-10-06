#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_GroupViewTask(Actor *arg0);
void Stg00_GroupViewDraw(Actor *arg0);

s32 Stg00_GroupWinMasks[] = { 6, 2, 4, 0 };
TaskDesc Stg00_GroupViewDesc = { 0, Stg00_GroupViewTask, Task_DefaultDestroy, Stg00_GroupViewDraw, 0x10, 0x18 };

void Stg00_GroupViewSetVideoMode(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->videoMode) {
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        break;
    case 2:
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        break;
    case 1:
        Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
        break;
    case 0:
        Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
        break;
    }
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x100);
}

void Stg00_SpawnRandomGroup(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 r;
    s32 c;
    s32 k;
    s32 base;
    s32 idx;
    s32 x;
    s32 y;
    s32 z;

    for (r = 0, z = -0x1400, y = 0x800, base = 0; r < 2; r++, base += 3) {
        for (c = 0, k = base, x = -0xA00; c < 3; k++, c++, x += 0xA00) {
            Task_Destroy(&slot[*&k]);
            do {
                idx = (Rand_Next() & 0xFFFF) % Digi_GetModelListCount();
            } while (Digi_GetModelListId(idx) >= 0xF0);
            args.digiId = Digi_GetModelListId(idx);
            args.facing = y;
            args.posX = x;
            args.posY = 0;
            args.posZ = z;
            Task_Create(0x105, &slot[k], (s32)&args);
        }
        z += 0x2800;
        y += 0x800;
    }
}

void Stg00_GroupViewTask(Actor *arg0) {
    Stg00ViewWork *w;
    Actor *cam;
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ViewWork *)arg0->work)->videoMode = 2;
        Gpu_AllocPacketBufs(0x25800);
        Stg00_GroupViewSetVideoMode(arg0);
        Stg00_SpawnRandomGroup(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ViewWork *)arg0->work;
        cam = (Actor *)Stg00_FindCamera();
        for (i = 0; i < Sys_State.frameDelta; i++) {
            if (Pad_State[0].right) {
                Stg00_CamRotate(cam, 0, 0x20, 0);
            } else if (Pad_State[0].left) {
                Stg00_CamRotate(cam, 0, -0x20, 0);
            }
            if (Pad_State[0].up) {
                Stg00_CamMoveViewPoint(cam, 0, 0, -0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, -0x20);
            } else if (Pad_State[0].down) {
                Stg00_CamMoveViewPoint(cam, 0, 0, 0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, 0x20);
            }
            if (Pad_State[0].triangle) {
                Stg00_CamMoveViewPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].cross) {
                Stg00_CamMoveViewPoint(cam, 0, 0x20, 0);
            }
            if (Pad_State[0].r1) {
                Stg00_CamMoveRefPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].l1) {
                Stg00_CamMoveRefPoint(cam, 0, 0x20, 0);
            }
        }
        if (Pad_State[0].square > 0) {
            if (++w->camPreset == 7) {
                w->camPreset = 0;
            }
            switch (w->camPreset) {
            case 0:
            default:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, -0x1400);
                break;
            case 1:
                Stg00_CamMoveOrigin(cam, -0xA00, 0, -0x1400);
                break;
            case 2:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, 0);
                break;
            case 3:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, 0);
                break;
            case 4:
                Stg00_CamMoveOrigin(cam, 0, 0, 0x2800);
                break;
            case 5:
            case 6:
                Stg00_CamMoveOrigin(cam, -0xA00, 0, 0);
                break;
            }
        }
        if (Pad_State[0].select > 0) {
            if (w->videoMode != 3) {
                w->videoMode++;
            } else {
                w->videoMode = 0;
            }
            Stg00_GroupViewSetVideoMode(arg0);
        }
        if (Pad_State[0].start > 0) {
            Stg00_SpawnRandomGroup(arg0);
        }
        if (Pad_State[0].circle > 0) {
            if (++w->winVariant == 4) {
                w->winVariant = 0;
            }
        }
        if (Pad_State[0].r2 > 0) {
            Sys_NextGameMode = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_GroupViewDraw(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, Stg00_GroupWinMasks[((Stg00PartsWork *)arg0->work)->winVariant]);
    Gfx_DrawParts(e);
}
