#ifndef MAIN_SKILL_H
#define MAIN_SKILL_H

#include "main/game.h"

/* Functions src/main/skill.c defines. */
EntED40 *Skill_FindById(s32 id);
s32 Skill_GetNameText(s32 arg0);
s32 Skill_GetDescText(s32 arg0);
s32 Skill_GetCastAnim(s32 id);
s32 Skill_GetType(s32 id);
s32 Skill_GetPartsEntry(s32 id);
u8 Skill_GetMpCost(s32 id);
void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
s32 Skill_GetTarget(s32 id);
s16 Skill_GetPower(s32 id);
u16 Skill_GetSpecialty(s32 id);
s32 *Skill_GetShotXa(s32 id);
u8 func_8001F020(s32 id);
s32 func_8001F044(s32 id);
s32 Skill_GetStatusFlags(s32 id);
s32 Skill_GetCureFlags(s32 id);
s32 Skill_GetRank(s32 id);
s32 func_8001F0E4(s32 id);
s32 func_8001F10C(s32 id);
s32 Skill_GetBuffFlags(s32 id);
s32 func_8001F158(s32 id);
s32 func_8001F180(s32 id);

#endif /* MAIN_SKILL_H */
