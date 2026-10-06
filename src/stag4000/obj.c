#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"

u8 Stg40_FlashPattern[] = { 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0xFF, 0 };
Stg40Col Stg40_FlashColors[] = {
    { 0xFF, 0xFF, 0xFF, 0 },
    { 0xFF, 0, 0, 0 },
    { 0xFF, 0, 0xFF, 0 },
};
TaskDesc Stg40_ObjDesc = {
    (TaskInitFn)Stg40_ObjInit, Stg40_ObjUpdate, Task_DefaultDestroy, Stg40_ObjDraw, 0x3C, 4,
};

void Stg40_SetLights(Blk16 *l, s32 r, s32 g, s32 b) {
    s32 i;
    Blk16 *p;

    for (i = 0, p = l; i < 3; i++, p++) {
        GsSetFlatLight(i, p);
    }
    GsSetAmbient(r, g, b);
    GsSetLightMode(0);
}

void Stg40_ObjStartFlash(Actor *a0, u8 a1) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    w->flashKind = a1;
    w->flashFrame = 0;
}

void Stg40_SetModelTint(Actor *a0, u8 on, u8 r, u8 g, u8 b) {
    Stg40ModelView *m = (Stg40ModelView *)a0->model;

    if (on == 0) {
        m->clutRow = 0;
        return;
    }
    m->clutRow = 2;
    m->fadeR = r;
    m->fadeG = g;
    m->fadeB = b;
}

s32 Stg40_ObjAnimDone(Actor *a0) {
    return a0->model->animDone < 0;
}

s32 Stg40_ObjStepMove(Stg40Ent48 *e) {
    s32 d;
    Stg40Loc *loc = &e->loc;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 c;

    if ((s16)e->targetHeading != e->heading) {
        c = e->heading;
        if (((s16)(e->targetHeading - ((u16)e->heading - 0x1000)) / 0x800) & 1) {
            e->heading = c - 0x100;
        } else {
            e->heading = c + 0x100;
        }
        e->heading &= 0xFFF;
        d = (s16)e->targetHeading - e->heading;
        if ((d >= 0) ? (d < 0x100) : ((e->heading - (s16)e->targetHeading) < 0x100)) {
            e->heading = e->targetHeading;
        }
    }
    e->octant = (s16)e->targetHeading / 512;
    if ((s16)e->targetHeading == e->heading && loc->moveFramesLeft != 0 && --loc->moveFramesLeft == 0 && loc->moving == 1) {
        loc->moving = 0;
    }
    x = loc->u0.pair.field_0 << 6;
    dx = ((x - (loc->prevTile.field_0 << 6)) * loc->moveFramesLeft) / loc->moveFrames;
    y = loc->u0.pair.field_2 << 6;
    dy = ((y - (loc->prevTile.field_2 << 6)) * loc->moveFramesLeft) / loc->moveFrames;
    loc->posX = x - dx;
    loc->posY = y - dy;
    e->roomId = Stg40_GetCell(loc->u0.pair.field_0, loc->u0.pair.field_2)->roomId;
    return loc->moveFramesLeft != 0;
}

void Stg40_ObjInit(Actor *a0, Stg40Ent48 *e)
{
  Stg40ActWork *w = (Stg40ActWork *) a0->work;
  Stg40Ent48 *new_var;
  Stg40Loc *loc;
  w->ent = e;
  e->actor = a0;
  if (e->digiId != (-1))
  {
    a0->digiId = e->digiId;
    w->modelFile = Digi_GetModelFile(a0->digiId);
    w->animFile = Digi_GetAnimFile(a0->digiId, 4);
    w->posZ = 0;
    w->posY = 0;
    w->posX = 0;
    w->rotY = (s16) e->targetHeading;
    w->field_20 = 0;
    w->field_22 = (w->field_23 = (w->field_24 = 0x80));
    w->flashKind = 0;
    w->flashFrame = 0;
    w->requeueTimer = 0;
  }
  loc = &e->loc;
  e->loc.u0.pair.field_0 = (loc->prevTile.field_0 = e->loc.u0.pair.field_0);
  loc->u0.pair.field_2 = (loc->prevTile.field_2 = e->loc.u0.pair.field_2);
  loc->moveFramesLeft = 0;
  loc->moveFrames = 1;
  loc->moving = 0;
  loc->posX = loc->u0.pair.field_0 << 6;
  loc->posY = loc->u0.pair.field_2 << 6;
  if (e->flags & 1)
  {
    Dung_StatePtr->scrollTarget = loc;
    Dung_StatePtr->playerLoc = loc;
    new_var = w->ent;
    Stg40_RootState->playerActor = a0;
    Stg40_RootState->playerEnt = new_var;
    Stg40_TurnQueueAdd(e->turnId);
  }
  w->drawn = 0;
}

void Stg40_ObjUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Arg207 arg;
    s32 *slot;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Task_NextState0(a0);
        if (w->ent->flags & 0x100) {
            if (w->ent->flags & 1) {
                Task_SetState1(a0, 5);
            }
            if (w->ent->flags & 2) {
                if (w->ent->flags & 0x800) {
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 3);
                }
            }
            if (w->ent->flags & 0x200) {
                Task_SetState1(a0, 0);
                w->ent->flags &= ~0x200;
            }
            w->ent->flags &= ~0x900;
        }
        Actor_InitTransform(a0, &w->posX, w->rotY);
        w->pendingAnim = 0x28;
        w->curAnim = -1;
        w->pendingLinkedModel = -1;
        w->linkedModel = -1;
        break;
    case 1:
        Stg40_ObjStepMove(w->ent);
        if (w->ent->flags & 1) {
            Stg40_PlayerUpdate(a0);
        }
        if (w->ent->flags & 2) {
            Stg40_EnemyUpdate(a0);
        }
        if (w->ent->flags & 4) {
            Stg40_FixtureUpdate(a0);
        }
        if (w->pendingLinkedModel != -1) {
            slot = (s32 *)a0->u34.children;
            if (*slot != 0) {
                Task_SetState0((Actor *)*slot, 3);
            } else {
                arg.parent = a0;
                arg.tableIndex = w->pendingLinkedModel;
                Task_Create(0x207, slot, (s32)&arg);
                w->linkedModel = w->pendingLinkedModel;
                w->pendingLinkedModel = -1;
            }
        }
        break;
    case 2:
        break;
    }
}

void Stg40_ObjDraw(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40Xform *x;
    s32 dx;
    s32 dy;
    s32 vis;
    s32 r;
    u8 k;

    w->drawn = 0;
    if (e->digiId == -1) {
        return;
    }
    dx = e->loc.posX - Stg40_RootState->viewX;
    if (dx < 0) {
        dx = Stg40_RootState->viewX - e->loc.posX;
    }
    dy = e->loc.posY - Stg40_RootState->viewY;
    if (dy < 0) {
        dy = Stg40_RootState->viewY - e->loc.posY;
    }
    if (dx < 0x1C0 && dy < 0x1C0) {
        Cd_QueueFile(w->modelFile);
        Cd_QueueFile(w->animFile);
    }
    if (dx < 0x140 && dy < 0x140) {
        vis = 1;
        r = Beetle_GetPart(0x11);
        if (r <= 0 || (Dung_StatePtr->dungeonIdx == 0x10 && r == 0x75)) {
            vis = 0;
        }
        if (e->flags & 1) {
            vis = 1;
        }
        Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
        if (w->pendingAnim != -1) {
            Anim_SetModelAnim(a0, w->pendingAnim);
            w->curAnim = w->pendingAnim;
            w->pendingAnim = -1;
        }
        x = (Stg40Xform *)a0->u38.ptr38;
        x->posX = (s16)((e->loc.posX - Stg40_RootState->viewX) * 40);
        x->posZ = (s16)-(((e->loc.posY - Stg40_RootState->viewY) << 11) / 64);
        x->posY = -(s16)e->loc.height;
        x->rotY = e->heading;
        x->scaleX = e->scaleX;
        x->scaleY = e->scaleY;
        x->scaleZ = e->scaleZ;
        if ((e->flags & 0x4000) && vis) {
            if (!(e->flags & 0x80)) {
                Stg40_DrawEntityShadow(&e->loc);
            }
            if (!(e->flags & 0x400)) {
                Anim_StepModelAnim(a0);
                Actor_UpdateTransform(a0);
                Gfx_CalcModelBoneMatrices(a0);
                Gfx_DrawTexModel(a0, 0);
            }
        }
        w->drawn = 1;
    }
    if (w->flashKind != 0) {
        k = Stg40_FlashPattern[w->flashFrame];
        if (k == 0xFF) {
            w->flashKind = 0;
            Stg40_SetModelTint(a0, 0, 0, 0, 0);
        } else {
            Stg40_SetModelTint(a0, k, Stg40_FlashColors[w->flashKind - 1].r, Stg40_FlashColors[w->flashKind - 1].g,
                          Stg40_FlashColors[w->flashKind - 1].b);
            w->flashFrame++;
        }
    }
}
