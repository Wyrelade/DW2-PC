#ifndef MAIN_NAMEENTRY_H
#define MAIN_NAMEENTRY_H

#include "main/game.h"

/* Functions src/main/nameentry.c defines. */
extern u8 Menu_NameEntryGetChar(Actor *);
extern void Snd_SaveCurrentId(void);
extern void Snd_RestoreSavedId(void);
extern s32 Snd_AnySlotLoading(void);
u8 Menu_NameEntryGetChar(Actor *a0);
void Menu_NameEntryInit(Actor *a, MenuNameEntryArg *v);
void Menu_NameEntryTask(Actor *a0);
void Menu_NameEntryDrawParts(Actor *a);

#endif /* MAIN_NAMEENTRY_H */
