nonmatching SpuInitMalloc, 0x54

glabel SpuInitMalloc
    /* 2B544 8003AD44 21108000 */  addu       $v0, $a0, $zero
    /* 2B548 8003AD48 0300401C */  bgtz       $v0, .L8003AD58
    /* 2B54C 8003AD4C 0040033C */   lui       $v1, (0x40001010 >> 16)
    /* 2B550 8003AD50 64EB0008 */  j          .L8003AD90
    /* 2B554 8003AD54 21100000 */   addu      $v0, $zero, $zero
  .L8003AD58:
    /* 2B558 8003AD58 0580043C */  lui        $a0, %hi(D_8004FE50)
    /* 2B55C 8003AD5C 50FE848C */  lw         $a0, %lo(D_8004FE50)($a0)
    /* 2B560 8003AD60 10106334 */  ori        $v1, $v1, (0x40001010 & 0xFFFF)
    /* 2B564 8003AD64 0000A3AC */  sw         $v1, 0x0($a1)
    /* 2B568 8003AD68 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2B56C 8003AD6C 0580013C */  lui        $at, %hi(Spu_MemList)
    /* 2B570 8003AD70 90FE25AC */  sw         $a1, %lo(Spu_MemList)($at)
    /* 2B574 8003AD74 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2B578 8003AD78 8CFE20AC */  sw         $zero, %lo(D_8004FE8C)($at)
    /* 2B57C 8003AD7C 0580013C */  lui        $at, %hi(D_8004FE88)
    /* 2B580 8003AD80 88FE22AC */  sw         $v0, %lo(D_8004FE88)($at)
    /* 2B584 8003AD84 04188300 */  sllv       $v1, $v1, $a0
    /* 2B588 8003AD88 F0EF6324 */  addiu      $v1, $v1, -0x1010
    /* 2B58C 8003AD8C 0400A3AC */  sw         $v1, 0x4($a1)
  .L8003AD90:
    /* 2B590 8003AD90 0800E003 */  jr         $ra
    /* 2B594 8003AD94 00000000 */   nop
endlabel SpuInitMalloc
    /* 2B598 8003AD98 00000000 */  nop
    /* 2B59C 8003AD9C 00000000 */  nop
    /* 2B5A0 8003ADA0 00000000 */  nop
