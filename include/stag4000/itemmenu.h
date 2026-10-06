#ifndef STAG4000_ITEMMENU_H
#define STAG4000_ITEMMENU_H

/* Functions src/stag4000/itemmenu.c defines. */
void Stg40_ItemMenuSetCursor();
s32 *Stg40_ItemMenuGetTextIds(void);
void Stg40_ItemMenuInit(Actor *a0, s32 *a1);
void Stg40_ItemMenuUpdate(Actor *a0);
void Stg40_ItemMenuDraw(Actor *a0);

#endif /* STAG4000_ITEMMENU_H */
