nonmatching Stg00_ScrollViewTask, 0x130

glabel Stg00_ScrollViewTask
    /* 9A4 80063D04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9A8 80063D08 01000224 */  addiu      $v0, $zero, 0x1
    /* 9AC 80063D0C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 9B0 80063D10 1000858C */  lw         $a1, 0x10($a0)
    /* 9B4 80063D14 2C00838C */  lw         $v1, 0x2C($a0)
    /* 9B8 80063D18 0A00A210 */  beq        $a1, $v0, .L80063D44
    /* 9BC 80063D1C 0200A228 */   slti      $v0, $a1, 0x2
    /* 9C0 80063D20 40004010 */  beqz       $v0, .L80063E24
    /* 9C4 80063D24 00000000 */   nop
    /* 9C8 80063D28 3E00A014 */  bnez       $a1, .L80063E24
    /* 9CC 80063D2C 00000000 */   nop
    /* 9D0 80063D30 000060AC */  sw         $zero, 0x0($v1)
    /* 9D4 80063D34 5145000C */  jal        Task_NextState0
    /* 9D8 80063D38 040060AC */   sw        $zero, 0x4($v1)
    /* 9DC 80063D3C 898F0108 */  j          .L80063E24
    /* 9E0 80063D40 00000000 */   nop
  .L80063D44:
    /* 9E4 80063D44 0680053C */  lui        $a1, %hi(Pad_State)
    /* 9E8 80063D48 F0F6A424 */  addiu      $a0, $a1, %lo(Pad_State)
    /* 9EC 80063D4C 0800828C */  lw         $v0, 0x8($a0)
    /* 9F0 80063D50 00000000 */  nop
    /* 9F4 80063D54 05004010 */  beqz       $v0, .L80063D6C
    /* 9F8 80063D58 00000000 */   nop
    /* 9FC 80063D5C 0400628C */  lw         $v0, 0x4($v1)
    /* A00 80063D60 00000000 */  nop
    /* A04 80063D64 04004224 */  addiu      $v0, $v0, 0x4
    /* A08 80063D68 040062AC */  sw         $v0, 0x4($v1)
  .L80063D6C:
    /* A0C 80063D6C 0C00828C */  lw         $v0, 0xC($a0)
    /* A10 80063D70 00000000 */  nop
    /* A14 80063D74 05004010 */  beqz       $v0, .L80063D8C
    /* A18 80063D78 00000000 */   nop
    /* A1C 80063D7C 0400628C */  lw         $v0, 0x4($v1)
    /* A20 80063D80 00000000 */  nop
    /* A24 80063D84 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* A28 80063D88 040062AC */  sw         $v0, 0x4($v1)
  .L80063D8C:
    /* A2C 80063D8C F0F6A28C */  lw         $v0, %lo(Pad_State)($a1)
    /* A30 80063D90 00000000 */  nop
    /* A34 80063D94 05004010 */  beqz       $v0, .L80063DAC
    /* A38 80063D98 00000000 */   nop
    /* A3C 80063D9C 0000628C */  lw         $v0, 0x0($v1)
    /* A40 80063DA0 00000000 */  nop
    /* A44 80063DA4 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* A48 80063DA8 000062AC */  sw         $v0, 0x0($v1)
  .L80063DAC:
    /* A4C 80063DAC 0400828C */  lw         $v0, 0x4($a0)
    /* A50 80063DB0 00000000 */  nop
    /* A54 80063DB4 05004010 */  beqz       $v0, .L80063DCC
    /* A58 80063DB8 00000000 */   nop
    /* A5C 80063DBC 0000628C */  lw         $v0, 0x0($v1)
    /* A60 80063DC0 00000000 */  nop
    /* A64 80063DC4 04004224 */  addiu      $v0, $v0, 0x4
    /* A68 80063DC8 000062AC */  sw         $v0, 0x0($v1)
  .L80063DCC:
    /* A6C 80063DCC 0000628C */  lw         $v0, 0x0($v1)
    /* A70 80063DD0 00000000 */  nop
    /* A74 80063DD4 05004018 */  blez       $v0, .L80063DEC
    /* A78 80063DD8 40FC4228 */   slti      $v0, $v0, -0x3C0
    /* A7C 80063DDC 000060AC */  sw         $zero, 0x0($v1)
    /* A80 80063DE0 0000628C */  lw         $v0, 0x0($v1)
    /* A84 80063DE4 00000000 */  nop
    /* A88 80063DE8 40FC4228 */  slti       $v0, $v0, -0x3C0
  .L80063DEC:
    /* A8C 80063DEC 02004010 */  beqz       $v0, .L80063DF8
    /* A90 80063DF0 40FC0224 */   addiu     $v0, $zero, -0x3C0
    /* A94 80063DF4 000062AC */  sw         $v0, 0x0($v1)
  .L80063DF8:
    /* A98 80063DF8 0400628C */  lw         $v0, 0x4($v1)
    /* A9C 80063DFC 00000000 */  nop
    /* AA0 80063E00 05004018 */  blez       $v0, .L80063E18
    /* AA4 80063E04 00FD4228 */   slti      $v0, $v0, -0x300
    /* AA8 80063E08 040060AC */  sw         $zero, 0x4($v1)
    /* AAC 80063E0C 0400628C */  lw         $v0, 0x4($v1)
    /* AB0 80063E10 00000000 */  nop
    /* AB4 80063E14 00FD4228 */  slti       $v0, $v0, -0x300
  .L80063E18:
    /* AB8 80063E18 02004010 */  beqz       $v0, .L80063E24
    /* ABC 80063E1C 00FD0224 */   addiu     $v0, $zero, -0x300
    /* AC0 80063E20 040062AC */  sw         $v0, 0x4($v1)
  .L80063E24:
    /* AC4 80063E24 1000BF8F */  lw         $ra, 0x10($sp)
    /* AC8 80063E28 00000000 */  nop
    /* ACC 80063E2C 0800E003 */  jr         $ra
    /* AD0 80063E30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg00_ScrollViewTask
