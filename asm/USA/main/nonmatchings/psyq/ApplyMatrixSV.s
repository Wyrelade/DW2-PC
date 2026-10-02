/* Handwritten function */
nonmatching ApplyMatrixSV, 0x5C

glabel ApplyMatrixSV
    /* 1DC44 8002D444 0000888C */  lw         $t0, 0x0($a0)
    /* 1DC48 8002D448 0400898C */  lw         $t1, 0x4($a0)
    /* 1DC4C 8002D44C 08008A8C */  lw         $t2, 0x8($a0)
    /* 1DC50 8002D450 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1DC54 8002D454 10008C8C */  lw         $t4, 0x10($a0)
    /* 1DC58 8002D458 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1DC5C 8002D45C 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1DC60 8002D460 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 1DC64 8002D464 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 1DC68 8002D468 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 1DC6C 8002D46C 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 1DC70 8002D470 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 1DC74 8002D474 00000000 */  nop
    /* 1DC78 8002D478 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DC7C 8002D47C 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 1DC80 8002D480 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 1DC84 8002D484 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 1DC88 8002D488 0000C8A4 */  sh         $t0, 0x0($a2)
    /* 1DC8C 8002D48C 0200C9A4 */  sh         $t1, 0x2($a2)
    /* 1DC90 8002D490 0400CAA4 */  sh         $t2, 0x4($a2)
    /* 1DC94 8002D494 2110C000 */  addu       $v0, $a2, $zero
    /* 1DC98 8002D498 0800E003 */  jr         $ra
    /* 1DC9C 8002D49C 00000000 */   nop
endlabel ApplyMatrixSV
    /* 1DCA0 8002D4A0 00000000 */  nop
