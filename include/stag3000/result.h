#ifndef STAG3000_RESULT_H
#define STAG3000_RESULT_H

/* Functions src/stag3000/result.c defines. */
void Stg30_ResultInit(Actor *a0, Stg30Pair *args);
u8 *Stg30_NumToDigits(u8 *out, s32 n);
void Stg30_LevelUpStats(DigiRosterEntry *e);
void Stg30_ResultUpdate(Actor *a0);
void Stg30_ResultDestroy(Actor *a0);
void Stg30_ResultDraw(Actor *a0);

#endif /* STAG3000_RESULT_H */
