#ifndef STAG3000_96DC_FUNCS_H
#define STAG3000_96DC_FUNCS_H

/* Functions src/stag3000/stag3000_96DC.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg30_BuildGuardScript(s32 idx);
s32 Stg30_PrepareAction(s32 idx);
void Stg30_BattleScriptTask(Actor *a0);

#endif /* STAG3000_96DC_FUNCS_H */
