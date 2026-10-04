#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"
#include "stag3000/stag3000_96DC_funcs.h"
#include "stag3000/stag3000_9F8C_funcs.h"
#include "stag3000/stag3000_AF5C_funcs.h"

void Stg30_InterruptSelectTask(Actor *a0)
{
  Stg30Work73358W *w = (Stg30Work73358W *) a0->work;
  switch (a0->stateLevel0)
  {
    case 0:
      if (Stg30_Battle.turns[2].turnType == 3)
    {
      w->slot = 2;
    }
      if (Stg30_Battle.turns[1].turnType == 3)
    {
      w->slot = 1;
    }
      if (Stg30_Battle.turns[0].turnType == 3)
    {
      w->slot = 0;
    }
      Task_NextState0(a0);
      break;

    case 1:
      switch (a0->stateLevel1)
    {
      case 0:

      default:
        switch (a0->stateLevel2)
      {
        case 0:

        default:
          D_80074094 = 0;
          w->palette = 7;
          w->scaleX = 0;
          w->scaleY = 0x334;
          Task_NextState2(a0);

        case 1:
          w->scaleX += 0x400;
          if (w->scaleX == 0x1000)
        {
          Task_NextState2(a0);
          case 2:
            w->scaleY += 0x200;

          if (w->scaleY >= 0x1000)
          {
            w->scaleY = 0x1000;
            Task_NextState2(a0);
            case 3:
              do
            {
              if (Pad_State[0].right > 0)
              {
                w->choice = 1;
                Snd_PlayById(0x12, 0);
                break;
              }
              if (Pad_State[0].left > 0)
              {
                w->choice = 0;
                Snd_PlayById(0x12, 0);
                break;
              }
              if (Pad_State[0].cross > 0)
              {
                Task_NextState2(a0);
                Snd_PlayById(0xE, 0);
              }
            }
            while (0);

          }
        }
          break;

        case 4:
          if (w->palette == 7)
        {
          if (w->choice != 0)
          {
            Task_SetState0(a0, 3);
          }
          else
          {
            Task_NextState1(a0);
          }
        }
          break;

      }

        if (a0->stateLevel2 == 4)
      {
        if (w->palette != 7)
        {
          w->palette++;
        }
      }
      else
        if (w->palette != 0)
      {
        w->palette--;
      }
        break;

      case 1:
        Stg30_Battle.interruptActive = a0->stateLevel1;
        do
      {
        if (Pad_State[0].right > 0)
        {
          if (w->slot == 2)
          {
            if (1)
            {
            }
            break;
          }
          w->slot++;
          Snd_PlayById(0x12, 0);
          break;
        }
        if (Pad_State[0].left > 0)
        {
          if (w->slot == 0)
          {
            break;
          }
          w->slot--;
          Snd_PlayById(0x12, 0);
          break;
        }
        if (Pad_State[0].cross > 0)
        {
          if (Stg30_Battle.turns[w->slot].turnType != 3)
          {
            break;
          }
          Snd_PlayById(0xE, 0);
          Task_NextState0(a0);
          break;
        }
        if (Pad_State[0].triangle > 0)
        {
          Task_SetState1(a0, 0);
          Snd_PlayById(0xB, 0);
        }
      }
      while (0);
        w->cursorPalette = Math_PingPongRange(a0->elapsed, 2, 0, 3);
        break;

    }

      break;

    case 2:
      Stg30_Battle.interruptSlot = w->slot;
      Stg30_Battle.interruptActive = 0;
      Task_NextState0(a0);
      break;

  }

}
