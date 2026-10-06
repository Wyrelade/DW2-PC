#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_DigiViewTask(Actor *arg0);
void Stg00_DigiViewDraw(Actor *arg0);

/* Skill ids in list order, 0-terminated. */
u8 Stg00_DigiViewSkills[] = {
    0x66, 0xA6, 0x31, 0x5B, 0x2C, 0x48, 0x1B, 0x02, 0x06, 0xCA, 0xC8, 0xC9, 0xC7, 0x8A, 0xE3, 0xF7,
    0xC2, 0xD7, 0x0B, 0xA4, 0x0D, 0x40, 0x53, 0x03, 0xB4, 0x87, 0x3F, 0x3A, 0xE6, 0xC5, 0x38, 0x2B,
    0x44, 0xDC, 0xEB, 0xE5, 0x30, 0x72, 0xA3, 0xD0, 0x4E, 0x4A, 0x45, 0x70, 0xE4, 0xF0, 0xA5, 0xD1,
    0x1E, 0xF2, 0xF8, 0xF6, 0x50, 0xDE, 0x84, 0x17, 0x5D, 0x2F, 0x4B, 0x67, 0x2D, 0x46, 0x51, 0x05,
    0xA1, 0x8B, 0xF5, 0x1D, 0xB7, 0x85, 0x65, 0x07, 0x6A, 0x32, 0x14, 0x39, 0x26, 0x88, 0x86, 0xCC,
    0xDF, 0x60, 0x4D, 0xFB, 0xBD, 0x5E, 0xD3, 0x64, 0xBF, 0x36, 0x34, 0xDD, 0x52, 0x82, 0x56, 0x41,
    0x42, 0xE0, 0x43, 0x6B, 0x37, 0x3B, 0x58, 0xD4, 0x33, 0x1A, 0x18, 0xD5, 0x54, 0xC6, 0x15, 0x6D,
    0x10, 0x22, 0x4C, 0xED, 0x55, 0xBE, 0x1C, 0xD2, 0x61, 0xD6, 0x0A, 0x2E, 0x0C, 0x5C, 0x6C, 0xEF,
    0x89, 0xBA, 0xBB, 0xEC, 0x69, 0xCE, 0x6E, 0x11, 0x35, 0x3C, 0xE2, 0x6F, 0x0E, 0xD9, 0xB8, 0xF4,
    0xF1, 0x25, 0xD8, 0x19, 0x4F, 0x2A, 0x21, 0xBC, 0x08, 0x12, 0x71, 0x3D, 0x47, 0x57, 0x73, 0xDA,
    0xCD, 0xC3, 0xCF, 0xE7, 0x16, 0x0F, 0x8C, 0x1F, 0x28, 0xB5, 0xB9, 0x01, 0x62, 0x29, 0x63, 0xA2,
    0xC0, 0x5A, 0x04, 0x23, 0xE1, 0x20, 0xC1, 0xEA, 0x68, 0x59, 0xDB, 0xCB, 0xA0, 0x24, 0x27, 0x83,
    0xE9, 0xF3, 0x49, 0xB6, 0x3E, 0xF9, 0xC4, 0x09, 0xA8, 0xA7, 0xEE, 0xE8, 0x13, 0x5F, 0x00, 0x00,
};
Stg00DigiViewPage Stg00_DigiViewPages[] = {
    { 0x010B0001, 7 },
    { 0x010B0002, 0 },
    { 0x010B0003, 6 },
    { 0x010B0004, 2 },
};
u8 Stg00_DigiViewPage2Anims[][4] = { { 0x28 }, { 0x29 }, { 0x2A }, { 0x2B }, { 0x2C }, { 0x2D }, { 0x2E } };
u8 Stg00_DigiViewPage3Anims[][4] = { { 0x1E }, { 0x1F }, { 0x20 } };
TaskDesc Stg00_DigiViewDesc = { 0, Stg00_DigiViewTask, Task_DefaultDestroy, Stg00_DigiViewDraw, 0x68, 0x18 };

void Stg00_DigiViewSpawnModel(Actor *arg0) {
    Stg00NameWork *w = (Stg00NameWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    Stg00TaskArgs5 args;
    TextOpenArgs t;

    while ((id = Digi_GetModelListId(w->modelListIdx)) == -1) {
        w->modelListIdx = 0;
    }
    Task_Destroy(slot);
    args.digiId = id;
    args.facing = 0;
    args.posX = 0;
    args.posY = 0;
    args.posZ = 0;
    Task_Create(0x105, slot, (s32)&args);
    Text_Close(&w->nameText);
    Text_Close(&w->nameTextSmall);
    t.text = (s32)Digi_GetDefaultName(Digi_GetModelListId(w->modelListIdx));
    t.bigFont = 1;
    t.color = 0;
    t.x = 0x10;
    t.y = 0xD0;
    t.charDelay = 0xE;
    t.charAdvance = 0;
    t.lineAdvance = 0;
    Text_Open(&w->nameText, &t);
    t.y = 0xC6;
    t.charDelay = 8;
    t.bigFont = 0;
    t.charAdvance = 9;
    Text_Open(&w->nameTextSmall, &t);
}

void Stg00_DigiViewTask(Actor *arg0)
{
  Stg00DigiViewWork *work;
  Actor *cam;
  Actor *s1;
  s32 i;
  s32 j;
  s32 k;
  s32 count;
  s32 v0;
  s32 v1;
  work = (Stg00DigiViewWork *) arg0->work;
  if (arg0->stateLevel0 == 1)
  {
    goto state1;
  }
  if (arg0->stateLevel0 >= 2)
  {
    return;
  }
  if (arg0->stateLevel0 != 0)
  {
    return;
  }
  work->panel = 0;
  work->digiCursor = 0;
  work->pageCursor = 0;
  work->page = 0;
  work->drawTex = 1;
  Mem_FillWordsNeg1(&work->nameText, 0x10);
  Stg00_DigiViewSpawnModel(arg0);
  Task_NextState0(arg0);
  return;
  state1:
  {
    switch (arg0->stateLevel1)
    {
      case 0:

      default:
        cam = (Actor *) Stg00_FindCamera();
        for (i = 0; i < Sys_State.frameDelta; i++)
      {
        if (Pad_State[0].right)
        {
          Stg00_CamRotate(cam, 0, 0x20, 0);
        }
        else
          if (Pad_State[0].left)
        {
          Stg00_CamRotate(cam, 0, -0x20, 0);
        }
        if (Pad_State[0].up)
        {
          Stg00_CamMoveViewPoint(cam, 0, 0, -0x20);
        }
        else
          if (Pad_State[0].down)
        {
          Stg00_CamMoveViewPoint(cam, 0, 0, 0x20);
        }
        if (Pad_State[0].triangle)
        {
          Stg00_CamMoveViewPoint(cam, 0, -0x20, 0);
        }
        else
          if (Pad_State[0].cross)
        {
          Stg00_CamMoveViewPoint(cam, 0, 0x20, 0);
        }
        if (Pad_State[0].r1)
        {
          Stg00_CamMoveRefPoint(cam, 0, -0x20, 0);
        }
        else
          if (Pad_State[0].l1)
        {
          Stg00_CamMoveRefPoint(cam, 0, 0x20, 0);
        }
      }

        if (Pad_Circle > 0)
      {
        ((Stg00ActorTimer *) arg0)->frameCount = 0;
        Task_NextState1(arg0);
      }
        break;

      case 1:
        if ((work->page == 1) && (work->panel == 1))
      {
        if (Pad_Repeat & 0x1000)
        {
          work->lastDirUp = work->panel;
          if (work->skillRow != 0)
          {
            work->skillRow -= 1;
          }
          else
            if (work->skillScroll != 0)
          {
            work->skillScroll -= 1;
          }
        }
        if (Pad_Repeat & 0x4000)
        {
          work->lastDirUp = 0;
          if (work->skillRow != 0xD)
          {
            work->skillRow += 1;
          }
          else
            if (Stg00_DigiViewSkills[work->skillScroll + 0xE] != 0)
          {
            work->skillScroll += 1;
          }
        }
        if (Pad_Repeat & 0x8000)
        {
          for (k = 0; k < 0xE; k++)
          {
            if (work->lastDirUp != 0)
            {
              if (work->skillRow != 0)
              {
                work->skillRow -= 1;
              }
              else
                if (work->skillScroll != 0)
              {
                work->skillScroll -= 1;
              }
            }
            else
              if (work->skillRow != 0xD)
            {
              work->skillRow += 1;
            }
            else
              if (Stg00_DigiViewSkills[work->skillScroll + 0xE] != 0)
            {
              work->skillScroll += 1;
            }
          }

        }
      }
        if (Pad_State[0].up > 0)
      {
        if (((Work65E24Slots *) work)->words[work->panel] != 0)
        {
          ((Work65E24Slots *) work)->words[work->panel] -= 1;
          goto clearElapsed1;
        }
      }
      else
        if (Pad_State[0].down > 0)
      {
        if (work->panel == 0)
        {
          if (work->digiCursor != 3)
          {
            work->digiCursor += 1;
            goto clearElapsed1;
          }
        }
        else
        {
          Stg00DigiViewPage *e = &Stg00_DigiViewPages[work->page];
          if (work->pageCursor != e->maxRow)
          {
            work->pageCursor += 1;
            clearElapsed1:
            arg0->elapsed = 0;

          }
        }
      }
        if (Pad_State[0].right > 0)
      {
        if (work->panel == 1)
        {
          work->panel = 0;
          goto clearElapsed2;
        }
      }
      else
      {
        do
        {
          if (Pad_State[0].left > 0)
          {
            if (work->panel == 0)
            {
              work->panel = 1;
              clearElapsed2:
              arg0->elapsed = 0;
            }
          }
        }
        while (0);
      }
        if (Pad_Square > 0)
      {
        work->page += 1;
        if (work->page == 4)
        {
          work->page = 0;
        }
        work->pageCursor = 0;
      }
        if (Pad_Circle > 0)
      {
        if (work->panel != 0)
        {
          goto findFirstSection;
        }
        count = 1;
        if (work->digiCursor == 0)
        {
          count = 8;
        }
        if (work->digiCursor == 3)
        {
          count = 8;
        }
        j = 0;
        if (count != 0)
        {
          do
          {
            v1 = ((Work65E24Slots *) work)->words[work->panel];
            if (v1 < 0)
            {
              goto rangeElse;
            }
            if (v1 < 2)
            {
              goto rangeElse;
            }
            if (v1 < 4)
            {
              goto rangeThen;
            }
            rangeElse:
            if (work->modelListIdx != 0)
            {
              v0 = work->modelListIdx - 1;
            }
            else
            {
              v0 = Digi_GetModelListCount() - 1;
            }

            goto storeAndUse;
            rangeThen:
            v0 = Digi_GetModelListCount() - 1;

            v1 = work->modelListIdx;
            if (v0 == v1)
            {
              work->modelListIdx = 0;
              goto useField10;
            }
            v0 = v1 + 1;
            storeAndUse:
            work->modelListIdx = v0;

            useField10:
            Digi_GetModelListId(work->modelListIdx);

            j++;
          }
          while (j < count);
        }
        do
        {
          Stg00_DigiViewSpawnModel(arg0);
          goto afterD700;
        }
        while (0);
        findFirstSection:
        s1 = (Actor *) Task_FindFirst(0x105, -1, -1);

        if (s1 != ((void *) 0))
        {
          switch (work->page)
          {
            case 0:
              Task_SetState01(s1, 2, ((Work65E24Slots *) work)->bytes[work->panel * 4]);
              break;

            case 1:
              Text_CloseArray(work->skillTexts, 0xE);
              Task_SetState01(s1, 2, 0xA);
              Task_SetState4(s1, Stg00_DigiViewSkills[work->skillScroll + work->skillRow]);
              break;

            case 2:
              Task_SetState01(s1, 2, 0xFF);
              Task_SetState2(s1, Stg00_DigiViewPage2Anims[work->pageCursor][0]);
              break;

            case 3:
              Task_SetState01(s1, 2, 0xFF);
              Task_SetState2(s1, Stg00_DigiViewPage3Anims[work->pageCursor][0]);
              break;

          }

          Task_SetState1(arg0, 0);
        }
        afterD700:
        ;

        ;
      }
        break;

    }

    if (D_8005F724 > 0)
    {
      s32 *ch;
      work = (Stg00DigiViewWork *) arg0->work;
      ch = (s32 *) arg0->u34.children;
      if (work->drawTex != 0)
      {
        Task_SetState01((Actor *) ch[0], 2, 8);
        work->drawTex = 0;
        return;
      }
      Task_SetState01((Actor *) ch[0], 2, 9);
      work->drawTex = 1;
    }
  }

}

void Stg00_DigiViewDraw(Actor *arg0) {
    s32 period;
    Stg00DigiViewWork *w = (Stg00DigiViewWork *)arg0->work;
    EntA0 *parts;
    TextOpenArgs args;
    s32 fp = 0;
    s32 e;
    s32 mask;
    s32 i;
    s32 s5;
    s32 s6;
    s32 s7;
    EntA0 *parts2;
    s32 col;

    if (arg0->stateLevel0 == 1 && arg0->stateLevel1 == 0) {
        return;
    }
    e = arg0->elapsed;
    if (e < 0x14) {
        fp = 1;
    } else {
        period = 0x28;
        if (e >= period) {
            arg0->elapsed = e - period;
        }
    }
    parts = Cd_GetFileEntry(0x10B0000);
    mask = 0;
    if (fp && w->panel == 0) {
        mask = 1 << (w->digiCursor + 1);
    }
    Gfx_HidePartsByMask(parts, mask);
    Gfx_SetPartsNumber(parts, 0x20, 4, Digi_GetModelListId(w->modelListIdx));
    Gfx_DrawParts(parts);
    parts = Cd_GetFileEntry(Stg00_DigiViewPages[w->page].partsFileId);
    parts2 = parts;
    mask = 0;
    if (fp && w->panel == 1) {
        mask = 1 << (w->pageCursor + 1);
    }
    Gfx_HidePartsByMask(parts2, mask);
    Gfx_DrawParts(parts2);
    for (i = 0; i < 0xE; i++) {
        Text_Close(&w->skillTexts[i]);
    }

    if (w->page != 1) {
        return;
    }
    s6 = w->skillScroll;
    i = 0;
    for (s5 = 0, s7 = 0x10; s5 <= 0; s5++, s7 += 0x6E) {
        s32 y;
        for (col = 0, y = 0x3A; col < 0xE; col++, y += 9) {
            args.text = Skill_GetNameText(Stg00_DigiViewSkills[s6++]);
            args.bigFont = 0;
            args.x = s7;
            args.y = y;
            args.charDelay = 0;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            if (w->field_60 == s5 && w->skillRow == col) {
                if (fp && w->panel == 1) {
                    continue;
                }
                args.color = 4;
            } else {
                args.color = 0;
            }
            Text_Open(&w->skillTexts[i], &args);
            i++;
        }
    }
}
