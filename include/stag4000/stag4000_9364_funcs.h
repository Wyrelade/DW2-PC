#ifndef STAG4000_9364_FUNCS_H
#define STAG4000_9364_FUNCS_H

/* Functions src/stag4000/stag4000_9364.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
s32 Stg40_FixtureUpdate(Actor *a0);
void Stg40_GateUpdate(Actor *a0);
void Stg40_ChestQueueModel(Stg40ObjQueueView *a0, s32 a1);
s32 Stg40_ChestUpdate(Actor *a0);
s32 Stg40_MineUpdate(Actor *a0);
s32 Stg40_SporeUpdate(Actor *a0);
s32 Stg40_RockUpdate(Actor *a0);
s32 Stg40_BugUpdate(Actor *a0);

#endif /* STAG4000_9364_FUNCS_H */
