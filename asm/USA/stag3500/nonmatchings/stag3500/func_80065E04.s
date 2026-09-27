nonmatching func_80065E04, 0x40

glabel func_80065E04
    /* 2AA4 80065E04 21180000 */  addu       $v1, $zero, $zero
    /* 2AA8 80065E08 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 2AAC 80065E0C 0780023C */  lui        $v0, %hi(D_8006AA58)
    /* 2AB0 80065E10 58AA4424 */  addiu      $a0, $v0, %lo(D_8006AA58)
  .L80065E14:
    /* 2AB4 80065E14 0000828C */  lw         $v0, 0x0($a0)
    /* 2AB8 80065E18 00000000 */  nop
    /* 2ABC 80065E1C 07004510 */  beq        $v0, $a1, .L80065E3C
    /* 2AC0 80065E20 21106000 */   addu      $v0, $v1, $zero
    /* 2AC4 80065E24 01006324 */  addiu      $v1, $v1, 0x1
    /* 2AC8 80065E28 0C006228 */  slti       $v0, $v1, 0xC
    /* 2ACC 80065E2C F9FF4014 */  bnez       $v0, .L80065E14
    /* 2AD0 80065E30 04008424 */   addiu     $a0, $a0, 0x4
    /* 2AD4 80065E34 0800E003 */  jr         $ra
    /* 2AD8 80065E38 FFFF6224 */   addiu     $v0, $v1, -0x1
  .L80065E3C:
    /* 2ADC 80065E3C 0800E003 */  jr         $ra
    /* 2AE0 80065E40 00000000 */   nop
endlabel func_80065E04
