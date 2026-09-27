nonmatching GsSetAmbient, 0x28

glabel GsSetAmbient
    /* 1C354 8002BB54 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C358 8002BB58 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C35C 8002BB5C 03210400 */  sra        $a0, $a0, 4
    /* 1C360 8002BB60 03290500 */  sra        $a1, $a1, 4
    /* 1C364 8002BB64 99B5000C */  jal        SetBackColor
    /* 1C368 8002BB68 03310600 */   sra       $a2, $a2, 4
    /* 1C36C 8002BB6C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C370 8002BB70 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C374 8002BB74 0800E003 */  jr         $ra
    /* 1C378 8002BB78 00000000 */   nop
endlabel GsSetAmbient
    /* 1C37C 8002BB7C 00000000 */  nop
    /* 1C380 8002BB80 00000000 */  nop
