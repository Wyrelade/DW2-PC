#include "common.h"
#include "main/156C.h"

extern Ent23A78 D_8005F8C8[0x50];
extern Ent54C48 D_80054C48[3];
extern s32 func_80024220(void);
extern void func_80023D68(s32);
extern s32 D_8005F774;
extern u8 D_80048F12;
extern u8 D_8004E6E5;
extern u16 D_8004EAFA;
extern s32 D_800506B8;
extern u32 D_800506E8;
extern s32 D_8004FC00;
extern S5D560 D_8005D560;
extern s32 D_8005F780;
extern State62F80 D_80062F80;
extern u8 D_8005F6A8[];
extern Elm678 D_8005F678[];
extern Elm6F0 D_8005F6F0[];
extern u8 D_800416FC[];
extern Obj48F08 *D_80048F08;
extern void (*D_80048F0C)(void *, ...);
extern u8 D_800102C0;
extern u8 D_80048F20[];
extern u8 D_80048F7C[];
extern Blk50938 D_80050938;
extern s32 D_80043794[];
extern Actor D_8005F770;
extern ActorWork *D_80041670[];
extern Elem20 D_8005CD60[];
extern Obj80041564 D_80041564;
extern u16 D_80041704[];
extern s32 D_80043794[];
extern u16 D_80047100[];
extern s32 *D_80049018;
extern s32 *D_8004901C;
extern s32 *D_80049020;
extern s32 *D_80049024;
extern u16 *D_8004FB88;
extern s32 D_80062FC4;
extern s32 D_8004FE5C;
extern void (*D_8004FBA0[])(void);
extern Stack54CD0 D_80054CD0;
extern List50798 D_80050798;
extern Blk54CF8 D_80054CF8[];
extern Blk54CF8 D_80058D28[];
extern EntE620 D_8005E620;
extern s32 D_80062FD8;
extern void func_8001DC24(s32, s32, ElmE620 *);
extern void func_80022AE4(void);
extern Blk54CF8 *func_8002796C(Blk54CF8 *, s32);
extern void func_8001A68C(s32, s32);
extern s32 func_80027A74(void *);
extern s32 func_80026FC4(void);
extern void func_80026FD4(void);
extern s32 func_8003D9E4(void);
extern void func_80030CC4(s32);
extern s32 func_8001CDA8(void);
extern s32 func_80022E90(s32, s32);
extern void func_80023BB0(void);
extern void func_8001BB88(s32 *);
extern void func_80022D84(ActorWork *);
extern s32 D_8005F79C;
extern Sub3C *func_8001FDBC(Actor *, s32);
extern void func_8001F5E8(Actor *);
extern s32 D_80043704[];
extern void func_80020920(Actor *);
extern void func_800200D0(Actor *);
extern void func_80020510(Actor *, s32);
extern Obj48DB8 D_80048DB8;
extern u8 D_8005FDC8[];
extern s32 func_8002DD64(void *);
extern s32 func_80030914(void *, s32);
extern s32 func_80030534(s32);
extern s32 func_80030690(s32, s32);
extern void *func_80030514(void *);
extern void func_800240E8();
extern void func_8001F320(Actor *);
extern Blk16 D_800416CC[];
extern s32 func_8002B564(s32, Blk16 *);
extern void func_8002BB54(s32, s32, s32);
extern void func_8002BAD4(s32);
extern s32 func_8001E134(void);
extern s32 *func_80011F5C(s32);
extern s32 D_80040FD0[];
extern void func_8001D550(Ent1D550 *, s32, s32);
extern void func_8001D884(s32);
extern void func_8001BC24(void *, Arg1BC24 *);
extern void func_800221C4(s32, s32);
extern void func_8001D5B4(Part28 *, s32, s32, s32);
extern s32 func_8001E984(s32, s32, s32);
extern void func_8002D744(void *, Obj209 *);
extern void func_8002B544(s32);
extern void func_8001F1A8(Actor *, s32);
extern s32 D_8004E6D0;
extern s32 D_8004E6CC;
extern void *D_8004E6C8;
extern s32 func_800294AC();
extern void func_80030D34();
extern Cmd62C18 D_80062C18;
extern void func_80036514(s16);
extern void func_800363A4(s16);
extern Elm354F4 *D_80061C50[];
extern s32 func_80032494(s16, s16);
extern s32 D_80060050;
extern s32 D_8006004C;
extern Flags4FC68 *D_8004FC68;
extern s32 D_8004FC70[];
extern int func_8003F178(int);
extern Vt4FB80 *D_8004FB80;
extern u8 D_8005FDD8[];
extern s32 *D_80049014;
extern s32 D_8004904C;
extern s32 D_80049050;
extern s32 func_80030AB4(s32);
extern s32 D_80061B38;
extern s32 D_80061B3C;
extern void func_8002DE94();
extern s32 D_8004FDB8;
extern s32 D_8004FE44;
extern Stat48E90 *D_80048E90;
extern Obj50768 *D_80050768;
extern s32 func_8002CB30(s32);
extern s32 func_8002FF04();
extern s32 func_8002FDC8();
extern s32 func_80039B54();
extern s32 func_80039A78();
extern s32 func_80039B4C(s32, s32);
extern volatile s32 D_80063080;
extern void func_80027004(s32, s32);
extern void func_80026FF4(s32, u8 *);
extern u8 D_80048E78[];
extern void func_8003A034(void);
extern s32 func_8003C3A4(s32);
extern void func_80032874();
extern Elm624E8 D_800624E8[];
extern s32 D_80049064;
extern u8 D_800618B0[];
extern s32 func_8002A9A4(s32, u8 *, s32);
extern s32 D_8004E6D8;
extern s32 D_8004E6D4;
extern void func_80030258();
extern void func_80030CD4(void);
extern void func_80030D04(s32 arg0, void (*arg1)());
extern s32 D_8004FBD4[];
extern s32 *D_8004FBD0;
extern void func_800315D0();
extern s32 func_80031750();
extern void func_800317FC(s32 *arg0, u32 arg1);
extern u16 *D_8004FE28;
extern s32 D_8004FE50;
extern void func_80023BF4(s32);
extern Hooks4FC50 D_8004FC50;
extern s32 D_80062F94;
extern void func_8003F5A4(s32);
extern s32 (*D_80048E30)();
extern s32 D_80048E98;
extern s32 func_80025760(Ent266D0 *, s32);
extern s16 func_80038BE4(s32, s32, s32, s32);
extern s32 D_80063010[4][4];
extern s32 (*D_80063050[4])(s32 *);
extern char D_80010D44[];
extern void func_8002A014();
extern s32 func_8003B794(s32);
extern s32 func_80030554(s32, u8 *, u8 *);
extern void func_8002DF74(void);
extern void func_8002CE5C(void);
extern void func_8002D684(s32, s32, s32);
extern void func_8002D6A4(s32, s32);
extern s16 D_8006197E;
extern s16 D_8006197C;
extern Blk5071C *D_8005071C;
extern char D_8001031C[];
extern void func_800274E8(char *, Rect2AB54 *);
extern s8 D_80010974[];
extern void func_8002A744(s8);
extern void (*volatile D_8004FE60)(void);
extern s32 func_8003A9F8(s32, u32);
extern Snd62D18 D_80062D18;
extern Rec62D08 *D_80062D08;
extern s32 func_80037C38(s32, s32, s32, s32);
extern s32 D_8004FC5C;
extern Gpu48F10 D_80048F10;
extern char D_80010250[];
extern char D_80010290[];
extern s32 *D_8004FE38;
extern volatile u16 D_8004FE40;
extern s32 func_8003A778(s32, ...);
extern u32 func_8003AB24(s32, u32);
extern Regs48E8C *D_80048E8C;
extern void (*D_80048E40)(void);
extern s32 D_8004FBC0;
extern char D_80010B74[];
extern s32 func_8003E19C(s32 *);
extern void func_8003FA24(s32 (*)(s32 *));
extern void func_8002A014();
extern s16 D_8006198C;
extern void func_8002ACC8(u16, u16, u16, u16, u16);
extern void func_8002BB84(void);
extern void func_8002AE4C();
extern void func_8002B2B4(void);
extern void func_8002B1A4();
extern s32 D_8004FE18;
extern s32 D_8004FDB0;
extern void func_8003A614(void);
extern s32 func_8003A1B4(s32, s32, s32, s32);
extern void func_8003A1C4(s32);
extern char D_80010310[];
extern void func_800274E8(char *, Rect2AB54 *);
extern s32 D_80061B24;
extern s32 D_80061B20;
extern s32 D_80061B1C;
extern s32 D_80061B14;
extern s32 D_80061B04;
extern s16 D_80061AFC;
extern s32 D_80061AF8;
extern void func_8002E1A4(s32, s32);
extern s32 D_8004FE88;
extern s32 D_8004FE8C;
extern Hdr3AD44 *D_8004FE90;
extern s32 func_80023910();
extern St6191C D_8006191C;
extern St6196C D_8006196C;
extern s16 D_8006198E;
extern void func_8002AE4C();
extern s32 func_80010F24(s32);
extern Ent62CFC *D_80062CFC;
extern s32 func_800398D4(s16, s16);
extern s32 D_8004E6E8;
extern u8 *D_8004E600;
extern u8 *D_8004E60C;
extern void func_80030A34(s32);
extern int func_80030A64(int);
extern void func_80030A84(s32);
extern void func_80026588(Actor *arg0);
extern void func_8002659C(Actor *arg0, u8 arg1);
extern void func_800265DC(Actor *arg0, u8 arg1);
extern s32 func_80026630(void);
extern s32 *D_8004FBC4;
extern Pair61900 D_80061900;
extern s32 D_80061990;
extern s32 D_80061994;
extern s32 D_80061998;
extern s32 D_8006199C;
extern s32 D_800619A0;
extern char D_80010624[];
extern void func_8002A014();
extern s16 func_80038BE4(s32, s32, s32, s32);
extern void func_8003A454(u16 *, u32);
extern s32 func_80036164();
extern s32 func_80036594();
extern void func_800391B4(s32);
extern u8 D_80062D38[];
extern u16 D_80062D90;
extern s32 D_80062D98[];
extern void func_8003B374(s32);
extern s32 func_8003C8EC(void);
extern void func_8003C8C4(s32);
extern s32 D_80061B28;
extern s32 D_80061B50;
extern s32 D_80061B00;
extern s32 D_80061B10;
extern s32 D_80061B08;
extern s32 D_80061B54;
extern char D_800102AC[];
extern s16 D_800618F0[];
extern s16 D_800618F4[];
extern DrawEnv D_80061908;
extern Rect2AB54 D_80061980;
extern ObjDesc **D_80040D50[];
extern char D_80010390[];
extern Obj25FBC *(*D_80048E2C)(void);
extern void (*D_80048E1C)(Obj25FBC *);
extern s32 (*D_80048EA0[])(Obj25FBC *);
extern s32 D_80048E5C;
extern void (*D_80048E18)(s32);
extern void func_80026610(s32);
extern s32 func_80025C00(void);
extern char D_80010C98[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern s32 func_8003E6C8(s32 *);
extern char D_80010C98[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern s32 func_8003E930(s32 *);
extern s32 D_8004FE78;
extern u8 D_80010364;
extern u8 D_80010378;
extern Obj4EAF8 D_8004EAF8;
extern s32 *D_8004FB8C;
extern s32 D_80063060;
extern s32 D_80063064;
extern s32 D_80063068;
extern s32 D_8006306C;
extern s32 D_80063070;
extern s32 D_80063074;
extern s32 D_80063078;
extern s32 D_8006307C;
extern s32 D_80062D50[];
extern s32 *D_80049034;
extern volatile s32 D_80049038;
extern volatile s32 D_8004903C;
extern s32 D_80049048;
extern Que291FC D_800600B0[];
extern s32 *D_8004E994;
extern volatile Cd4E9A4 D_8004E9A4;
extern s32 D_80048E50;
extern Reg48DF0 *D_80048DF0;
extern State60058 D_80060058;
extern void func_80026FE4(s32, u8 *);
extern Obj25FBC *D_80048E4C;
extern s32 func_8003DE18(s32 *);
extern s32 D_8005F704;
extern char D_800102F8[];
extern s32 D_80048E64;
extern s32 D_80048E9C;
extern s32 (*D_80048E20)(Ent266D0 *, s32);
extern void (*D_80048E24)(Ent266D0 *);
extern s32 func_80039334(s16, s16, s16, u16, u16);
extern s8 D_80010984[];
extern s32 D_8004FDBC;
extern s32 D_8004FDC0;
extern s32 D_8004FDC4;
extern Blk4FDCC D_8004FDCC;
extern s8 D_80062D0C;
extern s32 D_8004FC18;
extern Rec624F8 D_800624F8[];
extern s16 D_80062D30;
extern void func_8003FA14(void);
extern void func_8003FBF4(void);
extern void func_8003F46C();
extern char D_800103C4[];
extern u8 *func_8001E758(s32);
extern char D_80010304[];
extern char D_80010328[];
extern void func_80029FB4(void);
extern Pkt48F9C D_80048F9C;
extern s32 func_80039334(s16, s16, s16, u16, u16);
extern Reg506BC *D_800506BC;
extern s32 D_8004FDB4;
extern s32 D_8004FDDC;
extern s32 D_8004FDE0;
extern u16 D_8004FDE4[24];
extern s32 D_8004FE14;
extern s32 D_800503B8[];
extern u16 *D_8004E9A0;
extern char D_80010328[];
extern s32 func_80022038();
extern volatile u8 *D_8004EA60;
extern volatile u8 *D_8004EA64;
extern volatile s32 *D_8004EA68;
extern volatile s32 *D_8004EA6C;
extern volatile s32 *D_8004EA70;
extern volatile s32 *D_8004EA74;
extern volatile s32 *D_8004EA78;
extern volatile s32 *D_8004EA7C;
extern s32 func_80027104(s32);
extern DispEnv *func_80027CB0(DispEnv *);
extern DispEnv D_80061968;
extern s32 D_80049060;
extern s8 D_80049071[];
extern BlkFill618D0 D_800618D0[];
extern void func_80024260(s32, s32);
extern void func_8003569C(s16, s16);
extern void func_80032844(s16);
extern void func_80039994(s16);
extern char D_800103F8[];
extern void func_80029FB4(void);
extern void func_80029FB4(void);
extern s32 D_80062F70;
extern s32 D_80062F74;
extern void func_80029984(void);
extern s32 D_80041570[][8];
extern s32 D_800415F0[][8];
extern Mode5CCF8 D_8005CCF8;
extern s32 *D_80049028;
extern s32 *D_8004902C;
extern s32 *D_80049030;
extern s32 *D_80049034;
extern Prm1C D_80040F64;
extern s32 func_8001E704(s32 id);
extern s32 func_8001E728(s32 arg0, s32 arg1);
extern void func_80020C40(ContC40 *a0, s32 *a1, u16 a2);
extern void func_8002B424(Coord1F668 *, Coord1F668 *);
extern s16 D_8005E6E4;
extern void func_800226AC(void);
extern void func_80066F34(s32, s32);
extern s32 D_80048E88;
extern s32 D_80048E68;
extern s32 D_80048E6C;
extern s32 D_80048E58;
extern s32 D_80048E60;
extern s32 func_8002533C(Obj25FBC *);
extern char D_800102D4[];
extern char D_800102E0[];
extern char D_800102F4[];
extern s8 D_80010944[];
extern char D_80010950[];
extern u8 D_8004E9A8[];
extern u8 D_8004E6E4;
extern u8 *D_8004E98C;
extern u8 *D_8004E99C;
extern u8 *D_8004E990;
extern Hook33424 D_80061CD0[][16];
extern int func_8003FB24(void);
extern int func_8003FB38(void);
extern int func_8003FB4C(void);
extern int func_8003FB60(void);
extern int func_8003FB74(void);
extern int func_8003FB88(void);
extern int func_8003FB9C(void);
extern int func_8003FBB0(void);
extern void func_8003FEA4(void);
extern char D_80010C70[];
extern void func_8003F518(s32, u8 *);
extern s8 *func_8003F874(s8 *, s8 *);
extern s32 func_8003F574(u8 *, s32);
extern s32 func_8003F18C(s32 wait, s32 *a1, s32 *a2);
extern void func_8003FEA4(void);
extern s32 D_80062F90;
extern void func_80025CC8(Obj25FBC *a0);
extern void func_80026568(Actor *arg0, u8 arg1);
extern void (*D_80048E1C)(Obj25FBC *);
extern Flags506C0 *D_800506C0;
extern s32 D_800506DC;
extern Obj50720 *D_80050720;
extern char D_8001021C[];
extern char D_8001023C[];
extern char D_80048EC8[];
extern u16 D_80048F90[][2];
extern void func_8002A004(s32);
extern s16 D_800624D0;
extern s16 D_800624D2;
extern s32 D_80061C48;
extern s32 D_80060054;
extern s32 func_80013854(Part28 *, s32, s32);
extern u16 D_80040F98[];
extern void (*D_80061BC8)(s16, s16, s32);
extern void (*D_80061BCC)(s16, s16, s32);
extern void (*D_80061BD0)(s16, s16, s32);
extern void (*D_80061BD4)(s16, s16, s32);
extern void (*D_80061BD8)(s16, s16, s32);
extern void (*D_80061BDC)(s16, s16, s32);
extern void (*D_80061BE0)(s16, s16, s32);
extern void (*D_80061BE4)(s16, s16, s32);
extern void (*D_80061BE8)(s16, s16, s32);
extern void (*D_80061BEC)(s16, s16, s32);
extern void (*D_80061BF0)(s16, s16);
extern void func_8001CAC4(Elem20 *);
extern s32 func_80025D4C(Obj25FBC *);
extern s32 D_80061C44;
extern void func_80036784(void);
extern void func_80031AC4(s16, s16);
extern void func_80035CE4(s16, s16);
extern void func_80031CD4(s32 a0, s16 a1);
extern void func_80032644(s16 a0, s16 a1);
extern void func_800354F4(s32 arg0, s32 arg1);
extern void func_80031D74(s16, s16);
extern s32 func_800223EC(s32, s32, s32, s32);
extern s32 D_80050790;
extern s32 D_80050718;
extern s32 D_80050774;
extern Obj50720 *D_80050720;
extern s32 D_800506FC;
extern s32 D_80050778;
extern s32 D_8005077C;
extern s32 D_80050784;
extern Blk22E60 *D_80050788;
extern s32 D_80050948[];
extern s32 D_8005075C;
extern s32 D_80040E68[];
extern u8 *D_80010000[];
extern void func_8001A410(s32);
extern void func_8001A410(s32);
extern void func_80035C4C(s16 a0, s16 a1, s16 a2, s16 a3);
extern void func_80034E04(s16, s16, s8, s16);
extern void func_80035F04(s32);
extern Halves D_80050704;
extern Halves D_80050708;
extern s32 D_80050750;
extern s32 func_80023F90(s32 arg0);
extern Tbl50724 D_80050724[];
extern s32 D_8005078C;
extern s32 D_8005072C;
extern Halves D_80050700;
extern s32 func_80012778(s32, s32, s32, s32);
extern u8 *D_8005076C;
extern u8 *D_80050770;
extern u8 *D_8005076C;
extern void func_80015298(Actor *, s32);
extern u8 *D_8005076C;
extern char D_80010334[];
extern s32 D_80048FBC;
extern u32 D_80048FD0;
extern Halves D_8005070C;
extern void func_80014F78(Actor *);
extern void func_800153F4(Actor *, s32);
extern s32 D_80050764;
extern s32 D_8005F788[];
extern s32 func_8002284C(s32 mode);
extern void func_8001C4C8(s32 arg0);
extern void func_8001BE74(s32 a0, s32 a1);
extern Halves D_80050714;
extern void func_80019614(Actor194C8 *, s32);
extern s32 func_8001204C(s32, s32, s32, s32);
extern s32 func_8001236C(s32, s32, s32, s32);
extern s32 func_80012490(s32, s32, s32, s32);
extern s32 func_80012640(s32, s32);
extern Cd4FC48 D_8004FC48;
extern s32 D_80061C4C;
extern s16 D_80040DAC[];
extern Obj50720 *D_80050720;
extern Rec41194 *D_80041194[];
extern s32 D_800411FC[3];
extern s32 func_80023B70(s32 arg0);
extern s32 func_80023DB0(s32 arg0);
extern void func_80023E78(s32 a0);
extern void func_80023EB8(s32 a0);
extern s32 func_800239E4(s32 arg0, s32 *arg1);
extern s16 func_80039A44(s32 arg0, s16 arg1);
extern s16 func_80039F44(s32 a0, s16 id);
extern s16 func_8003A004(s16 a0);
extern s16 func_80032954(s32, s16, s32);
extern s16 D_80062D2C[];
extern u16 D_8004FC24[];
extern void func_80036C54(s32);
extern s16 D_80062CFA;
extern Rec62D08 *D_80062CB8[];
extern s32 D_80062C70[];
extern Ent62CFC *D_80062C30[];
extern s32 D_80062D04;
extern void func_80022F8C(void *a0, s32 a1);
extern s32 func_800299B8(void);
extern void func_8002D444(void *, SVec1D104 *, DVec1D104 *);
extern s32 D_80062F58;
extern s32 D_80062F5C;
extern s32 D_80062F60;
extern s32 D_80062F64;
extern s32 D_80062F68;
extern s32 func_80040198(void);
extern s32 func_80040084(void);
extern void func_8003F9A4(s32);
extern void func_8003F994(s32);
extern s32 func_8004015C(void);
extern s32 func_8003FFAC(void);
extern s32 func_8003F418(s32);
extern s32 func_8003F9B4(s32 a0);
extern void func_8001C088(s32 *arg0, s32 arg1);
extern void func_8001C0B0(s32 *arg0, s32 arg1);
extern void func_8001C088(s32 *arg0, s32 arg1);
extern void func_8001C0B0(s32 *arg0, s32 arg1);
extern void func_8002B334(s32, s32);
extern u8 func_8001D934(void);
extern s32 func_8001D958(void);
extern s32 func_8001D980(void);
extern s32 D_8004E88C[];
extern s32 D_8004E78C[];
extern s8 *D_8004E6EC[];
extern s32 D_8004E6DC;
extern u8 D_80061B68[];
extern u8 D_80061B70[];
extern u8 D_80061B78[];
extern s8 D_8001087C[];
extern s8 D_80010888[];
extern s8 D_800108A4[];
extern s8 D_800108B8[];
extern s16 D_80062CF8;
extern u16 D_80062A48[];
extern u8 D_80062A28[];
extern u16 D_80062C10;
extern u16 D_80062C12;
extern u16 D_800624D8;
extern u16 D_800624DA;
extern u16 D_800624DC;
extern u16 D_800624DE;
extern u16 D_800624E0;
extern u16 D_800624E2;
extern u16 D_80062A4A[];
extern u16 D_80062A4C[];
extern u16 D_80040F40[];
extern Hdr3AD44 D_80062DE0;
extern u16 D_80062A48[];
extern u8 D_80062A28[];
extern u8 D_80062D48;
extern s32 D_80062D10;
extern void func_8003C904(VAttr36C54 *);
extern void func_80038314(s32);
extern s32 D_800506D0;
extern s32 D_8004E9E0[];
extern Dma4FBF4 *D_8004FBF4;
extern char D_80010A04[];
extern char D_80010A20[];
extern s32 func_80036FA4(s16, s16, s16, u16, u16, u16);
extern s32 func_800374C0(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 func_80037744(s32);
extern void func_800379B4(void);
extern u16 func_80037B84(void);
extern void func_80037D64(u8);
extern u8 func_80039264(u8 *idx, u8 *val);
extern char D_800103AC[];
extern u8 D_8004900C[];
extern Rng48FE4 D_80048FE4[][5];
extern s32 func_80031838(void);
extern s32 func_8003B744(s32);
extern s32 D_80040E38[];
extern s32 D_80040E44[];
extern s32 D_80062F00;
extern s32 (*D_80062F04[2])(void);
extern s32 D_80062F0C;
extern s32 func_8003D7E8(void);
extern s32 func_8003D850(void);
extern void *D_8004E5E0;
extern s32 D_8004E5E4;
extern char D_800106D4[];
extern s32 func_8002DC94(void);
extern void func_8002DCD0(void);
extern void func_8002DCF8(void);
extern void func_8002DD20(void);
extern void (*D_80062FE0)(s32 *, s32, s32);
extern s8 D_80062FE8[];
extern s32 func_8002A9B4(s8 *);
extern s32 func_80036FA4(s16 a0, s16 a1, s16 a2, u16 a3, u16 arg4, u16 arg5);
extern s8 D_80062D1F;
extern u16 D_80062EE8[];
extern u16 D_80050298[];
extern u16 D_800502B0[];
extern void func_8003F760(s32 *a0, s32 a1, s32 a2);
s32 func_8003F864();
extern s32 func_8003F924(s8 *a, s8 *b);
extern Stat48E90 *D_80048E00;
extern s32 D_80048E70[];
extern s32 func_8002A054(s32, char *, char *);
extern s32 D_80048E94;
extern s32 func_80025984(Ent266D0 *, s32);
extern s32 *D_8004FE2C;
extern s32 *D_8004FE30;
extern s32 *D_8004FE34;
extern s32 D_800506D8;
extern Mat1F668 D_80061A28;
extern s32 func_8002281C(void);
extern s32 func_8001E22C(s32 a0);
extern s32 func_8001E0C0(s32 id);
extern char D_80010A34[];
extern TextOp D_80061BB0[37];
extern s32 func_80034A24(s16, s16, s16, s32);
extern s32 D_8004FE4C;
extern u32 D_8004FE54;
extern u32 D_8004FE58;
extern Str3F518 D_80010D38;
extern u32 D_80060060[];
extern u32 D_80060088[];
extern void func_80029160(s32 arg0);
extern s32 func_800291A8(s32 arg0);
extern s32 D_80048E54;
extern void (*D_80048E48)(void);
extern void (*D_80048E44)(void);
extern s32 func_80025984();
extern Obj25FBC *D_80048E4C;
extern s32 (*D_80048E34)(void);
extern void func_800260C8(Actor *a);
extern s32 func_80026170();
extern void func_8003B074();
extern u16 D_8004FC88[12];
extern u16 D_8004FCA0[128];
extern s16 func_80039150(s32 a0, u16 *a1, u16 *a2);
extern char D_80010D18[];
extern char D_80010C70[];
extern s32 func_8003EBF4(s32 *a0);
extern char D_80010C70[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern char D_80010D18[];
extern s32 func_8003EE14(s32 *st);
extern u16 D_80050298[];
extern u16 D_800502B0[];
extern volatile s32 D_8004FE7C;
extern s32 D_8004FE80;
extern void func_8003AC84(void);
extern void func_8003AC5C(void);
extern char D_80010AA4[];
extern char D_80010AC4[];
extern char D_80010AD8[];
extern char D_80010D18[];
extern s32 func_800401E4();
extern s32 func_8003F418(s32 a0);
extern u8 *func_80027014(u8 *s, s32 n);
extern char D_80010D18[];
extern s32 D_8004E9E0[];
extern s32 func_8002F860();
extern s32 func_8002F318();
extern s32 D_80062F54;
extern s32 D_80062F50;
extern u32 D_800506C8;
extern s32 D_800506CC;
extern char D_80010B9C[];
extern volatile s32 *D_8004EA88;
extern volatile s32 *D_8004EA8C;
extern volatile s32 D_8004EA90;
extern s32 D_8004EA94;
extern s32 D_8004FE48;
extern volatile s32 D_8004FE64;
extern s32 D_8004FE68[];
extern u16 D_80062EE8[];
extern char D_80010AA4[];
extern char D_80010AB4[];
extern void func_8003ACAC(void);
extern s32 func_80025FF4(Obj25FBC *a0, s32 a1);
extern s16 D_8004DDC0[];
extern s32 D_80061B80;
extern s32 D_80061B84;
extern char *D_80061B88;
extern char D_8001095C[];
extern char D_80010850[];
extern char D_80010860[];
extern char *D_8004E76C[];
extern s32 *D_8004E9C0;
extern u8 D_8004FE98[];
extern void func_8003C544(s32);
extern char D_8001034C[];
extern s32 D_800506D4;
extern s32 func_8003F584(s32, s32, s32);
extern void func_8003FEA4(void);
extern s32 func_8004015C(void);
extern s32 func_8003FFAC(void);
extern s32 func_8003F9B4(s32 a0);
extern s32 func_80040198(void);
extern s32 func_80040084(void);
extern s32 func_80024960(Ent266D0 *, s32);
extern s32 (*D_80048E3C)(Actor *);
extern void (*D_80048E38)(Obj25FBC *);
extern u8 D_8005FFB8[];
extern u8 D_80060000[];
extern void func_8002485C(s32 code);
extern void func_800247F4(Obj25FBC *a0);
extern s32 func_80024950(Actor *arg0);
extern void func_80024A1C(Obj25FBC *a0);
extern u8 *func_80024C98(s32 arg0);
extern s32 func_80024CB8(Obj25FBC *a0);
extern void func_80024DC8(Obj25FBC *a0);
extern s32 func_80025114(Obj25FBC *p);
extern volatile s8 D_80062D27;
extern u8 D_80050760;
extern s32 D_80049040;
extern s32 func_800354BC(s32 arg0);
extern s32 func_80035384(s32 arg0, s32 arg1, s32 arg2);
extern void func_800352E4(void);
extern void func_80035330(void);
extern char D_800106F4[];
extern volatile Reg2EC0C *D_8004E68C;
extern volatile u32 *D_8004E688;
extern volatile u8 *D_8004E670;
extern u16 func_8003CF04(s32 cenHigh, s32 cenLow, s32 noteHigh, s32 noteLow);
extern u16 *D_8004FB84;
extern s32 D_8004FB90;
extern char D_800109C8[];
extern char D_800109E4[];
extern void func_800313B4(void);
extern char D_800108D8[];
extern u8 *D_80060048;
extern s32 func_8003F5B4(Ent3EF1C *);
extern char D_800108EC[];
extern char D_800108F4[];
extern char D_80010904[];
extern u8 D_8004E6E0[];
extern CdTbl4E80C D_8004E80C;
extern Mat1F668 D_800619A8;
extern s32 func_8002CEE4(s32);
extern void func_8003B074(void);
extern s8 D_80010A64[];
extern char *D_80061B88;
extern char D_800108E0[];
extern char D_80010850[];
extern char D_80010860[];
extern u8 D_80061B78[];
extern u8 D_80061B70[];
extern u8 D_80061B68[];
extern s32 func_8002EDB4(void);
extern void func_80030334(s8 *s);
extern s32 setjmp(s32 *env);
extern void func_800313D4(s32 *env);
extern void func_8003139C(void);
extern s32 D_80062BD0[];
extern u16 D_80062A4E[];
extern u16 D_80062A50[];
extern s32 D_80062BCC;
extern s32 D_80062BD0[];
extern void (*D_80062BC8)(s32);
extern void (*D_80062A40)(s32);
extern void func_8003C554(s32 on_off, u32 voice_bit);
extern void func_8003D104(s32 a0, u16 *a1);
extern void func_8003B3F4(s32, s32);
extern void func_8003C344(s32, s32);
extern void func_8003B6E4(void);
extern void func_8003C374(void);
extern u16 D_80062A4E[];
extern u16 D_80062A50[];
extern u16 D_80062A52[];
extern Blk22E60 *D_800506F8[];
extern s32 D_80050730;
extern s32 D_80050738;
extern void func_80023484(void);
extern void func_8003D4A4(void);
extern Pair61900 D_80040EFC[];
extern ObjC0E4 D_80061A08;
extern ObjC0E4 D_80061A48;
extern ObjC0E4 D_800619E8;
extern void func_8002C834(s32 *, Mat1F668 *);
extern Halves D_8005074C;
extern Pair54 D_80040D70[][3];
extern u8 D_800632E0[0x80];
extern McDir401E4 D_800630A0[15];
extern s32 D_80063280[20];
extern Rev3B994 D_800503E8[];
extern void func_8002EBE0(s32 *dst, s32 *src, u32 count);
extern void func_8002EC0C(s32 ch, u32 madr, s32 hi, s32 lo, u32 chcr, u8 mode);
extern char D_80010404[];
extern char D_80010418[];
extern char D_80010420[];
extern Pair61900 D_800618F8;
extern Pair61900 D_800618FC;
extern s32 D_80061988;
extern Rec624F8 D_800624F0[];
extern Rec624F8 D_800624FA[];
extern Rec624F8 D_800624FC[];
extern Rec624F8 D_800624FE[];
extern Rec624F8 D_80062500[];
extern s8 D_800632D0[16];
extern char D_80010D64[];
extern s32 func_80040CE4(s32, s32, u8 *);
extern void func_80017214(Actor *);
extern s32 D_80049044;
extern u16 D_80062D60[];
s16 func_800388A4(s16, s16, s16, s16, u16);
void func_80021DC8(void);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80010D6C);

void func_80010D74(void) {
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80010D7C);

void func_80010E38(Obj10E38 *a0) {
    s32 n = a0->field_30;
    s32 *arr = a0->field_34;
    s32 i;

    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[i] = func_80010F24(arr[i]);
        }
    }
}

s32 func_80010EA4(void *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_80010F24(arg0);
}

void func_80010ED4(s32 *arg0) {
    if (*arg0 != 0) {
        func_800115C0(*arg0, 3);
        do {
            *arg0 = func_80010EA4(*arg0);
        } while (*arg0 != 0);
        *arg0 = 0;
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80010F24);

void func_8001107C(u32 id, s32 *slot, s32 arg) {
    ObjDesc *d;
    Buf111D4 *o;

    if (*slot != 0) {
        func_80010ED4(slot);
    }
    d = D_80040D50[id >> 8][id & 0xFF];
    o = func_800113B8(d->field_10, d->field_14);
    o->field_0 = id;
    o->field_24 = 0;
    if (arg != 0 && d->init != 0) {
        d->init(o, arg);
    }
    *slot = (s32)o;
}

void func_80011140(void) {
    func_80011544();
}

void func_80011160(void) {
}

void func_80011168(void) {
}

void func_80011170(Actor *arg0) {
    func_8001125C();
}

void func_80011190(void) {
    s16 i;
    for (i = 0; i < 100; i++) {
        D_80050798.entries[i] = 0;
    }
    D_80050798.count = 0;
}

Buf111D4 *func_800111D4(void) {
    Buf111D4 *s0 = (Buf111D4 *)func_80022F3C(0x40, 2);
    s32 i;
    func_80022F8C(s0, 0x40);
    for (i = 0; i < 0x64; i++) {
        if (D_80050798.entries[i] == 0) {
            D_80050798.entries[i] = (s32)s0;
            break;
        }
    }
    if (D_80050798.count < i + 1) {
        D_80050798.count = i + 1;
    }
    return s0;
}

void func_8001125C(arg0)
Act125C *arg0;
{
    Obj125C *sub;
    s32 i;
    s32 *p;
    s32 j;

    if (arg0->field_30 != 0) {
        s32 *fp = arg0->field_34;
        i = 0;
        if (arg0->field_30 > 0) {
            p = fp;
            do {
                func_80010ED4(p);
                p++;
            } while (++i < arg0->field_30);
            fp = arg0->field_34;
        }
        func_80022D84((ActorWork *)fp);
    }

    if (arg0->field_2C != 0) {
        func_80022D84(arg0->field_2C);
    }
    if (arg0->field_38 != 0) {
        func_80022D84(arg0->field_38);
    }

    sub = arg0->field_3C;
    if (sub != 0) {
        if (sub->field_6C != 0) {
            func_80022D84(sub->field_6C);
        }
        if (sub->field_70 != 0) {
            func_80022D84(sub->field_70);
        }
        i = sub->field_74 != 0;
        if (i) {
            func_80022D84(sub->field_74);
        }
        if (sub->field_78 != 0) {
            func_80022D84(sub->field_78);
        }
        func_80022D84((ActorWork *)arg0->field_3C);
    }

    for (j = 0; j < 100; j++) {
        if (D_80050798.entries[j] == (s32)arg0) {
            D_80050798.entries[j] = 0;
            break;
        }
    }

    func_80022D84((ActorWork *)arg0);
}

Buf111D4 *func_800113B8(s32 a0, s32 a1) {
    Buf111D4 *s0 = func_800111D4();
    if (a0 != 0) {
        s32 x = func_80022F3C(a0, 2);
        s0->field_2C = x;
        func_80022F8C((void *)x, a0);
    }
    if (a1 != 0) {
        s32 y = func_80022F3C(a1, 2);
        s0->field_34 = y;
        func_80022F8C((void *)y, a1);
        s0->field_30 = a1 >> 2;
    }
    return s0;
}

Ent11440 *func_80011440(void) {
    s32 i;
    Ent11440 *e;

    i = D_80050938.field_C;
    while (i < D_80050798.count) {
        e = (Ent11440 *)D_80050798.entries[i];
        if (e != 0
            && (D_80050938.field_0 == -1 || e->field_0 == D_80050938.field_0)
            && (D_80050938.field_4 == -1 || e->field_4 == D_80050938.field_4)
            && (D_80050938.field_8 == -1 || e->field_8 == D_80050938.field_8)) {
            D_80050938.field_C = i + 1;
            return (Ent11440 *)D_80050798.entries[i];
        }
        i++;
    }
    return 0;
}

extern Ent11440 *func_80011440(void);

Ent11440 *func_80011510(s32 arg0, s32 arg1, s32 arg2) {
    D_80050938.field_0 = arg0;
    D_80050938.field_4 = arg1;
    D_80050938.field_8 = arg2;
    D_80050938.field_C = 0;
    return func_80011440();
}

void func_80011544(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14 = 0;
    arg0->field_10++;
}

void func_80011564(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14++;
}

void func_80011580(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18++;
}

void func_80011598(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C++;
}

void func_800115AC(Actor *arg0) {
    arg0->field_20++;
}

void func_800115C0(Actor *arg0, u32 arg1) {
    arg0->field_10 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14 = 0;
}

void func_800115DC(Actor *arg0, u32 arg1) {
    arg0->field_14 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
}

void func_800115F4(Actor *arg0, u32 arg1, u32 arg2) {
    arg0->field_10 = arg1 & 0xFF;
    arg0->field_14 = arg2 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
}

void func_80011614(Actor *arg0, u32 arg1) {
    arg0->field_18 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
}

void func_80011628(Actor *arg0, u32 arg1) {
    arg0->field_1C = arg1 & 0xFF;
    arg0->field_20 = 0;
}

void func_80011638(Actor *arg0, u32 arg1) {
    arg0->field_20 = arg1 & 0xFF;
}

void func_80011644(void) {
    s32 *p;
    s32 i;

    p = D_80050948;
    func_80023BF4(0x19A);
    for (i = 0; i < D_8005075C; i++) {
        func_80023BF4(*p);
        p++;
    }
}


void func_800116A8(void) {
}

void func_800116B0(Actor *arg0, s32 *arg1) {
    ActorWork *w = arg0->work;
    w->field_0 = arg1[0];
    w->field_4 = arg1[1];
}

void func_800116CC(Actor *a0) {
    Wk116CC *w = (Wk116CC *)a0->work;
    s32 v;

    switch (a0->field_10) {
    case 0:
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
            break;
        case 1:
            return;
        }
        if (w->field_10 == 0) {
            switch (w->field_8) {
            case 0:
                v = 0xE;
                goto set;
            case 1:
                v = 0xD;
                goto set;
            case 2:
                v = 0xB;
            set:
                w->field_C = v;
                w->field_14 = 0;
                w->field_10 = 0;
                break;
            default:
                w->field_C = 7;
                w->field_10 = 2;
                w->field_14 = w->field_8 - 3;
                break;
            }
            w->field_8++;
            if (w->field_8 == 0x12) {
                w->field_8 = 0xF;
            }
        } else {
            w->field_10--;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 1:
            w->field_C = 0xD;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 2:
            w->field_C = 0xE;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 0:
        default:
            w->field_C = 0xB;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 3:
            func_800115C0(a0, 3);
            break;
        }
        break;
    }
}

void func_80011854(Actor *a0) {
    ActorWork *w = a0->work;
    Part11854 *e;
    Part11854 *q;
    Pt11BEC pos;
    Pt11BEC clut;
    Tex11BEC tex;
    s32 s;
    s32 i;
    s32 j;
    u8 u;
    u8 v;
    Actor *g;
    Ft4_11854 *p;

    e = (Part11854 *)func_800239A0(0x3120002);
    for (q = e; q->field_0 != 0; q++) {
        if (q->field_1C & w->field_C) {
            q->field_F = 0;
        } else {
            q->field_F = 1;
            q->field_C = w->field_14;
            if (w->field_4 != 0) {
                q->field_10 = -0x1000;
                q->field_E = 0;
            } else {
                q->field_10 = 0x1000;
                q->field_E = 1;
            }
        }
    }
    func_8001D884((s32)e);
    func_80011BEC(w->field_0, &tex, &pos, &clut);
    s = 1;
    if (w->field_4 != 0) {
        s = -1;
    }
    g = &D_8005F770;
    p = (Ft4_11854 *)g->work;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            p->c.rgb = D_8005074C;
            p->tag.len = 9;
            p->c.b.code = 0x2C;
            p->x0 = D_80040D70[j][i].field_0 * s;
            p->x1 = D_80040D70[j][i + 1].field_0 * s;
            p->x2 = D_80040D70[j + 1][i].field_0 * s;
            p->x3 = D_80040D70[j + 1][i + 1].field_0 * s;
            p->y0 = D_80040D70[j][i].field_2;
            p->y1 = D_80040D70[j][i + 1].field_2;
            p->y2 = D_80040D70[j + 1][i].field_2;
            p->y3 = D_80040D70[j + 1][i + 1].field_2;
            u = pos.x + (tex.field_C + i * 20);
            p->u0 = p->u2 = u;
            p->u1 = p->u3 = u + 20;
            v = pos.y + j * 20;
            p->v0 = p->v1 = v;
            p->v2 = p->v3 = v + 20;
            p->tpage = tex.field_10;
            p->clut = ((tex.field_1C + clut.y) << 6) | (((tex.field_18 + clut.x) >> 4) & 0x3F);
            p->tag.addr = ((PTag11854 *)g->field_138[0])->addr;
            ((PTag11854 *)g->field_138[0])->addr = (u32)p;
            p++;
        }
    }
    D_8005F79C = (s32)p;
}

void func_80011B58(Actor *arg0, s32 arg1) {
    arg0->work->field_0 = arg1;
}

void func_80011B64(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->field_10 == 0) {
        w->field_0 = func_8001CDA8();
        func_80011544(arg0);
    }
}

void func_80011BB0(Actor *arg0) {
    func_8001CE80(arg0->work->field_0);
    func_80011170(arg0);
}

void func_80011BEC(s32 id, Tex11BEC *out, Pt11BEC *pos, Pt11BEC *clut) {
    Tbl11BEC *t;
    s32 i;
    s32 k;
    s32 *p;
    Rect2AB54 r;
    Rect2AB54 r2;

    t = (Tbl11BEC *)func_80011510(10, -1, -1)->field_2C;
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == id) {
            goto found;
        }
    }
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == 0) {
            goto load;
        }
    }
    {
        s32 m = 0;
        s32 bi = 0;
        for (i = 0; i < 18; i++) {
            if (m < t->slot[i].t) {
                m = t->slot[i].t;
                bi = i;
            }
        }
        i = bi;
    }
load:
    for (k = 0; D_80040DAC[k] != -1; k++) {
        if (D_80040DAC[k] == id) {
            break;
        }
    }
    p = (s32 *)func_800239A0(k + 0x3250000);
    p++;
    if (*p++ & 8) {
        r.x = t->field_0->field_18 + i / 16 * 16;
        r.y = t->field_0->field_1C + 0xF0;
        r.y += i % 16;
        r.w = 16;
        r.h = 1;
        func_8002772C(&r, ((TimBlk11BEC *)p)->data);
    }
    p = (s32 *)((u8 *)p + *p);
    r2.x = t->field_0->field_18 + i % 3 * 10;
    r2.y = t->field_0->field_1C + i / 3 * 40;
    r2.w = ((TimBlk11BEC *)p)->w;
    r2.h = ((TimBlk11BEC *)p)->h;
    func_8002772C(&r2, ((TimBlk11BEC *)p)->data);
    t->slot[i].id = D_80040DAC[k];
found:
    t->slot[i].t = D_8005F774;
    *out = *t->field_0;
    pos->x = i % 3 * 40;
    pos->y = i / 3 * 40;
    clut->x = i / 16 * 16;
    clut->y = i % 16 + 0xF0;
}

void func_80011F04(void) {
    s32 i;
    s32 j;
    s32 v;

    i = 0;
    j = i;
    do {
        v = D_8005071C->field_BA9[i];
        D_8005071C->field_BA9[i] = 0;
        if (v != 0) {
            D_8005071C->field_BA9[j++] = v;
        }
        i++;
    } while (i < 12);
}

s32 *func_80011F5C(s32 id) {
    s32 *base = 0;
    u32 i;
    s32 key;

    if ((i = id - 0x78) < 0x10) {
        key = 0x5130000;
    } else if ((i = id - 0xD0) < 0x1A) {
        key = 0x5130001;
    } else if ((i = id - 0x97) < 0xF) {
        key = 0x5130002;
    } else {
        goto end;
    }
    base = (s32 *)func_800239A0(key);
    id = i;
end:
    if (base != 0) {
        base = &base[id];
    }
    return base;
}

s32 func_80011FE4(s32 arg0) {
    s32 r = 0;
    if (func_8001E134() != 0) {
        u8 *p = func_80011F5C(arg0);
        if (p != 0) {
            u8 b = *p;
            if (b != 0) {
                if (b < 5) {
                    r = 1;
                } else {
                    r = 2;
                }
            }
        }
    }
    return r;
}

s32 func_8001204C(s32 a0, s32 a1, s32 a2, s32 a3) {
    Rec11F5C *rec;
    s32 r;
    s16 *p;
    s16 *q;
    u8 v;
    s32 c;
    s32 i;
    s32 j;
    s32 best;
    s32 max;
    s32 n;
    s32 cnt;

    rec = (Rec11F5C *)func_80011F5C(a0);
    r = 0;
    switch (rec->field_1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    default:
        if (rec->field_1 == 0) {
            p = &D_80050720->field_24;
            q = &D_80050720->field_26;
        } else {
            p = &D_80050720->field_28;
            q = &D_80050720->field_2A;
        }
        if (*p >= *q) {
            return r;
        }
        *p = (*q < *p + rec->field_2) ? *q : (s16)(*p + rec->field_2);
        r = 1;
        break;
    case 0xB:
        if (func_80022518(a2) < 0) {
            func_8002254C(a2, 0);
            r = 1;
        }
    case 0xC:
    case 0xD:
    case 0xE:
        c = D_8005071C->field_BA5[rec->field_1 - 0xC];
        v = c;
        if (c != 0) {
            r = 2;
            if (rec->field_2 >= v) {
                D_8005071C->field_BA5[rec->field_1 - 0xC] = 0;
                r = 1;
            }
        }
        break;
    case 0xF:
        if (D_8005071C->field_BA8 != 0) {
            best = -1;
            max = 0;
            for (j = 0; j < D_8005071C->field_BA8; j++) {
                v = D_8005071C->field_BA9[j];
                if (rec->field_2 >= v && max < v) {
                    best = j;
                    max = v;
                }
            }
            r = 1;
            if (best == -1) {
                goto none;
            }
            D_8005071C->field_BA8--;
            D_8005071C->field_BA9[best] = 0;
            func_80011F04();
            D_80050760 = max;
            break;
        }
        break;
    case 0x10:
        if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (D_8005071C->field_BA5[i] != 0 && rec->field_2 >= D_8005071C->field_BA5[i]) {
                    D_8005071C->field_BA5[i] = 0;
                    cnt++;
                }
            }
            n = D_8005071C->field_BA8;
            for (i = 0; i < n; i++) {
                if (rec->field_2 >= D_8005071C->field_BA9[i]) {
                    D_8005071C->field_BA9[i] = 0;
                    D_8005071C->field_BA8--;
                    cnt++;
                }
            }
            func_80011F04();
            r = 1;
            if (cnt == 0) {
            none:
                r = 2;
            }
        }
        break;
    }
    return r;
}


s32 func_8001236C(s32 a0, s32 a1, s32 a2, s32 a3) {
    Obj1236C *o = (Obj1236C *)a3;
    Rec11F5C *r = (Rec11F5C *)func_80011F5C(a0);
    s16 *cur;
    s16 *lim;
    s16 step;

    if (r->field_0 == 3 && r->field_2 != ((s32 (*)(s32))func_8001D934)(o->field_1)) {
        return 0;
    }
    if (r->field_1 == 3) {
        if (o->field_16 != 0) {
            return 0;
        }
        o->field_16 = o->field_14;
        return 1;
    }
    if (o->field_16 == 0) {
        return 0;
    }
    if (r->field_1 == 0) {
        cur = &o->field_16;
        lim = &o->field_14;
    } else {
        cur = &o->field_1A;
        lim = &o->field_18;
    }
    if (*cur == *lim) {
        return 0;
    }
    if (r->field_0 == 3) {
        step = *lim - *cur;
    } else {
        step = r->field_2;
    }
    *cur = (*lim < *cur + step) ? *lim : (s16)(*cur + step);
    return 1;
}

s32 func_80012490(s32 a0, s32 a1, s32 a2, s32 a3) {
    Dg12490 *dg = (Dg12490 *)a3;
    Rec12490 *rec;
    s16 *p;
    s32 d;
    s32 n;
    s32 inc;

    rec = (Rec12490 *)func_80011F5C(a0);
    if (dg->field_16 == 0) {
        return 0;
    }
    switch (rec->field_1) {
    case 9:
        d = rec->field_2;
        if (d > 0 && d + dg->field_E >= 100) {
            return 0;
        }
        if (d < 0 && d + dg->field_E < 0) {
            return 0;
        }
        dg->field_E += rec->field_2;
        return 1;
    case 10:
        if (dg->field_10 == 99999999) {
            return 0;
        }
        d = dg->field_10 += rec->field_2;
        if (d > 99999999) {
            d = 99999999;
        }
        dg->field_10 = d;
        return 1;
    case 4:
    default:
        p = &dg->field_14;
        break;
    case 5:
        p = &dg->field_18;
        break;
    case 6:
        p = &dg->field_1C;
        break;
    case 7:
        p = &dg->field_1E;
        break;
    case 8:
        p = &dg->field_20;
        break;
    }
    if (*p == 999) {
        return 0;
    }
    n = (func_80023910() & 0xFFF) * 100 / 0x21000;
    inc = 3;
    if (n < 3) {
        inc = n + 1;
    }
    n = inc;
    *p = (*p + n < 1000) ? (s16)(*p + n) : 999;
    return 1;
}


s32 func_80012640(s32 a0, s32 a1) {
    ElmE620 *e = D_80050720->elems;
    Cfg12640 *c = (Cfg12640 *)func_80011F5C(a0);
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x24; i++, e++) {
        s16 cur;
        s16 max;
        if (e->field_0 < 2) continue;
        cur = e->field_16;
        if (cur == 0) continue;
        if (c->field_1 == 0 || c->field_1 == 2) {
            max = e->field_14;
            if (cur != max) {
                if (c->field_2 == 0) {
                    e->field_16 = max;
                } else {
                    e->field_16 = max < cur + c->field_2 ? max : e->field_16 + c->field_2;
                }
                n++;
            }
        }
        if ((u8)(c->field_1 - 1) < 2) {
            cur = e->field_1A;
            max = e->field_18;
            if (cur != max) {
                if (c->field_2 == 0) {
                    e->field_1A = max;
                } else {
                    e->field_1A = max < cur + c->field_2 ? max : e->field_1A + c->field_2;
                }
                n++;
            }
        }
    }
    return n != 0;
}


s32 func_80012778(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p;
    s32 r;

    p = (u8 *)func_80011F5C(a0);
    r = 0;
    if (p != NULL) {
        switch (*p) {
        case 5:
            r = func_8001204C(a0, a1, a2, a3);
            break;
        case 1:
        case 3:
            r = func_8001236C(a0, a1, a2, a3);
            break;
        case 4:
            r = func_80012490(a0, a1, a2, a3);
            break;
        case 2:
            r = func_80012640(a0, a1);
            break;
        }
        if (r != 0) {
            func_800227F0(a1);
        }
    }
    return r;
}


u8 func_8001287C(Actor *a0) {
    ActorWork *w;
    s32 base;
    s32 k;
    u8 *p;

    w = a0->work;
    base = w->field_C;
    base += 0x1FD00D4;
    k = w->field_2C >= 10;
    if (w->field_2C >= 5) {
        k++;
    }
    p = (u8 *)func_800239A0(base + k);
    return p[w->field_2E * D_80040E38[k] + w->field_2C - D_80040E44[k]];
}


void func_8001291C(Actor *a, Pair1291C *v) {
    ActorWork *w = a->work;

    *(Pair1291C *)w = *v;
    switch (w->field_0) {
    case 0:
    default:
        w->field_8 = 0xD;
        break;
    case 1:
        w->field_8 = 5;
        break;
    case 2:
        w->field_8 = 7;
        break;
    }
}

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s16 field_2C;
    /* 0x2E */ s16 field_2E;
} Wk12974;

typedef struct {
    /* 0x00 */ u8 name[0x5C];
} Nm12974;

extern u8 D_8005E634[];
extern u8 D_8005E6F1[];
extern Nm12974 D_8005E750[];
extern u16 D_8005F72C;
extern u8 func_8001287C(Actor *);
extern void func_8001A8BC(void);
extern void func_8001A8D0(void);

void func_80012974(Actor *a0) {
    Wk12974 *w = (Wk12974 *)a0->work;
    u8 *p;
    u8 *src;
    s32 i;
    u16 k;
    Arg1BC24 arg;
    Arg1BC24 arg2;

    switch (w->field_0) {
    default:
    case 0:
        p = D_8005E750[w->field_4].name;
        break;
    case 1:
        p = D_8005E634;
        break;
    case 2:
        p = D_8005E6F1;
        break;
    }
    switch (a0->field_10) {
    case 0:
        func_8001C088(&w->field_10, 5);
        for (i = 0; i < w->field_8; i++) {
            p[i] = 0xFD;
        }
        p[i] = 0xFF;
        switch (w->field_0) {
        default:
        case 0:
            src = func_8001E758(D_8005E620.elems[w->field_4].field_1);
            for (i = 0; i < 14; i++) {
                if (src[i] == 0xFF) {
                    break;
                }
                p[i] = src[i];
            }
            break;
        case 1:
            p[0] = 0xA;
            p[1] = 0x2E;
            p[2] = 0x2C;
            p[3] = 0x35;
            p[4] = 0x24;
            break;
        case 2:
            p[0] = 0x10;
            p[1] = 0x38;
            p[2] = 0x31;
            p[3] = 0x31;
            p[4] = 0x28;
            p[5] = 0x35;
            break;
        }
        func_8001A8BC();
        func_8001A68C(0x22, 1);
        w->field_C = 6;
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            func_8001BB88(&w->field_10);
            func_8001BB88(&w->field_14);
            func_8001BB88(&w->field_18);
            func_8001BB88(&w->field_20);
            arg.field_14 = (s32)func_800239A0(w->field_C + 0x1FD00D4);
            arg.field_8 = 0x28;
            arg.field_A = 0x42;
            arg.field_C = 0x13;
            arg.field_0 = 1;
            arg.field_4 = 0;
            arg.field_10 = 0x12;
            arg.field_18 = 0;
            func_8001BC24(&w->field_10, &arg);
            arg.field_14 = (s32)func_800239A0(w->field_C + 0x1FD00D5);
            arg.field_8 += 0x65;
            func_8001BC24(&w->field_14, &arg);
            arg.field_14 = (s32)func_800239A0(w->field_C + 0x1FD00D6);
            arg.field_8 += 0x65;
            func_8001BC24(&w->field_18, &arg);
            arg.field_8 = 0x26;
            arg.field_14 = (s32)p;
            arg.field_A = 0x20;
            arg.field_C = 0;
            arg.field_10 = 0;
            arg.field_18 = 0;
            func_8001BC24(&w->field_20, &arg);
            switch (w->field_0) {
            default:
            case 0:
                arg2.field_14 = (s32)func_8001E758(D_8005E620.elems[w->field_4].field_1);
                break;
            case 1:
                arg2.field_14 = (s32)func_800239A0(0x1FD0074);
                break;
            L34:
                w->field_2C = 10;
                w->field_2E = 7;
                func_8001A68C(0x12, 0);
                goto keys_done;
            Lnone:
                func_8001A68C(0x10, 0);
                goto keys_done;
            case 2:
                arg2.field_14 = (s32)func_800239A0(0x1FD0072);
                break;
            }
            arg2.field_4 = 4;
            arg2.field_8 = 0x23;
            arg2.field_0 = 0;
            arg2.field_A = 0x13;
            arg2.field_C = 0;
            arg2.field_10 = 0;
            arg2.field_18 = 0;
            func_8001BC24(&w->field_1C, &arg2);
            func_80011564(a0);
        case 1:
            k = D_8005F6F0[0].field_3C;
            if (k & 0x2000) {
                if (w->field_2C != 10) {
                    if (++w->field_2C == 10) {
                        w->field_2E = 7;
                    }
                    func_8001A68C(0x12, 0);
                }
            } else if (k & 0x8000) {
                if (w->field_2C != 0) {
                    w->field_2C--;
                    func_8001A68C(0x12, 0);
                }
            } else if (k & 0x1000) {
                if (w->field_2E != 0) {
                    w->field_2E--;
                    if (w->field_2C == 10) {
                        w->field_2C--;
                    }
                    func_8001A68C(0x12, 0);
                }
            } else if (k & 0x4000) {
                if (w->field_2E != 7) {
                    w->field_2E++;
                    func_8001A68C(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_20 > 0) {
                if (w->field_24 != w->field_8) {
                    w->field_24++;
                    func_8001A68C(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_28 > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    func_8001A68C(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_1C > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    p[w->field_24] = 0xFD;
                    func_8001A68C(0xB, 0);
                }
            } else if (D_8005F6F0[0].field_34 > 0) {
                goto L34;
            } else if (D_8005F6F0[0].field_14 > 0) {
                if (w->field_2C < 10 || w->field_2E < 4) {
                    if (w->field_24 != w->field_8) {
                        p[w->field_24] = func_8001287C(a0);
                        w->field_24++;
                        func_8001A68C(0xE, 0);
                    }
                } else if (w->field_2E == 7) {
                    for (i = 0; i < w->field_8; i++) {
                        if (p[i] != 0xFD) {
                            break;
                        }
                    }
                    if (i != w->field_8) {
                        for (i = w->field_8 - 1; i >= 0; i--) {
                            if (p[i] != 0xFD) {
                                break;
                            }
                            p[i] = 0xFF;
                        }
                        func_80011544(a0);
                        func_8001A68C(0xE, 0);
                    } else {
                        goto Lnone;
                    }
                }
            }
        keys_done:
            if (w->field_24 == w->field_8) {
                w->field_2C = 10;
                w->field_2E = 7;
            }
            if (D_8005F72C & 0xF000) {
                w->field_28 = 0;
            }
            break;
        }
        break;
    case 2:
        if (D_8005F788[0] != 0x500) {
            func_8001A8D0();
        }
        func_8001C0B0(&w->field_10, 5);
        func_80011544(a0);
        break;
    }
}


void func_8001309C(Actor *a) {
    ActorWork *w = a->work;
    Part28 *base = (Part28 *)func_800239A0(0x1A10018);
    Part28 *p;
    s32 k;
    s32 v;
    s32 x;

    w->field_28 += D_8005F770.field_8;
    for (p = base; p->field_0 != 0; p++) {
        if (p->field_1C & 0x20) {
            v = w->field_24;
            p->field_6 = -0x48;
            p->field_4 = v * 9 - 0x71;
            if (w->field_24 == w->field_8) {
                p->field_F = 0;
            } else {
                p->field_F = 1;
            }
        } else if (p->field_1C & 0x40) {
            v = w->field_2C;
            x = -0x73;
            if (v >= 10) {
                x = -0x6D;
            }
            if (v >= 5) {
                x += 6;
            }
            p->field_4 = x + v * 19;
            p->field_6 = w->field_2E * 18 - 0x2F;
        }
        k = 0;
        if (w->field_2C >= 10 && w->field_2E >= 4) {
            k = w->field_2E - 3;
        }
        if (p->field_1C & 0x7DC) {
            p->field_F = 0;
        }
        if (!(w->field_28 & 0x10)) {
            switch (k) {
            case 0:
                if (p->field_1C & 0x40) {
                    p->field_F = 1;
                }
                break;
            case 1:
                if (p->field_1C & 0x80) {
                    p->field_F = 1;
                }
                break;
            case 2:
                if (p->field_1C & 0x100) {
                    p->field_F = 1;
                }
                break;
            case 3:
                if (p->field_1C & 0x200) {
                    p->field_F = 1;
                }
                break;
            case 4:
                if (p->field_1C & 0x400) {
                    p->field_F = 1;
                }
                break;
            }
        }
        if (w->field_0 == 0 && (p->field_1C & 4)) {
            p->field_F = 1;
        }
        if (w->field_0 == 1 && (p->field_1C & 8)) {
            p->field_F = 1;
        }
        if (w->field_0 == 2 && (p->field_1C & 0x10)) {
            p->field_F = 1;
        }
    }
    func_8001D884((s32)base);
}


void func_80013308(s32 id) {
    s32 *p;
    u8 *src;
    u8 *dst;

    if (D_800506FC != id) {
        p = &D_80040E68[id];
        D_800506FC = id;
        src = (u8 *)func_80023DB0(*p);
        dst = D_80010000[0];
        func_80027044(dst, src, func_80023F90(*p) << 11);
    }
}

s32 func_80013378(void) {
    return D_800506FC;
}


extern void func_80013308(s32);
extern void func_8001107C(u32, s32 *, s32);
extern s32 func_8001A300(void);
extern s32 D_8005F78C;

void func_80013384(Actor *a0) {
    s32 st = a0->field_10;
    s32 t = a0->u34.field_34;
    switch (st) {
    case 0:
    default:
        func_80013308((D_8005F770.field_18 >> 8) - 1);
        func_8001107C(D_8005F770.field_18 & 0xFF00, t, 0);
        func_80011544(a0);
        break;
    case 1:
        if (D_8005F78C != 0) {
            func_800115C0(a0, 2);
        }
        break;
    case 2:
        if (func_8001A300() == 0) {
            func_800115C0(a0, 3);
        }
        break;
    }
}

void func_80013450(void) {
    func_8001125C();
}

void func_80013470(void *arg0, Src13470 *arg1) {
    Arg1BC24 local;
    local.field_14 = arg1->field_0;
    local.field_0 = arg1->field_10 >> 7;
    local.field_4 = arg1->field_11;
    local.field_8 = arg1->field_C;
    local.field_A = arg1->field_E;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = arg1->field_10 & 0x7F;
    local.field_1C = arg1->field_4;
    local.field_20 = arg1->field_8;
    func_8001BC24(arg0, &local);
}

void func_800134F8(void *arg0, s32 arg1, u32 arg2, Halves arg3) {
    Arg1BC24 local;
    local.field_0 = (arg2 >> 7) & 1;
    local.field_14 = arg1;
    local.field_4 = (arg2 >> 2) & 0xF;
    local.field_8 = arg3.lo;
    local.field_A = arg3.hi;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = arg2 & 3;
    func_8001BC24(arg0, &local);
}

s32 func_80013558(s32 *a0, Key13558 *a1, u32 a2) {
    s32 n = 0;

    while (a1->key != 0) {
        n++;
        func_800134F8(a0, (s32)func_800239A0((a1->key & 0xFFF) | 0x1FD0000),
                      a2 | ((a1->key & 0xF000) >> 10), a1->h);
        a1++;
        a0++;
    }
    return n;
}

void func_8001361C(s32 *a0, Halves *a1, s32 *a2, u32 a3) {
    while (*a2 != 0) {
        func_800134F8(a0, *a2, a3, *a1);
        a2++;
        a1++;
        a0++;
    }
}

s32 func_800136A4() {
    s32 result = func_8001BE08();
    if (result != 0) {
        result = func_80021E78(0x11) == 0 ? 1 : -1;
    }
    return result;
}

s32 func_800136E4(s32 arg0, s32 *arg1) {
    s32 v = *arg1 + 0x333;
    *arg1 = v;
    if (v >= 0x1000) {
        *arg1 = 0x1000;
        return 0;
    }
    return 1;
}

s32 func_80013714(s32 arg0, s32 *arg1) {
    s32 v = *arg1 - 0x333;
    *arg1 = v;
    if (v <= 0) {
        *arg1 = 0;
        return 0;
    }
    return 1;
}

void func_8001373C(void *arg0, s32 mask, s32 *arg2, s16 *arg3) {
    Part28 *p = arg0;
    Part28 *q = p;
    s32 x = arg3[2] + ((s16 *)arg2)[0] * arg3[4];
    s32 y = arg3[3] + ((s16 *)arg2)[1] * arg3[5];

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_4 = x;
                q->field_6 = y;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}


void func_800137B8(Part28 *p, s32 mask, s32 v) {
    Part28 *q = p;

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_C = v;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

void func_800137FC(Part28 *p, s32 mask, u16 *xy) {
    Part28 *q = p;

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_4 = xy[0];
                q->field_6 = xy[1];
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

s32 func_80013854(Part28 *p, s32 mask, s32 n) {
    Part28 *q;
    s32 r = 0;

    if (n <= 0) {
        r = mask;
    } else {
        q = p;
        if (p->field_0 != 0) {
            do {
                if (q->field_1C & mask) {
                    q->field_C = (D_80050768->field_4 >> 2) & 3;
                }
                p++;
                q++;
            } while (p->field_0 != 0);
        }
    }
    return r;
}

/* file-local views for func_800138C0 */
typedef struct {
    s16 field_0;
    s16 field_2;
} Coord138C0;

typedef struct {
    s16 h[2];
} Copy138C0;

/* view of Elm6F0 that reads the 0x3C flag word unsigned */
typedef struct {
    u8 _p[0x3C];
    u16 field_3C;
    u8 _p2[0x40 - 0x3E];
} ElmFlags138C0;

s32 func_800138C0(s32 a0, s32 a1, s32 a2) {
    Coord138C0 *p0 = (Coord138C0 *)a0;
    Coord138C0 *p1 = (Coord138C0 *)a1;
    Copy138C0 saved;
    s32 changed;

    changed = 0;
    saved = *(Copy138C0 *)p0;

    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x8000) {
        if (p0->field_0 > 0) {
            p0->field_0 = p0->field_0 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x2000) {
        if (p0->field_0 < p1->field_0 - 1) {
            p0->field_0 = p0->field_0 + 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x1000) {
        if (p0->field_2 > 0) {
            p0->field_2 = p0->field_2 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x4000) {
        if (p0->field_2 < p1->field_2 - 1) {
            p0->field_2 = p0->field_2 + 1;
        }
    }

tail:
    if (saved.h[0] != p0->field_0 || saved.h[1] != p0->field_2) {
        changed = -1;
    }
    return changed;
}

s32 func_80013A10(s32 arg0, s32 arg1) {
    return func_800138C0(arg0, arg1, 0);
}

s32 func_80013A30(s32 *arg0, s32 arg1, s32 arg2) {
    s32 old = *arg0;

    if (arg2 - 1 < arg1 - old) {
        *arg0 = arg1 - (arg2 - 1);
    } else if (arg1 < old) {
        *arg0 = arg1;
    }
    return *arg0 - old;
}

s32 func_80013A70(s16 *arg0, s16 *arg1) {
    return arg1[1] * arg0[0] + arg0[1];
}

s32 func_80013A90(s16 *arg0, s16 *arg1) {
    return arg1[0] * arg0[1] + arg0[0];
}

s32 func_80013AB0(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)func_800239A0(arg0);
    s32 r = func_80023A08(arg0 >> 16);
    return p[arg1] + r;
}

void func_80013AFC(u8 *out, s32 val, s32 width) {
    u8 buf[8];
    s32 sign = 0;
    s32 done = 0;
    s32 i;

    if (width < 0) {
        width = -width;
        sign = 1;
    }
    if (val > 99999999) {
        val = 99999999;
    }
    for (i = 0; i < width; i++) {
        u8 *p = &buf[i];
        if (!done) {
            *p = val % 10;
        } else {
            *p = 0xFD;
        }
        val = val / 10;
        done = (val == 0);
    }
    for (i = width - 1; i >= 0; i--) {
        if (sign && buf[i] == 0xFD) {
            continue;
        }
        *out++ = buf[i];
    }
    *out = 0xFF;
}

void func_80013BF8(Actor *arg0, s16 arg1) {
    arg0->work->field_30 = arg1;
}

void func_80013C04(Actor *a0) {
    Wk13C04 *w = (Wk13C04 *)a0->work;
    s32 *slot = (s32 *)a0->u34.field_34;
    Pair54 *tbl;
    s32 v;
    s32 k;
    s32 snd;

    switch (a0->field_10) {
    case 0:
    default:
        D_80050768 = (Obj50768 *)func_80022F3C(0x364, 2);
        D_80050768->field_360 = 0;
        D_80050764 = 0;
        *(Layout8C *)w->field_24 = *(Layout8C *)func_800239A0(0x5130005);
        D_80050768->field_0 = 0;
        v = D_8005F788[0];
        if (v / 256 != 2) {
            switch (v) {
            default:
                D_80050768->field_0 = 2;
                break;
            case 0x32D ... 0x32E:
                D_80050768->field_0 = 6;
                break;
            case 0x32A ... 0x32C:
                D_80050768->field_0 = 4;
                break;
            }
        } else {
            D_80050768->field_0 = 1;
            if (func_80021E78(0x67) == 0) {
                D_80050768->field_0 |= 8;
            }
        }
        if (func_8002284C(0) == 0x24) {
            D_80050768->field_0 = (D_80050768->field_0 | 0x10) & ~2;
        }
        D_80050768->field_4 = 0;
        func_8001C088(&w->field_0, 8);
        func_80011544(a0);
        func_8001C4C8(0x20);
        break;
    case 1:
        tbl = (Pair54 *)func_800239A0(0x5130006);
        switch (a0->field_14) {
        case 0:
        default:
            if (func_800136E4((s32)a0, &w->field_34) != 0) {
                break;
            }
            func_80013558(&w->field_0, (Key13558 *)func_800239A0(0x5130003), 2);
            func_8001BB88((D_80050768->field_0 & 1) ? &w->field_14 : &w->field_18);
            func_8001BE74(w->field_4, (D_80050768->field_0 >> 4) & 1);
            func_8001BE74(w->field_8, (D_80050768->field_0 >> 4) & 1);
            func_8001BE74(w->field_C, (D_80050768->field_0 >> 4) & 1);
            func_8001BE74(w->field_10, !(D_80050768->field_0 & 2));
            func_8001BE74(w->field_14, !(D_80050768->field_0 & 4));
            func_8001BE74(w->field_18, !(D_80050768->field_0 & 8));
            func_80011564(a0);
            break;
        case 1:
            if (func_80013A10((s32)w->field_20, (s32)w->field_24) != 0) {
                snd = 0xC;
            } else if (D_8005F6F0[0].field_14 > 0) {
                k = func_80013A70(w->field_20, w->field_24);
                if (k == 5 && (D_80050768->field_0 & 1)) {
                    k = 6;
                }
                if ((u32)(k - 1) < 3 && (D_80050768->field_0 & 0x10)) {
                    snd = 0x10;
                } else if (k == 4 && !(D_80050768->field_0 & 2)) {
                    snd = 0x10;
                } else if (k == 5 && !(D_80050768->field_0 & 4)) {
                    snd = 0x10;
                } else if (k == 6 && !(D_80050768->field_0 & 8)) {
                    snd = 0x10;
                } else if (k == 5) {
                    D_80050768->field_360 = 1;
                    func_800115C0(a0, 2);
                    snd = 0xA;
                } else {
                    w->field_32 = k;
                    func_80011564(a0);
                    snd = 0xA;
                }
            } else {
                if (D_8005F6F0[0].field_1C > 0) {
                    func_8001A68C(0xB, 0);
                    func_800115C0(a0, 2);
                }
                break;
            }
            func_8001A68C(snd, 0);
            break;
        case 2:
            switch (a0->field_18) {
            case 0:
            default:
                func_8001C0B0(&w->field_0, 8);
                func_80011580(a0);
                break;
            case 1:
                if (func_80013714((s32)a0, &w->field_34) == 0) {
                    func_80011564(a0);
                }
                break;
            }
            break;
        case 3:
            switch (a0->field_18) {
            case 0:
            default:
                func_8001107C(tbl[w->field_32].field_0, slot, tbl[w->field_32].field_2);
                func_80011580(a0);
                break;
            case 1:
                if (*slot == 0) {
                    if (D_80050768->field_360 != 0) {
                        func_800115C0(a0, 2);
                    } else {
                        func_800115DC(a0, 0);
                    }
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            func_8001C0B0(&w->field_0, 8);
            D_80050764 = D_80050768->field_360;
            func_80011564(a0);
            func_8001C4F0(0x20);
            break;
        case 1:
            if (func_80013714((s32)a0, &w->field_34) == 0) {
                func_800115C0(a0, 3);
                func_80022D84((ActorWork *)D_80050768);
            }
            break;
        }
        break;
    }
    if (D_80050768 != NULL) {
        D_80050768->field_4 = a0->field_28;
    }
}


void func_800141D4(Actor *actor) {
    Work141D4 *w = (Work141D4 *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    Part28 *base;
    Part28 *q;
    Part28 *r;

    if (w->field_34 != 0) {
        p = (s32 *)func_800239A0(0x5130004);
        if (*p != 0) {
            i = 0;
            list = p;
            do {
                obj = func_800239A0(*list);
                switch (i) {
                case 0:
                default:
                    func_8001373C(obj, 2, &w->field_20, &w->field_24);
                    func_800137B8(obj, 2, (actor->field_28 >> 2) & 3);
                    break;
                case 1:
                    func_8001D5B4(obj, 2, 8, D_80050720->field_8);
                    break;
                }
                func_8001D550(obj, 0x1000, w->field_34);
                list++;
                func_8001D884((s32)obj);
                i++;
            } while (*list != 0);
        }
    }
    base = (Part28 *)func_800239A0(0x459000C);
    for (q = base; q->field_0 != 0; q++) {
        switch (q->field_1C) {
        case 2:
            q->field_C = func_800223EC(actor->field_28, 0xA, 0, 7);
            break;
        case 8:
            q->field_4 -= 2;
            if (q->field_4 == -0x168) {
                q->field_4 = 0;
            }
            break;
        case 0x10:
            q->field_4 += 1;
            if (q->field_4 == 0xD8) {
                q->field_4 = 0;
            }
            break;
        case 0x20:
            q->field_4 -= 2;
            if (q->field_4 == -0x1C0) {
                q->field_4 = 0;
            }
            break;
        }
    }
    func_8001D884((s32)base);
}

void func_800143CC(Actor *arg0, s16 arg1) {
    ActorWork *w = arg0->work;

    w->field_38 = arg1;
    if (arg1 == 3) {
        D_80050768->field_35C = 0;
        w->field_3C = 0;
    }
}

void func_80014400(Actor *a) {
    Wk14400 *w = (Wk14400 *)a->work;
    s32 *p = (s32 *)a->u34.field_34;
    Pair54 *tbl;
    Pair54 *e;
    s32 idx;

    switch (a->field_10) {
    default:
    case 0:
        w->u2C.blk = ((Blk14400 *)func_800239A0(0x5130007))[w->field_38 - 1];
        func_8001C088(w, 0xA);
        func_80011544(a);
        break;
    case 1:
        tbl = (Pair54 *)func_80013AB0(0x513000A, w->field_38 - 1);
        switch (a->field_14) {
        default:
        case 0:
            if (func_800136E4((s32)a, &w->field_40) == 0) {
                func_80013558((s32 *)w, (Key13558 *)func_80013AB0(0x5130008, w->field_38 - 1), 2);
                switch (w->field_38) {
                case 5:
                case 6:
                    func_800115DC(a, 2);
                    break;
                default:
                    func_80011564(a);
                    break;
                }
            }
            break;
        case 1:
            if (((s32 (*)(s16 *, s16 *))func_80013A10)(w->field_28, w->u2C.field_2C) == 0) {
            if (D_8005F6F0[0].field_14 > 0) {
                idx = func_80013A70(w->field_28, w->u2C.field_2C);
                if (tbl[idx].field_0 == -1) {
                    break;
                }
                w->field_3A = idx;
                func_8001A68C(0xA, 0);
                switch (w->field_38) {
                case 7:
                case 8:
                    D_80050768->field_124 = w->field_28[0];
                    func_80011564(a);
                    break;
                case 4:
                    func_800115DC(a, 3);
                    break;
                default:
                    func_80011564(a);
                    break;
                }
            } else if (D_8005F6F0[0].field_1C > 0) {
                func_8001A68C(0xB, 0);
                func_800115C0(a, 2);
            }
            } else {
                func_8001A68C(0xC, 0);
            }
            break;
        case 2:
            switch (a->field_18) {
            default:
            case 0:
                e = &tbl[w->field_3A];
                func_8001107C(e->field_0, p, e->field_2);
                func_80011580(a);
                break;
            case 1:
                if (w->field_38 == 3) {
                    switch (D_80050768->field_35C) {
                    case 1:
                        func_8001C0B0(w->field_4, 9);
                        w->field_3C = 1;
                        break;
                    case 2:
                        func_8001C0B0(w, 0xA);
                        func_80013558((s32 *)w, (Key13558 *)func_80013AB0(0x5130008, w->field_38 - 1), 0);
                        w->field_3C = 0;
                        break;
                    }
                    D_80050768->field_35C = 0;
                }
                if (*p == 0) {
                    switch (w->field_38) {
                    default:
                        func_800115DC(a, 1);
                        break;
                    case 5:
                    case 6:
                        func_800115C0(a, 2);
                        break;
                    }
                }
                break;
            }
            break;
        case 3: {
            s32 *q = (s32 *)a->u34.field_34;
            switch (a->field_18) {
            default:
            case 0:
                func_8001C0B0(w, 0xA);
                func_80011580(a);
                break;
            case 1:
                if (func_80013714((s32)a, &w->field_40) == 0) {
                    func_80011580(a);
                }
                break;
            case 2:
                e = &tbl[w->field_3A];
                func_8001107C(e->field_0, q, e->field_2);
                func_80011580(a);
                break;
            case 3:
                if (*q == 0) {
                    func_800115DC(a, 0);
                }
                break;
            }
            break;
        }
        }
        break;
    case 2:
        switch (a->field_14) {
        default:
        case 0:
            func_8001C0B0(w, 0xA);
            func_80011564(a);
            break;
        case 1:
            if (func_80013714((s32)a, &w->field_40) == 0) {
                func_800115C0(a, 3);
            }
            break;
        }
        break;
    }
}


extern void func_8001373C(void *, s32, s32 *, s16 *);
extern void func_800137B8(Part28 *, s32, s32);
extern void func_8001D504(Obj1D504 *, s32);

void func_80014870(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;

    if (w->field_40 == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x5130009);
    if (*p == 0) {
        return;
    }
    list = p;
    do {
        obj = func_800239A0(*list);
        if (w->field_2C != 0 && w->field_3C == 0) {
            func_8001373C(obj, 2, &w->field_28, &w->field_2C);
            func_800137B8(obj, 2, (actor->field_28 >> 2) & 3);
            func_8001D504(obj, 0);
        } else {
            func_8001D504(obj, 2);
        }
        list++;
        func_8001D550(obj, 0x1000, w->field_40);
        func_8001D884((s32)obj);
    } while (*list != 0);
}

void func_80014978(Actor *arg0, s16 arg1) {
    arg0->work->field_6C = arg1;
}

void func_80014984(Actor *a0) {
    Wk14CBC *w = (Wk14CBC *)a0->work;
    s32 i;
    s32 v;
    s32 id;
    s32 *p;
    s16 *tbl;
    Halves *h;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_AC = func_80022910(3, (ElmE620 **)w->field_A0);
        func_8001C088(w, 0x1A);
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (func_800136E4((s32)a0, &w->field_70) != 0) {
                break;
            }
            func_80013558(w->field_0, (Key13558 *)func_800239A0(0x513000B), 2);
            w->field_74[0] = (s32)D_80050720->field_14;
            tbl = (s16 *)func_800239A0(0x513000F);
            w->field_74[1] = (s32)func_800239A0(tbl[D_80050720->field_11 * 11 + D_80050720->field_12] + 0x1FD0000);
            w->field_74[2] = (s32)D_80050720->field_D1;
            p = &w->field_74[3];
            for (i = 0; i < w->field_AC; i++) {
                *p++ = (s32)w->field_A0[i]->field_4C;
            }
            *p = 0;
            func_8001361C(w->field_40, (Halves *)func_800239A0(0x513000C), w->field_74, 2);
            if (D_80050768->field_0 & 1) {
                h = (Halves *)func_800239A0(0x513000D);
                for (i = 0; i < 4; i++) {
                    v = (i == 3) ? func_80021D60() : D_8005071C->field_BA5[i];
                    if (v != 0) {
                        id = v + 0x1FD00EC;
                        func_800134F8(&w->field_58[i], (s32)func_800239A0(i * 3 + id), 1, h[i]);
                    }
                }
            }
            for (i = w->field_AC; i < 3; i++) {
                func_8001BB88(&w->field_0[i * 3 + 7]);
                func_8001BB88(&w->field_0[i * 3 + 8]);
                func_8001BB88(&w->field_0[i * 3 + 9]);
            }
            func_80011564(a0);
            break;
        case 1:
            if (D_8005F6F0[0].field_1C > 0) {
                func_8001A68C(0xB, 0);
                func_800115C0(a0, 2);
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            func_8001C0B0(w, 0x1A);
            func_80011564(a0);
            break;
        case 1:
            if (func_80013714((s32)a0, &w->field_70) == 0) {
                func_800115C0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80014CBC(Actor *actor) {
    Wk14CBC *w = (Wk14CBC *)actor->work;
    s32 *p;
    s32 *list;
    s32 i;
    Part28 *obj;
    Rec14CBC *rec;

    if (w->field_70 == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x513000E);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = (Part28 *)func_800239A0(*list);
        if (i == 0) {
            func_8001D5B4(obj, 2, 8, D_80050720->field_8);
            func_8001D5B4(obj, 4, 4, D_80050720->field_26);
            func_8001D5B4(obj, 8, 4, D_80050720->field_24);
            func_8001D5B4(obj, 0x10, 4, D_80050720->field_2A);
            func_8001D5B4(obj, 0x20, 4, D_80050720->field_28);
        } else if (i - 1 < w->field_AC) {
            rec = w->field_A0[i - 1];
            func_8001D5B4(obj, 2, 3, rec->field_14);
            func_8001D5B4(obj, 4, 3, rec->field_16);
            func_8001D5B4(obj, 8, 3, rec->field_18);
            func_8001D5B4(obj, 0x10, 3, rec->field_1A);
            func_8001D5B4(obj, 0x20, 2, rec->field_D);
            func_8001D504(obj, 0);
        } else {
            func_8001D504(obj, 0xFFFF);
        }
        func_8001D550((Ent1D550 *)obj, 0x1000, w->field_70);
        list++;
        func_8001D884((s32)obj);
        i++;
    } while (*list != 0);
}

void func_80014EA4(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Src16198 st;

    if (func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, 0) != 0) {
        st.field_C = D_80050700;
        st.field_11 = 0;
        st.field_10 = 0x81;
        st.field_0 = (s32)func_800239A0(0x1FD00FD);
        st.field_4 = func_8001E048(D_80050768->field_108);
        func_80013470(&w->field_50, (Src13470 *)&st);
        func_8001A68C(0x1D, 0);
    } else {
        func_800134F8(&w->field_50, (s32)func_800239A0(0x1FD00A0), 0x81, D_80050700);
    }
}


void func_80014F78(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Halves *pos;
    Sub17D84 *rec;
    s32 n;
    s32 m;
    s32 r;
    Src16198 st;

    rec = (Sub17D84 *)func_80011F5C(D_80050768->field_108);
    pos = &D_80050700;
    n = rec->field_1 - 0xC;
    m = D_8005071C->field_BA5[n];
    st.field_C = *pos;
    st.field_11 = 0;
    st.field_10 = 0x81;
    switch (rec->field_1) {
    case 0xC:
    case 0xD:
    case 0xE:
        r = func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, 0);
        if (r == 0) {
            func_800134F8(&w->field_50, (s32)func_800239A0(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 1) {
            st.field_0 = (s32)func_800239A0(0x1FD00B3);
            r = m + 0x1FD00EC;
            st.field_4 = (s32)func_800239A0(n * 3 + r);
        } else {
            st.field_0 = (s32)func_800239A0(0x1FD00B4);
            st.field_4 = func_8001E048(D_80050768->field_108);
        }
        func_80013470(&w->field_50, (Src13470 *)&st);
        break;
    case 0xF:
    default:
        r = func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, 0);
        if (r == 0) {
            func_800134F8(&w->field_50, (s32)func_800239A0(0x1FD00A0), 0x81, D_80050700);
            goto end;
        }
        if (r == 2) {
            st.field_0 = (s32)func_800239A0(0x1FD00B4);
            st.field_4 = func_8001E048(D_80050768->field_108);
        } else if (D_8005071C->field_BA8 != 0) {
            st.field_0 = (s32)func_800239A0(0x1FD00B5);
            st.field_4 = 0;
        } else {
            st.field_0 = (s32)func_800239A0(0x1FD00B3);
            r = 0x1FD00EC;
            st.field_4 = (s32)func_800239A0(n * 3 + (D_80050760 + r));
        }
        func_80013470(&w->field_50, (Src13470 *)&st);
        break;
    case 0x10:
        r = func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, 0);
        if (r == 0) {
            func_800134F8(&w->field_50, (s32)func_800239A0(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 2) {
            st.field_0 = (s32)func_800239A0(0x1FD00B4);
            st.field_4 = func_8001E048(D_80050768->field_108);
        } else {
            st.field_4 = 0;
            if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
                st.field_0 = (s32)func_800239A0(0x1FD00B7);
            } else {
                st.field_0 = (s32)func_800239A0(0x1FD00B6);
            }
        }
        func_80013470(&w->field_50, (Src13470 *)&st);
        break;
    }
end:
    func_800153F4(a0, 0);
}


void func_80015298(Actor *a0, s32 a1) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 i;
    s32 id;
    s32 k;
    s32 img;
    Halves h;

    for (i = 0; i < 20; i++) {
        img = (s32)func_800239A0(0x1FD0098);
        id = D_8005076C[i];
        k = 0;
        if (id != 0xFF && D_80050720->field_2C[id] != 0) {
            img = func_8001E048(D_80050720->field_2C[id]);
            if (D_80050720->field_52[id] != 0) {
                k = 3;
            }
        }
        h.lo = (i / w->field_8C[1]) * 98 + 0x88;
        h.hi = (i % w->field_8C[1]) * 12 + 0x32;
        func_800134F8(&w->field_0[i], img, a1, h);
        func_8001BE74(w->field_0[i], k);
    }
}


void func_800153F4(Actor *a0, s32 a1) {
    HudSlots153F4 *w = (HudSlots153F4 *)a0->work;
    Halves *h;
    s32 i;
    s32 id;
    s32 v;

    h = (Halves *)func_800239A0(0x5130016);
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            v = func_80021D60();
        } else {
            v = D_8005071C->field_BA5[i];
        }
        if (v != 0) {
            id = v + 0x1FD00EC;
            id = i * 3 + id;
            func_800134F8(&w->slot[i], (s32)func_800239A0(id), a1, *h);
        } else {
            func_8001BB88(&w->slot[i]);
        }
        h++;
    }
}

void func_800154F0(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 i;
    s32 id;
    Halves h;

    i = func_80013A70(w->field_88, w->field_8C);
    func_8001BB88(&w->field_50);
    func_8001BB88(&w->field_54);
    func_8001BB88(&w->field_58);
    id = D_8005076C[i];
    if (id != 0xFF) {
        h.lo = 0xF;
        h.hi = 0x32;
        func_800134F8(&w->field_58, (s32)func_800239A0(D_80050770[i] | 0x1FD0000), 0, h);
        if (D_80050720->field_2C[id] != 0) {
            func_800134F8(&w->field_50, func_8001E084(D_80050720->field_2C[id]), 0x80, D_80050700);
            if (D_80050720->field_52[id] != 0) {
                h.lo = 0x10;
                h.hi = 0xCA;
                func_800134F8(&w->field_54, (s32)func_800239A0(0x1FD0097), 0x80, h);
            }
        }
    }
}


void func_80015668(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Halves h;

    func_8001BB88(&w->field_58);
    func_8001BB88(&w->field_5C);
    h.lo = 0xF;
    h.hi = 0x32;
    func_800134F8(&w->field_58, (s32)func_800239A0(0x1FD009B), 0, h);
    h.lo = 0xF;
    h.hi = 0x47;
    func_800134F8(&w->field_5C, func_8001E048(D_80050768->field_108), 0, h);
    if (w->field_98 == 3) {
        func_800134F8(&w->field_50, (s32)func_800239A0(0x1FD00FB), 0x80, D_80050700);
    }
}


void func_80015770(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 id;
    Src16198 st;

    if (D_8005F704 > 0) {
        id = D_8005076C[func_80013A70(w->field_88, w->field_8C)];
        if (id != 0xFF && func_80012778(D_80050768->field_108, D_80050768->field_10A, id, 0) != 0) {
            st.field_C = D_80050700;
            st.field_11 = 0;
            st.field_10 = 0x81;
            st.field_0 = (s32)func_800239A0(0x1FD00FC);
            st.field_4 = func_8001E048(D_80050720->field_2C[id]);
            func_80013470(&w->field_50, (Src13470 *)&st);
            func_80015298(a0, 0);
            func_8001A68C(0x1D, 0);
            func_800115DC(a0, 3);
        } else {
            func_8001A68C(0x10, 0);
        }
    }
}


void func_8001588C(Actor *a, s16 arg) {
    ActorWork *w = a->work;
    s32 mode;
    s32 k;

    w->field_98 = arg;
    mode = arg;
    if (mode == 2) {
        k = ((u8 *)func_80011F5C(D_80050768->field_108))[1];
        if (k == 11) {
            goto three;
        }
        if (k < 11) {
            goto def;
        }
        if (k < 17) {
            w->field_98 = 4;
            return;
        }
    def:
        w->field_98 = mode;
        return;
    three:
        w->field_98 = 3;
    }
}

void func_80015914(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 r;
    s32 id;
    s32 next;

    D_8005076C = (u8 *)func_800239A0(0x5130014);
    D_80050770 = (u8 *)func_800239A0(0x5130015);
    switch (a0->field_10) {
    case 0:
    default:
        *(Layout8C *)w->field_8C = *(Layout8C *)func_800239A0(0x5130010);
        func_8001C088(w->field_0, 0x22);
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (func_800136E4((s32)a0, &w->field_9C) != 0) {
                break;
            }
            func_80013558(&w->field_70, (Key13558 *)func_800239A0(0x5130011), 2);
            func_80015298(a0, 1);
            if (D_80050768->field_0 & 1) {
                func_800153F4(a0, 1);
            }
            func_80011564(a0);
            break;
        case 1:
            switch (w->field_98) {
            case 1:
                func_800154F0(a0);
                func_80011564(a0);
                break;
            case 2:
                func_80015668(a0);
                func_80014EA4(a0);
                func_800115DC(a0, 3);
                break;
            case 3:
                func_80015668(a0);
                func_80011564(a0);
                break;
            case 4:
                func_80015668(a0);
                func_80014F78(a0);
                func_800115DC(a0, 3);
                break;
            case 5:
switch (func_80022518(0x10)) {
case -1:
id = 0x154;
 next = 3;
break;
case 0:
id = 0x153;
 next = 3;
break;
default:
id = 0x152;
 next = 4;
break;
}
                func_800134F8(&w->field_50, (s32)func_800239A0(id | 0x1FD0000), 0x82, D_80050700);
                func_800115DC(a0, next);
                break;
            }
            break;
        case 2:
            if (func_80013A10((s32)w->field_88, (s32)w->field_8C) == 0) {
                if (D_8005F6F0[0].field_1C > 0) {
                    func_8001A68C(0xB, 0);
                    func_800115C0(a0, 2);
                } else if (w->field_98 == 3) {
                    func_80015770(a0);
                }
            } else {
                func_8001A68C(0xD, 0);
                func_800115DC(a0, 1);
            }
            break;
        case 3:
            switch (a0->field_18) {
            case 0:
                if (func_8001BE08(w->field_50) != 0) {
                    func_80011580(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_14 > 0 || a0->field_20++ >= 0x1F) {
                    func_800115C0(a0, 2);
                }
                break;
            }
            break;
        case 4:
            r = func_800136A4(w->field_50);
            switch (r) {
            case 1:
                func_8001C4F0(0x20);
                D_80050768->field_360 = r;
                func_800115C0(a0, 2);
                break;
            case -1:
                func_800115C0(a0, 2);
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            func_8001C0B0(w->field_0, 0x22);
            func_80011564(a0);
            break;
        case 1:
            if (func_80013714((s32)a0, &w->field_9C) == 0) {
                func_800115C0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80015D30(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 k;
    s32 mask;

    if (w->field_9C == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x5130012);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = func_800239A0(*list);
        mask = 1 << i;
        if (((s32 *)func_800239A0(0x5130013))[w->field_98 - 1] & mask) {
            switch (i) {
            case 0:
            if (w->field_98 == 1 || w->field_98 == 3) {
                func_8001373C(obj, 2, &w->field_88, &w->field_8C);
                func_800137B8(obj, 2, (actor->field_28 >> 2) & 3);
                func_8001D504(obj, 0);
            } else {
                func_8001D504(obj, 2);
            }
            func_8001D5B4(obj, 4, 4, D_80050720->field_26);
            func_8001D5B4(obj, 8, 4, D_80050720->field_24);
            func_8001D5B4(obj, 0x10, 4, D_80050720->field_2A);
            func_8001D5B4(obj, 0x20, 4, D_80050720->field_28);
                break;
            case 1:
            case 3:
                k = 0;
                if (w->field_98 == 5) {
                    k = -1;
                } else if (i == 3) {
                    k = 4;
                }
                func_8001D504(obj, k);
                break;
            default:
                func_8001D504(obj, 0);
                break;
            }
            func_8001D550(obj, 0x1000, w->field_9C);
            func_8001D884((s32)obj);
        }
        list++;
        i++;
    } while (*list != 0);
}


void func_80015F68(Obj16198 *w) {
    Cell16198 *c = w->field_72;
    Cell16198 *q;
    Cell16198 *p;
    s32 i;
    s32 id;

    if (w->field_64 >= 6) {
        goto party;
    }
    if (w->field_64 < 4) {
    party:
        i = 0;
        w->field_6C = func_8002281C();
        p = w->field_72;
        for (; i < w->field_6C;) {
            c->field_0 = D_80050720->field_66[i];
            p->field_2 = 0;
            p->field_4 = i++;
            p++;
            c++;
        }
        w->field_58.field_0[0] = w->field_6C / 8;
        w->field_58.field_0[1] = w->field_6C >= 9 ? 8 : w->field_6C;
    } else {
        w->field_6C = 0;
        q = w->field_72;
        for (i = 1; i < 0x118; i++) {
            id = func_8001E22C(i - 1);
            if (w->field_64 == 4) {
                if (func_8001E0C0(id) == 0x1F) {
                    continue;
                }
            } else if (func_8001E0C0(id) != 0x1F) {
                continue;
            }
            if (D_80050720->field_DD4[id] != 0) {
                c->field_0 = id;
                q->field_2 = D_80050720->field_DD4[id];
                q->field_2 = q->field_2 >= 100 ? 99 : q->field_2;
                q->field_2 = w->field_64 == 5 ? 0 : q->field_2;
                q++;
                c++;
                w->field_6C++;
            }
        }
        w->field_58.field_0[0] = w->field_6C / 8;
        w->field_58.field_0[0] += (u16)w->field_6C % 8 != 0;
        w->field_58.field_0[1] = w->field_6C >= 9 ? 8 : w->field_6C;
    }
    w->field_70 = w->field_6C != 0;
}


void func_80016198(Obj16198 *a0, s32 a1) {
    s32 n;
    s32 i;
    s32 base;
    s32 img;
    Halves h;
    Src16198 st;

    base = a0->field_6E * 8;
    n = a0->field_6C - base;
    n = (n > 16) ? 16 : n;
    for (i = 0; i < 16; i++) {
        func_8001BB88(&a0->field_0[i]);
    }
    for (i = 0; i < n; i++) {
        h.lo = (i / 8) * 113 + 30;
        h.hi = (i % 8) * 12 + 71;
        if (a0->field_72[base + i].field_0 == 0) {
            img = (s32)func_800239A0(0x1FD0098);
        } else {
            img = func_8001E048(a0->field_72[base + i].field_0);
        }
        if (a0->field_72[base + i].field_0 != 0 && a0->field_72[base + i].field_2 != 0) {
            st.field_C = h;
            st.field_10 = a1;
            st.field_11 = 0;
            st.field_0 = (s32)func_800239A0(0x1FD0125);
            st.field_4 = img;
            st.field_8 = a0->field_702[i];
            func_80013AFC(a0->field_702[i], a0->field_72[base + i].field_2, -2);
            func_80013470(&a0->field_0[i], (Src13470 *)&st);
        } else {
            func_800134F8(&a0->field_0[i], img, a1, h);
        }
    }
}

void func_80016394(Actor *a0, Obj16198 *w) {
    Cell16198 *c;
    s32 id;
    s32 snd;
    Src16198 st;

    c = &w->field_72[func_80013A70(w->field_54, w->field_58.field_0)];
    if (c->field_0 == 0) {
        snd = 0x10;
    } else {
        id = c->field_0;
        D_80050720->field_DD4[id] += (D_80050720->field_DD4[id] + 1 < 100);
        func_800227F0(c->field_4);
        st.field_C = D_80050704;
        st.field_10 = 0x81;
        st.field_11 = 0;
        st.field_4 = func_8001E048(id);
        st.field_0 = (s32)func_800239A0(0x1FD0122);
        func_80013470(&w->field_40, (Src13470 *)&st);
        func_80015F68(w);
        func_80016198(w, 0);
        func_800115DC(a0, 2);
        snd = 0xE;
    }
    func_8001A68C(snd, 0);
}

void func_800164AC(Actor *a0, Obj16198 *w) {
    Cell16198 *c;
    s32 n;
    s32 i;
    s32 t;
    s32 snd;
    Src16198 st;

    c = &w->field_72[func_80013A70(w->field_54, w->field_58.field_0)];
    if (c->field_0 == 0) {
        snd = 0x10;
    } else if (func_80013A70(w->field_54, w->field_58.field_0) >= w->field_6C) {
        snd = 0x10;
    } else {
        n = func_8002281C();
        for (i = 0; i < n; i++) {
            if (D_80050720->field_66[i] == 0) {
                break;
            }
        }
        if (i == n) {
            func_800134F8(&w->field_40, (s32)func_800239A0(0x1FD0124), 0x81, D_80050704);
            snd = 0x10;
        } else {
            D_80050720->field_66[i] = c->field_0;
            D_80050720->field_DD4[c->field_0]--;
            st.field_C = D_80050704;
            st.field_10 = 0x81;
            st.field_11 = 0;
            st.field_4 = func_8001E048(c->field_0);
            st.field_0 = (s32)func_800239A0(0x1FD0123);
            func_80013470(&w->field_40, (Src13470 *)&st);
            func_80015F68(w);
            if (w->field_54[0] >= w->field_58.field_0[0]) {
                w->field_54[0] = w->field_58.field_0[0] - 1;
            }
            if (w->field_54[1] >= w->field_58.field_0[1]) {
                w->field_54[1] = w->field_58.field_0[1] - 1;
            }
            t = w->field_58.field_0[0] - 2;
            if (t < 0) {
                t = 0;
            }
            w->field_6E = (w->field_6E < t) ? w->field_6E : t;
            func_80016198(w, 0);
            if (w->field_6C == 0) {
                func_800115DC(a0, 6);
            } else {
                func_800115DC(a0, 2);
            }
            snd = 0xE;
        }
    }
    func_8001A68C(snd, 0);
}


void func_800166FC(Actor *a0, Obj166FC *o) {
    s16 *pos = o->field_54;
    s16 *size = o->field_58;
    s32 id = o->field_72[func_80013A70(pos, size)].field_0;
    s32 r;
    Halves h;

    if (id != 0) {
        r = func_80011FE4(id);
        if (r != 0) {
            goto found;
        }
        h.lo = 0x10;
        h.hi = 0xBA;
        func_800134F8(o->field_44, func_800239A0(0x1FD00A1), 0x81, h);
    }
    func_8001A68C(0x10, 0);
    return;
found:
    D_80050768->field_108 = id;
    D_80050768->field_10A = o->field_72[func_80013A70(pos, size)].field_4;
    o->field_66 = r == 1;
    func_8001A68C(0xE, 0);
    func_80011564(a0);
}

void func_80016834(Actor *a0, GridMenu *m) {
    u16 v = m->field_72[func_80013A70(m->field_54, m->field_58)].field_0;

    if (v == 0) {
        func_8001A68C(0x10, 0);
    } else {
        func_8001A68C(0xE, 0);
        D_80050768->field_108 = v;
        D_80050768->field_10A = func_80013A70(m->field_54, m->field_58);
        func_800115DC(a0, 4);
    }
}

void func_800168F0(Actor *a0, Obj166FC *o) {
    s32 idx;
    u16 id;

    idx = func_80013A70(o->field_54, o->field_58);
    func_8001BB88(&o->field_40);
    func_8001BB88((s32 *)o->field_44);
    id = o->field_72[idx].field_0;
    if (id != 0) {
        if (o->field_64 != 5) {
            func_800134F8(&o->field_40, func_8001E048(id), 0, D_80050708);
        }
        func_800134F8(o->field_44, func_8001E084(id), 0x80, D_80050704);
    }
}

void func_800169D0(Actor *arg0, s16 arg1) {
    arg0->work->field_64 = arg1;
}

void func_800169DC(Actor *a0) {
    Obj16198 *w = (Obj16198 *)a0->work;
    s32 *slot;
    s32 r;
    s32 id;
    Src16198 st;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_58 = *(Box16198 *)func_800239A0(0x5130017);
        func_800226AC();
        w->field_6E = 0;
        w->field_54[1] = 0;
        w->field_54[0] = 0;
        func_80015F68(w);
        func_8001C088(w->field_0, 0x15);
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (func_800136E4((s32)a0, &w->field_68) != 0) {
                break;
            }
            func_80013558(&w->field_4C, (Key13558 *)func_80013AB0(0x5130018, w->field_64 - 1), 2);
            func_80015F68(w);
            func_80016198(w, 1);
            func_80011564(a0);
            break;
        case 1:
            switch (w->field_64) {
            default:
                func_800168F0(a0, (Obj166FC *)w);
                break;
            case 5:
                if (w->field_6C == 0) {
                    id = 0x1FD0151;
                    goto msg;
                }
                func_800168F0(a0, (Obj166FC *)w);
                func_80011564(a0);
                return;
            case 3:
            case 4:
                if (w->field_64 == 4) {
                    if (w->field_6C == 0) {
                        goto full;
                    }
                }
                func_800134F8(&w->field_40, (s32)func_800239A0(((s32)((u16)w->field_64 << 16) >> 16) + 0x1FD011D), 0x80, D_80050704);
                break;
            }
            func_80011564(a0);
            break;
        case 2:
            if (func_80013A10((s32)w->field_54, (s32)w->field_58.field_0) != 0) {
                func_8001A68C(0xD, 0);
                if (w->field_54[0] - w->field_6E >= 2) {
                    w->field_6E = w->field_54[0] - 1;
                    func_80016198(w, 0);
                } else if (w->field_54[0] < w->field_6E) {
                    w->field_6E = w->field_54[0];
                    func_80016198(w, 0);
                }
                func_800115DC(a0, 1);
            } else if (D_8005F6F0[0].field_1C > 0) {
                func_8001A68C(0xB, 0);
                func_800115C0(a0, 2);
            } else if (D_8005F6F0[0].field_14 > 0) {
                switch (w->field_64) {
                case 1:
                    func_800166FC(a0, (Obj166FC *)w);
                    break;
                case 2:
                    func_80016834(a0, (GridMenu *)w);
                    break;
                case 3:
                    func_80016394(a0, w);
                    break;
                case 4:
                    func_800164AC(a0, w);
                    break;
                }
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.field_34;
            switch (a0->field_18) {
            case 0:
            default:
                func_8001C0B0(w->field_0, 0x15);
                func_80011580(a0);
                break;
            case 1:
                if (func_80013714((s32)a0, &w->field_68) != 0) {
                    break;
                }
                func_8001107C(D_80040EFC[w->field_66].field_0, slot, D_80040EFC[w->field_66].field_2);
                func_80011580(a0);
                break;
            case 2:
                if (*slot == 0) {
                    func_800115DC(a0, 0);
                }
                break;
            }
            break;
        case 4:
            st.field_C.lo = 0x10;
            st.field_C.hi = 0xBA;
            st.field_10 = 0x81;
            st.field_11 = 0;
            st.field_4 = func_8001E048(D_80050768->field_108);
            switch (a0->field_18) {
            case 0:
            default:
                st.field_0 = (s32)func_800239A0(0x1FD00B9);
                func_80013470(&w->field_44, (Src13470 *)&st);
                func_80011580(a0);
                break;
            case 1:
                r = func_800136A4(w->field_44);
                switch (r) {
                case 1:
                    func_800227F0(D_80050768->field_10A);
                    st.field_0 = (s32)func_800239A0(0x1FD00BA);
                    func_80013470(&w->field_44, (Src13470 *)&st);
                    func_80015F68(w);
                    func_80016198(w, 0);
                    func_800115DC(a0, 2);
                    break;
                case -1:
                    func_800115DC(a0, 1);
                    break;
                }
                break;
            }
            break;
        case 5:
            switch (a0->field_18) {
            case 0:
                if (func_8001BE08(w->field_40) != 0) {
                    func_80011580(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_14 > 0 || a0->field_20++ >= 0x1F) {
                    func_800115C0(a0, 2);
                }
                break;
            }
            break;
        case 6:
            if (func_8001BE08(w->field_40) == 0) {
                break;
            }
        full:
            id = 0x1FD0127;
        msg:
            func_800134F8(&w->field_40, (s32)func_800239A0(id), 0x81, D_80050704);
            func_800115DC(a0, 5);
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            func_800226AC();
            func_8001C0B0(w->field_0, 0x15);
            func_80011564(a0);
            break;
        case 1:
            if (func_80013714((s32)a0, &w->field_68) == 0) {
                func_800115C0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80016FDC(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 k;
    s32 f;
    u16 m;
    Pair54 tmp;

    if (w->field_68 == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x5130019);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
loop:
        obj = func_800239A0(*list);
        switch (i) {
        case 0:
            tmp = w->field_54;
            f = w->field_54.field_0 + 1;
            func_8001D5B4(obj, 0x10, 2, f ? f : 1);
            func_8001D5B4(obj, 0x20, 2, w->field_58 ? w->field_58 : 1);
            tmp.field_0 = w->field_54.field_0 - w->field_6E;
            func_8001373C(obj, 2, (s32 *)&tmp, &w->field_58);
            func_800137B8(obj, 2, (actor->field_28 >> 2) & 3);
            f = func_80013854(obj, 8, w->field_6E);
            f |= func_80013854(obj, 4, w->field_58 - w->field_6E - 2);
            if (w->field_70 == 0) {
                f |= 0xE;
            }
            func_8001D504(obj, f);
            break;
        case 1:
            if (w->field_64 < 3) {
                m = 2;
            } else {
                m = 0xFFFF;
            }
            func_8001D504(obj, m);
            break;
        case 3:
            m = 0xFFFF;
            if (w->field_64 == 3 || w->field_64 == 5) {
                m = 1;
            } else if (w->field_64 == 4) {
                m = 2;
            }
            func_8001D504(obj, m);
            break;
        }
        func_8001D550(obj, 0x1000, w->field_68);
        list++;
        func_8001D884((s32)obj);
        i++;
    if (*list != 0) goto loop;
}


void func_80017214(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e;
    Rec17214 *g;
    Sel174F8 *d;
    Rec17214 tmp;
    u8 k;
    s32 id;
    s32 n;
    Obj50768 *p;

    e = &w->field_6C[func_80013A70(w->field_50, w->field_54)];
    p = D_80050768;
    do {} while (0);
    n = D_8005F704;
    g = (Rec17214 *)p->field_128;
    if (n > 0) {
        switch (e->field_0) {
        case 0:
        default:
            if (g->field_0 >= 3) {
                id = 0x1FD0111;
            icon:
                func_800134F8(w->field_40, func_800239A0(id), 0x81, D_8005070C);
                break;
            }
            g->field_0 = w->field_1A0[3] != 0 ? 1 : 2;
            d = &w->field_6C[w->field_50[1]];
            d->field_0 = 1;
            d->field_4 = (s32)g;
            d->field_2 = g->field_0;
            id = 0x1FD0110;
            goto swap;
        case 1:
            k = g->field_0;
            tmp = *(Rec17214 *)e->field_4;
            g->field_0 = tmp.field_0;
            tmp.field_0 = k;
            *(Rec17214 *)e->field_4 = *g;
            *g = tmp;
            id = 0x1FD0112;
        swap:
            func_800134F8(w->field_40, func_800239A0(id), 0x81, D_8005070C);
            D_80050768->field_126 = -1;
            func_80017D84((Obj17D84 *)w, 0);
            func_8001A68C(0xE, 0);
            func_800115DC(a0, 4);
            return;
        case 3:
            if (g->field_0 >= 3) {
                id = 0x1FD011E;
                goto icon;
            }
            func_800134F8(w->field_40, func_800239A0(0x1FD011F), 0x81, D_8005070C);
            func_800115DC(a0, 5);
            return;
        case 2:
            break;
        }
        func_8001A68C(0x10, 0);
    }
}

void func_800174F8(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e = &w->field_6C[func_80013A70(w->field_50, w->field_54)];
    s32 k;

    if (D_8005F704 > 0) {
        k = 0x10;
        if (e->field_0 == 1) {
            D_80050768->field_128 = e->field_4;
            D_80050768->field_126 = 0;
            w->field_62 = 3;
            func_800115DC(a0, 3);
            k = 0xE;
        }
        func_8001A68C(k, 0);
    }
}

void func_80017594(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    s32 k = func_80013A70(w->field_50, w->field_54);
    Sel174F8 *e = &w->field_6C[k];
    s32 i;

    if (D_8005F704 > 0) {
        if (e->field_2 != 2) {
            func_8001A68C(0x10, 0);
            return;
        }
        e->field_2 = w->field_19E + 3;
        w->field_1A0[w->field_19E++] = k;
        func_8001A68C(0xE, 0);
        if (w->field_19E < w->field_19C) {
            func_800115DC(a0, 1);
        } else {
            Obj50768 *d;
            D_80050768->field_120 = w->field_19C;
            d = D_80050768;
            i = 0;
            if (w->field_19C > 0) {
                do {
                    d->field_114[i] = w->field_6C[w->field_1A0[i]].field_4;
                } while (++i < w->field_19C);
            }
            w->field_62 = 2;
            func_800115DC(a0, 3);
        }
    }
}

void func_800176D8(Actor *s0) {
    Work176D8 *w = (Work176D8 *)s0->work;
    s16 c = w->field_19E;
    if (c == 0) {
        func_8001A68C(0xB, 0);
        func_800115C0(s0, 2);
    } else {
        s16 idx = (u16)c - 1;
        s16 v;
        w->field_19E = idx;
        v = w->field_1A0[idx];
        ((WorkElem8 *)((u8 *)w + 0x6C))[v].field_2 = 2;
        w->field_1A0[w->field_19E] = 0;
        func_8001A68C(0xB, 0);
        func_800115DC(s0, 1);
    }
}

void func_8001777C(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e = &w->field_6C[func_80013A70(w->field_50, w->field_54)];
    Src16198 st;

    if (D_8005F704 > 0) {
        if (e->field_0 == 1 && func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, e->field_4) != 0) {
            st.field_C = D_8005070C;
            st.field_11 = 0;
            st.field_10 = 0x81;
            st.field_0 = (s32)func_800239A0(0x1FD00FD);
            st.field_4 = func_8001E048(D_80050768->field_108);
            func_80013470(w->field_40, (Src13470 *)&st);
            func_8001A68C(0x1D, 0);
            func_800115DC(a0, 4);
        } else {
            func_8001A68C(0x10, 0);
        }
    }
}

void func_80017884(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Src16198 st;

    st.field_C = D_8005070C;
    st.field_11 = 0;
    st.field_10 = 0x81;
    if (func_80012778(D_80050768->field_108, D_80050768->field_10A, 0, 0) != 0) {
        st.field_0 = (s32)func_800239A0(0x1FD00FD);
        st.field_4 = func_8001E048(D_80050768->field_108);
        func_8001A68C(0x1D, 0);
    } else {
        st.field_0 = (s32)func_800239A0(0x1FD00A0);
        st.field_4 = 0;
    }
    func_80013470(w->field_40, (Src13470 *)&st);
}

void func_80017944(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    s32 k;
    s32 c;

    if (D_8005F704 > 0) {
        k = func_80013A70(w->field_50, w->field_54);
        if ((c = w->field_6C[k].field_0) == 1) {
            D_80050768->field_110 = (u8 *)w->field_6C[k].field_4;
            w->field_62 = 0;
            func_800115DC(a0, 3);
            D_80050768->field_35C = c;
            func_8001A68C(0xE, 0);
        } else {
            func_8001A68C(0x10, 0);
        }
    }
}


void func_800179EC(Wk179EC *w) {
    Row179EC *r = w->rows;
    ElmE620 *el = D_80050720->elems;
    s32 n = 0;
    s32 i;
    s32 ok;
    Row179EC *t;

    t = r;
    for (i = 0; i < 0x26; i++) {
        t->field_2 = 0;
        t->field_0 = 0;
        t++;
    }
    w->field_54 = 1;
    switch (w->field_60) {
    default:
        w->field_56 = func_80022578();
        break;
    case 2:
        w->field_56 = 0x18;
        break;
    case 7:
    case 8:
        if (w->field_1A6 == 0) {
            w->field_56 = func_80022578();
        } else {
            w->field_56 = 0x18;
        }
        if (w->field_60 == 8) {
            w->field_56++;
            n++;
            r->field_0 = 3;
            r->field_4 = 0;
            r->field_2 = 0;
            r++;
            w->field_52++;
        }
        break;
    case 6:
        w->field_56 = D_80050768->field_120;
        for (i = 0; i < D_80050768->field_120; i++) {
            r->field_0 = 1;
            r->field_4 = D_80050768->field_114[i];
            r->field_2 = i + 3;
            r++;
        }
        return;
    }
    for (i = 0; i < 0x24; i++, el++) {
        if (el->field_0 != 0) {
            ok = 0;
            switch (w->field_60) {
            default:
                if (el->field_0 >= 2) ok = -1;
                break;
            case 5:
                if (el->field_0 >= 2 && (s16)el->field_16 != 0) ok = -1;
                break;
            case 7:
            case 8:
                if (w->field_1A6 != 0) {
                    if (el->field_0 == 1) ok = -1;
                } else {
                    if (el->field_0 >= 2) ok = -1;
                }
                break;
            case 2:
                if (el->field_0 == 1) ok = -1;
                break;
            }
            if (ok) {
                r->field_0 = 1;
                r->field_4 = el;
                r->field_2 = (w->field_60 == 5) ? 2 : el->field_0;
                r++;
                n++;
            }
        }
    }
    if (D_80050768->field_0 & 1) {
        if (w->field_60 != 2 && w->field_60 != 5) {
            r = &w->rows[w->field_56 - 1];
            for (i = 0; i < D_8005071C->field_BA8; i++, r--) {
                r->field_0 = 2;
                r->field_1 = D_8005071C->field_BA9[i];
            }
        }
    }
    if (w->field_60 == 5) {
        w->field_56 = n;
        if (n < 4) {
            w->field_19C = n;
        } else {
            w->field_19C = 3;
        }
        w->field_19E = 0;
        w->field_1A4 = 0;
        w->field_1A2 = 0;
        w->field_1A0 = 0;
    }
}


void func_80017D84(Obj17D84 *a0, s32 a1) {
    s32 i;
    Ent17D84 *rec;
    Src13470 st;

    st.field_4 = 0;
    st.field_10 = a1;
    st.field_11 = 0;
    for (i = 0; i < 16; i++) {
        func_8001BB88(&a0->field_0[i]);
    }
    rec = &a0->field_6C[a0->field_68];
    for (i = 0; i < 4; i++) {
        switch (rec->field_0) {
        case 0:
            break;
        case 1:
            st.field_C = 109;
            st.field_E = i * 33 + 62;
            st.field_0 = (s32)func_800239A0(0x1FD0082);
            func_80013470(&a0->field_0[i * 4], &st);
            st.field_C = 208;
            st.field_E = i * 33 + 62;
            st.field_0 = (s32)func_800239A0(0x1FD00BB);
            func_80013470(&a0->field_0[i * 4 + 1], &st);
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)rec->field_4->field_4C;
            func_80013470(&a0->field_0[i * 4 + 2], &st);
            st.field_C = 208;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)func_8001E758(rec->field_4->field_1);
            func_80013470(&a0->field_0[i * 4 + 3], &st);
            break;
        case 2:
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)func_800239A0(rec->field_1 + 0x1FD00F5);
            func_80013470(&a0->field_0[i * 4 + 2], &st);
            break;
        case 3:
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)func_800239A0(0x1FD0114);
            func_80013470(&a0->field_0[i * 4 + 2], &st);
            break;
        }
        rec++;
    }
}

void func_80017F6C(Actor *a, s16 mode) {
    ModeWork17F6C *w = (ModeWork17F6C *)a->work;

    w->mode = mode;
    if (mode == 3 && ((Rec11F5C *)func_80011F5C(D_80050768->field_108))->field_0 == 2) {
        w->mode = 4;
    }
    w->flag6A = 1;
    switch (w->mode) {
    default:
        w->flag6A = 1;
        break;
    case 4:
    case 6:
        w->flag6A = 0;
        break;
    case 7:
    case 8:
        { s16 t = D_80050768->field_124 - 7; w->parity = (w->mode + t) & 1; }
        break;
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80018048);

void func_800188BC(Actor *actor) {
    Wk188BC *w = (Wk188BC *)actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 j;
    s32 f;
    u16 m;
    Row188BC *r;
    Part188BC *e;
    Pair54 tmp;

    if (w->field_64 == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x513001B);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = func_800239A0(p[i]);
        switch (i) {
        case 0:
            if (w->field_6A != 0) {
            tmp = w->field_50;
            tmp.field_2 = w->field_50.field_2 - w->field_68;
            func_8001373C(obj, 2, (s32 *)&tmp, &w->field_54);
            func_800137B8(obj, 2, (actor->field_28 >> 2) & 3);
            {
                s32 fl = (w->field_68 < 1) << 2;
                if (w->field_56 - w->field_68 - 4 <= 0) {
                    fl |= 8;
                }
                func_8001D504(obj, fl);
            }
            func_8001D5B4(obj, 0x10, 2, w->field_50.field_2 + 1);
            func_8001D5B4(obj, 0x20, 2, w->field_56);
            } else {
                func_8001D504(obj, -1);
            }
            break;
        default:
            f = w->field_68 - 1;
            r = &w->rows[f + i];
            j = i - 1;
            if (j >= w->field_56) {
                func_8001D504(obj, -1);
                break;
            }
            func_8001D504(obj, 0);
            f = 2;
            if (w->field_6A != 0 && j == w->field_50.field_2 - w->field_68) {
                f = 1;
            }
            switch (r->field_0) {
            case 0:
                func_8001D504(obj, f | 0xFE4);
                break;
            case 1:
                e = (Part188BC *)r->field_4;
                func_8001D504(obj, f | D_80040F40[r->field_2 - 1]);
                func_8001D5B4(obj, 0x20, 3, e->field_14);
                func_8001D5B4(obj, 0x40, 3, e->field_16);
                func_8001D5B4(obj, 0x80, 3, e->field_18);
                func_8001D5B4(obj, 0x100, 3, e->field_1A);
                break;
            case 2:
            case 3:
                func_8001D504(obj, -5);
                break;
            }
            break;
        case 5:
            break;
        case 6:
            m = 0xFFFF;
            if (w->field_60 == 7 || w->field_60 == 8) {
                m = 1;
                if (w->field_1A6 != 0) {
                    m = 2;
                }
            }
            func_8001D504(obj, m);
            break;
        }
        func_8001D550(obj, 0x1000, w->field_64);
        func_8001D884((s32)obj);
        i++;
    } while (p[i] != 0);
}


void func_80018BF8(Actor *a0, s16 a1) {
    Wk18BF8 *w;
    u8 *p;
    s32 i;
    Blk16 *b;
    s32 *q;

    w = (Wk18BF8 *)a0->work;
    w->field_7C = a1;
    p = D_80050768->field_110;
    w->field_84 = p;
    a0->field_C = p[1];
    func_80020C40((ContC40 *)a0, w->field_B0, w->field_BC);
    w->field_C0 = func_8001E704(a0->field_C);
    w->field_C4 = func_8001E728(a0->field_C, 0);
    func_8001FDBC(a0, w->field_C0)->field_3C = 3;
    func_80023BF4(w->field_C0);
    func_80023BF4(w->field_C4);
    w->field_C8 = 0;
    w->field_14C = 0;
    w->field_CC = D_80040F64;
    func_8002B424(0, (Coord1F668 *)&w->field_E8);
    w->field_148 = 1;
    w->field_142 = 11;
    w->field_140 = 0;
    w->field_144 = 0;
    w->field_138 = -0xE3;
    b = (Blk16 *)func_800239A0(0x513001F);
    q = (s32 *)func_800239A0(0x5130020);
    for (i = 0; i < 3; i++) {
        func_8002B564(i, &b[i]);
    }
    func_8002BB54(q[0], q[1], q[2]);
    func_8002BAD4(0);
}


void func_80018D78(Actor *a) {
    Wk18D78 *w = (Wk18D78 *)a->work;
    Halves *h;
    Rec18D78 *r;
    u8 **q;
    s32 i;
    Actor *t[1];
    s16 *p;
    s16 *s;
    Elm6F0 *d;

    switch (a->field_10) {
    default:
    case 0:
        w->blk = *(Blk18D78 *)func_800239A0(0x513001C);
        func_8001C088(w, 0x1B);
        func_8002B334(-0xA0, 0xB4);
        t[0] = a;
        func_8001107C(6, (s32 *)a->u34.field_34, (s32)t);
        a->field_30 = 0;
        func_80011544(a);
        break;
    case 1:
        switch (a->field_14) {
        default:
        case 0:
            h = (Halves *)func_800239A0(0x513001E);
            (*(Actor **)a->u34.field_34)->field_3C->field_3C = 4;
            if (func_800136E4((s32)a, &w->field_80) != 0) {
                break;
            }
            func_80013558((s32 *)w, (Key13558 *)func_80013AB0(0x513001D, 0), 1);
            r = w->field_84;
            func_800134F8(&w->field_50, (s32)r->field_4C, 0x81, h[0]);
            w->field_88 = func_8001E758(r->field_1);
            w->field_8C = func_800239A0(((s32 (*)(s32))func_8001D934)(r->field_1) + 0x1FD00C3);
            w->field_90 = func_800239A0(((s32 (*)(s32))func_8001D958)(r->field_1) + 0x1FD00C6);
            w->field_94 = func_800239A0(((s32 (*)(s32))func_8001D980)(r->field_1) + 0x1FD00CA);
            q = w->field_98;
            for (i = 0; i < 2; i++) {
                if (r->field_47[i] != 0) {
                    *q++ = func_8001E758(r->field_47[i]);
                }
            }
            *q = 0;
            func_8001361C(&w->field_54, &h[1], (s32 *)&w->field_88, 1);
            func_80011564(a);
            break;
        case 1:
            w->field_C8 = 1;
            func_8002B334(-0xA0, w->field_138[0] * 80 / 682 + 180);
            func_80011564(a);
            break;
        case 2:
            func_800136E4((s32)a, &w->field_14C);
            p = w->field_138;
            s = w->field_140;
            a->field_30 = 1;
            p[1] += s[1];
            if (D_8005F6F0[0].field_4 != 0) {
                s[1] = (s[1] - 5 < -0x22) ? -0x22 : s[1] - 5;
            }
            if (D_8005F6F0[0].field_0 != 0) {
                s[1] = (s[1] + 5 >= 0x23) ? 0x22 : s[1] + 5;
            }
            if (D_8005F6F0[0].field_C != 0) {
                p[0] = (p[0] + 0xB > 0) ? 0 : p[0] + 0xB;
            }
            if (D_8005F6F0[0].field_8 != 0) {
                p[0] = (p[0] - 0xB < -0x2AA) ? -0x2AA : p[0] - 0xB;
            }
            func_8002B334(-0xA0, p[0] * 80 / 682 + 180);
            d = D_8005F6F0;
            if (d->field_1C > 0 || d->field_10 > 0) {
                func_800115C0(a, 2);
                if (d->field_10 > 0) {
                    D_80050768->field_35E = -1;
                    func_8001A68C(0xE, 0);
                } else {
                    D_80050768->field_35E = 0;
                    func_8001A68C(0xB, 0);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->field_14) {
        default:
        case 0:
            func_8001C0B0(w, 0x1B);
            func_80011564(a);
            break;
        case 1:
            func_80013714((s32)a, &w->field_14C);
            if (func_80013714((s32)a, &w->field_80) == 0) {
                func_8002B334(0, 0);
                func_800115C0(a, 3);
            }
            break;
        }
        break;
    }
}


/* View of Actor.work used by func_80019214 (fields 0x80..0x14C). */
typedef struct {
    u8 _pad00[0x80];
    /* 0x80 */ s32 field_80;
    /* 0x84 */ s32 *field_84;
    u8 _pad88[0xB0 - 0x88];
    /* 0xB0 */ s32 field_B0;
    /* 0xB4 */ s32 field_B4;
    /* 0xB8 */ s32 field_B8;
    u8 _padBC[0xC0 - 0xBC];
    /* 0xC0 */ s32 field_C0;
    u8 _padC4[0xC8 - 0xC4];
    /* 0xC8 */ s32 field_C8;
    /* 0xCC */ s32 field_CC;
    /* 0xD0 */ s32 field_D0;
    /* 0xD4 */ s32 field_D4;
    /* 0xD8 */ s32 field_D8;
    /* 0xDC */ s32 field_DC;
    /* 0xE0 */ s32 field_E0;
    /* 0xE4 */ s32 field_E4;
    /* 0xE8 */ s32 field_E8;
    /* 0xEC */ s32 field_EC;
    u8 _padF0[0x100 - 0xF0];
    /* 0x100 */ s32 field_100;
    /* 0x104 */ s32 field_104;
    /* 0x108 */ s32 field_108;
    u8 _pad10C[0x138 - 0x10C];
    /* 0x138 */ s32 field_138;
    u8 _pad13C[0x148 - 0x13C];
    /* 0x148 */ s32 field_148;
    /* 0x14C */ s32 field_14C;
} Wk19214;

/* Record reached through Wk19214.field_84. */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 field_D;
    u8 _padE;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
} Rec19214;

/* Node reached through Actor.u38.ptr38. */
typedef struct {
    u8 _pad00[0x58];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
} Nd19214;

/* Stack context passed to func_8002C164. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 *field_1C;
} Ctx19214;

extern s32 func_8002C164(Ctx19214 *);

void func_80019214(Actor *actor) {
    Wk19214 *work;
    Rec19214 *rec;
    s32 *list;
    s32 *p;
    void *obj;
    Nd19214 *node;
    Ctx19214 ls;

    work = (Wk19214 *)actor->work;
    if (work->field_80 == 0) {
        goto Ltail;
    }
    p = (s32 *)func_800239A0(0x5130021);
    rec = (Rec19214 *)work->field_84;
    if (*p == 0) {
        goto Ltail;
    }
    list = p;
    do {
        obj = func_800239A0(*list);
        list++;
        func_8001D5B4(obj, 0x2, 3, rec->field_14);
        func_8001D5B4(obj, 0x4, 3, rec->field_16);
        func_8001D5B4(obj, 0x8, 3, rec->field_18);
        func_8001D5B4(obj, 0x10, 3, rec->field_1A);
        func_8001D5B4(obj, 0x20, 2, rec->field_D);
        func_8001D5B4(obj, 0x40, 3, rec->field_1C);
        func_8001D5B4(obj, 0x80, 3, rec->field_1E);
        func_8001D5B4(obj, 0x100, 3, rec->field_20);
        func_8001D5B4(obj, 0x200, 8, rec->field_10);
        func_8001D5B4(obj, 0x400, 8, func_8001E984(rec->field_D, rec->field_F, rec->field_10));
        func_8001D550((Ent1D550 *)obj, 0x1000, work->field_80);
        func_8001D884((s32)obj);
    } while (*list != 0);

Ltail:
    work->field_148 = 0;
    func_8002D744(&work->field_138, &work->field_EC);
    work->field_100 = work->field_B0;
    work->field_104 = work->field_B4;
    work->field_108 = work->field_B8;
    work->field_E8 = 0;
    ls.field_0 = work->field_CC;
    ls.field_4 = work->field_D0;
    ls.field_8 = work->field_D4;
    ls.field_C = work->field_D8;
    ls.field_10 = work->field_DC;
    ls.field_14 = work->field_E0;
    ls.field_18 = 0;
    ls.field_1C = &work->field_E8;
    func_8002B544(work->field_E4);
    func_8002C164(&ls);
    if (work->field_C8 == 0) {
        return;
    }
    if (work->field_14C == 0) {
        return;
    }
    if (work->field_C8 == 1) {
        func_8001F1A8(actor, 0);
        work->field_C8 = work->field_C8 + 1;
    }
    node = (Nd19214 *)actor->u38.ptr38;
    node->field_58 = work->field_14C;
    node->field_5C = work->field_14C;
    node->field_60 = work->field_14C;
    func_8001FDBC(actor, work->field_C0);
    func_8001F320(actor);
    func_80020920(actor);
    func_800200D0(actor);
    func_80020510(actor, 0);
}

void func_800194C8(a)
Actor194C8 *a;
{
    u8 *tbl;
    s32 i;
    s32 r, c;
    u8 *q;
    void *base;

    tbl = a->field_118;

    for (i = 3; i >= 0; i--) {
        a->records[i].count = 0;
    }

    for (i = 0; i < 0xC; i++) {
        q = tbl + i;
        if (q[0x22] == 0) continue;
        r = func_8001EE34(q[0x22]);
        c = a->records[r].count;
        a->records[r].arr[c] = q[0x22];
        a->records[r].count = (u16)a->records[r].count + 1;
    }

    for (i = 0; i < 4; i++) {
        base = func_800239A0(0x5130022);
        a->block64[i] = *(Blk12 *)((u8 *)base + i * 0xC);
        a->field_94[i] = 0;
        a->slot54[i].v = 0;
        *(s16 *)((u8 *)&a->block64[i] + 2) = a->records[i].count;
    }
}

void func_80019614(Actor194C8 *w, s32 arg1) {
    Src16198 st;
    s32 i;
    s32 ch;
    s32 n;
    s32 j;
    s32 k;
    s32 d0;
    s32 d;
    s32 f;
    s32 m;

    for (i = 6; i < 18; i++) {
        func_8001BB88(&w->field_0[i]);
    }
    st.field_4 = 0;
    st.field_10 = arg1;
    for (ch = 0; ch < 4; ch++) {
        st.field_C = ((Halves *)func_800239A0(0x5130025))[ch];
        d0 = w->field_94[ch];
        d = w->records[ch].count - d0;
        n = 3;
        if (d < 4) {
            n = d;
        }
        for (j = 0; j < n; j++) {
            f = 0;
            if (w->field_114 != ch) {
                f = 1;
            } else if (w->slot54[ch].field_2 != j + d0) {
                f = 1;
            }
            st.field_11 = f;
            st.field_0 = func_8001ED84(w->records[ch].arr[j + d0]);
            m = j + 6;
            func_80013470(&w->field_0[ch * 3 + m], (Src13470 *)&st);
            st.field_C.hi += 11;
        }
        func_8001BE74(w->field_0[ch + 2], w->field_114 != ch);
    }
}


void func_800197FC(Actor *arg0, s16 arg1) {
    arg0->work->field_A4 = arg1;
}

void func_80019808(Actor *a0) {
    Actor194C8 *w = (Actor194C8 *)a0->work;
    Halves h;
    Src16198 st;
    s32 i;
    s32 k;
    s32 id;
    s32 t;
    s32 j;
    s32 n;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_118 = D_80050768->field_110;
        func_800194C8(w);
        w->field_114 = 0;
        func_8001C088(&w->field_0, 0x15);
        func_80011544(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (func_800136E4((s32)a0, &w->field_A8) != 0) {
                break;
            }
            func_80013558(&w->field_0, (Key13558 *)func_80013AB0(0x5130024, 0), 1);
            func_80019614(w, 1);
            h.lo = 0x13;
            h.hi = 0x32;
            func_800134F8(&w->field_50, (s32)&w->field_118[0x4C], 1, h);
            func_80011564(a0);
            break;
        case 1:
            i = w->field_114;
            k = func_80013A70(&w->slot54[i].v, (s16 *)w->block64[i].data);
            func_8001BB88(&w->field_48);
            func_8001BB88(&w->field_4C);
            if (k < w->records[i].count) {
                id = w->records[i].arr[w->slot54[i].field_2];
                st.field_C = D_80050714;
                st.field_10 = 0x80;
                st.field_11 = 0;
                st.field_0 = func_8001EDD4(id);
                func_80013470(&w->field_48, (Src13470 *)&st);
                st.field_C.hi = 0xCA;
                st.field_0 = (s32)func_800239A0(0x1FD0150);
                func_80013AFC(w->field_11C, func_8001EE80(id), -4);
                st.field_4 = (s32)w->field_11C;
                func_80013470(&w->field_4C, (Src13470 *)&st);
            }
            func_80011564(a0);
            break;
        case 2:
            t = D_8005F6F0[0].field_4;
            if (t > 0 || D_8005F6F0[0].field_0 > 0) {
                n = w->field_114;
                if (t > 0) {
                    n--;
                } else {
                    n++;
                }
                w->field_114 = n & 3;
                func_8001A68C(0xD, 0);
                func_80019614(w, 0);
                func_800115DC(a0, 1);
            } else {
                j = w->field_114;
                if (func_80013A10((s32)&w->slot54[j], (s32)&w->block64[j]) != 0) {
                    func_80013A30(&w->field_94[j], w->slot54[j].field_2, 3);
                    func_80019614(w, 0);
                    func_8001A68C(0xD, 0);
                    func_800115DC(a0, 1);
                } else if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_10 > 0) {
                    func_800115C0(a0, 2);
                    if (D_8005F6F0[0].field_10 > 0) {
                        D_80050768->field_35E = -1;
                        func_8001A68C(0xE, 0);
                    } else {
                        D_80050768->field_35E = 0;
                        func_8001A68C(0xB, 0);
                    }
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            func_8001C0B0(&w->field_0, 0x15);
            func_80011564(a0);
            break;
        case 1:
            if (func_80013714((s32)a0, &w->field_A8) == 0) {
                func_800115C0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80019BF4(Actor *actor) {
    Wk19BF4 *w = (Wk19BF4 *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u16 v;
    Pair54 tmp;

    if (w->field_A8 == 0) {
        return;
    }
    p = (s32 *)func_800239A0(0x5130026);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = func_800239A0(p[i]);
        switch (i) {
        case 0:
            k = w->field_114;
            v = D_80040F98[k];
            if (w->field_AC[k].field_0 != 0) {
                tmp = w->field_54[k];
                tmp.field_2 = w->field_54[k].field_2 - w->field_94[k];
                func_8001373C(obj, 0x4000, (s32 *)&tmp, &w->field_64[k].field_0);
                func_800137B8(obj, 0x4000, (actor->field_28 >> 2) & 3);
            } else {
                v |= 0x4000;
            }
            func_8001D504(obj, v);
            break;
        case 1:
            m = 0xFFFFF;
            for (j = 0; j < 4; j++) {
                if (w->field_94[j] != 0) {
                    if (w->field_114 == j) {
                        m -= 1 << (j * 4 + 1);
                    } else {
                        m -= 1 << (j * 4 + 2);
                    }
                }
                if (w->field_64[j].field_2 - w->field_94[j] >= 4) {
                    if (w->field_114 == j) {
                        m -= 1 << (j * 4 + 3);
                    } else {
                        m -= 1 << (j * 4 + 4);
                    }
                }
            }
            func_8001D504(obj, m);
            break;
        }
        func_8001D550(obj, 0x1000, w->field_A8);
        func_8001D884((s32)obj);
        i++;
    } while (p[i] != 0);
}


void func_80019E40(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void func_80019E50(Actor *a0) {
    Ent19E50 *p;
    s32 *slot;
    s32 end = -1;
    s32 *s;

    if (a0->field_10 != 0) {
        return;
    }
    s = (s32 *)a0->u34.field_34;
    p = (Ent19E50 *)func_80023A08(a0->work->field_0);
    slot = s;
loop:
    if (p->field_0 == end) {
        goto done;
    }
    func_8001107C(p->field_0, slot, (s32)&p->field_10);
    slot++;
    p = (Ent19E50 *)((u8 *)p + p->field_C);
    goto loop;
done:
    func_80011544(a0);
}


void func_80019EE0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_80019EE8(Actor *a0) {
    s32 v1 = a0->field_10;
    u16 *a1 = (u16 *)&a0->work->field_0;
    switch (v1) {
    case 1:
        if (a0->field_14 == 0 || a0->field_14 != v1) {
            u16 nv = *a1 + 0x555;
            *a1 = nv;
            if ((s16)nv >= 0x1000) {
                *a1 = 0x1000;
                func_80011564(a0);
            }
        }
        break;
    case 0:
        func_80011544(a0);
        break;
    case 2: {
        s16 nv = *a1 - 0x555;
        *a1 = nv;
        if (nv <= 0) {
            *a1 = 0;
            func_80011544(a0);
        }
        break;
    }
    }
}

void func_80019FB4(Actor *arg0) {
    ActorWork *w = arg0->work;
    void *e = func_800239A0(D_80040FD0[arg0->field_8]);
    func_8001D550(e, 0x1000, *(s16 *)w);
    func_8001D884((s32)e);
}

void func_8001A01C(void) {
    s32 i;
    Ent54C48 *e;
    u32 n;
    u32 k;
    s32 *src;
    s32 *dst;
    s32 p;
    s32 j;

    for (i = 0; i < 3; i++) {
        e = &D_80054C48[i];
        switch (e->field_4) {
        case 0:
            break;
        case 1:
            if (e->field_0 == 0) {
                e->field_4 = 0;
                break;
            }
            e->field_20 = D_80041194[e->field_0]->field_0 >> 16;
            e->field_24 = D_80041194[e->field_0]->field_4 >> 16;
            func_80023BF4(e->field_24);
            e->field_4++;
            break;
        case 2:
            if (func_80023B70(e->field_24) == 3) {
                src = (s32 *)func_80023DB0(e->field_24);
                n = D_800411FC[i];
                dst = e->field_28;
                if ((u32)src + n > 0x801FFFFF) {
                    n = 0x801FFFFC - (u32)src;
                }
                n >>= 2;
                for (k = 0; k < n; k++) {
                    *dst++ = *src++;
                }
                e->field_4++;
            }
            break;
        case 3:
            func_80023BF4(e->field_20);
            e->field_4++;
            break;
        case 4:
            e->field_8 = func_80039A44(func_800239E4(D_80041194[e->field_0]->field_4, e->field_28), i);
            e->field_4++;
            break;
        case 5:
            if (func_80023B70(e->field_20) == 3) {
                func_80023E78(e->field_20);
                e->field_8 = func_80039F44((s32)func_800239A0(D_80041194[e->field_0]->field_0), e->field_8);
                e->field_4++;
            }
            break;
        case 6:
            e->field_A = 0;
            e->field_4++;
        case 7:
            j = e->field_A;
            p = *(j + D_80041194[e->field_0]->field_8);
            if (p != 0) {
                e->field_C[j] = func_80032954(func_800239E4(p, e->field_28), e->field_8, 0x10);
                e->field_A++;
            } else {
                e->field_4++;
            }
            break;
        default:
            if (func_8003A004(0)) {
                func_80023EB8(e->field_20);
                e->field_4 = 0;
            }
            break;
        }
    }
}


s32 func_8001A300(void) {
    s32 found = 0;
    s32 i = 0;
    Ent54C48 *p = D_80054C48;
    for (; i < 3; i++, p++) {
        if (p->field_4 != 0) found = 1;
        if (found) break;
    }
    return found;
}

void func_8001A340(void) {
    Ent54C48 *p;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 3; i++) {
        p = &D_80054C48[i];
        if (p->field_8 != -1) {
            for (j = 0; j < p->field_A; j++) {
                for (k = 0; k < 0x10; k++) {
                    func_8003569C(p->field_C[j], k);
                }
            }
        }
    }
    func_80035F04(0);
    D_80050718 = -1;
}

void func_8001A410(s32 id) {
    s32 i;
    s32 j;
    s32 k;

    if (id != -1) {
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        if (D_80054C48[i].field_4 == 0) {
            func_8003569C(D_80054C48[i].field_C[j], k);
        }
        if (D_80050718 == id) {
            D_80050718 = -1;
        }
    }
}

void func_8001A4A8(s32 idx) {
    s32 i;
    s32 k;

    if (D_80054C48[idx].field_8 == -1) {
        return;
    }
    for (i = 0; i < D_80054C48[idx].field_A; i++) {
        for (k = 0; k < 0x10; k++) {
            func_8003569C(D_80054C48[idx].field_C[i], k);
        }
        func_80032844(D_80054C48[idx].field_C[i]);
    }
    func_80039994(D_80054C48[idx].field_8);
    D_80054C48[idx].field_4 = 0;
    D_80054C48[idx].field_0 = -1;
    D_80054C48[idx].field_A = 0;
    D_80054C48[idx].field_8 = -1;
}

void func_8001A5F4(s32 idx, s32 v) {
    Ent54C48 *e = &D_80054C48[idx];

    if (e->field_0 != v) {
        func_8001A4A8(idx);
        e->field_4 = 1;
        e->field_0 = v;
        if (D_80050718 != -1 && idx == ((D_80050718 & 0xF00) >> 8)) {
            func_8001A410(D_80050718);
        }
    }
}

void func_8001A68C(s32 id, s32 set) {
    s32 k;
    s32 i;
    s32 j;
    if (D_80050718 != id) {
        if (set != 0 && D_80050718 != -1) {
            func_8001A410(D_80050718);
        }
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        func_8003569C(D_80054C48[i].field_C[j], k);
        func_80035C4C(D_80054C48[i].field_C[j], k, 0x7F, 0x7F);
        func_80034E04(D_80054C48[i].field_C[j], k, 1, 1);
        if (set != 0) {
            D_80050718 = id;
        }
    }
}

/* File-local view of an Ent54C48 element with the fields func_8001A75C stamps. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    u8 _padC[0x28 - 0xC];
    /* 0x28 */ s32 field_28;
} Ew54C48; /* 0x2C */

extern u8 D_80050A48;

extern void func_800357E4(void *, s16, s16);
extern void func_80035A04(s32);
extern void func_800352C4();
extern void func_80035024(s16, s16);
extern void func_80034F64(s8, s8, s8);
extern void func_800356D4(s8, s16, s16);
extern s16 func_80036474(s16);
extern void func_800363E4(s16, s16);
extern void func_80036574();
extern s32 func_80022F3C(s32, s32);
extern void func_8001A5F4(s32, s32);
extern void func_80023C74();

void func_8001A75C(void) {
    s32 v0;
    s32 i;
    Ew54C48 *e;

    func_800357E4(&D_80050A48, 6, 0x10);
    func_80035A04(0x1000);
    func_800352C4();
    func_80035024(0x7F, 0x7F);
    func_80034F64(0, 0, 1);
    func_800356D4(0, 0x7F, 0x7F);
    func_80036474(3);
    func_800363E4(0, 0);
    func_80036574();

    v0 = func_80022F3C(D_800411FC[0] + D_800411FC[1] + D_800411FC[2], 4);
    e = (Ew54C48 *)D_80054C48;
    e[0].field_28 = v0;
    v0 += D_800411FC[0];
    e[1].field_28 = v0;
    v0 += D_800411FC[1];
    e[2].field_28 = v0;
    for (i = 0; i < 3; i++) {
        e[i].field_4 = 0;
        e[i].field_0 = -1;
        e[i].field_A = 0;
        e[i].field_8 = -1;
    }

    func_8001A5F4(0, 1);
    do {
        func_8001A01C();
        func_80023C74();
    } while (D_80054C48[0].field_4 != 0);

    func_8001A5F4(1, 0xE);
    do {
        func_8001A01C();
        func_80023C74();
    } while (D_80054C48[1].field_4 != 0);
}

void func_8001A8BC(void) {
    D_80050774 = D_80050718;
}


void func_8001A8D0(void) {
    func_8001A68C(D_80050774, 1);
}


void func_8001A8F4(s32 arg0) {
    D_80054CD0.data[D_80054CD0.count] = arg0;
    D_80054CD0.count = D_80054CD0.count + 1;
}

s32 func_8001A920(void) {
    if (D_80054CD0.count == 0) {
        return 0;
    }
    D_80054CD0.count = D_80054CD0.count - 1;
    return D_80054CD0.data[D_80054CD0.count];
}

extern Elem20 *func_8001CB80(s32);
extern void func_8001107C(u32, s32 *, s32);

void func_8001A958(Actor *a0) {
    if (a0->field_10 != 0) {
        return;
    }
    func_8001CB80(0x13A0000);
    if ((D_8005F788[0] & 0xF00) != 0x500) {
        func_8001CB80(0x1100000);
        func_8001107C(0xA, a0->u34.field_34, 0);
    }
    func_80011544(a0);
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8001A9C8);

void func_8001BB88(s32 *slot) {
    Ent11440 *e;
    Actor *a;
    s32 i;
    Rec34 *r;
    Actor **q;

    if (*slot == -1) {
        return;
    }
    e = func_80011510(9, -1, -1);
    if (e != 0) {
        i = *slot;
        r = &e->field_2C[i];
        q = &e->field_34[i];
        r->field_0 = 0;
        a = q[1];
        if (a != 0) {
            func_800115C0(a, 3);
        }
        *slot = -1;
    }
}


void func_8001BC24(void *arg0, Arg1BC24 *arg1) {
    SrcBC24 *src = (SrcBC24 *)arg1;
    Ent11440 *r;
    Rec34 *base;
    Rec34 *p;
    Rec34 *rec;
    s32 i;

    r = func_80011510(9, -1, -1);
    if (r == 0) {
        return;
    }
    i = 0;
    base = r->field_2C;
    func_8001BB88(arg0);

    for (p = base; i < 0x32; i++, p++) {
        if (p->field_0 == 0) {
            break;
        }
    }

    if (src->field_C == 0) {
        if (src->field_0 != 0) {
            src->field_C = 9;
        } else {
            src->field_C = 7;
        }
    }
    if (src->field_10 == 0) {
        if (src->field_0 != 0) {
            src->field_10 = 0xF;
        } else {
            src->field_10 = 0xA;
        }
    }

    rec = &base[i];
    rec->field_0 = 1;
    rec->field_1 = *(u8 *)&src->field_0;
    rec->field_2 = *(u8 *)&src->field_4;
    rec->field_8 = src->field_14;
    rec->field_1C = src->field_8 - 0xA0;
    rec->field_1E = src->field_A - 0x78;
    rec->field_3 = *(u8 *)&src->field_C;
    rec->field_4 = *(u8 *)&src->field_10;
    rec->field_6 = *(u16 *)&src->field_18;
    rec->field_C = src->field_1C;
    rec->field_10 = src->field_20;
    rec->field_14 = src->field_24;
    rec->field_18 = src->field_28;
    rec->field_20 = *(u8 *)&src->field_4;
    rec->field_21 = *(u8 *)&src->field_18;
    rec->field_22 = 0;
    rec->field_23 = 0;
    rec->field_24 = 0;
    rec->field_25 = 0;
    rec->field_27 = 0;
    rec->field_26 = 0;
    rec->field_28 = 0;
    rec->field_29 = 0;
    rec->field_2A = 0;
    rec->field_2B = 0;
    rec->field_2C = 0;
    rec->field_2D = 0;
    rec->field_2E = 0;
    rec->field_2F = 0;
    rec->field_30 = 0;
    rec->field_31 = 0;

    *(s32 *)arg0 = i;
}

s32 func_8001BE08(s32 id) {
    Ent11440 *p;

    if (id == -1) {
        return 1;
    }
    p = func_80011510(9, -1, -1);
    if (p == 0) {
        return 0;
    }
    return p->field_2C[id].field_23;
}

void func_8001BE74(s32 a0, s32 a1) {
    Ent11440 *p = func_80011510(9, -1, -1);
    if (a0 != -1 && p != 0) {
        Rec34 *r = &p->field_2C[a0];
        r->field_20 = a1;
        r->field_2 = a1;
    }
}

void func_8001BEE8(s32 a0, s32 a1) {
    Ent11440 *p = func_80011510(9, -1, -1);
    if (a0 != -1 && p != 0) {
        p->field_2C[a0].field_30 = a1;
    }
}

void func_8001BF58(s32 a0, s32 a1) {
    Ent11440 *p = func_80011510(9, -1, -1);
    if (a0 != -1 && p != 0) {
        p->field_2C[a0].field_31 = a1;
    }
}

void func_8001BFC8(void *a0, s32 a1, s32 a2, Halves a3) {
    Arg1BC24 local;
    local.field_14 = (s32)func_800239A0(a1 + 0x1FD0000);
    local.field_0 = 0;
    local.field_4 = a2;
    local.field_8 = a3.lo;
    local.field_A = a3.hi;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = 0;
    func_8001BC24(a0, &local);
}

void func_8001C038(void *arg0, s32 arg1) {
    Arg1BC24 local;
    local.field_0 = 1;
    local.field_4 = 0;
    local.field_8 = 0;
    local.field_A = 0;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_14 = arg1;
    local.field_18 = 1;
    func_8001BC24(arg0, &local);
    func_800221C4(0x10, 0);
}

void func_8001C088(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        *arg0++ = -1;
    }
}

void func_8001C0B0(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        func_8001BB88(arg0);
        arg0++;
    }
}

void func_8001C104(void) {
    Rect2AB54 r;
    s32 i;

    for (i = 0; i < 2; i++) {
        r = ((View1C104 *)&D_8005F770)->area[i].rect;
        func_80027104(1);
        func_80027694((s32)&r, 0, 0, 0);
        func_80027480(0);
    }
}


void func_8001C194(s32 a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_8005F770.field_48[i].field_0 = 1;
        D_8005F770.field_48[i].field_1 = a0;
        D_8005F770.field_48[i].field_2 = a1;
        D_8005F770.field_48[i].field_3 = a2;
    }
}

void func_8001C1CC(void) {
    D_8005F770.field_48[0].field_0 = 0;
    D_8005F770.field_48[1].field_0 = 0;
}

void func_8001C1E0(s32 w, s32 h, s32 mode, s32 inter) {
    Db5F770 *g = (Db5F770 *)&D_8005F770;
    s32 n = 0;
    s32 hw = w / 2;
    s32 hh = h / 2;

    g->field_110 = hw;
    g->field_114 = hh;
    switch (mode) {
    default:
    case 0:
        func_8002A9F4(&g->draw[0], 0, h, w, h);
        func_8002A9F4(&g->draw[1], 0, 0, w, h);
        func_8002AAB4(&g->disp[0], 0, 0, w, h);
        func_8002AAB4(&g->disp[1], 0, h, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = h + hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 1:
        func_8002A9F4(&g->draw[0], 0, 0, w, h);
        func_8002A9F4(&g->draw[1], 0, 0, w, h);
        func_8002AAB4(&g->disp[0], 0, 0, w, h);
        func_8002AAB4(&g->disp[1], 0, 0, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 2:
        if (inter != 0) {
            func_8002A9F4(&g->draw[0], 480, 0, 320, 480);
            func_8002A9F4(&g->draw[1], 0, 0, 320, 480);
            func_8002AAB4(&g->disp[0], 0, 0, 320, 480);
            g->disp[0].isrgb24 = 1;
            func_8002AAB4(&g->disp[1], 480, 0, 320, 480);
            g->disp[1].isrgb24 = 1;
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
        } else {
            func_8002A9F4(&g->draw[0], w, 0, w, h);
            func_8002A9F4(&g->draw[1], 0, 0, w, h);
            func_8002AAB4(&g->disp[0], 0, 0, w, h);
            func_8002AAB4(&g->disp[1], w, 0, w, h);
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
            n = 0x40 - (w / 16) * 2;
        }
        break;
    }
    func_8001CD2C(n);
    func_8002B4C4();
    func_8002D6A4(0, 0);
}

void func_8001C4C8(s32 arg0) {
    D_80041564.field_8 = 0;
    D_80041564.field_0 = 2;
    D_80041564.field_4 = arg0;
    D_8005F780 = arg0 + 0xFF;
}

void func_8001C4F0(s32 arg0) {
    D_80041564.field_8 = 0;
    D_80041564.field_0 = 3;
    D_80041564.field_4 = arg0;
}

void func_8001C50C(s32 arg0) {
    D_80041564.field_8 = 1;
    D_80041564.field_0 = 2;
    D_80041564.field_4 = arg0;
    D_8005F780 = arg0 + 0xFF;
}

void func_8001C538(s32 arg0) {
    D_80041564.field_8 = 1;
    D_80041564.field_0 = 3;
    D_80041564.field_4 = arg0;
}

void func_8001C558(void) {
    D_80041564.field_8 = 0;
    D_80041564.field_0 = 0;
}

void func_8001C56C(void) {
    D_80041564.field_8 = 0;
    D_80041564.field_0 = 1;
}

void func_8001C584(void) {
    Fade1C584 *p;
    Fade1C584Mode *q;
    Tag1CE9C *ot;
    s32 w;
    s32 h;
    u8 c;
    s32 abr;

    if (D_8005F770.work == 0) {
        return;
    }
    for (;;) {
        switch (D_80041564.field_0) {
        default:
        case 0:
            D_8005F770.field_10 = 0;
            return;
        case 1:
            D_8005F770.field_10 = 0xFF;
            goto check;
        case 2:
            D_8005F770.field_10 -= D_80041564.field_4;
            if (D_8005F770.field_10 > 0) {
                goto draw;
            }
            D_8005F770.field_10 = 0;
            D_80041564.field_0 = 0;
            continue;
        case 3:
            D_8005F770.field_10 += D_80041564.field_4;
            if (D_8005F770.field_10 < 0xFF) {
                goto check;
            }
            D_8005F770.field_10 = 0xFF;
            D_80041564.field_0 = 1;
            continue;
        }
    }
check:
    if (D_8005F780 == 0) {
        return;
    }
draw:
    abr = 2;
    q = (Fade1C584Mode *)D_8005F770.work;
    p = (Fade1C584 *)q;
    ot = (Tag1CE9C *)D_8005F770.field_138[0];
    p->t.len = 5;
    p->code = 0x2A;
    c = D_8005F770.field_10;
    p->g = c;
    p->b = c;
    p->r = c;
    w = D_8005F770.field_110;
    p->x0 = p->x2 = -w;
    p->x1 = p->x3 = w;
    h = D_8005F770.field_114;
    p->y0 = p->y1 = -h;
    p->y2 = p->y3 = h;
    p->t.addr = ot->addr;
    ot->addr = (u32)p;
    q = &p->m;
    if (D_80041564.field_8 != 0) {
        abr = 1;
    }
    q->t.len = 1;
    q->mode = (abr << 5) | 0xE1000400;
    p->m.t.addr = ot->addr;
    ot->addr = (u32)q;
    q = (Fade1C584Mode *)(p + 1);
    D_8005F770.work = (ActorWork *)q;
}

void func_8001C760(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_8005F770.field_118[i] = D_80041570[D_8005CCF8.field_60][i];
        D_8005F770.field_138[i] = &D_80054CF8[D_8005F770.field_28].field_0[D_800415F0[D_8005CCF8.field_60][i]];
    }
}

void func_8001C800(s32 arg0) {
    D_80054CF8[2].field_0[0] = arg0;
}

void func_8001C818(s32 arg0) {
    func_8002796C(&D_80054CF8[arg0], 0x100C);
}

s32 func_8001C858(s32 arg0) {
    s32 *p = (s32 *)&D_80058D28[arg0];
    return func_80027A74(&p[-1]);
}

void func_8001C898(s32 arg0) {
    u32 *p = (u32 *)&D_80058D28[arg0];
    u32 *end = (u32 *)&D_80058D28[arg0 - 1];
    u32 *q;
    u32 m = 0xFFFFFF;

    p--;
    while (p != end) {
        q = p - 1;
        if ((*p & m) == ((u32)q & m)) {
            u32 v = *q;
            u32 w = (u32)(q - 1) & m;

            while ((v & m) == w) {
                q--;
                v = *q;
                w = (u32)(q - 1) & m;
            }
            *p = (u32)q & m;
        }
        p = q;
    }
}

s32 func_8001C92C(void) {
    return 0;
}

void func_8001C934(void) {
    if (D_80041670[0] != 0) {
        func_80022D84(D_80041670[0]);
        D_80041670[0] = 0;
        func_80022D84(D_80041670[1]);
        D_80041670[1] = 0;
    }
    D_8005F79C = 0;
}

void func_8001C988(void) {
    D_8005F770.work = D_80041670[D_8005F770.field_28];
}

extern s32 func_80022F3C(s32, s32);

void func_8001C9B0(s32 a0) {
    D_80041670[2] = (ActorWork *)a0;
    D_80041670[0] = (ActorWork *)func_80022F3C(a0, 2);
    D_80041670[1] = (ActorWork *)func_80022F3C(a0, 2);
    D_8005F770.work = D_80041670[D_8005F770.field_28];
}

Elem20 *func_8001CA28(s32 arg0) {
    return &D_8005CD60[arg0];
}

void func_8001CA3C(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        D_8005CD60[i].field_18 = 0x3E0 - (i / 2) * 32;
        D_8005CD60[i].field_14 = i;
        D_8005CD60[i].field_1C = (i & 1) << 8;
        D_8005CD60[i].field_0 = 0;
        D_8005CD60[i].field_4 = 0;
        D_8005CD60[i].field_8 = 0;
        D_8005CD60[i].field_C = 0;
        D_8005CD60[i].field_10 = 0;
    }
}

s32 func_8001CAA0() {
    return func_800239A0()->field_4 & 7;
}

void func_8001CAC4(Elem20 *a0) {
    u32 *p;
    u32 flags;
    Rect2AB54 clut;
    Rect2AB54 img;

    p = (u32 *)func_800239A0(a0->field_0);
    p++;
    flags = *p++;
    if (flags & 8) {
        if (flags & 7) {
            clut.x = 0;
            clut.y = a0->field_14 + 0x1E0;
            clut.w = 0x100;
            clut.h = 1;
            func_8002772C((s32)&clut, (s32)((TimBlk *)p + 1));
        }
        p = (u32 *)((u8 *)p + *p);
    }
    img.x = a0->field_18;
    img.y = a0->field_1C;
    img.w = ((TimBlk *)p)->rect.w;
    img.h = ((TimBlk *)p)->rect.h;
    func_8002772C((s32)&img, (s32)((TimBlk *)p + 1));
}


Elem20 *func_8001CB80(s32 id) {
    Elem20 *e;
    Elem20 *p;
    s32 i;
    u32 best;
    s32 idx;
    s32 n;
    s32 tp;
    s32 t;

    p = D_8005CD60;
    for (i = 0; i < 0x40; i++, p++) {
        if (p->field_0 == -1) {
            continue;
        }
        if (p->field_0 == -2) {
            continue;
        }
        if (p->field_0 == id) {
            p->field_4 = D_8005F770.field_0;
            return p;
        }
    }
    best = -1;
    idx = 0;
    if (func_8001CAA0(id)) {
        n = 0x20;
        tp = 1;
    } else {
        n = 0x40;
        tp = 0;
    }
    e = D_8005CD60;
    for (i = 0; i < n; i++, e++) {
        if (e->field_0 == -1) {
            continue;
        }
        if (e->field_0 == -2) {
            continue;
        }
        if (e->field_0 == 0) {
            idx = i;
            break;
        }
        if (e->field_4 < best) {
            best = e->field_4;
            idx = i;
        }
    }
    e = &D_8005CD60[idx];
    e->field_0 = id;
    e->field_4 = D_8005F770.field_0;
    e->field_8 = tp;
    t = e->field_14 & 2;
    e->field_C = t == 0;
    if (tp) {
        e->field_C <<= 6;
    } else {
        e->field_C <<= 7;
    }
    e->field_10 = (tp << 7) | ((e->field_1C & 0x100) >> 4) | ((e->field_18 & 0x3FF) >> 6) | ((e->field_1C & 0x200) << 2);
    func_8001CAC4(e);
    return e;
}

void func_8001CD2C(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Elem20 *p = func_8001CA28(i);
        if (i >= arg0) {
            p->field_0 = -1;
        } else {
            if (p->field_0 == -1) p->field_0 = 0;
        }
    }
}

s32 func_8001CDA8(void) {
    u32 min = -1;
    s32 best = 0;
    s32 i;
    Elem20 *p = D_8005CD60;

    for (i = 0; i < 24; i++, p++) {
        if (p->field_0 == -2) {
            continue;
        }
        if (p->field_0 == 0) {
            best = i;
            break;
        }
        if ((u32)p->field_4 < min) {
            min = p->field_4;
            best = i;
        }
    }
    p = &D_8005CD60[best];
    p->field_0 = -2;
    p->field_4 = D_8005F770.field_0;
    p->field_8 = 0;
    p->field_C = ((p->field_14 & 2) == 0) << 7;
    p->field_10 = ((p->field_1C & 0x100) >> 4) | ((p->field_18 & 0x3FF) >> 6) | ((p->field_1C & 0x200) << 2);
    return (s32)p;
}

void func_8001CE80(s32 *arg0) {
    if (*arg0 == -2) {
        *arg0 = 0;
    }
}

void func_8001CE9C(void *arg0, s32 arg1) {
    Obj1CE9C *s = arg0;
    Tag1CE9C *ot = (Tag1CE9C *)arg1;
    Ent1CE9C *e;
    Tex1CE9C *t;
    Pkt1CE9C *p;
    u16 tpage;
    s32 y;

    e = (Ent1CE9C *)func_800239A0(s->field_0);
    t = (Tex1CE9C *)func_8001CB80(s->field_0 & 0xFFFF0000);
    p = (Pkt1CE9C *)D_8005F79C;
    for (; e->field_0 != 0xFF; e++) {
        if (e->field_C != s->field_D) {
            continue;
        }
        p->s.c = s->field_8;
        p->s.tag.len = 4;
        p->s.c.code = 0x64;
        if (e->field_B & 0x80) {
            p->s.c.code = 0x66;
            tpage = t->field_10 + ((e->field_B & 3) << 5);
        } else {
            tpage = t->field_10;
        }
        p->s.x0 = e->field_2 + s->field_4;
        p->s.u0 = e->field_0 + t->field_C;
        p->s.w = e->field_8;
        p->s.y0 = e->field_4 + s->field_6;
        p->s.v0 = e->field_1;
        p->s.h = e->field_9;
        if (p->s.h == 0) {
            p->s.h--;
        }
        if (t->field_8 != 0) {
            y = t->field_14 + 0x1E0;
            p->s.clut = (e->field_A + y + s->field_C) << 6;
        } else {
            p->s.clut = ((e->field_7 + t->field_1C + e->field_A + s->field_C) << 6) |
                       (((e->field_6 + t->field_18) >> 4) & 0x3F);
        }
        p->s.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (Pkt1CE9C *)(&p->s + 1);
        p->t.tag.len = 1;
        p->t.code = 0xE1000600 | (tpage & 0x9FF);
        p->t.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (Pkt1CE9C *)(&p->t + 1);
    }
    D_8005F79C = (s32)p;
}


void func_8001D104(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    Ent1CE9C *e;
    Tex1CE9C *t;
    Poly1D104 *p;
    DVec1D104 out;
    SVec1D104 sv[4];
    s32 i;
    s32 u;
    s32 y;

    e = (Ent1CE9C *)func_800239A0(((Obj1CE9C *)arg0)->field_0);
    t = (Tex1CE9C *)func_8001CB80(((Obj1CE9C *)arg0)->field_0 & 0xFFFF0000);
    p = (Poly1D104 *)D_8005F79C;
    for (; e->field_0 != 0xFF; e++) {
        if (e->field_C != ((Obj1CE9C *)arg0)->field_D) {
            continue;
        }
        p->c = ((Obj1CE9C *)arg0)->field_8;
        p->tag.len = 9;
        p->c.code = 0x2C;
        if (e->field_B & 0x80) {
            p->c.code = 0x2E;
            p->v[1].extra = t->field_10 | ((e->field_B & 3) << 5);
        } else {
            p->v[1].extra = t->field_10;
        }
        sv[0].vx = sv[2].vx = e->field_2;
        sv[1].vx = sv[3].vx = e->field_2 + e->field_8;
        sv[0].vy = sv[1].vy = e->field_4;
        if (e->field_9) sv[2].vy = sv[3].vy = e->field_4 + e->field_9; else sv[2].vy = sv[3].vy = e->field_4 + 0xFF;
        sv[0].vz = sv[1].vz = sv[2].vz = sv[3].vz = 0;
        for (i = 0; i < 4; i++) {
            func_8002D444(arg1, &sv[i], &out);
            p->v[i].x = out.vx + ((Obj1CE9C *)arg0)->field_4;
            p->v[i].y = out.vy + ((Obj1CE9C *)arg0)->field_6;
        }
        u = e->field_0 + t->field_C;
        p->v[0].u = p->v[2].u = u;
        u += e->field_8;
        p->v[1].u = p->v[3].u = u;
        if (((Obj1CE9C *)arg0)->field_10 < 0) {
            p->v[1].u = p->v[3].u = u - 1;
        }
        if (p->v[1].u == 0) {
            p->v[1].u = p->v[3].u = 0xFF;
        }
        p->v[0].v = p->v[1].v = e->field_1;
        u = e->field_1 + e->field_9;
        p->v[2].v = p->v[3].v = u;
        if (((Obj1CE9C *)arg0)->field_14 < 0) {
            p->v[2].v = p->v[3].v = u - 1;
        }
        if (p->v[2].v == 0) {
            p->v[2].v = p->v[3].v = 0xFF;
        }
        if (t->field_8 != 0) {
            y = t->field_14 + 0x1E0;
            p->v[0].extra = (e->field_A + y + ((Obj1CE9C *)arg0)->field_C) << 6;
        } else {
            p->v[0].extra = ((e->field_7 + t->field_1C + e->field_A + ((Obj1CE9C *)arg0)->field_C) << 6) |
                            (((e->field_6 + t->field_18) >> 4) & 0x3F);
        }
        if (arg3 & 1) {
            p->v[0].x *= 2;
            p->v[1].x *= 2;
            p->v[2].x *= 2;
            p->v[3].x *= 2;
        }
        if (arg3 & 2) {
            p->v[0].y *= 2;
            p->v[1].y *= 2;
            p->v[2].y *= 2;
            p->v[3].y *= 2;
        }
        p->tag.addr = ((Tag1CE9C *)arg2)->addr;
        ((Tag1CE9C *)arg2)->addr = (u32)p;
        p++;
    }
    D_8005F79C = (s32)p;
}


void func_8001D504(Obj1D504 *p, s32 mask) {
    if (p->field_0 != 0) {
        do {
            if (p->field_1C & mask) {
                p->field_F = 0;
            } else {
                p->field_F = 1;
            }
            p++;
        } while (p->field_0 != 0);
    }
}

void func_8001D550(Ent1D550 *p, s32 a1, s32 a2) {
    if (p->field_0 == 0) {
        return;
    }
    do {
        if (a1 != 0x1000) {
            p->field_E = 0;
        } else {
            p->field_E = 1;
        }
        p->field_10 = a1;
        if (a2 != 0x1000) {
            p->field_E = 0;
        } else {
            p->field_E = 1;
        }
        p->field_14 = a2;
        p++;
    } while (p->field_0 != 0);
}

void func_8001D5B4(Part28 *p, s32 mask, s32 n, s32 val) {
    u8 d[8];
    Part28 *q;
    s32 i = 0;
    s32 lead = 0;
    s32 k;
    s32 x;

    if (n < 0) {
        lead = 1;
        n = -n;
    }
    x = val;
    for (k = n - 1; k != -1; k--) {
        d[k] = x % 10;
        x /= 10;
    }
    if (p->field_0 != 0) {
        q = p;
        do {
            if (q->field_1C & mask) {
                if (lead == 1 || i == n - 1 || d[i] != 0) {
                    lead = 1;
                    q->field_D = d[i];
                } else {
                    q->field_D = 0xFF;
                }
                i++;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

/* File-local record walked by func_8001D6B4 (stride 0x28). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0xB - 4];
    /* 0x0B */ u8 field_B;
    u8 _pad0C[0xE - 0xC];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x20 - 0x18];
    /* 0x20 */ s16 field_20;
    /* 0x22 */ s16 field_22;
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
} Rec1D6B4; /* 0x28 */

/* View of D_8005F770 (=Actor) fields func_8001D6B4 reads. */
typedef struct {
    u8 _pad00[0x110];
    /* 0x110 */ s32 field_110;
    /* 0x114 */ s32 field_114;
    u8 _pad118[0x138 - 0x118];
    /* 0x138 */ s32 field_138[1];
} Wk1D6B4;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    u8 _pad06[2];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    u8 _pad10[0x18 - 0x10];
    /* 0x18 */ s32 field_18;
} G4167C;

/* 2-byte-aligned aggregate forcing the lwl/lwr + swl/swr block copy. */
typedef struct {
    s16 h[4];
} Agg1D6B4;

extern G4167C D_8004167C;
extern u8 D_80041694;
extern void func_8001CE9C(void *, s32);
extern void func_8001D104(void *, void *, s32, s32);
extern void func_8002D4A4(Obj209 *, s32 *);

void func_8001D6B4(void *arg0, s32 arg1) {
    Rec1D6B4 *s2 = (Rec1D6B4 *)arg0;
    s32 s3 = 0;
    s32 s4;

    if (arg1 != 0) {
        s32 f114 = ((Wk1D6B4 *)&D_8005F770)->field_114;
        s3 = 0;
        s3 = (((Wk1D6B4 *)&D_8005F770)->field_110 ^ 0x140) == s3;
        if (f114 == 0xF0) {
            s3 |= 2;
        }
    }
    if (s2->field_0 == 0) {
        return;
    }
    do {
        s4 = ((Wk1D6B4 *)&D_8005F770)->field_138[s2->field_B];
        if (s2->field_F != 0) {
            if (s2->field_E != 0) {
                if (s3 != 0) {
                    s2->field_24 = 0;
                    s2->field_22 = 0;
                    s2->field_20 = 0;
                    s2->field_10 = 0x1000;
                    s2->field_14 = 0x1000;
                } else {
                    func_8001CE9C(s2, s4);
                    goto Ladv;
                }
            }
            if (D_8004167C.field_0 == *(s32 *)&s2->field_20 &&
                D_8004167C.field_4 == s2->field_24 &&
                D_8004167C.field_8 == s2->field_10 &&
                D_8004167C.field_C == s2->field_14) {
            } else {
                *(Agg1D6B4 *)&D_8004167C = *(Agg1D6B4 *)&s2->field_20;
                D_8004167C.field_8 = s2->field_10;
                D_8004167C.field_C = s2->field_14;
                func_8002D744(&D_8004167C, (Obj209 *)&D_8004167C.field_18);
                func_8002D4A4((Obj209 *)&D_8004167C.field_18, &D_8004167C.field_8);
            }
            func_8001D104(s2, &D_80041694, s4, s3);
        }
    Ladv:
        s2 = (Rec1D6B4 *)((u8 *)s2 + 0x28);
    } while (s2->field_0 != 0);
}

void func_8001D884(s32 arg0) {
    func_8001D6B4(arg0, 1);
}

void func_8001D8A4(s32 arg0) {
    func_8001D6B4(arg0, 0);
}

EntD8C4 *func_8001D8C4(id) s32 id; {
    EntD8C4 *p = (EntD8C4 *)func_80023A08(0xC6C);
    s16 v;

loop:
    v = p->field_0;
    if (v == 0) {
        goto fail;
    }
    if (v == id) {
        return p;
    }
    p++;
    goto loop;
fail:
    return 0;
}

u8 func_8001D910(void) {
    return func_8001D8C4()->field_3;
}

u8 func_8001D934(void) {
    return func_8001D8C4()->u4.field_4 & 0xF;
}

s32 func_8001D958(void) {
    return (func_8001D8C4()->u4.field_4h >> 4) & 0xF;
}

s32 func_8001D980(void) {
    return (func_8001D8C4()->u4.field_4h >> 8) & 0xF;
}

u8 func_8001D9A8(void) {
    return func_8001D8C4()->field_2;
}

s32 func_8001D9CC(s32 id, s32 k) {
    switch (k) {
    default:
    case 0:
        return func_8001D8C4(id)->u4.field_4h >> 12;
    case 1:
        return func_8001D8C4(id)->u6.field_6 & 0xF;
    case 2:
        return (func_8001D8C4(id)->u6.field_6h >> 4) & 0xF;
    case 3:
        return (func_8001D8C4(id)->u6.field_6h >> 8) & 0xF;
    case 4:
        return func_8001D8C4(id)->u6.field_6h >> 12;
    }
}


u8 func_8001DA80(s32 id, s32 val) {
    EntD8C4 *e = func_8001D8C4(id);
    s32 i;

    if (e->field_D[0] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (e->field_8[i + 1] == 0) {
            break;
        }
        if (val >= e->field_8[i] && val < e->field_8[i + 1]) {
            break;
        }
    }
    return e->field_D[i];
}

Ent1DB18 *func_8001DB18(s32 id) {
    Rec1DB18 *p = (Rec1DB18 *)func_80023A08(0xC6F);

    while (1) {
        if (p->field_0 == 0) {
            break;
        }
        if (p->field_0 == id) {
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
        Row1DB18 *row = (Row1DB18 *)p;
        for (i = 0; i < 3; i++) {
            out->field_1C[i] = row[i].field_8;
            out->field_22[i] = row[i].field_12;
        }
    }
}

void func_8001DC24(s32 a0, s32 a1, ElmE620 *e) {
    Row1DB18 *r = (Row1DB18 *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    func_80022F8C(e, 0x5C);
    e->field_0 = 2;
    e->field_1 = r[a1].field_8;
    e->field_16 = e->field_14 = r[a1].field_A;
    e->field_1A = e->field_18 = r[a1].field_C;
    name = func_8001E758(e->field_1);
    for (i = 0; i < 14; i++) {
        e->field_4C[i] = name[i];
    }
    e->field_D = r[a1].field_12;
    e->field_1C = r[a1].field_13;
    e->field_1E = r[a1].field_14;
    e->field_20 = r[a1].field_16;
    e->field_22 = r[a1].field_17;
    e->field_23 = r[a1].field_18;
    e->field_24 = r[a1].field_19;
    e->field_F = func_8001EB58(e->field_D);
    if (e->field_D == 1) {
        e->field_10 = 0;
    } else {
        e->field_10 = func_8001E984(e->field_D - 1, 100, 0);
    }
}

void func_8001DDA8(s32 a0, s32 a1, ElmE620 *e, Out1DDA8 *o) {
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
    e->field_0 = a1 + 3;
    e->field_1 = t->rows[a1].field_0;
    e->field_16 = e->field_14 = t->rows[a1].field_2;
    e->field_1A = e->field_18 = t->rows[a1].field_4;
    if (e->field_1 != 0) {
        name = func_8001E758(e->field_1);
        for (i = 0; i < 14; i++) {
            e->field_4C[i] = name[i];
        }
        e->field_D = t->rows[a1].field_A;
        e->field_10 = t->rows[a1].field_6;
        e->field_1C = t->rows[a1].field_B;
        e->field_1E = t->rows[a1].field_C;
        e->field_20 = t->rows[a1].field_E;
        e->field_22 = t->rows[a1].field_F;
        e->field_23 = t->rows[a1].field_10;
        e->field_24 = t->rows[a1].field_11;
        for (i = 3; i < 12; i++) {
            e->field_25[i - 3] = 0;
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


EntDFF4 *func_8001DFF4(arg0)
s32 arg0;
{
    s16 *p = (s16 *)func_800239A0(0x45E0000);
    while (*p != 0) {
        if (*p == arg0) {
            return (EntDFF4 *)p;
        }
        p = (s16 *)((u8 *)p + 0x10);
    }
    return 0;
}

s32 func_8001E048(s32 arg0) {
    s32 base = func_80023A08(0x45E);
    return func_8001DFF4(arg0)->field_8 + base;
}

s32 func_8001E084(s32 arg0) {
    s32 base = func_80023A08(0x45E);
    return func_8001DFF4(arg0)->field_C + base;
}

s32 func_8001E0C0(s32 id) {
    return func_8001DFF4(id)->u0.b0.field_2;
}

s32 func_8001E0E4(void) {
    return func_8001DFF4()->u0.b0.field_3 & 0xF;
}

s32 func_8001E108(void) {
    return func_8001DFF4() != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return func_8001DFF4()->u0.field_0 >> 30;
}

s32 func_8001E158(void) {
    return (func_8001DFF4()->u0.field_0 >> 28) & 3;
}

s32 func_8001E180(void) {
    return func_8001DFF4()->u4.field_4 & 0xFFFFFF;
}

u8 func_8001E1AC(void) {
    return func_8001DFF4()->u4.b4.field_7;
}

s32 func_8001E1D0(s32 id) {
    EntDFF4 *p = (EntDFF4 *)func_800239A0(0x45E0000);
    s32 i = 0;

    while (p->u0.field_0h != 0) {
        if (p->u0.field_0h == id) {
            return i;
        }
        p++;
        i++;
    }
    return 0;
}

s32 func_8001E22C(s32 a0) {
    s16 *p = (s16 *)func_800239A0(0x45E0000);
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
    D_8005D560.field_0 = arg0;
}

Blk18 *func_8001E298(ArgE298 *arg0) {
    Blk18 *base = (Blk18 *)func_800239A0((D_8005D560.field_0 << 16) | 2);
    return &base[arg0->field_5];
}

Blk18 *func_8001E2E0(ArgE298 *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)func_800239A0((D_8005D560.field_0 << 16) | 2);
    return &base[((ArgE298 *)((u8 *)arg0 + arg1))->field_6];
}

Blk18 *func_8001E338(ArgE298 *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)func_800239A0((D_8005D560.field_0 << 16) | 2);
    return &base[((ArgE298 *)((u8 *)arg0 + arg1))->field_C];
}

s32 func_8001E390(void) {
    while (D_8005D560.field_C->field_0 != 0) {
        if (func_80022038(func_8001E298((ArgE298 *)D_8005D560.field_C)) != 0) {
            D_8005D560.field_10 = *D_8005D560.field_C;
            {
                s32 r = D_8005D560.field_8;

                D_8005D560.field_C++;
                D_8005D560.field_8 = r + 1;
                return r;
            }
        }
        D_8005D560.field_C++;
        D_8005D560.field_8++;
    }
    return -1;
}

void func_8001E480(void) {
    D_8005D560.field_4 = func_80023A08(D_8005D560.field_0);
    D_8005D560.field_C = func_800239A0(D_8005D560.field_0 << 16);
    D_8005D560.field_8 = 0;
    func_8001E390();
}

EntE4CC *func_8001E4CC(arg0)
s32 arg0;
{
    EntE4CC *base = (EntE4CC *)func_800239A0(D_8005D560.field_0 << 16);
    return &base[arg0];
}

extern s32 func_80022038();
extern void func_80022388();

s32 func_8001E514(s32 arg0) {
    EntE4CC *base;
    s32 r;
    s32 i;
    r = func_80023A08(D_8005D560.field_0);
    base = func_8001E4CC(arg0);
    for (i = 0; i < 6; i++) {
        if (func_80022038(func_8001E2E0((ArgE298 *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    func_80022388(func_8001E338((ArgE298 *)base, i));
    return base->field_14[i] + r;
}

s32 func_8001E5C0(void) {
    return func_80023A08(D_8005D560.field_0);
}

Blk12 *func_8001E5E8(void) {
    EntE4CC *e = func_8001E4CC();
    Blk12 *base = (Blk12 *)func_800239A0((D_8005D560.field_0 << 16) | 1);
    return &base[e->field_4];
}

s16 func_8001E634(void) {
    return func_8001E4CC()->field_0;
}

s16 func_8001E658(void) {
    return func_8001E4CC()->field_2;
}

s32 func_8001E67C(s32 arg0) {
    if (arg0 < 0x12C) {
        return 0xCB9;
    }
    if ((u32)(arg0 - 0x190) < 0x65) {
        return 0xCBB;
    }
    return 0xCBA;
}

EntE6A8 *func_8001E6A8(s32 id) {
    EntE6A8 *e = (EntE6A8 *)func_800239A0(func_8001E67C(id) << 16);
    s32 k;

    while (1) {
        k = (e->u4.field_4 >> 1) & 0x7FFF;
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

s32 func_8001E704(s32 id) {
    return func_8001E6A8(id)->u4.h4.field_6;
}

s32 func_8001E728(s32 arg0, s32 arg1) {
    return func_8001E6A8(arg0)->field8[arg1];
}

u8 *func_8001E758(s32 id) {
    s32 v;

    v = func_8001E6A8(id)->field_0;
    v += func_80023A08(func_8001E67C(id));
    return (u8 *)v;
}

s16 func_8001E79C(s32 id) {
    return func_8001E6A8(id)->field_1E;
}

s16 func_8001E7C0(s32 id) {
    return func_8001E6A8(id)->field_20;
}

void func_8001E7E4(s32 a0, void *a1) {
    u8 *base;
    EntE6A8 *e;
    base = (u8 *)func_800239A0((func_8001E67C(a0) << 16) | 1);
    e = func_8001E6A8(a0);
    *(Row6 *)((u8 *)a1 + 0) = *(Row6 *)(base + e->field_22 * 6);
    e = func_8001E6A8(a0);
    *(Row6 *)((u8 *)a1 + 6) = *(Row6 *)(base + e->field_24 * 6);
    e = func_8001E6A8(a0);
    *(Row6 *)((u8 *)a1 + 12) = *(Row6 *)(base + e->field_26 * 6);
}

s32 func_8001E8D0(s32 id) {
    return func_8001E6A8(id)->u4.field_4 & 1;
}

u16 func_8001E8F4(s32 idx) {
    EntA0 *p = func_800239A0(0x1F80000) + idx;
    return (p->field_4 >> 1) & 0x7FFF;
}

s32 func_8001E938(void) {
    EntA0 *p = func_800239A0(0x1F80000);
    s32 i = 0;
    while ((p->field_4 >> 1) & 0x7FFF) {
        p++;
        i++;
    }
    return i;
}

s32 func_8001E984(s32 lv, s32 max, s32 cur) {
    s32 x;
    s32 sq;
    s32 exp;

    if (lv >= max) {
        return 99999999;
    }
    if (lv >= 62) {
        x = lv - 61;
        exp = 826540 + x * 65535;
    } else if (lv >= 31) {
        x = lv - 30;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15 + x * 1145) * 4 + 31080;
    } else if (lv >= 21) {
        x = lv - 20;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15) * 2 + x * 1220 + 5880;
    } else if (lv >= 11) {
        x = lv - 10;
        sq = x * x;
        exp = sq * x * 10 / 3 + sq * 10 + x * 107 + 480;
    } else {
        x = lv;
        sq = x * x;
        exp = sq * x / 3 + sq + x * 5;
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
        s32 r = (u16)((u16)func_80023910() % 3) + 2;
        return x + r;
    }
}

void func_8001EC00(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void func_8001EC10(Actor *arg0) {
    s32 state = arg0->field_10;

    switch (state) {
    case 0:
        func_80020C40((ContC40 *)arg0, D_80043704, 0);
        func_8001FDBC(arg0, 0x5B)->field_3C = 4;
        func_8001F5E8(arg0);
        func_80011544(arg0);
        break;
    case 1: {
        ActorWork *w = arg0->work;
        Actor *v1 = (Actor *)w->field_0;
        w->field_4 = 0;
        if (v1 != 0) {
            s32 st = v1->field_10;
            if (st != 0 && st != 3) {
                DstElem *de = v1->field_3C->field_78;
                ObjEC10 *dst = arg0->u38.ptr38;
                s32 t = de->field_34;
                dst->field_34 = 0;
                dst->field_30 = t;
                dst->field_38 = de->field_3C;
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
        func_8001FDBC(arg0, 0x5B);
        func_80020920(arg0);
        func_800200D0(arg0);
        func_80020510(arg0, 1);
    }
}

EntED40 *func_8001ED40(s32 id) {
    EntED40 *p = (EntED40 *)func_800239A0(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 func_8001ED84(s32 arg0) {
    s32 base = func_80023A08(0x25B);
    EntED40 *p = func_8001ED40(arg0);
    if (p != 0) {
        return p->field_24 + base;
    }
    return 0;
}

s32 func_8001EDD4(s32 arg0) {
    s32 base = func_80023A08(0x25B);
    return func_8001ED40(arg0)->field_28 + base;
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
        *a++ = p->field_2C[n][i];
        *b++ = p->field_2C[n + 1][i];
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
        return (u16)func_80023910() % 5;
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

void func_8001F1A8(Actor *a, s32 n) {
    Sub3C *s = a->field_3C;
    s32 i;
    s32 k;

    s->field_54 = n;
    s->field_58 = 0;
    s->field_50 = 0;
    for (i = 10; i < 0x6F; i += 10) {
        if (n < i) {
            s->field_48 = func_8001E728(a->field_C, i / 10 - 1);
            k = i - 10;
            s->field_4C = n - k;
            break;
        }
    }
    s->field_5C = 1;
    s->field_60 = 0;
}

void func_8001F24C(Actor *arg0, s32 arg1, s32 arg2) {
    Sub3C *p = arg0->field_3C;
    p->field_54 = arg1;
    p->field_58 = 0;
    p->field_50 = 0;
    p->field_48 = arg2;
    p->field_4C = 0;
    p->field_5C = 1;
    p->field_60 = 0;
}

s32 func_8001F274(Actor *a0, s32 n) {
    Sub3C *sub = a0->field_3C;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        k = 0;
        n = k;
        id = func_8001E728(a0->field_C, k);
    } else if (n < 20) {
        id = func_8001E728(a0->field_C, 1);
        n -= 10;
    } else {
        id = func_8001E728(a0->field_C, 2);
        n -= 20;
    }
    p = (s32 *)(func_80023A08(id) + ((sub->field_8 + 1) << 2));
    sub->field_64 = p;
    return p[n] != 0;
}

void func_8001F320(Actor *a) {
    Sub3C *s = a->field_3C;
    s32 *data = (s32 *)func_80023A08(s->field_48);
    s32 i;
    s32 j;
    s32 k;
    DstElem *e;
    u8 *f;
    u8 *q;
    s32 pos;
    Rec18 *r;

    if (data != s->field_50) {
        s->field_50 = data;
        s->field_68 = data + 1;
        i = s->field_8 + 1;
        s->field_64 = &data[i];
    }
    if (data[0] == 0) {
        data[0] = 1;
        for (k = 0; s->field_64[k] != 1; k++) {
            if (s->field_64[k] != 0) {
                s->field_64[k] += (s32)data;
            }
        }
        for (k = 0; k < s->field_8; k++) {
            s->field_68[k] += (s32)data;
        }
    }
    s->field_5C += D_8005F770.field_8;
    while (s->field_5C >= 2) {
        s->field_5C -= 2;
        e = s->field_78;
        f = (u8 *)s->field_64[s->field_4C];
        pos = s->field_58;
        for (i = 0; i < s->field_8; i++) {
            e->field_80 = f[s->field_58++];
            e++;
        }
        q = &f[s->field_58];
        if (*q & 0x80) {
            switch (*q) {
            case 0xFF:
                s->field_60 = -1;
                s->field_58 = pos;
                goto done;
            case 0xFE:
                s->field_58 = (q[2] << 8) | q[1];
                s->field_60 = -1;
                break;
            }
        }
    }
done:
    e = s->field_78;
    for (i = 0; i < s->field_8; i++) {
        r = &((Rec18 *)s->field_68[i])[e->field_80];
        e->field_60.m = r->m;
        for (j = 0; j < 3; j++) {
            e->field_60.t[j] = r->t[j];
        }
        e++;
    }
}


extern Blk20 D_80043714;

void func_8001F5E8(Actor *a0) {
    Sub3C *sub = a0->field_3C;
    DstElem *p = sub->field_78;
    s32 i = 0;
    while (i < sub->field_8) {
        i++;
        p->field_60 = D_80043714;
        p++;
    }
}

void func_8001F668(Col1F668 *col, SVec1F668 *v, s32 flags, s32 idx) {
    Coord1F668 coord;
    Mat1F668 m;
    s32 pz;
    s32 flag;
    PolyF4_1F668 *p;
    PolyF4_1F668 *q;
    DrMode1F668 *dm;
    s32 *ot;
    Actor *g;

    func_8002B424(0, &coord);
    func_8002BD94(&coord, &m);
    func_8002B494(&m);
    g = &D_8005F770;
    p = (PolyF4_1F668 *)g->work;
    ot = g->field_138[idx];
    p->c = *col;
    func_8002AB34((u8 *)p);
    q = p;
    if (flags & 4) {
        p->c.code |= 2;
    }
    func_8002D6D4(&v[0], &p->xy[0], &pz, &flag);
    p->xy[0].x /= 2;
    p->xy[0].y /= 2;
    func_8002D6D4(&v[1], &p->xy[1], &pz, &flag);
    p->xy[1].x /= 2;
    p->xy[1].y /= 2;
    func_8002D6D4(&v[2], &p->xy[2], &pz, &flag);
    p->xy[2].x /= 2;
    p->xy[2].y /= 2;
    func_8002D6D4(&v[3], &p->xy[3], &pz, &flag);
    p->xy[3].x /= 2;
    p->xy[3].y /= 2;
    p->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p++;
    func_8002ABB4((DrMode1F668 *)p, 0, 0, (flags & 3) << 5, 0);
    dm = (DrMode1F668 *)(q + 1);
    dm->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p = (PolyF4_1F668 *)(dm + 1);
    g->work = (ActorWork *)p;
}


void func_8001F90C(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        func_8002B564(i, &D_800416CC[i]);
    }
    func_8002BB54(0x4CC, 0x4CC, 0x4CC);
    func_8002BAD4(0);
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

void func_8001F9AC(Actor *a0) {
    Sub3C *w = a0->field_3C;
    Part1F9AC *r = (Part1F9AC *)w->field_1C;
    Pos1F9AC *pos = w->field_44;
    s32 k = 0;
    s32 j;
    s32 i;
    s32 m;
    DrMove2AB54 *prim;
    Rect2AB54 rc;
    Rect2AB54 rc2;
    Anim1F9AC *q;
    u8 n;

    if (r->field_0 != 0xFF) {
        if (func_8001F970(w->field_54) != 0) {
            switch (w->field_2C >> 1) {
            case 0:
                w->field_2C = (func_80023910() & 0x7F) + 0x3C;
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
            if ((w->field_2C -= D_8005F770.field_8) < 0) {
                w->field_2C = 0;
            }
        } else {
            k = 4;
            w->field_2C = 0;
        }
    }
    w->field_30 += D_8005F770.field_8;
    while (1) {
        if (w->field_30 < 0x18) break;
        w->field_30 -= 0x18;
    }
    j = (w->field_30 / 8) * 2;
    prim = ((Wk1F9AC *)&D_8005F770)->field_2C;
    for (i = 0; i < 10; i++, r++) {
        if (i < 2) {
            if (r->field_0 == 0xFF) continue;
        } else {
            if (r->field_0 == 0xFF) break;
            if (r->field_0 == 0xFE) break;
        }
        if (i < 2) {
            rc.x = r->uv[k] + pos->field_18;
            rc.y = r->uv[k + 1] + pos->field_1C;
        } else {
            rc.x = r->uv[j] + pos->field_18;
            rc.y = r->uv[j + 1] + pos->field_1C;
        }
        rc.w = r->field_2;
        rc.h = r->field_3;
        func_8002AB54(prim, &rc, r->field_0 + pos->field_18, r->field_1 + pos->field_1C);
        func_8002AAF4(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
        prim++;
    }
    if (r->field_0 == 0xFE) {
        q = (Anim1F9AC *)&r->field_1;
        for (i = 0; i < 10; i++, q++) {
            if (q->field_0 == 0xFF) break;
            if (D_8005F770.field_8 == 1) {
                q->field_9 += 1;
            } else {
                q->field_9 += 2;
            }
            n = q->field_8;
            while (1) {
                if (q->field_9 < n) break;
                q->field_9 -= n;
            }
            m = (q->field_9 >> 1) * 4;
            rc2.x = q->uv[m] + pos->field_18;
            rc2.y = q->uv[m + 1] + pos->field_1C;
            rc2.w = q->field_2;
            rc2.h = q->field_3;
            func_8002AB54(prim, &rc2, q->field_0 + pos->field_18, q->field_1 + pos->field_1C);
            func_8002AAF4(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->field_18;
            rc2.y = q->uv[m + 3] + pos->field_1C;
            rc2.w = q->field_6;
            rc2.h = q->field_7;
            func_8002AB54(prim, &rc2, q->field_4 + pos->field_18, q->field_5 + pos->field_1C);
            func_8002AAF4(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
            prim++;
        }
    }
    D_8005F79C = (s32)prim;
}


Sub3C *func_8001FDBC(Actor *a0, s32 id) {
    s32 fresh = 0;
    Mdl1FDBC *m = (Mdl1FDBC *)func_80023A08(id);
    Mdl1FDBC *base = m;
    Sub3C *t = a0->field_3C;
    Sub3C *s;
    s32 i;
    Sec1FDBC20 *p;
    Sec1FDBC20 *q;
    Sec1FDBC16 *r;
    s32 v;
    Ent1FDBC20 *e;

    if (t == NULL) {
        a0->field_3C = (Sub3C *)func_80022F3C(0x7C, 2);
        func_80022F8C(a0->field_3C, 0x7C);
        fresh = 1;
    } else if (t->field_4 == m && m->field_4 != 0) {
        return t;
    }
    s = a0->field_3C;
    s->field_0 = id;
    s->field_4 = base;
    s->field_8 = m->field_8;
    s->field_C = (s16 **)base->field_C;
    s->field_10 = s->field_C + s->field_8;
    s->field_14 = (Sec1FDBC20 **)(s->field_10 + s->field_8);
    s->field_18 = (s32 *)(s->field_14 + s->field_8);
    s->field_1C = s->field_18 + s->field_8;
    if (m->field_4 == 0) {
        for (i = 0; i < s->field_8; i++) {
            s->field_C[i] = (s16 *)((s32)s->field_C[i] + (s32)base);
            s->field_10[i] = (s16 *)((s32)s->field_10[i] + (s32)base);
            s->field_14[i] = (Sec1FDBC20 *)((s32)s->field_14[i] + (s32)base);
        }
        m->field_4 = 1;
    }
    if (fresh) {
        s->field_20 = 0;
        s->field_24 = 0;
        for (i = 0; i < s->field_8; i++) {
            if (s->field_20 < *s->field_C[i]) {
                s->field_20 = *s->field_C[i];
            }
            if (s->field_24 < *s->field_10[i]) {
                s->field_24 = *s->field_10[i];
            }
        }
        s->field_28 = 0;
        for (i = 0; i < s->field_8; i++) {
            p = s->field_14[i];
            e = p->e;
            q = (Sec1FDBC20 *)(e + p->n);
            e = q->e;
            r = (Sec1FDBC16 *)(e + q->n);
            v = r->e[r->n].v[0];
            if (s->field_28 < v) {
                s->field_28 = v;
            }
        }
        s->field_78 = (DstElem *)func_80022F3C(s->field_8 * sizeof(DstElem), 2);
        s->field_6C = (s32 *)func_80022F3C(s->field_20 * 4, 2);
        s->field_70 = (s32 *)func_80022F3C(s->field_20 * 4, 2);
        s->field_74 = (s32 *)func_80022F3C(s->field_24 * 4, 2);
    }
    return s;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800200D0);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020510);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020768);

extern void func_8002D744(void *, Obj209 *);
extern void func_8002D4A4(Obj209 *, s32 *);

void func_80020920(Actor *arg0) {
    Obj209 *obj = (Obj209 *)arg0->u38.ptr38;
    s32 local[3];

    obj->field_20 = obj->field_30;
    func_8002D744(&obj->field_40, obj);
    func_8002CF74((ObjC0E4 *)obj, &obj->field_48, local);
    obj->field_30.x += local[0];
    obj->field_30.y += local[1];
    obj->field_30.z += local[2];
    if (obj->field_58 == 0x1000 && obj->field_5C == obj->field_58 &&
        obj->field_60 == obj->field_5C) {
    } else {
        func_8002D4A4(obj, &obj->field_58);
    }
    obj->field_50 = 0;
    obj->field_4C = 0;
    obj->field_48 = 0;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800209F8);

void func_80020C14(s32 arg0) {
    func_80020920(arg0);
    func_800209F8(arg0);
}

extern void func_80022F8C(void *, s32);

void func_80020C40(ContC40 *a0, s32 *a1, u16 a2) {
    AllocC40 *p;
    if (a0->field_38 == 0) {
        a0->field_38 = (AllocC40 *)func_80022F3C(0x90, 2);
    }
    func_80022F8C(a0->field_38, 0x90);
    p = a0->field_38;
    p->field_60 = 0x1000;
    p->field_5C = 0x1000;
    p->field_58 = 0x1000;
    if (a1 != 0) {
        p->field_30 = a1[0];
        p->field_34 = a1[1];
        p->field_38 = a1[2];
    }
    p->field_42 = a2;
    func_80020C14((s32)a0);
}

void func_80020CE8(Obj20CE8 *a0, s32 a1) {
    s32 v = a0->field_0 + a0->field_4;
    a0->field_0 = v;
    if (v > 0) {
        if (v >= a0->field_8) {
            a0->field_0 = a0->field_8;
        }
    } else if (a1 == 0) {
        a0->field_8 = 0;
        a0->field_4 = 0;
        a0->field_0 = 0;
    } else {
        if (v >= a0->field_8) {
            a0->field_0 = -a0->field_8;
        }
    }
}

s32 func_80020D54(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->field_38;
    Obj20CE8 *e = &p->field_6C[i];

    if (i != 1) {
        func_80020CE8(e, 0);
    } else {
        func_80020CE8(e, 1);
    }
    if (i != 2) {
        p->field_48[i] += e->field_0 >> 8;
    } else {
        p->field_48[2] -= e->field_0 >> 8;
    }
    return e->field_0 >> 8;
}

s32 func_80020E00(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->field_38;
    Obj20CE8 *e = &p->field_6C[i];

    func_80020CE8(e, 0);
    switch (i) {
    case 0:
    case 1:
        p->field_48[i] -= e->field_0 >> 8;
        break;
    case 2:
        p->field_48[2] += e->field_0 >> 8;
        break;
    }
    return e->field_0 >> 8;
}

void func_80020EB0(Ctx38 *arg0, s32 arg1, Elem12 *arg2) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->field_0 = arg2->field_0;
    e->field_4 = arg2->field_4;
    e->field_8 = arg2->field_8;
}

void func_80020EE8(Ctx38 *arg0, s32 arg1) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->field_8 = 0;
    e->field_4 = 0;
    e->field_0 = 0;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020F10);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020FD0);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002130C);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800216E4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80021838);

void func_800218CC(Tri218CC *t, s32 n, Obj21ABC *o, Col21ABC *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 *sxy;
    s32 *sz;
    Tag21ABC *pk;
    LineF4_21ABC *l;
    Tpage21ABC *tp;
    s32 idx;

    pk = (Tag21ABC *)D_8005F770.work;
    sxy = o->field_6C;
    sz = o->field_70;
    idx = o->field_3C;
    for (i = 0; i < n; i++, t++) {
        do {
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            ot = (u32 *)D_8005F770.field_138[idx];
            l = (LineF4_21ABC *)pk;
            l->c = *col;
            l->tag.len = 6;
            l->c.code = 0x4E;
            l->end = 0x55555555;
            l->xy[3] = l->xy[0] = sxy[t->v[0]];
            l->xy[1] = sxy[t->v[1]];
            l->xy[2] = sxy[t->v[2]];
            ot += z;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF4_21ABC *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F79C = (s32)pk;
}

void func_80021ABC(Quad21ABC *q, s32 n, Obj21ABC *o, Col21ABC *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 xy[4];
    s32 *sxy;
    s32 *sz;
    Tag21ABC *pk;
    LineF4_21ABC *l4;
    LineF2_21ABC *l2;
    Tpage21ABC *tp;
    s32 idx;

    pk = (Tag21ABC *)D_8005F770.work;
    sxy = o->field_6C;
    sz = o->field_70;
    idx = o->field_3C;
    for (i = 0; i < n; i++, q++) {
        do {
            z = (sz[q->v[0]] + sz[q->v[1]] + sz[q->v[2]] + sz[q->v[3]]) / 4;
            ot = (u32 *)D_8005F770.field_138[idx];
            xy[0] = sxy[q->v[0]];
            xy[1] = sxy[q->v[1]];
            xy[2] = sxy[q->v[2]];
            xy[3] = sxy[q->v[3]];
            l4 = (LineF4_21ABC *)pk;
            l4->c = *col;
            l4->tag.len = 6;
            l4->c.code = 0x4E;
            l4->end = 0x55555555;
            l4->xy[0] = xy[0];
            l4->xy[1] = xy[1];
            l4->xy[2] = xy[3];
            l4->xy[3] = xy[2];
            do {
            } while (0);
            ot += z;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF4_21ABC *)pk + 1);
            l2 = (LineF2_21ABC *)pk;
            l2->c = *col;
            l2->tag.len = 3;
            l2->c.code = 0x42;
            l2->xy[0] = xy[2];
            l2->xy[1] = xy[0];
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF2_21ABC *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F79C = (s32)pk;
}


void func_80021D50(void) {
}

void func_80021D58(void) {
}

s32 func_80021D60(void) {
    s32 best = 0;
    s32 i;
    s32 v;

    if (D_8005071C->field_BA8 != 0) {
        for (i = 0; i < D_8005071C->field_BA8; i++) {
            best = (best < (v = D_8005071C->field_BA9[i])) ? v : best;
        }
    }
    return best;
}


void func_80021DC8(void) {
    s32 i;
    V1004_21DC8 *p;

    i = 0x1F;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->a[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->b[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->c[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 0xF;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->d[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    D_8005F664 = 0;
}


s32 func_80021E54(u8 *arg0, s32 arg1) {
    s32 i = arg1 >> 3;
    s32 m = 1 << (arg1 & 7);

    return (arg0[i] & m) != 0;
}

/* file-local views over D_8005E620 for func_80021E78 */
typedef struct { u8 _p[0x66]; u16 a[1]; } V66_21E78;
typedef struct { u8 _p[0xDD4]; u16 a[1]; } VDD4_21E78;
typedef struct { u8 field_0; u8 field_1; u8 _p[0x5A]; } ElmV_21E78; /* 0x5C */
typedef struct { u8 _p[0xE4]; ElmV_21E78 elems[0x24]; } EntV_21E78;

extern s32 D_8005F624;
extern s32 D_8005F644;
extern s32 D_8005F64C;
extern s32 D_8005F654;
extern s32 D_8005F664;
extern s32 func_80021E54(u8 *, s32);
extern s32 func_80066B48(s32);

s32 func_80021E78(s32 arg0) {
    s32 i;

    if (arg0 < 0x258) {
        return func_80021E54(&D_8005F624, arg0);
    }
    if (arg0 < 0x2BC) {
        return func_80021E54(&D_8005F644, arg0 - 0x258);
    }
    if (arg0 < 0x320) {
        return func_80021E54(&D_8005F64C, arg0 - 0x2BC);
    }
    if (arg0 < 0x3E8) {
        return func_80021E54(&D_8005F654, arg0 - 0x320);
    }
    if (arg0 < 0x44C) {
        return D_8005F664 >= arg0 - 0x3E8;
    }
    if (arg0 < 0x640) {
        return D_8005F664 < arg0 - 0x5DC;
    }
    if (arg0 < 0x8BD) {
        for (i = 0; i < 0x30; i++) {
            if (((V66_21E78 *)&D_8005E620)->a[i] == arg0 - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (arg0 < 0xBB8) {
        return ((VDD4_21E78 *)&D_8005E620)->a[arg0 - 0x7D0] != 0;
    }
    if (arg0 < 0xFA0) {
        s32 key = arg0 - 0xBB8;
        for (i = 0; i < 0x24; i++) {
            if (((EntV_21E78 *)&D_8005E620)->elems[i].field_1 == key) {
                if (((EntV_21E78 *)&D_8005E620)->elems[i].field_0 >= 2) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (func_80013378() == 2) {
        return func_80066B48(arg0);
    }
    return 0;
}

typedef struct {
    s16 id;
    s16 flag;
} Ent22038;

s32 func_80022038(Ent22038 *p) {
    s32 i;
    for (i = 0; i < 6; i++, p++) {
        if (p->id != -1) {
            if (p->flag != 0) {
                if (func_80021E78(p->id) != 1) {
                    return 0;
                }
            } else {
                if (func_80021E78(p->id) != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


void func_800220D0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 >> 3;
    s32 mask = 1 << (arg1 & 7);
    if (arg2 != 0) {
        arg0[idx] |= mask;
    } else {
        arg0[idx] &= ~mask;
    }
}

void func_80022118(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (D_8005E620.elems[i].field_0 == 0) {
            break;
        }
    }
    func_8001DC24(arg0, 0, &D_8005E620.elems[i]);
    func_80022AE4();
    for (i = 0; i < 3; i++) {
        D_8005E620.elems[i].field_0 =
            (D_8005E620.elems[i].field_0 >= 2) ? (i + 3) : 0;
    }
}

void func_800221C4(s32 id, s32 val) {
    if (id < 600) {
        if (id == 0x10 && val == 0) {
            func_800220D0((u8 *)&D_8005F624, 0x11, 0);
        }
        func_800220D0((u8 *)&D_8005F624, id, val);
    } else if (id < 700) {
        func_800220D0((u8 *)&D_8005F644, id - 600, val);
    } else if (id < 800) {
        func_800220D0((u8 *)&D_8005F64C, id - 700, val);
    } else if (id < 1000) {
        func_800220D0((u8 *)&D_8005F654, id - 800, val);
    } else if (id < 2000) {
        D_8005F664 = id - 1900;
    } else if (id < 0x8BD) {
        D_8005E6E4 = id - 2000;
        func_800226AC();
    } else if (id < 3000) {
        ((VDD4_21E78 *)&D_8005E620)->a[id - 2000]++;
    } else if (id < 4000) {
        switch (id - 3000) {
        case 3:
            func_80022118(0xB7);
            break;
        case 31:
            func_80022118(0xB6);
            break;
        case 217:
            func_80022118(0xB8);
            break;
        }
    } else if (id < 10000) {
        if (func_80013378() == 2) {
            func_80066F34(id, val);
        }
    }
}

void func_80022388(Pair22388 *p) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (p[i].field_0 != -1) {
            func_800221C4(p[i].field_0, p[i].field_2);
        }
    }
}

s32 func_800223EC(s32 v, s32 div, s32 lo, s32 hi) {
    s32 r;
    v /= div;
    if (lo < hi) {
        r = v % (hi - lo + 1);
        return r + lo;
    } else {
        r = v % (lo - hi + 1);
        return lo - r;
    }
}


s32 func_80022430(s32 v, s32 div, s32 lo, s32 hi) {
    s32 span;
    s32 r;

    v /= div;
    span = hi - lo;
    r = v % (span * 2);
    if (r < span) {
        return r + lo;
    }
    return hi - (r - span);
}


void func_80022468(void) {
    func_80022F8C(D_80050720, 0x1058);
    D_80050720->field_0 = 1;
    func_80021DC8();
    D_8005E620.field_14 = 0x8F;
    D_8005E620.field_15 = 0x95;
    D_8005E620.field_16 = 0xB7;
    D_8005E620.field_17 = 0xFF;
    D_8005E620.field_8 = 0x1F4;
    D_8005E620.field_D1 = 0x9E;
    D_8005E620.field_D2 = 0xD5;
    D_8005E620.field_D3 = 0x96;
    D_8005E620.field_D4 = 0xFF;
    D_8005E620.field_4 = 0;
}


void func_800224EC(s32 i, s32 v, s32 flag) {
    Obj50720 *p = D_80050720;
    u8 *q = &p->field_52[i];

    p->field_2C[i] = v;
    if (v != 0) {
        *q = flag;
        return;
    }
    *q = 1;
}


s32 func_80022518(s32 i) {
    Obj50720 *p = D_80050720;
    if (p->field_52[i] == 1) {
        return -1;
    }
    return p->field_2C[i];
}


void func_8002254C(s32 i, s32 v) {
    s32 r = 0;
    Obj50720 *p = D_80050720;
    u16 t = p->field_2C[i];
    u8 *q = &p->field_52[i];

    if (t != 0) {
        r = v;
    }
    *q = r;
}


u8 func_80022578(void) {
    u8 result = 0;
    s32 v = func_80022518(2) - 0x2F;
    if ((u32)v < 6) {
        result = D_800416FC[v];
    }
    return result;
}

s32 func_800225C4(void) {
    s32 r;
    s32 n;
    s32 i;

    r = -1;
    n = func_8002281C();
    for (i = 0; i < n; i++) {
        if (D_80050720->field_66[i] == 0) {
            r = i;
            goto done;
        }
    }
done:
    return r;
}


void func_80022628(void) {
    u16 *src;
    u16 *dst;
    s32 i;
    s32 v;

    src = D_80050720->field_66;
    dst = src;
    for (i = 0; i < 0x30; i++, src++) {
        v = *src;
        *src = 0;
        if (((s32 (*)(s32))func_8001E108)(v & 0xFFFF) == 0) {
            *dst = v;
            if ((v & 0xFFFF) != 0) {
                dst++;
            }
        }
    }
}


void func_800226AC(void) {
    u16 *base = D_80050720->field_66;
    u16 *pi;
    s32 i;
    s32 j;
    s32 best;
    s32 bestv;
    s32 v;
    u16 t;

    func_80022628();
    pi = base;
    for (i = 0; i < 0x2F; i++, pi++) {
        if (*pi == 0) {
            return;
        }
        best = i;
        bestv = func_8001E1D0(*pi);
        for (j = i + 1; j < 0x30; j++) {
            if (base[j] == 0) {
                break;
            }
            v = func_8001E1D0(base[j]);
            if (v < bestv) {
                best = j;
                bestv = v;
            }
        }
        if (best != i) {
            t = *pi;
            *pi = base[best];
            base[best] = t;
        }
    }
}


s32 func_800227A8(s32 id) {
    s32 i = func_800225C4();
    if (i != -1) {
        D_80050720->field_66[i] = id;
    }
    return i;
}


void func_800227F0(s32 i) {
    D_80050720->field_66[i] = 0;
    func_80022628();
}


s32 func_8002281C(void) {
    u16 v = D_80050720->field_34;
    s32 r = v - 0x49;
    s32 ret = 8;
    if ((u32)(v - 0x4B) < 5) {
        ret = r * 8;
    }
    return ret;
}


s32 func_8002284C(s32 mode) {
    s32 n = 0;
    s32 i;
    ElmE620 *e = D_80050720->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->field_0 == mode) n++;
            break;
        case 2:
            if (e->field_0 >= 2) n++;
            break;
        case 3:
            if (e->field_0 >= 3) n++;
            break;
        case 4:
            if (e->field_0 == 2) n++;
            break;
        }
    }
    return n;
}


s32 func_80022910(s32 mode, ElmE620 **list) {
    s32 n = 0;
    s32 i;
    ElmE620 **p = list;
    ElmE620 *e = D_80050720->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->field_0 == mode) {
                *p++ = e;
                n++;
            }
            break;
        case 2:
            if (e->field_0 >= 2) {
                *p++ = e;
                n++;
            }
            break;
        case 3:
            if (e->field_0 >= 3) {
                p++;
                list[e->field_0 - 3] = e;
                n++;
            }
            break;
        case 4:
            if (e->field_0 == 2) {
                *p++ = e;
                n++;
            }
            break;
        }
    }
    return n;
}


void func_800229F4(void) {
    ElmE620 tmp;
    ElmE620 *src;
    ElmE620 *dst;
    s32 i;

    src = D_80050720->elems;
    dst = src;
    for (i = 0; i < 0x24; i++, src++) {
        tmp = *src;
        src->field_0 = 0;
        if (tmp.field_0 != 0) {
            *dst = tmp;
            if (dst->field_0 != 0) {
                dst++;
            }
        }
    }
}


void func_80022AE4(void) {
    Tbl50724 tbl = D_80050724[0];
    ElmE620 *base = D_80050720->elems;
    ElmE620 tmp;
    s32 i;
    s32 j;
    s32 best;
    s32 bestk;
    s32 k;

    func_800229F4();
    for (i = 0; i < 0x23; i++) {
        if (base[i].field_0 == 0) {
            return;
        }
        best = i;
        bestk = base[i].field_1 + (999 - base[i].field_D) * 1000 + tbl.b[base[i].field_0] * 1000000;
        for (j = i + 1; j < 0x24; j++) {
            if (base[j].field_0 == 0) {
                break;
            }
            k = base[j].field_1 + (999 - base[j].field_D) * 1000 + tbl.b[base[j].field_0] * 1000000;
            if (k < bestk) {
                best = j;
                bestk = k;
            }
        }
        if (best != i) {
            tmp = base[i];
            base[i] = base[best];
            base[best] = tmp;
        }
    }
}


void func_80022D84(ActorWork *arg0) {
    Node22D84 *n = (Node22D84 *)((u8 *)arg0 - 0xC);
    Node22D84 *m = n->field_0;
    Node22D84 *nx = n->field_4;
    n->field_8 = 0;
    if (nx->field_8 == 0) {
        n->field_4 = nx->field_4;
        nx->field_4->field_0 = n;
    }
    if (m->field_8 == 0) {
        m->field_4 = n->field_4;
        n->field_4->field_0 = m;
    }
}

void func_80022DEC(s32 tag) {
    Blk22E60 *b = D_80050788;

    if (b->field_8 != 1) {
        do {
            if (b->field_8 == tag) {
                func_80022D84((ActorWork *)(b + 1));
            }
            b = b->field_4;
        } while (b->field_8 != 1);
    }
}


void func_80022E60(Blk22E60 *heap, s32 size) {
    Blk22E60 *end;

    D_80050784 = size;
    D_80050788 = heap;
    end = (Blk22E60 *)((u8 *)heap + size) - 1;
    heap->field_0 = NULL;
    heap->field_4 = end;
    heap->field_8 = 0;
    end->field_0 = heap;
    end->field_4 = NULL;
    end->field_8 = 1;
}


s32 func_80022E90(s32 arg0, s32 tag) {
    u32 size = ((u32)(arg0 + 3) >> 2) << 2;
    Blk22E60 *b = D_80050788;
    Blk22E60 *n;
    u32 avail;
    u32 lim = size + 0x14;

    if (b->field_8 != 1) {
        do {
            if (b->field_8 == 0) {
                avail = (s32)b->field_4 - (s32)b - 0xC;
                if (avail >= size) {
                    if (lim < avail) {
                        n = (Blk22E60 *)((u8 *)b + size + 0xC);
                        n->field_0 = b;
                        n->field_4 = b->field_4;
                        n->field_8 = 0;
                        b->field_4->field_0 = n;
                        b->field_4 = n;
                    }
                    b->field_8 = tag;
                    return (s32)(b + 1);
                }
            }
            b = b->field_4;
        } while (b->field_8 != 1);
    }
    return 0;
}


s32 func_80022F3C(s32 arg0, s32 arg1) {
    s32 r;
    while ((r = func_80022E90(arg0, arg1)) == 0) {
        func_80023BB0();
    }
    return r;
}

void func_80022F8C(void *a0, s32 a1) {
    s32 i;
    if (a1 & 3) {
        u8 *b = (u8 *)a0;
        for (i = 0; i < a1; i++) b[i] = 0;
    } else {
        s32 *w = (s32 *)a0;
        a1 >>= 2;
        for (i = 0; i < a1; i++) *w++ = 0;
    }
}

void func_80022FE8(s32 *tbl) {
    Blk22E60 *b = D_80050788;

    if (b->field_8 != 1) {
        do {
            tbl[b->field_8] += (s32)b->field_4 - (s32)b;
            b = b->field_4;
        } while (b->field_8 != 1);
    }
}


u32 func_80023044(void) {
    Blk22E60 *b = D_80050788;
    u32 best = 0;
    u32 sz;

    while (b->field_8 != 1) {
        if (b->field_8 == 0) {
            sz = (s32)b->field_4 - (s32)b;
            if (best < sz) {
                best = sz;
            }
        }
        b = b->field_4;
    }
    return best;
}


void func_800230AC(void) {
    func_80024654(D_8005F6A8, D_8005F6A8 + 0x22);
    func_80024544();
}

void func_800230DC(Rec230DC *arg0) {
    arg0->field_C = 0;
    arg0->field_15 = 0;
    arg0->field_14 = 0;
    arg0->field_10 = 0;
    arg0->field_8 = 0;
    arg0->field_4 = 0;
    arg0->field_8 = 0;
}

void func_800230FC(Rec230DC *p, u8 *buf) {
    s32 n;

    p->field_8 = p->field_4;
    p->field_4 = ((buf[2] << 8) + buf[3]) ^ 0xFFFF;
    p->field_0 = (p->field_8 ^ p->field_4) & p->field_4;
    if (p->field_8 != p->field_4) {
        p->field_10 = p->field_0;
        p->field_14 = 0;
        p->field_15 = 0;
        return;
    }
    n = ++p->field_15;
    if (p->field_14 == 0) {
        if (n >= 11) {
            goto rep;
        }
    } else if (n >= 4) {
    rep:
        p->field_14 = 1;
        p->field_15 = 0;
        p->field_10 = p->field_4;
        return;
    }
    p->field_10 = 0;
}

void func_800231AC(Elm6A8 *a0, s32 i) {
    switch (func_80024474(i << 4)) {
    case 2:
    case 6:
        switch (D_8005F678[i].field_C) {
        case 0:
        default:
            func_800230DC((Rec230DC *)&D_8005F678[i]);
            D_8005F678[i].field_C = 1;
            break;
        case 1:
            func_800230FC(&D_8005F678[i], a0);
            break;
        }
        break;
    case 0:
    default:
        D_8005F678[i].field_C = 0;
        break;
    }
}

s32 func_80023270(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (arg0 & arg2) {
        r = 1;
    } else if (arg1 & arg2) {
        r = -1;
    }
    return r;
}

void func_8002329C(void) {
    s32 i;
    Elm6A8 *a8 = (Elm6A8 *)D_8005F6A8;

    for (i = 0; i < 2; i++) {
        if (a8[i].field_0 != 0) {
            D_8005F678[i].field_C = 0;
            D_8005F678[i].field_4 = 0;
            D_8005F678[i].field_0 = 0;
            D_8005F678[i].field_10 = 0;
            D_8005F6F0[i].field_3E = 0;
        } else if ((a8[i].field_1 >> 4) == 4) {
            func_800231AC(&a8[i], i);
            D_8005F6F0[i].field_3E = 1;
        } else {
            D_8005F678[i].field_4 = 0;
            D_8005F678[i].field_0 = 0;
            D_8005F678[i].field_10 = 0;
            D_8005F6F0[i].field_3E = 0;
        }
        D_8005F6F0[i].field_8 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x1000);
        D_8005F6F0[i].field_C = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x4000);
        D_8005F6F0[i].field_0 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x2000);
        D_8005F6F0[i].field_4 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x8000);
        D_8005F6F0[i].field_10 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x20);
        D_8005F6F0[i].field_14 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x40);
        D_8005F6F0[i].field_1C = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x10);
        D_8005F6F0[i].field_18 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x80);
        D_8005F6F0[i].field_28 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x4);
        D_8005F6F0[i].field_2C = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x1);
        D_8005F6F0[i].field_20 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x8);
        D_8005F6F0[i].field_24 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x2);
        D_8005F6F0[i].field_30 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x100);
        D_8005F6F0[i].field_34 = func_80023270(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x800);
        D_8005F6F0[i].field_38 = D_8005F678[i].field_4;
        D_8005F6F0[i].field_3A = D_8005F678[i].field_0;
        D_8005F6F0[i].field_3C = D_8005F678[i].field_10;
    }
}

void func_80023484(void) {
    s32 t = ((Db5F770 *)&D_8005F770)->field_4 - (((Db5F770 *)&D_8005F770)->field_4 != 0);

    if (D_8005078C != 0 && D_8005072C >= t) {
        ((Db5F770 *)&D_8005F770)->field_28 = (((Db5F770 *)&D_8005F770)->field_28 == 0);
        func_80027CB0(&((Db5F770 *)&D_8005F770)->disp[((Db5F770 *)&D_8005F770)->field_28]);
        func_80027AE4(&((Db5F770 *)&D_8005F770)->draw[((Db5F770 *)&D_8005F770)->field_28]);
        func_8001C858(((Db5F770 *)&D_8005F770)->field_28 ^ 1);
        D_8005078C = 0;
        D_8005072C = 0;
    } else {
        D_8005072C++;
    }
    func_80031854();
}


void func_80023550(void) {
    Rect23550 r;
    TimInfo2BBD4 tim;
    u8 buf;
    s32 slot;
    s32 i;
    s32 t;
    s32 d;
    s32 u;

    func_80010D74();
    func_80030CD4();
    func_80030AB4(0);
    func_800273E8(0);
    func_80027104(0);
    func_80030D64((s32)func_80023484);
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x1FF;
    func_80027604((s32)&r, 0, 0, 0);
    func_80027480(0);
    func_8002AC54(0x140, 0xF0, 1, 1, 0);
    func_8002B4C4();
    func_80032914();
    func_8002CE5C();
    func_8001C1E0(0x140, 0x280, 1, 0);
    func_80027AE4(&((Db5F770 *)&D_8005F770)->draw[0]);
    func_80027CB0(&((Db5F770 *)&D_8005F770)->disp[0]);
    func_80030AB4(0);
    func_8002BBD4((u32 *)(D_80010000[0] + 4), &tim);
    func_80030AB4(0);
    func_8002772C((s32)&D_80050730, (s32)tim.paddr);
    func_80027480(0);
    func_80030AB4(0);
    func_800273E8(1);
    func_8002DC04();
    func_800304B4(0);
    func_80027278(0);
    func_80022E60(D_800506F8[0], 0x801FF000 - (s32)D_800506F8[0]);
    func_80023A38();
    func_8001A75C();
    D_8005F770.field_0 = 0;
    ((Db5F770 *)&D_8005F770)->field_4 = 0;
    D_8005F770.field_28 = 1;
    func_8001C934();
    func_8001C800(0);
    func_8001C760();
    func_800238E4(0);
    ((void (*)(s32))func_8003D4A4)(0);
    func_8003DD00();
    func_800230AC();
    buf = 0x80;
    while (((s32 (*)(s32, u8 *, s32))func_80030554)(0xE, &buf, 0) == 0) {
    }
    func_80030AB4(3);
    func_800307C4(9, 0, 0);
    func_80011190();
    func_8001CA3C();
    func_8001C818(0);
    func_8001C818(1);
    D_8005F770.field_0 = 1;
    D_8005F770.field_18 = 0x402;
    D_8005F770.field_1C = 0x402;
    ((Db5F770 *)&D_8005F770)->field_24 = 0;
    D_8005F770.field_C = 0;
    func_80022468();
    D_8005071C->field_0 = 0;
    func_8001C56C();
    func_8001C584();
    slot = 0;
    for (;;) {
        if (slot == 0) {
            func_80011190();
            func_8001C934();
            func_80022DEC(2);
            func_8001C818(0);
            func_8001C818(1);
            t = D_8005F770.field_18;
            u = D_8005F770.field_1C;
            D_8005F770.field_1C = 0;
            D_8005F770.field_20 = t;
            D_8005F770.field_18 = u;
            for (i = 0; i < 0x11; i++) {
                func_800221C4(i, 0);
            }
            func_8001107C(1, &slot, 0);
        }
        func_8001C584();
        D_8005F770.field_14 = 0;
        slot = func_80010EA4((void *)slot);
        D_8005F770.field_14 = 1;
        slot = func_80010EA4((void *)slot);
        func_8001C898(D_8005F770.field_28);
        func_80027480(0);
        D_8005078C = 1;
        while (*(volatile s32 *)&D_8005078C != 0) {
        }
        func_8001C988();
        func_8001C760();
        func_8001C818(D_8005F770.field_28);
        t = func_80030AB4(-1);
        u = D_80050738;
        D_80050738 = t;
        d = t - u;
        D_8005F770.field_8 = d;
        D_8005E620.field_4 += d;
        if (d > 6) {
            D_8005F770.field_8 = 6;
        }
        D_8005F770.field_0++;
        func_8002329C();
        func_800238F4();
        func_80023C74();
        func_8001A01C();
    }
}


void func_800238E4(s32 a0) {
    D_80050790 = a0 & 0xFFF;
}


void func_800238F4(void) {
    D_80050790 = (D_80050790 + 1) & 0xFFF;
}


s32 func_80023910(void) {
    func_800238F4();
    return D_80041704[D_80050790];
}


u16 func_80023944(u32 arg0) {
    return D_80041704[arg0 & 0xFFF];
}

void func_80023964(void) {
    D_8005F774 = 0;
}

void func_80023970(void) {
    D_8005F774 = 2;
}

void func_80023980(void) {
    D_8005F774 = 3;
}

void func_80023990(void) {
    D_8005F774 = 4;
}

EntA0 *func_800239A0(u32 arg0) {
    u32 index;
    u8 *base;
    if (arg0 == 0) {
        return 0;
    }
    index = arg0 & 0xFFFF;
    base = (u8 *)func_80023DB0(arg0 >> 16);
    return (EntA0 *)(((u32 *)base)[index] + (u32)base);
}

s32 func_800239E4(s32 arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg1[(u16)arg0] + (s32)arg1;
}

s32 func_80023A08(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_80023DB0(arg0);
}

void func_80023A38(void) {
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        p->field_4 = 0;
        p->field_C = 0;
        p->field_0 = 0;
        p->field_2 = 0;
        p->field_8 = 0;
    }
}

Ent23A78 *func_80023A78(arg0)
s32 arg0;
{
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == arg0) return p;
    }
    return NULL;
}

Ent23A78 *func_80023AB0(void) {
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) return p;
    }
    return NULL;
}

Ent23AE8 *func_80023AE8(void) {
    s32 min = D_8005F770.field_0;
    Ent23A78 *p = D_8005F8C8;
    Ent23A78 *best = 0;
    s32 i;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) continue;
        if (p->field_2 != 0) continue;
        if (p->field_0 != 3) continue;
        if (min < p->field_8) continue;
        min = p->field_8;
        best = p;
    }
    return (Ent23AE8 *)best;
}

s32 func_80023B70(s32 arg0) {
    Ent23A78 *e = func_80023A78(arg0);

    if (e != 0) {
        e->field_8 = D_8005F770.field_0;
        return e->field_0;
    }
    return 0;
}

void func_80023BB0(void) {
    Ent23AE8 *p = func_80023AE8();
    func_80022D84(p->field_C);
    p->field_4 = 0;
    p->field_C = 0;
    p->field_8 = 0;
    p->field_0 = 0;
    p->field_2 = 0;
}

void func_80023BF4(s32 id) {
    Ent23A78 *p = func_80023A78(id);

    if (p != NULL) {
        p->field_8 = D_8005F770.field_0;
        return;
    }
    p = func_80023AB0();
    p->field_4 = id;
    p->field_C = func_80022F3C(func_80023F90(id) << 11, 3);
    p->field_0 = 1;
    p->field_8 = 0;
    D_80050750 = 1;
}


void func_80023C74(void) {
    s32 started;
    s32 busy;
    s32 i;
    Ent23A78 *p;

    if (D_80050750 == 0) {
        return;
    }
    if (func_80024220() != 0) {
        return;
    }
    p = D_8005F8C8;
    started = 0;
    busy = 0;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) {
            continue;
        }
        if (p->field_0 != 1) {
            if (p->field_0 == 2) {
                p->field_0 = 3;
                p->field_8 = D_8005F770.field_0;
                busy = 1;
            }
        } else {
            busy = 1;
            if (started == 0) {
                func_80024260(p->field_4, p->field_C);
                p->field_0 = 2;
                p->field_8 = D_8005F770.field_0;
                started = busy;
            }
        }
    }
    if (busy == 0) {
        D_80050750 = 0;
    }
}


void func_80023D68(s32 arg0) {
    func_80023BF4(arg0);
    do {
        func_80023C74();
    } while (func_80023B70(arg0) != 3);
}

s32 func_80023DB0(s32 arg0) {
    Ent23A78 *p = func_80023A78(arg0);
    if (p != 0 && p->field_0 == 3) {
        p->field_8 = D_8005F770.field_0;
    } else {
        while (func_80024220() != 0) {
        }
        func_80023D68(arg0);
    }
    return func_80023A78(arg0)->field_C;
}

void func_80023E20(void) {
    Ent23A78 *p = func_80023A78();
    if (p != 0) {
        if (p->field_0 == 3) {
            func_80022D84(p->field_C);
            p->field_4 = 0;
            p->field_C = 0;
            p->field_8 = 0;
            p->field_0 = 0;
        }
    }
}

void func_80023E78(s32 a0) {
    Ent23A78 *p = func_80023A78();
    if (p != 0) {
        if (p->field_0 == 3) {
            p->field_2 = 1;
        }
    }
}

void func_80023EB8(s32 a0) {
    Ent23A78 *p = func_80023A78();
    if (p != 0) {
        if (p->field_0 == 3) {
            p->field_2 = 0;
        }
    }
}

void func_80023EF8(void) {
    s32 i;
    for (i = 0; i < 0x50; i++) {
        if (D_8005F8C8[i].field_4 != 0 && D_8005F8C8[i].field_2 == 0) {
            func_80022D84(D_8005F8C8[i].field_C);
            D_8005F8C8[i].field_4 = 0;
            D_8005F8C8[i].field_C = 0;
            D_8005F8C8[i].field_8 = 0;
            D_8005F8C8[i].field_0 = 0;
        }
    }
}

s32 func_80023F74(s32 arg0) {
    return D_80043794[arg0] != 0;
}

s32 func_80023F90(s32 arg0) {
    return D_80047100[arg0];
}

s32 func_80023FAC(s32 arg0) {
    return D_80043794[arg0];
}

void func_80023FC8(s32 arg0, void *arg1) {
    func_80030394(D_80043794[arg0]);
}

s32 func_80023FFC(void) {
    s32 x;
    func_80030914(D_8005FDC8, 3);
    x = func_8002DD64(D_8005FDC8);
    if (x == D_80048DB8.field_1C) {
        D_80048DB8.field_1C = x + 1;
        return 0;
    }
    return -1;
}

void func_8002405C(s32 a0) {
    if (a0 == 1 && func_80023FFC() == 0) {
        func_80030914((void *)D_80048DB8.field_8, 0x200);
        D_80048DB8.field_8 += 0x800;
        D_80048DB8.field_4 -= 1;
        if (D_80048DB8.field_4 != 0) {
            return;
        }
    } else {
        D_80048DB8.field_4 = -1;
    }
    func_80030534(0);
    func_80030690(9, 0);
}

void func_800240E8(s32 ev) {
    if (ev == 5) {
        if (D_80048DB8.field_0 == 4) {
            func_80030690(9, 0);
        } else {
            D_80048DB8.field_0 = 0;
            D_80048DB8.field_4 = D_80048DB8.field_10;
            func_80024260(D_80048DB8.field_14, D_80048DB8.field_18);
        }
    } else if (ev == 2) {
        switch (D_80048DB8.field_0) {
        case 1:
            D_80048DB8.field_C = 0xA0;
            func_80030690(14, &D_80048DB8.field_C);
            D_80048DB8.field_0++;
            break;
        case 2:
            func_80030534((s32)func_8002405C);
            func_80030690(6, 0);
            D_80048DB8.field_0++;
            break;
        case 3:
            D_80048DB8.field_0 = 4;
            break;
        case 4:
            if (D_80048DB8.field_4 == 0) {
                D_80048DB8.field_0 = 5;
                func_80030514(0);
            } else {
                D_80048DB8.field_0 = 0;
                D_80048DB8.field_4 = D_80048DB8.field_10;
                func_80024260(D_80048DB8.field_14, D_80048DB8.field_18);
            }
            break;
        }
    }
}

s32 func_80024220(void) {
    switch (D_80048DB8.field_0) {
    case 0:
        return 0;
    case 5:
        D_80048DB8.field_0 = 0;
        return 2;
    }
    return 1;
}

void func_80024260(s32 arg0, s32 arg1) {
    u8 sp10[8];
    s32 r;

    if (D_80048DB8.field_0 != 0) {
        while (func_80024220() != 0) {}
    }
    func_80023FC8(arg0, sp10);
    r = func_80023F90(arg0);
    D_80048DB8.field_4 = r;
    D_80048DB8.field_8 = arg1;
    D_80048DB8.field_10 = r;
    D_80048DB8.field_14 = arg0;
    D_80048DB8.field_18 = arg1;
    D_80048DB8.field_1C = func_80023FAC(arg0);
    D_80048DB8.field_0 += 1;
    func_80030514(func_800240E8);
    func_80030690(2, sp10);
}

void func_80024310(Actor *arg0, Block1C *arg1) {
    *(Block1C *)arg0->work = *arg1;
}

void func_80024350(Actor *arg0) {
    ActorWork *work = arg0->work;

    switch (arg0->field_10) {
    case 0:
        func_80020C40((ContC40 *)arg0, &work->field_8, work->field_14);
        func_8001FDBC(arg0, work->field_0)->field_3C = 3;
        func_8001F24C(arg0, 0, work->field_4);
        func_80011544(arg0);
        break;
    case 1: {
        Sub3C *s = arg0->field_3C;
        if (arg0->field_28 < work->field_18 && s->field_60 >= 0)
            break;
        func_800115C0(arg0, 3);
        break;
    }
    case 2:
        break;
    }
}

void func_80024410(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->field_10 == 1) {
        func_8001FDBC(arg0, w->field_0);
        func_8001F320(arg0);
        func_80020920(arg0);
        func_800200D0(arg0);
        func_80020510(arg0, 0);
    }
}

u8 func_80024474(void) {
    Obj25FBC *o = D_80048E2C();

    if (o->field_37 != 0 || o->field_38 != 0 || (o != o->field_10 && o->field_39 != 0)
        || *o->field_30 != 0) {
        switch (o->field_49) {
        case 3:
            return 1;
        case 2:
            return 1;
        case 6:
            return 4;
        }
    }
    return o->field_49;
}

void func_80024544(void) {
    State60058 *p = &D_80060058;

    D_80048E50 = 0;
    func_80026FC4();
    func_80026FF4(2, D_80048E78);
    func_80026FE4(2, D_80048E78);
    D_80048DF0->field_0 = -2;
    D_80048DF0->field_4 |= 1;
    func_80027004(3, 0);
    func_80026FD4();
    D_80048E1C(D_80048E4C);
    D_80048E1C(&D_80048E4C[1]);
    p->field_4 = 0;
    p->field_0 = 0;
    D_80048E50 = 1;
}

void func_80024610(void) {
    func_80026FC4();
    func_80027004(3, 1);
    func_80026FF4(2, D_80048E78);
    func_80026FD4();
}

void func_80024654(u8 *a0, u8 *a1) {
    Obj25FBC *base;
    Obj25FBC *p;
    u8 *q;
    s32 i;
    s32 j;

    D_80048E50 = 0;
    D_80048E64 = 0;
    func_80024704();
    base = D_80048E4C;
    base[0].field_30 = a0;
    base[1].field_30 = a1;
    p = base;
    for (i = 0; i < 2; i++, p++) {
        q = p->field_5D;
        p->field_C = 0;
        p->field_10 = p;
        p->field_30[0] = 0xFF;
        p->field_30[1] = 0;
        for (j = 5; j >= 0; j--) {
            *q++ = 0xFF;
        }
    }
    D_80048E50 = 1;
}


void func_80024704(void) {
    Obj25FBC *o = (Obj25FBC *)D_8005FDD8;

    func_80027014((u8 *)o, 0x1E0);
    o[0].field_3C = D_8005FFB8;
    o[0].field_40 = D_80060000;
    o[1].field_3C = &D_8005FFB8[0x23];
    D_80048E18 = func_8002485C;
    D_80048E1C = func_800247F4;
    D_80048E20 = func_80024960;
    D_80048E24 = (void (*)(Ent266D0 *))func_80024A1C;
    D_80048E2C = (Obj25FBC *(*)(void))func_80024C98;
    D_80048E3C = func_80024950;
    D_80048E30 = func_80024CB8;
    D_80048E34 = (s32 (*)(void))func_80025114;
    D_80048E4C = o;
    o[1].field_40 = &D_80060000[0x23];
    D_80048E38 = func_80024DC8;
}

void func_800247F4(Obj25FBC *a0) {
    u8 *p;
    s32 k;
    u8 c;

    if (a0->field_49 != 0) {
        p = a0->field_5D;
        c = 0xFF;
        k = 5;
        a0->field_49 = 0;
        a0->field_46 = 0;
        a0->field_E6 = 0;
        a0->field_14 = 0;
        a0->field_18 = 0;
        a0->field_E3 = 0;
        a0->field_E4 = 0;
        a0->field_E6 = 0;
        a0->field_E9 = 0;
        a0->field_EA = 0;
        a0->field_0 = 0;
        a0->field_4 = 0;
        a0->field_8 = 0;
        do {
            *p = c;
            k--;
            p++;
        } while (k >= 0);
    }
}

void func_8002485C(s32 code) {
    Obj25FBC *o;
    s32 done;

    do {
        o = &((Obj25FBC *)D_8005FDD8)[D_80048E58];
        if (code != -9) {
            if (code == 0) {
                *(D_80048E70 + D_80048E58) = 0;
            } else {
                func_80025034(o);
                func_80024950((Actor *)o);
            }
        }
        D_80048E5C = 0;
        D_80048E00->field_A = 0;
        D_80048E58++;
        if (D_80048E58 <= D_80048E6C) {
            done = func_8002533C(&((Obj25FBC *)D_8005FDD8)[D_80048E58]);
        } else {
            done = 1;
        }
        code = 0xFFFF;
    } while (done == 0);
}


s32 func_80024950(Actor *arg0) {
    s32 tmp = arg0->u34.b.field_37;
    arg0->u34.b.field_37 = 0;
    arg0->u38.field_38 = tmp;
    return tmp;
}

s32 func_80024960(Ent266D0 *e, s32 a1) {
    Obj25FBC *a0 = (Obj25FBC *)e;
    s32 i = a0->field_45 - 3;

    switch (a0->field_37) {
    case 0:
        if (i < 6 && a0->field_57[i] == 0) {
            return 0;
        }
        if (i < a0->field_34) {
            return a0->field_28[i];
        }
        return 0;
    case 0x4D:
        if (i < a0->field_36) {
            return a0->field_2C[i];
        }
        return 0xFF;
    default:
        if (i < a0->field_36) {
            return a0->field_2C[i];
        }
        return 0;
    }
}


void func_80024A1C(Obj25FBC *a0) {
    s32 n;
    s32 i;
    s32 j;
    s32 found;
    s32 mask;
    s32 s;
    u8 *p;
    u8 *q;

    func_80027014(a0->field_57, 6);
    if (a0->field_E6 != 0 && a0->field_28 != 0) {
        n = 6;
        if (a0->field_34 < 7) {
            n = a0->field_34;
        }
        for (i = 0; i < a0->field_E9; i++) {
            found = 0;
            mask = 1;
            if (a0->field_4[i].field_2 != 0) {
                mask = 0xFF;
            }
            p = a0->field_5D;
            q = a0->field_28;
            for (j = 0; j < n; p++, j++, q++) {
                if (*p == i && (*q & mask)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                s = D_80048E60 + a0->field_4[i].field_3;
                if (s < 0x3D) {
                    D_80048E60 = s;
                } else {
                    found = 0;
                }
                if (found) {
                    p = a0->field_5D;
                    q = a0->field_57;
                    for (j = 0; j < n; j++, q++) {
                        if (*p++ == i) {
                            *q = 1;
                        }
                    }
                }
            }
        }
        return;
    }
    if ((a0->field_E8 - 4U < 2 || a0->field_E8 == 7) && a0->field_E6 == 0 && a0->field_34 >= 2) {
        if ((a0->field_28[0] & 0xC0) == 0x40 && (a0->field_28[1] & 1) && D_80048E60 + 10 < 0x3D) {
            a0->field_57[1] = 1;
            a0->field_57[0] = 1;
            D_80048E60 += 10;
        }
        return;
    }
    if (*(volatile u8 *)&a0->field_E8 == 3) {
        a0->field_57[0] = 1;
        return;
    }
    if (a0->field_E6 == 0) {
        for (i = 0; i < 6; i++) {
            a0->field_57[i] = 1;
        }
    }
}

u8 *func_80024C98(s32 arg0) {
    u8 *p = D_8005FDD8;

    if (arg0 & 0xF0) {
        p += 0xF0;
    }
    return p;
}

s32 func_80024CB8(Obj25FBC *a0) {
    if (*a0->field_3C == 0xF3) {
        if (a0->field_E8 == 0) {
            func_80026568((Actor *)a0, 0);
            return 0;
        }
        if (a0->field_46 == 0xFF) {
            goto stop;
        }
        if (a0->field_49 == 2) {
            D_80048E1C(a0);
        }
    }
    switch (a0->field_46) {
    case 1:
        func_80026568((Actor *)a0, 1);
        break;
    case 0xFE:
    stop:
        func_80026568((Actor *)a0, 0);
        break;
    case 0:
    case 0xFF:
        break;
    default:
        if (a0->field_14 != 0) {
            a0->field_14(a0);
        } else {
            func_80025CC8(a0);
        }
        break;
    }
    return 0;
}

void func_80024DC8(Obj25FBC *a0) {
    s32 old;
    s32 i;
    s32 r;

    if (!(*a0->field_3C & 0xF0)) {
        a0->field_30[0] = 0xFF;
        a0->field_30[1] = 0;
        a0->field_E8 = 0;
        a0->field_35 = 0;
        D_80048E1C(a0);
        return;
    }
    old = a0->field_E8;
    a0->field_E8 = *a0->field_3C >> 4;
    if (a0->field_E8 == 0xF) {
        a0->field_E8 = old;
    } else {
        a0->field_30[0] = 0;
        a0->field_30[1] = a0->field_3C[0];
        a0->field_35 = a0->field_44;
        for (i = 2; i < a0->field_44; i++) {
            a0->field_30[i] = a0->field_3C[i];
        }
    }
    if ((a0->field_3C[1] == 0 && (a0->field_46 != 1 || a0->field_14 != 0) && a0->field_50 == 0)
        || a0->field_E8 != old) {
        D_80048E1C(a0);
    }

    a0->field_4A = 0;
    if (a0->field_46 == 0xFF) {
        return;
    }
    if (a0->field_46 != 0 && a0->field_37 == 0) {
        return;
    }
    if ((u8)(a0->field_46 - 2) < 0xFC && *a0->field_3C != 0xF3) {
        D_80048E1C(a0);
        return;
    }
    switch (a0->field_46) {
    case 0:
        a0->field_49 = 1;
        a0->field_46++;
        break;
    case 1:
        a0->field_47 = 0;
        a0->field_46++;
        break;
    case 0xFE:
        a0->field_46 = 0xFF;
        break;
    default:
        if (a0->field_18 != 0) {
            a0->field_46 += a0->field_18(a0);
        } else {
            a0->field_46 += func_80025D4C(a0);
        }
        break;
    }
}

void func_80025034(Obj25FBC *a0) {
    a0->field_4C++;
    if (a0->field_46 != 0) {
        if (a0->field_46 == 1) {
            if (a0->field_4A < 11) {
                a0->field_4A++;
                return;
            }
            a0->field_49 = 2;
            a0->field_46 = 0xFF;
            return;
        }
        if (a0->field_4A < 11) {
            a0->field_4A++;
            return;
        }
        if (a0->field_49 != 0) {
            D_80048E1C(a0);
        }
    }
    if (*a0->field_3C != 0xF3) {
        a0->field_30[0] = 0xFF;
        a0->field_30[1] = 0;
        a0->field_E8 = 0;
        a0->field_35 = 0;
    }
}

s32 func_80025114(Obj25FBC *p) {
    if (p->field_E6 != 0 && p->field_46 == 0xFF) {
        return 0;
    }
    return 1;
}

s32 func_80025144(void) {
    if (!(D_80048E8C->field_4 & 1)) {
        return 0;
    }
    if (!(D_80048E8C->field_0 & 1)) {
        return 0;
    }
    if (D_80048E40 != 0) {
        D_80048E40();
    }
    return 1;
}

s32 func_800251AC(void) {
    if (D_80048E90->field_A & 2) {
        D_80048E90->field_A = 0;
    } else {
        s32 a = D_80048E68;

        D_80048E88 = 1;
        if (a != 0 && D_80060058.field_0 < 150) {
            D_80060058.field_0++;
        }
        if (D_80048E6C == 0 && D_80060058.field_4 < 150) {
            D_80060058.field_4++;
        }
        if (D_80048E50 != 0 && D_80048E68 <= D_80048E6C) {
            D_80048E5C = 0;
            D_80048E58 = D_80048E68;
            if (func_8002533C(&D_80048E4C[D_80048E68]) == 0) {
                D_80048E18(0xFFFF);
            }
            D_80048E60 = 0;
            while (D_80048E58 <= D_80048E6C) {
                func_80025670(&D_80048E4C[D_80048E58]);
            }
            D_80048E90->field_E = 0x88;
        }
    }
    return 0;
}

s32 func_8002533C(Obj25FBC *a0) {
    Stat48E90 *st;
    s32 *tbl;
    s32 *q;
    s32 *p;
    s32 n;

    st = D_80048E90;
    *(volatile u16 *)&st->field_A = 0x40;
    *(volatile u16 *)&st->field_A = 0;
    *(volatile u16 *)&st->field_8 = 0xD;
    *(volatile u16 *)&st->field_E = 0x88;
    func_80026610(a0->field_E8 == 8 ? 0x50 : 0x91);
    D_80048E90->field_A = D_80048E58 ? 0x3003 : 0x1003;
    n = D_80048E70[D_80048E58];
    tbl = D_80048E70;
    if (n >= 0) {
        if (n > 0) {
            do {
                p = tbl;
                D_80048E38(&a0->field_C[--p[D_80048E58]]);
            } while (p[D_80048E58] > 0);
        }
        q = &D_80048E70[D_80048E58];
        if (*q == 0) {
            void (*fp)(Obj25FBC *);
            fp = D_80048E38;
            *q = -1;
            fp(a0);
            D_80048E3C((Actor *)a0);
        }
    }
    st = D_80048E90;
    if (st->field_4 & 0x200) {
        *(volatile u16 *)&st->field_A |= 0x10;
        if (st->field_4 & 0x200) {
            do {
            } while (func_80026630() == 0);
            D_80048E90->field_0 = 1;
            func_80026610(0x7D0);
            if (func_80025C00() == 0) {
                return 0;
            }
            func_80025C90();
            D_80048E90->field_0;
            func_80026610(0x1AE);
            while (!(D_80048E8C->field_0 & 0x80)) {
                if (func_80026630() != 0) {
                    return 0;
                }
            }
            D_80048E90->field_0 = 0x42;
            func_80026610(0x3C);
            if (func_80025C00() == 0) {
                return 0;
            }
            func_80025C90();
            D_80048E90->field_0;
            func_80026610(0x1AE);
            while (!(D_80048E8C->field_0 & 0x80)) {
                if (func_80026630() != 0) {
                    return 0;
                }
            }
            D_80048E90->field_0 = 1;
            func_80026610(0x3C);
            if (func_80025C00() == 0) {
                return 0;
            }
            func_80025C90();
            D_80048E90->field_0;
            return 0;
        }
        D_80048E8C->field_0 = -0x81;
    }
    if (a0->field_50 != 0 && a0->field_37 != 0) {
        return 0;
    }
    return 1;
}


void func_80025670(Obj25FBC *a0) {
    s32 r;

    r = D_80048EA0[D_80048E5C++](a0);
    if (r >= 0) {
        if (D_80048E5C != 0) {
            if (D_80048E5C != 3 || *a0->field_3C != 0x80) {
                func_80026610(0x3C);
                if (func_80025C00() == 0) {
                    D_80048E18(-3);
                }
            }
        }
        if (D_80048E5C >= 5) {
            D_80048E5C--;
        }
    } else {
        D_80048E18(r);
    }
}

s32 func_80025760(Ent266D0 *a0, s32 a1) {
    s32 r;
    s32 v;
    s32 t;

    if (a1 < 0) {
        r = D_80048E90->field_0;
        a0->field_44 = 0xFF;
        a0->field_45 = 1;
        *a0->field_40 = ~a1;
        while (!(D_80048E90->field_4 & 1)) {
        }
        while (func_80026630() == 0) {
        }
        D_80048E90->field_0 = ~a1;
    } else {
        v = 0x88;
        t = *a0->field_3C;
        if ((t >> 4) == 8 && a0->field_44 >= 9) {
            v = 0x22;
        }
        D_80060050 = 0x1AE;
        D_8006004C = *(volatile u16 *)0x1F801120;
        D_80060054 = *(volatile u16 *)0x1F801124;
        while (!(D_80048E90->field_4 & 2)) {
        }
        r = D_80048E90->field_0;
        D_80048E90->field_E = v;
        while (!(D_80048E8C->field_0 & 0x80)) {
            if (func_80026630() != 0) {
                return -0x14;
            }
        }
        D_80048E90->field_0 = a1;
        if (v == 0x22) {
            D_80048E8C->field_0 = -0x81;
            D_80048E90->field_A |= 0x10;
        }
        a0->field_45++;
        a0->field_3C[a0->field_44] = r;
        a0->field_44++;
    }
    return r;
}


s32 func_80025984(Ent266D0 *a0, s32 a1) {
    s32 v;
    s32 r;
    s32 t;
    s32 d;
    s32 base;
    s32 lim;
    Regs48E8C *p;

    d = *a0->field_3C;
    if ((d >> 4) == 8 && a0->field_44 >= 9) {
        v = 0x22;
    } else {
        v = 0x88;
    }
    while (!(D_80048E90->field_4 & 2)) {
    }
    func_80026610(0x190);
    r = D_80048E90->field_0;
    if (a0->field_44 != 0 || (r >> 4) != 8) {
        *(volatile u16 *)&D_80048E90->field_E = v;
    } else {
        D_80048E90->field_E = 0x22;
    }
    if (!(D_80048E8C->field_0 & 0x80)) {
        base = D_8006004C;
        lim = D_80060050;
        do {
            *(volatile u16 *)0x1F801124;
            t = *(volatile u16 *)0x1F801120;
            if (t < base) {
                if (*(volatile u16 *)0x1F801128 != 0) {
                    t += *(volatile u16 *)0x1F801128;
                } else {
                    t += 0x10000;
                }
            }
            if (*(volatile u16 *)0x1F801124 & 0x200) {
                if (t - base >= lim) {
                    return -2;
                }
            } else if (((t - base) >> 3) >= lim) {
                return -2;
            }
        } while (!(D_80048E8C->field_0 & 0x80));
    }
    if (((Slot267F0 *)a0)->field_E8 != 8 && D_80048E5C == 2) {
        func_80026610(0x3C);
        while (func_80026630() == 0) {
        }
    }
    D_80048E90->field_0 = a1;
    if (D_80048E5C == 3 && r == 0x80) {
        D_80048E8C->field_0 = -0x81;
        D_80048E90->field_A |= 0x10;
    }
    a0->field_45++;
    if (a0->field_44 != 0xFF) {
        (*(u8 * volatile *)&a0->field_3C)[*(volatile u8 *)&a0->field_44] = r;
    }
    a0->field_44++;
    return r;
}


s32 func_80025C00(void) {
    Regs48E8C *q = D_80048E8C;
    Stat48E90 *st = D_80048E90;

    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (func_80026630() != 0) {
                return 0;
            }
        } while (D_80048E90->field_4 & 0x80);
    }
    D_80048E90->field_A |= 0x10;
    return 1;
}

void func_80025C90(void) {
    while (!(D_80048E90->field_4 & 2)) {
    }
}

void func_80025CB8(Actor *arg0, u8 arg1, ActorWork *arg2, u8 arg3) {
    arg0->u34.b.field_37 = arg1;
    arg0->work = arg2;
    arg0->u34.b.field_36 = arg3;
}

void func_80025CC8(Obj25FBC *a0) {
    switch (a0->field_46) {
    case 2:
        func_80026588((Actor *)a0);
        break;
    case 3:
        func_8002659C((Actor *)a0, a0->field_E4);
        break;
    case 4:
        func_800265DC((Actor *)a0, a0->field_47);
        break;
    }
}

s32 func_80025D4C(Obj25FBC *a0) {
    u8 *p;
    s32 v;

    switch (a0->field_46) {

    case 2:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[7] != 0) {
            goto ret0;
        }
        if (a0->field_E3 == p[3] && a0->field_E4 == p[4] && a0->field_E9 == p[5] && a0->field_EA == p[6]) {
            a0->field_EE = 0;
        } else {
            a0->field_EE = 0xFFFF;
        }
        a0->field_E3 = (*(u8 *volatile *)&a0->field_3C)[3];
        a0->field_E4 = (*(u8 *volatile *)&a0->field_3C)[4];
        a0->field_E6 = 0;
        a0->field_E9 = (*(u8 *volatile *)&a0->field_3C)[5];
        a0->field_EA = (*(u8 *volatile *)&a0->field_3C)[6];
        a0->field_EC = 0;
        if (a0->field_EE != 0) {
            goto ret0;
        }
        a0->field_EB = 0;
        break;

    case 3:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[2] != 0) {
            goto ret0;
        }
        if (p[3] != 0) {
            goto ret0;
        }
        v = p[5] + (p[4] << 8);
        a0->field_E6 = v;
        if (a0->field_EE != (u16)v) {
            a0->field_EE = v;
        ret0:
            return 0;
        }
        a0->field_EE = 0xFFFF;
        a0->field_EB = 0;
        a0->field_47 = 0;
        break;

    case 4:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[2] != 0) {
            goto ret0;
        }
        if (p[3] != 0) {
            goto ret0;
        }
        v = a0->field_EC;
        v += 8;
        v += (p[4] + 3) & 0x1FC;
        a0->field_EC = v;
        if (++a0->field_47 < a0->field_EA) {
            goto ret0;
        }
        if (func_80025FBC(a0) > 0x80) {
            D_80048E1C(a0);
            a0->field_46 = 0xFE;
            a0->field_49 = 2;
            goto ret0;
        }
        if (a0->field_EE != a0->field_EC) {
            a0->field_EE = a0->field_EC;
            a0->field_47 = 0;
            a0->field_EC = 0;
            return 0;
        }
        a0->field_EE = 0;
        a0->field_EB = 0;
        a0->field_46 = 0xFF;
        func_80025FF4(a0, a0->field_63);
        a0->field_46 = 2;
        goto ret0;

    }
    return 1;
}


s32 func_80025FBC(Obj25FBC *arg0) {
    s32 a = ((arg0->field_E3 + 1) >> 1) << 2;
    s32 b = ((arg0->field_E9 * 5 + 3) & 0xFFC) + 4;
    return a + b + arg0->field_EC;
}

s32 func_80025FF4(Obj25FBC *a0, s32 a1) {
    s32 n;

    if (a1 == 0 || a0->field_4 != 0 || D_80048E34() != 0) {
        return 0;
    }
    a0->field_49 = 4;
    a0->field_46 = 1;
    a0->field_14 = (s32)func_800260C8;
    a0->field_18 = (s32)func_80026170;
    n = (a1 + 3) >> 2 << 2;
    a0->field_0 = n;
    a0->field_47 = 0;
    n += (a0->field_E3 + 1) / 2 * 4;
    a0->field_4 = n;
    n += (a0->field_E9 * 5 + 3) & 0xFFC;
    a0->field_8 = n;
    return 1;
}

void func_800260C8(Actor *a) {
    switch (a->field_46) {
    case 2:
        func_8002659C(a, a->field_47);
        return;
    case 3:
        func_800265BC(a, a->field_47);
        return;
    case 4:
        if (a->field_48[0].field_0 == 0) {
            func_800265DC(a, a->field_47);
            return;
        }
        func_800265FC(a);
        return;
    }
}

s32 func_80026170(Obj26170 *a) {
    volatile Ent26170 *q;
    Blk26170 *e;
    u8 *src;
    s32 n;
    s32 x;

    switch (a->field_46) {
    case 2:
        if (a->field_3C[2] != 0) return 0;
        if (a->field_3C[3] != 0) return 0;
        a->field_0[a->field_47] = (a->field_3C[4] << 8) + a->field_3C[5];
        if (a->field_EE != a->field_0[a->field_47]) {
            a->field_EE = a->field_0[a->field_47];
            return 0;
        }
        a->field_EE = 0;
        a->field_EB = 0;
        if (++a->field_47 < a->field_E3) return 0;
        a->field_47 = 0;
        break;
    case 3:
        if (a->field_3C[2] != 0) return 0;
        if (a->field_3C[3] != 0) return 0;
        q = &a->field_4[a->field_47];
        if (q->field_0 == a->field_3C[4] && q->field_1 == (a->field_3C[5] & 0x7F) && q->field_2 == a->field_3C[6]
            && q->field_3 == a->field_3C[7] && (x = a->field_3C[5], q->field_4 == x >> 7)) {
            a->field_EE = 0;
        } else {
            a->field_EE = 0xFFFF;
        }
        q->field_0 = a->field_3C[4];
        q->field_1 = a->field_3C[5] & 0x7F;
        q->field_2 = a->field_3C[6];
        q->field_3 = a->field_3C[7];
        q->field_4 = (x = a->field_3C[5]) >> 7;
        if (a->field_EE != 0) return 0;
        a->field_EB = 0;
        if (++a->field_47 < a->field_E9) return 0;
        a->field_47 = 0;
        a->field_48 = 0;
        break;
    case 4:
        if (a->field_3C[2] != 0) {
            a->field_48 = 0;
            return 0;
        }
        e = &a->field_8[a->field_47];
        if (a->field_48 == 0) {
            e->field_0 = a->field_48 = a->field_3C[4];
            src = a->field_3C + 5;
            n = 3;
            if (a->field_47 == 0) {
                D_80060048 = e->field_4 = (u8 *)&a->field_8[a->field_EA];
            } else {
                D_80060048 = e->field_4 = e[-1].field_4 + ((e[-1].field_0 + 3) & 0x1FC);
            }
        } else {
            src = a->field_3C + 3;
            n = 5;
        }
        while (--n != -1) {
            if (a->field_48 == 0) goto done;
            if (D_80060048 >= &a->field_E3) goto fail;
            if (*D_80060048 != *src) a->field_EE = 0xFFFF;
            *D_80060048++ = *src++;
            a->field_48--;
        }
        if (a->field_48 != 0) return 0;
    done:
        if (a->field_EE != 0) {
            a->field_EE = 0;
            a->field_48 = 0;
            return 0;
        }
        if (++a->field_47 >= a->field_EA) {
            a->field_49 = 6;
            a->field_46 = 0xFE;
            a->field_EB = 0;
            return 0;
        }
        a->field_48 = 0;
        a->field_EB = 0;
        return 0;
    fail:
        a->field_47 = 0;
        a->field_48 = 0;
        return 0;
    }
    return 1;
}


void func_80026568(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x43;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void func_80026588(Actor *arg0) {
    arg0->u34.b.field_37 = 0x45;
    arg0->work = NULL;
    arg0->u34.b.field_36 = 0;
}

void func_8002659C(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x4C;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void func_800265BC(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x46;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void func_800265DC(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x47;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void func_800265FC(Actor *arg0) {
    arg0->u34.b.field_37 = 0x4B;
    arg0->work = NULL;
    arg0->u34.b.field_36 = 0;
}

void func_80026610(s32 arg0) {
    D_80060050 = arg0;
    D_8006004C = *(volatile u16 *)0x1F801120;
}

s32 func_80026630(void) {
    u16 c = *(volatile u16 *)0x1F801120;
    s32 t = c;
    s32 d;
    s32 lim;

    if (t < D_8006004C) {
        if (*(volatile u16 *)0x1F801128 != 0) {
            t += *(volatile u16 *)0x1F801128;
        } else {
            t += 0x10000;
        }
    }
    if (!(*(volatile u16 *)0x1F801124 & 0x200)) {
        d = (t - D_8006004C) >> 3;
        lim = D_80060050;
    } else {
        d = t - D_8006004C;
        lim = D_80060050;
    }
    return d >= lim;
}


void func_800266D0(Ent266D0 *a0) {
    D_80048E98 = D_80048E30(a0);
    *a0->field_3C = 0;
    func_80025760(a0, -2);
}

void func_80026718(Obj25FBC *a0) {
    if (D_80048E58 == D_80048E68 && D_80048E54 != 0) {
        D_80048E48();
        D_80048E44();
    }
    if (D_80048E98 != 0) {
        D_80048E30(a0->field_C);
        D_80048E30(&a0->field_C[1]);
    }
    if (a0->field_37 == 0) {
        func_80025984(a0, 0x42);
    } else {
        func_80025984(a0, a0->field_37);
    }
}


s32 func_800267F0(Ent266D0 *a0) {
    s32 r;

    if (D_80048E98 != 0) {
        D_80048E30(&a0->field_C[2].e);
        D_80048E30(&a0->field_C[3].e);
    }
    r = func_80025984(a0, a0->field_37 ? 0 : D_80048E64);
    if (r >= 0) {
        D_80048E94 = (r & 0xF) * 2;
        if (D_80048E94 == 0) {
            D_80048E94 = 0x20;
        }
        r = 0;
    }
    return r;
}


s32 func_8002689C(Ent266D0 *a0) {
    s32 f = 0;
    s32 r;

    if (D_80048E64 != 0) {
        s32 st = *a0->field_3C;
        if ((st >> 4) == 8) {
            f = a0->field_37 == 0;
        }
    }
    D_80048E9C = f;
    if (f == 0 && a0->field_37 == 0 && a0->field_38 == 0
        && (a0 == a0->field_10 || a0->field_39 == 0) && *a0->field_30 == 0) {
        D_80048E24(a0);
    }
    r = func_80025984(a0, (u8)D_80048E20(a0, D_80048E9C));
    if (r == 0x5A || r == 0) {
        return r;
    }
    if (r >= 0) {
        return -4;
    }
    return r;
}

static inline s32 inl_w(s32 arg0) {
    volatile Regs48E8C *q = D_80048E8C;
    Stat48E90 *st = D_80048E90;
    D_80060050 = arg0;
    D_8006004C = *(volatile u16 *)0x1F801120;
    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (func_80026630() != 0) {
                return 0;
            }
        } while (D_80048E90->field_4 & 0x80);
    }
    D_80048E90->field_A |= 0x10;
    return 1;
}

static inline s32 inl_h(s32 arg0, volatile u16 *hw) {
    volatile Regs48E8C *q = D_80048E8C;
    Stat48E90 *st = D_80048E90;
    D_80060050 = arg0;
    D_8006004C = *hw;
    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (func_80026630() != 0) {
                return 0;
            }
        } while (D_80048E90->field_4 & 0x80);
    }
    D_80048E90->field_A |= 0x10;
    return 1;
}

s32 func_800269B8(Ent266D0 *a0) {
    s32 f;
    s32 i;
    s32 r;
    s32 t;
    s32 ok;
    s32 idx;
    Obj25FBC *e;
    Slot267F0 *s;
    s32 *slot;
    s32 c;

    if (D_80048E9C != 0 && a0->field_37 == 0 && a0->field_38 == 0
        && (a0 == a0->field_10 || a0->field_39 == 0) && *a0->field_30 == 0) {
        D_80048E24(a0);
    }
    f = D_80048E9C;
    if (f != 0) {
        for (i = -1; i < 4; i++) {
            if (--D_80048E94 <= 0) {
                break;
            }
            if (i >= 0) {
                s = &a0->field_C[i];
                if (s->e.field_37 == 0 && s->e.field_38 == 0
                    && (&s->e == s->e.field_10 || s->e.field_39 == 0) && *s->e.field_30 == 0) {
                    D_80048E24(&s->e);
                }
            }
            r = func_80025984(a0, (u8)D_80048E20(a0, 1));
            if (r < 0) {
                return r;
            }
            if (inl_w(0x3C) == 0) {
                return -3;
            }
        }
    }
    e = 0;
    idx = D_80048E58 == 0;
    while (D_80048E94 >= 2) {
        slot = &D_80048E70[idx];
        t = 0x3C;
        c = 3;
            if (*slot < 0) {
                break;
            }
            if (*slot > 0) {
                e = D_80048E4C[idx].field_C + *slot - 1;
                D_80048E38(e);
            }
            switch (*slot) {
            case 4:
                *slot = c;
                break;
            case 3:
                D_80048E38(e - 1);
                *slot = 1;
                break;
            case 0:
            case 1:
                e = &D_80048E4C[idx];
                D_80048E38(e);
                D_80048E3C((Actor *)e);
                *slot = -1;
                break;
            }
            r = func_80025760(a0, (u8)D_80048E20(a0, f));
            if (r < 0) {
                return r;
            }
            if (inl_w(t) == 0) {
                return -3;
            }
        D_80048E94--;
    }
    while (--D_80048E94 > 0) {
        s32 u = 0x22;
        volatile u16 *hw = (volatile u16 *)0x1F801120;
        t = 0x3C;
        r = func_80025760(a0, (u8)D_80048E20(a0, f));
        if (r < 0) {
            return r;
        }
        if (D_80048E90->field_E != u) {
            if (inl_h(t, hw) == 0) {
                return -3;
            }
        }
    }
    {
        Stat48E90 *st = D_80048E90;
        while (!(st->field_4 & 2)) {
        }
    }
    {
        s32 k = a0->field_44;
        a0->field_44 = k + 1;
        a0->field_3C[k] = D_80048E90->field_0;
    }
    D_80048E18(0);
    return 0;
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80026FB4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80026FC4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80026FD4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80026FE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80026FF4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80027004);

u8 *func_80027014(u8 *s, s32 n) {
    u8 *r = 0;

    if (s != 0) {
        r = s;
        if (n <= 0) {
            r = 0;
        } else {
            while (n > 0) {
                *s++ = 0;
                n--;
            }
        }
    }
    return r;
}


u8 *func_80027044(u8 *dst, u8 *src, s32 n) {
    u8 *r = 0;

    if (dst != 0) {
        u8 *d = dst;

        while (n > 0) {
            *dst++ = *src++;
            n--;
        }
        r = d;
    }
    return r;
}

u8 *func_80027084(u8 *s, s32 c, s32 n) {
    u8 *r = 0;

    if (s != 0) {
        r = s;
        if (n <= 0) {
            r = 0;
        } else {
            while (n > 0) {
                *s++ = c;
                n--;
            }
        }
    }
    return r;
}


u8 *func_800270B4(u8 *dst, u8 *src) {
    u8 *r = 0;

    if (dst != 0) {
        u8 *d = dst;
        if (src != 0) {
            s32 c = *src++;

            *dst++ = c;
            while (c != 0) {
                c = *src++;
                *dst++ = c;
            }
            r = d;
        }
    }
    return r;
}

s32 func_80027104(s32 mode) {
    Gpu48F10 *g;

    switch (mode & 7) {
    case 0:
    case 3:
        func_8002A014(D_8001021C, D_80048EC8, &D_80048F10);
    case 5:
        g = &D_80048F10;
        func_80029FDC((u8 *)g, 0, 0x80);
        func_80030CD4();
        func_8002A004((s32)D_80048F08 & 0xFFFFFF);
        g->field_0 = func_8002970C(mode);
        g->field_1 = 1;
        g->field_4 = D_80048F90[((volatile Gpu48F10 *)g)->field_0][0];
        g->field_6 = D_80048F9C.field_0[g->field_0][0];
        func_80029FDC(g->field_10, -1, 0x5C);
        func_80029FDC((u8 *)&g->field_6C, -1, 0x14);
        return g->field_0;
    default:
        if (D_80048F12 >= 2) {
            D_80048F0C(D_8001023C, mode);
        }
        return D_80048F08->fn_34(1);
    }
}

u8 func_80027278(u8 level) {
    s32 old = D_80048F10.field_2;

    D_80048F10.field_2 = level;
    if (level) {
        D_80048F0C(D_80010250, D_80048F10.field_2, D_80048F10.field_0, D_80048F10.field_3);
    }
    return old;
}

extern char D_8001027C[];

s32 func_800272D4(s32 a0) {
    s32 old = D_80048F10.field_1;

    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_8001027C, a0);
    }
    if (a0 != D_80048F10.field_1) {
        D_80048F08->fn_34(1);
        D_80048F10.field_1 = a0;
        func_80030D34(2, 0);
    }
    return old;
}


u8 func_80027378(void) {
    return D_80048F12;
}

s32 func_80027388(s32 a0) {
    s32 old;

    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_80010290, a0);
    }
    old = D_80048F10.field_C;
    D_80048F10.field_C = a0;
    return old;
}

void func_800273E8(s32 a0) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_800102AC, a0);
    }
    if (a0 == 0) {
        func_80029FDC((u8 *)&D_80048F10.field_6C, -1, 0x14);
    }
    D_80048F08->fn_10(a0 ? 0x03000000 : 0x03000001);
}

void func_80027480(void *a0) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_800102C0, a0);
    }
    D_80048F08->fn_3C(a0);
}

void func_800274E8(char *name, Rect2AB54 *r) {
    switch (D_80048F10.field_2) {
    case 1:
        if (r->w > D_80048F10.field_4 || r->w + r->x > D_80048F10.field_4
            || r->y > D_80048F10.field_6 || r->y + r->h > D_80048F10.field_6
            || r->w <= 0 || r->x < 0 || r->y < 0 || r->h <= 0) {
            D_80048F0C(D_800102D4, name);
            D_80048F0C(D_800102E0, r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        D_80048F0C(D_800102F4, name);
        D_80048F0C(D_800102E0, r->x, r->y, r->w, r->h);
        break;
    }
}

void func_80027604(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_800274E8(D_800102F8, a0);
    D_80048F08->fn_8(D_80048F08->field_C, a0, 8, ((a3 & 0xFF) << 16) | ((a2 & 0xFF) << 8) | (a1 & 0xFF));
}

void func_80027694(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_800274E8(D_80010304, a0);
    D_80048F08->fn_8(D_80048F08->field_C, a0, 8, ((a3 & 0xFF) << 16 | 0x80000000 | (a2 & 0xFF) << 8) | (a1 & 0xFF));
}

void func_8002772C(s32 a0, s32 a1) {
    func_800274E8(D_80010310, a0);
    D_80048F08->fn_8(D_80048F08->field_20, a0, 8, a1);
}

void func_8002778C(s32 a0, s32 a1) {
    func_800274E8(D_8001031C, a0);
    D_80048F08->fn_8(D_80048F08->field_1C, a0, 8, a1);
}

s32 func_800277EC(Rect2AB54 *rect, s32 x, s32 y) {
    func_800274E8(D_80010328, (s32)rect);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80048F9C.move[2] = *(u32 *)&rect->x;
    D_80048F9C.move[3] = (y << 16) | (x & 0xFFFF);
    D_80048F9C.move[4] = *(u32 *)&rect->w;
    return D_80048F08->fn_8((s32)D_80048F08->field_18, (s32)D_80048F9C.move, 0x14, 0);
}

OTag *func_800278A4(OTag *ot, s32 n) {
    u32 *term;

    if (D_80048F12 >= 2) {
        D_80048F0C(D_80010334, ot, n);
    }
    while (--n) {
        ot->len = 0;
        ot->addr = (u32)(ot + 1);
        ot++;
    }
    term = &D_80048FD0;
    *term = ((u32)&D_80048FBC & 0xFFFFFF) | 0x04000000;
    *(u32 *)ot = (u32)term & 0xFFFFFF;
    return ot;
}

Blk54CF8 *func_8002796C(Blk54CF8 *ot, s32 n) {
    u32 *term;

    if (D_80048F12 >= 2) {
        D_80048F0C(D_8001034C, ot, n);
    }
    D_80048F08->fn_2C(ot->field_0, n);
    term = &D_80048FD0;
    *term = ((u32)&D_80048FBC & 0xFFFFFF) | 0x4000000;
    ot->field_0[0] = (u32)term & 0xFFFFFF;
    return ot;
}

void func_80027A18(Ent27A18 *a0) {
    s32 n = a0->field_3;

    D_80048F08->fn_3C(0);
    D_80048F08->fn_14(a0->field_4, n);
}

s32 func_80027A74(void *a0) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_80010364, a0);
    }
    return D_80048F08->fn_8(D_80048F08->field_18, (s32)a0, 0, 0);
}

DrawEnv *func_80027AE4(DrawEnv *env) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(&D_80010378, env);
    }
    func_800284C4(env->dr_env, env);
    env->dr_env[0] |= 0xFFFFFF;
    D_80048F08->fn_8(D_80048F08->field_18, (s32)env->dr_env, 0x40, 0);
    func_80027044(D_80048F10.field_10, env, 0x5C);
    return env;
}

void func_80027BA4(s32 ot, DrawEnv *env) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_80010390, ot, env);
    }
    func_800284C4(env->dr_env, env);
    env->dr_env[0] = (env->dr_env[0] & 0xFF000000) | (ot & 0xFFFFFF);
    D_80048F08->fn_8(D_80048F08->field_18, (s32)env->dr_env, 0x40, 0);
    func_80027044(D_80048F10.field_10, env, 0x5C);
}

s32 func_80027C7C(s32 arg0) {
    func_80027044(arg0, D_80048F20, 0x5C);
    return arg0;
}

DispEnv *func_80027CB0(DispEnv *e) {
    DispEnv *env = e;
    s32 mode;
    s32 hs;
    s32 he;
    s32 vs;
    s32 ve;
    s32 k;
    s32 w;
    s32 t;
    s32 y;
    volatile DispEnv *d;

    mode = 0x08000000;
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_800103AC, env);
    }
    D_80048F08->fn_10(0x05000000 | ((env->disp.y & 0x3FF) << 10) | (env->disp.x & 0x3FF));
    d = &D_80048F10.field_6C;
    if (*(volatile s32 *)&D_80048F10.field_6C.isinter != *(s32 *)&env->isinter
        || d->disp.x != env->disp.x
        || d->disp.y != env->disp.y
        || d->disp.w != env->disp.w
        || d->disp.h != env->disp.h) {
        env->pad0 = func_80031838();
        if (env->pad0 == 1) {
            mode |= 0x08;
        }
        if (env->isrgb24) {
            mode |= 0x10;
        }
        if (env->isinter) {
            mode |= 0x20;
        }
        if (D_80048F10.field_3) {
            mode |= 0x80;
        }
        if (env->disp.w > 280) {
            if (env->disp.w <= 352) {
                mode |= 0x01;
            } else if (env->disp.w <= 400) {
                mode |= 0x40;
            } else if (env->disp.w <= 560) {
                mode |= 0x02;
            } else {
                mode |= 0x03;
            }
        }
        y = env->disp.h;
        if (env->pad0 != 0) {
            t = y < 289;
        } else {
            t = y < 257;
        }
        if (!t) {
            mode |= 0x24;
        }
        D_80048F08->fn_10(mode);
        env->pad0 = 8;
    }
    if (D_80048F10.field_6C.screen.x != env->screen.x
        || D_80048F10.field_6C.screen.y != env->screen.y
        || D_80048F10.field_6C.screen.w != env->screen.w
        || D_80048F10.field_6C.screen.h != env->screen.h
        || env->pad0 == 8) {
        env->pad0 = func_80031838();
        y = env->screen.y;
        if (env->pad0 != 0) {
            vs = y + 0x13;
        } else {
            vs = y + 0x10;
        }
        if (env->screen.h != 0) {
            ve = vs + env->screen.h;
        } else {
            ve = vs + 0xF0;
        }
        if (env->disp.w <= 280) {
            k = 0;
        } else if (env->disp.w <= 352) {
            k = 1;
        } else if (env->disp.w <= 400) {
            k = 2;
        } else if (env->disp.w <= 560) {
            k = 3;
        } else {
            k = 4;
        }
        hs = D_80048FE4[env->pad0][k].lo + env->screen.x * D_8004900C[k];
        w = D_80048FE4[env->pad0][k].hi - D_80048FE4[env->pad0][k].lo;
        he = hs + (env->screen.w != 0 ? (w * env->screen.w) >> 8 : w);
        if (env->pad0 != 0) {
            hs = hs < 0x21C ? 0x21C : (hs > 0xC94 ? 0xC94 : hs);
            he = he < hs + D_8004900C[k] * 4 ? hs + D_8004900C[k] * 4 : (he > 0xCBC ? 0xCBC : he);
            vs = vs < 0x13 ? 0x13 : (vs > 0x12F ? 0x12F : vs);
            ve = ve < vs + 2 ? vs + 2 : (ve > 0x131 ? 0x131 : ve);
        } else {
            hs = hs < 0x1F4 ? 0x1F4 : (hs > 0xCB2 ? 0xCB2 : hs);
            he = he < hs + D_8004900C[k] * 4 ? hs + D_8004900C[k] * 4 : (he > 0xCDA ? 0xCDA : he);
            vs = vs < 0x10 ? 0x10 : (vs > 0x101 ? 0x101 : vs);
            ve = ve < vs + 2 ? vs + 2 : (ve > 0x102 ? 0x102 : ve);
        }
        D_80048F08->fn_10(0x06000000 | ((he & 0xFFF) << 12) | (hs & 0xFFF));
        D_80048F08->fn_10(0x07000000 | ((ve & 0x3FF) << 10) | (vs & 0x3FF));
    }
    func_80027044((u8 *)&D_80048F10.field_6C, (u8 *)env, 0x14);
    return env;
}


s32 func_800281A8(s32 arg0) {
    func_80027044(arg0, D_80048F7C, 0x14);
    return arg0;
}

u32 func_800281DC(void) {
    return (u32)D_80048F08->fn() >> 31;
}

extern s32 func_80028754(s16, s16);
extern s32 func_800287EC(s16, s16);

void func_8002820C(Obj8228C *a0, Pt8228C *a1) {
    a0->field_3 = 2;
    a0->field_4 = func_80028754(a1->field_0, a1->field_2);
    a0->field_8 = func_800287EC((s16)(a1->field_0 + a1->field_4 - 1),
                                (s16)(a1->field_2 + a1->field_6 - 1));
}

void func_8002828C(Obj8228C *arg0, Pt8228C *arg1) {
    arg0->field_3 = 2;
    arg0->field_4 = func_80028884(arg1->field_0, arg1->field_2);
    arg0->field_8 = 0;
}

void func_800282CC(DrEnv282CC *d, DrawEnv *env) {
    Rect282CC rect;
    s32 len;

    d->w[1] = func_80028754(env->clip_x, env->clip_y);
    d->w[2] = func_800287EC(env->clip_w + env->clip_x - 1, env->clip_y + env->clip_h - 1);
    d->w[3] = func_80028884(env->ofs[0], env->ofs[1]);
    d->w[4] = func_80028734(env->dfe, env->dtd, env->tpage);
    d->w[5] = func_800288A0((Rect288A0 *)&env->tw_x);
    d->w[6] = 0xE6000000;
    len = 7;
    if (env->isbg) {
        rect.r.x = env->clip_x;
        rect.r.y = env->clip_y;
        rect.r.w = env->clip_w;
        rect.r.h = env->clip_h;
        rect.r.w = (rect.r.w < 0) ? 0 : ((rect.r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect.r.w);
        rect.r.h = (rect.r.h < 0) ? 0 : ((rect.r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect.r.h);
        rect.r.x -= env->ofs[0];
        rect.r.y -= env->ofs[1];
        d->w[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
        d->w[len++] = rect.w[0];
        d->w[len++] = rect.w[1];
    }
    d->h.len = len - 1;
}

void func_800284C4(DrEnv282CC *d, DrawEnv *env) {
    Rect282CC rect;
    s32 len;

    d->w[1] = func_80028754(env->clip_x, env->clip_y);
    d->w[2] = func_800287EC(env->clip_w + env->clip_x - 1, env->clip_y + env->clip_h - 1);
    d->w[3] = func_80028884(env->ofs[0], env->ofs[1]);
    d->w[4] = func_80028734(env->dfe, env->dtd, env->tpage);
    d->w[5] = func_800288A0((Rect288A0 *)&env->tw_x);
    d->w[6] = 0xE6000000;
    len = 7;
    if (env->isbg) {
        rect.r.x = env->clip_x;
        rect.r.y = env->clip_y;
        rect.r.w = env->clip_w;
        rect.r.h = env->clip_h;
        rect.r.w = (rect.r.w < 0) ? 0 : ((rect.r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect.r.w);
        rect.r.h = (rect.r.h < 0) ? 0 : ((rect.r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect.r.h);
        if ((rect.r.x & 0x3F) || (rect.r.w & 0x3F)) {
            rect.r.x -= env->ofs[0];
            rect.r.y -= env->ofs[1];
            d->w[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            d->w[len++] = rect.w[0];
            d->w[len++] = rect.w[1];
        } else {
            d->w[len++] = 0x02000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            d->w[len++] = rect.w[0];
            d->w[len++] = rect.w[1];
        }
    }
    d->h.len = len - 1;
}

int func_80028734(int a0, int a1, int a2) {
    int v1 = 0xE1000000;
    int v0;
    if (a1) v1 = 0xE1000200;
    v0 = a2 & 0x9FF;
    if (a0) v0 |= 0x400;
    return v0 | v1;
}

s32 func_80028754(s16 x, s16 y) {
    x = (x < 0) ? 0 : ((x > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : x);
    y = (y < 0) ? 0 : ((y > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : y);
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

s32 func_800287EC(s16 x, s16 y) {
    x = (x < 0) ? 0 : ((x > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : x);
    y = (y < 0) ? 0 : ((y > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : y);
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

s32 func_80028884(s32 arg0, s32 arg1) {
    return 0xE5000000 | ((arg1 & 0x7FF) << 11) | (arg0 & 0x7FF);
}

u32 func_800288A0(Rect288A0 *tw) {
    s32 t[4];

    if (tw != 0) {
        t[0] = (tw->x & 0xFF) >> 3;
        t[2] = (-tw->w & 0xFF) >> 3;
        t[1] = (tw->y & 0xFF) >> 3;
        t[3] = (-tw->h & 0xFF) >> 3;
        return 0xE2000000 | (t[1] << 15) | (t[0] << 10) | (t[3] << 5) | t[2];
    }
    return 0;
}

s32 func_80028920(void) {
    return *D_80049018;
}

s32 func_80028938(s32 *a0, s32 a1) {
    *D_80049034 |= 0x08000000;
    *D_80049030 = 0;
    *D_80049028 = (s32)&a0[a1 - 1];
    *D_8004902C = a1;
    *D_80049030 = 0x11000002;
    func_80029984();
    while (*D_80049030 & 0x01000000) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    return a1;
}

s32 func_80028A18(Rect282CC *rect, s32 color) {
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect->r.h);
    if ((rect->r.x & 0x3F) || (rect->r.w & 0x3F)) {
        D_80060060[0] = ((u32)D_80060088 & 0xFFFFFF) | 0x08000000;
        D_80060060[1] = 0xE3000000;
        D_80060060[2] = 0xE4FFFFFF;
        D_80060060[3] = 0xE5000000;
        D_80060060[4] = 0xE6000000;
        D_80060060[5] = gpu_draw_mode(0xE1000000, (u32)color >> 31, *D_80049018);
        D_80060060[6] = (color & 0xFFFFFF) | 0x60000000;
        D_80060060[7] = rect->w[0];
        D_80060060[8] = rect->w[1];
        D_80060088[0] = 0x03FFFFFF;
        D_80060088[1] = func_800291A8(3) | 0xE3000000;
        D_80060088[2] = func_800291A8(4) | 0xE4000000;
        D_80060088[3] = func_800291A8(5) | 0xE5000000;
    } else {
        D_80060060[0] = 0x05FFFFFF;
        D_80060060[1] = 0xE6000000;
        D_80060060[2] = gpu_draw_mode(0xE1000000, (u32)color >> 31, *D_80049018);
        D_80060060[3] = (color & 0xFFFFFF) | 0x02000000;
        D_80060060[4] = rect->w[0];
        D_80060060[5] = rect->w[1];
    }
    func_80029160((s32)D_80060060);
    return 0;
}


s32 func_80028C48(Rect28C48 *rect, s32 *p) {
    s32 size;
    s32 n;
    s32 blocks;
    s32 clr;
    s32 v;
    s32 *g;

    func_80029984();
    clr = 0;
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4) ? D_80048F10.field_4 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6) ? D_80048F10.field_6 : rect->r.h);
    size = (rect->r.w * rect->r.h + 1) / 2;
    if (size <= 0) {
        return -1;
    }
    n = size % 16;
    blocks = size / 16;
    while (!(*D_80049018 & 0x4000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    *D_80049018 = 0x4000000;
    *D_80049014 = 0x1000000;
    v = 0xA0000000;
    g = D_80049014;
    if (clr) {
        v = 0xB0000000;
    }
    *g = v;
    *D_80049014 = rect->word[0];
    *D_80049014 = rect->word[1];
    for (n--; n != -1; n--) {
        *D_80049014 = *p++;
    }
    if (blocks != 0) {
        *D_80049018 = 0x4000002;
        *D_8004901C = (s32)p;
        *D_80049020 = (blocks << 16) | 0x10;
        *D_80049024 = 0x1000201;
    }
    return 0;
}


s32 func_80028E84(Rect28E84 *rect, s32 *p) {
    s32 size;
    s32 n;
    s32 blocks;

    func_80029984();
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4) ? D_80048F10.field_4 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6) ? D_80048F10.field_6 : rect->r.h);
    size = (rect->r.w * rect->r.h + 1) / 2;
    if (size <= 0) {
        return -1;
    }
    n = size % 16;
    blocks = size / 16;
    while (!(*D_80049018 & 0x4000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    *D_80049018 = 0x4000000;
    *D_80049014 = 0x1000000;
    *D_80049014 = 0xC0000000;
    *D_80049014 = rect->w[0];
    *D_80049014 = rect->w[1];
    while (!(*D_80049018 & 0x8000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    for (n--; n != -1; n--) {
        *p++ = *D_80049014;
    }
    if (blocks != 0) {
        *D_80049018 = 0x4000003;
        *D_8004901C = (s32)p;
        *D_80049020 = (blocks << 16) | 0x10;
        *D_80049024 = 0x1000200;
    }
    return 0;
}


void func_80029104(s32 arg0) {
    *D_80049018 = arg0;
}

void func_80029118(void) {
}

s32 func_80029120(s32 *arg0, u32 arg1) {
    *D_80049018 = 0x4000000;
    while (arg1-- != 0) {
        *D_80049014 = *arg0++;
    }
    return 0;
}

void func_80029160(s32 arg0) {
    *D_80049018 = 0x4000002;
    *D_8004901C = arg0;
    *D_80049020 = 0;
    *D_80049024 = 0x1000401;
}

s32 func_800291A8(s32 arg0) {
    *D_80049018 = arg0 | 0x10000000;
    return *D_80049014 & 0xFFFFFF;
}

void func_800291D8(s32 arg0, s32 arg1, s32 arg2) { func_800291FC(arg0, arg1, 0, arg2); }

s32 func_800291FC(void (*func)(s32 *, s32), s32 *param, s32 n, s32 x) {
    s32 i;
    Gpu48F10 *g;

    func_80029984();
    while (((D_80049038 + 1) & 0x3F) == D_8004903C) {
        if (func_800299B8() != 0) {
            return -1;
        }
        func_800294AC();
    }
    D_80049040 = func_80030E50(0);
    g = &D_80048F10;
    g->field_8 = 1;
    if (g->field_1 == 0 ||
        (D_80049038 == D_8004903C && !(*D_80049024 & 0x1000000) && g->field_C == 0)) {
        while (!(*(volatile s32 *)D_80049018 & 0x4000000)) {
        }
        func(param, x);
        func_80030E50(D_80049040);
        return 0;
    }
    func_80030D34(2, func_800294AC);
    if (n != 0) {
        for (i = 0; i < n / 4; i++) {
            volatile s32 *d = D_800600B0[D_80049038].param;
            d[i] = param[i];
        }
        D_800600B0[D_80049038].ptr = D_800600B0[D_80049038].param;
    } else {
        D_800600B0[D_80049038].ptr = param;
    }
    D_800600B0[D_80049038].x = x;
    D_800600B0[D_80049038].func = func;
    D_80049038 = (D_80049038 + 1) & 0x3F;
    func_80030E50(D_80049040);
    func_800294AC();
    return (D_80049038 - D_8004903C) & 0x3F;
}


s32 func_800294AC(void) {
    void (*cb)(void);
    volatile s32 *g;
    s32 k1;
    s32 k2;

    if (*D_80049024 & 0x1000000) {
        return 1;
    }
    D_80049044 = func_80030E50(0);
    while (D_80049038 != D_8004903C && (k2 = 0x1000000, !(*D_80049024 & k2))) {
        if (((D_8004903C + 1) & 0x3F) == D_80049038 && D_80048F10.field_C == 0) {
            func_80030D34(2, 0);
        }
        g = (volatile s32 *)D_80049018;
        while (k1 = 0x4000000, !(*g & k1)) {
        }
        D_800600B0[D_8004903C].func(D_800600B0[D_8004903C].ptr, D_800600B0[D_8004903C].x);
        D_8004903C = (D_8004903C + 1) & 0x3F;
    }
    func_80030E50(D_80049044);
    if (D_80049038 == D_8004903C && !(*D_80049024 & 0x1000000) && D_80048F10.field_8 != 0) {
        cb = (void (*)(void))D_80048F10.field_C;
        if (cb != 0) {
            ((volatile Gpu48F10 *)&D_80048F10)->field_8 = 0;
            cb();
        }
    }
    return (D_80049038 - D_8004903C) & 0x3F;
}


s32 func_8002970C(s32 mode) {
    D_80049048 = func_80030E50(0);
    D_80049038 = D_8004903C = 0;
    switch (mode & 7) {
    case 0:
    case 5:
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0;
        func_80029FDC((u8 *)D_800600B0, 0, 0x1800);
        break;
    case 1:
    case 3:
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0x2000000;
        *D_80049018 = 0x1000000;
        break;
    }
    func_80030E50(D_80049048);
    if (mode & 7) {
        return 0;
    }
    return func_80029AFC(mode);
}

s32 func_80029848(s32 a0) {
    s32 n;

    if (a0 == 0) {
        func_80029984();
        while (D_80049038 != D_8004903C) {
            func_800294AC();
            if (func_800299B8() != 0) {
                return -1;
            }
        }
        while ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
            if (func_800299B8() != 0) {
                return -1;
            }
        }
        return 0;
    }
    n = (D_80049038 - D_8004903C) & 0x3F;
    if (n != 0) {
        func_800294AC();
    }
    if ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
        if (n != 0) {
            return n;
        }
        return 1;
    }
    return n;
}


void func_80029984(void) {
    D_8004904C = func_80030AB4(-1) + 0xF0;
    D_80049050 = 0;
}

s32 func_800299B8(void) {
    if (func_80030AB4(-1) > D_8004904C || D_80049050++ > 0xF0000) {
        *(volatile s32 *)D_80049018;
        func_8002A014(D_800103C4, (D_80049038 - D_8004903C) & 0x3F, *(volatile s32 *)D_80049018,
                      *(volatile s32 *)D_80049024, *(volatile s32 *)D_8004901C);
        D_80049048 = func_80030E50(0);
        D_8004903C = 0;
        D_80049038 = D_8004903C;
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0x2000000;
        *D_80049018 = 0x1000000;
        func_80030E50(D_80049048);
        return -1;
    }
    return 0;
}

s32 func_80029AFC(s32 a0) {
    *D_80049018 = 0x10000007;
    if ((*D_80049014 & 0xFFFFFF) != 2) {
        *D_80049014 = (*D_80049018 & 0x3FFF) | 0xE1001000;
        *(volatile s32 *)D_80049014;
        return 0;
    }
    if (!(a0 & 8)) {
        return 1;
    }
    *D_80049018 = 0x09000001;
    return 2;
}

s32 func_80029B9C(s32 a0, s32 a1) {
    func_800274E8(D_800103F8, a0);
    D_8004904C = func_80030AB4(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    func_80030D34(2, func_80029FB4);
    D_80048F08->field_20(a0, a1);
    return 0;
}

s32 func_80029C88(s32 a0, s32 a1) {
    func_800274E8(D_8001031C, a0);
    D_8004904C = func_80030AB4(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
        if (func_800299B8()) {
            return -1;
        }
    }
    func_80030D34(2, func_80029FB4);
    D_80048F08->field_1C(a0, a1);
    return 0;
}

s32 func_80029D74(Rect2AB54 *rect, s32 x, s32 y) {
    func_800274E8(D_80010328, (s32)rect);
    D_8004904C = func_80030AB4(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    func_80030D34(2, func_80029FB4);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80048F9C.move[2] = *(u32 *)&rect->x;
    D_80048F9C.move[3] = (y << 16) | (x & 0xFFFF);
    D_80048F9C.move[4] = *(u32 *)&rect->w;
    D_80048F08->field_18(D_80048F9C.move);
    return 0;
}

s32 func_80029EB8(u32 *p) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_80010364, p);
    }
    D_8004904C = func_80030AB4(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (func_800299B8() != 0) {
            return -1;
        }
    }
    func_80030D34(2, func_80029FB4);
    D_80048F08->field_18(p);
    return 0;
}

void func_80029FB4(void) { func_80030D34(0x2, func_800294AC); }

void func_80029FDC(u8 *arg0, s32 arg1, u32 arg2) {
    while (arg2-- != 0) {
        *arg0++ = arg1;
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002A004);

void func_8002A014(fmt, a1, a2, a3) char *fmt; s32 a1; s32 a2; s32 a3; {
    char **fp = &fmt;
    s32 *ap = &a1;
    ap[1] = a2;
    ap[2] = a3;
    func_8002A054(1, *fp, (char *)ap);
}


s32 func_8002A054(s32 fd, char *fmt0, char *ap) {
    s32 ret;
    s32 dprec;
    s32 fpprec;
    s32 width;
    char *xdigs;
    u8 *fmt;
    s32 ch;
    s32 n;
    char *cp;
    s32 flags;
    s32 prec;
    s32 sign;
    u32 _ulong;
    s32 base;
    s32 fieldsz;
    s32 realsz;
    s32 size;
    char *p;
    char buf[40];

    if (fmt0 == 0) {
        return 0;
    }
    fmt = (u8 *)fmt0;
    xdigs = D_80010404;
    ret = 0;
    for (;; fmt++) {
        ch = *fmt;
        if (ch == 0) {
            goto done;
        }
        if (ch != '%') {
            goto put;
        }
        flags = 0;
        prec = -1;
        sign = 0;
        dprec = 0;
        fpprec = 0;
        width = 0;
    rflag:
        ch = *++fmt;
        switch (ch) {
        case ' ':
            if (!sign) {
                sign = ' ';
            }
            goto rflag;
        case '#':
            flags |= 8;
            goto rflag;
        case '*':
            if ((width = VA_ARG(ap, s32)) >= 0) {
                goto rflag;
            }
            width = -width;
        case '-':
            flags |= 0x10;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *++fmt) == '*') {
                n = VA_ARG(ap, s32);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while ((u32)ch < 0x80 && (D_80049071[*fmt] & 4)) {
                n = n * 10 + (s32)(*fmt++ - '0');
                ch = *fmt;
            }
            fmt--;
            prec = n < 0 ? -1 : n;
            goto rflag;
        case '0':
            flags |= 0x20;
            goto rflag;
        case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            n = 0;
            do {
                n = n * 10 + (s32)(*fmt++ - '0');
            } while ((u32)(ch = *fmt) < 0x80 && (D_80049071[*(volatile u8 *)fmt] & 4));
            width = n;
            fmt--;
            goto rflag;
        case 'L':
            flags |= 2;
            goto rflag;
        case 'h':
            flags |= 4;
            goto rflag;
        case 'l':
            flags |= 1;
            goto rflag;
        case 'c':
            *(cp = buf) = VA_ARG(ap, s32);
            size = 1;
            sign = 0;
            break;
        case 'D':
            flags |= 1;
        case 'd':
        case 'i':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            if ((s32)_ulong < 0) {
                _ulong = -_ulong;
                sign = '-';
            }
            base = 10;
            goto number;
        case 'n':
            if (flags & 1) {
                *VA_ARG(ap, s32 *) = ret;
            } else if (flags & 4) {
                *VA_ARG(ap, s16 *) = ret;
            } else {
                *VA_ARG(ap, s32 *) = ret;
            }
            continue;
        case 'O':
            flags |= 1;
        case 'o':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 8;
            goto nosign;
        case 'p':
            _ulong = VA_ARG(ap, s32);
            base = 16;
            goto nosign;
        case 's':
            if ((cp = VA_ARG(ap, char *)) == 0) {
                cp = D_80010418;
            }
            if (prec >= 0) {
                p = (char *)func_8002A6F4((u8 *)cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec) {
                        size = prec;
                    }
                } else {
                    size = prec;
                }
            } else {
                size = func_8002A9B4((s8 *)cp);
            }
            sign = 0;
            break;
        case 'U':
            flags |= 1;
        case 'u':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 10;
            goto nosign;
        case 'X':
            xdigs = D_80010420;
        case 'x':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 16;
            if ((flags & 8) && _ulong != 0) {
                flags |= 0x40;
            }
        nosign:
            sign = 0;
        number:
            if ((dprec = prec) >= 0) {
                flags &= ~0x20;
            }
            cp = buf + 40;
            if (_ulong != 0 || dprec != 0) {
                do {
                    *--cp = xdigs[_ulong % base];
                    _ulong /= base;
                } while (_ulong);
                xdigs = D_80010404;
                if ((flags & 8) && base == 8 && *(s8 *)cp != '0') {
                    *--cp = '0';
                }
            }
            size = buf + 40 - cp;
            break;
        case '\0':
            goto done;
        default:
            goto put_s;
        }
        fieldsz = size + fpprec;
        if (sign) {
            fieldsz++;
        }
        if (flags & 0x40) {
            fieldsz += 2;
        }
        realsz = fieldsz > dprec ? fieldsz : dprec;
        if ((flags & 0x30) == 0 && width) {
            for (n = realsz; n < width; n++) {
                func_8002A744(' ');
            }
        }
        ch = sign;
        if (ch) {
            ((void (*)(s32))func_8002A744)(ch);
        }
        if (flags & 0x40) {
            func_8002A744('0');
            func_8002A744(*fmt);
        }
        if ((flags & 0x30) == 0x20) {
            for (n = realsz; n < width; n++) {
                func_8002A744('0');
            }
        }
        for (n = fieldsz; n < dprec; n++) {
            func_8002A744('0');
        }
        for (n = size; --n >= 0;) {
            func_8002A744(*cp++);
        }
        while (--fpprec >= 0) {
            func_8002A744('0');
        }
        if (flags & 0x10) {
            for (n = realsz; n < width; n++) {
                func_8002A744(' ');
            }
        }
        ret += realsz > width ? realsz : width;
        continue;
    done:
        func_8002A840();
        return ret;
    put_s:
        ret++;
        func_8002A744(*fmt);
        continue;
    put:
        ((void (*)(s32))func_8002A744)(ch);
    }
}


u8 *func_8002A6F4(u8 *p, s32 c, s32 n) {
    u8 *r = 0;

    if (p == 0) {
        goto end;
    }
    if (n <= 0) {
        goto end;
    }
    n--;
    goto test;
found:
    r = p - 1;
    goto end;
test:
    if (n < 0) {
        r = 0;
        goto end;
    }
    c &= 0xFF;
loop:
    if (*p++ == c) {
        goto found;
    }
    if (--n >= 0) {
        goto loop;
    }
    r = 0;
end:
    return r;
}


void func_8002A744(s8 c) {
    switch (c) {
    case 10:
        func_8002A744(0xD);
        D_80049060 = 0;
        break;
    case 9:
        do {
            func_8002A744(0x20);
        } while (D_80049060 & 7);
        return;
    default:
        if (D_80049071[(u8)c] & 0x97) {
            D_80049060++;
        }
        break;
    }
    if (D_80049064 >= 0x20) {
        func_8002A9A4(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
    D_800618B0[D_80049064++] = c;
}


void func_8002A840(void) {
    if (D_80049064 > 0) {
        func_8002A9A4(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
}

void func_8002A87C(s8 c) {
    switch (c) {
    case 10:
        func_8002A744(0xD);
        D_80049060 = 0;
        break;
    case 9:
        for (;;) {
            func_8002A744(0x20);
            if ((D_80049060 & 7) == 0) {
                goto flush;
            }
        }
    default:
        if (D_80049071[(u8)c] & 0x97) {
            D_80049060++;
        }
        break;
    }
    if (D_80049064 >= 0x20) {
        func_8002A9A4(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
    {
        s32 n = D_80049064;

        D_800618B0[n] = c;
        D_80049064 = n + 1;
    }
flush:
    if (D_80049064 > 0) {
        func_8002A9A4(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002A9A4);

s32 func_8002A9B4(s8 *s) {
    s32 n = 0;
    s32 r = 0;

    if (s != 0) {
        while (*s++ != 0) {
            n++;
        }
        r = n;
    }
    return r;
}


DrawEnv *func_8002A9F4(DrawEnv *env, s32 x, s32 y, s32 w, s32 h) {
    s32 mode = func_80031838();

    env->clip_x = x;
    env->clip_y = y;
    env->clip_w = w;
    env->tw_x = 0;
    env->tw_y = 0;
    env->tw_w = 0;
    env->tw_h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip_h = h;
    if (mode) {
        env->dfe = h < 0x121;
    } else {
        env->dfe = h < 0x101;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = 10;
    env->isbg = 0;
    return env;
}

Rec2AAB4 *func_8002AAB4(Rec2AAB4 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->field_0 = arg1;
    arg0->field_2 = arg2;
    arg0->field_4 = arg3;
    arg0->field_8 = 0;
    arg0->field_A = 0;
    arg0->field_C = 0;
    arg0->field_E = 0;
    arg0->field_11 = 0;
    arg0->field_10 = 0;
    arg0->field_13 = 0;
    arg0->field_12 = 0;
    arg0->field_6 = arg4;
    return arg0;
}

void func_8002AAF4(unsigned int *a0, unsigned int *a1) {
    *a1 = (*a1 & 0xFF000000) | (*a0 & 0x00FFFFFF);
    *a0 = (*a0 & 0xFF000000) | ((unsigned int)a1 & 0x00FFFFFF);
}

void func_8002AB34(u8 *a0) {
    a0[3] = 5;
    a0[7] = 0x28;
}

void func_8002AB54(DrMove2AB54 *p, Rect2AB54 *r, s32 x, s32 y) {
    s32 len = 5;

    if (r->w == 0 || r->h == 0) {
        len = 0;
    }
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    p->len = len;
    p->code[2] = *(u32 *)&r->x;
    p->code[3] = (y << 16) | (x & 0xFFFF);
    p->code[4] = *(u32 *)&r->w;
}

typedef struct {
    s16 x, y, w, h;
} Rect2ABB4;

typedef struct {
    u8 addr[3];
    u8 len;
    u32 code[2];
} DrMode2ABB4;

void func_8002ABB4(DrMode2ABB4 *p, s32 dfe, s32 dtd, s32 tpage, Rect2ABB4 *tw) {
    p->len = 2;
    p->code[0] = 0xE1000000 | (dtd ? 0x200 : 0) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
    if (tw) {
        p->code[1] = 0xE2000000 | (((tw->y & 0xFF) >> 3) << 15) | (((tw->x & 0xFF) >> 3) << 10)
            | ((((-tw->h) & 0xFF) >> 3) << 5) | (((-tw->w) & 0xFF) >> 3);
    } else {
        p->code[1] = 0;
    }
}


void func_8002AC54(u16 a0, u16 a1, u16 a2, u16 a3, u16 a4) {
    func_8002ACC8(a0, a1, a2, a3, a4);
    func_8002BB84();
    D_8006198C = 0;
    func_8002AE4C(a0, a1);
    func_8002B2B4();
    func_8002B1A4();
}

void func_8002ACC8(u16 x, u16 y, u16 flags, u16 dtd, u16 rgb24) {
    Rect2AB54 *r;
    s32 mode;
    s32 m;

    m = 0;
    if (((flags >> 4) & 3) == 3) {
        m = 3;
    }
    func_80027104(m);
    D_80061908.ofs[0] = D_80061908.ofs[1] = 0;
    D_80061908.tw_h = 0;
    D_80061908.tw_w = 0;
    D_80061908.tw_y = 0;
    D_80061908.tw_x = 0;
    D_80061908.tpage = 0;
    D_80061908.dtd = dtd;
    D_80061908.dfe = 0;
    D_80061908.isbg = 0;
    func_80027AE4(&D_80061908);
    D_80061968.disp.x = 0;
    D_80061968.disp.y = 0;
    D_80061968.disp.w = x;
    D_80061968.disp.h = y;
    r = &D_80061968.screen;
    r->x = 0;
    r->y = 0;
    r->w = 0;
    r->h = 0;
    mode = func_80031838();
    if (mode == 1) {
        D_80061968.screen.y = 0x18;
        D_80061968.pad0 = mode;
    }
    D_80061968.isinter = flags & 1;
    D_8006198E = flags & 4;
    D_80061968.isrgb24 = rgb24;
    func_80027CB0(&D_80061968);
}

void func_8002ADE4(s16 a0, s16 a1, s32 flags, u8 a3, u16 a4) {
    D_8006191C.field_0 = 0;
    D_8006191C.field_2 = a3;
    D_8006191C.field_3 = 0;
    D_8006191C.field_4 = 0;
    D_8006196C.field_0 = a0;
    D_8006196C.field_2 = a1;
    D_8006196C.field_C = flags & 1;
    D_8006198E = flags & 4;
    D_8006196C.field_D = a4;
    func_8002AE4C((u16)a0, (u16)a1, flags & 4);
}

/* y_div_x_inpb */
/* b_p */
void func_8002AE4C(a0, a1)
u16 a0;
u16 a1;
{
    s32 asp;
    BlkFill618D0 *p;
    Rect2AB54 *r;

    D_80061990 = a0;
    D_80061994 = a1;
    asp = (*(volatile s32 *)&D_80061994 << 14) / *(volatile s32 *)&D_80061990;
    do {
    D_80061A28.m[2][2] = D_80061A28.m[1][1] = D_80061A28.m[0][0] = 0x1000;
    D_80061A28.m[2][0] = D_80061A28.m[2][1] = D_80061A28.m[1][0] = D_80061A28.m[1][2] = D_80061A28.m[0][1] = D_80061A28.m[0][2] = 0;
    D_80061A28.t[0] = D_80061A28.t[1] = D_80061A28.t[2] = 0;
    (*(Mat1F668 *)&D_80061A48) = D_80061A28;
    } while (0);
    do {
    D_800619A8 = D_80061A28;
    D_800619A8.m[0][0] = D_800619A8.m[1][1] = D_800619A8.m[2][2] = 0;
    D_800619C8 = D_800619A8;
    } while (0);
    D_800618F8.field_0 = 0;
    D_800618F8.field_2 = 0;
    D_800618FC.field_0 = 0;
    D_800618FC.field_2 = 0;
    D_80061900.field_0 = D_80061900.field_2 = 0;
    r = &D_80061980;
    r->y = 0;
    (*(Mat1F668 *)&D_80061A48).m[1][1] = asp / 3;
    do {
    p = D_800618D0;
    r->x = 0;
    p->len = 3;
    p->code = 2;
    p++;
    p->len = 3;
    p->code = 2;
    } while (0);
    D_80061988 = 1;
    r->w = D_80061990;
    r->h = D_80061994;
}


void func_8002B06C(u8 r, u8 g, u8 b, Db2B06C *db) {
    s32 i;

    D_800618D0[D_8006198C].r = r;
    D_800618D0[D_8006198C].g = g;
    D_800618D0[D_8006198C].b = b;
    i = D_8006198C;
    D_800618D0[i].x0 = D_800618F0[i];
    D_800618D0[i].y0 = D_800618F4[i];
    D_800618D0[i].h = D_80061994;
    if (D_8006196C.field_D != 0) {
        D_800618D0[i].w = D_80061990 * 3 / 2;
    } else {
        D_800618D0[i].w = D_80061990;
    }
    func_8002AAF4(db->ot, (unsigned int *)&D_800618D0[D_8006198C]);
}

void func_8002B1A4() {
    s32 x;
    s32 y;

    if (D_8006198E != 0) {
        D_8006197E = 0;
        D_8006197C = 0;
        D_80061908.ofs[0] = D_80061900.field_0 + D_800618F0[D_8006198C];
        D_80061908.ofs[1] = D_80061900.field_2 + D_800618F4[D_8006198C];
        func_80027AE4(&D_80061908);
    } else {
        x = D_80061900.field_0 + *(D_8006198C ? &D_800618F0[0] : &D_800618F0[1]);
        y = D_80061900.field_2 + *(D_8006198C ? &D_800618F4[0] : &D_800618F4[1]);
        func_8002D6A4(x, y);
        D_8006197C = x;
        D_8006197E = y;
    }
}


void func_8002B2B4(void) {
    DrawEnv *dst = &D_80061908;
    Rect2AB54 *src = &D_80061980;
    s32 dx = D_800618F0[D_8006198C];
    s32 dy = D_800618F4[D_8006198C];
    s32 x;
    s32 y;

    dst->clip_w = src->w;
    dst->clip_h = src->h;
    x = src->x;
    y = src->y;
    dst->clip_x = x + dx;
    dst->clip_y = y + dy;
    func_80027AE4(dst);
}

void func_8002B334(s32 a0, s32 a1) {
    s32 x;
    s32 y;

    if (D_8006198E != 0) {
        D_8006197E = 0;
        D_8006197C = 0;
        D_80061908.ofs[0] = D_800618F0[D_8006198C] + a0;
        D_80061908.ofs[1] = D_800618F4[D_8006198C] + a1;
        func_80027AE4(&D_80061908);
    } else {
        x = a0 + *(D_8006198C ? &D_800618F0[0] : &D_800618F0[1]);
        y = a1 + *(D_8006198C ? &D_800618F4[0] : &D_800618F4[1]);
        func_8002D6A4(x, y);
        D_8006197C = x;
        D_8006197E = y;
    }
}


void func_8002B424(Coord1F668 *super, Coord1F668 *c) {
    c->coord = D_80061A28;
    c->super = super;
    c->flg = 0;
    if ((u32)super >= 2) {
        c->super->sub = c;
    }
}


extern void func_8002D5E4();
extern s32 func_8002D644();

s32 func_8002B494(s32 a0) {
    func_8002D5E4(a0);
    return func_8002D644(a0);
}
__asm__(".word 0\n");

void func_8002B4C4(void) {
    D_80061900.field_0 = D_80061990 / 2;
    D_80061900.field_2 = D_80061994 / 2;
    func_8002B1A4(&D_80061900);
    D_800619A0 = 10;
    D_8006199C = 0;
    D_80061998 = 0x3FFF;
}

void func_8002B544(s32 arg0) { func_8002D6C4(); }

s32 func_8002B564(s32 idx, Blk16 *src) {
    S32 lm;
    S32 cm;
    s32 r;
    s32 g;
    s32 b;
    s32 len;

    r = src->r;
    g = src->g;
    b = src->b;
    lm = D_800619A8;
    func_8002BA80(&cm);
    len = func_8002CEE4(src->x * src->x + src->y * src->y + src->z * src->z);
    if (len == 0) {
        return -1;
    }
    switch (idx) {
    case 0:
        lm.m[0][0] = -src->x * 4096 / len;
        lm.m[0][1] = -src->y * 4096 / len;
        lm.m[0][2] = -src->z * 4096 / len;
        cm.m[0][0] = (r << 12) / 255;
        cm.m[1][0] = (g << 12) / 255;
        cm.m[2][0] = (b << 12) / 255;
        break;
    case 1:
        lm.m[1][0] = -src->x * 4096 / len;
        lm.m[1][1] = -src->y * 4096 / len;
        lm.m[1][2] = -src->z * 4096 / len;
        cm.m[0][1] = (r << 12) / 255;
        cm.m[1][1] = (g << 12) / 255;
        cm.m[2][1] = (b << 12) / 255;
        break;
    case 2:
        lm.m[2][0] = -src->x * 4096 / len;
        lm.m[2][1] = -src->y * 4096 / len;
        lm.m[2][2] = -src->z * 4096 / len;
        cm.m[0][2] = (r << 12) / 255;
        cm.m[1][2] = (g << 12) / 255;
        cm.m[2][2] = (b << 12) / 255;
        break;
    }
    D_800619A8 = lm;
    func_8002BA1C(&cm);
    return 0;
}


extern S32 D_800619C8;
extern void func_8002D614(S32 *);

void func_8002BA1C(S32 *src) {
    D_800619C8 = *src;
    func_8002D614(src);
}
void func_8002BA80(S32 *dst) { *dst = D_800619C8; }

void func_8002BAD4(s32 a0) {
    switch (a0) {
    case 0:
        D_8006199C = 0;
        break;
    case 1:
        D_8006199C = a0;
        break;
    case 2:
        D_8006199C = a0;
        break;
    case 3:
        D_8006199C = a0;
        break;
    default:
        func_8002A014(D_80010624, a0);
        break;
    }
}

void func_8002BB54(s32 arg0, s32 arg1, s32 arg2) { func_8002D664(arg0 >> 4, arg1 >> 4, arg2 >> 4); }

void func_8002BB84(void) {
    func_8002CE5C();
    func_8002D684(0, 0, 0);
    func_8002D6A4(0, 0);
    D_8006197E = 0;
    D_8006197C = 0;
}

void func_8002BBD4(u32 *tim, TimInfo2BBD4 *out) {
    u32 flag = *tim;
    u32 *p;

    out->mode = flag;
    if ((flag >> 3) & 1) {
        tim++;
        p = tim + (*tim >> 2);
        tim++;
        out->crect.x = ((TimHalves *)tim)->lo;
        out->crect.y = ((TimHalves *)tim)->hi;
        tim++;
        out->crect.w = ((TimHalves *)tim)->lo;
        out->crect.h = ((TimHalves *)tim)->hi;
        tim++;
        out->caddr = tim;
        p++;
        out->prect.x = ((TimHalves *)p)->lo;
        out->prect.y = ((TimHalves *)p)->hi;
        p++;
        out->prect.w = ((TimHalves *)p)->lo;
        out->prect.h = ((TimHalves *)p)->hi;
        p++;
        out->paddr = p;
    } else {
        tim += 2;
        out->prect.x = ((TimHalves *)tim)->lo;
        out->prect.y = ((TimHalves *)tim)->hi;
        tim++;
        out->prect.w = ((TimHalves *)tim)->lo;
        out->prect.h = ((TimHalves *)tim)->hi;
        tim++;
        out->paddr = tim;
    }
}


void func_8002BCC4(Mat1F668 *m, s16 s, s16 c, s8 axis) {
    *m = D_80061A28;
    switch (axis) {
    case 'X':
    case 'x':
        m->m[1][1] = c;
        m->m[2][2] = c;
        m->m[1][2] = -s;
        m->m[2][1] = s;
        break;
    case 'Y':
    case 'y':
        m->m[0][0] = c;
        m->m[2][2] = c;
        m->m[0][2] = s;
        m->m[2][0] = -s;
        break;
    case 'Z':
    case 'z':
        m->m[0][0] = c;
        m->m[1][1] = c;
        m->m[0][1] = -s;
        m->m[1][0] = s;
        break;
    }
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002BD94);

extern void func_8002CF74(ObjC0E4 *, s32 *, s32 *);
extern void func_8002D224(ObjC0E4 *, ArgC0E4 *);
extern void func_8002D334(ObjC0E4 *, ArgC0E4 *);

void func_8002C064(ObjC0E4 *a0, ArgC0E4 *a1) {
    s32 tmp[3];
    func_8002CF74(a0, &a1->field_14, tmp);
    func_8002D334(a0, a1);
    a1->field_14 = tmp[0] + a0->field_14;
    a1->field_18 = tmp[1] + a0->field_18;
    a1->field_1C = tmp[2] + a0->field_1C;
}

void func_8002C0E4(ObjC0E4 *a0, ArgC0E4 *a1) {
    s32 tmp[3];
    func_8002CF74(a0, &a1->field_14, tmp);
    func_8002D224(a0, a1);
    a0->field_14 = tmp[0] + a0->field_14;
    a0->field_18 = tmp[1] + a0->field_18;
    a0->field_1C = tmp[2] + a0->field_1C;
}

s32 func_8002C164(Ctx19214 *c) {
    Mat1F668 m0;
    Mat1F668 m;
    ObjC0E4 o;
    ObjC0E4 o0;
    s32 v[3];
    u32 d;
    u32 x;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 e;
    s16 a;
    s16 b;
    s32 ret;

    D_80061A08 = D_80061A48;
    func_8002C774(&D_80061A08, -c->field_18);
    dx = c->field_C - c->field_0;
    dy = c->field_10 - c->field_4;
    dz = c->field_14 - c->field_8;
    d = dx * dx + dy * dy + dz * dz;
    ret = 1;
    if (d != 0) {
        dy = c->field_4 - c->field_10;
        x = dy * dy;
        e = 12 - func_8002DBB4(x);
        if (e < 0) {
            a = -((c->field_4 - c->field_10) << 12) / func_8002CEE4(d);
        } else if (c->field_4 - c->field_10 >= 0) {
            a = -func_8002CDB8((x << (12 - e)) / (d >> e));
        } else {
            a = func_8002CDB8((x << (12 - e)) / (d >> e));
        }
        dx = c->field_C - c->field_0;
        dz = c->field_14 - c->field_8;
        x = dx * dx + dz * dz;
        e = 12 - func_8002DBB4(x);
        if (e < 0) {
            b = (func_8002CEE4(x) << 12) / func_8002CEE4(d);
        } else {
            b = func_8002CDB8((x << (12 - e)) / (d >> e));
        }
        func_8002BCC4(&m, a, b, 0x78);
        func_8002D224(&D_80061A08, (ArgC0E4 *)&m);
        if (x != 0) {
            d = x;
            dx = c->field_C - c->field_0;
            x = dx * dx;
            e = 12 - func_8002DBB4(x);
            if (e < 0) {
                a = -((c->field_C - c->field_0) << 12) / func_8002CEE4(d);
            } else if (c->field_C - c->field_0 >= 0) {
                a = -func_8002CDB8((x << (12 - e)) / (d >> e));
            } else {
                a = func_8002CDB8((x << (12 - e)) / (d >> e));
            }
            dz = c->field_14 - c->field_8;
            x = dz * dz;
            e = 12 - func_8002DBB4(x);
            if (e < 0) {
                b = ((c->field_14 - c->field_8) << 12) / func_8002CEE4(d);
            } else if (c->field_14 - c->field_8 >= 0) {
                b = func_8002CDB8((x << (12 - e)) / (d >> e));
            } else {
                b = -func_8002CDB8((x << (12 - e)) / (d >> e));
            }
            func_8002BCC4(&m, a, b, 0x79);
            func_8002D224(&D_80061A08, (ArgC0E4 *)&m);
        }
        v[0] = -c->field_0;
        v[1] = -c->field_4;
        v[2] = -c->field_8;
        func_8002CF74(&D_80061A08, v, &D_80061A08.field_14);
        if (c->field_1C != NULL) {
            func_8002C834(c->field_1C, &m);
            func_8002D704((Obj2D704 *)&m, (Obj2D704 *)&o);
            func_8002CF74(&o, &m.t[0], v);
            o.field_14 = -v[0];
            o.field_18 = -v[1];
            o.field_1C = -v[2];
            func_8002C064(&D_80061A08, (ArgC0E4 *)&o);
            D_80061A08 = o;
        }
        D_800619E8 = D_80061A08;
        ret = 0;
    }
    return ret;
}


extern s32 func_8002CBC4(s32);
extern s32 func_8002CAF4(s32);

void func_8002C774(ObjC0E4 *a0, s32 a1) {
    ArgC0E4 mtx;
    s32 a = a1 / 360;
    s32 c = func_8002CBC4(a);
    s32 s = func_8002CAF4(a);
    if (a1 == 0) {
        return;
    }
    mtx.m[0][0] = c;
    mtx.m[0][1] = -s;
    mtx.m[0][2] = 0;
    mtx.m[1][0] = s;
    mtx.m[1][1] = c;
    mtx.m[1][2] = 0;
    mtx.m[2][0] = 0;
    mtx.m[2][1] = 0;
    mtx.m[2][2] = 0x1000;
    mtx.field_14 = 0;
    mtx.field_18 = 0;
    mtx.field_1C = 0;
    func_8002D224(a0, &mtx);
}
__asm__(".word 0\n.word 0\n.word 0\n");

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002C834);

s32 func_8002CAF4(s32 arg0) {
    if (arg0 < 0) {
        return -func_8002CB30(-arg0 & 0xFFF);
    }
    return func_8002CB30(arg0 & 0xFFF);
}

extern s16 D_80049110[];
extern s16 D_80048110[];

s32 func_8002CB30(s32 a) {
    if (a <= 0x800) {
        if (a <= 0x400) {
            return D_80049110[a];
        }
        return D_80049110[0x800 - a];
    }
    if (a <= 0xC00) {
        return -D_80048110[a];
    }
    return -D_80049110[0x1000 - a];
}


extern s16 D_80047910[];
extern s16 D_80048910[];
extern s16 D_80049110[];

s32 func_8002CBC4(s32 a) {
    if (a < 0) {
        a = -a;
    }
    a &= 0xFFF;
    if (a <= 0x800) {
        if (a <= 0x400) {
            return D_80049110[0x400 - a];
        }
        return -D_80048910[a];
    }
    if (a <= 0xC00) {
        return -D_80049110[0xC00 - a];
    }
    return D_80047910[a];
}


s32 func_8002CC64(s32 a) {
    s32 v[2][8];
    s32 i;
    s32 *yb;
    s32 *p;
    s32 *q;
    s32 xx, yy, nx, ny;

    i = 1;
    yb = &v[1][1];
    q = &v[1][2];
    p = &v[0][1];
    v[0][1] = a + 0x5D50AD;
    v[1][1] = a - 0x5D50AD;
    for (; i < 7; q++, i++, p++) {
        if (i != 4) {
            if (p[8] >= 0) {
                p[1] = p[0] - (p[8] >> i);
                *q = p[8] - (p[0] >> i);
            } else {
                p[1] = p[0] + (p[8] >> i);
                yb[i] = p[8] + (p[0] >> i);
            }
        } else {
            yy = v[1][4];
            if (yy >= 0) {
                nx = v[0][4] - (yy >> 4);
                ny = yy - (v[0][4] >> 4);
                v[0][4] = nx;
                v[1][4] = ny;
                if (ny >= 0) {
                    v[0][5] = nx - (ny >> 4);
                    v[1][5] = ny - (nx >> 4);
                } else {
                    v[0][5] = nx + (ny >> 4);
                    v[1][5] = ny + (nx >> 4);
                }
            } else {
                nx = v[0][4] + (yy >> 4);
                ny = yy + (v[0][4] >> 4);
                v[0][4] = nx;
                v[1][4] = ny;
                if (ny >= 0) {
                    v[0][5] = nx - (ny >> 4);
                    v[1][5] = ny - (nx >> 4);
                } else {
                    v[0][5] = nx + (ny >> 4);
                    v[1][5] = ny + (nx >> 4);
                }
            }
        }
    }
    return v[0][7];
}

extern s32 func_8002DBB4(s32);
extern s32 func_8002CC64(s32);

s32 func_8002CDB8(s32 a0) {
    s32 e, sh, x;
    if (a0 == 0) {
        return 0;
    }
    e = 8 - func_8002DBB4(a0);
    if (e >= 0) {
        sh = e >> 1;
        x = a0 >> (sh << 1);
    } else {
        sh = (e >> 1) + 1;
        x = a0 << (-(sh << 1));
    }
    sh -= 6;
    if (sh >= 0) {
        return func_8002CC64(x) << sh;
    }
    return func_8002CC64(x) >> (-sh);
}
__asm__(".word 0\n");

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002CE54);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002CE5C);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002CEE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002CF74);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D0D4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D178);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D224);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D334);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D444);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D4A4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D5E4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D614);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D644);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D664);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D684);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D6A4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D6C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D6D4);

Obj2D704 *func_8002D704(Obj2D704 *src, Obj2D704 *dst) {
    s32 a;
    s32 b;
    s32 c;
    s32 e;
    s32 x;

    a = src->f0.w;
    b = src->f4.w;
    dst->f4.w = a;
    dst->f0.w = b;
    dst->f0.h = a;
    c = src->f8.w;
    e = src->fC.w;
    dst->fC.w = c;
    dst->f8.w = e;
    dst->fC.h = b;
    dst->f8.h = c;
    x = src->f10;
    dst->f4.h = e;
    dst->f10 = x;
    return dst;
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002D744);

s32 func_8002D944(s32 y, s32 x) {
    s32 c;
    s32 r;
    s32 s1 = 0;
    s32 s2 = 0;

    if (x < 0) {
        s1 = 1;
        x = -x;
    }
    if (y < 0) {
        s2 = 1;
        y = -y;
    }
    if (x == 0 && y == 0) {
        return 0;
    }
    if (y < x) {
        if (y & 0x7FE00000) {
            c = y / (x >> 10);
        } else {
            c = (y << 10) / x;
        }
        c = D_8004DDC0[c];
    } else {
        if (x & 0x7FE00000) {
            c = x / (y >> 10);
        } else {
            c = (x << 10) / y;
        }
        c = 0x400 - D_8004DDC0[c];
    }
    if (s1) {
        c = 0x800 - c;
    }
    if (s2) {
        c = -c;
    }
    return c;
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002DAC4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002DB70);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002DBA4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002DBB4);

void func_8002DBD4(s32 arg0, s32 arg1) {
    D_80061B38 = arg0;
    D_80061B3C = arg1;
    func_8002DE94();
}

s32 func_8002DC04(void) {
    s32 i;

    i = 4;
loop:
    if (func_8002DC94() != 1) {
        if (--i != -1) {
            goto loop;
        }
        func_8002A014(D_800106D4);
        return 0;
    }
    D_8004E6C8 = func_8002DCD0;
    D_8004E6CC = (s32)func_8002DCF8;
    D_8004E5E0 = func_8002DD20;
    D_8004E5E4 = 0;
    return 1;
}


s32 func_8002DC94(void) {
    if (func_8002FF04() != 0) {
        return 0;
    }
    return func_8002FDC8() == 0;
}

void func_8002DCD0(void) { func_8002DD54(0xF0000003, 0x20); }

void func_8002DCF8(void) { func_8002DD54(0xF0000003, 0x40); }

void func_8002DD20(void) { func_8002DD54(0xF0000003, 0x40); }

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8002DD54);

s32 func_8002DD64(void *arg) {
    u8 *p = arg;

    return (((p[0] >> 4) * 10 + (p[0] & 0xF)) * 60
          + ((p[1] >> 4) * 10 + (p[1] & 0xF))) * 75
         + ((p[2] >> 4) * 10 + (p[2] & 0xF)) - 150;
}

extern s32 D_80061B98;
extern void func_8002DE68(void);

void func_8002DDE4(s32 arg0) {
    u8 b = arg0;

    func_80030554(0xE, &b, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_80061B98 = 0;
        } else {
            D_80061B98 = 1;
        }
        func_80030A34((s32)func_8002DF74);
        func_80030534((s32)func_8002DE68);
    }
    func_80030554(0x1B, 0, 0);
}

void func_8002DE68(void) { func_8002E2C4(); }

void func_8002DE94(void) {
    D_80061B24 = 0;
    D_80061B20 = 0;
    D_80061B1C = 0;
    D_80061B14 = 0;
    func_8002E1A4(0, D_80061B3C);
    D_80061B04 = 0;
    D_80061AFC = 0;
    D_80061AF8 = 0;
}

void func_8002DEF4(void) {
    func_80026FC4();
    if (D_8004E6E8 == 1) {
        func_80030A84(0);
        func_80030A64(0);
    } else {
        func_80030A34(0);
        func_80030534(0);
    }
    *D_8004E600 = 0;
    *D_8004E60C = 0;
    func_80026FD4();
}

void func_8002DF74(void) {
    Rec2DF74 *r = &((Rec2DF74 *)D_80061B38)[D_80061B20];
    void (*cb)(void);

    r->field_0 = 2;
    *(B4_2DF74 *)&D_80061B40 = r->field_1C;
    D_80061B44 = r->field_8;
    D_80061B20 = ((W1_2DF74 *)&D_80061B1C)->v;
    cb = ((F1_2DF74 *)&D_80061B50)->f;
    if (cb != 0) {
        cb();
    }
    D_80061B14 = 0;
}


extern s32 D_80061B98;
extern s32 D_80061B40;
extern s32 D_80061B44;

s32 func_8002E000(s32 arg0) {
    s32 t;
    if (D_80061B98 != 0) {
        return -1;
    }
    t = func_8002DD64(&D_80061B40);
    func_80030394(t + 1, arg0);
    return D_80061B44;
}
__asm__(".word 0\n.word 0\n.word 0\n");

void func_8002E064(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_8002E2A4(1, a1, a2);
    D_80061B28 = 0;
    D_80061B50 = a3;
    D_80061B00 = a0 & 1;
    D_80061B10 = 0;
    D_80061B08 = 0;
    D_80061AFC = 0;
    D_80061AF8 = 0;
    D_80061B54 = a4;
}

s32 func_8002E0F4(u32 *arg0) {
    s32 idx;
    s32 i;
    s32 ret = 1;
    u16 n;
    Rec2DF74 *r;

    idx = (arg0 - (u32 *)&((Rec2DF74 *)D_80061B38)[D_80061B3C]) / 504;
    r = &((Rec2DF74 *)D_80061B38)[idx];
    n = r->field_6;
    if (r->field_0 != 4) {
        goto end;
    }
    for (i = 0; i < (s16)n; i++) {
        ((Rec2DF74 *)*(volatile s32 *)&D_80061B38)[i + idx].field_0 = 0;
    }
    D_80061B24 = i + idx;
    ret = 0;
end:
    return ret;
}


void func_8002E1A4(s32 first, s32 n) {
    u32 i;
    s32 *w;

    for (i = 0; i < (u32)n; i++) {
        w = &((Slot2E1A4 *)D_80061B38)[i + first].field_0;
        *w = 0;
    }
}

s32 func_8002E1E4(Sect2E1E4 **a0, u16 **a1) {
    u16 *s;

    s = &((Slot2E1E4 *)D_80061B38)[D_80061B24].status;
    if (*s == 1) {
        D_80061B24 = 0;
        if (D_80061B2C != 0) {
            *s = 0;
        }
        s = &((Slot2E1E4 *)D_80061B38)[D_80061B24].status;
    }
    if (*(volatile u16 *)s != 2) {
        return 1;
    }
    *s = 4;
    *a0 = &((Sect2E1E4 *)&((Slot2E1E4 *)D_80061B38)[D_80061B3C])[D_80061B24];
    *a1 = s;
    return 0;
}

extern s32 D_80061B30, D_80061B0C, D_80061B2C;
void func_8002E2A4(s32 a0, s32 a1, s32 a2) {
    D_80061B30 = a0;
    D_80061B0C = a1;
    D_80061B2C = a2;
}

extern volatile u32 *D_8004E690;
extern volatile u8 *D_8004E670;
extern volatile u8 *D_8004E67C;
extern volatile u8 *D_8004E678;
extern volatile u32 *D_8004E680;
extern volatile u32 *D_8004E684;
extern volatile u32 *D_8004E6A0;
extern s32 D_8004E6B8;
extern s32 D_80061B18;
extern volatile u16 *D_80061B58;
extern u32 *D_80061B34;
extern void func_800304F4(void);

void func_8002E2C4(void) {
    volatile Res2E2C4 r;
    Hdr2E2C4 hdr;
    u8 res[8];
    u32 i;
    s32 m;
    u32 *s;
    u32 *d;

    if (D_80061B14 == 1) {
        return;
    }
    if (D_80061B00 != 0 && (*D_8004E690 & 0x1000000)) {
        D_80061B04 = 1;
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 1;
        return;
    }
    if (((s32 (*)(s32, u8 *))func_800304F4)(1, res) == 5) {
        return;
    }
    r.stat = res[0];
    r.intr = res[1];
    if (r.stat & 4) {
        D_8004E6B8 = 3;
        return;
    }
    D_80061B58 = &((Sect2E2C4 *)D_80061B38)[D_80061B1C].field_0;
    if (D_80061B58[0] != 0) {
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 4;
        return;
    }
    *D_8004E670 = 0;
    *D_8004E67C = 0;
    *D_8004E670 = 0;
    *D_8004E67C = 0x80;
    *D_8004E680 = 0x20943;
    *D_8004E684 = 0x1323;
    if (D_80061B98 == 0) {
        for (i = 0; i < 4; i++) {
            hdr.b[i] = *D_8004E678;
        }
        for (i = 0; i < 8; i++) {
            *D_8004E678;
        }
    }
    m = 0x11000000;
    if (D_80061B28 != 0) {
        ((void (*)(void *, s32, s32, s32))func_8002EBE0)((void *)D_80061B58, D_80061B28 + D_80061B18 * 2048, 8, 0);
    } else {
        ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, (void *)D_80061B58, 0, 8, m, 0, 0);
    }
    while (*D_8004E6A0 & 0x1000000) {
    }
    ((Sect2E2C4 *)D_80061B58)->field_1C = hdr;
    *D_8004E680 = 0x20843;
    *D_8004E684 = 0x1325;
    if (D_80061B30 == 1 && D_80061B0C != 0) {
        if (D_80061B0C != D_80061B58[4]) {
            D_80061B58[0] = 0;
            if (D_80061B28 != 0) {
                D_80061B18++;
            }
            return;
        }
        D_80061B30 = 0;
    }
    if (D_80061B58[0] != 0x160 || ((D_80061B58[1] >> 10) & 0x1F) != D_80061B10) {
        if (D_80061B28 != 0) {
            D_80061B18 = 0;
        } else {
            D_80061B58[0];
        }
        D_8004E6B8 = 5;
        D_80061B58[0] = 0;
        return;
    }
    if (D_80061AFC != D_80061B58[2] || (D_80061AF8 != 0 && D_80061AF8 != D_80061B58[4])) {
        D_80061AF8 = 0;
        D_80061AFC = 0;
        func_8002E1A4(D_80061B20, D_80061B1C - D_80061B20);
        D_80061B1C = D_80061B20;
        D_80061B58[0] = 0;
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 6;
        return;
    }
    if (D_80061B58[2] == 0) {
        D_80061AFC = 0;
        D_80061AF8 = D_80061B58[4];
        if (D_80061B2C != 0 && (u32)D_80061AF8 >= (u32)D_80061B2C) {
            D_80061AF8 = 0;
            D_80061AFC = 0;
            func_8002E1A4(D_80061B20, D_80061B1C - D_80061B20);
            D_80061B1C = D_80061B20;
            D_80061B58[0] = 0;
            D_80061B30 = 1;
            if (D_80061B54 != 0) {
                ((void (*)(void))D_80061B54)();
            }
            if (D_80061B28 != 0) {
                D_80061B18++;
            }
            D_8004E6B8 = 7;
            return;
        }
        if ((u32)(D_80061B3C - D_80061B1C - 1) < D_80061B58[3]) {
            if (D_80061B2C == 0) {
                D_80061B58[0] = 1;
                D_80061B30 = 1;
                if (D_80061B54 != 0) {
                    ((void (*)(void))D_80061B54)();
                }
                if (D_80061B28 != 0) {
                    D_80061B18++;
                }
                D_8004E6B8 = 8;
                return;
            }
            if (*(s16 *)D_80061B38 != 0) {
                D_80061B58[0] = 0;
                if (D_80061B28 != 0) {
                    D_80061B18++;
                }
                D_8004E6B8 = 9;
                return;
            }
            D_80061B58[0] = 1;
            d = (u32 *)D_80061B38;
            s = (u32 *)D_80061B58;
            D_80061B1C = 0;
            for (i = 0; i < 8; i++) {
                *d++ = *s++;
            }
            D_80061B58 = &((Sect2E2C4 *)D_80061B38)->field_0;
        }
        D_80061B20 = D_80061B1C;
    }
    D_8004E6B8 = 10;
    D_80061AFC++;
    D_80061B34 = (u32 *)((Sect2E2C4 *)D_80061B38 + D_80061B3C) + D_80061B1C * 504;
    if (D_80061B00 != 0) {
        m = 0x11000000;
        *D_8004E680 = 0x20943;
        *D_8004E684 = 0x1323;
    } else {
        m = 0x11400100;
        *D_8004E680 = 0x21020843;
    }
    if (D_80061B58[3] - 1 == D_80061B58[2]) {
        D_80061B14 = 1;
        if (D_80061B28 != 0) {
            ((void (*)(void *, s32, s32, s32))func_8002EBE0)(D_80061B34, D_80061B28 + D_80061B18 * 2048 + 0x20, 0x1F8, 1);
            D_80061B18++;
        } else {
            ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, D_80061B34, 0, 0x1F8, m, 1, 0);
        }
        D_80061AFC = 0;
        D_80061AF8 = 0;
        D_80061B10 = D_80061B08;
    } else {
        if (D_80061B28 != 0) {
            ((void (*)(void *, s32, s32, s32))func_8002EBE0)(D_80061B34, D_80061B28 + D_80061B18 * 2048 + 0x20, 0x1F8, 0);
            D_80061B18++;
        } else {
            ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, D_80061B34, 0, 0x1F8, m, 0, 0);
        }
    }
    *D_8004E684 = 0x1325;
    D_80061B58[0] = 3;
    D_80061B1C++;
    if (D_80061B28 != 0 && D_80061B14 != 0) {
        func_8002DF74();
    }
}


void func_8002EBE0(s32 *dst, s32 *src, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        *dst++ = *src++;
    }
}

void func_8002EC0C(s32 ch, u32 madr, s32 hi, s32 lo, u32 chcr, u8 mode) {
    volatile s32 dummy;
    volatile u32 *p;
    s32 off;
    s32 i;
    volatile Reg2EC0C *r;
    u8 v;
    s32 bit;

    i = 0;
    off = ch * 16;
    while (*(volatile u32 *)(off + 0x1F801088) & 0x01000000) {
        if (i == 0x10000) {
            func_8002A014(D_800106F4, *(volatile u32 *)(off + 0x1F801088));
            break;
        }
        i++;
    }
    if (mode == 1) {
        r = D_8004E68C;
        v = r->b[2] | (1 << ch);
    } else {
        r = D_8004E68C;
        v = r->b[2] & ~(1 << ch);
    }
    r->b[2] = v;
    do {
        dummy = D_8004E68C->w;
    } while (0);
    do {
        bit = 1 << (ch * 4 + 3);
    } while (0);
    p = (volatile u32 *)(ch * 16 + 0x1F801080);
    *D_8004E688 |= bit;
    *p++ = madr;
    *p++ = (hi << 16) | lo;
    while (!(*D_8004E670 & 0x40)) {
    }
    *p = chcr;
    dummy = *p;
}

extern u8 *D_8004E998;

static inline void cd_memcpy2EDB4(u8 *dst, u8 *src, u32 n) {
    if (dst != 0) {
        while (n--) {
            *dst++ = *src++;
        }
    }
}

s32 func_8002EDB4(void) {
    volatile u8 r;
    u8 result[8];
    s32 i;
    s32 j;
    s32 err;

    *D_8004E98C = 1;
    r = *D_8004E990 & 7;
    err = 0;
    if (r == 0) {
        return 0;
    }
    while (r != (*D_8004E990 & 7)) {
        r = *D_8004E990 & 7;
    }
    for (i = 0; i < 8; i++) {
        if (!(*D_8004E98C & 0x20)) {
            break;
        }
        result[i] = *D_8004E998;
    }
    for (j = i; j < 8; j++) {
        result[j] = 0;
    }
    *D_8004E98C = 1;
    *D_8004E990 = 7;
    *D_8004E99C = 7;
    if (r != 3 || D_8004E88C[D_8004E6E5] != 0) {
        if (!(D_8004E6D4 & 0x10) && (result[0] & 0x10)) {
            D_8004E6DC++;
        }
        D_8004E6D4 = result[0] & 0xFF;
        D_8004E6D8 = result[1];
        err = D_8004E6D4 & 0x1D;
    }
    if (r == 5 && D_8004E6D0 >= 3) {
        func_8002A014(D_8001087C);
        if (D_8004E6D0 >= 3) {
            func_8002A014(D_80010888, D_8004E6EC[D_8004E6E5], D_8004E6D4, D_8004E6D8);
        }
    }
    switch (r) {
    case 3:
        if (err) {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 5;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 2;
        } else if (D_8004E78C[D_8004E6E5] != 0) {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 3;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 1;
        } else {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 2;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 2;
        }
    case 2:
        D_8004E9A4.field_0 = err ? 5 : 2;
        cd_memcpy2EDB4(D_80061B68, result, 8);
        return 2;
    case 1:
        if (err && i == 1) {
            err = 0;
        }
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = err ? 5 : 1;
        cd_memcpy2EDB4(D_80061B70, result, 8);
        *D_8004E98C = 0;
        *D_8004E990 = 0;
        return 4;
    case 4:
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = ((volatile Cd4E9A4 *)&D_8004E9A4)->field_2 = 4;
        cd_memcpy2EDB4(D_80061B78, result, 8);
        cd_memcpy2EDB4(D_80061B70, result, 8);
        return 4;
    case 5:
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = 5;
        cd_memcpy2EDB4(D_80061B68, result, 8);
        cd_memcpy2EDB4(D_80061B70, result, 8);
        return 6;
    default:
        func_80030334(D_800108A4);
        func_8002A014(D_800108B8, r);
        return 0;
    }
}


s32 func_8002F318(a0, a1)
    s32 a0;
    u8 *a1;
{
    s32 r;
    s32 n;
    s32 e;
    s32 t;
    u8 s;
    s32 two;
    char **p0;
    s8 **com;
    char **intr;

    D_80061B80 = func_80030AB4(-1) + 0x3C0;
    com = D_8004E6EC;
    intr = D_8004E76C;
    two = 2;
    D_80061B84 = 0;
    D_80061B88 = D_800108D8;
    do {
        if (D_80061B80 < func_80030AB4(-1) || (n = D_80061B84++, n > 0x3C0000)) {
            func_80030334(D_80010850);
            p0 = &intr[D_8004E9A4.field_0];
            func_8002A014(D_80010860, D_80061B88, *(s8 * volatile *)&com[D_8004E6E5], *(char * volatile *)p0, intr[D_8004E9A4.field_1]);
            func_8002FCF4();
            r = -1;
        } else {
            r = 0;
        }
        if (r != 0) {
            return -1;
        }
        if (func_80030E28() != 0) {
            s = *D_8004E98C & 3;
            while ((e = func_8002EDB4()) != 0) {
                if (e & 4) {
                    if (D_8004E6CC != 0) {
                        ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                    }
                }
                if (e & 2) {
                    if (D_8004E6C8 != 0) {
                        ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                    }
                }
            }
            *D_8004E98C = s;
        }
        t = D_8004E9A4.field_0;
        if (t == two || t == 5) {
            D_8004E9A4.field_0 = two;
            cd_memcpy2EDB4(a1, D_80061B68, 8);
            return t;
        }
    } while (a0 == 0);
    return 0;
}


static __inline__ s32 func_8002F598_timeout(s8 **com, char **intr) {
    if (D_80061B80 < func_80030AB4(-1) || D_80061B84++ > 0x3C0000) {
        func_80030334(D_80010850);
        {
        char **p = &intr[D_8004E9A4.field_0];
        func_8002A014(D_80010860, D_80061B88, com[D_8004E6E5], *p, intr[D_8004E9A4.field_1]);
        }
        func_8002FCF4();
        return -1;
    }
    return 0;
}

s32 func_8002F598(mode, result)
s32 mode;
u8 *result;
{
    s32 r;
    s8 **com;
    char **intr;
    s32 ie;
    s32 st;
    s32 v;
    s32 n;
    u8 *src;
    u8 *dst;

    D_80061B80 = func_80030AB4(-1) + 0x3C0;
    D_80061B84 = 0;
    D_80061B88 = D_800108E0;
    com = D_8004E6EC;
    intr = D_8004E76C;
    do {
        if (func_8002F598_timeout(com, intr) != 0) {
            return -1;
        }
        if (func_80030E28() != 0) {
            st = *D_8004E98C & 3;
            while ((ie = func_8002EDB4()) != 0) {
                if (ie & 4) {
                    if (D_8004E6CC != 0) {
                        ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                    }
                }
                if (ie & 2) {
                    if (D_8004E6C8 != 0) {
                        ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                    }
                }
            }
            *D_8004E98C = st;
        }
        if ((v = D_8004E9A4.field_2) != 0) {
            ((volatile Cd4E9A4 *)(Cd4E9A4 *)&D_8004E9A4)->field_2 = 0;
            src = D_80061B78;
            if (result != 0) {
                dst = result;
                for (n = 7; n != -1; n--) {
                    *dst++ = *src++;
                }
            }
            return v;
        }
        if ((v = D_8004E9A4.field_1) != 0) {
            ((volatile Cd4E9A4 *)(Cd4E9A4 *)&D_8004E9A4)->field_1 = 0;
            dst = result;
            src = D_80061B70;
            if (dst != 0) {
                for (n = 7; n != -1; n--) {
                    *dst++ = *src++;
                }
            }
            return v;
        }
    } while (mode == 0);
    return 0;
}


s32 func_8002F860(com, param, result, async)
    u8 com;
    u8 *param;
    u8 *result;
    s32 async;
{
    s32 i;
    s32 r;
    s32 n;
    s32 e;
    s8 **cm;
    char **intr;
    char **p0;
    CdTbl4E80C *t;
    s32 *np;

    if (D_8004E6D0 >= 2) {
        func_8002A014(D_800108EC, D_8004E6EC[com]);
    }
    if (D_8004E80C.field_100[com] != 0 && param == 0) {
        if (D_8004E6D0 > 0) {
            func_8002A014(D_800108F4, D_8004E6EC[com]);
        }
        return -2;
    }
    func_8002F318(0, 0);
    if (com == 2) {
        for (i = 0; i < 4; i++) {
            D_8004E6E0[i] = param[i];
        }
    }
    if (com == 0xE) {
        D_8004E6E4 = param[0];
    }
    D_8004E9A4.field_0 = 0;
    t = &D_8004E80C;
    if (t->field_0[com] != 0) {
        D_8004E9A4.field_1 = 0;
    }
    *D_8004E98C = 0;
    np = t->field_100;
    for (i = 0; i < np[com]; i++) {
        *D_8004E99C = param[i];
    }
    D_8004E6E5 = com;
    *(volatile u8 *)D_8004E998 = com;
    if (async == 0) {
        D_80061B80 = func_80030AB4(-1) + 0x3C0;
        D_80061B84 = 0;
        D_80061B88 = D_80010904;
        if (D_8004E9A4.field_0 == 0) {
            cm = D_8004E6EC;
            intr = D_8004E76C;
            do {
                if (D_80061B80 < func_80030AB4(-1) || (n = D_80061B84++, n > 0x3C0000)) {
                    func_80030334(D_80010850);
                    p0 = &intr[D_8004E9A4.field_0];
                    func_8002A014(D_80010860, D_80061B88, *(s8 * volatile *)&cm[D_8004E6E5], *(char * volatile *)p0, intr[D_8004E9A4.field_1]);
                    func_8002FCF4();
                    r = -1;
                } else {
                    r = 0;
                }
                if (r != 0) {
                    return -1;
                }
                if (func_80030E28() != 0) {
                    com = *D_8004E98C & 3;
                    while ((e = func_8002EDB4()) != 0) {
                        if (e & 4) {
                            if (D_8004E6CC != 0) {
                                ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                            }
                        }
                        if (e & 2) {
                            if (D_8004E6C8 != 0) {
                                ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                            }
                        }
                    }
                    *D_8004E98C = com;
                }
            } while (D_8004E9A4.field_0 == 0);
        }
        cd_memcpy2EDB4(result, D_80061B68, 8);
        r = 0;
        if (D_8004E9A4.field_0 == 5) {
            r = -1;
        }
        return r;
    }
    return 0;
}


extern u8 *D_8004E98C;
extern u8 *D_8004E99C;
extern u8 *D_8004E990;
extern u8 *D_8004E998;
s32 func_8002FC6C(u8 *a0) {
    *D_8004E98C = 2;
    *D_8004E99C = a0[0];
    *D_8004E990 = a0[1];
    *D_8004E98C = 3;
    *D_8004E998 = a0[2];
    *D_8004E99C = a0[3];
    *D_8004E990 = 0x20;
    return 0;
}

void func_8002FCF4(void) {
    *D_8004E98C = 1;
    while (*D_8004E990 & 7) {
        *D_8004E98C = 1;
        *D_8004E990 = 7;
        *D_8004E99C = 7;
    }
    {
        volatile Cd4E9A4 *p = &D_8004E9A4;

        p->field_1 = p->field_2 = 0;
        p->field_0 = 2;
    }
    *D_8004E98C = 0;
    *D_8004E990 = 0;
    *D_8004E994 = 0x1325;
}

s32 func_8002FDC8(void) {
    u8 v[4];

    if (D_8004E9A0[0xDC] == 0 && D_8004E9A0[0xDD] == 0) {
        D_8004E9A0[0xC0] = 0x3FFF;
        D_8004E9A0[0xC1] = 0x3FFF;
    }
    D_8004E9A0[0xD8] = 0x3FFF;
    D_8004E9A0[0xD9] = 0x3FFF;
    D_8004E9A0[0xD5] = 0xC001;
    v[2] = 0x80;
    v[0] = 0x80;
    v[3] = 0;
    v[1] = 0;
    *D_8004E98C = 2;
    *D_8004E99C = v[0];
    *D_8004E990 = v[1];
    *D_8004E98C = 3;
    *D_8004E998 = v[2];
    *D_8004E99C = v[3];
    *D_8004E990 = 0x20;
    return 0;
}

void func_8002FEB8(void) {
    D_8004E6CC = 0;
    D_8004E6C8 = 0;
    D_8004E6D8 = 0;
    D_8004E6D4 = 0;
    func_80030CD4();
    func_80030D04(2, func_80030258);
}

s32 func_8002FF04(void) {
    func_80030334(D_80010944);
    func_8002A014(D_80010950, D_8004E9A8);
    D_8004E6E5 = 0;
    D_8004E6E4 = 0;
    D_8004E6CC = 0;
    D_8004E6C8 = 0;
    D_8004E6D8 = 0;
    D_8004E6D4 = 0;
    func_80030CD4();
    func_80030D04(2, func_80030258);
    *D_8004E98C = 1;
    while (*D_8004E990 & 7) {
        *D_8004E98C = 1;
        *D_8004E990 = 7;
        *D_8004E99C = 7;
    }
    {
        volatile Cd4E9A4 *p = &D_8004E9A4;

        p->field_1 = p->field_2 = 0;
        p->field_0 = 2;
    }
    *D_8004E98C = 0;
    *D_8004E990 = 0;
    *D_8004E994 = 0x1325;
    func_8002F860(1, 0, 0, 0);
    if (D_8004E6D4 & 0x10) {
        func_8002F860(1, 0, 0, 0);
    }
    if (func_8002F860(10, 0, 0, 0) != 0) {
        return -1;
    }
    if (func_8002F860(12, 0, 0, 0) != 0) {
        return -1;
    }
    if (func_8002F318(0, 0) != 2) {
        return -1;
    }
    return 0;
}


s32 func_800300E4(s32 mode) {
    s32 t;
    s32 n;
    char **p0;
    s8 **q;
    char *c;
    s32 lim;
    s8 **com;
    volatile Cd4E9A4 *st;
    char **intr;

    D_80061B80 = func_80030AB4(-1) + 0x3C0;
    lim = 0x3C0000;
    com = D_8004E6EC;
    st = &D_8004E9A4;
    intr = D_8004E76C;
    D_80061B84 = 0;
    D_80061B88 = D_8001095C;
    do {
        if (D_80061B80 < func_80030AB4(-1) || (n = D_80061B84++, n > lim)) {
            func_80030334(D_80010850);
p0 = &intr[st->field_0];
func_8002A014(D_80010860, D_80061B88, *(s8 * volatile *)&com[D_8004E6E5], *(char * volatile *)p0, intr[st->field_1]);
            func_8002FCF4();
            t = -1;
        } else {
            t = 0;
        }
        if (t != 0) {
            return -1;
        }
        if (!(*D_8004E9C0 & 0x01000000)) {
            return 0;
        }
    } while (mode == 0);
    return 1;
}


extern s32 D_8004E970;
void func_8003024C(s32 a0) {
    D_8004E970 = a0;
}

void func_80030258(void) {
    u8 save = *D_8004E98C & 3;
    s32 st;
    void (*cb)(u8, u8 *);
    volatile u8 *p1 = &D_8004E9A4.field_1;
    volatile u8 *p0 = &D_8004E9A4.field_0;

loop:
    st = func_8002EDB4();
    if (st != 0) {
        if (st & 4) {
            cb = (void (*)(u8, u8 *))D_8004E6CC;
            if (cb != 0) {
                cb(*p1, D_80061B70);
            }
        }
        if (st & 2) {
            cb = (void (*)(u8, u8 *))D_8004E6C8;
            if (cb != 0) {
                cb(*p0, D_80061B68);
            }
        }
        goto loop;
    }
    *D_8004E98C = save;
}

void func_80030334(s8 *s) {
    s8 c;

    if (!s) {
        s = D_80010974;
    }
    for (; (c = *s) != 0; ) {
        s++;
        func_8002A744(c);
    }
    func_8002A840();
}

u8 *func_80030394(a0, a1)
s32 a0;
u8 *a1;
{
    s32 D = a0 + 0x96;
    s32 q1 = D / 75;
    s32 r1 = D % 75;
    s32 q2 = q1 / 60;
    s32 r2 = q1 % 60;
    a1[2] = (r1 / 10) * 16 + r1 % 10;
    a1[1] = (r2 / 10) * 16 + r2 % 10;
    a1[0] = (q2 / 10) * 16 + q2 % 10;
    return a1;
}
__asm__(".word 0\n.word 0\n.word 0\n");

u8 func_800304A4(void) {
    return D_8004E6E5;
}

s32 func_800304B4(s32 a0) { s32 old = D_8004E6D0; D_8004E6D0 = a0; return old; }

void func_800304D4(void) { func_8002F318(); }

void func_800304F4(void) { func_8002F598(); }

void *func_80030514(void *a0) { void *old = D_8004E6C8; D_8004E6C8 = a0; return old; }

s32 func_80030534(s32 a0) { s32 old = D_8004E6CC; D_8004E6CC = a0; return old; }

s32 func_80030554(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *param = arg1;
    u8 *result = arg2;
    s32 com = arg0;
    void *old = D_8004E6C8;
    s32 cnt;
    s32 *tbl = D_8004E9E0;
    s32 ret;

    for (cnt = 3; cnt != -1; cnt--) {
        s32 c = com & 0xFF;
        s32 *len = &tbl[c];
        ret = 0;
        D_8004E6C8 = 0;
        if (c != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            func_8002F860(1, 0, 0, 0);
        }
        if (param == 0 || *len == 0 || func_8002F860(2, param, result, 0) == 0) {
            D_8004E6C8 = old;
            if (func_8002F860((u8)com, param, result, 0) == 0) {
                goto end;
            }
        }
    }
    D_8004E6C8 = old;
    ret = -1;
end:
    return ret + 1;
}

s32 func_80030690(s32 arg0, s32 arg1) {
    s32 param = arg1;
    s32 com = arg0;
    void *old = D_8004E6C8;
    s32 cnt;
    s32 *tbl = D_8004E9E0;
    s32 ret;

    for (cnt = 3; cnt != -1; cnt--) {
        s32 c = com & 0xFF;
        s32 *len = &tbl[c];
        ret = 0;
        D_8004E6C8 = 0;
        if (c != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            func_8002F860(1, 0, 0, 0);
        }
        if (param == 0 || *len == 0 || func_8002F860(2, param, 0, 0) == 0) {
            D_8004E6C8 = old;
            if (func_8002F860((u8)com, param, 0, 1) == 0) {
                goto end;
            }
        }
    }
    D_8004E6C8 = old;
    ret = -1;
end:
    return ret + 1;
}


s32 func_800307C4(u8 com, u8 *param, u8 *result) {
    void *old = D_8004E6C8;
    s32 n;
    s32 r;
    s32 *f;

    n = 3;
    do {
        D_8004E6C8 = 0;
        f = &D_8004E9E0[com];
        if (com != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            func_8002F860(1, 0, 0, 0);
        }
        if (param == 0 || *f == 0 || func_8002F860(2, param, result, 0) == 0) {
            D_8004E6C8 = old;
            if (func_8002F860(com, param, result, 0) == 0) {
                r = 0;
                goto done;
            }
        }
    } while (--n != -1);
    r = -1;
    D_8004E6C8 = old;
done:
    if (r != 0) {
        return 0;
    }
    return func_8002F318(0, result) == 2;
}


s32 func_80030914(void *arg0, s32 arg1) {
    return func_80030934() == 0;
}

s32 func_80030934(s32 addr, s32 size) {
    *D_8004EA60 = 0;
    *D_8004EA64 = 0x80;
    *D_8004EA6C = 0x20943;
    *D_8004EA68 = 0x1323;
    *D_8004EA70 |= 0x8000;
    *D_8004EA78 = addr;
    *D_8004EA7C = size | 0x10000;
    while (!(*D_8004EA60 & 0x40)) {
    }
    *D_8004EA74 = 0x11000000;
    while (*D_8004EA74 & 0x01000000) {
    }
    *D_8004EA68 = 0x1325;
    return 0;
}

void func_80030A34(s32 arg0) { func_80030D34(3, arg0); }

extern s32 D_80061BA4;
int func_80030A64(int a0) {
    int old = D_80061BA4;
    D_80061BA4 = a0;
    return old;
}

void func_80030A84(s32 arg0) { func_80030D34(3, arg0); }

s32 func_80030AB4(s32 mode) {
    volatile s32 buf;
    s32 status;
    s32 count;
    s32 v;
    s32 w;
    s32 m;

    status = *D_8004EA88;
    do {
        buf = *D_8004EA8C;
    } while (buf != *D_8004EA8C);
    count = (buf - D_8004EA90) & 0xFFFF;
    if (mode < 0) {
        return D_8004FBC0;
    }
    if (mode == 1) {
        return count;
    }
    m = mode;
    if (m > 0) {
        w = D_8004EA94 - 1;
        v = w + m;
    } else {
        v = D_8004EA94;
    }
    func_80030C2C(v, m > 0 ? m - 1 : 0);
    status = *D_8004EA88;
    func_80030C2C(D_8004FBC0 + 1, 1);
    if (status & 0x400000) {
        while (((status ^ *D_8004EA88) & 0x80000000) == 0) {
        }
    }
    D_8004EA94 = D_8004FBC0;
    do {
        D_8004EA90 = *D_8004EA8C;
    } while (D_8004EA90 != *D_8004EA8C);
    return count;
}


void func_80030C2C(s32 a0, s32 a1) {
    volatile s32 n = a1 << 15;

    while (D_8004FBC0 < a0) {
        if (--n == -1) {
            func_80030334(D_80010984);
            func_80030CC4(0);
            func_80027004(3, 0);
            return;
        }
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80030CC4);

void func_80030CD4(void) {
    D_8004FB80->fn_C();
}

void func_80030D04(s32 arg0, void (*arg1)()) {
    D_8004FB80->fn_8(arg0, arg1);
}

void func_80030D34(s32 arg0, s32 arg1) {
    D_8004FB80->fn_4(arg0, arg1);
}

void func_80030D64(s32 arg0) {
    D_8004FB80->fn_14(4, arg0);
}

void func_80030D98(s32 a0, s32 a1) {
    D_8004FB80->fn_14(a0, a1);
}

void func_80030DC8(void) {
    D_8004FB80->fn_10();
}

void func_80030DF8(void) {
    D_8004FB80->fn_18();
}

u16 func_80030E28(void) {
    return D_8004EAFA;
}

u16 func_80030E38(void) {
    return *D_8004FB88;
}

int func_80030E50(int a0) {
    int old = *D_8004FB88;
    *D_8004FB88 = a0;
    return old;
}

Obj4EAF8 *func_80030E68(void) {
    u16 *r;
    volatile u16 *q;

    if (D_8004EAF8.field_0 != 0) {
        return 0;
    }
    r = D_8004FB84;
    q = D_8004FB88;
    *q = 0;
    *r = *q;
    *D_8004FB8C = 0x33333333;
    func_80031370((s32 *)&D_8004EAF8, 0x41A);
    if (setjmp(D_8004EAF8.field_38) != 0) {
        func_80030F40();
    }
    D_8004EAF8.field_38[1] = (s32)D_8004EAF8.stack_top;
    func_800313D4(D_8004EAF8.field_38);
    D_8004EAF8.field_0 = 1;
    D_8004FB80->fn_14 = (void (*)())func_80031464();
    D_8004FB80->fn_4 = (void (*)())func_80031584();
    func_8003139C();
    func_80026FD4();
    return &D_8004EAF8;
}

void func_80030F40(void) {
    s32 i;
    u16 mask;

    if (D_8004EAF8.field_0 == 0) {
        func_8002A014(D_800109C8, *D_8004FB84);
        func_800313B4();
    }
    D_8004EAF8.field_2 = 1;
    while ((mask = (D_8004EAF8.field_30 & *(volatile u16 *)D_8004FB84) & *(volatile u16 *)D_8004FB88) != 0) {
        for (i = 0; mask != 0 && i < 11; i++, mask >>= 1) {
            if (mask & 1) {
                *D_8004FB84 = ~(1 << i);
                if (((void (**)(void))D_8004EAF8.field_4)[i] != 0) {
                    ((void (**)(void))D_8004EAF8.field_4)[i]();
                }
            }
        }
    }
    if (*D_8004FB84 & *(volatile u16 *)D_8004FB88) {
        if (D_8004FB90++ > 0x800) {
            func_8002A014(D_800109E4, *D_8004FB84, *(volatile u16 *)D_8004FB88);
            D_8004FB90 = 0;
            *D_8004FB84 = 0;
        }
    } else {
        D_8004FB90 = 0;
    }
    D_8004EAFA = 0;
    func_800313B4();
}

s32 func_80031110(s32 ch, s32 val) {
    s32 *arr = D_8004EAF8.field_4;
    s32 *slot = &arr[ch];
    s32 old = *slot;
    Obj4EAF8 *p;
    s32 m;
    s32 o;
    s32 z;

    if (val != old) {
        p = &D_8004EAF8;
        if (p->field_0 != 0) {
            o = *D_8004FB88;
            *D_8004FB88 = 0;
            m = (u16)o;
            if (val != 0) {
                *slot = val;
                m |= 1 << ch;
                p->field_30 |= 1 << ch;
            } else {
                *slot = 0;
                m &= ~(1 << ch);
                D_8004EAF8.field_30 &= ~(1 << ch);
            }
            if (ch == 0) {
                z = val == 0;
                func_80030CC4(z);
                func_80027004(3, z);
            }
            if (ch == 4) {
                func_80027004(0, val == 0);
            }
            if (ch == 5) {
                func_80027004(1, val == 0);
            }
            if (ch == 6) {
                func_80027004(2, val == 0);
            }
            *D_8004FB88 = m;
        }
    }
    return old;
}

extern u16 *D_8004FB84;
extern void func_800313C4();

Obj4EAF8 *func_80031258(void) {
    Obj4EAF8 *p = &D_8004EAF8;
    volatile u16 *q;
    u16 *r;

    if (p->field_0 == 0) {
        return 0;
    }
    func_80026FC4();
    q = D_8004FB88;
    p->field_32 = *q;
    p->field_34 = *D_8004FB8C;
    r = D_8004FB84;
    *q = 0;
    *r = *q;
    *D_8004FB8C &= 0x77777777;
    func_800313C4();
    p->field_0 = 0;
    return p;
}


Obj4EAF8 *func_800312F8(void) {
    Obj4EAF8 *p = &D_8004EAF8;

    if (p->field_0 != 0) {
        return 0;
    }
    func_800313D4(p->field_38);
    p->field_0 = 1;
    *D_8004FB88 = p->field_32;
    *D_8004FB8C = p->field_34;
    func_80026FD4();
    return p;
}

void func_80031370(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80031394);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003139C);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800313B4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800313C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800313D4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", setjmp);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80031420);

extern void func_800314BC(void);
extern void func_80031528(s32 arg0, void (*arg1)(void));

void (*func_80031464(void))(s32, void (*)(void)) {
    *D_8004FBC4 = 0x100;
    D_8004FBC0 = 0;
    func_80031554(D_8004FBA0, 8);
    func_80030D04(0, func_800314BC);
    return func_80031528;
}

void func_800314BC(void) {
    void (**p)(void);
    s32 i;

    i = 0;
    p = D_8004FBA0;
    D_8004FBC0++;
    do {
        if (*p != 0) {
            (*p)();
        }
        i++;
        p++;
    } while (i < 8);
}

void func_80031528(s32 arg0, void (*arg1)(void)) {
    if (arg1 != D_8004FBA0[arg0]) {
        D_8004FBA0[arg0] = arg1;
    }
}

void func_80031554(s32 *arg0, u32 arg1) {
    while (arg1-- != 0) {
        *arg0++ = 0;
    }
}

void *func_80031584(void) {
    func_800317FC(D_8004FBD4, 8);
    *D_8004FBD0 = 0;
    func_80030D04(3, func_800315D0);
    return func_80031750;
}

void func_800315D0(void) {
    u32 mask;
    s32 i;

    while ((mask = (*(volatile u32 *)D_8004FBD0 >> 24) & 0x7F) != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *(volatile u32 *)D_8004FBD0 &= (1 << (i + 24)) | 0xFFFFFF;
                if (((void (**)(void))D_8004FBD4)[i] != 0) {
                    ((void (**)(void))D_8004FBD4)[i]();
                }
            }
        }
    }
    if ((*(volatile u32 *)D_8004FBD0 & 0xFF000000) == 0x80000000 || (*(volatile u32 *)D_8004FBD0 & 0x8000)) {
        func_8002A014(D_80010A04, *(volatile u32 *)D_8004FBD0);
        for (i = 0; i < 7; i++) {
            func_8002A014(D_80010A20, i, D_8004FBF4[i].madr);
        }
    }
}


s32 func_80031750(s32 ch, s32 v) {
    s32 *p = D_8004FBD4;
    s32 old;

    p += ch;
    old = *p;

    if (v != old) {
        if (v != 0) {
            s32 *d = D_8004FBD0;
            s32 t, b;
            *p = v;
            t = *d & 0xFFFFFF;
            b = (1 << (ch + 16)) | 0x800000;
            *d = t | b;
        } else {
            s32 *e = D_8004FBD0;
            *p = 0;
            *e = ((*e & 0xFFFFFF) | 0x800000) & ~(1 << (ch + 16));
        }
    }
    return old;
}


void func_800317FC(s32 *arg0, u32 arg1) {
    while (arg1-- != 0) {
        *arg0++ = 0;
    }
}

s32 func_80031824(s32 a0) { s32 old = D_8004FC00; D_8004FC00 = a0; return old; }

s32 func_80031838(void) {
    return D_8004FC00;
}
__asm__(".word 0\n.word 0\n.word 0\n");

void func_80031854(void) {
    s32 ch;
    s32 i;
    Elm354F4 **pp;
    Elm354F4 **q;

    if (D_80061C44 == 1) {
        return;
    }
    D_80061C44 = 1;
    func_80036784();
    ch = 0;
    if (ch < D_800624D0) {
    pp = D_80061C50;
    do {
        s32 m = 1 << ch;

        if (!(D_80061C48 & m)) {
            continue;
        }
        i = 0;
        if (i < D_800624D2) {
        q = pp;
        do {
            if ((*q)[i].field_98 & 1) {
                func_80031D74(ch, i);
                if ((*q)[i].field_98 & 0x10) {
                    func_80031AC4(ch, i);
                }
                if ((*q)[i].field_98 & 0x20) {
                    func_80031AC4(ch, i);
                }
                if ((*q)[i].field_98 & 0x40) {
                    func_80035CE4(ch, i);
                }
                if ((*q)[i].field_98 & 0x80) {
                    func_80035CE4(ch, i);
                }
            }
            if ((*q)[i].field_98 & 2) {
                func_80031CD4((s16)ch, (s16)i);
            }
            if ((*q)[i].field_98 & 8) {
                func_80032644((s16)ch, (s16)i);
            }
            if ((*q)[i].field_98 & 4) {
                func_800354F4((s16)ch, (s16)i);
                (*q)[i].field_98 = 0;
            }
        } while (++i < D_800624D2);
        }
    } while (pp++, ++ch < D_800624D0);
    }
    D_80061C44 = 0;
}

void func_80031AC4(s16 a0, s16 a1) {
    Elm354F4 **pp = &D_80061C50[a0];
    Elm354F4 *e = &(*pp)[a1];
    u16 vol[2];
    s32 t;
    s32 d;
    s32 l;
    s32 r;

    t = e->field_A0 + 1;
    e->field_A0 = t;
    if (e->field_9C < t) {
        (*pp)[a1].field_98 &= ~0x10;
    } else {
        d = e->field_48 * t / e->field_9C;
        d -= e->field_4A;
        if (d != 0) {
            e->field_4A += d;
            func_80039150((s16)(a0 | (a1 << 8)), &vol[0], &vol[1]);
            l = vol[0] + d;
            if (l >= 0x80) {
                l = 0x7F;
            }
            if (l < 0) {
                l = 0;
            }
            r = vol[1] + d;
            if (r >= 0x80) {
                r = 0x7F;
            }
            if (r < 0) {
                r = 0;
            }
            func_80038BE4((s16)(a0 | (a1 << 8)), (u16)l, (u16)r, 1);
            if ((l == 0x7F && r == l) || (l == 0 && r == 0)) {
                D_80061C50[a0][a1].field_98 &= ~0x10;
            }
        }
    }
    func_80039150((s16)(a0 | (a1 << 8)), (u16 *)&e->field_5C, (u16 *)&e->field_5E);
}


void func_80031CD4(s32 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[(s16)a0][a1];

    func_800391B4((s16)(a0 | (a1 << 8)));
    e->field_14 = 0;
    D_80061C50[(s16)a0][a1].field_98 &= ~2;
}

void func_80031DA4(s16 arg0, s16 arg1);

void func_80031D74(s16 arg0, s16 arg1) { func_80031DA4(arg0, arg1); }

void func_80031DA4(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    s32 d;
    s32 acc;

    d = e->field_90 - e->field_54;
    if (d > 0) {
        if (e->field_52 > 0) {
            e->field_52--;
        } else if (e->field_52 == 0) {
            e->field_52 = e->field_54;
            e->field_90 = e->field_90 - 1;
        } else {
            e->field_90 = d;
        }
    } else if (e->field_54 >= e->field_90) {
        acc = e->field_90;
        do {
            do {
                func_800320E4(a0, a1);
            } while (e->field_90 == 0);
            acc += e->field_90;
        } while (acc < e->field_54);
        e->field_90 = acc - e->field_54;
    }
}

void func_80031EA0(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];

    e->field_21++;
    if ((s8)e->field_20 == 0) {
        e->field_88 = 0;
        e->field_1C = 0;
        e->field_90 = 0;
        if (D_80061C50[a0][a1].field_98 & 0x400) {
            e->field_0 = e->field_C;
        } else {
            e->field_0 = e->field_4;
        }
        return;
    }
    if ((s8)e->field_21 < (s8)e->field_20) {
        e->field_88 = 0;
        e->field_1C = 0;
        e->field_90 = 0;
        if (D_80061C50[a0][a1].field_98 & 0x400) {
            e->field_0 = e->field_C;
            e->field_8 = (s32)e->field_C;
        } else {
            e->field_0 = e->field_4;
            e->field_8 = (s32)e->field_4;
        }
        return;
    }
    D_80061C50[a0][a1].field_98 &= ~1;
    D_80061C50[a0][a1].field_98 &= ~8;
    D_80061C50[a0][a1].field_98 &= ~2;
    D_80061C50[a0][a1].field_98 |= 0x200;
    D_80061C50[a0][a1].field_98 |= 4;
    e->field_14 = 0;
    if (D_80061C50[a0][a1].field_98 & 0x400) {
        e->field_8 = (s32)e->field_C;
    } else {
        e->field_8 = (s32)e->field_4;
    }
    {
        s8 n = e->field_22;
        if (n != -1) {
            e->field_14 = 0;
            func_80032544(e->field_22, (s8)e->field_23);
            func_800391B4((s16)(a0 | (a1 << 8)));
        }
    }
    func_800391B4((s16)(a0 | (a1 << 8)));
    e->field_90 = e->field_54;
}


s32 func_800320E4(s16 a0, s16 a1) {
    Elm354F4 **pp = &D_80061C50[a0];
    Elm354F4 *e = &(*pp)[a1];
    u8 st = *e->field_0++;
    s32 c;
    s32 d;
    s32 n;
    s32 ev;
    s32 ret = 0;

    if (((*pp)[a1].field_98 & 0x401) == 0x401 && e->field_0 == (u8 *)e->field_10 + 1) {
        ((void (*)(s16, s16, s32))func_80031EA0)(a0, a1, ((u8 *)e->field_10)[1]);
        return -1;
    }
    if (st & 0x80) {
        e->field_17 = st & 0xF;
        ev = st & 0xF0;
        switch (ev) {
        case 0x90:
            e->field_16 = ev;
            n = *e->field_0++;
            d = *e->field_0++;
            e->field_90 = func_80032494(a0, a1);
            D_80061BB0[0](a0, a1, n, d);
            break;
        case 0xB0:
            e->field_16 = ev;
            D_80061BB0[4](a0, a1, *e->field_0++);
            break;
        case 0xC0:
            e->field_16 = ev;
            D_80061BB0[1](a0, a1, *e->field_0++);
            break;
        case 0xE0:
            e->field_16 = ev;
            e->field_0++;
            D_80061BB0[2](a0, a1);
            break;
        case 0xF0:
            e->field_16 = 0xFF;
            st = *e->field_0++; c = st;
            if (c == 0x2F) {
                goto end_track;
            }
            goto meta;
        }
    } else {
        switch (e->field_16) {
        case 0x90:
            d = *e->field_0++;
            e->field_90 = func_80032494(a0, a1);
            D_80061BB0[0](a0, a1, st, d);
            break;
        case 0xB0:
            D_80061BB0[4](a0, a1, st);
            break;
        case 0xC0:
            D_80061BB0[1](a0, a1, st);
            break;
        case 0xE0:
            D_80061BB0[2](a0, a1);
            break;
        case 0xFF:
            c = (u8)st;
            if (c == 0x2F) {
end_track:
                ret = 1;
                ((void (*)(s16, s16, s32))func_80031EA0)(a0, a1, 0x2F);
            } else {
meta:
                D_80061BB0[3](a0, a1, c);
            }
            break;
        }
    }
    return ret;
}


s32 func_80032494(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    u32 v = *e->field_0++;
    s32 r;

    if (v != 0) {
        if (v & 0x80) {
            u32 c;

            v &= 0x7F;
            do {
                c = *e->field_0++;
                v = (v << 7) + (c & 0x7F);
            } while (c & 0x80);
        }
        r = v * 10;
        e->field_88 += r;
    } else {
        r = 0;
    }
    return r;
}

void func_80032544(s32 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[(s16)a0][a1];

    e->field_20 = 1;
    e->field_21 = 0;
    D_80061C50[(s16)a0][a1].field_98 &= ~0x100;
    D_80061C50[(s16)a0][a1].field_98 &= ~8;
    D_80061C50[(s16)a0][a1].field_98 &= ~2;
    D_80061C50[(s16)a0][a1].field_98 &= ~4;
    D_80061C50[(s16)a0][a1].field_98 &= ~0x200;
    e->field_14 = 1;
    e->field_0 = e->field_4;
    D_80061C50[(s16)a0][a1].field_98 |= 1;
}

void func_80032644(s16 a0, s16 a1) {
    D_80061C50[a0][a1].field_14 = 1;
    D_80061C50[a0][a1].field_98 &= ~8;
}

void func_800326A4(s16 id) {
    s32 i;
    Elm354F4 **pp;

    func_80038BE4(id, 0, 0, 1);
    func_800391B4(id);
    D_80061C48 &= ~(1 << id);
    for (i = 0; i < D_800624D2; i++) {
        pp = &D_80061C50[id];
        (*pp)[i].field_98 = 0;
        (*pp)[i].field_22 = -1;
        (*pp)[i].field_23 = 0;
        (*pp)[i].field_48 = 0;
        (*pp)[i].field_4A = 0;
        (*pp)[i].field_9C = 0;
        (*pp)[i].field_A0 = 0;
        (*pp)[i].field_4C = 0;
        (*pp)[i].field_AC = 0;
        (*pp)[i].field_A8 = 0;
        (*pp)[i].field_A4 = 0;
        (*pp)[i].field_4E = 0;
        (*pp)[i].field_58 = 0x7F;
        (*pp)[i].field_5A = 0x7F;
    }
}

void func_80032820(s16 arg0) { func_800326A4(arg0); }

void func_80032844(s16 arg0) { func_800326A4(arg0); }

void func_80032874(void) {
    volatile u16 *dst = (volatile u16 *)0x1F801D80;
    u16 *src = D_8004FC24;
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        *dst++ = *src++;
    }
    func_80036C54(0x18);
    for (i = 0; i < 32; i++) {
        Hook33424 *row = D_80061CD0[i];
        for (j = 15; j >= 0; j--) {
            row[j] = 0;
        }
    }
    D_80061C4C = 0x3C;
    D_80061C48 = 0;
    D_80061C44 = 0;
}


void func_80032914(void) {
    func_80030CD4();
    func_8003A034();
    func_8003C3A4(7);
    func_80032874();
}

s16 func_80032954(s32 src, s16 arg1, s32 count) {
    s16 code;
    s32 i;
    s16 j;
    s32 r;
    s32 m;

    code = 0;
    if (D_80061C48 == -1) {
        func_8002A014(D_80010A34);
        return -1;
    }
    D_80061BB0[0] = (TextOp)func_800348D4;
    D_80061BB0[1] = (TextOp)func_800349B4;
    D_80061BB0[3] = (TextOp)func_80034704;
    D_80061BB0[2] = (TextOp)func_80034424;
    D_80061BB0[4] = (TextOp)func_800344D4;
    D_80061BB0[5] = (TextOp)func_80032C54;
    D_80061BB0[7] = (TextOp)func_80033054;
    D_80061BB0[8] = (TextOp)func_80033124;
    D_80061BB0[9] = (TextOp)func_800331F4;
    D_80061BB0[10] = (TextOp)func_800332E4;
    D_80061BB0[11] = (TextOp)func_80033424;
    D_80061BB0[12] = (TextOp)func_80033524;
    D_80061BB0[13] = (TextOp)func_80033664;
    D_80061BB0[14] = (TextOp)func_800336D4;
    D_80061BB0[15] = (TextOp)func_80033394;
    D_80061BB0[16] = (TextOp)func_80033744;
    D_80061BB0[6] = (TextOp)func_80032CD4;
    D_80061BB0[17] = (TextOp)func_80033804;
    D_80061BB0[18] = (TextOp)func_80033894;
    D_80061BB0[19] = (TextOp)func_80033954;
    D_80061BB0[20] = (TextOp)func_800339E4;
    D_80061BB0[21] = (TextOp)func_80033A74;
    D_80061BB0[22] = (TextOp)func_80033C24;
    D_80061BB0[23] = (TextOp)func_80033CE4;
    D_80061BB0[24] = (TextOp)func_80033D94;
    D_80061BB0[25] = (TextOp)func_80033E44;
    D_80061BB0[26] = (TextOp)func_80033EF4;
    D_80061BB0[27] = (TextOp)func_80033FB4;
    D_80061BB0[28] = (TextOp)func_80034064;
    D_80061BB0[29] = (TextOp)func_80034114;
    D_80061BB0[30] = (TextOp)func_800341F4;
    D_80061BB0[31] = (TextOp)func_80034294;
    D_80061BB0[32] = (TextOp)func_80034334;
    D_80061BB0[33] = (TextOp)func_80034364;
    D_80061BB0[34] = (TextOp)func_80034394;
    D_80061BB0[35] = (TextOp)func_800343C4;
    D_80061BB0[36] = (TextOp)func_800343F4;
    for (i = 0; i < 32; i++) {
        m = 1 << i;
        if (!(D_80061C48 & m)) {
            code = i;
            break;
        }
    }
    D_80061C48 |= 1 << code;
    for (j = 0; j < (s16)count; j++) {
        r = func_80034A24(code, j, arg1, src);
        src += r;
        if (r == -1) {
            return -1;
        }
    }
    return code;
}


void func_80032C54(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &D_80061C50[arg0][arg1];
    e->field_26 = *e->field_0++;
    e->field_90 = func_80032494(arg0, arg1);
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80032CD4);

void func_80033054(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    u8 k = e->field_17;

    func_80039334((s16)(a0 | (a1 << 8)), (s8)e->field_26, e->field_37[k], a2, e->field_27[k]);
    e->field_60[k] = a2;
    e->field_90 = func_80032494(a0, a1);
}

void func_80033124(s16 a0, s16 a1, s32 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    s32 i = e->field_17;

    func_80039334(a0 | (a1 << 8), e->field_26, e->field_37[i], e->field_60[i], (u8)a2);
    e->field_27[i] = a2;
    e->field_90 = func_80032494(a0, a1);
}

void func_800331F4(s16 a0, s16 a1, s32 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    u8 k = e->field_17;

    func_80038B74((s8)e->field_26, e->field_37[k], (u8)a2);
    func_80039334(a0 | (a1 << 8), (s8)e->field_26, e->field_37[k], e->field_60[k], e->field_27[k]);
    e->field_90 = func_80032494(a0, a1);
}

extern void func_80036764(void);
extern void func_80036774(void);

void func_800332E4(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];

    if (a2 < 0x40) {
        func_80036764();
    } else {
        func_80036774();
    }
    e->field_90 = func_80032494(a0, a1);
}

void func_80033394(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];

    func_800363E4(a2, a2);
    e->field_90 = func_80032494(a0, a1);
}

void func_80033424(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    Hook33424 *row;

    if (e->field_1B == 0x28) {
        row = D_80061CD0[a0];
        if (row[a1] != 0) {
            row[a1](a0, a1, a2);
        }
    }
    if (e->field_1B != 0x1E && e->field_1B != 0x14 && e->field_1B != 0x28) {
        e->field_1A = a2;
        e->field_1C = 0;
        e->field_1F++;
    }
    e->field_90 = func_80032494(a0, a1);
}

void func_80033524(a0, a1, a2)
s16 a0;
s16 a1;
u8 a2;
{
    Elm354F4 *e = &D_80061C50[a0][a1];
    u8 n;

    switch (a2) {
    case 0x14:
        e->field_1B = a2;
        e->field_1C = 1;
        e->field_90 = func_80032494(a0, a1);
        e->field_8 = (s32)e->field_0;
        break;
    case 0x1E:
        n = e->field_1D;
        e->field_1B = a2;
        if (n == 0) {
            e->field_15 = 0;
            e->field_90 = func_80032494(a0, a1);
        } else if (n < 0x7F) {
            e->field_1D = n - 1;
            e->field_90 = func_80032494(a0, a1);
            if (e->field_1D != 0) {
                e->field_0 = (u8 *)e->field_8;
            } else {
                e->field_15 = 0;
            }
        } else {
            func_80032494(a0, a1);
            e->field_90 = 0;
            e->field_0 = (u8 *)e->field_8;
        }
        break;
    default:
        e->field_1B = a2;
        e->field_1F++;
        e->field_90 = func_80032494(a0, a1);
        break;
    }
}

void func_80033664(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &D_80061C50[arg0][arg1];
    e->field_18 = arg2;
    e->field_1E++;
    e->field_90 = func_80032494(arg0, arg1);
}

void func_800336D4(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &D_80061C50[arg0][arg1];
    e->field_19 = arg2;
    e->field_1E++;
    e->field_90 = func_80032494(arg0, arg1);
}

void func_80033744(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];

    func_80036554();
    func_80036764();
    e->field_37[e->field_17] = e->field_17;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_60[e->field_17] = 0x7F;
    e->field_27[e->field_17] = 0x40;
    e->field_90 = func_80032494(a0, a1);
}

void func_80033804(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    s32 v = arg.field_24;

    func_80036164(a0, a1, a2, &arg);
    arg.field_0 = v;
    func_80036594(a0, a1, a2, &arg);
}

void func_80033894(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    s32 v = arg.field_24;

    func_80036164(a0, a1, a2, &arg);
    arg.field_1 = v;
    func_80036594(a0, a1, a2, &arg);
    v &= 0xFF;
    if (v == 0) {
        func_80036554();
    } else if (v == 4) {
        func_80036574();
    }
}

void func_80033954(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    s32 flag = d.field_24;

    func_80036164(a0, a1, a2, &d);
    d.field_6 = flag;
    func_80036594(a0, a1, a2, &d);
}

extern s32 func_80036164();
extern s32 func_80036594();

void func_800339E4(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    s32 v = d.field_24;

    func_80036164(a0, a1, a2, &d);
    d.field_7 = v;
    func_80036594(a0, a1, a2, &d);
}


extern s32 func_80036164();
extern void func_80033B80();
extern s32 func_80036594();
void func_80033B24(u32, u32, Out33B24 *);

void func_80033A74(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_A = 0;
    buf.field_0 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033B24(u32 arg0, u32 arg1, Out33B24 *arg2) {
    arg2->field_A = arg0 & 0x8000;
    arg2->field_C = arg1 & 0x8000;
    arg2->field_10 = arg1 & 0x4000;
    arg2->field_E = arg1 & 0x20;
    arg2->field_0 = ((arg0 & 0xFFFF) >> 8) & 0x7F;
    arg2->field_2 = ((arg0 & 0xFFFF) >> 4) & 0xF;
    arg2->field_4 = arg0 & 0xF;
    arg2->field_6 = (arg1 >> 6) & 0x7F;
    arg2->field_8 = arg1 & 0x1F;
}

void func_80033B80(Out33B24 *p, u16 *adsr1, u16 *adsr2) {
    u16 c;
    u16 a;
    u16 m;
    u16 r1;
    u16 r2;
    c = -(p->field_C != 0) & 0x8000;
    a = -(p->field_A != 0) & 0x8000;
    m = c;
    if (p->field_10) {
        m = c | 0x4000;
    }
    if (p->field_E) {
        m |= 0x20;
    }
    r1 = a | ((p->field_0 << 8) & 0x7F00) | ((p->field_2 << 4) & 0xF0) | (p->field_4 & 0xF);
    r2 = m | ((p->field_6 << 6) & 0x1FC0) | (p->field_8 & 0x1F);
    *adsr1 = r1;
    *adsr2 = r2;
}


void func_80033C24(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_A = 1;
    buf.field_0 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033CE4(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = (u8)d.field_24;

    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_2 = v;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033D94(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_4 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033E44(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_C = 0;
    buf.field_6 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033EF4(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_C = 1;
    buf.field_6 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80033FB4(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    func_80036164(a0, a1, a2, &d);
    func_80033B24(d.field_10, d.field_12, &buf);
    buf.field_E = 0;
    buf.field_8 = flag;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80034064(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    s32 f = d.field_24;

    func_80036164(a0, a1, a2, &d);
    buf.field_E = 1;
    buf.field_8 = f;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80034114(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = d.field_24;

    func_80036164(a0, a1, a2, &d);
    if ((u8)(v - 1) < 63) {
        buf.field_10 = 0;
    } else if ((u8)(v - 64) < 64) {
        buf.field_10 = 1;
    }
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_800341F4(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = d.field_24;

    func_80036164(a0, a1, a2, &d);
    d.field_9 = v;
    func_80033B80(&buf, &d.field_10, &d.field_12);
    func_80036594(a0, a1, a2, &d);
}

void func_80034294(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    Out33B24 buf;
    s32 v = arg.field_24;

    func_80036164(a0, a1, a2, &arg);
    arg.field_A = v;
    func_80033B80(&buf, &arg.field_10, &arg.field_12);
    func_80036594(a0, a1, a2, &arg);
}

void func_80034334(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    func_80036474((u8)arg.field_24);
}

void func_80034364(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    func_800363E4((u8)arg.field_24, (u8)arg.field_24);
}

void func_80034394(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    func_80036514((u8)arg.field_24);
}

void func_800343C4(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    func_800363A4((u8)arg.field_24);
}

void func_800343F4(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    func_800363A4((u8)arg.field_24);
}

void func_80034424(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    s32 note = *e->field_0++;

    func_80038A90((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[e->field_17], note);
    e->field_90 = func_80032494(a0, a1);
}

void func_800344D4(s16 a0, s16 a1, s32 a2) {
    s16 i = a0;
    s16 j = a1;
    Elm354F4 *e = &D_80061C50[i][j];
    s32 v = *e->field_0++;

    switch ((u8)a2) {
    case 0:
        e->field_26 = v;
        e->field_90 = func_80032494(i, j);
        return;
    case 6:
        D_80061BC8(i, j, v);
        return;
    case 7:
        D_80061BCC(i, j, v);
        return;
    case 10:
        D_80061BD0(i, j, v);
        return;
    case 11:
        D_80061BD4(i, j, v);
        return;
    case 64:
        D_80061BD8(i, j, v);
        return;
    case 91:
        D_80061BEC(i, j, v);
        return;
    case 98:
        D_80061BDC(i, j, v);
        return;
    case 99:
        D_80061BE0(i, j, v);
        return;
    case 100:
        D_80061BE4(i, j, v);
        return;
    case 101:
        D_80061BE8(i, j, v);
        return;
    case 0x79:
        D_80061BF0(i, j);
        return;
    }
    e->field_90 = func_80032494(a0, a1);
}


void func_80034704(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    s32 b0;
    s32 b1;
    s32 b2;
    u32 t;
    u32 r;

    b0 = *e->field_0++;
    b1 = *e->field_0++;
    b2 = *e->field_0++;
    e->field_94 = 60000000 / (b2 | ((b0 << 16) | (b1 << 8)));
    t = e->field_50 * e->field_94;
    if (t * 10 < D_80061C4C * 60) {
        e->field_52 = D_80061C4C * 600 / t;
        e->field_54 = D_80061C4C * 600 / t;
    } else {
        e->field_52 = -1;
        e->field_54 = (u32)(e->field_50 * e->field_94 * 10) / (D_80061C4C * 60);
        if (D_80061C4C * 30 < (u32)(e->field_50 * e->field_94 * 10) % (D_80061C4C * 60)) {
            e->field_54 = e->field_54 + 1;
        }
    }
    e->field_90 = func_80032494(a0, a1);
}


void func_800348D4(s32 a0, s32 a1, s32 a2, s32 a3) {
    Elm354F4 *e = &D_80061C50[(s16)a0][(s16)a1];
    u8 k = e->field_17;
    s32 v = e->field_27[k];
    s32 on = (u8)a3;

    if (a3 & 0xFF) {
        if (!((e->field_80 >> k) & 1)) {
            func_80036FA4((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[k], (u8)a2, on, v);
        }
    } else {
        func_800374C0((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[k], (u8)a2);
    }
}

void func_800349B4(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &D_80061C50[arg0][arg1];
    e->field_37[e->field_17] = arg2;
    e->field_90 = func_80032494(arg0, arg1);
}

s32 func_80034A24(s16 a0, s16 a1, s16 a2, s32 a3) {
    Elm354F4 *e;
    s32 n;
    s32 i;
    s32 b0;
    s32 b1;
    s32 b2;
    s32 t;
    s32 len;
    s32 r;
    u32 x;
    u32 q;
    u8 *pC;
    u8 *p8;
    u8 *p4;

    n = 0;
    e = &D_80061C50[a0][a1];
    e->field_20 = 1;
    e->field_15 = 0;
    e->field_16 = 0;
    e->field_17 = 0;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_1A = 0;
    e->field_1B = 0;
    e->field_1C = 0;
    e->field_1D = 0;
    e->field_1E = 0;
    e->field_1F = 0;
    e->field_14 = 0;
    e->field_21 = 0;
    e->field_52 = 1;
    e->field_50 = 0;
    e->field_26 = a2;
    e->field_56 = 0;
    e->field_84 = 0;
    e->field_88 = 0;
    e->field_8C = 0;
    e->field_90 = 0;
    e->field_80 = 0;
    e->field_24 = 0;
    e->field_25 = 0;
    for (i = 0; i < 0x10; i++) {
        e->field_27[i] = 0x40;
        e->field_37[i] = i;
        e->field_60[i] = 0x7F;
    }
    e->field_0 = (u8 *)a3;
    if (a1 == 0) {
        if (*e->field_0 == 'S' || *e->field_0 == 'p') {
            e->field_0 += 5;
            if (*e->field_0++ != 0) {
                func_8002A014(D_80010A64);
                return -1;
            }
            e->field_0 += 2;
            n += 8;
        }
    } else {
        e->field_0 += 2;
        n += 2;
    }
    b0 = *e->field_0++;
    b1 = *e->field_0++;
    e->field_50 = b1 | (b0 << 8);
    {
        s32 c0 = *e->field_0++;
        s32 c1 = *e->field_0++;
        s32 c2 = *e->field_0++;
        e->field_8C = c2 | ((c0 << 16) | (c1 << 8));
    }
    n += 5;
    if ((s32)((u32)e->field_8C >> 1) < 0x3938700 % e->field_8C) {
        e->field_8C = 0x3938700 / e->field_8C + 1;
    } else {
        e->field_8C = 0x3938700 / e->field_8C;
    }
    e->field_94 = e->field_8C;
    e->field_24 = *e->field_0++;
    e->field_25 = *e->field_0++;
    b0 = *e->field_0++;
    b1 = *e->field_0++;
    b2 = *e->field_0++;
    t = *e->field_0++;
    len = t | ((b0 << 24) + (b1 << 16) + (b2 << 8));
    n += 6;
    r = func_80032494(a0, a1);
    x = e->field_50 * e->field_8C;
    pC = *(u8 *volatile *)&e->field_0;
    p8 = *(u8 *volatile *)&e->field_0;
    p4 = *(u8 *volatile *)&e->field_0;
    e->field_C = pC;
    e->field_84 = r;
    e->field_90 = r;
    e->field_10 = 0;
    e->field_8 = (s32)p8;
    e->field_4 = p4;
    if (x * 10 < (u32)(D_80061C4C * 60)) {
        e->field_54 = e->field_52 = (u32)(D_80061C4C * 600) / x;
    } else {
        e->field_52 = -1;
        q = (u32)(e->field_50 * e->field_8C * 10) / (u32)(D_80061C4C * 60);
        e->field_54 = q;
        if ((u32)(D_80061C4C * 30) < (u32)(e->field_50 * e->field_8C * 10) % (u32)(D_80061C4C * 60)) {
            e->field_54 = q + 1;
        }
    }
    e->field_56 = e->field_54;
    return n + len;
}


void func_80034E44(s16 a0, s16 a1, s8 a2, s16 a3);

void func_80034E04(s16 arg0, s16 arg1, s8 arg2, s16 arg3) { func_80034E44(arg0, arg1, arg2, arg3); }

void func_80034E44(s16 a0, s16 a1, s8 a2, s16 a3) {
    Elm354F4 **p = &D_80061C50[a0];
    Elm354F4 *e = &(*p)[a1];
    s32 c;

    e->field_0 = e->field_4;
    e->field_8 = e->field_4;
    e->field_C = e->field_4;
    (*p)[a1].field_98 &= ~0x200;
    c = a2;
    (*p)[a1].field_98 &= ~4;
    e->field_20 = a3;
    if (c == 1) {
        (*p)[a1].field_98 |= 1;
        e->field_14 = c;
        e->field_21 = 0;
        func_80038BE4((s16)(a0 | (a1 << 8)), e->field_58, e->field_5A, 1);
    } else if (c == 0) {
        (*p)[a1].field_98 |= 2;
    }
}

void func_80034F64(s8 a0, s8 a1, s8 a2) {
    Cmd3D124 c;

    if (a0 == 0) {
        if (a1 == 0) {
            c.field_0 = 0x200;
            c.field_18 = a2;
        }
        if (a1 == 1) {
            c.field_0 = 0x100;
            c.field_14 = a2;
        }
    }
    if (a0 == 1) {
        if (a1 == 0) {
            c.field_0 = 0x2000;
            c.field_24 = a2;
        }
        if (a1 == 1) {
            c.field_0 = 0x1000;
            c.field_20 = a2;
        }
    }
    func_8003D124(&c);
}

void func_80035024(s16 a0, s16 a1) {
    Cmd3D124 c;

    c.field_0 = 3;
    c.field_4 = a0 * 0x81;
    c.field_6 = a1 * 0x81;
    func_8003D124(&c);
}

void func_80035074(s32 a0) {
    s32 i;
    s32 cmd;
    u16 rate;

    i = 0x3E7;
    do {
        i--;
    } while (i >= 0);
    cmd = 0xF2000002;
    rate = 0x44E8;
    D_8004FC48.b0 = 0;
    D_8004FC48.b1 = 0;
    D_8004FC48.b2 = 6;
    D_8004FC48.fn_4 = 0;
    switch (D_8004FC48.mode) {
    case 0:
        D_8004FC48.b2 = 0x7F;
        return;
    case 5:
        D_8004FC48.b2 = 0;
        if (a0 == 0) {
            D_8004FC48.b0 = 1;
        } else {
            cmd = 0xF2000003;
            rate = 1;
        }
        break;
    case 3:
        rate = 0x89D0;
        break;
    case 2:
        break;
    default:
        if (D_8004FC48.flag != 0) {
            return;
        }
        if (D_8004FC48.mode < 0x46) {
            rate = 0x204CC0 / D_8004FC48.mode;
            D_8004FC48.b1++;
        } else {
            rate = 0x409980 / D_8004FC48.mode;
        }
        break;
    }
    if (D_8004FC48.b0 != 0) {
        func_80026FC4();
        func_80030D64((s32)D_8004FC48.fn_0);
    } else {
        func_80026FC4();
        func_800354BC(cmd);
        func_80035384(cmd, (u16)rate, 0x1000);
        if (D_8004FC48.b2 == 0) {
            D_8004FC48.fn_4 = ((void (*(*)(s32, void (*)(void)))(void))func_80030D04)(0, 0);
            func_80030D04(D_8004FC48.b2, func_800352E4);
        } else if (D_8004FC48.b1 != 0) {
            func_80030D04(D_8004FC48.b2, func_80035330);
        } else {
            func_80030D04(D_8004FC48.b2, D_8004FC48.fn_0);
        }
    }
    func_80026FD4();
}


void func_800352A4(void) { func_80035074(1); }

void func_800352C4(void) { func_80035074(0); }

void func_800352E4(void) {
    if (D_8004FC50.fn_4 != 0) {
        D_8004FC50.fn_4();
    }
    D_8004FC50.fn_0();
}

void func_80035330(void) {
    if (D_8004FC5C == 0) {
        D_8004FC5C = 1;
    } else {
        D_8004FC5C = 0;
        D_8004FC50.fn_0();
    }
}

typedef struct {
    /* 0x0 */ u16 field_0;
    u8 _pad2[2];
    /* 0x4 */ u16 field_4;
    u8 _pad6[2];
    /* 0x8 */ u16 field_8;
    u8 _padA[6];
} Ch35384;

extern Ch35384 *D_8004FC6C;

s32 func_80035384(s32 arg0, s32 arg1, s32 arg2) {
    s32 ch = (u16)arg0;
    s32 flags = 0x48;
    if (ch >= 3) {
        return 0;
    }
    D_8004FC6C[ch].field_4 = 0;
    D_8004FC6C[ch].field_8 = arg1;
    if (ch == 0 || ch == 1) {
        if (arg2 & 0x10) {
            flags = 0x49;
        }
        if (!(arg2 & 1)) {
            flags |= 0x100;
        }
    } else if (ch == 2) {
        if (!(arg2 & 1)) {
            flags |= 0x200;
        }
    }
    if (arg2 & 0x1000) {
        flags |= 0x10;
    }
    D_8004FC6C[ch].field_4 = flags;
    return 1;
}


s32 func_80035420(s32 arg0) {
    s32 ch = arg0 & 0xFFFF;
    s32 ret;

    if (ch < 3) {
        ret = D_8004FC6C[ch].field_0;
    } else {
        ret = 0;
    }
    return ret;
}


s32 func_80035458(u16 arg0) {
    s32 i = arg0;

    D_8004FC68->field_4 |= D_8004FC70[i];
    return i < 3;
}

s32 func_80035488(u16 arg0) {
    D_8004FC68->field_4 &= ~D_8004FC70[arg0];
    return 1;
}

s32 func_800354BC(s32 arg0) {
    s32 ch = arg0 & 0xFFFF;

    if (ch >= 3) {
        return 0;
    }
    D_8004FC6C[ch].field_0 = 0;
    return 1;
}


extern void func_80036764(void);

void func_800354F4(s32 arg0, s32 arg1) {
    Elm354F4 *e;
    s32 i;
    s32 idx = (s16)arg0;

    e = &D_80061C50[idx][(s16)arg1];
    e->field_98 &= ~1;
    D_80061C50[(s16)arg0][(s16)arg1].field_98 &= ~2;
    D_80061C50[(s16)arg0][(s16)arg1].field_98 &= ~8;
    D_80061C50[(s16)arg0][(s16)arg1].field_98 &= ~0x400;
    D_80061C50[(s16)arg0][(s16)arg1].field_98 |= 4;
    func_800391B4((s16)(arg0 | (arg1 << 8)));
    func_80036764();

    e->field_14 = 0;
    e->field_88 = 0;
    e->field_1C = 0;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_1E = 0;
    e->field_1A = 0;
    e->field_1B = 0;
    e->field_1F = 0;
    e->field_17 = 0;
    e->field_21 = 0;
    e->field_1C = 0;
    e->field_1D = 0;
    e->field_15 = 0;
    e->field_16 = 0;
    e->field_90 = e->field_84;
    e->field_94 = e->field_8C;
    e->field_54 = e->field_56;
    e->field_0 = e->field_4;
    e->field_8 = e->field_4;

    for (i = 0; i < 0x10; i++) {
        e->field_37[i] = i;
        e->field_27[i] = 0x40;
        e->field_60[i] = 0x7F;
    }
    e->field_5C = 0x7F;
    e->field_5E = 0x7F;
}

void func_80035674(s16 arg0) { func_800354F4(arg0, 0); }

void func_8003569C(s16 arg0, s16 arg1) { func_800354F4(arg0, arg1); }

void func_800356D4(s8 a0, s16 l, s16 r) {
    Cmd3D124 c;

    if (a0 == 0) {
        c.field_0 = 0xC0;
        if (l >= 0x80) {
            l = 0x7F;
        }
        if (r >= 0x80) {
            r = 0x7F;
        }
        c.field_10 = l * 0x102;
        c.field_12 = r * 0x102;
    }
    if (a0 == 1) {
        c.field_0 = 0xC00;
        if (l >= 0x80) {
            l = 0x7F;
        }
        if (r >= 0x80) {
            r = 0x7F;
        }
        c.field_1C = l * 0x102;
        c.field_1E = r * 0x102;
    }
    func_8003D124(&c);
}

void func_800357E4(void *base, s16 rows, s16 cols) {
    Elm354F4 *b = base;
    Elm354F4 **pp;
    s32 i;
    s32 j;
    s32 m1;
    s32 k;
    s32 n;

    D_800624D0 = rows;
    D_800624D2 = cols;
    i = 0;
    if (i < rows) {
        n = cols;
        pp = D_80061C50;
        do {
            *pp = &b[i * n];
            pp++;
        } while (++i < rows);
    }
    for (i = rows; i < 32; i++) {
        D_80061C48 |= 1 << i;
    }
    i = 0;
    if (i < D_800624D0) {
        m1 = -1;
        k = 0x7F;
        pp = D_80061C50;
        do {
            Elm354F4 **q;

            j = 0;
            if (j < D_800624D2) {
                q = pp;
                do {
                    (*q)[j].field_98 = 0;
                    (*q)[j].field_22 = m1;
                    (*q)[j].field_23 = 0;
                    (*q)[j].field_48 = 0;
                    (*q)[j].field_4A = 0;
                    (*q)[j].field_9C = 0;
                    (*q)[j].field_A0 = 0;
                    (*q)[j].field_4C = 0;
                    (*q)[j].field_AC = 0;
                    (*q)[j].field_A8 = 0;
                    (*q)[j].field_A4 = 0;
                    (*q)[j].field_4E = 0;
                    (*q)[j].field_58 = k;
                    (*q)[j].field_5A = k;
                    (*q)[j].field_5C = k;
                    (*q)[j].field_5E = k;
                } while (++j < D_800624D2);
            }
            pp++;
        } while (++i < D_800624D0);
    }
}


void func_80035A04(s32 arg) {
    s32 mode;

    mode = func_80031838();
    if (arg & 0x1000) {
        D_8004FC48.flag = 1;
        D_8004FC48.mode = arg & 0xFFF;
    } else {
        D_8004FC48.flag = 0;
        D_8004FC48.mode = arg;
    }
    if (D_8004FC48.mode < 6) {
        switch (D_8004FC48.mode) {
        case 4:
            D_80061C4C = 0x32;
            if (mode == 1) {
                D_8004FC48.mode = 5;
            } else {
                D_8004FC48.mode = 0x32;
            }
            break;
        case 1:
            D_80061C4C = 0x3C;
            if (mode == 0) {
                D_8004FC48.mode = 5;
            } else {
                D_8004FC48.mode = 0x3C;
            }
            break;
        case 3:
            D_80061C4C = 0x78;
            break;
        case 2:
            D_80061C4C = 0xF0;
            break;
        case 5:
            if (mode == 0) {
                D_80061C4C = 0x3C;
            } else if (mode == 1) {
                D_80061C4C = 0x32;
            } else {
                D_80061C4C = 0x3C;
            }
            break;
        case 0:
            if (mode == 0) {
                D_80061C4C = 0x3C;
            } else if (mode == 1) {
                D_80061C4C = 0x32;
            } else {
                D_80061C4C = 0x3C;
            }
            break;
        default:
            D_80061C4C = 0x3C;
            break;
        }
    } else {
        D_80061C4C = D_8004FC48.mode;
    }
}


void func_80035B54(s32 a0, s16 a1, s16 a2, s16 a3) {
    Elm354F4 *e = &D_80061C50[(s16)a0][a1];

    if (e->field_98 != 1) {
        e->field_58 = a2;
        e->field_5A = a3;
    } else {
        func_80038BE4((s16)(a0 | (a1 << 8)), (u16)a2, (u16)a3, 1);
    }
}

void func_80035BE4(s16 a0, s16 a1, s16 a2) {
    Elm354F4 *e = D_80061C50[a0];

    if (e->field_98 != 1) {
        e->field_58 = a1;
        e->field_5A = a2;
    } else {
        func_80038BE4(a0, (u16)a1, (u16)a2, 1);
    }
}

void func_80035C4C(s16 a0, s16 a1, s16 a2, s16 a3) {
    Elm354F4 *e = &D_80061C50[a0][a1];

    if (e->field_98 != 1) {
        e->field_58 = a2;
        e->field_5A = a3;
    } else {
        func_80038BE4((s16)(a0 | (a1 << 8)), (u16)a2, (u16)a3, 1);
    }
}

void func_80035CE4(s16 a0, s16 a1) {
    Elm354F4 *e = &D_80061C50[a0][a1];
    s32 t;
    s32 n;
    u32 cur;
    u32 tgt;
    u32 v;

    t = e->field_A8 - 1;
    e->field_A8 = t;
    if (t < 0) {
        D_80061C50[a0][a1].field_98 &= ~0x40;
        D_80061C50[a0][a1].field_98 &= ~0x80;
        return;
    }
    n = e->field_4E;
    if (n > 0) {
        if (t % n != 0) {
            return;
        }
        cur = e->field_94;
        tgt = e->field_AC;
        if (tgt < cur) {
            v = cur - 1;
        } else {
            if (cur >= tgt) {
                goto done;
            }
            v = cur + 1;
        }
        e->field_94 = v;
    } else {
        cur = e->field_94;
        tgt = e->field_AC;
        if (tgt < cur) {
            v = cur + n;
            e->field_94 = v;
            if (v < tgt) {
                e->field_94 = tgt;
            }
        } else if (cur < tgt) {
            v = cur - n;
            e->field_94 = v;
            if ((u32)e->field_AC < v) {
                e->field_94 = e->field_AC;
            }
        }
    }
done:
    e->field_54 = (u32)(e->field_50 * e->field_94 * 10) / (D_80061C4C * 60);
    if (e->field_54 <= 0) {
        e->field_54 = 1;
    }
    if (e->field_A8 == 0 || e->field_94 == e->field_AC) {
        D_80061C50[a0][a1].field_98 &= ~0x40;
        D_80061C50[a0][a1].field_98 &= ~0x80;
    }
}


void func_80035F04(s32 arg) {
    VAttr36C54 attr;
    s16 i;
    s32 bit;

    attr.mask = 0x60093;
    attr.pitch = 0x1000;
    attr.addr = 0x1000;
    attr.adsr1 = 0x80FF;
    attr.vol_l = 0;
    attr.vol_r = 0;
    attr.adsr2 = 0x4000;
    for (i = 0; i < D_80062D0C; i++) {
        bit = 1 << i;
        if (!(D_8004FC18 & bit)) {
            D_800624E8[i].field_2 = 0x18;
            D_800624E8[i].field_6 = 0;
            D_800624E8[i].field_10 = 0xFF;
            D_800624E8[i].field_12 = 0;
            D_800624E8[i].field_14 = 0;
            D_800624E8[i].field_16 = 0xFF;
            D_800624E8[i].field_36 = 0;
            attr.voice = bit;
            func_8003C904(&attr);
            D_80062D30 = i;
            func_80038314(1);
        }
    }
}


s32 func_80036054(s16 a0, s16 a1, SlotHead8 *out) {
    if (D_80062D38[a0] == 1) {
        func_800398D4(a0, a1);
        out->field_0 = D_80062CFC[a1].field_0;
        out->field_1 = D_80062CFC[a1].field_1;
        out->field_2 = D_80062CFC[a1].field_2;
        out->field_3 = D_80062CFC[a1].field_3;
        out->field_4 = D_80062CFC[a1].field_4;
        out->field_6 = D_80062CFC[a1].field_6;
        return 0;
    }
    return -1;
}

s32 func_80036164(s32 a0, s32 a1, s32 a2, Rec62D08 *out) {
    s32 k;

    if (D_80062D38[(s16)a0] == 1) {
        func_800398D4(a0, a1);
        k = (s16)(a2 + D_80062D1F * 16);
        out->field_0 = D_80062D08[k].field_0;
        out->field_1 = D_80062D08[k].field_1;
        out->field_2 = D_80062D08[k].field_2;
        out->field_3 = D_80062D08[k].field_3;
        out->field_4 = D_80062D08[k].field_4;
        out->field_5 = D_80062D08[k].field_5;
        out->field_7 = D_80062D08[k].field_7;
        out->field_6 = D_80062D08[k].field_6;
        out->field_8 = D_80062D08[k].field_8;
        out->field_9 = D_80062D08[k].field_9;
        out->field_A = D_80062D08[k].field_A;
        out->field_B = D_80062D08[k].field_B;
        out->field_C = D_80062D08[k].field_C;
        out->field_D = D_80062D08[k].field_D;
        out->field_10 = D_80062D08[k].field_10;
        out->field_12 = D_80062D08[k].field_12;
        out->field_14 = D_80062D08[k].field_14;
        out->field_16 = D_80062D08[k].field_16;
        return 0;
    }
    return -1;
}


void func_800363A4(s16 arg0) {
    D_80062C18.field_0 = 8;
    D_80062C18.field_C = arg0;
    func_8003B994(&D_80062C18);
}

void func_800363E4(s16 arg0, s16 arg1) {
    D_80062C18.field_0 = 6;
    D_80062C18.field_8 = arg0 * 0x7FFF / 127;
    D_80062C18.field_A = arg1 * 0x7FFF / 127;
    func_8003B994(&D_80062C18);
}

s16 func_80036474(s16 arg0) {
    s32 neg = 0;
    s16 v = arg0;
    s16 r;

    if (arg0 < 0) {
        neg = 1;
        v = -arg0;
    }
    if ((u16)v < 10) {
        Cmd62C18 *c = &D_80062C18;

        c->field_0 = 1;
        if (neg) {
            c->field_4 = (s16)(v | 0x100);
        } else {
            c->field_4 = v;
        }
        r = v;
        if (r == 0) {
            func_8003B794(0);
        }
        func_8003B994(&D_80062C18);
        return r;
    }
    return -1;
}

void func_80036514(s16 arg0) {
    D_80062C18.field_0 = 0x10;
    D_80062C18.field_10 = arg0;
    func_8003B994(&D_80062C18);
}

void func_80036554(void) { func_8003B794(0); }

void func_80036574(void) { func_8003B794(1); }

s32 func_80036594(a0, a1, a2, src)
s16 a0;
s16 a1;
s16 a2;
Rec62D08 *src;
{
    s16 i;

    if (D_80062D38[a0] == 1) {
        func_800398D4(a0, a1);
        i = a2 + D_80062D18.field_7 * 16;
        D_80062D08[i].field_0 = src->field_0;
        D_80062D08[i].field_1 = src->field_1;
        D_80062D08[i].field_2 = src->field_2;
        D_80062D08[i].field_3 = src->field_3;
        D_80062D08[i].field_4 = src->field_4;
        D_80062D08[i].field_5 = src->field_5;
        D_80062D08[i].field_7 = src->field_7;
        D_80062D08[i].field_6 = src->field_6;
        D_80062D08[i].field_8 = src->field_8;
        D_80062D08[i].field_9 = src->field_9;
        D_80062D08[i].field_A = src->field_A;
        D_80062D08[i].field_B = src->field_B;
        D_80062D08[i].field_C = src->field_C;
        D_80062D08[i].field_D = src->field_D;
        D_80062D08[i].field_10 = src->field_10;
        D_80062D08[i].field_12 = src->field_12;
        D_80062D08[i].field_14 = src->field_14;
        D_80062D08[i].field_16 = src->field_16;
        return 0;
    }
    return -1;
}

extern u16 D_80062CB0;
void func_80036764(void) {
    D_80062CB0 = 0;
}

void func_80036774(void) {
    D_80062CB0 = 2;
}

void func_80036784(void) {
    VAttr36C54 attr;
    s32 i;
    s32 m;
    s32 x;
    s32 *masks;
    s32 *q;
    u8 *fl;
    Rec62A48 *r;
    s32 two;
    s32 k;
    Stride16 *p0, *p1, *p2, *p3, *p4, *p5;

    D_80062BCC = (D_80062BCC + 1) & 0xF;
    D_80062BD0[D_80062BCC] = 0;
    masks = D_80062BD0;
    for (i = 0; i < D_80062D0C; i++) {
        func_8003D104(i, (u16 *)&D_800624E8[i].field_6);
        if (D_800624E8[i].field_6 == 0) {
            masks[D_80062BCC] |= 1 << i;
        }
    }
    if (*(s8 *)&D_80062D48 == 0) {
        m = -1;
        q = D_80062BD0;
        for (i = 0; i < 15; i++) {
            m &= q[i];
        }
        for (i = 0; i < D_80062D0C; i++) {
            s32 bit;
            two = 2;
            bit = 1 << i;
            if (m & bit) {
                if (D_800624E8[i].field_1D == two) {
                    s16 lo;
                    u8 hi;
                    if (i < 16) {
                        hi = 0;
                        lo = bit;
                    } else {
                        lo = 0;
                        hi = 1 << (i - 16);
                    }
                    func_8003B3F4(0, (hi << 16) | lo);
                }
                D_800624E8[i].field_1D = 0;
            }
        }
    }
    D_800624D8 &= ~D_80062C10;
    D_800624DA &= ~D_80062C12;
    for (i = 0; i < 24; i++) {
        if (D_800624E8[i].field_1E != 0) {
            D_80062BC8(i);
        }
        if (D_800624E8[i].field_2A != 0) {
            D_80062A40(i);
        }
    }
    i = 0;
    fl = D_80062A28;
    r = (Rec62A48 *)D_80062A48;
    p5 = (Stride16 *)&r->field_A;
    p4 = (Stride16 *)&r->field_8;
    p3 = (Stride16 *)&r->field_6;
    p2 = (Stride16 *)&r->field_4;
    p1 = (Stride16 *)&r->field_2;
    p0 = (Stride16 *)&r->field_0;
    for (; i < 24; i++) {
        attr.mask = 0;
        attr.voice = 1 << i;
        if (*fl & 1) {
            attr.mask = 3;
            attr.vol_l = p0->v;
            attr.vol_r = p1->v;
        }
        if (*fl & 4) {
            attr.mask |= 0x10;
            attr.pitch = p2->v;
        }
        if (*fl & 8) {
            attr.mask |= 0x80;
            attr.addr = p3->v << 3;
        }
        if (*fl & 0x10) {
            attr.mask |= 0x60000;
            attr.adsr1 = p4->v;
            attr.adsr2 = p5->v;
        }
        if (attr.mask != 0) {
            func_8003C904(&attr);
        }
        *fl = 0;
        fl++;
        p5++;
        p4++;
        p3++;
        p2++;
        p1++;
        p0++;
    }
    func_8003C554(0, ((D_80062C12 & 0xFF) << 16) | D_80062C10);
    func_8003C554(1, ((D_800624DA & 0xFF) << 16) | D_800624D8);
    k = 0xFFFFFF >> (24 - D_80062D0C);
    x = ((D_800624DE << 16) | D_800624DC) & k;
    func_8003C344(8, x | (((s32 (*)(void))func_8003C374)() & ~k));
    x = ((D_800624E2 << 16) | D_800624E0) & k;
    func_8003B3F4(8, x | (((s32 (*)(void))func_8003B6E4)() & ~k));
    D_80062C10 = 0;
    D_80062C12 = 0;
    D_800624D8 = 0;
    D_800624DA = 0;
    D_800624E0 = 0;
    D_800624E2 = 0;
}


void func_80036C54(s32 arg) {
    VAttr36C54 attr;
    s32 n;
    u16 i;
    u16 *p;

    func_8003C8C4(0);
    D_80062CB0 = 0;
    func_8003AD44(0x20, &D_80062DE0);
    p = D_80062A48;
    for (i = 0; i < 0xC0; i++) {
        p[i] = 0;
    }
    for (i = 0; i < 0x18; i++) {
        D_80062A28[i] = 0;
    }
    D_80062D90 = 0;
    for (i = 0; i < 0x10; i++) {
        D_80062D38[i] = 0;
    }
    n = (s8)arg;
    if ((u32)n >= 0x18) {
        D_80062D0C = 0x18;
    } else {
        D_80062D0C = n;
    }
    attr.mask = 0x60093;
    attr.pitch = 0x1000;
    attr.addr = 0x1000;
    attr.adsr1 = 0x80FF;
    attr.vol_l = 0;
    attr.vol_r = 0;
    attr.adsr2 = 0x4000;
    for (i = 0; i < D_80062D0C; i++) {
        D_800624E8[i].field_2 = 0x18;
        D_800624E8[i].field_0 = 0xFF;
        D_800624E8[i].field_1D = 0;
        D_800624E8[i].field_4 = 0;
        D_800624E8[i].field_6 = 0;
        D_800624E8[i].field_10 = -1;
        D_800624E8[i].field_12 = 0;
        D_800624E8[i].field_14 = 0;
        D_800624E8[i].field_16 = 0xFF;
        D_800624E8[i].field_8 = 0;
        D_800624E8[i].field_C = 0;
        D_800624E8[i].field_A = 0x40;
        D_800624E8[i].field_36 = 0;
        D_800624E8[i].field_1E = 0;
        D_800624E8[i].field_20 = 0;
        D_800624E8[i].field_22 = 0;
        D_800624E8[i].field_24 = 0;
        D_800624E8[i].field_2A = 0;
        D_800624E8[i].field_2C = 0;
        D_800624E8[i].field_2E = 0;
        D_800624E8[i].field_30 = 0;
        D_800624E8[i].field_32 = 0;
        D_800624E8[i].field_26 = 0;
        attr.voice = 1 << i;
        func_8003C904(&attr);
        D_80062D30 = i;
        func_80038314(1);
    }
    D_80062C18.field_0 = 0;
    D_80062C18.field_8 = 0x3FFF;
    D_80062C18.field_A = 0x3FFF;
    D_80062C18.field_4 = 0;
    D_800624D8 = 0;
    D_800624DA = 0;
    D_80062C10 = 0;
    D_800624DC = 0;
    D_800624DE = 0;
    D_800624E0 = 0;
    D_800624E2 = 0;
    D_80062D48 = 0;
    D_80062CF8 = 0;
    D_80062D10 = 0;
    D_80062CFA = 0x80;
    func_80036784();
}


s32 func_80036FA4(s16 a0, s16 a1, s16 a2, u16 a3, u16 arg4, u16 arg5) {
    s32 a4 = arg4;
    s32 a5 = arg5;
    u8 val[128];
    u8 idx[128];
    Elm354F4 *e;
    s32 ret;
    u8 n;
    u8 i;
    u16 k;

    ret = 0;
    e = &D_80061C50[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    if (func_800398D4(a1, a2) != 0) {
        return -1;
    }
    D_80062D18.field_14 = a0;
    D_80062D18.field_2 = a3;
    D_80062D18.field_3 = 0;
    if (a0 == 0x21) {
        D_80062D18.field_4 = a4;
    } else {
        D_80062D18.field_4 = a4 * *(e->field_17 + e->field_60) / 127;
    }
    D_80062D18.field_5 = a5;
    D_80062D18.field_A = D_80062CFC[a2].field_1;
    D_80062D18.field_B = D_80062CFC[a2].field_4;
    D_80062D18.field_0 = D_80062CFC[a2].field_0;
    if (D_80062D18.field_7 >= ((Snd62D04 *)D_80062D04)->field_12) {
        return -1;
    }
    if (a4 == 0) {
        ret = func_800374C0(a0, a1, a2, a3);
    } else {
        n = func_80039264(idx, val);
        for (i = 0; i < n; i++) {
            D_80062D18.field_16 = val[i];
            k = (s8)idx[i] + D_80062D18.field_7 * 16;
            D_80062D18.field_C = idx[i];
            D_80062D18.field_F = D_80062D08[k].field_0;
            D_80062D18.field_D = D_80062D08[k].field_2;
            D_80062D18.field_E = D_80062D08[k].field_3;
            D_80062D18.field_10 = D_80062D08[k].field_4;
            D_80062D18.field_11 = D_80062D08[k].field_5;
            D_80062D18.field_12 = D_80062D08[k].field_1;
            D_80062D18.field_18 = func_80037744(0);
            if (D_80062D18.field_18 < D_80062D0C) {
                D_800624E8[D_80062D18.field_18].field_1D = 1;
                D_800624E8[D_80062D18.field_18].field_2 = 0;
                D_800624E8[D_80062D18.field_18].field_10 = a0;
                D_800624E8[D_80062D18.field_18].field_18 = D_80062D18.field_1;
                D_800624E8[D_80062D18.field_18].field_12 = D_80062D18.field_7;
                D_800624E8[D_80062D18.field_18].field_14 = a2;
                if (a0 != 0x21) {
                    D_800624E8[D_80062D18.field_18].field_8 = a4;
                    D_800624E8[D_80062D18.field_18].field_C = e->field_17;
                }
                D_800624E8[D_80062D18.field_18].field_A = a5;
                D_800624E8[D_80062D18.field_18].field_36 = D_80062D18.field_4;
                D_800624E8[D_80062D18.field_18].field_16 = (s8)D_80062D18.field_C;
                D_800624E8[D_80062D18.field_18].field_E = a3;
                D_800624E8[D_80062D18.field_18].field_1A = (s8)D_80062D18.field_F;
                D_800624E8[D_80062D18.field_18].field_0 = D_80062D18.field_16;
                func_800379B4();
                if (D_80062D18.field_16 == 0xFF) {
                    func_80037D64(D_80062D18.field_18);
                } else {
                    func_800383D4(n, func_80037B84());
                }
                ret |= 1 << D_80062D30;
            } else {
                ret = -1;
            }
        }
    }
    return ret;
}


s32 func_800374C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 bit;
    s32 k;
    u8 i;
    s32 n = 0;

    i = 0;
    if (i < D_80062D0C) {
        bit = 1;
        k = a3 & 0xFFFF;
        do {
            s32 m = bit << i;

            if (!(D_8004FC18 & m) && D_800624E8[i].field_E == k && D_800624E8[i].field_14 == (s16)a2 && D_800624E8[i].field_10 == (s16)a0 && D_800624E8[i].field_18 == (s16)a1) {
                if (D_800624E8[i].field_0 == 0xFF) {
                    func_800382D4(i);
                } else {
                    D_80062D30 = i;
                    func_80038314(0);
                }
                n++;
            }
            i++;
        } while (i < D_80062D0C);
    }
    return n;
}

void func_80037620(s32 a0, s32 a1, s32 a2, s32 a3, u16 p4, u16 p5) {
    u16 a;
    u16 b;

    if (p4 == p5) {
        b = 0x40;
        a = p4;
    } else if (p5 < p4) {
        b = (p5 << 6) / p4;
        a = p4;
    } else {
        a = p5;
        b = 0x7F - (p4 << 6) / p5;
    }
    func_80036FA4(0x21, (s16)a0, (s16)a1, (u16)a2, a, b);
}


void func_8003770C(s16 arg0, s16 arg1, u16 arg2) { func_800374C0(0x21, arg0, arg1, arg2); }

u8 func_80037744(s32 arg0) {
    u8 res = 99;
    u16 best_ee = 0xFFFF;
    u8 count = 0;
    s32 best_ea = 0;
    u8 cand = 99;
    u8 i = 0;
    u16 prio = D_80062D27;
    s32 bit;
    s32 mask;
    s32 n;

    if (i < D_80062D0C) {
        bit = 1;
        mask = D_8004FC18;
        for (; i < D_80062D0C; i++) {
            s32 m = bit << i;

            if (!(mask & m)) {
                if (D_800624E8[i].field_1D == 0 && D_800624E8[i].field_6 == 0) {
                    res = i;
                    break;
                }
                if (D_800624E8[i].field_1A < prio) {
                    prio = D_800624E8[i].field_1A;
                    cand = i;
                    best_ee = D_800624E8[i].field_6;
                    best_ea = D_800624E8[i].field_2;
                    count = 1;
                } else if (D_800624E8[i].field_1A == prio) {
                    count++;
                    if (D_800624E8[i].field_6 < best_ee) {
                        best_ea = D_800624E8[i].field_2;
                        best_ee = D_800624E8[i].field_6;
                        cand = i;
                    } else if (D_800624E8[i].field_6 == best_ee) {
                        s32 t = D_800624E8[i].field_2;

                        if (best_ea < (s16)D_800624E8[i].field_2) {
                            best_ea = t;
                            cand = i;
                        }
                    }
                }
            }
        }
    }
    if (res == 99) {
        res = cand;
        if (count == 0) {
            res = D_80062D0C;
        }
    }
    if (res < D_80062D0C) {
        for (i = 0; i < D_80062D0C; i++) {
            s32 m = 1 << i;

            if (!(D_8004FC18 & m)) {
                D_800624E8[i].field_2++;
            }
        }
        D_800624E8[res].field_2 = 0;
        D_800624E8[res].field_1A = D_80062D27;
        D_800624E8[res].field_2A = 0;
        D_800624E8[res].field_1E = 0;
    }
    return res;
}

void func_800379B4(void) {
    s32 i;
    s16 vi;
    s16 v;
    u16 w;
    u16 x;
    u16 m;
    u16 *d;
    Rec62D08 *r;
    s32 *p;
    s16 *q;

    i = 0;
    x = D_80062D18.field_18;
    vi = x * 8;
    D_800624E8[(s16)x].field_6 = 0x7FFF;
    for (; i < 16; i++) {
        D_80062BD0[i] &= ~(1 << D_80062D18.field_18);
    }
    q = &D_80062D18.field_16;
    x = *q;
    if (((s16)x & 1) > 0) {
        D_80062A4E[vi] = D_80062CFC[((s16)x - 1) / 2].field_C;
        D_80062A28[q[1]] |= 8;
    } else {
        D_80062A4E[vi] = D_80062CFC[((s16)x - 1) / 2].field_E;
        D_80062A28[q[1]] |= 8;
    }
    d = D_80062A50;
    D_80062A50[vi] = (r = &D_80062D08[D_80062D18.field_7 * 16 + (s8)D_80062D18.field_C])->field_10;
    w = r->field_12;
    v = D_80062CB0 + (w & 0x1F);
    m = w & 0xFFE0;
    if (v >= 0x20) {
        v = 0x1F;
    }
    d += vi;
    d[1] = v | m;
    D_80062A28[D_80062D18.field_18] |= 0x30;
}


u16 func_80037B84(void) {
    u32 v = D_80062D18.field_11;

    if (v >= 0x80) {
        v = 0x7F;
    }
    return func_80037C38(D_80062D18.field_2, 0, D_80062D18.field_10, v);
}

u16 func_80037BD0(s16 a0, s16 a1) {
    s16 i = D_80062D18.field_7 * 16 + (s8)D_80062D18.field_C;
    return func_80037C38(a0, a1, D_80062D08[i].field_4, D_80062D08[i].field_5);
}

s32 func_80037C38(s32 note, s32 fine, s32 center, s32 shift) {
    s16 f = (u8)shift + fine;
    s16 n;
    s16 fr;
    s16 oct;
    s16 idx;
    u32 p;

    n = note + f / 128 - (u8)center;
    fr = f % 128;
    if (fr < 0) {
        fr += 128;
        n--;
        n += fr / 128;
    }
    oct = n / 12 - 2;
    idx = n % 12;
    if (idx < 0) {
        idx += 12;
        oct = n / 12 - 3;
    }
    p = (D_8004FC88[idx] * D_8004FCA0[fr]) >> 16;
    if (oct >= 0) {
        p = 0x3FFF;
    } else {
        p += 1 << (-oct - 1);
        p >>= -oct;
    }
    return (u16)p;
}


void func_80037D64(u8 a0) {
    u32 vol;
    u32 l;
    u32 r;
    Elm354F4 *e;
    u32 pan;
    u32 l2;
    u32 r2;
    s32 lo;
    s32 hi;
    s16 i;
    s32 m;
    u32 v;

    e = &D_80061C50[D_80062D18.field_14 & 0xFF][(D_80062D18.field_14 & 0xFF00) >> 8];
    vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
    vol = D_80062D18.field_4 * (s32)vol / 0x3F01;
    vol = vol * D_80062D18.field_A * D_80062D18.field_D / 0x3F01;
    l = r = vol;
    if (D_80062D18.field_14 != 0x21) {
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
    }
    pan = (s8)D_80062D18.field_E;
    if (pan < 0x40) {
        r2 = r * pan / 63;
        l2 = l;
    } else {
        l2 = l * (0x7F - pan) / 63;
        r2 = r;
    }
    pan = (s8)D_80062D18.field_B;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    pan = (s8)D_80062D18.field_5;
    if (pan < 0x40) {
        r2 = pan * r2 / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    if (D_80062CF8 == 1) {
        if (l2 < r2) {
            l2 = r2;
        } else {
            r2 = l2;
        }
    }
    if (D_80062D18.field_14 != 0x21) {
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
    }
    v = a0;
    func_8003B744((D_80062D18.field_2 - (s8)D_80062D18.field_10) & 0x3F);
    ((Snd62A28 *)D_80062A28)->regs[v].vol_r = r2;
    D_80062A48[v * 8] = l2;
    D_80062A28[v] |= 3;
    if (v < 16) {
        lo = 1 << v;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (v - 16);
    }
    D_800624E8[a0].field_4 = 10;
    for (i = 0; i < D_80062D0C; i++) {
        m = 1 << i;
        if (!(D_8004FC18 & m)) {
            D_800624E8[i].field_1D &= 1;
        }
    }
    D_800624E8[a0].field_1D = 2;
    D_800624D8 |= lo;
    D_800624DA |= hi;
    D_80062C10 &= ~D_800624D8;
    D_80062C12 &= ~D_800624DA;
    if (D_80062D18.field_12 & 4) {
        D_800624DC |= lo;
        D_800624DE |= hi;
    } else {
        D_800624DC &= ~lo;
        D_800624DE &= ~hi;
    }
    D_800624E0 = lo;
    D_800624E2 = hi;
}


void func_800382D4(u8 arg0) {
    D_800624E8[arg0].field_1D = 0;
    D_800624E8[arg0].field_0 = 0;
    D_800624E8[arg0].field_4 = 0;
}

void func_80038314(s32 a0) {
    u16 ch = D_80062D30;
    u32 v = ch & 0xFFFF;
    s32 hi;
    s32 lo;
    s32 c10;
    s32 c12;

    if (v < 16) {
        lo = 1 << v;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (v - 16);
    }
    D_800624E8[ch].field_1D = 0;
    c10 = D_80062C10;
    c12 = D_80062C12;
    D_800624E8[ch].field_4 = 0;
    D_800624E8[ch].field_0 = 0;
    c10 |= lo;
    D_80062C10 = c10;
    D_800624D8 &= ~c10;
    c12 |= hi;
    D_80062C12 = c12;
    D_800624DA &= ~c12;
}

void func_800383D4(u8 a0, u16 a1) {
    u32 vol;
    u32 l;
    u32 r;
    u16 k;
    s32 lo;
    s32 hi;
    Elm354F4 *e;
    u8 pan;
    u32 l2;
    u32 r2;

    k = D_80062D18.field_18 * 8;
    vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
    vol = D_80062D18.field_4 * (s32)vol / 0x3F01;
    vol = vol * D_80062D18.field_A * D_80062D18.field_D / 0x3F01;
    e = &D_80061C50[D_80062D18.field_14 & 0xFF][(D_80062D18.field_14 & 0xFF00) >> 8];
    l = r = vol;
    if (D_80062D18.field_14 != 0x21) {
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
    }
    pan = D_80062D18.field_E;
    if (pan < 0x40) {
        r2 = r * pan / 63;
        l2 = l;
    } else {
        l2 = l * (0x7F - pan) / 63;
        r2 = r;
    }
    pan = D_80062D18.field_B;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    pan = D_80062D18.field_5;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    if (D_80062CF8 == 1) {
        if (l2 < r2) {
            l2 = r2;
        } else {
            r2 = l2;
        }
    }
    if (D_80062D18.field_14 != 0x21) {
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
    }
    D_80062A4C[k] = a1;
    D_80062A48[k] = l2;
    D_80062A4A[k] = r2;
    D_80062A28[D_80062D18.field_18] |= 7;
    D_800624E8[D_80062D18.field_18].field_4 = a1;
    if (D_80062D18.field_18 < 16) {
        lo = 1 << D_80062D18.field_18;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (D_80062D18.field_18 - 16);
    }
    if (D_80062D18.field_12 & 4) {
        D_800624DC |= lo;
        D_800624DE |= hi;
    } else {
        D_800624DC &= ~lo;
        D_800624DE &= ~hi;
    }
    D_800624E0 &= ~lo;
    D_800624E2 &= ~hi;
    D_800624D8 |= lo;
    D_800624DA |= hi;
    D_80062C10 &= ~D_800624D8;
    D_80062C12 &= ~D_800624DA;
}


s16 func_800388A4(s16 id, s16 a1, s16 a2, s16 a3, u16 a4) {
    u16 idx;
    u16 base;
    u16 frac;
    s16 d;
    s32 t;
    s32 q;
    s32 ret;

    d = a4 - 0x40;
    if (D_800624E8[id].field_10 == a1 && D_800624E8[id].field_18 == a2 && D_800624E8[id].field_14 == a3) {
    base = D_800624E8[id].field_E;
    idx = D_800624E8[id].field_16 + D_80062D1F * 16;
    if (d > 0) {
        t = d * D_80062D08[idx].field_D;
        q = t / 63;
        base += q;
        frac = (t - q * 63) * 2;
    } else if (d < 0) {
        t = d * D_80062D08[idx].field_C;
        q = t / 64;
        base = base + q - 1;
        frac = (t - q * 64) * 2 + 0x7F;
    } else {
        frac = 0;
    }
    D_80062D18.field_C = D_800624E8[id].field_16;
    D_80062D18.field_18 = id;
    ((Snd62A28 *)D_80062A28)->regs[id].pitch = ((u16 (*)())func_80037BD0)(base, frac);
    D_80062A28[id] |= 4;
    return 1;
    }
    return 0;
}

s32 func_80038A90(s16 a0, s16 a1, s16 a2, s32 a3) {
    s16 i;
    s32 sum;

    func_800398D4(a1, a2);
    i = 0;
    D_80062D2C[0] = a0;
    sum = 0;
    for (; i < D_80062D0C; i++) {
        sum += func_800388A4(i, a0, a1, a2, a3);
    }
    return sum;
}


s32 func_80038B74(s16 a0, s16 a1, s32 a2) {
    if (func_800398D4(a0, a1) != 0) {
        return -1;
    }
    D_80062CFC[a1].field_1 = a2;
    return D_80062CFC[a1].field_1;
}

s16 func_80038BE4(s32 a0, s32 a1, s32 a2, s32 a3) {
    Elm354F4 *e;
    s16 i;
    s32 t;
    u32 vol;
    u32 l;
    u32 r;
    s32 l2;
    u16 r2;
    u8 pan;
    u16 *pl;
    s32 id;
    u16 *pr;
    u16 x;

    e = &D_80061C50[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    e->field_58 = a1;
    e->field_5A = a2;
    id = a0;
    if (((volatile Elm354F4 *)e)->field_58 >= 0x7F) {
        e->field_58 = 0x7F;
    }
    if (e->field_5A >= 0x7F) {
        e->field_5A = 0x7F;
    }
    for (i = 0; i < D_80062D0C; i++) {
        s32 m;

        pr = D_80062A4A;
        pl = D_80062A48;
        m = 1 << i;

        if (!(D_8004FC18 & m) && D_800624E8[i].field_10 == (s16)id && D_800624E8[i].field_18 == e->field_26) {
            func_800398D4(D_800624E8[i].field_18, D_800624E8[i].field_12);
            t = D_800624E8[i].field_8 * *(D_800624E8[i].field_C + e->field_60) / 127 * 0x3FFF;
            vol = ((Snd62D04 *)D_80062D04)->field_18 * t / 0x3F01;
            vol = vol * D_80062CFC[D_800624E8[i].field_14].field_1 * D_80062D08[D_800624E8[i].field_12 * 16 + D_800624E8[i].field_16].field_2 / 0x3F01;
            l = vol * e->field_58 / 127;
            r = vol * e->field_5A / 127;
            pan = D_80062D08[D_800624E8[i].field_12 * 16 + D_800624E8[i].field_16].field_3;
            if (pan < 0x40) {
                r = r * pan / 63;
            } else {
                l = l * (0x7F - pan) / 63;
            }
            pan = D_80062CFC[D_800624E8[i].field_14].field_4;
            if (pan < 0x40) {
                r2 = (u16)r * pan / 63;
            } else {
                r2 = r;
                l = (u16)l * (0x7F - pan) / 63;
            }
            pan = D_800624E8[i].field_A;
            if (pan < 0x40) {
                r2 = r2 * pan / 63;
            } else {
                l = (u16)l * (0x7F - pan) / 63;
            }
            l2 = (u16)l;
            if (D_80062CF8 == 1) {
                if ((u32)l2 < r2) {
                    *(u16 *)&l = r2;
                } else {
                    r2 = l;
                }
                l2 = (u16)l;
            }
            l2 = l2 * l2 / 0x3FFF;
            pl[i * 8] = l2;
            pr[i * 8] = r2 * r2 / 0x3FFF;
            D_80062A28[i] |= 3;
        }
    }
    return id;
}

s16 func_80039150(s32 a0, u16 *a1, u16 *a2) {
    Elm354F4 *base = D_80061C50[a0 & 0xFF];
    Elm354F4 *e;

    D_80062D2C[0] = a0;
    e = &base[(a0 & 0xFF00) >> 8];
    *a1 = e->field_58;
    *a2 = e->field_5A;
    return D_80062D2C[0];
}

void func_800391B4(s32 id) {
    u8 i;

    for (i = 0; i < D_80062D0C; i++) {
        s32 m = 1 << i;

        if (!(D_8004FC18 & m) && D_800624F8[i].field_0 == (s16)id) {
            D_80062D30 = i;
            func_80038314(0);
        }
    }
}

u8 func_80039264(u8 *idx, u8 *val) {
    u8 n = 0;
    s8 i;

    for (i = 0; i < D_80062D18.field_0; i++) {
        Rec62D08 *r = &D_80062D08[D_80062D18.field_7 * 16 + i];

        if (D_80062D18.field_2 >= r->field_6 && D_80062D18.field_2 <= r->field_7) {
            val[n] = r->field_16;
            idx[n++] = i;
        }
    }
    return n;
}

s32 func_80039334(s16 a0, s16 a1, s16 a2, u16 a3, u16 a4) {
    Elm354F4 *e;
    Rec62D08 *rec;
    s16 i;
    s32 n;
    s32 t;
    u32 vol;
    u32 l;
    u32 r;
    u32 l2;
    u32 r2;
    u8 pan;
    s32 v4;
    s32 k;

    n = 0;
    v4 = a4;
    e = &D_80061C50[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    func_800398D4(a1, a2);
    D_80062D2C[0] = a0;
    if (v4 == 0) {
        v4 = 1;
    }
    if (a3 == 0) {
        a3 = 1;
    }
    for (i = 0; i < D_80062D0C; i++) {
        s32 m = 1 << i;
        s32 c1 = a1;

        if (D_8004FC18 & m) {
            continue;
        }
        if (D_800624F8[i].field_0 != a0) {
            continue;
        }
        if (D_800624FC[i].field_0 != a2) {
            continue;
        }
        if (D_80062500[i].field_0 != c1) {
            continue;
        }
        k = e->field_17;
        if ((&e->field_60[k])[0] != a3 && (&e->field_60[k])[0] == 0) {
            (&e->field_60[k])[0] = 1;
        }
        t = D_800624F0[i].field_0 * a3 / 127;
        do {} while (0);
        vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
        vol = (s32)(t * vol) / 0x3F01;
        t = (s32)vol / 127;
        t = t / 0x3F01;
        vol = vol * D_80062CFC[a2].field_1;
        k = D_800624FA[i].field_0 * 16 + D_800624FE[i].field_0;
        vol = vol * D_80062D08[k].field_2 / 0x3F01;
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
        pan = D_80062D08[k].field_3;
        if (pan < 0x40) {
            r2 = r * pan / 63;
            l2 = l;
        } else {
            l2 = l * (0x7F - pan) / 63;
            r2 = r;
        }
        pan = D_80062CFC[D_800624FC[i].field_0].field_4;
        if (pan < 0x40) {
            r2 = r2 * pan / 63;
        } else {
            l2 = l2 * (0x7F - pan) / 63;
        }
        pan = (u8)v4;
        if (pan < 0x40) {
            r2 = r2 * pan / 63;
        } else {
            l2 = l2 * (0x7F - pan) / 63;
        }
        if (D_80062CF8 == 1) {
            if (l2 < r2) {
                l2 = r2;
            } else {
                r2 = l2;
            }
        }
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
        (&D_80062A48[0])[i * 8] = l2;
        (&D_80062A48[1])[i * 8] = r2;
        D_80062A28[i] |= 3;
        n++;
    }
    return n;
}


s32 func_800398D4(s16 a0, s16 a1) {
    if ((u16)a0 >= 16 || D_80062D38[a0] != 1 || a1 >= D_80062CFA) {
        return -1;
    }
    D_80062D04 = D_80062C70[a0];
    D_80062CFC = D_80062C30[a0];
    D_80062D08 = D_80062CB8[a0];
    D_80062D18.field_1 = a0;
    D_80062D18.field_6 = a1;
    D_80062D18.field_7 = D_80062CFC[a1].field_8;
    return 0;
}


void func_80039994(s16 id) {
    s32 st;

    if ((u16)id < 16) {
        st = D_80062D38[id];
        if (st < 3) {
            if (st != 0) {
                func_8003B374(D_80062D98[id]);
                D_80062D38[id] = 0;
                D_80062D90--;
                if (func_8003C8EC() == 1) {
                    func_8003C8C4(0);
                }
            }
        }
    }
}

s16 func_80039A44(s32 arg0, s16 arg1) {
    return func_80039B54(arg0, arg1, func_80039A78, 0);
}

s32 func_80039A78(s32 a0, s32 a1, s32 id) {
    s32 r = func_8003ADA4(a0, a1);

    if (r == -1) {
        D_80062D38[(s16)id] = 0;
        func_8003C8C4(0);
        D_80062D90--;
        return -1;
    }
    return r;
}

s16 func_80039AE4(s32 arg0, s16 arg1, s32 arg2) {
    return func_80039B54(arg0, arg1, func_80039B4C, arg2);
}

s16 func_80039B18(s32 arg0, s16 arg1, s32 arg2) {
    return func_80039B54(arg0, arg1, func_80039B4C, arg2);
}

s32 func_80039B4C(s32 arg0, s32 arg1) {
    return arg1;
}

s32 func_80039B54(u8 *addr, s32 vabid, s32 (*fn)(), s32 mode) {
    s32 vagLens[256];
    s16 id;
    s32 i;
    s32 n;
    u8 vs;
    VabHdr39B54 *vh;
    Prog39B54 *prog;
    u16 *p;
    u8 *q;
    s32 spu;

    id = 16;
    if (func_8003C8EC() == 1) {
        return -1;
    }
    func_8003C8C4(1);
    if ((s16)vabid >= 16) {
        goto fail;
    }
    {
        if ((s16)vabid == -1) {
            for (i = 0; i < 16; i++) {
                if (D_80062D38[i] == 0) {
                    D_80062D38[i] = 1;
                    D_80062D90++;
                    id = i;
                    break;
                }
            }
        } else if (D_80062D38[(s16)vabid] == 0) {
            D_80062D38[(s16)vabid] = 1;
            D_80062D90++;
            id = (s16)vabid;
        }
    }
    if (id >= 16) {
    fail:
        func_8003C8C4(0);
        return -1;
    }
    q = addr;
    D_80062C70[id] = (s32)q;
    q += sizeof(VabHdr39B54);
    vh = (VabHdr39B54 *)addr;
    D_80062D10 = 0;
    if (((u32)vh->form >> 8) != 0x564142) {
        D_80062D38[id] = 0;
        func_8003C8C4(0);
        D_80062D90--;
        return -1;
    }
    if ((vh->form & 0xFF) == 'p' && vh->ver >= 5) {
        D_80062CFA = 0x80;
    } else {
        D_80062CFA = 0x40;
    }
    if (vh->ps > D_80062CFA) {
        D_80062D38[id] = 0;
        func_8003C8C4(0);
        D_80062D90--;
        return -1;
    }
    D_80062C30[id] = (Ent62CFC *)q;
    prog = (Prog39B54 *)q;
    q += D_80062CFA * sizeof(Prog39B54);
    n = 0;
    for (i = 0; i < D_80062CFA; i++) {
        prog[i].reserved1 = n;
        if (prog[i].tones != 0) {
            n++;
        }
    }
    D_80062CB8[id] = (Rec62D08 *)q;
    q += vh->ps * 16 * sizeof(Rec62D08);
    p = (u16 *)q;
    vs = vh->vs;
    n = 0;
    for (i = 0; i < 256; i++) {
        if (i <= vs) {
            s32 x = *p;
            if (vh->ver < 5) {
                vagLens[i] = x << 2;
            } else {
                vagLens[i] = x << 3;
            }
            n += vagLens[i];
        }
        p++;
    }
    n = (n + 0x3F) & ~0x3F;
    spu = fn(n, mode, id);
    if (spu == -1) {
        return -1;
    }
    if ((u32)(spu + n) > 0x80000) {
        D_80062D38[id] = 0;
        func_8003C8C4(0);
        D_80062D90--;
        return -1;
    }
    D_80062D98[id] = spu;
    n = 0;
    for (i = 0; i <= vs; i++) {
        n += vagLens[i];
        if (i % 2 == 0) {
            prog[i / 2].vagLo = (u32)(spu + n) >> 3;
        } else {
            prog[i / 2].vagHi = (u32)(spu + n) >> 3;
        }
    }
    D_80062D50[id] = n;
    D_80062D38[id] = 2;
    return id;
}


s16 func_80039F44(s32 a0, s16 id) {
    s32 addr;

    if ((u16)id < 17) {
        if (D_80062D38[id] == 2) {
            addr = D_80062D98[id];
            func_8003C7D4(0);
            if (func_8003C774(addr) != 0) {
                func_8003C714(a0, D_80062D50[id]);
                D_80062D38[id] = 1;
                return id;
            }
        }
    }
    func_8003C8C4(0);
    return -1;
}

extern s32 func_8003C804();

s16 func_8003A004(s16 a0) {
    do { } while (0);
    return func_8003C804(a0);
}
__asm__(".word 0\n.word 0\n");

extern void func_8003A054(s32);

void func_8003A034(void) { func_8003A054(0); }

void func_8003A054(s32 a0) {
    s32 i;
    u16 *p;

    func_80030CD4();
    func_8003A1D4(a0);
    if (a0 == 0) {
        i = 23;
        p = &D_8004FDE4[23];
        do {
            *p = 0xC000;
            i--;
            p--;
        } while (i >= 0);
    }
    func_8003A13C();
    D_8004FDBC = 0;
    D_8004FDC0 = 0;
    D_8004FDCC.field_0 = 0;
    D_8004FDCC.field_4 = 0;
    D_8004FDCC.field_6 = 0;
    D_8004FDCC.field_8 = 0;
    D_8004FDCC.field_C = 0;
    D_8004FDC4 = D_800503B8[0];
    func_8003AAE0(0xD1, D_800503B8[0], 0);
    D_8004FE88 = 0;
    D_8004FE8C = 0;
    D_8004FE90 = 0;
    D_8004FDB8 = 0;
    D_8004FE44 = 0;
    D_8004FDB4 = 0;
    D_8004FDE0 = 0;
    D_8004FDDC = 0;
    D_8004FE14 = 0;
}

void func_8003A13C(void) {
    if (D_8004FE18 == 0) {
        D_8004FE18 = 1;
        func_80026FC4();
        func_8003AD14((s32)func_8003A614);
        D_8004FDB0 = func_8003A1B4(0xF0000009, 0x20, 0x2000, 0);
        func_8003A1C4(D_8004FDB0);
        func_80026FD4();
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003A1B4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003A1C4);

s32 func_8003A1D4(s32 a0) {
    u32 i;
    s32 j;
    volatile u16 *p;
    volatile u16 *q;

    *D_8004FE38 |= 0xB0000;
    D_8004FE44 = 0;
    D_8004FE48 = 0;
    D_8004FE40 = 0;
    ((volatile u16 *)D_8004FE28)[0xC0] = 0;
    ((volatile u16 *)D_8004FE28)[0xC1] = 0;
    ((volatile u16 *)D_8004FE28)[0xD5] = 0;
    func_8003ACAC();
    ((volatile u16 *)D_8004FE28)[0xC0] = 0;
    ((volatile u16 *)D_8004FE28)[0xC1] = 0;
    i = 0;
    while (((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF) {
        if (++i > 0xF00) {
            func_8002A014(D_80010AA4, D_80010AB4);
            break;
        }
    }
    j = 0;
    p = D_80062EE8;
    D_8004FE4C = 2;
    D_8004FE50 = 3;
    D_8004FE54 = 8;
    D_8004FE58 = 7;
    ((volatile u16 *)D_8004FE28)[0xD6] = 4;
    ((volatile u16 *)D_8004FE28)[0xC2] = 0;
    ((volatile u16 *)D_8004FE28)[0xC3] = 0;
    ((volatile u16 *)D_8004FE28)[0xC6] = 0xFFFF;
    ((volatile u16 *)D_8004FE28)[0xC7] = 0xFFFF;
    ((volatile u16 *)D_8004FE28)[0xCC] = 0;
    ((volatile u16 *)D_8004FE28)[0xCD] = 0;
    do {
        *p++ = 0;
    } while (++j < 10);
    if (a0 == 0) {
        D_8004FE40 = 0x200;
        ((volatile u16 *)D_8004FE28)[0xC8] = 0;
        ((volatile u16 *)D_8004FE28)[0xC9] = 0;
        ((volatile u16 *)D_8004FE28)[0xCA] = 0;
        ((volatile u16 *)D_8004FE28)[0xCB] = 0;
        ((volatile u16 *)D_8004FE28)[0xD8] = 0;
        ((volatile u16 *)D_8004FE28)[0xD9] = 0;
        ((volatile u16 *)D_8004FE28)[0xDA] = 0;
        ((volatile u16 *)D_8004FE28)[0xDB] = 0;
        func_8003A454((s32)D_8004FE68, 0x10);
        q = D_8004FE28;
        for (j = 0; j < 24; j++) {
            q[0] = 0;
            q[1] = 0;
            q[2] = 0x3FFF;
            q[3] = 0x200;
            q[4] = 0;
            q[5] = 0;
            q += 8;
        }
        ((volatile u16 *)D_8004FE28)[0xC4] = 0xFFFF;
        ((volatile u16 *)D_8004FE28)[0xC5] = 0xFF;
        func_8003ACAC();
        func_8003ACAC();
        func_8003ACAC();
        func_8003ACAC();
        ((volatile u16 *)D_8004FE28)[0xC6] = 0xFFFF;
        ((volatile u16 *)D_8004FE28)[0xC7] = 0xFF;
        func_8003ACAC();
        func_8003ACAC();
        func_8003ACAC();
        func_8003ACAC();
    }
    D_8004FE5C = 1;
    ((volatile u16 *)D_8004FE28)[0xD5] = 0xC000;
    D_8004FE60 = 0;
    D_8004FE64 = 0;
    return 0;
}


void func_8003A454(u16 *addr, u32 size) {
    u16 status;
    s32 wsize;
    s32 i;
    u32 count;

    ((volatile u16 *)D_8004FE28)[0xD3] = D_8004FE40;
    status = ((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF;
    func_8003ACAC();
    while (size != 0) {
        wsize = 0x40;
        if (size <= 0x40) {
            wsize = size;
        }
        for (i = 0; i < wsize; i += 2) {
            ((volatile u16 *)D_8004FE28)[0xD4] = *addr++;
        }
        ((volatile u16 *)D_8004FE28)[0xD5] = (((volatile u16 *)D_8004FE28)[0xD5] & ~0x30) | 0x10;
        func_8003ACAC();
        count = 0;
        while (((volatile u16 *)D_8004FE28)[0xD7] & 0x400) {
            if (++count > 0xF00) {
                func_8002A014(D_80010AA4, D_80010AC4);
                break;
            }
        }
        func_8003ACAC();
        func_8003ACAC();
        size -= wsize;
    }
    ((volatile u16 *)D_8004FE28)[0xD5] &= ~0x30;
    count = 0;
    while ((((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF) != status) {
        if (++count > 0xF00) {
            func_8002A014(D_80010AA4, D_80010AD8);
            break;
        }
    }
}

void func_8003A614(void) {
    volatile u16 *r;
    u32 i;

    if (D_8004FE78 == 0) {
        func_8003ACAC();
    }
    r = D_8004FE28;
    r[0xD5] &= 0xFFCF;
    i = 0;
    while (r[0xD5] & 0x30) {
        if (++i > 0xF00) {
            break;
        }
    }
    if (D_8004FE60 != 0) {
        D_8004FE60();
    } else {
        func_8002DD54(0xF0000009, 0x20);
    }
}

void func_8003A6D0(s32 addr, u16 spuAddr, s32 blocks) {
    D_8004FE28[0xD3] = spuAddr;
    func_8003ACAC();
    D_8004FE28[0xD5] |= 0x30;
    blocks <<= 16;
    func_8003ACAC();
    func_8003AC84();
    *D_8004FE2C = addr;
    *D_8004FE30 = blocks | 0x10;
    D_8004FE78 = 1;
    *D_8004FE34 = 0x1000200;
}


s32 func_8003A778(s32 mode, ...) {
    u32 *ap;
    u32 t;
    u16 m;
    u32 i;
    s32 c;

    ap = (u32 *)(&mode + 1);
    switch (mode) {
    case 2:
        t = *ap;
        D_8004FE40 = t >> D_8004FE50;
        ((volatile u16 *)D_8004FE28)[0xD3] = t >> D_8004FE50;
        break;
    case 1:
        D_8004FE78 = 0;
        i = 0;
        while (((volatile u16 *)D_8004FE28)[0xD3] != *(u16 *)&D_8004FE40) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        ((volatile u16 *)D_8004FE28)[0xD5] = (((volatile u16 *)D_8004FE28)[0xD5] & ~0x30) | 0x20;
        break;
    case 0:
        D_8004FE78 = 1;
        i = 0;
        while (((volatile u16 *)D_8004FE28)[0xD3] != *(u16 *)&D_8004FE40) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        ((volatile u16 *)D_8004FE28)[0xD5] |= 0x30;
        break;
    case 3:
        m = 0x20;
        if (D_8004FE78 == 1) {
            m = 0x30;
        }
        i = 0;
        while ((((volatile u16 *)D_8004FE28)[0xD5] & 0x30) != m) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        if (D_8004FE78 == 1) {
            func_8003AC84();
        } else {
            func_8003AC5C();
        }
        ap++;
        c = 0x1000201;
        D_8004FE7C = ap[-1];
        t = *ap;
        D_8004FE80 = t / 64 + (t % 64 != 0);
        *(volatile s32 *)D_8004FE2C = D_8004FE7C;
        *(volatile s32 *)D_8004FE30 = (D_8004FE80 << 16) | 0x10;
        if (D_8004FE78 == 1) {
            c = 0x1000200;
        }
        *(volatile s32 *)D_8004FE34 = c;
        break;
    }
    return 0;
}

s32 func_8003A9F8(s32 a0, u32 a1) {
    if (D_8004FE44 == 0) {
        func_8003A778(2, D_8004FE40 << D_8004FE50);
        func_8003A778(1);
        func_8003A778(3, a0, a1);
    } else {
        func_8003A454(a0, a1);
    }
    return a1;
}

s32 func_8003AA7C(s32 a0, s32 a1) {
    func_8003A778(2, D_8004FE40 << D_8004FE50);
    func_8003A778(0);
    func_8003A778(3, a0, a1);
    return a1;
}

void func_8003AAE0(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
        D_8004FE28[arg0] = arg1;
    } else {
        D_8004FE28[arg0] = arg1 >> D_8004FE50;
    }
}

u32 func_8003AB24(s32 idx, u32 a1) {
    u32 v;
    u32 d;
    u16 r;

    if (D_8004FE4C != 0) {
        d = D_8004FE54;
        if (a1 % d) {
            a1 += d;
            a1 &= ~D_8004FE58;
        }
    }
    v = a1 >> D_8004FE50;
    r = v;
    switch (idx) {
    case -1:
        return r;
    case -2:
        return a1;
    default:
        D_8004FE28[idx] = v;
        return a1;
    }
}


s32 func_8003ABC8(s32 a0, s32 a1) {
    u16 x = D_8004FE28[a0];
    if (a1 == -1) return x;
    return x << D_8004FE50;
}

void func_8003AC04(s32 a0) {
    *D_8004FE38 &= 0xFFF8FFFF;
    if (a0 != 0) {
        *D_8004FE38 |= 0x30000;
    } else {
        *D_8004FE38 |= 0x50000;
    }
}

extern u32 *D_8004FE3C;
void func_8003AC5C(void) {
    *D_8004FE3C = (*D_8004FE3C & 0xF0FFFFFF) | 0x20000000;
}

void func_8003AC84(void) {
    *D_8004FE3C = (*D_8004FE3C & 0xF0FFFFFF) | 0x22000000;
}

void func_8003ACAC(void) {
    volatile s32 i;
    volatile s32 x;

    x = 13;
    for (i = 0; i < 60; i++) {
        x *= 13;
    }
}

void func_8003AD14(s32 arg0) { func_80030D34(4, arg0); }

s32 func_8003AD44(s32 n, Hdr3AD44 *h) {
    if (n > 0) {
        h->field_0 = 0x40001010;
        D_8004FE90 = h;
        D_8004FE8C = 0;
        D_8004FE88 = n;
        h->field_4 = (0x10000 << D_8004FE50) - 0x1010;
        return n;
    }
    return 0;
}

s32 func_8003ADA4(s32 size) {
    s32 i = 0;
    s32 found = -1;
    s32 rev;
    s32 n;
    s32 esz;
    Hdr3AD44 *e;
    u32 ta;
    s32 tb;

    if (D_8004FDC0 == 0) {
        rev = 0;
    } else {
        rev = (0x10000 - D_8004FDC4) << D_8004FE50;
    }
    if (size & ~D_8004FE58) {
        size += D_8004FE58;
    }
    size >>= D_8004FE50;
    size <<= D_8004FE50;

    if (D_8004FE90->field_0 & 0x40000000) {
        found = 0;
    } else {
        func_8003B074();
        for (; i < D_8004FE88; i++) {
            if ((D_8004FE90[i].field_0 & 0x40000000) ||
                ((D_8004FE90[i].field_0 & 0x80000000) && (u32)D_8004FE90[i].field_4 >= (u32)size)) {
                found = i;
                break;
            }
        }
    }
    if (found == -1) {
        return -1;
    }
    e = &D_8004FE90[found];
    if (e->field_0 & 0x40000000) {
        if (found >= D_8004FE88) {
            return -1;
        }
        if ((u32)(e->field_4 - rev) < (u32)size) {
            return -1;
        }
        n = found + 1;
        D_8004FE90[n].field_0 = ((*(volatile u32 *)&e->field_0 & 0x0FFFFFFF) + size) | 0x40000000;
        D_8004FE90[n].field_4 = e->field_4 - size;
        D_8004FE8C = n;
        e->field_4 = size;
        e->field_0 &= 0x0FFFFFFF;
        func_8003B074();
        return D_8004FE90[found].field_0;
    }
    esz = e->field_4;
    if ((u32)size < (u32)esz) {
        n = D_8004FE8C;
        if (n < D_8004FE88) {
            ta = D_8004FE90[n].field_0;
            tb = D_8004FE90[n].field_4;
            D_8004FE90[n].field_0 = (e->field_0 + size) | 0x80000000;
            D_8004FE90[n].field_4 = esz - size;
            D_8004FE8C = n + 1;
            D_8004FE90[n + 1].field_0 = ta;
            D_8004FE90[n + 1].field_4 = tb;
        }
    }
    D_8004FE90[found].field_4 = size;
    D_8004FE90[found].field_0 &= 0x0FFFFFFF;
    func_8003B074();
    return D_8004FE90[found].field_0;
}


void func_8003B074(void) {
    Hdr3AD44 *e;
    Hdr3AD44 *o;
    s32 i;
    s32 j;
    u32 t;
    s32 v;
    s32 n;
    Hdr3AD44 *tab;
    Hdr3AD44 *p;

    i = 0;
    if (D_8004FE8C >= 0) {
        n = D_8004FE8C;
        tab = D_8004FE90;
        do {
            if (tab[i].field_0 & 0x80000000) {
                j = i + 1;
                p = &tab[j];
            scan:
                if ((p++)->field_0 == 0x2FFFFFFF) {
                    j++;
                    goto scan;
                }
                if ((tab[j].field_0 & 0x80000000)
                    && (tab[j].field_0 & 0x0FFFFFFF) == (tab[i].field_0 & 0x0FFFFFFF) + tab[i].field_4) {
                    tab[j].field_0 = 0x2FFFFFFF;
                    tab[i].field_4 += tab[j].field_4;
                    continue;
                }
            }
            i++;
        } while (i <= n);
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (D_8004FE90[i].field_4 == 0) {
            D_8004FE90[i].field_0 = 0x2FFFFFFF;
        }
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (D_8004FE90[i].field_0 & 0x40000000) {
            break;
        }
        for (j = i + 1; j <= D_8004FE8C; j++) {
            if (D_8004FE90[j].field_0 & 0x40000000) {
                break;
            }
            if ((D_8004FE90[j].field_0 & 0x0FFFFFFF) < (D_8004FE90[i].field_0 & 0x0FFFFFFF)) {
                t = D_8004FE90[i].field_0;
                D_8004FE90[i].field_0 = D_8004FE90[j].field_0;
                v = D_8004FE90[i].field_4;
                D_8004FE90[i].field_4 = D_8004FE90[j].field_4;
                D_8004FE90[j].field_0 = t;
                D_8004FE90[j].field_4 = v;
            }
        }
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (D_8004FE90[i].field_0 & 0x40000000) {
            break;
        }
        if (D_8004FE90[i].field_0 == 0x2FFFFFFF) {
            D_8004FE90[i].field_0 = D_8004FE90[D_8004FE8C].field_0;
            D_8004FE90[i].field_4 = D_8004FE90[D_8004FE8C].field_4;
            D_8004FE8C = i;
            break;
        }
    }
    for (i = D_8004FE8C - 1; i >= 0; i--) {
        e = &D_8004FE90[i];
        if (!(e->field_0 & 0x80000000)) {
            break;
        }
        e->field_0 = (e->field_0 & 0x0FFFFFFF) | 0x40000000;
        e->field_4 += D_8004FE90[D_8004FE8C].field_4;
        D_8004FE8C = i;
    }
}


void func_8003B374(s32 id) {
    s32 i;
    u32 w;

    for (i = 0; i < D_8004FE88; i++) {
        w = D_8004FE90[i].field_0;
        if (w & 0x40000000) {
            break;
        }
        if (w == id) {
            D_8004FE90[i].field_0 = id | 0x80000000;
            break;
        }
    }
    func_8003B074();
}

void func_8003B3F4(s32 arg0, s32 arg1) { func_8003B424(arg0, arg1, 0xCA, 0xCB); }

s32 func_8003B424(s32 mode, u32 bits, s32 lo, s32 hi) {
    volatile u16 *r;
    u32 ret;
    u32 h;
    s32 one;
    u32 b;

    r = D_80062D60;
    b = bits;
    if (!(D_8004FE14 & 1)) {
        r = D_8004FE28;
    }
    h = (r[hi] & 0xFF) << 16;
    ret = r[lo] | h;
    one = 1;
    switch (mode) {
        do {} while (0);
    case 1:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p |= b;
            *q |= (b >> 16) & 0xFF;
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] |= b;
            D_8004FE28[hi] |= (b >> 16) & 0xFF;
        }
        ret |= b & 0xFFFFFF;
        break;
        do {} while (0);
    case 0:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p &= ~b;
            *q &= ~((b >> 16) & 0xFF);
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] &= ~b;
            D_8004FE28[hi] &= ~((b >> 16) & 0xFF);
        }
        ret &= ~(b & 0xFFFFFF);
        break;
        do {} while (0);
    case 8:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p = b;
            *q = (b >> 16) & 0xFF;
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] = b;
            D_8004FE28[hi] = (b >> 16) & 0xFF;
        }
        ret = b & 0xFFFFFF;
        break;
    default:
        break;
    }
    return ret & 0xFFFFFF;
}


void func_8003B6E4(void) { func_8003B714(0xCA, 0xCB); }

s32 func_8003B714(s32 a0, s32 a1) {
    volatile u16 *r = D_8004FE28;
    s32 hi = (r[a1] & 0xFF) << 16;

    return r[a0] | hi;
}

s32 func_8003B744(s32 arg0) {
    s32 v;

    if (arg0 < 0) {
        v = 0;
    } else {
        v = arg0;
        if (v >= 0x40) {
            v = 0x3F;
        }
    }
    D_8004FE28[0xD5] = (D_8004FE28[0xD5] & 0xC0FF) | ((v & 0x3F) << 8);
    return v;
}

s32 func_8003B794(s32 a0) {
    u16 r;

    switch (a0) {
    case 0:
        r = D_8004FE28[0xD5];
        D_8004FDBC = 0;
        D_8004FE28[0xD5] = r & ~0x80;
        D_8004FE28[0xC2] = 0;
        D_8004FE28[0xC3] = 0;
        D_8004FDCC.field_4 = 0;
        D_8004FDCC.field_6 = 0;
        break;
    case 1:
        if (D_8004FDC0 != a0 && func_8003B904(D_8004FDC4) != 0) {
            r = D_8004FE28[0xD5];
            D_8004FDBC = 0;
            D_8004FE28[0xD5] = r & ~0x80;
        } else {
            r = D_8004FE28[0xD5];
            D_8004FDBC = a0;
            D_8004FE28[0xD5] = r | 0x80;
        }
        break;
    }
    return D_8004FDBC;
}

s32 func_8003B884(u32 addr) {
    Hdr3AD44 *h;
    u32 v;

    if (D_8004FE90 == NULL) {
        return 0;
    }
    h = D_8004FE90;
    for (;; h++) {
        v = h->field_0;
        if (v & 0x80000000) {
            continue;
        }
        if (v & 0x40000000) {
            break;
        }
        v &= 0x0FFFFFFF;
        if (v >= addr) {
            return 1;
        }
        if (addr < v + h->field_4) {
            return 1;
        }
    }
    return 0;
}

s32 func_8003B904(u32 a0) {
    Hdr3AD44 *p;
    u32 v;
    u32 m1;
    u32 m2;
    u32 m3;

    a0 <<= D_8004FE50;
    if (D_8004FE90 == 0) {
        return 0;
    }
    m1 = 0x80000000;
    m2 = 0x40000000;
    m3 = 0xFFFFFFF;
    p = D_8004FE90;
    for (;;) {
        v = p->field_0;
        if (!(v & m1)) {
            if (v & m2) {
                goto zero;
            }
            v &= m3;
            if (v < a0) {
                if (a0 < v + p->field_4) {
                    break;
                }
            } else {
                break;
            }
        }
        p++;
    }
    return 1;
zero:
    return 0;
}


#define REVCPY(d, s) { u8 *_d = (u8 *)(d); u8 *_s = (u8 *)(s); s32 _n; for (_n = 0x43; _n != -1; _n--) { *_d++ = *_s++; } }
s32 func_8003B994(Cmd62C18 *attr) {
    Rev3B994 p;
    s32 mask;
    u32 mode;
    s32 all;
    volatile s32 clear;
    s32 modeSet;
    s32 delaySet;
    s32 fbSet;
    s32 wasOn;
    s32 t;
    s32 m;
    s32 *tbl;
    s32 d;

    wasOn = 0;
    modeSet = 0;
    delaySet = 0;
    clear = 0;
    mask = ((volatile Cmd62C18 *)attr)->field_0;
    fbSet = 0;
    all = mask == 0;
    p.field_0 = 0;
    if (all || (mask & 1)) {
        mode = attr->field_4;
        if (mode & 0x100) {
            mode &= ~0x100;
            clear = 1;
        }
        if (mode >= 10 || (tbl = D_800503B8, func_8003B904(D_800503B8[mode]))) {
            return -1;
        }
        modeSet = 1;
        D_8004FDCC.field_0 = mode;
        m = ((volatile Blk4FDCC *)&D_8004FDCC)->field_0;
        tbl += m;
        D_8004FDC4 = *tbl;
        REVCPY(&p, &D_800503E8[m]);
        switch (D_8004FDCC.field_0) {
        case 7:
            D_8004FDCC.field_C = 0x7F;
            D_8004FDCC.field_8 = 0x7F;
            break;
        case 8:
            D_8004FDCC.field_C = 0;
            D_8004FDCC.field_8 = 0x7F;
            break;
        default:
            D_8004FDCC.field_C = 0;
            D_8004FDCC.field_8 = 0;
            break;
        }
    }
    if (all || (mask & 8)) {
        s32 mm = D_8004FDCC.field_0;
        if (mm < 9) {
            if (mm >= 7) {
                delaySet = 1;
                if (!modeSet) {
                    REVCPY(&p, &D_800503E8[((volatile Blk4FDCC *)&D_8004FDCC)->field_0]);
                    p.field_0 = 0xC011C00;
                }
                d = attr->field_C;
                D_8004FDCC.field_8 = d;
                t = (d << 12) / 127;
                p.field_18 = (d << 13) / 127 - p.field_4;
                p.field_1A = t - p.field_6;
                p.field_1C = p.field_1E + t;
                p.field_24 = p.field_26 + t;
                p.field_38 = p.field_3C + t;
                p.field_3A = p.field_3E + t;
            }
        }
    }
    if (all || (mask & 0x10)) {
        s32 mm = D_8004FDCC.field_0;
        if (mm < 9) {
            if (mm >= 7) {
                fbSet = 1;
                if (!modeSet) {
                    if (!delaySet) {
                        REVCPY(&p, &D_800503E8[((volatile Blk4FDCC *)&D_8004FDCC)->field_0]);
                        p.field_0 = 0x80;
                    } else {
                        p.field_0 |= 0x80;
                    }
                }
                d = attr->field_10;
                D_8004FDCC.field_C = d;
                p.field_12 = (d * 0x8100) / 127;
            }
        }
    }
    if (modeSet) {
        wasOn = (((volatile u16 *)D_8004FE28)[0xD5] >> 7) & 1;
        if (wasOn) {
            ((volatile u16 *)D_8004FE28)[0xD5] &= ~0x80;
        }
    } else {
        if (all || (mask & 2)) {
            D_8004FE28[0xC2] = attr->field_8;
            D_8004FDCC.field_4 = attr->field_8;
        }
        if (all || (mask & 4)) {
            D_8004FE28[0xC3] = attr->field_A;
            D_8004FDCC.field_6 = attr->field_A;
        }
        goto done;
    }
    D_8004FE28[0xC2] = 0;
    D_8004FE28[0xC3] = 0;
    D_8004FDCC.field_4 = 0;
    D_8004FDCC.field_6 = 0;
done:
    if (modeSet || delaySet || fbSet) {
        func_8003BE74(&p);
    }
    if (clear) {
        func_8003C3A4(D_8004FDCC.field_0);
    }
    if (modeSet) {
        func_8003AAE0(0xD1, D_8004FDC4, 0);
        if (wasOn) {
            D_8004FE28[0xD5] |= 0x80;
        }
    }
    return 0;
}


void func_8003BE74(Rev3B994 *p) {
    u32 mask;
    s32 all;

    mask = p->field_0;
    all = mask == 0;
    if (all || (mask & 0x1)) {
        D_8004FE28[0xE0] = p->field_4;
    }
    if (all || (mask & 0x2)) {
        D_8004FE28[0xE1] = p->field_6;
    }
    if (all || (mask & 0x4)) {
        D_8004FE28[0xE2] = p->field_8;
    }
    if (all || (mask & 0x8)) {
        D_8004FE28[0xE3] = p->field_A;
    }
    if (all || (mask & 0x10)) {
        D_8004FE28[0xE4] = p->field_C;
    }
    if (all || (mask & 0x20)) {
        D_8004FE28[0xE5] = p->field_E;
    }
    if (all || (mask & 0x40)) {
        D_8004FE28[0xE6] = p->field_10;
    }
    if (all || (mask & 0x80)) {
        D_8004FE28[0xE7] = p->field_12;
    }
    if (all || (mask & 0x100)) {
        D_8004FE28[0xE8] = p->field_14;
    }
    if (all || (mask & 0x200)) {
        D_8004FE28[0xE9] = p->field_16;
    }
    if (all || (mask & 0x400)) {
        D_8004FE28[0xEA] = p->field_18;
    }
    if (all || (mask & 0x800)) {
        D_8004FE28[0xEB] = p->field_1A;
    }
    if (all || (mask & 0x1000)) {
        D_8004FE28[0xEC] = p->field_1C;
    }
    if (all || (mask & 0x2000)) {
        D_8004FE28[0xED] = p->field_1E;
    }
    if (all || (mask & 0x4000)) {
        D_8004FE28[0xEE] = p->field_20;
    }
    if (all || (mask & 0x8000)) {
        D_8004FE28[0xEF] = p->field_22;
    }
    if (all || (mask & 0x10000)) {
        D_8004FE28[0xF0] = p->field_24;
    }
    if (all || (mask & 0x20000)) {
        D_8004FE28[0xF1] = p->field_26;
    }
    if (all || (mask & 0x40000)) {
        D_8004FE28[0xF2] = p->field_28;
    }
    if (all || (mask & 0x80000)) {
        D_8004FE28[0xF3] = p->field_2A;
    }
    if (all || (mask & 0x100000)) {
        D_8004FE28[0xF4] = p->field_2C;
    }
    if (all || (mask & 0x200000)) {
        D_8004FE28[0xF5] = p->field_2E;
    }
    if (all || (mask & 0x400000)) {
        D_8004FE28[0xF6] = p->field_30;
    }
    if (all || (mask & 0x800000)) {
        D_8004FE28[0xF7] = p->field_32;
    }
    if (all || (mask & 0x1000000)) {
        D_8004FE28[0xF8] = p->field_34;
    }
    if (all || (mask & 0x2000000)) {
        D_8004FE28[0xF9] = p->field_36;
    }
    if (all || (mask & 0x4000000)) {
        D_8004FE28[0xFA] = p->field_38;
    }
    if (all || (mask & 0x8000000)) {
        D_8004FE28[0xFB] = p->field_3A;
    }
    if (all || (mask & 0x10000000)) {
        D_8004FE28[0xFC] = p->field_3C;
    }
    if (all || (mask & 0x20000000)) {
        D_8004FE28[0xFD] = p->field_3E;
    }
    if (all || (mask & 0x40000000)) {
        D_8004FE28[0xFE] = p->field_40;
    }
    if (all || (mask & 0x80000000)) {
        D_8004FE28[0xFF] = p->field_42;
    }
}


void func_8003C344(s32 arg0, s32 arg1) { func_8003B424(arg0, arg1, 0xCC, 0xCD); }

void func_8003C374(void) { func_8003B714(0xCC, 0xCD); }

s32 func_8003C3A4(s32 a0) {
    u32 size;
    u32 addr;
    u32 n;
    s32 cont;
    s32 mode;
    s32 wait = 0;
    s32 *p;
    void (*volatile cb)(void) = 0;

    if ((u32)a0 >= 10 || func_8003B904(*(p = &D_800503B8[a0])) != 0) {
        return -1;
    }
    if (a0 == 0) {
        size = 0x10 << D_8004FE50;
        addr = 0xFFF0 << D_8004FE50;
    } else {
        size = (0x10000 - *p) << D_8004FE50;
        addr = *p << D_8004FE50;
    }
    mode = D_8004FE44;
    if (mode == 1) {
        D_8004FE44 = 0;
        wait = 1;
    }
    cont = 1;
    if (D_8004FE60 != 0) {
        cb = D_8004FE60;
        D_8004FE60 = 0;
    }
    do {
        n = 0x400;
        if (size <= 0x400) {
            n = size;
            cont = 0;
        }
        func_8003A778(2, addr);
        func_8003A778(1);
        func_8003A778(3, D_8004FE98, n);
        size -= 0x400;
        addr += 0x400;
        func_8003C544(D_8004FDB0);
    } while (cont);
    if (wait) {
        D_8004FE44 = mode;
    }
    if (cb != 0) {
        D_8004FE60 = cb;
    }
    return 0;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003C544);

void func_8003C554(s32 on_off, u32 voice_bit) {
    u32 hi;
    s32 t;
    volatile u16 *p;

    voice_bit &= 0xFFFFFF;
    hi = voice_bit >> 16;
    switch (on_off) {
    case 1:
        if (D_8004FE14 & 1) {
            p = D_80062EE8;
            p[0] = voice_bit;
            p[1] = hi;
            *(volatile s32 *)&D_8004FDE0 |= 1;
            *(volatile s32 *)&D_8004FDDC |= voice_bit;
            if (p[2] & voice_bit) {
                p[2] &= ~voice_bit;
            }
            if (p[3] & hi) {
                p[3] &= ~hi;
            }
        } else {
            D_8004FE28[0xC4] = voice_bit;
            D_8004FE28[0xC5] = hi;
            t = D_8004FDB4 | voice_bit;
            goto store;
        }
        break;
    case 0:
        if (D_8004FE14 & 1) {
            p = D_80062EE8;
            p[2] = voice_bit;
            p[3] = hi;
            *(volatile s32 *)&D_8004FDE0 |= 1;
            *(volatile s32 *)&D_8004FDDC &= ~voice_bit;
            if (p[0] & voice_bit) {
                p[0] &= ~voice_bit;
            }
            if (p[1] & hi) {
                p[1] &= ~hi;
            }
        } else {
            ((volatile u16 *)D_8004FE28)[0xC6] = voice_bit;
            ((volatile u16 *)D_8004FE28)[0xC7] = hi;
            t = *(volatile s32 *)&D_8004FDB4 & ~voice_bit;
        store:
            D_8004FDB4 = t;
        }
        break;
    }
}


u32 func_8003C714(s32 a0, u32 n) {
    if (n > 0x7EFF0) {
        n = 0x7EFF0;
    }
    func_8003A9F8(a0, n);
    if (D_8004FE60 == 0) {
        D_8004FE5C = 0;
    }
    return n;
}

s32 func_8003C774(u32 addr) {
    if (addr - 0x1010 > 0x7EFE8) {
        return 0;
    }
    D_8004FE40 = func_8003AB24(-1, addr);
    return D_8004FE40 << D_8004FE50;
}

void func_8003C7D4(s32 arg0) {
    s32 v;

    switch (arg0) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8004FDB8 = arg0;
    D_8004FE44 = v;
}

s32 func_8003C804(s32 a0) {
    s32 r;

    if (D_8004FDB8 == 1 || D_8004FE5C == 1) {
        return 1;
    }
    r = func_8003C8B4(D_8004FDB0);
    if (a0 == 1) {
        if (r == 0) {
            while (func_8003C8B4(D_8004FDB0) == 0) {
            }
        }
        r = 1;
    } else if (r != 1) {
        return r;
    }
    D_8004FE5C = r;
    return r;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003C8B4);

void func_8003C8C4(s32 arg0) {
    if (arg0 == 1) {
        D_8004FE5C = 0;
    } else {
        D_8004FE5C = 1;
    }
}

s32 func_8003C8EC(void) {
    return (D_8004FE5C ^ 1) != 0;
}

void func_8003C904(VAttr36C54 *arg) {
    s32 ch;
    s32 ch8;
    u32 mask;
    s32 all;
    s32 vol;
    s32 vmode;
    u32 v;
    s32 m;
    volatile s32 i;
    volatile s32 w;

    mask = arg->mask;
    all = mask == 0;
    for (ch = 0; ch < 24; ch++) {
        if (!(arg->voice & (1 << ch))) {
            continue;
        }
        ch8 = ch << 3;
        if (all || (mask & 0x10)) {
            D_8004FE28[(ch << 3) + 2] = arg->pitch;
        }
        if (all || (mask & 0x40)) {
            D_8004FDE4[ch] = arg->sample_note;
        }
        if (all || (mask & 0x20)) {
            D_8004FE28[ch8 + 2] = func_8003CF04(D_8004FDE4[ch] >> 8, D_8004FDE4[ch] & 0xFF,
                                                arg->note >> 8, arg->note & 0xFF);
        }
        if (all || (mask & 0x1)) {
            vmode = 0;
            vol = arg->vol_l & 0x7FFF;
            if (all || (mask & 0x4)) {
                switch (arg->volmode_l) {
                case 1:
                    vmode = 0x8000;
                    break;
                case 2:
                    vmode = 0x9000;
                    break;
                case 3:
                    vmode = 0xA000;
                    break;
                case 4:
                    vmode = 0xB000;
                    break;
                case 5:
                    vmode = 0xC000;
                    break;
                case 6:
                    vmode = 0xD000;
                    break;
                case 7:
                    vmode = 0xE000;
                    break;
                }
            }
            if (vmode != 0) {
                if (arg->vol_l >= 0x80) {
                    vol = 0x7F;
                } else if (arg->vol_l < 0) {
                    vol = 0;
                }
            }
            D_8004FE28[ch8] = vol | vmode;
        }
        if (all || (mask & 0x2)) {
            vmode = 0;
            vol = arg->vol_r & 0x7FFF;
            if (all || (mask & 0x8)) {
                switch (arg->volmode_r) {
                case 1:
                    vmode = 0x8000;
                    break;
                case 2:
                    vmode = 0x9000;
                    break;
                case 3:
                    vmode = 0xA000;
                    break;
                case 4:
                    vmode = 0xB000;
                    break;
                case 5:
                    vmode = 0xC000;
                    break;
                case 6:
                    vmode = 0xD000;
                    break;
                case 7:
                    vmode = 0xE000;
                    break;
                }
            }
            if (vmode != 0) {
                if (arg->vol_r >= 0x80) {
                    vol = 0x7F;
                } else if (arg->vol_r < 0) {
                    vol = 0;
                }
            }
            D_8004FE28[ch8 + 1] = vol | vmode;
        }
        if (all || (mask & 0x80)) {
            func_8003AB24(ch8 | 3, arg->addr);
        }
        if (all || (mask & 0x10000)) {
            func_8003AB24(ch8 | 7, arg->loop_addr);
        }
        if (all || (mask & 0x20000)) {
            D_8004FE28[ch8 + 4] = arg->adsr1;
        }
        if (all || (mask & 0x40000)) {
            D_8004FE28[ch8 + 5] = arg->adsr2;
        }
        if (all || (mask & 0x800)) {
            v = arg->ar;
            if (v >= 0x80) {
                v = 0x7F;
            }
            m = 0;
            if (all || (mask & 0x100)) {
                if (arg->a_mode == 5) {
                    m = 0x80;
                }
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFF) | ((v | m) << 8);
        }
        if (all || (mask & 0x1000)) {
            v = arg->dr;
            if (v >= 0x10) {
                v = 0xF;
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFF0F) | (v << 4);
        }
        if (all || (mask & 0x2000)) {
            v = arg->sr;
            if (v >= 0x80) {
                v = 0x7F;
            }
            m = 0x100;
            if (all || (mask & 0x200)) {
                switch (arg->s_mode) {
                case 1:
                    m = 0;
                    break;
                case 5:
                    m = 0x200;
                    break;
                case 7:
                    m = 0x300;
                    break;
                }
            }
            D_8004FE28[ch8 + 5] = (((volatile u16 *)D_8004FE28)[ch8 + 5] & 0x3F) | ((v | m) << 6);
        }
        if (all || (mask & 0x4000)) {
            v = arg->rr;
            if (v >= 0x20) {
                v = 0x1F;
            }
            m = 0;
            if (all || (mask & 0x400)) {
                switch (arg->r_mode) {
                case 3:
                    m = 0;
                    break;
                case 7:
                    m = 0x20;
                    break;
                }
            }
            D_8004FE28[ch8 + 5] = (((volatile u16 *)D_8004FE28)[ch8 + 5] & 0xFFC0) | (v | m);
        }
        if (all || (mask & 0x8000)) {
            v = arg->sl;
            if (v >= 0x10) {
                v = 0xF;
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFFF0) | v;
        }
    }
    w = 1;
    for (i = 0; i < 2; i++) {
        w *= 13;
    }
}


u16 func_8003CF04(s32 cenHigh, s32 cenLow, s32 noteHigh, s32 noteLow) {
    s16 fine;
    s32 note;
    s32 oct;
    s16 key;
    s16 shift;
    u32 pitch;

    fine = noteLow + cenLow;
    note = (s16)(noteHigh + ((u16)fine >> 7) - cenHigh);
    fine = (u16)fine % 128;
    oct = note / 12;
    shift = oct - 2;
    key = note - oct * 12;
    if (key < 0) {
        key += 12;
        shift = oct - 3;
    }
    pitch = (D_80050298[key] * D_800502B0[(u16)fine]) >> 16;
    if (shift >= 0) {
        pitch = 0x3FFF;
    } else {
        pitch = (pitch + (1 << (-shift - 1))) >> -shift;
    }
    return pitch;
}

s32 func_8003CFD4(s32 note, s32 fine, u16 pitch) {
    s32 i;
    s32 j;
    s32 k;
    s32 bit = 0;
    s32 n;
    s32 m;
    s32 t;
    u16 f;
    u16 fn;
    u16 nt;
    u16 *p;
    u16 *q;

    if (pitch >= 0x4000) {
        pitch = 0x3FFF;
    }
    for (i = 0; i < 14; i++) {
        if ((pitch >> i) & 1) {
            bit = i;
        }
    }
    pitch = pitch << (15 - bit);
    j = 11;
    p = D_80050298;
    for (; j >= 0; j--) {
        if (pitch >= p[j]) {
            n = j;
            break;
        }
    }
    f = ((u32)pitch << 15) / D_80050298[(u16)n];
    for (k = 127, q = &D_800502B0[127]; k >= 0; k--, q--) {
        if (f >= *q) {
            m = k;
            break;
        }
    }
    t = m + 1;
    m = fine + t;
    fn = m;
    note = note + (bit - 12) * 12 + n + (fn >> 7);
    return ((u16)note << 8) | (fn & 0x7E);
}


void func_8003D104(s32 a0, u16 *a1) {
    *a1 = D_8004FE28[a0 * 8 + 6];
}

void func_8003D124(Cmd3D124 *a0) {
    s32 mask;
    s32 all;
    s32 mode;
    u16 vl;
    u16 vr;
    u16 *r;
    u16 v;

    vl = 0;
    mask = a0->field_0;
    vr = 0;
    all = mask == 0;
    if (all || (mask & 1)) {
        if (all || (mask & 4)) {
            switch (a0->field_8) {
            case 1:
                mode = 0x8000;
                break;
            case 2:
                mode = 0x9000;
                break;
            case 3:
                mode = 0xA000;
                break;
            case 4:
                mode = 0xB000;
                break;
            case 5:
                mode = 0xC000;
                break;
            case 6:
                mode = 0xD000;
                break;
            case 7:
                mode = 0xE000;
                break;
            case 0:
            default:
                vl = a0->field_4;
                mode = 0;
                break;
            }
        } else {
            vl = a0->field_4;
            mode = 0;
        }
        if (mode != 0) {
            if (a0->field_4 >= 0x80) {
                vl = 0x7F;
            } else if (a0->field_4 < 0) {
                vl = 0;
            } else {
                vl = a0->field_4;
            }
        }
        D_8004FE28[0xC0] = (vl & 0x7FFF) | mode;
    }
    if (all || (mask & 2)) {
        if (all || (mask & 8)) {
            switch (a0->field_A) {
            case 1:
                mode = 0x8000;
                break;
            case 2:
                mode = 0x9000;
                break;
            case 3:
                mode = 0xA000;
                break;
            case 4:
                mode = 0xB000;
                break;
            case 5:
                mode = 0xC000;
                break;
            case 6:
                mode = 0xD000;
                break;
            case 7:
                mode = 0xE000;
                break;
            case 0:
            default:
                vr = a0->field_6;
                mode = 0;
                break;
            }
        } else {
            vr = a0->field_6;
            mode = 0;
        }
        if (mode != 0) {
            if (a0->field_6 >= 0x80) {
                vr = 0x7F;
            } else if (a0->field_6 < 0) {
                vr = 0;
            } else {
                vr = a0->field_6;
            }
        }
        D_8004FE28[0xC1] = (vr & 0x7FFF) | mode;
    }
    if (all || (mask & 0x40)) {
        D_8004FE28[0xD8] = a0->field_10;
    }
    if (all || (mask & 0x80)) {
        D_8004FE28[0xD9] = a0->field_12;
    }
    if (all || (mask & 0x400)) {
        D_8004FE28[0xDA] = a0->field_1C;
    }
    if (all || (mask & 0x800)) {
        D_8004FE28[0xDB] = a0->field_1E;
    }
    if (all || (mask & 0x100)) {
        if (a0->field_14 == 0) {
            D_8004FE28[0xD5] &= ~4;
        } else {
            D_8004FE28[0xD5] |= 4;
        }
    }
    if (all || (mask & 0x200)) {
        if (a0->field_18 == 0) {
            D_8004FE28[0xD5] &= ~1;
        } else {
            D_8004FE28[0xD5] |= 1;
        }
    }
    if (all || (mask & 0x1000)) {
        if (a0->field_20 == 0) {
            D_8004FE28[0xD5] &= ~8;
        } else {
            D_8004FE28[0xD5] |= 8;
        }
    }
    if (all || (mask & 0x2000)) {
        if (a0->field_24 == 0) {
            r = D_8004FE28;
            v = r[0xD5] & ~2;
        } else {
            r = D_8004FE28;
            v = r[0xD5] | 2;
        }
        r[0xD5] = v;
    }
}


void func_8003D4A4(void) {
    func_8003D504();
    func_8003D594();
    func_8003D4F4();
}

void func_8003D4D4(void) { func_8003D5DC(); }

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D4F4);

extern s32 func_8003D610(void);
extern void func_8003D9D4(s32);
extern void func_8003DBE4(void);
extern void func_8003DAE0(void);
extern void func_8003DB74(void);
extern void func_8003DA04(void);

/* K&R definition: func_8003D4A4 / func_8003FBC4 call it without arguments. */
void func_8003D504(a0)
s32 a0;
{
    s32 s0 = a0;
    s32 s1;
    func_80030CC4(0);
    func_80030AB4(0);
    s1 = func_80026FC4();
    if (func_8003D610() == 0) {
        s0 = 0;
    }
    func_8003D9D4(s0);
    func_8003DBE4();
    func_8003DAE0();
    func_8003DB74();
    func_8003DA04();
    if (s1 == 1) {
        func_80026FD4();
    }
}

s32 func_8003D594(void) {
    s32 s = func_80026FC4();
    func_8003D9E4();
    func_80030CC4(0);
    if (s == 1) {
        func_80026FD4();
        return 0;
    }
    return 0;
}

s32 func_8003D5DC(void) {
    func_8003D9F4();
    func_8003DC24();
    return 0;
}

extern s32 D_800506B8;
void func_8003D604(s32 a0) {
    D_800506B8 = a0;
}

s32 func_8003D610(void) {
    return D_800506B8;
}

void func_8003D620(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8003D964();
    func_80026FC4();
    func_8003D8EC();
    func_80026FD4();
    func_80030CC4(0);
    func_8003D770();
    func_8003D8B4(a0, a1, a2, a3);
    D_800506B8 = 1;
}

void func_8003D6B0(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8003D964();
    func_80026FC4();
    func_8003D8EC();
    func_80026FD4();
    func_80030CC4(0);
    func_8003D770();
    func_8003D894(a0, a1, a2, a3);
    D_800506B8 = 1;
}

s32 func_8003D740(void) {
    func_8003D8A4();
    func_80030CC4(0);
    func_8003D8C4();
    return 1;
}

s32 func_8003D770(void) {
    func_80026FC4();
    D_80062F04[0] = func_8003D7E8;
    D_80062F04[1] = func_8003D850;
    D_80062F00 = 0;
    D_80062F0C = 0;
    func_80026FF4(1, (u8 *)&D_80062F04[-1]);
    func_80026FE4(1, (u8 *)&D_80062F04[-1]);
    func_80026FD4();
    return 1;
}


s32 func_8003D7E8(void) {
    volatile s32 i[4];

    D_800506BC->field_A = 0;
    i[0] = 10;
    while (--i[0] != -1) {
    }
    return 0;
}

s32 func_8003D850(void) {
    Flags506C0 *p = D_800506C0;

if (!((p->field_4 & 1) && (p->field_0 & 1))) {
 return 0;
 }
 return 1;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D894);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D8A4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D8B4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D8C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D8EC);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D964);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D9D4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D9E4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003D9F4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DA04);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DA48);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DA74);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DAB8);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DAE0);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DB74);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DBE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003DC24);

void func_8003DCA4(void) {
    D_80062FD8 = func_8003F178(0);
}

void func_8003DCCC(void) { func_8003F178(D_80062FD8); }

s32 *func_8003DCF4(void) {
    return &D_80062F80.field_0;
}

void func_8003DD00(void) {
    State62F80 *p = &D_80062F80;

    p->field_C = 0;
    p->field_44 = 0;
    func_8003FA14();
    p->field_0 = 0;
    p->field_4 = 0;
    p->field_8 = 0;
    ((volatile State62F80 *)p)->field_50[1] = 0;
    p->field_14 = -1;
    p->field_48[1] = 1;
    p->field_48[0] = 1;
    p->field_50[0] = ((volatile State62F80 *)p)->field_50[1];
    func_8003FBF4();
    func_80030D98(7, (s32)func_8003F46C);
}

void func_8003DD70(void) {
    volatile s32 *p = &D_80062F80.field_0;

    while (*p != 0) {
    }
    func_80030D98(7, 0);
    func_8003FDF0();
}

s32 func_8003DDB0(s32 arg0) {
    s32 r;

    if (D_80062F80.field_0 <= 0) {
        D_80062F80.field_0 = 1;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_10 = arg0;
        func_8003FA24(func_8003DE18);
        r = 1;
    } else {
        func_8002A014(D_80010B74, arg0);
        r = 0;
    }
    return r;
}

s32 func_8003DE18(s32 *st) {
    s32 r;
    volatile State62F80 *q;
    s32 m;
    s32 v;
    s32 *e;
    s32 *tbl;
    s32 k;
    s32 c;
    s32 w;
    s32 *pt;
    s32 k2;

    switch (*st) {
    case 0:
        D_80062F54 = 0;
        D_80062F50 = 0;
        *st = 10;
        e = &D_80062F80.field_50[D_80062F80.field_10 >> 4];
        v = *e;
        *e = 0;
        D_800506C8 = v;
    case 10:
        func_8003FEA4();
        func_8003F994(D_80062F80.field_10);
        *st = *st + 1;
        break;
    case 11:
        if (func_8004015C() == 0) {
            return 0;
        }
        r = func_8003FFAC();
        D_80062F54 = r;
        k = D_80062F80.field_10;
        tbl = D_80062F80.field_48;
        e = &tbl[k >> 4];
        D_800506CC = *e;
        switch (r) {
        case 4:
            if (D_800506CC == 0 && D_800506C8 < 0x80) {
                func_8003FEA4();
                func_8003F9B4(D_80062F80.field_10);
                *st = 0x15;
                break;
            }
            k = D_80062F80.field_10;
            tbl = D_80062F80.field_48;
            tbl[k >> 4] = 1;
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(D_80062F54);
            return 1;
        case 0:
            c = D_80062F80.field_C;
            m = 1 << k;
            if (!(c & m)) {
                D_80062F54 = 4;
            }
            w = D_80062F54;
            *e = 0;
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(w);
            return 1;
        case 2:
            if (++D_80062F50 < 3) {
                *st = 10;
                break;
            }
            *e = 1;
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(2);
            return 1;
        case 1:
            if (++D_80062F50 < 17) {
                *st = 10;
                break;
            }
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(1);
            tbl[D_80062F80.field_10 >> 4] = 0;
            return 1;
        default:
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(D_80062F54);
            pt = D_80062F80.field_48;
            pt[D_80062F80.field_10 >> 4] = 0;
            return 1;
        }
        break;
    case 21:
        if (func_80040198() == 0) {
            return 0;
        }
        func_80040084();
        *st = 0;
        break;
    default:
        func_8002A014(D_80010B9C);
        break;
    }
    return 0;
}


s32 func_8003E134(s32 arg0) {
    s32 r;

    if (D_80062F80.field_0 <= 0) {
        D_80062F80.field_0 = 2;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_10 = arg0;
        func_8003FA24(func_8003E19C);
        r = 1;
    } else {
        func_8002A014(D_80010B74);
        r = 0;
    }
    return r;
}

s32 func_8003E19C(s32 *st) {
    s32 r;

    switch (*st) {
    case 0:
        D_80062F5C = 0;
        D_80062F60 = 0;
        D_80062F58 = 0;
        D_80062F68 = 0;
        D_80062F64 = 0;
        (*st)++;
    case 1:
        func_8003FA24(func_8003DE18);
        *st = 10;
        break;
    case 10:
        switch (D_80062F80.field_4) {
        case 1:
            return 1;
        case 3:
            {
                volatile State62F80 *q = (volatile State62F80 *)&D_80062F80;
                D_80062F68 = 1;
                q->field_C = D_80062F80.field_C | (1 << D_80062F80.field_10);
            }
            func_8003FEA4();
            func_8003F9B4(D_80062F80.field_10);
            *st = 0x15;
            break;
        case 0:
        set30:
            *st = 30;
            break;
        default:
            return 1;
        }
        break;
    case 21:
        if (func_80040198() == 0) {
            return 0;
        }
        func_80040084();
        *st = 30;
    case 30:
        func_8003FEA4();
        func_8003F9A4(D_80062F90);
        *st = *st + 1;
        break;
    case 31:
        if (func_8004015C() == 0) {
            return 0;
        }
        r = func_8003FFAC();
        D_80062F64 = r;
        switch (r) {
        case 0:
            ((volatile State62F80 *)&D_80062F80)->field_4 = D_80062F68 ? 3 : 0;
            return 1;
        case 4:
            func_8003FEA4();
            func_8003F994(D_80062F90);
            *st = 0x32;
            break;
        case 2:
            *st = 1;
            return 0;
        case 1:
            if (++D_80062F5C < 17) {
                goto set30;
            }
        default:
            ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(D_80062F64);
            return 1;
        }
        break;
    case 50:
        if (func_8004015C() == 0) {
            return 0;
        }
        r = func_8003FFAC();
        D_80062F64 = r;
        if (r == 0) {
            ((volatile State62F80 *)&D_80062F80)->field_4 = 4;
            return 1;
        }
        *st = 1;
        break;
    default:
        return 0;
    }
    return 0;
}


s32 func_8003E444(s32 a0, s32 a1, s32 a2) {
    s32 tries;
    s32 r;
    s32 st;

    tries = 0;
    if (D_80062F80.field_14 >= 0) {
        func_8002A014(D_80010C70);
        return -1;
    }
    func_8003F518(a0, D_80062F80.field_24);
    func_8003F874(D_80062F80.field_24, a1);
    D_80062F80.field_10 = a0;
    do {
    retry:
        r = func_8003F574(D_80062F80.field_24, 1);
        if (r >= 0) {
            goto ok;
        }
        D_80062FD8 = func_8003F178(0);
        if (D_80062F80.field_0 > 0) {
            func_8002A014(D_80010B74);
        } else {
            D_80062F80.field_0 = 2;
            D_80062F80.field_4 = 0;
            D_80062F80.field_8 = 0;
            D_80062F90 = a0;
            func_8003FA24(func_8003E19C);
        }
        func_8003F18C(0, NULL, &st);
        func_8003F178(D_80062FD8);
        if (st == 3) {
            goto retry;
        }
        if (st != 2) {
            break;
        }
    } while (++tries < 5);
    if (st == 0) {
        st = 5;
    }
    return st;
ok:
    func_8003F5A4(r);
    func_8003FEA4();
    D_80062F80.field_14 = func_8003F574(D_80062F80.field_24, a2 | 0x8000);
    return 0;
}


void func_8003E5CC(void) {
    s32 *p = &D_80062F94;

    if (*p >= 0) {
        func_8003F5A4(*p);
        *p = -1;
    }
}

s32 func_8003E610(s32 a0, s32 a1, s32 a2) {
    char *msg;

    if (D_80062F80.field_14 < 0) {
        msg = D_80010C98;
    } else if (D_80062F80.field_0 > 0) {
        msg = D_80010B74;
    } else if (a2 & 0x7F) {
        msg = D_80010CBC;
    } else if (a1 & 0x7F) {
        msg = D_80010CE8;
    } else {
        D_80062F80.field_0 = 5;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_18 = a1;
        D_80062F80.field_20 = a0;
        D_80062F80.field_1C = a2;
        func_8003FA24(func_8003E6C8);
        return 1;
    }
    func_8002A014(msg);
    return 0;
}

s32 func_8003E6C8(s32 *state) {
    s32 r;

    switch (*state) {
    case 0:
        D_800506D0 = 0;
        *state = 10;
        func_8003FA24(func_8003DE18);
        return 0;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        while (func_8003F584(D_80062F80.field_14, D_80062F80.field_18, 0) != D_80062F80.field_18) {
        }
        func_8003FEA4();
        while (func_8003F594(D_80062F80.field_14, D_80062F80.field_20, D_80062F80.field_1C) != 0) {
        }
        *state = 30;
        break;
    case 30:
        if (func_8004015C() == 0) {
            return 0;
        }
        r = func_8003FFAC();
        if (r == 0) {
            goto fail;
        }
        if (++D_800506D0 < 4) {
            *state = 10;
            break;
        }
        if (r == 4) {
            func_8003FEA4();
            func_8003F9B4(D_80062F90);
            *state = 32;
            break;
        }
    fail:
        ((volatile State62F80 *)&D_80062F80)->field_4 = func_8003F418(r);
        return 1;
    case 32:
        if (func_80040198() == 0) {
            return 0;
        }
        func_80040084();
        *state = 0;
        break;
    default:
        return 0;
    }
    return 0;
}


s32 func_8003E878(s32 a0, s32 a1, s32 a2) {
    char *msg;

    if (D_80062F80.field_14 < 0) {
        msg = D_80010C98;
    } else if (D_80062F80.field_0 > 0) {
        msg = D_80010B74;
    } else if (a2 & 0x7F) {
        msg = D_80010CBC;
    } else if (a1 & 0x7F) {
        msg = D_80010CE8;
    } else {
        D_80062F80.field_0 = 6;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_18 = a1;
        D_80062F80.field_20 = a0;
        D_80062F80.field_1C = a2;
        func_8003FA24(func_8003E930);
        return 1;
    }
    func_8002A014(msg);
    return 0;
}

s32 func_8003E930(s32 *st) {
    s32 r;

    switch (*st) {
    case 0:
        D_800506D4 = 0;
        func_8003FA24(func_8003DE18);
        *st = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        while (func_8003F584(D_80062F80.field_14, D_80062F80.field_18, 0) != D_80062F80.field_18) {
        }
        func_8003FEA4();
        while (func_8002A9A4(D_80062F80.field_14, (u8 *)D_80062F80.field_20, D_80062F80.field_1C) != 0) {
        }
        *st = 30;
        break;
    case 30:
        if (!func_8004015C()) {
            return 0;
        }
        r = func_8003FFAC();
        if (r != 0) {
            if (++D_800506D4 < 4) {
                *st = 10;
                break;
            }
            if (r == 4) {
                func_8003FEA4();
                func_8003F9B4(D_80062F80.field_10);
                *st = 32;
                break;
            }
        }
        {
            State62F80 *g = &D_80062F80;

            g->field_4 = func_8003F418(r);
        }
        return 1;
    case 32:
        if (!func_80040198()) {
            return 0;
        }
        func_80040084();
        *st = 0;
        break;
    default:
        return 0;
    }
    return 0;
}

s32 func_8003EADC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (D_80062F80.field_0 > 0) {
        func_8002A014(D_80010D18);
        return 0;
    }
    if (D_80062F80.field_14 >= 0) {
        func_8002A014(D_80010C70);
        return 0;
    }
    if (a4 & 0x7F) {
        func_8002A014(D_80010CBC);
        return 0;
    }
    if (a3 & 0x7F) {
        func_8002A014(D_80010CE8);
        return 0;
    }
    func_8003F518(a0, &D_80062F80.field_24);
    func_8003F874(&D_80062F80.field_24, a1);
    D_80062F80.field_0 = 3;
    D_80062F80.field_4 = 0;
    D_80062F80.field_8 = 0;
    D_80062F80.field_18 = a3;
    D_80062F80.field_20 = a2;
    D_80062F80.field_1C = a4;
    D_80062F80.field_10 = a0;
    func_8003FA24(func_8003EBF4);
    return 1;
}

s32 func_8003EBF4(s32 *a0) {
    State62F80 *p;
    s32 r;

    switch (*a0) {
    case 0:
        D_800506D8 = 0;
        func_8003FA24(func_8003DE18);
        *a0 = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        r = func_8003F574(D_80062F80.field_24, 0x8001);
        D_80062F80.field_14 = r;
        p = &D_80062F80;
        if (r < 0) {
            p->field_4 = 5;
            return 1;
        }
    case 11:
        *a0 = 20;
        func_8003FA24(func_8003E6C8);
        return 0;
    case 20:
        func_8003F5A4(D_80062F80.field_14);
        D_80062F80.field_14 = -1;
        return 1;
    }
    return 0;
}


s32 func_8003ECFC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (D_80062F80.field_0 > 0) {
        func_8002A014(D_80010D18);
        return 0;
    }
    if (D_80062F80.field_14 >= 0) {
        func_8002A014(D_80010C70);
        return 0;
    }
    if (a4 & 0x7F) {
        func_8002A014(D_80010CBC);
        return 0;
    }
    if (a3 & 0x7F) {
        func_8002A014(D_80010CE8);
        return 0;
    }
    func_8003F518(a0, D_80062F80.field_24);
    func_8003F874(D_80062F80.field_24, a1);
    D_80062F80.field_0 = 4;
    D_80062F80.field_4 = 0;
    D_80062F80.field_8 = 0;
    D_80062F80.field_18 = a3;
    D_80062F80.field_20 = a2;
    D_80062F80.field_1C = a4;
    D_80062F80.field_10 = a0;
    func_8003FA24(func_8003EE14);
    return 1;
}

s32 func_8003EE14(s32 *st) {
    s32 r;
    s32 *q;
    volatile State62F80 *vp;

    switch (*st) {
    case 0:
        D_800506DC = 0;
        func_8003FA24(func_8003DE18);
        *st = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        r = func_8003F574(D_80062F80.field_24, 0x8001);
        D_80062F80.field_14 = r;
        if (r < 0) {
            vp = &D_80062F80;
            vp->field_4 = 5;
            return 1;
        }
    case 11:
        *st = 20;
        func_8003FA24(func_8003E930);
        break;
    case 20:
        q = &D_80062F94;
        func_8003F5A4(*q);
        *q = -1;
        return 1;
    }
    return 0;
}

s32 func_8003EF1C(s32 a0_arg, s8 *a1, Ent3EF1C *out_arg, s32 *count_arg, s32 skip, s32 n) {
    s32 a0 = a0_arg;
    Ent3EF1C *out = out_arg;
    s32 *count_out = count_arg;
    s8 buf[0x20];
    Ent3EF1C ent;
    s32 st;
    s32 tries;
    s32 i;
    s32 count;
    s32 r;
    s32 ret;

    if (D_80062F80.field_0 != 0) {
        func_8002A014(D_80010D18);
        ret = -1;
        goto end;
    }
    func_8003F518(a0, buf);
    func_8003F874(buf, a1);
    tries = 0;
    i = 0;
    st = 0;
    D_80062F80.field_C |= 1 << a0;
    count = 0;
    for (; i < skip + n; i++) {
        if (i == 0) {
            do {
                func_8003FEA4();
                r = func_8003F5C4(buf, (s32)&ent);
                if (r != 0) {
                    goto have;
                }
                st = func_8003F418(func_80040084());
                if (st == 0) {
                    goto have;
                }
            } while (++tries < 4);
            D_80062FD8 = func_8003F178(0);
            if (D_80062F80.field_0 > 0) {
                func_8002A014(D_80010B74);
            } else {
                D_80062F80.field_0 = 2;
                D_80062F80.field_4 = 0;
                D_80062F80.field_8 = 0;
                D_80062F90 = a0;
                func_8003FA24(func_8003E19C);
            }
            func_8003F18C(0, NULL, &st);
            func_8003F178(D_80062FD8);
            ret = st;
            goto end;
        } else {
            r = func_8003F5B4(&ent);
        }
    have:
        if (r == 0) {
            break;
        }
        if (i >= skip && out != NULL) {
            out[count] = ent;
            count++;
        }
    }
    ret = 0;
    if (count_out != NULL) {
        *count_out = count;
    }
end:
    return ret;
}


int func_8003F178(int a0) {
    int old = D_80062FC4;
    D_80062FC4 = a0;
    return old;
}

s32 func_8003F18C(s32 wait, s32 *a1, s32 *a2) {
    State62F80 *p = &D_80062F80;
    s32 t0;
    s32 a3;

    if (p->field_0 == 0 && p->field_8 == 0) {
        return -1;
    }
    t0 = p->field_0;
    a3 = p->field_4;
    if (wait == 0) {
        if (p->field_8 == 0) {
            volatile s32 *q = &p->field_8;

            do {
            } while (*q == 0);
        }
        if (a2 != 0) {
            *a2 = *(volatile s32 *)&D_80062F74;
        }
        if (a1 != 0) {
            *a1 = *(volatile s32 *)&D_80062F70;
        }
        ((volatile State62F80 *)&D_80062F80)->field_8 = 0;
        return 1;
    }
    if (p->field_8 == 0) {
        if (a2 != 0) {
            *a2 = a3;
        }
        if (a1 == 0) {
            return 0;
        }
        *a1 = t0;
        return 0;
    }
    if (a2 != 0) {
        *a2 = *(volatile s32 *)&D_80062F74;
    }
    if (a1 != 0) {
        *a1 = *(volatile s32 *)&D_80062F70;
    }
    p->field_8 = 0;
    return 1;
}

s32 func_8003F2A8(s32 a0, s32 a1, s32 a2) {
    u8 buf[0x20];
    s32 r;

    if (D_80062F80.field_0 == 0) {
        goto work;
    }
    func_8002A014(D_80010D18);
    return -1;
e1:
    return 7;
e2:
    return 4;
e3:
    return 6;
work:
    func_8003F518(a0, buf);
    func_8003F874(buf, a1);
    D_80062F80.field_C |= 1 << a0;
    r = func_800405B4(a0, a1, a2);
    if (r == 0) {
        goto e0;
    }
    if (r == -1) {
        goto e1;
    }
    if (r == -2) {
        goto e2;
    }
    if (r == -3) {
        goto e3;
    }
    if (r == 4) {
        return 2;
    }
    return func_8003F418(r);
e0:
    return 0;
}

s32 func_8003F3A4(void) {
    State62F80 *s = &D_80062F80;
    s32 r;

    if (s->field_0 != 0) {
        func_8002A014(D_80010D18);
        return -1;
    }
    r = func_800401E4();
    if (r != 0) {
        if (r == 4) {
            return 2;
        }
        return func_8003F418(r);
    }
    return 0;
}

s32 func_8003F418(s32 a0) {
    s32 r = 0;

    switch (a0) {
    case 0:
        break;
    case 2:
        r = 1;
        break;
    default:
        r = a0 | 0x8000;
        break;
    case 4:
        r = 3;
        break;
    case 1:
        r = 2;
        break;
    }
    return r;
}

void func_8003F46C(void) {
    State62F80 *s;
    Pair62F70 *d;
    volatile State62F80 *v;

    if (func_8003FB0C() == 0) {
        func_8003FAA0();
        if (func_8003FB0C() != 0) {
            s = &D_80062F80;
            ((volatile State62F80 *)s)->field_8 = 1;
            d = (Pair62F70 *)&D_80062F70;
            ((volatile Pair62F70 *)d)->field_0 = ((volatile State62F80 *)s)->field_0;
            ((volatile Pair62F70 *)d)->field_4 = ((volatile State62F80 *)s)->field_4;
            ((volatile State62F80 *)s)->field_0 = 0;
            ((volatile State62F80 *)s)->field_4 = 0;
            if (s->field_44 != 0) {
                ((void (*)(s32, s32))s->field_44)(((volatile Pair62F70 *)d)->field_0, ((volatile Pair62F70 *)d)->field_4);
            }
        }
    }
    v = &D_80062F80;
    v->field_50[0]++;
    v->field_50[1]++;
}

void func_8003F518(s32 n, u8 *out) {
    *(Str3F518 *)out = D_80010D38;
    out[2] = n / 16 + '0';
    out[3] = n % 16 + '0';
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F574);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F584);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F594);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F5A4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F5B4);

s32 func_8003F5C4(s8 *name, s32 a1) {
    Dcb3F760 *e;
    Dcb3F760 *base;
    u32 n;
    s8 *s;
    s8 *d;
    s32 found;

    s = name;
    d = D_80062FE8;
    while (*s >= 0x3B) {
        *d++ = *s++;
    }
    *d = 0;
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && func_8003F924(e->field_0, D_80062FE8) == 0) {
            D_80062FE0 = e->field_34;
            found = 1;
            goto done;
        }
    }
    found = 0;
done:
    if (found == 0) {
        return 0;
    }
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && func_8003F924(e->field_0, D_80062FE8) == 0) {
            e->field_34 = func_8003F760;
            break;
        }
    }
    return func_8003F864(name, a1);
}


void func_8003F760(s32 *a0, s32 a1, s32 a2) {
    Dcb3F760 *e;
    Dcb3F760 *base;
    u32 n;
    void (*fn)(s32 *, s32, s32);

    if (*a0 == 0) {
        *a0 = 1;
    }
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    fn = D_80062FE0;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && func_8003F924(e->field_0, D_80062FE8) == 0) {
            e->field_34 = fn;
            break;
        }
    }
    D_80062FE0(a0, a1, a2);
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F864);

s8 *func_8003F874(s8 *dst, s8 *src) {
    s8 *ret;
    s32 c;

    if (dst == 0 || src == 0) {
        return 0;
    }
    if (dst + func_8002A9B4(dst) != src + func_8002A9B4(src)) {
        ret = dst;
        while (*dst++ != 0) {
        }
        dst--;
        do {
            c = *(u8 *)src++;
            *dst++ = c;
        } while (c != 0);
        return ret;
    }
    return 0;
}


s32 func_8003F924(s8 *a, s8 *b) {
    if (a == 0 || b == 0) {
        if (a == b) {
            return 0;
        }
        if (a == 0) {
            return -1;
        }
        return 1;
    }
    while (*a == *b++) {
        if (*a++ == 0) {
            return 0;
        }
    }
    return *a - b[-1];
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F994);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F9A4);

extern void func_8003FA04();
extern s32 func_8003F9F4();

s32 func_8003F9B4(s32 a0) {
    func_8003FA04(a0);
    return func_8003F9F4(a0, 0x3F, 0);
}
__asm__(".word 0\n.word 0\n.word 0\n");

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003F9F4);

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_8003FA04);

void func_8003FA14(void) {
    D_800506E8 = -1;
}

void func_8003FA24(s32 (*fn)(s32 *)) {
    s32 i = D_800506E8 + 1;
    s32 *p;
    s32 k;

    if (i >= 4) {
        func_8002A014(D_80010D44);
        return;
    }
    k = 3;
    p = &D_80063010[i][3];
    D_800506E8 = i;
    D_80063050[i] = fn;
    for (; k >= 0; k--) {
        *p-- = 0;
    }
}

void func_8003FAA0(void) {
    s32 i = D_800506E8;

    if (i >= 0) {
        if (D_80063050[i](D_80063010[i]) != 0) {
            D_800506E8--;
        }
    }
}

s32 func_8003FB0C(void) {
    return D_800506E8 >> 31;
}
__asm__(".word 0\n.word 0\n");

int func_8003FB24(void) {
    D_80063080 = 1;
    return 0;
}

extern volatile s32 D_80063084;
int func_8003FB38(void) {
    D_80063084 = 1;
    return 0;
}

extern volatile s32 D_80063088;
int func_8003FB4C(void) {
    D_80063088 = 1;
    return 0;
}

extern volatile s32 D_8006308C;
int func_8003FB60(void) {
    D_8006308C = 1;
    return 0;
}

extern volatile s32 D_80063090;
int func_8003FB74(void) {
    D_80063090 = 1;
    return 0;
}

extern volatile s32 D_80063094;
int func_8003FB88(void) {
    D_80063094 = 1;
    return 0;
}

extern volatile s32 D_80063098;
int func_8003FB9C(void) {
    D_80063098 = 1;
    return 0;
}

extern volatile s32 D_8006309C;
int func_8003FBB0(void) {
    D_8006309C = 1;
    return 0;
}

void func_8003FBC4(void) {
    func_8003D504();
    func_8003D594();
    func_8003D4F4();
}

void func_8003FBF4(void) {
    s32 s;

    s = func_80026FC4();
    D_80063060 = func_8003A1B4(0xF4000001, 4, 0x1000, (s32)func_8003FB24);
    D_80063064 = func_8003A1B4(0xF4000001, 0x8000, 0x1000, (s32)func_8003FB38);
    D_80063068 = func_8003A1B4(0xF4000001, 0x100, 0x1000, (s32)func_8003FB4C);
    D_8006306C = func_8003A1B4(0xF4000001, 0x2000, 0x1000, (s32)func_8003FB60);
    D_80063070 = func_8003A1B4(0xF0000011, 4, 0x1000, (s32)func_8003FB74);
    D_80063074 = func_8003A1B4(0xF0000011, 0x8000, 0x1000, (s32)func_8003FB88);
    D_80063078 = func_8003A1B4(0xF0000011, 0x100, 0x1000, (s32)func_8003FB9C);
    D_8006307C = func_8003A1B4(0xF0000011, 0x2000, 0x1000, (s32)func_8003FBB0);
    func_8003A1C4(D_80063060);
    func_8003A1C4(D_80063064);
    func_8003A1C4(D_80063068);
    func_8003A1C4(D_8006306C);
    func_8003A1C4(D_80063070);
    func_8003A1C4(D_80063074);
    func_8003A1C4(D_80063078);
    func_8003A1C4(D_8006307C);
    func_8003FEA4();
    if (s == 1) {
        func_80026FD4();
    }
}


void func_8003FDD0(void) { func_8003D5DC(); }

void func_8003FDF0(void) {
    s32 s = func_80026FC4();

    func_800401D4(D_80063060);
    func_800401D4(D_80063064);
    func_800401D4(D_80063068);
    func_800401D4(D_8006306C);
    func_800401D4(D_80063070);
    func_800401D4(D_80063074);
    func_800401D4(D_80063078);
    func_800401D4(D_8006307C);
    if (s == 1) {
        func_80026FD4();
    }
}

void func_8003FEA4(void) {
    func_8003C8B4(D_80063060);
    func_8003C8B4(D_80063064);
    func_8003C8B4(D_80063068);
    func_8003C8B4(D_8006306C);
    func_8003C8B4(D_80063070);
    func_8003C8B4(D_80063074);
    func_8003C8B4(D_80063078);
    func_8003C8B4(D_8006307C);
    D_80063080 = D_80063084 = D_80063088 = D_8006308C = 0;
    D_80063090 = D_80063094 = D_80063098 = D_8006309C = 0;
}

s32 func_8003FFAC(void) {
    s32 r;

    do {
        r = D_80063080 + D_80063084 * 2 + D_80063088 * 4 + D_8006308C * 8;
    } while (r == 0);
    func_8003C8B4(D_80063070);
    func_8003C8B4(D_80063074);
    func_8003C8B4(D_80063078);
    func_8003C8B4(D_8006307C);
    D_80063080 = D_80063084 = D_80063088 = D_8006308C = 0;
    return r >> 1;
}

s32 func_80040084(void) {
    s32 v;

    do {
        v = D_80063090 + D_80063094 * 2 + D_80063098 * 4 + D_8006309C * 8;
    } while (v == 0);
    func_8003C8B4(D_80063060);
    func_8003C8B4(D_80063064);
    func_8003C8B4(D_80063068);
    func_8003C8B4(D_8006306C);
    D_80063090 = D_80063094 = D_80063098 = D_8006309C = 0;
    return v >> 1;
}

s32 func_8004015C(void) {
    return D_80063080 + D_80063084 * 2 + D_80063088 * 4 + D_8006308C * 8;
}

s32 func_80040198(void) {
    return D_80063090 + D_80063094 * 2 + D_80063098 * 4 + D_8006309C * 8;
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800401D4);

static inline s32 mcWriteFrame401E4(s32 port, s32 blk) {
    s32 j = 0;
    u8 *p = D_800632E0;
    u8 c = 0;
    s32 k;
    s32 r;

    for (k = 0; k < 0x7F; k++) {
        c ^= *p++;
    }
    *p = c;
    do {
        func_8003FEA4();
        func_8003F9F4(port, blk, D_800632E0);
        r = func_80040084();
        if (r == 0) break;
        if (r == 4) {
            func_8003FEA4();
            func_8003F9B4(port);
            func_80040084();
        }
        j++;
    } while (j < 8);
    return r;
}

s32 func_800401E4(s32 a0) {
    s32 i;
    s32 r;
    s32 n = 0;
    u8 *buf;
    McDir401E4 *d;
    s32 *q;

    d = D_800630A0;
    for (i = 0; i < 15; i++, d++) {
        buf = D_800632E0;
        func_80027014(buf, 0x80);
        func_80027014((u8 *)d, 0x20);
        D_800630A0[i].field_0 = 0xA0;
        D_800630A0[i].field_4 = 0;
        D_800630A0[i].field_8 = 0xFFFF;
        do { *(McBlk20 *)buf = *(McBlk20 *)d; } while (0);
        r = mcWriteFrame401E4(a0, i + 1);
        if (r != 0) goto out;
    }
    q = D_80063280;
    for (i = 0; i < 20; i++, q++) {
        do { *q = -1; } while (0);
        buf = D_800632E0;
        func_80027014(buf, 0x80);
        do { *(McBlk4 *)buf = *(McBlk4 *)q; } while (0);
        r = mcWriteFrame401E4(a0, i + 0x10);
        if (r != 0) goto out;
    }
    buf = D_800632E0;
    func_80027014(buf, 0x80);
    {
        s32 j = 0;
        u8 c = 0;
        s32 k;
        s32 t;

        buf[0] = 'M';
        buf[1] = 'C';
        for (k = 0; k < 0x7F; k++) {
            c ^= *buf++;
        }
        *buf = c;
        do {
            func_8003FEA4();
            func_8003F9F4(a0, 0, D_800632E0);
            t = func_80040084();
            if (t == 0) break;
            if (t == 4) {
                func_8003FEA4();
                func_8003F9B4(a0);
                func_80040084();
            }
            j++;
        } while (j < 8);
        r = t;
    }
    if (r != 0) goto out;
    do {
        func_8003FEA4();
        func_8003F9A4(a0);
        r = func_8003FFAC();
        if (r == 0) return 0;
        n++;
        func_8003FEA4();
        func_8003F9B4(a0);
        func_80040084();
    } while (n < 8);
out:
    return r;
}


s32 func_800405B4(s32 port, s8 *name, s32 nblocks)
{
    s8 *nm;
    s32 nb;
    s32 free;
    s32 tries;
    s32 i;
    s32 r;
    u32 j;
    s32 prev;
    s32 k;
    u8 *p;
    u8 x;
    s32 ret;
    s8 *u;
    McDir401E4 *d;
    s32 blk;
    s32 n;
    s32 sz;
    s8 *np;

    nm = name;
    nb = nblocks;
    free = 0;
    tries = 0;
    func_80027014(D_800632E0, 0x80);
    i = 0;
    func_80027014(D_800632E0, 0x80);
    do {
        func_8003FEA4();
        func_80040CE4(port, 0, D_800632E0);
        r = func_80040084();
        if (r == 0) {
            break;
        }
        if (r == 4) {
            func_8003FEA4();
            func_8003F9B4(port);
            func_80040084();
        }
    } while (++i < 8);
    ret = r;
    i = 0;
    if (ret != 0) {
        return ret;
    }
    if (D_800632E0[0] != 'M') {
        return -2;
    }
    if (D_800632E0[1] != 'C') {
        return -2;
    }
    d = D_800630A0;
    blk = 1;
    for (i = 0; i < 15; d++, blk++) {
        D_800632D0[blk - 1] = 0;
        func_80027014(D_800632E0, 0x80);
        k = 0;
        func_80027014(D_800632E0, 0x80);
        do {
            func_8003FEA4();
            func_80040CE4(port, blk, D_800632E0);
            r = func_80040084();
            if (r == 0) {
                break;
            }
            if (r == 4) {
                func_8003FEA4();
                func_8003F9B4(port);
                func_80040084();
            }
        } while (++k < 8);
        ret = r;
        i++;
        if (ret != 0) {
            return ret;
        }
        do { *(McBlk20 *)d = *(McBlk20 *)D_800632E0; } while (0);
    }
    for (i = 0; i < 15; i++) {
        if (D_800630A0[i].field_0 == 0x51) {
            D_800632D0[i] = 1;
            j = i;
            while (D_800630A0[j].field_8 != 0xFFFF) {
                j = D_800630A0[j].field_8;
                if (j >= 15) {
                    break;
                }
                D_800632D0[j] = 1;
            }
        }
    }
    for (i = 0; i < 15; i++) {
        if (D_800632D0[i] == 0) {
            D_800630A0[i].field_0 = 0xA0;
        }
    }
    for (i = 0; i < 15; i++) {
        if (D_800630A0[i].field_0 == 0x51 && func_8003F924(D_800630A0[i].field_A, nm) == 0) {
            func_8002A014(D_80010D64, D_800630A0[i].field_A, nm);
            return -3;
        }
    }
    for (i = 0; i < 15; i++) {
        D_800632D0[i] = 0;
        if ((D_800630A0[i].field_0 & 0xF0) == 0xA0) {
            free++;
        }
    }
    if (free < nb) {
        return -1;
    }
    free = 0;
    prev = 0;
    sz = nb << 13;
    for (i = 0; i < 15; i++) {
        if ((D_800630A0[i].field_0 & 0xF0) == 0xA0) {
            if (free == 0) {
                D_800630A0[i].field_0 = 0x51;
                D_800630A0[i].field_4 = sz;
                func_80040C74((u8 *)D_800630A0[i].field_A, (u8 *)nm, 0x14);
                prev = i;
                D_800632D0[i] = 1;
            } else {
                D_800630A0[prev].field_8 = i;
                D_800630A0[i].field_0 = 0x52;
                prev = i;
                D_800632D0[i] = 1;
            }
            free++;
            if (free >= nb) {
                D_800630A0[i].field_8 = 0xFFFF;
                if (free >= 2) {
                    D_800630A0[i].field_0 = 0x53;
                }
                break;
            }
        }
    }
    d = &D_800630A0[14];
    for (i = 14; i >= 0; i--, d--) {
        if (D_800632D0[i] != 0) {
            func_80027014(D_800632E0, 0x80);
            do { *(McBlk20 *)D_800632E0 = *(McBlk20 *)d; } while (0);
            blk = i + 1;
            k = 0;
            p = D_800632E0;
            x = 0;
            n = 0x7E;
            do {
                x ^= *p++;
            } while (--n >= 0);
            *p = x;
            do {
                func_8003FEA4();
                func_8003F9F4(port, blk, D_800632E0);
                r = func_80040084();
                if (r == 0) {
                    break;
                }
                if (r == 4) {
                    func_8003FEA4();
                    func_8003F9B4(port);
                    func_80040084();
                }
            } while (++k < 8);
            ret = r;
            k = 0;
            if (ret != 0) {
                return ret;
            }
        }
    }
    do {
        func_8003FEA4();
        func_8003F9A4(port);
        r = func_8003FFAC();
        if (r == 0) {
            return 0;
        }
        func_8003FEA4();
        func_8003F9B4(port);
        func_80040084();
    } while (++tries < 8);
    return r;
}



u8 *func_80040C74(u8 *dst, u8 *src, s32 n) {
    u8 *r = 0;

    if (dst != 0 && src != 0) {
        s32 i;
        u8 *d = dst;
        s32 c;

        i = 0;
        if (n > 0) {
            do {
                c = *src++;
                *dst++ = c;
                if (c == 0) {
                    goto inc;
                body:
                    *dst++ = 0;
                inc:
                    i++;
                    if (i < n) goto body;
                    break;
                }
            } while (++i < n);
        }
        r = d;
    }
    return r;
}


INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80040CE4);
