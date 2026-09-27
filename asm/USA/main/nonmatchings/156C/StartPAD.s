nonmatching StartPAD, 0xC

glabel StartPAD
    /* 2E0A4 8003D8A4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E0A8 8003D8A8 08004001 */  jr         $t2
    /* 2E0AC 8003D8AC 13000924 */   addiu     $t1, $zero, 0x13
endlabel StartPAD
    /* 2E0B0 8003D8B0 00000000 */  nop
