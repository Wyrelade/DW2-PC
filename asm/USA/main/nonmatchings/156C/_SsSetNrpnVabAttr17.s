nonmatching _SsSetNrpnVabAttr17, 0x24

glabel _SsSetNrpnVabAttr17
    /* 24B94 80034394 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24B98 80034398 4800A493 */  lbu        $a0, 0x48($sp)
    /* 24B9C 8003439C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24BA0 800343A0 45D9000C */  jal        SsUtSetReverbFeedback
    /* 24BA4 800343A4 2400A7AF */   sw        $a3, 0x24($sp)
    /* 24BA8 800343A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24BAC 800343AC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 24BB0 800343B0 0800E003 */  jr         $ra
    /* 24BB4 800343B4 00000000 */   nop
endlabel _SsSetNrpnVabAttr17
    /* 24BB8 800343B8 00000000 */  nop
    /* 24BBC 800343BC 00000000 */  nop
    /* 24BC0 800343C0 00000000 */  nop
