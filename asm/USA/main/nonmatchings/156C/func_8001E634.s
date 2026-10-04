nonmatching func_8001E634, 0x24

glabel func_8001E634
    /* EE34 8001E634 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EE38 8001E638 1000BFAF */  sw         $ra, 0x10($sp)
    /* EE3C 8001E63C 3379000C */  jal        Flag_GetEntry
    /* EE40 8001E640 00000000 */   nop
    /* EE44 8001E644 00004284 */  lh         $v0, 0x0($v0)
    /* EE48 8001E648 1000BF8F */  lw         $ra, 0x10($sp)
    /* EE4C 8001E64C 00000000 */  nop
    /* EE50 8001E650 0800E003 */  jr         $ra
    /* EE54 8001E654 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E634
