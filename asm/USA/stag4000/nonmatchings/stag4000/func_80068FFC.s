nonmatching func_80068FFC, 0xD0

glabel func_80068FFC
    /* 5C9C 80068FFC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5CA0 80069000 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5CA4 80069004 21808000 */  addu       $s0, $a0, $zero
    /* 5CA8 80069008 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5CAC 8006900C 9E87000C */  jal        Flag_Test
    /* 5CB0 80069010 68000424 */   addiu     $a0, $zero, 0x68
    /* 5CB4 80069014 09004010 */  beqz       $v0, .L8006903C
    /* 5CB8 80069018 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 5CBC 8006901C 2007438C */  lw         $v1, %lo(Save_GameStatePtr)($v0)
    /* 5CC0 80069020 00000000 */  nop
    /* 5CC4 80069024 28006284 */  lh         $v0, 0x28($v1)
    /* 5CC8 80069028 00000000 */  nop
    /* 5CCC 8006902C 0A004014 */  bnez       $v0, .L80069058
    /* 5CD0 80069030 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
    /* 5CD4 80069034 01000224 */  addiu      $v0, $zero, 0x1
    /* 5CD8 80069038 280062A4 */  sh         $v0, 0x28($v1)
  .L8006903C:
    /* 5CDC 8006903C 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 5CE0 80069040 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 5CE4 80069044 00000000 */  nop
    /* 5CE8 80069048 28004284 */  lh         $v0, 0x28($v0)
    /* 5CEC 8006904C 00000000 */  nop
    /* 5CF0 80069050 07004010 */  beqz       $v0, .L80069070
    /* 5CF4 80069054 0580023C */   lui       $v0, %hi(Save_GameStatePtr)
  .L80069058:
    /* 5CF8 80069058 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 5CFC 8006905C 00000000 */  nop
    /* 5D00 80069060 24004284 */  lh         $v0, 0x24($v0)
    /* 5D04 80069064 00000000 */  nop
    /* 5D08 80069068 04004014 */  bnez       $v0, .L8006907C
    /* 5D0C 8006906C 00000000 */   nop
  .L80069070:
    /* 5D10 80069070 21200002 */  addu       $a0, $s0, $zero
    /* 5D14 80069074 2DA40108 */  j          .L800690B4
    /* 5D18 80069078 1C000524 */   addiu     $a1, $zero, 0x1C
  .L8006907C:
    /* 5D1C 8006907C E3A2010C */  jal        func_80068B8C
    /* 5D20 80069080 21200002 */   addu      $a0, $s0, $zero
    /* 5D24 80069084 0D004014 */  bnez       $v0, .L800690BC
    /* 5D28 80069088 00000000 */   nop
    /* 5D2C 8006908C 12C3010C */  jal        func_80070C48
    /* 5D30 80069090 00000000 */   nop
    /* 5D34 80069094 21200002 */  addu       $a0, $s0, $zero
    /* 5D38 80069098 7745000C */  jal        Task_SetState1
    /* 5D3C 8006909C 21280000 */   addu      $a1, $zero, $zero
    /* 5D40 800690A0 CCB8010C */  jal        func_8006E330
    /* 5D44 800690A4 00000000 */   nop
    /* 5D48 800690A8 04004010 */  beqz       $v0, .L800690BC
    /* 5D4C 800690AC 21200002 */   addu      $a0, $s0, $zero
    /* 5D50 800690B0 04000524 */  addiu      $a1, $zero, 0x4
  .L800690B4:
    /* 5D54 800690B4 7745000C */  jal        Task_SetState1
    /* 5D58 800690B8 00000000 */   nop
  .L800690BC:
    /* 5D5C 800690BC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5D60 800690C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5D64 800690C4 0800E003 */  jr         $ra
    /* 5D68 800690C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068FFC
