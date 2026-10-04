#include "common.h"
#include "main/156C.h"

/* Start of main .text: crt0 (hand asm) and the task runner. Built with -G0: under -G8
 * cc1 writes C function text after all top-level asm, which would move the C
 * functions behind the crt0 asm. Nothing here reads small data. */

extern s32 Task_Run(s32);
extern TaskDesc **Task_DescTable[];

ASM_SOURCE("src/main/asm/crt0", func_80010D6C);

/* Overlay load address: every STAGxxxx.PRO is read to and runs from here. Ovl_LoadArea
 * starts right after main's .bss (the image's bytes there are leftovers, kept as a bin). */
extern u8 Ovl_LoadArea[];
u8 *const Ovl_LoadAddr = Ovl_LoadArea;
/* Unnamed: empty stub, only caller Sys_Main (first call, before ResetCallback), no table ref;
 * role unknown. */
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

extern s32 Sys_DrawPass;
extern s32 Sys_FrameDelta;

/* Task_Run's view of a task: the type id (index into Task_DescTable), the state set by
 * Task_SetState0 (3 = being destroyed) and the two counters it advances. */
typedef struct {
    /* 0x00 */ s32 id;
    u8 _pad04[0x0C];
    /* 0x10 */ s32 state;
    u8 _pad14[0x10];
    /* 0x24 */ s32 frameCount;
    /* 0x28 */ s32 elapsed;
} TaskRunObj;

/* Task_Run's view of a TaskDesc: the callbacks after Task_Create's init. */
typedef struct {
    /* 0x00 */ void (*init)(ActorAllocView *, s32);
    /* 0x04 */ void (*update)(TaskRunObj *);
    /* 0x08 */ void (*destroy)(TaskRunObj *);
    /* 0x0C */ void (*draw)(TaskRunObj *);
} TaskRunDesc;

/* The update and draw callbacks run on a stack in the scratchpad: the old sp is saved at
 * 0x1F8003FC and the callback runs with sp = 0x1F8003F8. Plain C cannot move sp, so the
 * switch is two small asm statements (the original did the same). They do nothing for
 * behaviour, so a non-matching build drops them. */
#define SCRATCH_STACK_TOP 0x1F8003FC
#ifdef NON_MATCHING
#define SCRATCH_STACK_ENTER(top)
#define SCRATCH_STACK_LEAVE()
#else
#define SCRATCH_STACK_ENTER(top) __asm__ volatile( \
    "move $8, %0\n\tsw $29, 0($8)\n\taddiu $8, $8, -4\n\tmove $29, $8" : : "r"(top) : "$8", "memory")
#define SCRATCH_STACK_LEAVE() __asm__ volatile("addiu $29, $29, 4\n\tlw $29, 0($29)" : : : "memory")
#endif

s32 Task_Run(s32 arg0) {
    TaskRunObj *t = (TaskRunObj *)arg0;
    TaskRunDesc *d = (TaskRunDesc *)Task_DescTable[t->id >> 8][t->id & 0xFF];

    if (Sys_DrawPass != 0) {
        if (d->draw != 0 && t->frameCount != 0) {
            if (t->state == 0) {
                goto children;
            }
            if (t->state != 3) {
                SCRATCH_STACK_ENTER(SCRATCH_STACK_TOP);
                d->draw(t);
                SCRATCH_STACK_LEAVE();
            }
        }
        if (t->state != 0) {
            s32 *c = &t->frameCount;
            *c += 1;
            c = &t->elapsed;
            *c += Sys_FrameDelta;
        }
    } else {
        if (t->state == 3) {
            d->destroy(t);
            return 0;
        }
        SCRATCH_STACK_ENTER(SCRATCH_STACK_TOP);
        d->update(t);
        SCRATCH_STACK_LEAVE();
    }
children:
    Task_RunChildren((TaskChildrenView *)t);
    return (s32)t;
}
