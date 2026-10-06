#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"
#include "stag0000/font.h"
#include "stag0000/fightbg.h"
#include "stag0000/digiview.h"
#include "stag0000/lineup.h"
#include "stag0000/videomode.h"
#include "stag0000/groupview.h"
#include "stag0000/digimodel.h"
#include "stag0000/soundlist.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_SoundTestTask(Actor *arg0);
void Stg00_SoundTestDraw(void);

/* "SOUNDTEST  VAB SEQ" in the game's glyph encoding (0x0A 'A', 0xFE space, 0xFF end). */
u8 Stg00_SoundTestTitle[] = {
    0x1C, 0x18, 0x1E, 0x17, 0x0D, 0x1D, 0x0E, 0x1C, 0x1D, 0xFE, 0xFE, 0x1F, 0x0A, 0x0B, 0xFE, 0x1C, 0x0E, 0x1A, 0xFF,
};
TaskDesc Stg00_SoundTestDesc = {
    0, Stg00_SoundTestTask, Task_DefaultDestroy, (TaskFn)Stg00_SoundTestDraw, 0x1C, 0,
};

void Stg00_SoundTestTask(Actor *arg0) {
    Stg00SndWork *w = (Stg00SndWork *)arg0->work;
    TextOpenArgs t;

    switch (arg0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->titleText, 3);
        Snd_UnloadSlot(1);
        Snd_UnloadSlot(2);
        w->loadedBank = -1;
        Task_NextState0(arg0);
        break;
    load:
        w->loadedBank = w->bank;
        Snd_SetSlotContent(0, w->bank + 1);
        w->pendingSound = w->sound;
        Task_SetState1(arg0, 1);
        goto text;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Pad_State[0].right > 0) {
                w->bank++;
                if (w->bank == Stg00_CountSoundBanks()) {
                    w->bank = 0;
                }
                w->sound = 0;
            } else if (Pad_State[0].left > 0) {
                if (w->bank == 0) {
                    w->bank = Stg00_CountSoundBanks() - 1;
                } else {
                    w->bank--;
                }
                w->sound = 0;
            } else if (Pad_State[0].up > 0) {
                w->sound++;
                if (w->sound == Stg00_CountBankSounds(w->bank)) {
                    w->sound = 0;
                }
            } else if (Pad_State[0].down > 0) {
                if (w->sound == 0) {
                    w->sound = Stg00_CountBankSounds(w->bank) - 1;
                } else {
                    w->sound--;
                }
            } else if (Pad_State[0].circle > 0) {
                if (w->loadedBank == w->bank) {
                    Snd_PlayById(w->sound, 0);
                } else {
                    goto load;
                }
            } else if (Pad_State[0].cross > 0) {
                Snd_StopAll();
            }
        text:
            t.text = (s32)Stg00_SoundTestTitle;
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x28;
            t.y = 0x28;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->titleText, &t);
            t.text = (s32)Stg00_GetBankLabel(w->bank);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x50;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->bankText, &t);
            t.text = (s32)Stg00_GetSoundIdLabel(w->bank, w->sound);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x64;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->soundText, &t);
            break;
        case 1:
            if (!Snd_AnySlotLoading()) {
                Snd_PlayById(w->pendingSound, 0);
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_SoundTestDraw(void) {
}
