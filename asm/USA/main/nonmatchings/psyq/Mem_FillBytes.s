nonmatching Mem_FillBytes, 0x24

glabel Mem_FillBytes
    /* 1A7DC 80029FDC 0600C010 */  beqz       $a2, .L80029FF8
    /* 1A7E0 80029FE0 FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 1A7E4 80029FE4 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80029FE8:
    /* 1A7E8 80029FE8 000085A0 */  sb         $a1, 0x0($a0)
    /* 1A7EC 80029FEC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1A7F0 80029FF0 FDFF4314 */  bne        $v0, $v1, .L80029FE8
    /* 1A7F4 80029FF4 01008424 */   addiu     $a0, $a0, 0x1
  .L80029FF8:
    /* 1A7F8 80029FF8 0800E003 */  jr         $ra
    /* 1A7FC 80029FFC 00000000 */   nop
endlabel Mem_FillBytes
    /* 1A800 8002A000 00000000 */  nop
