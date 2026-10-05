#ifndef MAIN_GPU_H
#define MAIN_GPU_H

#include "main/game.h"

/* Functions src/main/gpu.c defines. */
void Gpu_ClearScreens(void);
void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
void Gpu_DisableBgClear(void);
void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);

#endif /* MAIN_GPU_H */
