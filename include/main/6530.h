#ifndef MAIN_6530_H
#define MAIN_6530_H

#include "main/game.h"

/* Functions src/main/6530.c defines or declares, for the units after it. */
void Menu_ItemUseDraw(Actor *actor);
void Item_BuildMenuList(MenuItemWork *w);
void Menu_DrawItemGrid(MenuItemWork *a0, s32 a1);
void Item_MoveToStorage(Actor *a0, MenuItemWork *w);
void Item_TakeFromStorage(Actor *a0, MenuItemWork *w);
void Menu_PickItemToUse(Actor *a0, MenuItemPickWork *o);
void Menu_ItemGridSelect(Actor *a0, GridMenu *m);
void Menu_ShowSelItemText(Actor *a0, MenuItemPickWork *o);
void Menu_ItemInit(Actor *arg0, s16 arg1);
void Menu_ItemTask(Actor *a0);

#endif /* MAIN_6530_H */
