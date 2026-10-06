#ifndef STAG3000_ACTIONLOAD_H
#define STAG3000_ACTIONLOAD_H

/* Functions src/stag3000/actionload.c defines. */
void Stg30_ActionLoadInit(Actor *a0, s32 *args);
void Stg30_ActionLoadAddSorted(Actor *a0, s32 file, s32 lba);
void Stg30_ActionLoadUpdate(Actor *a0);
void Stg30_ActionLoadDestroy(Actor *a0);

#endif /* STAG3000_ACTIONLOAD_H */
