# Psy-Q API surface

Every Psy-Q library function the game C calls (main + the 7 overlays), with its call sites, what the game uses it
for and what it touches. This is the to-do list for the PC layer (P1): each entry must be provided by the port,
the game C keeps calling it by the same name. The gte.h macros, the Psy-Q data the game reads and the game's own
wrapper modules are listed too, so the shim boundary is clear.

Method: the built objects of the matching build (`build/USA/src/**/*.c.o`, all game C except `main/psyq.c` and
`stag1000/stag1000_libpress.c`, which hold the Psy-Q asm). A function counts when an object has a relocation to it
and it is in `configs/USA/psyq_funcs.txt`. Calls = `jal` relocations (all references are calls; no Psy-Q function
is taken by address). Callers = the enclosing function of each relocation. The title column comes from a call graph
over the main and stag1000 objects (code and data relocations, task descriptors followed, `Task_DescTable` not):

- `T`: reached from boot (`Sys_Main`, `Sys_VSyncHandler`, `Sys_GameModeTask`) and the stag1000 setup and title tasks
  (`Stg10_StageSetupDesc`, `Stg10_TitleDesc`). This is the title screen prototype (boot main + stag1000, no movie).
- `M`: reached from the stag1000 movie task (`Stg10_MovieDesc`). Retail boots into game mode 0x402 = the intro movie
  (file 0x282), then 0x401 = title.

## Count

- **109 Psy-Q functions** are referenced from the C objects (269 call sites). One of them, `InitHeap`, is called only
  by crt0 (`Sys_Start`, hand asm in `src/main/asm/crt0/Sys_Start.s`, built into `main/156C.c`), so the game proper calls
  **108**. `Card_CloseFile` is a Psy-Q function under a decomp name (libmcrd, most likely `MemCardClose`).
  The older estimate of 107 (decomp R6) is replaced by these numbers.
- 4 Psy-Q data symbols are read: `GsWSMATRIX`, `D_800619A8`, `StCdIntrFlag`, and crt0's `D_8004FC10`.
- 20 gte.h macros, 63 uses in 9 functions, all in `main/model.c`. No overlay uses a GTE macro.
- Psy-Q code calls back into the game only through the callbacks the game registers (below) and crt0's `jal Sys_Main`.

| Library | Functions | Calls | Title (T) | Movie (M) | What it is |
|---|---|---|---|---|---|
| libgpu | 17 | 59 | 13 | 4 | GPU: VRAM, OT, draw / display environments, packets |
| libgs | 12 | 38 | 3 | 0 | GS layer: graph init, coordinates, view, lights, TIM header |
| libgte | 14 | 34 | 5 | 0 | GTE math: matrices, rotation, perspective, sin / cos / atan |
| libcd | 19 | 74 | 10 | 10 | CD: commands, sector reads by interrupt, STR streaming |
| libetc | 3 | 8 | 3 | 0 | VSync, VBlank callback, interrupt reset |
| libsnd | 21 | 24 | 21 | 0 | Sequencer and VAB banks (libsnd over libspu) |
| libmcrd | 11 | 13 | 2 | 0 | Memory card file ops (libmcrd / libcard task stack) |
| libpad | 3 | 3 | 3 | 0 | SIO pad driver |
| libpress | 5 | 7 | 0 | 5 | MDEC: VLC and DCT decode (stag1000 movies) |
| libc2 | 3 | 8 | 1 | 0 | memcpy, memset, strcpy |
| libapi | 1 | 1 | 0 | 0 | InitHeap (crt0 only) |
| total | 109 | 269 | 61 | 19 | |

## Shim boundary

The PC layer provides the functions in this file and nothing below them. Everything in `src/main/psyq.c` and
`src/stag1000/stag1000_libpress.c` (540 + 18 functions as asm, 558 entries in `psyq_funcs.txt` with crt0) and the
Psy-Q data blocks goes away on PC. Several of those carry decomp names that look like
game code but are Psy-Q internals: the `Pad_*` SIO driver (`Pad_InitDriverHooks`, `Pad_SioExchangeByte`, ...),
`Cd_IntrCallback`, `Cd_StartDma`, `Cd_ClearStreamSlots`, the `Card_*` task stack (`Card_PushTask`, `Card_OnHwIoe`, ...),
`Gfx_SetLightColorMatrix` / `Gfx_GetLightColorMatrix`, `Math_MakeAxisRotMatrix`, `Debug_*`, and the data
`Sys_VSyncCallbacks`, `Sys_DmaCallbacks`, `Snd_SeqScores`, `Snd_MarkCallbacks`, `Card_TaskWork`. No game C calls them.

The callers are game C modules; most libraries have only a few:

| Library | Calling modules |
|---|---|
| libgpu | `main/anim`, `main/faceslot`, `main/gpu`, `main/ot`, `main/sys`, `main/texslot`, `stag0000/font`, `stag1000/movie`, `stag1000/stag1000`, `stag3500/textrect`, `stag4000/automap` |
| libgs | `main/anim`, `main/digistatus`, `main/gpu`, `main/sys`, `stag0000/camera`, `stag2000/camera`, `stag3000/camera`, `stag3500/camera`, `stag4000/camera`, `stag4000/obj` |
| libgte | `main/anim`, `main/digistatus`, `main/gpu`, `main/model`, `main/parts`, `main/sys`, `stag0000/camera`, `stag2000/camera`, `stag2000/mapbg`, `stag2000/staticbg`, `stag3000/camera`, `stag3500/camera`, `stag4000/camera`, `stag4000/floor`, `stag4000/player` |
| libcd | `main/cd`, `main/cdread`, `main/sys`, `stag0000/xaplay`, `stag1000/movie`, `stag2000/xastream`, `stag3000/xaplay`, `stag3500/xaplay` |
| libetc | `main/sys` |
| libsnd | `main/sound`, `main/sys` |
| libmcrd | `main/sys`, `stag1100/card` |
| libpad | `main/pad` |
| libpress | `stag1000/movie` |
| libc2 | `main/gamemode`, `stag1100/card`, `stag1100/cardmenu`, `stag3500/battle`, `stag4000/dungfile` |

- Frame loop and flip: `main/sys.c` (`Sys_Main`, `Sys_VSyncHandler`), `main/gpu.c`, `main/ot.c`, `main/primbuf.c`.
- Drawing: overlays draw through main (`Gfx_*` in model.c, parts.c, anim.c, texslot.c, faceslot.c; `Text_*` in text.c).
  The exceptions that call libgpu / libgs / libgte themselves: the per-overlay camera tasks (`GsSetRefView2`,
  `GsSetProjection`, `RotMatrixYXZ`), stag2000 backgrounds (`SetGeomOffset`), stag4000 floor and automap,
  stag0000 font, stag3500 textrect, the stag1000 movie. Several of them also build GPU packets themselves (below).
- CD: `main/cd.c` (file queue, cache), `main/cdread.c` (async sector reads), `main/cdpreload.c`; XA: `xaplay.c`
  (stag0000, stag3000, stag3500, same code) and `stag2000/xastream.c`; STR: `stag1000/movie.c`.
- Sound: `main/sound.c` (`Snd_Init`, 3 bank slots, `Snd_PlayById`) plus the sequencer tick in `Sys_VSyncHandler`.
- Pad: `main/pad.c` (`Pad_Init`, `Pad_PollPort`, `Pad_Update` into `Pad_State`).
- Memory card: `stag1100/card.c` (`Stg11_CardAsyncOp`, `Stg11_CardFileOp`, the card task).

## Functions by library

Columns: prototype as in the Psy-Q 4.7 headers; calls (`jal` count); callers (file and function); use; data or
hardware touched on the PS1; T / M as above.

### libgpu (17)

PC plan: Emulated PS1 GPU (backend/): 1024x512 16-bit VRAM, GP0 packet rasterizer walking the OT, DrawEnv / DispEnv state, present the display area. Exact look; the modern renderer comes later behind Gfx_ / Text_ (P2.7).

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `ResetGraph` | `int ResetGraph(int mode)` | 4 | main/gpu Gpu_ClearScreens<br>main/sys Sys_Main<br>stag1000/movie Stg10_MovieDestroy<br>stag1000/stag1000 Stg10_StageSetup | Boot reset (0); Gpu_ClearScreens and stag1000 scene / movie reset (1). | GPU, DMA ch2, GPU callbacks | T M |
| `SetGraphDebug` | `int SetGraphDebug(int level)` | 1 | main/sys Sys_Main | Boot: level 0. | libgpu .data | T |
| `SetDispMask` | `void SetDispMask(int mask)` | 2 | main/sys Sys_Main | Boot: display off, on after the boot image. | GP1 display enable | T |
| `DrawSync` | `int DrawSync(int mode)` | 7 | main/gpu Gpu_ClearScreens<br>main/sys Sys_Main<br>stag1000/movie Stg10_MovieDestroy<br>stag1000/movie Stg10_StrCallback<br>stag1000/stag1000 Stg10_StageSetup | Waits for the GPU after clears and uploads, and once per frame in the Sys_Main loop. | GPU queue, DMA | T M |
| `ClearImage` | `int ClearImage(RECT *rect, u_char r, u_char g, u_char b)` | 1 | main/sys Sys_Main | Boot: clears VRAM 640x511. | VRAM fill | T |
| `ClearImage2` | `int ClearImage2(RECT *rect, u_char r, u_char g, u_char b)` | 3 | main/gpu Gpu_ClearScreens<br>stag1000/movie Stg10_MovieDestroy<br>stag1000/stag1000 Stg10_StageSetup | Clears all of VRAM (1024x512) at stag1000 setup, Gpu_ClearScreens, movie end. | VRAM fill (interlace variant) | T M |
| `LoadImage` | `int LoadImage(RECT *rect, u_long *p)` | 10 | main/faceslot Gfx_FindOrLoadImageSlot<br>main/sys Sys_Main<br>main/texslot Gfx_LoadTexSlotImage<br>stag0000/font Stg00_FontInit<br>stag1000/movie Stg10_StrCallback<br>stag4000/automap Stg40_AutomapFlush<br>stag4000/automap Stg40_AutomapLoadClut | TIM pixel and CLUT uploads: boot image, texture slots, face images, stag0000 font, automap, movie slices. | VRAM upload (DMA ch2) | T M |
| `ClearOTagR` | `u_long *ClearOTagR(u_long *ot, int n)` | 1 | main/ot Gpu_ClearOt | Gpu_ClearOt: reverse OT, 0x100C entries per buffer. | OT in RAM (DMA ch6) | T |
| `DrawOTag` | `void DrawOTag(u_long *p)` | 1 | main/ot Gpu_DrawOt | Gpu_DrawOt: draws the finished OT (called from Sys_VSyncHandler). | GPU DMA linked-list walk | T |
| `PutDrawEnv` | `DRAWENV *PutDrawEnv(DRAWENV *env)` | 2 | main/sys Sys_Main<br>main/sys Sys_VSyncHandler | Buffer flip in Sys_VSyncHandler, boot. | GP0 draw area, offset, texpage | T |
| `PutDispEnv` | `DISPENV *PutDispEnv(DISPENV *env)` | 2 | main/sys Sys_Main<br>main/sys Sys_VSyncHandler | Buffer flip in Sys_VSyncHandler, boot. | GP1 display area and mode | T |
| `SetDefDrawEnv` | `DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h)` | 8 | main/gpu Gpu_InitDoubleBuffer | Gpu_InitDoubleBuffer: 2 draw envs per layout (320x240, 320x480 interlace, wide). | struct init only | T |
| `SetDefDispEnv` | `DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h)` | 8 | main/gpu Gpu_InitDoubleBuffer | Gpu_InitDoubleBuffer: 2 display envs. | struct init only | T |
| `AddPrim` | `void AddPrim(void *ot, void *p)` | 3 | main/anim Gfx_AnimateModelTex | Gfx_AnimateModelTex: links DR_MOVE packets into OT layer 6. | OT link (24-bit address) | - |
| `SetPolyF4` | `void SetPolyF4(POLY_F4 *p)` | 1 | main/anim Gfx_AddFlatQuad3D | Gfx_AddFlatQuad3D: packet header. | packet tag and code | - |
| `SetDrawMove` | `void SetDrawMove(DR_MOVE *p, RECT *rect, int x, int y)` | 3 | main/anim Gfx_AnimateModelTex | Gfx_AnimateModelTex: VRAM to VRAM copy for animated model textures. | packet (GP0 0x80) | - |
| `SetDrawMode` | `void SetDrawMode(DR_MODE *p, int dfe, int dtd, int tpage, RECT *tw)` | 2 | main/anim Gfx_AddFlatQuad3D<br>stag3500/textrect Stg35_RectDraw | Gfx_AddFlatQuad3D (blend mode), Stg35_RectDraw. | packet (GP0 0xE1, 0xE2) | - |

### libgs (12)

PC plan: C reimplementation on top of the libgte C math (GsWSMATRIX, light matrices, projection). Small: 12 functions, all math or struct setup.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `GsInitGraph` | `void GsInitGraph(u_short w, u_short h, u_short intmode, u_short dith, u_short vram)` | 1 | main/sys Sys_Main | Boot: 320x240, GsOFSGPU, dither on. | libgs globals, GPU | T |
| `GsSetOffset` | `void GsSetOffset(long x, long y)` | 4 | main/digistatus Menu_DigiStatusTask | Menu_DigiStatusTask: model offset in the status screen. | libgs draw offset | - |
| `GsInitCoordinate2` | `void GsInitCoordinate2(GsCOORDINATE2 *super, GsCOORDINATE2 *base)` | 7 | main/anim Gfx_AddFlatQuad3D<br>main/digistatus Menu_DigiStatusInit<br>stag0000/camera Stg00_CameraTask<br>stag2000/camera Stg20_CameraUpdate<br>stag3000/camera Stg30_CameraUpdate<br>stag3500/camera Stg35_CameraUpdate<br>stag4000/camera Stg40_CameraUpdate | Camera tasks (one per overlay), status screen, Gfx_AddFlatQuad3D. | struct init only | - |
| `GsSetLsMatrix` | `void GsSetLsMatrix(MATRIX *m)` | 1 | main/anim Gfx_AddFlatQuad3D | Gfx_AddFlatQuad3D. | GTE rotation and translation | - |
| `GsInit3D` | `void GsInit3D(void)` | 2 | main/gpu Gpu_InitDoubleBuffer<br>main/sys Sys_Main | Boot and Gpu_InitDoubleBuffer: libgs 3D state. | GTE control registers, libgs globals | T |
| `GsSetProjection` | `void GsSetProjection(long h)` | 6 | main/digistatus Menu_DigiStatusDraw<br>stag0000/camera Stg00_CameraDraw<br>stag2000/camera Stg20_CameraDraw<br>stag3000/camera Stg30_CameraDraw<br>stag3500/camera Stg35_CameraDraw<br>stag4000/camera Stg40_CameraUpdate | Camera tasks: projection distance (the widescreen hook). | GTE H register | - |
| `GsSetFlatLight` | `int GsSetFlatLight(int id, GsF_LIGHT *lt)` | 3 | main/anim Gfx_InitLights<br>main/digistatus Menu_DigiStatusInit<br>stag4000/obj Stg40_SetLights | Gfx_InitLights, Menu_DigiStatusInit, Stg40_SetLights: 3 parallel lights. | libgs light matrices (D_800619A8) | - |
| `GsSetLightMode` | `void GsSetLightMode(int mode)` | 3 | main/anim Gfx_InitLights<br>main/digistatus Menu_DigiStatusInit<br>stag4000/obj Stg40_SetLights | Same callers: mode 0 (no fog). | libgs globals | - |
| `GsSetAmbient` | `void GsSetAmbient(long r, long g, long b)` | 3 | main/anim Gfx_InitLights<br>main/digistatus Menu_DigiStatusInit<br>stag4000/obj Stg40_SetLights | Same callers: ambient colour. | GTE BK registers | - |
| `GsGetTimInfo` | `void GsGetTimInfo(u_long *tim, GsIMAGE *im)` | 1 | main/sys Sys_Main | Boot: parses the boot image TIM in the overlay area (Ovl_LoadAddr + 4). | none (TIM header) | T |
| `GsGetLs` | `void GsGetLs(GsCOORDINATE2 *coord, MATRIX *m)` | 1 | main/anim Gfx_AddFlatQuad3D | Gfx_AddFlatQuad3D: local-screen matrix. | GsWSMATRIX | - |
| `GsSetRefView2` | `int GsSetRefView2(GsRVIEW2 *pv)` | 6 | main/digistatus Menu_DigiStatusDraw<br>stag0000/camera Stg00_CameraDraw<br>stag2000/camera Stg20_CameraDraw<br>stag3000/camera Stg30_CameraDraw<br>stag3500/camera Stg35_CameraDraw<br>stag4000/camera Stg40_CameraUpdate | Camera tasks: view from eye, reference point and roll. | GsWSMATRIX, GsIDMATRIX | - |

### libgte (14)

PC plan: C fixed-point GTE (one gte_state struct: control / data registers, RTPS, MVMVA, NCLIP, NCS ...) with the same results as the hardware; the gte.h macros and these functions share it. Sin / atan tables from the Psy-Q data (build-time extraction) or regenerated and checked.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `rsin` | `int rsin(int a)` | 1 | stag4000/player Stg40_PlayerShootGift | Stg40_PlayerShootGift: shot direction. | sin table (main 38110 data) | - |
| `rcos` | `int rcos(int a)` | 1 | stag4000/player Stg40_PlayerShootGift | Stg40_PlayerShootGift. | sin table | - |
| `InitGeom` | `void InitGeom(void)` | 1 | main/sys Sys_Main | Boot: GTE on, default control registers. | GTE (COP2) | T |
| `ApplyMatrixLV` | `VECTOR *ApplyMatrixLV(MATRIX *m, VECTOR *v0, VECTOR *v1)` | 1 | main/model Actor_UpdateTransform | Actor_UpdateTransform: local move vector to world. | GTE MVMVA | - |
| `PushMatrix` | `void PushMatrix(void)` | 2 | stag4000/floor Stg40_DrawEntityShadow<br>stag4000/floor Stg40_ProjectGrid | Same: saves GTE rotation and translation. | libgte matrix stack (RAM) | - |
| `PopMatrix` | `void PopMatrix(void)` | 2 | stag4000/floor Stg40_DrawEntityShadow<br>stag4000/floor Stg40_ProjectGrid | Same. | libgte matrix stack | - |
| `ApplyMatrixSV` | `VECTOR *ApplyMatrixSV(MATRIX *m, SVECTOR *v0, SVECTOR *v1)` | 1 | main/parts Gfx_DrawPartQuadsRot | Gfx_DrawPartQuadsRot: rotated 2D part corners. | GTE MVMVA | T |
| `ScaleMatrix` | `MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v)` | 2 | main/model Actor_UpdateTransform<br>main/parts Gfx_DrawPartsEx | Actor_UpdateTransform, Gfx_DrawPartsEx. | none | T |
| `SetRotMatrix` | `void SetRotMatrix(MATRIX *m)` | 2 | stag4000/floor Stg40_DrawEntityShadow<br>stag4000/floor Stg40_ProjectGrid | Stg40 floor grid and entity shadows. | GTE rotation | - |
| `SetTransMatrix` | `void SetTransMatrix(MATRIX *m)` | 2 | stag4000/floor Stg40_DrawEntityShadow<br>stag4000/floor Stg40_ProjectGrid | Same. | GTE translation | - |
| `SetGeomOffset` | `void SetGeomOffset(long ofx, long ofy)` | 3 | main/gpu Gpu_InitDoubleBuffer<br>stag2000/mapbg Stg20_MapBgDraw<br>stag2000/staticbg Stg20_StaticBgUpdate | Gpu_InitDoubleBuffer, Stg20_MapBgDraw, Stg20_StaticBgUpdate. | GTE OFX, OFY | T |
| `RotTransPers` | `long RotTransPers(SVECTOR *v, long *sxy, long *p, long *flag)` | 7 | main/anim Gfx_AddFlatQuad3D<br>stag4000/floor Stg40_DrawEntityShadow<br>stag4000/floor Stg40_ProjectGrid | Gfx_AddFlatQuad3D, Stg40 floor grid and entity shadows. | GTE RTPS | - |
| `RotMatrixYXZ` | `MATRIX *RotMatrixYXZ(SVECTOR *r, MATRIX *m)` | 8 | main/digistatus Menu_DigiStatusDraw<br>main/model Actor_UpdateTransform<br>main/parts Gfx_DrawPartsEx<br>stag0000/camera Stg00_CameraDraw<br>stag2000/camera Stg20_CameraDraw<br>stag3000/camera Stg30_CameraDraw<br>stag3500/camera Stg35_CameraDraw<br>stag4000/camera Stg40_CameraUpdate | Actor_UpdateTransform, Gfx_DrawPartsEx, camera tasks, status screen. | sin/cos table (main 38110 data) | T |
| `ratan2` | `long ratan2(long y, long x)` | 1 | stag4000/player Stg40_PlayerShootGift | Stg40_PlayerShootGift: angle to the target. | atan table (libgte data) | - |

### libcd (19)

PC plan: Disc reader: file id -> LBA (Cd_FileLba / Cd_FileSectors) -> sectors from the user's image (raw 2352 for XA / STR) or the extracted tree. Callbacks run from the host frame pump, not from interrupts. XA = ADPCM decode into the mixer; St* = a small ring over the STR file.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `StSetRing` | `void StSetRing(u_long *ring_addr, u_long ring_size)` | 1 | stag1000/movie Stg10_StrInit | Stg10_StrInit: STR ring buffer (32 sectors). | libcd stream .bss | M |
| `CdInit` | `int CdInit(void)` | 1 | main/sys Sys_Main | Boot. | CD controller, CD interrupt, DMA ch3 | T |
| `CdPosToInt` | `int CdPosToInt(CdlLOC *p)` | 5 | main/cdread Cd_CheckNextSector<br>stag0000/xaplay Stg00_XaPlayTask<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | Cd_CheckNextSector (sector header check), XA end check. | none | T |
| `CdRead2` | `int CdRead2(long mode)` | 1 | stag1000/movie Stg10_StrKickCd | Stg10_StrKickCd: starts the STR stream read. | CD, stream interrupt | M |
| `StUnSetRing` | `void StUnSetRing(void)` | 1 | stag1000/movie Stg10_MovieDestroy | Stg10_MovieDestroy. | stream state | M |
| `StSetStream` | `void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)())` | 1 | stag1000/movie Stg10_StrInit | Stg10_StrInit: 24-bit mode, all frames, no callbacks. | stream state | M |
| `StFreeRing` | `u_long StFreeRing(u_long *base)` | 1 | stag1000/movie Stg10_StrNextVlc | Stg10_StrNextVlc: releases a frame. | ring buffer | M |
| `StGetNext` | `u_long StGetNext(u_long **addr, u_long **header)` | 1 | stag1000/movie Stg10_StrNext | Stg10_StrNext: next complete frame in the ring. | ring buffer | M |
| `StCdInterrupt` | `void StCdInterrupt(void)` | 1 | stag1000/movie Stg10_StrCallback | Stg10_StrCallback: runs a deferred stream interrupt (StCdIntrFlag). | CD interrupt, StCdIntrFlag | M |
| `CdIntToPos` | `CdlLOC *CdIntToPos(int i, CdlLOC *p)` | 9 | main/cd Cd_GetFilePos<br>stag0000/xaplay Stg00_XaPlayTask<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | Cd_GetFilePos (Cd_FileLba[id]), XA start positions. | none (BCD) | T M |
| `CdLastCom` | `int CdLastCom(void)` | 4 | stag0000/xaplay Stg00_XaPlayTask<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | XA tasks: last command was GetlocP. | libcd state | - |
| `CdSetDebug` | `int CdSetDebug(int level)` | 1 | main/sys Sys_Main | Boot: level 0. | libcd .data | T |
| `CdSync` | `int CdSync(int mode, u_char *result)` | 8 | stag0000/xaplay Stg00_XaPlayTask<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | XA tasks: poll command completion. | libcd state | - |
| `CdSyncCallback` | `CdlCB CdSyncCallback(CdlCB func)` | 2 | main/cdread Cd_ReadFileAsync<br>main/cdread Cd_ReadSyncCallback | cdread.c: Cd_ReadSyncCallback after Setloc. | CD interrupt callback | T |
| `CdReadyCallback` | `CdlCB CdReadyCallback(CdlCB func)` | 2 | main/cdread Cd_ReadSectorCallback<br>main/cdread Cd_ReadSyncCallback | cdread.c: Cd_ReadSectorCallback per data-ready interrupt. | CD interrupt callback | T |
| `CdControl` | `int CdControl(u_char com, u_char *param, u_char *result)` | 11 | main/sys Sys_Main<br>stag0000/xaplay Stg00_XaPlayTask<br>stag1000/movie Stg10_StrKickCd<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | Boot Setmode 0x80 (double speed, called through a cast); STR Setloc and Setmode; XA Setfilter (0x0D) and ReadS (0x1B). | CD command registers, CD interrupt | T M |
| `CdControlF` | `int CdControlF(u_char com, u_char *param)` | 16 | main/cdread Cd_ReadFileAsync<br>main/cdread Cd_ReadSectorCallback<br>main/cdread Cd_ReadSyncCallback<br>stag0000/xaplay Stg00_XaPlayDestroy<br>stag0000/xaplay Stg00_XaPlayTask<br>stag2000/xastream Stg20_XaStreamDestroy<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayDestroy<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayDestroy<br>stag3500/xaplay Stg35_XaPlayTask | cdread.c: Pause, Setmode, ReadN, Setloc; XA: SeekL (0x15), GetlocP (0x11), Pause. | CD command, no wait | T |
| `CdControlB` | `int CdControlB(u_char com, u_char *param, u_char *result)` | 6 | main/sys Sys_Main<br>stag0000/xaplay Stg00_XaPlayTask<br>stag1000/movie Stg10_MovieDestroy<br>stag2000/xastream Stg20_XaStreamUpdate<br>stag3000/xaplay Stg30_XaPlayTask<br>stag3500/xaplay Stg35_XaPlayTask | Pause at boot and movie end; XA Setmode. | CD command, blocking | T M |
| `CdGetSector` | `int CdGetSector(void *madr, int size)` | 2 | main/cdread Cd_CheckNextSector<br>main/cdread Cd_ReadSectorCallback | cdread.c: 3-word sector header, then 0x200 words (2048 bytes) into the file buffer. | CD data FIFO, DMA ch3 | T |

### libetc (3)

PC plan: Host timing: a 60 Hz VBlank counter, VSyncCallback handler called from the host loop (or a timer thread), ResetCallback a no-op.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `VSync` | `int VSync(int mode)` | 6 | main/sys Sys_Main | Boot waits, VSync(3); VSync(-1) = VBlank counter for frame pacing (Sys_State.frameDelta, playTime). | Sys_VSyncCount, root counters | T |
| `ResetCallback` | `int ResetCallback(void)` | 1 | main/sys Sys_Main | Boot: interrupt and callback system. | interrupt controller, Sys_DmaCallbacks, Sys_VSyncCallbacks | T |
| `VSyncCallback` | `int VSyncCallback(void (*f)(void))` | 1 | main/sys Sys_Main | Boot: installs Sys_VSyncHandler (buffer flip, sequencer tick). | VBlank interrupt | T |

### libsnd (21)

PC plan: Either SPU emulation + the real libsnd behaviour reimplemented in C (VAB / SEP parsing, 60 Hz tick), or a libsnd-level player into SDL audio. Stubs for the title prototype (no audio).

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `SsSeqCalledTbyT` | `void SsSeqCalledTbyT(void)` | 1 | main/sys Sys_VSyncHandler | Sys_VSyncHandler: one sequencer tick per VBlank. | sequencer, SPU voices, Snd_MarkCallbacks | T |
| `SsSepClose` | `void SsSepClose(short sep_access_num)` | 1 | main/sound Snd_UnloadSlot | Snd_UnloadSlot. | Snd_SeqScores | T |
| `SsInit` | `void SsInit(void)` | 1 | main/sys Sys_Main | Boot. | SPU init, libsnd globals | T |
| `SsSepOpen` | `short SsSepOpen(u_long *addr, short vab_id, short seq_num)` | 1 | main/sound Snd_ServiceSlotLoads | Snd_ServiceSlotLoads: SEP with 16 sequences. | Snd_SeqScores | T |
| `SsSepPlay` | `void SsSepPlay(short sep_access_num, short seq_num, char play_mode, short l_count)` | 1 | main/sound Snd_PlayById | Snd_PlayById: music and sound effects. | sequencer, SPU voices | T |
| `SsSetSerialAttr` | `void SsSetSerialAttr(char s_num, char attr, char mode)` | 1 | main/sound Snd_Init | Snd_Init: CD audio input on (XA). | SPU CD input | T |
| `SsSetMVol` | `void SsSetMVol(short voll, short volr)` | 1 | main/sound Snd_Init | Snd_Init: master volume 0x7F. | SPU main volume | T |
| `SsStart2` | `void SsStart2(void)` | 1 | main/sound Snd_Init | Snd_Init: starts the sequencer. | SPU | T |
| `SsSepStop` | `void SsSepStop(short sep_access_num, short seq_num)` | 4 | main/sound Snd_PlayById<br>main/sound Snd_StopAll<br>main/sound Snd_StopById<br>main/sound Snd_UnloadSlot | Snd_PlayById, Snd_StopAll, Snd_StopById, Snd_UnloadSlot. | sequencer, SPU voices | T |
| `SsSetSerialVol` | `void SsSetSerialVol(char s_num, short voll, short volr)` | 1 | main/sound Snd_Init | Snd_Init: CD audio volume 0x7F. | SPU CD volume | T |
| `SsSetTableSize` | `void SsSetTableSize(char *table, short s_max, short t_max)` | 1 | main/sound Snd_Init | Snd_Init: Snd_SeqAttrTable, 6 SEP x 16 sequences. | Snd_SeqScores | T |
| `SsSetTickMode` | `void SsSetTickMode(long tick_mode)` | 1 | main/sound Snd_Init | Snd_Init: 0x1000 = SS_NOTICK, ticked from Sys_VSyncHandler. | libsnd tick state | T |
| `SsSepSetVol` | `void SsSepSetVol(short sep_access_num, short seq_num, short voll, short volr)` | 1 | main/sound Snd_PlayById | Snd_PlayById: 0x7F. | sequencer | T |
| `SsUtAllKeyOff` | `void SsUtAllKeyOff(short mode)` | 1 | main/sound Snd_StopAll | Snd_StopAll. | SPU voices | T |
| `SsUtSetReverbDepth` | `void SsUtSetReverbDepth(short ldepth, short rdepth)` | 1 | main/sound Snd_Init | Snd_Init: depth 0. | SPU reverb | T |
| `SsUtSetReverbType` | `short SsUtSetReverbType(short type)` | 1 | main/sound Snd_Init | Snd_Init: reverb type 3. | SPU reverb work area | T |
| `SsUtReverbOn` | `void SsUtReverbOn(void)` | 1 | main/sound Snd_Init | Snd_Init. | SPU reverb | T |
| `SsVabClose` | `void SsVabClose(short vabid)` | 1 | main/sound Snd_UnloadSlot | Snd_UnloadSlot. | SPU RAM free | T |
| `SsVabOpenHead` | `short SsVabOpenHead(u_char *addr, short vabid)` | 1 | main/sound Snd_ServiceSlotLoads | Snd_ServiceSlotLoads: VH header of the slot's bank. | SPU RAM allocation, VAB tables | T |
| `SsVabTransBody` | `short SsVabTransBody(u_char *addr, short vabid)` | 1 | main/sound Snd_ServiceSlotLoads | Snd_ServiceSlotLoads: VB samples to SPU RAM. | SPU RAM (DMA ch4) | T |
| `SsVabTransCompleted` | `short SsVabTransCompleted(short immediate)` | 1 | main/sound Snd_ServiceSlotLoads | Snd_ServiceSlotLoads: polls the upload. | SPU DMA | T |

### libmcrd (11)

PC plan: Save files on disk: one file per card slot / name; the 0x4000 save block (0x1058 GameState inside) and the 0x1E000 DM transfer data; PS1 card image import (.mcr / .mcd). Async API kept (MemCardSync returns done at once).

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `MemCardInit` | `void MemCardInit(long val)` | 1 | main/sys Sys_Main | Boot (called through a cast, arg 0). | card events, Card_* task stack | T |
| `MemCardStart` | `void MemCardStart(void)` | 1 | main/sys Sys_Main | Boot. | card VBlank hook | T |
| `MemCardExist` | `long MemCardExist(long chan)` | 1 | stag1100/card Stg11_CardAsyncOp | Stg11_CardAsyncOp: card present. | card events | - |
| `MemCardAccept` | `long MemCardAccept(long chan)` | 1 | stag1100/card Stg11_CardAsyncOp | Stg11_CardAsyncOp: card ready or new card. | card events | - |
| `MemCardOpen` | `long MemCardOpen(long chan, char *file, long flag)` | 1 | stag1100/card Stg11_CardFileOp | Stg11_CardFileOp. | BIOS file system (bu00:, bu10:) | - |
| `Card_CloseFile` | `void MemCardClose(void) (decomp name Card_CloseFile)` | 1 | stag1100/card Stg11_CardFileOp | Stg11_CardFileOp: closes the open file. | BIOS close | - |
| `MemCardReadFile` | `long MemCardReadFile(long chan, char *file, u_long *adrs, long ofs, long bytes)` | 2 | stag1100/card Stg11_CardAsyncOp | Stg11_CardAsyncOp: save block (0x4000) and DM transfer data (0x1E000). | BIOS read, card events | - |
| `MemCardWriteFile` | `long MemCardWriteFile(long chan, char *file, u_long *adrs, long ofs, long bytes)` | 1 | stag1100/card Stg11_CardAsyncOp | Stg11_CardAsyncOp: save block (0x4000). | BIOS write, card events | - |
| `MemCardSync` | `long MemCardSync(long mode, long *cmds, long *rslt)` | 2 | stag1100/card Stg11_CardAsyncOp<br>stag1100/card Stg11_CardFileOp | Stg11_CardAsyncOp, Stg11_CardFileOp: polls the async op. | Card_* task stack | - |
| `MemCardCreateFile` | `long MemCardCreateFile(long chan, char *file, long blocks)` | 1 | stag1100/card Stg11_CardFileOp | Stg11_CardFileOp: 2 blocks. | BIOS create | - |
| `MemCardFormat` | `long MemCardFormat(long chan)` | 1 | stag1100/card Stg11_CardFileOp | Stg11_CardFileOp. | BIOS format | - |

### libpad (3)

PC plan: SDL3 keyboard / gamepad written into the receive buffers (Pad_RecvBufs) in the digital / analog pad reply format, so Pad_PollPort / Pad_Update stay as they are. PadGetState = connected.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `PadGetState` | `int PadGetState(int port)` | 1 | main/pad Pad_PollPort | Pad_PollPort: connection state per port (port << 4). | pad driver state | T |
| `PadStartCom` | `void PadStartCom(void)` | 1 | main/pad Pad_Init | Pad_Init: starts the per-VBlank pad exchange. | SIO0, interrupt chain | T |
| `PadInitDirect` | `void PadInitDirect(u_char *pad1, u_char *pad2)` | 1 | main/pad Pad_Init | Pad_Init: hands Pad_RecvBufs (2 x 0x22 bytes) to the SIO pad driver. | SIO0 registers, pad driver .bss, VBlank interrupt hook | T |

### libpress (5)

PC plan: C MDEC: DecDCTvlc2 (VLC with the game's table) + IDCT / YUV -> 24-bit slices, DecDCTout 'done' callback called synchronously. Or an STR decoder that feeds the same slices.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `DecDCTReset` | `void DecDCTReset(int mode)` | 1 | stag1000/movie Stg10_StrInit | Stg10_StrInit. | MDEC registers | M |
| `DecDCTin` | `void DecDCTin(u_long *buf, int mode)` | 1 | stag1000/movie Stg10_MovieUpdate | Stg10_MovieUpdate: run-level data to the MDEC. | MDEC, DMA ch0 | M |
| `DecDCTout` | `void DecDCTout(u_long *buf, int size)` | 2 | stag1000/movie Stg10_MovieUpdate<br>stag1000/movie Stg10_StrCallback | Stg10_MovieUpdate, Stg10_StrCallback: decoded 16-pixel slices. | MDEC, DMA ch1 | M |
| `DecDCToutCallback` | `int DecDCToutCallback(void (*func)())` | 2 | stag1000/movie Stg10_MovieDestroy<br>stag1000/movie Stg10_StrInit | Stg10_StrInit: Stg10_StrCallback per slice; cleared at movie end. | DMA ch1 callback | M |
| `DecDCTvlc2` | `int DecDCTvlc2(u_long *bs, u_long *buf, DECDCTTAB table)` | 1 | stag1000/movie Stg10_StrNextVlc | Stg10_StrNextVlc: VLC decode with the unpacked table (Stg10_VlcTable). | CPU only | M |

### libc2 (3)

PC plan: Host C library.

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `memcpy` | `void *memcpy(void *dst, const void *src, size_t n)` | 1 | main/gamemode Ovl_Load | Ovl_Load: copies the overlay file over Ovl_LoadArea. | RAM | T |
| `memset` | `void *memset(void *s, int c, size_t n)` | 6 | stag1100/card Stg11_CardInitHeader<br>stag1100/card Stg11_CardSetTitle<br>stag1100/cardmenu Stg11_TransferSelected<br>stag3500/battle Stg35_BattleUpdate<br>stag4000/dungfile Stg40_ApplyFloorLayout | stag1100 card header, title and transfer buffers; Stg35_BattleUpdate reset; Stg40_ApplyFloorLayout clear. | RAM | - |
| `strcpy` | `char *strcpy(char *dst, const char *src)` | 1 | stag1100/card Stg11_CardSetFileName | Stg11_CardSetFileName: memory card file name. | RAM | - |

### libapi (1)

PC plan: Not needed: crt0 goes away on PC, the game uses its own heap (Mem_InitHeap).

| Function | Prototype | Calls | Callers | Use | Touches | T/M |
|---|---|---|---|---|---|---|
| `InitHeap` | `void InitHeap(u_long *head, u_long size)` | 1 | main/156C Sys_Start | crt0 (Sys_Start, hand asm): heap after .bss. Not called from game C; the game has its own heap (Mem_InitHeap). | libc2 malloc arena | - |

## Psy-Q data the game reads

| Symbol | Library | Read by | Meaning | PC |
|---|---|---|---|---|
| `GsWSMATRIX` | libgs | `main/model.c` (`Gfx_CalcModelBoneMatrices` and the GTE matrix loads), `stag4000/floor.c` (`Stg40_ProjectGrid`, `Stg40_DrawEntityShadow`) | World-to-screen matrix, written by `GsSetRefView2`. Two views today: `CoordMatrix` (main), `Mat1F668` (stag4000). | A global `MATRIX` in the libgs shim; one type for both readers. |
| `D_800619A8` | libgs | `main/model.c` (`Gfx_CalcModelBoneMatrices`) | Light matrix (0x20 bytes) set by `GsSetFlatLight`; most likely `GsLIGHTWSMATRIX`. | Same, named in the shim. |
| `StCdIntrFlag` | libcd | `stag1000/movie.c` (`Stg10_StrCallback`) | Stream interrupt deferred while the MDEC was busy. `s32` in main headers, `u8` in stag1000. | Flag in the St* shim; one type. |
| `D_8004FC10` | libsn | crt0 only (`Sys_Start`) | `_stacksize` 0x8000 / `_ramsize` 0x800000. | Not needed. |

## gte.h macros

All in `main/model.c`. Each is a few GTE register moves or one GTE op; the PC versions are C functions or macros
over the same C GTE state as libgte, with the same fixed-point results.

| Macro | GTE work | Uses | Functions |
|---|---|---|---|
| `gte_SetRotMatrix` | RT control regs 0-4 | 5 | Actor_ProjectToScreen (2), Gfx_CalcModelBoneMatrices, Gfx_DrawTexModel, Gfx_DrawWireModel |
| `gte_SetTransMatrix` | TR control regs 5-7 | 5 | same as above |
| `gte_SetLightMatrix` | LLM control regs 8-12 | 1 | Gfx_DrawTexModel |
| `gte_ldclmv` | matrix column to IR1-IR3 | 6 | Actor_ProjectToScreen (3), Gfx_CalcModelBoneMatrices (3) |
| `gte_rtir` | MVMVA RT x IR | 6 | same |
| `gte_stclmv` | IR1-IR3 to matrix column | 6 | same |
| `gte_ldlv0` | 32-bit vector to V0 (16-bit) | 2 | Actor_ProjectToScreen, Gfx_CalcModelBoneMatrices |
| `gte_rtv0tr` | MVMVA RT x V0 + TR | 2 | same |
| `gte_stlvnl` | MAC1-MAC3 to VECTOR | 2 | same |
| `gte_ldv0` | SVECTOR to V0 | 2 | Actor_ProjectToScreen, Gfx_IsOriginOffscreen |
| `gte_ldv0u` | unaligned SVECTOR to V0 (not an inline_n.h name) | 4 | Gfx_CalcNormalColors (2), Gfx_ProjectModelVerts (2) |
| `gte_rtps` | RTPS (rotate, translate, perspective) | 4 | Actor_ProjectToScreen, Gfx_IsOriginOffscreen, Gfx_ProjectModelVerts (2) |
| `gte_stsxy` | SXY2 | 4 | same as gte_rtps |
| `gte_stszotz` | SZ3 >> 2 | 2 | Gfx_ProjectModelVerts (2) |
| `gte_stflg` | FLAG | 2 | Gfx_IsOriginOffscreen, Gfx_ProjectModelVerts |
| `gte_ncs` | NCS (normal colour single) | 2 | Gfx_CalcNormalColors (2) |
| `gte_strgb` | RGB2 | 2 | Gfx_CalcNormalColors (2) |
| `gte_ldsxy3` | SXY0-SXY2 | 2 | Gfx_AddQuadsGT4, Gfx_AddTrisGT3 |
| `gte_nclip` | NCLIP (back-face test) | 2 | same |
| `gte_stopz` | MAC0 | 2 | same |

None of these is on the title path (no 3D model there). The title uses libgte only through `RotMatrixYXZ`,
`ScaleMatrix` and `ApplyMatrixSV` (rotated 2D parts in `Gfx_DrawPartsEx` / `Gfx_DrawPartQuadsRot`).

## Callbacks and interrupt context

Psy-Q runs these game functions from interrupts. On PC they run from the host loop (one thread), in the same order
relative to the frame.

| Registered by | Callback | Runs on PS1 | Does | PC |
|---|---|---|---|---|
| `Sys_Main` `VSyncCallback` | `Sys_VSyncHandler` | every VBlank (60 Hz) | Flips buffers when `Sys_FlipPending` and enough VBlanks passed (`vsyncWait`, 30 / 60 Hz): `PutDispEnv`, `PutDrawEnv`, `Gpu_DrawOt`; ticks the sequencer (`SsSeqCalledTbyT`). | Host VBlank at 59.94 Hz calls it. `Sys_Main` spins on the volatile `Sys_FlipPending` until the handler clears it, so the spin must pump host VBlanks (or the handler runs on a timer thread). |
| `Cd_ReadFileAsync` `CdSyncCallback` | `Cd_ReadSyncCallback` | CD command complete | State machine: after Setloc sets mode 0xA0 (double speed, 2340-byte sectors), then ReadN; on error retries the file. | Called by the CD shim. Simplest: the shim runs the whole chain inside the `CdControlF(Setloc)` call, so the read is done when `Cd_ReadFileAsync` returns. The game spins on `Cd_PollRead` in `Cd_ReadFileAsync` and `Stg10_MovieUpdate`, so callbacks cannot wait for a later frame unless those spins pump. |
| `Cd_ReadSyncCallback` `CdReadyCallback` | `Cd_ReadSectorCallback` | each data sector | `CdGetSector` 3-word header (MSF, mode, subheader; checked against the expected LBA) + 2048 bytes, pause at the end. | The shim builds the header from the LBA and copies the data from the image or the extracted file. |
| `Stg10_StrInit` `DecDCToutCallback` | `Stg10_StrCallback` | MDEC slice out done | Uploads the slice (`LoadImage`), next slice, runs a deferred `StCdInterrupt`. | Called by the MDEC shim after each decoded slice. |

`VSync(-1)` (VBlank count) drives `Sys_State.frameDelta` (capped at 6) and `Save_GameState.playTime`, so the host
VBlank counter must advance at the PS1 rate. The pad driver and the memory card driver also run on VBlank inside
Psy-Q; the game only reads their results (`Pad_RecvBufs`, `PadGetState`, `MemCardSync`).

## Port findings from the list

- **24-bit OT links in game C.** No Psy-Q prim macros are used, but 14 game files write GPU packets and link them
  into OTs themselves with 24-bit addresses (`(u32)p & 0xFFFFFF`, `tag.addr : 24` bitfields in `main/156C.h`): main
  anim.c, model.c, ot.c, parts.c, portrait.c, text.c and the overlays stag0000 font.c, scrollview.c; stag1100
  cardmenu.c; stag2000 mapbg.c, staticbg.c; stag3500 textrect.c; stag4000 automap.c, floor.c. A PC pointer does not
  fit 24 bits. Plan: one 16 MB-aligned "PS1 RAM" arena that holds the heap (`Mem_InitHeap`), the OTs (`Gpu_OtBufs`)
  and every packet buffer; the emulated GPU resolves `arena + (link & 0xFFFFFF)`. Works for 32-bit and 64-bit builds.
  So "the overlays never touch the GPU" holds for Psy-Q calls only: 8 overlay files build packets, and overlays call
  `LoadImage`, `SetDrawMode`, `SetGeomOffset` and the libgs camera functions themselves.
- **Prototypes.** 25 of the functions are called from C with no prototype (C89 implicit declarations: `AddPrim`,
  `VSyncCallback`, `PadInitDirect`, `SetDefDrawEnv`, `GsInitGraph`, `memcpy`, ...), and the others have per-overlay
  declarations that disagree (`CdIntToPos` 3 forms, `CdControlF` `(s32, s32)` vs `(s32, u8 *)`, `GsSetRefView2` with 6
  view types, `RotMatrixYXZ` 3, `LoadImage` 2, `CdLastCom` / `StCdIntrFlag` u8 vs s32; `CdControl` and `MemCardInit`
  are called through casts). GCC 14 and Clang 16 reject implicit declarations by default. The native build needs one
  Psy-Q header set (`libgpu.h`, `libgs.h`, `libgte.h`, `libcd.h`, `libetc.h`, `libsnd.h`, `libmcrd.h`, `libpress.h`)
  with the real types, and the decomp's local declarations behind the build switch.
- **Overlay data reset.** Retail `Ovl_Load` copies the overlay file over the overlay area at every scene switch, so
  each overlay's `.data` and `.bss` start from their initial values each time. With all overlays linked into one
  program, `Ovl_Load` must restore that: keep a pristine copy of each overlay's `.data`, zero its `.bss`.
- **Boot image.** `Sys_Main` reads a TIM at `Ovl_LoadAddr + 4`: the initial bytes of the overlay area in the exe
  (`Ovl_LoadArea.bin`, extracted at build time) are the boot splash. The PC build keeps that blob as data.
- **Raw sectors.** Data files are read as 2048-byte sectors, but `Cd_CheckNextSector` checks the sector header
  position (`CdGetSector` 3 words). XA (`2.XAP`, Setfilter by file / channel, ReadS, GetlocP end check) and STR
  (`1.STR`) need Mode 2 sectors with subheaders: read them from the full image (`.img`), or keep them raw in the tree.
- **Busy waits.** The game spins on state that Psy-Q interrupts change: `Sys_FlipPending` (`Sys_Main`),
  `Cd_PollRead` (`Cd_ReadFileAsync`, `Stg10_MovieUpdate`), `StGetNext` (`Stg10_StrNext`, 2000 tries). On one thread
  the shim must either finish the work inside the call that starts it or pump from inside these waits.
- **No direct hardware access** in game C other than the scratchpad (`Task_Run`, `Gfx_CalcModelBoneMatrices`, R4).
- `Card_CloseFile` is libmcrd (`MemCardClose`); the decomp name stays, the shim provides it under both names.

## Title screen subset (prototype: boot main + stag1000 to the title, no audio)

61 functions are on the boot + title path (T). 21 libsnd and 2 libmcrd of them can be stubs for the first
prototype (no audio, no card), which leaves **38 to implement**:

- libgpu (13): ResetGraph, SetGraphDebug, SetDispMask, DrawSync, ClearImage, ClearImage2, LoadImage, ClearOTagR,
  DrawOTag, PutDrawEnv, PutDispEnv, SetDefDrawEnv, SetDefDispEnv
- libgs (3): GsInitGraph, GsInit3D, GsGetTimInfo
- libgte (5): InitGeom, SetGeomOffset, RotMatrixYXZ, ScaleMatrix, ApplyMatrixSV
- libcd (10): CdInit, CdSetDebug, CdControl, CdControlF, CdControlB, CdSyncCallback, CdReadyCallback, CdGetSector,
  CdIntToPos, CdPosToInt (the `main/cdread.c` sector path)
- libetc (3): ResetCallback, VSync, VSyncCallback
- libpad (3): PadInitDirect, PadStartCom, PadGetState
- libc2 (1): memcpy (`Ovl_Load`)

Retail boots into game mode 0x402 (intro movie) before the title. The movie path (M) adds 12 more: CdRead2, StSetRing,
StUnSetRing, StSetStream, StGetNext, StFreeRing, StCdInterrupt, DecDCTReset, DecDCTin, DecDCTout,
DecDCToutCallback, DecDCTvlc2. For the prototype they can be stubs: `StGetNext` hands one fake frame past the end
frame and `DecDCTout` calls the out callback at once, so `Stg10_MovieUpdate` ends the movie on its first frame and
sets game mode 0x401 (title), with no change to the game C.

## PC layer order (from this list)

1. Headers + link stubs for all 109 (P1.1): the native build links with every function present (stubs log once).
2. libetc + host loop (P1.2): VBlank counter, `Sys_VSyncHandler` pump, `Sys_FlipPending` spin.
3. libcd data path (P1.3): 10 functions over the disc image by file id.
4. libgpu + libgs init (P1.4): VRAM, OT walk, packets for the title (sprites, flat / textured quads, DR_MODE,
   DR_MOVE, fill). 13 + 3 functions.
5. libgte C (P1.5): 5 title functions first, then the other 9 and the 20 macros for 3D scenes.
6. libpad (P1.7): 3 functions, SDL3 input into the pad reply buffers.
7. Title on screen. Then libsnd (21) + SPU, libmcrd (11), libpress + St* (12), XA.
