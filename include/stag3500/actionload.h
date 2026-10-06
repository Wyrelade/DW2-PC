#ifndef STAG3500_ACTIONLOAD_H
#define STAG3500_ACTIONLOAD_H

/* Functions src/stag3500/actionload.c defines. */
void Stg35_ActionLoadInit(Actor *arg0, s32 *arg1);
void Stg35_ActionLoadAddSorted(Actor *arg0, s32 arg1, s32 arg2);
void Stg35_ActionLoadUpdate(Actor *arg0);
void Stg35_ActionLoadDestroy(Actor *arg0);

#endif /* STAG3500_ACTIONLOAD_H */
