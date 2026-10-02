nonmatching TransposeMatrix, 0x40

glabel TransposeMatrix
    /* 1DF04 8002D704 2110A000 */  addu       $v0, $a1, $zero
    /* 1DF08 8002D708 0000898C */  lw         $t1, 0x0($a0)
    /* 1DF0C 8002D70C 04008A8C */  lw         $t2, 0x4($a0)
    /* 1DF10 8002D710 0400A9AC */  sw         $t1, 0x4($a1)
    /* 1DF14 8002D714 0000AAAC */  sw         $t2, 0x0($a1)
    /* 1DF18 8002D718 0000A9A4 */  sh         $t1, 0x0($a1)
    /* 1DF1C 8002D71C 08008B8C */  lw         $t3, 0x8($a0)
    /* 1DF20 8002D720 0C00898C */  lw         $t1, 0xC($a0)
    /* 1DF24 8002D724 0C00ABAC */  sw         $t3, 0xC($a1)
    /* 1DF28 8002D728 0800A9AC */  sw         $t1, 0x8($a1)
    /* 1DF2C 8002D72C 0C00AAA4 */  sh         $t2, 0xC($a1)
    /* 1DF30 8002D730 0800ABA4 */  sh         $t3, 0x8($a1)
    /* 1DF34 8002D734 10008A84 */  lh         $t2, 0x10($a0)
    /* 1DF38 8002D738 0400A9A4 */  sh         $t1, 0x4($a1)
    /* 1DF3C 8002D73C 0800E003 */  jr         $ra
    /* 1DF40 8002D740 1000AAA4 */   sh        $t2, 0x10($a1)
endlabel TransposeMatrix
