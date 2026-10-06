#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_ShopBitsUpdate(Actor *a);
void Stg20_ShopBitsDestroy(Actor *a);
void Stg20_ShopBitsDraw(void);

TaskDesc Stg20_ShopBitsDesc = {
    0, Stg20_ShopBitsUpdate, Stg20_ShopBitsDestroy, (TaskFn)Stg20_ShopBitsDraw, 4, 0,
};

const Halves Stg20_BitsLabelPos = { 0xBD, 0x17 };
void Stg20_ShopBitsUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    if (a->stateLevel0 == 0) {
        Mem_FillWordsNeg1(w, 1);
        Text_OpenById(w, 0x5F, 0, Stg20_BitsLabelPos);
        Task_NextState0(a);
    }
}

void Stg20_ShopBitsDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

void Stg20_ShopBitsDraw(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60000);

    Gfx_SetPartsNumber(p, 2, 8, Save_GameState.bits);
    Gfx_DrawParts((s32)p);
}
