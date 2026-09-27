nonmatching func_80063D34, 0xF0

glabel func_80063D34
    /* 9D4 80063D34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9D8 80063D38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9DC 80063D3C 21808000 */  addu       $s0, $a0, $zero
    /* 9E0 80063D40 01000224 */  addiu      $v0, $zero, 0x1
    /* 9E4 80063D44 1400BFAF */  sw         $ra, 0x14($sp)
    /* 9E8 80063D48 1000048E */  lw         $a0, 0x10($s0)
    /* 9EC 80063D4C 2C00058E */  lw         $a1, 0x2C($s0)
    /* 9F0 80063D50 09008210 */  beq        $a0, $v0, .L80063D78
    /* 9F4 80063D54 02008228 */   slti      $v0, $a0, 0x2
    /* 9F8 80063D58 2E004010 */  beqz       $v0, .L80063E14
    /* 9FC 80063D5C 00000000 */   nop
    /* A00 80063D60 2C008014 */  bnez       $a0, .L80063E14
    /* A04 80063D64 00000000 */   nop
    /* A08 80063D68 5145000C */  jal        Task_NextState0
    /* A0C 80063D6C 21200002 */   addu      $a0, $s0, $zero
    /* A10 80063D70 858F0108 */  j          .L80063E14
    /* A14 80063D74 00000000 */   nop
  .L80063D78:
    /* A18 80063D78 1400038E */  lw         $v1, 0x14($s0)
    /* A1C 80063D7C 00000000 */  nop
    /* A20 80063D80 0E006410 */  beq        $v1, $a0, .L80063DBC
    /* A24 80063D84 02006228 */   slti      $v0, $v1, 0x2
    /* A28 80063D88 05004014 */  bnez       $v0, .L80063DA0
    /* A2C 80063D8C 02000224 */   addiu     $v0, $zero, 0x2
    /* A30 80063D90 16006210 */  beq        $v1, $v0, .L80063DEC
    /* A34 80063D94 03000224 */   addiu     $v0, $zero, 0x3
    /* A38 80063D98 1E006210 */  beq        $v1, $v0, .L80063E14
    /* A3C 80063D9C 00000000 */   nop
  .L80063DA0:
    /* A40 80063DA0 0000A28C */  lw         $v0, 0x0($a1)
    /* A44 80063DA4 07000324 */  addiu      $v1, $zero, 0x7
    /* A48 80063DA8 01004224 */  addiu      $v0, $v0, 0x1
    /* A4C 80063DAC 19004314 */  bne        $v0, $v1, .L80063E14
    /* A50 80063DB0 0000A2AC */   sw        $v0, 0x0($a1)
    /* A54 80063DB4 5945000C */  jal        Task_NextState1
    /* A58 80063DB8 21200002 */   addu      $a0, $s0, $zero
  .L80063DBC:
    /* A5C 80063DBC 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* A60 80063DC0 F0F64324 */  addiu      $v1, $v0, %lo(D_8005F6F0)
    /* A64 80063DC4 1400628C */  lw         $v0, 0x14($v1)
    /* A68 80063DC8 00000000 */  nop
    /* A6C 80063DCC 0F00401C */  bgtz       $v0, .L80063E0C
    /* A70 80063DD0 00000000 */   nop
    /* A74 80063DD4 3400628C */  lw         $v0, 0x34($v1)
    /* A78 80063DD8 00000000 */  nop
    /* A7C 80063DDC 0D004018 */  blez       $v0, .L80063E14
    /* A80 80063DE0 00000000 */   nop
    /* A84 80063DE4 838F0108 */  j          .L80063E0C
    /* A88 80063DE8 00000000 */   nop
  .L80063DEC:
    /* A8C 80063DEC 0000A28C */  lw         $v0, 0x0($a1)
    /* A90 80063DF0 00000000 */  nop
    /* A94 80063DF4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* A98 80063DF8 06004014 */  bnez       $v0, .L80063E14
    /* A9C 80063DFC 0000A2AC */   sw        $v0, 0x0($a1)
    /* AA0 80063E00 0680033C */  lui        $v1, %hi(D_8005F78C)
    /* AA4 80063E04 07040224 */  addiu      $v0, $zero, 0x407
    /* AA8 80063E08 8CF762AC */  sw         $v0, %lo(D_8005F78C)($v1)
  .L80063E0C:
    /* AAC 80063E0C 5945000C */  jal        Task_NextState1
    /* AB0 80063E10 21200002 */   addu      $a0, $s0, $zero
  .L80063E14:
    /* AB4 80063E14 1400BF8F */  lw         $ra, 0x14($sp)
    /* AB8 80063E18 1000B08F */  lw         $s0, 0x10($sp)
    /* ABC 80063E1C 0800E003 */  jr         $ra
    /* AC0 80063E20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063D34
