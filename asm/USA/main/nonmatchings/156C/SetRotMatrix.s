/* Handwritten function */
nonmatching SetRotMatrix, 0x30

glabel SetRotMatrix
    /* 1DDE4 8002D5E4 0000888C */  lw         $t0, 0x0($a0)
    /* 1DDE8 8002D5E8 0400898C */  lw         $t1, 0x4($a0)
    /* 1DDEC 8002D5EC 08008A8C */  lw         $t2, 0x8($a0)
    /* 1DDF0 8002D5F0 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1DDF4 8002D5F4 10008C8C */  lw         $t4, 0x10($a0)
    /* 1DDF8 8002D5F8 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1DDFC 8002D5FC 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1DE00 8002D600 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 1DE04 8002D604 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 1DE08 8002D608 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 1DE0C 8002D60C 0800E003 */  jr         $ra
    /* 1DE10 8002D610 00000000 */   nop
endlabel SetRotMatrix
