nonmatching SpuSetNoiseVoice, 0x24

glabel SpuSetNoiseVoice
    /* 2BBF4 8003B3F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BBF8 8003B3F8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2BBFC 8003B3FC CA000624 */  addiu      $a2, $zero, 0xCA
    /* 2BC00 8003B400 09ED000C */  jal        _SpuSetAnyVoice
    /* 2BC04 8003B404 CB000724 */   addiu     $a3, $zero, 0xCB
    /* 2BC08 8003B408 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2BC0C 8003B40C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2BC10 8003B410 0800E003 */  jr         $ra
    /* 2BC14 8003B414 00000000 */   nop
endlabel SpuSetNoiseVoice
    /* 2BC18 8003B418 00000000 */  nop
    /* 2BC1C 8003B41C 00000000 */  nop
    /* 2BC20 8003B420 00000000 */  nop
