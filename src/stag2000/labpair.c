#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/areaselect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabPairUpdate(Actor *a);
void Stg20_LabPairDraw(void);

Stg20Cell Stg20_LabPairNamePos[2] = { { 18, 24 }, { 213, 24 } };
TaskDesc Stg20_LabPairDesc = { 0, Stg20_LabPairUpdate, Task_DefaultDestroy, (TaskFn)Stg20_LabPairDraw, 8, 0 };

void Stg20_LabPairUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Stg20_OpenText(w, (s32)Save_GameState.elems[Stg20_MenuState.dnaParent0].name, 0, &Stg20_LabPairNamePos[0], 0);
        Stg20_OpenText(&w[1], (s32)Save_GameState.elems[Stg20_MenuState.dnaParent1].name, 0, &Stg20_LabPairNamePos[1], 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabPairDraw(void) {
    Gfx_DrawParts((s32)Cd_GetFileEntry(0xD120007));
}
