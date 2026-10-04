#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/stag0000_1AE4_funcs.h"
#include "stag0000/stag0000_39F0_funcs.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_PopupInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_PopupTask(Actor *arg0);
void Stg00_PopupDraw(Actor *arg0);
void Stg00_XaPlayInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_XaPlayTask(Actor *arg0);
void Stg00_XaPlayDestroy(Actor *arg0);
void Stg00_WindowTestTask(Actor *arg0);
void Stg00_WindowTestDraw(Actor *arg0);
void Stg00_SoundTestTask(Actor *arg0);
void Stg00_SoundTestDraw(void);
void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1);
void Stg00_CameraTask(Actor *arg0);
void Stg00_CameraDraw(Actor *arg0);

s32 Stg00_PopupItemMasks[] = { 0xB, 0xD, 0xE, 0x7 };
s32 Stg00_PopupNumMasks[] = { 0x16, 0xD, 0xB };
s32 Stg00_PopupNumParts[] = { 8, 0x10, 0x10 };
TaskDesc Stg00_PopupDesc = {
    (TaskInitFn)Stg00_PopupInit, Stg00_PopupTask, Task_DefaultDestroy, Stg00_PopupDraw, 0x14, 0,
};
/* Task_DescTable[1]: task ids 0x100-0x10D. */
TaskDesc *Stg00_TaskDescs[] = {
    &Stg00_StageSetupDesc, &Stg00_WindowTestDesc, &Stg00_VideoModeDesc, &Stg00_DigiViewDesc,
    &Stg00_GroupViewDesc, &Stg00_DigiModelDesc, &Stg00_FightBgDesc, &Stg00_SoundTestDesc,
    &Stg00_LineupDesc, &Stg00_CameraDesc, &Stg00_DungSelDesc, &Stg00_PopupDesc,
    &Stg00_XaPlayDesc, &Stg00_ScrollViewDesc,
};
s32 Stg00_XaTrackStart[] = { 0, 0x546, 0xB22, 0x10FE, 0x1770, 0x1F0E };
s32 Stg00_XaTrackLength[] = { 0x2EE, 0x3A2, 0x456, 0x474, 0x528, 0x672 };
TaskDesc Stg00_XaPlayDesc = {
    (TaskInitFn)Stg00_XaPlayInit, Stg00_XaPlayTask, Stg00_XaPlayDestroy, 0, 0x14, 0,
};

void Stg00_DigiModelDraw(Actor *arg0) {
    Stg00ModelWork *w = (Stg00ModelWork *)arg0->work;

    Gfx_AttachModel(arg0, w->modelFile);
    Anim_StepModelAnim(arg0);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    if (w->drawTex != 0) {
        Gfx_DrawTexModel(arg0, 0);
    }
    if (w->drawWire != 0) {
        Gfx_DrawWireModel(arg0, 0, &w->wireColor);
    }
}

void Stg00_PopupInit(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void Stg00_PopupTask(Actor *arg0) {
    Stg00FadeWork *w = (Stg00FadeWork *)arg0->work;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->palette++;
            w->scale += 0x200;
            if (w->palette != 7) {
                break;
            }
            arg0->elapsed = 0;
            w->scale = 0x1000;
            Task_NextState1(arg0);
        case 1:
            v = w->kind;
            if (v != 7) {
                if (arg0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->palette = Math_CycleRange(arg0->elapsed, 2, 8, 0xF);
                if (arg0->elapsed < 0x90) {
                    break;
                }
                w->palette = v;
            }
            Task_NextState1(arg0);
        case 2:
            if (--w->palette < 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_PopupDraw(Actor *arg0) {
    Stg00PanelWork *w = (Stg00PanelWork *)arg0->work;
    EntA0 *e = NULL;
    s32 draw = 1;
    Stg00PartScale *p;
    s32 id;

    switch (w->kind) {
    case 0:
    default:
        e = Cd_GetFileEntry(Skill_GetPartsEntry(w->value));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        e = Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask(e, Stg00_PopupItemMasks[w->kind - 4]);
        break;
    case 1:
    case 2:
    case 3:
        e = Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber(e, Stg00_PopupNumParts[w->kind - 1], 3, w->value);
        Gfx_HidePartsByMask(e, Stg00_PopupNumMasks[w->kind - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->scale != 0x1000) {
                p->unscaled = 0;
                p->scaleX = w->scale;
            } else {
                p->unscaled = 1;
            }
            p->palette = w->palette;
        }
        Gfx_DrawParts(e);
    }
    if (w->subPart != 0) {
        switch (w->subPart >> 8) {
        case 0:
        default:
            id = 0x1A10026;
            break;
        case 1:
            id = 0x1A10027;
            break;
        case 2:
            id = 0x1A10028;
            break;
        }
        e = Cd_GetFileEntry(id);
        Gfx_HidePartsByMask(e, ~(1 << ((u8)w->subPart - 1)));
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->scale != 0x1000) {
                p->unscaled = 0;
                p->scaleX = w->scale;
            } else {
                p->unscaled = 1;
            }
            p->palette = w->palette;
        }
        Gfx_DrawParts(e);
    }
}

/* Sound test banks: bank name, then its sound files. cc1 writes each table's strings to
 * .rodata right here, last entry first (the retail pool at 0x800634A8). */
u8 *D_80068FE8[] = {
    "COMM00", "BGM_0000", "BGM_0015", "BOX_OPEN", "BUG_0000", "BUG_0001", "BUG_0002", "BUG_0003",
    "BUG_0004", "BUG_0005", "COUNT000", "CURSOR00", "CURSOR01", "CURSOR02", "CURSOR03", "CURSOR04",
    "CURSOR05", "CURSOR06", "CURSOR07", "CURSOR08", "CURSOR09", "CURSOR10", "DEBAGU00", "DEBAGU01",
    "ENEMYOFF", "EXITGATE", "ITEMGET0", "ITEMGET1", "ITEMHIT0", "ITEMLOSE", "ITEMUSE0", "ITEMUSE1",
    "ITEMUSE2", "JISIN000", "LIFT0000", "NAME0001", "NEXTGATE", "PLATE000", "PLATE001", "PLATE002",
    "PLAYER00", "PLAYER01", "PLAYER02", "SIREN000", "TAIMLVUP", "TANK0000", "TANK0001", "TANK0002",
    "TANK0003", "TANK0004", "TITLE000", "TRANS000", "TRAP0000", "TRAP0001", "TRAP0002", "TRAP0003",
    "WINDOW00", "WINDOW01", "WINDOW02", "WINDOW03", 0,
};
u8 *D_800690DC[] = { "MAP001", "BGM_0014", 0 };
u8 *D_800690E8[] = { "MAP002", "BGM_0019", "JOGRESS2", 0 };
u8 *D_800690F8[] = { "MAP003", "BGM_0003", "JOGRESS1", 0 };
u8 *D_80069108[] = { "MAP004", "BGM_001A", "JOGRESS3", 0 };
u8 *D_80069118[] = { "MAP005", "BGM_0005", 0 };
u8 *D_80069124[] = { "MAP006", "BGM_0002", 0 };
u8 *D_80069130[] = { "MAP007", "BGM_0009", "JOGRESS4", 0 };
u8 *D_80069140[] = { "MAP008", "BGM_000A", 0 };
u8 *D_8006914C[] = { "MAP009", "BGM_000B", "JOGRESS6", 0 };
u8 *D_8006915C[] = { "MAP010", "BGM_000D", 0 };
u8 *D_80069168[] = { "MAP011", "BGM_0008", "JOGRESS5", 0 };
u8 *D_80069178[] = { "MAP012", "BGM_0006", 0 };
u8 *D_80069184[] = { "SAVE00", "SAVE0000", 0 };
u8 *D_80069190[] = { "SHOP00", "SHOP0000", 0 };
u8 *D_8006919C[] = { "BOSS00", "BOSS0000", "WF00_000", 0 };
u8 *D_800691AC[] = { "BOSS01", "BOSS0001", "WF00_001", 0 };
u8 *D_800691BC[] = { "BOSS02", "BOSS0002", "WF02_000", 0 };
u8 *D_800691CC[] = { "BOSS03", "BOSS0003", "WF03_000", 0 };
u8 *D_800691DC[] = { "BOSS04", "BOSS0004", "WF04_000", 0 };
u8 *D_800691EC[] = { "BOSS05", "BOSS0005", "WF04_001", 0 };
u8 *D_800691FC[] = { "BOSS06", "BOSS0006", "WF20_000", 0 };
u8 *D_8006920C[] = { "BOSS07", "BOSS0007", "BOSS0008", "WF21_000", 0 };
u8 *D_80069220[] = { "VS2P00", "BUTTON00", "VSDEMO00", "VSMAIN00", "VSMENU00", 0 };
u8 *D_80069238[] = { "SE_D00", "BAT_T000", "BAT_T001", "BAT_T002", "BAT_T004", "DOWN_000", "DOWN_001", "ENCOUNT0", 0 };
/* Unreferenced: the byte between the last string and .text (garbage in retail). */
const u8 D_80063A73 = 0x25;
u8 **Stg00_SoundBanks[] = {
    D_80068FE8, D_800690DC, D_800690E8, D_800690F8, D_80069108, D_80069118, D_80069124,
    D_80069130, D_80069140, D_8006914C, D_8006915C, D_80069168, D_80069178, D_80069184,
    D_80069190, D_8006919C, D_800691AC, D_800691BC, D_800691CC, D_800691DC, D_800691EC,
    D_800691FC, D_8006920C, D_80069220, D_80069238, 0,
};
s32 Stg00_WindowTestMasks[] = { 0xA2C, 0x8B2, 0x2CA };
Stg00PartMasks Stg00_WindowTestParts[] = {
    { 0x80, 0x100, 0x180, 0x1E00 },
    { 0x200, 0x400, 0x600, 0x1980 },
    { 0x800, 0x1000, 0x1800, 0x780 },
};
TaskDesc Stg00_WindowTestDesc = { 0, Stg00_WindowTestTask, Task_DefaultDestroy, Stg00_WindowTestDraw, 0x10, 0 };
/* "SOUNDTEST  VAB SEQ" in the game's glyph encoding (0x0A 'A', 0xFE space, 0xFF end). */
u8 Stg00_SoundTestTitle[] = {
    0x1C, 0x18, 0x1E, 0x17, 0x0D, 0x1D, 0x0E, 0x1C, 0x1D, 0xFE, 0xFE, 0x1F, 0x0A, 0x0B, 0xFE, 0x1C, 0x0E, 0x1A, 0xFF,
};
TaskDesc Stg00_SoundTestDesc = {
    0, Stg00_SoundTestTask, Task_DefaultDestroy, (TaskFn)Stg00_SoundTestDraw, 0x1C, 0,
};
TaskDesc Stg00_CameraDesc = {
    (TaskInitFn)Stg00_CameraInit, Stg00_CameraTask, Task_DefaultDestroy, Stg00_CameraDraw, 0x88, 0,
};

u8 Stg00_SoundLabelBuf[2][10];

void Stg00_XaPlayInit(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void Stg00_XaPlayTask(Actor *arg0) {
    Stg00CdWork *w = (Stg00CdWork *)arg0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->startSector = Cd_GetFileLba(w->fileId) + Stg00_XaTrackStart[w->track - 1];
            w->endSector = w->startSector + Stg00_XaTrackLength[w->track - 1];
            param[0] = 1;
            param[1] = w->xaChannel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->startSector, loc);
            CdControlF(0x15, (s32)loc);
            Task_NextState1(arg0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(arg0, 0);
                break;
            case 2:
                Task_NextState0(arg0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->startSector, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((Stg00ActorTimer *)arg0)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->endSector) {
                        Task_SetState0(arg0, 3);
                    } else {
                        CdControlF(0x11, 0);
                    }
                    break;
                }
            }
            break;
        }
        break;
    }
}

void Stg00_XaPlayDestroy(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

u8 *Stg00_GetSoundLabel(s32 arg0, s32 arg1) {
    u8 *s = Stg00_SoundBanks[arg0][arg1];
    s32 i = 0;
    s32 row = (arg1 != 0);

    for (; s[i] != 0; i++) {
        u8 c = s[i];
        if (c < 0x3A) {
            Stg00_SoundLabelBuf[row][i] = c - 0x30;
        } else if (c == 0x5F) {
            Stg00_SoundLabelBuf[row][i] = 0x24;
        } else {
            Stg00_SoundLabelBuf[row][i] = c + 0xC9;
        }
    }
    Stg00_SoundLabelBuf[row][i] = 0xFF;
    return Stg00_SoundLabelBuf[row];
}

u8 *Stg00_GetBankLabel(s32 arg0) {
    return Stg00_GetSoundLabel(arg0, 0);
}

u8 *Stg00_GetSoundIdLabel(s32 arg0, s32 arg1) {
    return Stg00_GetSoundLabel(arg0, arg1 + 1);
}

s32 Stg00_CountSoundBanks(void) {
    s32 i;

    for (i = 0; Stg00_SoundBanks[i] != NULL; i++) {
    }
    return i;
}

s32 Stg00_CountBankSounds(s32 arg0) {
    u8 **p = Stg00_SoundBanks[arg0];
    s32 i;

    for (i = 0; p[i] != NULL; i++) {
    }
    return i - 1;
}

void Stg00_WindowTestTask(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    s32 i;
    s32 n;

    switch (arg0->stateLevel0) {
    case 0:
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        if (Pad_State[0].up > 0) {
            if (w->cursor == 0) {
                break;
            }
            w->cursor--;
            w->holdDelay = 0x3C;
        } else if (Pad_State[0].down > 0) {
            if (w->cursor == 2) {
                break;
            }
            w->cursor++;
            w->holdDelay = 0x3C;
        } else {
            n = 5;
            for (i = 5; i >= 0; i--) {
                if (i == 5) {
                    w->counterDigits[n]++;
                }
                if (w->counterDigits[i] >= 10) {
                    w->counterDigits[i] -= 10;
                    if (i != 0) {
                        w->counterDigits[i - 1]++;
                    }
                }
            }
        }
        break;
    case 2:
        break;
    }
}

void Stg00_WindowTestDraw(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    EntA0 *e = Cd_GetFileEntry(0x770000);
    Stg00Part *p;

    Gfx_HidePartsByMask(e, Stg00_WindowTestMasks[w->cursor]);
    p = (Stg00Part *)e;
    while (p->fileId != 0) {
        if (p->partMask & Stg00_WindowTestParts[w->cursor].spinMask) {
            p->unscaled = 0;
            if (w->holdDelay != 0) {
                w->holdDelay--;
            } else {
                p->rotX += 0x20;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_0) {
            if ((p->rotX + 0x400) & 0x800) {
                p->visible = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_4) {
            if ((p->rotX - 0x418) & 0x800) {
                p->visible = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].resetMask) {
            p->unscaled = 1;
            p->rotX = 0;
        }
        p++;
    }
    Gfx_DrawParts(e);
}

void Stg00_SoundTestTask(Actor *arg0) {
    Stg00SndWork *w = (Stg00SndWork *)arg0->work;
    TextOpenArgs t;

    switch (arg0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->titleText, 3);
        Snd_UnloadSlot(1);
        Snd_UnloadSlot(2);
        w->loadedBank = -1;
        Task_NextState0(arg0);
        break;
    load:
        w->loadedBank = w->bank;
        Snd_SetSlotContent(0, w->bank + 1);
        w->pendingSound = w->sound;
        Task_SetState1(arg0, 1);
        goto text;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Pad_State[0].right > 0) {
                w->bank++;
                if (w->bank == Stg00_CountSoundBanks()) {
                    w->bank = 0;
                }
                w->sound = 0;
            } else if (Pad_State[0].left > 0) {
                if (w->bank == 0) {
                    w->bank = Stg00_CountSoundBanks() - 1;
                } else {
                    w->bank--;
                }
                w->sound = 0;
            } else if (Pad_State[0].up > 0) {
                w->sound++;
                if (w->sound == Stg00_CountBankSounds(w->bank)) {
                    w->sound = 0;
                }
            } else if (Pad_State[0].down > 0) {
                if (w->sound == 0) {
                    w->sound = Stg00_CountBankSounds(w->bank) - 1;
                } else {
                    w->sound--;
                }
            } else if (Pad_State[0].circle > 0) {
                if (w->loadedBank == w->bank) {
                    Snd_PlayById(w->sound, 0);
                } else {
                    goto load;
                }
            } else if (Pad_State[0].cross > 0) {
                Snd_StopAll();
            }
        text:
            t.text = (s32)Stg00_SoundTestTitle;
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x28;
            t.y = 0x28;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->titleText, &t);
            t.text = (s32)Stg00_GetBankLabel(w->bank);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x50;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->bankText, &t);
            t.text = (s32)Stg00_GetSoundIdLabel(w->bank, w->sound);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x64;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->soundText, &t);
            break;
        case 1:
            if (!Snd_AnySlotLoading()) {
                Snd_PlayById(w->pendingSound, 0);
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_SoundTestDraw(void) {
}

void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1) {
    *(Stg00CameraArg *)arg0->work = *arg1;
}

void Stg00_CameraTask(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        GsInitCoordinate2(NULL, &w->coord);
        w->dirty = 1;
        Task_NextState0(arg0);
    }
}

void Stg00_CameraDraw(Actor *arg0) {
    Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
    Stg00RefView rv;

    RotMatrixYXZ(&w->rotX, &w->coord.coord);
    w->coord.coord.t[0] = w->originX;
    w->coord.coord.t[1] = w->originY;
    w->coord.coord.t[2] = w->originZ;
    w->coord.flg = 0;
    rv.vpx = w->vpx;
    rv.vpy = w->vpy;
    rv.vpz = w->vpz;
    rv.vrx = w->vrx;
    rv.vry = w->vry;
    rv.vrz = w->vrz;
    rv.rz = 0;
    rv.super = &w->coord;
    GsSetProjection(w->projection);
    GsSetRefView2(&rv);
}

TaskEntry *Stg00_FindCamera(void) {
    return Task_FindFirst(0x109, -1, -1);
}

void Stg00_CamMoveViewPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->vpx += arg1;
        w->vpy += arg2;
        w->vpz += arg3;
    }
}

void Stg00_CamMoveRefPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->vrx += arg1;
        w->vry += arg2;
        w->vrz += arg3;
    }
}

void Stg00_CamSetProjection(Actor *arg0, s32 arg1) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->projection = arg1;
        w->dirty = 1;
    }
}

void Stg00_CamMoveOrigin(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->originX += arg1;
        w->originY += arg2;
        w->originZ += arg3;
    }
}

void Stg00_CamRotate(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00CameraWork *w = (Stg00CameraWork *)arg0->work;
        w->dirty = 1;
        w->rotX += arg1;
        w->rotY += arg2;
        w->rotZ += arg3;
    }
}
