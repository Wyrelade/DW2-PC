nonmatching InitPAD, 0xC

glabel InitPAD
    /* 2E094 8003D894 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E098 8003D898 08004001 */  jr         $t2
    /* 2E09C 8003D89C 12000924 */   addiu     $t1, $zero, 0x12
endlabel InitPAD
    /* 2E0A0 8003D8A0 00000000 */  nop
