#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"

/* Task callbacks the descriptor below needs (defined further down). */
void Stg30_InterruptSelectTask(Actor *a0);
void Stg30_InterruptSelectDraw(Actor *a0);

s32 Stg30_InterruptCursorMasks[] = { 2, 4, 8, 0x10, 0x20, 0x40 };
TaskDesc Stg30_InterruptSelectDesc = {
    0, Stg30_InterruptSelectTask, Task_DefaultDestroy, Stg30_InterruptSelectDraw, 0x14, 0,
};
/* Task_DescTable[5]: task ids 0x500-0x513. */
TaskDesc *Stg30_TaskDescs[] = {
    &Stg30_BattleDesc, &Stg30_FighterHudDesc, &Stg30_ResultDesc, &Stg30_CameraDesc, &Stg30_CommandMenuDesc,
    &Stg30_BannerDesc, &Stg30_ItemMenuDesc, &Stg30_SkillMenuDesc, &Stg30_TargetSelectDesc, &Stg30_FighterDesc,
    &Stg30_FightBgDesc, &Stg30_CommandInputDesc, &Stg30_FightMsgDesc, &Stg30_PopupDesc,
    &Stg30_ActionLoadDesc, &Stg30_BattleScriptDesc, &Stg30_InterruptSelectDesc, &Stg30_XaPlayDesc,
    &Stg30_SkillLearnDesc, &Stg30_JoinPromptDesc,
};

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

void Stg30_InterruptSelectDraw(Actor *a0) {
    Stg30InterruptSelectWork *w = (Stg30InterruptSelectWork *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    Stg30Part *r;
    s32 k;

    if (a0->stateLevel0 == 1 && a0->stateLevel1 == 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10008);
        for (q = p; q->fileId != 0; q++) {
            q->scaleX = w->scaleX;
            q->scaleY = w->scaleY;
            q->palette = w->palette;
            if (w->choice == 0) {
                switch (q->groupMask) {
                case 0x10:
                    q->visible = 0;
                    break;
                case 4:
                    q->visible = ((u32)Sys_State.frameCount >> 1) & 1;
                    break;
                case 8:
                    q->visible = (((u32)Sys_State.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            } else {
                switch (q->groupMask) {
                case 4:
                    q->visible = 0;
                    break;
                case 0x10:
                    q->visible = ((u32)Sys_State.frameCount >> 1) & 1;
                    break;
                case 0x20:
                    q->visible = (((u32)Sys_State.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    if (Stg30_Battle.interruptActive != 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A1000B);
        k = w->slot;
        if (Stg30_Battle.turns[k].turnType != 3) {
            k += 3;
        }
        for (r = p; r->fileId != 0; r++) {
            if (r->groupMask & Stg30_InterruptCursorMasks[k]) {
                r->visible = 1;
                r->palette = w->cursorPalette;
            } else {
                r->visible = 0;
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

void Stg30_InitBattle(void) {
    Mem_Zero(&Stg30_Battle, 0x3E0);
    Stg30_Battle.interruptActive = 1;
    if ((Sys_State.prevGameMode & 0xFF00) == 0x300) {
        Dung_State.floorSpecialty = 0;
        Dung_State.giftLevel = 0;
        Stg30_Battle.entries[0].fromCity = 1;
    }
    if (Sys_State.modeArg == 0x97 && Flag_Test(0x88)) {
        Sys_State.modeArg++;
    }
    D_80074098 = 4;
}
