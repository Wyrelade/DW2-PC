nonmatching func_8003D4D4, 0x20

glabel func_8003D4D4
    /* 2DCD4 8003D4D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DCD8 8003D4D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DCDC 8003D4DC 77F5000C */  jal        Card_Stop
    /* 2DCE0 8003D4E0 00000000 */   nop
    /* 2DCE4 8003D4E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DCE8 8003D4E8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2DCEC 8003D4EC 0800E003 */  jr         $ra
    /* 2DCF0 8003D4F0 00000000 */   nop
endlabel func_8003D4D4
