#ifndef MAIN_SOUND_H
#define MAIN_SOUND_H

#include "main/game.h"

/* Functions src/main/sound.c defines. */
extern void Snd_SetSlotContent(s32, s32);
void Snd_ServiceSlotLoads(void);
s32 Snd_AnySlotLoading(void);
void Snd_StopAll(void);
void Snd_StopById(s32 id);
void Snd_UnloadSlot(s32 idx);
void Snd_SetSlotContent(s32 idx, s32 v);
void Snd_PlayById(s32 id, s32 set);
void Snd_Init(void);
void Snd_SaveCurrentId(void);
void Snd_RestoreSavedId(void);

#endif /* MAIN_SOUND_H */
