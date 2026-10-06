#ifndef STAG3000_SKILLMENU_H
#define STAG3000_SKILLMENU_H

/* Functions src/stag3000/skillmenu.c defines. */
void Stg30_SkillMenuBuildLists(void);
void Stg30_OpenSkillText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
void Stg30_SkillMenuUpdate(Actor *a0);
void Stg30_SkillMenuDraw(Actor *a0);

#endif /* STAG3000_SKILLMENU_H */
