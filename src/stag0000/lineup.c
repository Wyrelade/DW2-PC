#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_LineupTask(Actor *arg0);
void Stg00_LineupDraw(Actor *arg0);

Stg00Pos Stg00_LineupLayouts[][9] = {
    { { 0, -10240 }, { 0, -7680 }, { 0, -5120 }, { 0, -2560 }, { 0, 0 }, { 0, 2560 }, { 0, 5120 }, { 0, 7680 }, { 0, 10240 } },
    { { -1280, -5120 }, { -1280, -2560 }, { -1280, 0 }, { -1280, 2560 }, { 1280, -5120 }, { 1280, -2560 }, { 1280, 0 }, { 1280, 2560 }, { 1280, 5120 } },
    { { -3840, -3840 }, { -3840, 0 }, { -3840, 3840 }, { 0, -3840 }, { 0, 0 }, { 0, 3840 }, { 3840, -3840 }, { 3840, 0 }, { 3840, 3840 } },
};
s32 Stg00_LineupWinMasks[] = { 6, 2, 4, 0 };
TaskDesc Stg00_LineupDesc = { 0, Stg00_LineupTask, Task_DefaultDestroy, Stg00_LineupDraw, 0x65C, 0x24 };

void Stg00_LineupSetVideoMode(Actor *arg0) {
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

void Stg00_LineupSpawnModels(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 i;

    for (i = 0; i < 9; i++) {
        Task_Destroy(slot);
        args.digiId = w->digiIds[i + w->scrollTop];
        args.facing = 0x400;
        args.posX = Stg00_LineupLayouts[w->layout][i].posX;
        args.posY = 0;
        args.posZ = Stg00_LineupLayouts[w->layout][i].posZ;
        Task_Create(0x105, slot, (s32)&args);
        slot++;
    }
}

void Stg00_LineupBuildList(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 i;
    s32 id;
    s32 v;
    s32 j;
    s32 k;

    for (i = 0; (id = Digi_GetModelListId(i)) < 0x12D; i++) {
        v = func_8001E79C(id);
        j = 0;
        if (w->count != 0) {
            for (k = j; k < w->count; k++) {
                if (v < w->sortKeys[k]) {
                    break;
                }
            }
            j = k;
            for (k = w->count; k >= j; k--) {
                w->sortKeys[k] = w->sortKeys[k - 1];
                w->digiIds[k] = w->digiIds[k - 1];
            }
        }
        w->sortKeys[j] = v;
        w->digiIds[j] = id;
        w->count++;
    }
}

void Stg00_LineupTask(Actor *arg0) {
    Stg00ListWork *w;
    Actor *cam;
    s32 i;
    s32 redraw;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ModeWork *)arg0->work)->videoMode = 2;
        Gpu_AllocPacketBufs(0x25800);
        Gfx_InitLights();
        Stg00_LineupSetVideoMode(arg0);
        Stg00_LineupBuildList(arg0);
        Stg00_LineupSpawnModels(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ListWork *)arg0->work;
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
        if (Pad_State[0].select > 0) {
            if (((Stg00ModeWork *)w)->videoMode != 3) {
                ((Stg00ModeWork *)w)->videoMode++;
            } else {
                ((Stg00ModeWork *)w)->videoMode = 0;
            }
            Stg00_LineupSetVideoMode(arg0);
        }
        redraw = 0;
        if (Pad_State[0].start > 0) {
            if (++w->layout == 3) {
                w->layout = 0;
            }
            redraw = 1;
        }
        if (Pad_State[0].repeat & 0x20) {
            if (w->scrollTop != 0) {
                w->scrollTop--;
                redraw = 1;
            }
        }
        if (Pad_State[0].repeat & 0x80) {
            if (w->scrollTop + 9 != w->count) {
                w->scrollTop++;
                redraw = 1;
            }
        }
        if (redraw) {
            Stg00_LineupSpawnModels(arg0);
        }
        if (Pad_State[0].r2 > 0) {
            Sys_NextGameMode = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_LineupDraw(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, Stg00_LineupWinMasks[((Stg00PartsWork *)arg0->work)->winVariant]);
    Gfx_DrawParts(e);
}
