#ifndef MAIN_307C_H
#define MAIN_307C_H

#include "main/game.h"

/* Functions src/main/307C.c defines or declares, for the units after it. */
extern u8 Menu_NameEntryGetChar(Actor *);
extern void Snd_SaveCurrentId(void);
extern void Snd_RestoreSavedId(void);
extern void Ovl_Load(s32);
extern s32 Snd_AnySlotLoading(void);
u8 Menu_NameEntryGetChar(Actor *a0);
void func_8001291C(Actor *a, Pair1291C *v);
void Menu_NameEntryTask(Actor *a0);
void Menu_NameEntryDrawParts(Actor *a);
void Ovl_Load(s32 id);
s32 Ovl_GetCurrentId(void);
void Sys_GameModeTask(Actor *a0);
void Task_DefaultDestroy2(void);
void Text_OpenDesc(void *arg0, TextDesc *arg1);
void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3);
s32 Text_PrintIdList(s32 *a0, TextIdListEntry *a1, u32 a2);
void Text_PrintList(s32 *a0, Halves *a1, s32 *a2, u32 a3);
s32 func_800136A4();
s32 Math_RampToOne(s32 arg0, s32 *arg1);
s32 Math_RampToZero(s32 arg0, s32 *arg1);
void Menu_SetPartsGridPos(void *arg0, s32 mask, s32 *arg2, s16 *arg3);
void Gfx_SetPartsPalette(GfxPart *p, s32 mask, s32 v);
void Menu_SetPartsPos(GfxPart *p, s32 mask, u16 *xy);
s32 Menu_BlinkOrHideParts(GfxPart *p, s32 mask, s32 n);
s32 Menu_MoveGridCursor(s32 a0, s32 a1, s32 a2);
s32 Menu_MoveGridCursorP1(s32 arg0, s32 arg1);
s32 Menu_ScrollToShow(s32 *arg0, s32 arg1, s32 arg2);
s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1);
s32 Menu_GridIndexRowMajor(s16 *arg0, s16 *arg1);
s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1);
void Text_FormatNumber(u8 *out, s32 val, s32 width);
void func_80013BF8(Actor *arg0, s16 arg1);
void Menu_TopMenuTask(Actor *a0);
void Menu_TopMenuDraw(Actor *actor);

#endif /* MAIN_307C_H */
