nonmatching _SsSetNrpnVabAttr16, 0x28

glabel _SsSetNrpnVabAttr16
    /* 24B64 80034364 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24B68 80034368 4800A493 */  lbu        $a0, 0x48($sp)
    /* 24B6C 8003436C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24B70 80034370 2400A7AF */  sw         $a3, 0x24($sp)
    /* 24B74 80034374 F9D8000C */  jal        SsUtSetReverbDepth
    /* 24B78 80034378 21288000 */   addu      $a1, $a0, $zero
    /* 24B7C 8003437C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24B80 80034380 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 24B84 80034384 0800E003 */  jr         $ra
    /* 24B88 80034388 00000000 */   nop
endlabel _SsSetNrpnVabAttr16
    /* 24B8C 8003438C 00000000 */  nop
    /* 24B90 80034390 00000000 */  nop
