nonmatching DecDCToutCallback, 0x24

glabel DecDCToutCallback
    /* 15FC 8006495C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1600 80064960 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1604 80064964 21288000 */  addu       $a1, $a0, $zero
    /* 1608 80064968 4DC3000C */  jal        DMACallback
    /* 160C 8006496C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1610 80064970 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1614 80064974 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1618 80064978 0800E003 */  jr         $ra
    /* 161C 8006497C 00000000 */   nop
endlabel DecDCToutCallback
