nonmatching DecDCTout, 0x20

glabel DecDCTout
    /* 1534 80064894 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1538 80064898 1000BFAF */  sw         $ra, 0x10($sp)
    /* 153C 8006489C C092010C */  jal        MDEC_out
    /* 1540 800648A0 00000000 */   nop
    /* 1544 800648A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1548 800648A8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 154C 800648AC 0800E003 */  jr         $ra
    /* 1550 800648B0 00000000 */   nop
endlabel DecDCTout
