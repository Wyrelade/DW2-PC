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
#include "stag3500/fighter.h"
#include "stag3500/roundbanner.h"
#include "stag3500/xaplay.h"
#include "stag3500/hud.h"
#include "stag3500/battlescript.h"

/* Skill pick lists by group: { skill id, weight, target type }, 0-terminated. */
Stg35SkillGroupEntry Stg35_SkillGroup0[] = {
    { 0x7, 35, 1 }, { 0x1F, 35, 0 }, { 0x3B, 35, 0 }, { 0x3F, 35, 0 }, { 0x5A, 35, 0 },
    { 0x64, 35, 0 }, { 0x6A, 35, 0 }, { 0x1, 30, 0 }, { 0x2, 30, 0 }, { 0x4, 30, 0 },
    { 0x5, 30, 0 }, { 0x23, 30, 0 }, { 0x3C, 30, 0 }, { 0x3E, 30, 0 }, { 0x58, 30, 0 },
    { 0x69, 30, 0 }, { 0x8B, 30, 0 }, { 0x21, 25, 1 }, { 0x3, 25, 0 }, { 0x20, 25, 0 },
    { 0x8, 20, 0 }, { 0x22, 20, 0 }, { 0x65, 20, 0 }, { 0 },
};
Stg35SkillGroupEntry Stg35_SkillGroup1[] = {
    { 0x84, 45, 1 }, { 0x25, 45, 0 }, { 0x26, 45, 0 }, { 0x41, 45, 0 }, { 0x60, 45, 0 },
    { 0x6C, 45, 0 }, { 0x6E, 45, 0 }, { 0x82, 45, 0 }, { 0x8A, 45, 0 }, { 0x8C, 45, 0 },
    { 0x6, 40, 0 }, { 0xB, 40, 0 }, { 0xF, 40, 0 }, { 0x11, 40, 0 }, { 0x29, 40, 0 },
    { 0x2F, 40, 0 }, { 0x3D, 40, 0 }, { 0x40, 40, 0 }, { 0x42, 40, 0 }, { 0x43, 40, 0 },
    { 0x45, 40, 0 }, { 0x46, 40, 0 }, { 0x47, 40, 0 }, { 0x59, 40, 0 }, { 0x66, 40, 0 },
    { 0x6B, 40, 0 }, { 0x83, 40, 0 }, { 0xD8, 40, 0 }, { 0 },
};
Stg35SkillGroupEntry Stg35_SkillGroup2[] = {
    { 0xA, 60, 0 }, { 0xD, 60, 0 }, { 0x53, 60, 0 }, { 0x73, 60, 0 }, { 0x85, 60, 0 },
    { 0x87, 60, 0 }, { 0x89, 60, 0 }, { 0xD9, 60, 0 }, { 0x24, 55, 0 }, { 0x28, 55, 0 },
    { 0x2A, 55, 0 }, { 0x49, 55, 0 }, { 0x9, 50, 0 }, { 0xC, 50, 0 }, { 0xE, 50, 0 },
    { 0x10, 50, 0 }, { 0x2C, 50, 0 }, { 0x2E, 50, 0 }, { 0x44, 50, 0 }, { 0x5C, 50, 0 },
    { 0x5D, 50, 0 }, { 0x61, 50, 0 }, { 0x2D, 20, 2 }, { 0 },
};
Stg35SkillGroupEntry Stg35_SkillGroup3[] = {
    { 0x50, 75, 1 }, { 0x19, 75, 0 }, { 0x30, 75, 0 }, { 0x48, 75, 0 }, { 0x4D, 75, 0 },
    { 0x72, 75, 0 }, { 0x3A, 70, 1 }, { 0x12, 70, 0 }, { 0x17, 70, 0 }, { 0x18, 70, 0 },
    { 0x2B, 70, 0 }, { 0x4F, 70, 0 }, { 0x62, 70, 0 }, { 0x70, 70, 0 }, { 0x13, 65, 0 },
    { 0x31, 65, 0 }, { 0x34, 65, 0 }, { 0x4B, 65, 0 }, { 0x67, 65, 0 }, { 0x86, 65, 0 },
    { 0x27, 30, 2 }, { 0x5B, 30, 2 }, { 0x6D, 30, 2 }, { 0x33, 25, 2 }, { 0 },
};
Stg35SkillGroupEntry Stg35_SkillGroup4[] = {
    { 0x38, 120, 0 }, { 0xFC, 120, 0 }, { 0x56, 110, 0 }, { 0x57, 100, 0 }, { 0xE4, 100, 0 },
    { 0x1C, 90, 0 }, { 0x54, 90, 0 }, { 0x4A, 80, 1 }, { 0x88, 80, 0 }, { 0xDA, 80, 0 },
    { 0x15, 60, 2 }, { 0x37, 60, 2 }, { 0x4C, 60, 2 }, { 0x52, 55, 2 }, { 0x16, 50, 2 },
    { 0x68, 50, 1 }, { 0x35, 45, 2 }, { 0x71, 45, 2 }, { 0x32, 40, 2 }, { 0x36, 40, 2 },
    { 0x4E, 40, 2 }, { 0x51, 40, 2 }, { 0x14, 40, 1 }, { 0x6F, 35, 2 }, { 0 },
};
Stg35SkillGroupEntry Stg35_SkillGroup5[] = {
    { 0x5E, 90, 2 }, { 0x63, 90, 2 }, { 0xEB, 90, 2 }, { 0x55, 85, 2 }, { 0xDB, 85, 2 },
    { 0x1D, 80, 2 }, { 0x39, 80, 2 }, { 0x1A, 75, 2 }, { 0x1B, 75, 2 }, { 0x1E, 75, 2 },
    { 0x5F, 70, 2 }, { 0 },
};
Stg35SkillGroupEntry *Stg35_SkillGroups[6] = {
    Stg35_SkillGroup0, Stg35_SkillGroup1, Stg35_SkillGroup2, Stg35_SkillGroup3, Stg35_SkillGroup4, Stg35_SkillGroup5,
};

void Stg35_FindSkillGroup(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    Stg35SkillGroupEntry *p;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        p = Stg35_SkillGroups[i];
        j = 0;
        while (p->skillId != 0) {
            if (p->skillId == arg0) {
                goto found;
            }
            p++;
            j++;
        }
        continue;
    found:
        *arg1 = i;
        *arg2 = j;
        *arg3 = p->targetType;
        *arg4 = p->field_2;
        return;
    }
    *arg1 = -1;
    *arg2 = 100;
}

void Stg35_BuildCommandList(s32 arg0) {
    u8 *ids = Stg35_Battle.rec[arg0].skillIds;
    Stg35Action *b = &Stg35_Battle.actions[arg0];
    s32 best[6];
    s32 grp;
    s32 idx;
    s32 v4;
    s32 v2;
    s32 found;
    s32 i;

    for (i = 0; i < 6; i++) {
        b->skills[i] = 0;
        best[i] = 100;
    }
    found = 0;
    for (i = 0; i < 12; i++) {
        if (ids[i] != 0) {
            Stg35_FindSkillGroup(ids[i], &grp, &idx, &v4, &v2);
            if (grp != -1 && best[grp] > idx) {
                best[grp] = idx;
                found = 1;
                b->skills[grp] = ids[i];
                b->field_1E[grp] = v2;
                b->targetTypes[grp] = v4;
            }
        }
    }
    if (!found) {
        b->skills[0] = Stg35_SkillGroup0[1].skillId;
        b->field_1E[0] = Stg35_SkillGroup0[1].field_2;
        b->targetTypes[0] = Stg35_SkillGroup0[1].targetType;
    }
}
