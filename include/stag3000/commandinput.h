#ifndef STAG3000_COMMANDINPUT_H
#define STAG3000_COMMANDINPUT_H

/* Functions src/stag3000/commandinput.c defines. */
void Stg30_DimFightersExcept(s32 sel, s32 from, s32 to);
void Stg30_UndimPartyFighters(void);
void Stg30_CommandInputTask(Actor *a0);

#endif /* STAG3000_COMMANDINPUT_H */
