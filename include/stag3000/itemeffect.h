#ifndef STAG3000_ITEMEFFECT_H
#define STAG3000_ITEMEFFECT_H

/* Functions src/stag3000/itemeffect.c defines. */
s32 Stg30_CalcCannonDamage(s32 idx, s32 id, s32 lvl);
s32 Stg30_ApplyItemEffect(s32 target, s32 tech, s16 *p3, s16 *p4);
void Stg30_BuildItemScript(void);

#endif /* STAG3000_ITEMEFFECT_H */
