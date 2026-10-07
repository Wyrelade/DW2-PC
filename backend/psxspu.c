#include <stdio.h>
#include <string.h>

#include "backend/psxspu.h"

/* Emulated PS1 SPU (P1.8), after psx-spx "Sound Processing Unit (SPU)": SPU-ADPCM decode (5
 * filters, flag bits loop start / end / repeat), pitch counter with PMON, the 4-point
 * interpolation table, the ADSR / sweep envelope steps (counter increment, exponential
 * rules), voice and main volumes, noise generator, KON / KOFF / ENDX, manual and DMA sound RAM
 * transfers, ATTR / STATX, reverb (22050 Hz, FIR resampled). Everything runs per 44.1 kHz
 * sample in PsxSpu_Render. Not mixed yet: the CD / external inputs (logged once). */

uint8_t PsxSpu_Ram[PSXSPU_RAM_SIZE];

#include "backend/psxspu_gauss.inc"

/* Envelope (ADSR phase or volume sweep) step parameters, psx-spx "Envelope Operation". */
typedef struct {
    int exp, decrease, shift, step; /* step 0..3 */
} EnvRate;

typedef struct {
    int counter;
} EnvState;

enum { PH_OFF, PH_ATTACK, PH_DECAY, PH_SUSTAIN, PH_RELEASE };

typedef struct {
    uint32_t cur_addr;    /* bytes, block being played */
    uint32_t repeat_addr; /* bytes */
    uint32_t counter;     /* pitch counter: bit 12 up = sample in block, 4..11 interpolation */
    int16_t s[3 + 28];    /* 3 samples of the previous block + the decoded block */
    int16_t hist1, hist2; /* ADPCM filter history */
    uint8_t flags;        /* flag byte of the current block */
    int ignore_loop;      /* LSAX written by software after key on */
    int phase;
    int level;            /* ADSR level (ENVX) */
    EnvState env;
    int vol_level[2];     /* current voice volume (VOLX) */
    EnvState vol_env[2];
} Voice;

static uint16_t regs[0x200]; /* register file as written (halfwords at 0x1F801C00..) */
static Voice voices[24];
static int main_level[2];
static EnvState main_env[2];
static uint32_t endx;
static uint32_t transfer_addr;
static int noise_level = 1, noise_timer;
/* reverb: input / output rings at 44.1 kHz for the FIR, buffer address, 22 kHz phase */
static int16_t rev_in[2][64];
static int16_t rev_out[2][64];
static int rev_pos; /* ring position (44.1 kHz samples) */
static uint32_t rev_addr; /* current buffer address, bytes */
static int rev_phase;

static void log_once(int id, const char *what) {
    static unsigned char seen[64];
    if (!seen[id & 63]) {
        seen[id & 63] = 1;
        printf("[spu] %s (logged once)\n", what);
    }
}

void PsxSpu_Reset(void) {
    memset(regs, 0, sizeof(regs));
    memset(voices, 0, sizeof(voices));
    memset(main_level, 0, sizeof(main_level));
    memset(main_env, 0, sizeof(main_env));
    endx = 0;
    transfer_addr = 0;
    noise_level = 1;
    noise_timer = 0;
    memset(rev_in, 0, sizeof(rev_in));
    memset(rev_out, 0, sizeof(rev_out));
    rev_pos = rev_phase = 0;
    rev_addr = 0;
}

/* --- envelope ---------------------------------------------------------------------------- */

static int env_tick(EnvState *e, const EnvRate *r, int level) {
    int step = 7 - r->step;
    int inc;
    if (r->decrease) step = ~step;
    step = (int)((unsigned int)step << (11 - r->shift > 0 ? 11 - r->shift : 0));
    inc = 0x8000 >> (r->shift - 11 > 0 ? r->shift - 11 : 0);
    if (r->exp && !r->decrease && level > 0x6000) {
        if (r->shift < 10) step >>= 2;
        else if (r->shift >= 11) inc >>= 2;
        else { step >>= 1; inc >>= 1; }
    } else if (r->exp && r->decrease) {
        step = step * level >> 15;
    }
    if ((r->step | (r->shift << 2)) != 0x7F) {
        if (inc < 1) inc = 1;
    }
    e->counter += inc;
    if (!(e->counter & 0x8000)) return level;
    e->counter = 0;
    level += step;
    if (!r->decrease) {
        if (level > 0x7FFF) level = 0x7FFF;
        if (level < -0x8000) level = -0x8000;
    } else if (level < 0) {
        level = 0;
    }
    return level;
}

static void adsr_rate(const Voice *v, int idx, EnvRate *r) {
    uint16_t a1 = regs[idx * 8 + 4], a2 = regs[idx * 8 + 5];
    memset(r, 0, sizeof(*r));
    switch (v->phase) {
    case PH_ATTACK:
        r->exp = a1 >> 15;
        r->shift = (a1 >> 10) & 0x1F;
        r->step = (a1 >> 8) & 3;
        break;
    case PH_DECAY:
        r->exp = 1;
        r->decrease = 1;
        r->shift = (a1 >> 4) & 0xF;
        r->step = 0;
        break;
    case PH_SUSTAIN:
        r->exp = a2 >> 15;
        r->decrease = (a2 >> 14) & 1;
        r->shift = (a2 >> 8) & 0x1F;
        r->step = (a2 >> 6) & 3;
        break;
    default: /* release */
        r->exp = (a2 >> 5) & 1;
        r->decrease = 1;
        r->shift = a2 & 0x1F;
        r->step = 0;
        break;
    }
}

static void adsr_step(Voice *v, int idx) {
    EnvRate r;
    if (v->phase == PH_OFF) return;
    adsr_rate(v, idx, &r);
    v->level = env_tick(&v->env, &r, v->level);
    switch (v->phase) {
    case PH_ATTACK:
        if (v->level >= 0x7FFF) { v->phase = PH_DECAY; v->env.counter = 0; }
        break;
    case PH_DECAY: {
        int sustain = ((regs[idx * 8 + 4] & 0xF) + 1) * 0x800;
        if (v->level <= sustain) { v->phase = PH_SUSTAIN; v->env.counter = 0; }
        break;
    }
    case PH_RELEASE:
        if (v->level <= 0) { v->level = 0; v->phase = PH_OFF; }
        break;
    }
}

/* Volume register: direct (bit 15 = 0, value * 2) or sweep. */
static int volume_step(uint16_t reg, EnvState *e, int level) {
    EnvRate r;
    if (!(reg & 0x8000)) return (int16_t)(reg << 1);
    r.exp = (reg >> 14) & 1;
    r.decrease = (reg >> 13) & 1;
    r.shift = (reg >> 2) & 0x1F;
    r.step = reg & 3;
    if (reg & 0x1000) log_once(1, "volume sweep with negative phase not modelled");
    return env_tick(e, &r, level);
}

/* --- ADPCM ------------------------------------------------------------------------------- */

static const int filter_pos[5] = { 0, 60, 115, 98, 122 };
static const int filter_neg[5] = { 0, 0, -52, -55, -60 };

static void decode_block(Voice *v) {
    const uint8_t *b = &PsxSpu_Ram[v->cur_addr & (PSXSPU_RAM_SIZE - 1) & ~15u];
    int shift = b[0] & 0xF, filter = (b[0] >> 4) & 7, i;
    if (shift > 12) shift = 9;
    if (filter > 4) filter = 4;
    v->flags = b[1];
    /* keep the last 3 samples for the interpolation */
    v->s[0] = v->s[28];
    v->s[1] = v->s[29];
    v->s[2] = v->s[30];
    for (i = 0; i < 28; i++) {
        int nib = (b[2 + i / 2] >> ((i & 1) * 4)) & 0xF;
        int x = (int16_t)(nib << 12) >> shift;
        x += (v->hist1 * filter_pos[filter] + v->hist2 * filter_neg[filter] + 32) >> 6;
        if (x > 0x7FFF) x = 0x7FFF;
        if (x < -0x8000) x = -0x8000;
        v->hist2 = v->hist1;
        v->hist1 = (int16_t)x;
        v->s[3 + i] = (int16_t)x;
    }
    if ((v->flags & 4) && !v->ignore_loop) v->repeat_addr = v->cur_addr & ~15u;
}

static void key_on(int i) {
    Voice *v = &voices[i];
    v->cur_addr = (uint32_t)regs[i * 8 + 3] << 3;
    v->counter = 0;
    v->hist1 = v->hist2 = 0;
    memset(v->s, 0, sizeof(v->s));
    v->ignore_loop = 0;
    v->phase = PH_ATTACK;
    v->level = 0;
    v->env.counter = 0;
    endx &= ~(1u << i);
    decode_block(v);
}

static void key_off(int i) {
    Voice *v = &voices[i];
    if (v->phase != PH_OFF) {
        v->phase = PH_RELEASE;
        v->env.counter = 0;
    }
}

/* End of a block: loop end flag, else the next block. */
static void next_block(Voice *v, int i) {
    if (v->flags & 1) {
        endx |= 1u << i;
        v->cur_addr = v->repeat_addr;
        if (!(v->flags & 2)) {
            v->phase = PH_RELEASE;
            v->level = 0;
        }
    } else {
        v->cur_addr = (v->cur_addr + 16) & (PSXSPU_RAM_SIZE - 1);
    }
    decode_block(v);
}

/* --- registers --------------------------------------------------------------------------- */

void PsxSpu_Write16(uint32_t off, uint16_t v) {
    off &= 0x3FE;
    regs[off >> 1] = v;
    if (off < 0x180) {
        int i = off >> 4;
        if ((off & 0xF) == 0xE) {
            voices[i].repeat_addr = (uint32_t)v << 3;
            if (voices[i].phase != PH_OFF) voices[i].ignore_loop = 1;
        } else if ((off & 0xF) == 0xC) {
            voices[i].level = (int16_t)v;
        }
        return;
    }
    switch (off) {
    case 0x188: case 0x18A: { /* KON */
        int base = off == 0x188 ? 0 : 16, b;
        for (b = 0; b < 16 && base + b < 24; b++)
            if (v & (1u << b)) key_on(base + b);
        break;
    }
    case 0x18C: case 0x18E: { /* KOFF */
        int base = off == 0x18C ? 0 : 16, b;
        for (b = 0; b < 16 && base + b < 24; b++)
            if (v & (1u << b)) key_off(base + b);
        break;
    }
    case 0x1A2: /* reverb work area start: also the current buffer address */
        rev_addr = (uint32_t)v << 3;
        break;
    case 0x1A6: /* transfer address */
        transfer_addr = (uint32_t)v << 3;
        break;
    case 0x1A8: /* manual write FIFO */
        PsxSpu_Ram[transfer_addr & (PSXSPU_RAM_SIZE - 1)] = (uint8_t)v;
        PsxSpu_Ram[(transfer_addr + 1) & (PSXSPU_RAM_SIZE - 1)] = (uint8_t)(v >> 8);
        transfer_addr = (transfer_addr + 2) & (PSXSPU_RAM_SIZE - 1);
        break;
    }
}

uint16_t PsxSpu_Read16(uint32_t off) {
    off &= 0x3FE;
    if (off < 0x180) {
        int i = off >> 4;
        if ((off & 0xF) == 0xC) return (uint16_t)voices[i].level;
        if ((off & 0xF) == 0xE) return (uint16_t)(voices[i].repeat_addr >> 3);
        return regs[off >> 1];
    }
    switch (off) {
    case 0x19C: return (uint16_t)endx;
    case 0x19E: return (uint16_t)(endx >> 16);
    case 0x1AE: { /* STATX: ATTR bits 0-5 applied at once, never busy */
        uint16_t attr = regs[0x1AA >> 1];
        return (uint16_t)((attr & 0x3F) | ((attr & 0x20) ? 0x80 : 0));
    }
    case 0x1B8: return (uint16_t)main_level[0];
    case 0x1BA: return (uint16_t)main_level[1];
    }
    if (off >= 0x200 && off < 0x260) {
        int i = (off - 0x200) >> 2;
        return (uint16_t)voices[i].vol_level[(off >> 1) & 1];
    }
    return regs[off >> 1];
}

void PsxSpu_DmaWrite(const uint32_t *src, uint32_t words) {
    uint32_t i;
    for (i = 0; i < words; i++) {
        uint32_t w = src[i];
        int k;
        for (k = 0; k < 4; k++) {
            PsxSpu_Ram[transfer_addr] = (uint8_t)(w >> (k * 8));
            transfer_addr = (transfer_addr + 1) & (PSXSPU_RAM_SIZE - 1);
        }
    }
}

void PsxSpu_DmaRead(uint32_t *dst, uint32_t words) {
    uint32_t i;
    for (i = 0; i < words; i++) {
        uint32_t w = 0;
        int k;
        for (k = 0; k < 4; k++) {
            w |= (uint32_t)PsxSpu_Ram[transfer_addr] << (k * 8);
            transfer_addr = (transfer_addr + 1) & (PSXSPU_RAM_SIZE - 1);
        }
        dst[i] = w;
    }
}

/* --- mixing ------------------------------------------------------------------------------ */

static void noise_tick(void) {
    uint16_t attr = regs[0x1AA >> 1];
    int shift = (attr >> 10) & 0xF, step = ((attr >> 8) & 3) + 4;
    int parity = ((noise_level >> 15) ^ (noise_level >> 12) ^ (noise_level >> 11) ^ (noise_level >> 10) ^ 1) & 1;
    noise_timer -= step;
    if (noise_timer < 0) {
        noise_level = (int16_t)(noise_level * 2 + parity);
        noise_timer += 0x20000 >> shift;
        if (noise_timer < 0) noise_timer += 0x20000 >> shift;
    }
}

static int clamp16(int x) { return x > 0x7FFF ? 0x7FFF : x < -0x8000 ? -0x8000 : x; }

/* --- reverb ------------------------------------------------------------------------------ */

/* psx-spx "SPU Reverb Formula": runs at 22050 Hz on the work area ESA..0x7FFFE; input and output
 * are resampled with the 39-tap FIR from the same page. */
static const int16_t rev_fir[39] = {
    -0x0001, 0, 0x0002, 0, -0x000A, 0, 0x0023, 0, -0x0067, 0, 0x010A, 0, -0x0268, 0, 0x0534, 0,
    -0x0B90, 0, 0x2806, 0x4000, 0x2806, 0, -0x0B90, 0, 0x0534, 0, -0x0268, 0, 0x010A, 0,
    -0x0067, 0, 0x0023, 0, -0x000A, 0, 0x0002, 0, -0x0001,
};

static int rreg(int r) { return (int16_t)regs[(0x1C0 + r * 2) >> 1]; }
static uint32_t raddr(int r) { return (uint32_t)regs[(0x1C0 + r * 2) >> 1] << 3; }

static uint32_t rev_wrap(uint32_t a) {
    uint32_t esa = (uint32_t)regs[0x1A2 >> 1] << 3;
    uint32_t size = 0x80000 - esa;
    if (size == 0) return esa;
    a = rev_addr + a - esa;
    return esa + (a % size);
}

static int rev_read(uint32_t off) {
    uint32_t a = rev_wrap(off) & 0x7FFFE;
    return (int16_t)(PsxSpu_Ram[a] | PsxSpu_Ram[a + 1] << 8);
}

static void rev_write(uint32_t off, int v) {
    uint32_t a;
    if (!(regs[0x1AA >> 1] & 0x80)) return;
    a = rev_wrap(off) & 0x7FFFE;
    v = clamp16(v);
    PsxSpu_Ram[a] = (uint8_t)v;
    PsxSpu_Ram[a + 1] = (uint8_t)(v >> 8);
}

static int mul(int a, int b) { return clamp16((a * b) >> 15); }

static int fir(const int16_t *h, int pos) {
    int i, acc = 0;
    for (i = 0; i < 39; i++) acc += rev_fir[i] * h[(pos - i) & 63];
    return acc >> 15;
}

/* One 44.1 kHz step: in = reverb send (L, R), out = reverb output (L, R) before EVOL. */
static void reverb_step(int inl, int inr, int *outl, int *outr) {
    rev_in[0][rev_pos & 63] = (int16_t)clamp16(inl);
    rev_in[1][rev_pos & 63] = (int16_t)clamp16(inr);
    rev_out[0][rev_pos & 63] = 0;
    rev_out[1][rev_pos & 63] = 0;
    if (rev_phase) {
        uint32_t esa = (uint32_t)regs[0x1A2 >> 1] << 3;
        int lin = mul(clamp16(fir(rev_in[0], rev_pos)), rreg(0x1E));
        int rin = mul(clamp16(fir(rev_in[1], rev_pos)), rreg(0x1F));
        int viir = rreg(2), vwall = rreg(7), vapf1 = rreg(8), vapf2 = rreg(9);
        int lo, ro, t;
        uint32_t dapf1 = raddr(0), dapf2 = raddr(1);
        /* same side reflection */
        t = rev_read(raddr(0xA) - 2);
        rev_write(raddr(0xA), mul(clamp16(lin + mul(rev_read(raddr(0x10)), vwall) - t), viir) + t);
        t = rev_read(raddr(0xB) - 2);
        rev_write(raddr(0xB), mul(clamp16(rin + mul(rev_read(raddr(0x11)), vwall) - t), viir) + t);
        /* different side reflection */
        t = rev_read(raddr(0x12) - 2);
        rev_write(raddr(0x12), mul(clamp16(lin + mul(rev_read(raddr(0x19)), vwall) - t), viir) + t);
        t = rev_read(raddr(0x13) - 2);
        rev_write(raddr(0x13), mul(clamp16(rin + mul(rev_read(raddr(0x18)), vwall) - t), viir) + t);
        /* early echo */
        lo = clamp16(mul(rreg(3), rev_read(raddr(0xC))) + mul(rreg(4), rev_read(raddr(0xE))) +
                     mul(rreg(5), rev_read(raddr(0x14))) + mul(rreg(6), rev_read(raddr(0x16))));
        ro = clamp16(mul(rreg(3), rev_read(raddr(0xD))) + mul(rreg(4), rev_read(raddr(0xF))) +
                     mul(rreg(5), rev_read(raddr(0x15))) + mul(rreg(6), rev_read(raddr(0x17))));
        /* late reverb APF1, APF2 */
        t = rev_read(raddr(0x1A) - dapf1);
        lo = clamp16(lo - mul(vapf1, t));
        rev_write(raddr(0x1A), lo);
        lo = clamp16(mul(lo, vapf1) + t);
        t = rev_read(raddr(0x1B) - dapf1);
        ro = clamp16(ro - mul(vapf1, t));
        rev_write(raddr(0x1B), ro);
        ro = clamp16(mul(ro, vapf1) + t);
        t = rev_read(raddr(0x1C) - dapf2);
        lo = clamp16(lo - mul(vapf2, t));
        rev_write(raddr(0x1C), lo);
        lo = clamp16(mul(lo, vapf2) + t);
        t = rev_read(raddr(0x1D) - dapf2);
        ro = clamp16(ro - mul(vapf2, t));
        rev_write(raddr(0x1D), ro);
        ro = clamp16(mul(ro, vapf2) + t);
        rev_out[0][rev_pos & 63] = (int16_t)lo;
        rev_out[1][rev_pos & 63] = (int16_t)ro;
        rev_addr = rev_addr + 2 > 0x7FFFE ? esa : rev_addr + 2;
        if (rev_addr < esa) rev_addr = esa;
    }
    /* zero-stuffed 22 kHz output back to 44.1 kHz: FIR gain x2 */
    *outl = clamp16(fir(rev_out[0], rev_pos) * 2);
    *outr = clamp16(fir(rev_out[1], rev_pos) * 2);
    rev_phase ^= 1;
    rev_pos++;
}

void PsxSpu_Render(int16_t *out, int n) {
    int f, i;

    for (f = 0; f < n; f++) {
        uint16_t attr = regs[0x1AA >> 1];
        uint32_t pmon = regs[0x190 >> 1] | (uint32_t)regs[0x192 >> 1] << 16;
        uint32_t non = regs[0x194 >> 1] | (uint32_t)regs[0x196 >> 1] << 16;
        int l = 0, r = 0, prev_out = 0, sl = 0, sr = 0, rl, rr;
        uint32_t eon = regs[0x198 >> 1] | (uint32_t)regs[0x19A >> 1] << 16;

        noise_tick();
        for (i = 0; i < 24; i++) {
            Voice *v = &voices[i];
            int sample, step, idx, ip;
            idx = v->counter >> 12;
            ip = (v->counter >> 4) & 0xFF;
            /* interpolation over s[idx .. idx + 3] (oldest .. new) */
            sample = (gauss_tbl[0xFF - ip] * v->s[idx]) >> 15;
            sample += (gauss_tbl[0x1FF - ip] * v->s[idx + 1]) >> 15;
            sample += (gauss_tbl[0x100 + ip] * v->s[idx + 2]) >> 15;
            sample += (gauss_tbl[ip] * v->s[idx + 3]) >> 15;
            if (non & (1u << i)) sample = (int16_t)noise_level;
            sample = (sample * v->level) >> 15;
            v->vol_level[0] = volume_step(regs[i * 8 + 0], &v->vol_env[0], v->vol_level[0]);
            v->vol_level[1] = volume_step(regs[i * 8 + 1], &v->vol_env[1], v->vol_level[1]);
            {
                int vl = (sample * v->vol_level[0]) >> 15, vr = (sample * v->vol_level[1]) >> 15;
                l += vl;
                r += vr;
                if (eon & (1u << i)) { sl += vl; sr += vr; }
            }
            /* pitch counter */
            step = regs[i * 8 + 2];
            if ((pmon & (1u << i)) && i > 0) {
                int factor = prev_out + 0x8000;
                step = ((int)(int16_t)step * factor) >> 15;
                step &= 0xFFFF;
            }
            if (step > 0x3FFF) step = 0x4000;
            v->counter += (uint32_t)step;
            while ((v->counter >> 12) >= 28) {
                v->counter -= 28u << 12;
                next_block(v, i);
            }
            adsr_step(v, i);
            prev_out = sample;
        }
        main_level[0] = volume_step(regs[0x180 >> 1], &main_env[0], main_level[0]);
        main_level[1] = volume_step(regs[0x182 >> 1], &main_env[1], main_level[1]);
        reverb_step(sl, sr, &rl, &rr);
        l = (clamp16(l) * main_level[0]) >> 15;
        r = (clamp16(r) * main_level[1]) >> 15;
        l += (rl * (int16_t)regs[0x184 >> 1]) >> 15;
        r += (rr * (int16_t)regs[0x186 >> 1]) >> 15;
        if ((attr & 1) && (regs[0x1B0 >> 1] || regs[0x1B2 >> 1]))
            log_once(3, "CD audio input enabled (XA / CD-DA), not mixed yet");
        if (!(attr & 0x8000) || !(attr & 0x4000)) l = r = 0;
        out[f * 2] = (int16_t)clamp16(l);
        out[f * 2 + 1] = (int16_t)clamp16(r);
    }
}
