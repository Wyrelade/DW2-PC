#ifndef MAIN_MEM_H
#define MAIN_MEM_H

#include "main/game.h"

/* Functions src/main/mem.c defines. */
void Mem_Free(ActorWork *arg0);
void Mem_FreeTag(s32 tag);
void Mem_InitHeap(MemBlock *heap, s32 size);
s32 Mem_TryAlloc(s32 arg0, s32 tag);
s32 Mem_Alloc(s32 arg0, s32 arg1);
void Mem_Zero(void *a0, s32 a1);
void Mem_SumSizesByTag(s32 *tbl);
u32 Mem_GetLargestFree(void);

#endif /* MAIN_MEM_H */
