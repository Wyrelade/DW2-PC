#ifndef STAG3000_BATTLESCRIPT_H
#define STAG3000_BATTLESCRIPT_H

/* Functions src/stag3000/battlescript.c defines. */
void Stg30_BuildGuardScript(s32 idx);
s32 Stg30_PrepareAction(s32 idx);
void Stg30_BattleScriptTask(Actor *a0);

#endif /* STAG3000_BATTLESCRIPT_H */
