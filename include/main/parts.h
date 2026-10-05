#ifndef MAIN_PARTS_H
#define MAIN_PARTS_H

#include "main/game.h"

/* Functions src/main/parts.c defines. */
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Gfx_DrawPartSprites(GfxPartSprite *, GfxPartOTag *);
extern void Gfx_DrawPartQuadsRot(void *, void *, s32, s32);
void Gfx_DrawPartSprites(GfxPartSprite *s, GfxPartOTag *ot);
void Gfx_DrawPartQuadsRot(void *arg0, void *arg1, s32 arg2, s32 arg3);
void Gfx_HidePartsByMask(GfxPartMaskView *p, s32 mask);
void Gfx_SetPartsScale(GfxPartScaleView *p, s32 a1, s32 a2);
void Gfx_SetPartsNumber(GfxPart *p, s32 mask, s32 n, s32 val);
void Gfx_DrawPartsEx(void *arg0, s32 arg1);
void Gfx_DrawParts(s32 arg0);
void Gfx_DrawPartsNoResScale(s32 arg0);

#endif /* MAIN_PARTS_H */
