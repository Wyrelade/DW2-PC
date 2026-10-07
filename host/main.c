#ifndef _WIN32
#define _GNU_SOURCE /* MAP_32BIT */
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <sys/mman.h>
#include <ucontext.h>
#endif

#include "common.h"
#include <SDL3/SDL.h>

#include "host/host.h"
#include "psyq/psyq_log.h"

/* Native entry point: replaces crt0 (Sys_Start). Checks the memory layout, keeps the overlays'
 * initial data, starts the SDL3 host, then runs the game's Sys_Main (it never returns; the host
 * quits on window close or Esc).
 *
 *   dw2 [--pak PATH] [--vblanks N] [--no-window] [--shot-dir DIR] [--shot-at N]... [--shot-vb N]...
 *       [--hold-boot N] [--press N:BUTTONS[:LEN]]... [--press2 N:BUTTONS[:LEN]]... [--save-dir DIR]
 *       [--fast] [--pad2-keys]
 *     --pak PATH     the data pack (default dw2.pak next to the exe, then build/native/dw2.pak;
 *                    doc/PACK_FORMAT.md), checked before anything else runs
 *     --vblanks N    quit after N VBlank waits in the Sys_FlipPending spin (0 = run on)
 *     --no-window    SDL dummy video and audio drivers (headless test runs)
 *     --shot-dir DIR screenshots go to DIR (default scratchpad/shots): the boot image when the
 *                    display turns on (if any screenshot option is given), each --shot-at, F12
 *     --shot-at N    screenshot pair at VBlank wait N (repeatable, up to 16)
 *     --shot-vb N    screenshot pair at the first wait with N VBlanks run (repeatable, up to 16,
 *                    ascending; an emulator probe counts the same frames)
 *     --hold-boot N  keep the boot image on screen N VBlanks (dev option, Host_DisplayOn)
 *     --press N:BUTTONS[:LEN]  hold BUTTONS ("Start", "Down+Cross", names as in the [input]
 *                    log) on port 0 from VBlank wait N for LEN waits (default 4); repeatable,
 *                    for headless input tests
 *     --press2 N:BUTTONS[:LEN]  the same on port 1; any --press2 makes port 1 a connected pad
 *                    (VS mode with one keyboard, headless)
 *     --pad2-keys    port 1 counts as connected; Tab moves the keyboard between port 0 and port 1
 *                    (VS mode with one keyboard in the window)
 *     --save-dir DIR memory card images card1.mcd / card2.mcd in DIR instead of the user data
 *                    folder (%APPDATA%\DW2-Online\saves\ on Windows,
 *                    ~/.local/share/DW2-Online/saves/ on Linux)
 *     --fast         no 59.94 Hz pacing: one VBlank per wait, as fast as the host runs (headless
 *                    test runs; same frame sequence as a paced run without catch-up VBlanks) */

extern void Sys_Main(void);
extern void Host_OvlSnapshot(void);
extern void Snd_NativeInit(void);
extern u8 Ovl_LoadArea[];
extern s32 Sys_FlipPending;

static unsigned int max_vblanks;
static unsigned int vblanks;
static const char *shot_dir;
static unsigned int shot_at[16];
static int shot_count;
static unsigned long long shot_vb[16];
static int shot_vb_count, shot_vb_done;
static int hold_boot;

static const char *shots(void) {
    static int made;

    if (shot_dir == NULL) {
        shot_dir = "scratchpad/shots";
    }
    if (!made) {
        made = 1;
        SDL_CreateDirectory(shot_dir);
    }
    return shot_dir;
}

void Host_ShotKey(void) {
    static int n;
    char tag[32];

    snprintf(tag, sizeof(tag), "f12_%d_wait%u", n++, vblanks);
    Host_SaveShot(shots(), tag);
}

void Host_DisplayOn(void) {
    static int done;
    int i;

    if (done) {
        return;
    }
    done = 1;
    if (shot_dir != NULL || shot_count != 0) {
        Host_SaveShot(shots(), "boot");
    }
    if (hold_boot > 0) {
        printf("[host] boot image held for %d VBlanks (--hold-boot)\n", hold_boot);
        for (i = 0; i < hold_boot; i++) {
            Host_VBlank();
        }
    }
}

/* The image (globals, Ps1_Ram with the heap) must sit in one 16 MB window for the 24-bit OT links
 * (psyq/ps1mem.h): linked at a 16 MB-aligned base (CMakeLists.txt) and smaller than 16 MB.
 * The game C also keeps pointers in 32-bit ints (P1.12): every address it can see, the window
 * and the stack it runs on, must be below 2 GB so that the int gives the pointer back (zero or
 * sign extended alike). */
static void check_window(void) {
    uintptr_t base = (uintptr_t)Ps1_Ram & ~(uintptr_t)0xFFFFFF;
    const void *probes[] = { Ps1_Ram, Ps1_Ram + PS1_RAM_SIZE - 1, Ps1_Scratchpad, Ovl_LoadArea, &Sys_FlipPending,
                             (const void *)Sys_Main };
    volatile int stack_probe = 0;
    size_t i;

    for (i = 0; i < sizeof(probes) / sizeof(probes[0]); i++) {
        if (((uintptr_t)probes[i] & ~(uintptr_t)0xFFFFFF) != base) {
            fprintf(stderr, "[host] %p is outside the 16 MB window at 0x%08lX\n", probes[i], (unsigned long)base);
            exit(1);
        }
    }
    if (base >= 0x80000000u || (uintptr_t)&stack_probe >= 0x80000000u) {
        fprintf(stderr, "[host] window 0x%08lX or stack %p is not below 2 GB\n", (unsigned long)base,
                (void *)&stack_probe);
        exit(1);
    }
    printf("[host] 16 MB window 0x%08lX: Ps1_Ram %p, heap %p..%p\n", (unsigned long)base, (void *)Ps1_Ram,
           PS1_RAM(0x80075000), PS1_RAM(0x801FF000));
}

void Host_WaitVBlank(void) {
    int i;

    if (vblanks == 0) {
        printf("[host] first VBlank wait (Sys_FlipPending spin) reached after %u Psy-Q calls\n", Psyq_CallCount);
        fflush(stdout);
    }
    vblanks++;
    Host_TraceTick(vblanks);
    Host_InputScriptTick(vblanks);
    for (i = 0; i < shot_count; i++) {
        if (shot_at[i] == vblanks) {
            char tag[32];

            snprintf(tag, sizeof(tag), "wait%u", vblanks);
            Host_SaveShot(shots(), tag);
        }
    }
    /* --shot-vb: by VBlank count, the frame count an emulator probe sees (the shots come in order) */
    while (shot_vb_done < shot_vb_count && Host_VBlankCount() >= shot_vb[shot_vb_done]) {
        char tag[32];

        snprintf(tag, sizeof(tag), "vb%llu", shot_vb[shot_vb_done++]);
        Host_SaveShot(shots(), tag);
    }
    if (max_vblanks != 0 && vblanks > max_vblanks) {
        printf("[host] stop after %u VBlank waits (%u Psy-Q calls)\n", max_vblanks, Psyq_CallCount);
        Host_Quit("--vblanks");
    }
    Host_VBlank();
}

/* --press / --press2 N:BUTTONS[:LEN] */
static int parse_press(int port, const char *arg) {
    char names[64];
    unsigned int at, len = 4;
    const char *c1 = strchr(arg, ':');
    const char *c2;
    size_t n;
    unsigned short bits;

    if (c1 == NULL) {
        return 0;
    }
    at = (unsigned int)strtoul(arg, NULL, 0);
    c2 = strchr(c1 + 1, ':');
    n = c2 != NULL ? (size_t)(c2 - (c1 + 1)) : strlen(c1 + 1);
    if (n == 0 || n >= sizeof(names)) {
        return 0;
    }
    memcpy(names, c1 + 1, n);
    names[n] = '\0';
    if (c2 != NULL) {
        len = (unsigned int)strtoul(c2 + 1, NULL, 0);
    }
    bits = Host_PadParseButtons(names);
    return bits != 0 && len != 0 && Host_InputScriptAdd(port, at, bits, len);
}

static const char *pak = NULL;
static int no_window = 0;

/* Everything from the layout check on: the game's own call stack. */
static void game_main(void) {
    check_window();
    Host_PakOpen(pak, no_window);
    Host_OvlSnapshot();
    Snd_NativeInit();
    Host_Init(no_window);
    printf("[host] Sys_Main\n");
    fflush(stdout);
    Sys_Main();
    Host_Quit("Sys_Main returned");
}

#ifndef _WIN32
/* Linux: the main thread's stack lies far above 4 GB, but the game keeps stack addresses in
 * 32-bit ints (Task_Create(id, slot, (s32)&local), P1.12). The game runs on a stack mapped below
 * 2 GB (MAP_32BIT), entered with a context switch on the same thread. */
#define GAME_STACK_SIZE (8u << 20)

static ucontext_t main_ctx, game_ctx;

static void run_on_low_stack(void) {
    void *stack = mmap(NULL, GAME_STACK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT,
                       -1, 0);

    if (stack == MAP_FAILED) {
        perror("[host] mmap game stack");
        exit(1);
    }
    getcontext(&game_ctx);
    game_ctx.uc_stack.ss_sp = stack;
    game_ctx.uc_stack.ss_size = GAME_STACK_SIZE;
    game_ctx.uc_link = &main_ctx;
    makecontext(&game_ctx, game_main, 0);
    swapcontext(&main_ctx, &game_ctx);
}
#endif

int main(int argc, char **argv) {
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--vblanks") == 0 && i + 1 < argc) {
            max_vblanks = (unsigned int)strtoul(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--pak") == 0 && i + 1 < argc) {
            pak = argv[++i];
        } else if (strcmp(argv[i], "--no-window") == 0) {
            no_window = 1;
        } else if (strcmp(argv[i], "--shot-dir") == 0 && i + 1 < argc) {
            shot_dir = argv[++i];
        } else if (strcmp(argv[i], "--shot-at") == 0 && i + 1 < argc && shot_count < 16) {
            shot_at[shot_count++] = (unsigned int)strtoul(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--shot-vb") == 0 && i + 1 < argc && shot_vb_count < 16) {
            shot_vb[shot_vb_count++] = strtoull(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--hold-boot") == 0 && i + 1 < argc) {
            hold_boot = (int)strtol(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--press") == 0 && i + 1 < argc && parse_press(0, argv[++i])) {
        } else if (strcmp(argv[i], "--press2") == 0 && i + 1 < argc && parse_press(1, argv[++i])) {
        } else if (strcmp(argv[i], "--pad2-keys") == 0) {
            Host_InputPad2Keys();
        } else if (strcmp(argv[i], "--fast") == 0) {
            Host_ClockFast();
        } else if (strcmp(argv[i], "--save-dir") == 0 && i + 1 < argc) {
            Host_CardSetDir(argv[++i]);
        } else {
            fprintf(stderr,
                    "usage: %s [--pak PATH] [--vblanks N] [--no-window] [--shot-dir DIR] [--shot-at N]... "
                    "[--shot-vb N]... [--hold-boot N] [--press N:BUTTONS[:LEN]]... [--press2 N:BUTTONS[:LEN]]... "
                    "[--save-dir DIR] [--fast] [--pad2-keys]\n",
                    argv[0]);
            return 2;
        }
    }
    setvbuf(stdout, NULL, _IOLBF, 1 << 16);
#ifdef _WIN32
    game_main();
#else
    run_on_low_stack();
#endif
    return 0;
}
