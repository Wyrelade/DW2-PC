#ifndef STAG4000_ENEMY_H
#define STAG4000_ENEMY_H

/* Functions src/stag4000/enemy.c defines. */
s32 Stg40_AiPathFlee(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathToTarget(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathChase(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiPathChaseInRoom(Stg40Ent48 *e, Pair54 *out);
s32 Stg40_AiTryStep(Stg40Ent48 *e, s32 mode);

#endif /* STAG4000_ENEMY_H */
