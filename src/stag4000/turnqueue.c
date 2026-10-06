#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/enemy.h"
#include "stag4000/entity.h"
#include "stag4000/spawn.h"
#include "stag4000/automap.h"
#include "stag4000/turnqueue.h"

void Stg40_TurnQueueReset(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;
    s16 *q = p->ids;
    s32 i;

    p->capacity = 10;
    p->count = 0;
    p->cursor = 0;
    for (i = 0; i < p->capacity; i++) {
        *q++ = -1;
    }
    *q = -2;
}

s16 *Stg40_TurnQueueFind(s16 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;
    s16 *p = f->ids;

    while (*p != -2) {
        if (*p == v) {
            return p;
        }
        p++;
    }
    return NULL;
}

void Stg40_TurnQueueAdd(s32 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;

    if (Stg40_TurnQueueFind(v) == NULL && f->count < f->capacity) {
        f->ids[f->count] = v;
        f->count++;
    }
}

void Stg40_TurnQueueRemove(s16 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;
    s16 *p = Stg40_TurnQueueFind(v);
    s16 *q;

    if (p != NULL) {
        for (q = p + 1; *q != -2;) {
            *p++ = *q++;
        }
        *p = -1;
        f->count--;
        if (f->ids[f->cursor] == -1) {
            f->cursor = 0;
        }
    }
}

s16 Stg40_TurnQueueNext(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;

    p->cursor = (p->cursor + 1 < p->count) ? p->cursor + 1 : 0;
    return p->ids[p->cursor];
}

s16 Stg40_TurnQueueCurrent(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;

    return p->ids[p->cursor];
}
