#ifndef STAG4000_TURNQUEUE_H
#define STAG4000_TURNQUEUE_H

/* Functions src/stag4000/turnqueue.c defines. */
void Stg40_TurnQueueReset(void);
s16 *Stg40_TurnQueueFind(s16 v);
void Stg40_TurnQueueAdd(s32 v);
void Stg40_TurnQueueRemove(s16 v);
s16 Stg40_TurnQueueNext(void);
s16 Stg40_TurnQueueCurrent(void);

#endif /* STAG4000_TURNQUEUE_H */
