#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"

/* Small data this file defines (.sdata, .sbss). Retail reaches it with %gp_rel here. */
s32 Snd_CurrentId = -1;
s32 Snd_SavedId;
/* .bss (game.h order) */
u8 Snd_SeqAttrTable[176 * 6 * 16];
SndSlot Snd_Slots[3];

/* Sound banks (SndBankDesc): VB file, VH file, then the SEQ/SEP entries, 0-ended. Each entry
 * is (resource file id << 16) | sub-entry index. */
u32 Snd_BankComm00[] = { 0x00E50000, 0x00E60000, 0x00E60001, 0x00E60002, 0x00E60003, 0x00E60004, 0x00000000 };
u32 Snd_BankMap001[] = { 0x07BE0000, 0x07BF0000, 0x07BF0001, 0x00000000 };
u32 Snd_BankMap002[] = { 0x07C00000, 0x07C10000, 0x07C10001, 0x00000000 };
u32 Snd_BankMap003[] = { 0x07C20000, 0x07C30000, 0x07C30001, 0x00000000 };
u32 Snd_BankMap004[] = { 0x07C40000, 0x07C50000, 0x07C50001, 0x00000000 };
u32 Snd_BankMap005[] = { 0x07C60000, 0x07C70000, 0x07C70001, 0x00000000 };
u32 Snd_BankMap006[] = { 0x07C80000, 0x07C90000, 0x07C90001, 0x00000000 };
u32 Snd_BankMap007[] = { 0x07CA0000, 0x07CB0000, 0x07CB0001, 0x00000000 };
u32 Snd_BankMap008[] = { 0x07CC0000, 0x07CD0000, 0x07CD0001, 0x00000000 };
u32 Snd_BankMap009[] = { 0x07CE0000, 0x07CF0000, 0x07CF0001, 0x00000000 };
u32 Snd_BankMap010[] = { 0x07D00000, 0x07D10000, 0x07D10001, 0x00000000 };
u32 Snd_BankMap011[] = { 0x07D20000, 0x07D30000, 0x07D30001, 0x00000000 };
u32 Snd_BankMap012[] = { 0x0D180000, 0x0D190000, 0x0D190001, 0x00000000 };
u32 Snd_BankSave00[] = { 0x0E330000, 0x0E350000, 0x0E350001, 0x00000000 };
u32 Snd_BankShop00[] = { 0x0D1C0000, 0x0D1D0000, 0x0D1D0001, 0x00000000 };
u32 Snd_BankBoss00[] = { 0x00E30000, 0x00E40000, 0x00E40001, 0x00000000 };
u32 Snd_BankBoss01[] = { 0x02670000, 0x02680000, 0x02680001, 0x00000000 };
u32 Snd_BankBoss02[] = { 0x02DD0000, 0x02DE0000, 0x02DE0001, 0x00000000 };
u32 Snd_BankBoss03[] = { 0x02DF0000, 0x02E00000, 0x02E00001, 0x00000000 };
u32 Snd_BankBoss04[] = { 0x02E90000, 0x02EA0000, 0x02EA0001, 0x00000000 };
u32 Snd_BankBoss05[] = { 0x02EB0000, 0x02EC0000, 0x02EC0001, 0x00000000 };
u32 Snd_BankBoss06[] = { 0x02ED0000, 0x02EE0000, 0x02EE0001, 0x00000000 };
u32 Snd_BankBoss07[] = { 0x02EF0000, 0x02F00000, 0x02F00001, 0x00000000 };
u32 Snd_BankVs2P00[] = { 0x0D4A0000, 0x0D4B0000, 0x0D4B0001, 0x00000000 };
u32 Snd_BankSeD00[] = { 0x07BD0000, 0x07BC0000, 0x07BC0001, 0x00000000 };
SndBankDesc *Snd_BankDescs[] = {
    0,
    (SndBankDesc *)Snd_BankComm00, (SndBankDesc *)Snd_BankMap001, (SndBankDesc *)Snd_BankMap002,
    (SndBankDesc *)Snd_BankMap003, (SndBankDesc *)Snd_BankMap004, (SndBankDesc *)Snd_BankMap005,
    (SndBankDesc *)Snd_BankMap006, (SndBankDesc *)Snd_BankMap007, (SndBankDesc *)Snd_BankMap008,
    (SndBankDesc *)Snd_BankMap009, (SndBankDesc *)Snd_BankMap010, (SndBankDesc *)Snd_BankMap011,
    (SndBankDesc *)Snd_BankMap012, (SndBankDesc *)Snd_BankSave00, (SndBankDesc *)Snd_BankShop00,
    (SndBankDesc *)Snd_BankBoss00, (SndBankDesc *)Snd_BankBoss01, (SndBankDesc *)Snd_BankBoss02,
    (SndBankDesc *)Snd_BankBoss03, (SndBankDesc *)Snd_BankBoss04, (SndBankDesc *)Snd_BankBoss05,
    (SndBankDesc *)Snd_BankBoss06, (SndBankDesc *)Snd_BankBoss07, (SndBankDesc *)Snd_BankVs2P00,
    (SndBankDesc *)Snd_BankSeD00,
};
s32 Snd_SlotBufSizes[3] = { 0x114D0, 0x13FE4, 0xBF44 };

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
#ifdef DW2_NATIVE
                if ((u32)src + n > (u32)PS1_RAM(0x801FFFFF)) {
                    n = (u32)PS1_RAM(0x801FFFFC) - (u32)src;
                }
#else
                if ((u32)src + n > 0x801FFFFF) {
                    n = 0x801FFFFC - (u32)src;
                }
#endif
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

#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void SsSetTableSize(void *, s16, s16);
extern void SsSetTickMode(s32);
extern void SsStart2();
extern void SsSetMVol(s16, s16);
extern void SsSetSerialAttr(s8, s8, s8);
extern void SsSetSerialVol(s8, s16, s16);
extern s16 SsUtSetReverbType(s16);
extern void SsUtSetReverbDepth(s16, s16);
extern void SsUtReverbOn();
#endif
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
