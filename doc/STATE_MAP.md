# Global state map

Every global of the main executable and of the 7 stage overlays, grouped by what it holds: one player's
state, the world / session the players are in, the engine, constant tables, or debug-only data. The map is
for the PC port: P2 (split simulation from presentation) and P3 (multiplayer: what is per tamer, what is
shared world, what a server owns).

Writers and readers come from the relocations of the built objects (a store through the symbol is a write, a
load is a read, taking the address counts with the reads). Code that reaches a global through a pointer
global (`Save_GameStatePtr`, `Dung_StatePtr`) is listed under that pointer. Sizes are the C object sizes.

Classes:

- PLAYER: belongs to one tamer (the save data and copies of it).
- WORLD: the session the tamer is in (city, dungeon, battle). Side `sim` = game rules and their state, `ui` =
  menus, windows and other presentation state.
- ENGINE: frame loop, tasks, heap, GPU, CD, sound, pad, memory card.
- CONST: tables the code only reads (task descriptors, layouts, game rules, text).
- DEBUG: the stag0000 test menu.
- PSYQ: data of the linked Psy-Q libraries (kept as asm).

## Memory map

| Range | What |
|---|---|
| 0x80010000 .. 0x80040CF0 | main .rodata + .text |
| 0x80040CF0 .. 0x800506F8 | main .data |
| 0x800506F8 .. 0x80050758 | main .sdata (`_gp` = 0x800506F8, the address of `Mem_HeapStart`) |
| 0x80050758 .. 0x80050798 | main .sbss (crt0 clears from `D_80050758`) |
| 0x80050798 .. 0x80063360 | main .bss (game, then Psy-Q library bss from 0x8005FDD8) |
| 0x80063360 .. | overlay area `Ovl_LoadArea`: every STAG*.PRO links here; `Ovl_Load` reads whole sectors over it |
| .. 0x800740A4 | end of the largest overlay (STAG3000 incl. bss) |
| 0x80075000 .. 0x801FF000 | heap (`Mem_HeapStart` constant, end literal in `Sys_Main`) |
| 0x801FFFF0 | initial stack (exe header); `Snd` clamps reads at 0x801FFFFC / 0x801FFFFF |
| 0x1F800000 | scratchpad: bone matrices in `Gfx_CalcModelBoneMatrices`, the stack of `Task_Run` |

Overlay end addresses: STAG0000 0x80069378, STAG1000 0x80066244, STAG1100 0x800685D8, STAG2000 0x80070F50, STAG3000 0x800740A4, STAG3500 0x8006AF74, STAG4000 0x80072BC8.
The main exe file image runs to 0x800AE800: the bytes after 0x80063360 are an opaque blob (`Ovl_LoadArea`)
that overlays and the heap overwrite. A port gives each overlay its own memory and allocates the heap.

## Per player vs world (multiplayer split)

| State | Globals | Class | Note for a split |
|---|---|---|---|
| Tamer save: name, rank, bits, play time | `Save_GameState` (playerName, rank, rankTitleSet, bits, playTime) | PLAYER | One per tamer account. |
| DigiBeetle: hp/mp, part slots, broken parts, name | `Save_GameState` hp, maxHp, mp, maxMp, slotItems, slotStatus, beetleName | PLAYER | One per tamer. |
| Items: bag and storage | `Save_GameState.bagItems[0x30]`, `.storageCounts[0x100]` | PLAYER | One per tamer. |
| Digimon roster | `Save_GameState.elems[0x24]` (`DigiRosterEntry`) | PLAYER | The battle party is elems[0..2] (state >= 3). One roster per tamer. |
| Story progress | `Save_GameState.eventFlags` (bits + progress word) | PLAYER | Per tamer, or shared if a group plays one story. |
| City session | stag2000 `Stg20_MapGrid`, `Stg20_MenuState`, `Stg20_ShopItems` | WORLD | Map grid is world; menu and shop state is per client UI. |
| Dungeon floor | `Dung_State` (ents, chests, hazards, traps, cells, turnQueue, encounters), `Stg40_RootState` | WORLD | Shared floor if players share a dungeon; the server owns it. |
| Dungeon party status | `Dung_State.status` (`DungStatus`: bugs, confusion, bind) | WORLD | Per tamer once several tamers walk a floor: today one block. |
| Battle | `Stg30_Battle` (digis[6]: 0..2 party copies, 3..5 enemies), `Stg30_TurnOrder`, `Stg30_BattleScript`, `Stg30_FighterStateBackup` | WORLD | Server owns. `Stg30_BattleUpdate` copies `Save_GameState.elems[0..2]` in, `Stg30_BattleDestroy` copies them back when the battle ends. |
| VS battle | `Stg35_Battle` (rec[6]: P1 0..2, P2 3..5), `Stg35_TurnOrder`, `Stg35_BattleScript` | WORLD | The one retail two-player mode; parties come in through `Save_GameState.elems[0..5]`. |
| Event script | `Flag_EntryIter`, `Text_ReturnStack` | WORLD | Runs per client today; event results write `Save_GameState.eventFlags`. |
| Random numbers | `Rand_Index` over `Rand_Table` | ENGINE | One stream for everything: a lockstep or server build needs its own streams. |
| Input | `Pad_State[2]` (port 1 / 2) | ENGINE | Per client; VS mode reads both ports. |
| Scene switch | `Sys_State.gameMode` / `nextGameMode` / `modeArg`, `Ovl_CurrentId` | ENGINE | Per client; game mode >> 8 picks the overlay. |

## One layout per object, aliases and kept views

Each object has one struct now; the overlays use the main types:

- `GameState` (`Save_GameState`, also each memory card slot image and `Stg11_VsParty.gameState`).
- `DigiRosterEntry` (the roster, `Stg30_Battle.digis`, `Stg30_FighterStateBackup.digis`, `Stg35_Battle.rec`).
- `DungState` with `DungStatus` at 0xBA0 (`Dung_State`, main and the overlays).
- `MenuGridLayout` (gridSize, origin, cellStep) for every 12-byte menu grid record.

Alias symbols (a second name for a field of another object, kept because retail code addresses it as its own
symbol; on PC they are the field):

| Alias | Is | Why kept |
|---|---|---|
| `Pad_Cross` | `Pad_State[0].cross` | one scalar load in `Stg20_BeetlePartsUpdate` |
| `Sys_GameMode` | `Sys_State.gameMode` | scalar loads in `Stg20_StageMain` |
| `Stg30_BattleDigis` | `Stg30_Battle.digis` | battle code relocates against it (views `Stg30CombatCD8`, `Stg30SlotBlk`) |
| `Stg30_BattleDigiNames` | `Stg30_Battle.digis[0].name` | name reads (view `Stg30Name5C`) |
| `Stg00_ScrollTileTex` | `Stg00_ScrollViewDesc` read as s32[20] | debug view reads past a 24-byte TaskDesc (retail bug) |
| `Stg11_CardIconImage`, `Stg11_CardIcon2`, `Stg11_CardIcon3` | offsets into the card icon TIM blobs | labels into extracted assets |

Views that stay (same bytes as the main type, different C access needed for identical code):

- `Stg20GameInit`: `Save_GameState` from 0x24 as the 0xBE-byte new-game block (`Stg20_ApplyStartPreset`).
- `Save_ClearEventFlags` walks a `GameState *` one byte per step (retail loop shape).
- `Sys_VsPartyConfirmed` is `s32` in main and `s16` in stag1100 / stag3500 (the overlays store halfwords).
- `GsWSMATRIX` (Psy-Q) is a `CoordMatrix` view in main and a MATRIX-shaped `Mat1F668` in stag4000.

## PLAYER

The save block and the copies the VS party pick makes. Field layout: `GameState` and `DigiRosterEntry` in include/main/156C.h.

### main (SLUS_011.93)

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Save_GameStatePtr` | main/savedata.c | `GameState *` | 0x4 | - | Beetle_GetPart, Beetle_SetPart, Beetle_SetPartBroken, Digi_CompactRoster, Digi_CountByState, Digi_ListByState, Digi_SortRoster, Item_AddToBag +51 | Constant pointer to Save_GameState; most main and stag4000 code reads the save through it. |
| `Save_GameState` | main/savedata.c | `GameState` | 0x1058 | Flag_Set, Save_ClearEventFlags, Stg20_AreaSelectUpdate, Stg20_SetSpecialFlag, Stg30_JoinCreateDigi | Digi_AddNew, Flag_Set, Flag_Test, Menu_NameEntryTask, Save_ClearEventFlags, Save_ResetGameState, Stg20_AddBits, Stg20_ApplyStartPreset +47 | The save block (GameState, 0x1058): tamer name, rank, bits, play time, DigiBeetle hp/mp and part slots, item bag, 0x24-slot digimon roster, item storage, event flags. The memory card writes it whole. |

### stag1100 (memory card / VS party)

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg11_VsParty` | stag1100/vsparty.c | `Stg11Party` | 0x120 | Stg11_StateSelectSlot | Stg11_StateSelectSlot, Stg11_StateVsPartySelect, Stg11_VsPartyBuildList, Stg11_VsPartyPick | VS party pick: GameState * of the memory card slot + the 3 chosen DigiRosterEntry copies (one player at a time). |

## WORLD

### main (SLUS_011.93), simulation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Dung_StatePtr` | main/12550.c | `DungState *` | 0x4 | - | Bug_CompactMemBugs, Bug_GetMaxMemBugLevel, Item_UseOnBeetle, Menu_BuildDigiList, Menu_OpenBugTexts, Menu_StatusTask, Menu_UseBugZapItem, Stg00_DungSelPickFlag +75 | Constant pointer to Dung_State (all users but two stag3000 functions go through it). |
| `Sys_VsPartyConfirmed` | main/skill.c | `s32` | 0x4 | Stg11_RootUpdate, Stg11_StateVsPartySelect, Stg11_VsPartyUpdate | Stg11_StateVsPartySelect, Stg35_RootUpdate | VS mode: YES to "Digi-Line OK?" (SYS_MESS 0x1AA); stag1100 then copies the picked party into Save_GameState.elems, stag3500 reads it as modeArg. Declared s16 in the overlays. |
| `Flag_EntryIter` | main/flagtable.c | `FlagEntryState` | 0x3C | Flag_SetTableFile | Flag_FirstPassingEntry, Flag_GetBranchCondBlock, Flag_GetBranchSetBlock, Flag_GetEntry, Flag_GetEntryCondBlock, Flag_GetEntryPosList, Flag_GetTableBase, Flag_NextPassingEntry +1 | Iterator over the current event flag table file (Flag_SetTableFile): which entry / branch passes the flag tests. Event script state. |
| `Dung_State` | main/12550.c | `DungState` | 0x1080 | - | Stg30_BattleWonUpdate, Stg30_FightBgUpdate, Stg30_GetFloorSpecialty, Stg30_InitBattle | Dungeon session (DungState, 0x1080): floor, entities ents[41], party status and bugs (DungStatus), chests, hazards, traps, cell grid, automap bits, turn queue, encounters, floor specialty, gift level. |

### main (SLUS_011.93), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Bug_LastZappedLevel` | main/itemeffect.c | `u8` | 0x1 | Item_UseOnBeetle | Menu_UseBugZapItem | Level of the bug the last Bug Zapper item removed, for the menu message. |
| `Menu_TopMenuResult` | main/topmenu.c | `s32` | 0x4 | Menu_TopMenuTask | Stg20_StageMain, Stg40_RootUpdate | Result of the field top menu; stag2000 / stag4000 root tasks read it. |
| `Menu_Ctx` | main/topmenu.c | `MenuCtx *` | 0x4 | Menu_TopMenuTask | Menu_BlinkOrHideParts, Menu_BuildDigiList, Menu_ConfirmMultiPick, Menu_ConfirmSinglePick, Menu_DigiListTask, Menu_DigiStatusInit, Menu_DigiStatusTask, Menu_DigiTransferPickSrc +18 | Field menu context (MenuCtx, heap): picked item / records, cursor, results; shared by all field menu tasks. |
| `Menu_PartGridSlots` | main/itemuse.c | `u8 *` | 0x4 | Menu_ItemUseTask | Menu_OpenItemNameTexts, Menu_ShowPartSlotInfo, Menu_UseItemOnTarget | Item use menu: current part grid slot table. |
| `Menu_PartGridLabels` | main/itemuse.c | `u8 *` | 0x4 | Menu_ItemUseTask | Menu_ShowPartSlotInfo | Item use menu: current part grid label table. |
| `Text_ReturnStack` | main/text.c | `TextStack` | 0x28 | Text_PopReturn, Text_PushReturn, Text_UpdateAllBoxes | Text_PopReturn, Text_PushReturn | Text script call stack (Text_PushReturn / Text_PopReturn). |

### stag1000 (title / movies), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg10_AttractCount` | stag1000/title.c | `s32` | 0x4 | Stg10_TitleUpdate | Stg10_TitleUpdate | Title idle timeouts: the first goes to mode 0x403, later ones to 0x402; wraps at 20. |

### stag1100 (memory card / VS party), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg11_LoadDone` | stag1100/vsparty.c | `s16` | 0x2 | Stg11_ModeMenuInit, Stg11_StateSelectSlot, Stg11_VsPartyUpdate | Stg11_ModeMenuUpdate | Set when a card save is loaded or a VS party is confirmed; the mode menu checks it. |

### stag2000 (city), simulation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg20_MapGrid` | stag2000/mapbg.c | `u8[24][24]` | 0x240 | - | Stg20_BuildMapGrid, Stg20_GetGridCell, Stg20_MarkGridOccupant | City map grid 24x24 (Stg20_BuildMapGrid, Stg20_MarkGridOccupant, Stg20_GetGridCell). |
| `Stg20_CellTmp` | stag2000/areaselect.c | `Stg20Cell` | 0x4 | Stg20_GetActorCell | Stg20_GetActorCell | Scratch cell result of Stg20_GetActorCell. |

### stag2000 (city), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg20_MenuState` | stag2000/areaselect.c | `Stg20MenuState` | 0x58 | Stg20_BeetleShopMenuUpdate, Stg20_BeetleShopUpdate, Stg20_DigiLabUpdate, Stg20_ItemShopMenuUpdate, Stg20_ItemShopUpdate, Stg20_LabDigivolve, Stg20_LabDnaDigivolve, Stg20_LabInfoUpdate +4 | Stg20_BeetleShopMenuDraw, Stg20_BeetleShopMenuUpdate, Stg20_BeetleShopUpdate, Stg20_CameraUpdate, Stg20_DigiLabUpdate, Stg20_FormatPrice, Stg20_IsCellBlocked, Stg20_ItemShopMenuDraw +20 | City menus: shop, lab (digivolve / DNA picks), area select results. |
| `Stg20_ShopItems` | stag2000/shoplist.c | `Stg20ShopList` | 0x546 | - | Stg20_LoadShopBuyList, Stg20_LoadShopSellList, Stg20_ShopListRefresh, Stg20_ShopListUpdate | Current shop buy / sell list. |

### stag3000 (battle), simulation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg30_RepeatSkillCount` | stag3000/skilleffect.c | `s32` | 0x4 | Stg30_BuildSkillScript | Stg30_BuildSkillScript | Hits left of a repeating skill (1..3 random, Stg30_BuildSkillScript). |
| `Stg30_BattleScript` | stag3000/skilleffect.c | `s16[0xC8]` | 0x190 | Stg30_BuildGuardScript | Stg30_BattleScriptTask, Stg30_BuildGuardScript, Stg30_BuildItemScript, Stg30_BuildSkillScript | Action script of the current turn (s16 opcodes the script task plays). |
| `Stg30_TurnOrder` | stag3000/battlestate.c | `s32[12]` | 0x30 | - | Stg30_TurnOrderClear, Stg30_TurnOrderFind, Stg30_TurnOrderFreeIndex, Stg30_TurnOrderGet, Stg30_TurnOrderInsert, Stg30_TurnOrderRemove | Turn order list of the round (slot ids). |
| `Stg30_FighterStateBackup` | stag3000/battlestate.c | `Stg30FighterBackup` | 0x270 | - | Stg30_RestoreFighterStates, Stg30_SaveFighterStates | Copy of the fighters, status and stat buffs taken before each action; restored when an interrupt cuts in (Stg30_BattleUpdate). |
| `Stg30_Battle` | stag3000/battlestate.c | `Stg30Battle` | 0x3E0 | Stg30_BattleUpdate, Stg30_BuildSkillScript, Stg30_CommandInputTask, Stg30_InitBattle, Stg30_InterruptSelectTask, Stg30_ItemMenuUpdate, Stg30_SkillMenuUpdate, Stg30_TargetSelectUpdate | Stg30_ActionLoadUpdate, Stg30_AiCanUseAction, Stg30_AiCheckCondition, Stg30_ApplyItemEffect, Stg30_ApplySkillDamage, Stg30_ApplySkillStatus, Stg30_BannerDraw, Stg30_BattleDestroy +40 | Battle state (Stg30Battle, 0x3E0): command header, digis[6] (0..2 party copies, 3..5 enemies), enemy AI, turns, status, stat buffs, item / target picks, join candidate, boss flag. |
| `Stg30_BattleDigis` | stag3000/battlestate.c | alias of `Stg30_Battle+0x018` | - | - | Stg30_AiChooseEnemyTurns, Stg30_ApplyItemEffect, Stg30_ApplySkillDamage, Stg30_FighterHudDraw | Alias of Stg30_Battle.digis (Stg30_Battle + 0x18); retail reaches the fighter block through it. |
| `Stg30_BattleDigiNames` | stag3000/battlestate.c | alias of `Stg30_Battle+0x064` | - | - | Stg30_FighterHudUpdate, Stg30_ResultUpdate, Stg30_SkillLearnUpdate | Alias of Stg30_Battle.digis[0].name (Stg30_Battle + 0x64). |

### stag3000 (battle), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg30_CommandMenuCursor` | stag3000/commandmenu.c | `s32` | 0x4 | Stg30_CommandMenuUpdate | Stg30_CommandMenuDraw, Stg30_CommandMenuUpdate | Command menu cursor. |
| `Stg30_ItemMenuColumn` | stag3000/itemmenu.c | `s16` | 0x2 | Stg30_ItemMenuUpdate | Stg30_ItemMenuDraw, Stg30_ItemMenuRefreshText, Stg30_ItemMenuUpdate | Battle item menu column. |
| `Stg30_ItemMenuRow` | stag3000/itemmenu.c | `s16[3]` | 0x6 | Stg30_ItemMenuUpdate | Stg30_ItemMenuDraw, Stg30_ItemMenuRefreshText, Stg30_ItemMenuUpdate | Battle item menu row per column. |
| `Stg30_ItemMenuScroll` | stag3000/itemmenu.c | `s16[3]` | 0x6 | Stg30_ItemMenuUpdate | Stg30_ItemMenuDraw, Stg30_ItemMenuRefreshText, Stg30_ItemMenuUpdate | Battle item menu scroll per column. |
| `Stg30_SkillMenuColumn` | stag3000/skillmenu.c | `s16` | 0x2 | Stg30_SkillMenuUpdate | Stg30_SkillMenuDraw, Stg30_SkillMenuRefreshText, Stg30_SkillMenuUpdate | Battle skill menu column. |
| `Stg30_SkillMenuRow` | stag3000/skillmenu.c | `s16[4]` | 0x8 | Stg30_SkillMenuUpdate | Stg30_SkillMenuDraw, Stg30_SkillMenuRefreshText, Stg30_SkillMenuUpdate | Battle skill menu row per column. |
| `Stg30_SkillMenuScroll` | stag3000/skillmenu.c | `s16[4]` | 0x8 | Stg30_SkillMenuUpdate | Stg30_SkillMenuDraw, Stg30_SkillMenuRefreshText, Stg30_SkillMenuUpdate | Battle skill menu scroll per column. |
| `Stg30_SkillMenuLists` | stag3000/skillmenu.c | `Stg30SkillList[4]` | 0x6C | - | Stg30_SkillMenuBuildLists, Stg30_SkillMenuDraw, Stg30_SkillMenuRefreshText, Stg30_SkillMenuUpdate | Battle skill menu lists. |
| `Stg30_CamShotVariant` | stag3000/camera.c | `s32` | 0x4 | Stg30_CameraUpdate | Stg30_CameraUpdate | Battle camera: shot variant picked for the next close-up. |

### stag3500 (VS battle), simulation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg35_TurnOrder` | stag3500/turn.c | `s32[12]` | 0x30 | - | Stg35_TurnOrderClear, Stg35_TurnOrderFind, Stg35_TurnOrderFreeIndex, Stg35_TurnOrderGet, Stg35_TurnOrderInsert, Stg35_TurnOrderRemove | VS turn order list. |
| `Stg35_Battle` | stag3500/turn.c | `Stg35Battle` | 0x358 | - | Stg35_ActionLoadUpdate, Stg35_ApplySkillDamage, Stg35_BattleUpdate, Stg35_BuildCommandList, Stg35_BuildSkillScript, Stg35_BuildTurnOrder, Stg35_CameraUpdate, Stg35_ClearBattle +3 | VS battle state (Stg35Battle, 0x358): rec[6] (P1 0..2, P2 3..5 copies of Save_GameState.elems), per-slot actions, script targets. |
| `Stg35_BattleScript` | stag3500/battlescript.c | `s16[0xC8]` | 0x190 | - | Stg35_BattleScriptTask, Stg35_BuildSkillScript | VS action script of the current turn. |

### stag3500 (VS battle), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg35_CamShotVariant` | stag3500/camera.c | `s32` | 0x4 | Stg35_CameraUpdate | Stg35_CameraUpdate | VS camera shot variant. |

### stag4000 (dungeon), simulation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg40_FloorBitsPal` | stag4000/cellgrid.c | `u16[10]` | 0x14 | - | Stg40_FillCellGrid | Cell code palette; entry 7 is patched per floor from Stg40_SpecialFloorValues. |
| `Stg40_RootState` | stag4000/stag4000.c | `Stg40B60 *` | 0x4 | Stg40_RootUpdate | Stg40_AddEntity, Stg40_AiPathChase, Stg40_AiPathChaseInRoom, Stg40_AiPathFlee, Stg40_AiPathToTarget, Stg40_ApplyFloorLayout, Stg40_ApplyTrapEffect, Stg40_AutomapDraw +69 | Dungeon floor state (Stg40B60, heap 0x190): message / target / trap state, item menu list, gift shot, party picks, event tiles, AI command, hazard mask. |
| `Stg40_LabelRoomsCur` | stag4000/cellgrid.c | `s32` | 0x4 | Stg40_LabelRooms | - | Written only (room labelling counter). |

### stag4000 (dungeon), presentation

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg40_FloorTask` | stag4000/floor.c | `Actor *` | 0x4 | Stg40_FloorInit | Stg40_IsScrollDone, Stg40_ScrollFollow, Stg40_ScrollTo, Stg40_ScrollToFollow | Floor draw / scroll task. |
| `Stg40_FloorWork` | stag4000/floor.c | `Stg40FloorWork *` | 0x4 | Stg40_FloorInit | Stg40_DrawEntityShadow | Its work block. |
| `Stg40_ItemMenuTask` | stag4000/itemmenu.c | `Actor *` | 0x4 | Stg40_ItemMenuInit, Stg40_ItemMenuUpdate | Stg40_ItemMenuGetTextIds, Stg40_ItemMenuSetCursor | Dungeon item menu task (+ its work pointer). |
| `Stg40_EnemyInfoTask` | stag4000/enemyinfo.c | `Actor *` | 0x4 | Stg40_EnemyInfoUpdate | - | Enemy info window task. |
| `Stg40_MsgWinTask` | stag4000/msgwin.c | `Actor *` | 0x4 | Stg40_MsgWinUpdate | - | Message window task. |
| `Stg40_MsgWinTexts` | stag4000/msgwin.c | `s32 *` | 0x4 | Stg40_MsgWinUpdate | Stg40_MsgWinClose, Stg40_MsgWinGetChoice, Stg40_MsgWinIsFinished, Stg40_MsgWinOpen | Message window text handles. |
| `Stg40_DigitBufs` | stag4000/msgwin.c | `u8[4][8]` | 0x20 | - | Stg40_NumToDigits | Number-to-digits scratch strings. |
| `Stg40_AutomapWork` | stag4000/automap.c | `Stg40TileGrid *` | 0x4 | Stg40_AutomapUpdate | Stg40_AutomapRevealAll, Stg40_AutomapSetCell | Automap work (tile grid). |
| `Stg40_CameraTask` | stag4000/camera.c | `Actor *` | 0x4 | Stg40_CameraInit | Stg40_CamIsMoving, Stg40_CamLoadScript, Stg40_CamStartMove | Dungeon camera task. |

### stag4000 (dungeon), task handles

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg40_RootTask` | stag4000/stag4000.c | `Actor *` | 0x4 | Stg40_RootUpdate | Stg40_PlayerInput | The dungeon root task (Actor *). |
| `Stg40_RootChildren` | stag4000/stag4000.c | `Stg40RootTasks *` | 0x4 | Stg40_RootUpdate | Stg40_PlayerEnemyInfo, Stg40_PlayerItemMenu, Stg40_PlayerShootGift | The root task's child task table. |

## ENGINE

### main (SLUS_011.93)

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Gfx_FadeState` | main/fade.c | `FadeState` | 0xC | Gfx_DrawFade, Gfx_FadeClear, Gfx_FadeInFromBlack, Gfx_FadeInFromWhite, Gfx_FadeOutToBlack, Gfx_FadeOutToWhite, Gfx_FadeSetBlack | Gfx_DrawFade, Gfx_FadeClear, Gfx_FadeInFromBlack, Gfx_FadeInFromWhite, Gfx_FadeOutToBlack, Gfx_FadeOutToWhite, Gfx_FadeSetBlack | Screen fade (mode, speed, additive / subtractive). |
| `Gpu_PrimBufs` | main/primbuf.c | `ActorWork *[3]` | 0xC | Gpu_AllocPacketBufs, Gpu_FreePrimBufs | Gpu_AllocPacketBufs, Gpu_FreePrimBufs, Gpu_ResetPrimBuf | Primitive packet buffers (heap, Gpu_AllocPacketBufs). |
| `Gfx_PartRotCache` | main/parts.c | `GfxPartRotCache` | 0x38 | - | Gfx_DrawPartsEx | Cached rotation matrix + scale for Gfx_DrawPartsEx. |
| `Cd_ReadState` | main/cdread.c | `CdReadState` | 0x20 | Cd_PollRead, Cd_ReadFileAsync, Cd_ReadSectorCallback, Cd_ReadSyncCallback | Cd_CheckNextSector, Cd_PollRead, Cd_ReadFileAsync, Cd_ReadSectorCallback, Cd_ReadSyncCallback | Current async CD read (state, file id, sectors left, destination, next LBA). |
| `Mem_HeapStart` | main/task.c | `MemBlock *` | 0x4 | - | Sys_Main | Heap start 0x80075000 (memory map constant in .sdata; = _gp symbol address). |
| `Ovl_CurrentId` | main/gamemode.c | `s32` | 0x4 | Ovl_Load | Ovl_GetCurrentId, Ovl_Load | Id of the loaded overlay (Ovl_FileIds index), -1 at boot. |
| `Snd_CurrentId` | main/sound.c | `s32` | 0x4 | Snd_PlayById, Snd_StopAll, Snd_StopById | Snd_PlayById, Snd_SaveCurrentId, Snd_SetSlotContent, Snd_StopById | Sound id playing now, -1 none. |
| `Sys_VSyncsSinceFlip` | main/sys.c | `s32` | 0x4 | Sys_VSyncHandler | Sys_VSyncHandler | VSync count since the last buffer flip (Sys_VSyncHandler). |
| `Sys_LastVSyncTime` | main/sys.c | `s32` | 0x4 | Sys_Main | Sys_Main | VSync counter at the last frame (Sys_Main frame pacing). |
| `Sys_MovieActive` | main/sys.c | `u8` | 0x1 | Stg10_MovieDestroy, Stg10_MovieInit | - | Set while a stag1000 movie plays; nothing reads it. |
| `Cd_QueueActive` | main/cd.c | `s32` | 0x4 | Cd_QueueFile, Cd_ServiceQueue | Cd_ServiceQueue | The file queue is being serviced. |
| `D_80050758` | main/task.c | `s32` | 0x4 | Sys_Start | Sys_Start | First .sbss word: crt0 (Sys_Start) clears from here to the end of bss. |
| `Cd_PreloadCount` | main/cdpreload.c | `s32` | 0x4 | Stg40_AddPreloadId, Stg40_ClearPreloadList | Cd_QueueStag4000Files, Stg40_AddPreloadId | Count of Cd_PreloadIds. |
| `Snd_SavedId` | main/sound.c | `s32` | 0x4 | Snd_SaveCurrentId | Snd_RestoreSavedId | Snd_CurrentId saved around name entry (Snd_SaveCurrentId / Snd_RestoreSavedId). |
| `Skill_ShotXaFile` | main/skill.c | `s32` | 0x4 | Skill_GetShotXa | Skill_GetShotXa | XA file of the current skill shot (Skill_GetShotXa result, first word). |
| `Skill_ShotXaChannel` | main/skill.c | `s32` | 0x4 | Skill_GetShotXa | - | XA channel (CdlSetfilter) of Skill_ShotXaFile. |
| `Mem_HeapSize` | main/mem.c | `s32` | 0x4 | Mem_InitHeap | - | Heap size given to Mem_InitHeap. |
| `Mem_HeapHead` | main/mem.c | `MemBlock *` | 0x4 | Mem_InitHeap | Mem_FreeTag, Mem_GetLargestFree, Mem_SumSizesByTag, Mem_TryAlloc | First heap block. |
| `Sys_FlipPending` | main/sys.c | `s32` | 0x4 | Sys_Main, Sys_VSyncHandler | Sys_Main, Sys_VSyncHandler | A buffer flip waits for the VSync handler. |
| `Rand_Index` | main/sys.c | `s32` | 0x4 | Rand_Seed, Rand_Step | Rand_Next, Rand_Step | Index into Rand_Table: the one random stream of the game (Rand_Seed / Rand_Step / Rand_Next). |
| `Task_List` | main/task.c | `TaskList` | 0x1A0 | Task_Alloc, Task_ClearList | Task_Alloc, Task_ClearList, Task_FindNext, Task_Free | The task list: count + 100 entries. |
| `Task_FindFilter` | main/task.c | `TaskFindFilter` | 0x10 | Task_FindFirst | Task_FindFirst, Task_FindNext | Task_FindFirst / Task_FindNext iterator state. |
| `Cd_PreloadIds` | main/cdpreload.c | `s32[0x40]` | 0x100 | - | Cd_QueueStag4000Files, Stg40_AddPreloadId, Stg40_ClearPreloadList | CD file ids stag4000 asks main to queue (Cd_QueueStag4000Files). |
| `Snd_SeqAttrTable` | main/sound.c | `u8[176*6*16]` | 0x4200 | - | Snd_Init | SEQ attribute work area given to the sound library (Snd_Init). |
| `Snd_Slots` | main/sound.c | `SndSlot[3]` | 0x84 | - | Snd_AnySlotLoading, Snd_Init, Snd_PlayById, Snd_ServiceSlotLoads, Snd_SetSlotContent, Snd_StopAll, Snd_StopById, Snd_UnloadSlot | 3 sound bank slots (content id, load state, VAB id, SEQ ids, VB/VH file ids). |
| `Gpu_OtBufs` | main/ot.c | `GpuOtBuf[2]` | 0x8060 | - | Gpu_ClearOt, Gpu_DrawOt, Gpu_SetLayerOtPtrs, Gpu_SetOtLayout, Gpu_SkipEmptyOtEntries | Two ordering tables (double buffer), 0x100C words each. |
| `Gpu_OtLayoutMode` | main/ot.c | `s32[2]` | 0x8 | - | - | OT layout word; code reads it only as Gpu_OtBufs[2].entries[0] (one past the two tables). |
| `Gfx_TexSlots` | main/texslot.c | `GfxTexSlot[0x40]` | 0x800 | - | Gfx_FindOrLoadTexSlot, Gfx_GetTexSlot, Gfx_InitTexSlots, Gfx_ReserveTexSlot | 0x40 VRAM texture slots (file id, VRAM x/y, tpage, colour mode, last use). |
| `Pad_PortButtons` | main/pad.c | `Elm678[2]` | 0x30 | - | Pad_PollPort, Pad_Update | Raw button words per port (Pad_PollPort). |
| `Pad_RecvBufs` | main/pad.c | `u8[0x48]` | 0x48 | - | Pad_Init, Pad_Update | Pad receive buffers handed to PadInitDirect. |
| `Pad_State` | main/pad.c | `PadState[2]` | 0x80 | - | Menu_ConfirmMultiPick, Menu_ConfirmSinglePick, Menu_DigiListTask, Menu_DigiStatusTask, Menu_DigiTransferPickSrc, Menu_DigiTransferPlace, Menu_ItemTask, Menu_ItemUseTask +64 | Per port input (PadState[2]): button words, held / pressed / repeat masks, connected. Pad_State[0] = player 1, [1] = player 2. |
| `Pad_Cross` | main/pad.c | alias of `Pad_State+0x14` | - | - | Stg20_BeetlePartsUpdate | Alias of Pad_State[0].cross (Pad_State + 0x14) kept for one scalar read in Stg20_BeetlePartsUpdate. |
| `Sys_State` | main/sys.c | `SysState` | 0x158 | Gfx_AddQuadsGT4, Gfx_AddTrisGT3, Gfx_AnimateModelTex, Gfx_DrawPartQuadsRot, Gfx_DrawPartSprites, Gfx_DrawWireQuads, Gfx_DrawWireTris, Gfx_FadeInFromBlack +25 | Anim_StepModelAnim, Cd_FindLruCachedFile, Cd_GetFileState, Cd_GetFileSync, Cd_QueueFile, Cd_ServiceQueue, Digi_InitFromTable, Enemy_InitRosterEntry +90 | Frame and display state (SysState, 0x158): frame counters, frame delta, draw pass, gameMode / nextGameMode / prevGameMode / modeArg (the scene switch), double buffer index, packet cursor, draw/disp envs, OT layer pointers. |
| `Sys_GameMode` | main/sys.c | alias of `Sys_State+0x18` | - | - | Stg20_StageMain | Alias of Sys_State.gameMode (Sys_State + 0x18) kept for Stg20_StageMain's scalar loads. |
| `Cd_FileCache` | main/cd.c | `CdCacheEntry[0x50]` | 0x500 | - | Cd_ClearFileCache, Cd_FindCachedFile, Cd_FindFreeCacheSlot, Cd_FindLruCachedFile, Cd_FreeUnlockedFiles, Cd_ServiceQueue | 0x50 loaded file slots (state, lock, file id, last use, data pointer). |
| `Cd_SectorHeader` | main/cdread.c | `u8[0x10]` | 0x10 | - | Cd_CheckNextSector | Header bytes of the last sector read. |

### stag1000 (title / movies)

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg10_StrWidth` | stag1000/movie.c | `s32` | 0x4 | Stg10_StrNext | Stg10_StrNext | Movie frame width. |
| `Stg10_StrHeight` | stag1000/movie.c | `s32` | 0x4 | Stg10_StrNext | Stg10_StrNext | Movie frame height. |
| `Stg10_StrRingBuf` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_StrInit | STR ring buffer (heap). |
| `Stg10_VlcBuf0` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_StrSetDefDecEnv | MDEC VLC buffer 0 (heap). |
| `Stg10_VlcBuf1` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_StrSetDefDecEnv | MDEC VLC buffer 1 (heap). |
| `Stg10_ImgBuf0` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_StrSetDefDecEnv | Decoded image buffer 0 (heap). |
| `Stg10_ImgBuf1` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_StrSetDefDecEnv | Decoded image buffer 1 (heap). |
| `Stg10_StrEndFlag` | stag1000/movie.c | `s32` | 0x4 | Stg10_MovieUpdate, Stg10_StrNext | Stg10_MovieUpdate | Movie reached its last frame. |
| `Stg10_MovieFileId` | stag1000/movie.c | `s32` | 0x4 | Stg10_MovieInit | Stg10_MovieUpdate | CD file id of the movie playing. |
| `Stg10_MovieEndFrame` | stag1000/movie.c | `s32` | 0x4 | Stg10_MovieInit | Stg10_StrNext | Last frame number of the movie. |
| `Stg10_DecEnv` | stag1000/movie.c | `StrDecEnv` | 0x38 | - | Stg10_MovieUpdate, Stg10_StrCallback | MDEC decode environment. |
| `Stg10_VlcTable` | stag1000/movie.c | `u32 *` | 0x4 | Stg10_MovieUpdate | Stg10_MovieDestroy, Stg10_MovieUpdate, Stg10_StrNextVlc | Unpacked VLC table (heap, from Stg10_VlcTablePacked). |

### stag1100 (memory card / VS party)

| Global | File | Type | Size | Written by | Read by (load / address) | Meaning |
|---|---|---|---|---|---|---|
| `Stg11_CardTask` | stag1100/card.c | `Actor *` | 0x4 | Stg11_CardTaskUpdate | Stg11_CardGetDataBuf, Stg11_CardGetProgress, Stg11_CardGetResult, Stg11_CardGetTransferBuf, Stg11_CardInitHeader, Stg11_CardSetFileName, Stg11_CardSetTitle, Stg11_CardStartOp | The memory card task (Actor *) that runs card operations. |
| `Stg11_CardWork` | stag1100/card.c | `Stg11SaveWork *` | 0x4 | Stg11_CardTaskUpdate | Stg11_CardFileOp | Work block of the memory card task. |

## State on the heap, reached from globals

Most per-scene state lives in task work blocks on the heap (`Task_Create` allocates `TaskDesc.workSize` bytes).
Globals that point into the heap:

- `Menu_Ctx` (`MenuCtx`): the field menu context.
- `Stg40_RootState` (`Stg40B60`, 0x190 bytes from `Mem_Alloc`): dungeon floor state.
- `Stg40_FloorWork`, `Stg40_AutomapWork`, `Stg11_CardWork`: task works of single tasks.
- `Gpu_PrimBufs`, the stag1000 movie buffers (`Stg10_StrRingBuf`, `Stg10_VlcBuf0/1`, `Stg10_ImgBuf0/1`, `Stg10_VlcTable`).
- `Cd_FileCache` entries point at loaded files (heap).

## CONST tables

Read-only data, by file. Task descriptors (`*Desc`, `*TaskDescs`) are the task tables: `Task_DescTable[0]` =
`Task_MainDescs`, `[1..7]` = each overlay's `StgXX_TaskDescs` (task id = table << 8 | row). Two tables are
written: `Gfx_PartRotCache` (a cache, listed under ENGINE) and `Stg40_FloorBitsPal[7]` (patched per floor, WORLD).

### main

- main/156C.c: `Task_MainDescs`, `Task_DescTable`
- main/portrait.c: `Text_PortraitQuadGrid`, `Text_PortraitDesc`
- main/faceslot.c: `Gfx_FaceImageIds`, `Gfx_TexSlotDesc`
- main/nameentry.c: `Menu_NameEntryRowStride`, `Menu_NameEntryPageCol`, `Menu_NameEntryDesc`
- main/gamemode.c: `Ovl_FileIds`, `Sys_GameModeDesc`
- main/topmenu.c: `Menu_TopMenuDesc`
- main/submenu.c: `Menu_SubMenuDesc`
- main/status.c: `Menu_StatusDesc`
- main/itemuse.c: `Menu_ItemUseDesc`, `Menu_ItemUseMsgPos`
- main/itemmenu.c: `Menu_ItemSubTasks`, `Menu_ItemDesc`, `Menu_ItemMsgPos`, `Menu_ItemNamePos`
- main/digilist.c: `Menu_DigiListGrid`, `Menu_DigiListSubTasks`, `Menu_DigiListTitlePos`, `Menu_DigiListRowMasks`, `Menu_DigiListDesc`, `Menu_DigiMsgPos`, `Menu_DigiListCursorTextPos`
- main/digistatus.c: `Menu_DigiStatusView`, `Menu_DigiStatusDesc`
- main/skilllist.c: `Menu_SkillPaneMasks`, `Menu_SkillListDesc`, `Menu_SkillMsgPos`
- main/spawnlist.c: `Task_SpawnListDesc`
- main/winframe.c: `Text_WinFrameParts`, `Text_WinFrameDesc`
- main/sound.c: `Snd_BankDescs`, `Snd_SlotBufSizes`, 25 sound bank rows (`Snd_Bank*`, one per VB file)
- main/text.c: `Text_SfxIds`, `Text_BuiltinStrings`, `Text_BoxDesc`, 67 `Text_Word_*` dictionary words
- main/ot.c: `Gpu_OtLayerLens`, `Gpu_OtLayerOffsets`
- main/shadow.c: `Gfx_ShadowDesc`
- main/anim.c: `Gfx_FlatLights`
- main/savedata.c: `Beetle_PartDigiCapacity`
- main/sys.c: `Rand_Table`, `Gfx_ZeroVector`, `Gfx_IdentityMatrix`, `Gfx_MatrixScaleX2`, `Gfx_MatrixScaleY2`, `Gfx_MatrixScaleXY2`, `Sys_BootImageRect`, `Gfx_ZeroSVector`, `Gfx_NeutralRgb`
- main/cd.c: `Cd_FileLba`, `Cd_FileSectors`, `Cd_FileCount`
- main/fxmodel.c: `Fx_ModelDesc`
- main/mem.c: `Digi_StateSortRank`

### stag1000

- stag1000/stag1000.c: `Stg10_VramClearRect`, `Stg10_MovieFileIds`, `Stg10_StageSetupDesc`
- stag1000/title.c: `Stg10_TitleDesc`
- stag1000/endscreen.c: `Stg10_EndScreenDesc`
- stag1000/movie.c: `Stg10_VramClearRect2`, `Stg10_MovieDesc`, `Stg10_TaskDescs`
- stag1000/stag1000_tail.c: `Stg10_VlcTablePacked`

### stag1100

- stag1100/stag1100.c: `Stg11_RootDesc`
- stag1100/bg.c: `Stg11_BgDesc`
- stag1100/modemenu.c: `Stg11_ModeHelpPos`, `Stg11_ModeMenuDesc`
- stag1100/cardmenu.c: `Stg11_PromptPos`, `Stg11_StatusPos`, `Stg11_TransferCountPos`, `Stg11_CardMenuDesc`
- stag1100/vsparty.c: `Stg11_VsPartyLayout`, `Stg11_VsPromptPos`, `D_80068208`, `Stg11_VsRowMasks`, `Stg11_VsPartyDesc`
- stag1100/card.c: `Stg11_CardIconTim1`, `Stg11_CardIconImage`, `Stg11_CardIconTim2`, `Stg11_CardIcon2`, `Stg11_CardIconTim3`, `Stg11_CardIcon3`, `Stg11_CardTaskDesc`, `Stg11_TaskDescs`

### stag2000

- stag2000/mapbg.c: `Stg20_ShakeOffsets`, `Stg20_MapBgDesc`
- stag2000/staticbg.c: `Stg20_StaticBgDesc`
- stag2000/digilab.c: `Stg20_DigiLabDesc`
- stag2000/itemshop.c: `Stg20_ItemShopDesc`
- stag2000/beetleshop.c: `Stg20_EngineHpTbl`, `Stg20_BatteryEpTbl`, `Stg20_BeetleShopDesc`
- stag2000/stag2000.c: `Stg20_StageMainDesc`
- stag2000/areaselect.c: `Stg20_StartPreset0`, `Stg20_StartPreset1`, `Stg20_PresetDigiNames`, `Stg20_MoveParams`, `Stg20_DirCellDelta`, `Stg20_AreaIconHideMasks`, `Stg20_AreaScreenPartsIds`, `Stg20_AreaSelectDesc`
- stag2000/labmodesel.c: `Stg20_LabModeSelDesc`
- stag2000/labroster.c: `Stg20_LabRosterTextPos`, `Stg20_LabRosterPanelIds`, `Stg20_LabRosterDesc`
- stag2000/msgwin.c: `Stg20_MsgWinDesc`
- stag2000/labcaption.c: `Stg20_LabCaptionPos`, `Stg20_LabCaptionDesc`
- stag2000/labinfo.c: `Stg20_LabInfoTextPos`, `Stg20_DigivolveRuleTbl`, `Stg20_LabInfoDesc`
- stag2000/labskills.c: `Stg20_LabSkillsCursorPos`, `Stg20_LabSkillsTextPos`, `Stg20_LabSkillsColHideMasks`, `Stg20_LabSkillsArrowBlinkMasks`, `Stg20_LabSkillsDesc`
- stag2000/labpair.c: `Stg20_LabPairNamePos`, `Stg20_LabPairDesc`
- stag2000/dna.c: `Stg20_DnaTypeIndexTbl`, `Stg20_DnaResultTbl`
- stag2000/shadow.c: `Stg20_ShadowDesc`
- stag2000/labjogbg.c: `Stg20_LabJogBgDesc`
- stag2000/labdigimodel.c: `Stg20_LabDigiModelDesc`
- stag2000/mapexit.c: `Stg20_MapExitDesc`
- stag2000/walker.c: `Stg20_DirAngles`, `Stg20_WalkerDesc`, `Stg20_TaskDescs`
- stag2000/xastream.c: `Stg20_XaStreamDesc`
- stag2000/shopbg.c: `Stg20_ShopBgDesc`
- stag2000/shopbits.c: `Stg20_ShopBitsDesc`
- stag2000/itemshopmenu.c: `Stg20_ItemShopMenuDesc`
- stag2000/beetleshopmenu.c: `Stg20_BeetleShopMenuDesc`
- stag2000/shoplist.c: `Stg20_ShopListTextPos`, `Stg20_PartsAnyBody`, `Stg20_ShooterGunAmmo`, `Stg20_ZCannonAmmo`, `Stg20_PartsAdmantOnly`, `Stg20_PartsSteelOnly`, `Stg20_PartsNotAdmant`, `Stg20_PartsTitanOnly`, `Stg20_PartsNotSteel`, `Stg20_MissileGunAmmo`, `Stg20_RCannonAmmo`, `Stg20_ShopListDesc`
- stag2000/beetleparts.c: `Stg20_BeetlePartsTextPos`, `Stg20_PartsPageCategory`, `Stg20_PartsPageSlot`, `Stg20_BodyDiagramParts`, `Stg20_BeetlePartsDesc`
- stag2000/partsupgrade.c: `Stg20_UpgradeTextPos`, `Stg20_UpgradeSlots`, `Stg20_PartsUpgradeDesc`
- stag2000/warppad.c: `Stg20_WarpPads`, `Stg20_WarpPadDesc`
- stag2000/camera.c: `Stg20_CameraDesc`

### stag3000

- stag3000/banner.c: `Stg30_BannerParts`, `Stg30_BannerDesc`
- stag3000/fightbg.c: `Stg30_FightBgModels`, `Stg30_SpecialFightBgModel`, `Stg30_FightBgByFloorElem`, `Stg30_FightBgDesc`
- stag3000/actionload.c: `Stg30_ActionLoadDesc`
- stag3000/commandinput.c: `Stg30_CommandInputDesc`
- stag3000/commandmenu.c: `Stg30_CursorBlinkPalettes`, `Stg30_CommandMenuDesc`
- stag3000/itemmenu.c: `Stg30_ItemListTextPos`, `Stg30_ItemColumnLabelPos`, `Stg30_ItemMenuArrowBlinkMasks`, `Stg30_ItemMenuColHideMasks`, `Stg30_ItemMenuCursorPos`, `Stg30_ItemMenuDesc`
- stag3000/skillmenu.c: `Stg30_SkillListTextPos`, `Stg30_SkillColumnLabelPos`, `Stg30_SkillMenuArrowBlinkMasks`, `Stg30_SkillMenuCursorPos`, `Stg30_SkillMenuColHideMasks`, `Stg30_SkillMenuDesc`
- stag3000/targetselect.c: `Stg30_TargetCursorMasks`, `Stg30_TargetAllEnemiesMask`, `Stg30_TargetAllAlliesMask`, `Stg30_TargetSelectDesc`
- stag3000/battle.c: `Stg30_JoinChance`, `Stg30_BattleDesc`
- stag3000/turn.c: `Stg30_StatusWearOff4Masks`, `Stg30_StatusWearOff4Labels`, `Stg30_StatusWearOff3Masks`, `Stg30_StatusWearOff3Labels`
- stag3000/skilleffect.c: `Stg30_CureStatusMasks`, `Stg30_CureStatusLabels`
- stag3000/battlescript.c: `Stg30_BattleScriptDesc`
- stag3000/fighter.c: `Stg30_HitReactHop1Motion`, `Stg30_HitReactHop2Motion`, `Stg30_HitReactPushMotion`, `Stg30_FighterDesc`
- stag3000/fightmsg.c: `Stg30_FightMsgParts`, `Stg30_FightMsgDesc`
- stag3000/popup.c: `Stg30_PopupItemMasks`, `Stg30_PopupNumMasks`, `Stg30_PopupNumParts`, `Stg30_PopupDesc`
- stag3000/interruptselect.c: `Stg30_InterruptCursorMasks`, `Stg30_InterruptSelectDesc`, `Stg30_TaskDescs`
- stag3000/xaplay.c: `Stg30_XaTrackStart`, `Stg30_XaTrackLength`, `Stg30_XaPlayDesc`
- stag3000/camera.c: `Stg30_CloseUpRotY`, `Stg30_CloseUpVpz`, `Stg30_CloseUpVry`, `Stg30_CameraDesc`
- stag3000/fighterhud.c: `Stg30_FighterHudFadeDelay`, `Stg30_FighterHudNamePos`, `Stg30_OrderLabelMsgs`, `Stg30_OrderLabelPos`, `Stg30_FighterHudParts`, `Stg30_StatusIconGroups`, `Stg30_StatusIconFlags`, `Stg30_StatusIconPos`, `Stg30_FighterHudDesc`
- stag3000/result.c: `Stg30_HpMpGrowth`, `Stg30_AtkDefGrowth`, `Stg30_SpeedGrowth`, `Stg30_ResultTextLayout`, `Stg30_ResultParts`, `Stg30_ResultDesc`
- stag3000/skilllearn.c: `Stg30_SkillLearnTextPos`, `Stg30_SkillLearnDesc`
- stag3000/joinprompt.c: `Stg30_JoinPromptTextPos`, `Stg30_MemoryCapacity`, `Stg30_JoinPromptDesc`

### stag3500

- stag3500/bg.c: `Stg35_BgDesc`
- stag3500/fightbg.c: `Stg35_FightBgDesc`
- stag3500/actionload.c: `Stg35_ActionLoadDesc`
- stag3500/stag3500.c: `Stg35_RootDesc`
- stag3500/vsmenu.c: `Stg35_VsMenuPromptMsgs`, `Stg35_VsMenuPhaseMasks`, `Stg35_VsMenuDesc`
- stag3500/matchup.c: `Stg35_MatchupLabelPos`, `Stg35_MatchupLabelMsgs`, `Stg35_MatchupPartyPos`, `Stg35_MatchupTamerPos`, `Stg35_MatchupDesc`
- stag3500/battle.c: `Stg35_BattleDesc`
- stag3500/turn.c: `Stg35_GaugeDefPercent`, `Stg35_DefaultTargets`
- stag3500/fighter.c: `Stg35_HitReactHop1Motion`, `Stg35_HitReactHop2Motion`, `Stg35_HitReactPushMotion`, `Stg35_FighterDesc`
- stag3500/roundbanner.c: `Stg35_RoundBannerDesc`, `Stg35_TaskDescs`
- stag3500/xaplay.c: `Stg35_XaTrackStart`, `Stg35_XaTrackLength`, `Stg35_XaPlayDesc`
- stag3500/hud.c: `Stg35_HpBarPosP1`, `Stg35_HpBarPosP2`, `Stg35_BattleHudDesc`
- stag3500/battlescript.c: `Stg35_BattleScriptDesc`
- stag3500/camera.c: `Stg35_CloseUpRotY`, `Stg35_CloseUpVpz`, `Stg35_CloseUpVry`, `Stg35_CameraDesc`
- stag3500/cmdlist.c: `Stg35_SkillGroup0`, `Stg35_SkillGroup1`, `Stg35_SkillGroup2`, `Stg35_SkillGroup3`, `Stg35_SkillGroup4`, `Stg35_SkillGroup5`, `Stg35_SkillGroups`
- stag3500/winbanner.c: `Stg35_WinBannerDesc`

### stag4000

- stag4000/stag4000.c: `Stg40_FloorFileIds`, `Stg40_RootDesc`
- stag4000/linkedmodel.c: `Stg40_LinkedModelTable`, `Stg40_LinkedModelDesc`
- stag4000/floor.c: `Stg40_FloorPrimIdx`, `Stg40_ShadowPrimIdx`, `Stg40_WallPrimIdx`, `Stg40_WallSides`, `Stg40_FloorDesc`
- stag4000/hud.c: `Stg40_HudLabels`, `Stg40_HudParts`, `Stg40_HudDesc`
- stag4000/bitswin.c: `Stg40_BitsLabelText`, `Stg40_BitsWinDesc`
- stag4000/itemmenu.c: `Stg40_ItemMenuParts`, `Stg40_ItemMenuDesc`
- stag4000/enemyinfo.c: `Stg40_EnemyInfoTextPos`, `Stg40_EnemyInfoParts`, `Stg40_EnemyInfoDesc`
- stag4000/msgwin.c: `Stg40_MsgWinDesc`
- stag4000/obj.c: `Stg40_FlashPattern`, `Stg40_FlashColors`, `Stg40_ObjDesc`
- stag4000/player.c: `Stg40_DirOffsets`, `Stg40_ObstacleItemReqs`, `Stg40_GiftGunReq`, `Stg40_StatusMsgIds`, `Stg40_GiftTakeChance`, `Stg40_GiftPointsByLevel`, `Stg40_ShootMsgIds`, `Stg40_PadDirTable`
- stag4000/spawn.c: `Stg40_EnemyAiTable`, `Stg40_EnemyPaceTable`, `Stg40_TaskDescs`
- stag4000/automap.c: `Stg40_AutomapClut`, `Stg40_AutomapDesc`
- stag4000/cellgrid.c: `Stg40_SpecialFloorValues`, `Stg40_FillNeighbours`
- stag4000/trap.c: `Stg40_TrapPartSlots`, `Stg40_TrapDisarmRanks`, `Stg40_TrapDisarmChance`, `Stg40_TrapEffectTable`, `Stg40_RandomPartSlots`
- stag4000/status.c: `Stg40_HazardRevealChance`, `Stg40_BugNestRevealChance`
- stag4000/camera.c: `Stg40_CameraDesc`

## DEBUG (stag0000 test menu)

STAG0000 is the developer test menu (gameMode 0x1xx): dungeon / floor select, model and lineup viewers, sound
and XA test, window test, video mode, scroll view. Its globals are task descriptors and tables plus three
bss words (`Stg00_FontTextBuf`, `Stg00_FontWork`, `Stg00_SoundLabelBuf`). None of it is game state.

- stag0000/stag0000.c: `Stg00_StageSetupDesc`
- stag0000/scrollview.c: `Stg00_ScrollTileTex`, `Stg00_ScrollViewDesc`
- stag0000/dungsel.c: `Stg00_DungSelDesc`
- stag0000/font.c: `Stg00_FontGlyphs`, `Stg00_FontTextBuf`, `Stg00_FontWork`
- stag0000/fightbg.c: `Stg00_FightBgDesc`
- stag0000/digiview.c: `Stg00_DigiViewSkills`, `Stg00_DigiViewPages`, `Stg00_DigiViewPage2Anims`, `Stg00_DigiViewPage3Anims`, `Stg00_DigiViewDesc`
- stag0000/lineup.c: `Stg00_LineupLayouts`, `Stg00_LineupWinMasks`, `Stg00_LineupDesc`
- stag0000/videomode.c: `Stg00_VideoModeDesc`
- stag0000/groupview.c: `Stg00_GroupWinMasks`, `Stg00_GroupViewDesc`
- stag0000/digimodel.c: `Stg00_HitReactHop1Motion`, `Stg00_HitReactHop2Motion`, `Stg00_HitReactPushMotion`, `Stg00_DigiModelDesc`
- stag0000/popup.c: `Stg00_PopupItemMasks`, `Stg00_PopupNumMasks`, `Stg00_PopupNumParts`, `Stg00_PopupDesc`, `Stg00_TaskDescs`
- stag0000/xaplay.c: `Stg00_XaTrackStart`, `Stg00_XaTrackLength`, `Stg00_XaPlayDesc`
- stag0000/soundlist.c: `Stg00_SoundBanks`, `Stg00_SoundLabelBuf`, 25 `Stg00_SoundBank*` rows
- stag0000/windowtest.c: `Stg00_WindowTestMasks`, `Stg00_WindowTestParts`, `Stg00_WindowTestDesc`
- stag0000/soundtest.c: `Stg00_SoundTestTitle`, `Stg00_SoundTestDesc`
- stag0000/camera.c: `Stg00_CameraDesc`

## PSYQ library data

| Block | Range | Symbols | Used by |
|---|---|---|---|
| main 38110.data.s | 0x80047910 .. 0x80048910 | 3 | libgte sin/cos tables |
| main 395F0.data.s | 0x80048DF0 .. 0x800506E8 | 226 | library .data: interrupt and DMA callbacks, VSync count, video mode, CD, SPU, pad SIO registers, memory card; game wrappers: Cd_IntrCallback, Cd_StartDma, Pad_AllocActPower, Pad_HandleReply, Pad_InitDriverHooks, Pad_IsInitialized, Pad_ParseInfoReply, Pad_SetInitialized, Pad_SetupInfoTables, Pad_SioExchangeByte +9 |
| main 505D8.data.s | 0x8005FDD8 .. 0x800632E0 | 239 | library .bss: pad driver, libgs (GsWSMATRIX, light matrices), CD streaming (StCdIntrFlag ...), libsnd sequencer (Snd_SeqScores, Snd_MarkCallbacks), libcard task stack (Card_TaskWork, Card_TaskFuncs); game wrappers: Actor_ProjectToScreen, Cd_ClearStreamSlots, Cd_IntrCallback, Gfx_CalcModelBoneMatrices, Gfx_GetLightColorMatrix, Gfx_SetLightColorMatrix, Pad_GetPortBlock, Pad_InitDriverHooks, Pad_IsTimedOut, Pad_ParseTableReply +9 |
| stag1000 stag1000_libpress.data.s | 0x80065258 .. 0x800653D0 | 17 | libpress (MDEC) .data |

## Unused globals

Never read (alignment pads, garbage bytes kept for the matching image, written-only words). A port drops them: `D_80050794` (main), `D_80072944` (stag4000), `D_80072AA8` (stag4000), `D_80072AC0` (stag4000), `D_80072B88` (stag4000), `D_800737E4` (stag3000), `D_800737EA` (stag3000), `D_800737F6` (stag3000), `D_800737FE` (stag3000), `D_80073802` (stag3000), `D_80073818` (stag3000), `D_8007388C` (stag3000), `D_80040CF0` (main), `D_8005073C` (main), `D_80050740` (main), `D_80050742` (main), `D_800651B4` (stag1000), `D_800684A4` (stag1100), `D_80070764` (stag2000), `D_8006AA54` (stag3500), `D_800725D4` (stag4000), `D_80072A9C` (stag4000). Other unreferenced fillers carry an `/* Unreferenced */` comment in src.
