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

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_WindowTestTask(Actor *arg0);
void Stg00_WindowTestDraw(Actor *arg0);

s32 Stg00_WindowTestMasks[] = { 0xA2C, 0x8B2, 0x2CA };
Stg00PartMasks Stg00_WindowTestParts[] = {
    { 0x80, 0x100, 0x180, 0x1E00 },
    { 0x200, 0x400, 0x600, 0x1980 },
    { 0x800, 0x1000, 0x1800, 0x780 },
};
TaskDesc Stg00_WindowTestDesc = { 0, Stg00_WindowTestTask, Task_DefaultDestroy, Stg00_WindowTestDraw, 0x10, 0 };

void Stg00_WindowTestTask(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    s32 i;
    s32 n;

    switch (arg0->stateLevel0) {
    case 0:
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        if (Pad_State[0].up > 0) {
            if (w->cursor == 0) {
                break;
            }
            w->cursor--;
            w->holdDelay = 0x3C;
        } else if (Pad_State[0].down > 0) {
            if (w->cursor == 2) {
                break;
            }
            w->cursor++;
            w->holdDelay = 0x3C;
        } else {
            n = 5;
            for (i = 5; i >= 0; i--) {
                if (i == 5) {
                    w->counterDigits[n]++;
                }
                if (w->counterDigits[i] >= 10) {
                    w->counterDigits[i] -= 10;
                    if (i != 0) {
                        w->counterDigits[i - 1]++;
                    }
                }
            }
        }
        break;
    case 2:
        break;
    }
}

void Stg00_WindowTestDraw(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    EntA0 *e = Cd_GetFileEntry(0x770000);
    Stg00Part *p;

    Gfx_HidePartsByMask(e, Stg00_WindowTestMasks[w->cursor]);
    p = (Stg00Part *)e;
    while (p->fileId != 0) {
        if (p->partMask & Stg00_WindowTestParts[w->cursor].spinMask) {
            p->unscaled = 0;
            if (w->holdDelay != 0) {
                w->holdDelay--;
            } else {
                p->rotX += 0x20;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].frontMask) {
            if ((p->rotX + 0x400) & 0x800) {
                p->visible = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].backMask) {
            if ((p->rotX - 0x418) & 0x800) {
                p->visible = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].resetMask) {
            p->unscaled = 1;
            p->rotX = 0;
        }
        p++;
    }
    Gfx_DrawParts(e);
}
