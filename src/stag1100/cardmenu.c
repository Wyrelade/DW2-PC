#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/cardmenu.h"
#include "stag1100/stag1100_301C_funcs.h"

Halves Stg11_PromptPos = { 0x10, 0xBA };
Halves Stg11_StatusPos = { 0x56, 0x4E };
Halves Stg11_TransferCountPos = { 0x61, 0xA4 };
TaskDesc Stg11_CardMenuDesc = {
    (TaskInitFn)Stg11_CardMenuInit, Stg11_CardMenuUpdate, Task_DefaultDestroy, Stg11_CardMenuDraw, 0x13C, 4,
};

/* Unnamed: empty stub, no callers, no table ref. */
void func_80063D20(void) {
}

void Stg11_ConvertCardDigi(Stg11MenuRow *arg0, Stg11CardRec *arg1) {
    s16 *skillTbl = (s16 *)Cd_GetFileEntry(0xD28000E);
    Stg11SpeciesRec *t = (Stg11SpeciesRec *)Cd_GetFileEntry(0xD280010);
    s32 i;

    t += Digi_GetRank(arg0->digiId);
    arg0->level = t->level;
    arg0->maxLevel = Digi_CalcMaxLevel(arg0->level);
    arg0->exp = t->exp;
    arg0->hp = t->base + arg1->hp / 20;
    if (t->hpMax < arg0->hp) {
        arg0->hp = t->hpMax;
    }
    arg0->mp = t->base + arg1->mp / 20;
    if (t->hpMax < arg0->mp) {
        arg0->mp = t->hpMax;
    }
    arg0->attack = arg1->attack / 7;
    if (t->statMax < arg0->attack) {
        arg0->attack = t->statMax;
    }
    if (arg0->attack == 0) {
        arg0->attack = 1;
    }
    arg0->defense = arg1->defense / 7;
    if (t->statMax < arg0->defense) {
        arg0->defense = t->statMax;
    }
    if (arg0->defense == 0) {
        arg0->defense = 1;
    }
    arg0->speed = arg1->speed / 10;
    if (t->speedMax < arg0->speed) {
        arg0->speed = t->speedMax;
    }
    if (arg0->speed == 0) {
        arg0->speed = 1;
    }
    arg0->uid = arg1->uid;
    arg0->skillCount = 0;
    for (i = 0; i < arg1->skillCount; i++) {
        if (arg1->skills[i] < 0x78 && skillTbl[arg1->skills[i]] != 0) {
            arg0->skills[arg0->skillCount++] = skillTbl[arg1->skills[i]];
        }
    }
    if (arg0->skillCount == 0) {
        arg0->skills[0] = Digi_GetLearnedSkill(arg0->digiId);
        arg0->skillCount = 1;
    }
}

void Stg11_ScanTransferCards(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11CardRec *p = (Stg11CardRec *)Stg11_CardGetTransferBuf();
    s16 *tbl = (s16 *)Cd_GetFileEntry(0xD28000F);
    Stg11MenuRow *c = arg1->transferRows;
    Stg11CardRec *rec;
    s16 maxLv;
    s32 i;
    s32 j;
    s32 n;
    s32 sum;

    p = ((Stg11CardArea *)p)->cards;
    arg1->transferRemaining = 0x18;
    maxLv = 0;
    for (i = 0; i < 0x24; i++) {
        if (Save_GameStatePtr->elems[i].state == 1) {
            arg1->transferRemaining--;
        }
        if (Save_GameStatePtr->elems[i].state != 0 && maxLv < Digi_GetRank(Save_GameStatePtr->elems[i].digiId)) {
            maxLv = Digi_GetRank(Save_GameStatePtr->elems[i].digiId);
        }
    }
    n = 0;
    for (i = 0; i < 5; i++, p++, c++) {
        rec = p;
        c->digiId = 0;
        c->transferState = 0;
        for (sum = j = 0; j < 0x80; j++) {
            sum += rec->bytes[j];
        }
        if (sum == 0x880 && (rec->field_BD & 0xF) && rec->speciesId < 0x100 && tbl[rec->speciesId] != 0
            && rec->field_80 != -1 && rec->field_80 >= 0x780) {
            for (j = 0; j < i; j++) {
                if (arg1->transferRows[j].digiId != 0 && arg1->transferRows[j].uid == rec->uid) {
                    break;
                }
            }
            if (j == i) {
                c->digiId = tbl[rec->speciesId];
                for (j = 0; j < 0x24; j++) {
                    if (((Stg11GameState *)Save_GameStatePtr)->elems[j].state != 0 && ((Stg11GameState *)Save_GameStatePtr)->elems[j].isTransferred != 0 && ((Stg11GameState *)Save_GameStatePtr)->elems[j].transferUid == rec->uid) {
                        c->transferState = 1;
                    }
                }
                if (maxLv < Digi_GetRank(c->digiId)) {
                    c->transferState = 2;
                }
                if (c->transferState == 0) {
                    n++;
                }
                Stg11_ConvertCardDigi(c, rec);
            }
        }
    }
    if (n < arg1->transferRemaining) {
        arg1->transferRemaining = n;
    }
}

void Stg11_OpenTransferText(Actor *arg0, Stg11MenuWork *arg1) {
    Halves *pos = (Halves *)Cd_GetFileEntry(0xD28000C);
    Stg11MenuRow *row = arg1->transferRows;
    TextDescHalves st;
    s32 i;

    Text_CloseArray(arg1->transferTexts, 11);
    st.strArg0 = 0;
    st.packedStyle = 0;
    st.color = 0;
    for (i = 0; i < 5; i++, row++) {
        st.pos = *pos++;
        st.text = row->digiId == 0 ? (s32)Cd_GetFileEntry(0x1FD0098)
                                    : (s32)Digi_GetDefaultName(row->digiId);
        Text_OpenDesc(&arg1->transferTexts[i * 2], (TextDesc *)&st);
        st.pos = *pos++;
        if (row->digiId != 0 && row->transferState != 0) {
            if (row->transferState == 1) {
                st.text = (s32)Cd_GetFileEntry(0x1FD01B2);
            } else {
                st.text = (s32)Cd_GetFileEntry(0x1FD01B7);
            }
            Text_OpenDesc(&arg1->transferTexts[i * 2 + 1], (TextDesc *)&st);
        }
    }
    st.pos = Stg11_TransferCountPos;
    st.text = (s32)Cd_GetFileEntry(arg1->transferRemaining + 0x1FD01BD);
    Text_OpenDesc(&arg1->transferCountText, (TextDesc *)&st);
}

void Stg11_TransferSelected(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11MenuRow *c = &arg1->transferRows[Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize)];
    Stg11DigiEntry *e = (Stg11DigiEntry *)Save_GameStatePtr->elems;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg1->transferRemaining == 0 || c->digiId == 0 || c->transferState != 0) {
        Snd_PlayById(0x10, 0);
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (e[i].state == 0) {
            break;
        }
    }
    if (i == 0x24) {
        Snd_PlayById(0x10, 0);
        return;
    }
    e += i;
    memset((u8 *)e, 0, 0x5C);
    e->state = 1;
    e->digiId = c->digiId;
    e->level = c->level;
    e->dp = 0;
    e->maxLevel = c->maxLevel;
    e->exp = c->exp;
    e->maxHp = c->hp;
    e->hp = c->hp;
    e->maxMp = c->mp;
    e->mp = c->mp;
    e->attack = c->attack;
    e->defense = c->defense;
    e->speed = c->speed;
    src = Digi_GetDefaultName(e->digiId);
    dst = e->name;
    while (*src != 0xFF) {
        *dst++ = *src++;
    }
    *dst = 0xFF;
    for (i = 0; i < c->skillCount; i++) {
        e->skills[i] = c->skills[i];
    }
    e->isTransferred = 1;
    e->transferUid = c->uid;
    arg1->transferRemaining--;
    c->transferState = 1;
    Stg11_OpenTransferText(arg0, arg1);
    Stg11_SetPromptMsg(arg1, 0x110, 1);
    Snd_PlayById(0xE, 0);
}

void Stg11_OpenSlotText(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list = arg1->saveList;
    Halves *pos = (Halves *)Cd_GetFileEntry(0xD28000B);
    TextDescHalves st;
    Stg11SaveSlot *slot;
    s32 i;

    st.strArg0 = 0;
    st.packedStyle = 0;
    st.color = 0;
    for (i = 0; i < 3; i++) {
        if (list->used[i] != 0) {
            st.pos = *pos++;
            slot = &list->slots[i];
            st.text = (s32)slot->u.gs.field_14;
            Text_OpenDesc(&arg1->slotTexts[i * 3], (TextDesc *)&st);
            st.pos = *pos++;
            st.text = (s32)Cd_GetFileEntry(((s16 *)Cd_GetFileEntry(0x513000F))[slot->u.gs.field_11 * 11 + slot->u.gs.field_12] + 0x1FD0000);
            Text_OpenDesc(&arg1->slotTexts[i * 3 + 1], (TextDesc *)&st);
        } else {
            st.pos = *pos++;
            st.text = (s32)Cd_GetFileEntry(0x1FD0098);
            Text_OpenDesc(&arg1->slotTexts[i * 3], (TextDesc *)&st);
            st.pos = *pos++;
            Text_OpenDesc(&arg1->slotTexts[i * 3 + 1], (TextDesc *)&st);
        }
        st.pos = *pos++;
        do {
            st.text = (s32)Cd_GetFileEntry(0x1FD005F);
            Text_OpenDesc(&arg1->slotTexts[i * 3 + 2], (TextDesc *)&st);
        } while (0);
    }
}

void Stg11_CloseSlotText(Actor *arg0, Stg11MenuWork *arg1) {
    Text_CloseArray(arg1->slotTexts, 9);
    arg1->listMode = 0;
}

void Stg11_SetStatusMsg(Stg11MenuWork *arg0, s32 arg1) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->statusText);
    } else {
        st.pos = Stg11_StatusPos;
        st.packedStyle = 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->statusText, (TextDesc *)&st);
    }
}

void Stg11_SetPromptMsg(Stg11MenuWork *arg0, s32 arg1, s32 arg2) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->promptText);
    } else {
        st.pos = Stg11_PromptPos;
        st.packedStyle = arg2 - 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->promptText, (TextDesc *)&st);
    }
}

s32 Stg11_IsPromptFinished(Stg11MenuWork *arg0) {
    return Text_IsFinished(arg0->promptText);
}

s32 Stg11_WatchCardRemoved(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r = 0;
    s32 v = Stg11_CardGetResult();

    if (v != -1) {
        if (v == 0) {
            Task_SetState1(arg0, 3);
            r = -1;
        } else {
            Stg11_CardStartOp(4, arg1->cardPort);
        }
    }
    return r;
}

void Stg11_StateWaitCancel(Actor *arg0, Stg11MenuWork *arg1) {
    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) == 0) {
        arg0->stateLevel2 = 1;
        if (Pad_State[arg1->padIndex].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState0(arg0, 2);
        }
    }
}

void Stg11_StateCardError(Actor *arg0, Stg11MenuWork *arg1) {
    s32 msg;

    switch (arg0->stateLevel2) {
    case 0:
        msg = 0;
        switch (Stg11_CardGetResult()) {
        case 1:
            msg = arg1->isLoad == 0 ? 0x16D : 0x16E;
            break;
        case 4:
            msg = 0x183;
            break;
        case 5:
            msg = 0x182;
            break;
        case 6:
            msg = 0x171;
            break;
        case 7:
            msg = 0x194;
            break;
        case 8:
            msg = 0x16F;
            break;
        case 10:
            msg = 0x16E;
            break;
        case 11:
            msg = arg1->isTransfer != 0 ? 0x1B1 : 0x186;
            break;
        }
        Stg11_SetStatusMsg(arg1, msg);
        Stg11_CloseSlotText(arg0, arg1);
        Stg11_CardStartOp(4, arg1->cardPort);
        Task_NextState2(arg0);
        break;
    case 1:
        if (Pad_State[arg1->padIndex].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState0(arg0, 2);
            return;
        }
        break;
    }
    Stg11_WatchCardRemoved(arg0, arg1);
}

void Stg11_StateCheckCard(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        Stg11_SetPromptMsg(arg1, arg1->pendingPromptMsg, 1);
        arg1->pendingPromptMsg = 0;
        arg1->listMode = 0;
        Stg11_CloseSlotText(arg0, arg1);
        Task_SetState2(arg0, 0xA);
    case 10:
        Stg11_CardStartOp(2, arg1->cardPort);
        Task_NextState2(arg0);
        break;
    case 11:
        switch (Stg11_CardGetResult()) {
        case -1:
            break;
        case 2:
            Stg11_SetStatusMsg(arg1, arg1->isTransfer ? 0x1AD : 0x16B);
            Task_SetState2(arg0, 0x14);
            break;
        case 0:
            Stg11_SetStatusMsg(arg1, arg1->cardPort + (arg1->isTransfer ? 0x1AE : 0x180));
            Task_SetState2(arg0, 0xA);
            break;
        }
        break;
    case 20:
        Stg11_CardStartOp(4, arg1->cardPort);
        Task_NextState2(arg0);
        break;
    case 21:
        switch (Stg11_CardGetResult()) {
        case -1:
            break;
        case 2:
            Task_SetState2(arg0, 0x1E);
            break;
        case 0:
            Stg11_SetStatusMsg(arg1, arg1->cardPort + (arg1->isTransfer ? 0x1AE : 0x180));
            Task_SetState2(arg0, 0xA);
            break;
        case 1:
            if (arg1->isLoad != 0) {
                Task_SetState1(arg0, 2);
            } else {
                Task_SetState1(arg0, 9);
            }
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        }
        break;
    case 30:
        Stg11_CardStartOp(5, arg1->cardPort);
        Task_NextState2(arg0);
        break;
    case 31:
        switch (Stg11_CardGetResult()) {
        case -1:
            break;
        case 9:
            Task_SetState1(arg0, 6);
            break;
        case 10:
            if (arg1->isLoad != 0) {
                Task_SetState1(arg0, 2);
            } else {
                Task_SetState1(arg0, 4);
            }
            break;
        case 0:
            Task_SetState2(arg0, 0xA);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        }
        break;
    }
    if (Pad_State[arg1->padIndex].triangle > 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(arg0, 2);
    }
}

void Stg11_StateAskFormat(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) == 0) {
        switch (arg0->stateLevel2) {
        case 0:
        default:
            Stg11_SetStatusMsg(arg1, 0x16D);
            Stg11_SetPromptMsg(arg1, 0x177, 1);
            Task_NextState2(arg0);
            break;
        case 1:
            r = Text_WaitYesNo(arg1->promptText);
            if (r != -1) {
                if (r == 1) {
                    Task_SetState0(arg0, 2);
                }
            } else {
                Task_SetState1(arg0, 10);
            }
            break;
        }
    }
}

void Stg11_StateFormat(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    switch (arg0->stateLevel2) {
    case 0:
        Stg11_SetStatusMsg(arg1, 0x193);
        Stg11_SetPromptMsg(arg1, 0, 0);
        Stg11_CardStartOp(6, arg1->cardPort);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->progressMode = 0;
        r = Stg11_CardGetResult();
        switch (r) {
        case 0:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 0x10:
            Task_SetState1(arg0, 4);
            break;
        case -1:
            break;
        }
        break;
    }
}

void Stg11_StateAskCreate(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) == 0) {
        switch (arg0->stateLevel2) {
        case 0:
        default:
            Stg11_SetStatusMsg(arg1, 0x16E);
            Stg11_SetPromptMsg(arg1, 0x176, 1);
            Task_NextState2(arg0);
            break;
        case 1:
            r = Text_WaitYesNo(arg1->promptText);
            if (r != -1) {
                if (r == 1) {
                    Task_SetState1(arg0, 5);
                }
            } else {
                Task_SetState0(arg0, 2);
            }
            break;
        }
    }
}

void Stg11_StateCreateFile(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        Stg11_CardInitHeader();
        Stg11_CardStartOp(7, arg1->cardPort);
        Stg11_SetStatusMsg(arg1, 0x184);
        Stg11_SetPromptMsg(arg1, 0, 0);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->progressMode = 0;
        switch (Stg11_CardGetResult()) {
        case -1:
            arg1->progressMode = 2;
            arg1->progress = Stg11_CardGetProgress(0x80);
            break;
        case 0:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 9:
            Stg11_CardStartOp(8, arg1->cardPort);
            Task_NextState2(arg0);
            break;
        }
        break;
    case 2:
        arg1->progressMode = 0;
        switch (Stg11_CardGetResult()) {
        case -1:
            arg1->progressMode = 2;
            arg1->progress = Stg11_CardGetProgress(0x80);
            break;
        case 0:
        case 0xF:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 0xC:
            Task_SetState1(arg0, 7);
            break;
        }
        break;
    }
}

void Stg11_StateReadFile(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list;
    Stg11SaveSlot *slot;
    s32 i;
    s32 j;

    switch (arg0->stateLevel2) {
    case 0:
        Stg11_CardStartOp(9, arg1->cardPort);
        Stg11_SetStatusMsg(arg1, arg1->isTransfer ? 0x1B0 : 0x185);
        Stg11_SetPromptMsg(arg1, 0, 0);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->progressMode = 0;
        switch (Stg11_CardGetResult()) {
        case -1:
            arg1->progressMode = 2;
            arg1->progress = Stg11_CardGetProgress(0x80);
            break;
        case 0:
        case 15:
            arg1->pendingPromptMsg = arg1->isLoad ? 0x183 : 0;
            Task_SetState1(arg0, 3);
            break;
        default:
            arg1->pendingPromptMsg = arg1->isLoad ? 0x183 : 0;
            Task_SetState1(arg0, 2);
            break;
        case 14:
            Stg11_CardInitHeader();
            Task_SetState1(arg0, 7);
            break;
        case 13:
            if (arg1->isTransfer != 0) {
                Task_SetState1(arg0, 0xC);
                break;
            }
            list = arg1->saveList;
            for (i = 0; i < 3; i++) {
                slot = &list->slots[i];
                if (list->used[i] != 0) {
                    for (j = 0; j < 0x24; j++) {
                        if (slot->u.gs.elems[j].state != 0) {
                            slot->u.gs.elems[j].name[13] = 0xFF;
                        }
                    }
                    slot->u.gs.field_14[5] = 0xFF;
                    slot->u.gs.field_D1[7] = 0xFF;
                }
            }
            Task_SetState1(arg0, 7);
            break;
        }
        break;
    }
}

void Stg11_StateSelectSlot(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list = arg1->saveList;
    Stg11SaveSlot *slot;
    DigiRosterEntry *e;
    s32 idx;
    s32 idx2;
    s32 msg;
    s32 r;
    s32 i;
    s32 n;

    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) != 0) {
        return;
    }
    switch (arg0->stateLevel2) {
    case 0:
    default:
        Stg11_SetStatusMsg(arg1, 0);
        msg = 0x170;
        if (arg1->isLoad == 0) {
            msg = 0x172;
        }
        if (arg1->isVsLoad != 0) {
            msg = 0x1A8;
        }
        Stg11_SetPromptMsg(arg1, msg, 1);
        arg1->listMode = 1;
        Stg11_OpenSlotText(arg0, arg1);
        Task_NextState2(arg0);
        break;
    case 1:
        if (Menu_MoveGridCursor(arg1->cursor, arg1->u6C.gridSize, arg1->padIndex) == 0) {
            if (Pad_State[arg1->padIndex].cross > 0) {
                idx = Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize);
                if (arg1->isLoad == 0) {
                    if (list->used[idx] == 0) {
                        list->used[idx] = Sys_State.prevGameMode;
                        *(list->slots + idx) = *(Stg11SaveSlot *)Save_GameStatePtr;
                        Stg11_OpenSlotText(arg0, arg1);
                        Task_SetState1(arg0, 8);
                        Snd_PlayById(0xE, 0);
                    } else {
                        Stg11_SetPromptMsg(arg1, 0x175, 1);
                        Task_NextState2(arg0);
                        Snd_PlayById(0xE, 0);
                    }
                } else {
                    if (list->used[idx] == 0) {
                        Snd_PlayById(0x10, 0);
                    } else {
                        if (arg1->isVsLoad == 0) {
                            *(Stg11SaveSlot *)Save_GameStatePtr = *(list->slots + idx);
                            Stg11_LoadDone = 1;
                            Sys_State.prevGameMode = list->used[idx];
                            Task_SetState0(arg0, 2);
                            Snd_PlayById(0xE, 0);
                        } else {
                            slot = &list->slots[idx];
                            e = slot->u.gs.elems;
                            Stg11_VsParty.gameState = &slot->u.gs;
                            for (n = i = 0; i < 3; i++, e++) {
                                Stg11_VsParty.members[i].state = 0;
                                if (e->state >= 3) {
                                    Stg11_VsParty.members[n] = *e;
                                    n++;
                                }
                            }
                            if (n < 3) {
                                Snd_PlayById(0x10, 0);
                                Stg11_SetPromptMsg(arg1, 0x1AB, 1);
                            } else {
                                Snd_PlayById(0xE, 0);
                                Task_SetState1(arg0, 0xB);
                            }
                        }
                    }
                }
            } else if (Pad_State[arg1->padIndex].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(arg0, 2);
            }
        } else {
            Snd_PlayById(0xD, 0);
            msg = 0x170;
            if (arg1->isLoad == 0) {
                msg = 0x172;
            }
            if (arg1->isVsLoad != 0) {
                msg = 0x1A8;
            }
            Stg11_SetPromptMsg(arg1, msg, 0);
        }
        break;
    case 2:
        r = Text_WaitYesNo(arg1->promptText);
        if (r != -1) {
            if (r == 1) {
                idx2 = Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize);
                list->used[idx2] = Sys_State.prevGameMode;
                *(list->slots + idx2) = *(Stg11SaveSlot *)Save_GameStatePtr;
                Stg11_OpenSlotText(arg0, arg1);
                Task_SetState1(arg0, 8);
            }
        } else {
            msg = 0x170;
            if (arg1->isLoad == 0) {
                msg = 0x172;
            }
            Stg11_SetPromptMsg(arg1, msg, 1);
            Task_SetState2(arg0, 1);
        }
        break;
    }
}

void Stg11_StateWriteSave(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        Stg11_CardStartOp(8, arg1->cardPort);
        Stg11_SetPromptMsg(arg1, 0x173, 1);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->progressMode = 0;
        switch (Stg11_CardGetResult()) {
        case -1:
            arg1->progressMode = 2;
            arg1->progress = Stg11_CardGetProgress(0x80);
            break;
        case 0:
        case 0xF:
            arg1->pendingPromptMsg = 0x182;
            Task_SetState1(arg0, 3);
            break;
        default:
            arg1->pendingPromptMsg = 0x182;
            Task_SetState1(arg0, 2);
            break;
        case 0xC:
            Stg11_CardStartOp(4, arg1->cardPort);
            Stg11_SetPromptMsg(arg1, 0x174, 1);
            Task_NextState2(arg0);
            break;
        }
        break;
    case 2:
        if (Stg11_WatchCardRemoved(arg0, arg1) == 0) {
            if (arg0->stateLevel3++ >= 0x3C) {
                Task_SetState1(arg0, 7);
            }
        }
        break;
    }
}

void Stg11_StateVsPartySelect(Actor *arg0, Stg11MenuWork *arg1) {
    s32 *slot = (s32 *)arg0->u34.children;
    DigiRosterEntry *d;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) != 0) {
        if (*slot != 0) {
            Task_SetState0((Actor *)*slot, 2);
        }
        Text_PrintIdList((s32 *)arg1, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280006, arg1->menuKind - 1), 0);
        Stg11_CloseSlotText(arg0, arg1);
        arg1->fade = 0x1000;
        return;
    }
    switch (arg0->stateLevel2) {
    case 0:
    default:
        Text_CloseArray((s32 *)arg1, 0x1A);
        Task_NextState2(arg0);
        break;
    case 1:
        if (Math_RampToZero(arg0, &arg1->fade) == 0) {
            Task_Create(0x605, slot, arg1->padIndex + 1);
            D_80050780 = 0;
            Task_NextState2(arg0);
        }
        break;
    case 2:
        if (*slot == 0) {
            if (D_80050780 != 0) {
                d = &Save_GameStatePtr->elems[arg1->padIndex * 3];
                for (i = 0; i < 3; i++) {
                    *d = Stg11_VsParty.members[i];
                    if (d->state != 0) {
                        d->state = i + 3;
                    }
                    d++;
                }
                src = Stg11_VsParty.gameState->field_14;
                dst = Save_GameStatePtr->elems[arg1->padIndex + 6].name;
                while (*src != 0xFF) {
                    *dst++ = *src++;
                }
                *dst = 0xFF;
                Task_SetState0(arg0, 3);
            } else {
                Task_NextState2(arg0);
            }
        }
        break;
    case 3:
        if (Math_RampToOne(arg0, &arg1->fade) == 0) {
            Text_PrintIdList((s32 *)arg1, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280006, arg1->menuKind - 1), 2);
            Task_SetState1(arg0, 7);
        }
        break;
    }
}

void Stg11_StateTransferList(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    if (arg0->stateLevel2 == 0) {
        Stg11_CardStartOp(4, arg1->cardPort);
    }
    if (Stg11_WatchCardRemoved(arg0, arg1) != 0) {
        Text_CloseArray(arg1->transferTexts, 11);
        Text_Close(&arg1->transferCountText);
        return;
    }
    switch (arg0->stateLevel2) {
    case 0:
    default:
        arg1->listMode = 2;
        arg1->u6C.gridSize[1] = 5;
        Stg11_SetStatusMsg(arg1, 0);
        Stg11_ScanTransferCards(arg0, arg1);
        Stg11_OpenTransferText(arg0, arg1);
        Task_NextState2(arg0);
        break;
    case 1:
        Stg11_SetPromptMsg(arg1, 0x1B6, 0);
        Task_NextState2(arg0);
        break;
    case 2:
        if (Menu_MoveGridCursor(arg1->cursor, arg1->u6C.gridSize, arg1->padIndex) == 0) {
            if (Pad_State[arg1->padIndex].cross > 0) {
                Stg11_TransferSelected(arg0, arg1);
            } else if (Pad_State[arg1->padIndex].triangle > 0) {
                Stg11_SetPromptMsg(arg1, 0x1B8, 1);
                Task_NextState2(arg0);
            }
        } else {
            Stg11_SetPromptMsg(arg1, 0x1B6, 0);
            Snd_PlayById(0xD, 0);
        }
        break;
    case 3:
        r = Text_WaitYesNo(arg1->promptText);
        if (r != -1) {
            if (r == 1) {
                Task_SetState0(arg0, 2);
            }
        } else {
            Task_SetState2(arg0, 1);
        }
        break;
    }
}

/* Memory card file names: Japanese data-transfer file, USA save file. */
const u8 Stg11_TransferFileName[] = "BISLPSP028001";
const u8 Stg11_SaveFileName[] = "BASLUS-01193 DMW2";
void Stg11_CardMenuInit(Actor *arg0, s16 arg1) {
    Stg11MenuWork *w = (Stg11MenuWork *)arg0->work;

    w->menuKind = arg1;
    w->isLoad = arg1 > 2;
    w->cardPort = (w->menuKind - 1) % 2;
    w->padIndex = w->menuKind == 7 || w->menuKind == 8;
    w->isVsLoad = w->menuKind >= 5 && w->menuKind <= 8;
    w->isTransfer = w->menuKind == 9 || w->menuKind == 10;
    if (w->menuKind == 9 || w->menuKind == 10) {
        Stg11_CardSetFileName(Stg11_TransferFileName, 1);
    } else {
        Stg11_CardSetFileName(Stg11_SaveFileName, 0);
    }
    w->saveList = (Stg11SaveList *)Stg11_CardGetDataBuf();
    w->progressMode = 0;
}

void Stg11_CardMenuUpdate(Actor *arg0) {
    Stg11MenuWork *w = (Stg11MenuWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        w->u6C.layout = ((Layout8C *)Cd_GetFileEntry(0xD280005))[w->menuKind - 1];
        Mem_FillWordsNeg1((s32 *)w, 0x1A);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(arg0, &w->fade) == 0) {
                Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280006, w->menuKind - 1), 2);
                w->pendingPromptMsg = 0;
                Stg11_SetStatusMsg(w, w->isTransfer ? 0x1AD : 0x16B);
                Task_SetState1(arg0, 3);
            }
            break;
        case 3:
            Stg11_StateCheckCard(arg0, w);
            break;
        case 2:
            Stg11_StateCardError(arg0, w);
            break;
        case 1:
            Stg11_StateWaitCancel(arg0, w);
            break;
        case 4:
            Stg11_StateAskCreate(arg0, w);
            break;
        case 5:
            Stg11_StateCreateFile(arg0, w);
            break;
        case 6:
            Stg11_StateReadFile(arg0, w);
            break;
        case 7:
            Stg11_StateSelectSlot(arg0, w);
            break;
        case 8:
            Stg11_StateWriteSave(arg0, w);
            break;
        case 9:
            Stg11_StateAskFormat(arg0, w);
            break;
        case 10:
            Stg11_StateFormat(arg0, w);
            break;
        case 11:
            Stg11_StateVsPartySelect(arg0, w);
            break;
        case 12:
            Stg11_StateTransferList(arg0, w);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray((s32 *)w, 0x1A);
            Task_NextState1(arg0);
            break;
        case 1:
            if (Math_RampToZero(arg0, &w->fade) == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    }
}

void Stg11_CardMenuDraw(Actor *arg0) {
    Stg11MenuWork *w = (Stg11MenuWork *)arg0->work;
    s32 *ids;
    GfxPart *parts;
    s32 *tbl;
    s32 *tblA;
    Stg11SaveSlot *slot;
    Stg11PolyG4 *p;
    u32 *ot;
    s32 i;
    s32 mask;
    s32 m1;
    s32 bit;
    Stg11SaveList *list;
    u32 t;
    s32 h;

    if (w->fade != 0) {
        ids = (s32 *)Cd_GetFileEntry(0xD280007);
        for (i = 0; ids[i] != 0; i++) {
            parts = (GfxPart *)Cd_GetFileEntry(ids[i]);
            switch (i) {
            case 0:
                tbl = (s32 *)Cd_GetFileEntry(0xD280008);
                bit = (w->listMode == 2) << 4;
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, tbl[w->menuKind - 1] & ~bit);
                break;
            case 1:
                tbl = (s32 *)Cd_GetFileEntry(0xD280009);
                m1 = tbl[w->listMode];
                if (w->progressMode == 0) {
                    m1 |= 0x20;
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, m1);
                if (w->listMode == 1) {
                    Menu_SetPartsGridPos(parts, 2, (s32 *)w->cursor, w->u6C.gridSize);
                    Gfx_SetPartsPalette(parts, 2, (arg0->elapsed >> 2) & 3);
                }
                if (w->listMode == 2) {
                    Menu_SetPartsGridPos(parts, 0x10, (s32 *)w->cursor, w->u6C.gridSize);
                }
                break;
            default:
                tblA = (s32 *)Cd_GetFileEntry(0xD28000A);
                list = w->saveList;
                mask = -1;
                if (w->listMode == 1) {
                    mask = tblA[1];
                    slot = &list->slots[i - 2];
                    if (list->used[i - 2] != 0) {
                        t = slot->u.hdr.playTime;
                        if (t > 0x14996FF) {
                            t = 0x14996FF;
                        }
                        Gfx_SetPartsNumber(parts, 0x10, 8, slot->u.hdr.money);
                        h = t / 216000;
                        Gfx_SetPartsNumber(parts, 0x20, -4, h * 100 + (t / 3600 - h * 60));
                    } else {
                        Gfx_SetPartsNumber(parts, 0x10, 8, 0);
                        Gfx_SetPartsNumber(parts, 0x20, -4, 0);
                    }
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, mask);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->fade);
            Gfx_DrawParts(parts);
        }
    }
    if (w->progressMode != 0) {
        p = (Stg11PolyG4 *)Sys_State.packet.addr;
        ot = Sys_State.otLayers.u[0];
        p->tag.b.len = 8;
        p->code = 0x38;
        p->r0 = 0xD;
        p->g0 = 0x66;
        p->b0 = 0x11;
        p->r1 = 0xFF;
        p->g1 = 0x96;
        p->b1 = 0;
        p->r2 = 0xD;
        p->g2 = 0x66;
        p->b2 = 0x11;
        p->r3 = 0xFF;
        p->g3 = 0x96;
        p->b3 = 0;
        p->code &= ~2;
        p->x0 = 0x12;
        p->y0 = 0x2A;
        p->x1 = w->progress + 0x12;
        p->y1 = 0x2A;
        p->x2 = 0x12;
        p->y2 = 0x35;
        p->x3 = w->progress + 0x12;
        p->y3 = 0x35;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        Sys_State.packet.addr = (s32)(p + 1);
    }
}
