#ifndef STAG3500_TURN_H
#define STAG3500_TURN_H

/* Functions src/stag3500/turn.c defines. */
s32 Stg35_ApplySkillDamage(s32 arg0, s32 arg1, s32 arg2);
void Stg35_TurnOrderClear(void);
void Stg35_TurnOrderInsert(s32 arg0, s32 arg1);
void Stg35_TurnOrderRemove(s32 arg0);
s32 Stg35_TurnOrderFind(s32 arg0);
s32 Stg35_TurnOrderFreeIndex(void);
s32 Stg35_TurnOrderGet(s32 arg0);
void Stg35_BuildTurnOrder(void);
void Stg35_SetChosenAction(s32 arg0, s32 arg1);

#endif /* STAG3500_TURN_H */
