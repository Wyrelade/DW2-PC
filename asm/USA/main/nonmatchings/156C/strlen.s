nonmatching strlen, 0x34

glabel strlen
    /* 1B1B4 8002A9B4 21180000 */  addu       $v1, $zero, $zero
    /* 1B1B8 8002A9B8 09008010 */  beqz       $a0, .L8002A9E0
    /* 1B1BC 8002A9BC 21100000 */   addu      $v0, $zero, $zero
    /* 1B1C0 8002A9C0 73AA0008 */  j          .L8002A9CC
    /* 1B1C4 8002A9C4 00000000 */   nop
  .L8002A9C8:
    /* 1B1C8 8002A9C8 01006324 */  addiu      $v1, $v1, 0x1
  .L8002A9CC:
    /* 1B1CC 8002A9CC 00008280 */  lb         $v0, 0x0($a0)
    /* 1B1D0 8002A9D0 00000000 */  nop
    /* 1B1D4 8002A9D4 FCFF4014 */  bnez       $v0, .L8002A9C8
    /* 1B1D8 8002A9D8 01008424 */   addiu     $a0, $a0, 0x1
    /* 1B1DC 8002A9DC 21106000 */  addu       $v0, $v1, $zero
  .L8002A9E0:
    /* 1B1E0 8002A9E0 0800E003 */  jr         $ra
    /* 1B1E4 8002A9E4 00000000 */   nop
endlabel strlen
    /* 1B1E8 8002A9E8 00000000 */  nop
    /* 1B1EC 8002A9EC 00000000 */  nop
    /* 1B1F0 8002A9F0 00000000 */  nop
