nonmatching _SsSetNrpnVabAttr15, 0x24

glabel _SsSetNrpnVabAttr15
    /* 24B34 80034334 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24B38 80034338 4800A493 */  lbu        $a0, 0x48($sp)
    /* 24B3C 8003433C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24B40 80034340 1DD9000C */  jal        SsUtSetReverbType
    /* 24B44 80034344 2400A7AF */   sw        $a3, 0x24($sp)
    /* 24B48 80034348 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24B4C 8003434C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 24B50 80034350 0800E003 */  jr         $ra
    /* 24B54 80034354 00000000 */   nop
endlabel _SsSetNrpnVabAttr15
    /* 24B58 80034358 00000000 */  nop
    /* 24B5C 8003435C 00000000 */  nop
    /* 24B60 80034360 00000000 */  nop
