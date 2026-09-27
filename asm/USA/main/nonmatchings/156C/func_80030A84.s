nonmatching func_80030A84, 0x24

glabel func_80030A84
    /* 21284 80030A84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21288 80030A88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2128C 80030A8C 21288000 */  addu       $a1, $a0, $zero
    /* 21290 80030A90 4DC3000C */  jal        DMACallback
    /* 21294 80030A94 03000424 */   addiu     $a0, $zero, 0x3
    /* 21298 80030A98 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2129C 80030A9C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 212A0 80030AA0 0800E003 */  jr         $ra
    /* 212A4 80030AA4 00000000 */   nop
endlabel func_80030A84
    /* 212A8 80030AA8 00000000 */  nop
    /* 212AC 80030AAC 00000000 */  nop
    /* 212B0 80030AB0 00000000 */  nop
