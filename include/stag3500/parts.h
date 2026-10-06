#ifndef STAG3500_PARTS_H
#define STAG3500_PARTS_H

/* Functions src/stag3500/parts.c defines. */
void Stg35_PartsAlloc(Stg35PartsHandle *arg0);
void Stg35_PartsFree(Stg35PartsHandle *arg0);
void Stg35_PartsSetFile(Stg35PartsHandle *arg0, s32 arg1);
void Stg35_PartsDraw(Stg35PartsHandle *arg0);
void Stg35_PartsHideByMask(Stg35PartsHandle *arg0, s32 arg1);
void Stg35_PartsShowGroup(Stg35PartsHandle *arg0, s32 mask);
void Stg35_PartsHideGroup(Stg35PartsHandle *arg0, s32 mask);
void Stg35_PartsStartOpen(Stg35PartsHandle *arg0);
void Stg35_PartsStartScaleOut(Stg35PartsHandle *arg0);
void Stg35_PartsSetPalette(Stg35PartsHandle *arg0, s32 mask, s32 v);
void Stg35_PartsSetX(Stg35PartsHandle *arg0, s32 mask, s32 v);
void Stg35_PartsSetY(Stg35PartsHandle *arg0, s32 mask, s32 v);
void Stg35_PartsStartSlideX(Stg35PartsHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed);
void Stg35_PartsSetNumber(Stg35PartsHandle *arg0, s32 arg1, s32 arg2, s32 arg3);

#endif /* STAG3500_PARTS_H */
