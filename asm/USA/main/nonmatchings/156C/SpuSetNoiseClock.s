nonmatching SpuSetNoiseClock, 0x48

glabel SpuSetNoiseClock
    /* 2BF44 8003B744 21108000 */  addu       $v0, $a0, $zero
    /* 2BF48 8003B748 06004004 */  bltz       $v0, .L8003B764
    /* 2BF4C 8003B74C 21280000 */   addu      $a1, $zero, $zero
    /* 2BF50 8003B750 21284000 */  addu       $a1, $v0, $zero
    /* 2BF54 8003B754 4000A228 */  slti       $v0, $a1, 0x40
    /* 2BF58 8003B758 02004014 */  bnez       $v0, .L8003B764
    /* 2BF5C 8003B75C 00000000 */   nop
    /* 2BF60 8003B760 3F000524 */  addiu      $a1, $zero, 0x3F
  .L8003B764:
    /* 2BF64 8003B764 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2BF68 8003B768 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2BF6C 8003B76C 3F00A230 */  andi       $v0, $a1, 0x3F
    /* 2BF70 8003B770 AA018394 */  lhu        $v1, 0x1AA($a0)
    /* 2BF74 8003B774 00120200 */  sll        $v0, $v0, 8
    /* 2BF78 8003B778 FFC06330 */  andi       $v1, $v1, 0xC0FF
    /* 2BF7C 8003B77C 25186200 */  or         $v1, $v1, $v0
    /* 2BF80 8003B780 2110A000 */  addu       $v0, $a1, $zero
    /* 2BF84 8003B784 0800E003 */  jr         $ra
    /* 2BF88 8003B788 AA0183A4 */   sh        $v1, 0x1AA($a0)
endlabel SpuSetNoiseClock
    /* 2BF8C 8003B78C 00000000 */  nop
    /* 2BF90 8003B790 00000000 */  nop
