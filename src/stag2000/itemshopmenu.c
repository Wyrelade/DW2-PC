#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_ItemShopMenuUpdate(Actor *a);
void Stg20_ItemShopMenuDestroy(Actor *a);
void Stg20_ItemShopMenuDraw(Actor *a);

TaskDesc Stg20_ItemShopMenuDesc = {
    0, Stg20_ItemShopMenuUpdate, Stg20_ItemShopMenuDestroy, Stg20_ItemShopMenuDraw, 8, 0,
};

const Halves Stg20_ShopMenuBuyPos = { 0x1B, 0x17 };
const Halves Stg20_ShopMenuSellPos = { 0x3F, 0x17 };
void Stg20_ItemShopMenuUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Text_OpenById(w, 0x12B, 0, Stg20_ShopMenuBuyPos);
        Text_OpenById(&w[1], 0x12C, 0, Stg20_ShopMenuSellPos);
        Task_NextState0(a);
        break;

    case 1:
        do {
            s32 *p = &Stg20_MenuState.menuChoice;

            if (Pad_State[0].right > 0) {
                if (*p == 0) {
                    *p = a->stateLevel0;
                    Snd_PlayById(0xC, 0);
                }
            } else if (Pad_State[0].left > 0) {
                if (*p != 0) {
                    *p -= 1;
                    Snd_PlayById(0xC, 0);
                }
            } else if (Pad_State[0].triangle > 0) {
                p[-18] = a->stateLevel0;
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

void Stg20_ItemShopMenuDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void Stg20_ItemShopMenuDraw(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60004);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = Stg20_MenuState.menuChoice != 0 ? -0x6C : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}
