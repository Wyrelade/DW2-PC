nonmatching func_80065894, 0x24

glabel func_80065894
    /* 2534 80065894 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2538 80065898 1000BFAF */  sw         $ra, 0x10($sp)
    /* 253C 8006589C 0000848C */  lw         $a0, 0x0($a0)
    /* 2540 800658A0 E26E000C */  jal        Text_Close
    /* 2544 800658A4 00000000 */   nop
    /* 2548 800658A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 254C 800658AC 00000000 */  nop
    /* 2550 800658B0 0800E003 */  jr         $ra
    /* 2554 800658B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80065894
