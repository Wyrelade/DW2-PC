#ifndef STAG0000_DUNGSEL_H
#define STAG0000_DUNGSEL_H

/* Functions src/stag0000/dungsel.c defines. */
void Stg00_RelocPtr(u32 *arg0, u32 arg1);
s32 Stg00_RelocDungFile(u32 *arg0);
void Stg00_LoadDungFile(Actor *arg0, Stg00SelWork *arg1, s32 arg2);
void Stg00_DungSelPickDungeon(Actor *arg0, Stg00SelWork *arg1);
void Stg00_DungSelPickFloor(Actor *arg0, Stg00SelWork *arg1_);
void Stg00_DungSelPickFlag(Actor *arg0, Stg00SelWork *arg1);
void Stg00_DungSelInit(void);
void Stg00_DungSelTask(Actor *arg0);
void Stg00_DungSelDraw(void);
void Stg00_DungSelDestroy(Actor *arg0);

#endif /* STAG0000_DUNGSEL_H */
