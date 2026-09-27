nonmatching _card_write, 0xC

glabel _card_write
    /* 301F4 8003F9F4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 301F8 8003F9F8 08004001 */  jr         $t2
    /* 301FC 8003F9FC 4E000924 */   addiu     $t1, $zero, 0x4E
endlabel _card_write
    /* 30200 8003FA00 00000000 */  nop
