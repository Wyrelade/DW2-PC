#ifndef STAG3500_BATTLE_H
#define STAG3500_BATTLE_H

/* Functions src/stag3500/battle.c defines. */
void Stg35_SetDigiAction(Actor *arg0, s32 arg1, s32 arg2);
void Stg35_ShowWinnerSide(Stg35ChildOwner *arg0, s32 arg1);
void Stg35_ShowAllDigi(Stg35ChildOwner *arg0);
void Stg35_BattleUpdate(Actor *arg0);
void Stg35_BattleDestroy(Actor *arg0);

#endif /* STAG3500_BATTLE_H */
