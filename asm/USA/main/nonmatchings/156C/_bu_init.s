nonmatching _bu_init, 0xC

glabel _bu_init
    /* 2DCF4 8003D4F4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 2DCF8 8003D4F8 08004001 */  jr         $t2
    /* 2DCFC 8003D4FC 70000924 */   addiu     $t1, $zero, 0x70
endlabel _bu_init
    /* 2DD00 8003D500 00000000 */  nop
