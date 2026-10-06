#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_MsgWinInit(Actor *a, s32 v);
void Stg20_MsgWinUpdate(Actor *a);
void Stg20_MsgWinDestroy(Actor *a);
void Stg20_MsgWinDraw(Actor *a);

TaskDesc Stg20_MsgWinDesc = {
    (TaskInitFn)Stg20_MsgWinInit, Stg20_MsgWinUpdate, Stg20_MsgWinDestroy, Stg20_MsgWinDraw, 0x20, 0,
};

void Stg20_MsgWinInit(Actor *a, s32 v) {
    a->param = v;
}

void Stg20_MsgWinUpdate(Actor *a) {
    Stg20NameWork *w = (Stg20NameWork *)a->work;
    Stg20TextArgs args;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1((s32 *)w, 1);
        Flag_Set(0x10, 0);
        Task_NextState0(a);
        break;
    case 1:
        if (w->msgPending != 0) {
            args.text = w->msgText;
            args.bigFont = 1;
            args.color = 0;
            args.pos.x = 0x10;
            args.pos.y = 0xBA;
            args.charAdvance = 0;
            args.lineAdvance = 0x10;
            args.charDelay = 3;
            args.strArg0 = (s32)w->name;
            Text_Open(w, &args);
            Flag_Set(0x10, 0);
            w->choice = -1;
            w->msgPending = 0;
        }
        if (w->choice == -1 && Flag_Test(0x10) != 0) {
            w->choice = Flag_Test(0x11);
        }
        break;
    case 2:
        break;
    }
}

void Stg20_MsgWinDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

void Stg20_MsgWinDraw(Actor *a) {
    Stg20Part *p;
    Stg20Part *q;
    s32 id;

    id = 0x3120003;
    if (a->param != 0) {
        id = 0x3120001;
    }
    p = (Stg20Part *)Cd_GetFileEntry(id);
    for (q = p; q->fileId != 0; q++) {
        q->field_E = 1;
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_MsgWinClear(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Text_Close((s32 *)e->work);
    }
}

void Stg20_MsgWinShowSkillDesc(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->msgText = Skill_GetDescText(id);
        w->msgPending = 1;
    }
}

void Stg20_MsgWinShowSysMsg(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->msgText = (s32)Cd_GetFileEntry(id + 0x1FD0000);
        w->msgPending = 1;
    }
}

void Stg20_MsgWinShowDigiMsg(s32 text, s32 digi) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20NameWork *w = (Stg20NameWork *)e->work;
        u8 *name = Digi_GetDefaultName(digi);
        s32 i;

        for (i = 0; i < 0xE; i++) {
            w->name[i] = name[i];
        }
        w->msgText = (s32)Cd_GetFileEntry(text + 0x1FD0000);
        w->msgPending = 1;
    }
}

s32 Stg20_MsgWinGetChoice(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        return ((Stg20TextWork *)e->work)->choice;
    }
    return 0;
}
