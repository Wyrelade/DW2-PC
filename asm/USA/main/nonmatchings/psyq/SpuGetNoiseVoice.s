nonmatching SpuGetNoiseVoice, 0x24

glabel SpuGetNoiseVoice
    /* 2BEE4 8003B6E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BEE8 8003B6E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2BEEC 8003B6EC CA000424 */  addiu      $a0, $zero, 0xCA
    /* 2BEF0 8003B6F0 C5ED000C */  jal        _SpuGetAnyVoice
    /* 2BEF4 8003B6F4 CB000524 */   addiu     $a1, $zero, 0xCB
    /* 2BEF8 8003B6F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2BEFC 8003B6FC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2BF00 8003B700 0800E003 */  jr         $ra
    /* 2BF04 8003B704 00000000 */   nop
endlabel SpuGetNoiseVoice
    /* 2BF08 8003B708 00000000 */  nop
    /* 2BF0C 8003B70C 00000000 */  nop
    /* 2BF10 8003B710 00000000 */  nop
