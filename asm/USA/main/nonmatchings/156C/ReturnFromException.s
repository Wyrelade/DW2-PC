nonmatching ReturnFromException, 0xC

glabel ReturnFromException
    /* 21BB4 800313B4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 21BB8 800313B8 08004001 */  jr         $t2
    /* 21BBC 800313BC 17000924 */   addiu     $t1, $zero, 0x17
endlabel ReturnFromException
    /* 21BC0 800313C0 00000000 */  nop
