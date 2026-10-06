#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/enemy.h"
#include "stag4000/entity.h"
#include "stag4000/spawn.h"
#include "stag4000/automap.h"
#include "stag4000/camera.h"

TaskDesc Stg40_CameraDesc = {
    (TaskInitFn)Stg40_CameraInit, Stg40_CameraUpdate, Task_DefaultDestroy, (TaskFn)Stg40_CameraDraw, 0x274, 0,
};
/* Unreferenced: 8-byte module alignment (see stag4000.h .bss). */
s32 D_80072A9C = 0;

Actor *Stg40_CameraTask;

s32 Stg40_CamIsMoving(void) {
    return Stg40_CameraTask->stateLevel1;
}

void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3) {
    Actor *t = Stg40_CameraTask;
    Stg40CameraWork *w = (Stg40CameraWork *)t->work;

    w->moveGoal = *blk;
    w->moveFrames = a1;
    w->rotYEnd = a2;
    w->rotYDelta = a3;
    Task_SetState1(t, 1);
}

void Stg40_CamLoadScript(Stg40CamCmd *src) {
    Stg40CameraWork *w = (Stg40CameraWork *)Stg40_CameraTask->work;
    s32 i;

    w->scriptPos = w->script;
    w->scriptLeft = 0;
    for (i = 0; src->frames != 0; i++, src++) {
        w->script[i] = *src;
        w->scriptLeft++;
    }
}

void Stg40_CamNextCommand(Actor *a0) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;
    Stg40CamCmd *c;

    if (w->scriptLeft != 0) {
        c = w->scriptPos;
        Stg40_CamStartMove(&c->goal, c->frames, c->rotYEnd, c->rotYDelta);
        w->scriptLeft--;
        w->scriptPos++;
    }
}

void Stg40_CamMoveStep(Actor *task) {
    Stg40CameraWork *w = (Stg40CameraWork *)task->work;
    s32 dx;
    s32 x0;
    s32 y0;
    s32 z0;

    if (task->stateLevel2 >= w->moveFrames) {
        do {
            w->view.words[0] = w->moveGoal.words[4];
            w->view.words[1] = w->moveGoal.words[5];
            w->view.words[2] = w->moveGoal.words[6];
            w->rot[1] = (u16)w->rotYEnd;
            if (w->scriptLeft != 0) {
                Stg40_CamNextCommand(task);
            } else {
                Task_SetState1(task, 0);
            }
        } while (0);
        return;
    }
    x0 = w->moveGoal.words[0];
    dx = (x0 - w->moveGoal.words[4]) / w->moveFrames;
    y0 = w->moveGoal.words[1];
    z0 = w->moveGoal.words[2];
    w->view.words[0] = x0 - dx * task->stateLevel2;
    w->view.words[1] = y0 - ((y0 - w->moveGoal.words[5]) / w->moveFrames) * task->stateLevel2;
    w->view.words[2] = z0 - ((z0 - w->moveGoal.words[6]) / w->moveFrames) * task->stateLevel2;
    w->dirty = 1;
    w->rot[1] = (u16)w->rotYEnd + (w->rotYDelta / w->moveFrames) * (w->moveFrames - task->stateLevel2);
    task->stateLevel2 = task->stateLevel2 + 1;
}

void Stg40_CameraInit(Actor *a0, Block1C *a1) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;

    Stg40_CameraTask = a0;
    w->view = *a1;
    w->scriptPos = 0;
    w->scriptLeft = 0;
}

void Stg40_CameraUpdate(Actor *a0) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;
    Stg40RView v;

    switch (a0->stateLevel0) {
    case 0:
    default:
        GsInitCoordinate2(0, &w->coord);
        w->dirty = 1;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->scriptLeft != 0) {
                Stg40_CamNextCommand(a0);
            }
            break;
        case 1:
            Stg40_CamMoveStep(a0);
            break;
        }
        w->dirty = 0;
        RotMatrixYXZ(w->rot, &w->coord.coord);
        w->coord.coord.t[0] = w->originX;
        w->coord.coord.t[1] = w->originY;
        w->coord.coord.t[2] = w->originZ;
        w->coord.flg = 0;
        v.vpvr[0] = w->view.words[0];
        v.vpvr[1] = w->view.words[1];
        v.vpvr[2] = w->view.words[2];
        v.vpvr[3] = w->view.words[3];
        v.vpvr[4] = w->view.words[4];
        v.vpvr[5] = w->view.words[5];
        v.rz = 0;
        v.super = &w->coord;
        GsSetProjection(w->view.words[6]);
        GsSetRefView2(&v);
        break;
    case 2:
        break;
    }
}

void Stg40_CameraDraw(void) {
}
