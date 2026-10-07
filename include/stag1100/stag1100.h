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

/* Save/load work area of the task held in Stg11_CardTask (Actor.work). */
typedef struct {
    /* 0x00 */ s32 port;
    /* 0x04 */ s32 result;
    /* 0x08 */ s32 retryCount;
    /* 0x0C */ u8 fileName[0x15];
    /* 0x21 */ u8 isTransferFile;
    u8 _pad22[0x02];
    /* 0x24 */ s32 portResult[2][2];
    union {
        /* 0x34 */ u16 sum[0x2000];
        /* memory card block header + data */
        struct Stg11CardBlock {
            /* 0x34 */ u8 magic[2];
            /* 0x36 */ u8 iconFlag;
            /* 0x37 */ u8 blocks;
            /* 0x38 */ u8 title[0x40];
            /* 0x78 */ u8 reserved[0x1C];
            /* 0x94 */ Stg11Clut clut;
            /* 0xB4 */ Stg11Icon icons[3];
            /* 0x234 */ u8 data[0x3DFC];
            /* 0x4030 */ u16 version;
            /* 0x4032 */ u16 checksum;
        } s;
    } u34;
    /* 0x4034 */ u8 transferBuf[0x1E000];
    /* 0x22034 */ s32 curOp;
    /* 0x22038 */ s32 progressTotal;
    /* 0x2203C */ s32 progressDone;
    /* 0x22040 */ s32 opStarted;
} Stg11SaveWork;

/* Save slot list pointed to by Stg11MenuWork.field_90. */
typedef struct {
    /* 0x00 */ s32 used[3];
    /* 0x0C */ GameState slots[3];
} Stg11SaveList;



/* Task work passed as the second argument of the menu handlers (Actor.work of the menu task). */
/* Five 0x20-byte party rows in Stg11MenuWork at 0x98, built from a
   Stg11CardRec by Stg11_ConvertCardDigi. */
typedef struct {
    /* 0x00 */ s16 digiId;
    /* 0x02 */ s16 transferState;
    /* 0x04 */ s16 skillCount;
    /* 0x06 */ u8 skills[8];
    /* 0x0E */ u8 level;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 hp;
    /* 0x16 */ s16 mp;
    /* 0x18 */ s16 attack;
    /* 0x1A */ s16 defense;
    /* 0x1C */ s16 speed;
    /* 0x1E */ u16 uid;
} Stg11MenuRow; /* size 0x20 */

/* 0x100-byte digimon record stored in the save work card area
   (Stg11_CardGetTransferBuf() area + 0x1D880, five records). */
typedef struct {
    /* 0x00 */ u8 bytes[0x80];
    /* 0x80 */ u32 field_80;
    u8 _pad84[0xC];
    /* 0x90 */ u16 uid;
    /* 0x92 */ u16 hp;
    u8 _pad94[0x2];
    /* 0x96 */ u16 mp;
    u8 _pad98[0x2];
    /* 0x9A */ u16 attack;
    /* 0x9C */ u16 defense;
    u8 _pad9E[0x2];
    /* 0xA0 */ u16 speed;
    /* 0xA2 */ u16 speciesId;
    u8 _padA4[0x19];
    /* 0xBD */ u8 field_BD;
    u8 _padBE[0xB];
    /* 0xC9 */ u8 skillCount;
    /* 0xCA */ u8 skills[0x36];
} Stg11CardRec; /* size 0x100 */

/* View of the Stg11_CardGetTransferBuf() area holding the card records. */
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
    /* 0x0A */ s16 speedMax;
} Stg11SpeciesRec;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 promptText;
    /* 0x08 */ s32 statusText;
    /* 0x0C */ s32 transferCountText;
    /* 0x10 */ s32 slotTexts[9];
    u8 _pad34[0x04];
    /* 0x38 */ s32 transferTexts[11];
    u8 _pad64[0x04];
    /* 0x68 */ s16 cursor[2];
    /* 0x6C */ union {
        Layout8C layout;
        s16 gridSize[2];
    } u6C;
    /* 0x78 */ s16 menuKind;
    /* 0x7A */ s16 isLoad;
    /* 0x7C */ s16 isVsLoad;
    /* 0x7E */ s16 padIndex;
    /* 0x80 */ s16 isTransfer;
    u8 _pad82[0x02];
    /* 0x84 */ s16 cardPort;
    /* 0x86 */ s16 listMode;
    /* 0x88 */ s16 pendingPromptMsg;
    u8 _pad8A[0x02];
    /* 0x8C */ s32 fade;
    /* 0x90 */ Stg11SaveList *saveList;
    /* 0x94 */ s16 progressMode;
    /* 0x96 */ s16 progress;
    /* 0x98 */ Stg11MenuRow transferRows[5];
    /* 0x138 */ s16 transferRemaining;
} Stg11MenuWork;

/* Work of the stage root task (Stg11_ModeMenuUpdate). */
typedef struct {
    /* 0x00 */ s32 texts[4];
    /* 0x10 */ s16 cursor[2];
    /* 0x14 */ union {
        Layout8C layout;
        s16 gridSize[2];
    } menu;
    /* 0x20 */ s16 mode;
    u8 _pad22[0x02];
    /* 0x24 */ s16 padIndex;
    u8 _pad26[0x02];
    /* 0x28 */ s32 fade;
} Stg11ModeMenuWork;

/* Per-cell task launch entry (Cd_GetFileEntrySubPtr(0xD280003, ...)). */
typedef struct {
    /* 0x0 */ s16 id;
    /* 0x2 */ s16 arg;
} Stg11TaskEntry;

/* Party-select slot (stride 8) in Stg11VsPartyWork. */
typedef struct {
    /* 0x0 */ u8 kind;
    u8 _pad1[0x1];
    /* 0x2 */ u8 rowState;
    u8 _pad3[0x1];
    /* 0x4 */ DigiRosterEntry *entry;
} Stg11Slot;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Stg11Pos;

/* Work of the party-select list task (Stg11_VsPartyUpdate, drawn by Stg11_VsPartyDraw). */
typedef struct {
    /* 0x00 */ s32 texts[0x14];
    /* 0x50 */ Stg11Pos cursor;
    /* 0x54 */ union {
        Layout8C layout;
        s16 grid[6];
    } menu;
    /* 0x60 */ s16 kind;
    u8 _pad62[0x02];
    /* 0x64 */ s16 padIndex;
    /* 0x66 */ s16 scrollTop;
    /* 0x68 */ s16 isRosterList;
    /* 0x6A */ s16 rosterCount;
    /* 0x6C */ Stg11Slot rows[0x26];
    /* 0x19C */ s32 scale;
    /* 0x1A0 */ s16 pickCount;
    /* 0x1A2 */ s16 pickedRows[3];
} Stg11VsPartyWork;

/* Stg11_VsParty: a save's GameState pointer followed by the three chosen party entries. */
typedef struct {
    /* 0x00 */ GameState *gameState;
    /* 0x04 */ DigiRosterEntry members[3];
    u8 _pad118[0x08];
} Stg11Party;

/* Memory card icon image: CLUT then the first icon frame. The three icon frames are
   TIM files (16x16 4bpp with CLUT, 0xC0 bytes each) linked into .data with INCLUDE_BIN;
   the code refers to the CLUT block of the first (from its CLUT data on, this struct)
   and to the pixels of the other two (DATA_LABEL in card.c). */
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

extern PadState Pad_State[];
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
extern u8 *strcpy(u8 *dst, const u8 *src);

extern Halves Stg11_PromptPos;
extern Halves Stg11_StatusPos;
/* .bss of each file, in retail order (cc1 lays tentative definitions out in the order of
 * their first declaration). STAG1100.PRO carries its .bss in the file, after all .data. */
extern Stg11Party Stg11_VsParty;
extern s16 Stg11_LoadDone;
extern Actor *Stg11_CardTask;
extern Stg11SaveWork *Stg11_CardWork;

s32 Stg11_CardGetResult(void);
void Stg11_CardStartOp(u8 arg0, s32 arg1);

extern void Task_NextState2(Actor *arg0);
extern void Task_SetState2(Actor *arg0, u32 arg1);
extern s32 Text_WaitYesNo(s32 arg0);
extern const u8 Stg11_TransferFileName[];
extern const u8 Stg11_SaveFileName[];
void Stg11_SetStatusMsg(Stg11MenuWork *arg0, s32 arg1);
void Stg11_CloseSlotText(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_SetPromptMsg(Stg11MenuWork *arg0, s32 arg1, s32 arg2);
s32 Stg11_WatchCardRemoved(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_ScanTransferCards(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_OpenTransferText(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_TransferSelected(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_CardSetFileName(const u8 *arg0, u8 arg1);
u8 *Stg11_CardGetDataBuf(void);
u8 *Stg11_CardGetTransferBuf(void);
void Stg11_CardSetTitle(const u8 *arg0);
s32 Stg11_CardGetProgress(s32 arg0);
s32 Stg11_CardChecksum(Stg11SaveWork *arg0);
void Stg11_CardInitHeader(void);
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
extern SysState Sys_State;
extern s16 Sys_VsPartyConfirmed;
extern Halves Stg11_TransferCountPos;
s32 Stg11_CardAsyncOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
s32 Stg11_CardFileOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gfx_DrawParts(s32 arg0);
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1);
extern s32 Menu_MoveGridCursor(s32 a0, s32 a1, s32 a2);
typedef struct {
    /* 0x0 */ s32 bgmStarted;
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
extern GameState *Save_GameStatePtr;
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern s32 Math_RampToOne(s32 arg0, s32 *arg1);
extern s32 Math_RampToZero(s32 arg0, s32 *arg1);
extern s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1);
extern s32 Text_PrintIdList(s32 *a0, TextIdListEntry *a1, u32 a2);
extern void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3);
extern void Text_SetInputPad(s32 a0, s32 a1);
extern s32 Digi_GetRank(s32 id);
extern u8 Digi_GetLearnedSkill(s32 id);
extern s32 Digi_CalcMaxLevel(s32 x);
extern u16 Stg11_VsRowMasks[];
extern TaskDesc Stg11_RootDesc;
extern TaskDesc Stg11_BgDesc;
extern TaskDesc Stg11_ModeMenuDesc;
extern TaskDesc Stg11_CardMenuDesc;
extern TaskDesc Stg11_VsPartyDesc;
extern TaskDesc Stg11_CardTaskDesc;
extern TaskDesc *Stg11_TaskDescs[];
extern Stg11IconImage Stg11_CardIconImage;
extern Stg11Icon Stg11_CardIcon2;
extern Stg11Icon Stg11_CardIcon3;
extern const u8 Stg11_CardTitle[32];
extern Halves Stg11_ModeHelpPos;
extern Layout8C Stg11_VsPartyLayout;
extern Halves Stg11_VsPromptPos;
extern Halves D_80068208;


#endif
