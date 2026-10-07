#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_StaticBgInit(Actor *a, s32 v);
void Stg20_StaticBgUpdate(Actor *a);
void Stg20_StaticBgDraw(Actor *a);

TaskDesc Stg20_StaticBgDesc = {
    (TaskInitFn)Stg20_StaticBgInit, Stg20_StaticBgUpdate, Task_DefaultDestroy, Stg20_StaticBgDraw, 0x40, 0,
};

void Stg20_StaticBgInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

void Stg20_StaticBgUpdate(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        SetGeomOffset(0, 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState1(a);
        case 1:
            if (Sys_State.fadeLevel == 0xFF) {
                switch (w->field_2C) {
                case 0:
                default:
                    Sys_State.nextGameMode = 0x303;
                    Sys_State.modeArg = 3;
                    break;
                case 1:
                    Sys_State.nextGameMode = 0x200;
                    break;
                }
                Task_NextState1(a);
            }
            break;
        case 2:
            break;
        }
        break;
    }
}

void Stg20_StaticBgDraw(Actor *a)
{
  Stg20LoadWork *w = (Stg20LoadWork *) a->work;
  GfxPartPkt *p = (GfxPartPkt *) Sys_State.packet.addr;
  GfxPartOTag *ot = (GfxPartOTag *) Sys_State.otLayers.addr[6];
  GfxPartTexSlot *t;
  s32 i;
  s16 x;
#ifdef DW2_NATIVE
  Host_PillarboxFrame(); /* PG.3 16:9: a 320-wide room picture keeps black sides */
#endif
  i = 0;
  while (i < 10)
  {
    if (w->ids[i] != 0)
    {
      t = (GfxPartTexSlot *) Gfx_FindOrLoadTexSlot(w->ids[i]);
      p->s.c = *((Col1CE9C *) (&Gfx_NeutralRgb));
      p->s.tag.len = 4;
      p->s.c.code = 0x64;
      x = (i * 64) - 0xA0;
      p->s.x0 = x;
      if (x >= (-0xE0))
      {
        if (x <= 0xA0)
        {
 do { p->s.u0 = t->u; p->s.w = 0x40; p->s.y0 = -0x80; p->s.v0 = 0; p->s.h = 0xFF; p->s.clut = (t->index + 0x1E0) << 6; p->s.tag.addr = ot->addr; ot->addr = (u32) p; p = (GfxPartPkt *) ((&p->s) + 1); p->t.tag.len = 1; p->t.code = 0xE1000600 | (t->tpage & 0x9FF); p->t.tag.addr = ot->addr; ot->addr = (u32) p; p = (GfxPartPkt *) ((&p->t) + 1); } while (0);
        }
      }
    }
    i++;
  }

  Sys_State.packet.addr = (s32) p;
}
