#ifndef STAG3000_SKILLLEARN_H
#define STAG3000_SKILLLEARN_H

/* Functions src/stag3000/skilllearn.c defines. */
void Stg30_SkillLearnInit(Actor *a0, Stg30SkillLearnArgs *args);
void Stg30_SkillLearnRefreshList(Actor *a0);
void Stg30_SkillLearnRefreshButtons(Actor *a0);
void Stg30_SkillLearnCompact(Actor *a0, s32 row);
void Stg30_SkillLearnDraw(Actor *a0);
void Stg30_SkillLearnUpdate(Actor *a0);

#endif /* STAG3000_SKILLLEARN_H */
