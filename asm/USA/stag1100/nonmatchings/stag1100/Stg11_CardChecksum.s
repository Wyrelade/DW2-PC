nonmatching Stg11_CardChecksum, 0x48

glabel Stg11_CardChecksum
    /* 4590 800678F0 34008424 */  addiu      $a0, $a0, 0x34
    /* 4594 800678F4 21300000 */  addu       $a2, $zero, $zero
    /* 4598 800678F8 FF1F0324 */  addiu      $v1, $zero, 0x1FFF
    /* 459C 800678FC FFFF0724 */  addiu      $a3, $zero, -0x1
  .L80067900:
    /* 45A0 80067900 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 45A4 80067904 0A006710 */  beq        $v1, $a3, .L80067930
    /* 45A8 80067908 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* 45AC 8006790C 00008294 */  lhu        $v0, 0x0($a0)
    /* 45B0 80067910 02008424 */  addiu      $a0, $a0, 0x2
    /* 45B4 80067914 2628C200 */  xor        $a1, $a2, $v0
    /* 45B8 80067918 05006710 */  beq        $v1, $a3, .L80067930
    /* 45BC 8006791C 2130A000 */   addu      $a2, $a1, $zero
    /* 45C0 80067920 00008294 */  lhu        $v0, 0x0($a0)
    /* 45C4 80067924 02008424 */  addiu      $a0, $a0, 0x2
    /* 45C8 80067928 409E0108 */  j          .L80067900
    /* 45CC 8006792C 21304500 */   addu      $a2, $v0, $a1
  .L80067930:
    /* 45D0 80067930 0800E003 */  jr         $ra
    /* 45D4 80067934 FFFFC230 */   andi      $v0, $a2, 0xFFFF
endlabel Stg11_CardChecksum
