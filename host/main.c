#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "host/host.h"
#include "psyq/psyq_log.h"

/* Native entry point: replaces crt0 (Sys_Start). Checks the memory layout, keeps the overlays'
 * initial data, starts the SDL3 host, then runs the game's Sys_Main (it never returns; the host
 * quits on window close or Esc).
 *
 *   dw2 [--pak PATH] [--vblanks N] [--no-window]
 *     --pak PATH    the data pack (default dw2.pak next to the exe, then build/native/dw2.pak;
 *                   doc/PACK_FORMAT.md), checked before anything else runs
 *     --vblanks N   quit after N VBlank waits in the Sys_FlipPending spin (0 = run on)
 *     --no-window   SDL dummy video and audio drivers (headless test runs) */

extern void Sys_Main(void);
extern void Host_OvlSnapshot(void);
extern u8 Ovl_LoadArea[];
extern s32 Sys_FlipPending;

static unsigned int max_vblanks;
static unsigned int vblanks;

/* The image (globals, Ps1_Ram with the heap) must sit in one 16 MB window for the 24-bit OT links
 * (psyq/ps1mem.h): linked at a 16 MB-aligned base (CMakeLists.txt) and smaller than 16 MB. */
static void check_window(void) {
    uintptr_t base = (uintptr_t)Ps1_Ram & ~(uintptr_t)0xFFFFFF;
    const void *probes[] = { Ps1_Ram, Ps1_Ram + PS1_RAM_SIZE - 1, Ps1_Scratchpad, Ovl_LoadArea, &Sys_FlipPending,
                             (const void *)Sys_Main };
    size_t i;

    for (i = 0; i < sizeof(probes) / sizeof(probes[0]); i++) {
        if (((uintptr_t)probes[i] & ~(uintptr_t)0xFFFFFF) != base) {
            fprintf(stderr, "[host] %p is outside the 16 MB window at 0x%08lX\n", probes[i], (unsigned long)base);
            exit(1);
        }
    }
    printf("[host] 16 MB window 0x%08lX: Ps1_Ram %p, heap %p..%p\n", (unsigned long)base, (void *)Ps1_Ram,
           PS1_RAM(0x80075000), PS1_RAM(0x801FF000));
}

void Host_WaitVBlank(void) {
    if (vblanks == 0) {
        printf("[host] first VBlank wait (Sys_FlipPending spin) reached after %u Psy-Q calls\n", Psyq_CallCount);
        fflush(stdout);
    }
    vblanks++;
    if (max_vblanks != 0 && vblanks > max_vblanks) {
        printf("[host] stop after %u VBlank waits (%u Psy-Q calls)\n", max_vblanks, Psyq_CallCount);
        Host_Quit("--vblanks");
    }
    Host_VBlank();
}

int main(int argc, char **argv) {
    const char *pak = NULL;
    int no_window = 0;
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--vblanks") == 0 && i + 1 < argc) {
            max_vblanks = (unsigned int)strtoul(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--pak") == 0 && i + 1 < argc) {
            pak = argv[++i];
        } else if (strcmp(argv[i], "--no-window") == 0) {
            no_window = 1;
        } else {
            fprintf(stderr, "usage: %s [--pak PATH] [--vblanks N] [--no-window]\n", argv[0]);
            return 2;
        }
    }
    setvbuf(stdout, NULL, _IOLBF, 1 << 16);
    check_window();
    Host_PakOpen(pak, no_window);
    Host_OvlSnapshot();
    Host_Init(no_window);
    printf("[host] Sys_Main\n");
    fflush(stdout);
    Sys_Main();
    Host_Quit("Sys_Main returned");
    return 0;
}
