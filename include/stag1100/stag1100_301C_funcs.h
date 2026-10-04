#ifndef STAG1100_301C_FUNCS_H
#define STAG1100_301C_FUNCS_H

/* Functions src/stag1100/stag1100_301C.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg11_CardMenuDraw(Actor *arg0);
void Stg11_VsPartyBuildList(Stg11Work66C04 *arg0);
void Stg11_VsPartyOpenRowText(Stg11Work66C04 *arg0, u8 arg1);
void Stg11_VsPartyPick(Actor *arg0);
void Stg11_VsPartyUnpick(Actor *arg0);
void Stg11_VsPartyInit(Actor *arg0, s16 arg1);
void Stg11_VsPartyUpdate(Actor *arg0);
void Stg11_VsPartyDraw(Actor *arg0);
void Stg11_CardInitHeader(void);
u8 *Stg11_CardGetDataBuf(void);
u8 *Stg11_CardGetTransferBuf(void);
void Stg11_CardSetTitle(u8 *arg0);
void Stg11_CardStartOp(u8 arg0, s32 arg1);
s32 Stg11_CardGetResult(void);
void Stg11_CardSetFileName(u8 *arg0, u8 arg1);
s32 Stg11_CardGetProgress(s32 arg0);
s32 Stg11_CardChecksum(Stg11SaveWork *arg0);
s32 Stg11_CardFileOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
s32 Stg11_CardAsyncOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
void Stg11_CardRunOp(Actor *arg0, s32 arg1);
void Stg11_CardTaskInit(void);
void Stg11_CardTaskUpdate(Actor *arg0);
void Stg11_CardTaskDestroy(Actor *arg0);
void Stg11_CardTaskDraw(void);

#endif /* STAG1100_301C_FUNCS_H */
