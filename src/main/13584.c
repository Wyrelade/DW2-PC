#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/4BCC.h"
#include "main/12550.h"
#include "main/12654.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
s32 D_8005072C;
s32 D_80050730;
s32 D_80050738;
s32 D_80050750;
s32 D_80050784;
MemBlock *D_80050788;
s32 D_8005078C;
s32 D_80050790;

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
    MemBlock *b = D_80050788;

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

    D_80050784 = size;
    D_80050788 = heap;
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
    MemBlock *b = D_80050788;
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
    MemBlock *b = D_80050788;

    if (b->tag != 1) {
        do {
            tbl[b->tag] += (s32)b->next - (s32)b;
            b = b->next;
        } while (b->tag != 1);
    }
}


u32 Mem_GetLargestFree(void) {
    MemBlock *b = D_80050788;
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
    PadInitDirect(D_8005F6A8, D_8005F6A8 + 0x22);
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
        switch (D_8005F678[i].initialized) {
        case 0:
        default:
            Pad_ResetButtons((PadButtons *)&D_8005F678[i]);
            D_8005F678[i].initialized = 1;
            break;
        case 1:
            Pad_UpdateButtons(&D_8005F678[i], a0);
            break;
        }
        break;
    case 0:
    default:
        D_8005F678[i].initialized = 0;
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
    PadBuf *a8 = (PadBuf *)D_8005F6A8;

    for (i = 0; i < 2; i++) {
        if (a8[i].status != 0) {
            D_8005F678[i].initialized = 0;
            D_8005F678[i].held = 0;
            D_8005F678[i].pressed = 0;
            D_8005F678[i].repeat = 0;
            D_8005F6F0[i].connected = 0;
        } else if ((a8[i].padType >> 4) == 4) {
            Pad_PollPort(&a8[i], i);
            D_8005F6F0[i].connected = 1;
        } else {
            D_8005F678[i].held = 0;
            D_8005F678[i].pressed = 0;
            D_8005F678[i].repeat = 0;
            D_8005F6F0[i].connected = 0;
        }
        D_8005F6F0[i].up = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x1000);
        D_8005F6F0[i].down = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x4000);
        D_8005F6F0[i].right = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x2000);
        D_8005F6F0[i].left = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x8000);
        D_8005F6F0[i].circle = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x20);
        D_8005F6F0[i].cross = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x40);
        D_8005F6F0[i].triangle = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x10);
        D_8005F6F0[i].square = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x80);
        D_8005F6F0[i].l1 = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x4);
        D_8005F6F0[i].l2 = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x1);
        D_8005F6F0[i].r1 = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x8);
        D_8005F6F0[i].r2 = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x2);
        D_8005F6F0[i].select = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x100);
        D_8005F6F0[i].start = Pad_GetButtonState(D_8005F678[i].pressed, D_8005F678[i].held, 0x800);
        D_8005F6F0[i].held = D_8005F678[i].held;
        D_8005F6F0[i].pressed = D_8005F678[i].pressed;
        D_8005F6F0[i].repeat = D_8005F678[i].repeat;
    }
}

void Sys_VSyncHandler(void) {
    s32 t = D_8005F770.vsyncWait - (D_8005F770.vsyncWait != 0);

    if (D_8005078C != 0 && D_8005072C >= t) {
        D_8005F770.bufIndex = (D_8005F770.bufIndex == 0);
        PutDispEnv(&D_8005F770.disp[D_8005F770.bufIndex]);
        PutDrawEnv(&D_8005F770.draw[D_8005F770.bufIndex]);
        Gpu_DrawOt(D_8005F770.bufIndex ^ 1);
        D_8005078C = 0;
        D_8005072C = 0;
    } else {
        D_8005072C++;
    }
    SsSeqCalledTbyT();
}


#ifdef NORMALIZED
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
    func_8002B4C4();
    SsInit();
    func_8002CE5C();
    Gpu_InitDoubleBuffer(0x140, 0x280, 1, 0);
    PutDrawEnv(&D_8005F770.draw[0]);
    PutDispEnv(&D_8005F770.disp[0]);
    VSync(0);
    GsGetTimInfo((u32 *)(D_80010000[0] + 4), &tim);
    VSync(0);
    LoadImage((s32)&D_80050730, (s32)tim.paddr);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    CdInit();
    CdSetDebug(0);
    SetGraphDebug(0);
    Mem_InitHeap(D_800506F8[0], 0x801FF000 - (s32)D_800506F8[0]);
    Cd_ClearFileCache();
    Snd_Init();
    D_8005F770.frameCount = 0;
    D_8005F770.vsyncWait = 0;
    D_8005F770.bufIndex = 1;
    Gpu_FreePrimBufs();
    func_8001C800(0);
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
    D_8005F770.frameCount = 1;
    D_8005F770.gameMode = 0x402;
    D_8005F770.nextGameMode = 0x402;
    D_8005F770.field_24 = 0;
    D_8005F770.field_C = 0;
    Save_ResetGameState();
    D_8005071C->field_0 = 0;
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
            t = D_8005F770.gameMode;
            u = D_8005F770.nextGameMode;
            D_8005F770.nextGameMode = 0;
            D_8005F770.prevGameMode = t;
            D_8005F770.gameMode = u;
            for (i = 0; i < 0x11; i++) {
                Flag_Set(i, 0);
            }
            Task_Create(1, &slot, 0);
        }
        Gfx_DrawFade();
        D_8005F770.drawPass = 0;
        slot = Task_TryRun((void *)slot);
        D_8005F770.drawPass = 1;
        slot = Task_TryRun((void *)slot);
        Gpu_SkipEmptyOtEntries(D_8005F770.bufIndex);
        DrawSync(0);
        D_8005078C = 1;
        while (*(volatile s32 *)&D_8005078C != 0) {
        }
        Gpu_ResetPrimBuf();
        Gpu_SetLayerOtPtrs();
        Gpu_ClearOt(D_8005F770.bufIndex);
        t = VSync(-1);
        u = D_80050738;
        D_80050738 = t;
        d = t - u;
        D_8005F770.frameDelta = d;
        D_8005E620.playTime += d;
        if (d > 6) {
            D_8005F770.frameDelta = 6;
        }
        D_8005F770.frameCount++;
        Pad_Update();
        Rand_Step();
        Cd_ServiceQueue();
        Snd_ServiceSlotLoads();
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Sys_Main);
void Sys_Main(void);
#endif


void Rand_Seed(s32 a0) {
    D_80050790 = a0 & 0xFFF;
}


void Rand_Step(void) {
    D_80050790 = (D_80050790 + 1) & 0xFFF;
}


s32 Rand_Next(void) {
    Rand_Step();
    return D_80041704[D_80050790];
}


u16 Rand_GetAt(u32 arg0) {
    return D_80041704[arg0 & 0xFFF];
}

void Sys_SetFrameRate60(void) {
    D_8005F770.vsyncWait = 0;
}

void Sys_SetFrameRate30(void) {
    D_8005F770.vsyncWait = 2;
}

void Sys_SetFrameRate20(void) {
    D_8005F770.vsyncWait = 3;
}

void Sys_SetFrameRate15(void) {
    D_8005F770.vsyncWait = 4;
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
    CdCacheEntry *p = D_8005F8C8;
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
    CdCacheEntry *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == arg0) return p;
    }
    return NULL;
}

CdCacheEntry *Cd_FindFreeCacheSlot(void) {
    s32 i;
    CdCacheEntry *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == 0) return p;
    }
    return NULL;
}

CdLruEntry *Cd_FindLruCachedFile(void) {
    s32 min = D_8005F770.frameCount;
    CdCacheEntry *p = D_8005F8C8;
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
        e->lastUsed = D_8005F770.frameCount;
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
        p->lastUsed = D_8005F770.frameCount;
        return;
    }
    p = Cd_FindFreeCacheSlot();
    p->fileId = id;
    p->data = Mem_Alloc(Cd_GetFileSectors(id) << 11, 3);
    p->state = 1;
    p->lastUsed = 0;
    D_80050750 = 1;
}


void Cd_ServiceQueue(void) {
    s32 started;
    s32 busy;
    s32 i;
    CdCacheEntry *p;

    if (D_80050750 == 0) {
        return;
    }
    if (Cd_PollRead() != 0) {
        return;
    }
    p = D_8005F8C8;
    started = 0;
    busy = 0;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->fileId == 0) {
            continue;
        }
        if (p->state != 1) {
            if (p->state == 2) {
                p->state = 3;
                p->lastUsed = D_8005F770.frameCount;
                busy = 1;
            }
        } else {
            busy = 1;
            if (started == 0) {
                Cd_ReadFileAsync(p->fileId, p->data);
                p->state = 2;
                p->lastUsed = D_8005F770.frameCount;
                started = busy;
            }
        }
    }
    if (busy == 0) {
        D_80050750 = 0;
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
        p->lastUsed = D_8005F770.frameCount;
    } else {
        while (Cd_PollRead() != 0) {
        }
        Cd_LoadFileSync(arg0);
    }
    return Cd_FindCachedFile(arg0)->data;
}

void Cd_FreeFile(void) {
    CdCacheEntry *p = Cd_FindCachedFile();
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
        if (D_8005F8C8[i].fileId != 0 && D_8005F8C8[i].locked == 0) {
            Mem_Free(D_8005F8C8[i].data);
            D_8005F8C8[i].fileId = 0;
            D_8005F8C8[i].data = 0;
            D_8005F8C8[i].lastUsed = 0;
            D_8005F8C8[i].state = 0;
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

s32 Cd_CheckNextSector(void) {
    s32 x;
    CdGetSector(D_8005FDC8, 3);
    x = CdPosToInt(D_8005FDC8);
    if (x == D_80048DB8.nextLba) {
        D_80048DB8.nextLba = x + 1;
        return 0;
    }
    return -1;
}

void Cd_ReadSectorCallback(s32 a0) {
    if (a0 == 1 && Cd_CheckNextSector() == 0) {
        CdGetSector((void *)D_80048DB8.dest, 0x200);
        D_80048DB8.dest += 0x800;
        D_80048DB8.sectorsLeft -= 1;
        if (D_80048DB8.sectorsLeft != 0) {
            return;
        }
    } else {
        D_80048DB8.sectorsLeft = -1;
    }
    CdReadyCallback(0);
    CdControlF(9, 0);
}

void Cd_ReadSyncCallback(s32 ev) {
    if (ev == 5) {
        if (D_80048DB8.state == 4) {
            CdControlF(9, 0);
        } else {
            D_80048DB8.state = 0;
            D_80048DB8.sectorsLeft = D_80048DB8.sectorCount;
            Cd_ReadFileAsync(D_80048DB8.fileId, D_80048DB8.buf);
        }
    } else if (ev == 2) {
        switch (D_80048DB8.state) {
        case 1:
            D_80048DB8.cdMode = 0xA0;
            CdControlF(14, &D_80048DB8.cdMode);
            D_80048DB8.state++;
            break;
        case 2:
            CdReadyCallback((s32)Cd_ReadSectorCallback);
            CdControlF(6, 0);
            D_80048DB8.state++;
            break;
        case 3:
            D_80048DB8.state = 4;
            break;
        case 4:
            if (D_80048DB8.sectorsLeft == 0) {
                D_80048DB8.state = 5;
                CdSyncCallback(0);
            } else {
                D_80048DB8.state = 0;
                D_80048DB8.sectorsLeft = D_80048DB8.sectorCount;
                Cd_ReadFileAsync(D_80048DB8.fileId, D_80048DB8.buf);
            }
            break;
        }
    }
}

s32 Cd_PollRead(void) {
    switch (D_80048DB8.state) {
    case 0:
        return 0;
    case 5:
        D_80048DB8.state = 0;
        return 2;
    }
    return 1;
}

void Cd_ReadFileAsync(s32 arg0, s32 arg1) {
    u8 sp10[8];
    s32 r;

    if (D_80048DB8.state != 0) {
        while (Cd_PollRead() != 0) {}
    }
    Cd_GetFilePos(arg0, sp10);
    r = Cd_GetFileSectors(arg0);
    D_80048DB8.sectorsLeft = r;
    D_80048DB8.dest = arg1;
    D_80048DB8.sectorCount = r;
    D_80048DB8.fileId = arg0;
    D_80048DB8.buf = arg1;
    D_80048DB8.nextLba = Cd_GetFileLba(arg0);
    D_80048DB8.state += 1;
    CdSyncCallback(Cd_ReadSyncCallback);
    CdControlF(2, sp10);
}

void func_80024310(Actor *arg0, Block1C *arg1) {
    *(Block1C *)arg0->work = *arg1;
}

void func_80024350(Actor *arg0) {
    ActorWork *work = arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, &work->field_8, work->field_14);
        Gfx_AttachModel(arg0, work->field_0)->otIndex = 3;
        Anim_SetModelAnimFile(arg0, 0, work->field_4);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorModel *s = arg0->model;
        if (arg0->elapsed < work->field_18 && s->animDone >= 0)
            break;
        Task_SetState0(arg0, 3);
        break;
    }
    case 2:
        break;
    }
}

void func_80024410(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->stateLevel0 == 1) {
        Gfx_AttachModel(arg0, w->field_0);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 0);
    }
}
