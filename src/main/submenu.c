#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_SubMenuInit(Actor *arg0, s16 arg1);
void Menu_SubMenuTask(Actor *a);
void Menu_SubMenuDraw(Actor *actor);

TaskDesc D_80040EB4 = {
    (TaskInitFn)Menu_SubMenuInit, Menu_SubMenuTask, Task_DefaultDestroy, Menu_SubMenuDraw, 0x44, 4,
};

void Menu_SubMenuInit(Actor *arg0, s16 arg1) {
    ActorWork *w = arg0->work;

    w->menuId = arg1;
    if (arg1 == 3) {
        Menu_Ctx->pickResult = 0;
    }
    w->optionsHidden = 0;
}

void Menu_SubMenuTask(Actor *a) {
    MenuSubMenuWork *w = (MenuSubMenuWork *)a->work;
    s32 *p = (s32 *)a->u34.children;
    Pair54 *tbl;
    s32 idx;

    switch (a->stateLevel0) {
    default:
    case 0:
        w->u2C.blk = ((MenuSubMenuLayout *)Cd_GetFileEntry(0x5130007))[w->menuId - 1];
        Mem_FillWordsNeg1(w, 0xA);
        Task_NextState0(a);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntrySubPtr(0x513000A, w->menuId - 1);
        switch (a->stateLevel1) {
        default:
        case 0:
            if (Math_RampToOne((s32)a, &w->ramp) == 0) {
                Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130008, w->menuId - 1), 2);
                switch (w->menuId) {
                case 5:
                case 6:
                    Task_SetState1(a, 2);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            }
            break;
        case 1:
            if (((s32 (*)(s16 *, s16 *))Menu_MoveGridCursorP1)(w->cursor, w->u2C.gridSize) == 0) {
            if (Pad_State[0].cross > 0) {
                idx = Menu_GridIndexColMajor(w->cursor, w->u2C.gridSize);
                if (tbl[idx].field_0 == -1) {
                    break;
                }
                w->selection = idx;
                Snd_PlayById(0xA, 0);
                switch (w->menuId) {
                case 7:
                case 8:
                    Menu_Ctx->subMenuCursor = w->cursor[0];
                    Task_NextState1(a);
                    break;
                case 4:
                    Task_SetState1(a, 3);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            } else if (Pad_State[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 2);
            }
            } else {
                Snd_PlayById(0xC, 0);
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            default:
            case 0:
                Task_Create(tbl[w->selection].field_0, p, tbl[w->selection].field_2);
                Task_NextState2(a);
                break;
            case 1:
                if (w->menuId == 3) {
                    switch (Menu_Ctx->pickResult) {
                    case 1:
                        Text_CloseArray(w->optionTexts, 9);
                        w->optionsHidden = 1;
                        break;
                    case 2:
                        Text_CloseArray(w, 0xA);
                        Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130008, w->menuId - 1), 0);
                        w->optionsHidden = 0;
                        break;
                    }
                    Menu_Ctx->pickResult = 0;
                }
                if (*p == 0) {
                    switch (w->menuId) {
                    default:
                        Task_SetState1(a, 1);
                        break;
                    case 5:
                    case 6:
                        Task_SetState0(a, 2);
                        break;
                    }
                }
                break;
            }
            break;
        case 3: {
            s32 *q = (s32 *)a->u34.children;
            switch (a->stateLevel2) {
            default:
            case 0:
                Text_CloseArray(w, 0xA);
                Task_NextState2(a);
                break;
            case 1:
                if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                    Task_NextState2(a);
                }
                break;
            case 2:
                Task_Create(tbl[w->selection].field_0, q, tbl[w->selection].field_2);
                Task_NextState2(a);
                break;
            case 3:
                if (*q == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        default:
        case 0:
            Text_CloseArray(w, 0xA);
            Task_NextState1(a);
            break;
        case 1:
            if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);

void Menu_SubMenuDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;

    if (w->subMenuRamp == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130009);
    if (*p == 0) {
        return;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        if (w->field_2C != 0 && w->optionsHidden == 0) {
            Menu_SetPartsGridPos(obj, 2, &w->field_28, &w->field_2C);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 2);
        }
        list++;
        Gfx_SetPartsScale(obj, 0x1000, w->subMenuRamp);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);
}
