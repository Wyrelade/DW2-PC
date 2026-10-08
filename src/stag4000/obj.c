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
                arg.parent = P32_SET(a0);
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

#ifdef DW2_NATIVE
#include <stdlib.h>
#include <string.h>

/* PG.8a 16:9: entities in the extra floor columns (floor.c Stg40_WideCols) are drawn through
 * side models: native copies of the actor, model and transform, so the game's own actor, model,
 * anim state (animDone / curAnim / pendingAnim drive the turn logic), RNG, heap and CD cache stay
 * as the retail 5-cell window leaves them. Stg40_ObjDraw only queues the entity; Sys_Main runs
 * Gfx_LateDraw after the draw pass, so the retail packets of the frame are already placed and
 * the side models only use what is left of the packet buffer. */
extern s32 Gfx_NoTexAnim;
extern void (*Gfx_LateDraw)(void);
extern ActorWork *Gpu_PrimBufs[];
extern GfxTexSlot Gfx_TexSlots[];
extern CdCacheEntry Cd_FileCache[0x50];

typedef struct {
    Actor *owner;  /* game actor drawn by this copy, NULL = free */
    s32 fileId;    /* model file */
    s32 file;      /* its cached data when built (a reload rebuilds) */
    s32 lastFrame; /* Sys_State.frameCount of the last draw */
    s32 anim;      /* anim it shows (wanted by the game), -1 none yet */
    s32 fallback;  /* showing anim 0x28 because the wanted anim file is not loaded */
    s32 needBytes; /* packet bytes at most: one prim per quad / triangle */
    Actor actor;
    ActorModel model;
    s32 xform[0x90 / 4];
} Stg40SideModel;

#define STG40_SIDE_MAX 32
static Stg40SideModel Stg40_SideModels[STG40_SIDE_MAX];
static Actor *Stg40_SideQueue[STG40_SIDE_MAX];
static s32 Stg40_SideCount;

static s32 Stg40_SideFileReady(s32 id) {
    CdCacheEntry *c;

    if (id == 0) {
        return 0;
    }
    c = Cd_FindCachedFile(id);
    return c != NULL && c->state == 3;
}

static s32 Stg40_SideAnimFile(Actor *a, s32 anim) {
    if (anim < 0 || anim >= 0x6E) {
        return 0;
    }
    return Digi_GetAnimFile(a->digiId, anim / 10);
}

static void Stg40_SideFree(Stg40SideModel *s) {
    free(s->model.bones);
    free(s->model.screenXY);
    free(s->model.vertOtz);
    free(s->model.vertColors);
    memset(s, 0, sizeof(*s));
}

/* The side model of owner, built (or rebuilt) for the model file; NULL when the file is not in
 * the CD cache (Gfx_AttachModel would load it synchronously). */
static Stg40SideModel *Stg40_SideModelFor(Actor *owner, s32 fileId) {
    Stg40SideModel *s;
    Stg40SideModel *pick = NULL;
    ActorModel *m;
    ModelQuadSection *p;
    GfxModelTriSec *r;
    s32 file;
    s32 i;
    s32 j;
    s32 v;
    s32 n;

    if (!Stg40_SideFileReady(fileId)) {
        return NULL;
    }
    file = Cd_FindCachedFile(fileId)->data;
    for (i = 0, s = Stg40_SideModels; i < STG40_SIDE_MAX; i++, s++) {
        if (s->owner == owner) {
            pick = s;
            break;
        }
        if (s->lastFrame == Sys_State.frameCount && s->owner != NULL) {
            continue; /* in use this frame */
        }
        if (pick == NULL || (pick->owner != NULL && (s->owner == NULL || s->lastFrame < pick->lastFrame))) {
            pick = s;
        }
    }
    if (pick == NULL) {
        return NULL;
    }
    s = pick;
    if (s->owner == owner && s->fileId == fileId && s->file == file) {
        return s;
    }
    Stg40_SideFree(s);
    s->owner = owner;
    s->fileId = fileId;
    s->file = file;
    s->lastFrame = Sys_State.frameCount - 2;
    s->anim = -1;
    s->actor.digiId = owner->digiId;
    s->actor.model = &s->model;
    s->actor.u38.ptr38 = (ActorTransformView *)s->xform;
    /* A non-NULL model whose file differs: Gfx_AttachModel binds the file without Mem_Alloc.
     * Buffers as in its fresh path, from the C heap. */
    m = Gfx_AttachModel(&s->actor, fileId);
    m->otIndex = 3;
    for (i = 0; i < m->boneCount; i++) {
        if (m->maxVerts < *P32(s16, m->boneVerts[i])) {
            m->maxVerts = *P32(s16, m->boneVerts[i]);
        }
        if (m->maxNormals < *P32(s16, m->boneNormals[i])) {
            m->maxNormals = *P32(s16, m->boneNormals[i]);
        }
        p = P32(ModelQuadSection, m->bonePolys[i]);
        for (j = 0; j < 2; j++) {
            n = p->n;
            s->needBytes += n * sizeof(PolyGT4_2130C);
            p = (ModelQuadSection *)((ModelQuadGT4 *)p->e + n);
        }
        v = ((GfxModelTriSec *)p)->e[((GfxModelTriSec *)p)->n].v[0];
        if (m->field_28 < v) {
            m->field_28 = v;
        }
        for (j = 0; j < 2; j++) {
            r = (GfxModelTriSec *)p;
            n = r->n;
            s->needBytes += n * sizeof(PolyGT3_20FD0);
            p = (ModelQuadSection *)((GfxModelTriGT3 *)r->e + n);
        }
    }
    m->bones = (ModelBone *)calloc(m->boneCount, sizeof(ModelBone));
    m->screenXY = (s32 *)calloc(m->maxVerts + 1, 4);
    m->vertOtz = (s32 *)calloc(m->maxVerts + 1, 4);
    m->vertColors = (s32 *)calloc(m->maxNormals + 1, 4);
    return s;
}

/* The game model's anim state and bone poses into the side model (same file). */
static void Stg40_SideCopyAnim(Stg40SideModel *s, ActorModel *real) {
    ActorModel *m = &s->model;

    m->animFileId = real->animFileId;
    m->animIndex = real->animIndex;
    m->animData = real->animData;
    m->animId = real->animId;
    m->animPos = real->animPos;
    m->animTimer = real->animTimer;
    m->animDone = real->animDone;
    m->animTable = real->animTable;
    m->bonePoseTables = real->bonePoseTables;
    memcpy(m->bones, real->bones, m->boneCount * sizeof(ModelBone));
    s->anim = real->animId;
    s->fallback = 0;
}

static s32 Stg40_SidePacketRoom(void) {
    return (s32)((sptr)Gpu_PrimBufs[Sys_State.bufIndex] + (sptr)Gpu_PrimBufs[2] - Sys_State.packet.addr);
}

/* Step and draw a side model whose transform is set; tint from the game model. */
static void Stg40_SideDrawModel(Stg40SideModel *s, ActorModel *real) {
    s32 *x = s->xform;

    if (!Stg40_SideFileReady(s->model.animFileId)) {
        return;
    }
    if (real != NULL) {
        s->model.clutRow = real->clutRow;
        s->model.tpageFlags = real->tpageFlags;
        ((Stg40ModelView *)&s->model)->fadeR = ((Stg40ModelView *)real)->fadeR;
        ((Stg40ModelView *)&s->model)->fadeG = ((Stg40ModelView *)real)->fadeG;
        ((Stg40ModelView *)&s->model)->fadeB = ((Stg40ModelView *)real)->fadeB;
    }
    ((Obj209 *)x)->moveX = 0;
    ((Obj209 *)x)->moveY = 0;
    ((Obj209 *)x)->moveZ = 0;
    Anim_StepModelAnim(&s->actor);
    Actor_UpdateTransform(&s->actor);
    Gfx_CalcModelBoneMatrices(&s->actor);
    Gfx_NoTexAnim = 1; /* no eye blink: Rand_Next, and the texture-anim timers in the file */
    Gfx_DrawTexModel(&s->actor, 0);
    Gfx_NoTexAnim = 0;
    s->lastFrame = Sys_State.frameCount;
}

/* Stg40_LinkedModelDraw for a parent drawn as a side model. */
static void Stg40_SideDrawChild(Actor *a0, Stg40SideModel *ps) {
    s32 *slot = (s32 *)a0->u34.children;
    Actor *c;
    Stg40ChildWork *cw;
    Stg40SideModel *s;
    Stg40Xform *x;

    if (slot == NULL || *slot == 0) {
        return;
    }
    c = (Actor *)(sptr)*slot;
    if (c->id != 0x207 || c->model == NULL || (c->stateLevel0 != 1 && c->stateLevel0 != 2)) {
        return;
    }
    cw = (Stg40ChildWork *)c->work;
    s = Stg40_SideModelFor(c, cw->modelFile);
    if (s == NULL || Stg40_SidePacketRoom() < s->needBytes + 0x100) {
        return;
    }
    if (s->lastFrame != Sys_State.frameCount - 1 || s->anim != c->model->animId ||
        s->model.animFileId != c->model->animFileId) {
        Stg40_SideCopyAnim(s, c->model);
    }
    memcpy(s->xform, ps->xform, sizeof(s->xform));
    x = (Stg40Xform *)s->xform;
    x->rotZ = 0;
    x->rotX = 0;
    x->rotY = 0;
    x->posY += cw->offsetY;
    Stg40_SideDrawModel(s, c->model);
}

/* Stg40_ObjDraw's visible part for an entity in the side columns, on its side model. */
static void Stg40_SideDrawEnt(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    ActorModel *real = a0->model;
    Stg40SideModel *s = NULL;
    Stg40Xform *x;
    s32 want;
    s32 vis;
    s32 r;

    vis = 1;
    r = Beetle_GetPart(0x11);
    if (r <= 0 || (Dung_StatePtr->dungeonIdx == 0x10 && r == 0x75)) {
        vis = 0;
    }
    if (e->flags & 1) {
        vis = 1;
    }
    if (!(e->flags & 0x4000) || !vis || a0->u38.ptr38 == NULL) {
        return;
    }
    if (!(e->flags & 0x400)) {
        s = Stg40_SideModelFor(a0, w->modelFile);
        if (s == NULL || Stg40_SidePacketRoom() < s->needBytes + 0x100) {
            return;
        }
        want = w->pendingAnim != -1 ? w->pendingAnim : w->curAnim;
        if (s->lastFrame != Sys_State.frameCount - 1 && w->pendingAnim == -1 && real != NULL &&
            real->file == s->model.file && real->bones != NULL && real->animId == want) {
            Stg40_SideCopyAnim(s, real); /* centre -> side: carry on with the game's pose */
        } else if (want != s->anim || (s->fallback && Stg40_SideFileReady(Stg40_SideAnimFile(a0, want))) ||
                   s->lastFrame != Sys_State.frameCount - 1) {
            s->fallback = 0;
            if (!Stg40_SideFileReady(Stg40_SideAnimFile(a0, want))) {
                if (!Stg40_SideFileReady(w->animFile)) {
                    return;
                }
                s->fallback = 1;
                Anim_SetModelAnim(&s->actor, 0x28);
            } else {
                Anim_SetModelAnim(&s->actor, want);
            }
            s->anim = want;
        }
    } else if (Stg40_SidePacketRoom() < 0x100) {
        return;
    }
    if (!(e->flags & 0x80)) {
        Stg40_DrawEntityShadow(&e->loc);
    }
    if (s == NULL) {
        return;
    }
    memcpy(s->xform, a0->u38.ptr38, sizeof(s->xform));
    x = (Stg40Xform *)s->xform;
    x->posX = (s16)((e->loc.posX - Stg40_RootState->viewX) * 40);
    x->posZ = (s16)-(((e->loc.posY - Stg40_RootState->viewY) << 11) / 64);
    x->posY = -(s16)e->loc.height;
    x->rotY = e->heading;
    x->scaleX = e->scaleX;
    x->scaleY = e->scaleY;
    x->scaleZ = e->scaleZ;
    Stg40_SideDrawModel(s, real);
    Stg40_SideDrawChild(a0, s);
}

/* Gfx_LateDraw: the queued side entities. The CD cache LRU stamps and the stamps of texture
 * slots that were hits are put back afterwards (the side draws load nothing but texture slots). */
static void Stg40_DrawSideEntities(void) {
    s32 cdUsed[0x50];
    s32 texFile[0x40];
    s32 texUsed[0x40];
    s32 i;

    for (i = 0; i < 0x50; i++) {
        cdUsed[i] = Cd_FileCache[i].lastUsed;
    }
    for (i = 0; i < 0x40; i++) {
        texFile[i] = Gfx_TexSlots[i].fileId;
        texUsed[i] = Gfx_TexSlots[i].lastUsed;
    }
    for (i = 0; i < Stg40_SideCount; i++) {
        Stg40_SideDrawEnt(Stg40_SideQueue[i]);
    }
    Stg40_SideCount = 0;
    for (i = 0; i < 0x50; i++) {
        Cd_FileCache[i].lastUsed = cdUsed[i];
    }
    for (i = 0; i < 0x40; i++) {
        if (Gfx_TexSlots[i].fileId == texFile[i]) {
            Gfx_TexSlots[i].lastUsed = texUsed[i];
        }
    }
}
#endif

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
#ifdef DW2_NATIVE
    /* PG.8a 16:9: the extra floor columns; drawn after the draw pass on a side model */
    else if (Host_WideMargin(Sys_State.centerX.s * 2) != 0 && dx < 0x140 + STG40_WIDE_COLS * 0x40 &&
             dy < 0x140 && Stg40_SideCount < STG40_SIDE_MAX) {
        Stg40_SideQueue[Stg40_SideCount++] = a0;
        Gfx_LateDraw = Stg40_DrawSideEntities;
    }
#endif
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
