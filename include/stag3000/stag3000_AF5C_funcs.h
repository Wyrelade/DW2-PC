#ifndef STAG3000_AF5C_FUNCS_H
#define STAG3000_AF5C_FUNCS_H

/* Functions src/stag3000/stag3000_AF5C.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
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
void Stg30_FighterSetAnim(Actor *a0, s32 anim);
void Stg30_FighterInit(Actor *a0, s32 *args);
void Stg30_SpawnSkillCastFx(Actor *a0, s32 k);
void Stg30_SpawnSkillHitFx(Actor *a0);
void Stg30_PlayHitReactSound(Actor *a0);
void Stg30_HitReactUpdate(Actor *arg0, s32 arg1);
void Stg30_FighterTask(Actor *arg0);
void Stg30_FighterDestroy(Actor *a0);
void Stg30_FighterDraw(Actor *a0);
void Stg30_FighterSetVisible(Actor *a0, s32 a1);
void Stg30_FighterQueueHomeReset(Actor *a0);
void Stg30_FightMsgInit(Stg30TaskHead *a0, s32 *args);
void Stg30_FightMsgUpdate(Stg30TaskHead *a0);
void Stg30_FightMsgDraw(Stg30TaskHead *a0);
void Stg30_PopupInit(Actor *a0, Vec3 *args);
void Stg30_PopupUpdate(Actor *a0);
void Stg30_PopupDraw(Actor *a0);

#endif /* STAG3000_AF5C_FUNCS_H */
