#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabDigiModelUpdate(Actor *a);
void Stg20_LabDigiModelDraw(Actor *a);

TaskDesc Stg20_LabDigiModelDesc = {
    0, Stg20_LabDigiModelUpdate, Task_DefaultDestroy, Stg20_LabDigiModelDraw, 0x3C, 0,
};

void Stg20_LabDigiModelUpdate(Actor *a) {
    Stg20Rot *o = (Stg20Rot *)a->u38.ptr38;
    Stg20DrawWork *w = (Stg20DrawWork *)a->work;
    Stg20ModelTint *t;
    s32 f;
    s32 st;
    s32 v;

    switch (a->stateLevel0) {
    case 0:
        switch (a->stateLevel1) {
        case 0:
        default:
            a->digiId = Stg20_MenuState.modelDigiId;
            w->modelId = Digi_GetModelFile(a->digiId);
            w->pos[0] = 0;
            w->pos[1] = 0;
            w->pos[2] = 0;
            a->param = Stg20_MenuState.modelSlide;
            Task_NextState1(a);
        case 1:
            f = Digi_GetModelFile(a->digiId);
            Cd_QueueFile(f);
            st = Cd_GetFileState(f);
            if (st != 3) {
                break;
            }
            f = Anim_GetModelAnimFile(a->digiId, 0);
            Cd_QueueFile(f);
            if (Cd_GetFileState(f) != st) {
                break;
            }
            Task_NextState1(a);
        case 2:
            Actor_InitTransform(a, w->pos, w->rot);
            o = (Stg20Rot *)a->u38.ptr38;
            Gfx_AttachModel(a, w->modelId)->otIndex = 3;
            Anim_SetModelAnim(a, 0);
            t = (Stg20ModelTint *)a->model;
            w->field_1C = 1;
            w->field_20 = 0;
            t->b = 0x80;
            t->g = 0x80;
            t->r = 0x80;
            w->field_26 = 0;
            w->field_25 = 0;
            w->field_24 = 0;
            if (Stg20_MenuState.modelNoGrow == 0) {
                o->scaleZ = 0;
                o->scaleY = 0;
                o->scaleX = 0;
            }
            w->visible = 1;
            Task_NextState0(a);
            if (a->param != 0) {
                Task_SetState1(a, 2);
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            break;
        case 1:
            if (o->posX > -0x640) {
                o->posX -= 0x20;
            } else {
                o->posX = -0x640;
                Task_SetState1(a, 0);
            }
            break;
        case 2:
            if (o->posX < 0x640) {
                o->posX += 0x20;
            } else {
                o->posX = 0x640;
                Task_SetState1(a, 0);
            }
            break;
        }
        if (a->param != 0) {
            o->rotY -= 0xB;
        } else {
            o->rotY += 0xB;
        }
        if (o->scaleX != 0x1000) {
            v = o->scaleX + 0x100;
            o->scaleX = v;
            o->scaleZ = v;
            o->scaleY = v;
        }
        break;
    case 2:
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabDigiModelDraw(Actor *a) {
    Stg20DrawWork *w = (Stg20DrawWork *)a->work;

    if (w->visible != 0) {
        Gfx_AttachModel(a, w->modelId);
        Anim_StepModelAnim(a);
        Actor_UpdateTransform(a);
        Gfx_CalcModelBoneMatrices(a);
        Gfx_DrawTexModel(a, 0);
    }
}
