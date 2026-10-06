#ifndef STAG3000_BATTLESTATE_H
#define STAG3000_BATTLESTATE_H

/* Functions src/stag3000/battlestate.c defines. */
s32 Stg30_GetSkillEffectKind(s32 id);
s32 Stg30_TargetFirst(s32 team, s32 flag, s32 mode);
s32 Stg30_TargetPrev(s32 team, s32 cur, s32 flag, s32 mode);
s32 Stg30_TargetNext(s32 team, s32 cur, s32 flag, s32 mode);
void Stg30_TurnOrderClear(void);
void Stg30_TurnOrderInsert(s32 idx, s32 v);
void Stg30_TurnOrderRemove(s32 i);
s32 Stg30_TurnOrderFind(s32 v);
s32 Stg30_TurnOrderFreeIndex(void);
s32 Stg30_TurnOrderGet(s32 i);
void Stg30_SaveFighterStates(void);
void Stg30_RestoreFighterStates(void);

#endif /* STAG3000_BATTLESTATE_H */
