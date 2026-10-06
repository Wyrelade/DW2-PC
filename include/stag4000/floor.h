#ifndef STAG4000_FLOOR_H
#define STAG4000_FLOOR_H

/* Functions src/stag4000/floor.c defines. */
void Stg40_ScrollFollow(Stg40Loc *loc);
void Stg40_ScrollTo(s32 a0, s32 a1, s32 a2);
void Stg40_ScrollToFollow(Stg40Loc *loc, s32 a1);
s32 Stg40_IsScrollDone(void);
void Stg40_ScrollStep(Actor *a0);
void Stg40_ScrollUpdate(Actor *a0);
s32 Stg40_Max4(s32 a, s32 b, s32 c, s32 d);
s32 Stg40_Min4(s32 a, s32 b, s32 c, s32 d);
void Stg40_FillTileCache(ActorWork *arg0);
void Stg40_MapPosToWorld(s32 x, s32 z, s32 y, Stg40Vec3 *out);
s32 Stg40_DrawTileWalls(Stg40FloorWork *w, s32 pkt, s32 x, s32 y);
s32 Stg40_DrawTileTop(Stg40FloorWork *w, s32 pkt, s32 x, s32 y);
void Stg40_DrawFloorTiles(Stg40FloorWork *w);
void Stg40_FloorInit(Actor *a0, s32 *ids);
void Stg40_FloorUpdate(Actor *a0);
void Stg40_FloorDraw(Actor *a0);

#endif /* STAG4000_FLOOR_H */
