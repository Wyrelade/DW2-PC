#ifndef MAIN_SYS_H
#define MAIN_SYS_H

#include "main/game.h"

/* Functions src/main/sys.c defines. */
void Sys_VSyncHandler(void);
void Sys_Main(void);
void Rand_Seed(s32 a0);
void Rand_Step(void);
s32 Rand_Next(void);
u16 Rand_GetAt(u32 arg0);
void Sys_SetFrameRate60(void);
void Sys_SetFrameRate30(void);
void Sys_SetFrameRate20(void);
void Sys_SetFrameRate15(void);

#endif /* MAIN_SYS_H */
