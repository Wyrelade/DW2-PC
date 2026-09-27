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

s32 func_800649D4(Stg11MenuWork *arg0) {
    return Text_IsFinished(arg0->field_4);
}

s32 func_800649F8(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r = 0;
    s32 v = func_80067818();

    if (v != -1) {
        if (v == 0) {
            Task_SetState1(arg0, 3);
            r = -1;
        } else {
            func_800677AC(4, arg1->field_84);
        }
    }
    return r;
}

void func_80064A6C(Actor *arg0, Stg11MenuWork *arg1) {
    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) == 0) {
        arg0->stateLevel2 = 1;
        if (D_8005F6F0[arg1->field_7E].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState0(arg0, 2);
        }
    }
}

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

void func_80066C04(Actor *arg0, s16 arg1) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
    w->field_60 = arg1;
    w->field_64 = (arg1 - 1) % 2;
    w->field_68 = w->field_60 >= 3;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066C48);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067124);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800673FC);

u8 *func_800676F4(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->u34.s.field_234;
}

u8 *func_8006770C(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->field_4034;
}

void func_80067724(u8 *arg0) {
    s32 i = 0;
    u8 *d = ((Stg11SaveWork *)D_800685D0->work)->u34.s.field_38;
    u8 c;

    memset(d, i, 0x40);
loop:
    c = *arg0++;
    if (c == 0) {
        return;
    }
    *d++ = c;
    *d++ = *arg0++;
    if (++i < 0x20) {
        goto loop;
    }
}

void func_800677AC(u8 arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    Task_SetState1(D_800685D0, arg0);
    w->field_0 = arg1;
    w->field_24[arg1][0] = -1;
    w->field_4 = -1;
    w->field_22038 = -1;
    w->field_22040 = 0;
}

s32 func_80067818(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->field_4;
}

void func_80067838(u8 *arg0, u8 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    strcpy(w->field_C, arg0);
    w->field_21 = arg1;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067880);

u16 func_800678F0(Stg11SaveWork *arg0) {
    u16 *p = arg0->u34.sum;
    u16 sum = 0;
    s32 n = 0x1FFF;

    while (1) {
        if (--n == -1) {
            break;
        }
        sum ^= *p++;
        if (--n == -1) {
            break;
        }
        sum += *p++;
    }
    return sum;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067938);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067B54);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067F64);

void func_80068050(void) {
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80068058);

void func_80068160(Actor *arg0) {
    Task_DefaultDestroy(arg0);
}

void func_80068180(void) {
}
