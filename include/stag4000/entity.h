#ifndef STAG4000_ENTITY_H
#define STAG4000_ENTITY_H

/* Functions src/stag4000/entity.c defines. */
s32 Stg40_FixtureUpdate(Actor *a0);
void Stg40_GateUpdate(Actor *a0);
void Stg40_ChestQueueModel(Stg40ObjQueueView *a0, s32 a1);
s32 Stg40_ChestUpdate(Actor *a0);
s32 Stg40_MineUpdate(Actor *a0);
s32 Stg40_SporeUpdate(Actor *a0);
s32 Stg40_RockUpdate(Actor *a0);
s32 Stg40_BugUpdate(Actor *a0);

#endif /* STAG4000_ENTITY_H */
