#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/stag0000_1AE4_funcs.h"
#include "stag0000/stag0000_39F0_funcs.h"

void Stg00_DigiModelDraw(Actor *arg0) {
    Stg00ModelWork *w = (Stg00ModelWork *)arg0->work;

    Gfx_AttachModel(arg0, w->field_14);
    Anim_StepModelAnim(arg0);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    if (w->field_20 != 0) {
        Gfx_DrawTexModel(arg0, 0);
    }
    if (w->field_24 != 0) {
        Gfx_DrawWireModel(arg0, 0, &w->field_28);
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
            w->field_10++;
            w->field_C += 0x200;
            if (w->field_10 != 7) {
                break;
            }
            arg0->elapsed = 0;
            w->field_C = 0x1000;
            Task_NextState1(arg0);
        case 1:
            v = w->field_0;
            if (v != 7) {
                if (arg0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->field_10 = Math_CycleRange(arg0->elapsed, 2, 8, 0xF);
                if (arg0->elapsed < 0x90) {
                    break;
                }
                w->field_10 = v;
            }
            Task_NextState1(arg0);
        case 2:
            if (--w->field_10 < 0) {
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
                p->field_E = 0;
                p->field_10 = w->scale;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->palette;
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
                p->field_E = 0;
                p->field_10 = w->scale;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->palette;
        }
        Gfx_DrawParts(e);
    }
}
INCLUDE_RODATA("asm/USA/stag0000/rodata", D_800634A8);

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
            w->field_C = Cd_GetFileLba(w->field_0) + Stg00_XaTrackStart[w->field_8 - 1];
            w->field_10 = w->field_C + Stg00_XaTrackLength[w->field_8 - 1];
            param[0] = 1;
            param[1] = w->field_4;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->field_C, loc);
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
            CdIntToPos(w->field_C, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((Stg00ActorTimer *)arg0)->field_24 & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->field_10) {
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
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_8) {
            p->field_E = 0;
            if (w->holdDelay != 0) {
                w->holdDelay--;
            } else {
                p->field_20 += 0x20;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_0) {
            if ((p->field_20 + 0x400) & 0x800) {
                p->field_F = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_4) {
            if ((p->field_20 - 0x418) & 0x800) {
                p->field_F = 0;
            }
        }
        if (p->partMask & Stg00_WindowTestParts[w->cursor].field_C) {
            p->field_E = 1;
            p->field_20 = 0;
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

void Stg00_CameraInit(Actor *arg0, Stg00Blk1C *arg1) {
    *(Stg00Blk1C *)arg0->work = *arg1;
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
