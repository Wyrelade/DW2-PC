nonmatching lseek, 0xC

glabel lseek
    /* 2FD84 8003F584 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2FD88 8003F588 08004001 */  jr         $t2
    /* 2FD8C 8003F58C 33000924 */   addiu     $t1, $zero, 0x33
endlabel lseek
    /* 2FD90 8003F590 00000000 */  nop
