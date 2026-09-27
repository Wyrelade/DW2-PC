nonmatching func_800649D4, 0x24

glabel func_800649D4
    /* 1674 800649D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1678 800649D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 167C 800649DC 0400848C */  lw         $a0, 0x4($a0)
    /* 1680 800649E0 826F000C */  jal        Text_IsFinished
    /* 1684 800649E4 00000000 */   nop
    /* 1688 800649E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 168C 800649EC 00000000 */  nop
    /* 1690 800649F0 0800E003 */  jr         $ra
    /* 1694 800649F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800649D4
