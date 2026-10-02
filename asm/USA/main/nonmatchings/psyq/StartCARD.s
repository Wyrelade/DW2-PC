nonmatching StartCARD, 0xC

glabel StartCARD
    /* 2E1E4 8003D9E4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E1E8 8003D9E8 08004001 */  jr         $t2
    /* 2E1EC 8003D9EC 4B000924 */   addiu     $t1, $zero, 0x4B
endlabel StartCARD
    /* 2E1F0 8003D9F0 00000000 */  nop
