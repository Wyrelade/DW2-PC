#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"
#include "stag0000/font.h"
#include "stag0000/fightbg.h"
#include "stag0000/digiview.h"
#include "stag0000/lineup.h"
#include "stag0000/videomode.h"
#include "stag0000/groupview.h"
#include "stag0000/digimodel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1);
void Stg00_CameraTask(Actor *arg0);
void Stg00_CameraDraw(Actor *arg0);

TaskDesc Stg00_CameraDesc = {
    (TaskInitFn)Stg00_CameraInit, Stg00_CameraTask, Task_DefaultDestroy, Stg00_CameraDraw, 0x88, 0,
};

void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1) {
    *(Stg00CameraArg *)arg0->work = *arg1;
}

void Stg00_CameraTask(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        GsInitCoordinate2(NULL, &w->coord);
        w->dirty = 1;
        Task_NextState0(arg0);
    }
}

void Stg00_CameraDraw(Actor *arg0) {
    Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
    Stg00RefView rv;

    RotMatrixYXZ(&w->rotX, &w->coord.coord);
    w->coord.coord.t[0] = w->originX;
    w->coord.coord.t[1] = w->originY;
    w->coord.coord.t[2] = w->originZ;
    w->coord.flg = 0;
    rv.vpx = w->vpx;
    rv.vpy = w->vpy;
    rv.vpz = w->vpz;
    rv.vrx = w->vrx;
    rv.vry = w->vry;
    rv.vrz = w->vrz;
    rv.rz = 0;
    rv.super = &w->coord;
    GsSetProjection(w->projection);
    GsSetRefView2(&rv);
}

TaskEntry *Stg00_FindCamera(void) {
    return Task_FindFirst(0x109, -1, -1);
}

void Stg00_CamMoveViewPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->vpx += arg1;
        w->vpy += arg2;
        w->vpz += arg3;
    }
}

void Stg00_CamMoveRefPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->vrx += arg1;
        w->vry += arg2;
        w->vrz += arg3;
    }
}

void Stg00_CamSetProjection(Actor *arg0, s32 arg1) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->projection = arg1;
        w->dirty = 1;
    }
}

void Stg00_CamMoveOrigin(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->originX += arg1;
        w->originY += arg2;
        w->originZ += arg3;
    }
}

void Stg00_CamRotate(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->rotX += arg1;
        w->rotY += arg2;
        w->rotZ += arg3;
    }
}
