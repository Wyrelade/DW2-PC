#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/F400.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/105BC.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"
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
