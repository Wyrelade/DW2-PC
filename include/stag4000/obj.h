#ifndef STAG4000_OBJ_H
#define STAG4000_OBJ_H

/* Functions src/stag4000/obj.c defines. */
void Stg40_SetLights(Blk16 *l, s32 r, s32 g, s32 b);
void Stg40_ObjStartFlash(Actor *a0, u8 a1);
void Stg40_SetModelTint(Actor *a0, u8 on, u8 r, u8 g, u8 b);
s32 Stg40_ObjAnimDone(Actor *a0);
s32 Stg40_ObjStepMove(Stg40Ent48 *e);
void Stg40_ObjInit(Actor *a0, Stg40Ent48 *e);
void Stg40_ObjUpdate(Actor *a0);
void Stg40_ObjDraw(Actor *a0);

#endif /* STAG4000_OBJ_H */
