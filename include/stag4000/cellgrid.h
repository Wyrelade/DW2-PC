#ifndef STAG4000_CELLGRID_H
#define STAG4000_CELLGRID_H

/* Functions src/stag4000/cellgrid.c defines. */
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

#endif /* STAG4000_CELLGRID_H */
