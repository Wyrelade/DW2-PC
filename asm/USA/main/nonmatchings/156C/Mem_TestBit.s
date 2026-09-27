nonmatching Mem_TestBit, 0x24

glabel Mem_TestBit
    /* 12654 80021E54 C3100500 */  sra        $v0, $a1, 3
    /* 12658 80021E58 0700A530 */  andi       $a1, $a1, 0x7
    /* 1265C 80021E5C 01000324 */  addiu      $v1, $zero, 0x1
    /* 12660 80021E60 21208200 */  addu       $a0, $a0, $v0
    /* 12664 80021E64 00008290 */  lbu        $v0, 0x0($a0)
    /* 12668 80021E68 0418A300 */  sllv       $v1, $v1, $a1
    /* 1266C 80021E6C 24104300 */  and        $v0, $v0, $v1
    /* 12670 80021E70 0800E003 */  jr         $ra
    /* 12674 80021E74 2B100200 */   sltu      $v0, $zero, $v0
endlabel Mem_TestBit
