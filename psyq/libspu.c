/* libspu (Psy-Q 4.7): retail functions translated from the MIPS asm (P1.8).
 * Register access goes through the LW / SH ... macros on the addresses held in the retail
 * globals D_8004FE28 (SPU base) and D_8004FE2C..D_8004FE3C (DMA channel 4 and SPU delay). */

#include "snd_native.h"

/* Hardware register pointers (retail data words). */
#define D_8004FE28 0x8004FE28u /* 0x1F801C00 SPU base */
#define D_8004FE2C 0x8004FE2Cu /* 0x1F8010C0 DMA4 MADR */
#define D_8004FE30 0x8004FE30u /* 0x1F8010C4 DMA4 BCR */
#define D_8004FE34 0x8004FE34u /* 0x1F8010C8 DMA4 CHCR */
#define D_8004FE38 0x8004FE38u /* 0x1F8010F0 DPCR */
#define D_8004FE3C 0x8004FE3Cu /* 0x1F801014 SPU delay */

/* libspu state */
#define _spu_EVdma 0x8004FDB0u
#define D_8004FDB4 0x8004FDB4u /* keyed-on voice mask */
#define D_8004FDB8 0x8004FDB8u /* transfer mode (SpuSetTransferMode) */
#define D_8004FDBC 0x8004FDBCu /* reverb on */
#define D_8004FDC0 0x8004FDC0u /* reverb work area reserved */
#define D_8004FDC4 0x8004FDC4u /* reverb work area start (8 byte units) */
#define D_8004FDCC 0x8004FDCCu /* reverb mode */
#define D_8004FDD0 0x8004FDD0u /* reverb depth L */
#define D_8004FDD2 0x8004FDD2u /* reverb depth R */
#define D_8004FDD4 0x8004FDD4u /* reverb delay */
#define D_8004FDD8 0x8004FDD8u /* reverb feedback */
#define D_8004FDDC 0x8004FDDCu
#define D_8004FDE0 0x8004FDE0u
#define D_8004FDE4 0x8004FDE4u /* per voice note (24 halfwords) */
#define D_8004FE12 0x8004FE12u
#define D_8004FE14 0x8004FE14u /* bit 0: write voice registers to the shadow D_80062D60 */
#define _spu_isCalled 0x8004FE18u
#define D_8004FE40 0x8004FE40u /* transfer start address (SPU units) */
#define D_8004FE44 0x8004FE44u /* transfer by IO (1) or DMA (0) */
#define D_8004FE48 0x8004FE48u
#define D_8004FE4C 0x8004FE4Cu
#define D_8004FE50 0x8004FE50u /* address shift (3) */
#define D_8004FE54 0x8004FE54u /* address unit (8) */
#define D_8004FE58 0x8004FE58u /* address mask (7) */
#define Spu_InTransfer 0x8004FE5Cu
#define D_8004FE60 0x8004FE60u /* transfer callback */
#define D_8004FE64 0x8004FE64u
#define D_8004FE68 0x8004FE68u /* 16 byte zero block */
#define D_8004FE78 0x8004FE78u /* DMA direction: 1 read, 0 write */
#define D_8004FE7C 0x8004FE7Cu /* DMA address */
#define D_8004FE80 0x8004FE80u /* DMA block count */
#define D_8004FE88 0x8004FE88u /* malloc list size */
#define D_8004FE8C 0x8004FE8Cu /* malloc list last index */
#define Spu_MemList 0x8004FE90u
#define D_8004FE98 0x8004FE98u /* 0x400 byte zero block */
#define D_80050298 0x80050298u /* note pitch table */
#define D_800502B0 0x800502B0u /* fine pitch table */
#define D_800503B8 0x800503B8u /* reverb work area start per mode */
#define D_800503E8 0x800503E8u /* reverb parameter sets, 0x44 bytes per mode */
#define D_80062D60 0x80062D60u /* voice register shadow */
#define D_80062EE8 0x80062EE8u /* key on / off shadow */

#define S_TIMEOUT 0x80010AA4u   /* "SPU:T/O [%s]\n" */
#define S_WAIT_RESET 0x80010AB4u /* "wait (reset)" */
#define S_WAIT_WRDY 0x80010AC4u  /* "wait (wrdy H -> L)" */
#define S_WAIT_DMAF 0x80010AD8u

#define SPU_BASE ((uint32_t)LW(D_8004FE28))
#define SHIFT(v) ((uint32_t)LW(v) & 31)

/* _spu_Fw1ts 0x8003ACAC: short busy delay */
int _spu_Fw1ts(void)
{
    volatile int32_t i;
    volatile int32_t v;

    v = 0xD;
    for (i = 0; i < 0x3C; i++)
        v = v * 13;
    return 0;
}

/* _spu_FsetDelayW 0x8003AC5C */
int _spu_FsetDelayW(void)
{
    uint32_t a = (uint32_t)LW(D_8004FE3C);
    SW(a, ((uint32_t)LW(a) & 0xF0FFFFFFu) | 0x20000000u);
    return 0;
}

/* _spu_FsetDelayR 0x8003AC84 */
int _spu_FsetDelayR(void)
{
    uint32_t a = (uint32_t)LW(D_8004FE3C);
    SW(a, ((uint32_t)LW(a) & 0xF0FFFFFFu) | 0x22000000u);
    return 0;
}

/* _spu_init 0x8003A1D4: SPU reset; a0 == 0 also clears voices and the sound RAM head */
int _spu_init(int a0)
{
    uint32_t base, a, p;
    uint32_t v1;
    int32_t i;

    a = (uint32_t)LW(D_8004FE38);
    SW(a, (uint32_t)LW(a) | 0xB0000u); /* DPCR: enable DMA4, priority 3 */
    base = SPU_BASE;
    SW(D_8004FE44, 0);
    SW(D_8004FE48, 0);
    SH(D_8004FE40, 0);
    SH(base + 0x180, 0);
    SH(base + 0x182, 0);
    SH(base + 0x1AA, 0);
    _spu_Fw1ts();
    base = SPU_BASE;
    SH(base + 0x180, 0);
    SH(base + 0x182, 0);
    if (LHU(base + 0x1AE) & 0x7FF) {
        v1 = 1;
        for (;;) {
            if (v1 >= 0xF01) {
                Psx_printf(S_TIMEOUT, S_WAIT_RESET);
                break;
            }
            if ((LHU(SPU_BASE + 0x1AE) & 0x7FF) == 0)
                break;
            v1++;
        }
    }
    SW(D_8004FE4C, 2);
    SW(D_8004FE50, 3);
    SW(D_8004FE54, 8);
    SW(D_8004FE58, 7);
    base = SPU_BASE;
    SH(base + 0x1AC, 4);
    SH(base + 0x184, 0);
    SH(base + 0x186, 0);
    SH(base + 0x18C, 0xFFFF);
    SH(base + 0x18E, 0xFFFF);
    SH(base + 0x198, 0);
    SH(base + 0x19A, 0);
    p = D_80062EE8;
    for (i = 0; i < 10; i++, p += 2)
        SH(p, 0);
    if (a0 == 0) {
        SH(D_8004FE40, 0x200);
        base = SPU_BASE;
        SH(base + 0x190, 0);
        SH(base + 0x192, 0);
        SH(base + 0x194, 0);
        SH(base + 0x196, 0);
        SH(base + 0x1B0, 0);
        SH(base + 0x1B2, 0);
        SH(base + 0x1B4, 0);
        SH(base + 0x1B6, 0);
        _spu_FwriteByIO(D_8004FE68, 0x10);
        p = SPU_BASE;
        for (i = 0; i < 0x18; i++, p += 0x10) {
            SH(p + 0x0, 0);
            SH(p + 0x2, 0);
            SH(p + 0x4, 0x3FFF);
            SH(p + 0x6, 0x200);
            SH(p + 0x8, 0);
            SH(p + 0xA, 0);
        }
        base = SPU_BASE;
        SH(base + 0x188, 0xFFFF); /* key on all */
        SH(base + 0x18A, 0xFF);
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        base = SPU_BASE;
        SH(base + 0x18C, 0xFFFF); /* key off all */
        SH(base + 0x18E, 0xFF);
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
    }
    base = SPU_BASE;
    SW(Spu_InTransfer, 1);
    SH(base + 0x1AA, 0xC000);
    SW(D_8004FE60, 0);
    SW(D_8004FE64, 0);
    return 0;
}

/* _spu_FwriteByIO 0x8003A454: write to sound RAM through the data FIFO (0x1A8) */
int _spu_FwriteByIO(uint32_t a0, uint32_t a1)
{
    uint32_t base, s0, s1 = a1, s2 = a0, s3, v1, n;

    base = SPU_BASE;
    v1 = LHU(D_8004FE40);
    s3 = LHU(base + 0x1AE) & 0x7FF;
    SH(base + 0x1A6, v1);
    _spu_Fw1ts();
    while (s1 != 0) {
        s0 = (s1 < 0x41) ? s1 : 0x40;
        if ((int32_t)s0 > 0) {
            base = SPU_BASE;
            for (v1 = 0; (int32_t)v1 < (int32_t)s0; v1 += 2) {
                SH(base + 0x1A8, LHU(s2));
                s2 += 2;
            }
        }
        base = SPU_BASE;
        SH(base + 0x1AA, (LHU(base + 0x1AA) & 0xFFCF) | 0x10); /* manual write */
        _spu_Fw1ts();
        if (LHU(SPU_BASE + 0x1AE) & 0x400) {
            n = 1;
            for (;;) {
                if (n >= 0xF01) {
                    Psx_printf(S_TIMEOUT, S_WAIT_WRDY);
                    break;
                }
                if ((LHU(SPU_BASE + 0x1AE) & 0x400) == 0)
                    break;
                n++;
            }
        }
        s1 -= s0;
        _spu_Fw1ts();
        _spu_Fw1ts();
    }
    base = SPU_BASE;
    SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFFCF);
    if ((uint32_t)(LHU(base + 0x1AE) & 0x7FF) != (s3 & 0xFFFF)) {
        n = 1;
        for (;;) {
            if (n >= 0xF01) {
                Psx_printf(S_TIMEOUT, S_WAIT_DMAF);
                break;
            }
            if ((uint32_t)(LHU(SPU_BASE + 0x1AE) & 0x7FF) == (s3 & 0xFFFF))
                break;
            n++;
        }
    }
    return 0;
}

/* _spu_FiDMA 0x8003A614: DMA channel 4 completion handler (DMACallback) */
int _spu_FiDMA(void)
{
    uint32_t a0;
    uint32_t v1;

    if (LW(D_8004FE78) == 0)
        _spu_Fw1ts();
    a0 = SPU_BASE;
    SH(a0 + 0x1AA, LHU(a0 + 0x1AA) & 0xFFCF); /* transfer mode stop */
    if (LHU(a0 + 0x1AA) & 0x30) {
        v1 = 1;
        while (v1 < 0xF01) {
            if ((LHU(a0 + 0x1AA) & 0x30) == 0)
                break;
            v1++;
        }
    }
    if (LW(D_8004FE60) != 0)
        SND_FN(LW(D_8004FE60))(); /* a0 holds 0xF0000000 in retail, the callback takes none */
    else
        Psx_DeliverEvent((int)0xF0000009, 0x20);
    return 0;
}

/* _spu_t 0x8003A778: transfer control. 2: set address, 1: prepare write, 0: prepare
 * read, 3: start the DMA (a1 = RAM address, a2 = byte size). */
int _spu_t(int a0, uint32_t a1, uint32_t a2)
{
    uint32_t base, want, v1, chcr;

    if (a0 == 1 || a0 == 0) {
        base = SPU_BASE;
        want = LHU(D_8004FE40);
        SW(D_8004FE78, a0 == 1 ? 0 : 1);
        if ((uint32_t)LHU(base + 0x1A6) != want) {
            v1 = 1;
            for (;;) {
                if (v1 >= 0xF01)
                    return -2;
                if ((uint32_t)LHU(base + 0x1A6) == want)
                    break;
                v1++;
            }
        }
        base = SPU_BASE;
        if (a0 == 1)
            SH(base + 0x1AA, (LHU(base + 0x1AA) & 0xFFCF) | 0x20); /* DMA write */
        else
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x30); /* DMA read */
        return 0;
    }
    if (a0 == 2) {
        v1 = a1 >> SHIFT(D_8004FE50);
        SH(D_8004FE40, v1);
        SH(SPU_BASE + 0x1A6, v1);
        return 0;
    }
    if (a0 != 3)
        return 0;

    want = (LW(D_8004FE78) == 1) ? 0x30 : 0x20;
    base = SPU_BASE;
    if ((uint32_t)(LHU(base + 0x1AA) & 0x30) != want) {
        v1 = 1;
        for (;;) {
            if (v1 >= 0xF01)
                return -2;
            if ((uint32_t)(LHU(base + 0x1AA) & 0x30) == want)
                break;
            v1++;
        }
    }
    if (LW(D_8004FE78) == 1)
        _spu_FsetDelayR();
    else
        _spu_FsetDelayW();
    SW(D_8004FE7C, a1);
    SW(D_8004FE80, (a2 >> 6) + ((a2 & 0x3F) != 0));
    SW(LW(D_8004FE2C), LW(D_8004FE7C));                     /* MADR */
    SW(LW(D_8004FE30), ((uint32_t)LW(D_8004FE80) << 16) | 0x10); /* BCR: n blocks of 16 words */
    chcr = 0x01000201u;
    if (LW(D_8004FE78) == 1)
        chcr = 0x01000200u;
    SW(LW(D_8004FE34), chcr); /* CHCR: start */
    return 0;
}

/* _spu_Fw 0x8003A9F8: write a1 bytes from a0 to sound RAM at the transfer address */
int _spu_Fw(uint32_t a0, uint32_t a1)
{
    if (LW(D_8004FE44) == 0) {
        _spu_t(2, (uint32_t)LHU(D_8004FE40) << SHIFT(D_8004FE50), 0);
        _spu_t(1, 0, 0);
        _spu_t(3, a0, a1);
    } else {
        _spu_FwriteByIO(a0, a1);
    }
    return (int)a1;
}

/* _spu_FsetRXX 0x8003AAE0 */
int _spu_FsetRXX(int a0, uint32_t a1, int a2)
{
    uint32_t p = ((uint32_t)a0 << 1) + SPU_BASE;

    if (a2 == 0)
        SH(p, a1);
    else
        SH(p, a1 >> SHIFT(D_8004FE50));
    return 0;
}

/* _spu_FsetRXXa 0x8003AB24: a0 = register index, -1: return the converted address,
 * -2: return the aligned byte address */
int _spu_FsetRXXa(int a0, uint32_t a1)
{
    uint32_t unit, a3;

    if (LW(D_8004FE4C) != 0) {
        unit = (uint32_t)LW(D_8004FE54);
        if (unit == 0) {
            Psx_printf(SND_ADDR("_spu_FsetRXXa: divide by 0\n"));
        } else if (a1 % unit != 0) {
            a1 = (a1 + unit) & ~(uint32_t)LW(D_8004FE58);
        }
    }
    a3 = a1 >> SHIFT(D_8004FE50);
    if (a0 == -2)
        return (int)a1;
    if (a0 == -1)
        return (int)(a3 & 0xFFFF);
    SH(((uint32_t)a0 << 1) + SPU_BASE, a3);
    return (int)a1;
}

/* _SpuDataCallback 0x8003AD14 */
int _SpuDataCallback(uint32_t a0)
{
    return (int)Psx_DMACallback(4, a0);
}

/* SpuStart 0x8003A13C: install the DMA handler and open the DMA event */
int SpuStart(void)
{
    int ev;

    if (LW(_spu_isCalled) == 0) {
        SW(_spu_isCalled, 1);
        Psx_EnterCriticalSection();
        _SpuDataCallback(SND_FNVAL(_spu_FiDMA));
        ev = Psx_OpenEvent((int)0xF0000009, 0x20, 0x2000, 0);
        SW(_spu_EVdma, ev);
        Psx_EnableEvent(ev);
        Psx_ExitCriticalSection();
    }
    return 0;
}

/* _SpuInit 0x8003A054 */
int _SpuInit(int a0)
{
    uint32_t p;
    int32_t i;
    uint32_t a1;

    Psx_ResetCallback();
    _spu_init(a0);
    if (a0 == 0) {
        p = D_8004FE12;
        for (i = 0x17; i >= 0; i--, p -= 2)
            SH(p, 0xC000);
    }
    SpuStart();
    a1 = (uint32_t)LW(D_800503B8);
    SW(D_8004FDBC, 0);
    SW(D_8004FDC0, 0);
    SW(D_8004FDCC, 0);
    SH(D_8004FDCC + 4, 0);
    SH(D_8004FDCC + 6, 0);
    SW(D_8004FDCC + 8, 0);
    SW(D_8004FDCC + 0xC, 0);
    SW(D_8004FDC4, a1);
    _spu_FsetRXX(0xD1, a1, 0); /* reverb work area start */
    SW(D_8004FE88, 0);
    SW(D_8004FE8C, 0);
    SW(Spu_MemList, 0);
    SW(D_8004FDB8, 0);
    SW(D_8004FE44, 0);
    SW(D_8004FDB4, 0);
    SW(D_8004FDE0, 0);
    SW(D_8004FDDC, 0);
    SW(D_8004FE14, 0);
    return 0;
}

/* SpuInit 0x8003A034 */
int SpuInit(void)
{
    _SpuInit(0);
    return 0;
}

/* SpuInitMalloc 0x8003AD44: a0 = max blocks, a1 = block table (8 bytes per entry) */
int SpuInitMalloc(int a0, uint32_t a1)
{
    if (a0 <= 0)
        return 0;
    SW(a1, 0x40001010u);
    SW(Spu_MemList, a1);
    SW(D_8004FE8C, 0);
    SW(D_8004FE88, a0);
    SW(a1 + 4, (0x10000u << SHIFT(D_8004FE50)) - 0x1010);
    return a0;
}

/* _spu_gcSPU 0x8003B074: merge free blocks, drop empty ones, sort by address.
 * Entry word: bit 31 free, bit 30 end of list, 0x2FFFFFFF unused, low 28 bits address. */
int _spu_gcSPU(void)
{
    int32_t n, t1, t5, a2, a1n, v1n;
    uint32_t t0, a3, p, a1, a0, v, e, w;

    n = LW(D_8004FE8C);
    t1 = 0;
    if (n >= 0) {
        t0 = (uint32_t)LW(Spu_MemList);
        t5 = n;
        a3 = t0;
        do {
            if ((uint32_t)LW(a3) & 0x80000000u) {
                a2 = t1 + 1;
                p = ((uint32_t)a2 << 3) + t0;
                while ((uint32_t)LW(p) == 0x2FFFFFFFu) {
                    p += 8;
                    a2++;
                }
                a1 = ((uint32_t)a2 << 3) + t0;
                e = (uint32_t)LW(a1);
                if ((e & 0x80000000u) &&
                    (e & 0x0FFFFFFFu) == ((uint32_t)LW(a3) & 0x0FFFFFFFu) + (uint32_t)LW(a3 + 4)) {
                    /* merge the following free block, check this entry again */
                    SW(a1, 0x2FFFFFFFu);
                    SW(a3 + 4, (uint32_t)LW(a3 + 4) + (uint32_t)LW(a1 + 4));
                    continue;
                }
            }
            a3 += 8;
            t1++;
        } while (t1 <= t5);
        n = LW(D_8004FE8C);
    }

    if (n >= 0) {
        p = (uint32_t)LW(Spu_MemList);
        for (t1 = 0; t1 <= n; t1++, p += 8) {
            if (LW(p + 4) == 0)
                SW(p, 0x2FFFFFFFu);
        }
    }

    v1n = LW(D_8004FE8C);
    if (v1n >= 0) {
        uint32_t t5p = (uint32_t)LW(Spu_MemList);
        uint32_t t2 = t5p;
        t1 = 0;
        do {
            int32_t t3;
            if ((uint32_t)LW(t2) & 0x40000000u)
                break;
            a2 = t1 + 1;
            if (!(v1n < a2)) {
                uint32_t t0p = t2;
                t3 = LW(D_8004FE8C);
                a0 = ((uint32_t)a2 << 3) + t5p;
                do {
                    a1 = (uint32_t)LW(a0);
                    if (a1 & 0x40000000u)
                        break;
                    a3 = (uint32_t)LW(t0p);
                    if ((a1 & 0x0FFFFFFFu) < (a3 & 0x0FFFFFFFu)) {
                        SW(t0p, a1);
                        v = (uint32_t)LW(a0 + 4);
                        w = (uint32_t)LW(t0p + 4);
                        SW(t0p + 4, v);
                        SW(a0, a3);
                        SW(a0 + 4, w);
                    }
                    a2++;
                    a0 += 8;
                } while (!(t3 < a2));
            }
            v1n = LW(D_8004FE8C);
            t1++;
            t2 += 8;
        } while (!(v1n < t1));
    }

    a1n = LW(D_8004FE8C);
    if (a1n >= 0) {
        uint32_t list = (uint32_t)LW(Spu_MemList);
        a0 = list;
        t1 = 0;
        for (;;) {
            uint32_t ev = (uint32_t)LW(a0);
            if (ev & 0x40000000u)
                break;
            if (ev == 0x2FFFFFFFu) {
                /* move the end marker here */
                uint32_t q = ((uint32_t)a1n << 3) + list;
                SW(a0, LW(q));
                v = (uint32_t)LW(q + 4);
                SW(D_8004FE8C, t1);
                SW(a0 + 4, v);
                break;
            }
            a1n = LW(D_8004FE8C);
            t1++;
            a0 += 8;
            if (a1n < t1)
                break;
        }
    }

    t1 = LW(D_8004FE8C) - 1;
    if (t1 >= 0) {
        uint32_t list = (uint32_t)LW(Spu_MemList);
        a0 = ((uint32_t)t1 << 3) + list;
        do {
            int32_t last;
            e = (uint32_t)LW(a0);
            if (!(e & 0x80000000u))
                break;
            /* free block before the end marker: becomes the end marker */
            last = LW(D_8004FE8C);
            SW(a0, (e & 0x0FFFFFFFu) | 0x40000000u);
            v = (uint32_t)LW(a0 + 4);
            SW(D_8004FE8C, t1);
            w = (uint32_t)LW(((uint32_t)last << 3) + list + 4);
            t1--;
            SW(a0 + 4, v + w);
            a0 -= 8;
        } while (t1 >= 0);
    }
    return 0;
}

/* SpuMalloc 0x8003ADA4 */
int SpuMalloc(int a0)
{
    uint32_t s1 = (uint32_t)a0, s3, mask, list, a2p, e, t0;
    int32_t s0 = 0, s2 = -1, n, a2i;

    if (LW(D_8004FDC0) == 0)
        s3 = 0;
    else
        s3 = (0x10000u - (uint32_t)LW(D_8004FDC4)) << SHIFT(D_8004FE50);
    mask = (uint32_t)LW(D_8004FE58);
    if (s1 & ~mask)
        s1 += mask;
    s1 = (uint32_t)((int32_t)s1 >> SHIFT(D_8004FE50));
    s1 = s1 << SHIFT(D_8004FE50);

    list = (uint32_t)LW(Spu_MemList);
    if ((uint32_t)LW(list) & 0x40000000u) {
        s2 = 0;
    } else {
        _spu_gcSPU();
        n = LW(D_8004FE88);
        if (s0 < n) {
            uint32_t p = ((uint32_t)s0 << 3) + (uint32_t)LW(Spu_MemList);
            do {
                e = (uint32_t)LW(p);
                if ((e & 0x40000000u) ||
                    ((e & 0x80000000u) && !((uint32_t)LW(p + 4) < s1))) {
                    s2 = s0;
                    break;
                }
                s0++;
                p += 8;
            } while (s0 < n);
        }
    }

    if (s2 == -1)
        return -1;
    list = (uint32_t)LW(Spu_MemList);
    a2p = ((uint32_t)s2 << 3) + list;
    e = (uint32_t)LW(a2p);
    if (e & 0x40000000u) {
        /* end marker: allocate from the remaining area */
        uint32_t q;
        if (!(s2 < LW(D_8004FE88)))
            return -1;
        if ((uint32_t)LW(a2p + 4) - s3 < s1)
            return -1;
        q = ((uint32_t)(s2 + 1) << 3) + list;
        SW(q, (((uint32_t)LW(a2p) & 0x0FFFFFFFu) + s1) | 0x40000000u);
        SW(q + 4, (uint32_t)LW(a2p + 4) - s1);
        e = (uint32_t)LW(a2p);
        SW(D_8004FE8C, s2 + 1);
        SW(a2p + 4, s1);
        SW(a2p, e & 0x0FFFFFFFu);
        _spu_gcSPU();
        return LW(((uint32_t)s2 << 3) + (uint32_t)LW(Spu_MemList));
    }

    /* free block: split when larger */
    t0 = (uint32_t)LW(a2p + 4);
    if (s1 < t0) {
        a2i = LW(D_8004FE8C);
        if (a2i < LW(D_8004FE88)) {
            uint32_t q = ((uint32_t)a2i << 3) + list;
            uint32_t w0 = (uint32_t)LW(q);
            uint32_t w1 = (uint32_t)LW(q + 4);
            SW(q, (e + s1) | 0x80000000u);
            SW(q + 4, t0 - s1);
            SW(D_8004FE8C, a2i + 1);
            SW(q + 8, w0);
            SW(q + 0xC, w1);
        }
    }
    a2p = ((uint32_t)s2 << 3) + (uint32_t)LW(Spu_MemList);
    e = (uint32_t)LW(a2p);
    SW(a2p + 4, s1);
    SW(a2p, e & 0x0FFFFFFFu);
    _spu_gcSPU();
    return LW(((uint32_t)s2 << 3) + (uint32_t)LW(Spu_MemList));
}

/* SpuFree 0x8003B374 */
int SpuFree(uint32_t a0)
{
    int32_t n, i;
    uint32_t p, e;

    n = LW(D_8004FE88);
    if (n > 0) {
        p = (uint32_t)LW(Spu_MemList);
        i = 0;
        for (;;) {
            e = (uint32_t)LW(p);
            if (e & 0x40000000u)
                break;
            i++;
            if (e == a0) {
                SW(p, a0 | 0x80000000u);
                break;
            }
            if (!(i < n))
                break;
            p += 8;
        }
    }
    _spu_gcSPU();
    return 0;
}

/* _SpuIsInAllocateArea_ 0x8003B904: 1 when an allocated block reaches past address a0 */
int _SpuIsInAllocateArea_(uint32_t a0)
{
    uint32_t p, e, addr;

    a0 <<= SHIFT(D_8004FE50);
    p = (uint32_t)LW(Spu_MemList);
    if (p == 0)
        return 0;
    for (;; p += 8) {
        e = (uint32_t)LW(p);
        if (e & 0x80000000u)
            continue;
        if (e & 0x40000000u)
            return 0;
        addr = e & 0x0FFFFFFFu;
        if (!(addr < a0))
            return 1;
        if (a0 < addr + (uint32_t)LW(p + 4))
            return 1;
    }
}

/* SpuSetNoiseVoice 0x8003B3F4 */
int SpuSetNoiseVoice(int a0, uint32_t a1)
{
    return _SpuSetAnyVoice(a0, a1, 0xCA, 0xCB);
}

/* _SpuSetAnyVoice 0x8003B424: a0 = 0 off, 1 on, 8 set; a2 / a3 = register index low / high */
int _SpuSetAnyVoice(int a0, uint32_t a1, int a2, int a3)
{
    uint32_t base, t2, lo, hi, bit;

    base = (LW(D_8004FE14) & 1) ? D_80062D60 : SPU_BASE;
    t2 = (uint32_t)LHU(((uint32_t)a2 << 1) + base) |
         (((uint32_t)LHU(((uint32_t)a3 << 1) + base) & 0xFF) << 16);
    bit = 1u << ((uint32_t)((a2 - 0xC6) >> 1) & 31);

    if (a0 == 1) {
        base = (LW(D_8004FE14) & 1) ? D_80062D60 : SPU_BASE;
        lo = ((uint32_t)a2 << 1) + base;
        hi = ((uint32_t)a3 << 1) + base;
        SH(lo, (uint32_t)LHU(lo) | a1);
        SH(hi, (uint32_t)LHU(hi) | ((a1 >> 16) & 0xFF));
        if (LW(D_8004FE14) & 1)
            SW(D_8004FDE0, (uint32_t)LW(D_8004FDE0) | bit);
        t2 |= a1 & 0xFFFFFF;
    } else if (a0 == 0) {
        base = (LW(D_8004FE14) & 1) ? D_80062D60 : SPU_BASE;
        lo = ((uint32_t)a2 << 1) + base;
        hi = ((uint32_t)a3 << 1) + base;
        SH(lo, (uint32_t)LHU(lo) & ~a1);
        SH(hi, (uint32_t)LHU(hi) & ~((a1 >> 16) & 0xFF));
        if (LW(D_8004FE14) & 1)
            SW(D_8004FDE0, (uint32_t)LW(D_8004FDE0) | bit);
        t2 &= ~(a1 & 0xFFFFFF);
    } else if (a0 == 8) {
        base = (LW(D_8004FE14) & 1) ? D_80062D60 : SPU_BASE;
        SH(((uint32_t)a2 << 1) + base, a1);
        SH(((uint32_t)a3 << 1) + base, (a1 >> 16) & 0xFF);
        if (LW(D_8004FE14) & 1)
            SW(D_8004FDE0, (uint32_t)LW(D_8004FDE0) | bit);
        t2 = a1 & 0xFFFFFF;
    }
    return (int)(t2 & 0xFFFFFF);
}

/* SpuGetNoiseVoice 0x8003B6E4 */
int SpuGetNoiseVoice(void)
{
    return _SpuGetAnyVoice(0xCA, 0xCB);
}

/* _SpuGetAnyVoice 0x8003B714 */
int _SpuGetAnyVoice(int a0, int a1)
{
    uint32_t base = SPU_BASE;
    uint32_t hi = LHU(((uint32_t)a1 << 1) + base);
    uint32_t lo = LHU(((uint32_t)a0 << 1) + base);

    return (int)(lo | ((hi & 0xFF) << 16));
}

/* SpuSetNoiseClock 0x8003B744 */
int SpuSetNoiseClock(int a0)
{
    int32_t a1 = 0;
    uint32_t base;

    if (a0 >= 0) {
        a1 = a0;
        if (!(a1 < 0x40))
            a1 = 0x3F;
    }
    base = SPU_BASE;
    SH(base + 0x1AA, ((uint32_t)LHU(base + 0x1AA) & 0xC0FF) | (((uint32_t)a1 & 0x3F) << 8));
    return a1;
}

/* SpuSetReverb 0x8003B794 */
int SpuSetReverb(int a0)
{
    uint32_t base, v;

    if (a0 == 0) {
        base = SPU_BASE;
        v = LHU(base + 0x1AA);
        SW(D_8004FDBC, 0);
        SH(base + 0x1AA, v & 0xFF7F);
        SH(base + 0x184, 0);
        SH(base + 0x186, 0);
        SH(D_8004FDD0, 0);
        SH(D_8004FDD0 + 2, 0);
    } else if (a0 == 1) {
        if (LW(D_8004FDC0) != a0 && _SpuIsInAllocateArea_((uint32_t)LW(D_8004FDC4)) != 0) {
            /* work area overlaps allocated sound RAM: reverb stays off */
            base = SPU_BASE;
            v = LHU(base + 0x1AA);
            SW(D_8004FDBC, 0);
            v &= 0xFF7F;
        } else {
            base = SPU_BASE;
            v = LHU(base + 0x1AA);
            SW(D_8004FDBC, a0);
            v |= 0x80;
        }
        SH(base + 0x1AA, v);
    }
    return LW(D_8004FDBC);
}

/* SpuSetReverbModeParam 0x8003B994 */
int SpuSetReverbModeParam(uint32_t a0)
{
    uint32_t buf[0x44 / 4]; /* SpuReverbAttr for _spu_setReverbAttr (retail sp+0x10) */
    uint32_t b = SND_ADDR(buf);
    uint32_t s3, s0, base, src, q;
    int32_t s4 = 0, s5, s6 = 0, s7 = 0, fp = 0, clear = 0, v1, i;
    int32_t v0, a1, a3, a2;

    for (i = 0; i < 0x44 / 4; i++)
        buf[i] = 0;
    s3 = (uint32_t)LW(a0);
    s5 = (s3 == 0);

    if (s5 || (s3 & 1)) {
        s0 = (uint32_t)LW(a0 + 4);
        if (s0 & 0x100) {
            s0 &= ~0x100u;
            clear = 1;
        }
        if (s0 >= 10)
            return -1;
        if (_SpuIsInAllocateArea_((uint32_t)LW(D_800503B8 + (s0 << 2))) != 0)
            return -1;
        s4 = 1;
        SW(D_8004FDCC, s0);
        v1 = LW(D_8004FDCC);
        SW(D_8004FDC4, LW(((uint32_t)v1 << 2) + D_800503B8));
        src = (uint32_t)v1 * 0x44 + D_800503E8;
        for (i = 0; i < 0x44; i++)
            SB(b + i, LBU(src + i));
        v1 = LW(D_8004FDCC);
        if (v1 == 7) {
            SW(D_8004FDD8, 0x7F);
            SW(D_8004FDD4, 0x7F);
        } else if (v1 == 8) {
            SW(D_8004FDD8, 0);
            SW(D_8004FDD4, 0x7F);
        } else {
            SW(D_8004FDD8, 0);
            SW(D_8004FDD4, 0);
        }
    }

    if (s5 || (s3 & 8)) {
        /* delay time (echo / delay modes only) */
        v1 = LW(D_8004FDCC);
        if (v1 < 9 && !(v1 < 7)) {
            s6 = 1;
            if (!s4) {
                src = (uint32_t)LW(D_8004FDCC) * 0x44 + D_800503E8;
                for (i = 0; i < 0x44; i++)
                    SB(b + i, LBU(src + i));
                SW(b, 0x0C011C00u);
            }
            v0 = LW(a0 + 0xC);
            v1 = (int32_t)((uint32_t)v0 << 13);
            a3 = MULT_HI(v1, 0x81020409);
            a1 = (int32_t)((uint32_t)v0 << 12);
            SW(D_8004FDD4, v0);
            q = (uint32_t)(((a3 + v1) >> 6) - (v1 >> 31));
            SH(b + 0x18, q - (uint32_t)LHU(b + 4));
            a2 = MULT_HI(a1, 0x81020409);
            q = (uint32_t)(((a2 + a1) >> 6) - (a1 >> 31));
            SH(b + 0x1A, q - (uint32_t)LHU(b + 6));
            SH(b + 0x24, (uint32_t)LHU(b + 0x26) + q);
            SH(b + 0x1C, (uint32_t)LHU(b + 0x1E) + q);
            SH(b + 0x3A, (uint32_t)LHU(b + 0x3E) + q);
            SH(b + 0x38, (uint32_t)LHU(b + 0x3C) + q);
        }
    }

    if (s5 || (s3 & 0x10)) {
        /* feedback (echo / delay modes only) */
        v1 = LW(D_8004FDCC);
        if (v1 < 9 && !(v1 < 7)) {
            fp = 1;
            if (!s4) {
                uint32_t m;
                if (!s6) {
                    src = (uint32_t)LW(D_8004FDCC) * 0x44 + D_800503E8;
                    for (i = 0; i < 0x44; i++)
                        SB(b + i, LBU(src + i));
                    m = 0x80;
                } else {
                    m = (uint32_t)LW(b) | 0x80;
                }
                SW(b, m);
            }
            v1 = LW(a0 + 0x10);
            v0 = (int32_t)((((uint32_t)v1 << 7) + (uint32_t)v1) << 8);
            SW(D_8004FDD8, v1);
            SH(b + 0x12, (uint32_t)(((MULT_HI(v0, 0x81020409) + v0) >> 6) - (v0 >> 31)));
        }
    }

    if (s4) {
        base = SPU_BASE;
        s7 = (LHU(base + 0x1AA) >> 7) & 1;
        if (s7)
            SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFF7F); /* reverb off while changing mode */
        base = SPU_BASE;
        SH(base + 0x184, 0);
        SH(base + 0x186, 0);
        SH(D_8004FDD0, 0);
        SH(D_8004FDD0 + 2, 0);
    } else {
        if (s5 || (s3 & 2)) {
            SH(SPU_BASE + 0x184, LHU(a0 + 8));
            SH(D_8004FDD0, LHU(a0 + 8));
        }
        if (s5 || (s3 & 4)) {
            SH(SPU_BASE + 0x186, LHU(a0 + 0xA));
            SH(D_8004FDD2, LHU(a0 + 0xA));
        }
    }

    if (s4 || s6 || fp)
        _spu_setReverbAttr(b);
    if (clear)
        SpuClearReverbWorkArea(LW(D_8004FDCC));
    if (s4) {
        _spu_FsetRXX(0xD1, (uint32_t)LW(D_8004FDC4), 0);
        if (s7) {
            base = SPU_BASE;
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x80);
        }
    }
    return 0;
}

/* _spu_setReverbAttr 0x8003BE74: reverb registers 0x1C0..0x1FE from a mask + 32 halfwords */
int _spu_setReverbAttr(uint32_t a0)
{
    uint32_t mask = (uint32_t)LW(a0);
    int all = (mask == 0);
    int32_t i;

    for (i = 0; i < 32; i++) {
        if (all || (mask & (1u << i)))
            SH(SPU_BASE + 0x1C0 + i * 2, LHU(a0 + 4 + i * 2));
    }
    return 0;
}

/* SpuSetReverbVoice 0x8003C344 */
int SpuSetReverbVoice(int a0, uint32_t a1)
{
    return _SpuSetAnyVoice(a0, a1, 0xCC, 0xCD);
}

/* SpuGetReverbVoice 0x8003C374 */
int SpuGetReverbVoice(void)
{
    return _SpuGetAnyVoice(0xCC, 0xCD);
}

/* SpuClearReverbWorkArea 0x8003C3A4: DMA zeros over the reverb work area of mode a0 */
int SpuClearReverbWorkArea(uint32_t a0)
{
    uint32_t saved = 0, s1, s2, s0, p, a;
    int32_t s3, s4, s5 = 0;

    if (a0 >= 10)
        return -1;
    p = D_800503B8 + (a0 << 2);
    if (_SpuIsInAllocateArea_((uint32_t)LW(p)) != 0)
        return -1;
    if (a0 == 0) {
        s1 = 0x10u << SHIFT(D_8004FE50);
        s2 = 0xFFF0u << SHIFT(D_8004FE50);
    } else {
        a = (uint32_t)LW(p);
        s1 = (0x10000u - a) << SHIFT(D_8004FE50);
        s2 = a << SHIFT(D_8004FE50);
    }
    s4 = LW(D_8004FE44);
    if (s4 == 1) {
        SW(D_8004FE44, 0);
        s5 = 1;
    }
    s3 = 1;
    if (LW(D_8004FE60) != 0) {
        saved = (uint32_t)LW(D_8004FE60);
        SW(D_8004FE60, 0);
    }
    do {
        if (s1 < 0x401) {
            s0 = s1;
            s3 = 0;
        } else {
            s0 = 0x400;
        }
        _spu_t(2, s2, 0);
        _spu_t(1, 0, 0);
        _spu_t(3, D_8004FE98, s0);
        s1 -= 0x400;
        s2 += 0x400;
        Psx_WaitEvent(LW(_spu_EVdma));
    } while (s3);
    if (s5)
        SW(D_8004FE44, s4);
    if (saved)
        SW(D_8004FE60, saved);
    return 0;
}

/* SpuSetKey 0x8003C554: a0 = 1 key on, 0 key off, a1 = voice mask */
int SpuSetKey(int a0, uint32_t a1)
{
    uint32_t a2, base, p = D_80062EE8;

    a1 &= 0xFFFFFF;
    a2 = a1 >> 16;
    if (a0 == 0) {
        if (LW(D_8004FE14) & 1) {
            SH(p + 4, a1);
            SH(p + 6, a2);
            SW(D_8004FDE0, (uint32_t)LW(D_8004FDE0) | 1);
            SW(D_8004FDDC, (uint32_t)LW(D_8004FDDC) & ~a1);
            if (LHU(p) & a1)
                SH(p, (uint32_t)LHU(p) & ~a1);
            if (LHU(p + 2) & a2)
                SH(p + 2, (uint32_t)LHU(p + 2) & ~a2);
        } else {
            base = SPU_BASE;
            SH(base + 0x18C, a1);
            SH(base + 0x18E, a2);
            SW(D_8004FDB4, (uint32_t)LW(D_8004FDB4) & ~a1);
        }
    } else if (a0 == 1) {
        if (LW(D_8004FE14) & 1) {
            SH(p, a1);
            SH(p + 2, a2);
            SW(D_8004FDE0, (uint32_t)LW(D_8004FDE0) | 1);
            SW(D_8004FDDC, (uint32_t)LW(D_8004FDDC) | a1);
            if (LHU(p + 4) & a1)
                SH(p + 4, (uint32_t)LHU(p + 4) & ~a1);
            if (LHU(p + 6) & a2)
                SH(p + 6, (uint32_t)LHU(p + 6) & ~a2);
        } else {
            uint32_t v = (uint32_t)LW(D_8004FDB4) | a1;
            base = SPU_BASE;
            SH(base + 0x188, a1);
            SH(base + 0x18A, a2);
            SW(D_8004FDB4, v);
        }
    }
    return 0;
}

/* SpuWrite 0x8003C714 */
int SpuWrite(uint32_t a0, uint32_t a1)
{
    uint32_t s0 = a1;

    if (s0 > 0x7EFF0)
        s0 = 0x7EFF0;
    _spu_Fw(a0, s0);
    if (LW(D_8004FE60) == 0)
        SW(Spu_InTransfer, 0);
    return (int)s0;
}

/* SpuSetTransferStartAddr 0x8003C774 */
int SpuSetTransferStartAddr(uint32_t a0)
{
    if (a0 - 0x1010 > 0x7EFE8)
        return 0;
    SH(D_8004FE40, _spu_FsetRXXa(-1, a0));
    return (int)((uint32_t)LHU(D_8004FE40) << SHIFT(D_8004FE50));
}

/* SpuSetTransferMode 0x8003C7D4 */
int SpuSetTransferMode(int a0)
{
    int32_t v = (a0 == 1) ? 1 : 0;

    SW(D_8004FDB8, a0);
    SW(D_8004FE44, v);
    return v;
}

/* SpuIsTransferCompleted 0x8003C804: a0 = 1 waits for the DMA event */
int SpuIsTransferCompleted(int a0)
{
    int v;

    if (LW(D_8004FDB8) == 1 || LW(Spu_InTransfer) == 1)
        return 1;
    v = Psx_TestEvent(LW(_spu_EVdma));
    if (a0 == 1) {
        if (v == 0) {
            do
                v = Psx_TestEvent(LW(_spu_EVdma));
            while (v == 0);
        }
        v = 1;
    } else if (v != 1) {
        return v;
    }
    SW(Spu_InTransfer, v);
    return v;
}

/* _spu_setInTransfer 0x8003C8C4 */
int _spu_setInTransfer(int a0)
{
    SW(Spu_InTransfer, a0 == 1 ? 0 : 1);
    return 0;
}

/* _spu_getInTransfer 0x8003C8EC */
int _spu_getInTransfer(void)
{
    return LW(Spu_InTransfer) != 1;
}

/* Volume mode from the attr mode field: 0x8000 + (mode - 1) * 0x1000 for modes 1..7. */
static uint32_t Spu_VolMode(uint32_t mode16)
{
    int32_t idx = (int16_t)(uint16_t)(mode16 - 1);

    if ((uint32_t)idx < 7)
        return 0x8000u + (uint32_t)idx * 0x1000u;
    return 0;
}

/* SpuSetVoiceAttr 0x8003C904: a0 = SpuVoiceAttr (voice mask, attr mask, fields) */
int SpuSetVoiceAttr(uint32_t a0)
{
    uint32_t s1, s3, s5, a1, a2, m, p, n;
    int32_t s2, s4, h;
    volatile int32_t dly_i, dly_v;

    s1 = (uint32_t)LW(a0 + 4);
    s5 = D_8004FDE4;
    s2 = (s1 == 0);
    for (s4 = 0; s4 < 0x18; s4++, s5 += 2) {
        if (!((uint32_t)LW(a0) & (1u << s4)))
            continue;
        s3 = (uint32_t)s4 << 3;
        p = (s3 << 1) + SPU_BASE;
        if (s2 || (s1 & 0x10))
            SH(((uint32_t)s4 << 4) + SPU_BASE + 4, LHU(a0 + 0x14)); /* pitch */
        if (s2 || (s1 & 0x40))
            SH(s5, LHU(a0 + 0x18)); /* note */
        if (s2 || (s1 & 0x20)) {
            n = LHU(s5);
            m = LHU(a0 + 0x16); /* sample note */
            SH((s3 << 1) + SPU_BASE + 4, _spu_note2pitch(n >> 8, n & 0xFF, m >> 8, m & 0xFF));
        }
        if (s2 || (s1 & 1)) {
            /* volume L */
            m = 0;
            a1 = LHU(a0 + 8) & 0x7FFF;
            if (s2 || (s1 & 4))
                m = Spu_VolMode(LHU(a0 + 0xC));
            if (m) {
                h = LH(a0 + 8);
                if (!(h < 0x80))
                    a1 = 0x7F;
                else if (h < 0)
                    a1 = 0;
            }
            SH((s3 << 1) + SPU_BASE, a1 | m);
        }
        if (s2 || (s1 & 2)) {
            /* volume R */
            m = 0;
            a1 = LHU(a0 + 0xA) & 0x7FFF;
            if (s2 || (s1 & 8))
                m = Spu_VolMode(LHU(a0 + 0xE));
            if (m) {
                h = LH(a0 + 0xA);
                if (!(h < 0x80))
                    a1 = 0x7F;
                else if (h < 0)
                    a1 = 0;
            }
            SH((s3 << 1) + SPU_BASE + 2, a1 | m);
        }
        if (s2 || (s1 & 0x80))
            _spu_FsetRXXa((int)(s3 | 3), (uint32_t)LW(a0 + 0x1C)); /* start address */
        if (s2 || (s1 & 0x10000))
            _spu_FsetRXXa((int)(s3 | 7), (uint32_t)LW(a0 + 0x20)); /* loop address */
        if (s2 || (s1 & 0x20000))
            SH((s3 << 1) + SPU_BASE + 8, LHU(a0 + 0x3A)); /* ADSR1 */
        if (s2 || (s1 & 0x40000))
            SH((s3 << 1) + SPU_BASE + 0xA, LHU(a0 + 0x3C)); /* ADSR2 */
        if (s2 || (s1 & 0x800)) {
            /* attack rate + mode */
            a1 = LHU(a0 + 0x30);
            if (!(a1 < 0x80))
                a1 = 0x7F;
            a2 = 0;
            if ((s2 || (s1 & 0x100)) && LW(a0 + 0x24) == 5)
                a2 = 0x80;
            p = (s3 << 1) + SPU_BASE;
            SH(p + 8, ((uint32_t)LHU(p + 8) & 0xFF) | ((a1 | a2) << 8));
        }
        if (s2 || (s1 & 0x1000)) {
            /* decay rate */
            a1 = LHU(a0 + 0x32);
            if (!(a1 < 0x10))
                a1 = 0xF;
            p = (s3 << 1) + SPU_BASE;
            SH(p + 8, ((uint32_t)LHU(p + 8) & 0xFF0F) | (a1 << 4));
        }
        if (s2 || (s1 & 0x2000)) {
            /* sustain rate + mode */
            a1 = LHU(a0 + 0x34);
            if (!(a1 < 0x80))
                a1 = 0x7F;
            a2 = 0x100;
            if (s2 || (s1 & 0x200)) {
                int32_t md = LW(a0 + 0x28);
                if (md == 5)
                    a2 = 0x200;
                else if (md < 6) {
                    if (md == 1)
                        a2 = 0;
                } else if (md == 7)
                    a2 = 0x300;
            }
            p = (s3 << 1) + SPU_BASE;
            SH(p + 0xA, ((uint32_t)LHU(p + 0xA) & 0x3F) | ((a1 | a2) << 6));
        }
        if (s2 || (s1 & 0x4000)) {
            /* release rate + mode */
            a1 = LHU(a0 + 0x36);
            if (!(a1 < 0x20))
                a1 = 0x1F;
            a2 = 0;
            if (s2 || (s1 & 0x400)) {
                int32_t md = LW(a0 + 0x2C);
                if (md != 3 && md == 7)
                    a2 = 0x20;
            }
            p = (s3 << 1) + SPU_BASE;
            SH(p + 0xA, ((uint32_t)LHU(p + 0xA) & 0xFFC0) | (a1 | a2));
        }
        if (s2 || (s1 & 0x8000)) {
            /* sustain level */
            a1 = LHU(a0 + 0x38);
            if (!(a1 < 0x10))
                a1 = 0xF;
            p = (s3 << 1) + SPU_BASE;
            SH(p + 8, ((uint32_t)LHU(p + 8) & 0xFFF0) | a1);
        }
    }
    dly_v = 1;
    for (dly_i = 0; dly_i < 2; dly_i++)
        dly_v = dly_v * 13;
    return 0;
}

/* _spu_note2pitch 0x8003CF04: a0/a1 = voice note / fine, a2/a3 = target note / fine */
int _spu_note2pitch(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    uint32_t sum, fine, t1, t2;
    int32_t d, q, oct, rem, sh;
    uint32_t r;

    sum = (a3 + a1) & 0xFFFF;
    d = (int16_t)(uint16_t)(a2 + (sum >> 7) - a0);
    q = (MULT_HI(d, 0x2AAAAAAB) >> 1) - (d >> 31); /* d / 12 */
    oct = q - 2;
    rem = d - q * 12;
    if ((int16_t)(uint16_t)rem < 0) {
        rem += 12;
        oct = q - 3;
    }
    fine = sum & 0x7F;
    t1 = LHU(D_80050298 + (uint32_t)((int32_t)(int16_t)(uint16_t)rem << 1));
    t2 = LHU(D_800502B0 + ((fine & 0xFFFF) << 1));
    r = (uint32_t)((int32_t)(t1 * t2) >> 16);
    sh = (int16_t)(uint16_t)oct;
    if (sh >= 0) {
        r = 0x3FFF;
    } else {
        uint32_t n = (uint32_t)(-sh);
        r = (r + (1u << ((n - 1) & 31))) >> (n & 31);
    }
    return (int)(r & 0xFFFF);
}

/* SpuGetVoiceEnvelope 0x8003D104 */
int SpuGetVoiceEnvelope(int a0, uint32_t a1)
{
    uint32_t v = LHU(((uint32_t)a0 << 4) + SPU_BASE + 0xC);

    SH(a1, v);
    return (int)v;
}

/* SpuSetCommonAttr 0x8003D124: a0 = SpuCommonAttr (mask, master volume, CD / ext mix) */
int SpuSetCommonAttr(uint32_t a0)
{
    uint32_t t1, a1, a2, base;
    int32_t all, h, idx;

    t1 = (uint32_t)LW(a0);
    all = (t1 == 0);

    if (all || (t1 & 1)) {
        /* master volume L */
        a1 = 0;
        a2 = 0;
        if (all || (t1 & 4)) {
            idx = LH(a0 + 8);
            if ((uint32_t)idx < 8 && idx != 0)
                a1 = 0x8000u + (uint32_t)(idx - 1) * 0x1000u;
        }
        if (a1 == 0) {
            a2 = LHU(a0 + 4);
        } else {
            h = LH(a0 + 4);
            a2 = 0x7F;
            if (h < 0x80) {
                a2 = 0;
                if (h >= 0)
                    a2 = LHU(a0 + 4);
            }
        }
        SH(SPU_BASE + 0x180, (a2 & 0x7FFF) | a1);
    }
    if (all || (t1 & 2)) {
        /* master volume R */
        a1 = 0;
        a2 = 0;
        if (all || (t1 & 8)) {
            idx = LH(a0 + 0xA);
            if ((uint32_t)idx < 8 && idx != 0)
                a1 = 0x8000u + (uint32_t)(idx - 1) * 0x1000u;
        }
        if (a1 == 0) {
            a2 = LHU(a0 + 6);
        } else {
            h = LH(a0 + 6);
            a2 = 0x7F;
            if (h < 0x80) {
                a2 = 0;
                if (h >= 0)
                    a2 = LHU(a0 + 6);
            }
        }
        SH(SPU_BASE + 0x182, (a2 & 0x7FFF) | a1);
    }
    if (all || (t1 & 0x40))
        SH(SPU_BASE + 0x1B0, LHU(a0 + 0x10)); /* CD volume L */
    if (all || (t1 & 0x80))
        SH(SPU_BASE + 0x1B2, LHU(a0 + 0x12)); /* CD volume R */
    if (all || (t1 & 0x400))
        SH(SPU_BASE + 0x1B4, LHU(a0 + 0x1C)); /* ext volume L */
    if (all || (t1 & 0x800))
        SH(SPU_BASE + 0x1B6, LHU(a0 + 0x1E)); /* ext volume R */
    if (all || (t1 & 0x100)) {
        base = SPU_BASE;
        if (LW(a0 + 0x14) == 0)
            SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFFFB); /* CD reverb */
        else
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x4);
    }
    if (all || (t1 & 0x200)) {
        base = SPU_BASE;
        if (LW(a0 + 0x18) == 0)
            SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFFFE); /* CD mix */
        else
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x1);
    }
    if (all || (t1 & 0x1000)) {
        base = SPU_BASE;
        if (LW(a0 + 0x20) == 0)
            SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFFF7); /* ext reverb */
        else
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x8);
    }
    if (all || (t1 & 0x2000)) {
        base = SPU_BASE;
        if (LW(a0 + 0x24) == 0)
            SH(base + 0x1AA, LHU(base + 0x1AA) & 0xFFFD); /* ext mix */
        else
            SH(base + 0x1AA, LHU(base + 0x1AA) | 0x2);
    }
    return 0;
}
