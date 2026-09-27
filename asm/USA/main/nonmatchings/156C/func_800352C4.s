nonmatching func_800352C4, 0x20

glabel func_800352C4
    /* 25AC4 800352C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25AC8 800352C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25ACC 800352CC 1DD4000C */  jal        _SsStart
    /* 25AD0 800352D0 21200000 */   addu      $a0, $zero, $zero
    /* 25AD4 800352D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25AD8 800352D8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25ADC 800352DC 0800E003 */  jr         $ra
    /* 25AE0 800352E0 00000000 */   nop
endlabel func_800352C4
