#ifndef STAG2000_BEETLEPARTS_H
#define STAG2000_BEETLEPARTS_H

/* Functions src/stag2000/beetleparts.c defines. */
void Stg20_FilterPartsList(Actor *a, s32 mode);
void Stg20_OpenMsgOrDesc(void *t, s32 id, Halves pos, s32 arg);
void Stg20_PartsListToBag(Actor *a);
void Stg20_GatherPartsList(Actor *a);
s32 Stg20_PartsListHas(Actor *a, s32 v);
void Stg20_PartsListRemove(Actor *a, s32 v);
void Stg20_InsertDescS16(s16 *list, s32 n, s32 v);
void Stg20_PartsListRefresh(Actor *a);
void Stg20_BeetlePartsDestroy(Actor *a);
void Stg20_BeetlePartsDraw(Actor *a);
void Stg20_BeetlePartsUpdate(Actor *a);

#endif /* STAG2000_BEETLEPARTS_H */
