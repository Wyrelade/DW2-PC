#include "common.h"
#include "stag4000/stag4000.h"

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063758);

void func_800637E8(void) {
    Stg40Blk5071C *b = D_8005071C;

    b->field_E54 = &b->field_E34;
    b->field_E34.field_0 = 0x40;
    b->field_E54->field_2 = 0x30;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063814);

void func_800639FC(void) {
    func_80070DC0();
    func_8006FED4();
    func_8006FFCC();
    func_800707D0();
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063A34);

void func_80063EF8(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80063F00);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006424C);

void func_80064830(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064838);

void func_80064880(void) {
    s32 i;

    for (i = 0x3F; i >= 0; i--) {
        D_80050948[i] = 0;
    }
    D_8005075C = 0;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800648AC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064930);

void func_80064970(Actor *a0, Stg40InitArg *a1) {
    Stg40InitWork *w = (Stg40InitWork *)a0->work;

    w->field_20 = a1->field_0;
    w->field_24 = a1->field_4;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006498C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064AFC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80064BD8);

void func_80065134(s32 arg0) {
    D_8005071C->field_1064 = arg0;
    Task_SetState1(D_80072B68, 0);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065168);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800651C0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065230);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065278);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065300);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800653EC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065424);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006545C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065890);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065BF8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065C50);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80065F94);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006620C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066318);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800665E0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006667C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066720);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066AD0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066BE4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066D78);

void func_80066DF0(u8 a0, u8 a1, u8 a2) {
    Stg40ObjWork *w = (Stg40ObjWork *)D_80072B70->work;

    w->field_46 = a0;
    w->field_44 = a1;
    w->field_45 = a2;
    w->field_24 = -1;
}

s32 *func_80066E18(void) {
    return &((Stg40ObjWork *)D_80072B70->work)->field_28;
}

void func_80066E30(Actor *a0, s32 *a1) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;

    D_80072B70 = a0;
    w->field_20 = *a1;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80066E48);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067044);

void func_800671E8(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800671F0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067454);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006755C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067610);

void func_800676A4(s32 i) {
    Text_Close(&D_80072B84[i]);
}

s32 func_800676D0(s32 i) {
    s32 *p = &D_80072B84[i];

    return Text_IsFinished(*p);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067704);

s32 func_80067750(s32 i) {
    s32 *p = &D_80072B84[i];

    return func_800136A4(*p);
}

void func_80067784(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006778C);

void func_800677F4(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800677FC);

void func_80067880(Actor *a0, u8 a1) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    w->field_26 = a1;
    w->field_27 = 0;
}

void func_80067894(Actor *a0, u8 on, u8 r, u8 g, u8 b) {
    Stg40ModelView *m = (Stg40ModelView *)a0->model;

    if (on == 0) {
        m->field_34 = 0;
        return;
    }
    m->field_34 = 2;
    m->field_38 = r;
    m->field_39 = g;
    m->field_3A = b;
}

s32 func_800678C4(Actor *a0) {
    return a0->model->animDone < 0;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800678D8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067A80);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067BA8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80067DB4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800680B0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006813C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800681BC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800682DC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068604);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800689E0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068A54);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068B8C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068C60);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068D3C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068DC0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068F20);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068FBC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80068FFC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800690CC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069188);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006932C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006940C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800694D0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069514);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006955C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006965C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069714);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069830);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006997C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069C94);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80069F84);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006A498);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006A614);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006A6EC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006A848);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006A9CC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006AB48);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006AD10);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006AE74);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006AF34);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B20C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B320);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B420);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B698);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B8C8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006B9A8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006BBBC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006BDEC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006BFB0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006C6C4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006C7CC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006C84C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006CAD4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006CD1C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006CF54);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006D0E8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006D418);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006D4E0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006D738);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DA18);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DB68);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DDDC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DEF0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006DFA4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E024);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E200);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E278);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E2B8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E330);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E490);

void func_8006E4DC(a0, a1)
    Actor *a0;
    s16 a1;
{
    ((Stg40ActWork *)a0->work)->field_30 = a1;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E4E8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E520);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E588);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E60C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E6CC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E764);

void func_8006E7F0(s32 i, s32 item, u8 status) {
    GameStateView *g = D_80050720;

    g->slotItems[i] = item;
    g->slotStatus[i] = item ? status : 1;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E820);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E858);

void func_8006E8C4(s32 i, u8 status) {
    GameStateView *g = D_80050720;

    g->slotStatus[i] = g->slotItems[i] ? status : 0;
}

void func_8006E8F4(s32 n) {
    GameStateView *g = D_80050720;

    g->hp = (g->hp - n < 0) ? 0 : g->hp - n;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006E920);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006EA84);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006EB84);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006EBF4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006ECD0);

void func_8006ED5C(void) {
    s32 i;
    u8 *p = D_8005071C->field_E7C;

    i = 0x17F;
    do {
        i--;
        *p++ = 0;
    } while (i >= 0);
    D_80072944 = 0;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006ED88);

void func_8006F06C(void) {
    func_8006ED5C();
    func_8006ED88(1);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F094);

void func_8006F168(Stg40ImgWork *a0) {
    LoadImage(&a0->rect, a0->data);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F18C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F1C8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F290);

void func_8006F38C(Stg40ImgWork *a0) {
    Gfx_ReleaseTexSlot(a0->field_758);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F3B0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F3F4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F62C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F6BC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006F86C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FC54);

void func_8006FDAC(void) {
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FDB4);

void func_8006FE5C(Actor *a0) {
    func_8006F38C((Stg40ImgWork *)a0->work);
    Task_DefaultDestroy(a0);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FE90);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FED4);

void func_8006FF28(void) {
    Mem_Free(D_8005071C->field_E58);
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FF54);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8006FFCC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800703E0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070438);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070490);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800706C8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070754);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800707D0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800708A4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800708FC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070974);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800709DC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070A7C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070AD0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070B2C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070BA4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070C48);

s16 func_80070C94(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    return p->field_0[p->field_1A];
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070CC0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070D74);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070DC0);

void func_80070EC0(u32 *p, u32 n) {
    if (*p < n) {
        *p += n;
    }
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070EE0);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80070FEC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8007107C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071180);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800711C4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071204);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071258);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071294);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071310);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8007142C);

s32 func_800715DC(void) {
    s32 r = func_8006E820();

    if (r > 0) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071608);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800716EC);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071DB4);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071F50);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80071FBC);

void func_800720EC(void) {
    D_80072B60->field_180 = 0;
}

s16 func_800720FC(void) {
    return D_80072B60->field_180;
}

s32 func_80072114(void) {
    return D_80072BC0->field_14;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_8007212C);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800721A8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80072250);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_800722B8);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80072418);

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000", func_80072468);

void func_800725A8(void) {
}
