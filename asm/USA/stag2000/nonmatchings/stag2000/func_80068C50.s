nonmatching func_80068C50, 0x34

glabel func_80068C50
    /* 58F0 80068C50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 58F4 80068C54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 58F8 80068C58 21808000 */  addu       $s0, $a0, $zero
    /* 58FC 80068C5C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5900 80068C60 2C00048E */  lw         $a0, 0x2C($s0)
    /* 5904 80068C64 2C70000C */  jal        Text_CloseArray
    /* 5908 80068C68 01000524 */   addiu     $a1, $zero, 0x1
    /* 590C 80068C6C 5C44000C */  jal        Task_DefaultDestroy
    /* 5910 80068C70 21200002 */   addu      $a0, $s0, $zero
    /* 5914 80068C74 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5918 80068C78 1000B08F */  lw         $s0, 0x10($sp)
    /* 591C 80068C7C 0800E003 */  jr         $ra
    /* 5920 80068C80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068C50
