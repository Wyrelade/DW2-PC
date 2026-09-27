nonmatching _SsSetNrpnVabAttr19, 0x24

glabel _SsSetNrpnVabAttr19
    /* 24BF4 800343F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24BF8 800343F8 4800A493 */  lbu        $a0, 0x48($sp)
    /* 24BFC 800343FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24C00 80034400 E9D8000C */  jal        SsUtSetReverbDelay
    /* 24C04 80034404 2400A7AF */   sw        $a3, 0x24($sp)
    /* 24C08 80034408 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24C0C 8003440C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 24C10 80034410 0800E003 */  jr         $ra
    /* 24C14 80034414 00000000 */   nop
endlabel _SsSetNrpnVabAttr19
    /* 24C18 80034418 00000000 */  nop
    /* 24C1C 8003441C 00000000 */  nop
    /* 24C20 80034420 00000000 */  nop
