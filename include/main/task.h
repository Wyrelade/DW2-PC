#ifndef MAIN_TASK_H
#define MAIN_TASK_H

#include "main/game.h"

/* Functions src/main/task.c defines. */
extern TaskEntry *Task_FindNext(void);
extern void Task_Create(u32, s32 *, s32);
void Task_Create(u32 id, s32 *slot, s32 arg);
void func_80011140(void);
void func_80011160(void);
void func_80011168(void);
void Task_DefaultDestroy(Actor *arg0);
void Task_ClearList(void);
ActorAllocView *Task_Alloc(void);
void Task_Free();
ActorAllocView *Task_AllocWithBuffers(s32 a0, s32 a1);
TaskEntry *Task_FindNext(void);
TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
void Task_NextState0(Actor *arg0);
void Task_NextState1(Actor *arg0);
void Task_NextState2(Actor *arg0);
void Task_NextState3(Actor *arg0);
void Task_NextState4(Actor *arg0);
void Task_SetState0(Actor *arg0, u32 arg1);
void Task_SetState1(Actor *arg0, u32 arg1);
void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2);
void Task_SetState2(Actor *arg0, u32 arg1);
void Task_SetState3(Actor *arg0, u32 arg1);
void Task_SetState4(Actor *arg0, u32 arg1);

#endif /* MAIN_TASK_H */
