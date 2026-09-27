nonmatching func_8003FBC4, 0x30

glabel func_8003FBC4
    /* 303C4 8003FBC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 303C8 8003FBC8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 303CC 8003FBCC 41F5000C */  jal        func_8003D504
    /* 303D0 8003FBD0 00000000 */   nop
    /* 303D4 8003FBD4 65F5000C */  jal        Card_Start
    /* 303D8 8003FBD8 00000000 */   nop
    /* 303DC 8003FBDC 3DF5000C */  jal        _bu_init
    /* 303E0 8003FBE0 00000000 */   nop
    /* 303E4 8003FBE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 303E8 8003FBE8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 303EC 8003FBEC 0800E003 */  jr         $ra
    /* 303F0 8003FBF0 00000000 */   nop
endlabel func_8003FBC4
