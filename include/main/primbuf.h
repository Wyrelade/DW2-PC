#ifndef MAIN_PRIMBUF_H
#define MAIN_PRIMBUF_H

#include "main/game.h"

/* Functions src/main/primbuf.c defines. */
s32 func_8001C92C(void);
void Gpu_FreePrimBufs(void);
void Gpu_ResetPrimBuf(void);
void Gpu_AllocPacketBufs(s32 a0);

#endif /* MAIN_PRIMBUF_H */
