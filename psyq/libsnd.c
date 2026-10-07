#include "snd_native.h"
#include "libsnd.h"
#include "psyq_log.h"

/* libsnd (Psy-Q 4.7): init / start, tick mode, table setup, VAB open / transfer / close, SEP
 * open / play / stop / volume, reverb and attribute utilities. Translated from the retail asm
 * (asm/USA/main/nonmatchings/psyq); globals stay at their retail addresses. */

/* Retail globals */
#define D_8004FC18 0x8004FC18u /* reserved voice mask (SsUtAllKeyOff skips these voices) */
#define D_8004FC24 0x8004FC24u /* 16 halfwords copied to SPU 0x1F801D80.. by _SsInit */
#define D_8004FC48 0x8004FC48u /* tick mode (low 12 bits), later the tick rate */
#define D_8004FC4C 0x8004FC4Cu /* 1 = SS_NOTICK (game calls SsSeqCalledTbyT itself) */
#define D_8004FC50 0x8004FC50u /* tick function (SsSeqCalledTbyT) */
#define D_8004FC54 0x8004FC54u /* previous VBlank interrupt callback */
#define D_8004FC58 0x8004FC58u /* byte: 1 = tick from VSyncCallback */
#define D_8004FC59 0x8004FC59u /* byte: 1 = tick every second interrupt */
#define D_8004FC5A 0x8004FC5Au /* byte: interrupt number for the tick (0 VBlank, 6 RCnt2), 0x7F none */
#define D_8004FC5C 0x8004FC5Cu /* toggle of _SsSeqCalledTbyT_1per2 */
#define D_8004FC88 0x8004FC88u /* note pitch table (12 halfwords) */
#define D_8004FCA0 0x8004FCA0u /* fine pitch table (128 halfwords) */
#define D_80010A34 0x80010A34u /* "Can't Open Sequence data any more\n\n" */
#define D_80010A64 0x80010A64u /* "This is not SEP Data.\n" */
#define D_80061BB0 0x80061BB0u /* sequence event handler table */
#define D_80061C44 0x80061C44u
#define D_80061C48 0x80061C48u /* bit per score slot in use (bits >= s_max set as used) */
#define Snd_TicksPerSec 0x80061C4Cu
#define Snd_SeqScores 0x80061C50u /* 32 pointers: score slot -> its sequences (stride 0xB0) */
#define Snd_MarkCallbacks 0x80061CD0u /* 32 x 16 words */
#define D_800624D0 0x800624D0u /* halfword: score slots (s_max) */
#define D_800624D2 0x800624D2u /* halfword: sequences per slot (t_max) */
#define D_800624EA 0x800624EAu /* voice table, stride 0x38 */
#define D_800624EE 0x800624EEu
#define D_800624F8 0x800624F8u
#define D_800624FA 0x800624FAu
#define D_800624FC 0x800624FCu
#define D_800624FE 0x800624FEu
#define D_8006251E 0x8006251Eu
#define D_80062C18 0x80062C18u /* SpuReverbAttr for SsUtSetReverb* */
#define D_80062C30 0x80062C30u /* per VAB: program table address */
#define D_80062C70 0x80062C70u /* per VAB: VH header address */
#define D_80062CB8 0x80062CB8u /* per VAB: tone table address */
#define D_80062CFA 0x80062CFAu /* halfword: max programs of the last opened VAB (64 / 128) */
#define D_80062CFC 0x80062CFCu /* program attribute pointer set by _SsVmVSetUp */
#define D_80062D08 0x80062D08u /* tone table pointer set by _SsVmVSetUp */
#define D_80062D0C 0x80062D0Cu /* byte: voice count */
#define D_80062D10 0x80062D10u
#define D_80062D1F 0x80062D1Fu /* byte: tone base set by _SsVmVSetUp */
#define D_80062D30 0x80062D30u /* halfword: current voice for _SsVmKeyOffNow */
#define D_80062D38 0x80062D38u /* 16 bytes: VAB state 0 free, 1 open / sent, 2 header only */
#define D_80062D50 0x80062D50u /* per VAB: body size */
#define D_80062D90 0x80062D90u /* halfword: VABs open */
#define D_80062D98 0x80062D98u /* per VAB: SPU address of the body */

/* Address of score slot sep, sequence seq (the 0xB0 byte per sequence structure). */
static uint32_t snd_score(uint32_t slot_ptr_addr, int32_t seq) {
    return (uint32_t)LW(slot_ptr_addr) + (uint32_t)(seq * 0xB0);
}

/* SsInit 0x80032914 */
void SsInit(void) {
    PSYQ_LOG("");
    Psx_ResetCallback();
    SpuInit();
    SpuClearReverbWorkArea(7);
    _SsInit();
}

/* _SsInit 0x80032874 */
int _SsInit(void) {
    int32_t i, j;
    uint32_t src = D_8004FC24, dst = 0x1F801D80u;

    /* SPU main volume / reverb / key registers from the default table */
    for (i = 0; i < 0x10; i++) {
        SH(dst, LHU(src));
        src += 2;
        dst += 2;
    }
    _SsVmInit(0x18);
    for (i = 0; i < 0x20; i++) {
        for (j = 0xF; j >= 0; j--)
            SW(Snd_MarkCallbacks + (uint32_t)i * 0x40 + (uint32_t)j * 4, 0);
    }
    SW(Snd_TicksPerSec, 0x3C);
    SW(D_80061C48, 0);
    SW(D_80061C44, 0);
    return 0;
}

/* SsStart2 0x800352C4 */
void SsStart2(void) {
    PSYQ_LOG("");
    _SsStart(0);
}

/* _SsStart 0x80035074 */
int _SsStart(int a0) {
    uint32_t s2 = 0xF2000002u; /* RCntCNT2 */
    int32_t s1 = 0x44E8;
    int32_t v1, t;
    uint32_t fn;
    int32_t irq;

    /* retail: empty delay loop of 1000 iterations here */
    v1 = LW(D_8004FC48);
    SB(D_8004FC5A, 6);
    SB(D_8004FC58, 0);
    SB(D_8004FC59, 0);
    SW(D_8004FC54, 0);
    if (v1 == 2) {
    } else if (v1 == 0) {
        SB(D_8004FC5A, 0x7F);
        return 0x7F;
    } else if (v1 == 3) {
        s1 = 0x89D0;
    } else if (v1 == 5) {
        SB(D_8004FC5A, 0);
        if (a0 == 0) {
            SB(D_8004FC58, 1);
        } else {
            s2 = 0xF2000003u; /* RCntCNT3 */
            s1 = 1;
        }
    } else {
        if (LW(D_8004FC4C) != 0)
            return LW(D_8004FC4C);
        t = LW(D_8004FC48);
        if (t == 0) {
            Psx_printf(SND_ADDR("_SsStart: tick rate 0\n"));
            return 0;
        }
        if (t < 0x46) {
            s1 = 0x204CC0 / t;
            SB(D_8004FC59, LBU(D_8004FC59) + 1);
        } else {
            s1 = 0x409980 / t;
        }
    }

    if (LB(D_8004FC58) != 0) {
        Psx_EnterCriticalSection();
        Psx_VSyncCallback((uint32_t)LW(D_8004FC50));
    } else {
        Psx_EnterCriticalSection();
        Psx_ResetRCnt((int)s2);
        Psx_SetRCnt((int)s2, s1 & 0xFFFF, 0x1000);
        irq = LB(D_8004FC5A);
        if (irq == 0) {
            uint32_t old = Psx_InterruptCallback(0, 0);
            irq = LB(D_8004FC5A);
            fn = SND_FNVAL(_SsTrapIntrVSync);
            SW(D_8004FC54, old);
        } else {
            fn = SND_FNVAL(_SsSeqCalledTbyT_1per2);
            if (LB(D_8004FC59) == 0)
                fn = (uint32_t)LW(D_8004FC50);
        }
        Psx_InterruptCallback(irq, fn);
    }
    Psx_ExitCriticalSection();
    return 0;
}

/* _SsTrapIntrVSync 0x800352E4: chain the previous VBlank callback, then tick */
int _SsTrapIntrVSync(void) {
    uint32_t f = (uint32_t)LW(D_8004FC54);
    if (f != 0)
        SND_FN(f)();
    return SND_FN(LW(D_8004FC50))();
}

/* _SsSeqCalledTbyT_1per2 0x80035330: tick on every second call */
int _SsSeqCalledTbyT_1per2(void) {
    if (LW(D_8004FC5C) == 0) {
        SW(D_8004FC5C, 1);
        return 1;
    }
    SW(D_8004FC5C, 0);
    return SND_FN(LW(D_8004FC50))();
}

/* SsSetTickMode 0x80035A04 */
void SsSetTickMode(int tick_mode) {
    int32_t vm, v1;

    PSYQ_LOG("0x%X", tick_mode);
    vm = Psx_GetVideoMode();
    if (tick_mode & 0x1000) {
        SW(D_8004FC4C, 1);
        SW(D_8004FC48, tick_mode & 0xFFF);
    } else {
        SW(D_8004FC4C, 0);
        SW(D_8004FC48, tick_mode);
    }
    v1 = LW(D_8004FC48);
    if (v1 >= 6) {
        SW(Snd_TicksPerSec, v1);
        return;
    }
    switch (v1) {
    case 0: /* SS_TICK60 / NOTICK: 50 on PAL, else 60 */
        SW(Snd_TicksPerSec, vm == 1 ? 0x32 : 0x3C);
        break;
    case 1:
        SW(Snd_TicksPerSec, 0x3C);
        SW(D_8004FC48, vm != 0 ? 0x3C : 5);
        break;
    case 2:
        SW(Snd_TicksPerSec, 0xF0);
        break;
    case 3:
        SW(Snd_TicksPerSec, 0x78);
        break;
    case 4:
        SW(Snd_TicksPerSec, 0x32);
        SW(D_8004FC48, vm == 1 ? 5 : 0x32);
        break;
    case 5: /* SS_TICKVSYNC */
        SW(Snd_TicksPerSec, vm == 1 ? 0x32 : 0x3C);
        break;
    default: /* negative */
        SW(Snd_TicksPerSec, 0x3C);
        break;
    }
}

/* SsSetTableSize 0x800357E4 */
void SsSetTableSize(char *table, short s_max, short t_max) {
    int32_t i, j, a3;
    uint32_t base = SND_ADDR(table);

    PSYQ_LOG("%p, %d, %d", (void *)table, s_max, t_max);
    SH(D_800624D0, s_max);
    SH(D_800624D2, t_max);
    for (i = 0; i < s_max; i++)
        SW(Snd_SeqScores + (uint32_t)i * 4, base + (uint32_t)(i * t_max) * 0xB0u);
    /* slots past s_max are marked used */
    for (a3 = s_max; a3 < 0x20; a3++)
        SW(D_80061C48, (uint32_t)LW(D_80061C48) | (1u << (a3 & 31)));
    for (i = 0; i < LH(D_800624D0); i++) {
        uint32_t slot = Snd_SeqScores + (uint32_t)i * 4;
        for (j = 0; j < LH(D_800624D2); j++) {
            uint32_t off = (uint32_t)j * 0xB0;
            SW(LW(slot) + off + 0x98, 0);
            SB(LW(slot) + off + 0x22, 0xFF);
            SB(LW(slot) + off + 0x23, 0);
            SH(LW(slot) + off + 0x48, 0);
            SH(LW(slot) + off + 0x4A, 0);
            SW(LW(slot) + off + 0x9C, 0);
            SW(LW(slot) + off + 0xA0, 0);
            SH(LW(slot) + off + 0x4C, 0);
            SW(LW(slot) + off + 0xAC, 0);
            SW(LW(slot) + off + 0xA8, 0);
            SW(LW(slot) + off + 0xA4, 0);
            SH(LW(slot) + off + 0x4E, 0);
            SH(LW(slot) + off + 0x58, 0x7F);
            SH(LW(slot) + off + 0x5A, 0x7F);
            SH(LW(slot) + off + 0x5C, 0x7F);
            SH(LW(slot) + off + 0x5E, 0x7F);
        }
    }
}

/* SsSetMVol 0x80035024 */
void SsSetMVol(short voll, short volr) {
    uint32_t attr[10] = {0}; /* SpuCommonAttr */
    uint32_t a = SND_ADDR(attr);

    PSYQ_LOG("%d, %d", voll, volr);
    SW(a + 0x0, 3);
    SH(a + 0x4, voll * 129);
    SH(a + 0x6, volr * 129);
    SpuSetCommonAttr(a);
}

/* SsSetSerialAttr 0x80034F64 */
void SsSetSerialAttr(char s_num, char attr, char mode) {
    uint32_t buf[10] = {0}; /* SpuCommonAttr; retail leaves the mask unset for other attr values */
    uint32_t a = SND_ADDR(buf);
    int32_t sn = (int8_t)s_num, at = (int8_t)attr, md = (int8_t)mode;

    PSYQ_LOG("%d, %d, %d", s_num, attr, mode);
    if (sn == 0) { /* CD input */
        if (at == 0) {
            SW(a + 0x0, 0x200);
            SW(a + 0x18, md);
        }
        if (at == 1) {
            SW(a + 0x0, 0x100);
            SW(a + 0x14, md);
        }
    }
    if (sn == 1) { /* external input */
        if (at == 0) {
            SW(a + 0x0, 0x2000);
            SW(a + 0x24, md);
        }
        if (at == sn) {
            SW(a + 0x0, 0x1000);
            SW(a + 0x20, md);
        }
    }
    SpuSetCommonAttr(a);
}

/* SsSetSerialVol 0x800356D4 */
void SsSetSerialVol(char s_num, short voll, short volr) {
    uint32_t buf[10] = {0}; /* SpuCommonAttr */
    uint32_t a = SND_ADDR(buf);
    int32_t l = voll, r = volr;

    PSYQ_LOG("%d, %d, %d", s_num, voll, volr);
    if ((uint8_t)s_num == 0) { /* CD volume */
        SW(a + 0x0, 0xC0);
        if ((int16_t)l >= 0x80)
            l = 0x7F;
        if ((int16_t)r >= 0x80)
            r = 0x7F;
        SH(a + 0x10, (int16_t)l * 258);
        SH(a + 0x12, (int16_t)r * 258);
    }
    if ((int8_t)s_num == 1) { /* external volume */
        SW(a + 0x0, 0xC00);
        if ((int16_t)l >= 0x80)
            l = 0x7F;
        if ((int16_t)r >= 0x80)
            r = 0x7F;
        SH(a + 0x1C, (int16_t)l * 258);
        SH(a + 0x1E, (int16_t)r * 258);
    }
    SpuSetCommonAttr(a);
}

/* SsVabOpenHead 0x80039A44 */
short SsVabOpenHead(u_char *addr, short vabid) {
    PSYQ_LOG("%p, %d", (void *)addr, vabid);
    return (short)_SsVabOpenHeadWithMode(SND_ADDR(addr), (int)vabid, SND_FNVAL(func_80039A78), 0);
}

/* _SsVabOpenHeadWithMode 0x80039B54: parse the VH header, allocate SPU memory for the body */
int _SsVabOpenHeadWithMode(uint32_t addr, int vabid, uint32_t allocfn, int mode) {
    uint32_t vagsize[0x100]; /* retail stack sp+0x10 */
    int32_t s2 = 0x10, v1, a1, a2, s1, ver;
    int32_t maxprog, count;
    uint32_t a3, s3, magic, s0, s4, spu;

    if (_spu_getInTransfer() == 1)
        return -1;
    _spu_setInTransfer(1);
    v1 = (int16_t)vabid;
    if (v1 >= 0x10) {
        _spu_setInTransfer(0);
        return -1;
    }
    if (v1 == -1) {
        /* first free id */
        for (a1 = 0; a1 < 0x10; a1++) {
            if (LBU(D_80062D38 + a1) == 0) {
                SB(D_80062D38 + a1, 1);
                SH(D_80062D90, LHU(D_80062D90) + 1);
                s2 = a1;
                break;
            }
        }
    } else if (LBU(D_80062D38 + v1) == 0) {
        SB(D_80062D38 + v1, 1);
        SH(D_80062D90, LHU(D_80062D90) + 1);
        s2 = vabid;
    }
    a2 = (int16_t)s2;
    if (a2 >= 0x10) {
        _spu_setInTransfer(0);
        return -1;
    }
    SW(D_80062C70 + (uint32_t)a2 * 4, addr);
    magic = (uint32_t)LW(addr);
    SW(D_80062D10, 0);
    a3 = addr + 0x20;
    if ((magic >> 8) != 0x564142) { /* "pBAV" */
        SB(D_80062D38 + a2, 0);
        goto fail;
    }
    maxprog = 0x40;
    if ((magic & 0xFF) == 0x70 && LW(addr + 4) >= 5)
        maxprog = 0x80;
    SH(D_80062CFA, maxprog);
    v1 = LH(D_80062CFA);
    if (v1 < LHU(addr + 0x12)) { /* too many programs */
        SB(D_80062D38 + (int16_t)s2, 0);
        goto fail;
    }
    SW(D_80062C30 + (uint32_t)(int16_t)s2 * 4, a3);
    s3 = a3;
    a3 = s3 + (uint32_t)v1 * 16;
    /* program attr +8: index among the used programs */
    count = 0;
    for (a1 = 0; a1 < v1; a1++) {
        uint32_t p = s3 + (uint32_t)a1 * 16;
        int32_t tones = LBU(p);
        SW(p + 8, count);
        if (tones != 0)
            count++;
    }
    SW(D_80062CB8 + (uint32_t)(int16_t)s2 * 4, a3);
    a3 += (uint32_t)LHU(addr + 0x12) << 9;
    s4 = (uint32_t)LBU(addr + 0x16);
    /* VAG size table */
    s0 = 0;
    for (a1 = 0; a1 < 0x100; a1++) {
        if (a1 <= (int32_t)(s4 & 0xFF)) {
            ver = LW(addr + 4);
            v1 = LHU(a3);
            vagsize[a1] = ver < 5 ? (uint32_t)v1 << 2 : (uint32_t)v1 << 3;
            s0 += vagsize[a1];
        }
        a3 += 2;
    }
    s0 = (s0 + 0x3F) & ~0x3Fu;
    s1 = (int16_t)s2;
    spu = (uint32_t)SND_FN(allocfn)(s0, mode, s1);
    if ((int32_t)spu == -1)
        return -1;
    if (spu + s0 > 0x80000u) {
        SB(D_80062D38 + s1, 0);
        goto fail;
    }
    SW(D_80062D98 + (uint32_t)s1 * 4, spu);
    /* VAG SPU addresses (in 8 byte units) into program attr +0xC / +0xE */
    s0 = 0;
    for (a1 = 0; a1 <= (int32_t)(s4 & 0xFF); a1++) {
        s0 += vagsize[a1];
        if ((a1 & 1) == 0)
            SH(s3 + (uint32_t)(a1 / 2) * 16 + 0xC, (spu + s0) >> 3);
        else
            SH(s3 + (uint32_t)(a1 / 2) * 16 + 0xE, (spu + s0) >> 3);
    }
    SW(D_80062D50 + (uint32_t)(int16_t)s2 * 4, s0);
    SB(D_80062D38 + (int16_t)s2, 2);
    return (int16_t)s2;

fail:
    _spu_setInTransfer(0);
    SH(D_80062D90, LHU(D_80062D90) - 1);
    return -1;
}

/* SsVabTransBody 0x80039F44 */
short SsVabTransBody(u_char *addr, short vabid) {
    int32_t id;

    PSYQ_LOG("%p, %d", (void *)addr, vabid);
    if ((uint16_t)vabid < 0x11) {
        id = vabid;
        if (LBU(D_80062D38 + id) == 2) {
            uint32_t spu = (uint32_t)LW(D_80062D98 + (uint32_t)id * 4);
            SpuSetTransferMode(0);
            if (SpuSetTransferStartAddr(spu) != 0) {
                SpuWrite(SND_ADDR(addr), LW(D_80062D50 + (uint32_t)id * 4));
                SB(D_80062D38 + id, 1);
                return (short)id;
            }
        }
    }
    _spu_setInTransfer(0);
    return -1;
}

/* SsVabTransCompleted 0x8003A004 */
short SsVabTransCompleted(short immediateFlag) {
    PSYQ_LOG("%d", immediateFlag);
    return (short)SpuIsTransferCompleted((int)immediateFlag);
}

/* SsVabClose 0x80039994 */
void SsVabClose(short vab_id) {
    int32_t id, st;

    PSYQ_LOG("%d", vab_id);
    if ((uint16_t)vab_id >= 0x10)
        return;
    id = vab_id;
    st = LBU(D_80062D38 + id);
    if (st >= 3 || st == 0)
        return;
    SpuFree(LW(D_80062D98 + (uint32_t)id * 4));
    SB(D_80062D38 + id, 0);
    SH(D_80062D90, LHU(D_80062D90) - 1);
    if (_spu_getInTransfer() == 1)
        _spu_setInTransfer(0);
}

/* SsSepOpen 0x80032954 */
short SsSepOpen(u_long *addr, short vab_id, short seq_num) {
    uint32_t used, h = D_80061BB0, p = SND_ADDR(addr);
    int32_t slot = 0, i, r;

    PSYQ_LOG("%p, %d, %d", (void *)addr, vab_id, seq_num);
    used = (uint32_t)LW(D_80061C48);
    if (used == 0xFFFFFFFFu) {
        Psx_printf(D_80010A34);
        return -1;
    }
    /* sequence event handlers */
    SW(h + 0x00, SND_FNVAL(_SsNoteOn));
    SW(h + 0x04, SND_FNVAL(_SsSetProgramChange));
    SW(h + 0x0C, SND_FNVAL(_SsGetMetaEvent));
    SW(h + 0x08, SND_FNVAL(_SsSetPitchBend));
    SW(h + 0x10, SND_FNVAL(_SsSetControlChange));
    SW(h + 0x14, SND_FNVAL(_SsContBankChange));
    SW(h + 0x1C, SND_FNVAL(_SsContMainVol));
    SW(h + 0x20, SND_FNVAL(_SsContPanpot));
    SW(h + 0x24, SND_FNVAL(_SsContExpression));
    SW(h + 0x28, SND_FNVAL(_SsContDamper));
    SW(h + 0x2C, SND_FNVAL(_SsContNrpn1));
    SW(h + 0x30, SND_FNVAL(_SsContNrpn2));
    SW(h + 0x34, SND_FNVAL(_SsContRpn1));
    SW(h + 0x38, SND_FNVAL(_SsContRpn2));
    SW(h + 0x3C, SND_FNVAL(_SsContExternal));
    SW(h + 0x40, SND_FNVAL(_SsContResetAll));
    SW(h + 0x18, SND_FNVAL(_SsContDataEntry));
    /* NRPN VAB attribute setters */
    SW(h + 0x44, SND_FNVAL(_SsSetNrpnVabAttr0));
    SW(h + 0x48, SND_FNVAL(_SsSetNrpnVabAttr1));
    SW(h + 0x4C, SND_FNVAL(_SsSetNrpnVabAttr2));
    SW(h + 0x50, SND_FNVAL(_SsSetNrpnVabAttr3));
    SW(h + 0x54, SND_FNVAL(_SsSetNrpnVabAttr4));
    SW(h + 0x58, SND_FNVAL(_SsSetNrpnVabAttr5));
    SW(h + 0x5C, SND_FNVAL(_SsSetNrpnVabAttr6));
    SW(h + 0x60, SND_FNVAL(_SsSetNrpnVabAttr7));
    SW(h + 0x64, SND_FNVAL(_SsSetNrpnVabAttr8));
    SW(h + 0x68, SND_FNVAL(_SsSetNrpnVabAttr9));
    SW(h + 0x6C, SND_FNVAL(_SsSetNrpnVabAttr10));
    SW(h + 0x70, SND_FNVAL(_SsSetNrpnVabAttr11));
    SW(h + 0x74, SND_FNVAL(_SsSetNrpnVabAttr12));
    SW(h + 0x78, SND_FNVAL(_SsSetNrpnVabAttr13));
    SW(h + 0x7C, SND_FNVAL(_SsSetNrpnVabAttr14));
    SW(h + 0x80, SND_FNVAL(_SsSetNrpnVabAttr15));
    SW(h + 0x84, SND_FNVAL(_SsSetNrpnVabAttr16));
    SW(h + 0x88, SND_FNVAL(_SsSetNrpnVabAttr17));
    SW(h + 0x8C, SND_FNVAL(_SsSetNrpnVabAttr18));
    SW(h + 0x90, SND_FNVAL(_SsSetNrpnVabAttr19));
    /* first free slot (retail keeps 0 if the scan finds none) */
    for (i = 0; i < 0x20; i++) {
        if ((used & (1u << i)) == 0) {
            slot = i;
            break;
        }
    }
    SW(D_80061C48, (uint32_t)LW(D_80061C48) | (1u << ((int16_t)slot & 31)));
    for (i = 0; (int16_t)i < seq_num; i++) {
        r = _SsInitSoundSeq((int16_t)slot, (int16_t)i, (int)vab_id, p);
        if (r == -1)
            return -1;
        p += (uint32_t)r;
    }
    return (short)slot;
}

/* _SsInitSoundSeq 0x80034A24: set up one sequence of a SEP / SEQ, returns its byte size */
int _SsInitSoundSeq(int sep, int seq, int vab_id, uint32_t data) {
    uint32_t s0, p;
    int32_t s1 = 0, s2, i, delta, tps, res_tempo, tps60, tps15;
    int32_t b0, b1, b2, b3;
    int32_t tempo, q, rem;

    s0 = (uint32_t)LW(Snd_SeqScores + (uint32_t)((int16_t)sep * 4)) + (uint32_t)((int16_t)seq * 0xB0);
    SB(s0 + 0x20, 1);
    for (i = 0x15; i <= 0x1F; i++)
        SB(s0 + i, 0);
    SB(s0 + 0x14, 0);
    SB(s0 + 0x21, 0);
    SH(s0 + 0x52, 1);
    SH(s0 + 0x50, 0);
    SB(s0 + 0x26, vab_id);
    SH(s0 + 0x56, 0);
    SW(s0 + 0x84, 0);
    SW(s0 + 0x88, 0);
    SW(s0 + 0x8C, 0);
    SW(s0 + 0x90, 0);
    SH(s0 + 0x80, 0);
    SB(s0 + 0x24, 0);
    SB(s0 + 0x25, 0);
    for (i = 0; i < 0x10; i++) { /* per channel: panpot, program, volume */
        SB(s0 + 0x27 + i, 0x40);
        SB(s0 + 0x37 + i, i);
        SH(s0 + 0x60 + i * 2, 0x7F);
    }
    SW(s0 + 0x0, data);
    if ((seq & 0xFFFF) != 0) {
        /* next sequence of a SEP: 2 byte sequence id */
        SW(s0 + 0x0, data + 2);
        s1 += 2;
    } else {
        b0 = LBU(data);
        if (b0 == 0x53 || b0 == 0x70) { /* "SEP" / "pQES" header */
            SW(s0 + 0x0, data + 5);
            b1 = LBU(data + 5);
            SW(s0 + 0x0, data + 6);
            if (b1 != 0) {
                Psx_printf(D_80010A64);
                return -1;
            }
            SW(s0 + 0x0, data + 8);
            s1 += 8;
        }
    }
    /* resolution (2 bytes) and tempo (3 bytes, usec per quarter note) */
    p = (uint32_t)LW(s0 + 0x0);
    b0 = LBU(p);
    SW(s0 + 0x0, p + 1);
    b1 = LBU(p + 1);
    SW(s0 + 0x0, p + 2);
    SH(s0 + 0x50, b1 | (b0 << 8));
    b0 = LBU(p + 2);
    SW(s0 + 0x0, p + 3);
    b1 = LBU(p + 3);
    SW(s0 + 0x0, p + 4);
    b2 = LBU(p + 4);
    tempo = (b0 << 16) | (b1 << 8) | b2;
    if (tempo == 0) {
        Psx_printf(SND_ADDR("_SsInitSoundSeq: tempo 0\n"));
        q = 0;
        rem = 0;
    } else {
        q = 60000000 / tempo;
        rem = 60000000 % tempo;
    }
    SW(s0 + 0x0, p + 5);
    SW(s0 + 0x8C, tempo);
    s1 += 5;
    if ((int32_t)((uint32_t)tempo >> 1) < rem)
        SW(s0 + 0x8C, q + 1); /* rounded BPM */
    else
        SW(s0 + 0x8C, q);
    SW(s0 + 0x94, LW(s0 + 0x8C));
    /* rhythm (2 bytes) and data length (4 bytes, big endian) */
    p = (uint32_t)LW(s0 + 0x0);
    b0 = LBU(p);
    SW(s0 + 0x0, p + 1);
    SB(s0 + 0x24, b0);
    b0 = LBU(p + 1);
    SW(s0 + 0x0, p + 2);
    SB(s0 + 0x25, b0);
    b0 = LBU(p + 2);
    SW(s0 + 0x0, p + 3);
    b1 = LBU(p + 3);
    SW(s0 + 0x0, p + 4);
    b2 = LBU(p + 4);
    SW(s0 + 0x0, p + 5);
    b3 = LBU(p + 5);
    SW(s0 + 0x0, p + 6);
    s2 = b3 | ((b0 << 24) + (b1 << 16) + (b2 << 8));
    delta = _SsReadDeltaValue((int16_t)sep, (int16_t)seq);
    res_tempo = LH(s0 + 0x50) * LW(s0 + 0x8C);
    SW(s0 + 0x8, LW(s0 + 0x0));
    tps = LW(Snd_TicksPerSec);
    SW(s0 + 0x84, delta);
    SW(s0 + 0x90, delta);
    SW(s0 + 0x10, 0);
    SW(s0 + 0xC, LW(s0 + 0x0));
    SW(s0 + 0x4, LW(s0 + 0x0));
    tps15 = tps * 15;
    tps60 = tps15 * 4;
    s1 += 6;
    if ((uint32_t)(res_tempo * 10) < (uint32_t)tps60) {
        /* fewer seq ticks than libsnd ticks: ticks per seq tick */
        uint32_t v;
        if (res_tempo == 0) {
            Psx_printf(SND_ADDR("_SsInitSoundSeq: divide by 0\n"));
            v = 0;
        } else {
            v = (uint32_t)(tps * 600) / (uint32_t)res_tempo;
        }
        SH(s0 + 0x52, v);
        SH(s0 + 0x54, v);
    } else {
        /* seq ticks per libsnd tick */
        uint32_t n, r;
        if (tps60 == 0) {
            Psx_printf(SND_ADDR("_SsInitSoundSeq: divide by 0\n"));
            n = 0;
            r = 0;
        } else {
            n = (uint32_t)(LH(s0 + 0x50) * LW(s0 + 0x8C) * 10) / (uint32_t)tps60;
            r = (uint32_t)(LH(s0 + 0x50) * LW(s0 + 0x8C) * 10) % (uint32_t)tps60;
        }
        SH(s0 + 0x52, 0xFFFF);
        SH(s0 + 0x54, n);
        if ((uint32_t)(tps15 * 2) < r)
            SH(s0 + 0x54, n + 1);
    }
    SH(s0 + 0x56, LHU(s0 + 0x54));
    return s1 + s2;
}

/* SsSepClose 0x80032844 */
void SsSepClose(short sep_access_num) {
    PSYQ_LOG("%d", sep_access_num);
    _SsClose((int)sep_access_num);
}

/* _SsClose 0x800326A4 */
int _SsClose(int a0) {
    int32_t sep = (int16_t)a0, i;
    uint32_t slot = Snd_SeqScores + (uint32_t)sep * 4;

    _SsVmSetSeqVol(sep, 0, 0, 1);
    _SsVmSeqKeyOff(sep);
    SW(D_80061C48, (uint32_t)LW(D_80061C48) & ~(1u << (sep & 31)));
    for (i = 0; i < LH(D_800624D2); i++) {
        uint32_t off = (uint32_t)i * 0xB0;
        SW(LW(slot) + off + 0x98, 0);
        SB(LW(slot) + off + 0x22, 0xFF);
        SB(LW(slot) + off + 0x23, 0);
        SH(LW(slot) + off + 0x48, 0);
        SH(LW(slot) + off + 0x4A, 0);
        SW(LW(slot) + off + 0x9C, 0);
        SW(LW(slot) + off + 0xA0, 0);
        SH(LW(slot) + off + 0x4C, 0);
        SW(LW(slot) + off + 0xAC, 0);
        SW(LW(slot) + off + 0xA8, 0);
        SW(LW(slot) + off + 0xA4, 0);
        SH(LW(slot) + off + 0x4E, 0);
        SH(LW(slot) + off + 0x58, 0x7F);
        SH(LW(slot) + off + 0x5A, 0x7F);
    }
    return 0;
}

/* SsSepPlay 0x80034E04 */
void SsSepPlay(short sep_access_num, short seq_num, char play_mode, short l_count) {
    PSYQ_LOG("%d, %d, %d, %d", sep_access_num, seq_num, play_mode, l_count);
    Snd_SetPlayMode((int)sep_access_num, (int)seq_num, (int)(int8_t)play_mode, (int)l_count);
}

/* Snd_SetPlayMode 0x80034E44 (_SsSndPlay): rewind and start (mode 1) or pause (mode 0) */
int Snd_SetPlayMode(int sep, int seq, int play_mode, int l_count) {
    uint32_t slot = Snd_SeqScores + (uint32_t)((int16_t)sep * 4);
    uint32_t off = (uint32_t)((int16_t)seq * 0xB0);
    uint32_t t0 = (uint32_t)LW(slot) + off;
    int32_t a, b, c, mode, voll, volr;

    a = LW(t0 + 0x4);
    b = LW(t0 + 0x4);
    c = LW(t0 + 0x4);
    SW(t0 + 0x0, a);
    SW(t0 + 0x8, b);
    SW(t0 + 0xC, c);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x200u);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x4u);
    mode = (int8_t)play_mode;
    SB(t0 + 0x20, l_count);
    if (mode == 1) {
        uint32_t q = (uint32_t)LW(slot) + off;
        SW(q + 0x98, (uint32_t)LW(q + 0x98) | 1);
        voll = LHU(t0 + 0x58);
        SB(t0 + 0x14, mode);
        volr = LHU(t0 + 0x5A);
        SB(t0 + 0x21, 0);
        _SsVmSetSeqVol((int16_t)(sep | (seq << 8)), voll, volr, 1);
    } else if (mode == 0) {
        uint32_t q = (uint32_t)LW(slot) + off;
        SW(q + 0x98, (uint32_t)LW(q + 0x98) | 2);
    }
    return 0;
}

/* SsSepStop 0x8003569C */
void SsSepStop(short sep_access_num, short seq_num) {
    PSYQ_LOG("%d, %d", sep_access_num, seq_num);
    _SsSndStop((int)sep_access_num, (int)seq_num);
}

/* SsSepSetVol 0x80035C4C */
void SsSepSetVol(short sep_access_num, short seq_num, short voll, short volr) {
    uint32_t s;

    PSYQ_LOG("%d, %d, %d, %d", sep_access_num, seq_num, voll, volr);
    s = snd_score(Snd_SeqScores + (uint32_t)(sep_access_num * 4), seq_num);
    if (LW(s + 0x98) != 1) {
        /* not playing: keep for the next play */
        SH(s + 0x58, voll);
        SH(s + 0x5A, volr);
    } else {
        _SsVmSetSeqVol((int16_t)(sep_access_num | (seq_num << 8)), voll & 0xFFFF, volr & 0xFFFF, 1);
    }
}

/* _SsSndNextSep 0x80032544: start the sequence at its start again (next SEP entry) */
int _SsSndNextSep(int sep, int seq) {
    uint32_t slot = Snd_SeqScores + (uint32_t)((int16_t)sep * 4);
    uint32_t off = (uint32_t)((int16_t)seq * 0xB0);
    uint32_t a3 = (uint32_t)LW(slot) + off;
    uint32_t v;

    SB(a3 + 0x20, 1);
    SB(a3 + 0x21, 0);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x100u);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x8u);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x2u);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x4u);
    SW(LW(slot) + off + 0x98, (uint32_t)LW(LW(slot) + off + 0x98) & ~0x200u);
    v = (uint32_t)LW(a3 + 0x4);
    SB(a3 + 0x14, 1);
    SW(a3 + 0x0, v);
    a3 = (uint32_t)LW(slot) + off;
    v = (uint32_t)LW(a3 + 0x98) | 1;
    SW(a3 + 0x98, v);
    return (int)v;
}

/* SsUtAllKeyOff 0x80035F04 */
void SsUtAllKeyOff(short mode) {
    uint32_t attr[0x10] = {0}; /* SpuVoiceAttr */
    uint32_t a = SND_ADDR(attr);
    int32_t s0 = 0, v;

    PSYQ_LOG("%d", mode);
    SW(a + 0x4, 0x60093);
    SH(a + 0x14, 0x1000);
    SW(a + 0x1C, 0x1000);
    SH(a + 0x3A, 0x80FF);
    SH(a + 0x8, 0);
    SH(a + 0xA, 0);
    SH(a + 0x3C, 0x4000);
    while ((int16_t)s0 < LB(D_80062D0C)) {
        v = (int16_t)s0;
        if ((LW(D_8004FC18) & (int32_t)(1u << (v & 31))) == 0) {
            uint32_t o = (uint32_t)(v * 0x38);
            SH(D_800624EA + o, 0x18);
            SH(D_800624EE + o, 0);
            SH(D_800624F8 + o, 0xFF);
            SH(D_800624FA + o, 0);
            SH(D_800624FC + o, 0);
            SH(D_800624FE + o, 0xFF);
            SH(D_8006251E + o, 0);
            SW(a + 0x0, 1u << (v & 31));
            SpuSetVoiceAttr(a);
            SH(D_80062D30, s0);
            _SsVmKeyOffNow(1);
        }
        s0++;
    }
}

/* SsUtSetReverbType 0x80036474 */
short SsUtSetReverbType(short type) {
    int32_t neg = 0, v1 = type, s0;

    PSYQ_LOG("%d", type);
    if (type < 0) {
        neg = 1;
        v1 = -(int32_t)type;
    }
    if ((v1 & 0xFFFF) >= 0xA)
        return -1;
    SW(D_80062C18 + 0x0, 1); /* SPU_REV_MODE */
    SW(D_80062C18 + 0x4, neg ? (int16_t)(v1 | 0x100) : (int16_t)v1); /* 0x100 = clear work area */
    s0 = (int16_t)v1;
    if (s0 == 0)
        SpuSetReverb(0);
    SpuSetReverbModeParam(D_80062C18);
    return (short)s0;
}

/* SsUtSetReverbDepth 0x800363E4 */
void SsUtSetReverbDepth(short ldepth, short rdepth) {
    int32_t l = ((int32_t)ldepth << 15) - ldepth; /* depth * 0x7FFF / 127 */
    int32_t r = ((int32_t)rdepth << 15) - rdepth;

    PSYQ_LOG("%d, %d", ldepth, rdepth);
    SW(D_80062C18 + 0x0, 6); /* SPU_REV_DEPTHL | SPU_REV_DEPTHR */
    SH(D_80062C18 + 0x8, ((MULT_HI(l, 0x81020409) + l) >> 6) - (l >> 31));
    SH(D_80062C18 + 0xA, ((MULT_HI(r, 0x81020409) + r) >> 6) - (r >> 31));
    SpuSetReverbModeParam(D_80062C18);
}

/* SsUtReverbOn 0x80036574 */
void SsUtReverbOn(void) {
    PSYQ_LOG("");
    SpuSetReverb(1);
}

/* SsUtReverbOff 0x80036554 */
int SsUtReverbOff(void) {
    SpuSetReverb(0);
    return 0;
}

/* SsUtSetReverbDelay 0x800363A4 */
int SsUtSetReverbDelay(int delay) {
    SW(D_80062C18 + 0xC, (int16_t)delay);
    SW(D_80062C18 + 0x0, 8); /* SPU_REV_DELAYTIME */
    SpuSetReverbModeParam(D_80062C18);
    return 0;
}

/* SsUtSetReverbFeedback 0x80036514 */
int SsUtSetReverbFeedback(int feedback) {
    SW(D_80062C18 + 0x10, (int16_t)feedback);
    SW(D_80062C18 + 0x0, 0x10); /* SPU_REV_FEEDBACK */
    SpuSetReverbModeParam(D_80062C18);
    return 0;
}

/* SsUtGetProgAtr 0x80036054 */
int SsUtGetProgAtr(int vab_id, int prog, uint32_t out) {
    int32_t id = (int16_t)vab_id, pr;
    uint32_t o;

    if (LBU(D_80062D38 + id) != 1)
        return -1;
    pr = (int16_t)prog;
    _SsVmVSetUp(id, pr);
    o = (uint32_t)(pr << 4);
    SB(out + 0x0, LBU(LW(D_80062CFC) + o + 0x0));
    SB(out + 0x1, LBU(LW(D_80062CFC) + o + 0x1));
    SB(out + 0x2, LBU(LW(D_80062CFC) + o + 0x2));
    SB(out + 0x3, LBU(LW(D_80062CFC) + o + 0x3));
    SB(out + 0x4, LBU(LW(D_80062CFC) + o + 0x4));
    SH(out + 0x6, LHU(LW(D_80062CFC) + o + 0x6));
    return 0;
}

/* SsUtGetVagAtr 0x80036164 */
int SsUtGetVagAtr(int vab_id, int prog, int tone, uint32_t out) {
    int32_t id = (int16_t)vab_id;
    uint32_t o, t;

    if (LBU(D_80062D38 + id) != 1)
        return -1;
    _SsVmVSetUp(id, (int16_t)prog);
    o = (uint32_t)((int32_t)(int16_t)(tone + (LB(D_80062D1F) << 4)) << 5);
    SB(out + 0x0, LBU(LW(D_80062D08) + o + 0x0));
    SB(out + 0x1, LBU(LW(D_80062D08) + o + 0x1));
    SB(out + 0x2, LBU(LW(D_80062D08) + o + 0x2));
    SB(out + 0x3, LBU(LW(D_80062D08) + o + 0x3));
    SB(out + 0x4, LBU(LW(D_80062D08) + o + 0x4));
    SB(out + 0x5, LBU(LW(D_80062D08) + o + 0x5));
    SB(out + 0x7, LBU(LW(D_80062D08) + o + 0x7));
    SB(out + 0x6, LBU(LW(D_80062D08) + o + 0x6));
    SB(out + 0x8, LBU(LW(D_80062D08) + o + 0x8));
    SB(out + 0x9, LBU(LW(D_80062D08) + o + 0x9));
    SB(out + 0xA, LBU(LW(D_80062D08) + o + 0xA));
    SB(out + 0xB, LBU(LW(D_80062D08) + o + 0xB));
    SB(out + 0xC, LBU(LW(D_80062D08) + o + 0xC));
    SB(out + 0xD, LBU(LW(D_80062D08) + o + 0xD));
    t = (uint32_t)LW(D_80062D08) + o;
    SH(out + 0x10, LHU(t + 0x10));
    SH(out + 0x12, LHU(t + 0x12));
    SH(out + 0x14, LHU(t + 0x14));
    SH(out + 0x16, LHU(t + 0x16));
    return 0;
}

/* SsUtSetVagAtr 0x80036594 */
int SsUtSetVagAtr(int vab_id, int prog, int tone, uint32_t in) {
    int32_t id = (int16_t)vab_id;
    uint32_t o, t;

    if (LBU(D_80062D38 + id) != 1)
        return -1;
    _SsVmVSetUp(id, (int16_t)prog);
    o = (uint32_t)((int32_t)(int16_t)(tone + (LB(D_80062D1F) << 4)) << 5);
    SB(LW(D_80062D08) + o + 0x0, LBU(in + 0x0));
    SB(LW(D_80062D08) + o + 0x1, LBU(in + 0x1));
    SB(LW(D_80062D08) + o + 0x2, LBU(in + 0x2));
    SB(LW(D_80062D08) + o + 0x3, LBU(in + 0x3));
    SB(LW(D_80062D08) + o + 0x4, LBU(in + 0x4));
    SB(LW(D_80062D08) + o + 0x5, LBU(in + 0x5));
    SB(LW(D_80062D08) + o + 0x7, LBU(in + 0x7));
    SB(LW(D_80062D08) + o + 0x6, LBU(in + 0x6));
    SB(LW(D_80062D08) + o + 0x8, LBU(in + 0x8));
    SB(LW(D_80062D08) + o + 0x9, LBU(in + 0x9));
    SB(LW(D_80062D08) + o + 0xA, LBU(in + 0xA));
    SB(LW(D_80062D08) + o + 0xB, LBU(in + 0xB));
    SB(LW(D_80062D08) + o + 0xC, LBU(in + 0xC));
    SB(LW(D_80062D08) + o + 0xD, LBU(in + 0xD));
    t = (uint32_t)LW(D_80062D08) + o;
    SH(t + 0x10, LHU(in + 0x10));
    SH(t + 0x12, LHU(in + 0x12));
    SH(t + 0x14, LHU(in + 0x14));
    SH(t + 0x16, LHU(in + 0x16));
    return 0;
}

/* _SsUtResolveADSR 0x80033B24: ADSR1 / ADSR2 words to the SsUt ADSR fields */
int _SsUtResolveADSR(uint32_t adsr1, uint32_t adsr2, uint32_t out) {
    SH(out + 0xA, adsr1 & 0x8000);        /* attack mode */
    SH(out + 0xC, adsr2 & 0x8000);        /* sustain mode */
    SH(out + 0x10, adsr2 & 0x4000);       /* sustain direction */
    SH(out + 0xE, adsr2 & 0x20);          /* release mode */
    SH(out + 0x0, ((adsr1 & 0xFFFF) >> 8) & 0x7F); /* attack rate */
    SH(out + 0x2, ((adsr1 & 0xFFFF) >> 4) & 0xF);  /* decay rate */
    SH(out + 0x4, adsr1 & 0xF);           /* sustain level */
    SH(out + 0x6, (adsr2 >> 6) & 0x7F);   /* sustain rate */
    SH(out + 0x8, adsr2 & 0x1F);          /* release rate */
    return (int)((adsr2 >> 6) & 0x7F);
}

/* _SsUtBuildADSR 0x80033B80: SsUt ADSR fields to ADSR1 / ADSR2 */
int _SsUtBuildADSR(uint32_t in, uint32_t out1, uint32_t out2) {
    uint32_t sm = LH(in + 0xC) != 0 ? 0xFFFF8000u : 0;
    uint32_t am = LH(in + 0xA) != 0 ? 0xFFFF8000u : 0;
    uint32_t t0 = sm, w1, w2;

    if (LH(in + 0x10) != 0)
        t0 = sm | 0x4000;
    if (LH(in + 0xE) != 0)
        t0 |= 0x20;
    w1 = am | (((uint32_t)LHU(in + 0x0) << 8) & 0x7F00) | (((uint32_t)LHU(in + 0x2) << 4) & 0xF0) |
         ((uint32_t)LHU(in + 0x4) & 0xF);
    w2 = t0 | (((uint32_t)LHU(in + 0x6) << 6) & 0x1FC0) | ((uint32_t)LHU(in + 0x8) & 0x1F);
    SH(out1, w1);
    SH(out2, w2);
    return (int)w2;
}

/* SsPitchFromNote 0x80037C38: SPU pitch of note + fine (1/128 semitone) relative to the
 * tone's center note / shift */
int SsPitchFromNote(int note, int fine, int center, int shift) {
    int32_t s = (int16_t)((shift & 0xFF) + fine);
    int32_t q, n, a1, t0, x, oct, a2, semi, sh, r;
    uint32_t prod;

    q = s;
    if (q < 0)
        q += 0x7F;
    q >>= 7;
    n = note + q - (center & 0xFF);
    a1 = n;
    s = s - (q << 7);
    t0 = s;
    if ((int16_t)s < 0) {
        int32_t v = s + 0x80, vs;
        t0 = v;
        n = n - 1;
        vs = (int16_t)v;
        if (vs < 0)
            vs += 0x7F;
        a1 = n + (vs >> 7);
    }
    x = (int16_t)a1;
    oct = (MULT_HI(x, 0x2AAAAAAB) >> 1) - (x >> 31); /* x / 12 */
    a2 = oct - 2;
    semi = x - oct * 12;
    a1 = semi;
    if ((int16_t)semi < 0) {
        a1 = semi + 12;
        a2 = oct - 3;
    }
    prod = (uint32_t)LHU(D_8004FC88 + (uint32_t)((int16_t)a1 * 2)) *
           (uint32_t)LHU(D_8004FCA0 + (uint32_t)((int16_t)t0 * 2));
    r = (int32_t)prod >> 16;
    sh = (int16_t)a2;
    if (sh >= 0) {
        r = 0x3FFF;
    } else {
        int32_t na = -sh;
        r = (int32_t)(((uint32_t)r + (1u << ((na - 1) & 31))) >> (na & 31));
    }
    return r & 0xFFFF;
}
