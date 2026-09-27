nonmatching CdReady, 0x20

glabel CdReady
    /* 20CF4 800304F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 20CF8 800304F8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 20CFC 800304FC 66BD000C */  jal        func_8002F598
    /* 20D00 80030500 00000000 */   nop
    /* 20D04 80030504 1000BF8F */  lw         $ra, 0x10($sp)
    /* 20D08 80030508 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 20D0C 8003050C 0800E003 */  jr         $ra
    /* 20D10 80030510 00000000 */   nop
endlabel CdReady
