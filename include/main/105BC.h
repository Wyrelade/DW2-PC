#ifndef MAIN_105BC_H
#define MAIN_105BC_H

#include "main/game.h"

/* Functions src/main/105BC.c defines, for the units after it. */
ActorModel *Gfx_AttachModel(Actor *a0, s32 id);
void Gfx_CalcModelBoneMatrices(Actor *a0);
void Gfx_DrawTexModel(Actor *a0, s32 mode);
void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
void Actor_UpdateTransform(Actor *arg0);
s32 Actor_ProjectToScreen(ContC40 *a0);
void Actor_RefreshTransform(s32 arg0);
void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
void Actor_StepAxisMotion(AxisMotion *a0, s32 a1);
s32 Actor_ApplyAxisMotion(ContC40 *a0, s32 i);
s32 Actor_ApplyAxisMotionRev(ContC40 *a0, s32 i);
void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2);
void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
void Gfx_CalcNormalColors(Vert6Pmv *v, ModelProjView *o);
void Gfx_AddTrisGT3(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode);
void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode);
s32 Gfx_ProjectModelVerts(Vert6Pmv *v, ModelProjView *o, s32 noCheck);
s32 Gfx_IsOriginOffscreen(void);
void Gfx_DrawWireTris(ModelWireTri *t, s32 n, ModelProjView *o, CVECTOR *col);
void Gfx_DrawWireQuads(GfxModelQuad *q, s32 n, ModelProjView *o, CVECTOR *col);

#endif /* MAIN_105BC_H */
