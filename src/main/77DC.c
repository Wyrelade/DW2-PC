#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/6530.h"

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches them with %gp_rel here. */
Halves Menu_DigiMsgPos = { 0x10, 0xBA };
Halves Menu_DigiListCursorTextPos = { 0x21, 0x9E };
Halves Menu_SkillMsgPos = { 0x10, 0xBA };
s32 Snd_CurrentId = -1;
s32 Snd_SavedId;
/* .bss (game.h order) */
u8 Snd_SeqAttrTable[176 * 6 * 16];
SndSlot Snd_Slots[3];
TextStack Text_ReturnStack;
/* The two ordering tables. Gpu_OtBufEnds is the symbol for the second one (code reads
 * Gpu_OtBufEnds[i] as the end of table i). */
GpuOtBuf Gpu_OtBufs[2];
DATA_LABEL(Gpu_OtBufEnds, Gpu_OtBufs, 0x4030);
/* OT layout mode (index into Gpu_OtLayerLens); code reads it as Gpu_OtBufs[2].entries[0]. */
s32 D_8005CD58[2];
GfxTexSlot Gfx_TexSlots[0x40];

/* Task callbacks the descriptors below name (defined further down; the digi list descriptor's
 * draw and the item draw at the top of this file). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_SetDigiListMode(Actor *a, s16 mode);
void Menu_DigiListTask(Actor *a0);
void Menu_DigiListDraw(Actor *actor);
void Menu_DigiStatusInit(Actor *a0, s16 a1);
void Menu_DigiStatusTask(Actor *a);
void Menu_DigiStatusDraw(Actor *actor);
void Menu_SkillListInit(Actor *arg0, s16 arg1);
void Menu_SkillListTask(Actor *a0);
void Menu_SkillListDraw(Actor *actor);
void Task_SpawnListInit(Actor *arg0, s32 *arg1);
void Task_SpawnListFromFile(Actor *a0);
void Text_WinFrameInit(Actor *arg0, s32 arg1);
void Text_WinFrameTask(Actor *a0);
void Text_WinFrameDraw(Actor *arg0);
void Text_LoadFontsTask(Actor *a0);
void Text_UpdateAllBoxes(Actor *a0);

MenuGridLayout Menu_DigiListGrid = { { 1, 1 }, { -60, -66, 0, 0x21 } };
/* Sub tasks the digimon list opens: { task id, Task_Create argument }. */
Pair61900 Menu_DigiListSubTasks[] = { { 0x11, 1 }, { 0x12, 1 }, { 0x10, 6 }, { 0x10, 8 } };
Halves Menu_DigiListTitlePos[] = { { 0x0E, 0x32 }, { 0x15, 0x32 } };
u16 Menu_DigiListRowMasks[] = { 0x0E04, 0x0E04, 0x0C04, 0x0A04, 0x0604 };
TaskDesc D_80040F4C = {
    (TaskInitFn)Menu_SetDigiListMode, Menu_DigiListTask, Task_DefaultDestroy, Menu_DigiListDraw, 0x1A8, 4,
};
Prm1C Menu_DigiStatusView = { { 0, -0x180, -0x1E00, 0, 0, 0, 0x230 } };
TaskDesc D_80040F80 = {
    (TaskInitFn)Menu_DigiStatusInit, Menu_DigiStatusTask, Task_DefaultDestroy, Menu_DigiStatusDraw, 0x150, 4,
};
u16 Menu_SkillPaneMasks[] = { 0xAC, 0xCA, 0xB2, 0x12A };
TaskDesc D_80040FA0 = {
    (TaskInitFn)Menu_SkillListInit, Menu_SkillListTask, Task_DefaultDestroy, Menu_SkillListDraw, 0x128, 4,
};
TaskDesc D_80040FB8 = {
    (TaskInitFn)Task_SpawnListInit, Task_SpawnListFromFile, Task_DefaultDestroy, 0, 4, 0xA0,
};
/* Window frame part resources (Cd_GetFileEntry ids). */
s32 Text_WinFrameParts[] = { 0x03120001, 0x03120003, 0x03120000, 0x03120004 };
TaskDesc D_80040FE0 = {
    (TaskInitFn)Text_WinFrameInit, Text_WinFrameTask, Task_DefaultDestroy, Text_WinFrameDraw, 2, 0,
};

/* Sound banks (SndBankDesc): VB file, VH file, then the SEQ/SEP entries, 0-ended. Each entry
 * is (resource file id << 16) | sub-entry index. */
u32 D_80040FF8[] = { 0x00E50000, 0x00E60000, 0x00E60001, 0x00E60002, 0x00E60003, 0x00E60004, 0x00000000 };
u32 D_80041014[] = { 0x07BE0000, 0x07BF0000, 0x07BF0001, 0x00000000 };
u32 D_80041024[] = { 0x07C00000, 0x07C10000, 0x07C10001, 0x00000000 };
u32 D_80041034[] = { 0x07C20000, 0x07C30000, 0x07C30001, 0x00000000 };
u32 D_80041044[] = { 0x07C40000, 0x07C50000, 0x07C50001, 0x00000000 };
u32 D_80041054[] = { 0x07C60000, 0x07C70000, 0x07C70001, 0x00000000 };
u32 D_80041064[] = { 0x07C80000, 0x07C90000, 0x07C90001, 0x00000000 };
u32 D_80041074[] = { 0x07CA0000, 0x07CB0000, 0x07CB0001, 0x00000000 };
u32 D_80041084[] = { 0x07CC0000, 0x07CD0000, 0x07CD0001, 0x00000000 };
u32 D_80041094[] = { 0x07CE0000, 0x07CF0000, 0x07CF0001, 0x00000000 };
u32 D_800410A4[] = { 0x07D00000, 0x07D10000, 0x07D10001, 0x00000000 };
u32 D_800410B4[] = { 0x07D20000, 0x07D30000, 0x07D30001, 0x00000000 };
u32 D_800410C4[] = { 0x0D180000, 0x0D190000, 0x0D190001, 0x00000000 };
u32 D_800410D4[] = { 0x0E330000, 0x0E350000, 0x0E350001, 0x00000000 };
u32 D_800410E4[] = { 0x0D1C0000, 0x0D1D0000, 0x0D1D0001, 0x00000000 };
u32 D_800410F4[] = { 0x00E30000, 0x00E40000, 0x00E40001, 0x00000000 };
u32 D_80041104[] = { 0x02670000, 0x02680000, 0x02680001, 0x00000000 };
u32 D_80041114[] = { 0x02DD0000, 0x02DE0000, 0x02DE0001, 0x00000000 };
u32 D_80041124[] = { 0x02DF0000, 0x02E00000, 0x02E00001, 0x00000000 };
u32 D_80041134[] = { 0x02E90000, 0x02EA0000, 0x02EA0001, 0x00000000 };
u32 D_80041144[] = { 0x02EB0000, 0x02EC0000, 0x02EC0001, 0x00000000 };
u32 D_80041154[] = { 0x02ED0000, 0x02EE0000, 0x02EE0001, 0x00000000 };
u32 D_80041164[] = { 0x02EF0000, 0x02F00000, 0x02F00001, 0x00000000 };
u32 D_80041174[] = { 0x0D4A0000, 0x0D4B0000, 0x0D4B0001, 0x00000000 };
u32 D_80041184[] = { 0x07BD0000, 0x07BC0000, 0x07BC0001, 0x00000000 };
SndBankDesc *Snd_BankDescs[] = {
    0,
    (SndBankDesc *)D_80040FF8, (SndBankDesc *)D_80041014, (SndBankDesc *)D_80041024,
    (SndBankDesc *)D_80041034, (SndBankDesc *)D_80041044, (SndBankDesc *)D_80041054,
    (SndBankDesc *)D_80041064, (SndBankDesc *)D_80041074, (SndBankDesc *)D_80041084,
    (SndBankDesc *)D_80041094, (SndBankDesc *)D_800410A4, (SndBankDesc *)D_800410B4,
    (SndBankDesc *)D_800410C4, (SndBankDesc *)D_800410D4, (SndBankDesc *)D_800410E4,
    (SndBankDesc *)D_800410F4, (SndBankDesc *)D_80041104, (SndBankDesc *)D_80041114,
    (SndBankDesc *)D_80041124, (SndBankDesc *)D_80041134, (SndBankDesc *)D_80041144,
    (SndBankDesc *)D_80041154, (SndBankDesc *)D_80041164, (SndBankDesc *)D_80041174,
    (SndBankDesc *)D_80041184,
};
s32 Snd_SlotBufSizes[3] = { 0x114D0, 0x13FE4, 0xBF44 };

/* Text dictionary: words the text engine substitutes for codes 6.. (glyph codes, 0xFF ends). */
u8 D_80041208[] = { 0x0D, 0x2C, 0x2A, 0x2C, 0x30, 0x32, 0x31, 0xFF }; /* "Digimon" */
u8 D_80041210[] = { 0x3C, 0x32, 0x38, 0xFF }; /* "you" */
u8 D_80041214[] = { 0x37, 0x2B, 0x28, 0xFF }; /* "the" */
u8 D_80041218[] = { 0x0D, 0x2C, 0x2A, 0x2C, 0x49, 0x0B, 0x28, 0x28, 0x37, 0x2F, 0x28, 0xFF }; /* "Digi-Beetle" */
u8 D_80041224[] = { 0x0D, 0x32, 0x30, 0x24, 0x2C, 0x31, 0xFF }; /* "Domain" */
u8 D_8004122C[] = { 0x10, 0x38, 0x24, 0x35, 0x27, 0xFF }; /* "Guard" */
u8 D_80041234[] = { 0x1D, 0x24, 0x30, 0x28, 0x35, 0xFF }; /* "Tamer" */
u8 D_8004123C[] = { 0x2B, 0x28, 0x35, 0x28, 0xFF }; /* "here" */
u8 D_80041244[] = { 0x2B, 0x24, 0x39, 0x28, 0xFF }; /* "have" */
u8 D_8004124C[] = { 0x14, 0x31, 0x2C, 0x2A, 0x2B, 0x37, 0x36, 0xFF }; /* "Knights" */
u8 D_80041254[] = { 0x24, 0x31, 0x27, 0xFF }; /* "and" */
u8 D_80041258[] = { 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "thing" */
u8 D_80041260[] = { 0x1C, 0x28, 0x26, 0x38, 0x35, 0x2C, 0x37, 0x3C, 0xFF }; /* "Security" */
u8 D_8004126C[] = { 0x37, 0x2B, 0x24, 0x37, 0xFF }; /* "that" */
u8 D_80041274[] = { 0x0B, 0x28, 0x35, 0x37, 0x35, 0x24, 0x31, 0xFF }; /* "Bertran" */
u8 D_8004127C[] = { 0x1D, 0x32, 0x38, 0x35, 0x31, 0x24, 0x30, 0x28, 0x31, 0x37, 0xFF }; /* "Tournament" */
u8 D_80041288[] = { 0x0C, 0x35, 0x2C, 0x30, 0x36, 0x32, 0x31, 0xFF }; /* "Crimson" */
u8 D_80041290[] = { 0x1F, 0x28, 0x31, 0x27, 0x32, 0x35, 0xFF }; /* "Vendor" */
u8 D_80041298[] = { 0x36, 0x32, 0x30, 0x28, 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "something" */
u8 D_800412A4[] = { 0x12, 0x37, 0x28, 0x30, 0xFF }; /* "Item" */
u8 D_800412AC[] = { 0x0F, 0x24, 0x2F, 0x26, 0x32, 0x31, 0xFF }; /* "Falcon" */
u8 D_800412B4[] = { 0x29, 0x32, 0x35, 0xFF }; /* "for" */
u8 D_800412B8[] = { 0x1D, 0x2B, 0x24, 0x37, 0x56, 0x36, 0xFF }; /* "That's" */
u8 D_800412C0[] = { 0x0C, 0x32, 0x30, 0x30, 0x24, 0x31, 0x27, 0x28, 0x35, 0xFF }; /* "Commander" */
u8 D_800412CC[] = { 0x0B, 0x2F, 0x32, 0x32, 0x27, 0xFF }; /* "Blood" */
u8 D_800412D4[] = { 0x15, 0x28, 0x24, 0x27, 0x28, 0x35, 0xFF }; /* "Leader" */
u8 D_800412DC[] = { 0x0A, 0x37, 0x37, 0x28, 0x31, 0x27, 0x24, 0x31, 0x37, 0xFF }; /* "Attendant" */
u8 D_800412E8[] = { 0x0C, 0x28, 0x26, 0x2C, 0x2F, 0x2C, 0x24, 0xFF }; /* "Cecilia" */
u8 D_800412F0[] = { 0x24, 0x2F, 0x2F, 0xFF }; /* "all" */
u8 D_800412F4[] = { 0x30, 0x2C, 0x36, 0x36, 0x2C, 0x32, 0x31, 0xFF }; /* "mission" */
u8 D_800412FC[] = { 0x37, 0x2B, 0x2C, 0x36, 0xFF }; /* "this" */
u8 D_80041304[] = { 0x16, 0x24, 0x36, 0x37, 0x28, 0x35, 0x1D, 0x3C, 0x35, 0x24, 0x31, 0x31, 0x32, 0x30, 0x32, 0x31, 0xFF }; /* "MasterTyrannomon" */
u8 D_80041318[] = { 0x0A, 0x35, 0x26, 0x2B, 0x2C, 0x39, 0x28, 0xFF }; /* "Archive" */
u8 D_80041320[] = { 0x0B, 0x2F, 0x24, 0x26, 0x2E, 0xFF }; /* "Black" */
u8 D_80041328[] = { 0x12, 0x56, 0x2F, 0x2F, 0xFF }; /* "I'll" */
u8 D_80041330[] = { 0x24, 0x35, 0x28, 0xFF }; /* "are" */
u8 D_80041334[] = { 0x1C, 0x3A, 0x32, 0x35, 0x27, 0xFF }; /* "Sword" */
u8 D_8004133C[] = { 0x35, 0x2C, 0x2A, 0x2B, 0x37, 0xFF }; /* "right" */
u8 D_80041344[] = { 0x27, 0x2C, 0x2A, 0x2C, 0x39, 0x32, 0x2F, 0x39, 0x28, 0xFF }; /* "digivolve" */
u8 D_80041350[] = { 0x28, 0x31, 0x37, 0x28, 0x35, 0xFF }; /* "enter" */
u8 D_80041358[] = { 0x20, 0x2B, 0x24, 0x37, 0xFF }; /* "What" */
u8 D_80041360[] = { 0x3A, 0x2C, 0x2F, 0x2F, 0xFF }; /* "will" */
u8 D_80041368[] = { 0x26, 0x32, 0x30, 0x28, 0xFF }; /* "come" */
u8 D_80041370[] = { 0x22, 0x32, 0x38, 0xFF }; /* "You" */
u8 D_80041374[] = { 0x0C, 0x32, 0x2F, 0x2C, 0x36, 0x28, 0x38, 0x30, 0xFF }; /* "Coliseum" */
u8 D_80041380[] = { 0x24, 0x25, 0x32, 0x38, 0x37, 0xFF }; /* "about" */
u8 D_80041388[] = { 0x27, 0x32, 0x31, 0x56, 0x37, 0xFF }; /* "don't" */
u8 D_80041390[] = { 0x24, 0x31, 0x3C, 0x37, 0x2B, 0x2C, 0x31, 0x2A, 0xFF }; /* "anything" */
u8 D_8004139C[] = { 0x1F, 0x24, 0x31, 0x27, 0x24, 0x35, 0xFF }; /* "Vandar" */
u8 D_800413A4[] = { 0x19, 0x24, 0x35, 0x37, 0x36, 0xFF }; /* "Parts" */
u8 D_800413AC[] = { 0x3A, 0x2B, 0x28, 0x35, 0x28, 0xFF }; /* "where" */
u8 D_800413B4[] = { 0x1D, 0x2B, 0x28, 0xFF }; /* "The" */
u8 D_800413B8[] = { 0x2E, 0x31, 0x32, 0x3A, 0xFF }; /* "know" */
u8 D_800413C0[] = { 0x15, 0x28, 0x32, 0x30, 0x32, 0x31, 0xFF }; /* "Leomon" */
u8 D_800413C8[] = { 0x3A, 0x24, 0x31, 0x37, 0xFF }; /* "want" */
u8 D_800413D0[] = { 0x18, 0x2F, 0x27, 0x30, 0x24, 0x31, 0xFF }; /* "Oldman" */
u8 D_800413D8[] = { 0x2F, 0x2C, 0x2E, 0x28, 0xFF }; /* "like" */
u8 D_800413E0[] = { 0x31, 0x28, 0x28, 0x27, 0xFF }; /* "need" */
u8 D_800413E8[] = { 0x0C, 0x2B, 0x2C, 0x28, 0x29, 0xFF }; /* "Chief" */
u8 D_800413F0[] = { 0x3A, 0x2C, 0x37, 0x2B, 0xFF }; /* "with" */
u8 D_800413F8[] = { 0x1D, 0x2B, 0x24, 0x31, 0x2E, 0xFF }; /* "Thank" */
u8 D_80041400[] = { 0x36, 0x37, 0x35, 0x24, 0x31, 0x2A, 0x28, 0xFF }; /* "strange" */
u8 D_80041408[] = { 0x12, 0x36, 0x2F, 0x24, 0x31, 0x27, 0xFF }; /* "Island" */
u8 D_80041410[] = { 0x26, 0x24, 0x31, 0xFF }; /* "can" */
u8 D_80041414[] = { 0x35, 0x28, 0x24, 0x2F, 0x2F, 0x3C, 0xFF }; /* "really" */
u8 D_8004141C[] = { 0x0B, 0x2F, 0x38, 0x28, 0xFF }; /* "Blue" */
u8 D_80041424[] = { 0x37, 0x2C, 0x30, 0x28, 0xFF }; /* "time" */
/* Sound effect per text sfx code. */
s16 Text_SfxIds[] = { 0x19, 0x1A, 0x21, 0x2B, 0x20, 0x2A, 0x1F, 0x17, 0x08 };
u8 *Text_BuiltinStrings[] = {
    D_80041208, D_80041210, D_80041214, D_80041218, D_80041224, D_8004122C,
    D_80041234, D_8004123C, D_80041244, D_8004124C, D_80041254, D_80041258,
    D_80041260, D_8004126C, D_80041274, D_8004127C, D_80041288, D_80041290,
    D_80041298, D_800412A4, D_800412AC, D_800412B4, D_800412B8, D_800412C0,
    D_800412CC, D_800412D4, D_800412DC, D_800412E8, D_800412F0, D_800412F4,
    D_800412FC, D_80041304, D_80041318, D_80041320, D_80041328, D_80041330,
    D_80041334, D_8004133C, D_80041344, D_80041350, D_80041358, D_80041360,
    D_80041368, D_80041370, D_80041374, D_80041380, D_80041388, D_80041390,
    D_8004139C, D_800413A4, D_800413AC, D_800413B4, D_800413B8, D_800413C0,
    D_800413C8, D_800413D0, D_800413D8, D_800413E0, D_800413E8, D_800413F0,
    D_800413F8, D_80041400, D_80041408, D_80041410, D_80041414, D_8004141C,
    D_80041424,
};
TaskDesc D_8004154C = { 0, Text_LoadFontsTask, Task_DefaultDestroy, Text_UpdateAllBoxes, 0xA34, 0xD8 };
FadeState Gfx_FadeState = { 1, 0, 0 };
/* Ordering table layout per mode: layer lengths and offsets (8 layers). */
s32 Gpu_OtLayerLens[][8] = {
    { 15, 15, 15, 4, 15, 15, 15, 0 },
    { 15, 15, 15, 5, 15, 5, 15, 0 },
    { 15, 5, 15, 5, 15, 15, 15, 0 },
    { 15, 6, 15, 5, 15, 6, 15, 0 },
};
s32 Gpu_OtLayerOffsets[][8] = {
    { 0, 2, 4, 6, 0x1006, 0x1008, 0x100A, 0 },
    { 0, 2, 4, 6, 0x806, 0x808, 0x1008, 0 },
    { 0, 2, 0x802, 0x804, 0x1004, 0x1006, 0x1008, 0 },
    { 0, 2, 0x402, 0x404, 0xC04, 0xC06, 0x1006, 0 },
};
ActorWork *Gpu_PrimBufs[3] = { 0 };
/* Gfx_DrawPartsEx's cached rotation/scale and the matrix built from it (identity at boot). */
GfxPartRotCache Gfx_PartRotCache = {
    0, 0, { 0 }, 0x1000, 0x1000, 0x1000, { 0 },
    { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } }, { 0, 0, 0 } },
};
DATA_LABEL(Gfx_PartRotMatrix, Gfx_PartRotCache, 0x18);

void Menu_ItemDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 k;
    s32 f;
    u16 m;
    Pair54 tmp;

    if (w->fade == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130019);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            tmp = w->itemCursor;
            f = w->itemCursor.field_0 + 1;
            Gfx_SetPartsNumber(obj, 0x10, 2, f ? f : 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->itemGridSize ? w->itemGridSize : 1);
            tmp.field_0 = w->itemCursor.field_0 - w->scrollRow;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->itemGridSize);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            k = Menu_BlinkOrHideParts(obj, 8, w->scrollRow);
            k |= Menu_BlinkOrHideParts(obj, 4, w->itemGridSize - w->scrollRow - 2);
            if (w->hasItems == 0) {
                k |= 0xE;
            }
            Gfx_HidePartsByMask(obj, k);
            break;
        case 1:
            f = w->menuMode;
            if (f < 3) {
                m = 2;
            } else {
                m = 0xFFFF;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        case 3:
            m = 0xFFFF;
            if (w->menuMode == 3 || w->menuMode == 5) {
                m = 1;
            } else if (w->menuMode == 4) {
                m = 2;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->fade);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void Menu_DigiTransferPlace(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e;
    DigiRosterSwapRec *g;
    MenuDigiPickRow *d;
    DigiRosterSwapRec tmp;
    u8 k;
    s32 id;
    s32 n;

    e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    n = Pad_State[0].cross;
    g = (DigiRosterSwapRec *)Menu_Ctx->field_128;
    if (n > 0) {
        switch (e->kind) {
        case 0:
        default:
            if (g->state >= 3) {
                id = 0x1FD0111;
            icon:
                Text_OpenPacked(w->msgText, Cd_GetFileEntry(id), 0x81, Menu_DigiMsgPos);
                break;
            }
            g->state = w->pickedIndices[3] != 0 ? 1 : 2;
            d = &w->rows[w->cursor[1]];
            d->kind = 1;
            d->record = (s32)g;
            d->pickState = g->state;
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD0110), 0x81, Menu_DigiMsgPos);
            Menu_Ctx->field_126 = -1;
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
            Snd_PlayById(0xE, 0);
            Task_SetState1(a0, 4);
            return;
        case 1:
            k = g->state;
            tmp = *(DigiRosterSwapRec *)e->record;
            g->state = tmp.state;
            tmp.state = k;
            *(DigiRosterSwapRec *)e->record = *g;
            *g = tmp;
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD0112), 0x81, Menu_DigiMsgPos);
            Menu_Ctx->field_126 = -1;
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
            Snd_PlayById(0xE, 0);
            Task_SetState1(a0, 4);
            return;
        case 3:
            if (g->state >= 3) {
                id = 0x1FD011E;
                goto icon;
            }
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD011F), 0x81, Menu_DigiMsgPos);
            Task_SetState1(a0, 5);
            return;
        case 2:
            break;
        }
        Snd_PlayById(0x10, 0);
    }
}

void Menu_DigiTransferPickSrc(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    s32 k;

    if (Pad_State[0].cross > 0) {
        k = 0x10;
        if (e->kind == 1) {
            Menu_Ctx->field_128 = e->record;
            Menu_Ctx->field_126 = 0;
            w->field_62 = 3;
            Task_SetState1(a0, 3);
            k = 0xE;
        }
        Snd_PlayById(k, 0);
    }
}

void Menu_ConfirmMultiPick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
    MenuDigiPickRow *e = &w->rows[k];
    s32 i;

    if (Pad_State[0].cross > 0) {
        if (e->pickState != 2) {
            Snd_PlayById(0x10, 0);
            return;
        }
        e->pickState = w->pickedCount + 3;
        w->pickedIndices[w->pickedCount++] = k;
        Snd_PlayById(0xE, 0);
        if (w->pickedCount < w->pickMax) {
            Task_SetState1(a0, 1);
        } else {
            MenuCtx *d = Menu_Ctx;
            d->pickCount = w->pickMax;
            for (i = 0; i < w->pickMax; i++) {
                e = &w->rows[w->pickedIndices[i]];
                d->pickedRecords[i] = e->record;
            }
            w->field_62 = 2;
            Task_SetState1(a0, 3);
        }
    }
}

void Menu_UndoLastPick(Actor *s0) {
    MenuPickWork *w = (MenuPickWork *)s0->work;
    s16 c = w->pickCount;
    if (c == 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(s0, 2);
    } else {
        s16 idx = (u16)c - 1;
        s16 v;
        w->pickCount = idx;
        v = w->picks[idx];
        ((WorkElem8 *)((u8 *)w + 0x6C))[v].pickState = 2;
        w->picks[w->pickCount] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(s0, 1);
    }
}

void Menu_UseItemOnDigi(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    TextDescHalves st;

    if (Pad_State[0].cross > 0) {
        if (e->kind == 1 && Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, e->record) != 0) {
            st.pos = Menu_DigiMsgPos;
            st.color = 0;
            st.packedStyle = 0x81;
            st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
            Text_OpenDesc(w->msgText, (TextDesc *)&st);
            Snd_PlayById(0x1D, 0);
            Task_SetState1(a0, 4);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}

void Menu_PickUseItemDirect(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    TextDescHalves st;

    st.pos = Menu_DigiMsgPos;
    st.color = 0;
    st.packedStyle = 0x81;
    if (Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0) != 0) {
        st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        Snd_PlayById(0x1D, 0);
    } else {
        st.text = (s32)Cd_GetFileEntry(0x1FD00A0);
        st.strArg0 = 0;
    }
    Text_OpenDesc(w->msgText, (TextDesc *)&st);
}

void Menu_ConfirmSinglePick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k;
    s32 c;

    if (Pad_State[0].cross > 0) {
        k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
        if ((c = w->rows[k].kind) == 1) {
            Menu_Ctx->selRecord = (u8 *)w->rows[k].record;
            w->field_62 = 0;
            Task_SetState1(a0, 3);
            Menu_Ctx->pickResult = c;
            Snd_PlayById(0xE, 0);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}


void Menu_BuildDigiList(MenuDigiListBuildWork *w) {
    MenuDigiListBuildRow *r = w->rows;
    DigiRosterEntry *el = Save_GameStatePtr->elems;
    s32 n = 0;
    s32 i;
    s32 ok;
    MenuDigiListBuildRow *t;

    for (i = 0, t = r; i < 0x26; i++) {
        t->field_2 = 0;
        t->kind = 0;
        t++;
    }
    w->gridCols = 1;
    switch (w->mode) {
    default:
        w->rowCount = Beetle_GetDigiCapacity();
        break;
    case 2:
        w->rowCount = 0x18;
        break;
    case 7:
    case 8:
        if (w->parity == 0) {
            w->rowCount = Beetle_GetDigiCapacity();
        } else {
            w->rowCount = 0x18;
        }
        if (w->mode == 8) {
            w->rowCount++;
            n++;
            r->kind = 3;
            r->entry = 0;
            r->field_2 = 0;
            r++;
            w->cursorRow++;
        }
        break;
    case 6:
        w->rowCount = Menu_Ctx->pickCount;
        for (i = 0; i < Menu_Ctx->pickCount; i++) {
            r->kind = 1;
            r->entry = Menu_Ctx->pickedRecords[i];
            r->field_2 = i + 3;
            r++;
        }
        return;
    }
    for (i = 0; i < 0x24; i++, el++) {
        if (el->state != 0) {
            ok = 0;
            switch (w->mode) {
            default:
                if (el->state >= 2) ok = -1;
                break;
            case 5:
                if (el->state >= 2 && (s16)el->hp != 0) ok = -1;
                break;
            case 7:
            case 8:
                if (w->parity == 0 ? el->state >= 2 : el->state == 1) ok = -1;
                break;
            case 2:
                if (el->state == 1) ok = -1;
                break;
            }
            if (ok) {
                r->kind = 1;
                r->entry = el;
                r->field_2 = (w->mode == 5) ? 2 : el->state;
                r++;
                n++;
            }
        }
    }
    if (Menu_Ctx->flags & 1) {
        switch (w->mode) {
        case 2:
        case 5:
            break;
        default:
            r = &w->rows[w->rowCount - 1];
            for (i = 0; i < Dung_StatePtr->memBugCount; i++, r--) {
                r->kind = 2;
                r->bugLevel = Dung_StatePtr->memBugLevels[i];
            }
            break;
        }
    }
    if (w->mode == 5) {
        w->rowCount = n;
        if (n < 4) {
            w->pickMax = n;
        } else {
            w->pickMax = 3;
        }
        w->pickCount = 0;
        w->pick2 = 0;
        w->pick1 = 0;
        w->pick0 = 0;
    }
}


void Menu_DigiListDrawRows(MenuDigiListRowsView *a0, s32 a1) {
    s32 i;
    MenuDigiListRow *rec;
    TextDesc st;

    st.strArg0 = 0;
    st.packedStyle = a1;
    st.color = 0;
    for (i = 0; i < 16; i++) {
        Text_Close(&a0->textBoxes[i]);
    }
    rec = &a0->entries[a0->scrollTop];
    for (i = 0; i < 4; i++) {
        switch (rec->kind) {
        case 0:
            break;
        case 1:
            st.x = 109;
            st.y = i * 33 + 62;
            st.text = (s32)Cd_GetFileEntry(0x1FD0082);
            Text_OpenDesc(&a0->textBoxes[i * 4], &st);
            st.x = 208;
            st.y = i * 33 + 62;
            st.text = (s32)Cd_GetFileEntry(0x1FD00BB);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 1], &st);
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)rec->digi->name;
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            st.x = 208;
            st.y = i * 33 + 50;
            st.text = (s32)Digi_GetDefaultName(rec->digi->digiId);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 3], &st);
            break;
        case 2:
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)Cd_GetFileEntry(rec->memBugLevel + 0x1FD00F5);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            break;
        case 3:
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)Cd_GetFileEntry(0x1FD0114);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            break;
        }
        rec++;
    }
}

void Menu_SetDigiListMode(Actor *a, s16 mode) {
    MenuDigiListModeWork *w = (MenuDigiListModeWork *)a->work;

    w->mode = mode;
    if (mode == 3 && ((ItemEffect *)Item_GetEffectRec(Menu_Ctx->itemId))->useType == 2) {
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
        { s16 t = Menu_Ctx->subMenuCursor - 7; w->parity = (w->mode + t) & 1; }
        break;
    }
}

void Menu_DigiListTask(Actor *a0) {
    MenuDigiListWork *w = (MenuDigiListWork *)a0->work;
    s32 *slot;
    s32 r;
    s32 i;
    s32 id;
    u8 *p;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->grid = Menu_DigiListGrid;
        w->scrollTop = 0;
        w->cursor[1] = 0;
        w->cursor[0] = 0;
        Menu_BuildDigiList((MenuDigiListBuildWork *)w);
        Mem_FillWordsNeg1(w->texts, 0x14);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->scale) != 0) {
                break;
            }
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 1);
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->mode) {
            default:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD00D3), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 3:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD009E), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 4:
                Menu_PickUseItemDirect(a0);
                Task_SetState1(a0, 4);
                break;
            case 5:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->pickCount + 0x1FD0109), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 6:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010C), 0x80, Menu_DigiMsgPos);
                Task_SetState1(a0, 5);
                break;
            case 7:
            case 8:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->mode + 0x1FD0107), 0x80, Menu_DigiMsgPos);
                id = 0x1FD0072;
                if (w->parity != 0) {
                    id = 0x1FD009A;
                }
                Text_OpenPacked(&w->titleText, (s32)Cd_GetFileEntry(id), 0, Menu_DigiListTitlePos[w->parity]);
                Task_NextState1(a0);
                break;
            }
            if (w->showCursor != 0) {
                Text_OpenPacked(&w->cursorText, (s32)Cd_GetFileEntry(0x1FD00FA), 0, Menu_DigiListCursorTextPos);
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->grid.gridSize) == 0) {
                if (Pad_State[0].triangle > 0) {
                    if (w->mode != 5) {
                        Snd_PlayById(0xB, 0);
                        Task_SetState0(a0, 2);
                    } else {
                        Menu_UndoLastPick(a0);
                    }
                } else {
                    switch (w->mode) {
                    case 1:
                    case 2:
                        Menu_ConfirmSinglePick(a0);
                        break;
                    case 3:
                        Menu_UseItemOnDigi(a0);
                        break;
                    case 5:
                        Menu_ConfirmMultiPick(a0);
                        break;
                    case 7:
                        Menu_DigiTransferPickSrc(a0);
                        break;
                    case 8:
                        Menu_DigiTransferPlace(a0);
                        break;
                    }
                }
            } else {
                Snd_PlayById(0xD, 0);
                if (w->cursor[1] - w->scrollTop >= 4) {
                    w->scrollTop = w->cursor[1] - 3;
                    Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
                } else if (w->cursor[1] < w->scrollTop) {
                    w->scrollTop = w->cursor[1];
                    Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
                }
                Task_SetState1(a0, 1);
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.children;
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(w->texts, 0x14);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->scale) != 0) {
                    break;
                }
                Task_NextState2(a0);
                break;
            case 2:
                Task_Create(Menu_DigiListSubTasks[w->subTask].field_0, slot, Menu_DigiListSubTasks[w->subTask].field_2);
                Task_NextState2(a0);
                break;
            case 3:
                if (*slot != 0) {
                    break;
                }
                switch (w->mode) {
                default:
                    Task_SetState1(a0, 0);
                    break;
                case 1:
                case 2:
                    if (Menu_Ctx->confirmed == 0) {
                        Task_SetState1(a0, 0);
                        Menu_Ctx->pickResult = 2;
                    } else {
                        w->subTask ^= 1;
                        Task_SetState2(a0, 2);
                    }
                    break;
                case 5:
                    if (Menu_Ctx->pickConfirmed != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 2);
                        break;
                    }
                    Menu_UndoLastPick(a0);
                    Task_SetState1(a0, 0);
                    break;
                case 7:
                    if (Menu_Ctx->field_126 != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 0);
                        break;
                    }
                    Task_SetState1(a0, 0);
                    break;
                }
                break;
            }
            break;
        case 4:
            switch (a0->stateLevel2) {
            case 0:
                if (Text_IsFinished(w->promptText) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (Pad_State[0].triangle > 0 || Pad_State[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 5:
            r = Text_WaitYesNo(w->promptText);
            if (r == 0) {
                break;
            }
            switch (w->mode) {
            case 6:
            default:
                if (r == 1) {
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010D), 0x81, Menu_DigiMsgPos);
                    for (i = 0; i < 0x24; i++) {
                        if (Save_GameStatePtr->elems[i].state >= 3) {
                            Save_GameStatePtr->elems[i].state = 2;
                        }
                    }
                    for (i = 0; i < Menu_Ctx->pickCount; i++) {
                        *Menu_Ctx->pickedRecords[i] = i + 3;
                    }
                    Menu_Ctx->pickConfirmed = -1;
                    Task_SetState1(a0, 4);
                } else {
                    Menu_Ctx->pickConfirmed = 0;
                    Task_SetState0(a0, 2);
                }
                break;
            case 8:
                if (r == 1) {
                    p = (u8 *)Menu_Ctx->field_128;
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD0113), 0x81, Menu_DigiMsgPos);
                    *p = 0;
                    Menu_Ctx->field_126 = -1;
                    Snd_PlayById(0xE, 0);
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 1);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 0x14);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void Menu_DigiListDraw(Actor *actor) {
    MenuDigiListDrawView *w = (MenuDigiListDrawView *)actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 j;
    s32 f;
    u16 m;
    MenuDigiListDrawRow *r;
    DigiRosterListView *e;
    Pair54 tmp;

    if (w->scale == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513001B);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            if (w->showCursor != 0) {
            tmp = w->cursor;
            tmp.field_2 = w->cursor.field_2 - w->scrollTop;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->gridCols);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            {
                s32 fl = (w->scrollTop < 1) << 2;
                if (w->rowCount - w->scrollTop - 4 <= 0) {
                    fl |= 8;
                }
                Gfx_HidePartsByMask(obj, fl);
            }
            Gfx_SetPartsNumber(obj, 0x10, 2, w->cursor.field_2 + 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->rowCount);
            } else {
                Gfx_HidePartsByMask(obj, -1);
            }
            break;
        default:
            r = &w->rows[w->scrollTop + (i - 1)];
            j = i - 1;
            if (j >= w->rowCount) {
                Gfx_HidePartsByMask(obj, -1);
                break;
            }
            Gfx_HidePartsByMask(obj, 0);
            f = 2;
            if (w->showCursor != 0 && j == w->cursor.field_2 - w->scrollTop) {
                f = 1;
            }
            switch (r->kind) {
            case 0:
                Gfx_HidePartsByMask(obj, f | 0xFE4);
                break;
            case 1:
                e = (DigiRosterListView *)r->digi;
                Gfx_HidePartsByMask(obj, f | Menu_DigiListRowMasks[r->pickState - 1]);
                Gfx_SetPartsNumber(obj, 0x20, 3, e->maxHp);
                Gfx_SetPartsNumber(obj, 0x40, 3, e->hp);
                Gfx_SetPartsNumber(obj, 0x80, 3, e->maxMp);
                Gfx_SetPartsNumber(obj, 0x100, 3, e->mp);
                break;
            case 2:
            case 3:
                Gfx_HidePartsByMask(obj, -5);
                break;
            }
            break;
        case 5:
            break;
        case 6:
            m = 0xFFFF;
            if (w->mode == 7 || w->mode == 8) {
                m = 1;
                if (w->parity != 0) {
                    m = 2;
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->scale);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void Menu_DigiStatusInit(Actor *a0, s16 a1) {
    MenuDigiStatusInitWork *w;
    u8 *p;
    s32 i;
    Blk16 *b;
    s32 *q;

    w = (MenuDigiStatusInitWork *)a0->work;
    w->field_7C = a1;
    p = Menu_Ctx->selRecord;
    w->digimon = p;
    a0->digiId = p[1];
    Actor_InitTransform((ContC40 *)a0, w->pos, w->initRotY);
    w->modelFile = Digi_GetModelFile(a0->digiId);
    w->animFile = Anim_GetModelAnimFile(a0->digiId, 0);
    Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
    Cd_QueueFile(w->modelFile);
    Cd_QueueFile(w->animFile);
    w->modelPhase = 0;
    w->modelScale = 0;
    w->view = Menu_DigiStatusView;
    GsInitCoordinate2(0, (Coord1F668 *)&w->coord);
    w->field_148 = 1;
    w->rotSpeedY = 11;
    w->rotSpeedX = 0;
    w->rotSpeedZ = 0;
    w->rotX = -0xE3;
    b = (Blk16 *)Cd_GetFileEntry(0x513001F);
    q = (s32 *)Cd_GetFileEntry(0x5130020);
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &b[i]);
    }
    GsSetAmbient(q[0], q[1], q[2]);
    GsSetLightMode(0);
}


void Menu_DigiStatusTask(Actor *a) {
    MenuDigiStatusWork *w = (MenuDigiStatusWork *)a->work;
    Halves *h;
    MenuDigiStatusEntry *r;
    u8 **q;
    s32 i;
    Actor *t[1];
    s16 *p;
    s16 *s;
    PadState *d;

    switch (a->stateLevel0) {
    default:
    case 0:
        w->blk = *(MenuDigiStatusLayout *)Cd_GetFileEntry(0x513001C);
        Mem_FillWordsNeg1(w, 0x1B);
        GsSetOffset(-0xA0, 0xB4);
        t[0] = a;
        Task_Create(6, (s32 *)a->u34.children, (s32)t);
        a->childCount = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        default:
        case 0:
            h = (Halves *)Cd_GetFileEntry(0x513001E);
            (*(Actor **)a->u34.children)->model->otIndex = 4;
            if (Math_RampToOne((s32)a, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x513001D, 0), 1);
            r = w->digimon;
            Text_OpenPacked(&w->nameText, (s32)r->name, 0x81, h[0]);
            w->speciesName = Digi_GetDefaultName(r->speciesId);
            w->typeName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetType)(r->speciesId) + 0x1FD00C3);
            w->rankName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetRank)(r->speciesId) + 0x1FD00C6);
            w->specialtyName = Cd_GetFileEntry(((s32 (*)(s32))Digi_GetSpecialty)(r->speciesId) + 0x1FD00CA);
            q = w->parentNames;
            for (i = 0; i < 2; i++) {
                if (r->parentIds[i] != 0) {
                    *q++ = Digi_GetDefaultName(r->parentIds[i]);
                }
            }
            *q = 0;
            Text_PrintList(&w->infoTexts, &h[1], (s32 *)&w->speciesName, 1);
            Task_NextState1(a);
            break;
        case 1:
            w->modelPhase = 1;
            GsSetOffset(-0xA0, w->rot[0] * 80 / 682 + 180);
            Task_NextState1(a);
            break;
        case 2:
            Math_RampToOne((s32)a, &w->modelScale);
            p = w->rot;
            s = w->rotSpeed;
            a->childCount = 1;
            p[1] += s[1];
            if (Pad_State[0].left != 0) {
                s[1] = (s[1] - 5 < -0x22) ? -0x22 : s[1] - 5;
            }
            if (Pad_State[0].right != 0) {
                s[1] = (s[1] + 5 >= 0x23) ? 0x22 : s[1] + 5;
            }
            if (Pad_State[0].down != 0) {
                p[0] = (p[0] + 0xB > 0) ? 0 : p[0] + 0xB;
            }
            if (Pad_State[0].up != 0) {
                p[0] = (p[0] - 0xB < -0x2AA) ? -0x2AA : p[0] - 0xB;
            }
            GsSetOffset(-0xA0, p[0] * 80 / 682 + 180);
            d = Pad_State;
            if (d->triangle > 0 || d->circle > 0) {
                Task_SetState0(a, 2);
                if (d->circle > 0) {
                    Menu_Ctx->confirmed = -1;
                    Snd_PlayById(0xE, 0);
                } else {
                    Menu_Ctx->confirmed = 0;
                    Snd_PlayById(0xB, 0);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        default:
        case 0:
            Text_CloseArray(w, 0x1B);
            Task_NextState1(a);
            break;
        case 1:
            Math_RampToZero((s32)a, &w->modelScale);
            if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                GsSetOffset(0, 0);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

extern s32 GsSetRefView2(GsRVIEW2 *);

void Menu_DigiStatusDraw(Actor *actor) {
    Wk19214 *work;
    Rec19214 *rec;
    s32 *list;
    s32 *p;
    void *obj;
    Nd19214 *node;
    GsRVIEW2 ls;

    work = (Wk19214 *)actor->work;
    if (work->ramp == 0) {
        goto Ltail;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130021);
    rec = (Rec19214 *)work->digimon;
    if (*p == 0) {
        goto Ltail;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        list++;
        Gfx_SetPartsNumber(obj, 0x2, 3, rec->maxHp);
        Gfx_SetPartsNumber(obj, 0x4, 3, rec->hp);
        Gfx_SetPartsNumber(obj, 0x8, 3, rec->maxMp);
        Gfx_SetPartsNumber(obj, 0x10, 3, rec->mp);
        Gfx_SetPartsNumber(obj, 0x20, 2, rec->level);
        Gfx_SetPartsNumber(obj, 0x40, 3, rec->attack);
        Gfx_SetPartsNumber(obj, 0x80, 3, rec->defense);
        Gfx_SetPartsNumber(obj, 0x100, 3, rec->speed);
        Gfx_SetPartsNumber(obj, 0x200, 8, rec->exp);
        Gfx_SetPartsNumber(obj, 0x400, 8, Digi_GetExpToNextLevel(rec->level, rec->maxLevel, rec->exp));
        Gfx_SetPartsScale((GfxPartScaleView *)obj, 0x1000, work->ramp);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);

Ltail:
    work->field_148 = 0;
    RotMatrixYXZ(&work->rot, &work->coordMatrix);
    work->coordTx = work->posX;
    work->coordTy = work->posY;
    work->coordTz = work->posZ;
    work->coord = 0;
    ls.vpx = work->vpx;
    ls.vpy = work->vpy;
    ls.vpz = work->vpz;
    ls.vrx = work->vrx;
    ls.vry = work->vry;
    ls.vrz = work->vrz;
    ls.rz = 0;
    ls.super = &work->coord;
    GsSetProjection(work->projection);
    GsSetRefView2(&ls);
    if (work->modelPhase == 0) {
        return;
    }
    if (work->modelScale == 0) {
        return;
    }
    if (work->modelPhase == 1) {
        Anim_SetModelAnim(actor, 0);
        work->modelPhase = work->modelPhase + 1;
    }
    node = (Nd19214 *)actor->u38.ptr38;
    node->scaleX = work->modelScale;
    node->scaleY = work->modelScale;
    node->scaleZ = work->modelScale;
    Gfx_AttachModel(actor, work->modelFile);
    Anim_StepModelAnim(actor);
    Actor_UpdateTransform(actor);
    Gfx_CalcModelBoneMatrices(actor);
    Gfx_DrawTexModel(actor, 0);
}

void Menu_SkillListBuildTabs(a)
Actor194C8 *a;
{
    u8 *tbl;
    s32 i;
    s32 r, c;
    u8 *q;
    void *base;

    tbl = a->selRecord;

    for (i = 3; i >= 0; i--) {
        a->records[i].count = 0;
    }

    for (i = 0; i < 0xC; i++) {
        q = tbl + i;
        if (q[0x22] == 0) continue;
        r = Skill_GetType(q[0x22]);
        c = a->records[r].count;
        a->records[r].arr[c] = q[0x22];
        a->records[r].count = (u16)a->records[r].count + 1;
    }

    for (i = 0; i < 4; i++) {
        base = Cd_GetFileEntry(0x5130022);
        a->block64[i] = *(Blk12 *)((u8 *)base + i * 0xC);
        a->scrollTop[i] = 0;
        a->slot54[i].v = 0;
        *(s16 *)((u8 *)&a->block64[i] + 2) = a->records[i].count;
    }
}

void Menu_SkillListOpenNames(Actor194C8 *w, s32 arg1)
{
  int new_var;
  TextDescHalves st;
  s32 i;
  s32 new_var2;
  s32 ch;
  s32 n;
  s32 j;
  s32 k;
  s32 d0;
  s32 d;
  s32 f;
  s32 m;
  for (i = 6; i < 18; i++)
  {
    Text_Close(&w->textBoxes[i]);
  }

  st.strArg0 = 0;
  st.packedStyle = arg1;
  for (ch = 0; ch < 4; ch++)
  {
    st.pos = ((Halves *) Cd_GetFileEntry(0x5130025))[ch];
    d0 = w->scrollTop[ch];
    d = w->records[ch].count - d0;
    n = 3;
    if (d < 4)
    {
      n = d;
    }
    for (j = 0; j < n; j++)
    {
      i = d0;
      f = 0;
      if (w->curTab != ch)
      {
        f = 1;
      }
      else
      {
        new_var2 = d0;
        if (w->slot54[ch].row != (j + new_var2))
        {
          f = 1;
        }
      }
      new_var = 11;
      st.color = f;
      st.text = Skill_GetNameText(w->records[ch].arr[j + i]);
      m = j + 6;
      Text_OpenDesc(&w->textBoxes[(ch * 3) + m], (TextDesc *) (&st));
      st.pos.hi += new_var;
    }

    Text_SetColor(w->textBoxes[ch + 2], w->curTab != ch);
  }

}


void Menu_SkillListInit(Actor *arg0, s16 arg1) {
    arg0->work->field_A4 = arg1;
}

void Menu_SkillListTask(Actor *a0) {
    Actor194C8 *w = (Actor194C8 *)a0->work;
    Halves h;
    TextDescHalves st;
    s32 i;
    s32 k;
    s32 id;
    s32 t;
    s32 j;
    s32 n;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->selRecord = Menu_Ctx->selRecord;
        Menu_SkillListBuildTabs(w);
        w->curTab = 0;
        Mem_FillWordsNeg1(&w->textBoxes, 0x15);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->fadeRamp) != 0) {
                break;
            }
            Text_PrintIdList(&w->textBoxes, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130024, 0), 1);
            Menu_SkillListOpenNames(w, 1);
            h.lo = 0x13;
            h.hi = 0x32;
            Text_OpenPacked(&w->nameText, (s32)&w->selRecord[0x4C], 1, h);
            Task_NextState1(a0);
            break;
        case 1:
            i = w->curTab;
            k = Menu_GridIndexColMajor(&w->slot54[i].v, (s16 *)w->block64[i].data);
            Text_Close(&w->descText);
            Text_Close(&w->numberText);
            if (k < w->records[i].count) {
                id = w->records[i].arr[w->slot54[i].row];
                st.pos = Menu_SkillMsgPos;
                st.packedStyle = 0x80;
                st.color = 0;
                st.text = Skill_GetDescText(id);
                Text_OpenDesc(&w->descText, (TextDesc *)&st);
                st.pos.hi = 0xCA;
                st.text = (s32)Cd_GetFileEntry(0x1FD0150);
                Text_FormatNumber(w->numBuf, Skill_GetMpCost(id), -4);
                st.strArg0 = (s32)w->numBuf;
                Text_OpenDesc(&w->numberText, (TextDesc *)&st);
            }
            Task_NextState1(a0);
            break;
        case 2:
            t = Pad_State[0].left;
            if (t > 0 || Pad_State[0].right > 0) {
                n = w->curTab;
                if (t > 0) {
                    n--;
                } else {
                    n++;
                }
                w->curTab = n & 3;
                Snd_PlayById(0xD, 0);
                Menu_SkillListOpenNames(w, 0);
                Task_SetState1(a0, 1);
            } else {
                j = w->curTab;
                if (Menu_MoveGridCursorP1((s32)&w->slot54[j], (s32)&w->block64[j]) != 0) {
                    Menu_ScrollToShow(&w->scrollTop[j], w->slot54[j].row, 3);
                    Menu_SkillListOpenNames(w, 0);
                    Snd_PlayById(0xD, 0);
                    Task_SetState1(a0, 1);
                } else if (Pad_State[0].triangle > 0 || Pad_State[0].circle > 0) {
                    Task_SetState0(a0, 2);
                    if (Pad_State[0].circle > 0) {
                        Menu_Ctx->confirmed = -1;
                        Snd_PlayById(0xE, 0);
                    } else {
                        Menu_Ctx->confirmed = 0;
                        Snd_PlayById(0xB, 0);
                    }
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->textBoxes, 0x15);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->fadeRamp) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void Menu_SkillListDraw(Actor *actor) {
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

    if (w->ramp == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130026);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            k = w->activePane;
            v = Menu_SkillPaneMasks[k];
            if (w->records[k].count != 0) {
                tmp = w->cursors[k];
                tmp.field_2 = w->cursors[k].field_2 - w->scroll[k];
                Menu_SetPartsGridPos(obj, 0x4000, (s32 *)&tmp, &w->grids[k].cols);
                Gfx_SetPartsPalette(obj, 0x4000, (actor->elapsed >> 2) & 3);
            } else {
                v |= 0x4000;
            }
            Gfx_HidePartsByMask(obj, v);
            break;
        case 1:
            m = 0xFFFFF;
            for (j = 0; j < 4; j++) {
                if (w->scroll[j] != 0) {
                    if (w->activePane == j) {
                        m -= 1 << (j * 4 + 1);
                    } else {
                        m -= 1 << (j * 4 + 2);
                    }
                }
                if (w->grids[j].rows - w->scroll[j] >= 4) {
                    if (w->activePane == j) {
                        m -= 1 << (j * 4 + 3);
                    } else {
                        m -= 1 << (j * 4 + 4);
                    }
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->ramp);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void Task_SpawnListInit(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void Task_SpawnListFromFile(Actor *a0) {
    TaskSpawnEntry *p;
    s32 *slot;
    s32 end = -1;
    s32 *s;

    if (a0->stateLevel0 != 0) {
        return;
    }
    s = (s32 *)a0->u34.children;
    p = (TaskSpawnEntry *)Cd_GetFileOrNull(a0->work->field_0);
    slot = s;
loop:
    if (p->taskId == end) {
        goto done;
    }
    Task_Create(p->taskId, slot, (s32)&p->args);
    slot++;
    p = (TaskSpawnEntry *)((u8 *)p + p->size);
    goto loop;
done:
    Task_NextState0(a0);
}


void Text_WinFrameInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

void Text_WinFrameTask(Actor *a0) {
    s32 v1 = a0->stateLevel0;
    u16 *a1 = (u16 *)&a0->work->field_0;
    switch (v1) {
    case 1:
        if (a0->stateLevel1 == 0 || a0->stateLevel1 != v1) {
            u16 nv = *a1 + 0x555;
            *a1 = nv;
            if ((s16)nv >= 0x1000) {
                *a1 = 0x1000;
                Task_NextState1(a0);
            }
        }
        break;
    case 0:
        Task_NextState0(a0);
        break;
    case 2: {
        s16 nv = *a1 - 0x555;
        *a1 = nv;
        if (nv <= 0) {
            *a1 = 0;
            Task_NextState0(a0);
        }
        break;
    }
    }
}

void Text_WinFrameDraw(Actor *arg0) {
    ActorWork *w = arg0->work;
    void *e = Cd_GetFileEntry(Text_WinFrameParts[arg0->param]);
    Gfx_SetPartsScale(e, 0x1000, *(s16 *)w);
    Gfx_DrawParts((s32)e);
}

void Snd_ServiceSlotLoads(void) {
    s32 i;
    SndSlot *e;
    u32 n;
    u32 k;
    s32 *src;
    s32 *dst;
    s32 p;
    s32 j;

    for (i = 0; i < 3; i++) {
        e = &Snd_Slots[i];
        switch (e->loadState) {
        case 0:
            break;
        case 1:
            if (e->contentId == 0) {
                e->loadState = 0;
                break;
            }
            e->vbFileId = Snd_BankDescs[e->contentId]->vbFile >> 16;
            e->vhFileId = Snd_BankDescs[e->contentId]->vhFile >> 16;
            Cd_QueueFile(e->vhFileId);
            e->loadState++;
            break;
        case 2:
            if (Cd_GetFileState(e->vhFileId) == 3) {
                src = (s32 *)Cd_GetFileSync(e->vhFileId);
                n = Snd_SlotBufSizes[i];
                dst = e->headerBuf;
                if ((u32)src + n > 0x801FFFFF) {
                    n = 0x801FFFFC - (u32)src;
                }
                n >>= 2;
                for (k = 0; k < n; k++) {
                    *dst++ = *src++;
                }
                e->loadState++;
            }
            break;
        case 3:
            Cd_QueueFile(e->vbFileId);
            e->loadState++;
            break;
        case 4:
            e->vabId = SsVabOpenHead(Mem_GetOffsetEntry(Snd_BankDescs[e->contentId]->vhFile, e->headerBuf), i);
            e->loadState++;
            break;
        case 5:
            if (Cd_GetFileState(e->vbFileId) == 3) {
                Cd_LockFile(e->vbFileId);
                e->vabId = SsVabTransBody((s32)Cd_GetFileEntry(Snd_BankDescs[e->contentId]->vbFile), e->vabId);
                e->loadState++;
            }
            break;
        case 6:
            e->sepCount = 0;
            e->loadState++;
        case 7:
            j = e->sepCount;
            p = *(j + Snd_BankDescs[e->contentId]->sepOffsets);
            if (p != 0) {
                e->sepIds[j] = SsSepOpen(Mem_GetOffsetEntry(p, e->headerBuf), e->vabId, 0x10);
                e->sepCount++;
            } else {
                e->loadState++;
            }
            break;
        default:
            if (SsVabTransCompleted(0)) {
                Cd_UnlockFile(e->vbFileId);
                e->loadState = 0;
            }
            break;
        }
    }
}


s32 Snd_AnySlotLoading(void) {
    s32 found = 0;
    s32 i = 0;
    SndSlot *p = Snd_Slots;
    for (; i < 3; i++, p++) {
        if (p->loadState != 0) found = 1;
        if (found) break;
    }
    return found;
}

void Snd_StopAll(void) {
    SndSlot *p;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 3; i++) {
        p = &Snd_Slots[i];
        if (p->vabId != -1) {
            for (j = 0; j < p->sepCount; j++) {
                for (k = 0; k < 0x10; k++) {
                    SsSepStop(p->sepIds[j], k);
                }
            }
        }
    }
    SsUtAllKeyOff(0);
    Snd_CurrentId = -1;
}

void Snd_StopById(s32 id) {
    s32 i;
    s32 j;
    s32 k;

    if (id != -1) {
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        if (Snd_Slots[i].loadState == 0) {
            SsSepStop(Snd_Slots[i].sepIds[j], k);
        }
        if (Snd_CurrentId == id) {
            Snd_CurrentId = -1;
        }
    }
}

void Snd_UnloadSlot(s32 idx) {
    s32 i;
    s32 k;

    if (Snd_Slots[idx].vabId == -1) {
        return;
    }
    for (i = 0; i < Snd_Slots[idx].sepCount; i++) {
        for (k = 0; k < 0x10; k++) {
            SsSepStop(Snd_Slots[idx].sepIds[i], k);
        }
        SsSepClose(Snd_Slots[idx].sepIds[i]);
    }
    SsVabClose(Snd_Slots[idx].vabId);
    Snd_Slots[idx].loadState = 0;
    Snd_Slots[idx].contentId = -1;
    Snd_Slots[idx].sepCount = 0;
    Snd_Slots[idx].vabId = -1;
}

void Snd_SetSlotContent(s32 idx, s32 v) {
    if (Snd_Slots[idx].contentId != v) {
        Snd_UnloadSlot(idx);
        Snd_Slots[idx].loadState = 1;
        Snd_Slots[idx].contentId = v;
        if (Snd_CurrentId != -1 && idx == ((Snd_CurrentId & 0xF00) >> 8)) {
            Snd_StopById(Snd_CurrentId);
        }
    }
}

void Snd_PlayById(s32 id, s32 set) {
    s32 k;
    s32 i;
    s32 j;
    if (Snd_CurrentId != id) {
        if (set != 0 && Snd_CurrentId != -1) {
            Snd_StopById(Snd_CurrentId);
        }
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        SsSepStop(Snd_Slots[i].sepIds[j], k);
        SsSepSetVol(Snd_Slots[i].sepIds[j], k, 0x7F, 0x7F);
        SsSepPlay(Snd_Slots[i].sepIds[j], k, 1, 1);
        if (set != 0) {
            Snd_CurrentId = id;
        }
    }
} /* libsnd sequence table: SS_SEQ_TABSIZ * 6 seqs * 16 */

extern void SsSetTableSize(void *, s16, s16);
extern void SsSetTickMode(s32);
extern void SsStart2();
extern void SsSetMVol(s16, s16);
extern void SsSetSerialAttr(s8, s8, s8);
extern void SsSetSerialVol(s8, s16, s16);
extern s16 SsUtSetReverbType(s16);
extern void SsUtSetReverbDepth(s16, s16);
extern void SsUtReverbOn();
extern s32 Mem_Alloc(s32, s32);
extern void Snd_SetSlotContent(s32, s32);
extern void Cd_ServiceQueue();

void Snd_Init(void) {
    s32 v0;
    s32 i;
    Ew54C48 *e;

    SsSetTableSize(Snd_SeqAttrTable, 6, 0x10);
    SsSetTickMode(0x1000);
    SsStart2();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 1);
    SsSetSerialVol(0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    SsUtSetReverbDepth(0, 0);
    SsUtReverbOn();

    v0 = Mem_Alloc(Snd_SlotBufSizes[0] + Snd_SlotBufSizes[1] + Snd_SlotBufSizes[2], 4);
    e = (Ew54C48 *)Snd_Slots;
    e[0].headerBuf = v0;
    v0 += Snd_SlotBufSizes[0];
    e[1].headerBuf = v0;
    v0 += Snd_SlotBufSizes[1];
    e[2].headerBuf = v0;
    for (i = 0; i < 3; i++) {
        e[i].loadState = 0;
        e[i].contentId = -1;
        e[i].sepCount = 0;
        e[i].vabId = -1;
    }

    Snd_SetSlotContent(0, 1);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (Snd_Slots[0].loadState != 0);

    Snd_SetSlotContent(1, 0xE);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (Snd_Slots[1].loadState != 0);
}

void Snd_SaveCurrentId(void) {
    Snd_SavedId = Snd_CurrentId;
}


void Snd_RestoreSavedId(void) {
    Snd_PlayById(Snd_SavedId, 1);
}


void Text_PushReturn(s32 arg0) {
    Text_ReturnStack.data[Text_ReturnStack.count] = arg0;
    Text_ReturnStack.count = Text_ReturnStack.count + 1;
}

s32 Text_PopReturn(void) {
    if (Text_ReturnStack.count == 0) {
        return 0;
    }
    Text_ReturnStack.count = Text_ReturnStack.count - 1;
    return Text_ReturnStack.data[Text_ReturnStack.count];
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern void Task_Create(u32, s32 *, s32);

void Text_LoadFontsTask(Actor *a0) {
    if (a0->stateLevel0 != 0) {
        return;
    }
    Gfx_FindOrLoadTexSlot(0x13A0000);
    if ((Sys_GameMode[0] & 0xF00) != 0x500) {
        Gfx_FindOrLoadTexSlot(0x1100000);
        Task_Create(0xA, a0->u34.children, 0);
    }
    Task_NextState0(a0);
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern Obj6A8C0 *Stg20_FindWalkerByDigiId(s32);
extern void Stg20_WalkerWarpToCell(void *, s32 *);
extern s32 Stg20_WalkerIsPathDone(void *);
extern void Stg20_WalkerSetAnim(Obj6A8C0 *, s32);
extern void Stg40_TextObjCommand(s32 *);
extern s32 Stg40_IsTextObjCmdBusy(void);
extern void Stg20_StartBgShake(void);

void Text_UpdateAllBoxes(Actor *a0) {
    GfxTexSlot *font[2];
    Pair54 glyph;
    Pair54 cell;
    Pair54 pos;
    s32 num[2];
    s32 nums[3];
    TextBoxWork *wk;
    TextBoxKids *slots;
    s32 row;
    TextGlyphPoly *pkt;
    s32 *ot;
    s32 cols;
    s32 page;
    s32 nFA;
    s32 nFB;
    s32 nF9;
    s32 nF8;
    s32 nF6;
    s32 nF5;
    s32 nF4b;
    s32 nF4a;
    s32 nF4c;
    u8 nF4d;
    s32 grew;
    TextBox *r;
    u8 *s;
    s32 stop;
    s32 line;
    s32 c;
    s32 vf;
    u8 k9;
    s32 k4;
    u8 k;
    s32 j;
    s32 *np;
    u8 isF6;
    u8 mode2;
    Obj6A8C0 *h;
    PadState *tb;

    pkt = (TextGlyphPoly *)Sys_State.packet.addr;
    slots = (TextBoxKids *)a0->u34.children;
    wk = (TextBoxWork *)a0->work;
    tb = Pad_State;
    row = 0;
    do {
        if (wk->rec[row].inUse != 0) {
            r = &wk->rec[row];
            nFA = 0;
            nFB = 0;
            nF9 = 0;
            nF8 = 0;
            nF6 = 0;
            nF5 = 0;
            nF4b = 0;
            nF4a = 0;
            s = (u8 *)r->text;
            nF4c = line = 0;
            pos = *(Pair54 *)&r->x;
            nF4d = 0;
            ot = Sys_State.otLayers.u[r->otIndex];
            page = 0;
            r->color = r->baseColor;
            if (r->waitingInput == 0 && r->charDelay != 0) {
                r->delayTimer += Sys_State.frameDelta;
                if (r->delayTimer >= r->charDelay) {
                    r->visibleChars++;
                    r->delayTimer -= r->charDelay;
                }
            }
            if (r->bigFont != 0) {
                glyph.field_0 = 8;
                glyph.field_2 = 0xD;
                cell.field_0 = 9;
                cols = 0xD;
                cell.field_2 = 0xE;
                font[0] = Gfx_FindOrLoadTexSlot(0x1100000);
                font[1] = Gfx_FindOrLoadTexSlot(0x1100000);
            } else {
                glyph.field_0 = 7;
                glyph.field_2 = 9;
                cell.field_0 = 7;
                cols = 0x11;
                cell.field_2 = 0xA;
                font[0] = Gfx_FindOrLoadTexSlot(0x13A0000);
                font[1] = Gfx_FindOrLoadTexSlot(0x13A0000);
            }
            Text_ReturnStack.count = 0;
            stop = 0;
            grew = 0;
            do {
                switch (*s) {
                case 0xFF:
                    vf = Text_PopReturn();
                    if (vf == 0) {
                        r->charDelay = 0;
                        r->finished = 1;
                        stop = 1;
                        break;
                    }
                    s = (u8 *)vf - 1;
                    line--;
                    break;
                case 0xFE:
                    pos.field_0 = r->x;
                    pos.field_2 += r->lineAdvance;
                    break;
                case 0xFD:
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                case 0xFC:
                    r->text = (s32)(s + 1);
                    r->visibleChars = 0;
                    r->cmdFADone = 0;
                    r->cmdFBDone = 0;
                    r->cmdF9Done = 0;
                    r->cmdF6Done = 0;
                    r->pausesDone = 0;
                    r->cmdF4TurnDone = 0;
                    r->cmdF4ObjDone = 0;
                    r->cmdF4TaskDone = 0;
                    r->soundsDone = 0;
                    break;
                case 0xFB:
                    if (r->cmdFBDone == nFB) {
                        if (tb[r->padIndex].cross > 0) {
                            stop = 1;
                            r->cmdFBDone = nFB + 1;
                            r->waitingInput = 0;
                            Snd_PlayById(0x13, 0);
                        } else {
                            stop = 1;
                            wk->blinkTimer += Sys_State.frameDelta;
                            if (wk->blinkTimer >= 0x18) {
                                wk->blinkTimer -= 0x18;
                            }
                            c = ((wk->blinkTimer / 6) & 3) + 0x4F;
                            r->waitingInput = 1;
                            goto draw;
                        }
                    }
                    nFB++;
                    break;
                case 0xFA:
                    s++;
                    if (r->cmdFADone == nFA) {
                        switch (a0->stateLevel1) {
                        default:
                        case 0:
                            Snd_PlayById((*s & 1) ? 0x38 : 0x37, 0);
                            switch (*s) {
                            case 0:
                                Task_Create(4, (s32 *)&slots->box[row], 0);
                                r->x = -0x90;
                                r->y = 0x34;
                                break;
                            case 2:
                                Task_Create(4, (s32 *)&slots->box[row], 1);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 6:
                                Task_Create(4, (s32 *)&slots->box[row], 3);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 4:
                                Task_Create(4, (s32 *)&slots->box[row], 2);
                                r->x = -0x90;
                                r->y = 0x12;
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                if (slots->box[row] != 0) {
                                    Task_SetState0(slots->box[row], 2);
                                }
                                Task_NextState1(a0);
                                break;
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            if (slots->box[row]->stateLevel1 == 1) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        case 2:
                            if (slots->box[row] == 0) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        }
                    }
                    nFA++;
                    break;
                case 0xF9:
                    s++;
                    k9 = *s;
                    if (k9 & 1) {
                        if (r->cmdF9Done == nF9) {
                            if (slots->num[(k9 >> 1) & 1] != 0) {
                                Task_SetState0(slots->num[(k9 >> 1) & 1], 2);
                            }
                            r->cmdF9Done++;
                            Snd_PlayById(0x3A, 0);
                        }
                    } else if (r->cmdF9Done == nF9) {
                        num[1] = (k9 >> 1) & 1;
                        s++;
                        num[0] = *s++ * 100;
                        num[0] += *s++ * 10;
                        num[0] += *s;
                        if (slots->num[num[1]] != 0) {
                            Text_PortraitSetImage(slots->num[num[1]], num[0]);
                        } else {
                            Task_Create(5, (s32 *)&slots->num[num[1]], (s32)num);
                        }
                        r->cmdF9Done++;
                        Snd_PlayById(0x39, 0);
                    } else {
                        s += 3;
                    }
                    nF9++;
                    break;
                set1:
                    r->choiceCursor = 1;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                set0:
                    r->choiceCursor = 0;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                case 0xF8:
                    s++;
                    if (r->choicesDone == nF8) {
                        switch (*s) {
                        default:
                        case 0:
                            stop = 1;
                            r->waitingInput = 1;
                            if (tb[r->padIndex].pressed & 0x6000) {
                                goto set1;
                            }
                            if (tb[r->padIndex].pressed & 0x9000) {
                                goto set0;
                            }
                            if (tb[r->padIndex].cross > 0) {
                                r->waitingInput = 0;
                                r->choicesDone++;
                                Flag_Set(0x10, 1);
                                Flag_Set(0x11, r->choiceCursor);
                                Snd_PlayById(0xA, 0);
                            }
                        cntF8:
                            nF8++;
                            goto next;
                        case 1:
                            c = 0x53;
                            if (r->choiceCursor == 0) {
                                goto draw;
                            }
                            break;
                        case 2:
                            c = 0x53;
                            if (r->choiceCursor == 1) {
                                goto draw;
                            }
                            break;
                        }
                    }
                    pos.field_0 += r->charAdvance;
                    break;
                case 0xF6:
                case 0xF7:
                    isF6 = *s == 0xF6;
                    mode2 = Sys_State.gameMode / 256 == 2;
                    s++;
                    if (r->cmdF6Done == nF6) {
                        switch (a0->stateLevel1) {
                        case 0:
                        default:
                            for (j = 0, np = nums; j < 3; j++) {
                                *np = *s++ * 100;
                                *np += *s++ * 10;
                                *np += *s++;
                                np++;
                            }
                            if (mode2) {
                                Stg40_TextObjCommand(nums);
                            } else {
                                h = Stg20_FindWalkerByDigiId(nums[0]);
                                wk->moveActor = h;
                                Stg20_WalkerWarpToCell(h, &nums[1]);
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            break;
                        }
                        if (mode2 == 0) {
                            if (isF6 == 0 || Stg20_WalkerIsPathDone(wk->moveActor) != 0) {
                                goto advF6;
                            }
                            goto nextF6;
                        }
                        if (Stg40_IsTextObjCmdBusy() != 0) {
                            goto nextF6;
                        }
                    advF6:
                        r->waitingInput = 0;
                        r->cmdF6Done++;
                        Task_SetState1(a0, 0);
                    } else {
                        s += 8;
                    }
                nextF6:
                    nF6++;
                    break;
                case 0xF5:
                    if (r->pausesDone == nF5) {
                        if (wk->waitTimer == 0x1E) {
                            stop = 1;
                            r->pausesDone = nF5 + 1;
                            r->waitingInput = 0;
                            wk->waitTimer = 0;
                        } else {
                            stop = 1;
                            wk->waitTimer++;
                            r->waitingInput = 1;
                        }
                    }
                    nF5++;
                    break;
                case 0xF4:
                    s++;
                    k4 = *s;
                    s++;
                    if (k4 < 0x10) {
                        if (r->cmdF4ObjDone == nF4a) {
                            s32 d0, d1;
                            d0 = *s++;
                            d1 = *s++;
                            h = Stg20_FindWalkerByDigiId(d0 * 100 + d1 * 10 + *s);
                            if (h != 0) {
                                Stg20_WalkerSetAnim(h, k4 + 0x1E);
                            }
                            r->cmdF4ObjDone++;
                        } else {
                            s += 2;
                        }
                        nF4a++;
                    } else if (k4 < 0x20) {
                        if (r->cmdF4TurnDone == nF4b) {
                            s32 n;
                            n = *s++ * 100;
                            n += *s++ * 10;
                            do {} while (0);
                            k4 = (k4 - 0x10) << 10;
                            h = Stg20_FindWalkerByDigiId(n + *s);
                            if (h != 0) {
                                h->transform->rotY = k4;
                            }
                            r->cmdF4TurnDone++;
                        } else {
                            s += 2;
                        }
                        nF4b++;
                    } else if (k4 < 0x30) {
                        if (r->cmdF4TaskDone == nF4c) {
                            switch (a0->stateLevel1) {
                            case 0:
                            default:
                                num[0] = k4 & 0xF;
                                num[1] = 0;
                                Task_Create(0x16, (s32 *)&slots->task, (s32)num);
                                a0->stateLevel1++;
                                r->waitingInput = 1;
                                break;
                            case 1:
                                s += 2;
                                if (slots->task == 0) {
                                    a0->stateLevel1 = 0;
                                    r->waitingInput = 0;
                                    r->cmdF4TaskDone++;
                                }
                                break;
                            }
                        } else {
                            s--;
                        }
                        nF4c++;
                    } else if (k4 < 0x40) {
                        r->color = k4 & 0xF;
                        s--;
                    } else {
                        k4 &= 0xF;
                        if (r->soundsDone == nF4d) {
                            if (k4 != 7) {
                                Snd_PlayById(Text_SfxIds[k4], 0);
                            }
                            r->soundsDone++;
                            if (k4 == 4) {
                                Stg20_StartBgShake();
                            }
                        }
                        s--;
                        nF4d++;
                    }
                    break;
                case 0xF3:
                    stop = 1;
                    s++;
                    switch (a0->stateLevel1) {
                    case 0:
                    default:
                        Gfx_FadeOutToBlack(0xA);
                        Task_NextState1(a0);
                        break;
                    case 1:
                        break;
                    }
                    if (++a0->stateLevel2 >= 0x19) {
                        if (*s == 0xFC) {
                            Sys_State.nextGameMode = 0x605;
                        } else if (*s == 0xFD) {
                            Sys_State.nextGameMode = 0x500;
                        } else if (*s == 0xFE) {
                            Sys_State.nextGameMode = 0x404;
                        } else if (*s == 0xFF) {
                            Sys_State.nextGameMode = 0x405;
                        } else {
                            Sys_State.nextGameMode = *s + 0x300;
                        }
                        s++;
                        Sys_State.modeArg = *s;
                    }
                    break;
                case 0xF2:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        Text_PushReturn((s32)(s + 1));
                        line--;
                        s = (u8 *)Item_GetNameText(n) - 1;
                    }
                    break;
                case 0xF1:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        Text_PushReturn((s32)(s + 1));
                        line--;
                        s = Digi_GetDefaultName(n) - 1;
                    }
                    break;
                case 0xF0:
                    s++;
                    k = *s;
                    Text_PushReturn((s32)(s + 1));
                    switch (k) {
                    case 0:
                        s = &Save_GameState.field_14 - 1; /* text before the player name */
                        break;
                    case 5:
                        s = &Save_GameState.field_D1 - 1; /* text before the name at 0xD1 */
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        {
                            s32 *args = &r->strArg0;
                            s32 jj = k - 1;
                            s = (u8 *)args[jj] - 1;
                        }
                        break;
                    default:
                        s = Text_BuiltinStrings[k - 6] - 1;
                        break;
                    }
                    line--;
                    break;
                case 0xEF:
                    do {
                        s++;
                        c = *s + 0xF0;
                        goto draw;
                    } while (0);
                default:
                    c = *s;
                draw:
                    if (r->bigFont != 0) {
                        if ((s16)c >= 0x88) {
                            c -= 0x88;
                            page = 1;
                        } else {
                            page = 0;
                        }
                    }
                    pkt->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
                    pkt->tag.b.len = 9;
                    pkt->c.code = 0x2C;
                    pkt->x0 = pkt->x2 = pos.field_0;
                    pkt->x1 = pkt->x3 = pkt->x0 + glyph.field_0;
                    pkt->y0 = pkt->y1 = pos.field_2;
                    pkt->y2 = pkt->y3 = pkt->y0 + glyph.field_2;
                    pkt->u0 = pkt->u2 = font[page]->uOffset + ((s16)c % cols) * cell.field_0;
                    pkt->u1 = pkt->u3 = pkt->u0 + glyph.field_0;
                    pkt->v0 = pkt->v1 = ((s16)c / cols) * cell.field_2;
                    pkt->v2 = pkt->v3 = pkt->v0 + glyph.field_2;
                    pkt->clut = ((font[page]->vramY + (r->color + 0xF8)) << 6) | ((font[page]->vramX >> 4) & 0x3F);
                    pkt->tpage = font[page]->tpage;
                    if (Sys_State.centerX.s == 0x140) {
                        pkt->x0 *= 2;
                        pkt->x1 *= 2;
                        pkt->x2 *= 2;
                        pkt->x3 *= 2;
                    }
                    if (Sys_State.centerY.s == 0xF0) {
                        pkt->y0 *= 2;
                        pkt->y1 *= 2;
                        pkt->y2 *= 2;
                        pkt->y3 *= 2;
                    }
                    pkt->tag.word = (pkt->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
                    *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                    pkt++;
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                }
            next:
                s++;
                if (stop != 0) {
                    break;
                }
            } while (r->charDelay == 0 || ++line < r->visibleChars);
        }
    } while (++row < 0x32);
    Sys_State.packet.addr = (s32)pkt;
}


void Text_Close(s32 *slot) {
    TaskEntry *e;
    Actor *a;
    s32 i;
    TextBox *r;
    Actor **q;

    if (*slot == -1) {
        return;
    }
    e = Task_FindFirst(9, -1, -1);
    if (e != 0) {
        i = *slot;
        r = &e->work[i];
        q = &e->children[i];
        r->inUse = 0;
        a = q[1];
        if (a != 0) {
            Task_SetState0(a, 3);
        }
        *slot = -1;
    }
}


void Text_Open(void *arg0, TextOpenArgs *arg1) {
    TextOpenSrc *src = (TextOpenSrc *)arg1;
    TaskEntry *r;
    TextBox *base;
    TextBox *p;
    TextBox *rec;
    s32 i;

    r = Task_FindFirst(9, -1, -1);
    if (r == 0) {
        return;
    }
    i = 0;
    base = r->work;
    Text_Close(arg0);

    for (p = base; i < 0x32; i++, p++) {
        if (p->inUse == 0) {
            break;
        }
    }

    if (src->charAdvance == 0) {
        if (src->bigFont != 0) {
            src->charAdvance = 9;
        } else {
            src->charAdvance = 7;
        }
    }
    if (src->lineAdvance == 0) {
        if (src->bigFont != 0) {
            src->lineAdvance = 0xF;
        } else {
            src->lineAdvance = 0xA;
        }
    }

    rec = &base[i];
    rec->inUse = 1;
    rec->bigFont = *(u8 *)&src->bigFont;
    rec->color = *(u8 *)&src->color;
    rec->text = src->text;
    rec->x = src->x - 0xA0;
    rec->y = src->y - 0x78;
    rec->charAdvance = *(u8 *)&src->charAdvance;
    rec->lineAdvance = *(u8 *)&src->lineAdvance;
    rec->charDelay = *(u16 *)&src->charDelay;
    rec->strArg0 = src->strArg0;
    rec->strArg1 = src->strArg1;
    rec->strArg2 = src->strArg2;
    rec->strArg3 = src->strArg3;
    rec->baseColor = *(u8 *)&src->color;
    rec->delayTimer = *(u8 *)&src->charDelay;
    rec->visibleChars = 0;
    rec->finished = 0;
    rec->cmdFADone = 0;
    rec->cmdFBDone = 0;
    rec->waitingInput = 0;
    rec->cmdF9Done = 0;
    rec->choicesDone = 0;
    rec->choiceCursor = 0;
    rec->cmdF6Done = 0;
    rec->pausesDone = 0;
    rec->cmdF4TurnDone = 0;
    rec->cmdF4ObjDone = 0;
    rec->cmdF4TaskDone = 0;
    rec->soundsDone = 0;
    rec->padIndex = 0;
    rec->otIndex = 0;

    *(s32 *)arg0 = i;
}

s32 Text_IsFinished(s32 id) {
    TaskEntry *p;

    if (id == -1) {
        return 1;
    }
    p = Task_FindFirst(9, -1, -1);
    if (p != 0) {
        TextBox *w = &p->work[id];
        return w->finished;
    }
    return 0;
}

void Text_SetColor(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->baseColor = a1;
        r->color = a1;
    }
}

void Text_SetInputPad(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->padIndex = a1;
    }
}

void Text_SetOtLayer(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->otIndex = a1;
    }
}

void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3) {
    TextOpenArgs local;
    local.text = (s32)Cd_GetFileEntry(a1 + 0x1FD0000);
    local.bigFont = 0;
    local.color = a2;
    local.x = a3.lo;
    local.y = a3.hi;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = 0;
    Text_Open(a0, &local);
}

void Text_OpenMsgClearChoice(void *arg0, s32 arg1) {
    TextOpenArgs local;
    local.bigFont = 1;
    local.color = 0;
    local.x = 0;
    local.y = 0;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.text = arg1;
    local.charDelay = 1;
    Text_Open(arg0, &local);
    Flag_Set(0x10, 0);
}

void Mem_FillWordsNeg1(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        *arg0++ = -1;
    }
}

void Text_CloseArray(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        Text_Close(arg0);
        arg0++;
    }
}

void Gpu_ClearScreens(void) {
    RECT r;
    s32 i;

    for (i = 0; i < 2; i++) {
        r = Sys_State.disp[i].disp;
        ResetGraph(1);
        ClearImage2((s32)&r, 0, 0, 0);
        DrawSync(0);
    }
}


void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Sys_State.draw[i].isbg = 1;
        Sys_State.draw[i].r0 = a0;
        Sys_State.draw[i].g0 = a1;
        Sys_State.draw[i].b0 = a2;
    }
}

void Gpu_DisableBgClear(void) {
    Sys_State.draw[0].isbg = 0;
    Sys_State.draw[1].isbg = 0;
}

void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter) {
    SysState *g = &Sys_State;
    s32 n = 0;
    s32 hw = w / 2;
    s32 hh = h / 2;

    g->centerX.s = hw;
    g->centerY.s = hh;
    switch (mode) {
    default:
    case 0:
        SetDefDrawEnv(&g->draw[0], 0, h, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, h, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = h + hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 1:
        SetDefDrawEnv(&g->draw[0], 0, 0, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, 0, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 2:
        if (inter != 0) {
            SetDefDrawEnv(&g->draw[0], 480, 0, 320, 480);
            SetDefDrawEnv(&g->draw[1], 0, 0, 320, 480);
            SetDefDispEnv(&g->disp[0], 0, 0, 320, 480);
            g->disp[0].isrgb24 = 1;
            SetDefDispEnv(&g->disp[1], 480, 0, 320, 480);
            g->disp[1].isrgb24 = 1;
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
        } else {
            SetDefDrawEnv(&g->draw[0], w, 0, w, h);
            SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
            SetDefDispEnv(&g->disp[0], 0, 0, w, h);
            SetDefDispEnv(&g->disp[1], w, 0, w, h);
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
    Gfx_SetTexSlotCount(n);
    GsInit3D();
    SetGeomOffset(0, 0);
}

void Gfx_FadeInFromBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    Sys_State.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeInFromWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    Sys_State.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeClear(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 0;
}

void Gfx_FadeSetBlack(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 1;
}

void Gfx_DrawFade(void) {
    GfxFadePkt *p;
    GfxFadeMode *q;
    GfxPartOTag *ot;
    s32 w;
    s32 h;
    u8 c;
    s32 abr;

    if (Sys_State.packet.work == 0) {
        return;
    }
    for (;;) {
        switch (Gfx_FadeState.mode) {
        default:
        case 0:
            Sys_State.fadeLevel = 0;
            return;
        case 1:
            Sys_State.fadeLevel = 0xFF;
            goto check;
        case 2:
            Sys_State.fadeLevel -= Gfx_FadeState.speed;
            if (Sys_State.fadeLevel > 0) {
                goto draw;
            }
            Sys_State.fadeLevel = 0;
            Gfx_FadeState.mode = 0;
            continue;
        case 3:
            Sys_State.fadeLevel += Gfx_FadeState.speed;
            if (Sys_State.fadeLevel < 0xFF) {
                goto check;
            }
            Sys_State.fadeLevel = 0xFF;
            Gfx_FadeState.mode = 1;
            continue;
        }
    }
check:
    if (Sys_State.fadeLevel == 0) {
        return;
    }
draw:
    abr = 2;
    q = (GfxFadeMode *)Sys_State.packet.work;
    p = (GfxFadePkt *)q;
    ot = (GfxPartOTag *)Sys_State.otLayers.s[0];
    p->t.len = 5;
    p->code = 0x2A;
    c = Sys_State.fadeLevel;
    p->g = c;
    p->b = c;
    p->r = c;
    w = Sys_State.centerX.lo;
    p->x0 = p->x2 = -w;
    p->x1 = p->x3 = w;
    h = Sys_State.centerY.lo;
    p->y0 = p->y1 = -h;
    p->y2 = p->y3 = h;
    p->t.addr = ot->addr;
    ot->addr = (u32)p;
    q = &p->m;
    if (Gfx_FadeState.additive != 0) {
        abr = 1;
    }
    q->t.len = 1;
    q->mode = (abr << 5) | 0xE1000400;
    p->m.t.addr = ot->addr;
    ot->addr = (u32)q;
    q = (GfxFadeMode *)(p + 1);
    Sys_State.packet.work = (ActorWork *)q;
}

void Gpu_SetLayerOtPtrs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        Sys_State.otLayerLen[i] = Gpu_OtLayerLens[Gpu_OtBufs[2].entries[0]][i];
        Sys_State.otLayers.s[i] = &Gpu_OtBufs[Sys_State.bufIndex].entries[Gpu_OtLayerOffsets[Gpu_OtBufs[2].entries[0]][i]];
    }
}

void Gpu_SetOtLayout(s32 arg0) {
    Gpu_OtBufs[2].entries[0] = arg0;
}

void Gpu_ClearOt(s32 arg0) {
    ClearOTagR(&Gpu_OtBufs[arg0], 0x100C);
}

s32 Gpu_DrawOt(s32 arg0) {
    s32 *p = (s32 *)&Gpu_OtBufEnds[arg0];
    return DrawOTag(&p[-1]);
}

void Gpu_SkipEmptyOtEntries(s32 arg0) {
    u32 *ot = (u32 *)&Gpu_OtBufEnds[arg0];
    u32 *end = (u32 *)&Gpu_OtBufEnds[arg0 - 1];
    u32 *p;
    u32 *q;
    u32 m;

    p = ot - 1;
    m = 0xFFFFFF;
    while (p != end) {
        q = p - 1;
        if ((*p & m) == ((u32)q & m)) {
            while ((*q & m) == ((u32)(q - 1) & m)) {
                q--;
            }
            *p = (u32)q & m;
        }
        p = q;
    }
}

/* Unnamed: returns 0, no callers, no table ref. */
s32 func_8001C92C(void) {
    return 0;
}

void Gpu_FreePrimBufs(void) {
    if (Gpu_PrimBufs[0] != 0) {
        Mem_Free(Gpu_PrimBufs[0]);
        Gpu_PrimBufs[0] = 0;
        Mem_Free(Gpu_PrimBufs[1]);
        Gpu_PrimBufs[1] = 0;
    }
    Sys_State.packet.addr = 0;
}

void Gpu_ResetPrimBuf(void) {
    Sys_State.packet.work = Gpu_PrimBufs[Sys_State.bufIndex];
}

extern s32 Mem_Alloc(s32, s32);

void Gpu_AllocPacketBufs(s32 a0) {
    Gpu_PrimBufs[2] = (ActorWork *)a0;
    Gpu_PrimBufs[0] = (ActorWork *)Mem_Alloc(a0, 2);
    Gpu_PrimBufs[1] = (ActorWork *)Mem_Alloc(a0, 2);
    Sys_State.packet.work = Gpu_PrimBufs[Sys_State.bufIndex];
}

GfxTexSlot *Gfx_GetTexSlot(s32 arg0) {
    return &Gfx_TexSlots[arg0];
}

void Gfx_InitTexSlots(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Gfx_TexSlots[i].vramX = 0x3E0 - (i / 2) * 32;
        Gfx_TexSlots[i].index = i;
        Gfx_TexSlots[i].vramY = (i & 1) << 8;
        Gfx_TexSlots[i].fileId = 0;
        Gfx_TexSlots[i].lastUsed = 0;
        Gfx_TexSlots[i].colorMode = 0;
        Gfx_TexSlots[i].uOffset = 0;
        Gfx_TexSlots[i].tpage = 0;
    }
}

s32 Gfx_GetTimPixelMode() {
    return Cd_GetFileEntry()->packedId & 7;
}

void Gfx_LoadTexSlotImage(GfxTexSlot *a0) {
    u32 *p;
    u32 flags;
    RECT clut;
    RECT img;
    s32 hasClut;
    s32 mode;

    p = (u32 *)Cd_GetFileEntry(a0->fileId);
    p++;
    flags = *p++;
    hasClut = flags & 8;
    mode = flags & 7;
    if (hasClut) {
        if (mode) {
            clut.x = 0;
            clut.y = a0->index + 0x1E0;
            clut.w = 0x100;
            clut.h = 1;
            LoadImage((s32)&clut, (s32)((TimBlk *)p + 1));
        }
        p = (u32 *)((u8 *)p + *p);
    }
    img.x = a0->vramX;
    img.y = a0->vramY;
    img.w = ((TimBlk *)p)->rect.w;
    img.h = ((TimBlk *)p)->rect.h;
    LoadImage((s32)&img, (s32)((TimBlk *)p + 1));
}


GfxTexSlot *Gfx_FindOrLoadTexSlot(s32 id) {
    GfxTexSlot *e;
    GfxTexSlot *p;
    s32 i;
    s32 j;
    u32 best;
    s32 idx;
    s32 n;
    s32 tp;
    s32 t;

    p = Gfx_TexSlots;
    for (i = 0; i < 0x40; i++, p++) {
        if (p->fileId == -1) {
            continue;
        }
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == id) {
            p->lastUsed = Sys_State.frameCount;
            return p;
        }
    }
    best = -1;
    idx = 0;
    if (Gfx_GetTimPixelMode(id)) {
        n = 0x20;
        tp = 1;
    } else {
        n = 0x40;
        tp = 0;
    }
    e = Gfx_TexSlots;
    for (j = 0; j < n; j++, e++) {
        if (e->fileId == -1) {
            continue;
        }
        if (e->fileId == -2) {
            continue;
        }
        if (e->fileId == 0) {
            idx = j;
            break;
        }
        if (e->lastUsed < best) {
            best = e->lastUsed;
            idx = j;
        }
    }
    e = &Gfx_TexSlots[idx];
    e->fileId = id;
    e->lastUsed = Sys_State.frameCount;
    e->colorMode = tp;
    t = e->index & 2;
    e->uOffset = t == 0;
    if (tp) {
        e->uOffset <<= 6;
    } else {
        e->uOffset <<= 7;
    }
    e->tpage = (tp << 7) | ((e->vramY & 0x100) >> 4) | ((e->vramX & 0x3FF) >> 6) | ((e->vramY & 0x200) << 2);
    Gfx_LoadTexSlotImage(e);
    return e;
}

void Gfx_SetTexSlotCount(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        GfxTexSlot *p = Gfx_GetTexSlot(i);
        if (i >= arg0) {
            p->fileId = -1;
        } else {
            if (p->fileId == -1) p->fileId = 0;
        }
    }
}

s32 Gfx_ReserveTexSlot(void) {
    u32 min = -1;
    s32 best = 0;
    s32 i;
    GfxTexSlot *p = Gfx_TexSlots;

    for (i = 0; i < 24; i++, p++) {
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == 0) {
            best = i;
            break;
        }
        if ((u32)p->lastUsed < min) {
            min = p->lastUsed;
            best = i;
        }
    }
    p = &Gfx_TexSlots[best];
    p->fileId = -2;
    p->lastUsed = Sys_State.frameCount;
    p->colorMode = 0;
    p->uOffset = ((p->index & 2) == 0) << 7;
    p->tpage = ((p->vramY & 0x100) >> 4) | ((p->vramX & 0x3FF) >> 6) | ((p->vramY & 0x200) << 2);
    return (s32)p;
}

void Gfx_ReleaseTexSlot(s32 *arg0) {
    if (*arg0 == -2) {
        *arg0 = 0;
    }
}

void Gfx_DrawPartSprites(GfxPartSprite *s, GfxPartOTag *ot) {
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPkt *p;
    u16 tpage;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(s->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId & 0xFFFF0000);
    p = (GfxPartPkt *)Sys_State.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != s->partGroup) {
            continue;
        }
        p->s.c = s->color;
        p->s.tag.len = 4;
        p->s.c.code = 0x64;
        if (e->blend & 0x80) {
            p->s.c.code = 0x66;
            tpage = t->tpage + ((e->blend & 3) << 5);
        } else {
            tpage = t->tpage;
        }
        p->s.x0 = e->x + s->x;
        p->s.u0 = e->u + t->u;
        p->s.w = e->w;
        p->s.y0 = e->y + s->y;
        p->s.v0 = e->v;
        p->s.h = e->h;
        if (p->s.h == 0) {
            p->s.h--;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->s.clut = (e->clutRow + y + s->clutRow) << 6;
        } else {
            p->s.clut = ((e->clutY + t->clutY + e->clutRow + s->clutRow) << 6) |
                       (((e->clutX + t->clutX) >> 4) & 0x3F);
        }
        p->s.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->s + 1);
        p->t.tag.len = 1;
        p->t.code = 0xE1000600 | (tpage & 0x9FF);
        p->t.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->t + 1);
    }
    Sys_State.packet.addr = (s32)p;
}


void Gfx_DrawPartQuadsRot(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPolyFT4 *p;
    GfxPartRotXY out;
    SVec1D104 sv[4];
    s32 i;
    s32 u;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(((GfxPartSprite *)arg0)->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(((GfxPartSprite *)arg0)->fileId & 0xFFFF0000);
    p = (GfxPartPolyFT4 *)Sys_State.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != ((GfxPartSprite *)arg0)->partGroup) {
            continue;
        }
        p->c = ((GfxPartSprite *)arg0)->color;
        p->tag.len = 9;
        p->c.code = 0x2C;
        if (e->blend & 0x80) {
            p->c.code = 0x2E;
            p->v[1].extra = t->tpage | ((e->blend & 3) << 5);
        } else {
            p->v[1].extra = t->tpage;
        }
        sv[0].vx = sv[2].vx = e->x;
        sv[1].vx = sv[3].vx = e->x + e->w;
        sv[0].vy = sv[1].vy = e->y;
        if (e->h) sv[2].vy = sv[3].vy = e->y + e->h; else sv[2].vy = sv[3].vy = e->y + 0xFF;
        sv[0].vz = sv[1].vz = sv[2].vz = sv[3].vz = 0;
        for (i = 0; i < 4; i++) {
            ApplyMatrixSV(arg1, &sv[i], &out);
            p->v[i].x = out.vx + ((GfxPartSprite *)arg0)->x;
            p->v[i].y = out.vy + ((GfxPartSprite *)arg0)->y;
        }
        u = e->u + t->u;
        p->v[0].u = p->v[2].u = u;
        u += e->w;
        p->v[1].u = p->v[3].u = u;
        if (((GfxPartSprite *)arg0)->scaleX < 0) {
            p->v[1].u = p->v[3].u = u - 1;
        }
        if (p->v[1].u == 0) {
            p->v[1].u = p->v[3].u = 0xFF;
        }
        p->v[0].v = p->v[1].v = e->v;
        u = e->v + e->h;
        p->v[2].v = p->v[3].v = u;
        if (((GfxPartSprite *)arg0)->scaleY < 0) {
            p->v[2].v = p->v[3].v = u - 1;
        }
        if (p->v[2].v == 0) {
            p->v[2].v = p->v[3].v = 0xFF;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->v[0].extra = (e->clutRow + y + ((GfxPartSprite *)arg0)->clutRow) << 6;
        } else {
            p->v[0].extra = ((e->clutY + t->clutY + e->clutRow + ((GfxPartSprite *)arg0)->clutRow) << 6) |
                            (((e->clutX + t->clutX) >> 4) & 0x3F);
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
        p->tag.addr = ((GfxPartOTag *)arg2)->addr;
        ((GfxPartOTag *)arg2)->addr = (u32)p;
        p++;
    }
    Sys_State.packet.addr = (s32)p;
}


void Gfx_HidePartsByMask(GfxPartMaskView *p, s32 mask) {
    s32 i;

    for (i = 0; p[i].fileId != 0; i++) {
        if (p[i].partMask & mask) {
            p[i].visible = 0;
        } else {
            p[i].visible = 1;
        }
    }
}

void Gfx_SetPartsScale(GfxPartScaleView *p, s32 a1, s32 a2) {
    if (p->fileId == 0) {
        return;
    }
    do {
        if (a1 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleX = a1;
        if (a2 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleY = a2;
        p++;
    } while (p->fileId != 0);
}

void Gfx_SetPartsNumber(GfxPart *p, s32 mask, s32 n, s32 val) {
    u8 d[8];
    GfxPart *q;
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
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                if (lead == 1 || i == n - 1 || d[i] != 0) {
                    lead = 1;
                    q->frame = d[i];
                } else {
                    q->frame = 0xFF;
                }
                i++;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
} /* identity matrix */
extern void Gfx_DrawPartSprites(GfxPartSprite *, GfxPartOTag *);
extern void Gfx_DrawPartQuadsRot(void *, void *, s32, s32);
extern void ScaleMatrix(Obj209 *, s32 *);

void Gfx_DrawPartsEx(void *arg0, s32 arg1) {
    Rec1D6B4 *s2 = (Rec1D6B4 *)arg0;
    s32 s3 = 0;
    s32 s4;

    if (arg1 != 0) {
        s32 f114 = Sys_State.centerY.s;
        s3 = 0;
        s3 = (Sys_State.centerX.s ^ 0x140) == s3;
        if (f114 == 0xF0) {
            s3 |= 2;
        }
    }
    if (s2->fileId == 0) {
        return;
    }
    do {
        s4 = Sys_State.otLayers.addr[s2->otLayer];
        if (s2->visible != 0) {
            if (s2->unscaled != 0) {
                if (s3 != 0) {
                    s2->rotZ = 0;
                    s2->rotY = 0;
                    s2->rotX = 0;
                    s2->scaleX = 0x1000;
                    s2->scaleY = 0x1000;
                } else {
                    Gfx_DrawPartSprites((GfxPartSprite *)s2, (GfxPartOTag *)s4);
                    goto Ladv;
                }
            }
            if (Gfx_PartRotCache.rotXY == *(s32 *)&s2->rotX &&
                Gfx_PartRotCache.rotZ == s2->rotZ &&
                Gfx_PartRotCache.scaleX == s2->scaleX &&
                Gfx_PartRotCache.scaleY == s2->scaleY) {
            } else {
                *(Agg1D6B4 *)&Gfx_PartRotCache = *(Agg1D6B4 *)&s2->rotX;
                Gfx_PartRotCache.scaleX = s2->scaleX;
                Gfx_PartRotCache.scaleY = s2->scaleY;
                RotMatrixYXZ(&Gfx_PartRotCache, (Obj209 *)&Gfx_PartRotCache.matrix);
                ScaleMatrix((Obj209 *)&Gfx_PartRotCache.matrix, &Gfx_PartRotCache.scaleX);
            }
            Gfx_DrawPartQuadsRot(s2, &Gfx_PartRotMatrix, s4, s3);
        }
    Ladv:
        s2 = (Rec1D6B4 *)((u8 *)s2 + 0x28);
    } while (s2->fileId != 0);
}

void Gfx_DrawParts(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 1);
}

void Gfx_DrawPartsNoResScale(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 0);
}

DigiBaseData *Digi_FindBaseData(id) s32 id; {
    DigiBaseData *p = (DigiBaseData *)Cd_GetFileOrNull(0xC6C);
    s16 v;

loop:
    v = p->id;
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

/* Unnamed: DIGIMNDT byte +3 (0..8), not rank/type/specialty (checked vs MetalKid RankId); only
 * use is an index in stag2000 func_8006A190's table, meaning unproven. */
u8 func_8001D910(s32 digiId) {
    return Digi_FindBaseData(digiId)->field_3;
}

u8 Digi_GetType(s32 digiId) {
    return Digi_FindBaseData(digiId)->u4.attrsLo & 0xF;
}

s32 Digi_GetRank(s32 digiId) {
    return (Digi_FindBaseData(digiId)->u4.field_4h >> 4) & 0xF;
}

s32 Digi_GetSpecialty(s32 digiId) {
    return (Digi_FindBaseData(digiId)->u4.field_4h >> 8) & 0xF;
}

u8 Digi_GetLearnedSkill(s32 digiId) {
    return Digi_FindBaseData(digiId)->learnedSkill;
}

s32 Digi_GetStatGrowth(s32 id, s32 k) {
    switch (k) {
    default:
    case 0:
        return Digi_FindBaseData(id)->u4.field_4h >> 12;
    case 1:
        return Digi_FindBaseData(id)->u6.growthLo & 0xF;
    case 2:
        return (Digi_FindBaseData(id)->u6.field_6h >> 4) & 0xF;
    case 3:
        return (Digi_FindBaseData(id)->u6.field_6h >> 8) & 0xF;
    case 4:
        return Digi_FindBaseData(id)->u6.field_6h >> 12;
    }
}
