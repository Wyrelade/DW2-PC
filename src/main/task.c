#include "common.h"
#include "main/game.h"

#ifdef DW2_NATIVE
/* Called before its definition (an implicit int declaration in retail C). */
ActorAllocView *Task_AllocWithBuffers(s32 a0, s32 a1);
#endif

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches the ones this unit uses with %gp_rel. */
/* Heap start: the fixed end of the overlay load area (memory map). */
#ifdef DW2_NATIVE
MemBlock *Mem_HeapStart = (MemBlock *)PS1_RAM(0x80075000);
#else
MemBlock *Mem_HeapStart = (MemBlock *)0x80075000;
#endif
/* Unreferenced: the first .sbss word (crt0 clears .sbss/.bss from here). */
s32 D_80050758;
/* .bss (game.h order) */
TaskList Task_List;
TaskFindFilter Task_FindFilter;

/* Defined further down. */
void Task_DefaultDestroy(Actor *arg0);

void Task_Create(u32 id, s32 *slot, s32 arg) {
    TaskDesc *d;
    ActorAllocView *o;

    if (*slot != 0) {
        Task_Destroy(slot);
    }
    d = Task_DescTable[id >> 8][id & 0xFF];
    o = Task_AllocWithBuffers(d->workSize, d->auxSize);
    o->id = id;
    o->frameCount = 0;
    if (arg != 0 && d->init != 0) {
        d->init(o, arg);
    }
    *slot = (s32)o;
}

/* Unnamed: calls Task_NextState0() with no argument, no callers, no table ref (dead). */
void func_80011140(void) {
    Task_NextState0();
}

/* Unnamed: empty stub, no callers, no table ref. */
void func_80011160(void) {
}

/* Unnamed: empty stub, no callers, no table ref. */
void func_80011168(void) {
}

void Task_DefaultDestroy(Actor *arg0) {
#ifdef DW2_NATIVE
    Task_Free(arg0);
#else
    /* No argument: a0 still holds arg0 for Task_Free. */
    Task_Free();
#endif
}

void Task_ClearList(void) {
    s16 i;
    for (i = 0; i < 100; i++) {
        Task_List.entries[i] = 0;
    }
    Task_List.count = 0;
}

ActorAllocView *Task_Alloc(void) {
    ActorAllocView *s0 = (ActorAllocView *)Mem_Alloc(0x40, 2);
    s32 i;
    Mem_Zero(s0, 0x40);
    for (i = 0; i < 0x64; i++) {
        if (Task_List.entries[i] == 0) {
            Task_List.entries[i] = (s32)s0;
            break;
        }
    }
    if (Task_List.count < i + 1) {
        Task_List.count = i + 1;
    }
    return s0;
}

void Task_Free(arg0)
TaskFreeView *arg0;
{
    ActorModelFreeView *sub;
    s32 i;
    s32 *p;
    s32 j;

    if (arg0->childCount != 0) {
        s32 *fp = arg0->children;
        i = 0;
        if (arg0->childCount > 0) {
            p = fp;
            do {
                Task_Destroy(p);
                p++;
            } while (++i < arg0->childCount);
            fp = arg0->children;
        }
        Mem_Free((ActorWork *)fp);
    }

    if (arg0->work != 0) {
        Mem_Free(arg0->work);
    }
    if (arg0->transform != 0) {
        Mem_Free(arg0->transform);
    }

    sub = arg0->model;
    if (sub != 0) {
        if (sub->screenXY != 0) {
            Mem_Free(sub->screenXY);
        }
        if (sub->vertOtz != 0) {
            Mem_Free(sub->vertOtz);
        }
        i = sub->vertColors != 0;
        if (i) {
            Mem_Free(sub->vertColors);
        }
        if (sub->bones != 0) {
            Mem_Free(sub->bones);
        }
        Mem_Free((ActorWork *)arg0->model);
    }

    for (j = 0; j < 100; j++) {
        if (Task_List.entries[j] == (s32)arg0) {
            Task_List.entries[j] = 0;
            break;
        }
    }

    Mem_Free((ActorWork *)arg0);
}

ActorAllocView *Task_AllocWithBuffers(s32 a0, s32 a1) {
    ActorAllocView *s0 = Task_Alloc();
    if (a0 != 0) {
        s32 x = Mem_Alloc(a0, 2);
        s0->work = x;
        Mem_Zero((void *)x, a0);
    }
    if (a1 != 0) {
        s32 y = Mem_Alloc(a1, 2);
        s0->children = y;
        Mem_Zero((void *)y, a1);
        s0->childCount = a1 >> 2;
    }
    return s0;
}

TaskEntry *Task_FindNext(void) {
    s32 i;
    TaskEntry *e;

    i = Task_FindFilter.nextIndex;
    while (i < Task_List.count) {
        do {
            e = (TaskEntry *)Task_List.entries[i];
            if (e != 0) {
                if (Task_FindFilter.key0 != -1) {
                    if (e->id != Task_FindFilter.key0) break;
                }
                if (Task_FindFilter.key1 != -1) {
                    if (e->field_4 != Task_FindFilter.key1) break;
                }
                if (Task_FindFilter.key2 != -1) {
                    if (e->param != Task_FindFilter.key2) break;
                }
                Task_FindFilter.nextIndex = i + 1;
                return (TaskEntry *)Task_List.entries[i];
            }
        } while (0);
        i++;
    }
    return 0;
}

extern TaskEntry *Task_FindNext(void);

TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2) {
    Task_FindFilter.key0 = arg0;
    Task_FindFilter.key1 = arg1;
    Task_FindFilter.key2 = arg2;
    Task_FindFilter.nextIndex = 0;
    return Task_FindNext();
}

#ifdef DW2_NATIVE
/* Retail callers sometimes pass a NULL task (a child task already gone: stag3000
 * Stg30_TargetSelectUpdate for an empty enemy slot, stag4000 Stg40_RootUpdate closing the HUD after
 * the top menu closed it). On the PS1 the state bytes land in RAM low words (address 0 is RAM) and
 * are never read back; here the store is skipped. */
#define TASK_NULL_GUARD(t) if ((t) == NULL) return;
#else
#define TASK_NULL_GUARD(t)
#endif

void Task_NextState0(Actor *arg0) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1 = 0;
    arg0->stateLevel0++;
}

void Task_NextState1(Actor *arg0) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1++;
}

void Task_NextState2(Actor *arg0) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2++;
}

void Task_NextState3(Actor *arg0) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4 = 0;
    arg0->stateLevel3++;
}

void Task_NextState4(Actor *arg0) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4++;
}

void Task_SetState0(Actor *arg0, u32 arg1) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel0 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
    arg0->stateLevel1 = 0;
}

void Task_SetState1(Actor *arg0, u32 arg1) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel1 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
}

void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel0 = arg1 & 0xFF;
    arg0->stateLevel1 = arg2 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel2 = 0;
}

void Task_SetState2(Actor *arg0, u32 arg1) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel2 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
    arg0->stateLevel3 = 0;
}

void Task_SetState3(Actor *arg0, u32 arg1) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel3 = arg1 & 0xFF;
    arg0->stateLevel4 = 0;
}

void Task_SetState4(Actor *arg0, u32 arg1) {
    TASK_NULL_GUARD(arg0)
    arg0->stateLevel4 = arg1 & 0xFF;
}
