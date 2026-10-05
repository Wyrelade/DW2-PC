#ifndef MAIN_ITEMUSE_H
#define MAIN_ITEMUSE_H

#include "main/game.h"

/* Functions src/main/itemuse.c defines. */
void Menu_UseItemDirect(Actor *a0);
void Menu_UseBugZapItem(Actor *a0);
void Menu_OpenItemNameTexts(Actor *a0, s32 a1);
void Menu_OpenBugTexts(Actor *a0, s32 a1);
void Menu_ShowPartSlotInfo(Actor *a0);
void Menu_OpenUseItemTexts(Actor *a0);
void Menu_UseItemOnTarget(Actor *a0);
void Menu_SetItemUseMode(Actor *a, s16 arg);
void Menu_ItemUseTask(Actor *a0);
void Menu_ItemUseDraw(Actor *actor);

#endif /* MAIN_ITEMUSE_H */
