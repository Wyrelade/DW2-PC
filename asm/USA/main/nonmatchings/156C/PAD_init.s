nonmatching PAD_init, 0xC

glabel PAD_init
    /* 2E0B4 8003D8B4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E0B8 8003D8B8 08004001 */  jr         $t2
    /* 2E0BC 8003D8BC 15000924 */   addiu     $t1, $zero, 0x15
endlabel PAD_init
    /* 2E0C0 8003D8C0 00000000 */  nop
