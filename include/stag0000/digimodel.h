#ifndef STAG0000_DIGIMODEL_H
#define STAG0000_DIGIMODEL_H

/* Functions src/stag0000/digimodel.c defines. */
void Stg00_DigiModelInit(Actor *arg0, Stg00ModelArg *arg1);
void Stg00_SpawnSkillCastFx(Actor *arg0, s32 arg1);
void Stg00_SpawnSkillHitFx(Actor *arg0);
void Stg00_HitReactUpdate(Actor *arg0, s32 arg1, s32 arg2);
void Stg00_ResetToHomePos(Actor *arg0);
void Stg00_DigiModelTask(Actor *arg0);
void Stg00_DigiModelDraw(Actor *arg0);

#endif /* STAG0000_DIGIMODEL_H */
