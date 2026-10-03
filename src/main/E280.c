#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/4BCC.h"
#include "main/6530.h"
#include "main/77DC.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
s32 D_80050778;
s32 D_8005077C;

u8 func_8001DA80(s32 id, s32 val) {
    EntD8C4 *e = func_8001D8C4(id);
    s32 i;

    if (e->rangeValues[0] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (e->rangeBounds[i + 1] == 0) {
            break;
        }
        if (val >= e->rangeBounds[i] && val < e->rangeBounds[i + 1]) {
            break;
        }
    }
    return e->rangeValues[i];
}

Ent1DB18 *func_8001DB18(s32 id) {
    Rec1DB18 *p = (Rec1DB18 *)Cd_GetFileOrNull(0xC6F);

    while (1) {
        if (p->id == 0) {
            break;
        }
        if (p->id == id) {
            return (Ent1DB18 *)p;
        }
        p++;
    }
    return 0;
}

void func_8001DB68(void *a0, Out1DB68 *out) {
    Ent1DB18 *src = func_8001DB18(a0);
    Ent1DB18 *p;
    s32 i;
    out->field_0 = src->u0.h.field_2;
    out->field_4 = ((s32)src->u0.field_0 << 20) >> 28;
    out->field_8 = ((s32)src->u0.field_0 << 16) >> 28;
    out->field_C = src->u4.field_4b;
    out->field_10 = (src->u4.field_4 >> 8) & 0xF;
    out->field_14 = (src->u4.field_4 >> 12) & 0xF;
    p = src;
    out->field_18 = p->u4.h.field_6;
    {
        DigiInitRow *row = (DigiInitRow *)p;
        for (i = 0; i < 3; i++) {
            out->digiIds[i] = row[i].digiId;
            out->levels[i] = row[i].level;
        }
    }
}

void Digi_InitFromTable(s32 a0, s32 a1, DigiRosterEntry *e) {
    DigiInitRow *r = (DigiInitRow *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    Mem_Zero(e, 0x5C);
    e->state = 2;
    {
        DigiInitRow *row = &r[a1];
        e->digiId = row->digiId;
        e->hp = e->maxHp = row->hp;
        e->mp = e->maxMp = row->mp;
    }
    name = Digi_GetDefaultName(e->digiId);
    for (i = 0; i < 14; i++) {
        e->name[i] = name[i];
    }
    {
        DigiInitRow *row = &r[a1];
        e->level = row->level;
        e->field_1C = row->field_13;
        e->field_1E = row->field_14;
        e->field_20 = row->field_16;
        e->attr[0] = row->field_17;
        e->attr[1] = row->field_18;
        e->attr[2] = row->field_19;
    }
    e->maxLevel = func_8001EB58(e->level);
    if (e->level == 1) {
        e->exp = 0;
    } else {
        e->exp = Digi_GetExpToNextLevel(e->level - 1, 100, 0);
    }
}

void func_8001DDA8(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o) {
    Tbl1DDA8 *t = (Tbl1DDA8 *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    e->state = a1 + 3;
    e->digiId = t->rows[a1].digiId;
    e->hp = e->maxHp = t->rows[a1].hp;
    e->mp = e->maxMp = t->rows[a1].mp;
    if (e->digiId != 0) {
        name = Digi_GetDefaultName(e->digiId);
        for (i = 0; i < 14; i++) {
            e->name[i] = name[i];
        }
        e->level = t->rows[a1].field_A;
        e->exp = t->rows[a1].field_6;
        e->field_1C = t->rows[a1].field_B;
        e->field_1E = t->rows[a1].field_C;
        e->field_20 = t->rows[a1].field_E;
        e->attr[0] = t->rows[a1].field_F;
        e->attr[1] = t->rows[a1].field_10;
        e->attr[2] = t->rows[a1].field_11;
        for (i = 3; i < 12; i++) {
            e->attr[i] = 0;
        }
        o->field_2 = t->rows[a1].field_F;
        o->field_3 = t->rows[a1].field_10;
        o->field_4 = t->rows[a1].field_11;
        o->field_9[0] = t->rows[a1].field_12[0][1];
        o->field_9[1] = t->rows[a1].field_12[1][1];
        o->field_9[2] = t->rows[a1].field_12[2][1];
        o->field_9[3] = t->rows[a1].field_12[3][1];
        o->field_0 = t->rows[a1].field_8;
        o->field_D[0] = t->rows[a1].field_12[0][2];
        o->field_D[1] = t->rows[a1].field_12[1][2];
        o->field_D[2] = t->rows[a1].field_12[2][2];
        o->field_D[3] = t->rows[a1].field_12[3][2];
        o->field_5[0] = t->rows[a1].field_12[0][0];
        o->field_5[1] = t->rows[a1].field_12[1][0];
        o->field_5[2] = t->rows[a1].field_12[2][0];
        o->field_5[3] = t->rows[a1].field_12[3][0];
    }
}


ItemTableEntry *Item_FindById(arg0)
s32 arg0;
{
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    while (*p != 0) {
        if (*p == arg0) {
            return (ItemTableEntry *)p;
        }
        p = (s16 *)((u8 *)p + 0x10);
    }
    return 0;
}

s32 Item_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->nameOffset + base;
}

s32 Item_GetDescText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->descOffset + base;
}

s32 func_8001E0C0(s32 id) {
    return Item_FindById(id)->u0.b0.field_2;
}

s32 func_8001E0E4(void) {
    return Item_FindById()->u0.b0.field_3 & 0xF;
}

s32 Item_CheckId(void) {
    return Item_FindById() != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return Item_FindById()->u0.field_0 >> 30;
}

s32 func_8001E158(void) {
    return (Item_FindById()->u0.field_0 >> 28) & 3;
}

s32 func_8001E180(void) {
    return Item_FindById()->u4.field_4 & 0xFFFFFF;
}

u8 func_8001E1AC(void) {
    return Item_FindById()->u4.b4.field_7;
}

s32 Item_GetTableIndex(s32 id) {
    ItemTableEntry *p = (ItemTableEntry *)Cd_GetFileEntry(0x45E0000);
    s32 i = 0;

    while (p->u0.id != 0) {
        if (p->u0.id == id) {
            return i;
        }
        p++;
        i++;
    }
    return 0;
}

s32 Item_GetIdAtIndex(s32 a0) {
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    s32 i;
    s32 r;
    for (i = 0; i < a0; i++) {
        if (*p == 0) break;
        p = (s16 *)((u8 *)p + 0x10);
    }
    r = 0;
    if (i == a0) {
        r = *p;
    }
    return r;
}

void func_8001E28C(s32 arg0) {
    D_8005D560.fileId = arg0;
}

Blk18 *func_8001E298(FlagEntryIdx *arg0) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[arg0->condIdx];
}

Blk18 *func_8001E2E0(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altCondIdx];
}

Blk18 *func_8001E338(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altSetIdx];
}

s32 Flag_NextPassingEntry(void) {
    while (D_8005D560.cursor->field_0 != 0) {
        if (Flag_TestConds(func_8001E298((FlagEntryIdx *)D_8005D560.cursor)) != 0) {
            D_8005D560.match = *D_8005D560.cursor;
            {
                s32 r = D_8005D560.entryIndex;

                D_8005D560.cursor++;
                D_8005D560.entryIndex = r + 1;
                return r;
            }
        }
        D_8005D560.cursor++;
        D_8005D560.entryIndex++;
    }
    return -1;
}

void func_8001E480(void) {
    D_8005D560.fileBase = Cd_GetFileOrNull(D_8005D560.fileId);
    D_8005D560.cursor = Cd_GetFileEntry(D_8005D560.fileId << 16);
    D_8005D560.entryIndex = 0;
    Flag_NextPassingEntry();
}

FlagBranchEntry *func_8001E4CC(arg0)
s32 arg0;
{
    FlagBranchEntry *base = (FlagBranchEntry *)Cd_GetFileEntry(D_8005D560.fileId << 16);
    return &base[arg0];
}

extern s32 Flag_TestConds();
extern void Flag_ApplySets();

s32 Flag_SelectBranch(s32 arg0) {
    FlagBranchEntry *base;
    s32 r;
    s32 i;
    r = Cd_GetFileOrNull(D_8005D560.fileId);
    base = func_8001E4CC(arg0);
    for (i = 0; i < 6; i++) {
        if (Flag_TestConds(func_8001E2E0((FlagEntryIdx *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    Flag_ApplySets(func_8001E338((FlagEntryIdx *)base, i));
    return base->branchOffsets[i] + r;
}

s32 func_8001E5C0(void) {
    return Cd_GetFileOrNull(D_8005D560.fileId);
}

Blk12 *func_8001E5E8(void) {
    FlagBranchEntry *e = func_8001E4CC();
    Blk12 *base = (Blk12 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 1);
    return &base[e->blockIndex];
}

s16 func_8001E634(void) {
    return func_8001E4CC()->field_0;
}

s16 func_8001E658(void) {
    return func_8001E4CC()->field_2;
}

s32 Digi_GetDataFileId(s32 arg0) {
    if (arg0 < 0x12C) {
        return 0xCB9;
    }
    if ((u32)(arg0 - 0x190) < 0x65) {
        return 0xCBB;
    }
    return 0xCBA;
}

DigiData *Digi_FindDataById(s32 id) {
    DigiData *e = (DigiData *)Cd_GetFileEntry(Digi_GetDataFileId(id) << 16);
    s32 k;

    while (1) {
        k = (e->u4.packedId >> 1) & 0x7FFF;
        if (k == 0) {
            break;
        }
        if (k == id) {
            return e;
        }
        e++;
    }
    return 0;
}

s32 Digi_GetModelFile(s32 id) {
    return Digi_FindDataById(id)->u4.h4.modelFile;
}

s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1) {
    return Digi_FindDataById(arg0)->animFiles[arg1];
}

u8 *Digi_GetDefaultName(s32 id) {
    s32 v;

    v = Digi_FindDataById(id)->nameOffset;
    v += Cd_GetFileOrNull(Digi_GetDataFileId(id));
    return (u8 *)v;
}

s16 func_8001E79C(s32 id) {
    return Digi_FindDataById(id)->field_1E;
}

s16 func_8001E7C0(s32 id) {
    return Digi_FindDataById(id)->field_20;
}

void func_8001E7E4(s32 a0, void *a1) {
    u8 *base;
    DigiData *e;
    base = (u8 *)Cd_GetFileEntry((Digi_GetDataFileId(a0) << 16) | 1);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 0) = *(Row6 *)(base + e->field_22 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 6) = *(Row6 *)(base + e->field_24 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 12) = *(Row6 *)(base + e->field_26 * 6);
}

s32 func_8001E8D0(s32 id) {
    return Digi_FindDataById(id)->u4.packedId & 1;
}

u16 func_8001E8F4(s32 idx) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000) + idx;
    return (p->packedId >> 1) & 0x7FFF;
}

s32 func_8001E938(void) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000);
    s32 i = 0;
    while ((p->packedId >> 1) & 0x7FFF) {
        p++;
        i++;
    }
    return i;
}

s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur) {
    s32 x;
    s32 exp;

    if (lv >= max) {
        return 99999999;
    }
    if (lv >= 62) {
        x = lv - 61;
        exp = 826540 + x * 65535;
    } else if (lv >= 31) {
        x = lv - 30;
        exp = x * x * x * 20 + x * x * 60 + x * 4580 + 31080;
    } else if (lv >= 21) {
        x = lv - 20;
        exp = x * x * x * 10 + x * x * 30 + x * 1220 + 5880;
    } else if (lv >= 11) {
        x = lv - 10;
        exp = x * x * x * 10 / 3 + x * x * 10 + x * 107 + 480;
    } else {
        x = lv;
        exp = x * x * x / 3 + x * x + x * 5;
    }
    if (exp < cur) {
        return 0;
    }
    return exp - cur;
}

s32 func_8001EB58(s32 x) {
    s32 h = x / 2;

    if (x < 6) {
        return x / 3 + 13;
    }
    if (x < 18) {
        return h + 14;
    }
    if (x < 28) {
        return h + 17;
    }
    {
        s32 r = (u16)((u16)Rand_Next() % 3) + 2;
        return x + r;
    }
}

void func_8001EC00(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void func_8001EC10(Actor *arg0) {
    s32 state = arg0->stateLevel0;

    switch (state) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorWork *w = arg0->work;
        Actor *v1 = (Actor *)w->field_0;
        w->field_4 = 0;
        if (v1 != 0) {
            s32 st = v1->stateLevel0;
            if (st != 0 && st != 3) {
                ModelBone *de = v1->model->bones;
                ActorTransformView *dst = arg0->u38.ptr38;
                s32 t = de->worldTx;
                dst->posY = 0;
                dst->posX = t;
                dst->posZ = de->worldTz;
                w->field_4 = state;
            }
        }
        break;
    }
    case 2:
        break;
    }
}

void func_8001ECE4(Actor *arg0) {
    if (arg0->work->field_4 != 0) {
        Gfx_AttachModel(arg0, 0x5B);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 1);
    }
}

EntED40 *func_8001ED40(s32 id) {
    EntED40 *p = (EntED40 *)Cd_GetFileEntry(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 func_8001ED84(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    EntED40 *p = func_8001ED40(arg0);
    if (p != 0) {
        return p->nameOffset + base;
    }
    return 0;
}

s32 func_8001EDD4(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    return func_8001ED40(arg0)->descOffset + base;
}

s32 func_8001EE10(s32 id) {
    return func_8001ED40(id)->u0.h0.field_2 & 3;
}

s32 func_8001EE34(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 18) & 3;
}

s32 func_8001EE5C(s32 id) {
    return func_8001ED40(id)->field_C;
}

u8 func_8001EE80(s32 id) {
    return func_8001ED40(id)->field_4;
}

void func_8001EEA4(s32 id, s32 n, s16 *a, s16 *b) {
    EntED40 *p = func_8001ED40(id);
    s32 i;

    n *= 2;
    for (i = 0; i < 3; i++) {
        a[i] = p->field_2C[n][i];
        b[i] = p->field_2C[n + 1][i];
    }
}


s32 func_8001EF3C(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 20) & 0xF;
}

s16 func_8001EF64(s32 id) {
    return func_8001ED40(id)->field_8;
}

u16 func_8001EF88(s32 id) {
    u16 v = func_8001ED40(id)->u0.b0.field_3 & 0xF;

    if (v == 6) {
        return (u16)Rand_Next() % 5;
    }
    return v;
}

s32 *func_8001EFF0(s32 id) {
    EntED40 *e = func_8001ED40(id);
    D_80050778 = e->field_6;
    D_8005077C = e->field_5;
    return &D_80050778;
}


u8 func_8001F020(s32 id) {
    return func_8001ED40(id)->u10.field_10b;
}

s32 func_8001F044(s32 id) {
    return func_8001ED40(id)->field_20 & 0xF;
}

s32 func_8001F068(s32 id) {
    return func_8001ED40(id)->field_18 & 0x3FFFFFF;
}

s32 func_8001F094(s32 id) {
    return func_8001ED40(id)->field_1C & 0x3FFFF;
}

s32 func_8001F0C0(s32 id) {
    return func_8001ED40(id)->u0.field_0 >> 28;
}

s32 func_8001F0E4(s32 id) {
    return (func_8001ED40(id)->u10.field_10 >> 8) & 0x7FFF;
}

s32 func_8001F10C(s32 id) {
    return func_8001ED40(id)->field_14 & 0x3FF;
}

s32 func_8001F130(s32 id) {
    return (func_8001ED40(id)->field_14 >> 10) & 0x1FFF;
}

s32 func_8001F158(s32 id) {
    return (func_8001ED40(id)->field_1C >> 18) & 0x1F;
}

s32 func_8001F180(s32 id) {
    return (func_8001ED40(id)->field_1C >> 23) & 0xFF;
}

void Anim_SetModelAnim(Actor *a, s32 n) {
    ActorModel *s = a->model;
    s32 i;
    s32 k;

    s->animId = n;
    s->animPos = 0;
    s->animData = 0;
    for (i = 10; i < 0x6F; i += 10) {
        if (n < i) {
            s->animFileId = Anim_GetModelAnimFile(a->digiId, i / 10 - 1);
            k = i - 10;
            s->animIndex = n - k;
            break;
        }
    }
    s->animTimer = 1;
    s->animDone = 0;
}

void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2) {
    ActorModel *p = arg0->model;
    p->animId = arg1;
    p->animPos = 0;
    p->animData = 0;
    p->animFileId = arg2;
    p->animIndex = 0;
    p->animTimer = 1;
    p->animDone = 0;
}

#ifdef NORMALIZED
s32 Anim_HasModelAnim(Actor *a0, s32 n) {
    ActorModel *sub = a0->model;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        k = 0;
        n = k;
        id = Anim_GetModelAnimFile(a0->digiId, k);
    } else if (n < 20) {
        id = Anim_GetModelAnimFile(a0->digiId, 1);
        n -= 10;
    } else {
        id = Anim_GetModelAnimFile(a0->digiId, 2);
        n -= 20;
    }
    p = (s32 *)(Cd_GetFileOrNull(id) + ((sub->boneCount + 1) << 2));
    sub->animTable = p;
    return p[n] != 0;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Anim_HasModelAnim);
s32 Anim_HasModelAnim(Actor *a0, s32 n);
#endif

void Anim_StepModelAnim(Actor *a) {
    ActorModel *s = a->model;
    s32 *data = (s32 *)Cd_GetFileOrNull(s->animFileId);
    s32 i;
    s32 j;
    s32 k;
    ModelBone *e;
    u8 *f;
    u8 *q;
    s32 pos;
    Rec18 *r;

    if (data != s->animData) {
        s->animData = data;
        s->bonePoseTables = data + 1;
        {
            s32 n = s->boneCount + 1;
            s->animTable = &data[n];
        }
    }
    if (data[0] == 0) {
        data[0] = 1;
        for (k = 0; s->animTable[k] != 1; k++) {
            if (s->animTable[k] != 0) {
                s->animTable[k] += (s32)data;
            }
        }
        for (k = 0; k < s->boneCount; k++) {
            s->bonePoseTables[k] += (s32)data;
        }
    }
    s->animTimer += D_8005F770.frameDelta;
    while (s->animTimer >= 2) {
        s->animTimer -= 2;
        e = s->bones;
        f = (u8 *)s->animTable[s->animIndex];
        pos = s->animPos;
        for (i = 0; i < s->boneCount; i++) {
            e->keyIndex = f[s->animPos++];
            e++;
        }
        q = &f[s->animPos];
        if (*q & 0x80) {
            switch (*q) {
            case 0xFF:
                s->animDone = -1;
                s->animPos = pos;
                goto done;
            case 0xFE:
                s->animPos = (q[2] << 8) | q[1];
                s->animDone = -1;
                break;
            }
        }
    }
done:
    {
        ModelBone *b = s->bones;
        s32 n;
        for (n = 0; n < s->boneCount; n++, b++) {
            r = &((Rec18 *)s->bonePoseTables[n])[b->keyIndex];
            b->localMat.m = r->m;
            for (j = 0; j < 3; j++) {
                b->localMat.t[j] = r->t[j];
            }
        }
    }
}

void Gfx_ResetModelBones(Actor *a0) {
    ActorModel *sub = a0->model;
    ModelBone *p = sub->bones;
    s32 i = 0;
    while (i < sub->boneCount) {
        i++;
        p->localMat = D_80043714;
        p++;
    }
}

void Gfx_AddFlatQuad3D(GfxQuadColor *col, GfxQuadVert *v, s32 flags, s32 idx) {
    Coord1F668 coord;
    Mat1F668 m;
    s32 pz;
    s32 flag;
    PolyF4_1F668 *p;
    PolyF4_1F668 *q;
    DrMode1F668 *dm;
    s32 *ot;
    SysState *g;

    GsInitCoordinate2(0, &coord);
    GsGetLs(&coord, &m);
    GsSetLsMatrix(&m);
    g = &D_8005F770;
    p = (PolyF4_1F668 *)g->packet.work;
    ot = g->otLayers.s[idx];
    p->c = *col;
    SetPolyF4((u8 *)p);
    q = p;
    if (flags & 4) {
        p->c.code |= 2;
    }
    RotTransPers(&v[0], &p->xy[0], &pz, &flag);
    p->xy[0].x /= 2;
    p->xy[0].y /= 2;
    RotTransPers(&v[1], &p->xy[1], &pz, &flag);
    p->xy[1].x /= 2;
    p->xy[1].y /= 2;
    RotTransPers(&v[2], &p->xy[2], &pz, &flag);
    p->xy[2].x /= 2;
    p->xy[2].y /= 2;
    RotTransPers(&v[3], &p->xy[3], &pz, &flag);
    p->xy[3].x /= 2;
    p->xy[3].y /= 2;
    p->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p++;
    SetDrawMode((DrMode1F668 *)p, 0, 0, (flags & 3) << 5, 0);
    dm = (DrMode1F668 *)(q + 1);
    dm->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p = (PolyF4_1F668 *)(dm + 1);
    g->packet.work = (ActorWork *)p;
}


void Gfx_InitLights(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &D_800416CC[i]);
    }
    GsSetAmbient(0x4CC, 0x4CC, 0x4CC);
    GsSetLightMode(0);
}

s32 func_8001F970(s32 arg0) {
    if (arg0 == 0x64 || arg0 == 0xA || arg0 == 0x14) {
        return 0;
    }
    if (arg0 == 0x15) {
        return 0;
    }
    return arg0 != 0x16;
}

void Gfx_AnimateModelTex(Actor *a0) {
    ActorModel *w = a0->model;
    GfxTexAnimPart *r = (GfxTexAnimPart *)w->texAnimParts;
    GfxModelTexSlot *pos = w->texSlot;
    s32 k = 0;
    s32 j;
    s32 i;
    s32 c;
    s32 m;
    DR_MOVE *prim;
    RECT rc;
    RECT rc2;
    GfxModelTexAnim *q;
    u8 n;

    if (r->dstX != 0xFF) {
        if (func_8001F970(w->animId) != 0) {
            switch (w->blinkTimer >> 1) {
            case 0:
                w->blinkTimer = (Rand_Next() & 0x7F) + 0x3C;
            default:
                k = 0;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                k = 2;
                break;
            case 3:
            case 4:
                k = 4;
                break;
            }
            if ((w->blinkTimer -= D_8005F770.frameDelta) < 0) {
                w->blinkTimer = 0;
            }
        } else {
            k = 4;
            w->blinkTimer = 0;
        }
    }
    w->texAnimTimer += D_8005F770.frameDelta;
    while (1) {
        if (w->texAnimTimer < 0x18) break;
        w->texAnimTimer -= 0x18;
    }
    j = (w->texAnimTimer / 8) * 2;
    prim = D_8005F770.packet.drMove;
    for (i = 0; i < 10; i++, r++) {
        if (i < 2) {
            if (r->dstX == 0xFF) continue;
        } else {
            if (r->dstX == 0xFF) break;
            if (r->dstX == 0xFE) break;
        }
        if (i < 2) {
            rc.x = r->uv[k] + pos->vramX;
            rc.y = r->uv[k + 1] + pos->vramY;
        } else {
            rc.x = r->uv[j] + pos->vramX;
            rc.y = r->uv[j + 1] + pos->vramY;
        }
        rc.w = r->w;
        rc.h = r->h;
        SetDrawMove(prim, &rc, r->dstX + pos->vramX, r->dstY + pos->vramY);
        AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
        prim++;
    }
    if (r->dstX == 0xFE) {
        q = (GfxModelTexAnim *)&(r++)->dstY;
        for (c = 0; c < 10; c++, q++) {
            if (q->dstX == 0xFF) break;
            if (D_8005F770.frameDelta == 1) {
                q->timer += 1;
            } else {
                q->timer += 2;
            }
            n = q->period;
            while (1) {
                if (q->timer < n) break;
                q->timer -= n;
            }
            m = (q->timer >> 1) * 4;
            rc2.x = q->uv[m] + pos->vramX;
            rc2.y = q->uv[m + 1] + pos->vramY;
            rc2.w = q->w;
            rc2.h = q->h;
            SetDrawMove(prim, &rc2, q->dstX + pos->vramX, q->dstY + pos->vramY);
            AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->vramX;
            rc2.y = q->uv[m + 3] + pos->vramY;
            rc2.w = q->w2;
            rc2.h = q->h2;
            SetDrawMove(prim, &rc2, q->dstX2 + pos->vramX, q->dstY2 + pos->vramY);
            AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
            prim++;
        }
    }
    D_8005F770.packet.addr = (s32)prim;
}
INCLUDE_RODATA("asm/USA/main/rodata", D_800101E4);


ActorModel *Gfx_AttachModel(Actor *a0, s32 id) {
    s32 fresh = 0;
    GfxModelFile *m = (GfxModelFile *)Cd_GetFileOrNull(id);
    GfxModelFile *base = m;
    ActorModel *t = a0->model;
    ActorModel *s;
    s32 i;
    ModelQuadSection *p;
    ModelQuadSection *q;
    GfxModelTriSec *r;
    s32 v;
    Ent1FDBC20 *e;

    if (t == NULL) {
        a0->model = (ActorModel *)Mem_Alloc(0x7C, 2);
        Mem_Zero(a0->model, 0x7C);
        fresh = 1;
    } else if (t->file == m && m->relocated != 0) {
        return t;
    }
    s = a0->model;
    s->fileId = id;
    s->file = base;
    s->boneCount = m->count;
    s->boneVerts = (s16 **)base->tables;
    s->boneNormals = s->boneVerts + s->boneCount;
    s->bonePolys = (ModelQuadSection **)(s->boneNormals + s->boneCount);
    s->boneDepths = (s32 *)(s->bonePolys + s->boneCount);
    s->texAnimParts = s->boneDepths + s->boneCount;
    if (m->relocated == 0) {
        for (i = 0; i < s->boneCount; i++) {
            s->boneVerts[i] = (s16 *)((s32)s->boneVerts[i] + (s32)base);
            s->boneNormals[i] = (s16 *)((s32)s->boneNormals[i] + (s32)base);
            s->bonePolys[i] = (ModelQuadSection *)((s32)s->bonePolys[i] + (s32)base);
        }
        m->relocated = 1;
    }
    if (fresh) {
        s->maxVerts = 0;
        s->maxNormals = 0;
        for (i = 0; i < s->boneCount; i++) {
            if (s->maxVerts < *s->boneVerts[i]) {
                s->maxVerts = *s->boneVerts[i];
            }
            if (s->maxNormals < *s->boneNormals[i]) {
                s->maxNormals = *s->boneNormals[i];
            }
        }
        s->field_28 = 0;
        for (i = 0; i < s->boneCount; i++) {
            p = s->bonePolys[i];
            e = p->e;
            q = (ModelQuadSection *)(e + p->n);
            e = q->e;
            r = (GfxModelTriSec *)(e + q->n);
            v = r->e[r->n].v[0];
            if (s->field_28 < v) {
                s->field_28 = v;
            }
        }
        s->bones = (ModelBone *)Mem_Alloc(s->boneCount * sizeof(ModelBone), 2);
        s->screenXY = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertOtz = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertColors = (s32 *)Mem_Alloc(s->maxNormals * 4, 2);
    }
    return s;
}

void Gfx_CalcModelBoneMatrices(Actor *a0) {
    CoordMatrix cam;
    Mat1F668 light;
    ActorModel *s;
    ActorTransformView *o;
    ModelBone *d;
    GfxBoneScratchNode *sp;
    GfxBoneScratchNode *e;
    Blk20 *r;
    Blk20 *in;
    Blk20 *out;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    s = a0->model;
    o = a0->u38.ptr38;
    d = s->bones;
    cam = D_80061A08;
    light = D_800619A8;
    sp = (GfxBoneScratchNode *)0x1F800000;
    sp[0].parent = 0;
    sp[0].local = o->matrix;
    sp[0].local.t[0] = o->posX;
    sp[0].local.t[1] = o->posY;
    sp[0].local.t[2] = o->posZ;
    sp[0].world.m = sp[0].local;
    for (i = 1; i < 9; i++) {
        sp[i].parent = &sp[i - 1];
    }
    n = s->boneCount;
    for (j = 0; j < n; j++, d++) {
        e = &sp[s->boneDepths[j] + 1];
        e->local = d->localMat;
        for (k = 0; k < 3; k++) {
            switch (k) {
            default:
            case 0:
                r = &e->parent->world.m;
                in = &e->local;
                out = &e->world.m;
                break;
            case 1:
                r = (Blk20 *)&cam;
                in = &e->world.m;
                out = &d->viewMat;
                break;
            case 2:
                r = (Blk20 *)&light;
                in = &e->world.m;
                out = &d->lightMat;
                break;
            }
            gte_SetRotMatrix(r);
            gte_ldclmv(&in->m.m[0][0]);
            gte_rtir();
            if (k == 1) {
                d->worldM0 = e->world.w[0];
                d->worldM1 = e->world.w[1];
            }
            gte_stclmv(&out->m.m[0][0]);
            gte_ldclmv(&in->m.m[0][1]);
            gte_rtir();
            if (k == 1) {
                d->worldM2 = e->world.w[2];
                d->worldM3 = e->world.w[3];
            }
            gte_stclmv(&out->m.m[0][1]);
            gte_ldclmv(&in->m.m[0][2]);
            gte_rtir();
            if (k == 1) {
                d->worldM4 = e->world.w[4];
                d->worldTx = e->world.w[5];
            }
            gte_stclmv(&out->m.m[0][2]);
            gte_SetTransMatrix(r);
            gte_ldlv0(in->t);
            gte_rtv0tr();
            if (k == 1) {
                d->worldTy = e->world.w[6];
                d->worldTz = e->world.w[7];
            }
            gte_stlvnl(out->t);
        }
    }
}


void Gfx_DrawTexModel(Actor *a0, s32 mode) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    ModelQuadGT4 *q;
    GfxModelTriGT3 *r;
    s32 i;
    s32 j;
    s32 n;

    s = a0->model;
    i = 0;
    e = s->bones;
    s->texSlot = (struct GfxModelTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId << 16);
    s->otzShift = D_8005F770.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        gte_SetLightMatrix(&e->lightMat);
        Gfx_CalcNormalColors((Vert6Pmv *)s->boneNormals[i], (ModelProjView *)s);
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = (ModelQuadGT4 *)p->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    Gfx_AddQuadsGT4(q, n, s, 2);
                } else {
                    Gfx_AddQuadsGT4(q, n, s, j);
                }
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = (GfxModelTriGT3 *)((GfxModelTriSec *)p)->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    func_80020FD0(r, n, s, 2);
                } else {
                    func_80020FD0(r, n, s, j);
                }
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
    Gfx_AnimateModelTex(a0);
}


void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    Ent1FDBC20 *q;
    GfxModelTri *r;
    s32 i;
    s32 j;
    s32 n;

    i = 0;
    s = a0->model;
    e = s->bones;
    s->otzShift = D_8005F770.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = p->e;
            if (n != 0) {
                Gfx_DrawWireQuads((GfxModelQuad *)q, n, (ModelProjView *)s, col);
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = ((GfxModelTriSec *)p)->e;
            if (n != 0) {
                Gfx_DrawWireTris((ModelWireTri *)r, n, (ModelProjView *)s, col);
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
}


extern void RotMatrixYXZ(void *, Obj209 *);
extern void ScaleMatrix(Obj209 *, s32 *);

void Actor_UpdateTransform(Actor *arg0) {
    Obj209 *obj = (Obj209 *)arg0->u38.ptr38;
    s32 local[3];

    obj->prevPos = obj->pos;
    RotMatrixYXZ(&obj->rot, obj);
    ApplyMatrixLV((CoordMatrix *)obj, &obj->moveX, local);
    obj->pos.x += local[0];
    obj->pos.y += local[1];
    obj->pos.z += local[2];
    if (obj->scaleX == 0x1000 && obj->scaleY == obj->scaleX &&
        obj->scaleZ == obj->scaleY) {
    } else {
        ScaleMatrix(obj, &obj->scaleX);
    }
    obj->moveZ = 0;
    obj->moveY = 0;
    obj->moveX = 0;
}

s32 Actor_ProjectToScreen(ContC40 *a0) {
    Mat1F668 m;
    AllocC40 *p;
    LongVec3 *t;
    s32 x, y;

    p = a0->transform;
    t = &p->t;
    *t = *(LongVec3 *)&p->posX;
    gte_SetRotMatrix(&D_80061A08);
    gte_ldclmv(&p->m[0][0]);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&p->m[0][1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&p->m[0][2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);
    gte_SetTransMatrix(&D_80061A08);
    gte_ldlv0(t);
    gte_rtv0tr();
    gte_stlvnl(m.t);
    gte_SetRotMatrix(&m);
    gte_SetTransMatrix(&m);
    gte_ldv0(D_80050744);
    gte_rtps();
    gte_stsxy(&p->screenX);
    x = 0x160;
    y = 0x110;
    if (p->screenX < -x) return 1;
    if (p->screenX > x) return 1;
    if (p->screenY < -y) return 1;
    return p->screenY > y;
}


void Actor_RefreshTransform(s32 arg0) {
    Actor_UpdateTransform(arg0);
    Actor_ProjectToScreen(arg0);
}

extern void Mem_Zero(void *, s32);

void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2) {
    AllocC40 *p;
    if (a0->transform == 0) {
        a0->transform = (AllocC40 *)Mem_Alloc(0x90, 2);
    }
    Mem_Zero(a0->transform, 0x90);
    p = a0->transform;
    p->scaleZ = 0x1000;
    p->scaleY = 0x1000;
    p->scaleX = 0x1000;
    if (a1 != 0) {
        p->posX = a1[0];
        p->posY = a1[1];
        p->posZ = a1[2];
    }
    p->rotY = a2;
    Actor_RefreshTransform((s32)a0);
}

void Actor_StepAxisMotion(AxisMotion *a0, s32 a1) {
    s32 v = a0->speed + a0->accel;
    a0->speed = v;
    if (v > 0) {
        if (v >= a0->maxSpeed) {
            a0->speed = a0->maxSpeed;
        }
    } else if (a1 == 0) {
        a0->maxSpeed = 0;
        a0->accel = 0;
        a0->speed = 0;
    } else {
        if (v >= a0->maxSpeed) {
            a0->speed = -a0->maxSpeed;
        }
    }
}

s32 func_80020D54(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    if (i != 1) {
        Actor_StepAxisMotion(e, 0);
    } else {
        Actor_StepAxisMotion(e, 1);
    }
    if (i != 2) {
        (&p->moveDelta.vx)[i] += e->speed >> 8;
    } else {
        p->moveDelta.vz -= e->speed >> 8;
    }
    return e->speed >> 8;
}

s32 func_80020E00(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    Actor_StepAxisMotion(e, 0);
    switch (i) {
    case 0:
    case 1:
        (&p->moveDelta.vx)[i] -= e->speed >> 8;
        break;
    case 2:
        p->moveDelta.vz += e->speed >> 8;
        break;
    }
    return e->speed >> 8;
}

void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->speed = arg2->speed;
    e->accel = arg2->accel;
    e->maxSpeed = arg2->maxSpeed;
}

void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->maxSpeed = 0;
    e->accel = 0;
    e->speed = 0;
}

void Gfx_CalcNormalColors(Vert6Pmv *v, ModelProjView *o) {
    s32 n;
    CVECTOR *c;
    s32 i;

    n = v->vx;
    c = o->vertColors;
    v++;
    if (o->field_34 != 0) {
        for (i = 0; i < n; i++) {
            *c = o->flatColor;
            c++;
        }
        return;
    }
    gte_ldv0u(v);
    gte_ncs();
    gte_strgb(c);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_ncs();
        v++;
        c++;
        i++;
        gte_strgb(c);
    }
}

#ifdef NORMALIZED
void func_80020FD0(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[3];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT3_20FD0 *p;
    s32 i;
    s32 z;
    SysState *g;

    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    tex = (GfxTexSlot *)s->texSlot;
    idx = s->otIndex;
    code = 0x36;
    if (mode == 1) {
        code = 0x34;
    }
    g = &D_8005F770;
    p = (PolyGT3_20FD0 *)g->packet.work;
    for (i = 0; i < n; i++, t++) {
        sxy[0] = xy[t->v[0]];
        sxy[1] = xy[t->v[1]];
        sxy[2] = xy[t->v[2]];
        gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
        gte_nclip();
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[1] == sxy[2]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 9;
        p->c0.code = 0x34;
        p->xy0 = sxy[0];
        p->xy1 = sxy[1];
        p->xy2 = sxy[2];
        p->c0 = col[t->c[0]];
        p->c1 = col[t->c[1]];
        p->c2 = col[t->c[2]];
        p->c0.code = code;
        z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
        if (mode == 2) {
            p->tpage = tex->tpage | s->field_36;
        } else {
            p->tpage = tex->tpage | t->tpage;
        }
        p->clut = t->clut + (((tex->vramY + s->field_34) << 6) | ((tex->vramX >> 4) & 0x3F));
        p->u0 = t->u0 + tex->uOffset;
        p->u1 = t->u1 + tex->uOffset;
        p->u2 = t->u2 + tex->uOffset;
        p->v0 = t->v0;
        p->v1 = t->v1;
        p->v2 = t->v2;
        p->tag.addr = ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr;
        ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr = (u32)p;
        p++;
        z = t->v[2];
    }
    D_8005F770.packet.addr = (s32)p;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020FD0);
void func_80020FD0(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode);
#endif


#ifdef NORMALIZED
void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[4];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT4_2130C *p;
    s32 i;
    s32 z;
    SysState *g;

    tex = (GfxTexSlot *)s->texSlot;
    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    idx = s->otIndex;
    code = 0x3E;
    if (mode == 1) {
        code = 0x3C;
    }
    g = &D_8005F770;
    p = (PolyGT4_2130C *)g->packet.work;
    for (i = 0; i < n; i++, t++) {
        sxy[0] = xy[t->v[0]];
        sxy[1] = xy[t->v[1]];
        sxy[2] = xy[t->v[2]];
        sxy[3] = xy[t->v[3]];
        gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
        gte_nclip();
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[0] == sxy[3] ||
            sxy[1] == sxy[2] || sxy[1] == sxy[3] || sxy[2] == sxy[3]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 12;
        p->c0.code = 0x3C;
        p->xy0 = sxy[0];
        p->xy1 = sxy[1];
        p->xy2 = sxy[2];
        p->xy3 = sxy[3];
        p->c0 = col[t->c[0]];
        p->c1 = col[t->c[1]];
        p->c2 = col[t->c[2]];
        p->c3 = col[t->c[3]];
        p->c0.code = code;
        z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]] + sz[t->v[3]]) / 4;
        if (mode == 2) {
            p->tpage = tex->tpage | s->field_36;
        } else {
            p->tpage = tex->tpage | t->tpage;
        }
        p->clut = t->clut + (((tex->vramY + s->field_34) << 6) | ((tex->vramX >> 4) & 0x3F));
        p->u0 = t->u0 + tex->uOffset;
        p->u1 = t->u1 + tex->uOffset;
        p->u2 = t->u2 + tex->uOffset;
        p->u3 = t->u3 + tex->uOffset;
        p->v0 = t->v0;
        p->v1 = t->v1;
        p->v2 = t->v2;
        p->v3 = t->v3;
        p->tag.addr = ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr;
        ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr = (u32)p;
        p++;
    }
    D_8005F770.packet.addr = (s32)p;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_AddQuadsGT4);
void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode);
#endif


s32 Gfx_ProjectModelVerts(Vert6Pmv *v, ModelProjView *o, s32 noCheck) {
    s32 otz;
    s32 flag;
    s32 n;
    SxyPmv *sxy;
    s32 *z;
    s32 zs;
    s32 xs;
    s32 ys;
    s32 i;
    SysState *scr;

    n = v->vx;
    v++;
    scr = &D_8005F770;
    sxy = (SxyPmv *)o->screenXY;
    z = o->vertOtz;
    zs = o->otzShift;
    xs = scr->centerX.s != 320;
    ys = scr->centerY.s != 240;
    gte_ldv0u(v);
    gte_rtps();
    gte_stsxy(sxy);
    gte_stszotz(&otz);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_rtps();
        v++;
        i++;
        *z = otz >> zs;
        z++;
        sxy->vx >>= xs;
        sxy->vy >>= ys;
        sxy++;
        gte_stsxy(sxy);
        gte_stszotz(&otz);
        if (!noCheck) {
            gte_stflg(&flag);
            if (flag < 0) {
                return 1;
            }
        }
    }
    *z = otz >> zs;
    sxy->vx >>= xs;
    sxy->vy >>= ys;
    return 0;
}

s32 Gfx_IsOriginOffscreen(void) {
    SxyIso sxy;
    s32 flag;

    gte_ldv0(D_80043704);
    gte_rtps();
    gte_stflg(&flag);
    if (flag < 0) {
        return 1;
    }
    gte_stsxy(&sxy);
    if (sxy.vx < -0x160) {
        return 1;
    }
    if (sxy.vx > 0x160) {
        return 1;
    }
    if (sxy.vy < -0x110) {
        return 1;
    }
    return sxy.vy > 0x110;
}

void Gfx_DrawWireTris(ModelWireTri *t, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l;
    Tpage21ABC *tp;
    s32 idx;

    pk = (GfxModelOTag *)D_8005F770.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, t++) {
        do {
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            ot = (u32 *)D_8005F770.otLayers.s[idx] + z;
            l = (LINE_F4 *)pk;
            l->c = *col;
            l->tag.len = 6;
            l->c.code = 0x4E;
            l->end = 0x55555555;
            l->xy[0] = l->xy[3] = sxy[t->v[0]];
            l->xy[1] = sxy[t->v[1]];
            l->xy[2] = sxy[t->v[2]];
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F770.packet.addr = (s32)pk;
}

void Gfx_DrawWireQuads(GfxModelQuad *q, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 xy[4];
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l4;
    LINE_F2 *l2;
    s32 *layer;
    Tpage21ABC *tp;
    GfxModelQuad *last;
    s32 idx;

    pk = (GfxModelOTag *)D_8005F770.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, q++) {
        do {
            z = (sz[q->v[0]] + sz[q->v[1]] + sz[q->v[2]] + sz[q->v[3]]) / 4;
            layer = D_8005F770.otLayers.s[idx];
            ot = (u32 *)layer;
            xy[0] = sxy[q->v[0]];
            xy[1] = sxy[q->v[1]];
            xy[2] = sxy[q->v[2]];
            last = q;
            xy[3] = sxy[last->v[3]];
            l4 = (LINE_F4 *)pk;
            l4->c = *col;
            l4->tag.len = 6;
            l4->c.code = 0x4E;
            l4->end = 0x55555555;
            l4->xy[0] = xy[0];
            l4->xy[1] = xy[1];
            l4->xy[2] = xy[3];
            l4->xy[3] = xy[2];
            ot += z;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            l2 = (LINE_F2 *)pk;
            l2->c = *col;
            l2->tag.len = 3;
            l2->c.code = 0x42;
            l2->xy[0] = xy[2];
            l2->xy[1] = xy[0];
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F2 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F770.packet.addr = (s32)pk;
}
