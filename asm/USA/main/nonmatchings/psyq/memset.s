nonmatching memset, 0x30

glabel memset
    /* 17884 80027084 09008010 */  beqz       $a0, .L800270AC
    /* 17888 80027088 21100000 */   addu      $v0, $zero, $zero
    /* 1788C 8002708C 0300C01C */  bgtz       $a2, .L8002709C
    /* 17890 80027090 21108000 */   addu      $v0, $a0, $zero
    /* 17894 80027094 2B9C0008 */  j          .L800270AC
    /* 17898 80027098 21100000 */   addu      $v0, $zero, $zero
  .L8002709C:
    /* 1789C 8002709C 000085A0 */  sb         $a1, 0x0($a0)
    /* 178A0 800270A0 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 178A4 800270A4 FDFFC01C */  bgtz       $a2, .L8002709C
    /* 178A8 800270A8 01008424 */   addiu     $a0, $a0, 0x1
  .L800270AC:
    /* 178AC 800270AC 0800E003 */  jr         $ra
    /* 178B0 800270B0 00000000 */   nop
endlabel memset
