#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_ShadowInit(Actor *a, s32 v);
void Stg20_ShadowUpdate(Actor *a);
void Stg20_ShadowDraw(Actor *a);

TaskDesc Stg20_ShadowDesc = {
    (TaskInitFn)Stg20_ShadowInit, Stg20_ShadowUpdate, Task_DefaultDestroy, Stg20_ShadowDraw, 4, 0,
};

void Stg20_ShadowInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

void Stg20_ShadowUpdate(Actor *a) {
    Actor *t;

    switch (a->stateLevel0) {
    case 0:
        Actor_InitTransform(a, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(a);
        Task_NextState0(a);
        break;
    case 1:
        t = ((Stg20LinkWork *)a->work)->target;
        if (t != NULL && t->stateLevel0 != 0) {
            ((Stg20PosView *)a->u38.ptr38)->pos = ((Stg20PosView *)t->u38.ptr38)->pos;
        }
        break;
    case 2:
        break;
    }
}

void Stg20_ShadowDraw(Actor *a) {
    Gfx_AttachModel(a, 0x2F7);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    Gfx_DrawTexModel(a, 1);
}
