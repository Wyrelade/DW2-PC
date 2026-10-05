#ifndef MAIN_GAMEMODE_H
#define MAIN_GAMEMODE_H

#include "main/game.h"

/* Functions src/main/gamemode.c defines. */
extern void Ovl_Load(s32);
void Ovl_Load(s32 id);
s32 Ovl_GetCurrentId(void);
void Sys_GameModeTask(Actor *a0);
void Task_DefaultDestroy2(void);

#endif /* MAIN_GAMEMODE_H */
