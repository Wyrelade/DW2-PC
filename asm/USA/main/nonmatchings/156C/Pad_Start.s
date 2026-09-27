nonmatching Pad_Start, 0x30

glabel Pad_Start
    /* 2DF40 8003D740 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DF44 8003D744 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DF48 8003D748 29F6000C */  jal        StartPAD
    /* 2DF4C 8003D74C 00000000 */   nop
    /* 2DF50 8003D750 31C3000C */  jal        ChangeClearPAD
    /* 2DF54 8003D754 21200000 */   addu      $a0, $zero, $zero
    /* 2DF58 8003D758 31F6000C */  jal        func_8003D8C4
    /* 2DF5C 8003D75C 00000000 */   nop
    /* 2DF60 8003D760 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DF64 8003D764 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DF68 8003D768 0800E003 */  jr         $ra
    /* 2DF6C 8003D76C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Pad_Start
