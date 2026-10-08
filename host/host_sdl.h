#ifndef HOST_HOST_SDL_H
#define HOST_HOST_SDL_H

/* Internal to host/: the parts that use SDL types. */

#include <SDL3/SDL.h>

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
void Host_AudioClose(void);

#endif /* HOST_HOST_SDL_H */
