nonmatching func_8006BBF0, 0x34

glabel func_8006BBF0
    /* 8890 8006BBF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8894 8006BBF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8898 8006BBF8 21808000 */  addu       $s0, $a0, $zero
    /* 889C 8006BBFC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 88A0 8006BC00 2C00048E */  lw         $a0, 0x2C($s0)
    /* 88A4 8006BC04 2C70000C */  jal        Text_CloseArray
    /* 88A8 8006BC08 01000524 */   addiu     $a1, $zero, 0x1
    /* 88AC 8006BC0C 5C44000C */  jal        Task_DefaultDestroy
    /* 88B0 8006BC10 21200002 */   addu      $a0, $s0, $zero
    /* 88B4 8006BC14 1400BF8F */  lw         $ra, 0x14($sp)
    /* 88B8 8006BC18 1000B08F */  lw         $s0, 0x10($sp)
    /* 88BC 8006BC1C 0800E003 */  jr         $ra
    /* 88C0 8006BC20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006BBF0
