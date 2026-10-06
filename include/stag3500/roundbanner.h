#ifndef STAG3500_ROUNDBANNER_H
#define STAG3500_ROUNDBANNER_H

/* Functions src/stag3500/roundbanner.c defines. */
void Stg35_RoundBannerInit(Actor *arg0, s32 arg1);
void Stg35_RoundBannerTask(Actor *arg0);
void Stg35_RoundBannerDestroy(Actor *arg0);
void Stg35_RoundBannerDraw(Actor *arg0);
void Stg35_ClearBattle(void);

#endif /* STAG3500_ROUNDBANNER_H */
