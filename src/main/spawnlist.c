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

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Task_SpawnListInit(Actor *arg0, s32 *arg1);
void Task_SpawnListFromFile(Actor *a0);

TaskDesc Task_SpawnListDesc = {
    (TaskInitFn)Task_SpawnListInit, Task_SpawnListFromFile, Task_DefaultDestroy, 0, 4, 0xA0,
};

void Task_SpawnListInit(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void Task_SpawnListFromFile(Actor *a0) {
    TaskSpawnEntry *p;
    s32 *slot;
    s32 end = -1;
    s32 *s;

    if (a0->stateLevel0 != 0) {
        return;
    }
    s = (s32 *)a0->u34.children;
    p = (TaskSpawnEntry *)Cd_GetFileOrNull(a0->work->field_0);
    slot = s;
loop:
    if (p->taskId == end) {
        goto done;
    }
    Task_Create(p->taskId, slot, (s32)&p->args);
    slot++;
    p = (TaskSpawnEntry *)((u8 *)p + p->size);
    goto loop;
done:
    Task_NextState0(a0);
}
