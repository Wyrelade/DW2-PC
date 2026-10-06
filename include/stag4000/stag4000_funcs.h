#ifndef STAG4000_STAG4000_H
#define STAG4000_STAG4000_H

/* Functions src/stag4000/stag4000.c defines. */
void Stg40_RootUpdate(Actor *arg0);
s32 Stg40_AddPreloadId(s32 val);
void Stg40_InitDisplay(void);
void Stg40_InitFloorHeader(void);
void Stg40_InitDungeonEntry(void);
void Stg40_BuildFloorMap(void);
void Stg40_RootInit(void);
s32 Stg40_BeginTransition(Actor *arg0);
void Stg40_RootDraw(void);
void Stg40_RootDestroy(Actor *a0);
void Stg40_ClearPreloadList(void);
void func_80064930(Actor *a0, s32 a1);
void Stg40_SetupStage(Actor *a0);

#endif /* STAG4000_STAG4000_H */
