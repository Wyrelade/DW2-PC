nonmatching func_8006F06C, 0x28

glabel func_8006F06C
    /* BD0C 8006F06C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BD10 8006F070 1000BFAF */  sw         $ra, 0x10($sp)
    /* BD14 8006F074 57BB010C */  jal        func_8006ED5C
    /* BD18 8006F078 00000000 */   nop
    /* BD1C 8006F07C 62BB010C */  jal        func_8006ED88
    /* BD20 8006F080 01000424 */   addiu     $a0, $zero, 0x1
    /* BD24 8006F084 1000BF8F */  lw         $ra, 0x10($sp)
    /* BD28 8006F088 00000000 */  nop
    /* BD2C 8006F08C 0800E003 */  jr         $ra
    /* BD30 8006F090 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F06C
