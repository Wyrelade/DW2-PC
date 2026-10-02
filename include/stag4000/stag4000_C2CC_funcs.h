#ifndef STAG4000_C2CC_FUNCS_H
#define STAG4000_C2CC_FUNCS_H

/* Functions src/stag4000/stag4000_C2CC.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void func_8006F62C(Stg40TileWork *a0, s32 x, s32 y);
void func_8006F6BC(Stg40TileWork *w);
void func_8006FC54(ActorWork *w);
void func_8006FDAC(void);
void func_8006FDB4(Actor *a0);
void func_8006FE5C(Actor *a0);
void func_8006FE90(Actor *a0);
void func_8006FED4(void);
void func_8006FF28(void);
u16 func_8006FF54(u16 *pal, u32 *bits, s32 x, s32 y);
u16 func_800703E0(s32 x, s32 y);
Stg40Cell *func_80070438(s32 x, s32 y);
void func_80070490(s32 buf, s32 p1, s32 x, s32 y, s32 fill);
s32 func_800706C8(void);
void func_80070754(void);
void func_800707D0(void);
Stg40Cell *func_800708A4(s32 x, s32 y);
void func_800708FC(s32 x, s32 y, s32 flag);
void func_80070974(s32 x, s32 y);
void func_800709DC(void);
void func_80070A7C(void);
s16 *func_80070AD0(s16 v);
void func_80070B2C(s32 v);
void func_80070BA4(s16 v);
s16 func_80070C48(void);
s16 func_80070C94(void);
void func_80070CC0(s32 id);
void func_80070D74(void);
void func_80070DC0(void);
void func_80070EC0(u32 *p, u32 n);
s32 func_80070EE0(s32 *p);
s32 func_80070FEC(Stg40Pick *out, Stg40Rec3 *e, u8 key);
void func_8007107C(void);
s32 func_80071180(void);
s32 func_800711C4(s32 n);
s32 func_80071204(s32 i);
s32 func_80071258(s32 i);
s32 func_80071294(void);
void func_80071310(s32 a0, s32 a1);
void func_8007142C(s32 a0, s32 a1);
s32 func_800715DC(void);
s32 func_80071608(void);
void func_80071DB4(void);
Stg40Ent48 *func_80071F50(s32 id);
void func_80071FBC(s32 *arg);
void func_800720EC(void);
s16 func_800720FC(void);
s32 func_80072114(void);
void func_8007212C(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);
void func_800721A8(Stg40Cmd *src);
void func_80072250(Actor *a0);
void func_800722B8(Actor *task);
void func_80072418(Actor *a0, Block1C *a1);
void func_80072468(Actor *a0);
void func_800725A8(void);

#endif /* STAG4000_C2CC_FUNCS_H */
