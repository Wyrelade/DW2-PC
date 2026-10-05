#ifndef MAIN_TEXSLOT_H
#define MAIN_TEXSLOT_H

#include "main/game.h"

/* Functions src/main/texslot.c defines. */
extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
GfxTexSlot *Gfx_GetTexSlot(s32 arg0);
void Gfx_InitTexSlots(void);
s32 Gfx_GetTimPixelMode();
void Gfx_LoadTexSlotImage(GfxTexSlot *a0);
GfxTexSlot *Gfx_FindOrLoadTexSlot(s32 id);
void Gfx_SetTexSlotCount(s32 arg0);
s32 Gfx_ReserveTexSlot(void);
void Gfx_ReleaseTexSlot(s32 *arg0);

#endif /* MAIN_TEXSLOT_H */
