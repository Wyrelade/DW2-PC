#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"

void Gpu_ClearScreens(void) {
    RECT r;
    s32 i;

    for (i = 0; i < 2; i++) {
        r = Sys_State.disp[i].disp;
        ResetGraph(1);
        ClearImage2((s32)&r, 0, 0, 0);
        DrawSync(0);
    }
}

void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Sys_State.draw[i].isbg = 1;
        Sys_State.draw[i].r0 = a0;
        Sys_State.draw[i].g0 = a1;
        Sys_State.draw[i].b0 = a2;
    }
}

void Gpu_DisableBgClear(void) {
    Sys_State.draw[0].isbg = 0;
    Sys_State.draw[1].isbg = 0;
}

void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter) {
    SysState *g = &Sys_State;
    s32 n = 0;
    s32 hw = w / 2;
    s32 hh = h / 2;

    g->centerX.s = hw;
    g->centerY.s = hh;
    switch (mode) {
    default:
    case 0:
        SetDefDrawEnv(&g->draw[0], 0, h, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, h, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = h + hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 1:
        SetDefDrawEnv(&g->draw[0], 0, 0, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, 0, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 2:
        if (inter != 0) {
            SetDefDrawEnv(&g->draw[0], 480, 0, 320, 480);
            SetDefDrawEnv(&g->draw[1], 0, 0, 320, 480);
            SetDefDispEnv(&g->disp[0], 0, 0, 320, 480);
            g->disp[0].isrgb24 = 1;
            SetDefDispEnv(&g->disp[1], 480, 0, 320, 480);
            g->disp[1].isrgb24 = 1;
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
        } else {
            SetDefDrawEnv(&g->draw[0], w, 0, w, h);
            SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
            SetDefDispEnv(&g->disp[0], 0, 0, w, h);
            SetDefDispEnv(&g->disp[1], w, 0, w, h);
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
            n = 0x40 - (w / 16) * 2;
        }
        break;
    }
    Gfx_SetTexSlotCount(n);
    GsInit3D();
    SetGeomOffset(0, 0);
}
