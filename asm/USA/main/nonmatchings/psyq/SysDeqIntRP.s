nonmatching SysDeqIntRP, 0xC

glabel SysDeqIntRP
    /* 177F4 80026FF4 C0000A24 */  addiu      $t2, $zero, 0xC0
    /* 177F8 80026FF8 08004001 */  jr         $t2
    /* 177FC 80026FFC 03000924 */   addiu     $t1, $zero, 0x3
endlabel SysDeqIntRP
    /* 17800 80027000 00000000 */  nop
