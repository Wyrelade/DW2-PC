#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"
#include "stag3500/textrect.h"
#include "stag3500/turn.h"
#include "stag3500/parts.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_BattleHudTask(Actor *arg0);
void Stg35_BattleHudDestroy(Actor *arg0);
void Stg35_BattleHudDraw(Actor *arg0);

Stg35XY Stg35_HpBarPosP1[] = { { -129, 150 }, { -129, 172 }, { -129, 194 } };
Stg35XY Stg35_HpBarPosP2[] = { { 17, 150 }, { 17, 172 }, { 17, 194 } };
TaskDesc Stg35_BattleHudDesc = {
    0, Stg35_BattleHudTask, Stg35_BattleHudDestroy, Stg35_BattleHudDraw, 0xC8, 0,
};

void Stg35_HudUpdateSkillList(Actor *arg0) {
    Stg35HudWork *w = (Stg35HudWork *)arg0->work;
    s32 sel = 6 - w->gauge[arg0->param] / 4096;
    Stg35TextHandle *t;
    s32 i;

    for (i = 0; i < 7; i++) {
        t = &w->text[i];
        if (arg0->param == 0) {
            Stg35_TextSetLayout(t, 0, 0xB8, i * 14 + 0x49);
        } else {
            Stg35_TextSetLayout(t, 0, 0x1C, i * 14 + 0x49);
        }
        if (i == 0) {
            Stg35_TextSetSysMsg(t, 1);
        } else if (w->gaugeSkills[i - 1] != 0) {
            Stg35_TextSetSkillName(t, w->gaugeSkills[i - 1]);
        } else {
            Stg35_TextSetSysMsg(t, 0x1C3);
        }
        if (i == sel) {
            Stg35_TextSetColor((Stg35PartsHandle *)t, 4);
        } else {
            Stg35_TextSetColor((Stg35PartsHandle *)t, 1);
        }
        Stg35_TextOpen(t);
    }
}

void Stg35_HudUpdateGaugeColumn(Actor *arg0, s32 arg1) {
    Stg35HudWork *w = (Stg35HudWork *)arg0->work;
    s32 s = Stg35_ScaleBarLen(0xC4, 0x7000, w->gauge[arg0->param]);
    Stg35SpriteHandle *sp;

    if (arg0->param == 0) {
        sp = &w->sprite[2];
    } else {
        sp = &w->sprite[3];
    }
    Stg35_RectSetHeight(sp, s);
    Stg35_RectSetY(sp, 0x60 - s);
    if (w->gauge[arg0->param] >= 0x6000) {
        Stg35_RectSetColor(sp, 0, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 1, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    } else {
        Stg35_RectSetColor(sp, 0, 0xAE, 0x7E, 0x11);
        Stg35_RectSetColor(sp, 1, 0xAE, 0x7E, 0x11);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    }
}

void Stg35_HudUpdateGaugeBar(Actor *arg0, s32 arg1) {
    Stg35HudWork *w = (Stg35HudWork *)arg0->work;
    s32 s = Stg35_ScaleBarLen(0x70, 0x6000, w->gauge[arg0->param]);
    Stg35SpriteHandle *sp;

    if (arg0->param == 0) {
        sp = &w->sprite[0];
    } else {
        sp = &w->sprite[1];
    }
    if (arg0->param == 0) {
        Stg35_RectSetWidth(sp, s);
        Stg35_RectSetX(sp, -0x16 - s);
    } else {
        Stg35_RectSetWidth(sp, s);
    }
    if (s == 0x70) {
        Stg35_RectSetColor(sp, 0, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 1, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 2, 0xA4, 0x19, 2);
        Stg35_RectSetColor(sp, 3, 0xA4, 0x19, 2);
    } else if (arg0->param == 0) {
        Stg35_RectSetColor(sp, 0, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 1, 0, 0, 0xFC);
        Stg35_RectSetColor(sp, 2, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 3, 0, 0, 0xFC);
    } else {
        Stg35_RectSetColor(sp, 1, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 0, 0, 0, 0xFC);
        Stg35_RectSetColor(sp, 3, 0xFA, 0, 0);
        Stg35_RectSetColor(sp, 2, 0, 0, 0xFC);
    }
}

void Stg35_BattleHudTask(Actor *arg0) {
    Stg35HudWork *w = (Stg35HudWork *)arg0->work;
    s32 i;
    s32 j;
    s32 order[6];
    Stg35SpriteHandle *sp;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 3; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 7; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        for (i = 0; i < 10; i++) {
            Stg35_RectAlloc(&w->sprite[i]);
        }
        Stg35_PartsSetFile(&w->load[0], 0xD3F0005);
        Stg35_PartsSetFile(&w->load[1], 0xD3F0006);
        Stg35_PartsSetFile(&w->load[2], 0xD3F0007);
        sp = &w->sprite[0];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, -0x86, -0xC4, 0x70, 0x12);
        sp = &w->sprite[1];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, 0x15, -0xC4, 0x70, 0x12);
        sp = &w->sprite[3];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, -0x84, -0x64, 0x6B, 0xC4);
        sp = &w->sprite[2];
        Stg35_RectSetDrawMode(sp, 0, 0, 0);
        Stg35_RectSetBounds(sp, 0x18, -0x64, 0x6B, 0xC4);
        for (i = 0; i < 3; i++) {
            sp = &w->sprite[4 + i];
            Stg35_RectSetDrawMode(sp, 0, 0, 0);
            Stg35_RectSetColor(sp, 0, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 2, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 1, 0xEB, 0xEE, 6);
            Stg35_RectSetColor(sp, 3, 0xEB, 0xEE, 6);
            Stg35_RectSetBounds(sp, Stg35_HpBarPosP1[i].x, Stg35_HpBarPosP1[i].y, 0x70, 0xC);
        }
        for (i = 0; i < 3; i++) {
            sp = &w->sprite[7 + i];
            Stg35_RectSetDrawMode(sp, 0, 0, 0);
            Stg35_RectSetColor(sp, 1, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 3, 0xB6, 0x92, 0x16);
            Stg35_RectSetColor(sp, 0, 0xEB, 0xEE, 6);
            Stg35_RectSetColor(sp, 2, 0xEB, 0xEE, 6);
            Stg35_RectSetBounds(sp, Stg35_HpBarPosP2[i].x, Stg35_HpBarPosP2[i].y, 0x70, 0xC);
        }
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        default:
        case 0:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                Stg35_PartsHideByMask(&w->load[0], -2);
                Stg35_PartsHideByMask(&w->load[1], -0xE1);
                Stg35_PartsHideByMask(&w->load[2], -0xE1);
                Stg35_RectSetHeight(&w->sprite[3], 0);
                Stg35_RectSetHeight(&w->sprite[2], 0);
                break;
            case 1:
                break;
            }
            break;
        case 1:
            for (j = 0; j < 6; j++) {
                order[j] = 0;
            }
            for (j = 0; j < 6; j++) {
                s32 r = Stg35_TurnOrderGet(j);
                if (r != -1) {
                    order[r] = j + 1;
                }
            }
            Stg35_PartsSetNumber(&w->load[1], 0x20, 1, order[0]);
            Stg35_PartsSetNumber(&w->load[1], 0x40, 1, order[1]);
            Stg35_PartsSetNumber(&w->load[1], 0x80, 1, order[2]);
            Stg35_PartsSetNumber(&w->load[2], 0x20, 1, order[3]);
            Stg35_PartsSetNumber(&w->load[2], 0x40, 1, order[4]);
            Stg35_PartsSetNumber(&w->load[2], 0x80, 1, order[5]);
            break;
        case 2: {
            s32 *gauge = &w->gauge[arg0->param];
            Stg35PartsHandle *load = &w->load[arg0->param + 1];
            Stg35PartsHandle *base = w->load;
            s32 pressed = Pad_State[arg0->param].pressed & 0xFFFF;
            s32 r;

            switch (arg0->stateLevel2) {
            default:
            case 0:
                switch (arg0->stateLevel3) {
                default:
                case 0:
                    Snd_PlayById(0x25, 0);
                    w->gaugeDone = 0;
                    Stg35_PartsShowGroup(load, 2);
                    Task_NextState3(arg0);
                    arg0->elapsed = 0;
                case 1: {
                    s32 frame = Math_CycleRange(arg0->elapsed, 2, 0, 7);
                    Stg35_PartsSetPalette(load, 2, frame);
                    if (frame == 7) {
                        arg0->elapsed = 0;
                        Task_NextState3(arg0);
                    }
                    break;
                }
                case 2:
                    if (arg0->elapsed < 0x78) {
                        break;
                    }
                    Task_NextState3(arg0);
                    arg0->elapsed = 0;
                case 3: {
                    s32 frame = Math_CycleRange(arg0->elapsed, 2, 7, 0);
                    Stg35_PartsSetPalette(load, 2, frame);
                    if (frame == 0) {
                        arg0->elapsed = 0;
                        Task_NextState2(arg0);
                    }
                    break;
                }
                }
                break;
            case 1:
                switch (arg0->stateLevel3) {
                case 0:
                    arg0->elapsed = 0;
                    w->gauge[arg0->param] = 0;
                    Stg35_PartsHideGroup(load, 2);
                    Stg35_PartsShowGroup(base, 2);
                    if (arg0->param == 0) {
                        Stg35_PartsShowGroup(base, 8);
                        Stg35_PartsShowGroup(base, 0x20);
                    } else {
                        Stg35_PartsShowGroup(base, 4);
                        Stg35_PartsShowGroup(base, 0x10);
                    }
                    Task_NextState3(arg0);
                case 1:
                    if (pressed & 0x40) {
                        *gauge += 0xD00;
                        Snd_PlayById(0x100, 0);
                    } else {
                        *gauge = (*gauge < 0x1F9) ? 0 : *gauge - 0x1F8;
                    }
                    *gauge = (*gauge >= 0x7000) ? 0x6FFF : *gauge;
                    Stg35_HudUpdateGaugeColumn(arg0, 0);
                    Stg35_HudUpdateGaugeBar(arg0, 0);
                    Stg35_HudUpdateSkillList(arg0);
                    if (arg0->param == 0) {
                        Stg35_PartsSetX(&w->load[0], 0x20, 0x4F);
                        Stg35_PartsSetY(&w->load[0], 0x20, 0x2B - (w->gauge[0] / 0x1000) * 14);
                    } else {
                        Stg35_PartsSetX(&w->load[0], 0x10, -0x4D);
                        Stg35_PartsSetY(&w->load[0], 0x10, 0x2B - (w->gauge[1] / 0x1000) * 14);
                    }
                    if (((ActorAllocView *)arg0)->frameCount & 4) {
                        Stg35_PartsShowGroup(load, 4);
                    } else {
                        Stg35_PartsHideGroup(load, 4);
                    }
                    {
                        s32 pct = (0x12C - arg0->elapsed) / 3;
                        if (pct == 100) {
                            pct = 99;
                        }
                        Stg35_PartsSetNumber(base, 2, 2, pct);
                    }
                    if (arg0->elapsed >= 0x12C) {
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                case 2:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(0xE, 0);
                        Stg35_HudUpdateGaugeBar(arg0, 1);
                        Stg35_HudUpdateGaugeColumn(arg0, 1);
                        arg0->elapsed = 0;
                        Task_NextState4(arg0);
                    case 1:
                        r = Math_CycleRange(arg0->elapsed, 2, 0, 7);
                        if (arg0->param == 0) {
                            Stg35_PartsSetPalette(&w->load[0], 0x20, r);
                        } else {
                            Stg35_PartsSetPalette(&w->load[0], 0x10, r);
                        }
                        if (r == 7) {
                            Task_NextState4(arg0);
                        }
                        break;
                    case 2:
                        if (arg0->elapsed >= 0x3C) {
                            s32 level = w->gauge[arg0->param] / 0x1000;
                            w->gaugeLevel = level;
                            w->gaugeSkill = w->gaugeSkills[5 - level];
                            Task_NextState3(arg0);
                        }
                        break;
                    }
                    break;
                case 3:
                    for (i = 0; i < 7; i++) {
                        Stg35_TextClose(&w->text[i]);
                    }
                    Stg35_RectSetHeight(&w->sprite[arg0->param + 2], 0);
                    Stg35_PartsHideGroup(load, 6);
                    Stg35_PartsHideGroup(base, 0x3E);
                    if (w->gaugeLevel == 6) {
                        w->gaugeDone = 1;
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    } else if (w->gaugeSkills[5 - w->gaugeLevel] != 0) {
                        goto done;
                    } else {
                        w->gaugeDone = 1;
                        Task_NextState3(arg0);
                        Task_NextState3(arg0);
                        arg0->elapsed = 0;
                    }
                    break;
                case 4:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(7, 0);
                        Task_NextState4(arg0);
                    case 1:
                        Stg35_PartsShowGroup(base, 0x40);
                        Stg35_PartsSetPalette(base, 0x40, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
                        if (arg0->elapsed >= 0xB4) {
                            Stg35_PartsHideGroup(base, 0x40);
                            goto done;
                        }
                        break;
                    }
                    break;
                case 5:
                    switch (arg0->stateLevel4) {
                    default:
                    case 0:
                        Snd_PlayById(0x1C, 0);
                        Task_NextState4(arg0);
                    case 1:
                        Stg35_PartsShowGroup(base, 0x80);
                        Stg35_PartsSetPalette(base, 0x80, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
                        if (arg0->elapsed >= 0xB4) {
                            Stg35_PartsHideGroup(base, 0x80);
                        done:
                            Task_SetState1(arg0, 1);
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        }
        for (i = 0; i < 6; i++) {
            if (w->hpBars[i].hpShown != w->hpBars[i].hpTarget) {
                if (w->hpBars[i].hpShown < w->hpBars[i].hpTarget) {
                    w->hpBars[i].hpShown += arg0->elapsed;
                    if (w->hpBars[i].hpTarget < w->hpBars[i].hpShown) {
                        w->hpBars[i].hpShown = w->hpBars[i].hpTarget;
                    }
                } else {
                    w->hpBars[i].hpShown -= arg0->elapsed;
                    if (w->hpBars[i].hpShown < w->hpBars[i].hpTarget) {
                        w->hpBars[i].hpShown = w->hpBars[i].hpTarget;
                    }
                }
            }
            Stg35_RectSetWidth(&w->sprite[4 + i], Stg35_ScaleBarLen(0x70, w->hpBars[i].maxHp, w->hpBars[i].hpShown));
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        default:
        case 0:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
            break;
        case 1:
            break;
        }
        break;
    }
}

void Stg35_BattleHudDestroy(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    for (i = 0; i < 10; i++) {
        Stg35_RectFree(&w->sprite[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_BattleHudDraw(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Stg35_PartsDraw(&w->load[i]);
    }
    for (i = 0; i < 10; i++) {
        Stg35_RectDraw(&w->sprite[i]);
    }
}

void Stg35_HudStartGauge(s32 arg0, s32 *arg1) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35HudWork *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35HudWork *)e->work;
        Task_SetState1(e, 2);
        e->param = arg0;
        for (i = 0; i < 6; i++) {
            w->gaugeSkills[i] = arg1[i];
        }
    }
}

s32 Stg35_HudGetGaugeStatus(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);

    if (e != NULL && e->stateLevel1 == 2) {
        return 1;
    }
    return (((Stg35HudWork *)e->work)->gaugeDone != 0) * 2;
}

void Stg35_HudSyncHp(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35HudWork *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35HudWork *)e->work;
        for (i = 0; i < 6; i++) {
            w->hpBars[i].hpTarget = Stg35_Battle.rec[i].hp;
            w->hpBars[i].maxHp = Stg35_Battle.rec[i].maxHp;
        }
    }
}

s32 Stg35_HudGetGaugeLevel(void) {
    TaskEntry *e = Task_FindFirst(0x708, -1, -1);

    if (e != NULL) {
        return ((Stg35HudWork *)e->work)->gaugeLevel;
    }
    return 1;
}

s32 Stg35_HudPeekGaugeLevel(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35HudWork *w;
    s32 n;

    if (e != NULL) {
        w = (Stg35HudWork *)e->work;
        n = w->gauge[arg0] / 4096;
        if (w->gaugeSkills[5 - n] != 0) {
            if (n == 6) {
                return 6;
            }
            return n;
        }
    }
    return 0;
}
