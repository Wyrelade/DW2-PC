nonmatching SpuSetReverbVoice, 0x24

glabel SpuSetReverbVoice
    /* 2CB44 8003C344 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CB48 8003C348 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2CB4C 8003C34C CC000624 */  addiu      $a2, $zero, 0xCC
    /* 2CB50 8003C350 09ED000C */  jal        _SpuSetAnyVoice
    /* 2CB54 8003C354 CD000724 */   addiu     $a3, $zero, 0xCD
    /* 2CB58 8003C358 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2CB5C 8003C35C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2CB60 8003C360 0800E003 */  jr         $ra
    /* 2CB64 8003C364 00000000 */   nop
endlabel SpuSetReverbVoice
    /* 2CB68 8003C368 00000000 */  nop
    /* 2CB6C 8003C36C 00000000 */  nop
    /* 2CB70 8003C370 00000000 */  nop
