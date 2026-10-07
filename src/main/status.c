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

/* Declarations the original file made before this code. */
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_StatusInit(Actor *arg0, s16 arg1);
void Menu_StatusTask(Actor *a0);
void Menu_StatusDraw(Actor *actor);

TaskDesc Menu_StatusDesc = {
    (TaskInitFn)Menu_StatusInit, Menu_StatusTask, Task_DefaultDestroy, Menu_StatusDraw, 0xB0, 4,
};

void Menu_StatusInit(Actor *arg0, s16 arg1) {
    arg0->work->field_6C = arg1;
}

void Menu_StatusTask(Actor *a0) {
    MenuStatusWork *w = (MenuStatusWork *)a0->work;
    s32 i;
    s32 v;
    s32 id;
    s32 *p;
    s16 *tbl;
    Halves *h;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->digiCount = Digi_ListByState(3, (DigiRosterEntry **)w->digiList);
        Mem_FillWordsNeg1(w, 0x1A);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->scale) != 0) {
                break;
            }
            Text_PrintIdList(w->labelTexts, (TextIdListEntry *)Cd_GetFileEntry(0x513000B), 2);
            w->textArgs[0] = (s32)Save_GameStatePtr->playerName;
            tbl = (s16 *)Cd_GetFileEntry(0x513000F);
            w->textArgs[1] = (s32)Cd_GetFileEntry(tbl[Save_GameStatePtr->rankTitleSet * 11 + Save_GameStatePtr->rank] + 0x1FD0000);
            w->textArgs[2] = (s32)Save_GameStatePtr->beetleName;
            p = &w->textArgs[3];
            for (i = 0; i < w->digiCount; i++) {
                *p++ = (s32)w->digiList[i]->name;
            }
            *p = 0;
            Text_PrintList(w->listTexts, (Halves *)Cd_GetFileEntry(0x513000C), w->textArgs, 2);
            if (Menu_Ctx->flags & 1) {
                h = (Halves *)Cd_GetFileEntry(0x513000D);
                for (i = 0; i < 4; i++) {
                    v = (i == 3) ? Bug_GetMaxMemBugLevel() : Dung_StatePtr->status.bugLevels[i];
                    if (v != 0) {
                        id = v + 0x1FD00EC;
                        Text_OpenPacked(&w->bugTexts[i], (s32)Cd_GetFileEntry(i * 3 + id), 1, h[i]);
                    }
                }
            }
            for (i = w->digiCount; i < 3; i++) {
                Text_Close(&w->labelTexts[i * 3 + 7]);
                Text_Close(&w->labelTexts[i * 3 + 8]);
                Text_Close(&w->labelTexts[i * 3 + 9]);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (Pad_State[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w, 0x1A);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Menu_StatusDraw(Actor *actor) {
    MenuStatusWork *w = (MenuStatusWork *)actor->work;
    s32 *p;
    s32 *list;
    s32 i;
    GfxPart *obj;
    DigiRosterEntry *rec;

    if (w->scale == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513000E);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = (GfxPart *)Cd_GetFileEntry(*list);
        if (i == 0) {
            Gfx_SetPartsNumber(obj, 2, 8, Save_GameStatePtr->bits);
            Gfx_SetPartsNumber(obj, 4, 4, Save_GameStatePtr->maxHp);
            Gfx_SetPartsNumber(obj, 8, 4, Save_GameStatePtr->hp);
            Gfx_SetPartsNumber(obj, 0x10, 4, Save_GameStatePtr->maxMp);
            Gfx_SetPartsNumber(obj, 0x20, 4, Save_GameStatePtr->mp);
        } else if (i - 1 < w->digiCount) {
            rec = w->digiList[i - 1];
            Gfx_SetPartsNumber(obj, 2, 3, rec->maxHp);
            Gfx_SetPartsNumber(obj, 4, 3, rec->hp);
            Gfx_SetPartsNumber(obj, 8, 3, rec->maxMp);
            Gfx_SetPartsNumber(obj, 0x10, 3, rec->mp);
            Gfx_SetPartsNumber(obj, 0x20, 2, rec->level);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 0xFFFF);
        }
        Gfx_SetPartsScale((GfxPartScaleView *)obj, 0x1000, w->scale);
        list++;
        Gfx_DrawParts((s32)obj);
        i++;
    } while (*list != 0);
}
