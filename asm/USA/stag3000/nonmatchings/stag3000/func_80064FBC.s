nonmatching func_80064FBC, 0x38

glabel func_80064FBC
    /* 1C5C 80064FBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C60 80064FC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C64 80064FC4 21808000 */  addu       $s0, $a0, $zero
    /* 1C68 80064FC8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C6C 80064FCC 2C00048E */  lw         $a0, 0x2C($s0)
    /* 1C70 80064FD0 04000524 */  addiu      $a1, $zero, 0x4
    /* 1C74 80064FD4 2C70000C */  jal        Text_CloseArray
    /* 1C78 80064FD8 04008424 */   addiu     $a0, $a0, 0x4
    /* 1C7C 80064FDC 5C44000C */  jal        Task_DefaultDestroy
    /* 1C80 80064FE0 21200002 */   addu      $a0, $s0, $zero
    /* 1C84 80064FE4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C88 80064FE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C8C 80064FEC 0800E003 */  jr         $ra
    /* 1C90 80064FF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80064FBC
