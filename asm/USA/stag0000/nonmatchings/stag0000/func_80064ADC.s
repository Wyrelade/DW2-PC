nonmatching func_80064ADC, 0x2C

glabel func_80064ADC
    /* 177C 80064ADC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1780 80064AE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1784 80064AE4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1788 80064AE8 4594010C */  jal        func_80065114
    /* 178C 80064AEC 21808000 */   addu      $s0, $a0, $zero
    /* 1790 80064AF0 5C44000C */  jal        Task_DefaultDestroy
    /* 1794 80064AF4 21200002 */   addu      $a0, $s0, $zero
    /* 1798 80064AF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 179C 80064AFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 17A0 80064B00 0800E003 */  jr         $ra
    /* 17A4 80064B04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80064ADC
