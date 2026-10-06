#ifndef MAIN_DIGIDATA_H
#define MAIN_DIGIDATA_H

#include "main/game.h"

/* Functions src/main/digidata.c defines. */
s32 Digi_GetDataFileId(s32 arg0);
DigiData *Digi_FindDataById(s32 id);
s32 Digi_GetModelFile(s32 id);
s32 Digi_GetAnimFile(s32 arg0, s32 arg1);
u8 *Digi_GetDefaultName(s32 id);
s16 func_8001E79C(s32 id);
s16 Digi_GetHitFxOffsetY(s32 id);
void Digi_GetCastFxOffsets(s32 a0, void *a1);
s32 func_8001E8D0(s32 id);
u16 Digi_GetModelListId(s32 idx);
s32 Digi_GetModelListCount(void);
s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur);
s32 Digi_CalcMaxLevel(s32 x);

#endif /* MAIN_DIGIDATA_H */
