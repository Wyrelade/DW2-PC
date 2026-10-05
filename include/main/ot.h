#ifndef MAIN_OT_H
#define MAIN_OT_H

#include "main/game.h"

/* Functions src/main/ot.c defines. */
void Gpu_SetLayerOtPtrs(void);
void Gpu_SetOtLayout(s32 arg0);
void Gpu_ClearOt(s32 arg0);
s32 Gpu_DrawOt(s32 arg0);
void Gpu_SkipEmptyOtEntries(s32 arg0);

#endif /* MAIN_OT_H */
