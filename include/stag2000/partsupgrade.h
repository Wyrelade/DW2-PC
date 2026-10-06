#ifndef STAG2000_PARTSUPGRADE_H
#define STAG2000_PARTSUPGRADE_H

/* Functions src/stag2000/partsupgrade.c defines. */
void Stg20_BuildUpgradeList(Actor *a);
s32 Stg20_CanUpgradePart(s32 item);
void Stg20_UpgradeListRefresh(Actor *a);
void Stg20_PartsUpgradeUpdate(Actor *task);
void Stg20_PartsUpgradeDestroy(Actor *a);
void Stg20_PartsUpgradeDraw(Actor *a);

#endif /* STAG2000_PARTSUPGRADE_H */
