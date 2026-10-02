nonmatching EnableEvent, 0xC

glabel EnableEvent
    /* 2A9C4 8003A1C4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2A9C8 8003A1C8 08004001 */  jr         $t2
    /* 2A9CC 8003A1CC 0C000924 */   addiu     $t1, $zero, 0xC
endlabel EnableEvent
    /* 2A9D0 8003A1D0 00000000 */  nop
