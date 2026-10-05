#ifndef MAIN_SKILLLIST_H
#define MAIN_SKILLLIST_H

#include "main/game.h"

/* Functions src/main/skilllist.c defines. */
void Menu_SkillListBuildTabs();
void Menu_SkillListOpenNames(Actor194C8 *w, s32 arg1);
void Menu_SkillListInit(Actor *arg0, s16 arg1);
void Menu_SkillListTask(Actor *a0);
void Menu_SkillListDraw(Actor *actor);

#endif /* MAIN_SKILLLIST_H */
