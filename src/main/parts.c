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
#include "main/texslot.h"

/* Gfx_DrawPartsEx's cached rotation/scale and the matrix built from it (identity at boot). */
GfxPartRotCache Gfx_PartRotCache = {
    0, 0, { 0 }, 0x1000, 0x1000, 0x1000, { 0 },
    { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } }, { 0, 0, 0 } },
};
DATA_LABEL(Gfx_PartRotMatrix, Gfx_PartRotCache, 0x18);

void Gfx_DrawPartSprites(GfxPartSprite *s, GfxPartOTag *ot) {
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPkt *p;
    u16 tpage;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(s->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId & 0xFFFF0000);
    p = (GfxPartPkt *)Sys_State.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != s->partGroup) {
            continue;
        }
        p->s.c = s->color;
        p->s.tag.len = 4;
        p->s.c.code = 0x64;
        if (e->blend & 0x80) {
            p->s.c.code = 0x66;
            tpage = t->tpage + ((e->blend & 3) << 5);
        } else {
            tpage = t->tpage;
        }
        p->s.x0 = e->x + s->x;
        p->s.u0 = e->u + t->u;
        p->s.w = e->w;
        p->s.y0 = e->y + s->y;
        p->s.v0 = e->v;
        p->s.h = e->h;
        if (p->s.h == 0) {
            p->s.h--;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->s.clut = (e->clutRow + y + s->clutRow) << 6;
        } else {
            p->s.clut = ((e->clutY + t->clutY + e->clutRow + s->clutRow) << 6) |
                       (((e->clutX + t->clutX) >> 4) & 0x3F);
        }
        p->s.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->s + 1);
        p->t.tag.len = 1;
        p->t.code = 0xE1000600 | (tpage & 0x9FF);
        p->t.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->t + 1);
    }
    Sys_State.packet.addr = (s32)p;
}

void Gfx_DrawPartQuadsRot(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPolyFT4 *p;
    GfxPartRotXY out;
    SVec1D104 sv[4];
    s32 i;
    s32 u;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(((GfxPartSprite *)arg0)->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(((GfxPartSprite *)arg0)->fileId & 0xFFFF0000);
    p = (GfxPartPolyFT4 *)Sys_State.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != ((GfxPartSprite *)arg0)->partGroup) {
            continue;
        }
        p->c = ((GfxPartSprite *)arg0)->color;
        p->tag.len = 9;
        p->c.code = 0x2C;
        if (e->blend & 0x80) {
            p->c.code = 0x2E;
            p->v[1].extra = t->tpage | ((e->blend & 3) << 5);
        } else {
            p->v[1].extra = t->tpage;
        }
        sv[0].vx = sv[2].vx = e->x;
        sv[1].vx = sv[3].vx = e->x + e->w;
        sv[0].vy = sv[1].vy = e->y;
        if (e->h) sv[2].vy = sv[3].vy = e->y + e->h; else sv[2].vy = sv[3].vy = e->y + 0xFF;
        sv[0].vz = sv[1].vz = sv[2].vz = sv[3].vz = 0;
        for (i = 0; i < 4; i++) {
            ApplyMatrixSV(arg1, &sv[i], &out);
            p->v[i].x = out.vx + ((GfxPartSprite *)arg0)->x;
            p->v[i].y = out.vy + ((GfxPartSprite *)arg0)->y;
        }
        u = e->u + t->u;
        p->v[0].u = p->v[2].u = u;
        u += e->w;
        p->v[1].u = p->v[3].u = u;
        if (((GfxPartSprite *)arg0)->scaleX < 0) {
            p->v[1].u = p->v[3].u = u - 1;
        }
        if (p->v[1].u == 0) {
            p->v[1].u = p->v[3].u = 0xFF;
        }
        p->v[0].v = p->v[1].v = e->v;
        u = e->v + e->h;
        p->v[2].v = p->v[3].v = u;
        if (((GfxPartSprite *)arg0)->scaleY < 0) {
            p->v[2].v = p->v[3].v = u - 1;
        }
        if (p->v[2].v == 0) {
            p->v[2].v = p->v[3].v = 0xFF;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->v[0].extra = (e->clutRow + y + ((GfxPartSprite *)arg0)->clutRow) << 6;
        } else {
            p->v[0].extra = ((e->clutY + t->clutY + e->clutRow + ((GfxPartSprite *)arg0)->clutRow) << 6) |
                            (((e->clutX + t->clutX) >> 4) & 0x3F);
        }
        if (arg3 & 1) {
            p->v[0].x *= 2;
            p->v[1].x *= 2;
            p->v[2].x *= 2;
            p->v[3].x *= 2;
        }
        if (arg3 & 2) {
            p->v[0].y *= 2;
            p->v[1].y *= 2;
            p->v[2].y *= 2;
            p->v[3].y *= 2;
        }
        p->tag.addr = ((GfxPartOTag *)arg2)->addr;
        ((GfxPartOTag *)arg2)->addr = (u32)p;
        p++;
    }
    Sys_State.packet.addr = (s32)p;
}

void Gfx_HidePartsByMask(GfxPartMaskView *p, s32 mask) {
    s32 i;

    for (i = 0; p[i].fileId != 0; i++) {
        if (p[i].partMask & mask) {
            p[i].visible = 0;
        } else {
            p[i].visible = 1;
        }
    }
}

void Gfx_SetPartsScale(GfxPartScaleView *p, s32 a1, s32 a2) {
    if (p->fileId == 0) {
        return;
    }
    do {
        if (a1 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleX = a1;
        if (a2 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleY = a2;
        p++;
    } while (p->fileId != 0);
}

void Gfx_SetPartsNumber(GfxPart *p, s32 mask, s32 n, s32 val) {
    u8 d[8];
    GfxPart *q;
    s32 i = 0;
    s32 lead = 0;
    s32 k;
    s32 x;

    if (n < 0) {
        lead = 1;
        n = -n;
    }
    x = val;
    for (k = n - 1; k != -1; k--) {
        d[k] = x % 10;
        x /= 10;
    }
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                if (lead == 1 || i == n - 1 || d[i] != 0) {
                    lead = 1;
                    q->frame = d[i];
                } else {
                    q->frame = 0xFF;
                }
                i++;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
} /* identity matrix */
extern void Gfx_DrawPartSprites(GfxPartSprite *, GfxPartOTag *);
extern void Gfx_DrawPartQuadsRot(void *, void *, s32, s32);
extern void ScaleMatrix(Obj209 *, s32 *);

void Gfx_DrawPartsEx(void *arg0, s32 arg1) {
    Rec1D6B4 *s2 = (Rec1D6B4 *)arg0;
    s32 s3 = 0;
    s32 s4;

    if (arg1 != 0) {
        s32 f114 = Sys_State.centerY.s;
        s3 = 0;
        s3 = (Sys_State.centerX.s ^ 0x140) == s3;
        if (f114 == 0xF0) {
            s3 |= 2;
        }
    }
    if (s2->fileId == 0) {
        return;
    }
    do {
        s4 = Sys_State.otLayers.addr[s2->otLayer];
        if (s2->visible != 0) {
            if (s2->unscaled != 0) {
                if (s3 != 0) {
                    s2->rotZ = 0;
                    s2->rotY = 0;
                    s2->rotX = 0;
                    s2->scaleX = 0x1000;
                    s2->scaleY = 0x1000;
                } else {
                    Gfx_DrawPartSprites((GfxPartSprite *)s2, (GfxPartOTag *)s4);
                    goto Ladv;
                }
            }
            if (Gfx_PartRotCache.rotXY == *(s32 *)&s2->rotX &&
                Gfx_PartRotCache.rotZ == s2->rotZ &&
                Gfx_PartRotCache.scaleX == s2->scaleX &&
                Gfx_PartRotCache.scaleY == s2->scaleY) {
            } else {
                *(Agg1D6B4 *)&Gfx_PartRotCache = *(Agg1D6B4 *)&s2->rotX;
                Gfx_PartRotCache.scaleX = s2->scaleX;
                Gfx_PartRotCache.scaleY = s2->scaleY;
                RotMatrixYXZ(&Gfx_PartRotCache, (Obj209 *)&Gfx_PartRotCache.matrix);
                ScaleMatrix((Obj209 *)&Gfx_PartRotCache.matrix, &Gfx_PartRotCache.scaleX);
            }
            Gfx_DrawPartQuadsRot(s2, &Gfx_PartRotMatrix, s4, s3);
        }
    Ladv:
        s2 = (Rec1D6B4 *)((u8 *)s2 + 0x28);
    } while (s2->fileId != 0);
}

void Gfx_DrawParts(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 1);
}

void Gfx_DrawPartsNoResScale(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 0);
}
