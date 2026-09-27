nonmatching WaitEvent, 0xC

glabel WaitEvent
    /* 2CD44 8003C544 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2CD48 8003C548 08004001 */  jr         $t2
    /* 2CD4C 8003C54C 0A000924 */   addiu     $t1, $zero, 0xA
endlabel WaitEvent
    /* 2CD50 8003C550 00000000 */  nop
