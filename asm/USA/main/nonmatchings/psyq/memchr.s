nonmatching memchr, 0x50

glabel memchr
    /* 1AEF4 8002A6F4 11008010 */  beqz       $a0, .L8002A73C
    /* 1AEF8 8002A6F8 21100000 */   addu      $v0, $zero, $zero
    /* 1AEFC 8002A6FC 0F00C018 */  blez       $a2, .L8002A73C
    /* 1AF00 8002A700 00000000 */   nop
    /* 1AF04 8002A704 C5A90008 */  j          .L8002A714
    /* 1AF08 8002A708 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L8002A70C:
    /* 1AF0C 8002A70C CFA90008 */  j          .L8002A73C
    /* 1AF10 8002A710 FFFF8224 */   addiu     $v0, $a0, -0x1
  .L8002A714:
    /* 1AF14 8002A714 0900C004 */  bltz       $a2, .L8002A73C
    /* 1AF18 8002A718 21100000 */   addu      $v0, $zero, $zero
    /* 1AF1C 8002A71C FF00A530 */  andi       $a1, $a1, 0xFF
  .L8002A720:
    /* 1AF20 8002A720 00008290 */  lbu        $v0, 0x0($a0)
    /* 1AF24 8002A724 00000000 */  nop
    /* 1AF28 8002A728 F8FF4510 */  beq        $v0, $a1, .L8002A70C
    /* 1AF2C 8002A72C 01008424 */   addiu     $a0, $a0, 0x1
    /* 1AF30 8002A730 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 1AF34 8002A734 FAFFC104 */  bgez       $a2, .L8002A720
    /* 1AF38 8002A738 21100000 */   addu      $v0, $zero, $zero
  .L8002A73C:
    /* 1AF3C 8002A73C 0800E003 */  jr         $ra
    /* 1AF40 8002A740 00000000 */   nop
endlabel memchr
