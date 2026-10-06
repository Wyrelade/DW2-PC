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
#include "main/105BC.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"

/* Small data. Retail reaches Mem_HeapSize and Mem_HeapHead with %gp_rel, so they are defined
 * here; Digi_StateSortRank is the first .sdata word of the old 13584 unit (12654 reads it with
 * %hi/%lo). */
DigiSortRank Digi_StateSortRank[1] = { { 0, 5, 4, 1, 2, 3 } };
s32 Mem_HeapSize;
MemBlock *Mem_HeapHead;

void Mem_Free(ActorWork *arg0) {
    MemFreeBlock *n = (MemFreeBlock *)((u8 *)arg0 - 0xC);
    MemFreeBlock *m = n->prev;
    MemFreeBlock *nx = n->next;
    n->tag = 0;
    if (nx->tag == 0) {
        n->next = nx->next;
        nx->next->prev = n;
    }
    if (m->tag == 0) {
        m->next = n->next;
        n->next->prev = m;
    }
}

void Mem_FreeTag(s32 tag) {
    MemBlock *b = Mem_HeapHead;

    if (b->tag != 1) {
        do {
            if (b->tag == tag) {
                Mem_Free((ActorWork *)(b + 1));
            }
            b = b->next;
        } while (b->tag != 1);
    }
}

void Mem_InitHeap(MemBlock *heap, s32 size) {
    MemBlock *end;

    Mem_HeapSize = size;
    Mem_HeapHead = heap;
    end = (MemBlock *)((u8 *)heap + size) - 1;
    heap->prev = NULL;
    heap->next = end;
    heap->tag = 0;
    end->prev = heap;
    end->next = NULL;
    end->tag = 1;
}

s32 Mem_TryAlloc(s32 arg0, s32 tag) {
    u32 size = ((u32)(arg0 + 3) >> 2) << 2;
    MemBlock *b = Mem_HeapHead;
    MemBlock *n;
    u32 avail;
    u32 lim = size + 0x14;

    if (b->tag != 1) {
        do {
            if (b->tag == 0) {
                avail = (s32)b->next - (s32)b - 0xC;
                if (avail >= size) {
                    if (lim < avail) {
                        n = (MemBlock *)((u8 *)b + size + 0xC);
                        n->prev = b;
                        n->next = b->next;
                        n->tag = 0;
                        b->next->prev = n;
                        b->next = n;
                    }
                    b->tag = tag;
                    return (s32)(b + 1);
                }
            }
            b = b->next;
        } while (b->tag != 1);
    }
    return 0;
}

s32 Mem_Alloc(s32 arg0, s32 arg1) {
    s32 r;
    while ((r = Mem_TryAlloc(arg0, arg1)) == 0) {
        Cd_EvictLruFile();
    }
    return r;
}

void Mem_Zero(void *a0, s32 a1) {
    s32 i;
    if (a1 & 3) {
        u8 *b = (u8 *)a0;
        for (i = 0; i < a1; i++) b[i] = 0;
    } else {
        s32 *w = (s32 *)a0;
        a1 >>= 2;
        for (i = 0; i < a1; i++) *w++ = 0;
    }
}

void Mem_SumSizesByTag(s32 *tbl) {
    MemBlock *b = Mem_HeapHead;

    if (b->tag != 1) {
        do {
            tbl[b->tag] += (s32)b->next - (s32)b;
            b = b->next;
        } while (b->tag != 1);
    }
}

u32 Mem_GetLargestFree(void) {
    MemBlock *b = Mem_HeapHead;
    u32 best = 0;
    u32 sz;

    while (b->tag != 1) {
        if (b->tag == 0) {
            sz = (s32)b->next - (s32)b;
            if (best < sz) {
                best = sz;
            }
        }
        b = b->next;
    }
    return best;
}
