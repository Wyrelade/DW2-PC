#ifndef STAG0000_FUNCS_H
#define STAG0000_FUNCS_H

/* Functions src/stag0000/stag0000.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg00_StageSetup(Actor *arg0);
void Stg00_ScrollViewTask(Actor *arg0);
void Stg00_InitTileSprt(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3);
void Stg00_ScrollViewDraw(Actor *arg0);
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

#endif /* STAG0000_FUNCS_H */
