#ifndef MAIN_CD_H
#define MAIN_CD_H

#include "main/game.h"

/* Functions src/main/cd.c defines. */
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
void Cd_FreeFile(s32);
void Cd_LockFile(s32 a0);
void Cd_UnlockFile(s32 a0);
void Cd_FreeUnlockedFiles(void);
s32 Cd_IsFileValid(s32 arg0);
s32 Cd_GetFileSectors(s32 arg0);
s32 Cd_GetFileLba(s32 arg0);
void Cd_GetFilePos(s32 arg0, void *arg1);

#endif /* MAIN_CD_H */
