nonmatching SsVabTransCompleted, 0x28

glabel SsVabTransCompleted
    /* 2A804 8003A004 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A808 8003A008 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A80C 8003A00C 00240400 */  sll        $a0, $a0, 16
    /* 2A810 8003A010 01F2000C */  jal        SpuIsTransferCompleted
    /* 2A814 8003A014 03240400 */   sra       $a0, $a0, 16
    /* 2A818 8003A018 00140200 */  sll        $v0, $v0, 16
    /* 2A81C 8003A01C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A820 8003A020 03140200 */  sra        $v0, $v0, 16
    /* 2A824 8003A024 0800E003 */  jr         $ra
    /* 2A828 8003A028 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SsVabTransCompleted
    /* 2A82C 8003A02C 00000000 */  nop
    /* 2A830 8003A030 00000000 */  nop
