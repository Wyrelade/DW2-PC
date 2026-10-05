#ifndef MAIN_PORTRAIT_H
#define MAIN_PORTRAIT_H

#include "main/game.h"

/* Functions src/main/portrait.c defines. */
void Text_PortraitInit(Actor *arg0, s32 *arg1);
void Text_PortraitTask(Actor *a0);
void Text_PortraitDraw(Actor *a0);
void Text_PortraitSetImage(Actor *arg0, s32 arg1);

#endif /* MAIN_PORTRAIT_H */
