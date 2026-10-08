#include "common.h"
#include "stag4000/stag4000.h"

/* Task callbacks this unit defines further down (the descriptor comes first). */
void Stg40_LinkedModelInit(Actor *a0, Stg40LinkedModelArg *a1);
void Stg40_LinkedModelUpdate(Actor *a0);
void Stg40_LinkedModelDraw(Actor *a0);

/* Unreferenced. */
u8 *D_800725D4[] = { D_80072AA8, D_80072AC0 };
Stg40LinkedModelDef Stg40_LinkedModelTable[] = {
    { 0x27E, 0 }, { 0x27F, 0 }, { 0x280, 0 }, { 0x281, 0 }, { 0x282, 0 }, { 0x283, 0 },
    { 0x284, 0 }, { 0x285, 0 }, { 0x27D, 1 }, { 0x27C, 1 }, { 0x27B, 1 },
};
TaskDesc Stg40_LinkedModelDesc = {
    (TaskInitFn)Stg40_LinkedModelInit, Stg40_LinkedModelUpdate, Task_DefaultDestroy, Stg40_LinkedModelDraw, 0x2C, 0,
};

void Stg40_LinkedModelInit(Actor *a0, Stg40LinkedModelArg *a1) {
    Stg40LinkedModelWork *w = (Stg40LinkedModelWork *)a0->work;

    w->parent = a1->parent;
    w->tableIndex = a1->tableIndex;
}

void Stg40_LinkedModelUpdate(Actor *a0) {
    Stg40LinkedModelWork *w = (Stg40LinkedModelWork *)a0->work;
    Stg40LinkedModelDef *ent;
    ActorModel *m;

    switch (a0->stateLevel0) {
    case 0:
    default:
        ent = &Stg40_LinkedModelTable[(s16)w->tableIndex];
        Actor_InitTransform(a0, w->pos, w->rotY);
        w->pos[2] = 0;
        w->pos[1] = 0;
        w->pos[0] = 0;
        w->rotY = 0;
        a0->digiId = w->digiId = ent->digiId;
        w->modelFile = Digi_GetModelFile(a0->digiId);
        w->animFile = Digi_GetAnimFile(a0->digiId, 4);
        Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
        Task_NextState0(a0);
        if (ent->field_2 != 1) {
            Anim_SetModelAnim(a0, 0x28);
            w->offsetY = 0;
            break;
        }
        Anim_SetModelAnim(a0, 0x2C);
        w->offsetY = -0xA80;
        Task_NextState1(a0);
        break;
    case 1:
        m = a0->model;
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (m->animDone < 0) {
                Task_SetState0(a0, 3);
            }
            break;
        case 1:
            if (m->animDone < 0) {
                Anim_SetModelAnim(a0, 0x28);
                Task_NextState1(a0);
            }
            break;
        case 2:
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg40_LinkedModelDraw(Actor *a0) {
    Stg40ChildWork *w = (Stg40ChildWork *)a0->work;
    Actor *p = P32(Actor, w->parent);
    Stg40Xform *x;

    if (((Stg40ActWork *)p->work)->drawn != 0) {
        x = (Stg40Xform *)a0->u38.ptr38;
        *x = *(Stg40Xform *)p->u38.ptr38;
        x->rotZ = 0;
        x->rotX = 0;
        x->rotY = 0;
        x->posY += w->offsetY;
        Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
        Anim_StepModelAnim(a0);
        Actor_UpdateTransform(a0);
        Gfx_CalcModelBoneMatrices(a0);
        Gfx_DrawTexModel(a0, 0);
    }
}
