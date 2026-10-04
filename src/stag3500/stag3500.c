#include "common.h"
#include "stag3500/stag3500.h"

void Stg35_BgUpdate(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;

    if (arg0->stateLevel0 == 0) {
        Stg35_PartsAlloc(w);
        Stg35_PartsSetFile(w, 0xD3F0000);
        Task_NextState0(arg0);
    }
}

void Stg35_BgDestroy(Actor *arg0) {
    Stg35_PartsFree((Stg35PartsHandle *)arg0->work);
    Task_DefaultDestroy(arg0);
}

void Stg35_BgDraw(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;

    Stg35_PartsSetPalette(w, 2, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    Stg35_PartsDraw(w);
}

void Stg35_FightBgUpdate(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        arg0->digiId = 0xD77;
        Actor_InitTransform(arg0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(arg0, arg0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void Stg35_FightBgDraw(Actor *arg0) {
    Gfx_AttachModel(arg0, arg0->digiId);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void Stg35_ActionLoadInit(Actor *arg0, s32 *arg1) {
    ((Stg35FighterWork *)arg0->work)->field_0 = *arg1;
}

void Stg35_ActionLoadAddSorted(Actor *arg0, s32 arg1, s32 arg2) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->sortedCount; i++) {
        if (arg2 < w->sortedLbas[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->sortedCount; i < j; j--) {
            w->sortedFileIds[j] = w->sortedFileIds[j - 1];
            w->sortedLbas[j] = w->sortedLbas[j - 1];
        }
    }
    w->sortedFileIds[i] = arg1;
    w->sortedLbas[i] = arg2;
    w->sortedCount++;
}

void Stg35_ActionLoadUpdate(Actor *arg0) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
    s16 *p;
    GfxPart *part;
    s16 a[4];
    s16 b[4];
    s32 i;
    s32 j;
    s32 k;

    if (arg0->stateLevel0 != 0) {
        return;
    }
    switch (arg0->stateLevel1) {
    case 0:
    default:
        p = w->script;
        k = 0;
        while (*p != 0x14) {
            switch (*p) {
            case 13:
            case 19:
                p += 3;
                break;
            case 0:
            case 1:
            case 2:
            case 3:
            case 7:
            case 14:
            case 15:
                p += 2;
                break;
            case 4:
            case 5:
            case 6:
            case 16:
            case 17:
            case 18:
                p += 1;
                break;
            case 8:
                w->casterDigiId = Stg35_Battle.rec[p[1]].digiId;
                w->skillId = p[2];
                p += 3;
                break;
            case 9:
                w->targetReactKinds[k] = 1;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 10:
                w->targetReactKinds[k] = 2;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 11:
                w->targetReactKinds[k] = 3;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 12:
                w->targetReactKinds[k] = 0;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            }
        }
        Cd_QueueFile(Skill_GetPartsEntry(w->skillId) >> 16);
        Task_NextState1(arg0);
        break;
    case 1:
        w->keptCount = 0;
        w->tempCount = 0;
        w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->casterDigiId);
        w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->casterDigiId, 0);
        w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->casterDigiId, Skill_GetCastAnim(w->skillId) + 5);
        for (i = 0; i < 6; i++) {
            if (w->targetDigiIds[i] != 0) {
                w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->targetDigiIds[i]);
                w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 0);
                switch (w->targetReactKinds[i]) {
                case 0:
                default:
                    break;
                case 1:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 1);
                    break;
                case 3:
                    w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 0xA);
                case 2:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 2);
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 9);
                    break;
                }
            }
        }
        if (w->skillId != 0) {
            for (k = 0; k < 2; k++) {
                Skill_GetFxSet(w->skillId, k, a, b);
                for (j = 0; j < 3; j++) {
                    if (a[j] != 0) {
                        w->tempFiles[w->tempCount++] = a[j];
                    }
                    if (b[j] != 0) {
                        w->tempFiles[w->tempCount++] = b[j];
                    }
                }
            }
        }
        w->keptFiles[w->keptCount++] = 0x1A1;
        w->keptFiles[w->keptCount++] = 0x13B;
        w->keptFiles[w->keptCount++] = 0x1A0;
        w->keptFiles[w->keptCount++] = 0x22B;
        w->keptFiles[w->keptCount++] = 0xCB9;
        Task_NextState1(arg0);
        break;
    case 2:
        if (Cd_GetFileState(Skill_GetPartsEntry(w->skillId) >> 16) == 3) {
            w->keptFiles[w->keptCount++] = 0x1EF;
            part = (GfxPart *)Cd_GetFileEntry(Skill_GetPartsEntry(w->skillId));
            while (part->fileId != 0) {
                w->tempFiles[w->tempCount++] = part->fileId >> 16;
                part++;
            }
            w->sortedCount = 0;
            for (i = 0; i < w->keptCount; i++) {
                Stg35_ActionLoadAddSorted(arg0, w->keptFiles[i], Cd_GetFileLba(w->keptFiles[i]));
            }
            for (i = 0; i < w->tempCount; i++) {
                Stg35_ActionLoadAddSorted(arg0, w->tempFiles[i], Cd_GetFileLba(w->tempFiles[i]));
            }
            Task_NextState1(arg0);
            w->loadTimer = 0;
        }
        break;
    case 3:
        if (++w->loadTimer < 300) {
            for (i = 0; i < w->sortedCount; i++) {
                Cd_QueueFile(w->sortedFileIds[i]);
                if (Cd_GetFileState(w->sortedFileIds[i]) != 3) {
                    return;
                }
            }
        }
        Task_NextState0(arg0);
        break;
    }
}

void Stg35_ActionLoadDestroy(Actor *arg0) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
    s32 i;

    for (i = 0; i < w->tempCount; i++) {
        if (w->tempFiles[i] != 0) {
            Cd_FreeFile(w->tempFiles[i]);
        }
    }
}

void Stg35_RootUpdate(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    SysState *s;
    SysState *t;

    if (arg0->stateLevel0 != 0) {
        return;
    }
    s = &Sys_State;
    switch (s->gameMode) {
    case 0x701:
    default:
        t = s;
        switch (t->prevGameMode) {
        case 0x603:
            t->modeArg = D_80050780 != 0;
            break;
            do {
            } while (0);
        case 0x604:
            s->modeArg = (D_80050780 != 0) ? 2 : 1;
            break;
        default:
            t->modeArg = 0;
            break;
        }
        id = 0x701;
        break;
    case 0x703:
        id = 0x705;
        break;
    case 0x702:
        id = 0x703;
        break;
    }
    Task_Create(id, slot, 0);
    Task_NextState0(arg0);
}

void Stg35_VsMenuUpdate(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    u16 pad;
    SysState *g;

    switch (arg0->stateLevel0) {
    case 0:
        switch (Sys_State.modeArg) {
        case 0:
        default:
            for (i = 4; i >= 0; i--) {
                Save_GameState.elems[i].state = 0;
            }
            w->phase = 0;
            break;
        case 1:
            w->phase = 2;
            break;
        case 2:
            w->phase = 1;
            break;
        }
        if (Save_GameState.elems[0].state != 0) {
            w->p1Loaded = 1;
        }
        if (Save_GameState.elems[3].state != 0) {
            w->p2Loaded = 1;
        }
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, &slot[0], 0);
        Task_Create(0x702, &slot[1], 0);
        for (i = 0; i < 4; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 7; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        Snd_UnloadSlot(2);
        Snd_SetSlotContent(1, 0x18);
        Task_NextState0(arg0);
        break;
    case 1:
        if (w->musicStarted == 0 && Snd_AnySlotLoading() == 0) {
            w->musicStarted = 1;
            Snd_PlayById(0x103, 1);
            Snd_SetSlotContent(2, 0x19);
        }
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Stg35_PartsSetFile(&w->load[0], 0xD3F0001);
            Stg35_PartsStartOpen(&w->load[0]);
            Stg35_PartsSetFile(&w->load[1], 0x3120003);
            Stg35_PartsStartOpen(&w->load[1]);
            if (w->p1Loaded != 0) {
                Stg35_PartsSetFile(&w->load[2], 0xD3F0003);
                Stg35_PartsStartOpen(&w->load[2]);
                Stg35_PartsSetNumber(&w->load[2], 2, 3, (s16)Save_GameState.elems[0].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x10, 3, (s16)Save_GameState.elems[0].maxMp);
                Stg35_PartsSetNumber(&w->load[2], 4, 3, (s16)Save_GameState.elems[1].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x20, 3, (s16)Save_GameState.elems[1].maxMp);
                Stg35_PartsSetNumber(&w->load[2], 8, 3, (s16)Save_GameState.elems[2].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x40, 3, (s16)Save_GameState.elems[2].maxMp);
            }
            if (w->p2Loaded != 0) {
                Stg35_PartsSetFile(&w->load[3], 0xD3F0004);
                Stg35_PartsStartOpen(&w->load[3]);
                Stg35_PartsSetNumber(&w->load[3], 2, 3, (s16)Save_GameState.elems[3].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x10, 3, (s16)Save_GameState.elems[3].maxMp);
                Stg35_PartsSetNumber(&w->load[3], 4, 3, (s16)Save_GameState.elems[4].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x20, 3, (s16)Save_GameState.elems[4].maxMp);
                Stg35_PartsSetNumber(&w->load[3], 8, 3, (s16)Save_GameState.elems[5].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x40, 3, (s16)Save_GameState.elems[5].maxMp);
            }
            Stg35_TextSetLayout(&w->text[0], 0x101, 0x10, 0xBA);
            if (w->p1Loaded != 0) {
                for (i = 0; i < 3; i++) {
                    Stg35_TextSetLayout(&w->text[i + 1], 0, 0x15, i * 0x22 + 0x4E);
                    Stg35_TextSetString((Stg35PartsHandle *)&w->text[i + 1], (s32)Save_GameState.elems[i].name);
                    Stg35_TextOpen(&w->text[i + 1]);
                }
            }
            if (w->p2Loaded != 0) {
                for (i = 0; i < 3; i++) {
                    Stg35_TextSetLayout(&w->text[i + 4], 0, 0xC9, i * 0x22 + 0x4E);
                    Stg35_TextSetString((Stg35PartsHandle *)&w->text[i + 4], (s32)Save_GameState.elems[i + 3].name);
                    Stg35_TextOpen(&w->text[i + 4]);
                }
            }
            w->promptDirty = 1;
            Task_NextState1(arg0);
        case 1:
            do {
                switch (w->phase) {
                case 0:
                default:
                    pad = Pad_State[0].pressed;
                    break;
                case 1:
                    pad = Pad_State[0].pressed | Pad_State[1].pressed;
                    break;
                case 2:
                    pad = Pad_State[1].pressed;
                    break;
                }
                if (pad & 0x10) {
                    Snd_PlayById(0xB, 0);
                    w->backPressed = 1;
                    Task_NextState0(arg0);
                    break;
                }
                if (pad & 0x40) {
                    Snd_PlayById(0xE, 0);
                    w->backPressed = 0;
                    Task_NextState0(arg0);
                }
            } while (0);
            if (w->promptDirty != 0) {
                w->promptDirty = 0;
                Stg35_TextSetSysMsg(&w->text[0], Stg35_VsMenuPromptMsgs[w->phase]);
                Stg35_TextOpen(&w->text[0]);
            }
            Stg35_PartsHideByMask(&w->load[0], Stg35_VsMenuPhaseMasks[w->phase]);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            for (i = 0; i < 4; i++) {
                Stg35_PartsStartScaleOut(&w->load[i]);
            }
            for (i = 0; i < 7; i++) {
                Stg35_TextClose(&w->text[i]);
            }
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            break;
        }
        g = &Sys_State;
        if (g->fadeLevel == 0xFF) {
            s32 v;

            switch (w->phase) {
            case 0:
            default:
                v = w->backPressed == 0 ? 0x603 : 0x401;
                break;
            case 1:
                v = w->backPressed == 0 ? 0x702 : 0x701;
                break;
            case 2:
                v = w->backPressed == 0 ? 0x604 : 0x701;
                break;
            }
            g->nextGameMode = v;
        }
        break;
    }
}

void Stg35_VsMenuDestroy(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_VsMenuDraw(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;

    Stg35_PartsSetPalette(&w->load[0], 0x2A, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    Stg35_PartsDraw(&w->load[0]);
    Stg35_PartsDraw(&w->load[1]);
    if (w->p1Loaded != 0) {
        Stg35_PartsDraw(&w->load[2]);
    }
    if (w->p2Loaded != 0) {
        Stg35_PartsDraw(&w->load[3]);
    }
}

void Stg35_MatchupUpdate(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, slot, 0);
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 14; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg35_PartsSetFile(w->load, 0xD3F0002);
                Stg35_PartsStartSlideX(w->load, 0, 2, 0x140, 0, -0x1400);
                Stg35_PartsStartSlideX(w->load, 1, 4, -0x140, 0, 0x1400);
                Stg35_PartsHideByMask(w->load, 0x18);
                Task_NextState2(arg0);
            case 1:
                if (++arg0->stateLevel3 == 0x14) {
                    Snd_PlayById(0x101, 1);
                    Stg35_PartsHideByMask(w->load, 0x10);
                    for (j = 0; j < 6; j++) {
                        Stg35_TextSetLayout(&w->text[j], 1, Stg35_MatchupLabelPos[j].x, Stg35_MatchupLabelPos[j].y);
                        Stg35_TextSetSysMsg(&w->text[j], Stg35_MatchupLabelMsgs[j]);
                        Stg35_TextOpen(&w->text[j]);
                    }
                    for (k = 0; k < 6; k++) {
                        Stg35_TextSetLayout(&w->text[k + 6], 1, Stg35_MatchupPartyPos[k / 3].x, Stg35_MatchupPartyPos[k / 3].y + (k % 3) * 12);
                        Stg35_TextSetString((Stg35PartsHandle *)&w->text[k + 6], (s32)Digi_GetDefaultName(Save_GameState.elems[k].digiId));
                        Stg35_TextOpen(&w->text[k + 6]);
                    }
                    for (l = 0; l < 2; l++) {
                        Stg35_TextSetLayout(&w->text[l + 12], 1, Stg35_MatchupTamerPos[l].x, Stg35_MatchupTamerPos[l].y);
                        Stg35_TextSetString((Stg35PartsHandle *)&w->text[l + 12], (s32)Save_GameState.elems[l + 6].name);
                        Stg35_TextOpen(&w->text[l + 12]);
                    }
                }
                if (arg0->stateLevel3 == 0x1E) {
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                v = Math_CycleRange(arg0->elapsed, 6, 0, 7);
                Stg35_PartsHideByMask(w->load, 0);
                Stg35_PartsSetPalette(w->load, 0x10, v);
                if (v == 7) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            if (Pad_State[0].cross > 0 || Pad_State[1].cross > 0) {
                Task_NextState0(arg0);
            }
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            if (Sys_State.fadeLevel == 0xFF) {
                Sys_State.nextGameMode = 0x703;
            }
            break;
        }
        break;
    }
}

void Stg35_MatchupDestroy(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 14; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_MatchupDraw(Actor *arg0) {
    Stg35_PartsDraw((Stg35PartsHandle *)arg0->work);
}

void Stg35_SetDigiAction(Actor *arg0, s32 arg1, s32 arg2) {
    arg0->stateLevel0 = 2;
    arg0->stateLevel1 = arg1;
    arg0->stateLevel2 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel4 = arg2;
}

void Stg35_ShowWinnerSide(Stg35ChildOwner *arg0, s32 arg1) {
    Stg35BattleChildren *l = arg0->children;
    s32 i;

    for (i = 0; i < 6; i++) {
        Actor *a = l->fighters[i];

        if (a != NULL) {
            if (arg1 == 0) {
                if (i < 3) {
                    Stg35_FighterSetVisible(a, 1);
                    Stg35_FighterQueueHomeReset(l->fighters[i]);
                } else {
                    Stg35_FighterSetVisible(a, 0);
                }
            } else {
                if (i >= 3) {
                    Stg35_FighterSetVisible(a, 1);
                    Stg35_FighterQueueHomeReset(l->fighters[i]);
                } else {
                    Stg35_FighterSetVisible(a, 0);
                }
            }
        }
    }
}

void Stg35_ShowAllDigi(Stg35ChildOwner *arg0) {
    Stg35BattleChildren *l = arg0->children;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (l->fighters[i] != NULL) {
            Stg35_FighterSetVisible(l->fighters[i], 1);
            Stg35_FighterQueueHomeReset(l->fighters[i]);
        }
    }
}

void Stg35_BattleUpdate(Actor *arg0) {
    Stg35BattleWork *w = (Stg35BattleWork *)arg0->work;
    Actor **c = (Actor **)arg0->u34.children;
    Stg35Arg3 a;
    s32 buf[6];
    s32 cnt[2];
    Actor *e;
    Actor *e2;
    s32 i;
    s32 k;
    s32 n;
    s32 m;
    s32 j;
    s32 r;
    s32 sum;
    s32 wait;
    s32 f;

    switch (arg0->stateLevel0) {
    case 0:
        Snd_PlayById(0x102, 1);
        Stg35_ClearBattle();
        Cd_FreeUnlockedFiles();
        Gpu_AllocPacketBufs(0x32000);
        Gfx_InitLights();
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, (s32 *)&c[0], 0);
        Task_Create(0x706, (s32 *)&c[4], 0);
        Task_Create(0x704, (s32 *)&c[5], 0);
        Cd_QueueFile(0x1FD);
        Cd_QueueFile(0x25B);
        Cd_QueueFile(0xD3F);
        Cd_QueueFile(0xD41);
        Cd_QueueFile(0xD93);
        for (k = 0; k < 6; k++) {
            Stg35_Battle.rec[k] = Save_GameState.elems[k];
        }
        for (j = 0; j < 6; j++) {
            a.field_8 = 0;
            a.field_0 = Stg35_Battle.rec[j].digiId;
            a.field_4 = j;
            Task_Create(0x707, (s32 *)&c[11 + j], (s32)&a);
        }
        for (j = 0; j < 6; j++) {
            Stg35_BuildCommandList(j);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (c[4]->stateLevel0 == 1 && c[4]->stateLevel1 == 1) {
                Task_Create(0x708, (s32 *)&c[19], 0);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg35_ShowAllDigi((Stg35ChildOwner *)arg0);
                Stg35_SetCameraShot(0x18);
                Stg35_BuildTurnOrder();
                e2 = (Actor *)Task_FindFirst(0x708, -1, -1);
                if (e2 != NULL) {
                    Task_SetState1(e2, 1);
                }
                Task_NextState2(arg0);
            case 2:
                Task_Create(0x70C, (s32 *)&c[17], w->round);
                Task_NextState2(arg0);
            case 3:
                if (c[17] == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 2:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                if (Stg35_Battle.rec[Stg35_TurnOrderGet(0)].hp == 0) {
                    Task_NextState1(arg0);
                    break;
                }
                Task_NextState2(arg0);
            case 1:
                switch (arg0->stateLevel3) {
                case 0:
                default:
                    Stg35_SetCameraShot(Stg35_TurnOrderGet(0) + 0xA);
                    for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                        if (e->param == Stg35_TurnOrderGet(0)) {
                            Stg35_FighterSetVisible(e, 1);
                            Stg35_FighterQueueHomeReset(e);
                        } else {
                            Stg35_FighterSetVisible(e, 0);
                        }
                    }
                    for (m = 0; m < 6; m++) {
                        buf[5 - m] = Stg35_Battle.actions[Stg35_TurnOrderGet(0)].skills[m];
                    }
                    Stg35_HudStartGauge(Stg35_TurnOrderGet(0) >= 3, buf);
                    Task_NextState3(arg0);
                    break;
                case 1:
                    if (Stg35_HudGetGaugeStatus() == 1) {
                        break;
                    }
                    if (Stg35_HudGetGaugeStatus() == 2) {
                        Task_SetState1(arg0, 3);
                        break;
                    }
                    f = Stg35_TurnOrderGet(0);
                    Stg35_SetChosenAction(f, Stg35_HudGetGaugeLevel());
                    Task_NextState2(arg0);
                    break;
                }
                break;
            case 2:
                if (Stg35_PrepareAction(Stg35_TurnOrderGet(0)) != 0) {
                    Task_Create(0x709, (s32 *)&c[18], 1);
                }
                Task_NextState2(arg0);
            case 3:
                if (c[18] == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        lose:
            Task_SetState1(arg0, 3);
            r = 1;
            w->winnerSide = r;
            goto chk;
        case 3:
            r = 0;
            sum = 0;
            for (n = 0; n < 3; n++) {
                sum += Stg35_Battle.rec[n].hp;
            }
            if (sum == 0) {
                goto lose;
            }
            sum = 0;
            for (n = 3; n < 6; n++) {
                sum += Stg35_Battle.rec[n].hp;
            }
            if (sum == 0) {
                Task_SetState1(arg0, 4);
                r = 1;
                w->winnerSide = 0;
            }
        chk:
            if (r == 0) {
                Stg35_TurnOrderRemove(0);
                if (Stg35_TurnOrderGet(0) == -1) {
                if (++w->round == 3) {
                memset((u8 *)cnt, 0, 8);
                for (n = 0; n < 3; n++) {
                    if (Stg35_Battle.rec[n].hp != 0) {
                        cnt[0]++;
                    }
                }
                for (n = 3; n < 6; n++) {
                    if (Stg35_Battle.rec[n].hp != 0) {
                        cnt[1]++;
                    }
                }
                if (cnt[0] == cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;
                    for (n = 0; n < 3; n++) {
                        if (Stg35_Battle.rec[n].hp != 0) {
                            cnt[0] += Stg35_Battle.rec[n].hp;
                        }
                    }
                    for (n = 3; n < 6; n++) {
                        if (Stg35_Battle.rec[n].hp != 0) {
                            cnt[1] += Stg35_Battle.rec[n].hp;
                        }
                    }
                }
                if (cnt[0] >= cnt[1]) {
                    w->winnerSide = 0;
                } else {
                    w->winnerSide = 1;
                }
                } else {
                    Task_SetState1(arg0, 1);
                    break;
                }
                } else {
                    Task_SetState1(arg0, 2);
                    break;
                }
            }
            Task_NextState0(arg0);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        nf:
            wait = 1;
            goto done;
        case 0:
        default:
            Snd_PlayById(0x202, 1);
            Stg35_SetCameraShot(w->winnerSide + 0x19);
            Stg35_ShowWinnerSide((Stg35ChildOwner *)arg0, w->winnerSide);
            arg0->elapsed = 0;
            Task_NextState1(arg0);
        case 1:
            wait = 0;
            for (i = w->winnerSide * 3; i < w->winnerSide * 3 + 3; i++) {
                if (Stg35_Battle.rec[i].hp != 0) {
                    f = Anim_GetModelAnimFile(Stg35_Battle.rec[i].digiId, 8);
                    Cd_QueueFile(f);
                    if (Cd_GetFileState(f) != 3) {
                        goto nf;
                    }
                }
            }
        done:
            if (wait != 0) {
                break;
            }
            if (arg0->elapsed < 0x3C) {
                break;
            }
            for (j = w->winnerSide * 3; j < w->winnerSide * 3 + 3; j++) {
                if (Stg35_Battle.rec[j].hp != 0) {
                    Task_SetState01(c[11 + j], 2, 2);
                }
            }
            Task_NextState1(arg0);
            arg0->elapsed = 0;
        case 2:
            if (arg0->elapsed < 0x78) {
                break;
            }
            Task_Create(0x70D, (s32 *)&c[10], w->winnerSide);
            Task_NextState1(arg0);
        case 3:
            if (arg0->elapsed < 0x78) {
                break;
            }
            if (Pad_State[0].cross > 0 || Pad_State[1].cross > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 4:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState1(arg0);
        case 5:
            if (++arg0->stateLevel2 >= 0x10) {
                Sys_State.nextGameMode = 0x701;
                Task_NextState1(arg0);
            }
            break;
        case 6:
            break;
        }
        break;
    }
}
