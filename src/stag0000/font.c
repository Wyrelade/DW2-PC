#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

INCLUDE_BIN(Stg00_FontGlyphs, "assets/stag0000/font_glyphs.bin");

u8 *Stg00_FontTextBuf;
Stg00Work *Stg00_FontWork;

/* Unnamed: empty stub, called once by Stg00_DungSelPickFlag before the warp, no other ref. */
void func_80064E44(void) {
}

void Stg00_FontSetColor(s16 arg0) {
    Stg00Work *w = Stg00_FontWork;
    if (arg0 < 6) {
        w->color = arg0;
    } else {
        w->color = 0;
    }
}

void Stg00_FontInit(void) {
    s32 i;
    s32 n;
    s32 fill;
    u8 *src;
    u16 *p;
    RECT *r;

    Stg00_FontWork = (Stg00Work *)Mem_Alloc(NATIVE_SIZE(Stg00Work, 0x9D8), 2);
    Stg00_FontTextBuf = Stg00_FontWork->textBuf;
    Stg00_FontWork->texSlot = Gfx_ReserveTexSlot();
    n = 0x200;
    src = Stg00_FontGlyphs;
    r = &Stg00_FontWork->rectBig;
    r->x = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->x;
    r->y = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->y;
    r->w = 0x10;
    r->h = 0x40;
    r = (RECT *)&Stg00_FontWork->clutX;
    r->x = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->x;
    r->y = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->y + 0xF9;
    r->w = 0x10;
    r->h = 6;
    p = Stg00_FontWork->buf;
    fill = 0x2222;
    for (i = 0x3FF; i >= 0; i--) {
        p[i] = fill;
    }
    for (i = 0; i < n; i++, src++) {
        s32 k = (i / 64) * 128;

        k += (i % 8) * 16;
        k += ((i / 8) % 8) * 2;
        p[k] = 0;
        p[k] = *src >> 7;
        p[k] |= (*src & 0x40) ? 0x10 : 0;
        p[k] |= (*src & 0x20) ? 0x100 : 0;
        p[k] |= (*src & 0x10) ? 0x1000 : 0;
        p[k + 1] = 0;
        p[k + 1] = (*src >> 3) & 1;
        p[k + 1] |= (*src & 0x04) ? 0x10 : 0;
        p[k + 1] |= (*src & 0x02) ? 0x100 : 0;
        p[k + 1] |= (*src & 0x01) ? 0x1000 : 0;
    }
    p = Stg00_FontWork->clut;
    for (i = 0; i < 0x18; i++) {
        *p++ = 0;
        *p++ = 0;
        *p++ = 0;
        *p++ = 0;
    }
    p = Stg00_FontWork->clut;
    p[0x00] = 0x8000;
    p[0x10] = 0x8000;
    p[0x20] = 0x8000;
    p[0x01] = 0x3DEF;
    p[0x31] = 0x3DEF;
    p[0x11] = 0x0F;
    p[0x41] = 0x0F;
    p[0x21] = 0x3C00;
    p[0x51] = 0x3C00;
    LoadImage((RECT *)&Stg00_FontWork->clutX, (u32 *)Stg00_FontWork->clut);
    LoadImage(&Stg00_FontWork->rectBig, (u32 *)Stg00_FontWork->buf);
    Stg00_FontSetColor(0);
}

void Stg00_FontFree(void) {
    Gfx_ReleaseTexSlot(Stg00_FontWork->texSlot);
    Mem_Free((ActorWork *)Stg00_FontWork);
}

void Stg00_FontDrawStr(s32 arg0, s32 arg1, u8 *arg2)
{
    Stg00PolyFT4 *poly = (Stg00PolyFT4 *) Sys_State.packet.addr;
    Stg00OTag *ot = (Stg00OTag *) Sys_State.otLayers.s[0];
    Stg00Work *work = Stg00_FontWork;
    u8 ch;
    s32 x;
    s32 y = arg1 - Sys_State.centerY.s;
    Stg00TexSlot *tex;
    u16 clut;
    u16 tpage;
    s32 c;

    clut = ((work->clutY + work->color) << 6) | ((work->clutX >> 4) & 0x3F);
    tex = (Stg00TexSlot *) work->texSlot;
    x = arg0 - Sys_State.centerX.s;
    tpage = (1 << 5) | ((tex->y & 0x100) >> 4) | ((tex->x & 0x3FF) >> 6) | ((tex->y & 0x200) << 2);
    while ((ch = *arg2) != 0) {
        if ((u32) (ch - 0x20) < 0x50) {
            c = *arg2;
            if (c >= 0x60) {
                c -= 0x20;
            }
            c -= 0x20;
            poly->tag.b.len = 9;
            poly->code = 0x2C;
            poly->r0 = 0xFF;
            poly->g0 = 0xFF;
            poly->b0 = 0xFF;
            poly->tpage = tpage;
            poly->clut = clut;
            poly->u0 = c % 8 * 8 + ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u;
            poly->v0 = c / 8 * 8;
            poly->u1 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8 + 8;
            poly->v1 = c / 8 * 8;
            poly->u2 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8;
            poly->v2 = c / 8 * 8 + 8;
            poly->u3 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8 + 8;
            poly->v3 = c / 8 * 8 + 8;
            poly->x0 = x;
            poly->y0 = y;
            poly->x1 = x + 8;
            poly->y1 = y;
            poly->x2 = x;
            poly->y2 = y + 8;
            poly->x3 = x + 8;
            poly->y3 = y + 8;
            ((Stg00OTag *) &poly->tag)->addr = ot->addr;
            ot->addr = (u32) poly;
            poly++;
        }
        arg2++;
        x += 8;
    }
    Sys_State.packet.addr = (s32) poly;
}

void Stg00_FontDrawSheet(void) {
    Stg00PolyFT4 *p = (Stg00PolyFT4 *)Sys_State.packet.work;
    u32 *ot = Sys_State.otLayers.u[0];
    Stg00Work *w;
    Stg00TexSlot *t;
    s32 h;

    p->tag.b.len = 9;
    p->code = 0x2C;
    p->r0 = 0xFF;
    p->g0 = 0xFF;
    p->b0 = 0xFF;
    w = Stg00_FontWork;
    t = (Stg00TexSlot *)w->texSlot;
    p->tpage = (0 << 7) | (1 << 5) | ((t->y & 0x100) >> 4) | ((t->x & 0x3FF) >> 6) | ((t->y & 0x200) << 2);
    p->clut = (w->clutY << 6) | ((w->clutX >> 4) & 0x3F);
    p->u0 = ((Stg00TexSlot *)w->texSlot)->u;
    p->v0 = 0;
    p->u1 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u + 0x40;
    p->v1 = 0;
    p->u2 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u;
    p->v2 = h = 0x40;
    p->u3 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u + h;
    p->v3 = h;
    p->x0 = -0x20;
    p->y0 = -0x20;
    p->x1 = 0x20;
    p->y1 = -0x20;
    p->x2 = -0x20;
    p->y2 = 0x20;
    p->x3 = 0x20;
    p->y3 = 0x20;
    p->code &= ~2;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    p++;
    Sys_State.packet.work = (ActorWork *)p;
}

void Stg00_FontPrintBuf(s32 arg0, s32 arg1) {
    Stg00_FontDrawStr(arg0, arg1, Stg00_FontTextBuf);
}

void Stg00_FontPrintBufCentered(s32 arg0, s32 arg1) {
    Stg00_FontDrawStr(arg0 + Sys_State.centerX.s, arg1 + Sys_State.centerY.s, Stg00_FontTextBuf);
}
