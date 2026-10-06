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
#include "main/digidata.h"

/* The three flat lights Gfx_InitLights sets: direction, then color. */
Blk16 Gfx_FlatLights[] = {
    { 0, 0x3200, 0, 0x80, 0x80, 0x80 },
    { -0x3200, 0, 0, 0x37, 0x37, 0x37 },
    { 0x3200, 0, 0, 0x37, 0x37, 0x37 },
};

void Anim_SetModelAnim(Actor *a, s32 n) {
    ActorModel *s = a->model;
    s32 i;
    s32 k;

    s->animId = n;
    s->animPos = 0;
    s->animData = 0;
    for (i = 10; i < 0x6F; i += 10) {
        if (n < i) {
            s->animFileId = Digi_GetAnimFile(a->digiId, i / 10 - 1);
            k = i - 10;
            s->animIndex = n - k;
            break;
        }
    }
    s->animTimer = 1;
    s->animDone = 0;
}

void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2) {
    ActorModel *p = arg0->model;
    p->animId = arg1;
    p->animPos = 0;
    p->animData = 0;
    p->animFileId = arg2;
    p->animIndex = 0;
    p->animTimer = 1;
    p->animDone = 0;
}

s32 Anim_HasModelAnim(Actor *a0, s32 n) {
    ActorModel *sub = a0->model;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        id = Digi_GetAnimFile(a0->digiId, 0);
        k = 0;
    } else if (n < 20) {
        id = Digi_GetAnimFile(a0->digiId, 1);
        k = n - 10;
    } else {
        id = Digi_GetAnimFile(a0->digiId, 2);
        k = n - 20;
    }
    p = (s32 *)(Cd_GetFileOrNull(id) + ((sub->boneCount + 1) << 2));
    sub->animTable = p;
    return p[k] != 0;
}

void Anim_StepModelAnim(Actor *a) {
    ActorModel *s = a->model;
    s32 *data = (s32 *)Cd_GetFileOrNull(s->animFileId);
    s32 i;
    s32 j;
    s32 k;
    ModelBone *e;
    u8 *f;
    u8 *q;
    s32 pos;
    Rec18 *r;

    if (data != s->animData) {
        s->animData = data;
        s->bonePoseTables = data + 1;
        {
            s32 n = s->boneCount + 1;
            s->animTable = &data[n];
        }
    }
    if (data[0] == 0) {
        data[0] = 1;
        for (k = 0; s->animTable[k] != 1; k++) {
            if (s->animTable[k] != 0) {
                s->animTable[k] += (s32)data;
            }
        }
        for (k = 0; k < s->boneCount; k++) {
            s->bonePoseTables[k] += (s32)data;
        }
    }
    s->animTimer += Sys_State.frameDelta;
    while (s->animTimer >= 2) {
        s->animTimer -= 2;
        e = s->bones;
        f = (u8 *)s->animTable[s->animIndex];
        pos = s->animPos;
        for (i = 0; i < s->boneCount; i++) {
            e->keyIndex = f[s->animPos++];
            e++;
        }
        q = &f[s->animPos];
        if (*q & 0x80) {
            switch (*q) {
            case 0xFF:
                s->animDone = -1;
                s->animPos = pos;
                goto done;
            case 0xFE:
                s->animPos = (q[2] << 8) | q[1];
                s->animDone = -1;
                break;
            }
        }
    }
done:
    {
        ModelBone *b = s->bones;
        s32 n;
        for (n = 0; n < s->boneCount; n++, b++) {
            r = &((Rec18 *)s->bonePoseTables[n])[b->keyIndex];
            b->localMat.m = r->m;
            for (j = 0; j < 3; j++) {
                b->localMat.t[j] = r->t[j];
            }
        }
    }
}

void Gfx_ResetModelBones(Actor *a0) {
    ActorModel *sub = a0->model;
    ModelBone *p = sub->bones;
    s32 i = 0;
    while (i < sub->boneCount) {
        i++;
        p->localMat = Gfx_IdentityMatrix;
        p++;
    }
}

void Gfx_AddFlatQuad3D(GfxQuadColor *col, GfxQuadVert *v, s32 flags, s32 idx) {
    Coord1F668 coord;
    Mat1F668 m;
    s32 pz;
    s32 flag;
    PolyF4_1F668 *p;
    PolyF4_1F668 *q;
    DrMode1F668 *dm;
    s32 *ot;
    SysState *g;

    GsInitCoordinate2(0, &coord);
    GsGetLs(&coord, &m);
    GsSetLsMatrix(&m);
    g = &Sys_State;
    p = (PolyF4_1F668 *)g->packet.work;
    ot = g->otLayers.s[idx];
    p->c = *col;
    SetPolyF4((u8 *)p);
    q = p;
    if (flags & 4) {
        p->c.code |= 2;
    }
    RotTransPers(&v[0], &p->xy[0], &pz, &flag);
    p->xy[0].x /= 2;
    p->xy[0].y /= 2;
    RotTransPers(&v[1], &p->xy[1], &pz, &flag);
    p->xy[1].x /= 2;
    p->xy[1].y /= 2;
    RotTransPers(&v[2], &p->xy[2], &pz, &flag);
    p->xy[2].x /= 2;
    p->xy[2].y /= 2;
    RotTransPers(&v[3], &p->xy[3], &pz, &flag);
    p->xy[3].x /= 2;
    p->xy[3].y /= 2;
    p->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p++;
    SetDrawMode((DrMode1F668 *)p, 0, 0, (flags & 3) << 5, 0);
    dm = (DrMode1F668 *)(q + 1);
    dm->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p = (PolyF4_1F668 *)(dm + 1);
    g->packet.work = (ActorWork *)p;
}

void Gfx_InitLights(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &Gfx_FlatLights[i]);
    }
    GsSetAmbient(0x4CC, 0x4CC, 0x4CC);
    GsSetLightMode(0);
}

s32 Gfx_AnimAllowsBlink(s32 arg0) {
    if (arg0 == 0x64 || arg0 == 0xA || arg0 == 0x14) {
        return 0;
    }
    if (arg0 == 0x15) {
        return 0;
    }
    return arg0 != 0x16;
}

void Gfx_AnimateModelTex(Actor *a0) {
    ActorModel *w = a0->model;
    GfxTexAnimPart *r = (GfxTexAnimPart *)w->texAnimParts;
    GfxModelTexSlot *pos = w->texSlot;
    s32 k = 0;
    s32 j;
    s32 i;
    s32 c;
    s32 m;
    DR_MOVE *prim;
    RECT rc;
    RECT rc2;
    GfxModelTexAnim *q;
    u8 n;

    if (r->dstX != 0xFF) {
        if (Gfx_AnimAllowsBlink(w->animId) != 0) {
            switch (w->blinkTimer >> 1) {
            case 0:
                w->blinkTimer = (Rand_Next() & 0x7F) + 0x3C;
            default:
                k = 0;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                k = 2;
                break;
            case 3:
            case 4:
                k = 4;
                break;
            }
            if ((w->blinkTimer -= Sys_State.frameDelta) < 0) {
                w->blinkTimer = 0;
            }
        } else {
            k = 4;
            w->blinkTimer = 0;
        }
    }
    w->texAnimTimer += Sys_State.frameDelta;
    while (1) {
        if (w->texAnimTimer < 0x18) break;
        w->texAnimTimer -= 0x18;
    }
    j = (w->texAnimTimer / 8) * 2;
    prim = Sys_State.packet.drMove;
    for (i = 0; i < 10; i++, r++) {
        if (i < 2) {
            if (r->dstX == 0xFF) continue;
        } else {
            if (r->dstX == 0xFF) break;
            if (r->dstX == 0xFE) break;
        }
        if (i < 2) {
            rc.x = r->uv[k] + pos->vramX;
            rc.y = r->uv[k + 1] + pos->vramY;
        } else {
            rc.x = r->uv[j] + pos->vramX;
            rc.y = r->uv[j + 1] + pos->vramY;
        }
        rc.w = r->w;
        rc.h = r->h;
        SetDrawMove(prim, &rc, r->dstX + pos->vramX, r->dstY + pos->vramY);
        AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
        prim++;
    }
    if (r->dstX == 0xFE) {
        q = (GfxModelTexAnim *)&(r++)->dstY;
        for (c = 0; c < 10; c++, q++) {
            if (q->dstX == 0xFF) break;
            if (Sys_State.frameDelta == 1) {
                q->timer += 1;
            } else {
                q->timer += 2;
            }
            n = q->period;
            while (1) {
                if (q->timer < n) break;
                q->timer -= n;
            }
            m = (q->timer >> 1) * 4;
            rc2.x = q->uv[m] + pos->vramX;
            rc2.y = q->uv[m + 1] + pos->vramY;
            rc2.w = q->w;
            rc2.h = q->h;
            SetDrawMove(prim, &rc2, q->dstX + pos->vramX, q->dstY + pos->vramY);
            AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->vramX;
            rc2.y = q->uv[m + 3] + pos->vramY;
            rc2.w = q->w2;
            rc2.h = q->h2;
            SetDrawMove(prim, &rc2, q->dstX2 + pos->vramX, q->dstY2 + pos->vramY);
            AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
            prim++;
        }
    }
    Sys_State.packet.addr = (s32)prim;
}
