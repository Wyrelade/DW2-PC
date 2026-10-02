nonmatching SsSeqStop, 0x28

glabel SsSeqStop
    /* 25E74 80035674 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25E78 80035678 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25E7C 8003567C 00240400 */  sll        $a0, $a0, 16
    /* 25E80 80035680 03240400 */  sra        $a0, $a0, 16
    /* 25E84 80035684 3DD5000C */  jal        _SsSndStop
    /* 25E88 80035688 21280000 */   addu      $a1, $zero, $zero
    /* 25E8C 8003568C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25E90 80035690 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25E94 80035694 0800E003 */  jr         $ra
    /* 25E98 80035698 00000000 */   nop
endlabel SsSeqStop
