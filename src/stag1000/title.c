#include "common.h"
#include "stag1000/stag1000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg10_TitleUpdate(Actor *a0);
void Stg10_TitleDraw(Actor *a0);

s32 Stg10_AttractCount = 0;
TaskDesc Stg10_TitleDesc = { 0, Stg10_TitleUpdate, Task_DefaultDestroy, Stg10_TitleDraw, 0x14, 0 };

void Stg10_TitleUpdate(Actor *a0) {
    Stg10TitleWork *w = (Stg10TitleWork *)a0->work;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        do {
            Snd_PlayById(0x31, 1);
            w->field_0 = 0;
            w->cursor = 1;
            Task_NextState0(a0);
        } while (0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->menuOpen = 0;
            if (Pad_State[0].start > 0) {
                Snd_PlayById(0x11, 0);
                Task_NextState1(a0);
            }
            switch (a0->stateLevel2) {
            case 0:
            default:
                if (a0->elapsed >= 600) {
                    if (Stg10_AttractCount == 0) {
                        Sys_State.nextGameMode = 0x403;
                    } else {
                        Sys_State.nextGameMode = 0x402;
                    }
                    if (++Stg10_AttractCount == 20) {
                        Stg10_AttractCount = 0;
                    }
                    Task_NextState2(a0);
                }
                break;
            case 1:
                break;
            }
            break;
        case 1:
            w->menuOpen = 1;
            {
                PadState *pad;
                PadState *p;

                do {
                    pad = Pad_State;
                    if (pad[0].down > 0 && w->cursor != 2) {
                        v = w->cursor + 1;
                        goto snd;
                    }
                } while (0);
                p = pad;
                if (pad[0].up > 0 && w->cursor != 0) {
                    v = w->cursor - 1;
                    goto snd;
                }
                if (p->start > 0 || p->cross > 0) {
                    Snd_PlayById(0x11, 0);
                    if (w->cursor == 2 && (pad[0].connected == 0 || pad[1].connected == 0)) {
                        Task_NextState1(a0);
                    } else {
                        Task_NextState0(a0);
                    }
                }
            }
            break;
        case 2:
            do {
                w->padWarning = 1;
                if (Pad_State[0].start > 0) {
                    w->padWarning = 0;
                    Task_SetState1(a0, 1);
                }
            } while (0);
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Snd_StopById(0x31);
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(a0);
        case 1:
            if (++a0->stateLevel4 >= 20) {
                switch (w->cursor) {
                case 0:
                default:
                    Save_ResetGameState();
                    Sys_State.nextGameMode = 0x307;
                    Sys_State.modeArg = 4;
                    break;
                case 1:
                    Sys_State.nextGameMode = 0x602;
                    Sys_State.modeArg = 0;
                    break;
                case 2:
                    Sys_State.nextGameMode = 0x701;
                    Sys_State.modeArg = 0;
                    break;
                snd:
                    w->cursor = v;
                    Snd_PlayById(0xC, 0);
                    break;
                case 3:
                    func_8006359C();
                    Task_NextState2(a0);
                    break;
                }
            }
            break;
        case 2:
            break;
        }
        break;
    }
}

void Stg10_TitleDraw(Actor *a0) {
    Stg10TitleWork *w = (Stg10TitleWork *)a0->work;
    Stg10TitlePart *list = (Stg10TitlePart *)Cd_GetFileEntry(0x1840000);
    Stg10TitlePart *p = list;

    if (p->fileId != 0) {
        do {
            if (p->partMask & 0x2) {
                p->scrollX = p->scrollX < -0x1D9 ? 0 : p->scrollX - 1;
            }
            if (p->partMask & 0x100) {
                p->scrollX = p->scrollX < -0x1C9 ? 0 : p->scrollX - 2;
            }
            if (p->partMask & 0x200) {
                p->scrollX = p->scrollX < 3 ? 0x1CC : p->scrollX - 2;
            }
            if (p->partMask & 0x400) {
                p->scrollX = p->scrollX < 0x1CF ? 0x398 : p->scrollX - 2;
            }
            if (Sys_State.frameCount & 1) {
                if (p->partMask & 0x800) {
                    p->scrollX = p->scrollX < -0x2CE ? 0 : p->scrollX - 1;
                }
                if (p->partMask & 0x1000) {
                    p->scrollX = p->scrollX < 2 ? 0x2D0 : p->scrollX - 1;
                }
                if (p->partMask & 0x2000) {
                    p->scrollX = p->scrollX < 0x2D2 ? 0x5A0 : p->scrollX - 1;
                }
            }
            if (p->partMask & 0x3F00) {
                p->palette = Math_CycleRange(a0->elapsed, 6, 0, 0xF);
            }
            switch (w->menuOpen) {
            case 0:
            default:
                if (p->partMask & 0x10) {
                    p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                }
                if (p->partMask & 0xEC) {
                    p->visible = 0;
                } else {
                    p->visible = 1;
                }
                break;
            case 1:
                if (w->padWarning == 0) {
                switch (w->cursor) {
                case 0:
                default:
                    if (p->partMask & 0x20) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 1:
                    if (p->partMask & 0x40) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 2:
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    if (p->partMask & 0x4) {
                        p->palette = 5;
                    }
                    break;
                case 3:
                    if (p->partMask & 0x20) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x40) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x80) {
                        p->palette = 5;
                    }
                    if (p->partMask & 0x4) {
                        p->palette = Math_CycleRange(a0->elapsed, 6, 0, 4);
                    }
                    break;
                }
                if (p->partMask & 0x18) {
                    p->visible = 0;
                } else {
                    p->visible = 1;
                }
                } else {
                    Gfx_HidePartsByMask((GfxPartMaskView *)list, 0xF4);
                }
                break;
            }
            p->unscaled = 1;
            p++;
        } while (p->fileId != 0);
    }
    Gfx_DrawPartsNoResScale((s32)list);
}
