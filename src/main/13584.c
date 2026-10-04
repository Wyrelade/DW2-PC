#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/4BCC.h"
#include "main/6530.h"
#include "main/77DC.h"
#include "main/E280.h"
#include "main/105BC.h"
#include "main/12550.h"
#include "main/12654.h"

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches the ones this unit uses with %gp_rel. The others sit here
 * in retail order (12654 reads Digi_StateSortRank, 105BC Gfx_ZeroSVector, 187C/77DC
 * Gfx_NeutralRgb, STAG1000 D_80050741). */
DigiSortRank Digi_StateSortRank[1] = { { 0, 5, 4, 1, 2, 3 } };
s32 Sys_VSyncsSinceFlip = 0;
RECT Sys_BootImageRect = { 0, 0, 320, 480 };
s32 Sys_LastVSyncTime = 0;
/* Unreferenced. */
s32 D_8005073C = 0x10000;
u8 D_80050740 = 0;
u8 D_80050741 = 0;
s16 D_80050742 = 0;
GfxQuadVert Gfx_ZeroSVector[1] = { 0 };
Halves Gfx_NeutralRgb = { 0x8080, 0x80 }; /* RGB 0x80, 0x80, 0x80 */
s32 Cd_QueueActive = 0;
/* Unreferenced: the number of CD files (Cd_FileLba entries). */
s32 D_80050754 = 0xE5B;
s32 Mem_HeapSize;
MemBlock *Mem_HeapHead;
s32 Sys_FlipPending;
s32 Rand_Index;
/* Unreferenced: pads .sbss to the start of .bss. */
s32 D_80050794;

/* Rand_Next's table of 0x1000 random halfwords. */
INCLUDE_BIN(Rand_Table, "assets/main/rand_table.bin");
/* Gfx_ZeroVector and the matrices sit in this unit's data in retail order (E280 and 105BC
 * use them). */
s32 Gfx_ZeroVector[4] = { 0 };
Blk20 Gfx_IdentityMatrix = { { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
/* Unreferenced: the same with x, y, then x and y scaled by 2. */
Blk20 D_80043734 = { { { { 0x2000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
Blk20 D_80043754 = { { { { 0x1000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
Blk20 D_80043774 = { { { { 0x2000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
/* CD file table: start LBA and size in sectors per file id (disc layout). */
INCLUDE_BIN(Cd_FileLba, "assets/main/cd_file_lba.bin");
INCLUDE_BIN(Cd_FileSectors, "assets/main/cd_file_sectors.bin");

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


void Pad_Init(void) {
    PadInitDirect(Pad_RecvBufs, Pad_RecvBufs + 0x22);
    PadStartCom();
}

void Pad_ResetButtons(PadButtons *arg0) {
    arg0->connected = 0;
    arg0->repeatTimer = 0;
    arg0->repeating = 0;
    arg0->repeat = 0;
    arg0->prevHeld = 0;
    arg0->held = 0;
    arg0->prevHeld = 0;
}

void Pad_UpdateButtons(PadButtons *p, u8 *buf) {
    s32 n;

    p->prevHeld = p->held;
    p->held = ((buf[2] << 8) + buf[3]) ^ 0xFFFF;
    p->pressed = (p->prevHeld ^ p->held) & p->held;
    if (p->prevHeld != p->held) {
        p->repeat = p->pressed;
        p->repeating = 0;
        p->repeatTimer = 0;
        return;
    }
    n = ++p->repeatTimer;
    if (p->repeating == 0) {
        if (n >= 11) {
            goto rep;
        }
    } else if (n >= 4) {
    rep:
        p->repeating = 1;
        p->repeatTimer = 0;
        p->repeat = p->held;
        return;
    }
    p->repeat = 0;
}

void Pad_PollPort(PadBuf *a0, s32 i) {
    switch (PadGetState(i << 4)) {
    case 2:
    case 6:
        switch (Pad_PortButtons[i].initialized) {
        case 0:
        default:
            Pad_ResetButtons((PadButtons *)&Pad_PortButtons[i]);
            Pad_PortButtons[i].initialized = 1;
            break;
        case 1:
            Pad_UpdateButtons(&Pad_PortButtons[i], a0);
            break;
        }
        break;
    case 0:
    default:
        Pad_PortButtons[i].initialized = 0;
        break;
    }
}

s32 Pad_GetButtonState(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (arg0 & arg2) {
        r = 1;
    } else if (arg1 & arg2) {
        r = -1;
    }
    return r;
}

void Pad_Update(void) {
    s32 i;
    PadBuf *a8 = (PadBuf *)Pad_RecvBufs;

    for (i = 0; i < 2; i++) {
        if (a8[i].status != 0) {
            Pad_PortButtons[i].initialized = 0;
            Pad_PortButtons[i].held = 0;
            Pad_PortButtons[i].pressed = 0;
            Pad_PortButtons[i].repeat = 0;
            Pad_State[i].connected = 0;
        } else if ((a8[i].padType >> 4) == 4) {
            Pad_PollPort(&a8[i], i);
            Pad_State[i].connected = 1;
        } else {
            Pad_PortButtons[i].held = 0;
            Pad_PortButtons[i].pressed = 0;
            Pad_PortButtons[i].repeat = 0;
            Pad_State[i].connected = 0;
        }
        Pad_State[i].up = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x1000);
        Pad_State[i].down = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x4000);
        Pad_State[i].right = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x2000);
        Pad_State[i].left = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x8000);
        Pad_State[i].circle = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x20);
        Pad_State[i].cross = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x40);
        Pad_State[i].triangle = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x10);
        Pad_State[i].square = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x80);
        Pad_State[i].l1 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x4);
        Pad_State[i].l2 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x1);
        Pad_State[i].r1 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x8);
        Pad_State[i].r2 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x2);
        Pad_State[i].select = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x100);
        Pad_State[i].start = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x800);
        Pad_State[i].held = Pad_PortButtons[i].held;
        Pad_State[i].pressed = Pad_PortButtons[i].pressed;
        Pad_State[i].repeat = Pad_PortButtons[i].repeat;
    }
}

void Sys_VSyncHandler(void) {
    s32 t = Sys_State.vsyncWait - (Sys_State.vsyncWait != 0);

    if (Sys_FlipPending != 0 && Sys_VSyncsSinceFlip >= t) {
        Sys_State.bufIndex = (Sys_State.bufIndex == 0);
        PutDispEnv(&Sys_State.disp[Sys_State.bufIndex]);
        PutDrawEnv(&Sys_State.draw[Sys_State.bufIndex]);
        Gpu_DrawOt(Sys_State.bufIndex ^ 1);
        Sys_FlipPending = 0;
        Sys_VSyncsSinceFlip = 0;
    } else {
        Sys_VSyncsSinceFlip++;
    }
    SsSeqCalledTbyT();
}


void Sys_Main(void) {
    SysClearRect r;
    GsIMAGE tim;
    u8 buf;
    s32 slot;
    s32 i;
    s32 t;
    s32 d;
    s32 u;

    func_80010D74();
    ResetCallback();
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    VSyncCallback((s32)Sys_VSyncHandler);
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x1FF;
    ClearImage((s32)&r, 0, 0, 0);
    DrawSync(0);
    GsInitGraph(0x140, 0xF0, 1, 1, 0);
    GsInit3D();
    SsInit();
    InitGeom();
    Gpu_InitDoubleBuffer(0x140, 0x280, 1, 0);
    PutDrawEnv(&Sys_State.draw[0]);
    PutDispEnv(&Sys_State.disp[0]);
    VSync(0);
    GsGetTimInfo((u32 *)(Ovl_LoadAddr + 4), &tim);
    VSync(0);
    LoadImage((s32)&Sys_BootImageRect, (s32)tim.paddr);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    CdInit();
    CdSetDebug(0);
    SetGraphDebug(0);
    Mem_InitHeap(Mem_HeapStart, 0x801FF000 - (s32)Mem_HeapStart);
    Cd_ClearFileCache();
    Snd_Init();
    Sys_State.frameCount = 0;
    Sys_State.vsyncWait = 0;
    Sys_State.bufIndex = 1;
    Gpu_FreePrimBufs();
    Gpu_SetOtLayout(0);
    Gpu_SetLayerOtPtrs();
    Rand_Seed(0);
    ((void (*)(s32))MemCardInit)(0);
    MemCardStart();
    Pad_Init();
    buf = 0x80;
    while (((s32 (*)(s32, u8 *, s32))CdControl)(0xE, &buf, 0) == 0) {
    }
    VSync(3);
    CdControlB(9, 0, 0);
    Task_ClearList();
    Gfx_InitTexSlots();
    Gpu_ClearOt(0);
    Gpu_ClearOt(1);
    Sys_State.frameCount = 1;
    Sys_State.gameMode = 0x402;
    Sys_State.nextGameMode = 0x402;
    Sys_State.modeArg = 0;
    Sys_State.field_C = 0;
    Save_ResetGameState();
    Dung_StatePtr->entryMode = 0;
    Gfx_FadeSetBlack();
    Gfx_DrawFade();
    slot = 0;
    for (;;) {
        if (slot == 0) {
            Task_ClearList();
            Gpu_FreePrimBufs();
            Mem_FreeTag(2);
            Gpu_ClearOt(0);
            Gpu_ClearOt(1);
            {
                s32 cur = Sys_State.gameMode;
                s32 next = Sys_State.nextGameMode;

                Sys_State.nextGameMode = 0;
                Sys_State.prevGameMode = cur;
                Sys_State.gameMode = next;
            }
            for (i = 0; i < 0x11; i++) {
                Flag_Set(i, 0);
            }
            Task_Create(1, &slot, 0);
        }
        Gfx_DrawFade();
        Sys_State.drawPass = 0;
        slot = Task_TryRun((void *)slot);
        Sys_State.drawPass = 1;
        slot = Task_TryRun((void *)slot);
        Gpu_SkipEmptyOtEntries(Sys_State.bufIndex);
        DrawSync(0);
        Sys_FlipPending = 1;
        while (*(volatile s32 *)&Sys_FlipPending != 0) {
        }
        Gpu_ResetPrimBuf();
        Gpu_SetLayerOtPtrs();
        Gpu_ClearOt(Sys_State.bufIndex);
        t = VSync(-1);
        u = Sys_LastVSyncTime;
        Sys_LastVSyncTime = t;
        d = t - u;
        Sys_State.frameDelta = d;
        Save_GameState.playTime += d;
        if (d > 6) {
            Sys_State.frameDelta = 6;
        }
        Sys_State.frameCount++;
        Pad_Update();
        Rand_Step();
        Cd_ServiceQueue();
        Snd_ServiceSlotLoads();
    }
}


void Rand_Seed(s32 a0) {
    Rand_Index = a0 & 0xFFF;
}


void Rand_Step(void) {
    Rand_Index = (Rand_Index + 1) & 0xFFF;
}


s32 Rand_Next(void) {
    Rand_Step();
    return Rand_Table[Rand_Index];
}


u16 Rand_GetAt(u32 arg0) {
    return Rand_Table[arg0 & 0xFFF];
}

void Sys_SetFrameRate60(void) {
    Sys_State.vsyncWait = 0;
}

void Sys_SetFrameRate30(void) {
    Sys_State.vsyncWait = 2;
}

void Sys_SetFrameRate20(void) {
    Sys_State.vsyncWait = 3;
}

void Sys_SetFrameRate15(void) {
    Sys_State.vsyncWait = 4;
}

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
