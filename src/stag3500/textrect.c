#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"

void Stg35_TextAlloc(Stg35TextHandle *arg0) {
    Stg35TextObj *p = (Stg35TextObj *)Mem_Alloc(0x1C, 2);

    arg0->text = p;
    Mem_Zero(p, 0x1C);
    arg0->text->slot = -1;
}

void Stg35_TextFree(Stg35TextHandle *arg0) {
    if (arg0->text != NULL) {
        Text_Close(arg0->text);
        Mem_Free(arg0->text);
        arg0->text = NULL;
    }
}

void Stg35_TextSetLayout(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->text->bigFont = arg1 >> 8;
    arg0->text->color = 0;
    arg0->text->x = arg2;
    arg0->text->y = arg3;
    arg0->text->charDelay = arg1 & 0xFF;
}

void Stg35_TextSetString(Stg35PartsHandle *arg0, s32 arg1) {
    arg0->load->mode = arg1;
}

void Stg35_TextSetColor(Stg35PartsHandle *arg0, s32 arg1) {
    arg0->load->u.color = arg1;
}

void Stg35_TextSetSysMsg(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
}

void Stg35_TextSetSkillName(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->text = Skill_GetNameText(arg1);
}

void Stg35_TextOpen(Stg35TextHandle *arg0) {
    Stg35TextObj *t = arg0->text;
    TextOpenArgs a;

    a.text = t->text;
    a.bigFont = t->bigFont;
    a.color = t->color;
    a.x = t->x;
    a.y = t->y;
    a.charAdvance = 0;
    a.lineAdvance = 0;
    a.charDelay = t->charDelay;
    Text_Open(t, &a);
}

void Stg35_TextClose(Stg35TextHandle *arg0) {
    Text_Close(arg0->text);
}

void Stg35_RectAlloc(Stg35SpriteHandle *arg0) {
    arg0->sprite = (Stg35Sprite *)Mem_Alloc(0x20, 2);
    Mem_Zero(arg0->sprite, 0x20);
}

void Stg35_RectFree(Stg35SpriteHandle *arg0) {
    if (arg0->sprite != NULL) {
        Mem_Free(arg0->sprite);
        arg0->sprite = NULL;
    }
}

void Stg35_RectDraw(Stg35SpriteHandle *arg0) {
    Stg35Sprite *s = arg0->sprite;
    SysState *g;
    Stg35PolyG4 *p;
    u32 *ot;

    if (s->w != 0 && s->h != 0) {
        g = &Sys_State;
        p = (Stg35PolyG4 *)g->packet.work;
        ot = g->otLayers.u[s->otLayer];
        p->c0 = s->colors[0];
        p->c1 = s->colors[1];
        p->c2 = s->colors[2];
        p->c3 = s->colors[3];
        p->tag.b.len = 8;
        p->c0.code = 0x38;
        if (s->semiTrans != 0) {
            p->c0.code = 0x3A;
        }
        p->x0 = p->x2 = s->x;
        p->x1 = p->x3 = s->x + s->w;
        p->y0 = p->y1 = s->y;
        p->y2 = p->y3 = s->y + s->h;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        p++;
        if (s->semiTrans != 0) {
            SetDrawMode((Stg35DrMode *)p, 0, 0, (s->abr & 3) << 5, 0);
            ((Stg35DrMode *)p)->tag = (((Stg35DrMode *)p)->tag & 0xFF000000) | (*ot & 0xFFFFFF);
            *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
            p = (Stg35PolyG4 *)((Stg35DrMode *)p + 1);
        }
        g->packet.work = (ActorWork *)p;
    }
}

void Stg35_RectSetDrawMode(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3) {
    Stg35Sprite *s = arg0->sprite;
    s->otLayer = arg1;
    s->semiTrans = arg2;
    s->abr = arg3;
}

void Stg35_RectSetColor(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->colors[arg1].r = arg2;
    s->colors[arg1].g = arg3;
    s->colors[arg1].b = arg4;
}

void Stg35_RectSetWidth(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->w = arg1;
}

void Stg35_RectSetHeight(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->h = arg1;
}

void Stg35_RectSetX(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->x = arg1;
}

void Stg35_RectSetY(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->y = arg1;
}

void Stg35_RectSetBounds(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->x = arg1;
    s->y = arg2;
    s->w = arg3;
    s->h = arg4;
}

s32 Stg35_ScaleBarLen(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;

    if (arg2 >= arg1) {
        return arg0;
    }
    r = arg0 * arg2 / arg1;
    if (arg2 != 0 && r == 0) {
        r = 1;
    }
    if (r == arg1 && r != arg2) {
        r--;
    }
    return r;
}
