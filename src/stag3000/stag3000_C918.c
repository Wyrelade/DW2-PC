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

void func_8006FC78(Actor *a0)
{
  Stg30Work73358W *w = (Stg30Work73358W *) a0->work;
  switch (a0->stateLevel0)
  {
    case 0:
      if (D_80073CC0.field_2AC[2].field_0 == 3)
    {
      w->field_10 = 2;
    }
      if (D_80073CC0.field_2AC[1].field_0 == 3)
    {
      w->field_10 = 1;
    }
      if (D_80073CC0.field_2AC[0].field_0 == 3)
    {
      w->field_10 = 0;
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
          w->field_4 = 7;
          w->field_0 = 0;
          w->field_2 = 0x334;
          Task_NextState2(a0);

        case 1:
          w->field_0 += 0x400;
          if (w->field_0 == 0x1000)
        {
          Task_NextState2(a0);
          case 2:
            w->field_2 += 0x200;

          if (w->field_2 >= 0x1000)
          {
            w->field_2 = 0x1000;
            Task_NextState2(a0);
            case 3:
              do
            {
              if (Pad_State[0].right > 0)
              {
                w->field_C = 1;
                Snd_PlayById(0x12, 0);
                break;
              }
              if (Pad_State[0].left > 0)
              {
                w->field_C = 0;
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
          if (w->field_4 == 7)
        {
          if (w->field_C != 0)
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
        if (w->field_4 != 7)
        {
          w->field_4++;
        }
      }
      else
        if (w->field_4 != 0)
      {
        w->field_4--;
      }
        break;

      case 1:
        D_80073CC0.field_3D4 = a0->stateLevel1;
        do
      {
        if (Pad_State[0].right > 0)
        {
          if (w->field_10 == 2)
          {
            if (1)
            {
            }
            break;
          }
          w->field_10++;
          Snd_PlayById(0x12, 0);
          break;
        }
        if (Pad_State[0].left > 0)
        {
          if (w->field_10 == 0)
          {
            break;
          }
          w->field_10--;
          Snd_PlayById(0x12, 0);
          break;
        }
        if (Pad_State[0].cross > 0)
        {
          if (D_80073CC0.field_2AC[w->field_10].field_0 != 3)
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
        w->field_8 = Math_PingPongRange(a0->elapsed, 2, 0, 3);
        break;

    }

      break;

    case 2:
      D_80073CC0.field_3D0 = w->field_10;
      D_80073CC0.field_3D4 = 0;
      Task_NextState0(a0);
      break;

  }

}
