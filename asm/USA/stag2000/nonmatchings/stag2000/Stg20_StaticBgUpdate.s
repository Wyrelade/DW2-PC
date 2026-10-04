nonmatching Stg20_StaticBgUpdate, 0x15C

glabel Stg20_StaticBgUpdate
    /* 97C 80063CDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 980 80063CE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 984 80063CE4 21888000 */  addu       $s1, $a0, $zero
    /* 988 80063CE8 01000524 */  addiu      $a1, $zero, 0x1
    /* 98C 80063CEC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 990 80063CF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 994 80063CF4 1000248E */  lw         $a0, 0x10($s1)
    /* 998 80063CF8 2C00308E */  lw         $s0, 0x2C($s1)
    /* 99C 80063CFC 49008510 */  beq        $a0, $a1, .L80063E24
    /* 9A0 80063D00 02008228 */   slti      $v0, $a0, 0x2
    /* 9A4 80063D04 05004010 */  beqz       $v0, .L80063D1C
    /* 9A8 80063D08 00000000 */   nop
    /* 9AC 80063D0C 08008010 */  beqz       $a0, .L80063D30
    /* 9B0 80063D10 00000000 */   nop
    /* 9B4 80063D14 898F0108 */  j          .L80063E24
    /* 9B8 80063D18 00000000 */   nop
  .L80063D1C:
    /* 9BC 80063D1C 02000224 */  addiu      $v0, $zero, 0x2
    /* 9C0 80063D20 20008210 */  beq        $a0, $v0, .L80063DA4
    /* 9C4 80063D24 00000000 */   nop
    /* 9C8 80063D28 898F0108 */  j          .L80063E24
    /* 9CC 80063D2C 00000000 */   nop
  .L80063D30:
    /* 9D0 80063D30 0000048E */  lw         $a0, 0x0($s0)
    /* 9D4 80063D34 828E000C */  jal        Cd_GetFileOrNull
    /* 9D8 80063D38 00000000 */   nop
    /* 9DC 80063D3C 21200000 */  addu       $a0, $zero, $zero
    /* 9E0 80063D40 21180002 */  addu       $v1, $s0, $zero
    /* 9E4 80063D44 21284000 */  addu       $a1, $v0, $zero
  .L80063D48:
    /* 9E8 80063D48 0000A28C */  lw         $v0, 0x0($a1)
    /* 9EC 80063D4C 00000000 */  nop
    /* 9F0 80063D50 07004010 */  beqz       $v0, .L80063D70
    /* 9F4 80063D54 00000000 */   nop
    /* 9F8 80063D58 0000028E */  lw         $v0, 0x0($s0)
    /* 9FC 80063D5C 00000000 */  nop
    /* A00 80063D60 00140200 */  sll        $v0, $v0, 16
    /* A04 80063D64 21104400 */  addu       $v0, $v0, $a0
    /* A08 80063D68 5D8F0108 */  j          .L80063D74
    /* A0C 80063D6C 040062AC */   sw        $v0, 0x4($v1)
  .L80063D70:
    /* A10 80063D70 040060AC */  sw         $zero, 0x4($v1)
  .L80063D74:
    /* A14 80063D74 04006324 */  addiu      $v1, $v1, 0x4
    /* A18 80063D78 01008424 */  addiu      $a0, $a0, 0x1
    /* A1C 80063D7C 0A008228 */  slti       $v0, $a0, 0xA
    /* A20 80063D80 F1FF4014 */  bnez       $v0, .L80063D48
    /* A24 80063D84 0400A524 */   addiu     $a1, $a1, 0x4
    /* A28 80063D88 21200000 */  addu       $a0, $zero, $zero
    /* A2C 80063D8C A9B5000C */  jal        SetGeomOffset
    /* A30 80063D90 21288000 */   addu      $a1, $a0, $zero
    /* A34 80063D94 5145000C */  jal        Task_NextState0
    /* A38 80063D98 21202002 */   addu      $a0, $s1, $zero
    /* A3C 80063D9C 898F0108 */  j          .L80063E24
    /* A40 80063DA0 00000000 */   nop
  .L80063DA4:
    /* A44 80063DA4 1400238E */  lw         $v1, 0x14($s1)
    /* A48 80063DA8 00000000 */  nop
    /* A4C 80063DAC 09006510 */  beq        $v1, $a1, .L80063DD4
    /* A50 80063DB0 02006228 */   slti      $v0, $v1, 0x2
    /* A54 80063DB4 03004014 */  bnez       $v0, .L80063DC4
    /* A58 80063DB8 00000000 */   nop
    /* A5C 80063DBC 19006410 */  beq        $v1, $a0, .L80063E24
    /* A60 80063DC0 00000000 */   nop
  .L80063DC4:
    /* A64 80063DC4 3C71000C */  jal        Gfx_FadeOutToBlack
    /* A68 80063DC8 10000424 */   addiu     $a0, $zero, 0x10
    /* A6C 80063DCC 5945000C */  jal        Task_NextState1
    /* A70 80063DD0 21202002 */   addu      $a0, $s1, $zero
  .L80063DD4:
    /* A74 80063DD4 0680023C */  lui        $v0, %hi(Sys_State)
    /* A78 80063DD8 70F74524 */  addiu      $a1, $v0, %lo(Sys_State)
    /* A7C 80063DDC 1000A38C */  lw         $v1, 0x10($a1)
    /* A80 80063DE0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A84 80063DE4 0F006214 */  bne        $v1, $v0, .L80063E24
    /* A88 80063DE8 00000000 */   nop
    /* A8C 80063DEC 2C00048E */  lw         $a0, 0x2C($s0)
    /* A90 80063DF0 00000000 */  nop
    /* A94 80063DF4 03008010 */  beqz       $a0, .L80063E04
    /* A98 80063DF8 01000224 */   addiu     $v0, $zero, 0x1
    /* A9C 80063DFC 06008210 */  beq        $a0, $v0, .L80063E18
    /* AA0 80063E00 00020224 */   addiu     $v0, $zero, 0x200
  .L80063E04:
    /* AA4 80063E04 03030224 */  addiu      $v0, $zero, 0x303
    /* AA8 80063E08 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* AAC 80063E0C 03000224 */  addiu      $v0, $zero, 0x3
    /* AB0 80063E10 878F0108 */  j          .L80063E1C
    /* AB4 80063E14 2400A2AC */   sw        $v0, 0x24($a1)
  .L80063E18:
    /* AB8 80063E18 1C00A2AC */  sw         $v0, 0x1C($a1)
  .L80063E1C:
    /* ABC 80063E1C 5945000C */  jal        Task_NextState1
    /* AC0 80063E20 21202002 */   addu      $a0, $s1, $zero
  .L80063E24:
    /* AC4 80063E24 1800BF8F */  lw         $ra, 0x18($sp)
    /* AC8 80063E28 1400B18F */  lw         $s1, 0x14($sp)
    /* ACC 80063E2C 1000B08F */  lw         $s0, 0x10($sp)
    /* AD0 80063E30 0800E003 */  jr         $ra
    /* AD4 80063E34 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_StaticBgUpdate
