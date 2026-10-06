#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_FightBgUpdate(Actor *arg0);
void Stg35_FightBgDraw(Actor *arg0);

TaskDesc Stg35_FightBgDesc = { 0, Stg35_FightBgUpdate, Task_DefaultDestroy, Stg35_FightBgDraw, 0, 0 };

void Stg35_FightBgUpdate(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        arg0->digiId = 0xD77;
        Actor_InitTransform(arg0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(arg0, arg0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void Stg35_FightBgDraw(Actor *arg0) {
    Gfx_AttachModel(arg0, arg0->digiId);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}
