#ifndef STAG4000_SPAWN_H
#define STAG4000_SPAWN_H

/* Functions src/stag4000/spawn.c defines. */
s32 Stg40_SpawnHazard();
s32 Stg40_AddEntity();
void Stg40_SpawnEnemyParties(void);
void Stg40_SpawnChests(void);
void Stg40_SpawnFixedHazards(void);
s32 Stg40_GetRegionCells(u8 (*tbl)[2], s32 v);
void Stg40_SpawnHazardAtRandom(u8 (*tbl)[2], s32 a1, s32 a2);
void Stg40_SpawnRandomHazards(void);
Stg40Ent48 *Stg40_FindEntAt(s16 x, s16 y);
void Stg40_RevealAllEnts(void);
s32 Stg40_IsEntAdjacent(Stg40Ent48 *a, Stg40Ent48 *b);
s32 Stg40_CheckEncounter(void);
s32 Stg40_DeltaToOctant(s32 dx, s32 dy);
void Stg40_ObjSetAnim();
void Stg40_ObjSetAnimIfNew(Actor *a0, s32 a1);
s32 Stg40_ObjWaitAnim(Actor *a0);
s32 Stg40_ObjWaitAnimOrSkip(Actor *a0);
void Stg40_LoadEventTiles(s32 a0);
s32 Stg40_CheckEventTile(void);
void Stg40_ObjQueueFiles(Stg40ObjQueueView *a0, s32 a1, s32 a2);
void Stg40_SetBeetlePart(s32 i, s32 item, u8 status);
s32 Stg40_GetBeetlePart();
s32 Stg40_GetPartLevel(s32 slot);
void Stg40_SetPartBroken(s32 i, u8 status);
void Stg40_DamageBeetle(s32 n);
s32 Stg40_ListUsableItems(Stg40ItemReq *a);
s16 Stg40_ListPartyDigi(s32 mode);

#endif /* STAG4000_SPAWN_H */
