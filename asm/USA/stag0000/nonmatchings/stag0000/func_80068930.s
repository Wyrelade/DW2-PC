nonmatching func_80068930, 0x28

glabel func_80068930
    /* 55D0 80068930 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 55D4 80068934 09010424 */  addiu      $a0, $zero, 0x109
    /* 55D8 80068938 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 55DC 8006893C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 55E0 80068940 4445000C */  jal        Task_FindFirst
    /* 55E4 80068944 2130A000 */   addu      $a2, $a1, $zero
    /* 55E8 80068948 1000BF8F */  lw         $ra, 0x10($sp)
    /* 55EC 8006894C 00000000 */  nop
    /* 55F0 80068950 0800E003 */  jr         $ra
    /* 55F4 80068954 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068930
