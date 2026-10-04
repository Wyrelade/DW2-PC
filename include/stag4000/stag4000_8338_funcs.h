#ifndef STAG4000_8338_FUNCS_H
#define STAG4000_8338_FUNCS_H

/* Functions src/stag4000/stag4000_8338.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
s32 Stg40_AiPathFlee(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathToTarget(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathChase(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathChaseInRoom(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiTryStep(Stg40Ent48 *e, s32 mode);

#endif /* STAG4000_8338_FUNCS_H */
