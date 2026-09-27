nonmatching write, 0xC

glabel write
    /* 1B1A4 8002A9A4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1B1A8 8002A9A8 08004001 */  jr         $t2
    /* 1B1AC 8002A9AC 35000924 */   addiu     $t1, $zero, 0x35
endlabel write
    /* 1B1B0 8002A9B0 00000000 */  nop
