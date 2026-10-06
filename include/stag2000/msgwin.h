#ifndef STAG2000_MSGWIN_H
#define STAG2000_MSGWIN_H

/* Functions src/stag2000/msgwin.c defines. */
void Stg20_MsgWinInit(Actor *a, s32 v);
void Stg20_MsgWinUpdate(Actor *a);
void Stg20_MsgWinDestroy(Actor *a);
void Stg20_MsgWinDraw(Actor *a);
void Stg20_MsgWinClear(void);
void Stg20_MsgWinShowSkillDesc(s32 id);
void Stg20_MsgWinShowSysMsg(s32 id);
void Stg20_MsgWinShowDigiMsg(s32 text, s32 digi);
s32 Stg20_MsgWinGetChoice(void);

#endif /* STAG2000_MSGWIN_H */
