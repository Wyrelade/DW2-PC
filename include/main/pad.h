#ifndef MAIN_PAD_H
#define MAIN_PAD_H

#include "main/game.h"

/* Functions src/main/pad.c defines. */
void Pad_Init(void);
void Pad_ResetButtons(PadButtons *arg0);
void Pad_UpdateButtons(PadButtons *p, u8 *buf);
void Pad_PollPort(PadBuf *a0, s32 i);
s32 Pad_GetButtonState(s32 arg0, s32 arg1, s32 arg2);
void Pad_Update(void);

#endif /* MAIN_PAD_H */
