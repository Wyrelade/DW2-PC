#ifndef HOST_HOST_H
#define HOST_HOST_H

/* Host layer (SDL3, one thread). The game C and the Psy-Q layer call the hooks below in the
 * native build (DW2_NATIVE); SDL types stay in host/host_sdl.h. */

/* Ovl_Load: all overlays are linked; restore overlay `id`'s initial .data and zero its .bss
 * (what the retail file copy over the overlay area did). id = Ovl_FileIds index. */
void Host_OvlReset(int id);

/* Sys_Main's spin on Sys_FlipPending: one paced host VBlank per call (host/main.c). */
void Host_WaitVBlank(void);

/* host/sdl.c: SDL init (window, renderer, gamepads, audio), event pump, present, shutdown.
 * no_window: SDL dummy video and audio drivers (headless test runs). */
void Host_Init(int no_window);
void Host_Shutdown(void);
/* Clean shutdown from anywhere (window closed, Esc, --vblanks reached), then exit(0). */
void Host_Quit(const char *why);

/* host/vblank.c: the 59.94 Hz VBlank clock. Sleeps to the next deadline, then runs each due
 * VBlank (Psyq_VBlank: VSync(-1) counter + Sys_VSyncHandler), presents the display area,
 * pumps events and feeds audio. libetc's VSync waits and Host_WaitVBlank use it. */
void Host_VBlank(void);
/* --fast: no pacing, each Host_VBlank runs exactly one VBlank at once. */
void Host_ClockFast(void);
/* host/trace.c: logs game mode changes at VBlank wait `wait` (dev log). */
void Host_TraceTick(unsigned int wait);
/* VBlanks run so far (the PS1 VSync count; a 30 fps scene runs two per wait). */
unsigned long long Host_VBlankCount(void);
/* VBlanks run so far and the measured rate since the clock started. */
void Host_LogRate(const char *what);

/* host/main.c: libgpu's SetDispMask(1). The first time (the boot image is in VRAM): saves the
 * "boot" screenshot when screenshots are on and holds the picture --hold-boot N VBlanks (dev
 * option; on the PS1 the CD loads after it take that long, here they are instant). */
void Host_DisplayOn(void);
/* F12: one screenshot pair into the --shot-dir directory (default scratchpad/shots). */
void Host_ShotKey(void);
/* host/shot.c: <dir>/<tag>_display.png (the display area) and <tag>_vram.png (1024x512). */
void Host_SaveShot(const char *dir, const char *tag);

/* host/input.c: PS1 digital pad buttons held on `port` (0 or 1), active high, in the pad reply
 * bit order (PAD_* in host/host_sdl.h). Keyboard is port 0; gamepads take ports 0, 1 in order.
 * psyq/libpad.c writes them into the pad receive buffers each VBlank (P1.7). */
unsigned short Host_PadButtons(int port);
/* A controller on `port`: port 0 always (keyboard), port 1 while a gamepad is on it. */
int Host_PadConnected(int port);
/* --press dev option: hold `bits` on port 0 from VBlank wait `at` for `len` waits (headless
 * input tests). Host_InputScriptTick runs at each VBlank wait. Returns 0 when the table is full. */
int Host_InputScriptAdd(unsigned int at, unsigned short bits, unsigned int len);
void Host_InputScriptTick(unsigned int wait);
/* "Start", "Down+Cross" ... (bit names as logged) -> mask, 0 if a name is unknown. */
unsigned short Host_PadParseButtons(const char *names);

/* host/pak.c: the game's disc files from dw2.pak (doc/PACK_FORMAT.md). Host_PakOpen opens the
 * pack (path, or NULL = dw2.pak next to the exe, then build/native/dw2.pak), checks it against
 * the compiled-in manifest and exits with a message on any problem. Host_PakSector fills body
 * with disc sector `lba` after its 4-byte header: subheader (8) + 2328 bytes (Form 1: the 2048
 * data bytes, then zeros) and returns the file id, or -1 (no file there; body is zero). */
void Host_PakOpen(const char *path, int no_window);
int Host_PakSector(int lba, unsigned char *body);
/* The file holding sector `lba` and its size in sectors, or -1 (and 0 sectors). */
int Host_PakFileAt(int lba, int *sectors);

/* host/card.c: memory card image files (raw 128 KB PS1 card images card1.mcd / card2.mcd in
 * the user data folder, or --save-dir). Host_CardLoad reads card `port` (0, 1) into buf: 1 read,
 * 0 no file, -1 wrong size or read error. Host_CardStore writes it (temp file + rename): 1 ok. */
void Host_CardSetDir(const char *dir);
int Host_CardLoad(int port, unsigned char *buf, int size);
int Host_CardStore(int port, const unsigned char *buf, int size);

#endif /* HOST_HOST_H */
