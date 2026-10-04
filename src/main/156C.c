#include "common.h"
#include "main/156C.h"

/* Start of main .text: crt0 (hand asm), the task runner and Task_Run (C with an
 * inline stack switch in the original, restored as asm). Built with -G0: under -G8
 * cc1 writes C function text after all top-level asm, which would move the C
 * functions behind Task_Run. Nothing here reads small data. */

extern s32 Task_Run(s32);
extern TaskDesc **Task_DescTable[];

ASM_SOURCE("src/main/asm/crt0", func_80010D6C);

INCLUDE_RODATA("asm/USA/main/rodata", Ovl_LoadAddr);
void func_80010D74(void) {
}

ASM_SOURCE("src/main/asm/crt0", Sys_Start);

void Task_RunChildren(TaskChildrenView *a0) {
    s32 n = a0->childCount;
    s32 *arr = a0->children;
    s32 i;

    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[i] = Task_Run(arr[i]);
        }
    }
}

s32 Task_TryRun(void *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return Task_Run(arg0);
}

void Task_Destroy(s32 *arg0) {
    if (*arg0 != 0) {
        Task_SetState0(*arg0, 3);
        do {
            *arg0 = Task_TryRun(*arg0);
        } while (*arg0 != 0);
        *arg0 = 0;
    }
}

#ifdef NON_MATCHING
extern s32 Sys_DrawPass;
extern s32 Sys_FrameDelta;

/* Task_Run's view of a task: the type id (index into Task_DescTable), the state set by
 * Task_SetState0 (3 = being destroyed) and the two counters it advances. */
typedef struct {
    /* 0x00 */ s32 id;
    u8 _pad04[0x0C];
    /* 0x10 */ s32 state;
    u8 _pad14[0x10];
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
} TaskRunObj;

/* Task_Run's view of an TaskDesc: the callbacks after Task_Create's init. */
typedef struct {
    /* 0x00 */ void (*init)(ActorAllocView *, s32);
    /* 0x04 */ void (*field_4)(TaskRunObj *);
    /* 0x08 */ void (*field_8)(TaskRunObj *);
    /* 0x0C */ void (*field_C)(TaskRunObj *);
} TaskRunDesc;

/* The original switches sp to the scratchpad (old sp saved at 0x1F8003FC, callback
 * runs with sp = 0x1F8003F8) around the field_4 and field_C calls, then restores it.
 * The stack switch has no effect on behaviour, so C just calls the callbacks. */
s32 Task_Run(s32 arg0) {
    TaskRunObj *t = (TaskRunObj *)arg0;
    TaskRunDesc *d = (TaskRunDesc *)Task_DescTable[t->id >> 8][t->id & 0xFF];

    if (Sys_DrawPass == 0) {
        if (t->state == 3) {
            d->field_8(t);
            return 0;
        }
        d->field_4(t);                      /* on the scratchpad stack */
    } else {
        if (d->field_C != 0 && t->field_24 != 0 && t->state != 0 && t->state != 3) {
            d->field_C(t);                  /* on the scratchpad stack */
        }
        if (t->state != 0) {
            t->field_24++;
            t->field_28 += Sys_FrameDelta;
        }
    }
    Task_RunChildren((TaskChildrenView *)t);
    return (s32)t;
}
#else
ASM_SOURCE("src/main/asm/game", Task_Run);
#endif
