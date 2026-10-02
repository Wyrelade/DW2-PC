nonmatching SsUtSetReverbFeedback, 0x3C

glabel SsUtSetReverbFeedback
    /* 26D14 80036514 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26D18 80036518 0680033C */  lui        $v1, %hi(D_80062C18)
    /* 26D1C 8003651C 182C6324 */  addiu      $v1, $v1, %lo(D_80062C18)
    /* 26D20 80036520 10000224 */  addiu      $v0, $zero, 0x10
    /* 26D24 80036524 00240400 */  sll        $a0, $a0, 16
    /* 26D28 80036528 03240400 */  sra        $a0, $a0, 16
    /* 26D2C 8003652C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26D30 80036530 100064AC */  sw         $a0, 0x10($v1)
    /* 26D34 80036534 21206000 */  addu       $a0, $v1, $zero
    /* 26D38 80036538 65EE000C */  jal        SpuSetReverbModeParam
    /* 26D3C 8003653C 000062AC */   sw        $v0, 0x0($v1)
    /* 26D40 80036540 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26D44 80036544 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 26D48 80036548 0800E003 */  jr         $ra
    /* 26D4C 8003654C 00000000 */   nop
endlabel SsUtSetReverbFeedback
    /* 26D50 80036550 00000000 */  nop
