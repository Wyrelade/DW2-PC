#ifndef STAG2000_MAPBG_H
#define STAG2000_MAPBG_H

/* Functions src/stag2000/mapbg.c defines. */
void Stg20_BuildMapGrid(Actor *a);
s32 Stg20_GetGridCell(Stg20Cell *c);
void Stg20_MarkGridOccupant(Stg20Cell *c, s32 set, s32 flag);
void Stg20_MapBgInit(Actor *a, s32 v);
void Stg20_MapBgUpdate(Actor *a);
void Stg20_StartBgShake(void);
void Stg20_MapBgDraw(Actor *a);

#endif /* STAG2000_MAPBG_H */
