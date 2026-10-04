#ifndef STAG3000_9F8C_FUNCS_H
#define STAG3000_9F8C_FUNCS_H

/* Functions src/stag3000/stag3000_9F8C.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
s32 Stg30_CalcCannonDamage(s32 idx, s32 id, s32 lvl);
s32 Stg30_ApplyItemEffect(s32 target, s32 tech, s16 *p3, s16 *p4);
void Stg30_BuildItemScript(void);

#endif /* STAG3000_9F8C_FUNCS_H */
