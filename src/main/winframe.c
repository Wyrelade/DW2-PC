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
void Text_WinFrameInit(Actor *arg0, s32 arg1);
void Text_WinFrameTask(Actor *a0);
void Text_WinFrameDraw(Actor *arg0);
/* Window frame part resources (Cd_GetFileEntry ids). */
s32 Text_WinFrameParts[] = { 0x03120001, 0x03120003, 0x03120000, 0x03120004 };
TaskDesc Text_WinFrameDesc = {
    (TaskInitFn)Text_WinFrameInit, Text_WinFrameTask, Task_DefaultDestroy, Text_WinFrameDraw, 2, 0,
};

void Text_WinFrameInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

void Text_WinFrameTask(Actor *a0) {
    s32 v1 = a0->stateLevel0;
    u16 *a1 = (u16 *)&a0->work->field_0;
    switch (v1) {
    case 1:
        if (a0->stateLevel1 == 0 || a0->stateLevel1 != v1) {
            u16 nv = *a1 + 0x555;
            *a1 = nv;
            if ((s16)nv >= 0x1000) {
                *a1 = 0x1000;
                Task_NextState1(a0);
            }
        }
        break;
    case 0:
        Task_NextState0(a0);
        break;
    case 2: {
        s16 nv = *a1 - 0x555;
        *a1 = nv;
        if (nv <= 0) {
            *a1 = 0;
            Task_NextState0(a0);
        }
        break;
    }
    }
}

void Text_WinFrameDraw(Actor *arg0) {
    ActorWork *w = arg0->work;
    void *e = Cd_GetFileEntry(Text_WinFrameParts[arg0->param]);
    Gfx_SetPartsScale(e, 0x1000, *(s16 *)w);
    Gfx_DrawParts((s32)e);
}
