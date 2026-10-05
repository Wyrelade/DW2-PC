#ifndef STAG1100_CARD_H
#define STAG1100_CARD_H

/* Functions src/stag1100/card.c defines. */
void Stg11_CardInitHeader(void);
u8 *Stg11_CardGetDataBuf(void);
u8 *Stg11_CardGetTransferBuf(void);
void Stg11_CardSetTitle(const u8 *arg0);
void Stg11_CardStartOp(u8 arg0, s32 arg1);
s32 Stg11_CardGetResult(void);
void Stg11_CardSetFileName(const u8 *arg0, u8 arg1);
s32 Stg11_CardGetProgress(s32 arg0);
s32 Stg11_CardChecksum(Stg11SaveWork *arg0);
s32 Stg11_CardFileOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
s32 Stg11_CardAsyncOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
void Stg11_CardRunOp(Actor *arg0, s32 arg1);
void Stg11_CardTaskInit(void);
void Stg11_CardTaskUpdate(Actor *arg0);
void Stg11_CardTaskDestroy(Actor *arg0);
void Stg11_CardTaskDraw(void);

#endif /* STAG1100_CARD_H */
