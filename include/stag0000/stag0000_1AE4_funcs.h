#ifndef STAG0000_1AE4_FUNCS_H
#define STAG0000_1AE4_FUNCS_H

/* Functions src/stag0000/stag0000_1AE4.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg00_FontInit(void);
void Stg00_DigiViewTask(Actor *arg0);
void Stg00_DigiViewDraw(Actor *arg0);
void Stg00_SpawnRandomGroup(Actor *arg0);
void func_80064E44(void);
void Stg00_FontSetColor(s16 arg0);
void Stg00_FontFree(void);
void Stg00_FontDrawStr(s32 arg0, s32 arg1, u8 *arg2);
void Stg00_FontDrawSheet(void);
void Stg00_FontPrintBuf(s32 arg0, s32 arg1);
void Stg00_FontPrintBufCentered(s32 arg0, s32 arg1);
void Stg00_FightBgTask(Actor *arg0);
void Stg00_FightBgDraw(Actor *arg0);
void Stg00_DigiViewSpawnModel(Actor *arg0);
void Stg00_LineupSetVideoMode(Actor *arg0);
void Stg00_LineupSpawnModels(Actor *arg0);
void Stg00_LineupBuildList(Actor *arg0);
void Stg00_LineupTask(Actor *arg0);
void Stg00_LineupDraw(Actor *arg0);
void Stg00_VideoModeTask(Actor *arg0);
void Stg00_GroupViewSetVideoMode(Actor *arg0);
void Stg00_GroupViewTask(Actor *arg0);

#endif /* STAG0000_1AE4_FUNCS_H */
