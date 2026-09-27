nonmatching _new_card, 0xC

glabel _new_card
    /* 30204 8003FA04 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 30208 8003FA08 08004001 */  jr         $t2
    /* 3020C 8003FA0C 50000924 */   addiu     $t1, $zero, 0x50
endlabel _new_card
    /* 30210 8003FA10 00000000 */  nop
