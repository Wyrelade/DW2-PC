#ifndef STAG3000_100C_FUNCS_H
#define STAG3000_100C_FUNCS_H

/* Functions src/stag3000/stag3000_100C.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg30_CommandMenuUpdate(Actor *a0);
void Stg30_ItemMenuUpdate(Actor *a0);
void Stg30_DimFightersExcept(s32 sel, s32 from, s32 to);
void Stg30_UndimPartyFighters(void);
void Stg30_CommandInputTask(Actor *a0);
void Stg30_CommandMenuDestroy(Actor *a0);
void Stg30_CommandMenuDraw(Actor *a0);
void Stg30_ItemMenuBuildLists(Actor *a0);
void Stg30_OpenItemText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
s32 Stg30_ItemToSkillId(s32 c);
void Stg30_ItemMenuInit(Actor *a0, s32 *args);
void Stg30_SkillMenuBuildLists(void);
void Stg30_OpenSkillText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
void Stg30_SkillMenuUpdate(Actor *a0);
void Stg30_SkillMenuDraw(Actor *a0);
void Stg30_TargetSelectUpdate(Actor *a0);
void Stg30_TargetSelectDraw(Actor *a0);

#endif /* STAG3000_100C_FUNCS_H */
