nonmatching SsUtReverbOff, 0x20

glabel SsUtReverbOff
    /* 26D54 80036554 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26D58 80036558 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26D5C 8003655C E5ED000C */  jal        SpuSetReverb
    /* 26D60 80036560 21200000 */   addu      $a0, $zero, $zero
    /* 26D64 80036564 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26D68 80036568 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 26D6C 8003656C 0800E003 */  jr         $ra
    /* 26D70 80036570 00000000 */   nop
endlabel SsUtReverbOff
