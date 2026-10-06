#ifndef STAG3000_FIGHTER_H
#define STAG3000_FIGHTER_H

/* Functions src/stag3000/fighter.c defines. */
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

#endif /* STAG3000_FIGHTER_H */
