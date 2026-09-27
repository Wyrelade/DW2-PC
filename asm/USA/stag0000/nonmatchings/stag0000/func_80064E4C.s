nonmatching func_80064E4C, 0x2C

glabel func_80064E4C
    /* 1AEC 80064E4C 0780023C */  lui        $v0, %hi(D_80069360)
    /* 1AF0 80064E50 6093438C */  lw         $v1, %lo(D_80069360)($v0)
    /* 1AF4 80064E54 00140400 */  sll        $v0, $a0, 16
    /* 1AF8 80064E58 03140200 */  sra        $v0, $v0, 16
    /* 1AFC 80064E5C 06004228 */  slti       $v0, $v0, 0x6
    /* 1B00 80064E60 03004010 */  beqz       $v0, .L80064E70
    /* 1B04 80064E64 00000000 */   nop
    /* 1B08 80064E68 0800E003 */  jr         $ra
    /* 1B0C 80064E6C D40864A4 */   sh        $a0, 0x8D4($v1)
  .L80064E70:
    /* 1B10 80064E70 0800E003 */  jr         $ra
    /* 1B14 80064E74 D40860A4 */   sh        $zero, 0x8D4($v1)
endlabel func_80064E4C
