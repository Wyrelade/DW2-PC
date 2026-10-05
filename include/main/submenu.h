#ifndef MAIN_SUBMENU_H
#define MAIN_SUBMENU_H

#include "main/game.h"

/* Functions src/main/submenu.c defines. */
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Task_Create(u32, s32 *, s32);
void Menu_SubMenuInit(Actor *arg0, s16 arg1);
void Menu_SubMenuTask(Actor *a);
void Menu_SubMenuDraw(Actor *actor);

#endif /* MAIN_SUBMENU_H */
