nonmatching func_8003FDD0, 0x20

glabel func_8003FDD0
    /* 305D0 8003FDD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 305D4 8003FDD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 305D8 8003FDD8 77F5000C */  jal        Card_Stop
    /* 305DC 8003FDDC 00000000 */   nop
    /* 305E0 8003FDE0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 305E4 8003FDE4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 305E8 8003FDE8 0800E003 */  jr         $ra
    /* 305EC 8003FDEC 00000000 */   nop
endlabel func_8003FDD0
