#ifndef MAIN_GAMEMODE_H
#define MAIN_GAMEMODE_H

#include "main/game.h"

/* Functions src/main/gamemode.c defines. */
extern void Ovl_Load(s32);
void Ovl_Load(s32 id);
s32 Ovl_GetCurrentId(void);
void Sys_GameModeTask(Actor *a0);
#ifdef DW2_NATIVE
void Sys_GameModeDestroy(Actor *a0);
#else
void Sys_GameModeDestroy(void);
#endif

#endif /* MAIN_GAMEMODE_H */
