#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabJogBgUpdate(Actor *a);
void Stg20_LabJogBgDraw(Actor *a);

TaskDesc Stg20_LabJogBgDesc = { 0, Stg20_LabJogBgUpdate, Task_DefaultDestroy, Stg20_LabJogBgDraw, 0, 0 };

void Stg20_LabJogBgUpdate(Actor *a) {
    if (a->stateLevel0 == 0) {
        Actor_InitTransform(a, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a, 0xD14)->otIndex = 5;
        Gfx_ResetModelBones(a);
        ((Stg20Rot *)a->u38.ptr38)->rotY = 0x200;
        Task_NextState0(a);
    }
}

const CVECTOR Stg20_JogBgWireColor = { 0xFF, 0x64, 0x00, 0x00 };
void Stg20_LabJogBgDraw(Actor *a) {
    CVECTOR c;

    Gfx_AttachModel(a, 0xD14);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    c = Stg20_JogBgWireColor;
    Gfx_DrawWireModel(a, 1, &c);
}
