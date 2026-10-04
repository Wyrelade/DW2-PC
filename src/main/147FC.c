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
#include "main/13584.h"

/* From Cd_CheckNextSector: the asynchronous CD file read and the Fx model task. Retail links
 * a PsyQ data-only object (the rcos/sin tables) between 13584.c's .data and this unit's. */

/* Task callbacks the descriptor below names (defined further down). */
void Fx_ModelInit(Actor *arg0, Block1C *arg1);
void Fx_ModelTask(Actor *arg0);
void Fx_ModelDraw(Actor *arg0);

/* .bss: the header of the sector being read (Cd_CheckNextSector). */
u8 Cd_SectorHeader[0x10];
CdReadState Cd_ReadState = { 0 };
TaskDesc D_80048DD8 = { (TaskInitFn)Fx_ModelInit, Fx_ModelTask, Task_DefaultDestroy, Fx_ModelDraw, 0x1C, 0 };

s32 Cd_CheckNextSector(void) {
    s32 x;
    CdGetSector(Cd_SectorHeader, 3);
    x = CdPosToInt(Cd_SectorHeader);
    if (x == Cd_ReadState.nextLba) {
        Cd_ReadState.nextLba = x + 1;
        return 0;
    }
    return -1;
}

void Cd_ReadSectorCallback(s32 a0) {
    if (a0 == 1 && Cd_CheckNextSector() == 0) {
        CdGetSector((void *)Cd_ReadState.dest, 0x200);
        Cd_ReadState.dest += 0x800;
        Cd_ReadState.sectorsLeft -= 1;
        if (Cd_ReadState.sectorsLeft != 0) {
            return;
        }
    } else {
        Cd_ReadState.sectorsLeft = -1;
    }
    CdReadyCallback(0);
    CdControlF(9, 0);
}

void Cd_ReadSyncCallback(s32 ev) {
    if (ev == 5) {
        if (Cd_ReadState.state == 4) {
            CdControlF(9, 0);
        } else {
            Cd_ReadState.state = 0;
            Cd_ReadState.sectorsLeft = Cd_ReadState.sectorCount;
            Cd_ReadFileAsync(Cd_ReadState.fileId, Cd_ReadState.buf);
        }
    } else if (ev == 2) {
        switch (Cd_ReadState.state) {
        case 1:
            Cd_ReadState.cdMode = 0xA0;
            CdControlF(14, &Cd_ReadState.cdMode);
            Cd_ReadState.state++;
            break;
        case 2:
            CdReadyCallback((s32)Cd_ReadSectorCallback);
            CdControlF(6, 0);
            Cd_ReadState.state++;
            break;
        case 3:
            Cd_ReadState.state = 4;
            break;
        case 4:
            if (Cd_ReadState.sectorsLeft == 0) {
                Cd_ReadState.state = 5;
                CdSyncCallback(0);
            } else {
                Cd_ReadState.state = 0;
                Cd_ReadState.sectorsLeft = Cd_ReadState.sectorCount;
                Cd_ReadFileAsync(Cd_ReadState.fileId, Cd_ReadState.buf);
            }
            break;
        }
    }
}

s32 Cd_PollRead(void) {
    switch (Cd_ReadState.state) {
    case 0:
        return 0;
    case 5:
        Cd_ReadState.state = 0;
        return 2;
    }
    return 1;
}

void Cd_ReadFileAsync(s32 arg0, s32 arg1) {
    u8 sp10[8];
    s32 r;

    if (Cd_ReadState.state != 0) {
        while (Cd_PollRead() != 0) {}
    }
    Cd_GetFilePos(arg0, sp10);
    r = Cd_GetFileSectors(arg0);
    Cd_ReadState.sectorsLeft = r;
    Cd_ReadState.dest = arg1;
    Cd_ReadState.sectorCount = r;
    Cd_ReadState.fileId = arg0;
    Cd_ReadState.buf = arg1;
    Cd_ReadState.nextLba = Cd_GetFileLba(arg0);
    Cd_ReadState.state += 1;
    CdSyncCallback(Cd_ReadSyncCallback);
    CdControlF(2, sp10);
}

void Fx_ModelInit(Actor *arg0, Block1C *arg1) {
    *(Block1C *)arg0->work = *arg1;
}

void Fx_ModelTask(Actor *arg0) {
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
        if (arg0->elapsed < work->duration && s->animDone >= 0)
            break;
        Task_SetState0(arg0, 3);
        break;
    }
    case 2:
        break;
    }
}

void Fx_ModelDraw(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->stateLevel0 == 1) {
        Gfx_AttachModel(arg0, w->field_0);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 0);
    }
}
