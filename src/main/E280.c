#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/6530.h"
#include "main/77DC.h"

/* Small data this unit defines (.sbss in game.h's order). Retail reaches the first two
 * with %gp_rel here; D_80050780 is only used by overlays. */
s32 Skill_ShotXaFile;
s32 D_8005077C;
s32 D_80050780;
/* .bss */
FlagEntryState Flag_EntryIter;

/* Task callbacks the descriptor below names (defined further down). */
void func_8001EC00(Actor *arg0, s32 *arg1);
void func_8001EC10(Actor *arg0);
void func_8001ECE4(Actor *arg0);

TaskDesc D_800416B4 = { (TaskInitFn)func_8001EC00, func_8001EC10, Task_DefaultDestroy, func_8001ECE4, 8, 0 };
/* The three flat lights Gfx_InitLights sets: direction, then color. */
Blk16 Gfx_FlatLights[] = {
    { 0, 0x3200, 0, 0x80, 0x80, 0x80 },
    { -0x3200, 0, 0, 0x37, 0x37, 0x37 },
    { 0x3200, 0, 0, 0x37, 0x37, 0x37 },
};

u8 Digi_GetEvolutionTarget(s32 id, s32 val) {
    DigiBaseData *e = Digi_FindBaseData(id);
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

Ent1DB18 *Enemy_FindSetById(s32 id) {
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

void Enemy_GetSetSummary(void *a0, Out1DB68 *out) {
    Ent1DB18 *src = Enemy_FindSetById(a0);
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
    DigiInitRow *r = (DigiInitRow *)Enemy_FindSetById(a0);
    u8 *name;
    s32 i;

    if ((Sys_GameMode[0] & 0xFF00) == 0x500) {
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
        e->attack = row->attack;
        e->defense = row->defense;
        e->speed = row->speed;
        e->attr[0] = row->skill0;
        e->attr[1] = row->skill1;
        e->attr[2] = row->skill2;
    }
    e->maxLevel = Digi_CalcMaxLevel(e->level);
    if (e->level == 1) {
        e->exp = 0;
    } else {
        e->exp = Digi_GetExpToNextLevel(e->level - 1, 100, 0);
    }
}

void Enemy_InitRosterEntry(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o) {
    Tbl1DDA8 *t = (Tbl1DDA8 *)Enemy_FindSetById(a0);
    u8 *name;
    s32 i;

    if ((Sys_GameMode[0] & 0xFF00) == 0x500) {
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
        e->level = t->rows[a1].level;
        e->exp = t->rows[a1].exp;
        e->attack = t->rows[a1].field_B;
        e->defense = t->rows[a1].field_C;
        e->speed = t->rows[a1].field_E;
        e->attr[0] = t->rows[a1].attr0;
        e->attr[1] = t->rows[a1].attr1;
        e->attr[2] = t->rows[a1].attr2;
        for (i = 3; i < 12; i++) {
            e->attr[i] = 0;
        }
        o->skill0 = t->rows[a1].attr0;
        o->skill1 = t->rows[a1].attr1;
        o->skill2 = t->rows[a1].attr2;
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

s32 Item_GetCategory(s32 id) {
    return Item_FindById(id)->u0.b0.category;
}

s32 Item_GetLevel(s32 itemId) {
    return Item_FindById(itemId)->u0.b0.field_3 & 0xF;
}

s32 Item_CheckId(s32 itemId) {
    return Item_FindById(itemId) != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return Item_FindById()->u0.field_0 >> 30;
}

/* Unnamed: ITEMDATA word0 bits 28-29, values 0/2/3, no callers. */
s32 func_8001E158(void) {
    return (Item_FindById()->u0.field_0 >> 28) & 3;
}

s32 Item_GetPrice(s32 itemId) {
    return Item_FindById(itemId)->u4.field_4 & 0xFFFFFF;
}

u8 Item_GetBodyMask(s32 itemId) {
    return Item_FindById(itemId)->u4.b4.bodyMask;
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

void Flag_SetTableFile(s32 arg0) {
    Flag_EntryIter.fileId = arg0;
}

Blk18 *Flag_GetEntryCondBlock(FlagEntryIdx *arg0) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[arg0->condIdx];
}

Blk18 *Flag_GetBranchCondBlock(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altCondIdx];
}

Blk18 *Flag_GetBranchSetBlock(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altSetIdx];
}

s32 Flag_NextPassingEntry(void) {
    while (Flag_EntryIter.cursor->field_0 != 0) {
        if (Flag_TestConds(Flag_GetEntryCondBlock((FlagEntryIdx *)Flag_EntryIter.cursor)) != 0) {
            Flag_EntryIter.match = *Flag_EntryIter.cursor;
            {
                s32 r = Flag_EntryIter.entryIndex;

                Flag_EntryIter.cursor++;
                Flag_EntryIter.entryIndex = r + 1;
                return r;
            }
        }
        Flag_EntryIter.cursor++;
        Flag_EntryIter.entryIndex++;
    }
    return -1;
}

void Flag_FirstPassingEntry(void) {
    Flag_EntryIter.fileBase = Cd_GetFileOrNull(Flag_EntryIter.fileId);
    Flag_EntryIter.cursor = Cd_GetFileEntry(Flag_EntryIter.fileId << 16);
    Flag_EntryIter.entryIndex = 0;
    Flag_NextPassingEntry();
}

FlagBranchEntry *Flag_GetEntry(arg0)
s32 arg0;
{
    FlagBranchEntry *base = (FlagBranchEntry *)Cd_GetFileEntry(Flag_EntryIter.fileId << 16);
    return &base[arg0];
}

extern s32 Flag_TestConds();
extern void Flag_ApplySets();

s32 Flag_SelectBranch(s32 arg0) {
    FlagBranchEntry *base;
    s32 r;
    s32 i;
    r = Cd_GetFileOrNull(Flag_EntryIter.fileId);
    base = Flag_GetEntry(arg0);
    for (i = 0; i < 6; i++) {
        if (Flag_TestConds(Flag_GetBranchCondBlock((FlagEntryIdx *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    Flag_ApplySets(Flag_GetBranchSetBlock((FlagEntryIdx *)base, i));
    return base->branchOffsets[i] + r;
}

s32 Flag_GetTableBase(void) {
    return Cd_GetFileOrNull(Flag_EntryIter.fileId);
}

Blk12 *Flag_GetEntryPosList(s32 index) {
    FlagBranchEntry *e = Flag_GetEntry(index);
    Blk12 *base = (Blk12 *)Cd_GetFileEntry((Flag_EntryIter.fileId << 16) | 1);
    return &base[e->blockIndex];
}

s16 Flag_GetEntryDigiId(s32 index) {
    return Flag_GetEntry(index)->field_0;
}

s16 Flag_GetEntryDir(s32 index) {
    return Flag_GetEntry(index)->field_2;
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

/* Unnamed: DigiData field_1E (MODELDTx), subtracted with +0x280 from fx Y, lineup sort key,
 * battle height bucket; values do not track model size (Monzaemon 857, Biyomon 1280), meaning
 * unproven. */
s16 func_8001E79C(s32 id) {
    return Digi_FindDataById(id)->field_1E;
}

/* Unnamed: DigiData field_20, Y offset for hit-fx slot 1 only; meaning unproven. */
s16 func_8001E7C0(s32 id) {
    return Digi_FindDataById(id)->field_20;
}

void Digi_GetCastFxOffsets(s32 a0, void *a1) {
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

/* Unnamed: DigiData packedId bit 0 (set on e.g. Overlord GAIA, C-Seadramon) picks sound 0x204 vs
 * 0x205 in the hit reaction; what the bit means is unproven. */
s32 func_8001E8D0(s32 id) {
    return Digi_FindDataById(id)->u4.packedId & 1;
}

u16 Digi_GetModelListId(s32 idx) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000) + idx;
    return (p->packedId >> 1) & 0x7FFF;
}

s32 Digi_GetModelListCount(void) {
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

s32 Digi_CalcMaxLevel(s32 x) {
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

/* Unnamed: stores *arg1 into actor work field_0, no callers, no table ref. */
void func_8001EC00(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

/* Unnamed: actor update for model 0x5B following another actor's root bone XZ, no callers, no
 * table ref (dead task body). */
void func_8001EC10(Actor *arg0) {
    s32 state = arg0->stateLevel0;

    switch (state) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, Gfx_ZeroVector, 0);
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

/* Unnamed: draw for the same model-0x5B actor when work field_4 set, no callers, no table ref. */
void func_8001ECE4(Actor *arg0) {
    if (arg0->work->field_4 != 0) {
        Gfx_AttachModel(arg0, 0x5B);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 1);
    }
}

EntED40 *Skill_FindById(s32 id) {
    EntED40 *p = (EntED40 *)Cd_GetFileEntry(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 Skill_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    EntED40 *p = Skill_FindById(arg0);
    if (p != 0) {
        return p->nameOffset + base;
    }
    return 0;
}

s32 Skill_GetDescText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    return Skill_FindById(arg0)->descOffset + base;
}

s32 Skill_GetCastAnim(s32 id) {
    return Skill_FindById(id)->u0.h0.field_2 & 3;
}

s32 Skill_GetType(s32 id) {
    return (Skill_FindById(id)->u0.field_0 >> 18) & 3;
}

s32 Skill_GetPartsEntry(s32 id) {
    return Skill_FindById(id)->partsEntry;
}

u8 Skill_GetMpCost(s32 id) {
    return Skill_FindById(id)->mpCost;
}

void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b) {
    EntED40 *p = Skill_FindById(id);
    s32 i;

    n *= 2;
    for (i = 0; i < 3; i++) {
        a[i] = p->field_2C[n][i];
        b[i] = p->field_2C[n + 1][i];
    }
}


s32 Skill_GetTarget(s32 id) {
    return (Skill_FindById(id)->u0.field_0 >> 20) & 0xF;
}

s16 Skill_GetPower(s32 id) {
    return Skill_FindById(id)->power;
}

u16 Skill_GetSpecialty(s32 id) {
    u16 v = Skill_FindById(id)->u0.b0.field_3 & 0xF;

    if (v == 6) {
        return (u16)Rand_Next() % 5;
    }
    return v;
}

s32 *Skill_GetShotXa(s32 id) {
    EntED40 *e = Skill_FindById(id);
    Skill_ShotXaFile = e->shotXaFile;
    D_8005077C = e->field_5;
    return &Skill_ShotXaFile;
}


/* Unnamed: WAZADATA byte 0x10 bit set (8/0x10/0x20/1/2 tested for different battle effects), no
 * single meaning. */
u8 func_8001F020(s32 id) {
    return Skill_FindById(id)->u10.field_10b;
}

/* Unnamed: WAZADATA field_20 low nibble, bit 8 retargets in battle target selection; other bits
 * unproven. */
s32 func_8001F044(s32 id) {
    return Skill_FindById(id)->field_20 & 0xF;
}

s32 Skill_GetStatusFlags(s32 id) {
    return Skill_FindById(id)->statusFlags & 0x3FFFFFF;
}

s32 Skill_GetCureFlags(s32 id) {
    return Skill_FindById(id)->field_1C & 0x3FFFF;
}

s32 Skill_GetRank(s32 id) {
    return Skill_FindById(id)->u0.field_0 >> 28;
}

/* Unnamed: WAZADATA (field_10>>8)&0x7FFF mixed effect flag set (bits 4, 0x2000 tested), no
 * single meaning. */
s32 func_8001F0E4(s32 id) {
    return (Skill_FindById(id)->u10.field_10 >> 8) & 0x7FFF;
}

/* Unnamed: WAZADATA field_14 &0x3FF effect flags read once in battle damage calc, meaning
 * unproven. */
s32 func_8001F10C(s32 id) {
    return Skill_FindById(id)->field_14 & 0x3FF;
}

s32 Skill_GetBuffFlags(s32 id) {
    return (Skill_FindById(id)->field_14 >> 10) & 0x1FFF;
}

/* Unnamed: WAZADATA (field_1C>>18)&0x1F flags read once in battle damage calc, meaning unproven
 * (issue #4 calls it "prevent", unconfirmed). */
s32 func_8001F158(s32 id) {
    return (Skill_FindById(id)->field_1C >> 18) & 0x1F;
}

/* Unnamed: WAZADATA (field_1C>>23)&0xFF flags read once in battle turn code, meaning unproven. */
s32 func_8001F180(s32 id) {
    return (Skill_FindById(id)->field_1C >> 23) & 0xFF;
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

s32 Anim_HasModelAnim(Actor *a0, s32 n) {
    ActorModel *sub = a0->model;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        id = Anim_GetModelAnimFile(a0->digiId, 0);
        k = 0;
    } else if (n < 20) {
        id = Anim_GetModelAnimFile(a0->digiId, 1);
        k = n - 10;
    } else {
        id = Anim_GetModelAnimFile(a0->digiId, 2);
        k = n - 20;
    }
    p = (s32 *)(Cd_GetFileOrNull(id) + ((sub->boneCount + 1) << 2));
    sub->animTable = p;
    return p[k] != 0;
}

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
    s->animTimer += Sys_State.frameDelta;
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
        p->localMat = Gfx_IdentityMatrix;
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
    g = &Sys_State;
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
        GsSetFlatLight(i, &Gfx_FlatLights[i]);
    }
    GsSetAmbient(0x4CC, 0x4CC, 0x4CC);
    GsSetLightMode(0);
}

s32 Gfx_AnimAllowsBlink(s32 arg0) {
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
        if (Gfx_AnimAllowsBlink(w->animId) != 0) {
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
            if ((w->blinkTimer -= Sys_State.frameDelta) < 0) {
                w->blinkTimer = 0;
            }
        } else {
            k = 4;
            w->blinkTimer = 0;
        }
    }
    w->texAnimTimer += Sys_State.frameDelta;
    while (1) {
        if (w->texAnimTimer < 0x18) break;
        w->texAnimTimer -= 0x18;
    }
    j = (w->texAnimTimer / 8) * 2;
    prim = Sys_State.packet.drMove;
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
        AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
        prim++;
    }
    if (r->dstX == 0xFE) {
        q = (GfxModelTexAnim *)&(r++)->dstY;
        for (c = 0; c < 10; c++, q++) {
            if (q->dstX == 0xFF) break;
            if (Sys_State.frameDelta == 1) {
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
            AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->vramX;
            rc2.y = q->uv[m + 3] + pos->vramY;
            rc2.w = q->w2;
            rc2.h = q->h2;
            SetDrawMove(prim, &rc2, q->dstX2 + pos->vramX, q->dstY2 + pos->vramY);
            AddPrim(Sys_State.otLayers.u[6], (unsigned int *)prim);
            prim++;
        }
    }
    Sys_State.packet.addr = (s32)prim;
}
