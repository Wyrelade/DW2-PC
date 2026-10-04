nonmatching Stg35_BattleUpdate, 0x9DC

glabel Stg35_BattleUpdate
    /* 1958 80064CB8 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 195C 80064CBC 5000B4AF */  sw         $s4, 0x50($sp)
    /* 1960 80064CC0 21A08000 */  addu       $s4, $a0, $zero
    /* 1964 80064CC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1968 80064CC8 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 196C 80064CCC 5800B6AF */  sw         $s6, 0x58($sp)
    /* 1970 80064CD0 5400B5AF */  sw         $s5, 0x54($sp)
    /* 1974 80064CD4 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 1978 80064CD8 4800B2AF */  sw         $s2, 0x48($sp)
    /* 197C 80064CDC 4400B1AF */  sw         $s1, 0x44($sp)
    /* 1980 80064CE0 4000B0AF */  sw         $s0, 0x40($sp)
    /* 1984 80064CE4 2C00938E */  lw         $s3, 0x2C($s4)
    /* 1988 80064CE8 1000848E */  lw         $a0, 0x10($s4)
    /* 198C 80064CEC 3400958E */  lw         $s5, 0x34($s4)
    /* 1990 80064CF0 75008210 */  beq        $a0, $v0, .L80064EC8
    /* 1994 80064CF4 02008228 */   slti      $v0, $a0, 0x2
    /* 1998 80064CF8 05004010 */  beqz       $v0, .L80064D10
    /* 199C 80064CFC 00000000 */   nop
    /* 19A0 80064D00 08008010 */  beqz       $a0, .L80064D24
    /* 19A4 80064D04 02010424 */   addiu     $a0, $zero, 0x102
    /* 19A8 80064D08 9B950108 */  j          .L8006566C
    /* 19AC 80064D0C 00000000 */   nop
  .L80064D10:
    /* 19B0 80064D10 02000224 */  addiu      $v0, $zero, 0x2
    /* 19B4 80064D14 C1018210 */  beq        $a0, $v0, .L8006541C
    /* 19B8 80064D18 00000000 */   nop
    /* 19BC 80064D1C 9B950108 */  j          .L8006566C
    /* 19C0 80064D20 00000000 */   nop
  .L80064D24:
    /* 19C4 80064D24 A369000C */  jal        Snd_PlayById
    /* 19C8 80064D28 01000524 */   addiu     $a1, $zero, 0x1
    /* 19CC 80064D2C C89D010C */  jal        Stg35_ClearBattle
    /* 19D0 80064D30 00000000 */   nop
    /* 19D4 80064D34 BE8F000C */  jal        Cd_FreeUnlockedFiles
    /* 19D8 80064D38 00000000 */   nop
    /* 19DC 80064D3C 0300043C */  lui        $a0, (0x32000 >> 16)
    /* 19E0 80064D40 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 19E4 80064D44 00208434 */   ori       $a0, $a0, (0x32000 & 0xFFFF)
    /* 19E8 80064D48 437E000C */  jal        Gfx_InitLights
    /* 19EC 80064D4C 00000000 */   nop
    /* 19F0 80064D50 5C8E000C */  jal        Sys_SetFrameRate30
    /* 19F4 80064D54 00000000 */   nop
    /* 19F8 80064D58 40010424 */  addiu      $a0, $zero, 0x140
    /* 19FC 80064D5C E0010524 */  addiu      $a1, $zero, 0x1E0
    /* 1A00 80064D60 02000624 */  addiu      $a2, $zero, 0x2
    /* 1A04 80064D64 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 1A08 80064D68 21380000 */   addu      $a3, $zero, $zero
    /* 1A0C 80064D6C 21200000 */  addu       $a0, $zero, $zero
    /* 1A10 80064D70 21288000 */  addu       $a1, $a0, $zero
    /* 1A14 80064D74 6570000C */  jal        Gpu_SetBgClearColor
    /* 1A18 80064D78 21308000 */   addu      $a2, $a0, $zero
    /* 1A1C 80064D7C 4170000C */  jal        Gpu_ClearScreens
    /* 1A20 80064D80 00000000 */   nop
    /* 1A24 80064D84 3271000C */  jal        Gfx_FadeInFromBlack
    /* 1A28 80064D88 40000424 */   addiu     $a0, $zero, 0x40
    /* 1A2C 80064D8C 09000424 */  addiu      $a0, $zero, 0x9
    /* 1A30 80064D90 2128A002 */  addu       $a1, $s5, $zero
    /* 1A34 80064D94 1F44000C */  jal        Task_Create
    /* 1A38 80064D98 21300000 */   addu      $a2, $zero, $zero
    /* 1A3C 80064D9C 06070424 */  addiu      $a0, $zero, 0x706
    /* 1A40 80064DA0 1000A526 */  addiu      $a1, $s5, 0x10
    /* 1A44 80064DA4 1F44000C */  jal        Task_Create
    /* 1A48 80064DA8 21300000 */   addu      $a2, $zero, $zero
    /* 1A4C 80064DAC 04070424 */  addiu      $a0, $zero, 0x704
    /* 1A50 80064DB0 1400A526 */  addiu      $a1, $s5, 0x14
    /* 1A54 80064DB4 1F44000C */  jal        Task_Create
    /* 1A58 80064DB8 21300000 */   addu      $a2, $zero, $zero
    /* 1A5C 80064DBC FD8E000C */  jal        Cd_QueueFile
    /* 1A60 80064DC0 FD010424 */   addiu     $a0, $zero, 0x1FD
    /* 1A64 80064DC4 FD8E000C */  jal        Cd_QueueFile
    /* 1A68 80064DC8 5B020424 */   addiu     $a0, $zero, 0x25B
    /* 1A6C 80064DCC FD8E000C */  jal        Cd_QueueFile
    /* 1A70 80064DD0 3F0D0424 */   addiu     $a0, $zero, 0xD3F
    /* 1A74 80064DD4 FD8E000C */  jal        Cd_QueueFile
    /* 1A78 80064DD8 410D0424 */   addiu     $a0, $zero, 0xD41
    /* 1A7C 80064DDC FD8E000C */  jal        Cd_QueueFile
    /* 1A80 80064DE0 930D0424 */   addiu     $a0, $zero, 0xD93
    /* 1A84 80064DE4 21380000 */  addu       $a3, $zero, $zero
    /* 1A88 80064DE8 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 1A8C 80064DEC 20E64424 */  addiu      $a0, $v0, %lo(Save_GameState)
    /* 1A90 80064DF0 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1A94 80064DF4 88AA4624 */  addiu      $a2, $v0, %lo(Stg35_Battle)
  .L80064DF8:
    /* 1A98 80064DF8 1000C324 */  addiu      $v1, $a2, 0x10
    /* 1A9C 80064DFC E4008224 */  addiu      $v0, $a0, 0xE4
    /* 1AA0 80064E00 34018524 */  addiu      $a1, $a0, 0x134
  .L80064E04:
    /* 1AA4 80064E04 0000488C */  lw         $t0, 0x0($v0)
    /* 1AA8 80064E08 0400498C */  lw         $t1, 0x4($v0)
    /* 1AAC 80064E0C 08004A8C */  lw         $t2, 0x8($v0)
    /* 1AB0 80064E10 0C004B8C */  lw         $t3, 0xC($v0)
    /* 1AB4 80064E14 000068AC */  sw         $t0, 0x0($v1)
    /* 1AB8 80064E18 040069AC */  sw         $t1, 0x4($v1)
    /* 1ABC 80064E1C 08006AAC */  sw         $t2, 0x8($v1)
    /* 1AC0 80064E20 0C006BAC */  sw         $t3, 0xC($v1)
    /* 1AC4 80064E24 10004224 */  addiu      $v0, $v0, 0x10
    /* 1AC8 80064E28 F6FF4514 */  bne        $v0, $a1, .L80064E04
    /* 1ACC 80064E2C 10006324 */   addiu     $v1, $v1, 0x10
    /* 1AD0 80064E30 0000488C */  lw         $t0, 0x0($v0)
    /* 1AD4 80064E34 0400498C */  lw         $t1, 0x4($v0)
    /* 1AD8 80064E38 08004A8C */  lw         $t2, 0x8($v0)
    /* 1ADC 80064E3C 000068AC */  sw         $t0, 0x0($v1)
    /* 1AE0 80064E40 040069AC */  sw         $t1, 0x4($v1)
    /* 1AE4 80064E44 08006AAC */  sw         $t2, 0x8($v1)
    /* 1AE8 80064E48 5C008424 */  addiu      $a0, $a0, 0x5C
    /* 1AEC 80064E4C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 1AF0 80064E50 0600E228 */  slti       $v0, $a3, 0x6
    /* 1AF4 80064E54 E8FF4014 */  bnez       $v0, .L80064DF8
    /* 1AF8 80064E58 5C00C624 */   addiu     $a2, $a2, 0x5C
    /* 1AFC 80064E5C 21800000 */  addu       $s0, $zero, $zero
    /* 1B00 80064E60 2C001224 */  addiu      $s2, $zero, 0x2C
    /* 1B04 80064E64 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1B08 80064E68 88AA5124 */  addiu      $s1, $v0, %lo(Stg35_Battle)
    /* 1B0C 80064E6C 07070424 */  addiu      $a0, $zero, 0x707
  .L80064E70:
    /* 1B10 80064E70 2128B202 */  addu       $a1, $s5, $s2
    /* 1B14 80064E74 1000A627 */  addiu      $a2, $sp, 0x10
    /* 1B18 80064E78 04005226 */  addiu      $s2, $s2, 0x4
    /* 1B1C 80064E7C 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1B20 80064E80 11002292 */  lbu        $v0, 0x11($s1)
    /* 1B24 80064E84 5C003126 */  addiu      $s1, $s1, 0x5C
    /* 1B28 80064E88 1400B0AF */  sw         $s0, 0x14($sp)
    /* 1B2C 80064E8C 01001026 */  addiu      $s0, $s0, 0x1
    /* 1B30 80064E90 1F44000C */  jal        Task_Create
    /* 1B34 80064E94 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1B38 80064E98 0600022A */  slti       $v0, $s0, 0x6
    /* 1B3C 80064E9C F4FF4014 */  bnez       $v0, .L80064E70
    /* 1B40 80064EA0 07070424 */   addiu     $a0, $zero, 0x707
    /* 1B44 80064EA4 21800000 */  addu       $s0, $zero, $zero
  .L80064EA8:
    /* 1B48 80064EA8 5AA8010C */  jal        Stg35_BuildCommandList
    /* 1B4C 80064EAC 21200002 */   addu      $a0, $s0, $zero
    /* 1B50 80064EB0 01001026 */  addiu      $s0, $s0, 0x1
    /* 1B54 80064EB4 0600022A */  slti       $v0, $s0, 0x6
    /* 1B58 80064EB8 54014010 */  beqz       $v0, .L8006540C
    /* 1B5C 80064EBC 00000000 */   nop
    /* 1B60 80064EC0 AA930108 */  j          .L80064EA8
    /* 1B64 80064EC4 00000000 */   nop
  .L80064EC8:
    /* 1B68 80064EC8 1400858E */  lw         $a1, 0x14($s4)
    /* 1B6C 80064ECC 00000000 */  nop
    /* 1B70 80064ED0 1600A410 */  beq        $a1, $a0, .L80064F2C
    /* 1B74 80064ED4 0200A228 */   slti      $v0, $a1, 0x2
    /* 1B78 80064ED8 05004014 */  bnez       $v0, .L80064EF0
    /* 1B7C 80064EDC 02000224 */   addiu     $v0, $zero, 0x2
    /* 1B80 80064EE0 3700A210 */  beq        $a1, $v0, .L80064FC0
    /* 1B84 80064EE4 03000224 */   addiu     $v0, $zero, 0x3
    /* 1B88 80064EE8 C400A210 */  beq        $a1, $v0, .L800651FC
    /* 1B8C 80064EEC 21300000 */   addu      $a2, $zero, $zero
  .L80064EF0:
    /* 1B90 80064EF0 1000A38E */  lw         $v1, 0x10($s5)
    /* 1B94 80064EF4 00000000 */  nop
    /* 1B98 80064EF8 1000628C */  lw         $v0, 0x10($v1)
    /* 1B9C 80064EFC 00000000 */  nop
    /* 1BA0 80064F00 DA014414 */  bne        $v0, $a0, .L8006566C
    /* 1BA4 80064F04 00000000 */   nop
    /* 1BA8 80064F08 1400628C */  lw         $v0, 0x14($v1)
    /* 1BAC 80064F0C 00000000 */  nop
    /* 1BB0 80064F10 D6014414 */  bne        $v0, $a0, .L8006566C
    /* 1BB4 80064F14 4C00A526 */   addiu     $a1, $s5, 0x4C
    /* 1BB8 80064F18 08070424 */  addiu      $a0, $zero, 0x708
    /* 1BBC 80064F1C 1F44000C */  jal        Task_Create
    /* 1BC0 80064F20 21300000 */   addu      $a2, $zero, $zero
    /* 1BC4 80064F24 99950108 */  j          .L80065664
    /* 1BC8 80064F28 00000000 */   nop
  .L80064F2C:
    /* 1BCC 80064F2C 1800838E */  lw         $v1, 0x18($s4)
    /* 1BD0 80064F30 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BD4 80064F34 16006210 */  beq        $v1, $v0, .L80064F90
    /* 1BD8 80064F38 03006228 */   slti      $v0, $v1, 0x3
    /* 1BDC 80064F3C 03004014 */  bnez       $v0, .L80064F4C
    /* 1BE0 80064F40 03000224 */   addiu     $v0, $zero, 0x3
    /* 1BE4 80064F44 18006210 */  beq        $v1, $v0, .L80064FA8
    /* 1BE8 80064F48 00000000 */   nop
  .L80064F4C:
    /* 1BEC 80064F4C 1593010C */  jal        Stg35_ShowAllDigi
    /* 1BF0 80064F50 21208002 */   addu      $a0, $s4, $zero
    /* 1BF4 80064F54 20A8010C */  jal        Stg35_SetCameraShot
    /* 1BF8 80064F58 18000424 */   addiu     $a0, $zero, 0x18
    /* 1BFC 80064F5C 9897010C */  jal        Stg35_BuildTurnOrder
    /* 1C00 80064F60 00000000 */   nop
    /* 1C04 80064F64 08070424 */  addiu      $a0, $zero, 0x708
    /* 1C08 80064F68 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 1C0C 80064F6C 4445000C */  jal        Task_FindFirst
    /* 1C10 80064F70 2130A000 */   addu      $a2, $a1, $zero
    /* 1C14 80064F74 04004010 */  beqz       $v0, .L80064F88
    /* 1C18 80064F78 00000000 */   nop
    /* 1C1C 80064F7C 21204000 */  addu       $a0, $v0, $zero
    /* 1C20 80064F80 7745000C */  jal        Task_SetState1
    /* 1C24 80064F84 01000524 */   addiu     $a1, $zero, 0x1
  .L80064F88:
    /* 1C28 80064F88 6045000C */  jal        Task_NextState2
    /* 1C2C 80064F8C 21208002 */   addu      $a0, $s4, $zero
  .L80064F90:
    /* 1C30 80064F90 0C070424 */  addiu      $a0, $zero, 0x70C
    /* 1C34 80064F94 0400668E */  lw         $a2, 0x4($s3)
    /* 1C38 80064F98 1F44000C */  jal        Task_Create
    /* 1C3C 80064F9C 4400A526 */   addiu     $a1, $s5, 0x44
    /* 1C40 80064FA0 6045000C */  jal        Task_NextState2
    /* 1C44 80064FA4 21208002 */   addu      $a0, $s4, $zero
  .L80064FA8:
    /* 1C48 80064FA8 4400A28E */  lw         $v0, 0x44($s5)
    /* 1C4C 80064FAC 00000000 */  nop
    /* 1C50 80064FB0 AC014010 */  beqz       $v0, .L80065664
    /* 1C54 80064FB4 00000000 */   nop
    /* 1C58 80064FB8 9B950108 */  j          .L8006566C
    /* 1C5C 80064FBC 00000000 */   nop
  .L80064FC0:
    /* 1C60 80064FC0 1800838E */  lw         $v1, 0x18($s4)
    /* 1C64 80064FC4 00000000 */  nop
    /* 1C68 80064FC8 17006410 */  beq        $v1, $a0, .L80065028
    /* 1C6C 80064FCC 02006228 */   slti      $v0, $v1, 0x2
    /* 1C70 80064FD0 05004014 */  bnez       $v0, .L80064FE8
    /* 1C74 80064FD4 00000000 */   nop
    /* 1C78 80064FD8 71006510 */  beq        $v1, $a1, .L800651A0
    /* 1C7C 80064FDC 03000224 */   addiu     $v0, $zero, 0x3
    /* 1C80 80064FE0 7A006210 */  beq        $v1, $v0, .L800651CC
    /* 1C84 80064FE4 00000000 */   nop
  .L80064FE8:
    /* 1C88 80064FE8 21200000 */  addu       $a0, $zero, $zero
    /* 1C8C 80064FEC 0780103C */  lui        $s0, %hi(Stg35_Battle)
    /* 1C90 80064FF0 9197010C */  jal        Stg35_TurnOrderGet
    /* 1C94 80064FF4 88AA1026 */   addiu     $s0, $s0, %lo(Stg35_Battle)
    /* 1C98 80064FF8 40180200 */  sll        $v1, $v0, 1
    /* 1C9C 80064FFC 21186200 */  addu       $v1, $v1, $v0
    /* 1CA0 80065000 C0180300 */  sll        $v1, $v1, 3
    /* 1CA4 80065004 23186200 */  subu       $v1, $v1, $v0
    /* 1CA8 80065008 80180300 */  sll        $v1, $v1, 2
    /* 1CAC 8006500C 21187000 */  addu       $v1, $v1, $s0
    /* 1CB0 80065010 26006284 */  lh         $v0, 0x26($v1)
    /* 1CB4 80065014 00000000 */  nop
    /* 1CB8 80065018 92014010 */  beqz       $v0, .L80065664
    /* 1CBC 8006501C 00000000 */   nop
    /* 1CC0 80065020 6045000C */  jal        Task_NextState2
    /* 1CC4 80065024 21208002 */   addu      $a0, $s4, $zero
  .L80065028:
    /* 1CC8 80065028 1C00908E */  lw         $s0, 0x1C($s4)
    /* 1CCC 8006502C 00000000 */  nop
    /* 1CD0 80065030 03000012 */  beqz       $s0, .L80065040
    /* 1CD4 80065034 01000224 */   addiu     $v0, $zero, 0x1
    /* 1CD8 80065038 40000212 */  beq        $s0, $v0, .L8006513C
    /* 1CDC 8006503C 00000000 */   nop
  .L80065040:
    /* 1CE0 80065040 9197010C */  jal        Stg35_TurnOrderGet
    /* 1CE4 80065044 21200000 */   addu      $a0, $zero, $zero
    /* 1CE8 80065048 20A8010C */  jal        Stg35_SetCameraShot
    /* 1CEC 8006504C 0A004424 */   addiu     $a0, $v0, 0xA
    /* 1CF0 80065050 07070424 */  addiu      $a0, $zero, 0x707
    /* 1CF4 80065054 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 1CF8 80065058 4445000C */  jal        Task_FindFirst
    /* 1CFC 8006505C 2130A000 */   addu      $a2, $a1, $zero
    /* 1D00 80065060 21804000 */  addu       $s0, $v0, $zero
    /* 1D04 80065064 14000012 */  beqz       $s0, .L800650B8
    /* 1D08 80065068 00000000 */   nop
  .L8006506C:
    /* 1D0C 8006506C 9197010C */  jal        Stg35_TurnOrderGet
    /* 1D10 80065070 21200000 */   addu      $a0, $zero, $zero
    /* 1D14 80065074 0800038E */  lw         $v1, 0x8($s0)
    /* 1D18 80065078 00000000 */  nop
    /* 1D1C 8006507C 07006214 */  bne        $v1, $v0, .L8006509C
    /* 1D20 80065080 21200002 */   addu      $a0, $s0, $zero
    /* 1D24 80065084 359D010C */  jal        Stg35_FighterSetVisible
    /* 1D28 80065088 01000524 */   addiu     $a1, $zero, 0x1
    /* 1D2C 8006508C 3E9D010C */  jal        Stg35_FighterQueueHomeReset
    /* 1D30 80065090 21200002 */   addu      $a0, $s0, $zero
    /* 1D34 80065094 29940108 */  j          .L800650A4
    /* 1D38 80065098 00000000 */   nop
  .L8006509C:
    /* 1D3C 8006509C 359D010C */  jal        Stg35_FighterSetVisible
    /* 1D40 800650A0 21280000 */   addu      $a1, $zero, $zero
  .L800650A4:
    /* 1D44 800650A4 1045000C */  jal        Task_FindNext
    /* 1D48 800650A8 00000000 */   nop
    /* 1D4C 800650AC 21804000 */  addu       $s0, $v0, $zero
    /* 1D50 800650B0 EEFF0016 */  bnez       $s0, .L8006506C
    /* 1D54 800650B4 00000000 */   nop
  .L800650B8:
    /* 1D58 800650B8 21800000 */  addu       $s0, $zero, $zero
    /* 1D5C 800650BC 05001324 */  addiu      $s3, $zero, 0x5
    /* 1D60 800650C0 2000B127 */  addiu      $s1, $sp, 0x20
    /* 1D64 800650C4 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1D68 800650C8 88AA5224 */  addiu      $s2, $v0, %lo(Stg35_Battle)
  .L800650CC:
    /* 1D6C 800650CC 9197010C */  jal        Stg35_TurnOrderGet
    /* 1D70 800650D0 21200000 */   addu      $a0, $zero, $zero
    /* 1D74 800650D4 23207002 */  subu       $a0, $s3, $s0
    /* 1D78 800650D8 40180200 */  sll        $v1, $v0, 1
    /* 1D7C 800650DC 21186200 */  addu       $v1, $v1, $v0
    /* 1D80 800650E0 80180300 */  sll        $v1, $v1, 2
    /* 1D84 800650E4 23186200 */  subu       $v1, $v1, $v0
    /* 1D88 800650E8 80180300 */  sll        $v1, $v1, 2
    /* 1D8C 800650EC 21180302 */  addu       $v1, $s0, $v1
    /* 1D90 800650F0 01001026 */  addiu      $s0, $s0, 0x1
    /* 1D94 800650F4 80200400 */  sll        $a0, $a0, 2
    /* 1D98 800650F8 21187200 */  addu       $v1, $v1, $s2
    /* 1D9C 800650FC 44026290 */  lbu        $v0, 0x244($v1)
    /* 1DA0 80065100 21202402 */  addu       $a0, $s1, $a0
    /* 1DA4 80065104 000082AC */  sw         $v0, 0x0($a0)
    /* 1DA8 80065108 0600022A */  slti       $v0, $s0, 0x6
    /* 1DAC 8006510C EFFF4014 */  bnez       $v0, .L800650CC
    /* 1DB0 80065110 00000000 */   nop
    /* 1DB4 80065114 9197010C */  jal        Stg35_TurnOrderGet
    /* 1DB8 80065118 21200000 */   addu      $a0, $zero, $zero
    /* 1DBC 8006511C 03004228 */  slti       $v0, $v0, 0x3
    /* 1DC0 80065120 01004438 */  xori       $a0, $v0, 0x1
    /* 1DC4 80065124 C4A2010C */  jal        Stg35_HudStartGauge
    /* 1DC8 80065128 2000A527 */   addiu     $a1, $sp, 0x20
    /* 1DCC 8006512C 6645000C */  jal        Task_NextState3
    /* 1DD0 80065130 21208002 */   addu      $a0, $s4, $zero
    /* 1DD4 80065134 9B950108 */  j          .L8006566C
    /* 1DD8 80065138 00000000 */   nop
  .L8006513C:
    /* 1DDC 8006513C E7A2010C */  jal        Stg35_HudGetGaugeStatus
    /* 1DE0 80065140 00000000 */   nop
    /* 1DE4 80065144 49015010 */  beq        $v0, $s0, .L8006566C
    /* 1DE8 80065148 00000000 */   nop
    /* 1DEC 8006514C E7A2010C */  jal        Stg35_HudGetGaugeStatus
    /* 1DF0 80065150 00000000 */   nop
    /* 1DF4 80065154 02000324 */  addiu      $v1, $zero, 0x2
    /* 1DF8 80065158 06004314 */  bne        $v0, $v1, .L80065174
    /* 1DFC 8006515C 00000000 */   nop
    /* 1E00 80065160 21208002 */  addu       $a0, $s4, $zero
    /* 1E04 80065164 7745000C */  jal        Task_SetState1
    /* 1E08 80065168 03000524 */   addiu     $a1, $zero, 0x3
    /* 1E0C 8006516C 9B950108 */  j          .L8006566C
    /* 1E10 80065170 00000000 */   nop
  .L80065174:
    /* 1E14 80065174 9197010C */  jal        Stg35_TurnOrderGet
    /* 1E18 80065178 21200000 */   addu      $a0, $zero, $zero
    /* 1E1C 8006517C 17A3010C */  jal        Stg35_HudGetGaugeLevel
    /* 1E20 80065180 21804000 */   addu      $s0, $v0, $zero
    /* 1E24 80065184 21200002 */  addu       $a0, $s0, $zero
    /* 1E28 80065188 E397010C */  jal        Stg35_SetChosenAction
    /* 1E2C 8006518C 21284000 */   addu      $a1, $v0, $zero
    /* 1E30 80065190 6045000C */  jal        Task_NextState2
    /* 1E34 80065194 21208002 */   addu      $a0, $s4, $zero
    /* 1E38 80065198 9B950108 */  j          .L8006566C
    /* 1E3C 8006519C 00000000 */   nop
  .L800651A0:
    /* 1E40 800651A0 9197010C */  jal        Stg35_TurnOrderGet
    /* 1E44 800651A4 21200000 */   addu      $a0, $zero, $zero
    /* 1E48 800651A8 14A6010C */  jal        Stg35_PrepareAction
    /* 1E4C 800651AC 21204000 */   addu      $a0, $v0, $zero
    /* 1E50 800651B0 04004010 */  beqz       $v0, .L800651C4
    /* 1E54 800651B4 09070424 */   addiu     $a0, $zero, 0x709
    /* 1E58 800651B8 4800A526 */  addiu      $a1, $s5, 0x48
    /* 1E5C 800651BC 1F44000C */  jal        Task_Create
    /* 1E60 800651C0 01000624 */   addiu     $a2, $zero, 0x1
  .L800651C4:
    /* 1E64 800651C4 6045000C */  jal        Task_NextState2
    /* 1E68 800651C8 21208002 */   addu      $a0, $s4, $zero
  .L800651CC:
    /* 1E6C 800651CC 4800A28E */  lw         $v0, 0x48($s5)
    /* 1E70 800651D0 00000000 */  nop
    /* 1E74 800651D4 23014010 */  beqz       $v0, .L80065664
    /* 1E78 800651D8 00000000 */   nop
    /* 1E7C 800651DC 9B950108 */  j          .L8006566C
    /* 1E80 800651E0 00000000 */   nop
  .L800651E4:
    /* 1E84 800651E4 21208002 */  addu       $a0, $s4, $zero
    /* 1E88 800651E8 7745000C */  jal        Task_SetState1
    /* 1E8C 800651EC 03000524 */   addiu     $a1, $zero, 0x3
    /* 1E90 800651F0 01000624 */  addiu      $a2, $zero, 0x1
    /* 1E94 800651F4 9B940108 */  j          .L8006526C
    /* 1E98 800651F8 0C0066AE */   sw        $a2, 0xC($s3)
  .L800651FC:
    /* 1E9C 800651FC 2128C000 */  addu       $a1, $a2, $zero
    /* 1EA0 80065200 2120C000 */  addu       $a0, $a2, $zero
    /* 1EA4 80065204 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1EA8 80065208 88AA4324 */  addiu      $v1, $v0, %lo(Stg35_Battle)
  .L8006520C:
    /* 1EAC 8006520C 26006284 */  lh         $v0, 0x26($v1)
    /* 1EB0 80065210 01008424 */  addiu      $a0, $a0, 0x1
    /* 1EB4 80065214 2128A200 */  addu       $a1, $a1, $v0
    /* 1EB8 80065218 03008228 */  slti       $v0, $a0, 0x3
    /* 1EBC 8006521C FBFF4014 */  bnez       $v0, .L8006520C
    /* 1EC0 80065220 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 1EC4 80065224 EFFFA010 */  beqz       $a1, .L800651E4
    /* 1EC8 80065228 21280000 */   addu      $a1, $zero, $zero
    /* 1ECC 8006522C 03000424 */  addiu      $a0, $zero, 0x3
    /* 1ED0 80065230 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1ED4 80065234 88AA4224 */  addiu      $v0, $v0, %lo(Stg35_Battle)
    /* 1ED8 80065238 14014324 */  addiu      $v1, $v0, 0x114
  .L8006523C:
    /* 1EDC 8006523C 26006284 */  lh         $v0, 0x26($v1)
    /* 1EE0 80065240 01008424 */  addiu      $a0, $a0, 0x1
    /* 1EE4 80065244 2128A200 */  addu       $a1, $a1, $v0
    /* 1EE8 80065248 06008228 */  slti       $v0, $a0, 0x6
    /* 1EEC 8006524C FBFF4014 */  bnez       $v0, .L8006523C
    /* 1EF0 80065250 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 1EF4 80065254 0500A014 */  bnez       $a1, .L8006526C
    /* 1EF8 80065258 21208002 */   addu      $a0, $s4, $zero
    /* 1EFC 8006525C 7745000C */  jal        Task_SetState1
    /* 1F00 80065260 04000524 */   addiu     $a1, $zero, 0x4
    /* 1F04 80065264 01000624 */  addiu      $a2, $zero, 0x1
    /* 1F08 80065268 0C0060AE */  sw         $zero, 0xC($s3)
  .L8006526C:
    /* 1F0C 8006526C 6700C014 */  bnez       $a2, .L8006540C
    /* 1F10 80065270 00000000 */   nop
    /* 1F14 80065274 6197010C */  jal        Stg35_TurnOrderRemove
    /* 1F18 80065278 21200000 */   addu      $a0, $zero, $zero
    /* 1F1C 8006527C 9197010C */  jal        Stg35_TurnOrderGet
    /* 1F20 80065280 21200000 */   addu      $a0, $zero, $zero
    /* 1F24 80065284 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 1F28 80065288 5C004314 */  bne        $v0, $v1, .L800653FC
    /* 1F2C 8006528C 21208002 */   addu      $a0, $s4, $zero
    /* 1F30 80065290 0400628E */  lw         $v0, 0x4($s3)
    /* 1F34 80065294 03000324 */  addiu      $v1, $zero, 0x3
    /* 1F38 80065298 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F3C 8006529C 53004314 */  bne        $v0, $v1, .L800653EC
    /* 1F40 800652A0 040062AE */   sw        $v0, 0x4($s3)
    /* 1F44 800652A4 3800A427 */  addiu      $a0, $sp, 0x38
    /* 1F48 800652A8 21280000 */  addu       $a1, $zero, $zero
    /* 1F4C 800652AC 219C000C */  jal        memset
    /* 1F50 800652B0 08000624 */   addiu     $a2, $zero, 0x8
    /* 1F54 800652B4 21200000 */  addu       $a0, $zero, $zero
    /* 1F58 800652B8 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1F5C 800652BC 88AA4324 */  addiu      $v1, $v0, %lo(Stg35_Battle)
  .L800652C0:
    /* 1F60 800652C0 26006284 */  lh         $v0, 0x26($v1)
    /* 1F64 800652C4 00000000 */  nop
    /* 1F68 800652C8 05004010 */  beqz       $v0, .L800652E0
    /* 1F6C 800652CC 00000000 */   nop
    /* 1F70 800652D0 3800A28F */  lw         $v0, 0x38($sp)
    /* 1F74 800652D4 00000000 */  nop
    /* 1F78 800652D8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F7C 800652DC 3800A2AF */  sw         $v0, 0x38($sp)
  .L800652E0:
    /* 1F80 800652E0 01008424 */  addiu      $a0, $a0, 0x1
    /* 1F84 800652E4 03008228 */  slti       $v0, $a0, 0x3
    /* 1F88 800652E8 F5FF4014 */  bnez       $v0, .L800652C0
    /* 1F8C 800652EC 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 1F90 800652F0 03000424 */  addiu      $a0, $zero, 0x3
    /* 1F94 800652F4 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1F98 800652F8 88AA4224 */  addiu      $v0, $v0, %lo(Stg35_Battle)
    /* 1F9C 800652FC 14014324 */  addiu      $v1, $v0, 0x114
  .L80065300:
    /* 1FA0 80065300 26006284 */  lh         $v0, 0x26($v1)
    /* 1FA4 80065304 00000000 */  nop
    /* 1FA8 80065308 05004010 */  beqz       $v0, .L80065320
    /* 1FAC 8006530C 00000000 */   nop
    /* 1FB0 80065310 3C00A28F */  lw         $v0, 0x3C($sp)
    /* 1FB4 80065314 00000000 */  nop
    /* 1FB8 80065318 01004224 */  addiu      $v0, $v0, 0x1
    /* 1FBC 8006531C 3C00A2AF */  sw         $v0, 0x3C($sp)
  .L80065320:
    /* 1FC0 80065320 01008424 */  addiu      $a0, $a0, 0x1
    /* 1FC4 80065324 06008228 */  slti       $v0, $a0, 0x6
    /* 1FC8 80065328 F5FF4014 */  bnez       $v0, .L80065300
    /* 1FCC 8006532C 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 1FD0 80065330 3800A38F */  lw         $v1, 0x38($sp)
    /* 1FD4 80065334 3C00A28F */  lw         $v0, 0x3C($sp)
    /* 1FD8 80065338 00000000 */  nop
    /* 1FDC 8006533C 21006214 */  bne        $v1, $v0, .L800653C4
    /* 1FE0 80065340 21200000 */   addu      $a0, $zero, $zero
    /* 1FE4 80065344 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 1FE8 80065348 88AA4524 */  addiu      $a1, $v0, %lo(Stg35_Battle)
    /* 1FEC 8006534C 3800A0AF */  sw         $zero, 0x38($sp)
    /* 1FF0 80065350 3C00A0AF */  sw         $zero, 0x3C($sp)
  .L80065354:
    /* 1FF4 80065354 2600A384 */  lh         $v1, 0x26($a1)
    /* 1FF8 80065358 00000000 */  nop
    /* 1FFC 8006535C 05006010 */  beqz       $v1, .L80065374
    /* 2000 80065360 00000000 */   nop
    /* 2004 80065364 3800A28F */  lw         $v0, 0x38($sp)
    /* 2008 80065368 00000000 */  nop
    /* 200C 8006536C 21104300 */  addu       $v0, $v0, $v1
    /* 2010 80065370 3800A2AF */  sw         $v0, 0x38($sp)
  .L80065374:
    /* 2014 80065374 01008424 */  addiu      $a0, $a0, 0x1
    /* 2018 80065378 03008228 */  slti       $v0, $a0, 0x3
    /* 201C 8006537C F5FF4014 */  bnez       $v0, .L80065354
    /* 2020 80065380 5C00A524 */   addiu     $a1, $a1, 0x5C
    /* 2024 80065384 03000424 */  addiu      $a0, $zero, 0x3
    /* 2028 80065388 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 202C 8006538C 88AA4224 */  addiu      $v0, $v0, %lo(Stg35_Battle)
    /* 2030 80065390 14014524 */  addiu      $a1, $v0, 0x114
  .L80065394:
    /* 2034 80065394 2600A384 */  lh         $v1, 0x26($a1)
    /* 2038 80065398 00000000 */  nop
    /* 203C 8006539C 05006010 */  beqz       $v1, .L800653B4
    /* 2040 800653A0 00000000 */   nop
    /* 2044 800653A4 3C00A28F */  lw         $v0, 0x3C($sp)
    /* 2048 800653A8 00000000 */  nop
    /* 204C 800653AC 21104300 */  addu       $v0, $v0, $v1
    /* 2050 800653B0 3C00A2AF */  sw         $v0, 0x3C($sp)
  .L800653B4:
    /* 2054 800653B4 01008424 */  addiu      $a0, $a0, 0x1
    /* 2058 800653B8 06008228 */  slti       $v0, $a0, 0x6
    /* 205C 800653BC F5FF4014 */  bnez       $v0, .L80065394
    /* 2060 800653C0 5C00A524 */   addiu     $a1, $a1, 0x5C
  .L800653C4:
    /* 2064 800653C4 3800A28F */  lw         $v0, 0x38($sp)
    /* 2068 800653C8 3C00A38F */  lw         $v1, 0x3C($sp)
    /* 206C 800653CC 00000000 */  nop
    /* 2070 800653D0 2A104300 */  slt        $v0, $v0, $v1
    /* 2074 800653D4 03004014 */  bnez       $v0, .L800653E4
    /* 2078 800653D8 01000224 */   addiu     $v0, $zero, 0x1
    /* 207C 800653DC 03950108 */  j          .L8006540C
    /* 2080 800653E0 0C0060AE */   sw        $zero, 0xC($s3)
  .L800653E4:
    /* 2084 800653E4 03950108 */  j          .L8006540C
    /* 2088 800653E8 0C0062AE */   sw        $v0, 0xC($s3)
  .L800653EC:
    /* 208C 800653EC 7745000C */  jal        Task_SetState1
    /* 2090 800653F0 01000524 */   addiu     $a1, $zero, 0x1
    /* 2094 800653F4 9B950108 */  j          .L8006566C
    /* 2098 800653F8 00000000 */   nop
  .L800653FC:
    /* 209C 800653FC 7745000C */  jal        Task_SetState1
    /* 20A0 80065400 02000524 */   addiu     $a1, $zero, 0x2
    /* 20A4 80065404 9B950108 */  j          .L8006566C
    /* 20A8 80065408 00000000 */   nop
  .L8006540C:
    /* 20AC 8006540C 5145000C */  jal        Task_NextState0
    /* 20B0 80065410 21208002 */   addu      $a0, $s4, $zero
    /* 20B4 80065414 9B950108 */  j          .L8006566C
    /* 20B8 80065418 00000000 */   nop
  .L8006541C:
    /* 20BC 8006541C 1400838E */  lw         $v1, 0x14($s4)
    /* 20C0 80065420 00000000 */  nop
    /* 20C4 80065424 0700622C */  sltiu      $v0, $v1, 0x7
    /* 20C8 80065428 0A004010 */  beqz       $v0, .L80065454
    /* 20CC 8006542C 0680023C */   lui       $v0, %hi(jtbl_800633B0)
    /* 20D0 80065430 B0334224 */  addiu      $v0, $v0, %lo(jtbl_800633B0)
    /* 20D4 80065434 80180300 */  sll        $v1, $v1, 2
    /* 20D8 80065438 21186200 */  addu       $v1, $v1, $v0
    /* 20DC 8006543C 0000628C */  lw         $v0, 0x0($v1)
    /* 20E0 80065440 00000000 */  nop
    /* 20E4 80065444 08004000 */  jr         $v0
    /* 20E8 80065448 00000000 */   nop
  .L8006544C:
    /* 20EC 8006544C 47950108 */  j          .L8006551C
    /* 20F0 80065450 01001624 */   addiu     $s6, $zero, 0x1
  jlabel .L80065454
    /* 20F4 80065454 02020424 */  addiu      $a0, $zero, 0x202
    /* 20F8 80065458 A369000C */  jal        Snd_PlayById
    /* 20FC 8006545C 01000524 */   addiu     $a1, $zero, 0x1
    /* 2100 80065460 0C00648E */  lw         $a0, 0xC($s3)
    /* 2104 80065464 20A8010C */  jal        Stg35_SetCameraShot
    /* 2108 80065468 19008424 */   addiu     $a0, $a0, 0x19
    /* 210C 8006546C 0C00658E */  lw         $a1, 0xC($s3)
    /* 2110 80065470 EC92010C */  jal        Stg35_ShowWinnerSide
    /* 2114 80065474 21208002 */   addu      $a0, $s4, $zero
    /* 2118 80065478 21208002 */  addu       $a0, $s4, $zero
    /* 211C 8006547C 5945000C */  jal        Task_NextState1
    /* 2120 80065480 280080AE */   sw        $zero, 0x28($s4)
  jlabel .L80065484
    /* 2124 80065484 0C00628E */  lw         $v0, 0xC($s3)
    /* 2128 80065488 00000000 */  nop
    /* 212C 8006548C 40180200 */  sll        $v1, $v0, 1
    /* 2130 80065490 21906200 */  addu       $s2, $v1, $v0
    /* 2134 80065494 01000224 */  addiu      $v0, $zero, 0x1
    /* 2138 80065498 20004010 */  beqz       $v0, .L8006551C
    /* 213C 8006549C 21B00000 */   addu      $s6, $zero, $zero
    /* 2140 800654A0 0780033C */  lui        $v1, %hi(Stg35_Battle)
    /* 2144 800654A4 88AA6324 */  addiu      $v1, $v1, %lo(Stg35_Battle)
    /* 2148 800654A8 04105200 */  sllv       $v0, $s2, $v0
    /* 214C 800654AC 21105200 */  addu       $v0, $v0, $s2
    /* 2150 800654B0 C0100200 */  sll        $v0, $v0, 3
    /* 2154 800654B4 23105200 */  subu       $v0, $v0, $s2
    /* 2158 800654B8 80100200 */  sll        $v0, $v0, 2
    /* 215C 800654BC 21884300 */  addu       $s1, $v0, $v1
  .L800654C0:
    /* 2160 800654C0 26002286 */  lh         $v0, 0x26($s1)
    /* 2164 800654C4 00000000 */  nop
    /* 2168 800654C8 0C004010 */  beqz       $v0, .L800654FC
    /* 216C 800654CC 00000000 */   nop
    /* 2170 800654D0 11002492 */  lbu        $a0, 0x11($s1)
    /* 2174 800654D4 CA79000C */  jal        Anim_GetModelAnimFile
    /* 2178 800654D8 08000524 */   addiu     $a1, $zero, 0x8
    /* 217C 800654DC 21804000 */  addu       $s0, $v0, $zero
    /* 2180 800654E0 FD8E000C */  jal        Cd_QueueFile
    /* 2184 800654E4 21200002 */   addu      $a0, $s0, $zero
    /* 2188 800654E8 DC8E000C */  jal        Cd_GetFileState
    /* 218C 800654EC 21200002 */   addu      $a0, $s0, $zero
    /* 2190 800654F0 03000324 */  addiu      $v1, $zero, 0x3
    /* 2194 800654F4 D5FF4314 */  bne        $v0, $v1, .L8006544C
    /* 2198 800654F8 00000000 */   nop
  .L800654FC:
    /* 219C 800654FC 0C00638E */  lw         $v1, 0xC($s3)
    /* 21A0 80065500 01005226 */  addiu      $s2, $s2, 0x1
    /* 21A4 80065504 40100300 */  sll        $v0, $v1, 1
    /* 21A8 80065508 21104300 */  addu       $v0, $v0, $v1
    /* 21AC 8006550C 03004224 */  addiu      $v0, $v0, 0x3
    /* 21B0 80065510 2A104202 */  slt        $v0, $s2, $v0
    /* 21B4 80065514 EAFF4014 */  bnez       $v0, .L800654C0
    /* 21B8 80065518 5C003126 */   addiu     $s1, $s1, 0x5C
  .L8006551C:
    /* 21BC 8006551C 5300C016 */  bnez       $s6, .L8006566C
    /* 21C0 80065520 00000000 */   nop
    /* 21C4 80065524 2800828E */  lw         $v0, 0x28($s4)
    /* 21C8 80065528 00000000 */  nop
    /* 21CC 8006552C 3C004228 */  slti       $v0, $v0, 0x3C
    /* 21D0 80065530 4E004014 */  bnez       $v0, .L8006566C
    /* 21D4 80065534 00000000 */   nop
    /* 21D8 80065538 0C00628E */  lw         $v0, 0xC($s3)
    /* 21DC 8006553C 00000000 */  nop
    /* 21E0 80065540 40180200 */  sll        $v1, $v0, 1
    /* 21E4 80065544 21806200 */  addu       $s0, $v1, $v0
    /* 21E8 80065548 01000224 */  addiu      $v0, $zero, 0x1
    /* 21EC 8006554C 1A004010 */  beqz       $v0, .L800655B8
    /* 21F0 80065550 80101000 */   sll       $v0, $s0, 2
    /* 21F4 80065554 21905500 */  addu       $s2, $v0, $s5
    /* 21F8 80065558 0780033C */  lui        $v1, %hi(Stg35_Battle)
    /* 21FC 8006555C 88AA6324 */  addiu      $v1, $v1, %lo(Stg35_Battle)
    /* 2200 80065560 40101000 */  sll        $v0, $s0, 1
    /* 2204 80065564 21105000 */  addu       $v0, $v0, $s0
    /* 2208 80065568 C0100200 */  sll        $v0, $v0, 3
    /* 220C 8006556C 23105000 */  subu       $v0, $v0, $s0
    /* 2210 80065570 80100200 */  sll        $v0, $v0, 2
    /* 2214 80065574 21884300 */  addu       $s1, $v0, $v1
  .L80065578:
    /* 2218 80065578 26002286 */  lh         $v0, 0x26($s1)
    /* 221C 8006557C 00000000 */  nop
    /* 2220 80065580 04004010 */  beqz       $v0, .L80065594
    /* 2224 80065584 02000524 */   addiu     $a1, $zero, 0x2
    /* 2228 80065588 2C00448E */  lw         $a0, 0x2C($s2)
    /* 222C 8006558C 7D45000C */  jal        Task_SetState01
    /* 2230 80065590 2130A000 */   addu      $a2, $a1, $zero
  .L80065594:
    /* 2234 80065594 04005226 */  addiu      $s2, $s2, 0x4
    /* 2238 80065598 0C00638E */  lw         $v1, 0xC($s3)
    /* 223C 8006559C 01001026 */  addiu      $s0, $s0, 0x1
    /* 2240 800655A0 40100300 */  sll        $v0, $v1, 1
    /* 2244 800655A4 21104300 */  addu       $v0, $v0, $v1
    /* 2248 800655A8 03004224 */  addiu      $v0, $v0, 0x3
    /* 224C 800655AC 2A100202 */  slt        $v0, $s0, $v0
    /* 2250 800655B0 F1FF4014 */  bnez       $v0, .L80065578
    /* 2254 800655B4 5C003126 */   addiu     $s1, $s1, 0x5C
  .L800655B8:
    /* 2258 800655B8 5945000C */  jal        Task_NextState1
    /* 225C 800655BC 21208002 */   addu      $a0, $s4, $zero
    /* 2260 800655C0 280080AE */  sw         $zero, 0x28($s4)
  jlabel .L800655C4
    /* 2264 800655C4 2800828E */  lw         $v0, 0x28($s4)
    /* 2268 800655C8 00000000 */  nop
    /* 226C 800655CC 78004228 */  slti       $v0, $v0, 0x78
    /* 2270 800655D0 26004014 */  bnez       $v0, .L8006566C
    /* 2274 800655D4 00000000 */   nop
    /* 2278 800655D8 0D070424 */  addiu      $a0, $zero, 0x70D
    /* 227C 800655DC 0C00668E */  lw         $a2, 0xC($s3)
    /* 2280 800655E0 1F44000C */  jal        Task_Create
    /* 2284 800655E4 2800A526 */   addiu     $a1, $s5, 0x28
    /* 2288 800655E8 5945000C */  jal        Task_NextState1
    /* 228C 800655EC 21208002 */   addu      $a0, $s4, $zero
  jlabel .L800655F0
    /* 2290 800655F0 2800828E */  lw         $v0, 0x28($s4)
    /* 2294 800655F4 00000000 */  nop
    /* 2298 800655F8 78004228 */  slti       $v0, $v0, 0x78
    /* 229C 800655FC 1B004014 */  bnez       $v0, .L8006566C
    /* 22A0 80065600 0680023C */   lui       $v0, %hi(Pad_State)
    /* 22A4 80065604 F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 22A8 80065608 1400628C */  lw         $v0, 0x14($v1)
    /* 22AC 8006560C 00000000 */  nop
    /* 22B0 80065610 1400401C */  bgtz       $v0, .L80065664
    /* 22B4 80065614 00000000 */   nop
    /* 22B8 80065618 5400628C */  lw         $v0, 0x54($v1)
    /* 22BC 8006561C 00000000 */  nop
    /* 22C0 80065620 12004018 */  blez       $v0, .L8006566C
    /* 22C4 80065624 00000000 */   nop
    /* 22C8 80065628 99950108 */  j          .L80065664
    /* 22CC 8006562C 00000000 */   nop
  jlabel .L80065630
    /* 22D0 80065630 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 22D4 80065634 0F000424 */   addiu     $a0, $zero, 0xF
    /* 22D8 80065638 5945000C */  jal        Task_NextState1
    /* 22DC 8006563C 21208002 */   addu      $a0, $s4, $zero
  jlabel .L80065640
    /* 22E0 80065640 1800828E */  lw         $v0, 0x18($s4)
    /* 22E4 80065644 00000000 */  nop
    /* 22E8 80065648 01004224 */  addiu      $v0, $v0, 0x1
    /* 22EC 8006564C 180082AE */  sw         $v0, 0x18($s4)
    /* 22F0 80065650 10004228 */  slti       $v0, $v0, 0x10
    /* 22F4 80065654 05004014 */  bnez       $v0, .L8006566C
    /* 22F8 80065658 0680033C */   lui       $v1, %hi(Sys_NextGameMode)
    /* 22FC 8006565C 01070224 */  addiu      $v0, $zero, 0x701
    /* 2300 80065660 8CF762AC */  sw         $v0, %lo(Sys_NextGameMode)($v1)
  .L80065664:
    /* 2304 80065664 5945000C */  jal        Task_NextState1
    /* 2308 80065668 21208002 */   addu      $a0, $s4, $zero
  jlabel .L8006566C
    /* 230C 8006566C 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* 2310 80065670 5800B68F */  lw         $s6, 0x58($sp)
    /* 2314 80065674 5400B58F */  lw         $s5, 0x54($sp)
    /* 2318 80065678 5000B48F */  lw         $s4, 0x50($sp)
    /* 231C 8006567C 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 2320 80065680 4800B28F */  lw         $s2, 0x48($sp)
    /* 2324 80065684 4400B18F */  lw         $s1, 0x44($sp)
    /* 2328 80065688 4000B08F */  lw         $s0, 0x40($sp)
    /* 232C 8006568C 0800E003 */  jr         $ra
    /* 2330 80065690 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel Stg35_BattleUpdate
