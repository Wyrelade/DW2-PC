nonmatching SsSepClose, 0x24

glabel SsSepClose
    /* 23044 80032844 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23048 80032848 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2304C 8003284C 00240400 */  sll        $a0, $a0, 16
    /* 23050 80032850 A9C9000C */  jal        _SsClose
    /* 23054 80032854 03240400 */   sra       $a0, $a0, 16
    /* 23058 80032858 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2305C 8003285C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 23060 80032860 0800E003 */  jr         $ra
    /* 23064 80032864 00000000 */   nop
endlabel SsSepClose
    /* 23068 80032868 00000000 */  nop
    /* 2306C 8003286C 00000000 */  nop
    /* 23070 80032870 00000000 */  nop
