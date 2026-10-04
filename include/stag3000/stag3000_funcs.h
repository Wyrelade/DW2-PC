#ifndef STAG3000_FUNCS_H
#define STAG3000_FUNCS_H

/* Functions src/stag3000/stag3000.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg30_BannerInit(Actor *a0, s32 a1);
void Stg30_BannerUpdate(Actor *a0);
void Stg30_BannerDraw(Actor *a0);
void Stg30_FightBgUpdate(Actor *a0);
void Stg30_FightBgDraw(Actor *a0);
void Stg30_ActionLoadInit(Actor *a0, s32 *args);
void Stg30_ActionLoadAddSorted(Actor *a0, s32 file, s32 lba);
void Stg30_ActionLoadUpdate(Actor *a0);

#endif /* STAG3000_FUNCS_H */
