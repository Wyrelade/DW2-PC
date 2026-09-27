nonmatching func_80039A78, 0x68

glabel func_80039A78
    /* 2A278 80039A78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A27C 80039A7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A280 80039A80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A284 80039A84 69EB000C */  jal        func_8003ADA4
    /* 2A288 80039A88 2180C000 */   addu      $s0, $a2, $zero
    /* 2A28C 80039A8C 21184000 */  addu       $v1, $v0, $zero
    /* 2A290 80039A90 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2A294 80039A94 0E006214 */  bne        $v1, $v0, .L80039AD0
    /* 2A298 80039A98 21106000 */   addu      $v0, $v1, $zero
    /* 2A29C 80039A9C 00141000 */  sll        $v0, $s0, 16
    /* 2A2A0 80039AA0 03140200 */  sra        $v0, $v0, 16
    /* 2A2A4 80039AA4 0680013C */  lui        $at, %hi(D_80062D38)
    /* 2A2A8 80039AA8 21082200 */  addu       $at, $at, $v0
    /* 2A2AC 80039AAC 382D20A0 */  sb         $zero, %lo(D_80062D38)($at)
    /* 2A2B0 80039AB0 31F2000C */  jal        _spu_setInTransfer
    /* 2A2B4 80039AB4 21200000 */   addu      $a0, $zero, $zero
    /* 2A2B8 80039AB8 0680033C */  lui        $v1, %hi(D_80062D90)
    /* 2A2BC 80039ABC 902D6394 */  lhu        $v1, %lo(D_80062D90)($v1)
    /* 2A2C0 80039AC0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2A2C4 80039AC4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2A2C8 80039AC8 0680013C */  lui        $at, %hi(D_80062D90)
    /* 2A2CC 80039ACC 902D23A4 */  sh         $v1, %lo(D_80062D90)($at)
  .L80039AD0:
    /* 2A2D0 80039AD0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A2D4 80039AD4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A2D8 80039AD8 0800E003 */  jr         $ra
    /* 2A2DC 80039ADC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039A78
    /* 2A2E0 80039AE0 00000000 */  nop
