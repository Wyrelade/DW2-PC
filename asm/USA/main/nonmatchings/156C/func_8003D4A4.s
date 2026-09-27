nonmatching func_8003D4A4, 0x30

glabel func_8003D4A4
    /* 2DCA4 8003D4A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DCA8 8003D4A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DCAC 8003D4AC 41F5000C */  jal        func_8003D504
    /* 2DCB0 8003D4B0 00000000 */   nop
    /* 2DCB4 8003D4B4 65F5000C */  jal        func_8003D594
    /* 2DCB8 8003D4B8 00000000 */   nop
    /* 2DCBC 8003D4BC 3DF5000C */  jal        _bu_init
    /* 2DCC0 8003D4C0 00000000 */   nop
    /* 2DCC4 8003D4C4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DCC8 8003D4C8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2DCCC 8003D4CC 0800E003 */  jr         $ra
    /* 2DCD0 8003D4D0 00000000 */   nop
endlabel func_8003D4A4
