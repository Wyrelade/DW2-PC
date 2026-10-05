#ifndef MAIN_TEXT_H
#define MAIN_TEXT_H

#include "main/game.h"

/* Functions src/main/text.c defines. */
void Text_PushReturn(s32 arg0);
s32 Text_PopReturn(void);
void Text_LoadFontsTask(Actor *a0);
void Text_UpdateAllBoxes(Actor *a0);
void Text_Close(s32 *slot);
void Text_Open(void *arg0, TextOpenArgs *arg1);
s32 Text_IsFinished(s32 id);
void Text_SetColor(s32 a0, s32 a1);
void Text_SetInputPad(s32 a0, s32 a1);
void Text_SetOtLayer(s32 a0, s32 a1);
void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3);
void Text_OpenMsgClearChoice(void *arg0, s32 arg1);
void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
void Text_CloseArray(s32 *arg0, s32 arg1);

#endif /* MAIN_TEXT_H */
