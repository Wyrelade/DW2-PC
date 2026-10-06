#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_DigiLabUpdate(Actor *a);
void Stg20_DigiLabDraw(Actor *a);

TaskDesc Stg20_DigiLabDesc = { 0, Stg20_DigiLabUpdate, Task_DefaultDestroy, Stg20_DigiLabDraw, 0x14, 0x24 };

void Stg20_LabDnaDigivolve(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    s32 buf[9];
    Stg20WarpFx args;
    Stg20Digi nd;
    Stg20Digi *p;
    Stg20Digi *q;
    s32 t;
    s32 i;
    s32 ok;
    s32 v;
    s32 hi;
    s32 lo;
    s32 best;
    s32 bestv;
    s32 n;
    s32 s;
    u8 ml;
    s32 j;
    s32 k;
    s32 f;

    Stg20_LabIsDna[0] = 1;
    switch (a->stateLevel2) {
    case 0:
    default:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[1] != 0) {
                Task_SetState0((Actor *)slot[1], 2);
            }
            Stg20_MenuState.excludeFirst = 0;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowSysMsg(0x117);
            Stg20_MenuState.pickStep = 1;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (D_800709B8.result != 0) {
                    Task_SetState1(a, 0);
                } else {
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.pickedIndex].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 0;
            Task_Create(0x30A, &slot[1], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 2;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (Stg20_MenuState.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 2:
                    Task_SetState2(a, 3);
                    Stg20_MenuState.dnaParent0 = Stg20_MenuState.infoRosterIndex;
                    break;
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 1);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 3:
        switch (a->stateLevel3) {
        case 0:
        default:
            Task_SetState1((Actor *)slot[1], 1);
            if (slot[2] != 0) {
                Task_SetState0((Actor *)slot[2], 2);
            }
            Stg20_MenuState.excludeFirst = 1;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowDigiMsg(0x11C, Save_GameState.elems[Stg20_MenuState.dnaParent0].digiId);
            Stg20_MenuState.pickStep = 2;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (Stg20_MenuState.result != 0) {
                    if (slot[1] != 0) {
                        Task_SetState0((Actor *)slot[1], 2);
                    }
                    Task_SetState2(a, 0);
                } else {
                    Stg20_MenuState.dnaParent1 = Stg20_MenuState.pickedIndex;
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 4:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.dnaParent1].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 1;
            Task_Create(0x30A, &slot[2], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 3;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.dnaParent1;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 3);
                    break;
                case 2:
                    Task_SetState2(a, 6);
                    Task_SetState0((Actor *)slot[5], 3);
                    break;
                }
            }
            break;
        }
        break;
    case 5:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 4);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a->stateLevel3) {
        case 0:
        default:
            ok = 1;
            buf[0] = Digi_GetModelFile(Stg20_MenuState.evoTargetId);
            buf[1] = Anim_GetModelAnimFile(Stg20_MenuState.evoTargetId, 0);
            buf[2] = 0xDD8;
            buf[3] = 0xDD7;
            buf[4] = 0x25B;
            buf[5] = 0x1A1;
            buf[6] = 0x314;
            buf[7] = 0x25C;
            buf[8] = 0x3D0;
            for (f = 0; f < 9; f++) {
                Cd_QueueFile(buf[f]);
                if (Cd_GetFileState(buf[f]) != 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0) {
                Task_NextState3(a);
            }
            break;
        case 1:
            switch (a->stateLevel4) {
            case 0:
            default:
                buf[0] = 0x512;
                buf[1] = 1;
                buf[2] = 0x2A3;
                Task_Create(0x313, &slot[8], (s32)buf);
                Task_NextState4(a);
                Snd_StopById(0x101);
                break;
            case 1:
                if (((Actor *)slot[8])->stateLevel0 == 0) {
                    break;
                }
                Task_SetState0((Actor *)slot[8], 2);
                Task_SetState1((Actor *)w->menu, 2);
                w->timer = 0x5A;
                w->busy = 1;
                Task_NextState3(a);
                break;
            }
            break;
        case 2:
            if (--w->timer != 0) {
                break;
            }
            args.animFileId = 0xDD8;
            args.modelFileId = 0xDD7;
            args.rotY = 0;
            args.duration = 0x78;
            args.z = 0;
            args.y = 0;
            args.x = 0;
            Task_Create(7, &slot[6], (s32)&args);
            Task_SetState1((Actor *)slot[1], 2);
            Task_SetState1((Actor *)slot[2], 1);
            Task_NextState3(a);
            break;
        case 3:
            if (((Actor *)w->menu)->stateLevel2 == 3) {
                Stg20_MenuState.modelDigiId = Stg20_MenuState.evoTargetId;
                Stg20_MenuState.modelNoGrow = 1;
                Stg20_MenuState.modelSlide = 0;
                Task_Create(0x30A, &slot[1], 0);
                Task_SetState0((Actor *)slot[2], 3);
                Task_NextState3(a);
            }
            break;
        case 4:
            if (((Actor *)w->menu)->stateLevel1 != 0) {
                break;
            }
            p = (Stg20Digi *)&D_8005E704[Stg20_MenuState.dnaParent0];
            q = (Stg20Digi *)&D_8005E704[Stg20_MenuState.dnaParent1];
            t = Digi_GetRank(Stg20_MenuState.evoTargetId);
            w->busy = 0;
            Snd_PlayById(0x101, 1);
            Mem_Zero(&nd, 0x5C);
            nd.state = 1;
            nd.level = t * 10 + 1;
            nd.digiId = Stg20_MenuState.evoTargetId;
            nd.dp = (p->dp > q->dp ? p->dp : q->dp) + 1;
            if (p->level > q->level) {
                ml = p->level + q->level / 5;
            } else {
                ml = q->level + p->level / 5;
            }
            nd.maxLevel = ml;
            if (ml >= 99) {
                nd.maxLevel = 99;
            }
            if (nd.level == 1) {
                nd.exp = 0;
            } else {
                nd.exp = Digi_GetExpToNextLevel(nd.level - 1, 100, 0);
            }
            s = p->maxHp + q->maxHp;
            switch (t) {
            case 0:
            default:
                v = s * 10;
                break;
            case 1:
                v = s * 34;
                break;
            case 2:
                v = s * 45;
                break;
            }
            nd.hp = nd.maxHp = v / 100;
            s = p->maxMp + q->maxMp;
            switch (t) {
            case 0:
            default:
                v = s * 10;
                break;
            case 1:
                v = s * 34;
                break;
            case 2:
                v = s * 45;
                break;
            }
            nd.mp = nd.maxMp = v / 100;
            if (p->attack > q->attack) {
                hi = p->attack;
                lo = q->attack;
            } else {
                lo = p->attack;
                hi = q->attack;
            }
            switch (t) {
            case 0:
            default:
                nd.attack = (hi * 40 + lo * 30) / 100;
                break;
            case 1:
                nd.attack = (hi * 50 + lo * 30) / 100;
                break;
            case 2:
                nd.attack = (hi * 50 + lo * 40) / 100;
                break;
            }
            if (p->defense > q->defense) {
                hi = p->defense;
                lo = q->defense;
            } else {
                lo = p->defense;
                hi = q->defense;
            }
            switch (t) {
            case 0:
            default:
                nd.defense = (hi * 40 + lo * 30) / 100;
                break;
            case 1:
                nd.defense = (hi * 50 + lo * 30) / 100;
                break;
            case 2:
                nd.defense = (hi * 50 + lo * 40) / 100;
                break;
            }
            switch (t) {
            case 0:
            default:
                nd.speed = (p->speed + q->speed) * 30 / 100;
                break;
            case 1:
                nd.speed = (p->speed + q->speed) * 45 / 100;
                break;
            case 2:
                nd.speed = (p->speed + q->speed) / 2;
                break;
            }
            best = 0;
            bestv = 0;
            for (i = 0; i < 12; i++) {
                if (p->skills[i] != 0 && t >= Skill_GetRank(p->skills[i])) {
                    v = Skill_GetPower(p->skills[i]);
                    if (bestv < v) {
                        bestv = v;
                        best = p->skills[i];
                    }
                }
                if (q->skills[i] != 0 && t >= Skill_GetRank(q->skills[i])) {
                    v = Skill_GetPower(q->skills[i]);
                    if (bestv < v) {
                        bestv = v;
                        best = q->skills[i];
                    }
                }
            }
            nd.skills[0] = Digi_GetLearnedSkill(nd.digiId);
            if (best != 0 && nd.skills[0] != best) {
                nd.skills[1] = best;
            }
            for (j = 0, n = 0; j < 12; j++) {
                if (p->skills[j] != nd.skills[0] && p->skills[j] != nd.skills[1]) {
                    nd.learned[n++] = p->skills[j];
                }
                if (q->skills[j] != nd.skills[0] && q->skills[j] != nd.skills[1]) {
                    nd.learned[n++] = q->skills[j];
                }
            }
            nd.parent0 = p->digiId;
            nd.parent1 = q->digiId;
            p->state = 0;
            q->state = 0;
            Digi_SortRoster();
            for (k = 0; k < 0x24; k++) {
                if (Save_GameState.elems[k].state == 0) {
                    break;
                }
            }
            Save_GameState.elems[k] = *(DigiRosterEntry *)&nd;
            Stg20_DnaNewSlot = k;
            Task_NextState2(a);
            break;
        }
        break;
    case 7:
        switch (a->stateLevel3) {
        case 0:
        default:
            buf[4] = 0;
            buf[5] = Stg20_DnaNewSlot;
            Task_Create(0x16, &slot[7], (s32)&buf[4]);
            Task_NextState3(a);
            break;
        case 1:
            if (slot[7] == 0) {
                Task_NextState2(a);
            }
            break;
        }
        break;
    case 8:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.pickedIndex = Stg20_MenuState.dnaNewSlot;
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 4;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 1:
                case 2:
                case 3:
                    Digi_SortRoster();
                    Save_GameState.elems[0].state = Save_GameState.elems[0].state != 0 ? 3 : 0;
                    Save_GameState.elems[1].state = Save_GameState.elems[1].state != 0 ? 4 : 0;
                    Save_GameState.elems[2].state = Save_GameState.elems[2].state != 0 ? 5 : 0;
                    Task_SetState2(a, 0);
                    break;
                case 0:
                    Task_NextState2(a);
                    break;
                }
            }
            break;
        }
        break;
    case 9:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 8);
            }
            break;
        }
        break;
    }
}

void Stg20_LabDigivolve(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    s32 buf[5];
    Stg20WarpFx args;
    s32 i;
    s32 ok;
    Stg20DigiBoost *e;
    s16 v;

    Stg20_LabIsDna[0] = 0;
    switch (a->stateLevel2) {
    case 0:
    default:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[1] != 0) {
                Task_SetState0((Actor *)slot[1], 2);
            }
            Stg20_MenuState.excludeFirst = 0;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowSysMsg(0x116);
            Stg20_MenuState.pickStep = 0;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (D_800709B8.result != 0) {
                    Task_SetState1(a, 0);
                } else {
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.pickedIndex].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 0;
            Task_Create(0x30A, &slot[1], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 0;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 2:
                    Task_SetState0((Actor *)slot[5], 3);
                    Task_SetState2(a, 3);
                    break;
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 1);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 3:
        switch (a->stateLevel3) {
        case 0:
        default:
            ok = 1;
            buf[0] = Digi_GetModelFile(Stg20_MenuState.evoTargetId);
            buf[1] = Anim_GetModelAnimFile(Stg20_MenuState.evoTargetId, 0);
            buf[2] = 0xDDB;
            buf[3] = 0xDD9;
            buf[4] = 0x3D0;
            for (i = 0; i < 5; i++) {
                Cd_QueueFile(buf[i]);
                if (Cd_GetFileState(buf[i]) != 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0) {
                Task_NextState3(a);
            }
            break;
        case 1:
            switch (a->stateLevel4) {
            case 0:
            default:
                buf[0] = 0x512;
                buf[1] = 0;
                buf[2] = 0x2A3;
                Task_Create(0x313, &slot[8], (s32)buf);
                Task_NextState4(a);
                Snd_StopById(0x101);
                break;
            case 1:
                if (((Actor *)slot[8])->stateLevel0 == 0) {
                    break;
                }
                Task_SetState0((Actor *)slot[8], 2);
                Task_SetState1((Actor *)w->menu, 1);
                w->busy = 1;
                Task_NextState4(a);
                w->timer = 0x5A;
            case 2:
                if (--w->timer != 0) {
                    break;
                }
                args.animFileId = 0xDDB;
                args.modelFileId = 0xDD9;
                args.rotY = 0;
                args.duration = 0x78;
                args.z = 0;
                args.y = 0;
                args.x = 0;
                Task_Create(7, &slot[6], (s32)&args);
                Task_NextState3(a);
                break;
            }
            break;
        case 2:
            if (((Actor *)w->menu)->stateLevel2 == 3) {
                Stg20_MenuState.modelDigiId = Stg20_MenuState.evoTargetId;
                Stg20_MenuState.modelNoGrow = 1;
                Stg20_MenuState.modelSlide = 0;
                Task_Create(0x30A, &slot[1], 0);
                Task_NextState3(a);
            }
            break;
        case 3:
            if (((Actor *)w->menu)->stateLevel1 == 0) {
                w->busy = 0;
                Snd_PlayById(0x101, 1);
                e = (Stg20DigiBoost *)&D_8005E704[Stg20_MenuState.infoRosterIndex];
                e->digiId = Stg20_MenuState.evoTargetId;
                e->maxHp += 30;
                v = e->maxHp;
                if (v >= 1000) {
                    v = 999;
                }
                e->maxHp = v;
                e->hp = v;
                e->maxMp += 30;
                v = e->maxMp;
                if (v >= 1000) {
                    v = 999;
                }
                e->maxMp = v;
                e->mp = v;
                e->field_46 = Digi_GetLearnedSkill(e->digiId);
                Task_NextState2(a);
            }
            break;
        }
        break;
    case 4:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 1;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 1:
                case 2:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 0:
                    Task_NextState2(a);
                    break;
                }
            }
            break;
        }
        break;
    case 5:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 4);
            }
            break;
        }
        break;
    }
}

void Stg20_DigiLabUpdate(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Stg20_MenuState.labMode = 0;
        Task_Create(0x30D, &slot[5], 0);
        w->menu = Task_FindFirst(0x308, -1, -1);
        Stg20_MenuState.menuAllowed = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_SetState0((Actor *)w->menu, 0);
                Task_Create(0x30B, &slot[3], 0);
                Stg20_MsgWinShowSysMsg(0x115);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else {
                        if (Stg20_MenuState.labMode != 0) {
                            Task_NextState1(a);
                        }
                        Task_NextState1(a);
                    }
                }
                break;
            }
            break;
        case 1:
            Stg20_LabDigivolve(a);
            break;
        case 2:
            Stg20_LabDnaDigivolve(a);
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.modeArg = 1;
                Sys_State.nextGameMode = Sys_State.prevGameMode;
            }
            break;
        }
        break;
    }
}

void Stg20_DigiLabDraw(Actor *a) {
    Stg20ScrollWork *w = (Stg20ScrollWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD12000B);
    GfxPart *q;

    if (w->on != 0) {
        if (w->level != 7) {
            w->level++;
        }
    } else {
        if (w->level != 0) {
            w->level--;
        }
    }
    for (q = p; q->fileId != 0; q++) {
        switch (q->groupMask) {
        case 1:
            q->y = w->scroll;
            break;
        case 2:
            q->x = q->x == -0x133 ? 0 : q->x - 1;
            break;
        case 4:
            q->x = q->x == 0xC1 ? 0 : q->x + 1;
            break;
        case 8:
            q->x = q->x == 0x18E ? 0 : q->x + 2;
            break;
        case 16:
            q->x = q->x == -0x18E ? 0 : q->x - 2;
            break;
        }
        if (q->groupMask & 0x1E) {
            if (w->level != 0) {
                q->palette = w->level;
                q->visible = 1;
            } else {
                q->visible = 0;
            }
        }
    }
    w->scroll = w->scroll == -0xEC ? 0 : w->scroll - 1;
    Gfx_DrawParts((s32)p);
}
