#ifndef STAG3000_JOINPROMPT_H
#define STAG3000_JOINPROMPT_H

/* Functions src/stag3000/joinprompt.c defines. */
void Stg30_JoinPromptUpdate(Actor *a0);
void Stg30_JoinPromptInit(Actor *a0, s32 *args);
void Stg30_JoinCreateDigi(Actor *a0, s32 a1);
void Stg30_JoinPromptDraw(Actor *a0);

#endif /* STAG3000_JOINPROMPT_H */
