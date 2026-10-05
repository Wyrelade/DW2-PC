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
#include "main/77DC.h"
#include "main/gamedata.h"

/* .bss */
FlagEntryState Flag_EntryIter;

void Flag_SetTableFile(s32 arg0) {
    Flag_EntryIter.fileId = arg0;
}

Blk18 *Flag_GetEntryCondBlock(FlagEntryIdx *arg0) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[arg0->condIdx];
}

Blk18 *Flag_GetBranchCondBlock(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altCondIdx];
}

Blk18 *Flag_GetBranchSetBlock(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altSetIdx];
}

s32 Flag_NextPassingEntry(void) {
    while (Flag_EntryIter.cursor->field_0 != 0) {
        if (Flag_TestConds(Flag_GetEntryCondBlock((FlagEntryIdx *)Flag_EntryIter.cursor)) != 0) {
            Flag_EntryIter.match = *Flag_EntryIter.cursor;
            {
                s32 r = Flag_EntryIter.entryIndex;

                Flag_EntryIter.cursor++;
                Flag_EntryIter.entryIndex = r + 1;
                return r;
            }
        }
        Flag_EntryIter.cursor++;
        Flag_EntryIter.entryIndex++;
    }
    return -1;
}

void Flag_FirstPassingEntry(void) {
    Flag_EntryIter.fileBase = Cd_GetFileOrNull(Flag_EntryIter.fileId);
    Flag_EntryIter.cursor = Cd_GetFileEntry(Flag_EntryIter.fileId << 16);
    Flag_EntryIter.entryIndex = 0;
    Flag_NextPassingEntry();
}

FlagBranchEntry *Flag_GetEntry(arg0)
s32 arg0;
{
    FlagBranchEntry *base = (FlagBranchEntry *)Cd_GetFileEntry(Flag_EntryIter.fileId << 16);
    return &base[arg0];
}

extern s32 Flag_TestConds();
extern void Flag_ApplySets();

s32 Flag_SelectBranch(s32 arg0) {
    FlagBranchEntry *base;
    s32 r;
    s32 i;
    r = Cd_GetFileOrNull(Flag_EntryIter.fileId);
    base = Flag_GetEntry(arg0);
    for (i = 0; i < 6; i++) {
        if (Flag_TestConds(Flag_GetBranchCondBlock((FlagEntryIdx *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    Flag_ApplySets(Flag_GetBranchSetBlock((FlagEntryIdx *)base, i));
    return base->branchOffsets[i] + r;
}

s32 Flag_GetTableBase(void) {
    return Cd_GetFileOrNull(Flag_EntryIter.fileId);
}

Blk12 *Flag_GetEntryPosList(s32 index) {
    FlagBranchEntry *e = Flag_GetEntry(index);
    Blk12 *base = (Blk12 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 1);
    return &base[e->blockIndex];
}

s16 Flag_GetEntryDigiId(s32 index) {
    return Flag_GetEntry(index)->field_0;
}

s16 Flag_GetEntryDir(s32 index) {
    return Flag_GetEntry(index)->field_2;
}
