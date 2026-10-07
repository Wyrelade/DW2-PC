#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backend/psxspu.h"
#include "libsnd.h"
#include "psyq_log.h"
#include "snd_native.h"

/* The memory and hardware model under the translated libsnd / libspu (snd_native.h):
 * address dispatch (retail RAM in Ps1_Ram, SPU registers, DMA channel 4, native pointers),
 * the DMA channel 4 transfer into the SPU model, the libapi / libetc services the sound code
 * calls, and the retail data image the library globals start from. */

#define PSYQ_ASM_STR_(x) #x
#define PSYQ_ASM_XSTR_(x) PSYQ_ASM_STR_(x)
#define PSYQ_ASM_NAME(NAME) PSYQ_ASM_XSTR_(__USER_LABEL_PREFIX__) NAME

/* Retail exe bytes (configs/USA/include_bin_native.txt): rodata 0x80010000..0x80011000 and the
 * data / bss block 0x80038000..0x80063360 (libsnd / libspu globals and tables live there). */
__asm__(
    ".data\n"
    "    .balign 16\n"
    "    .globl " PSYQ_ASM_NAME("Snd_RetailRodata") "\n"
    PSYQ_ASM_NAME("Snd_RetailRodata") ":\n"
    "    .incbin \"assets/main/retail_rodata.bin\"\n"
    "    .balign 16\n"
    "    .globl " PSYQ_ASM_NAME("Snd_RetailData") "\n"
    PSYQ_ASM_NAME("Snd_RetailData") ":\n"
    "    .incbin \"assets/main/retail_data.bin\"\n"
    ".text");
extern const uint8_t Snd_RetailRodata[0x1000];
extern const uint8_t Snd_RetailData[0x2B360];

void Snd_NativeInit(void) {
    memcpy(PS1_RAM(0x80010000), Snd_RetailRodata, sizeof(Snd_RetailRodata));
    memcpy(PS1_RAM(0x80038000), Snd_RetailData, sizeof(Snd_RetailData));
    /* D_8004FC50: the sequencer entry _SsSeqCalledTbyT_1per2 calls (retail &SsSeqCalledTbyT) */
    Snd_W32(0x8004FC50, SND_FNVAL(SsSeqCalledTbyT));
    PsxSpu_Reset();
}

/* --- DMA channel 4 (SPU) ----------------------------------------------------------------- */

static int is_hw(uint32_t a) { return (a & 0xFFFFF000u) == 0x1F801000u || (a & 0xFFFFF000u) == 0x1F802000u; }
static int is_ram(uint32_t a) { return (a & 0xDFE00000u) == 0x80000000u; }

static uint32_t dma_madr, dma_bcr, dma_chcr, dma_dpcr, dma_dicr, spu_delay, com_delay;
static uint32_t dma4_callback;
static int dma4_pending;

/* MADR value back to a pointer: retail RAM, a native pointer, or a 24-bit native address in
 * the 16 MB window (psyq/ps1mem.h). */
static uint8_t *dma_ptr(uint32_t madr) {
    if (is_ram(madr)) return PS1_RAM(madr);
    if (madr < 0x01000000u) return (uint8_t *)PS1_LINK_PTR(madr);
    return SND_PTR(madr);
}

static void dma4_run(void) {
    uint32_t words;
    int mode = (dma_chcr >> 9) & 3;
    if (mode == 1) words = (dma_bcr & 0xFFFF) * (dma_bcr >> 16);
    else words = (dma_bcr & 0xFFFF) ? (dma_bcr & 0xFFFF) : 0x10000;
    if (dma_chcr & 1) PsxSpu_DmaWrite((const uint32_t *)dma_ptr(dma_madr), words);
    else PsxSpu_DmaRead((uint32_t *)dma_ptr(dma_madr), words);
    dma_madr += words * 4;
    dma_chcr &= ~0x01000000u;
    if (dma_dicr & (1u << (16 + 4))) dma_dicr |= 1u << (24 + 4);
    dma4_pending = 1;
}

/* The DMA completion interrupt arrives "later": on the next hardware read or VBlank. */
static void dma4_deliver(void) {
    if (dma4_pending) {
        dma4_pending = 0;
        if (dma4_callback) SND_FN(dma4_callback)();
    }
}

/* Dev dump (DW2_SND_DUMP="DIR,N1,N2,..."): at those VBlank counts, write the libsnd / libspu
 * globals (data 0x8004FC00 +0x800, bss 0x80061B00 +0x1500) and the SPU RAM to DIR, in the
 * layout of the Redux probe dumps (scratchpad/redux_p18). */
static void debug_dump(void) {
    static int vb;
    const char *env = getenv("DW2_SND_DUMP");
    char dir[260], name[300];
    const char *p;
    FILE *f;
    vb++;
    if (env == NULL) return;
    p = strchr(env, ',');
    if (p == NULL || p - env >= (int)sizeof(dir)) return;
    memcpy(dir, env, p - env);
    dir[p - env] = 0;
    while (p != NULL) {
        if (atoi(p + 1) == vb) break;
        p = strchr(p + 1, ',');
    }
    if (p == NULL) return;
    snprintf(name, sizeof(name), "%s/data_%d.bin", dir, vb);
    if ((f = fopen(name, "wb")) != NULL) { fwrite(PS1_RAM(0x8004FC00), 1, 0x800, f); fclose(f); }
    snprintf(name, sizeof(name), "%s/bss_%d.bin", dir, vb);
    if ((f = fopen(name, "wb")) != NULL) { fwrite(PS1_RAM(0x80061B00), 1, 0x1500, f); fclose(f); }
    snprintf(name, sizeof(name), "%s/spuram_%d.bin", dir, vb);
    if ((f = fopen(name, "wb")) != NULL) { fwrite(PsxSpu_Ram, 1, PSXSPU_RAM_SIZE, f); fclose(f); }
    printf("[snd] dump at VBlank %d to %s\n", vb, dir);
}

void Snd_HwVBlank(void) {
    dma4_deliver();
    debug_dump();
}


static uint32_t hw_read(uint32_t a, int size) {
    dma4_deliver();
    if (a >= 0x1F801C00u && a < 0x1F802000u) {
        uint32_t off = a - 0x1F801C00u;
        if (size == 4) return PsxSpu_Read16(off) | (uint32_t)PsxSpu_Read16(off + 2) << 16;
        return PsxSpu_Read16(off);
    }
    switch (a) {
    case 0x1F8010C0: return dma_madr;
    case 0x1F8010C4: return dma_bcr;
    case 0x1F8010C8: return dma_chcr;
    case 0x1F8010F0: return dma_dpcr;
    case 0x1F8010F4: return dma_dicr;
    case 0x1F801014: return spu_delay;
    case 0x1F801020: return com_delay;
    }
    PSYQ_LOG("hardware read 0x%08X not modelled", a);
    return 0;
}

static void hw_write(uint32_t a, uint32_t v, int size) {
    if (a >= 0x1F801C00u && a < 0x1F802000u) {
        uint32_t off = a - 0x1F801C00u;
        PsxSpu_Write16(off, (uint16_t)v);
        if (size == 4) PsxSpu_Write16(off + 2, (uint16_t)(v >> 16));
        return;
    }
    switch (a) {
    case 0x1F8010C0: dma_madr = v; return;
    case 0x1F8010C4: dma_bcr = v; return;
    case 0x1F8010C8:
        dma_chcr = v;
        if (v & 0x01000000u) dma4_run();
        return;
    case 0x1F8010F0: dma_dpcr = v; return;
    case 0x1F8010F4:
        /* bits 24-30 acknowledge on write 1 */
        dma_dicr = (dma_dicr & 0xFF000000u & ~(v & 0x7F000000u)) | (v & 0x00FFFFFFu);
        return;
    case 0x1F801014: spu_delay = v; return;
    case 0x1F801020: com_delay = v; return;
    }
    PSYQ_LOG("hardware write 0x%08X = 0x%X not modelled", a, v);
}

uint32_t Snd_R32(uint32_t a) {
    uint32_t v;
    if (is_hw(a)) return hw_read(a, 4);
    memcpy(&v, is_ram(a) ? PS1_RAM(a) : SND_PTR(a), 4);
    return v;
}

uint32_t Snd_R16(uint32_t a) {
    uint16_t v;
    if (is_hw(a)) return hw_read(a, 2) & 0xFFFF;
    memcpy(&v, is_ram(a) ? PS1_RAM(a) : SND_PTR(a), 2);
    return v;
}

uint32_t Snd_R8(uint32_t a) {
    if (is_hw(a)) return hw_read(a & ~1u, 2) >> ((a & 1) * 8) & 0xFF;
    return *(uint8_t *)(is_ram(a) ? PS1_RAM(a) : SND_PTR(a));
}

void Snd_W32(uint32_t a, uint32_t v) {
    if (is_hw(a)) { hw_write(a, v, 4); return; }
    memcpy(is_ram(a) ? PS1_RAM(a) : SND_PTR(a), &v, 4);
}

void Snd_W16(uint32_t a, uint32_t v) {
    uint16_t h = (uint16_t)v;
    if (is_hw(a)) { hw_write(a, h, 2); return; }
    memcpy(is_ram(a) ? PS1_RAM(a) : SND_PTR(a), &h, 2);
}

void Snd_W8(uint32_t a, uint32_t v) {
    if (is_hw(a)) { PSYQ_LOG("hardware byte write 0x%08X", a); return; }
    *(uint8_t *)(is_ram(a) ? PS1_RAM(a) : SND_PTR(a)) = (uint8_t)v;
}

/* --- libapi / libetc services ------------------------------------------------------------ */

int Psx_GetVideoMode(void) { return 0; /* NTSC */ }
int Psx_EnterCriticalSection(void) { return 1; }
void Psx_ExitCriticalSection(void) {}

/* Events: the one libspu opens (DMA done, class 0xF0000009 spec 0x20) is delivered by the
 * DMA channel 4 handler (_spu_FiDMA -> DeliverEvent). TestEvent / WaitEvent first let a pending
 * DMA completion interrupt run (time passes while the CPU waits). */
static struct { int desc, spec, fired, used; } events[8];

int Psx_OpenEvent(int desc, int spec, int mode, uint32_t func) {
    int i;
    PSYQ_LOG("0x%X, 0x%X, 0x%X, 0x%X", desc, spec, mode, func);
    for (i = 0; i < 8; i++) {
        if (!events[i].used) {
            events[i].used = 1;
            events[i].desc = desc;
            events[i].spec = spec;
            events[i].fired = 0;
            return (int)(0xF1000000u + i);
        }
    }
    return -1;
}

int Psx_EnableEvent(int event) { (void)event; return 1; }

void Psx_DeliverEvent(int ev1, int ev2) {
    int i;
    for (i = 0; i < 8; i++)
        if (events[i].used && events[i].desc == ev1 && events[i].spec == ev2) events[i].fired = 1;
}

int Psx_TestEvent(int event) {
    int i = event & 7;
    dma4_deliver();
    if ((uint32_t)event - 0xF1000000u >= 8 || !events[i].fired) return 0;
    events[i].fired = 0;
    return 1;
}

int Psx_WaitEvent(int event) {
    int i = event & 7;
    dma4_deliver();
    if ((uint32_t)event - 0xF1000000u < 8) {
        if (!events[i].fired) PSYQ_LOG("WaitEvent 0x%X: event never delivered", event);
        events[i].fired = 0;
    }
    return 1;
}

uint32_t Psx_DMACallback(int dma, uint32_t func) {
    uint32_t old = 0;
    PSYQ_LOG("%d, 0x%X", dma, func);
    if (dma == 4) {
        old = dma4_callback;
        dma4_callback = func;
    }
    return old;
}

uint32_t Psx_InterruptCallback(int irq, uint32_t func) {
    PSYQ_LOG("%d, 0x%X (SPU IRQ not modelled)", irq, func);
    return 0;
}

int Psx_VSyncCallback(uint32_t func) {
    PSYQ_LOG("0x%X ignored (libsnd tick runs from SsSeqCalledTbyT)", func);
    return 0;
}

void Psx_ResetCallback(void) {}
int Psx_SetRCnt(int spec, int target, int mode) { PSYQ_LOG("0x%X, %d, 0x%X", spec, target, mode); return 1; }
int Psx_ResetRCnt(int spec) { (void)spec; return 1; }

void Psx_printf(uint32_t fmt, ...) {
    /* retail format strings are retail addresses: print the string and the raw arguments */
    va_list ap;
    const char *s = is_ram(fmt) ? (const char *)PS1_RAM(fmt) : (const char *)SND_PTR(fmt);
    va_start(ap, fmt);
    printf("[snd] ");
    vprintf(s, ap);
    va_end(ap);
}
