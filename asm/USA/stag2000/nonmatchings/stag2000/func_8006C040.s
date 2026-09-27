nonmatching func_8006C040, 0x34

glabel func_8006C040
    /* 8CE0 8006C040 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8CE4 8006C044 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8CE8 8006C048 21808000 */  addu       $s0, $a0, $zero
    /* 8CEC 8006C04C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8CF0 8006C050 2C00048E */  lw         $a0, 0x2C($s0)
    /* 8CF4 8006C054 2C70000C */  jal        Text_CloseArray
    /* 8CF8 8006C058 02000524 */   addiu     $a1, $zero, 0x2
    /* 8CFC 8006C05C 5C44000C */  jal        Task_DefaultDestroy
    /* 8D00 8006C060 21200002 */   addu      $a0, $s0, $zero
    /* 8D04 8006C064 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8D08 8006C068 1000B08F */  lw         $s0, 0x10($sp)
    /* 8D0C 8006C06C 0800E003 */  jr         $ra
    /* 8D10 8006C070 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C040
