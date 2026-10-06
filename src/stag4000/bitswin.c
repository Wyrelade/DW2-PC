#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/bitswin.h"

Stg40TextPos Stg40_BitsLabelText = { 0x80, { 0xC4, 0x3A } };
TaskDesc Stg40_BitsWinDesc = { 0, Stg40_BitsWinUpdate, Task_DefaultDestroy, Stg40_BitsWinDraw, 0xC, 0 };

void Stg40_BitsWinUpdate(Actor *a0) {
    Stg40BitsWinWork *w = (Stg40BitsWinWork *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->text, 1);
        w->scale = 0;
        w->shownBits = Save_GameStatePtr->bits;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                Text_OpenById(w, Stg40_BitsLabelText.id, 0, Stg40_BitsLabelText.pos);
                Text_SetOtLayer(w->text, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (Save_GameStatePtr->bits < w->shownBits) {
                w->shownBits = (w->shownBits - 10 < Save_GameStatePtr->bits) ? Save_GameStatePtr->bits : w->shownBits - 10;
            }
            if (w->shownBits < Save_GameStatePtr->bits) {
                w->shownBits = (w->shownBits + 10 > Save_GameStatePtr->bits) ? Save_GameStatePtr->bits : w->shownBits + 10;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->text, 1);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Stg40_BitsWinDraw(Actor *a0) {
    ActorWork *w = a0->work;
    EntA0 *p;

    if (w->field_4 != 0) {
        p = Cd_GetFileEntry(0x7D40002);
        Gfx_SetPartsNumber((GfxPart *)p, 2, 8, w->field_8);
        Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_4);
        Gfx_DrawParts((s32)p);
    }
}
