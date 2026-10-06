#ifndef MAIN_DIGIBASE_H
#define MAIN_DIGIBASE_H

#include "main/game.h"

/* Functions src/main/digibase.c defines. */
DigiBaseData *Digi_FindBaseData();
u8 Digi_GetDnaGroup(s32);
u8 Digi_GetType(s32);
s32 Digi_GetRank(s32);
s32 Digi_GetSpecialty(s32);
u8 Digi_GetLearnedSkill(s32);
s32 Digi_GetStatGrowth(s32 id, s32 k);

#endif /* MAIN_DIGIBASE_H */
