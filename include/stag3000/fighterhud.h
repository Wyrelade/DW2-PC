#ifndef STAG3000_FIGHTERHUD_H
#define STAG3000_FIGHTERHUD_H

/* Functions src/stag3000/fighterhud.c defines. */
void Stg30_SetGaugeParts(Stg30Part *p, s32 unit, s32 num, s32 den);
void Stg30_FighterHudInit(Actor *a0, Stg30Ref **args);
void Stg30_FighterHudUpdate(Stg30TaskHead *a0);
void Stg30_FighterHudDestroy(Actor *a0);
void Stg30_FighterHudDraw(Actor *a0);

#endif /* STAG3000_FIGHTERHUD_H */
