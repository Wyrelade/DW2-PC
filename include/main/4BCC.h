#ifndef MAIN_4BCC_H
#define MAIN_4BCC_H

#include "main/game.h"

/* Functions src/main/4BCC.c defines or declares, for the units after it. */
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Task_Create(u32, s32 *, s32);
void func_800143CC(Actor *arg0, s16 arg1);
void Menu_SubMenuTask(Actor *a);
void Menu_SubMenuDraw(Actor *actor);
void func_80014978(Actor *arg0, s16 arg1);
void func_80014984(Actor *a0);
void func_80014CBC(Actor *actor);
void Menu_UseItemDirect(Actor *a0);
void func_80014F78(Actor *a0);
void Menu_OpenItemNameTexts(Actor *a0, s32 a1);
void func_800153F4(Actor *a0, s32 a1);
void func_800154F0(Actor *a0);
void func_80015668(Actor *a0);
void Menu_UseItemOnTarget(Actor *a0);
void Menu_SetItemUseMode(Actor *a, s16 arg);
void Menu_ItemUseTask(Actor *a0);

#endif /* MAIN_4BCC_H */
