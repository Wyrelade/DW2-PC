#ifndef STAG3000_ITEMMENU_H
#define STAG3000_ITEMMENU_H

/* Functions src/stag3000/itemmenu.c defines. */
void Stg30_ItemMenuUpdate(Actor *a0);
void Stg30_ItemMenuBuildLists(Actor *a0);
void Stg30_OpenItemText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
s32 Stg30_ItemToSkillId(s32 c);
void Stg30_ItemMenuInit(Actor *a0, s32 *args);
void Stg30_ItemMenuDraw(Actor *a0);

#endif /* STAG3000_ITEMMENU_H */
