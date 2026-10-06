#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/itemmenu.h"

s32 Stg40_ItemMenuParts[] = { 0x07D40003, 0x07D40007 };
TaskDesc Stg40_ItemMenuDesc = {
    (TaskInitFn)Stg40_ItemMenuInit, Stg40_ItemMenuUpdate, Task_DefaultDestroy, Stg40_ItemMenuDraw, 0x48, 0,
};
Actor *Stg40_ItemMenuTask;

void Stg40_ItemMenuSetCursor(a0, a1, a2)
    u8 a0;
    u8 a1;
    u8 a2;
{
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)Stg40_ItemMenuTask->work;

    w->cursorRow = a0;
    w->rowCount = a1;
    w->arrowFlags = a2;
    w->refresh = -1;
}

s32 *Stg40_ItemMenuGetTextIds(void) {
    return ((Stg40ItemMenuWork *)Stg40_ItemMenuTask->work)->rowTextIds;
}

void Stg40_ItemMenuInit(Actor *a0, s32 *a1) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;

    Stg40_ItemMenuTask = a0;
    w->hasDesc = *a1;
}

void Stg40_ItemMenuUpdate(Actor *a0) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;
    TextOpenArgs args;
    s32 n;
    s32 i;

    n = 6;
    if (w->hasDesc != 0) {
        n = 7;
    }
    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(w->rowTexts, n);
        w->scale = 0;
        Stg40_ItemMenuTask = a0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                args.x = 0x1B;
                args.y = 0x33;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                for (i = 0; i < w->rowCount; i++) {
                    args.text = w->rowTextIds[i];
                    Text_Open(&w->rowTexts[i], &args);
                    Text_SetOtLayer(w->rowTexts[i], 2);
                    args.y += 0xC;
                }
                if (w->hasDesc != 0) {
                    args.bigFont = 1;
                    args.text = w->descTextId;
                    args.x = 0x10;
                    args.y = 0x8A;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(&w->descText, &args);
                    Text_SetOtLayer(w->descText, 2);
                }
                w->refresh = 0;
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->refresh != 0) {
                Task_SetState1(a0, 0);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->rowTexts, n);
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

void Stg40_ItemMenuDraw(Actor *a0) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 n;
    s32 i;
    s32 mask;

    if (w->scale != 0) {
        n = 1;
        if (w->hasDesc != 0) {
            n = 2;
        }
        for (i = 0; i < n; i++) {
            p = (GfxPart *)Cd_GetFileEntry(Stg40_ItemMenuParts[i]);
            switch (i) {
            case 0:
            default:
                mask = ((w->arrowFlags & 1) == 0) << 2;
                if (!(w->arrowFlags & 2)) {
                    mask |= 8;
                }
                for (q = p; q->fileId != 0; q++) {
                    if (q->groupMask & 2) {
                        q->x = -0x90;
                        q->y = w->cursorRow * 12 - 0x46;
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                    if (q->groupMask & 0xC) {
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)p, mask);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
            Gfx_DrawParts((s32)p);
        }
    }
}
