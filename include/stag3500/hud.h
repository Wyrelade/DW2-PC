#ifndef STAG3500_HUD_H
#define STAG3500_HUD_H

/* Functions src/stag3500/hud.c defines. */
void Stg35_HudUpdateSkillList(Actor *arg0);
void Stg35_HudUpdateGaugeColumn(Actor *arg0, s32 arg1);
void Stg35_HudUpdateGaugeBar(Actor *arg0, s32 arg1);
void Stg35_BattleHudDestroy(Actor *arg0);
void Stg35_BattleHudDraw(Actor *arg0);
void Stg35_HudStartGauge(s32 arg0, s32 *arg1);
s32 Stg35_HudGetGaugeStatus(void);
void Stg35_HudSyncHp(void);
s32 Stg35_HudGetGaugeLevel(void);
s32 Stg35_HudPeekGaugeLevel(s32 arg0);
void Stg35_BattleHudTask(Actor *arg0);

#endif /* STAG3500_HUD_H */
