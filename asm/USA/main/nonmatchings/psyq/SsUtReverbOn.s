nonmatching SsUtReverbOn, 0x20

glabel SsUtReverbOn
    /* 26D74 80036574 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26D78 80036578 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26D7C 8003657C E5ED000C */  jal        SpuSetReverb
    /* 26D80 80036580 01000424 */   addiu     $a0, $zero, 0x1
    /* 26D84 80036584 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26D88 80036588 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 26D8C 8003658C 0800E003 */  jr         $ra
    /* 26D90 80036590 00000000 */   nop
endlabel SsUtReverbOn
