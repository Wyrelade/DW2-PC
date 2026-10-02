/* Handwritten function */
nonmatching RotTransPers, 0x2C

glabel RotTransPers
    /* 1DED4 8002D6D4 000080C8 */  lwc2       $0, 0x0($a0)
    /* 1DED8 8002D6D8 040081C8 */  lwc2       $1, 0x4($a0)
    /* 1DEDC 8002D6DC 00000000 */  nop
    /* 1DEE0 8002D6E0 0100184A */  rtps
    /* 1DEE4 8002D6E4 0000AEE8 */  swc2       $14, 0x0($a1)
    /* 1DEE8 8002D6E8 0000C8E8 */  swc2       $8, 0x0($a2)
    /* 1DEEC 8002D6EC 00F84348 */  cfc2       $v1, $31 /* handwritten instruction */
    /* 1DEF0 8002D6F0 00980248 */  mfc2       $v0, $19 /* handwritten instruction */
    /* 1DEF4 8002D6F4 0000E3AC */  sw         $v1, 0x0($a3)
    /* 1DEF8 8002D6F8 0800E003 */  jr         $ra
    /* 1DEFC 8002D6FC 83100200 */   sra       $v0, $v0, 2
endlabel RotTransPers
    /* 1DF00 8002D700 00000000 */  nop
