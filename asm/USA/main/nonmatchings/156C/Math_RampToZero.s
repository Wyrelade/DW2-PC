nonmatching Math_RampToZero, 0x28

glabel Math_RampToZero
    /* 3F14 80013714 0000A28C */  lw         $v0, 0x0($a1)
    /* 3F18 80013718 00000000 */  nop
    /* 3F1C 8001371C CDFC4224 */  addiu      $v0, $v0, -0x333
    /* 3F20 80013720 03004018 */  blez       $v0, .L80013730
    /* 3F24 80013724 0000A2AC */   sw        $v0, 0x0($a1)
    /* 3F28 80013728 0800E003 */  jr         $ra
    /* 3F2C 8001372C 01000224 */   addiu     $v0, $zero, 0x1
  .L80013730:
    /* 3F30 80013730 0000A0AC */  sw         $zero, 0x0($a1)
    /* 3F34 80013734 0800E003 */  jr         $ra
    /* 3F38 80013738 21100000 */   addu      $v0, $zero, $zero
endlabel Math_RampToZero
