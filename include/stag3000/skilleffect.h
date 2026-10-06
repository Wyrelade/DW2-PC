#ifndef STAG3000_SKILLEFFECT_H
#define STAG3000_SKILLEFFECT_H

/* Functions src/stag3000/skilleffect.c defines. */
void Stg30_RetargetAction(void);
s32 Stg30_CompareSpecialty(s32 a, s32 b);
s32 Stg30_GetFloorSpecialty(void);
s32 Stg30_ApplySkillStatus(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5);
void Stg30_StatDebuff(s16 *max, s16 *b, s16 *c);
void Stg30_StatBuff(s16 *max, s16 *b, s16 *c);
s32 Stg30_SkillHitCheck(s32 idx, s16 *tgt, s32 n, s32 id);

#endif /* STAG3000_SKILLEFFECT_H */
