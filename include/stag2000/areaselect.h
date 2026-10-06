#ifndef STAG2000_AREASELECT_H
#define STAG2000_AREASELECT_H

/* Functions src/stag2000/areaselect.c defines. */
s32 Stg20_TestSpecialFlag(s32 id);
void Stg20_SetSpecialFlag(s32 id, s32 on);
s32 Stg20_IsOnCellCenter(Actor *a);
s32 Stg20_AreaSelectFindDir(Actor *a, s32 dir);
void Stg20_AreaSelectUpdate(Actor *a);
void Stg20_AreaSelectDraw(Actor *a);
void Stg20_ApplyStartPreset(s32 arg0);
s32 Stg20_OwnsDigi(s32 id);
void Stg20_AddBits(s32 d);
void Stg20_RemoveOwnedDigi(s32 id);
void Stg20_OpenText(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color);
Stg20Cell *Stg20_GetActorCell(Actor *a);
void Stg20_SnapToCell(Actor *a, s32 doX, s32 doZ);
void Stg20_SetMoveParams(Actor *a, s32 i);
Stg20Cell *Stg20_GetCellInDir(Actor *a, s32 dir);
s32 Stg20_IsCellBlocked(Actor *a, s32 dir);
void Stg20_AddOccupantMark(Actor *a, Stg20Marks *m, s32 dir, s32 timer);
void Stg20_TickOccupantMarks(Actor *a, Stg20Marks *m);
s32 Stg20_CellDistWeighted(Stg20Cell *c, s32 x, s32 y, s32 flag);
void Stg20_AreaSelectShowName(Actor *a, s32 open);

#endif /* STAG2000_AREASELECT_H */
