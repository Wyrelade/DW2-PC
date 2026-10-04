#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"

/* Unnamed: empty stub, called once by Stg00_DungSelPickFlag before the warp, no other ref. */
void func_80064E44(void) {
}

void Stg00_FontSetColor(s16 arg0) {
    Stg00Work *w = Stg00_FontWork;
    if (arg0 < 6) {
        w->color = arg0;
    } else {
        w->color = 0;
    }
}

void Stg00_FontInit(void) {
    s32 i;
    s32 n;
    s32 fill;
    u8 *src;
    u16 *p;
    RECT *r;

    Stg00_FontWork = (Stg00Work *)Mem_Alloc(0x9D8, 2);
    Stg00_FontTextBuf = Stg00_FontWork->textBuf;
    Stg00_FontWork->texSlot = Gfx_ReserveTexSlot();
    n = 0x200;
    src = Stg00_FontGlyphs;
    r = &Stg00_FontWork->rectBig;
    r->x = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->x;
    r->y = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->y;
    r->w = 0x10;
    r->h = 0x40;
    r = (RECT *)&Stg00_FontWork->clutX;
    r->x = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->x;
    r->y = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->y + 0xF9;
    r->w = 0x10;
    r->h = 6;
    p = Stg00_FontWork->buf;
    fill = 0x2222;
    for (i = 0x3FF; i >= 0; i--) {
        p[i] = fill;
    }
    for (i = 0; i < n; i++, src++) {
        s32 k = (i / 64) * 128;

        k += (i % 8) * 16;
        k += ((i / 8) % 8) * 2;
        p[k] = 0;
        p[k] = *src >> 7;
        p[k] |= (*src & 0x40) ? 0x10 : 0;
        p[k] |= (*src & 0x20) ? 0x100 : 0;
        p[k] |= (*src & 0x10) ? 0x1000 : 0;
        p[k + 1] = 0;
        p[k + 1] = (*src >> 3) & 1;
        p[k + 1] |= (*src & 0x04) ? 0x10 : 0;
        p[k + 1] |= (*src & 0x02) ? 0x100 : 0;
        p[k + 1] |= (*src & 0x01) ? 0x1000 : 0;
    }
    p = Stg00_FontWork->clut;
    for (i = 0; i < 0x18; i++) {
        *p++ = 0;
        *p++ = 0;
        *p++ = 0;
        *p++ = 0;
    }
    p = Stg00_FontWork->clut;
    p[0x00] = 0x8000;
    p[0x10] = 0x8000;
    p[0x20] = 0x8000;
    p[0x01] = 0x3DEF;
    p[0x31] = 0x3DEF;
    p[0x11] = 0x0F;
    p[0x41] = 0x0F;
    p[0x21] = 0x3C00;
    p[0x51] = 0x3C00;
    LoadImage((RECT *)&Stg00_FontWork->clutX, (u32 *)Stg00_FontWork->clut);
    LoadImage(&Stg00_FontWork->rectBig, (u32 *)Stg00_FontWork->buf);
    Stg00_FontSetColor(0);
}

void Stg00_FontFree(void) {
    Gfx_ReleaseTexSlot(Stg00_FontWork->texSlot);
    Mem_Free((ActorWork *)Stg00_FontWork);
}

void Stg00_FontDrawStr(s32 arg0, s32 arg1, u8 *arg2)
{
    Stg00PolyFT4 *poly = (Stg00PolyFT4 *) Sys_State.packet.addr;
    Stg00OTag *ot = (Stg00OTag *) Sys_State.otLayers.s[0];
    Stg00Work *work = Stg00_FontWork;
    u8 ch;
    s32 x;
    s32 y = arg1 - Sys_State.centerY.s;
    Stg00TexSlot *tex;
    u16 clut;
    u16 tpage;
    s32 c;

    clut = ((work->clutY + work->color) << 6) | ((work->clutX >> 4) & 0x3F);
    tex = (Stg00TexSlot *) work->texSlot;
    x = arg0 - Sys_State.centerX.s;
    tpage = (1 << 5) | ((tex->y & 0x100) >> 4) | ((tex->x & 0x3FF) >> 6) | ((tex->y & 0x200) << 2);
    while ((ch = *arg2) != 0) {
        if ((u32) (ch - 0x20) < 0x50) {
            c = *arg2;
            if (c >= 0x60) {
                c -= 0x20;
            }
            c -= 0x20;
            poly->tag.b.len = 9;
            poly->code = 0x2C;
            poly->r0 = 0xFF;
            poly->g0 = 0xFF;
            poly->b0 = 0xFF;
            poly->tpage = tpage;
            poly->clut = clut;
            poly->u0 = c % 8 * 8 + ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u;
            poly->v0 = c / 8 * 8;
            poly->u1 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8 + 8;
            poly->v1 = c / 8 * 8;
            poly->u2 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8;
            poly->v2 = c / 8 * 8 + 8;
            poly->u3 = ((Stg00TexSlot *) Stg00_FontWork->texSlot)->u + c % 8 * 8 + 8;
            poly->v3 = c / 8 * 8 + 8;
            poly->x0 = x;
            poly->y0 = y;
            poly->x1 = x + 8;
            poly->y1 = y;
            poly->x2 = x;
            poly->y2 = y + 8;
            poly->x3 = x + 8;
            poly->y3 = y + 8;
            ((Stg00OTag *) &poly->tag)->addr = ot->addr;
            ot->addr = (u32) poly;
            poly++;
        }
        arg2++;
        x += 8;
    }
    Sys_PacketCursor = (s32) poly;
}

void Stg00_FontDrawSheet(void) {
    Stg00PolyFT4 *p = (Stg00PolyFT4 *)Sys_State.packet.work;
    u32 *ot = Sys_State.otLayers.u[0];
    Stg00Work *w;
    Stg00TexSlot *t;
    s32 h;

    p->tag.b.len = 9;
    p->code = 0x2C;
    p->r0 = 0xFF;
    p->g0 = 0xFF;
    p->b0 = 0xFF;
    w = Stg00_FontWork;
    t = (Stg00TexSlot *)w->texSlot;
    p->tpage = (0 << 7) | (1 << 5) | ((t->y & 0x100) >> 4) | ((t->x & 0x3FF) >> 6) | ((t->y & 0x200) << 2);
    p->clut = (w->clutY << 6) | ((w->clutX >> 4) & 0x3F);
    p->u0 = ((Stg00TexSlot *)w->texSlot)->u;
    p->v0 = 0;
    p->u1 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u + 0x40;
    p->v1 = 0;
    p->u2 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u;
    p->v2 = h = 0x40;
    p->u3 = ((Stg00TexSlot *)Stg00_FontWork->texSlot)->u + h;
    p->v3 = h;
    p->x0 = -0x20;
    p->y0 = -0x20;
    p->x1 = 0x20;
    p->y1 = -0x20;
    p->x2 = -0x20;
    p->y2 = 0x20;
    p->x3 = 0x20;
    p->y3 = 0x20;
    p->code &= ~2;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    p++;
    Sys_State.packet.work = (ActorWork *)p;
}

void Stg00_FontPrintBuf(s32 arg0, s32 arg1) {
    Stg00_FontDrawStr(arg0, arg1, Stg00_FontTextBuf);
}

void Stg00_FontPrintBufCentered(s32 arg0, s32 arg1) {
    Stg00_FontDrawStr(arg0 + Sys_State.centerX.s, arg1 + Sys_State.centerY.s, Stg00_FontTextBuf);
}

void Stg00_FightBgTask(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Actor_InitTransform(arg0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(arg0, 0x78)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void Stg00_FightBgDraw(Actor *arg0) {
    Gfx_AttachModel(arg0, 0x78);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

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

void Stg00_LineupSetVideoMode(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->videoMode) {
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        break;
    case 2:
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        break;
    case 1:
        Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
        break;
    case 0:
        Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
        break;
    }
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x100);
}

void Stg00_LineupSpawnModels(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 i;

    for (i = 0; i < 9; i++) {
        Task_Destroy(slot);
        args.digiId = w->digiIds[i + w->scrollTop];
        args.facing = 0x400;
        args.posX = Stg00_LineupLayouts[w->layout][i].posX;
        args.posY = 0;
        args.posZ = Stg00_LineupLayouts[w->layout][i].posZ;
        Task_Create(0x105, slot, (s32)&args);
        slot++;
    }
}

void Stg00_LineupBuildList(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 i;
    s32 id;
    s32 v;
    s32 j;
    s32 k;

    for (i = 0; (id = Digi_GetModelListId(i)) < 0x12D; i++) {
        v = func_8001E79C(id);
        j = 0;
        if (w->count != 0) {
            for (k = j; k < w->count; k++) {
                if (v < w->sortKeys[k]) {
                    break;
                }
            }
            j = k;
            for (k = w->count; k >= j; k--) {
                w->sortKeys[k] = w->sortKeys[k - 1];
                w->digiIds[k] = w->digiIds[k - 1];
            }
        }
        w->sortKeys[j] = v;
        w->digiIds[j] = id;
        w->count++;
    }
}

void Stg00_LineupTask(Actor *arg0) {
    Stg00ListWork *w;
    Actor *cam;
    s32 i;
    s32 redraw;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ModeWork *)arg0->work)->videoMode = 2;
        Gpu_AllocPacketBufs(0x25800);
        Gfx_InitLights();
        Stg00_LineupSetVideoMode(arg0);
        Stg00_LineupBuildList(arg0);
        Stg00_LineupSpawnModels(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ListWork *)arg0->work;
        cam = (Actor *)Stg00_FindCamera();
        for (i = 0; i < Sys_State.frameDelta; i++) {
            if (Pad_State[0].right) {
                Stg00_CamRotate(cam, 0, 0x20, 0);
            } else if (Pad_State[0].left) {
                Stg00_CamRotate(cam, 0, -0x20, 0);
            }
            if (Pad_State[0].up) {
                Stg00_CamMoveViewPoint(cam, 0, 0, -0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, -0x20);
            } else if (Pad_State[0].down) {
                Stg00_CamMoveViewPoint(cam, 0, 0, 0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, 0x20);
            }
            if (Pad_State[0].triangle) {
                Stg00_CamMoveViewPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].cross) {
                Stg00_CamMoveViewPoint(cam, 0, 0x20, 0);
            }
            if (Pad_State[0].r1) {
                Stg00_CamMoveRefPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].l1) {
                Stg00_CamMoveRefPoint(cam, 0, 0x20, 0);
            }
        }
        if (Pad_Select > 0) {
            if (((Stg00ModeWork *)w)->videoMode != 3) {
                ((Stg00ModeWork *)w)->videoMode++;
            } else {
                ((Stg00ModeWork *)w)->videoMode = 0;
            }
            Stg00_LineupSetVideoMode(arg0);
        }
        redraw = 0;
        if (D_8005F724 > 0) {
            if (++w->layout == 3) {
                w->layout = 0;
            }
            redraw = 1;
        }
        if (Pad_Repeat & 0x20) {
            if (w->scrollTop != 0) {
                w->scrollTop--;
                redraw = 1;
            }
        }
        if (Pad_Repeat & 0x80) {
            if (w->scrollTop + 9 != w->count) {
                w->scrollTop++;
                redraw = 1;
            }
        }
        if (redraw) {
            Stg00_LineupSpawnModels(arg0);
        }
        if (Pad_R2 > 0) {
            Sys_NextGameMode = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_LineupDraw(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, Stg00_LineupWinMasks[((Stg00PartsWork *)arg0->work)->winVariant]);
    Gfx_DrawParts(e);
}

void Stg00_VideoModeTask(Actor *arg0) {
    Stg00ModeWork *w;
    Stg00ModeWork *w2;

    switch (arg0->stateLevel0) {
    case 0:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Gpu_AllocPacketBufs(0x25800);
            Gfx_InitLights();
        case 1:
            break;
        }
        w = (Stg00ModeWork *)arg0->work;
        Sys_SetFrameRate60();
        switch (w->videoMode) {
        case 1:
        default:
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
            break;
        case 0:
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
            break;
        case 3:
            Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
            break;
        case 2:
            Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
            break;
        }
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Task_NextState1(arg0);
        case 1:
            break;
        }
        w2 = (Stg00ModeWork *)arg0->work;
        if (Pad_Select > 0) {
            if (w2->videoMode != 3) {
                w2->videoMode++;
            } else {
                w2->videoMode = 0;
            }
            Task_SetState0(arg0, 2);
        }
        break;
    case 2:
        Task_SetState01(arg0, 0, 1);
        break;
    }
}

void Stg00_GroupViewSetVideoMode(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->videoMode) {
    default:
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        break;
    case 2:
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        break;
    case 1:
        Gpu_InitDoubleBuffer(0x280, 0xF0, 0, 0);
        break;
    case 0:
        Gpu_InitDoubleBuffer(0x280, 0x1E0, 1, 0);
        break;
    }
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x100);
}

void Stg00_SpawnRandomGroup(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 r;
    s32 c;
    s32 k;
    s32 base;
    s32 idx;
    s32 x;
    s32 y;
    s32 z;

    for (r = 0, z = -0x1400, y = 0x800, base = 0; r < 2; r++, base += 3) {
        for (c = 0, k = base, x = -0xA00; c < 3; k++, c++, x += 0xA00) {
            Task_Destroy(&slot[*&k]);
            do {
                idx = (Rand_Next() & 0xFFFF) % Digi_GetModelListCount();
            } while (Digi_GetModelListId(idx) >= 0xF0);
            args.digiId = Digi_GetModelListId(idx);
            args.facing = y;
            args.posX = x;
            args.posY = 0;
            args.posZ = z;
            Task_Create(0x105, &slot[k], (s32)&args);
        }
        z += 0x2800;
        y += 0x800;
    }
}

void Stg00_GroupViewTask(Actor *arg0) {
    Stg00ViewWork *w;
    Actor *cam;
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ViewWork *)arg0->work)->videoMode = 2;
        Gpu_AllocPacketBufs(0x25800);
        Stg00_GroupViewSetVideoMode(arg0);
        Stg00_SpawnRandomGroup(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ViewWork *)arg0->work;
        cam = (Actor *)Stg00_FindCamera();
        for (i = 0; i < Sys_State.frameDelta; i++) {
            if (Pad_State[0].right) {
                Stg00_CamRotate(cam, 0, 0x20, 0);
            } else if (Pad_State[0].left) {
                Stg00_CamRotate(cam, 0, -0x20, 0);
            }
            if (Pad_State[0].up) {
                Stg00_CamMoveViewPoint(cam, 0, 0, -0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, -0x20);
            } else if (Pad_State[0].down) {
                Stg00_CamMoveViewPoint(cam, 0, 0, 0x20);
                Stg00_CamMoveRefPoint(cam, 0, 0, 0x20);
            }
            if (Pad_State[0].triangle) {
                Stg00_CamMoveViewPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].cross) {
                Stg00_CamMoveViewPoint(cam, 0, 0x20, 0);
            }
            if (Pad_State[0].r1) {
                Stg00_CamMoveRefPoint(cam, 0, -0x20, 0);
            } else if (Pad_State[0].l1) {
                Stg00_CamMoveRefPoint(cam, 0, 0x20, 0);
            }
        }
        if (Pad_Square > 0) {
            if (++w->camPreset == 7) {
                w->camPreset = 0;
            }
            switch (w->camPreset) {
            case 0:
            default:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, -0x1400);
                break;
            case 1:
                Stg00_CamMoveOrigin(cam, -0xA00, 0, -0x1400);
                break;
            case 2:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, 0);
                break;
            case 3:
                Stg00_CamMoveOrigin(cam, 0xA00, 0, 0);
                break;
            case 4:
                Stg00_CamMoveOrigin(cam, 0, 0, 0x2800);
                break;
            case 5:
            case 6:
                Stg00_CamMoveOrigin(cam, -0xA00, 0, 0);
                break;
            }
        }
        if (Pad_Select > 0) {
            if (w->videoMode != 3) {
                w->videoMode++;
            } else {
                w->videoMode = 0;
            }
            Stg00_GroupViewSetVideoMode(arg0);
        }
        if (Pad_State[0].start > 0) {
            Stg00_SpawnRandomGroup(arg0);
        }
        if (Pad_State[0].circle > 0) {
            if (++w->winVariant == 4) {
                w->winVariant = 0;
            }
        }
        if (Pad_R2 > 0) {
            Sys_NextGameMode = 0x102;
        }
        break;
    case 2:
        break;
    }
}
