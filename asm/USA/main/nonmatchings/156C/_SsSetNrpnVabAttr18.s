nonmatching _SsSetNrpnVabAttr18, 0x24

glabel _SsSetNrpnVabAttr18
    /* 24BC4 800343C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24BC8 800343C8 4800A493 */  lbu        $a0, 0x48($sp)
    /* 24BCC 800343CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24BD0 800343D0 E9D8000C */  jal        SsUtSetReverbDelay
    /* 24BD4 800343D4 2400A7AF */   sw        $a3, 0x24($sp)
    /* 24BD8 800343D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24BDC 800343DC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 24BE0 800343E0 0800E003 */  jr         $ra
    /* 24BE4 800343E4 00000000 */   nop
endlabel _SsSetNrpnVabAttr18
    /* 24BE8 800343E8 00000000 */  nop
    /* 24BEC 800343EC 00000000 */  nop
    /* 24BF0 800343F0 00000000 */  nop
