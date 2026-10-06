#ifndef STAG3500_FIGHTER_H
#define STAG3500_FIGHTER_H

/* Functions src/stag3500/fighter.c defines. */
void Stg35_FighterSetAnim(Actor *arg0, s32 arg1);
void Stg35_FighterInit(Actor *arg0, Stg35Vec3 *arg1);
void Stg35_SpawnSkillCastFx(Actor *arg0, s32 arg1);
void Stg35_SpawnSkillHitFx(Actor *arg0);
void Stg35_PlayHitReactSound(Actor *arg0);
void Stg35_HitReactUpdate(Actor *arg0, s32 arg1);
void Stg35_FighterTask(Actor *arg0);
void Stg35_FighterDestroy(Actor *arg0);
void Stg35_FighterDraw(Actor *arg0);
void Stg35_FighterSetVisible(Actor *arg0, s32 arg1);
void Stg35_FighterQueueHomeReset(Actor *arg0);

#endif /* STAG3500_FIGHTER_H */
