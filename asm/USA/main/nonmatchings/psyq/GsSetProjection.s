nonmatching GsSetProjection, 0x20

glabel GsSetProjection
    /* 1BD44 8002B544 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BD48 8002B548 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1BD4C 8002B54C B1B5000C */  jal        SetGeomScreen
    /* 1BD50 8002B550 00000000 */   nop
    /* 1BD54 8002B554 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BD58 8002B558 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1BD5C 8002B55C 0800E003 */  jr         $ra
    /* 1BD60 8002B560 00000000 */   nop
endlabel GsSetProjection
