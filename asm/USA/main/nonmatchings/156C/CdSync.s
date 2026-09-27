nonmatching CdSync, 0x20

glabel CdSync
    /* 20CD4 800304D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 20CD8 800304D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 20CDC 800304DC C6BC000C */  jal        func_8002F318
    /* 20CE0 800304E0 00000000 */   nop
    /* 20CE4 800304E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 20CE8 800304E8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 20CEC 800304EC 0800E003 */  jr         $ra
    /* 20CF0 800304F0 00000000 */   nop
endlabel CdSync
