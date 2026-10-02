nonmatching DrawOTag, 0x70

glabel DrawOTag
    /* 18274 80027A74 0580023C */  lui        $v0, %hi(D_80048F12)
    /* 18278 80027A78 128F4290 */  lbu        $v0, %lo(D_80048F12)($v0)
    /* 1827C 80027A7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 18280 80027A80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 18284 80027A84 21808000 */  addu       $s0, $a0, $zero
    /* 18288 80027A88 0200422C */  sltiu      $v0, $v0, 0x2
    /* 1828C 80027A8C 08004014 */  bnez       $v0, .L80027AB0
    /* 18290 80027A90 1400BFAF */   sw        $ra, 0x14($sp)
    /* 18294 80027A94 0180043C */  lui        $a0, %hi(D_80010364)
    /* 18298 80027A98 64038424 */  addiu      $a0, $a0, %lo(D_80010364)
    /* 1829C 80027A9C 0580023C */  lui        $v0, %hi(D_80048F0C)
    /* 182A0 80027AA0 0C8F428C */  lw         $v0, %lo(D_80048F0C)($v0)
    /* 182A4 80027AA4 00000000 */  nop
    /* 182A8 80027AA8 09F84000 */  jalr       $v0
    /* 182AC 80027AAC 21280002 */   addu      $a1, $s0, $zero
  .L80027AB0:
    /* 182B0 80027AB0 21280002 */  addu       $a1, $s0, $zero
    /* 182B4 80027AB4 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 182B8 80027AB8 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 182BC 80027ABC 21300000 */  addu       $a2, $zero, $zero
    /* 182C0 80027AC0 1800448C */  lw         $a0, 0x18($v0)
    /* 182C4 80027AC4 0800428C */  lw         $v0, 0x8($v0)
    /* 182C8 80027AC8 00000000 */  nop
    /* 182CC 80027ACC 09F84000 */  jalr       $v0
    /* 182D0 80027AD0 21380000 */   addu      $a3, $zero, $zero
    /* 182D4 80027AD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 182D8 80027AD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 182DC 80027ADC 0800E003 */  jr         $ra
    /* 182E0 80027AE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DrawOTag
