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
#include "main/model.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"
#include "main/mem.h"
#include "main/pad.h"
#include "main/sys.h"
#include "main/cd.h"

/* The asynchronous CD file read. Retail links a PsyQ data-only object (the rcos/sin tables)
 * between cd.c's .data and this file's. */

/* .bss: the header of the sector being read (Cd_CheckNextSector). */
u8 Cd_SectorHeader[0x10];
CdReadState Cd_ReadState = { 0 };

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
