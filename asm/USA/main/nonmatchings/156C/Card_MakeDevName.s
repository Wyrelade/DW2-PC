nonmatching Card_MakeDevName, 0x5C

glabel Card_MakeDevName
    /* 2FD18 8003F518 21308000 */  addu       $a2, $a0, $zero
    /* 2FD1C 8003F51C 2138A000 */  addu       $a3, $a1, $zero
    /* 2FD20 8003F520 0180053C */  lui        $a1, %hi(D_80010D38)
    /* 2FD24 8003F524 380DA524 */  addiu      $a1, $a1, %lo(D_80010D38)
    /* 2FD28 8003F528 0300A288 */  lwl        $v0, 0x3($a1)
    /* 2FD2C 8003F52C 0000A298 */  lwr        $v0, 0x0($a1)
    /* 2FD30 8003F530 0400A380 */  lb         $v1, 0x4($a1)
    /* 2FD34 8003F534 0500A480 */  lb         $a0, 0x5($a1)
    /* 2FD38 8003F538 0300E2A8 */  swl        $v0, 0x3($a3)
    /* 2FD3C 8003F53C 0000E2B8 */  swr        $v0, 0x0($a3)
    /* 2FD40 8003F540 0400E3A0 */  sb         $v1, 0x4($a3)
    /* 2FD44 8003F544 0500E4A0 */  sb         $a0, 0x5($a3)
    /* 2FD48 8003F548 0200C104 */  bgez       $a2, .L8003F554
    /* 2FD4C 8003F54C 2110C000 */   addu      $v0, $a2, $zero
    /* 2FD50 8003F550 0F00C224 */  addiu      $v0, $a2, 0xF
  .L8003F554:
    /* 2FD54 8003F554 03110200 */  sra        $v0, $v0, 4
    /* 2FD58 8003F558 30004324 */  addiu      $v1, $v0, 0x30
    /* 2FD5C 8003F55C 00110200 */  sll        $v0, $v0, 4
    /* 2FD60 8003F560 2310C200 */  subu       $v0, $a2, $v0
    /* 2FD64 8003F564 30004224 */  addiu      $v0, $v0, 0x30
    /* 2FD68 8003F568 0200E3A0 */  sb         $v1, 0x2($a3)
    /* 2FD6C 8003F56C 0800E003 */  jr         $ra
    /* 2FD70 8003F570 0300E2A0 */   sb        $v0, 0x3($a3)
endlabel Card_MakeDevName
