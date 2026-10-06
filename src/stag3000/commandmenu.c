#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_CommandMenuUpdate(Actor *a0);
void Stg30_CommandMenuDestroy(Actor *a0);
void Stg30_CommandMenuDraw(Actor *a0);

u8 Stg30_CursorBlinkPalettes[] = { 0, 1, 2, 3, 2, 1, 0xFF };
TaskDesc Stg30_CommandMenuDesc = {
    0, Stg30_CommandMenuUpdate, Stg30_CommandMenuDestroy, Stg30_CommandMenuDraw, 0x14, 0,
};

s32 Stg30_CommandMenuCursor;
u8 D_800737E4[4];

const Halves Stg30_TamerNameTextPos = { 0x16, 0x30 };
void Stg30_CommandMenuUpdate(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Halves pos;
    TextOpenArgs args;
    s32 i;
    s32 j;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
        Stg30_CommandMenuCursor = 0;
        Mem_FillWordsNeg1(w->text, 4);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel2) {
        case 0:
        default:
            switch (a0->stateLevel3) {
            case 0:
            default:
                a0->elapsed = 0;
                Task_NextState3(a0);
                break;
            case 1:
                for (j = 0; j < a0->elapsed; j++) {
                    w->scale += 0x2AA;
                }
                a0->elapsed = 0;
                if (w->scale > 0x1000) {
                    w->scale = 0x1000;
                    Task_NextState2(a0);
                }
                break;
            }
            break;
        case 1:
            do {
                if (Pad_State[0].up > 0) {
                    if (Stg30_CommandMenuCursor == 0) break;
                    Stg30_CommandMenuCursor--;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (Pad_State[0].down > 0) {
                    if (Stg30_Battle.entries[0].inputSlot == 6) {
                        if (Stg30_CommandMenuCursor == 2) break;
                        if (Stg30_Battle.entries[0].fromCity != 0) break;
                        Stg30_CommandMenuCursor++;
                        Snd_PlayById(0xC, 0);
                        break;
                    }
                    if (Stg30_CommandMenuCursor == 1) break;
                    Stg30_CommandMenuCursor++;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (Pad_State[0].cross > 0) {
                    Stg30_Battle.entries[0].cancelled = 0;
                    Stg30_Battle.entries[0].menuChoice = Stg30_CommandMenuCursor;
                    Snd_PlayById(0xA, 0);
                    Task_NextState0(a0);
                    break;
                }
                if (Stg30_Battle.entries[0].inputSlot == 6) break;
                if (Pad_State[0].triangle > 0) {
                    Stg30_Battle.entries[0].cancelled = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                }
            } while (0);
            if (Stg30_Battle.entries[0].inputSlot == 6) {
                Text_OpenPacked(w->text, (s32)Save_GameState.playerName, 0x10, Stg30_TamerNameTextPos);
                for (k = 0; k < 3; k++) {
                    if (Stg30_Battle.entries[0].fromCity != 0 && k != 0) {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 3, pos);
                    } else if (Stg30_CommandMenuCursor == k) {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 0, pos);
                    } else {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 1, pos);
                    }
                }
            } else {
                if (w->text[0] == -1) {
                    args.text = (s32)((Stg30StateDigis *)&Stg30_Battle)->digis[Stg30_Battle.entries[0].inputSlot].name;
                    args.color = 4;
                    args.x = 0x16;
                    args.bigFont = 0;
                    args.y = 0x30;
                    args.charDelay = 0;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(w->text, &args);
                }
                for (i = 0; i < 2; i++) {
                    s32 *text = &w->text[i + 1];

                    pos.hi = i * 11 + 0x3C;
                    pos.lo = 0x16;
                    Text_OpenById(text, i + 5, Stg30_CommandMenuCursor != i, pos);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->text, 4);
            a0->elapsed = 0;
            Task_NextState1(a0);
            break;
        case 1:
            for (j = 0; j < a0->elapsed; j++) {
                w->scale -= 0x2AA;
            }
            if (w->scale <= 0) {
                w->scale = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void Stg30_CommandMenuDestroy(Actor *a0) {
    Text_CloseArray(((Stg30Work73078 *)a0->work)->text, 4);
    Task_DefaultDestroy(a0);
}

void Stg30_CommandMenuDraw(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;

    p = (Stg30Part *)Cd_GetFileEntry(0x1A10009);
    Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = -0x92;
            q->y = Stg30_CommandMenuCursor * 11 - 0x33;
            while (1) {
                if (a0->elapsed < 0x18) break;
                a0->elapsed = a0->elapsed - 0x18;
            }
            q->palette = Stg30_CursorBlinkPalettes[a0->elapsed / 4];
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}
