#ifndef MAIN_CDREAD_H
#define MAIN_CDREAD_H

#include "main/game.h"

/* Functions src/main/cdread.c defines. */
s32 Cd_CheckNextSector(void);
void Cd_ReadSectorCallback(s32 a0);
void Cd_ReadSyncCallback(s32 ev);
s32 Cd_PollRead(void);
void Cd_ReadFileAsync(s32 arg0, s32 arg1);

#endif /* MAIN_CDREAD_H */
