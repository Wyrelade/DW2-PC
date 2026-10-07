/* libsnd voice manager (_SsVm*), retail Psy-Q 4.7 code translated from
 * asm/USA/main/nonmatchings/psyq. Globals stay at their retail addresses (snd_native.h).
 *
 * Voice table: 24 entries of 0x38 bytes at 0x800624E8 (fields named below by their
 * absolute address of voice 0, index with VM(v)). Shadow SPU voice registers: 24 x 0x10 bytes
 * at 0x80062A48, dirty flags per voice at 0x80062A28 (1 volume, 4 pitch, 8 address,
 * 0x10/0x20 ADSR), committed by _SsVmFlush. */

#include "snd_native.h"

#define Snd_SeqScores 0x80061C50u

#define D_8004FC18 0x8004FC18u /* reserved voice mask (SsSetReservedVoice) */

/* Key masks (low 16 voices, high 8 voices) */
#define D_800624D8 0x800624D8u /* key on 0..15 */
#define D_800624DA 0x800624DAu /* key on 16..23 */
#define D_800624DC 0x800624DCu /* reverb on 0..15 */
#define D_800624DE 0x800624DEu /* reverb on 16..23 */
#define D_800624E0 0x800624E0u /* noise 0..15 */
#define D_800624E2 0x800624E2u /* noise 16..23 */
#define D_80062C10 0x80062C10u /* key off 0..15 */
#define D_80062C12 0x80062C12u /* key off 16..23 */

/* Voice table fields (voice 0 address, + VM(v)) */
#define D_800624E8 0x800624E8u /* h vag number (0xFF = noise) */
#define D_800624EA 0x800624EAu /* h age */
#define D_800624EC 0x800624ECu /* h pitch */
#define D_800624EE 0x800624EEu /* h envelope (SpuGetVoiceEnvelope) */
#define D_800624F0 0x800624F0u /* h velocity */
#define D_800624F2 0x800624F2u /* b note pan */
#define D_800624F4 0x800624F4u /* h channel */
#define D_800624F6 0x800624F6u /* h note */
#define D_800624F8 0x800624F8u /* h seq access number */
#define D_800624FA 0x800624FAu /* h program tone block */
#define D_800624FC 0x800624FCu /* h program */
#define D_800624FE 0x800624FEu /* h tone index */
#define D_80062500 0x80062500u /* h vab id */
#define D_80062502 0x80062502u /* h priority */
#define D_80062505 0x80062505u /* b state: 0 free, 1 key on, 2 noise */
#define D_80062506 0x80062506u /* h callback 1 request */
#define D_80062508 0x80062508u
#define D_8006250A 0x8006250Au
#define D_8006250C 0x8006250Cu
#define D_8006250E 0x8006250Eu
#define D_80062512 0x80062512u /* h callback 2 request */
#define D_80062514 0x80062514u
#define D_80062516 0x80062516u
#define D_80062518 0x80062518u
#define D_8006251A 0x8006251Au
#define D_8006251E 0x8006251Eu /* h volume */

#define D_80062A28 0x80062A28u /* b[24] dirty flags */
#define D_80062A40 0x80062A40u /* fn callback 2 */
#define D_80062A48 0x80062A48u /* shadow regs: volume left */
#define D_80062A4A 0x80062A4Au /* volume right */
#define D_80062A4C 0x80062A4Cu /* pitch */
#define D_80062A4E 0x80062A4Eu /* start address >> 3 */
#define D_80062A50 0x80062A50u /* ADSR1, +2 ADSR2 */
#define D_80062BC8 0x80062BC8u /* fn callback 1 */
#define D_80062BCC 0x80062BCCu /* envelope ring index */
#define D_80062BD0 0x80062BD0u /* w[16] envelope zero masks */
#define D_80062C18 0x80062C18u
#define D_80062C30 0x80062C30u /* w[16] ProgAtr table per vab */
#define D_80062C70 0x80062C70u /* w[16] VabHdr per vab */
#define D_80062CB0 0x80062CB0u /* h damper (release rate add) */
#define D_80062CB8 0x80062CB8u /* w[16] VagAtr table per vab */
#define D_80062CF8 0x80062CF8u /* h mono */
#define D_80062CFA 0x80062CFAu /* h max programs */
#define D_80062CFC 0x80062CFCu /* w current ProgAtr table */
#define D_80062D04 0x80062D04u /* w current VabHdr */
#define D_80062D08 0x80062D08u /* w current VagAtr table */
#define D_80062D0C 0x80062D0Cu /* b voice count */
#define D_80062D10 0x80062D10u
/* Current note block 0x80062D18.. */
#define D_80062D18 0x80062D18u /* b tones in program */
#define D_80062D19 0x80062D19u /* b vab id */
#define D_80062D1A 0x80062D1Au /* b note */
#define D_80062D1B 0x80062D1Bu /* b fine */
#define D_80062D1C 0x80062D1Cu /* b volume */
#define D_80062D1D 0x80062D1Du /* b pan */
#define D_80062D1E 0x80062D1Eu /* b program */
#define D_80062D1F 0x80062D1Fu /* b program tone block */
#define D_80062D22 0x80062D22u /* b program volume */
#define D_80062D23 0x80062D23u /* b program pan */
#define D_80062D24 0x80062D24u /* b tone index */
#define D_80062D25 0x80062D25u /* b tone volume */
#define D_80062D26 0x80062D26u /* b tone pan */
#define D_80062D27 0x80062D27u /* b tone priority */
#define D_80062D28 0x80062D28u /* b tone center */
#define D_80062D29 0x80062D29u /* b tone shift */
#define D_80062D2A 0x80062D2Au /* b tone mode */
#define D_80062D2C 0x80062D2Cu /* h seq access number */
#define D_80062D2E 0x80062D2Eu /* h vag number */
#define D_80062D30 0x80062D30u /* h current voice */
#define D_80062D38 0x80062D38u /* b[16] vab state */
#define D_80062D48 0x80062D48u
#define D_80062D90 0x80062D90u /* h vab count */
#define D_80062DE0 0x80062DE0u /* SpuMalloc table */

#define VM(v) ((uint32_t)(v) * 0x38u)
#define SLLV(x, s) ((uint32_t)(x) << ((uint32_t)(s) & 31))

/* The retail division-by-constant sequences. */
static uint32_t Vm_DivU(uint32_t x, uint32_t m, int sh)
{
    uint32_t h = MULTU_HI(x, m);
    return (h + ((x - h) >> 1)) >> sh;
}

static int32_t Vm_DivS(int32_t x, uint32_t m, int sh)
{
    int32_t h = MULT_HI(x, m);
    return ((int32_t)(h + x) >> sh) - (x >> 31);
}

/* Same, with srl and no sign fix (positive operands in the retail code). */
static uint32_t Vm_DivSL(int32_t x, uint32_t m, int sh)
{
    int32_t h = MULT_HI(x, m);
    return (uint32_t)(h + x) >> sh;
}

static uint32_t Vm_ScoreAddr(uint32_t acc)
{
    int32_t s = (int32_t)(acc & 0xFF00) >> 8;
    return (uint32_t)LW(Snd_SeqScores + (acc & 0xFF) * 4) + (uint32_t)(s * 0xB0);
}

/* _SsVmDamperOff 0x80036764 */
int _SsVmDamperOff(void)
{
    SH(D_80062CB0, 0);
    return 0;
}

/* _SsVmDamperOn 0x80036774 */
int _SsVmDamperOn(void)
{
    SH(D_80062CB0, 2);
    return 0;
}

/* _SsVmFlush 0x80036784: once per tick, commit the shadow registers and the key masks. */
int _SsVmFlush(void)
{
    uint8_t attr[0x40]; /* SpuVoiceAttr at retail sp+0x10 */
    uint32_t a = SND_ADDR(attr);
    uint32_t cnt, s2, s0mask, rv;
    int32_t s0;
    int i;

    for (i = 0; i < 0x40; i++)
        attr[i] = 0;

    /* envelope ring: voices whose envelope reached 0 this tick */
    cnt = ((uint32_t)LW(D_80062BCC) + 1) & 0xF;
    SW(D_80062BCC, cnt);
    SW(D_80062BD0 + cnt * 4, 0);
    for (s0 = 0; s0 < LB(D_80062D0C); s0++) {
        SpuGetVoiceEnvelope(s0, D_800624EE + VM(s0));
        if (LHU(D_800624EE + VM(s0)) == 0) {
            uint32_t p = D_80062BD0 + (uint32_t)LW(D_80062BCC) * 4;
            SW(p, (uint32_t)LW(p) | SLLV(1, s0));
        }
    }

    if (LB(D_80062D48) == 0) {
        /* silent for 15 ticks: free the voice, end noise */
        s2 = 0xFFFFFFFFu;
        for (i = 0; i < 15; i++)
            s2 &= (uint32_t)LW(D_80062BD0 + i * 4);
        for (s0 = 0; s0 < LB(D_80062D0C); s0++) {
            uint32_t a1 = SLLV(1, s0);
            if ((s2 & a1) == 0)
                continue;
            if (LB(D_80062505 + VM(s0)) == 2) {
                uint32_t v0;
                if (s0 < 0x10) {
                    v0 = 0;
                } else {
                    a1 = 0;
                    v0 = SLLV(1, s0 - 0x10);
                }
                SpuSetNoiseVoice(0, ((v0 & 0xFF) << 16) | (uint32_t)(int32_t)(int16_t)a1);
            }
            SB(D_80062505 + VM(s0), 0);
        }
    }

    /* drop key on bits of voices also keyed off this tick */
    SH(D_800624D8, LHU(D_800624D8) & ~LHU(D_80062C10));
    SH(D_800624DA, LHU(D_800624DA) & ~LHU(D_80062C12));

    for (s0 = 0; s0 < 0x18; s0++) {
        if (LH(D_80062506 + VM(s0)) != 0)
            SND_FN(LW(D_80062BC8))(s0);
        if (LH(D_80062512 + VM(s0)) != 0)
            SND_FN(LW(D_80062A40))(s0);
    }

    /* dirty voice registers through SpuSetVoiceAttr */
    for (s0 = 0; s0 < 0x18; s0++) {
        uint32_t r = D_80062A48 + (uint32_t)s0 * 0x10;
        uint32_t f = D_80062A28 + (uint32_t)s0;
        SW(a + 0x4, 0);              /* mask */
        SW(a + 0x0, SLLV(1, s0));    /* voice */
        if (LBU(f) & 1) {
            SW(a + 0x4, 3);          /* SPU_VOICE_VOLL | VOLR */
            SH(a + 0x8, LHU(r + 0x0));
            SH(a + 0xA, LHU(r + 0x2));
        }
        if (LBU(f) & 4) {
            SW(a + 0x4, LW(a + 0x4) | 0x10); /* pitch */
            SH(a + 0x14, LHU(r + 0x4));
        }
        if (LBU(f) & 8) {
            SW(a + 0x4, LW(a + 0x4) | 0x80); /* wave start address */
            SW(a + 0x1C, LHU(r + 0x6) << 3);
        }
        if (LBU(f) & 0x10) {
            SW(a + 0x4, LW(a + 0x4) | 0x60000); /* ADSR1 / ADSR2 */
            SH(a + 0x3A, LHU(r + 0x8));
            SH(a + 0x3C, LHU(r + 0xA));
        }
        if (LW(a + 0x4) != 0)
            SpuSetVoiceAttr(a);
        SB(f, 0);
    }

    /* key off, then key on */
    SpuSetKey(0, ((uint32_t)LBU(D_80062C12) << 16) | (uint32_t)LHU(D_80062C10));
    SpuSetKey(1, ((uint32_t)LBU(D_800624DA) << 16) | (uint32_t)LHU(D_800624D8));

    /* reverb and noise bits of the voices the manager owns */
    s0mask = (uint32_t)((int32_t)0xFFFFFF >> ((uint32_t)(0x18 - LB(D_80062D0C)) & 31));
    s2 = (((uint32_t)LHU(D_800624DE) << 16) | (uint32_t)LHU(D_800624DC)) & s0mask;
    rv = (uint32_t)SpuGetReverbVoice();
    SpuSetReverbVoice(8, s2 | (rv & ~s0mask));
    s2 = (((uint32_t)LHU(D_800624E2) << 16) | (uint32_t)LHU(D_800624E0)) & s0mask;
    rv = (uint32_t)SpuGetNoiseVoice();
    SpuSetNoiseVoice(8, s2 | (rv & ~s0mask));

    SH(D_80062C10, 0);
    SH(D_80062C12, 0);
    SH(D_800624D8, 0);
    SH(D_800624DA, 0);
    SH(D_800624E0, 0);
    SH(D_800624E2, 0);
    return 0;
}

/* _SsVmInit 0x80036C54 */
int _SsVmInit(int a0)
{
    uint8_t attr[0x40]; /* SpuVoiceAttr at retail sp+0x10 */
    uint32_t a = SND_ADDR(attr);
    uint32_t s0;
    int32_t v1;
    int i;

    for (i = 0; i < 0x40; i++)
        attr[i] = 0;

    _spu_setInTransfer(0);
    SH(D_80062CB0, 0);
    SpuInitMalloc(0x20, D_80062DE0);
    for (s0 = 0; (s0 & 0xFFFF) < 0xC0; s0++)
        SH(D_80062A48 + (s0 & 0xFFFF) * 2, 0);
    for (s0 = 0; (s0 & 0xFFFF) < 0x18; s0++)
        SB(D_80062A28 + (s0 & 0xFFFF), 0);
    SH(D_80062D90, 0);
    for (s0 = 0; (s0 & 0xFFFF) < 0x10; s0++)
        SB(D_80062D38 + (s0 & 0xFFFF), 0);

    v1 = (int8_t)a0;
    if ((uint32_t)v1 < 0x18)
        SB(D_80062D0C, v1);
    else
        SB(D_80062D0C, 0x18);

    SW(a + 0x4, 0x60093); /* volume, pitch, address, ADSR1/2 */
    SH(a + 0x14, 0x1000);
    SW(a + 0x1C, 0x1000);
    SH(a + 0x3A, 0x80FF);
    SH(a + 0x8, 0);
    SH(a + 0xA, 0);
    SH(a + 0x3C, 0x4000);

    for (s0 = 0; (int32_t)(s0 & 0xFFFF) < LB(D_80062D0C); s0++) {
        uint32_t v = s0 & 0xFFFF;
        uint32_t o = VM(v);
        SH(D_800624EA + o, 0x18);
        SH(D_800624E8 + o, 0xFF);
        SB(D_80062505 + o, 0);
        SH(D_800624EC + o, 0);
        SH(D_800624EE + o, 0);
        SH(D_800624F8 + o, -1);
        SH(D_800624FA + o, 0);
        SH(D_800624FC + o, 0);
        SH(D_800624FE + o, 0xFF);
        SH(D_800624F0 + o, 0);
        SH(D_800624F4 + o, 0);
        SB(D_800624F2 + o, 0x40);
        SH(D_8006251E + o, 0);
        SH(D_80062506 + o, 0);
        SH(D_80062508 + o, 0);
        SH(D_8006250A + o, 0);
        SH(D_8006250C + o, 0);
        SH(D_80062512 + o, 0);
        SH(D_80062514 + o, 0);
        SH(D_80062516 + o, 0);
        SH(D_80062518 + o, 0);
        SH(D_8006251A + o, 0);
        SH(D_8006250E + o, 0);
        SW(a + 0x0, SLLV(1, v));
        SpuSetVoiceAttr(a);
        SH(D_80062D30, s0);
        _SsVmKeyOffNow(1);
    }

    SW(D_80062C18 + 0x0, 0);
    SH(D_80062C18 + 0x8, 0x3FFF);
    SH(D_80062C18 + 0xA, 0x3FFF);
    SW(D_80062C18 + 0x4, 0);
    SH(D_800624D8, 0);
    SH(D_800624DA, 0);
    SH(D_80062C10, 0);
    SH(D_800624DC, 0);
    SH(D_800624DE, 0);
    SH(D_800624E0, 0);
    SH(D_800624E2, 0);
    SB(D_80062D48, 0);
    SH(D_80062CF8, 0);
    SW(D_80062D10, 0);
    SH(D_80062CFA, 0x80);
    _SsVmFlush();
    return 0;
}

/* _SsVmKeyOn 0x80036FA4: seq access number, vab, program, note, velocity, pan.
 * Returns the mask of the voices keyed on (-1 if a tone found no voice). */
int _SsVmKeyOn(int a0, int a1, int a2, int a3, int vel, int pan)
{
    uint8_t vagbuf[0x80]; /* retail sp+0x10 */
    uint8_t tonebuf[0x80]; /* retail sp+0x90 */
    uint32_t s6 = (uint32_t)a0;
    uint32_t s3 = (uint32_t)a1;
    uint32_t s7 = (uint32_t)a3;
    uint32_t prog = (uint32_t)a2 & 0xFFFF; /* sp+0x110 */
    int32_t s1 = (int16_t)a0;
    uint32_t s5, s4, fp, pa, n;
    int32_t s2 = 0;
    int32_t a2s, sp118;
    uint32_t i;

    s5 = (uint32_t)LW(Snd_SeqScores + ((uint32_t)a0 & 0xFF) * 4) +
         (uint32_t)(((int32_t)(s1 & 0xFF00) >> 8) * 0xB0);
    s4 = (uint32_t)vel & 0xFFFF;
    fp = (uint32_t)pan & 0xFFFF;
    if (_SsVmVSetUp((int16_t)a1, (int16_t)a2) != 0)
        return -1;

    SH(D_80062D2C, a0);
    SB(D_80062D1A, s7);
    SB(D_80062D1B, 0);
    if (s1 == 0x21) {
        SB(D_80062D1C, s4);
    } else {
        /* velocity * channel volume / 127 */
        int32_t v = (int32_t)s4 * LH(s5 + 0x60 + (uint32_t)LBU(s5 + 0x17) * 2);
        SB(D_80062D1C, Vm_DivS(v, 0x81020409u, 6));
    }
    SB(D_80062D1D, fp);
    a2s = (int16_t)prog;
    pa = (uint32_t)LW(D_80062CFC) + (uint32_t)(a2s * 16);
    SB(D_80062D22, LBU(pa + 1));
    SB(D_80062D23, LBU(pa + 4));
    SB(D_80062D18, LBU(pa + 0));
    if (!(LB(D_80062D1F) < LHU((uint32_t)LW(D_80062D04) + 0x12)))
        return -1;

    if (s4 == 0) /* velocity 0: key off */
        return _SsVmKeyOff((int16_t)s6, (int16_t)s3, a2s, s7 & 0xFFFF);

    n = (uint32_t)_SsVmSelectToneAndVag(SND_ADDR(tonebuf), SND_ADDR(vagbuf));
    s3 = n;
    if ((n & 0xFF) == 0)
        return s2;

    sp118 = (int16_t)s6;
    for (i = 0; (i & 0xFF) < (s3 & 0xFF); i++) {
        uint32_t k = i & 0xFF;
        uint32_t t, v, o;
        uint32_t tn;

        SH(D_80062D2E, LBU(SND_ADDR(vagbuf) + k));
        tn = (uint32_t)LBU(SND_ADDR(tonebuf) + k);
        v = (uint32_t)((int8_t)tn + LB(D_80062D1F) * 16) & 0xFFFF;
        SB(D_80062D24, tn);
        t = (uint32_t)LW(D_80062D08) + (v << 5);
        SB(D_80062D27, LBU(t + 0));
        SB(D_80062D25, LBU(t + 2));
        SB(D_80062D26, LBU(t + 3));
        SB(D_80062D28, LBU(t + 4));
        SB(D_80062D29, LBU(t + 5));
        SB(D_80062D2A, LBU(t + 1));
        v = (uint32_t)_SsVmAlloc(0) & 0xFF;
        SH(D_80062D30, v);
        if (!((int32_t)v < LB(D_80062D0C))) {
            s2 = -1;
            continue;
        }
        SB(D_80062505 + VM(v), 1);
        o = VM(LH(D_80062D30));
        SH(D_800624EA + o, 0);
        SH(D_800624F8 + o, s6);
        SH(D_80062500 + o, (int8_t)LBU(D_80062D19));
        SH(D_800624FA + o, (int8_t)LBU(D_80062D1F));
        SH(D_800624FC + o, prog);
        if (sp118 != 0x21) {
            SH(D_800624F0 + o, s4);
            SH(D_800624F4 + o, LBU(s5 + 0x17));
        }
        SB(D_800624F2 + o, fp);
        SH(D_8006251E + o, (int8_t)LBU(D_80062D1C));
        SH(D_800624FE + o, (int8_t)LBU(D_80062D24));
        SH(D_800624F6 + o, s7);
        SH(D_80062502 + o, (int8_t)LBU(D_80062D27));
        SH(D_800624E8 + o, LHU(D_80062D2E));
        _SsVmDoAllocate();
        if (LH(D_80062D2E) == 0xFF) {
            vmNoiseOn(LBU(D_80062D30));
        } else {
            uint32_t p = (uint32_t)note2pitch();
            _SsVmKeyOnNow(s3 & 0xFF, p & 0xFFFF);
        }
        s2 |= (int32_t)SLLV(1, LH(D_80062D30));
    }
    return s2;
}

/* _SsVmKeyOff 0x800374C0: seq access number, vab, program, note. Returns the voice count. */
int _SsVmKeyOff(int a0, int a1, int a2, int a3)
{
    int32_t s5 = (int32_t)((uint32_t)a3 & 0xFFFF);
    int32_t s4 = (int16_t)a2;
    int32_t s3 = (int16_t)a0;
    int32_t s2 = (int16_t)a1;
    int32_t s1 = 0;
    uint32_t s0;

    for (s0 = 0; (int32_t)(s0 & 0xFF) < LB(D_80062D0C); s0++) {
        uint32_t v = s0 & 0xFF;
        uint32_t o = VM(v);
        if ((uint32_t)LW(D_8004FC18) & SLLV(1, v))
            continue;
        if (LH(D_800624F6 + o) != s5)
            continue;
        if (LH(D_800624FC + o) != s4)
            continue;
        if (LH(D_800624F8 + o) != s3)
            continue;
        if (LH(D_80062500 + o) != s2)
            continue;
        if (LH(D_800624E8 + o) == 0xFF) {
            s1++;
            vmNoiseOff(v);
        } else {
            SH(D_80062D30, v);
            _SsVmKeyOffNow(0);
            s1++;
        }
    }
    return s1;
}

/* _SsVmAlloc 0x80037744: pick a voice for the current tone (free, else lowest priority,
 * else oldest / quietest). Returns the voice or the voice count when none. */
int _SsVmAlloc(int a0)
{
    uint32_t t3 = 0x63, t4 = 0xFFFF, t2 = 0, t0 = 0, t1 = 0x63, a3 = 0;
    uint32_t t5 = (uint32_t)(int32_t)(int8_t)LBU(D_80062D27);
    int32_t n = LB(D_80062D0C);
    (void)a0;

    if (n > 0) {
        uint32_t t7 = (uint32_t)LW(D_8004FC18);
        int32_t t6 = n;
        do {
            uint32_t v = a3 & 0xFF;
            uint32_t o = VM(v);
            if ((t7 & SLLV(1, v)) == 0) {
                int32_t a2v, a1v;
                if (LB(D_80062505 + o) == 0 && LHU(D_800624EE + o) == 0) {
                    t3 = a3; /* free voice */
                    goto done;
                }
                a1v = (int32_t)(t5 & 0xFFFF);
                a2v = LH(D_80062502 + o);
                if (a2v < a1v) {
                    t5 = (uint32_t)LHU(D_80062502 + o);
                    t1 = a3;
                    t4 = (uint32_t)LHU(D_800624EE + o);
                    t0 = (uint32_t)LHU(D_800624EA + o);
                    t2 = 1;
                } else if (a2v == a1v) {
                    uint32_t e0 = t4 & 0xFFFF;
                    uint32_t e = (uint32_t)LHU(D_800624EE + o);
                    t2++;
                    if (e < e0) {
                        t0 = (uint32_t)LHU(D_800624EA + o);
                        t4 = e;
                        t1 = a3;
                    } else if (e == e0) {
                        if ((int32_t)t0 < LH(D_800624EA + o)) {
                            t0 = (uint32_t)LHU(D_800624EA + o);
                            t1 = a3;
                        }
                    }
                }
            }
            a3++;
        } while ((int32_t)(a3 & 0xFF) < t6);
    }
done:
    if ((t3 & 0xFF) == 0x63) {
        t3 = t1;
        if ((t2 & 0xFF) == 0)
            t3 = (uint32_t)LBU(D_80062D0C);
    }
    n = LB(D_80062D0C);
    if ((int32_t)(t3 & 0xFF) < n) {
        uint32_t o;
        if (n > 0) {
            uint32_t mask = (uint32_t)LW(D_8004FC18);
            for (a3 = 0; (int32_t)(a3 & 0xFF) < n; a3++) {
                uint32_t v = a3 & 0xFF;
                if ((mask & SLLV(1, v)) == 0)
                    SH(D_800624EA + VM(v), LHU(D_800624EA + VM(v)) + 1);
            }
        }
        o = VM(t3 & 0xFF);
        SH(D_800624EA + o, 0);
        SH(D_80062512 + o, 0);
        SH(D_80062506 + o, 0);
        SH(D_80062502 + o, (int8_t)LBU(D_80062D27));
    }
    return t3 & 0xFF;
}

/* _SsVmDoAllocate 0x800379B4: wave address and ADSR of the current tone into the shadow
 * registers of the current voice. */
int _SsVmDoAllocate(void)
{
    uint32_t t0 = (uint32_t)LHU(D_80062D30) << 3;
    int32_t off = (int32_t)(int16_t)t0 * 2;
    uint32_t v1, t, a0, sum;
    int32_t a1, idx;

    SH(D_800624EE + VM((int16_t)LHU(D_80062D30)), 0x7FFF);
    for (a1 = 0; a1 < 0x10; a1++) {
        uint32_t p = D_80062BD0 + (uint32_t)a1 * 4;
        SW(p, (uint32_t)LW(p) & ~SLLV(1, LH(D_80062D30)));
    }

    /* vag address table: two entries per 16-byte ProgAtr reserved area */
    v1 = (uint32_t)LHU(D_80062D2E);
    idx = ((int32_t)(int16_t)v1 - 1) / 2;
    if ((v1 & 1) != 0)
        SH(D_80062A4E + off, LHU((uint32_t)LW(D_80062CFC) + (uint32_t)(idx * 16) + 0xC));
    else
        SH(D_80062A4E + off, LHU((uint32_t)LW(D_80062CFC) + (uint32_t)(idx * 16) + 0xE));
    SB(D_80062A28 + LH(D_80062D30), LBU(D_80062A28 + LH(D_80062D30)) | 0x8);

    t = (uint32_t)LW(D_80062D08) + (uint32_t)((LB(D_80062D1F) * 16 + LB(D_80062D24)) << 5);
    SH(D_80062A50 + off, LHU(t + 0x10));
    a0 = (uint32_t)LHU(t + 0x12);
    sum = (uint32_t)LHU(D_80062CB0) + (a0 & 0x1F); /* release rate + damper */
    if (!((int16_t)sum < 0x20))
        sum = 0x1F;
    SH(D_80062A50 + off + 2, sum | (a0 & 0xFFE0));
    SB(D_80062A28 + LH(D_80062D30), LBU(D_80062A28 + LH(D_80062D30)) | 0x30);
    return 0;
}

/* note2pitch 0x80037B84 */
int note2pitch(void)
{
    uint32_t shift = (uint32_t)LBU(D_80062D29);
    if (!((shift & 0xFF) < 0x80))
        shift = 0x7F;
    return SsPitchFromNote(LB(D_80062D1A), 0, LBU(D_80062D28), shift) & 0xFFFF;
}

/* note2pitch2 0x80037BD0: note, fine of a pitch bend */
int note2pitch2(int a0, int a1)
{
    int32_t idx = (int16_t)((int8_t)LBU(D_80062D24) + (LB(D_80062D1F) << 4));
    uint32_t t = (uint32_t)(idx * 32) + (uint32_t)LW(D_80062D08);
    return SsPitchFromNote((int16_t)a0, (int16_t)a1, LBU(t + 4), LBU(t + 5)) & 0xFFFF;
}

/* vmNoiseOn 0x80037D64: key on the current tone as noise on voice a0. */
int vmNoiseOn(int a0)
{
    uint32_t s3 = (uint32_t)a0;
    uint32_t s0, a3, a2, s1, s2, v1, a0m;
    int32_t a3v, p;
    uint32_t a1;

    /* velocity * vab master * program * tone volume */
    a3v = Vm_DivS(LB(D_80062D1C) * (int32_t)(LBU((uint32_t)LW(D_80062D04) + 0x18) * 0x3FFF),
                  0x82061029u, 13);
    a2 = Vm_DivU((uint32_t)(a3v * LB(D_80062D22) * LB(D_80062D25)), 0x40C2051u, 13);
    a3 = a2;
    if ((int16_t)LHU(D_80062D2C) != 0x21) {
        uint32_t sc = Vm_ScoreAddr((uint32_t)(int32_t)(int16_t)LHU(D_80062D2C));
        uint32_t l = a2 * (uint32_t)LHU(sc + 0x58);
        uint32_t r = a2 * (uint32_t)LHU(sc + 0x5A);
        a3 = Vm_DivU(l, 0x2040811u, 6);
        a2 = Vm_DivU(r, 0x2040811u, 6);
    }

    /* tone pan */
    p = LB(D_80062D26);
    if ((uint32_t)p < 0x40) {
        s2 = a3;
        s1 = Vm_DivU(a2 * (uint32_t)p, 0x4104105u, 5);
    } else {
        s1 = a2;
        s2 = Vm_DivU(a3 * (uint32_t)(0x7F - p), 0x4104105u, 5);
    }
    /* program pan */
    p = LB(D_80062D23);
    if ((uint32_t)p < 0x40)
        s1 = Vm_DivU(s1 * (uint32_t)p, 0x4104105u, 5);
    else
        s2 = Vm_DivU(s2 * (uint32_t)(0x7F - p), 0x4104105u, 5);
    /* note pan */
    p = LB(D_80062D1D);
    if ((uint32_t)p < 0x40)
        s1 = Vm_DivU((uint32_t)p * s1, 0x4104105u, 5);
    else
        s2 = Vm_DivU(s2 * (uint32_t)(0x7F - p), 0x4104105u, 5);

    if (LH(D_80062CF8) == 1) { /* mono */
        if (s2 < s1)
            s2 = s1;
        else
            s1 = s2;
    }
    if (LH(D_80062D2C) != 0x21) {
        s2 = Vm_DivU(s2 * s2, 0x40011u, 13);
        s1 = Vm_DivU(s1 * s1, 0x40011u, 13);
    }

    SpuSetNoiseClock((LB(D_80062D1A) - LB(D_80062D28)) & 0x3F);
    s0 = s3 & 0xFF;
    SH(D_80062A4A + s0 * 16, s1);
    SH(D_80062A48 + s0 * 16, s2);
    SB(D_80062A28 + s0, LBU(D_80062A28 + s0) | 0x3);
    if (s0 < 0x10) {
        a3 = SLLV(1, s0);
        a2 = 0;
    } else {
        a3 = 0;
        a2 = SLLV(1, s0 - 0x10);
    }
    SH(D_800624EC + VM(s3 & 0xFF), 0xA);

    /* only one noise voice: the other noise voices go back to plain key on state */
    for (a1 = 0; (int16_t)a1 < LB(D_80062D0C); a1++) {
        int32_t v = (int16_t)a1;
        if (((uint32_t)LW(D_8004FC18) & SLLV(1, v)) == 0)
            SB(D_80062505 + VM(v), LBU(D_80062505 + VM(v)) & 1);
    }
    SB(D_80062505 + VM(s3 & 0xFF), 2);

    v1 = (uint32_t)LHU(D_800624D8) | a3;
    a0m = (uint32_t)LHU(D_800624DA) | a2;
    SH(D_800624D8, v1);
    SH(D_80062C10, LHU(D_80062C10) & ~v1);
    SH(D_800624DA, a0m);
    SH(D_80062C12, LHU(D_80062C12) & ~a0m);
    if (LBU(D_80062D2A) & 4) { /* reverb */
        SH(D_800624DC, LHU(D_800624DC) | a3);
        SH(D_800624DE, LHU(D_800624DE) | a2);
    } else {
        SH(D_800624DC, LHU(D_800624DC) & ~a3);
        SH(D_800624DE, LHU(D_800624DE) & ~a2);
    }
    SH(D_800624E0, a3);
    SH(D_800624E2, a2);
    return 0;
}

/* vmNoiseOff 0x800382D4 */
int vmNoiseOff(int a0)
{
    uint32_t o = VM((uint32_t)a0 & 0xFF);
    SB(D_80062505 + o, 0);
    SH(D_800624E8 + o, 0);
    SH(D_800624EC + o, 0);
    return 0;
}

/* _SsVmKeyOffNow 0x80038314: key off the current voice (D_80062D30). a0 unused. */
int _SsVmKeyOffNow(int a0)
{
    uint32_t v = (uint32_t)LHU(D_80062D30);
    uint32_t lo, hi, o, k1, k2;
    (void)a0;

    if (v < 0x10) {
        lo = SLLV(1, v);
        hi = 0;
    } else {
        lo = 0;
        hi = SLLV(1, v - 0x10);
    }
    o = VM(v);
    SB(D_80062505 + o, 0);
    k1 = (uint32_t)LHU(D_80062C10);
    k2 = (uint32_t)LHU(D_80062C12);
    SH(D_800624EC + o, 0);
    SH(D_800624E8 + o, 0);
    k1 |= lo;
    SH(D_80062C10, k1);
    SH(D_800624D8, LHU(D_800624D8) & ~k1);
    k2 |= hi;
    SH(D_80062C12, k2);
    SH(D_800624DA, LHU(D_800624DA) & ~k2);
    return 0;
}

/* _SsVmKeyOnNow 0x800383D4: volume / pan of the current tone, key on the current voice
 * with pitch a1. a0 (tone count) unused. */
int _SsVmKeyOnNow(int a0, int a1)
{
    uint32_t t1 = (uint32_t)a1;
    uint32_t t2 = (uint32_t)LH(D_80062D30) << 3;
    uint32_t a2, a3, l, r, pan, lo, hi, okon1, okon2;
    int32_t a3v, acc;
    (void)a0;

    /* velocity * vab master * program * tone volume */
    a3v = Vm_DivS(LB(D_80062D1C) * (int32_t)(LBU((uint32_t)LW(D_80062D04) + 0x18) * 0x3FFF),
                  0x82061029u, 13);
    a2 = Vm_DivU((uint32_t)(a3v * LB(D_80062D22) * LB(D_80062D25)), 0x40C2051u, 13);
    acc = (int16_t)LHU(D_80062D2C);
    a3 = a2;
    if (acc != 0x21) { /* sequence volume */
        uint32_t sc = Vm_ScoreAddr((uint32_t)acc);
        uint32_t lv = a2 * (uint32_t)LHU(sc + 0x58);
        uint32_t rv = a2 * (uint32_t)LHU(sc + 0x5A);
        a3 = Vm_DivU(lv, 0x2040811u, 6);
        a2 = Vm_DivU(rv, 0x2040811u, 6);
    }

    /* tone pan */
    pan = (uint32_t)LBU(D_80062D26);
    if (pan < 0x40) {
        l = a3;
        r = Vm_DivU(a2 * pan, 0x4104105u, 5);
    } else {
        r = a2;
        l = Vm_DivU(a3 * (0x7F - pan), 0x4104105u, 5);
    }
    /* program pan */
    pan = (uint32_t)LBU(D_80062D23);
    if (pan < 0x40)
        r = Vm_DivU(r * pan, 0x4104105u, 5);
    else
        l = Vm_DivU(l * (0x7F - pan), 0x4104105u, 5);
    /* note pan */
    pan = (uint32_t)LBU(D_80062D1D);
    if (pan < 0x40)
        r = Vm_DivU(r * pan, 0x4104105u, 5);
    else
        l = Vm_DivU(l * (0x7F - pan), 0x4104105u, 5);

    if (LH(D_80062CF8) == 1) { /* mono */
        if (l < r)
            l = r;
        else
            r = l;
    }
    if (LH(D_80062D2C) != 0x21) {
        l = Vm_DivU(l * l, 0x40011u, 13);
        r = Vm_DivU(r * r, 0x40011u, 13);
    }

    {
        uint32_t off = (t2 & 0xFFFF) * 2;
        SH(D_80062A4C + off, t1);
        SH(D_80062A48 + off, l);
        SH(D_80062A4A + off, r);
    }
    SB(D_80062A28 + LH(D_80062D30), LBU(D_80062A28 + LH(D_80062D30)) | 0x7);
    SH(D_800624EC + VM(LH(D_80062D30)), t1);

    if (LH(D_80062D30) < 0x10) {
        lo = SLLV(1, LH(D_80062D30));
        hi = 0;
    } else {
        lo = 0;
        hi = SLLV(1, LH(D_80062D30) - 0x10);
    }
    if (LBU(D_80062D2A) & 4) { /* reverb */
        SH(D_800624DC, LHU(D_800624DC) | lo);
        SH(D_800624DE, LHU(D_800624DE) | hi);
    } else {
        SH(D_800624DC, LHU(D_800624DC) & ~lo);
        SH(D_800624DE, LHU(D_800624DE) & ~hi);
    }
    /* no noise, key on, clear key off */
    SH(D_800624E0, LHU(D_800624E0) & ~lo);
    okon2 = (uint32_t)LHU(D_800624DA) | hi;
    okon1 = (uint32_t)LHU(D_800624D8) | lo;
    SH(D_800624DA, okon2);
    SH(D_800624E2, LHU(D_800624E2) & ~hi);
    SH(D_800624D8, okon1);
    SH(D_80062C10, LHU(D_80062C10) & ~okon1);
    SH(D_80062C12, LHU(D_80062C12) & ~okon2);
    return 0;
}

/* _SsVmPBVoice 0x800388A4: voice, seq access number, vab, program, bend (0x40 center).
 * Returns 1 when the voice plays that note, after the new pitch went to the shadow regs. */
int _SsVmPBVoice(int a0, int a1, int a2, int a3, int bend)
{
    uint32_t t1 = (uint32_t)a0;
    int32_t t0 = (int16_t)(bend - 0x40);
    uint32_t o = VM((int16_t)a0);
    uint32_t ti, note, fine, t;
    int32_t s0, x;

    if (LH(D_800624F8 + o) != (int16_t)a1)
        return 0;
    if (LH(D_80062500 + o) != (int16_t)a2)
        return 0;
    if (LH(D_800624FC + o) != (int16_t)a3)
        return 0;

    ti = (uint32_t)LHU(D_800624FE + o) + (uint32_t)(LB(D_80062D1F) << 4);
    note = (uint32_t)LHU(D_800624F6 + o);
    if (t0 > 0) {
        int32_t q;
        t = (uint32_t)LW(D_80062D08) + ((ti & 0xFFFF) << 5);
        x = t0 * LBU(t + 0xD); /* pbmax */
        q = Vm_DivS(x, 0x82082083u, 5);
        note += (uint32_t)q;
        fine = (uint32_t)(x - q * 63) << 1;
    } else if (t0 < 0) {
        int32_t q;
        t = (uint32_t)LW(D_80062D08) + ((ti & 0xFFFF) << 5);
        x = t0 * LBU(t + 0xC); /* pbmin */
        q = x / 64;
        note = note + (uint32_t)q - 1;
        fine = (uint32_t)((x - q * 64) * 2 + 0x7F);
    } else {
        fine = 0;
    }

    s0 = (int16_t)t1;
    SH(D_80062D30, t1);
    SB(D_80062D24, LBU(D_800624FE + VM(s0)));
    t = (uint32_t)note2pitch2(note & 0xFFFF, fine & 0xFFFF);
    SH(D_80062A4C + (uint32_t)(s0 << 4), t);
    SB(D_80062A28 + s0, LBU(D_80062A28 + s0) | 0x4);
    return 1;
}

/* _SsVmPitchBend 0x80038A90: seq access number, vab, program, bend. Returns the voice count. */
int _SsVmPitchBend(int a0, int a1, int a2, int a3)
{
    int32_t s0 = 0;
    uint32_t s1;

    _SsVmVSetUp((int16_t)a1, (int16_t)a2);
    SH(D_80062D2C, a0);
    for (s1 = 0; (int16_t)s1 < LB(D_80062D0C); s1++)
        s0 += (int16_t)_SsVmPBVoice((int16_t)s1, (int16_t)a0, (int16_t)a1, (int16_t)a2,
                                    (uint32_t)a3 & 0xFFFF);
    return s0;
}

/* func_80038B74 0x80038B74: set the program volume byte. vab, program, volume. */
int func_80038B74(int a0, int a1, int a2)
{
    int32_t s0 = (int16_t)a1;

    if (_SsVmVSetUp((int16_t)a0, s0) != 0)
        return -1;
    SB((uint32_t)LW(D_80062CFC) + (uint32_t)(s0 << 4) + 1, a2);
    return LBU((uint32_t)LW(D_80062CFC) + (uint32_t)(s0 << 4) + 1);
}

/* _SsVmSetSeqVol 0x80038BE4: seq access number, left, right. Recomputes the volume of every
 * voice of that sequence. */
int _SsVmSetSeqVol(int a0, int a1, int a2)
{
    uint32_t s6 = (uint32_t)a0;
    uint32_t s1 = Vm_ScoreAddr((uint32_t)a0);
    uint32_t s2;

    SH(s1 + 0x58, a1);
    SH(s1 + 0x5A, a2);
    if (!(LHU(s1 + 0x58) < 0x7F))
        SH(s1 + 0x58, 0x7F);
    if (!(LHU(s1 + 0x5A) < 0x7F))
        SH(s1 + 0x5A, 0x7F);

    for (s2 = 0; (int16_t)s2 < LB(D_80062D0C); s2++) {
        int32_t v = (int16_t)s2;
        uint32_t o = VM(v);
        uint32_t t, vol, l, r, pan;
        int32_t x;

        if ((uint32_t)LW(D_8004FC18) & SLLV(1, v))
            continue;
        if (LH(D_800624F8 + o) != (int16_t)s6)
            continue;
        if (LH(D_80062500 + o) != LB(s1 + 0x26))
            continue;
        _SsVmVSetUp(LH(D_80062500 + o), LH(D_800624FA + o));

        /* velocity * channel volume / 127 * vab master * program * tone volume */
        x = Vm_DivS(LH(D_800624F0 + o) * LH(s1 + 0x60 + (uint32_t)(LH(D_800624F4 + o) * 2)),
                    0x81020409u, 6);
        x = Vm_DivS((int32_t)LBU((uint32_t)LW(D_80062D04) + 0x18) * (x * 0x3FFF),
                    0x82061029u, 13);
        x = x * LBU((uint32_t)LW(D_80062CFC) + (uint32_t)(LH(D_800624FC + o) << 4) + 1);
        t = (uint32_t)LW(D_80062D08) +
            (uint32_t)(((LH(D_800624FA + o) << 4) + LH(D_800624FE + o)) << 5);
        vol = Vm_DivU((uint32_t)(x * LBU(t + 2)), 0x40C2051u, 13);
        l = Vm_DivU(vol * (uint32_t)LHU(s1 + 0x58), 0x2040811u, 6);
        r = Vm_DivU(vol * (uint32_t)LHU(s1 + 0x5A), 0x2040811u, 6);

        /* tone pan */
        pan = (uint32_t)LBU(t + 3);
        if (pan < 0x40)
            r = Vm_DivU(r * pan, 0x4104105u, 5);
        else
            l = Vm_DivU(l * (0x7F - pan), 0x4104105u, 5);
        /* program pan */
        pan = (uint32_t)LBU((uint32_t)LW(D_80062CFC) + (uint32_t)(LH(D_800624FC + VM(v)) << 4) + 4);
        if (pan < 0x40)
            r = Vm_DivSL((int32_t)((r & 0xFFFF) * pan), 0x82082083u, 5);
        else
            l = (uint32_t)Vm_DivS((int32_t)((l & 0xFFFF) * (0x7F - pan)), 0x82082083u, 5);
        /* note pan */
        pan = (uint32_t)LBU(D_800624F2 + VM(v));
        if (pan < 0x40)
            r = Vm_DivSL((int32_t)((r & 0xFFFF) * pan), 0x82082083u, 5);
        else
            l = (uint32_t)Vm_DivS((int32_t)((l & 0xFFFF) * (0x7F - pan)), 0x82082083u, 5);

        if (LH(D_80062CF8) == 1) { /* mono */
            if ((l & 0xFFFF) < (r & 0xFFFF))
                l = r;
            else
                r = l;
        }
        {
            int32_t ll = (int32_t)((l & 0xFFFF) * (l & 0xFFFF));
            int32_t rr = (int32_t)((r & 0xFFFF) * (r & 0xFFFF));
            SH(D_80062A48 + (uint32_t)(v << 4), Vm_DivS(ll, 0x80020009u, 13));
            SH(D_80062A4A + (uint32_t)(v << 4), Vm_DivS(rr, 0x80020009u, 13));
        }
        SB(D_80062A28 + v, LBU(D_80062A28 + v) | 0x3);
    }
    return (int16_t)s6;
}

/* _SsVmGetSeqVol 0x80039150: seq access number, short *left, short *right */
int _SsVmGetSeqVol(int a0, uint32_t a1, uint32_t a2)
{
    uint32_t sc = Vm_ScoreAddr((uint32_t)a0);

    SH(D_80062D2C, a0);
    SH(a1, LHU(sc + 0x58));
    SH(a2, LHU(sc + 0x5A));
    return LH(D_80062D2C);
}

/* _SsVmSeqKeyOff 0x800391B4: key off every voice of a sequence */
int _SsVmSeqKeyOff(int a0)
{
    int32_t s1 = (int16_t)a0;
    uint32_t s0;

    for (s0 = 0; (int32_t)(s0 & 0xFF) < LB(D_80062D0C); s0++) {
        uint32_t v = s0 & 0xFF;
        if ((uint32_t)LW(D_8004FC18) & SLLV(1, v))
            continue;
        if (LH(D_800624F8 + VM(v)) != s1)
            continue;
        SH(D_80062D30, v);
        _SsVmKeyOffNow(0);
    }
    return 0;
}

/* _SsVmSelectToneAndVag 0x80039264: tones of the current program whose key range holds the
 * current note. Writes tone indexes to a0[] and vag numbers to a1[], returns the count. */
int _SsVmSelectToneAndVag(uint32_t a0, uint32_t a1)
{
    uint32_t cnt = 0, i = 0;

    if (LB(D_80062D18) <= 0)
        return 0;
    do {
        uint32_t t = (uint32_t)LW(D_80062D08) +
                     (uint32_t)(((LB(D_80062D1F) << 4) + (int8_t)i) << 5);
        int32_t note = LB(D_80062D1A);
        if (!(note < LBU(t + 6)) && !(LBU(t + 7) < note)) { /* min..max */
            uint32_t k = cnt & 0xFF;
            cnt++;
            SB(a1 + k, LBU(t + 0x16));
            SB(a0 + k, i);
        }
        i++;
    } while ((int8_t)i < LB(D_80062D18));
    return cnt & 0xFF;
}

/* _SsVmSetVol 0x80039334: seq access number, vab, program, volume, pan. Returns the voice
 * count. */
int _SsVmSetVol(int a0, int a1, int a2, int a3, int pan)
{
    uint32_t s1 = (uint32_t)a3;
    int32_t s5 = (int16_t)a0;
    uint32_t s4 = Vm_ScoreAddr((uint32_t)a0);
    int32_t s2 = (int16_t)a1;
    int32_t s3 = (int16_t)a2;
    uint32_t s6 = (uint32_t)pan & 0xFFFF;
    int32_t s7 = 0;
    uint32_t vol, t1;

    _SsVmVSetUp(s2, s3);
    SH(D_80062D2C, a0);
    if (s6 == 0)
        s6 = 1;
    if ((s1 & 0xFFFF) == 0)
        s1 = 1;
    vol = s1 & 0xFFFF;

    for (t1 = 0; (int16_t)t1 < LB(D_80062D0C); t1++) {
        int32_t v = (int16_t)t1;
        uint32_t o = VM(v);
        uint32_t cv, t, x, l, r, pan2;
        int32_t y;

        if ((uint32_t)LW(D_8004FC18) & SLLV(1, v))
            continue;
        if (LH(D_800624F8 + o) != s5)
            continue;
        if (LH(D_800624FC + o) != s3)
            continue;
        if (LH(D_80062500 + o) != s2)
            continue;

        cv = s4 + 0x60 + (uint32_t)LBU(s4 + 0x17) * 2; /* channel volume */
        if (LH(cv) != (int32_t)vol && LH(cv) == 0)
            SH(cv, 1);

        y = Vm_DivS(LH(D_800624F0 + o) * (int32_t)vol, 0x81020409u, 6);
        y = Vm_DivS(y * (int32_t)(LBU((uint32_t)LW(D_80062D04) + 0x18) * 0x3FFF), 0x82061029u, 13);
        y = y * LBU((uint32_t)LW(D_80062CFC) + (uint32_t)(s3 << 4) + 1);
        t = (uint32_t)LW(D_80062D08) +
            (uint32_t)(((LH(D_800624FA + o) << 4) + LH(D_800624FE + o)) << 5);
        x = Vm_DivU((uint32_t)(y * LBU(t + 2)), 0x40C2051u, 13);
        l = Vm_DivU(x * (uint32_t)LHU(s4 + 0x58), 0x2040811u, 6);
        r = Vm_DivU(x * (uint32_t)LHU(s4 + 0x5A), 0x2040811u, 6);

        /* tone pan */
        pan2 = (uint32_t)LBU(t + 3);
        if (pan2 < 0x40)
            r = Vm_DivU(r * pan2, 0x4104105u, 5);
        else
            l = Vm_DivU(l * (0x7F - pan2), 0x4104105u, 5);
        /* program pan */
        pan2 = (uint32_t)LBU((uint32_t)LW(D_80062CFC) + (uint32_t)(LH(D_800624FC + VM(v)) << 4) + 4);
        if (pan2 < 0x40)
            r = Vm_DivU(r * pan2, 0x4104105u, 5);
        else
            l = Vm_DivU(l * (0x7F - pan2), 0x4104105u, 5);
        /* pan argument */
        pan2 = s6 & 0xFF;
        if (pan2 < 0x40)
            r = Vm_DivU(r * pan2, 0x4104105u, 5);
        else
            l = Vm_DivU(l * (0x7F - pan2), 0x4104105u, 5);

        if (LH(D_80062CF8) == 1) { /* mono */
            if (l < r)
                l = r;
            else
                r = l;
        }
        l = Vm_DivU(l * l, 0x40011u, 13);
        r = Vm_DivU(r * r, 0x40011u, 13);
        SH(D_80062A48 + (uint32_t)(v << 4), l);
        SH(D_80062A4A + (uint32_t)(v << 4), r);
        SB(D_80062A28 + v, LBU(D_80062A28 + v) | 0x3);
        s7++;
    }
    return s7;
}

/* _SsVmVSetUp 0x800398D4: select vab a0, program a1 (current VabHdr / ProgAtr / VagAtr). */
int _SsVmVSetUp(int a0, int a1)
{
    int32_t vab, prog;
    uint32_t pa;

    if (!(((uint32_t)a0 & 0xFFFF) < 0x10))
        return -1;
    vab = (int16_t)a0;
    if (LBU(D_80062D38 + vab) != 1)
        return -1;
    prog = (int16_t)a1;
    if (!(prog < LH(D_80062CFA)))
        return -1;
    SB(D_80062D19, a0);
    SB(D_80062D1E, a1);
    SW(D_80062D08, LW(D_80062CB8 + vab * 4));
    SW(D_80062D04, LW(D_80062C70 + vab * 4));
    pa = (uint32_t)LW(D_80062C30 + vab * 4);
    SW(D_80062CFC, pa);
    SB(D_80062D1F, LBU(pa + (uint32_t)(prog << 4) + 8));
    return 0;
}

/* func_80039A78 0x80039A78: SpuMalloc for a vab; on failure free vab slot a2. */
int func_80039A78(int a0, int a1, int a2)
{
    int v = SpuMalloc(a0);
    (void)a1;

    if (v != -1)
        return v;
    SB(D_80062D38 + (int16_t)a2, 0);
    _spu_setInTransfer(0);
    SH(D_80062D90, LHU(D_80062D90) - 1);
    return -1;
}
