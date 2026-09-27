nonmatching func_80064B70, 0x24

glabel func_80064B70
    /* 1810 80064B70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1814 80064B74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1818 80064B78 2C00848C */  lw         $a0, 0x2C($a0)
    /* 181C 80064B7C 6C98010C */  jal        func_800661B0
    /* 1820 80064B80 00000000 */   nop
    /* 1824 80064B84 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1828 80064B88 00000000 */  nop
    /* 182C 80064B8C 0800E003 */  jr         $ra
    /* 1830 80064B90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80064B70
