#ifndef MAIN_FACESLOT_H
#define MAIN_FACESLOT_H

#include "main/game.h"

/* Functions src/main/faceslot.c defines. */
void Gfx_TexSlotTaskInit(Actor *arg0);
void Gfx_TexSlotTaskKill(Actor *arg0);
void Gfx_FindOrLoadImageSlot(s32 id, GfxImageInfo *out, GfxVramPos *pos, GfxVramPos *clut);

#endif /* MAIN_FACESLOT_H */
