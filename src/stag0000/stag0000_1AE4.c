#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"

void func_80064E44(void) {
}

void func_80064E4C(s16 arg0) {
    Stg00Work *w = D_80069360;
    if (arg0 < 6) {
        w->field_8D4 = arg0;
    } else {
        w->field_8D4 = 0;
    }
}

#ifdef NORMALIZED
void func_80064E78(void)
{
  s32 i;
  s32 j;
  s32 n;
  u8 *src;
  u16 *buf;
  u16 *d;
  u16 *p;
  s32 t;
  RECT *r;
  D_80069360 = (Stg00Work *) Mem_Alloc(0x9D8, 2);
  D_8006935C = ((u8 *) D_80069360) + 0x8D6;
  D_80069360->field_8D0 = Gfx_ReserveTexSlot();
  n = 0x200;
  src = D_80068AD0;
  r = &D_80069360->rectBig;
  r->x = ((Stg00TexSlot *) D_80069360->field_8D0)->x;
  r->y = ((Stg00TexSlot *) D_80069360->field_8D0)->y;
  r->w = 0x10;
  r->h = 0x40;
  r = (RECT *) (&D_80069360->field_8C0);
  r->x = ((Stg00TexSlot *) D_80069360->field_8D0)->x;
  r->y = ((Stg00TexSlot *) D_80069360->field_8D0)->y + 0xF9;
  r->w = 0x10;
  r->h = 6;
  buf = D_80069360->buf;
  for (i = 0x3FF; i >= 0; i--)
  {
    buf[i] = 0x2222;
  }

  for (j = 0; j < n; j++, src++)
  {
    i = (j / 64) * 128;
    d = &buf[(i + ((j % 8) * 16)) + (((j / 8) % 8) * 2)];
    d[0] = 0;
    d[0] = (*src) >> 7;
    d[0] |= ((*src) & 0x40) ? (0x10) : (0);
    d[0] |= ((*src) & 0x20) ? (0x100) : (0);
    d[0] |= ((*src) & 0x10) ? (0x1000) : (0);
    d[1] = 0;
    d[1] = ((*src) >> 3) & 1;
    d[1] |= ((*src) & 0x04) ? (0x10) : (0);
    d[1] |= ((*src) & 0x02) ? (0x100) : (0);
    d[1] |= ((*src) & 0x01) ? (0x1000) : (0);
  }

  p = D_80069360->clut;
  for (i = 0; i < 0x18; i++)
  {
    *(p++) = 0;
    *(p++) = 0;
    *(p++) = 0;
    *(p++) = 0;
  }

  p = D_80069360->clut;
  p[0x00] = 0x8000;
  p[0x10] = 0x8000;
  p[0x20] = 0x8000;
  p[0x01] = 0x3DEF;
  p[0x31] = 0x3DEF;
  p[0x11] = 0x0F;
  p[0x41] = 0x0F;
  p[0x21] = 0x3C00;
  p[0x51] = 0x3C00;
  LoadImage((RECT *) (&D_80069360->field_8C0), (u32 *) D_80069360->clut);
  LoadImage(&D_80069360->rectBig, (u32 *) D_80069360->buf);
  func_80064E4C(0);
}
#else
INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000_1AE4", func_80064E78);
void func_80064E78(void);
#endif

void func_80065114(void) {
    Gfx_ReleaseTexSlot(D_80069360->field_8D0);
    Mem_Free((ActorWork *)D_80069360);
}

void func_80065150(s32 arg0, s32 arg1, u8 *arg2)
{
    Stg00PolyFT4 *poly = (Stg00PolyFT4 *) D_8005F770.packet.addr;
    Stg00OTag *ot = (Stg00OTag *) D_8005F770.otLayers.s[0];
    Stg00Work *work = D_80069360;
    u8 ch;
    s32 x;
    s32 y = arg1 - D_8005F770.centerY.s;
    Stg00TexSlot *tex;
    u16 clut;
    u16 tpage;
    s32 c;

    clut = ((work->field_8C2 + work->field_8D4) << 6) | ((work->field_8C0 >> 4) & 0x3F);
    tex = (Stg00TexSlot *) work->field_8D0;
    x = arg0 - D_8005F770.centerX.s;
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
            poly->u0 = c % 8 * 8 + ((Stg00TexSlot *) D_80069360->field_8D0)->u;
            poly->v0 = c / 8 * 8;
            poly->u1 = ((Stg00TexSlot *) D_80069360->field_8D0)->u + c % 8 * 8 + 8;
            poly->v1 = c / 8 * 8;
            poly->u2 = ((Stg00TexSlot *) D_80069360->field_8D0)->u + c % 8 * 8;
            poly->v2 = c / 8 * 8 + 8;
            poly->u3 = ((Stg00TexSlot *) D_80069360->field_8D0)->u + c % 8 * 8 + 8;
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
    D_8005F79C = (s32) poly;
}

void func_80065374(void) {
    Stg00PolyFT4 *p = (Stg00PolyFT4 *)D_8005F770.packet.work;
    u32 *ot = D_8005F770.otLayers.u[0];
    Stg00Work *w;
    Stg00TexSlot *t;
    s32 h;

    p->tag.b.len = 9;
    p->code = 0x2C;
    p->r0 = 0xFF;
    p->g0 = 0xFF;
    p->b0 = 0xFF;
    w = D_80069360;
    t = (Stg00TexSlot *)w->field_8D0;
    p->tpage = (0 << 7) | (1 << 5) | ((t->y & 0x100) >> 4) | ((t->x & 0x3FF) >> 6) | ((t->y & 0x200) << 2);
    p->clut = (w->field_8C2 << 6) | ((w->field_8C0 >> 4) & 0x3F);
    p->u0 = ((Stg00TexSlot *)w->field_8D0)->u;
    p->v0 = 0;
    p->u1 = ((Stg00TexSlot *)D_80069360->field_8D0)->u + 0x40;
    p->v1 = 0;
    p->u2 = ((Stg00TexSlot *)D_80069360->field_8D0)->u;
    p->v2 = h = 0x40;
    p->u3 = ((Stg00TexSlot *)D_80069360->field_8D0)->u + h;
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
    D_8005F770.packet.work = (ActorWork *)p;
}

void func_800654F4(s32 arg0, s32 arg1) {
    func_80065150(arg0, arg1, D_8006935C);
}

void func_8006551C(s32 arg0, s32 arg1) {
    func_80065150(arg0 + D_8005F770.centerX.s, arg1 + D_8005F770.centerY.s, D_8006935C);
}

void func_80065558(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Actor_InitTransform(arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, 0x78)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void func_800655B8(Actor *arg0) {
    Gfx_AttachModel(arg0, 0x78);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void func_800655FC(Actor *arg0) {
    Stg00NameWork *w = (Stg00NameWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    Stg00TaskArgs5 args;
    TextOpenArgs t;

    while ((id = func_8001E8F4(w->field_10)) == -1) {
        w->field_10 = 0;
    }
    Task_Destroy(slot);
    args.field_0 = id;
    args.field_10 = 0;
    args.field_4 = 0;
    args.field_8 = 0;
    args.field_C = 0;
    Task_Create(0x105, slot, (s32)&args);
    Text_Close(&w->field_14);
    Text_Close(&w->field_18);
    t.text = (s32)Digi_GetDefaultName(func_8001E8F4(w->field_10));
    t.bigFont = 1;
    t.color = 0;
    t.x = 0x10;
    t.y = 0xD0;
    t.charDelay = 0xE;
    t.charAdvance = 0;
    t.lineAdvance = 0;
    Text_Open(&w->field_14, &t);
    t.y = 0xC6;
    t.charDelay = 8;
    t.bigFont = 0;
    t.charAdvance = 9;
    Text_Open(&w->field_18, &t);
}

#ifdef NORMALIZED
void func_8006571C(Actor *arg0)
{
  Work65E24 *work;
  Actor *cam;
  Actor *s1;
  s32 i;
  s32 j;
  s32 count;
  s32 v0;
  s32 v1;
  work = (Work65E24 *) arg0->work;
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
  work->field_8 = 0;
  work->field_0 = 0;
  work->field_4 = 0;
  work->field_C = 0;
  work->field_54 = 1;
  Mem_FillWordsNeg1(&work->field_14, 0x10);
  func_800655FC(arg0);
  Task_NextState0(arg0);
  return;
  state1:
  {
    switch (arg0->stateLevel1)
    {
      case 0:

      default:
        cam = (Actor *) func_80068930();
        for (i = 0; i < D_8005F770.frameDelta; i++)
      {
        if (D_8005F6F0[0].right)
        {
          func_80068A44(cam, 0, 0x20, 0);
        }
        else
          if (D_8005F6F0[0].left)
        {
          func_80068A44(cam, 0, -0x20, 0);
        }
        if (D_8005F6F0[0].up)
        {
          func_80068958(cam, 0, 0, -0x20);
        }
        else
          if (D_8005F6F0[0].down)
        {
          func_80068958(cam, 0, 0, 0x20);
        }
        if (D_8005F6F0[0].triangle)
        {
          func_80068958(cam, 0, -0x20, 0);
        }
        else
          if (D_8005F6F0[0].cross)
        {
          func_80068958(cam, 0, 0x20, 0);
        }
        if (D_8005F6F0[0].r1)
        {
          func_8006899C(cam, 0, -0x20, 0);
        }
        else
          if (D_8005F6F0[0].l1)
        {
          func_8006899C(cam, 0, 0x20, 0);
        }
      }

        if (D_8005F700 > 0)
      {
        ((Stg00ActorTimer *) arg0)->field_24 = 0;
        Task_NextState1(arg0);
      }
        break;

      case 1:
        if ((work->field_C == 1) && (work->field_8 == 1))
      {
        if (D_8005F72C & 0x1000)
        {
          work->field_58 = work->field_8;
          if (work->field_64 != 0)
          {
            work->field_64 -= 1;
          }
          else
            if (work->field_5C != 0)
          {
            work->field_5C -= 1;
          }
        }
        if (D_8005F72C & 0x4000)
        {
          work->field_58 = 0;
          if (work->field_64 != 0xD)
          {
            work->field_64 += 1;
          }
          else
            if (D_80068CE8[work->field_5C + 0xE] != 0)
          {
            work->field_5C += 1;
          }
        }
        if (D_8005F72C & 0x8000)
        {
          for (i = 0; i < 0xE; i++)
          {
            if (work->field_58 != 0)
            {
              if (work->field_64 != 0)
              {
                work->field_64 -= 1;
              }
              else
                if (work->field_5C != 0)
              {
                work->field_5C -= 1;
              }
            }
            else
              if (work->field_64 != 0xD)
            {
              work->field_64 += 1;
            }
            else
              if (D_80068CE8[work->field_5C + 0xE] != 0)
            {
              work->field_5C += 1;
            }
          }

        }
      }
        if (D_8005F6F0[0].up > 0)
      {
        if (((Work65E24Slots *) work)->words[work->field_8] != 0)
        {
          ((Work65E24Slots *) work)->words[work->field_8] -= 1;
          goto clearElapsed1;
        }
      }
      else
        if (D_8005F6F0[0].down > 0)
      {
        if (work->field_8 == 0)
        {
          if (work->field_0 != 3)
          {
            work->field_0 += 1;
            goto clearElapsed1;
          }
        }
        else
        {
          v0 = D_80068DB8[work->field_C].field_4;
          if (work->field_4 != v0)
          {
            work->field_4 += 1;
            clearElapsed1:
            arg0->elapsed = 0;

          }
        }
      }
        if (D_8005F6F0[0].right > 0)
      {
        if (work->field_8 == 1)
        {
          work->field_8 = 0;
          goto clearElapsed2;
        }
      }
      else
      {
        do
        {
          if (D_8005F6F0[0].left > 0)
          {
            if (work->field_8 == 0)
            {
              work->field_8 = 1;
              clearElapsed2:
              arg0->elapsed = 0;
            }
          }
        }
        while (0);
      }
        if (D_8005F708 > 0)
      {
        work->field_C += 1;
        if (work->field_C == 4)
        {
          work->field_C = 0;
        }
        work->field_4 = 0;
      }
        if (D_8005F700 > 0)
      {
        if (work->field_8 != 0)
        {
          goto findFirstSection;
        }
        count = 1;
        if (work->field_0 == 0)
        {
          count = 8;
        }
        if (work->field_0 == 3)
        {
          count = 8;
        }
        j = 0;
        if (count != 0)
        {
          do
          {
            v1 = ((Work65E24Slots *) work)->words[work->field_8];
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
            if (work->field_10 != 0)
            {
              v0 = work->field_10 - 1;
            }
            else
            {
              v0 = func_8001E938() - 1;
            }

            goto storeAndUse;
            rangeThen:
            v0 = func_8001E938() - 1;

            v1 = work->field_10;
            if (v0 == v1)
            {
              work->field_10 = 0;
              goto useField10;
            }
            v0 = v1 + 1;
            storeAndUse:
            work->field_10 = v0;

            useField10:
            func_8001E8F4(work->field_10);

            j++;
          }
          while (j < count);
        }
        do
        {
          func_800655FC(arg0);
          goto afterD700;
        }
        while (0);
        findFirstSection:
        s1 = (Actor *) Task_FindFirst(0x105, -1, -1);

        if (s1 != ((void *) 0))
        {
          switch (work->field_C)
          {
            case 0:
              Task_SetState01(s1, 2, ((Work65E24Slots *) work)->bytes[work->field_8 * 4]);
              break;

            case 1:
              Text_CloseArray(work->field_1C, 0xE);
              Task_SetState01(s1, 2, 0xA);
              Task_SetState4(s1, D_80068CE8[work->field_5C + work->field_64]);
              break;

            case 2:
              Task_SetState01(s1, 2, 0xFF);
              Task_SetState2(s1, D_80068DD8[work->field_4][0]);
              break;

            case 3:
              Task_SetState01(s1, 2, 0xFF);
              Task_SetState2(s1, D_80068DF4[work->field_4][0]);
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
      work = (Work65E24 *) arg0->work;
      ch = (s32 *) arg0->u34.children;
      if (work->field_54 != 0)
      {
        Task_SetState01((Actor *) ch[0], 2, 8);
        work->field_54 = 0;
        return;
      }
      Task_SetState01((Actor *) ch[0], 2, 9);
      work->field_54 = 1;
    }
  }

}
#else
INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000_1AE4", func_8006571C);
void func_8006571C(Actor *arg0);
#endif

#ifdef NORMALIZED
void func_80065E24(Actor *arg0) {
    s32 period;
    Work65E24 *w = (Work65E24 *)arg0->work;
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
    s32 slot;

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
    if (fp && w->field_8 == 0) {
        mask = 1 << (w->field_0 + 1);
    }
    Gfx_HidePartsByMask(parts, mask);
    Gfx_SetPartsNumber(parts, 0x20, 4, func_8001E8F4(w->field_10));
    Gfx_DrawParts(parts);
    parts = Cd_GetFileEntry(D_80068DB8[w->field_C].field_0);
    parts2 = parts;
    mask = 0;
    if (fp && w->field_8 == 1) {
        mask = 1 << (w->field_4 + 1);
    }
    Gfx_HidePartsByMask(parts2, mask);
    Gfx_DrawParts(parts2);
    for (i = 0; i < 0xE; i++) {
        Text_Close(&w->field_1C[i]);
    }

    if (w->field_C != 1) {
        return;
    }
    s6 = w->field_5C;
    slot = 0;
    s7 = 0x10;
    for (s5 = 0; s5 <= 0; s5++) {
        s32 y = 0x3A;
        slot++;
        slot--;
        for (col = 0; col < 0xE; col++, y = y + 9) {
            args.text = func_8001ED84(D_80068CE8[s6++]);
            args.bigFont = 0;
            args.x = s7;
            args.y = y;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            if (w->field_60 == s5 && w->field_64 == col) {
                if (fp && w->field_8 == 1) {
                    continue;
                }
                args.color = 4;
            } else {
                args.color = 0;
            }
            Text_Open(&w->field_1C[slot], &args);
            slot++;
        }
        s7 += 0x6E;
    }
}
#else
INCLUDE_ASM("asm/USA/stag0000/nonmatchings/stag0000_1AE4", func_80065E24);
void func_80065E24(Actor *arg0);
#endif

void func_80066084(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->field_0) {
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

void func_80066130(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg00TaskArgs5 args;
    s32 i;

    for (i = 0; i < 9; i++) {
        Task_Destroy(slot);
        args.field_0 = w->field_330[i + w->field_654];
        args.field_10 = 0x400;
        args.field_4 = D_80068E18[w->field_658][i].field_0;
        args.field_8 = 0;
        args.field_C = D_80068E18[w->field_658][i].field_2;
        Task_Create(0x105, slot, (s32)&args);
        slot++;
    }
}

void func_8006620C(Actor *arg0) {
    Stg00ListWork *w = (Stg00ListWork *)arg0->work;
    s32 i;
    s32 id;
    s32 v;
    s32 j;
    s32 k;

    for (i = 0; (id = func_8001E8F4(i)) < 0x12D; i++) {
        v = func_8001E79C(id);
        j = 0;
        if (w->field_650 != 0) {
            for (k = j; k < w->field_650; k++) {
                if (v < w->field_10[k]) {
                    break;
                }
            }
            j = k;
            for (k = w->field_650; k >= j; k--) {
                w->field_10[k] = w->field_10[k - 1];
                w->field_330[k] = w->field_330[k - 1];
            }
        }
        w->field_10[j] = v;
        w->field_330[j] = id;
        w->field_650++;
    }
}

void func_80066318(Actor *arg0) {
    Stg00ListWork *w;
    Actor *cam;
    s32 i;
    s32 redraw;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ModeWork *)arg0->work)->field_0 = 2;
        Gpu_AllocPacketBufs(0x25800);
        Gfx_InitLights();
        func_80066084(arg0);
        func_8006620C(arg0);
        func_80066130(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ListWork *)arg0->work;
        cam = (Actor *)func_80068930();
        for (i = 0; i < D_8005F770.frameDelta; i++) {
            if (D_8005F6F0[0].right) {
                func_80068A44(cam, 0, 0x20, 0);
            } else if (D_8005F6F0[0].left) {
                func_80068A44(cam, 0, -0x20, 0);
            }
            if (D_8005F6F0[0].up) {
                func_80068958(cam, 0, 0, -0x20);
                func_8006899C(cam, 0, 0, -0x20);
            } else if (D_8005F6F0[0].down) {
                func_80068958(cam, 0, 0, 0x20);
                func_8006899C(cam, 0, 0, 0x20);
            }
            if (D_8005F6F0[0].triangle) {
                func_80068958(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].cross) {
                func_80068958(cam, 0, 0x20, 0);
            }
            if (D_8005F6F0[0].r1) {
                func_8006899C(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].l1) {
                func_8006899C(cam, 0, 0x20, 0);
            }
        }
        if (D_8005F720 > 0) {
            if (((Stg00ModeWork *)w)->field_0 != 3) {
                ((Stg00ModeWork *)w)->field_0++;
            } else {
                ((Stg00ModeWork *)w)->field_0 = 0;
            }
            func_80066084(arg0);
        }
        redraw = 0;
        if (D_8005F724 > 0) {
            if (++w->field_658 == 3) {
                w->field_658 = 0;
            }
            redraw = 1;
        }
        if (D_8005F72C & 0x20) {
            if (w->field_654 != 0) {
                w->field_654--;
                redraw = 1;
            }
        }
        if (D_8005F72C & 0x80) {
            if (w->field_654 + 9 != w->field_650) {
                w->field_654++;
                redraw = 1;
            }
        }
        if (redraw) {
            func_80066130(arg0);
        }
        if (D_8005F714 > 0) {
            D_8005F78C = 0x102;
        }
        break;
    case 2:
        break;
    }
}

void func_80066618(Actor *arg0) {
    EntA0 *e = Cd_GetFileEntry(0x1890000);
    Gfx_HidePartsByMask(e, D_80068E84[((Stg00PartsWork *)arg0->work)->field_C]);
    Gfx_DrawParts(e);
}

void func_80066678(Actor *arg0) {
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
        switch (w->field_0) {
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
        if (D_8005F720 > 0) {
            if (w2->field_0 != 3) {
                w2->field_0++;
            } else {
                w2->field_0 = 0;
            }
            Task_SetState0(arg0, 2);
        }
        break;
    case 2:
        Task_SetState01(arg0, 0, 1);
        break;
    }
}

void func_80066828(Actor *arg0) {
    switch (((Stg00ModeWork *)arg0->work)->field_0) {
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

void func_800668D4(Actor *arg0) {
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
                idx = (Rand_Next() & 0xFFFF) % func_8001E938();
            } while (func_8001E8F4(idx) >= 0xF0);
            args.field_0 = func_8001E8F4(idx);
            args.field_10 = y;
            args.field_4 = x;
            args.field_8 = 0;
            args.field_C = z;
            Task_Create(0x105, &slot[k], (s32)&args);
        }
        z += 0x2800;
        y += 0x800;
    }
}

void func_800669F4(Actor *arg0) {
    Stg00ViewWork *w;
    Actor *cam;
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        ((Stg00ViewWork *)arg0->work)->field_0 = 2;
        Gpu_AllocPacketBufs(0x25800);
        func_80066828(arg0);
        func_800668D4(arg0);
        Task_NextState0(arg0);
        break;
    case 1:
        w = (Stg00ViewWork *)arg0->work;
        cam = (Actor *)func_80068930();
        for (i = 0; i < D_8005F770.frameDelta; i++) {
            if (D_8005F6F0[0].right) {
                func_80068A44(cam, 0, 0x20, 0);
            } else if (D_8005F6F0[0].left) {
                func_80068A44(cam, 0, -0x20, 0);
            }
            if (D_8005F6F0[0].up) {
                func_80068958(cam, 0, 0, -0x20);
                func_8006899C(cam, 0, 0, -0x20);
            } else if (D_8005F6F0[0].down) {
                func_80068958(cam, 0, 0, 0x20);
                func_8006899C(cam, 0, 0, 0x20);
            }
            if (D_8005F6F0[0].triangle) {
                func_80068958(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].cross) {
                func_80068958(cam, 0, 0x20, 0);
            }
            if (D_8005F6F0[0].r1) {
                func_8006899C(cam, 0, -0x20, 0);
            } else if (D_8005F6F0[0].l1) {
                func_8006899C(cam, 0, 0x20, 0);
            }
        }
        if (D_8005F708 > 0) {
            if (++w->field_8 == 7) {
                w->field_8 = 0;
            }
            switch (w->field_8) {
            case 0:
            default:
                func_80068A00(cam, 0xA00, 0, -0x1400);
                break;
            case 1:
                func_80068A00(cam, -0xA00, 0, -0x1400);
                break;
            case 2:
                func_80068A00(cam, 0xA00, 0, 0);
                break;
            case 3:
                func_80068A00(cam, 0xA00, 0, 0);
                break;
            case 4:
                func_80068A00(cam, 0, 0, 0x2800);
                break;
            case 5:
            case 6:
                func_80068A00(cam, -0xA00, 0, 0);
                break;
            }
        }
        if (D_8005F720 > 0) {
            if (w->field_0 != 3) {
                w->field_0++;
            } else {
                w->field_0 = 0;
            }
            func_80066828(arg0);
        }
        if (D_8005F6F0[0].start > 0) {
            func_800668D4(arg0);
        }
        if (D_8005F6F0[0].circle > 0) {
            if (++w->field_C == 4) {
                w->field_C = 0;
            }
        }
        if (D_8005F714 > 0) {
            D_8005F78C = 0x102;
        }
        break;
    case 2:
        break;
    }
}
