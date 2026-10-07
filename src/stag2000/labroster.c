#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabRosterUpdate(Actor *a);
void Stg20_LabRosterDraw(Actor *a);

Halves Stg20_LabRosterTextPos[4][4] = {
    { { 194, 60 }, { 95, 48 }, { 194, 48 }, { 95, 60 } },
    { { 194, 94 }, { 95, 82 }, { 194, 82 }, { 95, 94 } },
    { { 194, 128 }, { 95, 116 }, { 194, 116 }, { 95, 128 } },
    { { 194, 162 }, { 95, 150 }, { 194, 150 }, { 95, 162 } },
};
s32 Stg20_LabRosterPanelIds[4] = { 0x0D120003, 0x0D120004, 0x0D120005, 0x0D120006 };
TaskDesc Stg20_LabRosterDesc = { 0, Stg20_LabRosterUpdate, Task_DefaultDestroy, Stg20_LabRosterDraw, 0x78, 0 };

void Stg20_LabRosterSetText(Actor *a, s32 i) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    Stg20Slot *s = &w->slots[i];
    Halves *pos = Stg20_LabRosterTextPos[i];
    s32 digi = Save_GameState.elems[s->slot].digiId;
    s32 j;

    if (s->enabled != 0) {
        for (j = 0; j < 4; j++) {
            Text_Close(&w->texts[i * 4 + j]);
        }
        if (s->used != 0) {
            Text_OpenById(&w->texts[i * 4 + 0], 0x81, 0, pos[0]);
            Text_OpenPacked(&w->texts[i * 4 + 1], (s32)Save_GameState.elems[s->slot].name, 0, pos[1]);
            Text_OpenPacked(&w->texts[i * 4 + 2], (s32)Digi_GetDefaultName(digi), 0, pos[2]);
            Text_OpenById(&w->texts[i * 4 + 3], Digi_GetRank(digi) + 0xC6, 0, pos[3]);
        }
    }
}

void Stg20_LabRosterFillSlots(Actor *a) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        w->slots[i].used = Save_GameState.elems[i + Stg20_MenuState.rosterTop].state != 0;
        w->slots[i].enabled = 1;
        w->slots[i].slot = i + Stg20_MenuState.rosterTop;
    }
}

void Stg20_LabRosterUpdate(Actor *a) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    s32 i;
    s32 j;
    s32 snd;
    s32 idx;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 16);
        for (j = 0; j < 0x24; j++) {
            if (Save_GameState.elems[j].state != 0) {
                w->count++;
            }
        }
        Stg20_LabRosterFillSlots(a);
        Task_NextState0(a);
        break;
    tri:
        Stg20_MenuState.result = 1;
        Stg20_MenuState.pickedIndex = Stg20_MenuState.rosterTop + Stg20_MenuState.rosterCursor;
        Snd_PlayById(0xB, 0);
        Task_NextState0(a);
        goto done;
    ok:
        Stg20_MenuState.result = 0;
        Stg20_MenuState.pickedIndex = idx;
        Snd_PlayById(0xE, 0);
        Task_NextState0(a);
        goto done;
    case 1:
        snd = 0;
        if (Pad_State[0].repeat & 0x1000) {
            if (Stg20_MenuState.rosterCursor != 0) {
                w->timer = 0;
                snd = 1;
                Stg20_MenuState.rosterCursor--;
            } else if (Stg20_MenuState.rosterTop != 0) {
                Stg20_MenuState.rosterTop--;
                snd = 1;
            }
            Stg20_LabRosterFillSlots(a);
        } else if (Pad_State[0].repeat & 0x4000) {
            if (Stg20_MenuState.rosterCursor != 3) {
                w->timer = 0;
                snd = 1;
                Stg20_MenuState.rosterCursor++;
            } else if (Stg20_MenuState.rosterTop + 4 < w->count) {
                Stg20_MenuState.rosterTop++;
                snd = 1;
            }
            Stg20_LabRosterFillSlots(a);
        } else if (Pad_State[0].triangle > 0) {
            goto tri;
        } else if (Pad_State[0].cross > 0) {
            idx = Stg20_MenuState.rosterTop + Stg20_MenuState.rosterCursor;
            if ((Stg20_MenuState.excludeFirst != 0 && Stg20_MenuState.dnaParent0 == idx) || Save_GameState.elems[idx].state == 0) {
                Snd_PlayById(0x10, 0);
            } else {
                goto ok;
            }
        }
    done:
        if (snd != 0) {
            Snd_PlayById(0xD, 0);
        }
        for (i = 0; i < 4; i++) {
            Stg20_LabRosterSetText(a, i);
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 16);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabRosterDraw(Actor *a) {
    DigiRosterEntry *ros;
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    GfxPart *p;
    GfxPart *r;
    GfxPart *q;
    GfxPart *s;
    s32 i;

    w->timer++;
    p = (GfxPart *)Cd_GetFileEntry(0xD120002);
    do {
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & 2) {
                q->x = 0x1D;
                q->y = Stg20_MenuState.rosterCursor * 0x22 - 0x3E;
                q->visible = ((w->timer >> 4) ^ 1) & 1;
            }
            if (q->groupMask & 4) {
                q->visible = Stg20_MenuState.rosterTop != 0;
            }
            if (q->groupMask & 8) {
                q->visible = Stg20_MenuState.rosterTop + 4 < w->count;
            }
        }
        Gfx_DrawParts((s32)p);
        for (i = 0; i < 4; i++) {
            ros = Save_GameState.elems;
            r = (GfxPart *)Cd_GetFileEntry(Stg20_LabRosterPanelIds[i]);
            for (s = r; s->fileId != 0; s++) {
                do {
                    if (s->groupMask & 2) {
                        s->visible = Stg20_MenuState.rosterCursor != i;
                    }
                } while (0);
                if (s->groupMask & 4) {
                    s->visible = Stg20_MenuState.rosterCursor == i;
                }
                if (s->groupMask & 8) {
                    s->visible = w->slots[i].used != 0;
                }
            }
            Gfx_SetPartsNumber(r, 8, 2, ros[i + Stg20_MenuState.rosterTop].level);
            Gfx_DrawParts((s32)r);
        }
    } while (0);
}
