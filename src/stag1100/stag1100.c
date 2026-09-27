#include "common.h"
#include "stag1100/stag1100.h"

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006358C);

void func_8006374C(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Task_NextState0(arg0);
    }
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006377C);

void func_80063894(Actor *arg0, s16 arg1) {
    Stg11Work63894 *w = (Stg11Work63894 *)arg0->work;
    D_800685C8 = 0;
    w->field_20 = arg1;
    w->field_24 = arg1 == 4;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800638BC);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80063C08);

void func_80063D20(void) {
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80063D28);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064000);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064304);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006448C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800646C0);

void func_800648B4(Actor *arg0, Stg11MenuWork *arg1) {
    Text_CloseArray(arg1->field_10, 9);
    arg1->field_86 = 0;
}

void func_800648E4(Stg11MenuWork *arg0, s32 arg1) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->field_8);
    } else {
        st.pos = D_800681D8;
        st.field_10 = 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->field_8, (TextDesc *)&st);
    }
}

void func_8006495C(Stg11MenuWork *arg0, s32 arg1, s32 arg2) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->field_4);
    } else {
        st.pos = D_800681D4;
        st.field_10 = arg2 - 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->field_4, (TextDesc *)&st);
    }
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800649D4);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800649F8);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064A6C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064B00);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064C64);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064EF0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064FD0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800650A8);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065188);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065318);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800654E4);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065A3C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065BA0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065E64);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066028);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800660F0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006637C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066748);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066860);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066A0C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066B60);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066C04);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066C48);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067124);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800673FC);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800676F4);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006770C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067724);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800677AC);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067818);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067838);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067880);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800678F0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067938);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067B54);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067F64);

void func_80068050(void) {
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80068058);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80068160);

void func_80068180(void) {
}
