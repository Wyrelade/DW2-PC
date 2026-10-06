#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/F400.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/model.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"
#include "main/mem.h" /* RGB 0x80, 0x80, 0x80 */

s32 Cd_QueueActive = 0;
/* Unreferenced: the number of CD files (Cd_FileLba entries). */
s32 Cd_FileCount = 0xE5B;
/* Unreferenced: pads .sbss to the start of .bss. */
s32 D_80050794;
CdCacheEntry Cd_FileCache[0x50];
/* CD file table: start LBA and size in sectors per file id (disc layout). */
INCLUDE_BIN(Cd_FileLba, "assets/main/cd_file_lba.bin");
INCLUDE_BIN(Cd_FileSectors, "assets/main/cd_file_sectors.bin");

EntA0 *Cd_GetFileEntry(u32 arg0) {
    u32 index;
    u8 *base;
    if (arg0 == 0) {
        return 0;
    }
    index = arg0 & 0xFFFF;
    base = (u8 *)Cd_GetFileSync(arg0 >> 16);
    return (EntA0 *)(((u32 *)base)[index] + (u32)base);
}

s32 Mem_GetOffsetEntry(s32 arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg1[(u16)arg0] + (s32)arg1;
}

s32 Cd_GetFileOrNull(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return Cd_GetFileSync(arg0);
}

void Cd_ClearFileCache(void) {
    s32 i;
    CdCacheEntry *p = Cd_FileCache;
    for (i = 0; i < 0x50; i++, p++) {
        p->fileId = 0;
        p->data = 0;
        p->state = 0;
        p->locked = 0;
        p->lastUsed = 0;
    }
}

CdCacheEntry *Cd_FindCachedFile(arg0)
s32 arg0;
{
    s32 i;
    CdCacheEntry *p = Cd_FileCache;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == arg0) return p;
    }
    return NULL;
}

CdCacheEntry *Cd_FindFreeCacheSlot(void) {
    s32 i;
    CdCacheEntry *p = Cd_FileCache;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == 0) return p;
    }
    return NULL;
}

CdLruEntry *Cd_FindLruCachedFile(void) {
    s32 min = Sys_State.frameCount;
    CdCacheEntry *p = Cd_FileCache;
    CdCacheEntry *best = 0;
    s32 i;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == 0) continue;
        if (p->locked != 0) continue;
        if (p->state != 3) continue;
        if (min < p->lastUsed) continue;
        min = p->lastUsed;
        best = p;
    }
    return (CdLruEntry *)best;
}

s32 Cd_GetFileState(s32 arg0) {
    CdCacheEntry *e = Cd_FindCachedFile(arg0);

    if (e != 0) {
        e->lastUsed = Sys_State.frameCount;
        return e->state;
    }
    return 0;
}

void Cd_EvictLruFile(void) {
    CdLruEntry *p = Cd_FindLruCachedFile();
    Mem_Free(p->data);
    p->fileId = 0;
    p->data = 0;
    p->lastUsed = 0;
    p->state = 0;
    p->locked = 0;
}

void Cd_QueueFile(s32 id) {
    CdCacheEntry *p = Cd_FindCachedFile(id);

    if (p != NULL) {
        p->lastUsed = Sys_State.frameCount;
        return;
    }
    p = Cd_FindFreeCacheSlot();
    p->fileId = id;
    p->data = Mem_Alloc(Cd_GetFileSectors(id) << 11, 3);
    p->state = 1;
    p->lastUsed = 0;
    Cd_QueueActive = 1;
}

void Cd_ServiceQueue(void) {
    s32 started;
    s32 busy;
    s32 i;
    CdCacheEntry *p;

    if (Cd_QueueActive == 0) {
        return;
    }
    if (Cd_PollRead() != 0) {
        return;
    }
    p = Cd_FileCache;
    started = 0;
    busy = 0;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == 0) {
            continue;
        }
        if (p->state != 1) {
            if (p->state == 2) {
                p->state = 3;
                p->lastUsed = Sys_State.frameCount;
                busy = 1;
            }
        } else {
            busy = 1;
            if (started == 0) {
                Cd_ReadFileAsync(p->fileId, p->data);
                p->state = 2;
                p->lastUsed = Sys_State.frameCount;
                started = busy;
            }
        }
    }
    if (busy == 0) {
        Cd_QueueActive = 0;
    }
}

void Cd_LoadFileSync(s32 arg0) {
    Cd_QueueFile(arg0);
    do {
        Cd_ServiceQueue();
    } while (Cd_GetFileState(arg0) != 3);
}

s32 Cd_GetFileSync(s32 arg0) {
    CdCacheEntry *p = Cd_FindCachedFile(arg0);
    if (p != 0 && p->state == 3) {
        p->lastUsed = Sys_State.frameCount;
    } else {
        while (Cd_PollRead() != 0) {
        }
        Cd_LoadFileSync(arg0);
    }
    return Cd_FindCachedFile(arg0)->data;
}

void Cd_FreeFile(s32 fileId) {
    CdCacheEntry *p = Cd_FindCachedFile(fileId);
    if (p != 0) {
        if (p->state == 3) {
            Mem_Free(p->data);
            p->fileId = 0;
            p->data = 0;
            p->lastUsed = 0;
            p->state = 0;
        }
    }
}

void Cd_LockFile(s32 a0) {
    CdCacheEntry *p = Cd_FindCachedFile();
    if (p != 0) {
        if (p->state == 3) {
            p->locked = 1;
        }
    }
}

void Cd_UnlockFile(s32 a0) {
    CdCacheEntry *p = Cd_FindCachedFile();
    if (p != 0) {
        if (p->state == 3) {
            p->locked = 0;
        }
    }
}

void Cd_FreeUnlockedFiles(void) {
    s32 i;
    for (i = 0; i < 0x50; i++) {
        if (Cd_FileCache[i].fileId != 0 && Cd_FileCache[i].locked == 0) {
            Mem_Free(Cd_FileCache[i].data);
            Cd_FileCache[i].fileId = 0;
            Cd_FileCache[i].data = 0;
            Cd_FileCache[i].lastUsed = 0;
            Cd_FileCache[i].state = 0;
        }
    }
}

s32 Cd_IsFileValid(s32 arg0) {
    return Cd_FileLba[arg0] != 0;
}

s32 Cd_GetFileSectors(s32 arg0) {
    return Cd_FileSectors[arg0];
}

s32 Cd_GetFileLba(s32 arg0) {
    return Cd_FileLba[arg0];
}

void Cd_GetFilePos(s32 arg0, void *arg1) {
    CdIntToPos(Cd_FileLba[arg0]);
}
