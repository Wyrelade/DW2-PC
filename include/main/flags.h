#ifndef MAIN_FLAGS_H
#define MAIN_FLAGS_H

#include "main/game.h"

/* Functions src/main/flags.c defines. */
extern s32 Mem_TestBit(u8 *, s32);
extern s32 Stg20_TestSpecialFlag(s32);
s32 Mem_TestBit(u8 *arg0, s32 arg1);
s32 Flag_Test(s32 arg0);
s32 Flag_TestConds(Ent22038 *p);
void Mem_WriteBit(u8 *arg0, s32 arg1, s32 arg2);
void Digi_AddNew(s32 arg0);
void Flag_Set(s32 id, s32 val);
void Flag_ApplySets(FlagSetPair *p);
s32 Math_CycleRange(s32 v, s32 div, s32 lo, s32 hi);
s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);

#endif /* MAIN_FLAGS_H */
