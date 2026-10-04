nonmatching DecDCTinSync, 0x3C

glabel DecDCTinSync
    /* 1554 800648B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1558 800648B8 05008014 */  bnez       $a0, .L800648D0
    /* 155C 800648BC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1560 800648C0 E392010C */  jal        MDEC_in_sync
    /* 1564 800648C4 00000000 */   nop
    /* 1568 800648C8 38920108 */  j          .L800648E0
    /* 156C 800648CC 00000000 */   nop
  .L800648D0:
    /* 1570 800648D0 2D93010C */  jal        func_80064CB4
    /* 1574 800648D4 00000000 */   nop
    /* 1578 800648D8 42170200 */  srl        $v0, $v0, 29
    /* 157C 800648DC 01004230 */  andi       $v0, $v0, 0x1
  .L800648E0:
    /* 1580 800648E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1584 800648E4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1588 800648E8 0800E003 */  jr         $ra
    /* 158C 800648EC 00000000 */   nop
endlabel DecDCTinSync
