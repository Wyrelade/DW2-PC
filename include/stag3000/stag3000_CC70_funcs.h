#ifndef STAG3000_CC70_FUNCS_H
#define STAG3000_CC70_FUNCS_H

/* Functions src/stag3000/stag3000_CC70.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg30_InterruptSelectDraw(Actor *a0);
void Stg30_SetGaugeParts(Stg30Part *p, s32 unit, s32 num, s32 den);
void Stg30_JoinPromptUpdate(Actor *a0);
void Stg30_InitBattle(void);
void Stg30_XaPlayInit(Actor *a0, Vec3 *args);
void Stg30_XaPlayTask(Stg30TaskHead *a0);
void Stg30_XaPlayDestroy(Actor *a0);
s32 Stg30_CamEaseStep(s32 a, s32 b);
void Stg30_CamEaseToward(Stg30Work7343C *w, Stg30CamGoal *g);
void Stg30_CameraUpdate(Actor *arg0);
void Stg30_CameraDraw(Actor *a0);
void Stg30_SetCameraShot(u8 state);
void Stg30_FighterHudInit(Actor *a0, Stg30Ref **args);
void Stg30_FighterHudUpdate(Stg30TaskHead *a0);
void Stg30_FighterHudDestroy(Actor *a0);
void Stg30_FighterHudDraw(Actor *a0);
void Stg30_ResultInit(Actor *a0, Stg30Pair *args);
u8 *Stg30_NumToDigits(u8 *out, s32 n);
void Stg30_LevelUpStats(DigiRosterEntry *e);
void Stg30_ResultUpdate(Actor *a0);
void Stg30_ResultDestroy(Actor *a0);
void Stg30_ResultDraw(Actor *a0);
void Stg30_SkillLearnInit(Actor *a0, Stg30SkillLearnArgs *args);
void Stg30_SkillLearnRefreshList(Actor *a0);
void Stg30_SkillLearnRefreshButtons(Actor *a0);
void Stg30_SkillLearnCompact(Actor *a0, s32 row);
void Stg30_SkillLearnDraw(Actor *a0);
void Stg30_JoinPromptInit(Actor *a0, s32 *args);
void Stg30_JoinCreateDigi(Actor *a0, s32 a1);
void Stg30_JoinPromptDraw(Actor *a0);

#endif /* STAG3000_CC70_FUNCS_H */
