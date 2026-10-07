/* libsnd sequencer (retail Psy-Q 4.7, translated from asm/USA/main/nonmatchings/psyq):
 * the per-VBlank score walk, the SEQ event reader and the MIDI event / controller / NRPN
 * handlers. Score layout (one 0xB0 block per sequence, Snd_SeqScores[sep] points to the first):
 *
 *   0x00 u32 read pointer           0x04 u32 data start (after header)  0x08 u32 loop start
 *   0x0C u32 alternate start (0x400) 0x10 u32 end check pointer (0x401)
 *   0x14 u8  playing                 0x15 u8 loop active                 0x16 u8 running status
 *   0x17 u8  channel                 0x18 / 0x19 u8 RPN LSB / MSB        0x1A / 0x1B NRPN LSB / MSB
 *   0x1C u8  loop start flag         0x1D u8 loop count                  0x1E / 0x1F RPN / NRPN count
 *   0x20 s8  play count (0 = loop)   0x21 u8 times played                0x22 / 0x23 s8 next sep
 *   0x26 s8  vab id                  0x27[16] u8 channel pan             0x37[16] u8 channel program
 *   0x48 s16 crescendo volume step   0x4A s16 crescendo volume done      0x4E s16 tempo step
 *   0x50 s16 resolution (tpqn)       0x52 s16 VBlank counter (-1 fast)   0x54 s16 ticks per VBlank
 *   0x56 u16 initial ticks per VBlank 0x5C / 0x5E u16 seq vol L / R      0x60[16] u16 channel vol
 *   0x80 s16 channel mute mask       0x84 u32 initial delta              0x88 u32 total ticks
 *   0x8C u32 initial tempo           0x90 s32 delta left (x10)           0x94 u32 tempo (BPM)
 *   0x98 u32 command flags           0x9C / 0xA0 crescendo length / pos  0xA8 tempo frames left
 *   0xAC u32 target tempo */

#include "snd_native.h"
#include "libsnd.h"
#include "psyq_log.h"

#define Snd_SeqScores 0x80061C50u
#define Snd_MarkCallbacks 0x80061CD0u
#define Snd_TicksPerSec 0x80061C4Cu
#define D_80061C44 0x80061C44u /* SsSeqCalledTbyT busy flag */
#define D_80061C48 0x80061C48u /* open sep bit mask */
#define D_800624D0 0x800624D0u /* s16 sep count (SsSetTableSize s_max) */
#define D_800624D2 0x800624D2u /* s16 seq per sep (SsSetTableSize t_max) */
/* MIDI event handlers, filled by _SsInit */
#define D_80061BB0 0x80061BB0u /* note on */
#define D_80061BB4 0x80061BB4u /* program change */
#define D_80061BB8 0x80061BB8u /* pitch bend */
#define D_80061BBC 0x80061BBCu /* meta event */
#define D_80061BC0 0x80061BC0u /* control change */
/* controller handlers */
#define D_80061BC8 0x80061BC8u /* 0x06 data entry */
#define D_80061BCC 0x80061BCCu /* 0x07 main volume */
#define D_80061BD0 0x80061BD0u /* 0x0A panpot */
#define D_80061BD4 0x80061BD4u /* 0x0B expression */
#define D_80061BD8 0x80061BD8u /* 0x40 damper */
#define D_80061BDC 0x80061BDCu /* 0x62 NRPN LSB */
#define D_80061BE0 0x80061BE0u /* 0x63 NRPN MSB */
#define D_80061BE4 0x80061BE4u /* 0x64 RPN LSB */
#define D_80061BE8 0x80061BE8u /* 0x65 RPN MSB */
#define D_80061BEC 0x80061BECu /* 0x5B external effect depth */
#define D_80061BF0 0x80061BF0u /* 0x79 reset all */
#define D_80061BF4 0x80061BF4u /* NRPN attribute handlers [20] */

/* Score block of (sep, seq): sep and seq already sign extended. */
#define SCORE(sep, seq) ((uint32_t)LW(Snd_SeqScores + ((uint32_t)(sep) << 2)) + (uint32_t)(seq) * 0xB0u)
#define S16(x) ((int32_t)(int16_t)(x))
#define SEQKEY(a0, a1) S16((uint32_t)(a0) | ((uint32_t)(a1) << 8))

/* SsSeqCalledTbyT 0x80031854 */
void SsSeqCalledTbyT(void)
{
    int32_t i, j;
    uint32_t tbl, off, sc;

    PSYQ_LOG("");
    if (LW(D_80061C44) == 1)
        return;
    SW(D_80061C44, 1);
    _SsVmFlush();
    if (LH(D_800624D0) > 0) {
        tbl = Snd_SeqScores;
        i = 0;
        do {
            if ((LW(D_80061C48) & (1u << (i & 31))) != 0 && LH(D_800624D2) > 0) {
                j = 0;
                off = 0;
                do {
                    int32_t sep = S16(i), seq = S16(j);
                    sc = (uint32_t)LW(tbl) + off;
                    if (LW(sc + 0x98) & 0x1) {
                        func_80031D74(sep, seq);
                        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x10)
                            _SsSndCrescendo(sep, seq);
                        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x20)
                            _SsSndCrescendo(sep, seq);
                        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x40)
                            _SsSndTempo(sep, seq);
                        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x80)
                            _SsSndTempo(sep, seq);
                    }
                    if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x2)
                        _SsSndPause(sep, seq);
                    if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x8)
                        _SsSndReplay(sep, seq);
                    if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x4) {
                        _SsSndStop(sep, seq);
                        SW((uint32_t)LW(tbl) + off + 0x98, 0);
                    }
                    j++;
                    off += 0xB0;
                } while (j < LH(D_800624D2));
            }
            i++;
            tbl += 4;
        } while (i < LH(D_800624D0));
    }
    SW(D_80061C44, 0);
}

/* func_80031D74 0x80031D74 */
int func_80031D74(int a0, int a1)
{
    func_80031DA4(S16(a0), S16(a1));
    return 0;
}

/* func_80031DA4 0x80031DA4: advance one score by one VBlank, read the events that fall due */
int func_80031DA4(int a0, int a1)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t s1 = SCORE(sep, seq);
    int32_t step = LH(s1 + 0x54);
    int32_t left = LW(s1 + 0x90);
    int32_t stepu = LHU(s1 + 0x54);
    int32_t rest = left - step;

    if (rest > 0) {
        int32_t cnt = LH(s1 + 0x52);
        if (cnt > 0) {
            /* slow tempo: count VBlanks down */
            SH(s1 + 0x52, LHU(s1 + 0x52) - 1);
        } else if (cnt == 0) {
            int32_t v = LW(s1 + 0x90);
            SH(s1 + 0x52, stepu);
            SW(s1 + 0x90, v - 1);
        } else {
            SW(s1 + 0x90, rest);
        }
        return 0;
    }
    if (step < left)
        return 0;
    {
        int32_t acc = left, d, st;
        do {
            do {
                _SsGetSeqData(sep, seq);
                d = LW(s1 + 0x90);
            } while (d == 0);
            st = LH(s1 + 0x54);
            acc += d;
        } while (acc < st);
        SW(s1 + 0x90, acc - st);
    }
    return 0;
}

/* Snd_SeqEndOfTrack 0x80031EA0: end of track, loop or stop */
int Snd_SeqEndOfTrack(int a0, int a1, int a2)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t s0 = (uint32_t)LW(tbl) + off;
    int32_t played = LBU(s0 + 0x21) + 1;
    int32_t count = LB(s0 + 0x20);

    (void)a2;
    SB(s0 + 0x21, played);
    if (count == 0) {
        /* endless: back to the start */
        SW(s0 + 0x88, 0);
        SB(s0 + 0x1C, 0);
        SW(s0 + 0x90, 0);
        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x400)
            SW(s0 + 0x0, LW(s0 + 0xC));
        else
            SW(s0 + 0x0, LW(s0 + 0x4));
        return 0;
    }
    if (S16((int8_t)played) < count) {
        uint32_t p, q;
        SW(s0 + 0x88, 0);
        SB(s0 + 0x1C, 0);
        SW(s0 + 0x90, 0);
        if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x400) {
            p = LW(s0 + 0xC);
            q = LW(s0 + 0xC);
        } else {
            p = LW(s0 + 0x4);
            q = LW(s0 + 0x4);
        }
        SW(s0 + 0x0, p);
        SW(s0 + 0x8, q);
        return 0;
    }
    /* last pass: stop */
    SW((uint32_t)LW(tbl) + off + 0x98, LW((uint32_t)LW(tbl) + off + 0x98) & ~1u);
    SW((uint32_t)LW(tbl) + off + 0x98, LW((uint32_t)LW(tbl) + off + 0x98) & ~8u);
    SW((uint32_t)LW(tbl) + off + 0x98, LW((uint32_t)LW(tbl) + off + 0x98) & ~2u);
    SW((uint32_t)LW(tbl) + off + 0x98, LW((uint32_t)LW(tbl) + off + 0x98) | 0x200);
    SW((uint32_t)LW(tbl) + off + 0x98, LW((uint32_t)LW(tbl) + off + 0x98) | 0x4);
    SB(s0 + 0x14, 0);
    if (LW((uint32_t)LW(tbl) + off + 0x98) & 0x400)
        SW(s0 + 0x8, LW(s0 + 0xC));
    else
        SW(s0 + 0x8, LW(s0 + 0x4));
    if (LB(s0 + 0x22) != -1) {
        int32_t nsep = LB(s0 + 0x22), nseq = LB(s0 + 0x23);
        SB(s0 + 0x14, 0);
        _SsSndNextSep(nsep, nseq);
        _SsVmSeqKeyOff(SEQKEY(a0, a1));
    }
    _SsVmSeqKeyOff(SEQKEY(a0, a1));
    SW(s0 + 0x90, LH(s0 + 0x54));
    return 0;
}

/* _SsGetSeqData 0x800320E4: read one event and dispatch it */
int _SsGetSeqData(int a0, int a1)
{
    int32_t t1 = S16(a0), t0 = S16(a1);
    uint32_t tbl = Snd_SeqScores + ((uint32_t)t1 << 2);
    uint32_t off = (uint32_t)t0 * 0xB0u;
    uint32_t s3 = (uint32_t)LW(tbl) + off;
    uint32_t p = LW(s3 + 0x0);
    int32_t s2 = LBU(p);
    int32_t s4, a2;

    p++;
    SW(s3 + 0x0, p);
    if ((LW(off + (uint32_t)LW(tbl) + 0x98) & 0x401) == 0x401) {
        uint32_t end = LW(s3 + 0x10);
        if (p == end + 1) {
            Snd_SeqEndOfTrack(t1, t0, LBU(end + 1));
            return -1;
        }
    }
    if (s2 & 0x80) {
        /* status byte */
        SB(s3 + 0x17, s2 & 0xF);
        a2 = s2 & 0xF0;
        switch (a2) {
        case 0x90:
            SB(s3 + 0x16, a2);
            p = LW(s3 + 0x0);
            s2 = LBU(p);
            p++;
            SW(s3 + 0x0, p);
            s4 = LBU(p);
            p++;
            SW(s3 + 0x0, p);
            SW(s3 + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
            SND_FN(LW(D_80061BB0))(S16(a0), S16(a1), s2, s4);
            return 0;
        case 0xB0:
            p = LW(s3 + 0x0);
            SB(s3 + 0x16, a2);
            a2 = LBU(p);
            SW(s3 + 0x0, p + 1);
            SND_FN(LW(D_80061BC0))(S16(a0), S16(a1), a2);
            return 0;
        case 0xC0:
            p = LW(s3 + 0x0);
            SB(s3 + 0x16, a2);
            a2 = LBU(p);
            SW(s3 + 0x0, p + 1);
            SND_FN(LW(D_80061BB4))(S16(a0), S16(a1), a2);
            return 0;
        case 0xE0:
            p = LW(s3 + 0x0);
            SB(s3 + 0x16, a2);
            SW(s3 + 0x0, p + 1);
            SND_FN(LW(D_80061BB8))(S16(a0), S16(a1));
            return 0;
        case 0xF0:
            p = LW(s3 + 0x0);
            SB(s3 + 0x16, 0xFF);
            a2 = LBU(p);
            SW(s3 + 0x0, p + 1);
            if ((a2 & 0xFF) == 0x2F) {
                Snd_SeqEndOfTrack(S16(a0), S16(a1), 0x2F);
                return 1;
            }
            SND_FN(LW(D_80061BBC))(S16(a0), S16(a1), a2 & 0xFF);
            return 0;
        default:
            return 0;
        }
    }
    /* running status: s2 is the first data byte */
    switch (LBU(s3 + 0x16)) {
    case 0x90:
        p = LW(s3 + 0x0);
        s4 = LBU(p);
        SW(s3 + 0x0, p + 1);
        SW(s3 + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
        SND_FN(LW(D_80061BB0))(S16(a0), S16(a1), s2, s4);
        return 0;
    case 0xB0:
        SND_FN(LW(D_80061BC0))(S16(a0), S16(a1), s2);
        return 0;
    case 0xC0:
        SND_FN(LW(D_80061BB4))(S16(a0), S16(a1), s2);
        return 0;
    case 0xE0:
        SND_FN(LW(D_80061BB8))(S16(a0), S16(a1));
        return 0;
    case 0xFF:
        a2 = s2 & 0xFF;
        if (a2 == 0x2F) {
            Snd_SeqEndOfTrack(S16(a0), S16(a1), 0x2F);
            return 1;
        }
        SND_FN(LW(D_80061BBC))(S16(a0), S16(a1), a2);
        return 0;
    default:
        return 0;
    }
}

/* _SsReadDeltaValue 0x80032494: variable length delta time, returned x10, added to 0x88 */
int _SsReadDeltaValue(int a0, int a1)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    uint32_t p = LW(sc + 0x0);
    uint32_t v = LBU(p), b, r;

    SW(sc + 0x0, p + 1);
    if (v == 0)
        return 0;
    if (v & 0x80) {
        v &= 0x7F;
        do {
            p = LW(sc + 0x0);
            v <<= 7;
            b = LBU(p);
            SW(sc + 0x0, p + 1);
            v += b & 0x7F;
        } while (b & 0x80);
    }
    r = v * 10;
    SW(sc + 0x88, (uint32_t)LW(sc + 0x88) + r);
    return (int)r;
}

/* _SsSndCrescendo 0x80031AC4: one step of a volume fade */
int _SsSndCrescendo(int a0, int a1)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t s2 = (uint32_t)LW(tbl) + off;
    int32_t pos = LW(s2 + 0xA0) + 1;
    int32_t len = LW(s2 + 0x9C);
    int32_t prod, s0, s1, key;
    uint32_t done, buf[1];

    SW(s2 + 0xA0, pos);
    if (len < pos) {
        uint32_t sc = off + (uint32_t)LW(tbl);
        SW(sc + 0x98, LW(sc + 0x98) & ~0x10u);
        goto getvol;
    }
    prod = LH(s2 + 0x48) * pos;
    if (len == 0 || (len == -1 && prod == INT32_MIN)) {
        Psx_printf(SND_ADDR("_SsSndCrescendo: bad divide\n"));
        return 0;
    }
    s0 = prod / len;
    done = LHU(s2 + 0x4A);
    s0 -= LH(s2 + 0x4A);
    if (s0 == 0)
        goto getvol;
    key = SEQKEY(a0, a1);
    SH(s2 + 0x4A, done + s0);
    _SsVmGetSeqVol(key, SND_ADDR(buf), SND_ADDR(buf) + 2);
    s1 = LHU(SND_ADDR(buf)) + s0;
    if (s1 >= 0x80)
        s1 = 0x7F;
    if (s1 < 0)
        s1 = 0;
    s0 = LHU(SND_ADDR(buf) + 2) + s0;
    if (s0 >= 0x80)
        s0 = 0x7F;
    if (s0 < 0)
        s0 = 0;
    _SsVmSetSeqVol(key, s1 & 0xFFFF, s0 & 0xFFFF, 1);
    if ((s1 == 0x7F && s0 == 0x7F) || (s1 == 0 && s0 == 0)) {
        uint32_t sc = SCORE(S16(a0), S16(a1));
        SW(sc + 0x98, LW(sc + 0x98) & ~0x10u);
    }
getvol:
    _SsVmGetSeqVol(SEQKEY(a0, a1), s2 + 0x5C, s2 + 0x5E);
    return 0;
}

/* _SsSndPause 0x80031CD4 */
int _SsSndPause(int a0, int a1)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t s1 = (uint32_t)LW(tbl) + off;
    uint32_t sc;

    _SsVmSeqKeyOff(SEQKEY(a0, a1));
    SB(s1 + 0x14, 0);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) & ~2u);
    return 0;
}

/* _SsSndReplay 0x80032644 */
int _SsSndReplay(int a0, int a1)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t sc;

    SB((uint32_t)LW(tbl) + off + 0x14, 1);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) & ~8u);
    return 0;
}

/* _SsGetMetaEvent 0x80034704: tempo meta event (3 bytes, microseconds per quarter note) */
int _SsGetMetaEvent(int a0, int a1, int a2)
{
    uint32_t s0 = SCORE(S16(a0), S16(a1));
    uint32_t p = LW(s0 + 0x0);
    int32_t b0, b1, b2, usq, bpm;
    uint32_t tps, t1, d60, q, r;

    (void)a2;
    b0 = LBU(p);
    p++;
    SW(s0 + 0x0, p);
    b1 = LBU(p);
    SW(s0 + 0x0, p + 1);
    b2 = LBU(p + 1);
    usq = b2 | ((b0 << 16) | (b1 << 8));
    if (usq == 0) {
        Psx_printf(SND_ADDR("_SsGetMetaEvent: tempo 0\n"));
        return 0;
    }
    bpm = 60000000 / usq;
    tps = LW(Snd_TicksPerSec);
    SW(s0 + 0x0, p + 2);
    SW(s0 + 0x94, bpm);
    t1 = (uint32_t)(LH(s0 + 0x50) * bpm);
    d60 = tps * 60;
    if (t1 * 10 < d60) {
        /* less than one tick unit per VBlank: count VBlanks per unit */
        if (t1 == 0) {
            Psx_printf(SND_ADDR("_SsGetMetaEvent: divide by 0\n"));
            return 0;
        }
        q = (tps * 600) / t1;
        SH(s0 + 0x52, q);
        SH(s0 + 0x54, q);
    } else {
        uint32_t v;
        if (d60 == 0) {
            Psx_printf(SND_ADDR("_SsGetMetaEvent: divide by 0\n"));
            return 0;
        }
        v = (uint32_t)(LH(s0 + 0x50) * LW(s0 + 0x94)) * 10;
        q = v / d60;
        v = (uint32_t)(LH(s0 + 0x50) * LW(s0 + 0x94)) * 10;
        r = v % d60;
        SH(s0 + 0x52, -1);
        SH(s0 + 0x54, q);
        if (tps * 30 < r)
            SH(s0 + 0x54, q + 1);
    }
    SW(s0 + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsNoteOn 0x800348D4: velocity 0 is key off */
int _SsNoteOn(int a0, int a1, int a2, int a3)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    int32_t vel = a3 & 0xFF;
    int32_t ch = LBU(sc + 0x17);
    uint32_t cp = sc + (uint32_t)ch;
    int32_t pan = LBU(cp + 0x27);

    if (vel != 0) {
        if ((LH(sc + 0x80) >> ch) & 1)
            return 0; /* channel muted */
        _SsVmKeyOn(SEQKEY(a0, a1), LB(sc + 0x26), LBU(cp + 0x37), a2 & 0xFF, vel, pan);
    } else {
        _SsVmKeyOff(SEQKEY(a0, a1), LB(sc + 0x26), LBU(cp + 0x37), a2 & 0xFF);
    }
    return 0;
}

/* _SsSetProgramChange 0x800349B4 */
int _SsSetProgramChange(int a0, int a1, int a2)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));

    SB(sc + (uint32_t)LBU(sc + 0x17) + 0x37, a2);
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsSetPitchBend 0x80034424 */
int _SsSetPitchBend(int a0, int a1)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    uint32_t p = LW(sc + 0x0);
    int32_t vab = LB(sc + 0x26);
    int32_t ch = LBU(sc + 0x17);
    int32_t val = LBU(p);

    SW(sc + 0x0, p + 1);
    _SsVmPitchBend(SEQKEY(a0, a1), vab, LBU(sc + (uint32_t)ch + 0x37), val);
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsSetControlChange 0x800344D4: a2 = controller number, value read here */
int _SsSetControlChange(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    uint32_t p = LW(sc + 0x0);
    int32_t val = LBU(p);
    uint32_t fn;

    SW(sc + 0x0, p + 1);
    switch (a2 & 0xFF) {
    case 0x00: /* bank change */
        SB(sc + 0x26, val);
        SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
        return 0;
    case 0x06: fn = LW(D_80061BC8); break;
    case 0x07: fn = LW(D_80061BCC); break;
    case 0x0A: fn = LW(D_80061BD0); break;
    case 0x0B: fn = LW(D_80061BD4); break;
    case 0x40: fn = LW(D_80061BD8); break;
    case 0x5B: fn = LW(D_80061BEC); break;
    case 0x62: fn = LW(D_80061BDC); break;
    case 0x63: fn = LW(D_80061BE0); break;
    case 0x64: fn = LW(D_80061BE4); break;
    case 0x65: fn = LW(D_80061BE8); break;
    case 0x79:
        SND_FN(LW(D_80061BF0))(sep, seq);
        return 0;
    default:
        SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
        return 0;
    }
    SND_FN(fn)(sep, seq, val);
    return 0;
}

/* _SsContBankChange 0x80032C54 */
int _SsContBankChange(int a0, int a1)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    uint32_t p = LW(sc + 0x0);
    int32_t v = LBU(p);

    SW(sc + 0x0, p + 1);
    SB(sc + 0x26, v);
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsContDataEntry 0x80032CD4: RPN (pitch bend range) / NRPN (VAB attribute) data entry */
int _SsContDataEntry(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t s0 = SCORE(sep, seq);
    int32_t ch = LBU(s0 + 0x17);
    uint32_t prog[4] = {0}, vag[8] = {0};
    uint32_t pa = SND_ADDR(prog), va = SND_ADDR(vag);
    int32_t data = a2;

    SsUtGetProgAtr(LB(s0 + 0x26), LBU(s0 + (uint32_t)ch + 0x37), pa);
    if (LBU(s0 + 0x1C) == 1 && LBU(s0 + 0x15) == 0) {
        /* loop count of a loop start mark */
        SB(s0 + 0x1D, data);
        SB(s0 + 0x1C, 0);
        SB(s0 + 0x15, 1);
        SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
        return 0;
    }
    if (LBU(s0 + 0x1E) == 2) {
        if (LBU(s0 + 0x19) == 0 && LBU(pa + 0) != 0) {
            uint32_t cp = (uint32_t)ch + s0;
            uint32_t d = (uint32_t)data & 0xFF;
            int32_t inrange = ((uint32_t)(data - 0x41) & 0xFF) < 0x3F;
            int32_t d25 = (int32_t)(d * 25);
            int32_t tone = 0;
            (void)inrange;
            (void)d25;
            do {
                SsUtGetVagAtr(LB(s0 + 0x26), LBU(cp + 0x37), S16(tone), va);
                switch (LBU(s0 + 0x18)) {
                case 0: /* pitch bend range */
                    SB(va + 0xD, data & 0x7F);
                    SB(va + 0xC, data & 0x7F);
                    break;
                case 1: /* value computed then dropped: the byte is written back unchanged */
                    SB(va + 0x5, LBU(va + 0x5));
                    break;
                case 2: /* same */
                    SB(va + 0x4, LBU(va + 0x4));
                    break;
                default:
                    break;
                }
                SsUtSetVagAtr(LB(s0 + 0x26), LBU(cp + 0x37), S16(tone), va);
                tone++;
            } while (tone < LBU(pa + 0));
        }
        SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
        SB(s0 + 0x1E, 0);
        return 0;
    }
    if (LBU(s0 + 0x1F) == 2) {
        /* NRPN attribute: handler [0x1A] gets (vab, prog, tone, VagAtr by value, nrpn, data) */
        int32_t nrpn, vab, pg, tone;
        if (LBU(s0 + 0x1B) == 0x10) {
            nrpn = LBU(s0 + 0x1A);
            vab = LB(s0 + 0x26);
            pg = LBU(s0 + (uint32_t)ch + 0x37);
            tone = 0;
        } else {
            nrpn = LBU(s0 + 0x1A);
            vab = LB(s0 + 0x26);
            pg = LBU(s0 + (uint32_t)ch + 0x37);
            tone = LBU(s0 + 0x1B);
        }
        SND_FN(LW(D_80061BF4 + ((uint32_t)nrpn << 2)))(vab, pg, tone,
            (uint32_t)LHU(va + 0) | ((uint32_t)LHU(va + 2) << 16), (uint32_t)LW(va + 0x4),
            (uint32_t)LW(va + 0x8), (uint32_t)LW(va + 0xC), (uint32_t)LW(va + 0x10),
            (uint32_t)LW(va + 0x14), (uint32_t)LW(va + 0x18), (uint32_t)LW(va + 0x1C), nrpn,
            data & 0xFF);
        SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
        SB(s0 + 0x1F, 0);
        return 0;
    }
    SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContMainVol 0x80033054 */
int _SsContMainVol(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    int32_t ch = LBU(sc + 0x17);
    uint32_t cp = sc + (uint32_t)ch;

    _SsVmSetVol(SEQKEY(a0, a1), LB(sc + 0x26), LBU(cp + 0x37), a2 & 0xFF, LBU(cp + 0x27));
    SH(sc + ((uint32_t)ch << 1) + 0x60, a2 & 0xFF);
    SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContPanpot 0x80033124 */
int _SsContPanpot(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    int32_t ch = LBU(sc + 0x17);
    uint32_t cp = sc + (uint32_t)ch;

    _SsVmSetVol(SEQKEY(a0, a1), LB(sc + 0x26), LBU(cp + 0x37),
                LHU(sc + ((uint32_t)ch << 1) + 0x60), a2 & 0xFF);
    SB(cp + 0x27, a2);
    SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContExpression 0x800331F4 */
int _SsContExpression(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    int32_t ch = LBU(sc + 0x17);
    uint32_t cp = sc + (uint32_t)ch;

    func_80038B74(LB(sc + 0x26), LBU(cp + 0x37), a2 & 0xFF);
    _SsVmSetVol(SEQKEY(a0, a1), LB(sc + 0x26), LBU(cp + 0x37),
                LHU(((uint32_t)ch << 1) + sc + 0x60), LBU(cp + 0x27));
    SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContDamper 0x800332E4 */
int _SsContDamper(int a0, int a1, int a2)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));

    if ((uint32_t)(a2 & 0xFF) < 0x40)
        _SsVmDamperOff();
    else
        _SsVmDamperOn();
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsContExternal 0x80033394: effect depth = reverb depth */
int _SsContExternal(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    int32_t d = a2 & 0xFF;

    SsUtSetReverbDepth(d, d);
    SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContNrpn1 0x80033424: NRPN LSB (CC 0x62) */
int _SsContNrpn1(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t s0 = SCORE(sep, seq);
    int32_t msb = LBU(s0 + 0x1B);

    if (msb == 0x28) {
        /* mark: per (sep, seq) hook, 16 entries per sep */
        uint32_t fn = LW(Snd_MarkCallbacks + ((uint32_t)sep << 6) + ((uint32_t)seq << 2));
        if (fn != 0)
            SND_FN(fn)(sep, seq, a2 & 0xFF);
        msb = LBU(s0 + 0x1B);
    }
    if (msb != 0x1E && msb != 0x14 && msb != 0x28) {
        int32_t n = LBU(s0 + 0x1F);
        SB(s0 + 0x1A, a2);
        SB(s0 + 0x1C, 0);
        SB(s0 + 0x1F, n + 1);
    }
    SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContNrpn2 0x80033524: NRPN MSB (CC 0x63): 0x14 loop start, 0x1E loop end */
int _SsContNrpn2(int a0, int a1, int a2)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t s0 = SCORE(sep, seq);
    int32_t v, cnt;

    switch (a2 & 0xFF) {
    case 0x14:
        SB(s0 + 0x1B, a2);
        SB(s0 + 0x1C, 1);
        v = _SsReadDeltaValue(sep, seq);
        {
            uint32_t p = LW(s0 + 0x0);
            SW(s0 + 0x90, v);
            SW(s0 + 0x8, p);
        }
        return 0;
    case 0x1E:
        cnt = LBU(s0 + 0x1D);
        SB(s0 + 0x1B, a2);
        if (cnt == 0) {
            SB(s0 + 0x15, 0);
            break;
        }
        if (cnt < 0x7F) {
            SB(s0 + 0x1D, cnt - 1);
            v = _SsReadDeltaValue(sep, seq);
            cnt = LBU(s0 + 0x1D);
            SW(s0 + 0x90, v);
            if (cnt != 0)
                SW(s0 + 0x0, LW(s0 + 0x8));
            else
                SB(s0 + 0x15, 0);
            return 0;
        }
        /* 0x7F and up: endless loop */
        _SsReadDeltaValue(sep, seq);
        {
            uint32_t p = LW(s0 + 0x8);
            SW(s0 + 0x90, 0);
            SW(s0 + 0x0, p);
        }
        return 0;
    default:
        cnt = LBU(s0 + 0x1F);
        SB(s0 + 0x1B, a2);
        SB(s0 + 0x1F, cnt + 1);
        break;
    }
    SW(s0 + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* _SsContRpn1 0x80033664: RPN LSB (CC 0x64) */
int _SsContRpn1(int a0, int a1, int a2)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    int32_t n = LBU(sc + 0x1E);

    SB(sc + 0x18, a2);
    SB(sc + 0x1E, n + 1);
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsContRpn2 0x800336D4: RPN MSB (CC 0x65) */
int _SsContRpn2(int a0, int a1, int a2)
{
    uint32_t sc = SCORE(S16(a0), S16(a1));
    int32_t n = LBU(sc + 0x1E);

    SB(sc + 0x19, a2);
    SB(sc + 0x1E, n + 1);
    SW(sc + 0x90, _SsReadDeltaValue(S16(a0), S16(a1)));
    return 0;
}

/* _SsContResetAll 0x80033744 */
int _SsContResetAll(int a0, int a1)
{
    int32_t sep = S16(a0), seq = S16(a1);
    uint32_t sc = SCORE(sep, seq);
    int32_t ch;

    SsUtReverbOff();
    _SsVmDamperOff();
    ch = LBU(sc + 0x17);
    SB(sc + (uint32_t)ch + 0x37, ch);
    ch = LBU(sc + 0x17);
    SB(sc + 0x18, 0);
    SB(sc + 0x19, 0);
    SH(sc + ((uint32_t)ch << 1) + 0x60, 0x7F);
    ch = LBU(sc + 0x17);
    SB(sc + (uint32_t)ch + 0x27, 0x40);
    SW(sc + 0x90, _SsReadDeltaValue(sep, seq));
    return 0;
}

/* NRPN attribute handlers. Retail passes a VagAtr (32 bytes) by value in a3 + 7 stack words,
 * then the NRPN number and the data byte as further stack arguments. */
#define NRPN_PARAMS                                                                           \
    int a0, int a1, int a2, uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3, uint32_t w4, \
        uint32_t w5, uint32_t w6, uint32_t w7, int nrpn, int data

/* The by-value VagAtr argument as one contiguous block. */
static void nrpn_vag(uint32_t va, uint32_t w0, uint32_t w1, uint32_t w2, uint32_t w3,
                     uint32_t w4, uint32_t w5, uint32_t w6, uint32_t w7)
{
    SW(va + 0x00, w0);
    SW(va + 0x04, w1);
    SW(va + 0x08, w2);
    SW(va + 0x0C, w3);
    SW(va + 0x10, w4);
    SW(va + 0x14, w5);
    SW(va + 0x18, w6);
    SW(va + 0x1C, w7);
}

#define NRPN_VAG_SETUP()                                    \
    uint32_t vag_[8];                                       \
    uint32_t va = SND_ADDR(vag_);                           \
    int32_t vab = S16(a0), prg = S16(a1), tone = S16(a2);   \
    (void)nrpn;                                             \
    nrpn_vag(va, w0, w1, w2, w3, w4, w5, w6, w7)

/* Byte field of the VagAtr = data. */
static int nrpn_set_byte(int a0, int a1, int a2, uint32_t va, int field, int data)
{
    SsUtGetVagAtr(a0, a1, a2, va);
    SB(va + (uint32_t)field, data);
    SsUtSetVagAtr(a0, a1, a2, va);
    return 0;
}

/* ADSR field: resolve the VagAtr ADSR (optional), set one field (+ a mode field), rebuild. The
 * ADSR work block is zeroed here: retail leaves it as stack garbage where no resolve runs. */
static int nrpn_set_adsr(int a0, int a1, int a2, uint32_t va, int resolve, int field, int val,
                         int mfield, int mval)
{
    uint32_t adsr_[6] = {0};
    uint32_t ad = SND_ADDR(adsr_);

    SsUtGetVagAtr(a0, a1, a2, va);
    if (resolve)
        _SsUtResolveADSR(LHU(va + 0x10), LHU(va + 0x12), ad);
    if (mfield >= 0)
        SH(ad + (uint32_t)mfield, mval);
    SH(ad + (uint32_t)field, val);
    _SsUtBuildADSR(ad, va + 0x10, va + 0x12);
    SsUtSetVagAtr(a0, a1, a2, va);
    return 0;
}

/* _SsSetNrpnVabAttr0 0x80033804: priority */
int _SsSetNrpnVabAttr0(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_byte(vab, prg, tone, va, 0x0, data);
}

/* _SsSetNrpnVabAttr1 0x80033894: mode (0 reverb off, 4 reverb on) */
int _SsSetNrpnVabAttr1(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    nrpn_set_byte(vab, prg, tone, va, 0x1, data);
    if ((data & 0xFF) == 0)
        SsUtReverbOff();
    else if ((data & 0xFF) == 4)
        SsUtReverbOn();
    return 0;
}

/* _SsSetNrpnVabAttr2 0x80033954: note min */
int _SsSetNrpnVabAttr2(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_byte(vab, prg, tone, va, 0x6, data);
}

/* _SsSetNrpnVabAttr3 0x800339E4: note max */
int _SsSetNrpnVabAttr3(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_byte(vab, prg, tone, va, 0x7, data);
}

/* _SsSetNrpnVabAttr4 0x80033A74: attack rate, linear */
int _SsSetNrpnVabAttr4(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x0, data & 0xFF, 0xA, 0);
}

/* _SsSetNrpnVabAttr5 0x80033C24: attack rate, exponential */
int _SsSetNrpnVabAttr5(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x0, data & 0xFF, 0xA, 1);
}

/* _SsSetNrpnVabAttr6 0x80033CE4: decay rate */
int _SsSetNrpnVabAttr6(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x2, data & 0xFF, -1, 0);
}

/* _SsSetNrpnVabAttr7 0x80033D94: sustain level */
int _SsSetNrpnVabAttr7(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x4, data & 0xFF, -1, 0);
}

/* _SsSetNrpnVabAttr8 0x80033E44: sustain rate, linear */
int _SsSetNrpnVabAttr8(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x6, data & 0xFF, 0xC, 0);
}

/* _SsSetNrpnVabAttr9 0x80033EF4: sustain rate, exponential */
int _SsSetNrpnVabAttr9(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x6, data & 0xFF, 0xC, 1);
}

/* _SsSetNrpnVabAttr10 0x80033FB4: release rate, linear */
int _SsSetNrpnVabAttr10(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 1, 0x8, data & 0xFF, 0xE, 0);
}

/* _SsSetNrpnVabAttr11 0x80034064: release rate, exponential (retail: no resolve) */
int _SsSetNrpnVabAttr11(NRPN_PARAMS)
{
    NRPN_VAG_SETUP();
    return nrpn_set_adsr(vab, prg, tone, va, 0, 0x8, data & 0xFF, 0xE, 1);
}

/* _SsSetNrpnVabAttr12 0x80034114: sustain direction (retail: no resolve) */
int _SsSetNrpnVabAttr12(NRPN_PARAMS)
{
    uint32_t adsr_[6] = {0};
    uint32_t ad = SND_ADDR(adsr_);
    NRPN_VAG_SETUP();

    SsUtGetVagAtr(vab, prg, tone, va);
    if (((uint32_t)(data - 1) & 0xFF) < 0x3F)
        SH(ad + 0x10, 0);
    else if (((uint32_t)(data - 0x40) & 0xFF) < 0x40)
        SH(ad + 0x10, 1);
    _SsUtBuildADSR(ad, va + 0x10, va + 0x12);
    SsUtSetVagAtr(vab, prg, tone, va);
    return 0;
}

/* _SsSetNrpnVabAttr13 0x800341F4: vibrato time (retail rebuilds the ADSR from a garbage block) */
int _SsSetNrpnVabAttr13(NRPN_PARAMS)
{
    uint32_t adsr_[6] = {0};
    NRPN_VAG_SETUP();

    SsUtGetVagAtr(vab, prg, tone, va);
    SB(va + 0x9, data);
    _SsUtBuildADSR(SND_ADDR(adsr_), va + 0x10, va + 0x12);
    SsUtSetVagAtr(vab, prg, tone, va);
    return 0;
}

/* _SsSetNrpnVabAttr14 0x80034294: portamento width (same garbage ADSR rebuild) */
int _SsSetNrpnVabAttr14(NRPN_PARAMS)
{
    uint32_t adsr_[6] = {0};
    NRPN_VAG_SETUP();

    SsUtGetVagAtr(vab, prg, tone, va);
    SB(va + 0xA, data);
    _SsUtBuildADSR(SND_ADDR(adsr_), va + 0x10, va + 0x12);
    SsUtSetVagAtr(vab, prg, tone, va);
    return 0;
}

/* _SsSetNrpnVabAttr15 0x80034334: reverb type */
int _SsSetNrpnVabAttr15(NRPN_PARAMS)
{
    (void)a0; (void)a1; (void)a2; (void)w0; (void)w1; (void)w2; (void)w3; (void)w4;
    (void)w5; (void)w6; (void)w7; (void)nrpn;
    SsUtSetReverbType(data & 0xFF);
    return 0;
}

/* _SsSetNrpnVabAttr16 0x80034364: reverb depth */
int _SsSetNrpnVabAttr16(NRPN_PARAMS)
{
    (void)a0; (void)a1; (void)a2; (void)w0; (void)w1; (void)w2; (void)w3; (void)w4;
    (void)w5; (void)w6; (void)w7; (void)nrpn;
    SsUtSetReverbDepth(data & 0xFF, data & 0xFF);
    return 0;
}

/* _SsSetNrpnVabAttr17 0x80034394: reverb feedback */
int _SsSetNrpnVabAttr17(NRPN_PARAMS)
{
    (void)a0; (void)a1; (void)a2; (void)w0; (void)w1; (void)w2; (void)w3; (void)w4;
    (void)w5; (void)w6; (void)w7; (void)nrpn;
    SsUtSetReverbFeedback(data & 0xFF);
    return 0;
}

/* _SsSetNrpnVabAttr18 0x800343C4: reverb delay */
int _SsSetNrpnVabAttr18(NRPN_PARAMS)
{
    (void)a0; (void)a1; (void)a2; (void)w0; (void)w1; (void)w2; (void)w3; (void)w4;
    (void)w5; (void)w6; (void)w7; (void)nrpn;
    SsUtSetReverbDelay(data & 0xFF);
    return 0;
}

/* _SsSetNrpnVabAttr19 0x800343F4: reverb delay too (retail) */
int _SsSetNrpnVabAttr19(NRPN_PARAMS)
{
    (void)a0; (void)a1; (void)a2; (void)w0; (void)w1; (void)w2; (void)w3; (void)w4;
    (void)w5; (void)w6; (void)w7; (void)nrpn;
    SsUtSetReverbDelay(data & 0xFF);
    return 0;
}

/* _SsSndStop 0x800354F4: stop and reset the score */
int _SsSndStop(int a0, int a1)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t s0 = (uint32_t)LW(tbl) + off;
    uint32_t sc, delta, tempo, base1, base2;
    int32_t step, i;

    SW(s0 + 0x98, LW(s0 + 0x98) & ~1u);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) & ~2u);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) & ~8u);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) & ~0x401u);
    sc = off + (uint32_t)LW(tbl);
    SW(sc + 0x98, LW(sc + 0x98) | 0x4);
    _SsVmSeqKeyOff(SEQKEY(a0, a1));
    _SsVmDamperOff();
    delta = LW(s0 + 0x84);
    tempo = LW(s0 + 0x8C);
    step = LHU(s0 + 0x56);
    base1 = LW(s0 + 0x4);
    base2 = LW(s0 + 0x4);
    SB(s0 + 0x14, 0);
    SW(s0 + 0x88, 0);
    SB(s0 + 0x1C, 0);
    SB(s0 + 0x18, 0);
    SB(s0 + 0x19, 0);
    SB(s0 + 0x1E, 0);
    SB(s0 + 0x1A, 0);
    SB(s0 + 0x1B, 0);
    SB(s0 + 0x1F, 0);
    SB(s0 + 0x17, 0);
    SB(s0 + 0x21, 0);
    SB(s0 + 0x1C, 0);
    SB(s0 + 0x1D, 0);
    SB(s0 + 0x15, 0);
    SB(s0 + 0x16, 0);
    SW(s0 + 0x90, delta);
    SW(s0 + 0x94, tempo);
    SH(s0 + 0x54, step);
    SW(s0 + 0x0, base1);
    SW(s0 + 0x8, base2);
    for (i = 0; i < 0x10; i++) {
        SB(s0 + (uint32_t)i + 0x37, i);
        SB(s0 + (uint32_t)i + 0x27, 0x40);
        SH(s0 + ((uint32_t)i << 1) + 0x60, 0x7F);
    }
    SH(s0 + 0x5C, 0x7F);
    SH(s0 + 0x5E, 0x7F);
    return 0;
}

/* _SsSndTempo 0x80035CE4: one step of a tempo change toward 0xAC */
int _SsSndTempo(int a0, int a1)
{
    uint32_t tbl = Snd_SeqScores + ((uint32_t)S16(a0) << 2);
    uint32_t off = (uint32_t)S16(a1) * 0xB0u;
    uint32_t a3 = (uint32_t)LW(tbl) + off;
    int32_t left = LW(a3 + 0xA8) - 1;
    int32_t step;
    uint32_t cur, tgt, sc, prod, d, q;

    SW(a3 + 0xA8, left);
    if (left < 0) {
        sc = off + (uint32_t)LW(tbl);
        SW(sc + 0x98, LW(sc + 0x98) & ~0x40u);
        sc = off + (uint32_t)LW(tbl);
        SW(sc + 0x98, LW(sc + 0x98) & ~0x80u);
        return 0;
    }
    step = LH(a3 + 0x4E);
    if (step > 0) {
        /* one BPM every `step` frames */
        if (left % step != 0)
            return 0;
        cur = LW(a3 + 0x94);
        tgt = LW(a3 + 0xAC);
        if (tgt < cur)
            SW(a3 + 0x94, cur - 1);
        else if (cur < tgt)
            SW(a3 + 0x94, cur + 1);
    } else {
        /* -step BPM per frame, clamped at the target */
        uint32_t v;
        int32_t over;
        cur = LW(a3 + 0x94);
        tgt = LW(a3 + 0xAC);
        if (tgt < cur) {
            v = cur + (uint32_t)step;
            SW(a3 + 0x94, v);
            over = v < tgt;
        } else if (cur < tgt) {
            v = cur - (uint32_t)step;
            tgt = LW(a3 + 0xAC);
            SW(a3 + 0x94, v);
            over = tgt < v;
        } else {
            over = 0;
        }
        if (over)
            SW(a3 + 0x94, tgt);
    }
    prod = (uint32_t)(LH(a3 + 0x50) * LW(a3 + 0x94)) * 10;
    d = (uint32_t)LW(Snd_TicksPerSec) * 60;
    if (d == 0) {
        Psx_printf(SND_ADDR("_SsSndTempo: divide by 0\n"));
        return 0;
    }
    q = prod / d;
    SH(a3 + 0x54, q);
    if ((int32_t)(q << 16) <= 0)
        SH(a3 + 0x54, 1);
    if (LW(a3 + 0xA8) == 0 || LW(a3 + 0x94) == LW(a3 + 0xAC)) {
        sc = SCORE(S16(a0), S16(a1));
        SW(sc + 0x98, LW(sc + 0x98) & ~0x40u);
        sc = SCORE(S16(a0), S16(a1));
        SW(sc + 0x98, LW(sc + 0x98) & ~0x80u);
    }
    return 0;
}
