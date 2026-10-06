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
#include "main/digilist.h"

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_DigiStatusInit(Actor *a0, s16 a1);
void Menu_DigiStatusTask(Actor *a);
void Menu_DigiStatusDraw(Actor *actor);

Prm1C Menu_DigiStatusView = { { 0, -0x180, -0x1E00, 0, 0, 0, 0x230 } };
TaskDesc Menu_DigiStatusDesc = {
    (TaskInitFn)Menu_DigiStatusInit, Menu_DigiStatusTask, Task_DefaultDestroy, Menu_DigiStatusDraw, 0x150, 4,
};

void Menu_DigiStatusInit(Actor *a0, s16 a1) {
    MenuDigiStatusInitWork *w;
    u8 *p;
    s32 i;
    Blk16 *b;
    s32 *q;

    w = (MenuDigiStatusInitWork *)a0->work;
    w->field_7C = a1;
    p = Menu_Ctx->selRecord;
    w->digimon = p;
    a0->digiId = p[1];
    Actor_InitTransform((ContC40 *)a0, w->pos, w->initRotY);
    w->modelFile = Digi_GetModelFile(a0->digiId);
    w->animFile = Anim_GetModelAnimFile(a0->digiId, 0);
    Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
    Cd_QueueFile(w->modelFile);
    Cd_QueueFile(w->animFile);
    w->modelPhase = 0;
    w->modelScale = 0;
    w->view = Menu_DigiStatusView;
    GsInitCoordinate2(0, (Coord1F668 *)&w->coord);
    w->field_148 = 1;
    w->rotSpeedY = 11;
    w->rotSpeedX = 0;
    w->rotSpeedZ = 0;
    w->rotX = -0xE3;
    b = (Blk16 *)Cd_GetFileEntry(0x513001F);
    q = (s32 *)Cd_GetFileEntry(0x5130020);
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &b[i]);
    }
    GsSetAmbient(q[0], q[1], q[2]);
    GsSetLightMode(0);
}

void Menu_DigiStatusTask(Actor *a) {
    MenuDigiStatusWork *w = (MenuDigiStatusWork *)a->work;
    Halves *h;
    MenuDigiStatusEntry *r;
    u8 **q;
    s32 i;
    Actor *t[1];
    s16 *p;
    s16 *s;
    PadState *d;

    switch (a->stateLevel0) {
    default:
    case 0:
        w->blk = *(MenuDigiStatusLayout *)Cd_GetFileEntry(0x513001C);
        Mem_FillWordsNeg1(w, 0x1B);
        GsSetOffset(-0xA0, 0xB4);
        t[0] = a;
        Task_Create(6, (s32 *)a->u34.children, (s32)t);
        a->childCount = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        default:
        case 0:
            h = (Halves *)Cd_GetFileEntry(0x513001E);
            (*(Actor **)a->u34.children)->model->otIndex = 4;
            if (Math_RampToOne((s32)a, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x513001D, 0), 1);
            r = w->digimon;
            Text_OpenPacked(&w->nameText, (s32)r->name, 0x81, h[0]);
            w->speciesName = Digi_GetDefaultName(r->speciesId);
            w->typeName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetType)(r->speciesId) + 0x1FD00C3);
            w->rankName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetRank)(r->speciesId) + 0x1FD00C6);
            w->specialtyName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetSpecialty)(r->speciesId) + 0x1FD00CA);
            q = w->parentNames;
            for (i = 0; i < 2; i++) {
                if (r->parentIds[i] != 0) {
                    *q++ = Digi_GetDefaultName(r->parentIds[i]);
                }
            }
            *q = 0;
            Text_PrintList(&w->infoTexts, &h[1], (s32 *)&w->speciesName, 1);
            Task_NextState1(a);
            break;
        case 1:
            w->modelPhase = 1;
            GsSetOffset(-0xA0, w->rot[0] * 80 / 682 + 180);
            Task_NextState1(a);
            break;
        case 2:
            Math_RampToOne((s32)a, &w->modelScale);
            p = w->rot;
            s = w->rotSpeed;
            a->childCount = 1;
            p[1] += s[1];
            if (Pad_State[0].left != 0) {
                s[1] = (s[1] - 5 < -0x22) ? -0x22 : s[1] - 5;
            }
            if (Pad_State[0].right != 0) {
                s[1] = (s[1] + 5 >= 0x23) ? 0x22 : s[1] + 5;
            }
            if (Pad_State[0].down != 0) {
                p[0] = (p[0] + 0xB > 0) ? 0 : p[0] + 0xB;
            }
            if (Pad_State[0].up != 0) {
                p[0] = (p[0] - 0xB < -0x2AA) ? -0x2AA : p[0] - 0xB;
            }
            GsSetOffset(-0xA0, p[0] * 80 / 682 + 180);
            d = Pad_State;
            if (d->triangle > 0 || d->circle > 0) {
                Task_SetState0(a, 2);
                if (d->circle > 0) {
                    Menu_Ctx->confirmed = -1;
                    Snd_PlayById(0xE, 0);
                } else {
                    Menu_Ctx->confirmed = 0;
                    Snd_PlayById(0xB, 0);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        default:
        case 0:
            Text_CloseArray(w, 0x1B);
            Task_NextState1(a);
            break;
        case 1:
            Math_RampToZero((s32)a, &w->modelScale);
            if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                GsSetOffset(0, 0);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

extern s32 GsSetRefView2(GsRVIEW2 *);

void Menu_DigiStatusDraw(Actor *actor) {
    Wk19214 *work;
    Rec19214 *rec;
    s32 *list;
    s32 *p;
    void *obj;
    Nd19214 *node;
    GsRVIEW2 ls;

    work = (Wk19214 *)actor->work;
    if (work->ramp == 0) {
        goto Ltail;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130021);
    rec = (Rec19214 *)work->digimon;
    if (*p == 0) {
        goto Ltail;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        list++;
        Gfx_SetPartsNumber(obj, 0x2, 3, rec->maxHp);
        Gfx_SetPartsNumber(obj, 0x4, 3, rec->hp);
        Gfx_SetPartsNumber(obj, 0x8, 3, rec->maxMp);
        Gfx_SetPartsNumber(obj, 0x10, 3, rec->mp);
        Gfx_SetPartsNumber(obj, 0x20, 2, rec->level);
        Gfx_SetPartsNumber(obj, 0x40, 3, rec->attack);
        Gfx_SetPartsNumber(obj, 0x80, 3, rec->defense);
        Gfx_SetPartsNumber(obj, 0x100, 3, rec->speed);
        Gfx_SetPartsNumber(obj, 0x200, 8, rec->exp);
        Gfx_SetPartsNumber(obj, 0x400, 8, Digi_GetExpToNextLevel(rec->level, rec->maxLevel, rec->exp));
        Gfx_SetPartsScale((GfxPartScaleView *)obj, 0x1000, work->ramp);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);

Ltail:
    work->field_148 = 0;
    RotMatrixYXZ(&work->rot, &work->coordMatrix);
    work->coordTx = work->posX;
    work->coordTy = work->posY;
    work->coordTz = work->posZ;
    work->coord = 0;
    ls.vpx = work->vpx;
    ls.vpy = work->vpy;
    ls.vpz = work->vpz;
    ls.vrx = work->vrx;
    ls.vry = work->vry;
    ls.vrz = work->vrz;
    ls.rz = 0;
    ls.super = &work->coord;
    GsSetProjection(work->projection);
    GsSetRefView2(&ls);
    if (work->modelPhase == 0) {
        return;
    }
    if (work->modelScale == 0) {
        return;
    }
    if (work->modelPhase == 1) {
        Anim_SetModelAnim(actor, 0);
        work->modelPhase = work->modelPhase + 1;
    }
    node = (Nd19214 *)actor->u38.ptr38;
    node->scaleX = work->modelScale;
    node->scaleY = work->modelScale;
    node->scaleZ = work->modelScale;
    Gfx_AttachModel(actor, work->modelFile);
    Anim_StepModelAnim(actor);
    Actor_UpdateTransform(actor);
    Gfx_CalcModelBoneMatrices(actor);
    Gfx_DrawTexModel(actor, 0);
}
