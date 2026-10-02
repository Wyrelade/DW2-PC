#ifndef MAIN_12550_H
#define MAIN_12550_H

#include "main/game.h"

/* Functions src/main/12550.c defines or declares, for the units after it. */
extern s32 Mem_TestBit(u8 *, s32);
extern s32 func_80066B48(s32);
void func_80021D50(void);
void func_80021D58(void);
s32 func_80021D60(void);
void Save_ClearEventFlags(void);
s32 Mem_TestBit(u8 *arg0, s32 arg1);
s32 Flag_Test(s32 arg0);
s32 Flag_TestConds(Ent22038 *p);
void Mem_WriteBit(u8 *arg0, s32 arg1, s32 arg2);
void Digi_AddNew(s32 arg0);
void Flag_Set(s32 id, s32 val);
void Flag_ApplySets(FlagSetPair *p);
s32 Math_CycleRange(s32 v, s32 div, s32 lo, s32 hi);
s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);
void Save_ResetGameState(void);
void func_800224EC(s32 i, s32 v, s32 flag);
s32 func_80022518(s32 i);
void func_8002254C(s32 i, s32 v);
u8 func_80022578(void);
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

#endif /* MAIN_12550_H */
