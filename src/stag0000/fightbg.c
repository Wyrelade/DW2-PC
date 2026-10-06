#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_FightBgTask(Actor *arg0);
void Stg00_FightBgDraw(Actor *arg0);

TaskDesc Stg00_FightBgDesc = { 0, Stg00_FightBgTask, Task_DefaultDestroy, Stg00_FightBgDraw, 0, 0 };

void Stg00_FightBgTask(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Actor_InitTransform(arg0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(arg0, 0x78)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void Stg00_FightBgDraw(Actor *arg0) {
    Gfx_AttachModel(arg0, 0x78);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}
