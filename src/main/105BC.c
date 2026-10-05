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

/* RCS id of the original sys.c. */
const char D_800101E4[] = "$Id: sys.c,v 1.140 1998/01/12 07:52:27 noda Exp yos $";

ActorModel *Gfx_AttachModel(Actor *a0, s32 id) {
    s32 fresh = 0;
    GfxModelFile *m = (GfxModelFile *)Cd_GetFileOrNull(id);
    GfxModelFile *base = m;
    ActorModel *t = a0->model;
    ActorModel *s;
    s32 i;
    ModelQuadSection *p;
    ModelQuadSection *q;
    GfxModelTriSec *r;
    s32 v;
    Ent1FDBC20 *e;

    if (t == NULL) {
        a0->model = (ActorModel *)Mem_Alloc(0x7C, 2);
        Mem_Zero(a0->model, 0x7C);
        fresh = 1;
    } else if (t->file == m && m->relocated != 0) {
        return t;
    }
    s = a0->model;
    s->fileId = id;
    s->file = base;
    s->boneCount = m->count;
    s->boneVerts = (s16 **)base->tables;
    s->boneNormals = s->boneVerts + s->boneCount;
    s->bonePolys = (ModelQuadSection **)(s->boneNormals + s->boneCount);
    s->boneDepths = (s32 *)(s->bonePolys + s->boneCount);
    s->texAnimParts = s->boneDepths + s->boneCount;
    if (m->relocated == 0) {
        for (i = 0; i < s->boneCount; i++) {
            s->boneVerts[i] = (s16 *)((s32)s->boneVerts[i] + (s32)base);
            s->boneNormals[i] = (s16 *)((s32)s->boneNormals[i] + (s32)base);
            s->bonePolys[i] = (ModelQuadSection *)((s32)s->bonePolys[i] + (s32)base);
        }
        m->relocated = 1;
    }
    if (fresh) {
        s->maxVerts = 0;
        s->maxNormals = 0;
        for (i = 0; i < s->boneCount; i++) {
            if (s->maxVerts < *s->boneVerts[i]) {
                s->maxVerts = *s->boneVerts[i];
            }
            if (s->maxNormals < *s->boneNormals[i]) {
                s->maxNormals = *s->boneNormals[i];
            }
        }
        s->field_28 = 0;
        for (i = 0; i < s->boneCount; i++) {
            p = s->bonePolys[i];
            e = p->e;
            q = (ModelQuadSection *)(e + p->n);
            e = q->e;
            r = (GfxModelTriSec *)(e + q->n);
            v = r->e[r->n].v[0];
            if (s->field_28 < v) {
                s->field_28 = v;
            }
        }
        s->bones = (ModelBone *)Mem_Alloc(s->boneCount * sizeof(ModelBone), 2);
        s->screenXY = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertOtz = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertColors = (s32 *)Mem_Alloc(s->maxNormals * 4, 2);
    }
    return s;
}

void Gfx_CalcModelBoneMatrices(Actor *a0) {
    CoordMatrix cam;
    Mat1F668 light;
    ActorModel *s;
    ActorTransformView *o;
    ModelBone *d;
    GfxBoneScratchNode *sp;
    GfxBoneScratchNode *e;
    Blk20 *r;
    Blk20 *in;
    Blk20 *out;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    s = a0->model;
    o = a0->u38.ptr38;
    d = s->bones;
    cam = GsWSMATRIX;
    light = D_800619A8;
    sp = (GfxBoneScratchNode *)0x1F800000;
    sp[0].parent = 0;
    sp[0].local = o->matrix;
    sp[0].local.t[0] = o->posX;
    sp[0].local.t[1] = o->posY;
    sp[0].local.t[2] = o->posZ;
    sp[0].world.m = sp[0].local;
    for (i = 1; i < 9; i++) {
        sp[i].parent = &sp[i - 1];
    }
    n = s->boneCount;
    for (j = 0; j < n; j++, d++) {
        e = &sp[s->boneDepths[j] + 1];
        e->local = d->localMat;
        for (k = 0; k < 3; k++) {
            switch (k) {
            default:
            case 0:
                r = &e->parent->world.m;
                in = &e->local;
                out = &e->world.m;
                break;
            case 1:
                r = (Blk20 *)&cam;
                in = &e->world.m;
                out = &d->viewMat;
                break;
            case 2:
                r = (Blk20 *)&light;
                in = &e->world.m;
                out = &d->lightMat;
                break;
            }
            gte_SetRotMatrix(r);
            gte_ldclmv(&in->m.m[0][0]);
            gte_rtir();
            if (k == 1) {
                d->worldM0 = e->world.w[0];
                d->worldM1 = e->world.w[1];
            }
            gte_stclmv(&out->m.m[0][0]);
            gte_ldclmv(&in->m.m[0][1]);
            gte_rtir();
            if (k == 1) {
                d->worldM2 = e->world.w[2];
                d->worldM3 = e->world.w[3];
            }
            gte_stclmv(&out->m.m[0][1]);
            gte_ldclmv(&in->m.m[0][2]);
            gte_rtir();
            if (k == 1) {
                d->worldM4 = e->world.w[4];
                d->worldTx = e->world.w[5];
            }
            gte_stclmv(&out->m.m[0][2]);
            gte_SetTransMatrix(r);
            gte_ldlv0(in->t);
            gte_rtv0tr();
            if (k == 1) {
                d->worldTy = e->world.w[6];
                d->worldTz = e->world.w[7];
            }
            gte_stlvnl(out->t);
        }
    }
}


void Gfx_DrawTexModel(Actor *a0, s32 mode) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    ModelQuadGT4 *q;
    GfxModelTriGT3 *r;
    s32 i;
    s32 j;
    s32 n;

    s = a0->model;
    i = 0;
    e = s->bones;
    s->texSlot = (struct GfxModelTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId << 16);
    s->otzShift = Sys_State.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        gte_SetLightMatrix(&e->lightMat);
        Gfx_CalcNormalColors((Vert6Pmv *)s->boneNormals[i], (ModelProjView *)s);
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = (ModelQuadGT4 *)p->e;
            if (n != 0) {
                if (s->clutRow == 1) {
                    Gfx_AddQuadsGT4(q, n, s, 2);
                } else {
                    Gfx_AddQuadsGT4(q, n, s, j);
                }
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = (GfxModelTriGT3 *)((GfxModelTriSec *)p)->e;
            if (n != 0) {
                if (s->clutRow == 1) {
                    Gfx_AddTrisGT3(r, n, s, 2);
                } else {
                    Gfx_AddTrisGT3(r, n, s, j);
                }
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
    Gfx_AnimateModelTex(a0);
}


void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    Ent1FDBC20 *q;
    GfxModelTri *r;
    s32 i;
    s32 j;
    s32 n;

    i = 0;
    s = a0->model;
    e = s->bones;
    s->otzShift = Sys_State.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = p->e;
            if (n != 0) {
                Gfx_DrawWireQuads((GfxModelQuad *)q, n, (ModelProjView *)s, col);
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = ((GfxModelTriSec *)p)->e;
            if (n != 0) {
                Gfx_DrawWireTris((ModelWireTri *)r, n, (ModelProjView *)s, col);
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
}


extern void RotMatrixYXZ(void *, Obj209 *);
extern void ScaleMatrix(Obj209 *, s32 *);

void Actor_UpdateTransform(Actor *arg0) {
    Obj209 *obj = (Obj209 *)arg0->u38.ptr38;
    s32 local[3];

    obj->prevPos = obj->pos;
    RotMatrixYXZ(&obj->rot, obj);
    ApplyMatrixLV((CoordMatrix *)obj, &obj->moveX, local);
    obj->pos.x += local[0];
    obj->pos.y += local[1];
    obj->pos.z += local[2];
    if (obj->scaleX == 0x1000 && obj->scaleY == obj->scaleX &&
        obj->scaleZ == obj->scaleY) {
    } else {
        ScaleMatrix(obj, &obj->scaleX);
    }
    obj->moveZ = 0;
    obj->moveY = 0;
    obj->moveX = 0;
}

s32 Actor_ProjectToScreen(ContC40 *a0) {
    Mat1F668 m;
    AllocC40 *p;
    LongVec3 *t;
    s32 x, y;

    p = a0->transform;
    t = &p->t;
    *t = *(LongVec3 *)&p->posX;
    gte_SetRotMatrix(&GsWSMATRIX);
    gte_ldclmv(&p->m[0][0]);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&p->m[0][1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&p->m[0][2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);
    gte_SetTransMatrix(&GsWSMATRIX);
    gte_ldlv0(t);
    gte_rtv0tr();
    gte_stlvnl(m.t);
    gte_SetRotMatrix(&m);
    gte_SetTransMatrix(&m);
    gte_ldv0(Gfx_ZeroSVector);
    gte_rtps();
    gte_stsxy(&p->screenX);
    x = 0x160;
    y = 0x110;
    if (p->screenX < -x) return 1;
    if (p->screenX > x) return 1;
    if (p->screenY < -y) return 1;
    return p->screenY > y;
}


void Actor_RefreshTransform(s32 arg0) {
    Actor_UpdateTransform(arg0);
    Actor_ProjectToScreen(arg0);
}

extern void Mem_Zero(void *, s32);

void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2) {
    AllocC40 *p;
    if (a0->transform == 0) {
        a0->transform = (AllocC40 *)Mem_Alloc(0x90, 2);
    }
    Mem_Zero(a0->transform, 0x90);
    p = a0->transform;
    p->scaleZ = 0x1000;
    p->scaleY = 0x1000;
    p->scaleX = 0x1000;
    if (a1 != 0) {
        p->posX = a1[0];
        p->posY = a1[1];
        p->posZ = a1[2];
    }
    p->rotY = a2;
    Actor_RefreshTransform((s32)a0);
}

void Actor_StepAxisMotion(AxisMotion *a0, s32 a1) {
    s32 v = a0->speed + a0->accel;
    a0->speed = v;
    if (v > 0) {
        if (v >= a0->maxSpeed) {
            a0->speed = a0->maxSpeed;
        }
    } else if (a1 == 0) {
        a0->maxSpeed = 0;
        a0->accel = 0;
        a0->speed = 0;
    } else {
        if (v >= a0->maxSpeed) {
            a0->speed = -a0->maxSpeed;
        }
    }
}

s32 Actor_ApplyAxisMotion(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    if (i != 1) {
        Actor_StepAxisMotion(e, 0);
    } else {
        Actor_StepAxisMotion(e, 1);
    }
    if (i != 2) {
        (&p->moveDelta.vx)[i] += e->speed >> 8;
    } else {
        p->moveDelta.vz -= e->speed >> 8;
    }
    return e->speed >> 8;
}

s32 Actor_ApplyAxisMotionRev(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    Actor_StepAxisMotion(e, 0);
    switch (i) {
    case 0:
    case 1:
        (&p->moveDelta.vx)[i] -= e->speed >> 8;
        break;
    case 2:
        p->moveDelta.vz += e->speed >> 8;
        break;
    }
    return e->speed >> 8;
}

void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->speed = arg2->speed;
    e->accel = arg2->accel;
    e->maxSpeed = arg2->maxSpeed;
}

void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->maxSpeed = 0;
    e->accel = 0;
    e->speed = 0;
}

void Gfx_CalcNormalColors(Vert6Pmv *v, ModelProjView *o) {
    s32 n;
    CVECTOR *c;
    s32 i;

    n = v->vx;
    c = o->vertColors;
    v++;
    if (o->clutRow != 0) {
        for (i = 0; i < n; i++) {
            *c = o->flatColor;
            c++;
        }
        return;
    }
    gte_ldv0u(v);
    gte_ncs();
    gte_strgb(c);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_ncs();
        v++;
        c++;
        i++;
        gte_strgb(c);
    }
}

void Gfx_AddTrisGT3(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[3];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT3_20FD0 *p;
    s32 i;
    s32 z;

    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    tex = (GfxTexSlot *)s->texSlot;
    idx = s->otIndex;
    code = 0x36;
    if (mode == 1) {
        code = 0x34;
    }
    p = (PolyGT3_20FD0 *)Sys_State.packet.work;
    for (i = 0; i < n; i++, t++) {
        do {
            sxy[0] = xy[t->v[0]];
            sxy[1] = xy[t->v[1]];
            sxy[2] = xy[t->v[2]];
            gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
            gte_nclip();
            if (sxy[0] == sxy[1]) {
                break;
            }
            if (sxy[0] == sxy[2]) {
                break;
            }
            if (sxy[1] == sxy[2]) {
                break;
            }
            gte_stopz(&opz);
            if (opz <= 0) {
                break;
            }
            p->tag.len = 9;
            p->c0.code = 0x34;
            p->xy0 = sxy[0];
            p->xy1 = sxy[1];
            p->xy2 = sxy[2];
            p->c0 = col[t->c[0]];
            p->c1 = col[t->c[1]];
            p->c2 = col[t->c[2]];
            p->c0.code = code;
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            if (mode == 2) {
                p->tpage = tex->tpage | s->tpageFlags;
            } else {
                p->tpage = tex->tpage | t->tpage;
            }
            p->clut = t->clut + (((tex->vramY + s->clutRow) << 6) | ((tex->vramX >> 4) & 0x3F));
            p->u0 = t->u0 + tex->uOffset;
            p->u1 = t->u1 + tex->uOffset;
            p->u2 = t->u2 + tex->uOffset;
            p->v0 = t->v0;
            p->v1 = t->v1;
            p->v2 = t->v2;
            p->tag.addr = ((GfxModelOTag *)&Sys_State.otLayers.s[idx][z])->addr;
            ((GfxModelOTag *)&Sys_State.otLayers.s[idx][z])->addr = (u32)p;
            p++;
        } while (0);
    }
    Sys_State.packet.addr = (s32)p;
}


void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[4];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT4_2130C *p;
    s32 i;
    s32 z;
    SysState *g;

    tex = (GfxTexSlot *)s->texSlot;
    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    idx = s->otIndex;
    code = 0x3E;
    if (mode == 1) {
        code = 0x3C;
    }
    g = &Sys_State;
    p = (PolyGT4_2130C *)g->packet.work;
    for (i = 0; i < n; i++, t++) {
        do {
            sxy[0] = xy[t->v[0]];
            sxy[1] = xy[t->v[1]];
            sxy[2] = xy[t->v[2]];
            sxy[3] = xy[t->v[3]];
            gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
            gte_nclip();
        } while (0);
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[0] == sxy[3] ||
            sxy[1] == sxy[2] || sxy[1] == sxy[3] || sxy[2] == sxy[3]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 12;
        p->c0.code = 0x3C;
        do {
            p->xy0 = sxy[0];
            p->xy1 = sxy[1];
            p->xy2 = sxy[2];
            p->xy3 = sxy[3];
            p->c0 = col[t->c[0]];
            p->c1 = col[t->c[1]];
            p->c2 = col[t->c[2]];
            p->c3 = col[t->c[3]];
            p->c0.code = code;
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]] + sz[t->v[3]]) / 4;
            if (mode == 2) {
                p->tpage = tex->tpage | s->tpageFlags;
            } else {
                p->tpage = tex->tpage | t->tpage;
            }
            p->clut = t->clut + (((tex->vramY + s->clutRow) << 6) | ((tex->vramX >> 4) & 0x3F));
            p->u0 = t->u0 + tex->uOffset;
            p->u1 = t->u1 + tex->uOffset;
            p->u2 = t->u2 + tex->uOffset;
            p->u3 = t->u3 + tex->uOffset;
            p->v0 = t->v0;
            p->v1 = t->v1;
            p->v2 = t->v2;
            p->v3 = t->v3;
            p->tag.addr = ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr;
            ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr = (u32)p;
            p++;
        } while (0);
    }
    Sys_State.packet.addr = (s32)p;
}


s32 Gfx_ProjectModelVerts(Vert6Pmv *v, ModelProjView *o, s32 noCheck) {
    s32 otz;
    s32 flag;
    s32 n;
    SxyPmv *sxy;
    s32 *z;
    s32 zs;
    s32 xs;
    s32 ys;
    s32 i;
    SysState *scr;

    n = v->vx;
    v++;
    scr = &Sys_State;
    sxy = (SxyPmv *)o->screenXY;
    z = o->vertOtz;
    zs = o->otzShift;
    xs = scr->centerX.s != 320;
    ys = scr->centerY.s != 240;
    gte_ldv0u(v);
    gte_rtps();
    gte_stsxy(sxy);
    gte_stszotz(&otz);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_rtps();
        v++;
        i++;
        *z = otz >> zs;
        z++;
        sxy->vx >>= xs;
        sxy->vy >>= ys;
        sxy++;
        gte_stsxy(sxy);
        gte_stszotz(&otz);
        if (!noCheck) {
            gte_stflg(&flag);
            if (flag < 0) {
                return 1;
            }
        }
    }
    *z = otz >> zs;
    sxy->vx >>= xs;
    sxy->vy >>= ys;
    return 0;
}

s32 Gfx_IsOriginOffscreen(void) {
    SxyIso sxy;
    s32 flag;

    gte_ldv0(Gfx_ZeroVector);
    gte_rtps();
    gte_stflg(&flag);
    if (flag < 0) {
        return 1;
    }
    gte_stsxy(&sxy);
    if (sxy.vx < -0x160) {
        return 1;
    }
    if (sxy.vx > 0x160) {
        return 1;
    }
    if (sxy.vy < -0x110) {
        return 1;
    }
    return sxy.vy > 0x110;
}

void Gfx_DrawWireTris(ModelWireTri *t, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l;
    Tpage21ABC *tp;
    s32 idx;

    pk = (GfxModelOTag *)Sys_State.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, t++) {
        do {
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            ot = (u32 *)Sys_State.otLayers.s[idx] + z;
            l = (LINE_F4 *)pk;
            l->c = *col;
            l->tag.len = 6;
            l->c.code = 0x4E;
            l->end = 0x55555555;
            l->xy[0] = l->xy[3] = sxy[t->v[0]];
            l->xy[1] = sxy[t->v[1]];
            l->xy[2] = sxy[t->v[2]];
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    Sys_State.packet.addr = (s32)pk;
}

void Gfx_DrawWireQuads(GfxModelQuad *q, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 xy[4];
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l4;
    LINE_F2 *l2;
    s32 *layer;
    Tpage21ABC *tp;
    GfxModelQuad *last;
    s32 idx;

    pk = (GfxModelOTag *)Sys_State.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, q++) {
        do {
            z = (sz[q->v[0]] + sz[q->v[1]] + sz[q->v[2]] + sz[q->v[3]]) / 4;
            layer = Sys_State.otLayers.s[idx];
            ot = (u32 *)layer;
            xy[0] = sxy[q->v[0]];
            xy[1] = sxy[q->v[1]];
            xy[2] = sxy[q->v[2]];
            last = q;
            xy[3] = sxy[last->v[3]];
            l4 = (LINE_F4 *)pk;
            l4->c = *col;
            l4->tag.len = 6;
            l4->c.code = 0x4E;
            l4->end = 0x55555555;
            l4->xy[0] = xy[0];
            l4->xy[1] = xy[1];
            l4->xy[2] = xy[3];
            l4->xy[3] = xy[2];
            ot += z;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            l2 = (LINE_F2 *)pk;
            l2->c = *col;
            l2->tag.len = 3;
            l2->c.code = 0x42;
            l2->xy[0] = xy[2];
            l2->xy[1] = xy[0];
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F2 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    Sys_State.packet.addr = (s32)pk;
}
