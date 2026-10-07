#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/modemenu.h"
#include "stag1100/vsparty.h"
#include "stag1100/card.h"

Halves Stg11_ModeHelpPos = { 0x10, 0xBA };
TaskDesc Stg11_ModeMenuDesc = {
    (TaskInitFn)Stg11_ModeMenuInit, Stg11_ModeMenuUpdate, Task_DefaultDestroy, Stg11_ModeMenuDraw, 0x2C, 4,
};

void Stg11_ModeMenuInit(Actor *arg0, s16 arg1) {
    Stg11ModeMenuWork *w = (Stg11ModeMenuWork *)arg0->work;
    Stg11_LoadDone = 0;
    w->mode = arg1;
    w->padIndex = arg1 == 4;
}

void Stg11_ModeMenuUpdate(Actor *arg0) {
    Stg11ModeMenuWork *w = (Stg11ModeMenuWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg11TaskEntry *tasks;
    s32 idx;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        w->menu.layout = ((MenuGridLayout *)Cd_GetFileEntry(0xD280000))[w->mode - 1];
        Mem_FillWordsNeg1(w->texts, 4);
        Task_NextState0(arg0);
        break;
    case 1:
        tasks = (Stg11TaskEntry *)Cd_GetFileEntrySubPtr(0xD280003, w->mode - 1);
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(arg0, &w->fade) == 0) {
                Text_PrintIdList(w->texts, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280001, w->mode - 1), 2);
                Text_OpenPacked(&w->texts[3], (s32)Cd_GetFileEntry(w->mode + 0x1FD01A2), 0x81, Stg11_ModeHelpPos);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if (Menu_MoveGridCursor(w->cursor, w->menu.gridSize, w->padIndex) == 0) {
                if (Pad_State[w->padIndex].cross > 0) {
                    if (tasks[Menu_GridIndexColMajor(w->cursor, w->menu.gridSize)].id != -1) {
                        Snd_PlayById(0xA, 0);
                        Task_NextState1(arg0);
                    }
                } else if (Pad_State[w->padIndex].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(arg0, 2);
                }
            } else {
                Snd_PlayById(0xC, 0);
            }
            break;
        case 2:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                idx = Menu_GridIndexColMajor(w->cursor, w->menu.gridSize);
                Task_Create(tasks[idx].id, slot, tasks[idx].arg);
                Text_Close(&w->texts[3]);
                Task_NextState2(arg0);
                break;
            case 1:
                if (*slot == 0) {
                    if (Stg11_LoadDone == 0) {
                        Text_OpenPacked(&w->texts[3], (s32)Cd_GetFileEntry(w->mode + 0x1FD01A2), 0x81, Stg11_ModeHelpPos);
                        Task_SetState1(arg0, 1);
                    } else {
                        Task_SetState0(arg0, 2);
                    }
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 4);
            Gfx_FadeOutToBlack(0x20);
            Task_NextState1(arg0);
            break;
        case 1:
            if (Math_RampToZero(arg0, &w->fade) == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    }
}

void Stg11_ModeMenuDraw(Actor *arg0) {
    Stg11ModeMenuWork *w = (Stg11ModeMenuWork *)arg0->work;
    s32 *list;
    s32 i;
    GfxPart *parts;
    s32 *masks;

    if (w->fade != 0) {
        list = (s32 *)Cd_GetFileEntry(0xD280002);
        for (i = 0; list[i] != 0; i++) {
            parts = (GfxPart *)Cd_GetFileEntry(list[i]);
            if (i == 0) {
                masks = (s32 *)Cd_GetFileEntry(0xD280004);
                Menu_SetPartsGridPos(parts, 0x20, (s32 *)w->cursor, w->menu.gridSize);
                Gfx_SetPartsPalette(parts, 0x20, (arg0->elapsed >> 2) & 3);
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, masks[w->mode - 1]);
            }
            Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->fade);
            Gfx_DrawParts(parts);
        }
    }
}
