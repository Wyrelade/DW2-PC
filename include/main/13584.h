#ifndef MAIN_13584_H
#define MAIN_13584_H

#include "main/game.h"

/* Functions src/main/13584.c defines or declares, for the units after it. */
void Mem_Free(ActorWork *arg0);
void Mem_FreeTag(s32 tag);
void Mem_InitHeap(MemBlock *heap, s32 size);
s32 Mem_TryAlloc(s32 arg0, s32 tag);
s32 Mem_Alloc(s32 arg0, s32 arg1);
void Mem_Zero(void *a0, s32 a1);
void Mem_SumSizesByTag(s32 *tbl);
u32 Mem_GetLargestFree(void);
void Pad_Init(void);
void Pad_ResetButtons(PadButtons *arg0);
void Pad_UpdateButtons(PadButtons *p, u8 *buf);
void Pad_PollPort(PadBuf *a0, s32 i);
s32 Pad_GetButtonState(s32 arg0, s32 arg1, s32 arg2);
void Pad_Update(void);
void Sys_VSyncHandler(void);
void Sys_Main(void);
void Rand_Seed(s32 a0);
void Rand_Step(void);
s32 Rand_Next(void);
u16 Rand_GetAt(u32 arg0);
void Sys_SetFrameRate60(void);
void Sys_SetFrameRate30(void);
void Sys_SetFrameRate20(void);
void Sys_SetFrameRate15(void);
EntA0 *Cd_GetFileEntry(u32 arg0);
s32 Mem_GetOffsetEntry(s32 arg0, s32 *arg1);
s32 Cd_GetFileOrNull(s32 arg0);
void Cd_ClearFileCache(void);
CdCacheEntry *Cd_FindCachedFile();
CdCacheEntry *Cd_FindFreeCacheSlot(void);
CdLruEntry *Cd_FindLruCachedFile(void);
s32 Cd_GetFileState(s32 arg0);
void Cd_EvictLruFile(void);
void Cd_QueueFile(s32 id);
void Cd_ServiceQueue(void);
void Cd_LoadFileSync(s32 arg0);
s32 Cd_GetFileSync(s32 arg0);
void Cd_FreeFile(void);
void Cd_LockFile(s32 a0);
void Cd_UnlockFile(s32 a0);
void Cd_FreeUnlockedFiles(void);
s32 Cd_IsFileValid(s32 arg0);
s32 Cd_GetFileSectors(s32 arg0);
s32 Cd_GetFileLba(s32 arg0);
void Cd_GetFilePos(s32 arg0, void *arg1);
s32 Cd_CheckNextSector(void);
void Cd_ReadSectorCallback(s32 a0);
void Cd_ReadSyncCallback(s32 ev);
s32 Cd_PollRead(void);
void Cd_ReadFileAsync(s32 arg0, s32 arg1);
void func_80024310(Actor *arg0, Block1C *arg1);
void func_80024350(Actor *arg0);
void func_80024410(Actor *arg0);

#endif /* MAIN_13584_H */
