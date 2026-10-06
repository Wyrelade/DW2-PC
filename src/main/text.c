#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/sound.h"

/* .bss */
TextStack Text_ReturnStack;

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Text_LoadFontsTask(Actor *a0);
void Text_UpdateAllBoxes(Actor *a0);

/* Text dictionary: words the text engine substitutes for codes 6.. (glyph codes, 0xFF ends). */
u8 Text_Word_Digimon[] = { 0x0D, 0x2C, 0x2A, 0x2C, 0x30, 0x32, 0x31, 0xFF }; /* "Digimon" */
u8 Text_Word_you[] = { 0x3C, 0x32, 0x38, 0xFF }; /* "you" */
u8 Text_Word_the[] = { 0x37, 0x2B, 0x28, 0xFF }; /* "the" */
u8 Text_Word_DigiBeetle[] = { 0x0D, 0x2C, 0x2A, 0x2C, 0x49, 0x0B, 0x28, 0x28, 0x37, 0x2F, 0x28, 0xFF }; /* "Digi-Beetle" */
u8 Text_Word_Domain[] = { 0x0D, 0x32, 0x30, 0x24, 0x2C, 0x31, 0xFF }; /* "Domain" */
u8 Text_Word_Guard[] = { 0x10, 0x38, 0x24, 0x35, 0x27, 0xFF }; /* "Guard" */
u8 Text_Word_Tamer[] = { 0x1D, 0x24, 0x30, 0x28, 0x35, 0xFF }; /* "Tamer" */
u8 Text_Word_here[] = { 0x2B, 0x28, 0x35, 0x28, 0xFF }; /* "here" */
u8 Text_Word_have[] = { 0x2B, 0x24, 0x39, 0x28, 0xFF }; /* "have" */
u8 Text_Word_Knights[] = { 0x14, 0x31, 0x2C, 0x2A, 0x2B, 0x37, 0x36, 0xFF }; /* "Knights" */
u8 Text_Word_and[] = { 0x24, 0x31, 0x27, 0xFF }; /* "and" */
u8 Text_Word_thing[] = { 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "thing" */
u8 Text_Word_Security[] = { 0x1C, 0x28, 0x26, 0x38, 0x35, 0x2C, 0x37, 0x3C, 0xFF }; /* "Security" */
u8 Text_Word_that[] = { 0x37, 0x2B, 0x24, 0x37, 0xFF }; /* "that" */
u8 Text_Word_Bertran[] = { 0x0B, 0x28, 0x35, 0x37, 0x35, 0x24, 0x31, 0xFF }; /* "Bertran" */
u8 Text_Word_Tournament[] = { 0x1D, 0x32, 0x38, 0x35, 0x31, 0x24, 0x30, 0x28, 0x31, 0x37, 0xFF }; /* "Tournament" */
u8 Text_Word_Crimson[] = { 0x0C, 0x35, 0x2C, 0x30, 0x36, 0x32, 0x31, 0xFF }; /* "Crimson" */
u8 Text_Word_Vendor[] = { 0x1F, 0x28, 0x31, 0x27, 0x32, 0x35, 0xFF }; /* "Vendor" */
u8 Text_Word_something[] = { 0x36, 0x32, 0x30, 0x28, 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "something" */
u8 Text_Word_Item[] = { 0x12, 0x37, 0x28, 0x30, 0xFF }; /* "Item" */
u8 Text_Word_Falcon[] = { 0x0F, 0x24, 0x2F, 0x26, 0x32, 0x31, 0xFF }; /* "Falcon" */
u8 Text_Word_for[] = { 0x29, 0x32, 0x35, 0xFF }; /* "for" */
u8 Text_Word_Thats[] = { 0x1D, 0x2B, 0x24, 0x37, 0x56, 0x36, 0xFF }; /* "That's" */
u8 Text_Word_Commander[] = { 0x0C, 0x32, 0x30, 0x30, 0x24, 0x31, 0x27, 0x28, 0x35, 0xFF }; /* "Commander" */
u8 Text_Word_Blood[] = { 0x0B, 0x2F, 0x32, 0x32, 0x27, 0xFF }; /* "Blood" */
u8 Text_Word_Leader[] = { 0x15, 0x28, 0x24, 0x27, 0x28, 0x35, 0xFF }; /* "Leader" */
u8 Text_Word_Attendant[] = { 0x0A, 0x37, 0x37, 0x28, 0x31, 0x27, 0x24, 0x31, 0x37, 0xFF }; /* "Attendant" */
u8 Text_Word_Cecilia[] = { 0x0C, 0x28, 0x26, 0x2C, 0x2F, 0x2C, 0x24, 0xFF }; /* "Cecilia" */
u8 Text_Word_all[] = { 0x24, 0x2F, 0x2F, 0xFF }; /* "all" */
u8 Text_Word_mission[] = { 0x30, 0x2C, 0x36, 0x36, 0x2C, 0x32, 0x31, 0xFF }; /* "mission" */
u8 Text_Word_this[] = { 0x37, 0x2B, 0x2C, 0x36, 0xFF }; /* "this" */
u8 Text_Word_MasterTyrannomon[] = { 0x16, 0x24, 0x36, 0x37, 0x28, 0x35, 0x1D, 0x3C, 0x35, 0x24, 0x31, 0x31, 0x32, 0x30, 0x32, 0x31, 0xFF }; /* "MasterTyrannomon" */
u8 Text_Word_Archive[] = { 0x0A, 0x35, 0x26, 0x2B, 0x2C, 0x39, 0x28, 0xFF }; /* "Archive" */
u8 Text_Word_Black[] = { 0x0B, 0x2F, 0x24, 0x26, 0x2E, 0xFF }; /* "Black" */
u8 Text_Word_Ill[] = { 0x12, 0x56, 0x2F, 0x2F, 0xFF }; /* "I'll" */
u8 Text_Word_are[] = { 0x24, 0x35, 0x28, 0xFF }; /* "are" */
u8 Text_Word_Sword[] = { 0x1C, 0x3A, 0x32, 0x35, 0x27, 0xFF }; /* "Sword" */
u8 Text_Word_right[] = { 0x35, 0x2C, 0x2A, 0x2B, 0x37, 0xFF }; /* "right" */
u8 Text_Word_digivolve[] = { 0x27, 0x2C, 0x2A, 0x2C, 0x39, 0x32, 0x2F, 0x39, 0x28, 0xFF }; /* "digivolve" */
u8 Text_Word_enter[] = { 0x28, 0x31, 0x37, 0x28, 0x35, 0xFF }; /* "enter" */
u8 Text_Word_What[] = { 0x20, 0x2B, 0x24, 0x37, 0xFF }; /* "What" */
u8 Text_Word_will[] = { 0x3A, 0x2C, 0x2F, 0x2F, 0xFF }; /* "will" */
u8 Text_Word_come[] = { 0x26, 0x32, 0x30, 0x28, 0xFF }; /* "come" */
u8 Text_Word_You[] = { 0x22, 0x32, 0x38, 0xFF }; /* "You" */
u8 Text_Word_Coliseum[] = { 0x0C, 0x32, 0x2F, 0x2C, 0x36, 0x28, 0x38, 0x30, 0xFF }; /* "Coliseum" */
u8 Text_Word_about[] = { 0x24, 0x25, 0x32, 0x38, 0x37, 0xFF }; /* "about" */
u8 Text_Word_dont[] = { 0x27, 0x32, 0x31, 0x56, 0x37, 0xFF }; /* "don't" */
u8 Text_Word_anything[] = { 0x24, 0x31, 0x3C, 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "anything" */
u8 Text_Word_Vandar[] = { 0x1F, 0x24, 0x31, 0x27, 0x24, 0x35, 0xFF }; /* "Vandar" */
u8 Text_Word_Parts[] = { 0x19, 0x24, 0x35, 0x37, 0x36, 0xFF }; /* "Parts" */
u8 Text_Word_where[] = { 0x3A, 0x2B, 0x28, 0x35, 0x28, 0xFF }; /* "where" */
u8 Text_Word_The[] = { 0x1D, 0x2B, 0x28, 0xFF }; /* "The" */
u8 Text_Word_know[] = { 0x2E, 0x31, 0x32, 0x3A, 0xFF }; /* "know" */
u8 Text_Word_Leomon[] = { 0x15, 0x28, 0x32, 0x30, 0x32, 0x31, 0xFF }; /* "Leomon" */
u8 Text_Word_want[] = { 0x3A, 0x24, 0x31, 0x37, 0xFF }; /* "want" */
u8 Text_Word_Oldman[] = { 0x18, 0x2F, 0x27, 0x30, 0x24, 0x31, 0xFF }; /* "Oldman" */
u8 Text_Word_like[] = { 0x2F, 0x2C, 0x2E, 0x28, 0xFF }; /* "like" */
u8 Text_Word_need[] = { 0x31, 0x28, 0x28, 0x27, 0xFF }; /* "need" */
u8 Text_Word_Chief[] = { 0x0C, 0x2B, 0x2C, 0x28, 0x29, 0xFF }; /* "Chief" */
u8 Text_Word_with[] = { 0x3A, 0x2C, 0x37, 0x2B, 0xFF }; /* "with" */
u8 Text_Word_Thank[] = { 0x1D, 0x2B, 0x24, 0x31, 0x2E, 0xFF }; /* "Thank" */
u8 Text_Word_strange[] = { 0x36, 0x37, 0x35, 0x24, 0x31, 0x2A, 0x28, 0xFF }; /* "strange" */
u8 Text_Word_Island[] = { 0x12, 0x36, 0x2F, 0x24, 0x31, 0x27, 0xFF }; /* "Island" */
u8 Text_Word_can[] = { 0x26, 0x24, 0x31, 0xFF }; /* "can" */
u8 Text_Word_really[] = { 0x35, 0x28, 0x24, 0x2F, 0x2F, 0x3C, 0xFF }; /* "really" */
u8 Text_Word_Blue[] = { 0x0B, 0x2F, 0x38, 0x28, 0xFF }; /* "Blue" */
u8 Text_Word_time[] = { 0x37, 0x2C, 0x30, 0x28, 0xFF }; /* "time" */
/* Sound effect per text sfx code. */
s16 Text_SfxIds[] = { 0x19, 0x1A, 0x21, 0x2B, 0x20, 0x2A, 0x1F, 0x17, 0x08 };
u8 *Text_BuiltinStrings[] = {
    Text_Word_Digimon, Text_Word_you, Text_Word_the, Text_Word_DigiBeetle, Text_Word_Domain, Text_Word_Guard,
    Text_Word_Tamer, Text_Word_here, Text_Word_have, Text_Word_Knights, Text_Word_and, Text_Word_thing,
    Text_Word_Security, Text_Word_that, Text_Word_Bertran, Text_Word_Tournament, Text_Word_Crimson, Text_Word_Vendor,
    Text_Word_something, Text_Word_Item, Text_Word_Falcon, Text_Word_for, Text_Word_Thats, Text_Word_Commander,
    Text_Word_Blood, Text_Word_Leader, Text_Word_Attendant, Text_Word_Cecilia, Text_Word_all, Text_Word_mission,
    Text_Word_this, Text_Word_MasterTyrannomon, Text_Word_Archive, Text_Word_Black, Text_Word_Ill, Text_Word_are,
    Text_Word_Sword, Text_Word_right, Text_Word_digivolve, Text_Word_enter, Text_Word_What, Text_Word_will,
    Text_Word_come, Text_Word_You, Text_Word_Coliseum, Text_Word_about, Text_Word_dont, Text_Word_anything,
    Text_Word_Vandar, Text_Word_Parts, Text_Word_where, Text_Word_The, Text_Word_know, Text_Word_Leomon,
    Text_Word_want, Text_Word_Oldman, Text_Word_like, Text_Word_need, Text_Word_Chief, Text_Word_with,
    Text_Word_Thank, Text_Word_strange, Text_Word_Island, Text_Word_can, Text_Word_really, Text_Word_Blue,
    Text_Word_time,
};
TaskDesc Text_BoxDesc = { 0, Text_LoadFontsTask, Task_DefaultDestroy, Text_UpdateAllBoxes, 0xA34, 0xD8 };

void Text_PushReturn(s32 arg0) {
    Text_ReturnStack.data[Text_ReturnStack.count] = arg0;
    Text_ReturnStack.count = Text_ReturnStack.count + 1;
}

s32 Text_PopReturn(void) {
    if (Text_ReturnStack.count == 0) {
        return 0;
    }
    Text_ReturnStack.count = Text_ReturnStack.count - 1;
    return Text_ReturnStack.data[Text_ReturnStack.count];
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern void Task_Create(u32, s32 *, s32);

void Text_LoadFontsTask(Actor *a0) {
    if (a0->stateLevel0 != 0) {
        return;
    }
    Gfx_FindOrLoadTexSlot(0x13A0000);
    if ((Sys_State.gameMode & 0xF00) != 0x500) {
        Gfx_FindOrLoadTexSlot(0x1100000);
        Task_Create(0xA, a0->u34.children, 0);
    }
    Task_NextState0(a0);
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern Obj6A8C0 *Stg20_FindWalkerByDigiId(s32);
extern void Stg20_WalkerWarpToCell(void *, s32 *);
extern s32 Stg20_WalkerIsPathDone(void *);
extern void Stg20_WalkerSetAnim(Obj6A8C0 *, s32);
extern void Stg40_TextObjCommand(s32 *);
extern s32 Stg40_IsTextObjCmdBusy(void);
extern void Stg20_StartBgShake(void);

void Text_UpdateAllBoxes(Actor *a0) {
    GfxTexSlot *font[2];
    Pair54 glyph;
    Pair54 cell;
    Pair54 pos;
    s32 num[2];
    s32 nums[3];
    TextBoxWork *wk;
    TextBoxKids *slots;
    s32 row;
    TextGlyphPoly *pkt;
    s32 *ot;
    s32 cols;
    s32 page;
    s32 nFA;
    s32 nFB;
    s32 nF9;
    s32 nF8;
    s32 nF6;
    s32 nF5;
    s32 nF4b;
    s32 nF4a;
    s32 nF4c;
    u8 nF4d;
    s32 grew;
    TextBox *r;
    u8 *s;
    s32 stop;
    s32 line;
    s32 c;
    s32 vf;
    u8 k9;
    s32 k4;
    u8 k;
    s32 j;
    s32 *np;
    u8 isF6;
    u8 mode2;
    Obj6A8C0 *h;
    PadState *tb;

    pkt = (TextGlyphPoly *)Sys_State.packet.addr;
    slots = (TextBoxKids *)a0->u34.children;
    wk = (TextBoxWork *)a0->work;
    tb = Pad_State;
    row = 0;
    do {
        if (wk->rec[row].inUse != 0) {
            r = &wk->rec[row];
            nFA = 0;
            nFB = 0;
            nF9 = 0;
            nF8 = 0;
            nF6 = 0;
            nF5 = 0;
            nF4b = 0;
            nF4a = 0;
            s = (u8 *)r->text;
            nF4c = line = 0;
            pos = *(Pair54 *)&r->x;
            nF4d = 0;
            ot = Sys_State.otLayers.u[r->otIndex];
            page = 0;
            r->color = r->baseColor;
            if (r->waitingInput == 0 && r->charDelay != 0) {
                r->delayTimer += Sys_State.frameDelta;
                if (r->delayTimer >= r->charDelay) {
                    r->visibleChars++;
                    r->delayTimer -= r->charDelay;
                }
            }
            if (r->bigFont != 0) {
                glyph.field_0 = 8;
                glyph.field_2 = 0xD;
                cell.field_0 = 9;
                cols = 0xD;
                cell.field_2 = 0xE;
                font[0] = Gfx_FindOrLoadTexSlot(0x1100000);
                font[1] = Gfx_FindOrLoadTexSlot(0x1100000);
            } else {
                glyph.field_0 = 7;
                glyph.field_2 = 9;
                cell.field_0 = 7;
                cols = 0x11;
                cell.field_2 = 0xA;
                font[0] = Gfx_FindOrLoadTexSlot(0x13A0000);
                font[1] = Gfx_FindOrLoadTexSlot(0x13A0000);
            }
            Text_ReturnStack.count = 0;
            stop = 0;
            grew = 0;
            do {
                switch (*s) {
                case 0xFF:
                    vf = Text_PopReturn();
                    if (vf == 0) {
                        r->charDelay = 0;
                        r->finished = 1;
                        stop = 1;
                        break;
                    }
                    s = (u8 *)vf - 1;
                    line--;
                    break;
                case 0xFE:
                    pos.field_0 = r->x;
                    pos.field_2 += r->lineAdvance;
                    break;
                case 0xFD:
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                case 0xFC:
                    r->text = (s32)(s + 1);
                    r->visibleChars = 0;
                    r->cmdFADone = 0;
                    r->cmdFBDone = 0;
                    r->cmdF9Done = 0;
                    r->cmdF6Done = 0;
                    r->pausesDone = 0;
                    r->cmdF4TurnDone = 0;
                    r->cmdF4ObjDone = 0;
                    r->cmdF4TaskDone = 0;
                    r->soundsDone = 0;
                    break;
                case 0xFB:
                    if (r->cmdFBDone == nFB) {
                        if (tb[r->padIndex].cross > 0) {
                            stop = 1;
                            r->cmdFBDone = nFB + 1;
                            r->waitingInput = 0;
                            Snd_PlayById(0x13, 0);
                        } else {
                            stop = 1;
                            wk->blinkTimer += Sys_State.frameDelta;
                            if (wk->blinkTimer >= 0x18) {
                                wk->blinkTimer -= 0x18;
                            }
                            c = ((wk->blinkTimer / 6) & 3) + 0x4F;
                            r->waitingInput = 1;
                            goto draw;
                        }
                    }
                    nFB++;
                    break;
                case 0xFA:
                    s++;
                    if (r->cmdFADone == nFA) {
                        switch (a0->stateLevel1) {
                        default:
                        case 0:
                            Snd_PlayById((*s & 1) ? 0x38 : 0x37, 0);
                            switch (*s) {
                            case 0:
                                Task_Create(4, (s32 *)&slots->box[row], 0);
                                r->x = -0x90;
                                r->y = 0x34;
                                break;
                            case 2:
                                Task_Create(4, (s32 *)&slots->box[row], 1);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 6:
                                Task_Create(4, (s32 *)&slots->box[row], 3);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 4:
                                Task_Create(4, (s32 *)&slots->box[row], 2);
                                r->x = -0x90;
                                r->y = 0x12;
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                if (slots->box[row] != 0) {
                                    Task_SetState0(slots->box[row], 2);
                                }
                                Task_NextState1(a0);
                                break;
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            if (slots->box[row]->stateLevel1 == 1) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        case 2:
                            if (slots->box[row] == 0) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        }
                    }
                    nFA++;
                    break;
                case 0xF9:
                    s++;
                    k9 = *s;
                    if (k9 & 1) {
                        if (r->cmdF9Done == nF9) {
                            if (slots->num[(k9 >> 1) & 1] != 0) {
                                Task_SetState0(slots->num[(k9 >> 1) & 1], 2);
                            }
                            r->cmdF9Done++;
                            Snd_PlayById(0x3A, 0);
                        }
                    } else if (r->cmdF9Done == nF9) {
                        num[1] = (k9 >> 1) & 1;
                        s++;
                        num[0] = *s++ * 100;
                        num[0] += *s++ * 10;
                        num[0] += *s;
                        if (slots->num[num[1]] != 0) {
                            Text_PortraitSetImage(slots->num[num[1]], num[0]);
                        } else {
                            Task_Create(5, (s32 *)&slots->num[num[1]], (s32)num);
                        }
                        r->cmdF9Done++;
                        Snd_PlayById(0x39, 0);
                    } else {
                        s += 3;
                    }
                    nF9++;
                    break;
                set1:
                    r->choiceCursor = 1;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                set0:
                    r->choiceCursor = 0;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                case 0xF8:
                    s++;
                    if (r->choicesDone == nF8) {
                        switch (*s) {
                        default:
                        case 0:
                            stop = 1;
                            r->waitingInput = 1;
                            if (tb[r->padIndex].pressed & 0x6000) {
                                goto set1;
                            }
                            if (tb[r->padIndex].pressed & 0x9000) {
                                goto set0;
                            }
                            if (tb[r->padIndex].cross > 0) {
                                r->waitingInput = 0;
                                r->choicesDone++;
                                Flag_Set(0x10, 1);
                                Flag_Set(0x11, r->choiceCursor);
                                Snd_PlayById(0xA, 0);
                            }
                        cntF8:
                            nF8++;
                            goto next;
                        case 1:
                            c = 0x53;
                            if (r->choiceCursor == 0) {
                                goto draw;
                            }
                            break;
                        case 2:
                            c = 0x53;
                            if (r->choiceCursor == 1) {
                                goto draw;
                            }
                            break;
                        }
                    }
                    pos.field_0 += r->charAdvance;
                    break;
                case 0xF6:
                case 0xF7:
                    isF6 = *s == 0xF6;
                    mode2 = Sys_State.gameMode / 256 == 2;
                    s++;
                    if (r->cmdF6Done == nF6) {
                        switch (a0->stateLevel1) {
                        case 0:
                        default:
                            for (j = 0, np = nums; j < 3; j++) {
                                *np = *s++ * 100;
                                *np += *s++ * 10;
                                *np += *s++;
                                np++;
                            }
                            if (mode2) {
                                Stg40_TextObjCommand(nums);
                            } else {
                                h = Stg20_FindWalkerByDigiId(nums[0]);
                                wk->moveActor = h;
                                Stg20_WalkerWarpToCell(h, &nums[1]);
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            break;
                        }
                        if (mode2 == 0) {
                            if (isF6 == 0 || Stg20_WalkerIsPathDone(wk->moveActor) != 0) {
                                goto advF6;
                            }
                            goto nextF6;
                        }
                        if (Stg40_IsTextObjCmdBusy() != 0) {
                            goto nextF6;
                        }
                    advF6:
                        r->waitingInput = 0;
                        r->cmdF6Done++;
                        Task_SetState1(a0, 0);
                    } else {
                        s += 8;
                    }
                nextF6:
                    nF6++;
                    break;
                case 0xF5:
                    if (r->pausesDone == nF5) {
                        if (wk->waitTimer == 0x1E) {
                            stop = 1;
                            r->pausesDone = nF5 + 1;
                            r->waitingInput = 0;
                            wk->waitTimer = 0;
                        } else {
                            stop = 1;
                            wk->waitTimer++;
                            r->waitingInput = 1;
                        }
                    }
                    nF5++;
                    break;
                case 0xF4:
                    s++;
                    k4 = *s;
                    s++;
                    if (k4 < 0x10) {
                        if (r->cmdF4ObjDone == nF4a) {
                            s32 d0, d1;
                            d0 = *s++;
                            d1 = *s++;
                            h = Stg20_FindWalkerByDigiId(d0 * 100 + d1 * 10 + *s);
                            if (h != 0) {
                                Stg20_WalkerSetAnim(h, k4 + 0x1E);
                            }
                            r->cmdF4ObjDone++;
                        } else {
                            s += 2;
                        }
                        nF4a++;
                    } else if (k4 < 0x20) {
                        if (r->cmdF4TurnDone == nF4b) {
                            s32 n;
                            n = *s++ * 100;
                            n += *s++ * 10;
                            do {} while (0);
                            k4 = (k4 - 0x10) << 10;
                            h = Stg20_FindWalkerByDigiId(n + *s);
                            if (h != 0) {
                                h->transform->rotY = k4;
                            }
                            r->cmdF4TurnDone++;
                        } else {
                            s += 2;
                        }
                        nF4b++;
                    } else if (k4 < 0x30) {
                        if (r->cmdF4TaskDone == nF4c) {
                            switch (a0->stateLevel1) {
                            case 0:
                            default:
                                num[0] = k4 & 0xF;
                                num[1] = 0;
                                Task_Create(0x16, (s32 *)&slots->task, (s32)num);
                                a0->stateLevel1++;
                                r->waitingInput = 1;
                                break;
                            case 1:
                                s += 2;
                                if (slots->task == 0) {
                                    a0->stateLevel1 = 0;
                                    r->waitingInput = 0;
                                    r->cmdF4TaskDone++;
                                }
                                break;
                            }
                        } else {
                            s--;
                        }
                        nF4c++;
                    } else if (k4 < 0x40) {
                        r->color = k4 & 0xF;
                        s--;
                    } else {
                        k4 &= 0xF;
                        if (r->soundsDone == nF4d) {
                            if (k4 != 7) {
                                Snd_PlayById(Text_SfxIds[k4], 0);
                            }
                            r->soundsDone++;
                            if (k4 == 4) {
                                Stg20_StartBgShake();
                            }
                        }
                        s--;
                        nF4d++;
                    }
                    break;
                case 0xF3:
                    stop = 1;
                    s++;
                    switch (a0->stateLevel1) {
                    case 0:
                    default:
                        Gfx_FadeOutToBlack(0xA);
                        Task_NextState1(a0);
                        break;
                    case 1:
                        break;
                    }
                    if (++a0->stateLevel2 >= 0x19) {
                        if (*s == 0xFC) {
                            Sys_State.nextGameMode = 0x605;
                        } else if (*s == 0xFD) {
                            Sys_State.nextGameMode = 0x500;
                        } else if (*s == 0xFE) {
                            Sys_State.nextGameMode = 0x404;
                        } else if (*s == 0xFF) {
                            Sys_State.nextGameMode = 0x405;
                        } else {
                            Sys_State.nextGameMode = *s + 0x300;
                        }
                        s++;
                        Sys_State.modeArg = *s;
                    }
                    break;
                case 0xF2:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        Text_PushReturn((s32)(s + 1));
                        line--;
                        s = (u8 *)Item_GetNameText(n) - 1;
                    }
                    break;
                case 0xF1:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        Text_PushReturn((s32)(s + 1));
                        line--;
                        s = Digi_GetDefaultName(n) - 1;
                    }
                    break;
                case 0xF0:
                    s++;
                    k = *s;
                    Text_PushReturn((s32)(s + 1));
                    switch (k) {
                    case 0:
                        s = Save_GameState.playerName - 1; /* text before the player name */
                        break;
                    case 5:
                        s = Save_GameState.field_D1 - 1; /* text before the name at 0xD1 */
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        {
                            s32 *args = &r->strArg0;
                            s32 jj = k - 1;
                            s = (u8 *)args[jj] - 1;
                        }
                        break;
                    default:
                        s = Text_BuiltinStrings[k - 6] - 1;
                        break;
                    }
                    line--;
                    break;
                case 0xEF:
                    do {
                        s++;
                        c = *s + 0xF0;
                        goto draw;
                    } while (0);
                default:
                    c = *s;
                draw:
                    if (r->bigFont != 0) {
                        if ((s16)c >= 0x88) {
                            c -= 0x88;
                            page = 1;
                        } else {
                            page = 0;
                        }
                    }
                    pkt->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
                    pkt->tag.b.len = 9;
                    pkt->c.code = 0x2C;
                    pkt->x0 = pkt->x2 = pos.field_0;
                    pkt->x1 = pkt->x3 = pkt->x0 + glyph.field_0;
                    pkt->y0 = pkt->y1 = pos.field_2;
                    pkt->y2 = pkt->y3 = pkt->y0 + glyph.field_2;
                    pkt->u0 = pkt->u2 = font[page]->uOffset + ((s16)c % cols) * cell.field_0;
                    pkt->u1 = pkt->u3 = pkt->u0 + glyph.field_0;
                    pkt->v0 = pkt->v1 = ((s16)c / cols) * cell.field_2;
                    pkt->v2 = pkt->v3 = pkt->v0 + glyph.field_2;
                    pkt->clut = ((font[page]->vramY + (r->color + 0xF8)) << 6) | ((font[page]->vramX >> 4) & 0x3F);
                    pkt->tpage = font[page]->tpage;
                    if (Sys_State.centerX.s == 0x140) {
                        pkt->x0 *= 2;
                        pkt->x1 *= 2;
                        pkt->x2 *= 2;
                        pkt->x3 *= 2;
                    }
                    if (Sys_State.centerY.s == 0xF0) {
                        pkt->y0 *= 2;
                        pkt->y1 *= 2;
                        pkt->y2 *= 2;
                        pkt->y3 *= 2;
                    }
                    pkt->tag.word = (pkt->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
                    *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                    pkt++;
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                }
            next:
                s++;
                if (stop != 0) {
                    break;
                }
            } while (r->charDelay == 0 || ++line < r->visibleChars);
        }
    } while (++row < 0x32);
    Sys_State.packet.addr = (s32)pkt;
}

void Text_Close(s32 *slot) {
    TaskEntry *e;
    Actor *a;
    s32 i;
    TextBox *r;
    Actor **q;

    if (*slot == -1) {
        return;
    }
    e = Task_FindFirst(9, -1, -1);
    if (e != 0) {
        i = *slot;
        r = &e->work[i];
        q = &e->children[i];
        r->inUse = 0;
        a = q[1];
        if (a != 0) {
            Task_SetState0(a, 3);
        }
        *slot = -1;
    }
}

void Text_Open(void *arg0, TextOpenArgs *arg1) {
    TextOpenSrc *src = (TextOpenSrc *)arg1;
    TaskEntry *r;
    TextBox *base;
    TextBox *p;
    TextBox *rec;
    s32 i;

    r = Task_FindFirst(9, -1, -1);
    if (r == 0) {
        return;
    }
    i = 0;
    base = r->work;
    Text_Close(arg0);

    for (p = base; i < 0x32; i++, p++) {
        if (p->inUse == 0) {
            break;
        }
    }

    if (src->charAdvance == 0) {
        if (src->bigFont != 0) {
            src->charAdvance = 9;
        } else {
            src->charAdvance = 7;
        }
    }
    if (src->lineAdvance == 0) {
        if (src->bigFont != 0) {
            src->lineAdvance = 0xF;
        } else {
            src->lineAdvance = 0xA;
        }
    }

    rec = &base[i];
    rec->inUse = 1;
    rec->bigFont = *(u8 *)&src->bigFont;
    rec->color = *(u8 *)&src->color;
    rec->text = src->text;
    rec->x = src->x - 0xA0;
    rec->y = src->y - 0x78;
    rec->charAdvance = *(u8 *)&src->charAdvance;
    rec->lineAdvance = *(u8 *)&src->lineAdvance;
    rec->charDelay = *(u16 *)&src->charDelay;
    rec->strArg0 = src->strArg0;
    rec->strArg1 = src->strArg1;
    rec->strArg2 = src->strArg2;
    rec->strArg3 = src->strArg3;
    rec->baseColor = *(u8 *)&src->color;
    rec->delayTimer = *(u8 *)&src->charDelay;
    rec->visibleChars = 0;
    rec->finished = 0;
    rec->cmdFADone = 0;
    rec->cmdFBDone = 0;
    rec->waitingInput = 0;
    rec->cmdF9Done = 0;
    rec->choicesDone = 0;
    rec->choiceCursor = 0;
    rec->cmdF6Done = 0;
    rec->pausesDone = 0;
    rec->cmdF4TurnDone = 0;
    rec->cmdF4ObjDone = 0;
    rec->cmdF4TaskDone = 0;
    rec->soundsDone = 0;
    rec->padIndex = 0;
    rec->otIndex = 0;

    *(s32 *)arg0 = i;
}

s32 Text_IsFinished(s32 id) {
    TaskEntry *p;

    if (id == -1) {
        return 1;
    }
    p = Task_FindFirst(9, -1, -1);
    if (p != 0) {
        TextBox *w = &p->work[id];
        return w->finished;
    }
    return 0;
}

void Text_SetColor(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->baseColor = a1;
        r->color = a1;
    }
}

void Text_SetInputPad(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->padIndex = a1;
    }
}

void Text_SetOtLayer(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->otIndex = a1;
    }
}

void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3) {
    TextOpenArgs local;
    local.text = (s32)Cd_GetFileEntry(a1 + 0x1FD0000);
    local.bigFont = 0;
    local.color = a2;
    local.x = a3.lo;
    local.y = a3.hi;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = 0;
    Text_Open(a0, &local);
}

void Text_OpenMsgClearChoice(void *arg0, s32 arg1) {
    TextOpenArgs local;
    local.bigFont = 1;
    local.color = 0;
    local.x = 0;
    local.y = 0;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.text = arg1;
    local.charDelay = 1;
    Text_Open(arg0, &local);
    Flag_Set(0x10, 0);
}

void Mem_FillWordsNeg1(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        *arg0++ = -1;
    }
}

void Text_CloseArray(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        Text_Close(arg0);
        arg0++;
    }
}
