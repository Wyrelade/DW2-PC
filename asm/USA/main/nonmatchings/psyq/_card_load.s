nonmatching _card_load, 0xC

glabel _card_load
    /* 301A4 8003F9A4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 301A8 8003F9A8 08004001 */  jr         $t2
    /* 301AC 8003F9AC AC000924 */   addiu     $t1, $zero, 0xAC
endlabel _card_load
    /* 301B0 8003F9B0 00000000 */  nop
