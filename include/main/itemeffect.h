#ifndef MAIN_ITEMEFFECT_H
#define MAIN_ITEMEFFECT_H

#include "main/game.h"

/* Functions src/main/itemeffect.c defines. */
void Bug_CompactMemBugs(void);
s32 *Item_GetEffectRec(s32 id);
s32 Item_GetUseKind(s32 arg0);
s32 Item_UseOnBeetle(s32 a0, s32 a1, s32 a2, s32 a3);
s32 Item_ApplyToDigi(s32 a0, s32 a1, s32 a2, s32 a3);
s32 Item_UseStatBoost(s32 a0, s32 a1, s32 a2, s32 a3);
s32 Item_UseRecoverAll(s32 a0, s32 a1);
s32 Item_Use(s32 a0, s32 a1, s32 a2, s32 a3);

#endif /* MAIN_ITEMEFFECT_H */
