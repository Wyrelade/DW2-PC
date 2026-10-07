#include "common.h"
#include "stag3000/stag3000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_FightBgUpdate(Actor *a0);
void Stg30_FightBgDraw(Actor *a0);

s32 Stg30_FightBgModels[] = { 0xE2D, 0xE2A, 0xE2C, 0xE29, 0xE2E, 0xE2B };
s32 Stg30_SpecialFightBgModel = 0xD77;
s32 Stg30_FightBgByFloorElem[] = { 5, 5, 0, 1, 2, 3, 4 };
TaskDesc Stg30_FightBgDesc = { 0, Stg30_FightBgUpdate, Task_DefaultDestroy, Stg30_FightBgDraw, 0, 0 };

void Stg30_FightBgUpdate(Actor *a0) {
    if (a0->stateLevel0 == 0) {
        if (Stg30_Battle.fromCity != 0) {
            a0->digiId = Stg30_SpecialFightBgModel;
        } else {
            a0->digiId = Stg30_FightBgModels[Stg30_FightBgByFloorElem[Dung_State.floorSpecialty]];
        }
        Actor_InitTransform(a0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a0, a0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(a0);
        Task_NextState0(a0);
    }
}

void Stg30_FightBgDraw(Actor *a0) {
    Gfx_AttachModel(a0, a0->digiId);
    Actor_UpdateTransform(a0);
    Gfx_CalcModelBoneMatrices(a0);
    Gfx_DrawTexModel(a0, 1);
}
