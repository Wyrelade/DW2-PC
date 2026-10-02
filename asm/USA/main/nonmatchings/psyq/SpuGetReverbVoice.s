nonmatching SpuGetReverbVoice, 0x24

glabel SpuGetReverbVoice
    /* 2CB74 8003C374 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CB78 8003C378 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2CB7C 8003C37C CC000424 */  addiu      $a0, $zero, 0xCC
    /* 2CB80 8003C380 C5ED000C */  jal        _SpuGetAnyVoice
    /* 2CB84 8003C384 CD000524 */   addiu     $a1, $zero, 0xCD
    /* 2CB88 8003C388 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2CB8C 8003C38C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2CB90 8003C390 0800E003 */  jr         $ra
    /* 2CB94 8003C394 00000000 */   nop
endlabel SpuGetReverbVoice
    /* 2CB98 8003C398 00000000 */  nop
    /* 2CB9C 8003C39C 00000000 */  nop
    /* 2CBA0 8003C3A0 00000000 */  nop
