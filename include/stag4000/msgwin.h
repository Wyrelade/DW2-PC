#ifndef STAG4000_MSGWIN_H
#define STAG4000_MSGWIN_H

/* Functions src/stag4000/msgwin.c defines. */
u8 *Stg40_NumToDigits(s32 i, s32 v);
void Stg40_MsgWinOpen(s32 i, s32 file, s32 a2, s32 a3);
void Stg40_MsgWinClose(s32 i);
s32 Stg40_MsgWinIsFinished(s32 i);
s32 Stg40_MsgWinCloseIfDone(s32 i);
s32 Stg40_MsgWinGetChoice(s32 i);
void Stg40_MsgWinInit(void);
void Stg40_MsgWinUpdate(Actor *a0);
void Stg40_MsgWinDraw(void);

#endif /* STAG4000_MSGWIN_H */
