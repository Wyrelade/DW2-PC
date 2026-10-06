#ifndef STAG3000_TURN_H
#define STAG3000_TURN_H

/* Functions src/stag3000/turn.c defines. */
s32 Stg30_AiCanUseAction(s32 idx, s32 i, Stg30EnemyAi *p);
s32 Stg30_AiCheckCondition(s32 cond, s32 self);
s32 Stg30_PickTarget(s32 id, s32 kind, s32 def);
void Stg30_AiChooseEnemyTurns(void);
void Stg30_BuildTurnOrder(void);
s32 Stg30_CompareTypes(s32 a, s32 b);
s32 Stg30_UpdateTurnStatus(s32 idx);

#endif /* STAG3000_TURN_H */
