#ifndef STAG4000_C2CC_FUNCS_H
#define STAG4000_C2CC_FUNCS_H

/* Functions src/stag4000/stag4000_C2CC.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg40_RevealCell(Stg40TileWork *a0, s32 x, s32 y);
void Stg40_AutomapRevealAround(Stg40TileWork *w);
void Stg40_AutomapDrawModes(ActorWork *w);
void Stg40_AutomapInit(void);
void Stg40_AutomapUpdate(Actor *a0);
void Stg40_AutomapDestroy(Actor *a0);
void Stg40_AutomapDraw(Actor *a0);
void Stg40_AllocCellGrid(void);
void Stg40_FreeCellGrid(void);
u16 Stg40_ReadFloorBits(u16 *pal, u32 *bits, s32 x, s32 y);
u16 Stg40_GetCellFlags(s32 x, s32 y);
Stg40Cell *Stg40_GetCell(s32 x, s32 y);
void Stg40_FloodFillRoom(s32 buf, s32 p1, s32 x, s32 y, s32 fill);
s32 Stg40_FindUnlabeledRoom(void);
void Stg40_LabelFilledCells(void);
void Stg40_LabelRooms(void);
Stg40Cell *Stg40_GetCell2(s32 x, s32 y);
void Stg40_SetCellOccupied(s32 x, s32 y, s32 flag);
void Stg40_ClearCellOccupied(s32 x, s32 y);
void Stg40_ApplyTrapCells(void);
void Stg40_TurnQueueReset(void);
s16 *Stg40_TurnQueueFind(s16 v);
void Stg40_TurnQueueAdd(s32 v);
void Stg40_TurnQueueRemove(s16 v);
s16 Stg40_TurnQueueNext(void);
s16 Stg40_TurnQueueCurrent(void);
void Stg40_LoadDungFile(s32 id);
void Stg40_PickFloorLayout(void);
void Stg40_ApplyFloorLayout(void);
void Stg40_RelocPtr(u32 *p, u32 n);
s32 Stg40_RelocDungFile(s32 *p);
s32 Stg40_PickRandomPoint(Stg40Pick *out, Stg40Rec3 *e, u8 key);
void Stg40_PickSpawnPoints(void);
s32 Stg40_RandPercent(void);
s32 Stg40_RandInt(s32 n);
s32 Stg40_GetTrapDisarmRank(s32 i);
s32 Stg40_RollTrapDisarm(s32 i);
s32 Stg40_RollTrapEffect(void);
void Stg40_ShowTrapEffectMsg(s32 a0, s32 a1);
void Stg40_ApplyTrapEffect(s32 a0, s32 a1);
s32 Stg40_GetPartState(void);
s32 Stg40_PickRandomPart(void);
void Stg40_RollObjectReveal(void);
Stg40Ent48 *Stg40_FindEntByDigiId(s32 id);
void Stg40_TextObjCommand(s32 *arg);
void Stg40_EndTextObjCmd(void);
s16 Stg40_IsTextObjCmdBusy(void);
s32 Stg40_CamIsMoving(void);
void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);
void Stg40_CamLoadScript(Stg40Cmd *src);
void Stg40_CamNextCommand(Actor *a0);
void Stg40_CamMoveStep(Actor *task);
void Stg40_CameraInit(Actor *a0, Block1C *a1);
void Stg40_CameraUpdate(Actor *a0);
void Stg40_CameraDraw(void);

#endif /* STAG4000_C2CC_FUNCS_H */
