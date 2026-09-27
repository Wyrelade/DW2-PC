nonmatching InitCARD, 0xC

glabel InitCARD
    /* 2E1D4 8003D9D4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E1D8 8003D9D8 08004001 */  jr         $t2
    /* 2E1DC 8003D9DC 4A000924 */   addiu     $t1, $zero, 0x4A
endlabel InitCARD
    /* 2E1E0 8003D9E0 00000000 */  nop
