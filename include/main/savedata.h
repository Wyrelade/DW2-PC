#ifndef MAIN_SAVEDATA_H
#define MAIN_SAVEDATA_H

#include "main/game.h"

/* Functions src/main/savedata.c defines. */
void Save_ResetGameState(void);
void Beetle_SetPart(s32 i, s32 v, s32 flag);
s32 Beetle_GetPart(s32 i);
void Beetle_SetPartBroken(s32 i, s32 v);
u8 Beetle_GetDigiCapacity(void);
s32 Item_FindFreeBagSlot(void);
void Item_CompactBag(void);
void Item_SortList(void);
s32 Item_AddToBag(s32 id);
void Item_RemoveFromBag(s32 i);
s32 Item_GetBagCapacity(void);
s32 Digi_CountByState(s32 mode);
s32 Digi_ListByState(s32 mode, DigiRosterEntry **list);
void Digi_CompactRoster(void);
void Digi_SortRoster(void);

#endif /* MAIN_SAVEDATA_H */
