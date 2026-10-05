#ifndef MAIN_ANIM_H
#define MAIN_ANIM_H

#include "main/game.h"

/* Functions src/main/anim.c defines. */
void Anim_SetModelAnim(Actor *a, s32 n);
void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2);
s32 Anim_HasModelAnim(Actor *a0, s32 n);
void Anim_StepModelAnim(Actor *a);
void Gfx_ResetModelBones(Actor *a0);
void Gfx_AddFlatQuad3D(GfxQuadColor *col, GfxQuadVert *v, s32 flags, s32 idx);
void Gfx_InitLights(void);
s32 Gfx_AnimAllowsBlink(s32 arg0);
void Gfx_AnimateModelTex(Actor *a0);

#endif /* MAIN_ANIM_H */
