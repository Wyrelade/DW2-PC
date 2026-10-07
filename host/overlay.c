#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "host/host.h"

#ifdef _WIN32
/* Overlay data ranges (PE). CMakeLists.txt relinks each overlay so its .data and .bss are the grouped
 * sections .data$dw2ovl_<unit>_1 and _2; the markers below are _0 and _3. The linker sorts
 * .data$* by name, so [start, end) holds exactly that overlay's .data and .bss. */
#define OVL_MARKERS(unit)                                                                \
    __attribute__((section(".data$dw2ovl_" #unit "_0"), aligned(16))) u8 Ovl_DataStart_##unit[1] = { 0 }; \
    __attribute__((section(".data$dw2ovl_" #unit "_3"))) u8 Ovl_DataEnd_##unit[1] = { 0 };
#define OVL_START(unit) Ovl_DataStart_##unit
#define OVL_END(unit) Ovl_DataEnd_##unit
#else
/* Overlay data ranges (ELF). CMakeLists.txt relinks each overlay so its .data and .bss are one
 * section dw2ovl_<unit>; the linker defines __start_ / __stop_ around a section with a C name. */
#define OVL_MARKERS(unit) extern u8 __start_dw2ovl_##unit[], __stop_dw2ovl_##unit[];
#define OVL_START(unit) __start_dw2ovl_##unit
#define OVL_END(unit) __stop_dw2ovl_##unit
#endif

OVL_MARKERS(stag0000)
OVL_MARKERS(stag1000)
OVL_MARKERS(stag1100)
OVL_MARKERS(stag2000)
OVL_MARKERS(stag3000)
OVL_MARKERS(stag3500)
OVL_MARKERS(stag4000)

/* Boot image: the exe's initial bytes of the retail overlay area (Ovl_LoadArea), a TIM at +4
 * that Sys_Main shows at boot. Extracted by splat (assets/Ovl_LoadArea.bin). */
INCLUDE_BIN(Ovl_LoadArea, "assets/Ovl_LoadArea.bin");

typedef struct {
    const char *name;
    u8 *start;
    u8 *end;
    u8 *pristine;
} OvlRange;

/* Indexed by overlay id (Ovl_FileIds order). */
#define OVL_RANGE(unit) { #unit, OVL_START(unit), OVL_END(unit), 0 }
static OvlRange ovl_ranges[7] = {
    OVL_RANGE(stag0000), OVL_RANGE(stag4000), OVL_RANGE(stag2000), OVL_RANGE(stag1000),
    OVL_RANGE(stag3000), OVL_RANGE(stag1100), OVL_RANGE(stag3500),
};

/* Before any game code runs: keep the initial bytes of every overlay range. */
void Host_OvlSnapshot(void) {
    int i;

    for (i = 0; i < 7; i++) {
        OvlRange *r = &ovl_ranges[i];
        size_t n = (size_t)(r->end - r->start);

        if (r->end <= r->start) {
            fprintf(stderr, "[host] overlay %s: bad data range %p..%p\n", r->name, (void *)r->start, (void *)r->end);
            exit(1);
        }
        r->pristine = malloc(n);
        memcpy(r->pristine, r->start, n);
        printf("[host] overlay %d %s: data+bss %p..%p (0x%X bytes)\n", i, r->name, (void *)r->start, (void *)r->end,
               (unsigned)n);
    }
}

void Host_OvlReset(int id) {
    OvlRange *r;

    if (id < 0 || id >= 7) {
        fprintf(stderr, "[host] Ovl_Load: bad overlay id %d\n", id);
        exit(1);
    }
    r = &ovl_ranges[id];
    memcpy(r->start, r->pristine, (size_t)(r->end - r->start));
    printf("[host] Ovl_Load(%d): %s data restored, bss zeroed\n", id, r->name);
    fflush(stdout);
}
