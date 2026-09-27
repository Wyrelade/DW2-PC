nonmatching func_8006D0F0, 0x34

glabel func_8006D0F0
    /* 9D90 8006D0F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9D94 8006D0F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9D98 8006D0F8 21808000 */  addu       $s0, $a0, $zero
    /* 9D9C 8006D0FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 9DA0 8006D100 2C00048E */  lw         $a0, 0x2C($s0)
    /* 9DA4 8006D104 2C70000C */  jal        Text_CloseArray
    /* 9DA8 8006D108 0F000524 */   addiu     $a1, $zero, 0xF
    /* 9DAC 8006D10C 5C44000C */  jal        Task_DefaultDestroy
    /* 9DB0 8006D110 21200002 */   addu      $a0, $s0, $zero
    /* 9DB4 8006D114 1400BF8F */  lw         $ra, 0x14($sp)
    /* 9DB8 8006D118 1000B08F */  lw         $s0, 0x10($sp)
    /* 9DBC 8006D11C 0800E003 */  jr         $ra
    /* 9DC0 8006D120 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006D0F0
