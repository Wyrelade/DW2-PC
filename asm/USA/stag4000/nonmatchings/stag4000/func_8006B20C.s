nonmatching func_8006B20C, 0x114

glabel func_8006B20C
    /* 7EAC 8006B20C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7EB0 8006B210 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7EB4 8006B214 21808000 */  addu       $s0, $a0, $zero
    /* 7EB8 8006B218 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7EBC 8006B21C 1800038E */  lw         $v1, 0x18($s0)
    /* 7EC0 8006B220 00000000 */  nop
    /* 7EC4 8006B224 0500622C */  sltiu      $v0, $v1, 0x5
    /* 7EC8 8006B228 08004010 */  beqz       $v0, .L8006B24C
    /* 7ECC 8006B22C 0680023C */   lui       $v0, %hi(jtbl_80063454)
    /* 7ED0 8006B230 54344224 */  addiu      $v0, $v0, %lo(jtbl_80063454)
    /* 7ED4 8006B234 80180300 */  sll        $v1, $v1, 2
    /* 7ED8 8006B238 21186200 */  addu       $v1, $v1, $v0
    /* 7EDC 8006B23C 0000628C */  lw         $v0, 0x0($v1)
    /* 7EE0 8006B240 00000000 */  nop
    /* 7EE4 8006B244 08004000 */  jr         $v0
    /* 7EE8 8006B248 00000000 */   nop
  jlabel .L8006B24C
    /* 7EEC 8006B24C 30000424 */  addiu      $a0, $zero, 0x30
    /* 7EF0 8006B250 A369000C */  jal        Snd_PlayById
    /* 7EF4 8006B254 01000524 */   addiu     $a1, $zero, 0x1
    /* 7EF8 8006B258 21200002 */  addu       $a0, $s0, $zero
    /* 7EFC 8006B25C 37B9010C */  jal        func_8006E4DC
    /* 7F00 8006B260 2B000524 */   addiu     $a1, $zero, 0x2B
    /* 7F04 8006B264 C2AC0108 */  j          .L8006B308
    /* 7F08 8006B268 00000000 */   nop
  jlabel .L8006B26C
    /* 7F0C 8006B26C 62B9010C */  jal        func_8006E588
    /* 7F10 8006B270 21200002 */   addu      $a0, $s0, $zero
    /* 7F14 8006B274 01000324 */  addiu      $v1, $zero, 0x1
    /* 7F18 8006B278 25004314 */  bne        $v0, $v1, .L8006B310
    /* 7F1C 8006B27C FD01053C */   lui       $a1, (0x1FD0054 >> 16)
    /* 7F20 8006B280 21206000 */  addu       $a0, $v1, $zero
    /* 7F24 8006B284 0580023C */  lui        $v0, %hi(D_80050720)
    /* 7F28 8006B288 2007468C */  lw         $a2, %lo(D_80050720)($v0)
    /* 7F2C 8006B28C 5400A534 */  ori        $a1, $a1, (0x1FD0054 & 0xFFFF)
    /* 7F30 8006B290 21380000 */  addu       $a3, $zero, $zero
    /* 7F34 8006B294 849D010C */  jal        func_80067610
    /* 7F38 8006B298 D100C624 */   addiu     $a2, $a2, 0xD1
    /* 7F3C 8006B29C C2AC0108 */  j          .L8006B308
    /* 7F40 8006B2A0 00000000 */   nop
  jlabel .L8006B2A4
    /* 7F44 8006B2A4 C19D010C */  jal        func_80067704
    /* 7F48 8006B2A8 01000424 */   addiu     $a0, $zero, 0x1
    /* 7F4C 8006B2AC 21304000 */  addu       $a2, $v0, $zero
    /* 7F50 8006B2B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 7F54 8006B2B4 1600C214 */  bne        $a2, $v0, .L8006B310
    /* 7F58 8006B2B8 0580053C */   lui       $a1, %hi(D_8005071C)
    /* 7F5C 8006B2BC 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 7F60 8006B2C0 1C07A38C */  lw         $v1, %lo(D_8005071C)($a1)
    /* 7F64 8006B2C4 03000224 */  addiu      $v0, $zero, 0x3
    /* 7F68 8006B2C8 010062A0 */  sb         $v0, 0x1($v1)
    /* 7F6C 8006B2CC 1C07A28C */  lw         $v0, %lo(D_8005071C)($a1)
    /* 7F70 8006B2D0 21280000 */  addu       $a1, $zero, $zero
    /* 7F74 8006B2D4 A369000C */  jal        Snd_PlayById
    /* 7F78 8006B2D8 070046A0 */   sb        $a2, 0x7($v0)
    /* 7F7C 8006B2DC C2AC0108 */  j          .L8006B308
    /* 7F80 8006B2E0 00000000 */   nop
  jlabel .L8006B2E4
    /* 7F84 8006B2E4 1C00028E */  lw         $v0, 0x1C($s0)
    /* 7F88 8006B2E8 00000000 */  nop
    /* 7F8C 8006B2EC 21184000 */  addu       $v1, $v0, $zero
    /* 7F90 8006B2F0 01004224 */  addiu      $v0, $v0, 0x1
    /* 7F94 8006B2F4 1E006328 */  slti       $v1, $v1, 0x1E
    /* 7F98 8006B2F8 05006014 */  bnez       $v1, .L8006B310
    /* 7F9C 8006B2FC 1C0002AE */   sw        $v0, 0x1C($s0)
    /* 7FA0 8006B300 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 7FA4 8006B304 10000424 */   addiu     $a0, $zero, 0x10
  .L8006B308:
    /* 7FA8 8006B308 6045000C */  jal        Task_NextState2
    /* 7FAC 8006B30C 21200002 */   addu      $a0, $s0, $zero
  jlabel .L8006B310
    /* 7FB0 8006B310 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7FB4 8006B314 1000B08F */  lw         $s0, 0x10($sp)
    /* 7FB8 8006B318 0800E003 */  jr         $ra
    /* 7FBC 8006B31C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B20C
