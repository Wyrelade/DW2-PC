#ifndef STAG4000_AUTOMAP_H
#define STAG4000_AUTOMAP_H

/* Functions src/stag4000/automap.c defines. */
void Stg40_RevealRoom(Stg40AutomapWork *w, s32 x, s32 y);
void Stg40_AutomapSetCell(s32 idx, s32 row, s32 val);
void Stg40_AutomapMoveMarker(s32 x, s32 y, s32 ox, s32 oy, s32 dir);
void Stg40_AutomapRedraw(Stg40AutomapWork *a0);
void Stg40_ClearVisitedBits(void);
void Stg40_SyncVisitedBits(s32 arg0);
void Stg40_ResetVisitedCells(void);
void Stg40_AutomapRevealAll(void);
void Stg40_AutomapLoadClut(Stg40ImgWork *a0);
void Stg40_AutomapFlush(Stg40AutomapWork *a0);
void Stg40_AutomapCycleClut(Stg40ImgWork *a0);
void Stg40_AutomapInitTex(Stg40AutomapWork *w);
void Stg40_AutomapReleaseTex(Stg40ImgWork *a0);
s16 Stg40_AutomapInitDims(Stg40AutomapWork *a0);
void Stg40_RevealCell(Stg40AutomapWork *a0, s32 x, s32 y);
void Stg40_AutomapRevealAround(Stg40AutomapWork *w);
void Stg40_AutomapDrawModes(ActorWork *w);
void Stg40_AutomapInit(void);
void Stg40_AutomapUpdate(Actor *a0);
void Stg40_AutomapDestroy(Actor *a0);
void Stg40_AutomapDraw(Actor *a0);

#endif /* STAG4000_AUTOMAP_H */
