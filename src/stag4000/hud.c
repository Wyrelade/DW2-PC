#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/hud.h"

Stg40TextPos Stg40_HudLabels[] = {
    { 0x76, { 0xC4, 0x16 } },
    { 0x77, { 0xC4, 0x22 } },
};
s32 Stg40_HudParts[] = { 0x07D40000, 0x07D40001 };
TaskDesc Stg40_HudDesc = { 0, Stg40_HudUpdate, Task_DefaultDestroy, Stg40_HudDraw, 0x18, 4 };

void Stg40_HudUpdate(Actor *a0) {
    Stg40HudWork *w = (Stg40HudWork *)a0->work;
    Stg40HudChildren *s3 = (Stg40HudChildren *)a0->u34.children;
    TextOpenArgs args;
    Stg40FloorHeader *fe;
    s32 n;
    s32 x = 0x12;
    s32 sh;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->labelText0, 3);
        w->scale = 0;
        s3->bitsWinTask = 0;
        n = Dung_StatePtr->floorHdr->nameLen - 6;
        sh = n;
        do {
            if (n >= 7) {
                sh = 6;
            }
        } while (0);
        w->partMask = ~(1 << sh);
        w->shownHp = Save_GameStatePtr->hp;
        w->shownMp = Save_GameStatePtr->mp;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                fe = Dung_StatePtr->floorHdr;
                args.x = x;
                args.y = 0x16;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                args.text = (s32)fe->name;
                Text_Open(&w->nameText, &args);
                Text_SetOtLayer(w->nameText, 2);
                Text_OpenById(&w->labelText0, Stg40_HudLabels[0].id, 0, Stg40_HudLabels[0].pos);
                Text_OpenById(&w->labelText1, Stg40_HudLabels[1].id, 0, Stg40_HudLabels[1].pos);
                Text_SetOtLayer(w->labelText0, 2);
                Text_SetOtLayer(w->labelText1, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->shownHp > Save_GameStatePtr->hp) {
                w->shownHp = (w->shownHp - 0x21 < Save_GameStatePtr->hp) ? Save_GameStatePtr->hp : (u16)w->shownHp - 0x21;
            }
            if (w->shownHp < Save_GameStatePtr->hp) {
                w->shownHp = (Save_GameStatePtr->hp < w->shownHp + 0x21) ? Save_GameStatePtr->hp : (u16)w->shownHp + 0x21;
            }
            if (Save_GameStatePtr->hp == 0) {
                w->shownHp = 0;
            }
            if (w->shownMp > Save_GameStatePtr->mp) {
                w->shownMp = (w->shownMp - 1 < Save_GameStatePtr->mp) ? Save_GameStatePtr->mp : (u16)w->shownMp - 1;
            }
            if (w->shownMp < Save_GameStatePtr->mp) {
                w->shownMp = (Save_GameStatePtr->mp < w->shownMp + 1) ? Save_GameStatePtr->mp : (u16)w->shownMp + 1;
            }
            if (Save_GameStatePtr->mp == 0) {
                w->shownMp = 0;
            }
            break;
        }
        if (s3->bitsWinTask != 0) {
            if (Dung_StatePtr->bitBugLevel == 0 && s3->bitsWinTask->stateLevel0 != 2) {
                Task_SetState0(s3->bitsWinTask, 2);
            }
        } else {
            if (Dung_StatePtr->bitBugLevel != 0) {
                Task_Create(0x20A, (s32 *)s3, 0);
            }
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            n = 3;
            Text_CloseArray(&w->labelText0, n);
            if (s3->bitsWinTask != 0) {
                Task_SetState0(s3->bitsWinTask, 2);
            }
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

void Stg40_HudDraw(Actor *a0) {
    Stg40HudDrawView *w = (Stg40HudDrawView *)a0->work;
    EntA0 *p;
    s32 i;

    if (w->scale != 0) {
        for (i = 0; i < 2; i++) {
            p = Cd_GetFileEntry(Stg40_HudParts[i]);
            switch (i) {
            case 0:
            default:
                Gfx_SetPartsNumber((GfxPart *)p, 2, 4, Save_GameState.maxHp);
                Gfx_SetPartsNumber((GfxPart *)p, 4, 4, w->shownHp);
                Gfx_SetPartsNumber((GfxPart *)p, 8, 4, Save_GameState.maxMp);
                Gfx_SetPartsNumber((GfxPart *)p, 0x10, 4, w->shownMp);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, w->partMask);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
            Gfx_DrawParts((s32)p);
        }
    }
}
