nonmatching func_8006E8F4, 0x2C

glabel func_8006E8F4
    /* B594 8006E8F4 0580023C */  lui        $v0, %hi(D_80050720)
    /* B598 8006E8F8 2007458C */  lw         $a1, %lo(D_80050720)($v0)
    /* B59C 8006E8FC 00000000 */  nop
    /* B5A0 8006E900 2400A284 */  lh         $v0, 0x24($a1)
    /* B5A4 8006E904 2400A394 */  lhu        $v1, 0x24($a1)
    /* B5A8 8006E908 23104400 */  subu       $v0, $v0, $a0
    /* B5AC 8006E90C 02004104 */  bgez       $v0, .L8006E918
    /* B5B0 8006E910 23106400 */   subu      $v0, $v1, $a0
    /* B5B4 8006E914 21100000 */  addu       $v0, $zero, $zero
  .L8006E918:
    /* B5B8 8006E918 0800E003 */  jr         $ra
    /* B5BC 8006E91C 2400A2A4 */   sh        $v0, 0x24($a1)
endlabel func_8006E8F4
