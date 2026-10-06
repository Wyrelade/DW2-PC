#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_BeetleShopMenuUpdate(Actor *a);
void Stg20_BeetleShopMenuDestroy(Actor *a);
void Stg20_BeetleShopMenuDraw(Actor *a);

TaskDesc Stg20_BeetleShopMenuDesc = {
    0, Stg20_BeetleShopMenuUpdate, Stg20_BeetleShopMenuDestroy, Stg20_BeetleShopMenuDraw, 8, 0,
};

const Halves Stg20_BeetleMenuPartsPos = { 0x1B, 0x17 };
const Halves Stg20_BeetleMenuUpgradePos = { 0x54, 0x17 };
void Stg20_BeetleShopMenuUpdate(Actor *a) {
    s32 state = a->stateLevel0;
    s32 *w = (s32 *)a->work;

    switch (state) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Text_OpenById(w, 0xDD, 0, Stg20_BeetleMenuPartsPos);
        Text_OpenById(&w[1], 0xDE, 0, Stg20_BeetleMenuUpgradePos);
        Task_NextState0(a);
        break;

    case 1:
        do {
            /* p[-18] is Stg20_MenuState.result */
            s32 *p = &Stg20_MenuState.menuChoice;

            if (Pad_State[0].right > 0) {
                if (*p != 0) {
                    break;
                }
                *p = state;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].left > 0) {
                if (*p == 0) {
                    break;
                }
                *p -= 1;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].triangle > 0) {
                p[-18] = state;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 3);
            } else if (Pad_State[0].cross > 0) {
                p[-18] = 0;
                Snd_PlayById(0xA, 0);
                Task_SetState0(a, 3);
            }
        } while (0);
        break;

    case 2:
        break;
    }
}

void Stg20_BeetleShopMenuDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void Stg20_BeetleShopMenuDraw(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930008);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = Stg20_MenuState.menuChoice != 0 ? -0x57 : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}
