#ifndef MAIN_FLAGTABLE_H
#define MAIN_FLAGTABLE_H

#include "main/game.h"

/* Functions src/main/flagtable.c defines. */
void Flag_SetTableFile(s32 arg0);
Blk18 *Flag_GetEntryCondBlock(FlagEntryIdx *arg0);
Blk18 *Flag_GetBranchCondBlock(FlagEntryIdx *arg0, s32 arg1);
Blk18 *Flag_GetBranchSetBlock(FlagEntryIdx *arg0, s32 arg1);
s32 Flag_NextPassingEntry(void);
void Flag_FirstPassingEntry(void);
FlagBranchEntry *Flag_GetEntry();
s32 Flag_SelectBranch(s32 arg0);
s32 Flag_GetTableBase(void);
Blk12 *Flag_GetEntryPosList(s32);
s16 Flag_GetEntryDigiId(s32);
s16 Flag_GetEntryDir(s32);

#endif /* MAIN_FLAGTABLE_H */
