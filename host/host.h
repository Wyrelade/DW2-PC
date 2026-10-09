#ifndef HOST_HOST_H
#define HOST_HOST_H

/* Host layer (SDL3). The game C and the Psy-Q layer call the hooks below in the native build
 * (DW2_NATIVE); SDL types stay in host/host_sdl.h. With a visible window the game runs on its own
 * thread and the window on the main thread (PG.10 b3, host/main.c); headless runs use one. */

/* Ovl_Load: all overlays are linked; restore overlay `id`'s initial .data and zero its .bss
 * (what the retail file copy over the overlay area did). id = Ovl_FileIds index. */
void Host_OvlReset(int id);

/* Sys_Main's spin on Sys_FlipPending: one paced host VBlank per call (host/main.c). */
void Host_WaitVBlank(void);

/* host/main.c, on the game thread: SDL init (window, renderer, gamepads, audio; done by the main
 * thread when there is a game thread), then the VBlank clock starts. no_window: SDL dummy video
 * and audio drivers (headless test runs). host/sdl.c: event pump, present, shutdown. */
void Host_Init(int no_window);
void Host_Shutdown(void);
/* Clean shutdown from anywhere (window closed, Esc, --vblanks reached), then exit(0). */
void Host_Quit(const char *why);

/* host/vblank.c: the 59.94 Hz VBlank clock. Sleeps to the next deadline, then runs each due
 * VBlank (Psyq_VBlank: VSync(-1) counter + Sys_VSyncHandler), publishes the display area for the
 * window, takes the window's requests and input, and feeds audio. libetc's VSync waits and Host_WaitVBlank use it. */
void Host_VBlank(void);
/* --fast: no pacing, each Host_VBlank runs exactly one VBlank at once. */
void Host_ClockFast(void);
/* host/trace.c: logs game mode changes at VBlank wait `wait` (dev log). */
void Host_TraceTick(unsigned int wait);
/* PR.10, game thread: 1 while the title / main menu scene runs (game mode 0x401, stag1000). */
int Host_OnTitle(void);
/* host/trace.c: PG.3 per-scene 16:9 rule (pillarbox for 2D-only scenes), at each VBlank wait. */
void Host_SceneTick(void);
/* VBlanks run so far (the PS1 VSync count; a 30 fps scene runs two per wait). */
unsigned long long Host_VBlankCount(void);
/* VBlanks run so far and the measured rate since the clock started. */
void Host_LogRate(const char *what);

/* host/main.c, PR.4: 1 when the STR movies play (a window, or --movies); 0 for headless test
 * runs, where libcd's P1.10 stub ends each movie on its first frame. */
int Host_MoviesOn(void);
/* host/main.c: dev option --start-mode N, the game mode Sys_Main starts in (0: the title, 0x402). */
int Host_StartMode(void);
/* host/main.c: libgpu's SetDispMask(1). The first time (the boot image is in VRAM): saves the
 * "boot" screenshot when screenshots are on and holds the picture --hold-boot N VBlanks (dev
 * option; on the PS1 the CD loads after it take that long, here they are instant). */
void Host_DisplayOn(void);
/* F12 (PR.22): the picture the window shows, one PNG <dir>/dw2_<date>_<time>_N.png in
 * screenshots/ next to the exe (or --shot-dir). */
void Host_ShotKey(void);
/* host/sdl.c, any thread: the next Host_Present writes the game picture as the window shows it
 * (scale, 16:9, sharpening, letterbox bars cropped, no UI layer) to path, then a notice. */
void Host_WindowShot(const char *path);
/* host/shot.c: <dir>/<tag>_display.png (the display area) and <tag>_vram.png (1024x512). */
void Host_SaveShot(const char *dir, const char *tag);

/* host/sdl.c: PG.10b HD renderer before Host_Init: 0 automatic (GPU with a window, software
 * headless), 1 software, 2 GPU (also headless: hidden window). */
void Host_SetRenderer(int choice);
/* host/sdl.c: PG.2 no-wobble HD geometry on / off (the GTE's precise hook and the HD path). */
void Host_SetPgxp(int on);
/* host/sdl.c: PR.2b sharpening of the HD picture, 0..100 (0 off; F8 toggles back to the last). */
void Host_SetSharpen(int strength);
/* host/sdl.c: PG.3 16:9 on / off (wide HD surfaces, 16:9 window picture). */
void Host_SetWide(int on);
/* PG.3, for the game C (DW2_NATIVE): extra screen pixels on each side of a picture `width` wide
 * in 16:9 (0 in 4:3), so culls can let objects into the sides; and a mark that the frame being
 * built is a 2D picture that keeps black sides (pillarbox). */
int Host_WideMargin(int width);
void Host_PillarboxFrame(void);

/* host/input.c: PS1 digital pad buttons held on `port` (0 or 1), active high, in the pad reply
 * bit order (PAD_* in host/host_sdl.h). Keyboard is port 0; gamepads take ports 0, 1 in order.
 * psyq/libpad.c writes them into the pad receive buffers each VBlank (P1.7). */
unsigned short Host_PadButtons(int port);
/* A controller on `port`: port 0 always (keyboard), port 1 while a gamepad is on it, a --press2
 * script exists (a scripted pad) or --pad2-keys is given. */
int Host_PadConnected(int port);
/* --pad2-keys dev option: port 1 counts as connected and Tab moves the keyboard between port 0
 * and port 1 (VS mode with one keyboard, P1.20). */
void Host_InputPad2Keys(void);
/* --press / --press2 dev options: hold `bits` on `port` from VBlank wait `at` for `len` waits
 * (headless input tests). Host_InputScriptTick runs at each VBlank wait. Returns 0 when the table
 * is full. */
int Host_InputScriptAdd(int port, unsigned int at, unsigned short bits, unsigned int len);
void Host_InputScriptTick(unsigned int wait);
/* "Start", "Down+Cross" ... (bit names as logged) -> mask, 0 if a name is unknown. */
unsigned short Host_PadParseButtons(const char *names);

/* host/pak.c: the game's disc files from dw2.pak (doc/PACK_FORMAT.md). Host_PakOpen opens the
 * pack (path, or NULL = dw2.pak next to the exe, in the user data folder, then
 * build/native/dw2.pak) and checks it against the compiled-in manifest; when there is none or it
 * fails, it builds one from the disc image (disc, or one found next to the exe / in the user data
 * folder, host/pakbuild.c) and exits with a message if that fails too. Host_PakSector fills body
 * with disc sector `lba` after its 4-byte header: subheader (8) + 2328 bytes (Form 1: the 2048
 * data bytes, then zeros) and returns the file id, or -1 (no file there; body is zero). */
void Host_PakOpen(const char *path, const char *disc, int no_window);
int Host_PakSector(int lba, unsigned char *body);
/* The file holding sector `lba` and its size in sectors, or -1 (and 0 sectors). */
int Host_PakFileAt(int lba, int *sectors);
#if DW2_DEV
/* Dev tools, main thread: file `id` (Form 1) whole, malloc'd (free it); NULL if not readable. */
void *Host_PakReadFile(int id, int *size);
#endif

/* host/card.c: memory card image files (raw 128 KB PS1 card images card1.mcd / card2.mcd in
 * the user data folder, or --save-dir). Host_CardLoad reads card `port` (0, 1) into buf: 1 read,
 * 0 no file, -1 wrong size or read error. Host_CardStore writes it (temp file + rename): 1 ok. */
void Host_CardSetDir(const char *dir);
int Host_CardLoad(int port, unsigned char *buf, int size);
int Host_CardStore(int port, const unsigned char *buf, int size);

#endif /* HOST_HOST_H */
