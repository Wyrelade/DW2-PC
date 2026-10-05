#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/4BCC.h"
#include "main/6530.h"
#include "main/77DC.h"
#include "main/E280.h"
#include "main/105BC.h"
#include "main/12550.h"
#include "main/12654.h"
#include "main/13584.h"
#include "main/cdread.h"

/* The Fx model task: a model played for a fixed time with one animation. */

/* Task callbacks the descriptor below names (defined further down). */
void Fx_ModelInit(Actor *arg0, Block1C *arg1);
void Fx_ModelTask(Actor *arg0);
void Fx_ModelDraw(Actor *arg0);
TaskDesc D_80048DD8 = { (TaskInitFn)Fx_ModelInit, Fx_ModelTask, Task_DefaultDestroy, Fx_ModelDraw, 0x1C, 0 };

void Fx_ModelInit(Actor *arg0, Block1C *arg1) {
    *(Block1C *)arg0->work = *arg1;
}

void Fx_ModelTask(Actor *arg0) {
    ActorWork *work = arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, &work->field_8, work->field_14);
        Gfx_AttachModel(arg0, work->field_0)->otIndex = 3;
        Anim_SetModelAnimFile(arg0, 0, work->field_4);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorModel *s = arg0->model;
        if (arg0->elapsed < work->duration && s->animDone >= 0)
            break;
        Task_SetState0(arg0, 3);
        break;
    }
    case 2:
        break;
    }
}

void Fx_ModelDraw(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->stateLevel0 == 1) {
        Gfx_AttachModel(arg0, w->field_0);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 0);
    }
}
