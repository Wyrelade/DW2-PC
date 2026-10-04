#ifndef STAG3500_FUNCS_H
#define STAG3500_FUNCS_H

/* Functions src/stag3500/stag3500.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg35_VsMenuUpdate(Actor *arg0);
void Stg35_BgUpdate(Actor *arg0);
void Stg35_BgDestroy(Actor *arg0);
void Stg35_BgDraw(Actor *arg0);
void Stg35_FightBgUpdate(Actor *arg0);
void Stg35_FightBgDraw(Actor *arg0);
void Stg35_ActionLoadInit(Actor *arg0, s32 *arg1);
void Stg35_ActionLoadAddSorted(Actor *arg0, s32 arg1, s32 arg2);
void Stg35_ActionLoadUpdate(Actor *arg0);
void Stg35_ActionLoadDestroy(Actor *arg0);
void Stg35_RootUpdate(Actor *arg0);
void Stg35_VsMenuDestroy(Actor *arg0);
void Stg35_VsMenuDraw(Actor *arg0);
void Stg35_MatchupUpdate(Actor *arg0);
void Stg35_MatchupDestroy(Actor *arg0);
void Stg35_MatchupDraw(Actor *arg0);
void Stg35_SetDigiAction(Actor *arg0, s32 arg1, s32 arg2);
void Stg35_ShowWinnerSide(Stg35ChildOwner *arg0, s32 arg1);
void Stg35_ShowAllDigi(Stg35ChildOwner *arg0);
void Stg35_BattleUpdate(Actor *arg0);

#endif /* STAG3500_FUNCS_H */
