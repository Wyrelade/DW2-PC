#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/enemyinfo.h"

/* (x, y) pairs */
u16 Stg40_EnemyInfoTextPos[] = {
    0x0F, 0xC5, 0x0F, 0xB6, 0x37, 0xC5, 0x0F, 0xD1,
    0x73, 0xC5, 0x73, 0xB6, 0x9B, 0xC5, 0x73, 0xD1,
    0xD7, 0xC5, 0xD7, 0xB6, 0xFF, 0xC5, 0xD7, 0xD1,
};
s32 Stg40_EnemyInfoParts[] = { 0x07D40004, 0x07D40005, 0x07D40006 };
TaskDesc Stg40_EnemyInfoDesc = {
    (TaskInitFn)Stg40_EnemyInfoInit, Stg40_EnemyInfoUpdate, Task_DefaultDestroy, Stg40_EnemyInfoDraw, 0x38, 0,
};
Actor *Stg40_EnemyInfoTask;

void Stg40_EnemyInfoInit(void) {
}

void Stg40_EnemyInfoUpdate(Actor *a0) {
    Stg40EnemyInfoWork *w = (Stg40EnemyInfoWork *)a0->work;
    Stg40EnemyParty *info;
    TextOpenArgs args;
    u16 *pos;
    s32 i;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Stg40_EnemyInfoTask = a0;
        Mem_FillWordsNeg1(w->texts, 12);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                pos = Stg40_EnemyInfoTextPos;
                info = (Stg40EnemyParty *)Stg40_RootState->enemyList[Stg40_RootState->enemyIndex]->params;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 1;
                Text_CloseArray(w->texts, 12);
                for (i = 0; i < info->digiCount * 4; i++) {
                    args.x = *pos++;
                    args.y = *pos++;
                    k = info->digiIds[i / 4];
                    switch (i % 4) {
                    case 0:
                    default:
                        args.text = (s32)Cd_GetFileEntry(0x1FD0081);
                        break;
                    case 1:
                        args.text = (s32)Digi_GetDefaultName(k);
                        break;
                    case 2:
                        args.text = (s32)Cd_GetFileEntry(Digi_GetType(k) + 0x1FD00C3);
                        break;
                    case 3:
                        args.text = (s32)Cd_GetFileEntry(Digi_GetRank(k) + 0x1FD00C6);
                        break;
                    }
                    Text_Open(&w->texts[i], &args);
                    Text_SetOtLayer(w->texts[i], 2);
                }
                Task_NextState1(a0);
            }
            break;
        case 1:
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 12);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        case 100:
            Task_SetState0(a0, 1);
            break;
        }
        break;
    }
}

void Stg40_EnemyInfoDraw(Actor *a0) {
    ActorWork *w = a0->work;
    Stg40EnemyParty *info;
    EntA0 *p;
    s32 i;

    if (w->field_0 != 0) {
        info = (Stg40EnemyParty *)Stg40_RootState->enemyList[Stg40_RootState->enemyIndex]->params;
        for (i = 0; i < 3; i++) {
            p = Cd_GetFileEntry(Stg40_EnemyInfoParts[i]);
            if (i >= info->digiCount) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, -1);
            } else {
                Gfx_SetPartsNumber((GfxPart *)p, 2, 2, info->levels[i]);
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_0);
            }
            Gfx_DrawParts((s32)p);
        }
    }
}
