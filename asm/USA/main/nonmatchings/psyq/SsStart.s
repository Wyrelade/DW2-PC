nonmatching SsStart, 0x20

glabel SsStart
    /* 25AA4 800352A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25AA8 800352A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25AAC 800352AC 1DD4000C */  jal        _SsStart
    /* 25AB0 800352B0 01000424 */   addiu     $a0, $zero, 0x1
    /* 25AB4 800352B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25AB8 800352B8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25ABC 800352BC 0800E003 */  jr         $ra
    /* 25AC0 800352C0 00000000 */   nop
endlabel SsStart
