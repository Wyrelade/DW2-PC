#ifndef STAG3000_BATTLE_H
#define STAG3000_BATTLE_H

/* Functions src/stag3000/battle.c defines. */
void Stg30_BattleWonUpdate(Actor *a0);
void Stg30_SetDigiAction(Actor *a0, s32 a1, s32 a2);
void Stg30_ShowPartyFighters(Stg30ListOwner *a0);
void Stg30_ShowAllFighters(Stg30ListOwner *a0);
void Stg30_ResetAllFightersHome(Stg30ListOwner *a0);
s32 Stg30_HasSkillOrNew(DigiRosterEntry *a0, s16 *a1, u8 id);
s32 Stg30_RankCanLearnSkill(s32 a0, u8 a1);
void Stg30_BattleLostUpdate(Stg30ListOwner *a0);
void Stg30_ResetPartyStats(void);
void Stg30_BattleUpdate(Actor *a0);
void Stg30_BattleDestroy(Actor *a0);

#endif /* STAG3000_BATTLE_H */
