#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabModeSelUpdate(Actor *a);
void Stg20_LabModeSelDraw(Actor *a);

TaskDesc Stg20_LabModeSelDesc = { 0, Stg20_LabModeSelUpdate, Task_DefaultDestroy, Stg20_LabModeSelDraw, 0xC, 0 };

const Halves Stg20_LabDigivolveTextPos = { 0x1B, 0x18 };
const Halves Stg20_LabDnaTextPos = { 0x51, 0x18 };
void Stg20_LabModeSelUpdate(Actor *a)
{
  Stg20YesNoWork *w = (Stg20YesNoWork *) a->work;
  switch (a->stateLevel0)
  {
    case 0:
      w->sel = Stg20_MenuState.labMode != 0;
      Mem_FillWordsNeg1(w->texts, 2);
      Text_OpenById(&w->texts[0], 0x102, 0, Stg20_LabDigivolveTextPos);
      Text_OpenById(&w->texts[1], 0x103, 0, Stg20_LabDnaTextPos);
      Task_NextState0(a);
      break;

    case 1:
      if (Pad_State[0].left > 0)
    {
      if (w->sel == 0)
      {
        break;
      }
      w->sel = 0;
      Snd_PlayById(0xC, 0);
    }
    else
      if (Pad_State[0].right > 0)
    {
      if (w->sel != 0)
      {
        break;
      }
      w->sel = 1;
      Snd_PlayById(0xC, 0);
    }
    else
      if (Pad_State[0].triangle <= 0)
    {
 do { if (Pad_State[0].cross > 0) { Stg20_MenuState.result = 0; Stg20_MenuState.labMode = w->sel; Snd_PlayById(0xA, 0); Task_NextState0(a); } } while (0);
    }
    else
    {
      Stg20_MenuState.result = 1;
      Stg20_MenuState.labMode = w->sel;
      Snd_PlayById(0xB, 0);
      Task_NextState0(a);
    }
      break;

    case 2:
      Text_CloseArray(w->texts, 2);
      Task_NextState0(a);
      break;

  }

}

void Stg20_LabModeSelDraw(Actor *a) {
    Stg20BlinkTask *t = (Stg20BlinkTask *)a;
    Stg20Work *w = t->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = w->field_0 * 0x36 - 0x8E;
            q->y = -0x60;
            q->visible = ((t->frameCount >> 4) ^ 1) & 1;
        }
    }
    Gfx_DrawParts((s32)p);
}
