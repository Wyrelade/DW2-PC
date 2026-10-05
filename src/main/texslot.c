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

/* Declarations the original file made before this code. */
extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
GfxTexSlot Gfx_TexSlots[0x40];

GfxTexSlot *Gfx_GetTexSlot(s32 arg0) {
    return &Gfx_TexSlots[arg0];
}

void Gfx_InitTexSlots(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Gfx_TexSlots[i].vramX = 0x3E0 - (i / 2) * 32;
        Gfx_TexSlots[i].index = i;
        Gfx_TexSlots[i].vramY = (i & 1) << 8;
        Gfx_TexSlots[i].fileId = 0;
        Gfx_TexSlots[i].lastUsed = 0;
        Gfx_TexSlots[i].colorMode = 0;
        Gfx_TexSlots[i].uOffset = 0;
        Gfx_TexSlots[i].tpage = 0;
    }
}

s32 Gfx_GetTimPixelMode() {
    return Cd_GetFileEntry()->packedId & 7;
}

void Gfx_LoadTexSlotImage(GfxTexSlot *a0) {
    u32 *p;
    u32 flags;
    RECT clut;
    RECT img;
    s32 hasClut;
    s32 mode;

    p = (u32 *)Cd_GetFileEntry(a0->fileId);
    p++;
    flags = *p++;
    hasClut = flags & 8;
    mode = flags & 7;
    if (hasClut) {
        if (mode) {
            clut.x = 0;
            clut.y = a0->index + 0x1E0;
            clut.w = 0x100;
            clut.h = 1;
            LoadImage((s32)&clut, (s32)((TimBlk *)p + 1));
        }
        p = (u32 *)((u8 *)p + *p);
    }
    img.x = a0->vramX;
    img.y = a0->vramY;
    img.w = ((TimBlk *)p)->rect.w;
    img.h = ((TimBlk *)p)->rect.h;
    LoadImage((s32)&img, (s32)((TimBlk *)p + 1));
}

GfxTexSlot *Gfx_FindOrLoadTexSlot(s32 id) {
    GfxTexSlot *e;
    GfxTexSlot *p;
    s32 i;
    s32 j;
    u32 best;
    s32 idx;
    s32 n;
    s32 tp;
    s32 t;

    p = Gfx_TexSlots;
    for (i = 0; i < 0x40; i++, p++) {
        if (p->fileId == -1) {
            continue;
        }
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == id) {
            p->lastUsed = Sys_State.frameCount;
            return p;
        }
    }
    best = -1;
    idx = 0;
    if (Gfx_GetTimPixelMode(id)) {
        n = 0x20;
        tp = 1;
    } else {
        n = 0x40;
        tp = 0;
    }
    e = Gfx_TexSlots;
    for (j = 0; j < n; j++, e++) {
        if (e->fileId == -1) {
            continue;
        }
        if (e->fileId == -2) {
            continue;
        }
        if (e->fileId == 0) {
            idx = j;
            break;
        }
        if (e->lastUsed < best) {
            best = e->lastUsed;
            idx = j;
        }
    }
    e = &Gfx_TexSlots[idx];
    e->fileId = id;
    e->lastUsed = Sys_State.frameCount;
    e->colorMode = tp;
    t = e->index & 2;
    e->uOffset = t == 0;
    if (tp) {
        e->uOffset <<= 6;
    } else {
        e->uOffset <<= 7;
    }
    e->tpage = (tp << 7) | ((e->vramY & 0x100) >> 4) | ((e->vramX & 0x3FF) >> 6) | ((e->vramY & 0x200) << 2);
    Gfx_LoadTexSlotImage(e);
    return e;
}

void Gfx_SetTexSlotCount(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        GfxTexSlot *p = Gfx_GetTexSlot(i);
        if (i >= arg0) {
            p->fileId = -1;
        } else {
            if (p->fileId == -1) p->fileId = 0;
        }
    }
}

s32 Gfx_ReserveTexSlot(void) {
    u32 min = -1;
    s32 best = 0;
    s32 i;
    GfxTexSlot *p = Gfx_TexSlots;

    for (i = 0; i < 24; i++, p++) {
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == 0) {
            best = i;
            break;
        }
        if ((u32)p->lastUsed < min) {
            min = p->lastUsed;
            best = i;
        }
    }
    p = &Gfx_TexSlots[best];
    p->fileId = -2;
    p->lastUsed = Sys_State.frameCount;
    p->colorMode = 0;
    p->uOffset = ((p->index & 2) == 0) << 7;
    p->tpage = ((p->vramY & 0x100) >> 4) | ((p->vramX & 0x3FF) >> 6) | ((p->vramY & 0x200) << 2);
    return (s32)p;
}

void Gfx_ReleaseTexSlot(s32 *arg0) {
    if (*arg0 == -2) {
        *arg0 = 0;
    }
}
