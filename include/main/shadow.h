#ifndef MAIN_SHADOW_H
#define MAIN_SHADOW_H

#include "main/game.h"

/* Functions src/main/shadow.c defines. */
void Gfx_ShadowInit(Actor *arg0, s32 *arg1);
void Gfx_ShadowUpdate(Actor *arg0);
void Gfx_ShadowDraw(Actor *arg0);

#endif /* MAIN_SHADOW_H */
