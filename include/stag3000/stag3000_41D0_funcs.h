#ifndef STAG3000_41D0_FUNCS_H
#define STAG3000_41D0_FUNCS_H

/* Functions src/stag3000/stag3000_41D0.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg30_BattleWonUpdate(Actor *a0);
void Stg30_SetDigiAction(Actor *a0, s32 a1, s32 a2);
void Stg30_ShowPartyFighters(Stg30ListOwner *a0);
void Stg30_ShowAllFighters(Stg30ListOwner *a0);
void Stg30_ResetAllFightersHome(Stg30ListOwner *a0);
s32 Stg30_HasSkillOrNew(Stg30IdSet *a0, s16 *a1, u8 id);
s32 Stg30_RankCanLearnSkill(s32 a0, u8 a1);
void Stg30_BattleLostUpdate(Stg30ListOwner *a0);
void Stg30_ResetPartyStats(void);
void Stg30_BattleUpdate(Actor *a0);

#endif /* STAG3000_41D0_FUNCS_H */
