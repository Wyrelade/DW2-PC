#ifndef MAIN_147FC_H
#define MAIN_147FC_H

#include "main/game.h"

/* Functions src/main/147FC.c defines, for the units after it. */
s32 Cd_CheckNextSector(void);
void Cd_ReadSectorCallback(s32 a0);
void Cd_ReadSyncCallback(s32 ev);
s32 Cd_PollRead(void);
void Cd_ReadFileAsync(s32 arg0, s32 arg1);
void Fx_ModelInit(Actor *arg0, Block1C *arg1);
void Fx_ModelTask(Actor *arg0);
void Fx_ModelDraw(Actor *arg0);

#endif /* MAIN_147FC_H */
