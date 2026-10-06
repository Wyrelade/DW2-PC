#ifndef STAG4000_DUNGFILE_H
#define STAG4000_DUNGFILE_H

/* Functions src/stag4000/dungfile.c defines. */
void Stg40_LoadDungFile(s32 id);
void Stg40_PickFloorLayout(void);
void Stg40_ApplyFloorLayout(void);
void Stg40_RelocPtr(u32 *p, u32 n);
s32 Stg40_RelocDungFile(s32 *p);
s32 Stg40_PickRandomPoint(Stg40CellPos *out, Stg40CellPoint *e, u8 key);
void Stg40_PickSpawnPoints(void);
s32 Stg40_RandPercent(void);
s32 Stg40_RandInt(s32 n);

#endif /* STAG4000_DUNGFILE_H */
