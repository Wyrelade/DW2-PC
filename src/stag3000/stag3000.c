#include "common.h"
#include "stag3000/stag3000.h"

void func_80063898(Actor *a0, s32 a1) {
    a0->field_8 = a1;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800638A0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006399C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80063A6C);

void func_80063B28(Actor *a0) {
    Gfx_AttachModel(a0, a0->digiId);
    Actor_UpdateTransform(a0);
    Gfx_CalcModelBoneMatrices(a0);
    Gfx_DrawTexModel(a0, 1);
}

void func_80063B70(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80063B80);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80063C44);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006436C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800643E0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80064480);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800644D4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80064B30);

void func_80064FBC(Actor *a0) {
    Text_CloseArray(((Stg30Work73078 *)a0->work)->text, 4);
    Task_DefaultDestroy(a0);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80064FF4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065100);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800652C8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065354);

s32 func_80065540(s32 c) {
    if (c >= 0xE1) {
        return c + 0x2E;
    }
    if (c >= 0xD9) {
        return c + 0x2E;
    }
    if (c >= 0xB0) {
        return c + 0x68;
    }
    if (c >= 0xA6) {
        return c + 0x7E;
    }
    return c + 0x85;
}

void func_80065584(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065594);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065A98);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066000);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800663F8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066484);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066698);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066AE0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066DB0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800672B0);

void func_80067530(Actor *a0, s32 a1, s32 a2) {
    a0->stateLevel0 = 2;
    a0->stateLevel1 = a1;
    a0->stateLevel2 = 0;
    a0->stateLevel3 = 0;
    a0->stateLevel4 = a2;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006754C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800675CC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067624);

s32 func_8006767C(Stg30IdSet *a0, s16 *a1, u8 id) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (a0->ids[i] == id) {
            return 1;
        }
        if (a1[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 func_800676C4(s32 a0, u8 a1) {
    return a0 >= func_8001F0C0(a1);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800676F4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067DB4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067EC4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80067F2C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80068CE0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80068DA4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80068E34);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800692A4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069594);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800696E8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800699F8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069A44);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069DE8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006A030);

s32 func_8006A118(void) {
    if (D_8005D5A0.field_103D == 0) {
        return 5;
    }
    return D_8005D5A0.field_103D - 2;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006A140);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006A968);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006AA18);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006AAA8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006B950);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006BBD8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006CA3C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006CB28);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006CB8C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006D2EC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006D4D8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006DB90);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E2BC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E31C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E3D0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E47C);

void func_8006E530(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_80073A20[i] = v;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E55C);

void func_8006E5B4(s32 i) {
    for (; i < 11; i++) {
        D_80073A20[i] = D_80073A20[i + 1];
    }
}

s32 func_8006E5F8(s32 v) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (v == D_80073A20[i]) {
            return i;
        }
    }
    return -1;
}

s32 func_8006E634(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_80073A20[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 func_8006E674(s32 i) {
    return D_80073A20[i];
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E690);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E770);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E850);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E888);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006E978);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EB24);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EC5C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EC94);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EF50);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F530);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F554);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F640);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F664);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F674);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F69C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F820);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F8CC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006F8EC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FA28);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FC78);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FFD0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800701FC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800702A8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800702C8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800704FC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070530);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070588);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800706BC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070C68);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070D14);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070D68);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80070D8C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007100C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071044);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007118C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071470);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071488);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071538);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007191C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071BDC);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071C14);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071D70);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071DC4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80071F9C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80072080);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800720E4);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800726E8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800728A0);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800728D8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8007292C);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80072F84);
