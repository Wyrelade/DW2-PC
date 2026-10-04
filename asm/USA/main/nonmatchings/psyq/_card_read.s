nonmatching _card_read, 0xC

glabel _card_read
    /* 314E4 80040CE4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 314E8 80040CE8 08004001 */  jr         $t2
    /* 314EC 80040CEC 4F000924 */   addiu     $t1, $zero, 0x4F
endlabel _card_read
