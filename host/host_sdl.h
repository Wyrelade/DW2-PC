#ifndef HOST_HOST_SDL_H
#define HOST_HOST_SDL_H

/* Internal to host/: the parts that use SDL types. */

#include <SDL3/SDL.h>

/* PR.14: 32-bit Windows only promises a 4-byte aligned stack, and main() does not realign it,
 * but SDL3.dll's SSE code (e.g. the software renderer's linear stretch, scale_mat_SSE) keeps
 * 16-byte locals on the stack and faulted. Functions entered from outside our code (main, thread
 * entries, SDL callbacks) realign to 16 so every call into SDL gets an aligned stack. */
#if defined(__i386__)
#define HOST_ENTRY __attribute__((force_align_arg_pointer))
#else
#define HOST_ENTRY
#endif

/* PS1 digital pad buttons, bit order of the pad reply's two button bytes (the reply sends them
 * active low; these masks are active high). */
#define PAD_SELECT   0x0001
#define PAD_L3       0x0002
#define PAD_R3       0x0004
#define PAD_START    0x0008
#define PAD_UP       0x0010
#define PAD_RIGHT    0x0020
#define PAD_DOWN     0x0040
#define PAD_LEFT     0x0080
#define PAD_L2       0x0100
#define PAD_R2       0x0200
#define PAD_L1       0x0400
#define PAD_R1       0x0800
#define PAD_TRIANGLE 0x1000
#define PAD_CIRCLE   0x2000
#define PAD_CROSS    0x4000
#define PAD_SQUARE   0x8000

/* dw2.pak (doc/PACK_FORMAT.md), shared by host/pak.c and host/pakbuild.c. */
#define PAK_FILES 0xE5B
#define PAK_VERSION 1
#define PAK_HEADER_SIZE 0x50
#define PAK_ENTRY_SIZE 0x40
#define PAK_MAGIC "DW2PAK\x1a\0"
/* host/pak.c: the compiled-in manifest, the exe hash and the 0xE5B file hashes (exits if bad). */
void Pak_ParseManifest(Uint8 *exe_sha, Uint8 (*sha)[32]);
/* host/pakbuild.c, main thread, before the game window. Host_DiscFind: the disc image to build
 * from (`disc`, else the exe folder, else the user data folder; with a window and none found, a
 * file dialog); a malloc'd path (SDL_free) of an image whose SLUS_011.93 matches the manifest,
 * or NULL with the reason in err. Host_PakBuild: writes the pack from that image to `out` (or to
 * `fallback` when out's folder is not writable) through a .tmp file and a rename; 0 with the
 * path written in `built`, or -1 with the reason in err and no pack or .tmp left behind. */
char *Host_DiscFind(const char *disc, int no_window, char *err, size_t errlen);
int Host_PakBuild(const char *image, const char *out, const char *fallback, int no_window, char *built,
                  size_t builtlen, char *err, size_t errlen);

/* host/sdl.c. PG.10 b3: with a visible window the game runs on its own thread; the window side
 * (Host_InitWindow, Host_PumpEvents, Host_Present, Host_WindowLoop, Host_Shutdown) stays on the
 * main thread, Host_Publish and Host_GameEvents run on the game thread at each VBlank wait. */
void Host_SetThreaded(int on);
int Host_Threaded(void);
void Host_InitWindow(int no_window);
void Host_WindowLoop(void);
void Host_PumpEvents(void);
void Host_Present(void);
void Host_Publish(void);
void Host_GameEvents(void);

/* host/vblank.c */
void Host_ClockStart(void);
#if DW2_DEV
void Host_ClockStats(uint64_t *vblanks, uint64_t *flip_count, unsigned int *restart_count);
#endif

/* host/input.c */
void Host_InputDevice(const SDL_Event *e);
void Host_InputPress(const SDL_Event *e);
void Host_InputInit(void);  /* main thread, before the game thread reads input */
void Host_InputPoll(void);  /* main thread: keyboard / gamepad state after the event pump */
void Host_InputLatch(void); /* game thread, once per VBlank: the buttons the pad replies use */
void Host_InputClose(void);

/* host/audio.c */
void Host_AudioOpen(void);
void Host_AudioFeed(void);
void Host_AudioSetVolume(int volume); /* 0..100, main thread (PR.2) */
void Host_AudioClose(void);

/* host/sdl.c (PR.2): F1 window helpers, main thread */
void Host_RequestSetting(int id, int value);
const char *Host_RendererName(void);

/* host/sdl.c (PR.3): window modes (SET_WINDOW_*), main thread */
int Host_WindowMode(void);
int Host_WindowHeadless(void);
void Host_SetWindowMode(int mode);   /* applies it (the caller updates the setting) */
void Host_WindowModeRefresh(void);   /* fullscreen display / mode changed: applied again */

#endif /* HOST_HOST_SDL_H */
