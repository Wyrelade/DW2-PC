nonmatching StopCARD, 0xC

glabel StopCARD
    /* 2E1F4 8003D9F4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E1F8 8003D9F8 08004001 */  jr         $t2
    /* 2E1FC 8003D9FC 4C000924 */   addiu     $t1, $zero, 0x4C
endlabel StopCARD
    /* 2E200 8003DA00 00000000 */  nop
