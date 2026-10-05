#ifndef MAIN_GAMEDATA_H
#define MAIN_GAMEDATA_H

#include "main/game.h"

/* Functions src/main/gamedata.c defines. */
extern s32 Flag_TestConds();
extern void Flag_ApplySets();
extern void Mem_Zero(void *, s32);
u8 Digi_GetEvolutionTarget(s32 id, s32 val);
Ent1DB18 *Enemy_FindSetById(s32 id);
void Enemy_GetSetSummary(void *a0, Out1DB68 *out);
void Digi_InitFromTable(s32 a0, s32 a1, DigiRosterEntry *e);
void Enemy_InitRosterEntry(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o);
ItemTableEntry *Item_FindById();
s32 Item_GetNameText(s32 arg0);
s32 Item_GetDescText(s32 arg0);
s32 Item_GetCategory(s32 id);
s32 Item_GetLevel(s32);
s32 Item_CheckId(s32);
s32 func_8001E134(void);
s32 func_8001E158(void);
s32 Item_GetPrice(s32);
u8 Item_GetBodyMask(s32);
s32 Item_GetTableIndex(s32 id);
s32 Item_GetIdAtIndex(s32 a0);

#endif /* MAIN_GAMEDATA_H */
