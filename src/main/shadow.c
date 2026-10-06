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

/* Shadow task (main task id 6): model 0x5B on the ground (y 0) under the root bone of the actor
 * given at create time; drawn while that actor lives. Created by the digimon status menu and the
 * stag0000 / stag3000 / stag3500 fighters; stag2000 has its own copy (Stg20_ShadowDesc).
 * Task callbacks the descriptor below names (defined further down). */
void Gfx_ShadowInit(Actor *arg0, s32 *arg1);
void Gfx_ShadowUpdate(Actor *arg0);
void Gfx_ShadowDraw(Actor *arg0);

TaskDesc Gfx_ShadowDesc = { (TaskInitFn)Gfx_ShadowInit, Gfx_ShadowUpdate, Task_DefaultDestroy, Gfx_ShadowDraw, 8, 0 };

/* work field_0 = the actor to follow. */
void Gfx_ShadowInit(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

/* Follow the target's root bone XZ at y 0; work field_4 = 1 while the target is alive. */
void Gfx_ShadowUpdate(Actor *arg0) {
    s32 state = arg0->stateLevel0;

    switch (state) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(arg0, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorWork *w = arg0->work;
        Actor *v1 = (Actor *)w->field_0;
        w->field_4 = 0;
        if (v1 != 0) {
            s32 st = v1->stateLevel0;
            if (st != 0 && st != 3) {
                ModelBone *de = v1->model->bones;
                ActorTransformView *dst = arg0->u38.ptr38;
                s32 t = de->worldTx;
                dst->posY = 0;
                dst->posX = t;
                dst->posZ = de->worldTz;
                w->field_4 = state;
            }
        }
        break;
    }
    case 2:
        break;
    }
}

/* Draw the shadow model while work field_4 is set. */
void Gfx_ShadowDraw(Actor *arg0) {
    if (arg0->work->field_4 != 0) {
        Gfx_AttachModel(arg0, 0x5B);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 1);
    }
}
