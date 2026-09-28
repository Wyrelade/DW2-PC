#ifndef STAG1100_H
#define STAG1100_H

#include "common.h"
#include "main/156C.h"

/* STAG1100 (Ovl_FileIds id 5, gameMode 0x6xx): save and menu tasks. */

/* 16-colour CLUT and 16x16 4bpp icon frame of a memory card header. */
typedef struct {
    u8 data[0x20];
} Stg11Clut;

typedef struct {
    u8 data[0x80];
} Stg11Icon;

/* Save/load work area of the task held in D_800685D0 (Actor.work). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u8 field_C[0x15];
    /* 0x21 */ u8 field_21;
    u8 _pad22[0x02];
    /* 0x24 */ s32 field_24[2][2];
    union {
        /* 0x34 */ u16 sum[0x2000];
        /* memory card block header + data */
        struct Stg11CardBlock {
            /* 0x34 */ u8 magic[2];
            /* 0x36 */ u8 iconFlag;
            /* 0x37 */ u8 blocks;
            /* 0x38 */ u8 field_38[0x40];
            /* 0x78 */ u8 field_78[0x1C];
            /* 0x94 */ Stg11Clut clut;
            /* 0xB4 */ Stg11Icon icons[3];
            /* 0x234 */ u8 field_234[0x3DFC];
            /* 0x4030 */ u16 field_4030;
            /* 0x4032 */ u16 field_4032;
        } s;
    } u34;
    /* 0x4034 */ u8 field_4034[0x1E000];
    /* 0x22034 */ s32 field_22034;
    /* 0x22038 */ s32 field_22038;
    /* 0x2203C */ s32 field_2203C;
    /* 0x22040 */ s32 field_22040;
} Stg11SaveWork;

/* One save slot image (stride 0x1058): a GameStateView copy plus trailer. */
typedef struct {
    union {
        /* 0x000 */ GameStateView gs;
        struct {
            u8 _pad0[0x4];
            /* 0x004 */ u32 playTime;
            /* 0x008 */ s32 money;
        } hdr;
    } u;
    u8 _padFD4[0x84];
} Stg11SaveSlot; /* size 0x1058 */

/* Save slot list pointed to by Stg11MenuWork.field_90. */
typedef struct {
    /* 0x00 */ s32 used[3];
    /* 0x0C */ Stg11SaveSlot slots[3];
} Stg11SaveList;

/* Roster entry view (DigiRosterEntry layout) with the skill bytes at 0x22
   and the 0x49/0x4A fields spelled out. */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0xB];
    /* 0x0D */ u8 level;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 exp;
    /* 0x14 */ u16 maxHp;
    /* 0x16 */ u16 hp;
    /* 0x18 */ u16 maxMp;
    /* 0x1A */ u16 mp;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ u16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 skills[0x27];
    /* 0x49 */ u8 field_49;
    /* 0x4A */ u16 field_4A;
    /* 0x4C */ u8 name[14];
    u8 _pad5A[0x2];
} Stg11DigiEntry; /* size 0x5C */

/* D_80050720 viewed with Stg11DigiEntry roster entries. */
typedef struct {
    u8 _pad00[0xE4];
    /* 0xE4 */ Stg11DigiEntry elems[0x24];
} Stg11GameState;

/* Task work passed as the second argument of the menu handlers (Actor.work of the menu task). */
/* Five 0x20-byte party rows in Stg11MenuWork at 0x98, built from a
   Stg11CardRec by func_80063D28. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 skillCount;
    /* 0x06 */ u8 skills[8];
    /* 0x0E */ u8 level;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 hp;
    /* 0x16 */ s16 mp;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ u16 field_1E;
} Stg11MenuRow; /* size 0x20 */

/* 0x100-byte digimon record stored in the save work card area
   (func_8006770C() area + 0x1D880, five records). */
typedef struct {
    /* 0x00 */ u8 bytes[0x80];
    /* 0x80 */ u32 field_80;
    u8 _pad84[0xC];
    /* 0x90 */ u16 uid;
    /* 0x92 */ u16 field_92;
    u8 _pad94[0x2];
    /* 0x96 */ u16 field_96;
    u8 _pad98[0x2];
    /* 0x9A */ u16 field_9A;
    /* 0x9C */ u16 field_9C;
    u8 _pad9E[0x2];
    /* 0xA0 */ u16 field_A0;
    /* 0xA2 */ u16 field_A2;
    u8 _padA4[0x19];
    /* 0xBD */ u8 field_BD;
    u8 _padBE[0xB];
    /* 0xC9 */ u8 skillCount;
    /* 0xCA */ u8 skills[0x36];
} Stg11CardRec; /* size 0x100 */

/* View of the func_8006770C() area holding the card records. */
typedef struct {
    u8 _pad0[0x1D880];
    /* 0x1D880 */ Stg11CardRec cards[5];
} Stg11CardArea;

/* 12-byte per-species stat record (Cd_GetFileEntry(0xD280010)). */
typedef struct {
    /* 0x00 */ u8 level;
    u8 _pad1;
    /* 0x02 */ s16 exp;
    /* 0x04 */ s16 base;
    /* 0x06 */ s16 hpMax;
    /* 0x08 */ s16 statMax;
    /* 0x0A */ s16 field_A;
} Stg11SpeciesRec;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10[9];
    u8 _pad34[0x04];
    /* 0x38 */ s32 field_38[11];
    u8 _pad64[0x04];
    /* 0x68 */ s16 cursor[2];
    /* 0x6C */ union {
        Layout8C layout;
        s16 gridSize[2];
    } u6C;
    /* 0x78 */ s16 field_78;
    /* 0x7A */ s16 field_7A;
    /* 0x7C */ s16 field_7C;
    /* 0x7E */ s16 field_7E;
    /* 0x80 */ s16 field_80;
    u8 _pad82[0x02];
    /* 0x84 */ s16 field_84;
    /* 0x86 */ s16 field_86;
    /* 0x88 */ s16 field_88;
    u8 _pad8A[0x02];
    /* 0x8C */ s32 field_8C;
    /* 0x90 */ Stg11SaveList *field_90;
    /* 0x94 */ s16 field_94;
    /* 0x96 */ s16 field_96;
    /* 0x98 */ Stg11MenuRow field_98[5];
    /* 0x138 */ s16 field_138;
} Stg11MenuWork;

/* Work of the stage root task (func_800638BC). */
typedef struct {
    /* 0x00 */ s32 texts[4];
    /* 0x10 */ s16 field_10[2];
    /* 0x14 */ union {
        Layout8C layout;
        s16 gridSize[2];
    } field_14;
    /* 0x20 */ s16 field_20;
    u8 _pad22[0x02];
    /* 0x24 */ s16 field_24;
    u8 _pad26[0x02];
    /* 0x28 */ s32 field_28;
} Stg11Work63894;

/* Per-cell task launch entry (Cd_GetFileEntrySubPtr(0xD280003, ...)). */
typedef struct {
    /* 0x0 */ s16 id;
    /* 0x2 */ s16 arg;
} Stg11TaskEntry;

/* Party-select slot (stride 8) in Stg11Work66C04. */
typedef struct {
    /* 0x0 */ u8 field_0;
    u8 _pad1[0x1];
    /* 0x2 */ u8 field_2;
    u8 _pad3[0x1];
    /* 0x4 */ DigiRosterEntry *field_4;
} Stg11Slot;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Stg11Pos;

/* Work of the party-select list task (func_80066C48, drawn by func_80067124). */
typedef struct {
    /* 0x00 */ s32 field_0[0x14];
    /* 0x50 */ Stg11Pos field_50;
    /* 0x54 */ union {
        Layout8C layout;
        s16 grid[6];
    } field_54;
    /* 0x60 */ s16 field_60;
    u8 _pad62[0x02];
    /* 0x64 */ s16 field_64;
    /* 0x66 */ s16 field_66;
    /* 0x68 */ s16 field_68;
    /* 0x6A */ s16 field_6A;
    /* 0x6C */ Stg11Slot field_6C[0x26];
    /* 0x19C */ s32 scale;
    /* 0x1A0 */ s16 field_1A0;
    /* 0x1A2 */ s16 field_1A2[3];
} Stg11Work66C04;

/* D_800684A8: a save's GameState pointer followed by the three chosen party entries. */
typedef struct {
    /* 0x00 */ GameStateView *field_0;
    /* 0x04 */ DigiRosterEntry field_4[3];
    u8 _pad118[0x08];
} Stg11Party;

/* Memory card icon image: CLUT then the first icon frame. */
typedef struct {
    /* 0x00 */ Stg11Clut clut;
    u8 _pad20[0xC];
    /* 0x2C */ Stg11Icon icon;
} Stg11IconImage;

/* PsyQ POLY_G4 packet. */
typedef struct {
    /* 0x00 */ union {
        u32 word;
        struct {
            u8 addr[3];
            u8 len;
        } b;
    } tag;
    /* 0x04 */ u8 r0;
    /* 0x05 */ u8 g0;
    /* 0x06 */ u8 b0;
    /* 0x07 */ u8 code;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ u8 r1;
    /* 0x0D */ u8 g1;
    /* 0x0E */ u8 b1;
    u8 _pad0F;
    /* 0x10 */ s16 x1;
    /* 0x12 */ s16 y1;
    /* 0x14 */ u8 r2;
    /* 0x15 */ u8 g2;
    /* 0x16 */ u8 b2;
    u8 _pad17;
    /* 0x18 */ s16 x2;
    /* 0x1A */ s16 y2;
    /* 0x1C */ u8 r3;
    /* 0x1D */ u8 g3;
    /* 0x1E */ u8 b3;
    u8 _pad1F;
    /* 0x20 */ s16 x3;
    /* 0x22 */ s16 y3;
} Stg11PolyG4; /* size 0x24 */

extern PadState D_8005F6F0[];
extern void Snd_PlayById(s32, s32);
extern void Text_Close(s32 *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 Text_IsFinished(s32 id);
extern void Text_OpenDesc(void *arg0, TextDesc *arg1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Task_NextState0(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern u8 *memset(u8 *s, s32 c, s32 n);
extern u8 *strcpy(u8 *dst, u8 *src);

extern Halves D_800681D4;
extern Halves D_800681D8;
extern s16 D_800685C8;
extern Actor *D_800685D0;
extern Stg11SaveWork *D_800685D4;
extern Stg11Party D_800684A8;

s32 func_80067818(void);
void func_800677AC(u8 arg0, s32 arg1);

extern void Task_NextState2(Actor *arg0);
extern void Task_SetState2(Actor *arg0, u32 arg1);
extern s32 func_800136A4(s32 arg0);
extern u8 D_80063454[];
extern u8 D_80063464[];
void func_800648E4(Stg11MenuWork *arg0, s32 arg1);
void func_800648B4(Actor *arg0, Stg11MenuWork *arg1);
void func_8006495C(Stg11MenuWork *arg0, s32 arg1, s32 arg2);
s32 func_800649F8(Actor *arg0, Stg11MenuWork *arg1);
void func_80064000(Actor *arg0, Stg11MenuWork *arg1);
void func_80064304(Actor *arg0, Stg11MenuWork *arg1);
void func_8006448C(Actor *arg0, Stg11MenuWork *arg1);
void func_80067838(u8 *arg0, u8 arg1);
u8 *func_800676F4(void);
u8 *func_8006770C(void);
void func_80067724(u8 *arg0);
s32 func_80067880(s32 arg0);
s32 func_800678F0(Stg11SaveWork *arg0);
void func_800673FC(void);
extern u8 *Digi_GetDefaultName(s32);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeOutToBlack(s32);
extern void Task_Create(u32, s32 *, s32);
extern void Snd_StopAll(void);
extern void Snd_UnloadSlot(s32);
extern void Snd_SetSlotContent(s32, s32);
extern s32 Snd_AnySlotLoading(void);
extern void Task_NextState1(Actor *arg0);
extern SysState D_8005F770;
extern s16 D_80050780;
extern Halves D_800681DC;
s32 func_80067B54(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
s32 func_80067938(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gfx_DrawParts(void *);
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1);
extern s32 Menu_MoveGridCursor(s16 *cursor, s16 *gridSize, s32 pad);
typedef struct {
    /* 0x0 */ s32 field_0;
} Stg11MainWork;

extern s32 MemCardSync(s32 wait, s32 *a1, s32 *a2);
extern s32 MemCardOpen(s32 a0, s32 a1, s32 a2);
extern s32 MemCardCreateFile(s32 a0, s32 a1, s32 a2);
extern s32 MemCardFormat(s32 chan);
extern s32 MemCardExist(s32 arg0);
extern s32 MemCardAccept(s32 arg0);
extern s32 MemCardReadFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 MemCardWriteFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void Card_CloseFile(void);
extern GameStateView *D_80050720;
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern s32 Math_RampToOne(Actor *arg0, s32 *arg1);
extern s32 Math_RampToZero(Actor *arg0, s32 *arg1);
extern s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1);
extern s32 Text_PrintIdList(s32 *a0, TextIdListEntry *a1, u32 a2);
extern void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3);
extern void Text_SetInputPad(s32 a0, s32 a1);
extern s32 func_8001D958(s32 id);
extern u8 func_8001D9A8(s32 id);
extern s32 func_8001EB58(s32 x);
extern u16 D_8006820C[];
extern Stg11IconImage D_80068244;
extern Stg11Icon D_80068330;
extern Stg11Icon D_800683F0;
extern u8 D_800634C4[];
extern Halves D_800681B8;
extern Layout8C D_800681F8;
extern Halves D_80068204;
extern Halves D_80068208;


#endif
