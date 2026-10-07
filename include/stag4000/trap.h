#ifndef STAG4000_TRAP_H
#define STAG4000_TRAP_H

/* Functions src/stag4000/trap.c defines. */
s32 Stg40_GetTrapDisarmRank(s32 i);
s32 Stg40_RollTrapDisarm(s32 i);
s32 Stg40_RollTrapEffect(void);
void Stg40_ShowTrapEffectMsg(s32 a0, s32 a1);
void Stg40_ApplyTrapEffect(s32 a0, s32 a1);
#ifdef DW2_NATIVE
s32 Stg40_GetPartState(s32 part);
#else
s32 Stg40_GetPartState(void);
#endif
s32 Stg40_PickRandomPart(void);

#endif /* STAG4000_TRAP_H */
