nonmatching SysEnqIntRP, 0xC

glabel SysEnqIntRP
    /* 177E4 80026FE4 C0000A24 */  addiu      $t2, $zero, 0xC0
    /* 177E8 80026FE8 08004001 */  jr         $t2
    /* 177EC 80026FEC 02000924 */   addiu     $t1, $zero, 0x2
endlabel SysEnqIntRP
    /* 177F0 80026FF0 00000000 */  nop
