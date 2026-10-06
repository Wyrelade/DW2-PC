#ifndef STAG2000_WALKER_H
#define STAG2000_WALKER_H

/* Functions src/stag2000/walker.c defines. */
Actor *Stg20_FindWalkerByDigiId(s32 id);
void Stg20_WalkerWarpToCell(Actor *a, Stg20Pos2 *pos);
s32 Stg20_WalkerIsPathDone(Actor *a);
void Stg20_WalkerSetAnim(Actor *a, s32 anim);
void Stg20_WalkerInit(Actor *a, Stg20Spawn *s);
void Stg20_WalkerGetInput(Actor *a);
s32 Stg20_InputToDir(Actor *a);
void Stg20_WalkerFaceDir(Actor *a, s32 i);
void Stg20_WalkerHalt(Actor *a);
void Stg20_WalkerUpdate(Actor *a);
void Stg20_WalkerDraw(Actor *a);

#endif /* STAG2000_WALKER_H */
