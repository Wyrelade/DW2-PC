nonmatching func_80068050, 0x34

glabel func_80068050
    /* 4CF0 80068050 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4CF4 80068054 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4CF8 80068058 21808000 */  addu       $s0, $a0, $zero
    /* 4CFC 8006805C 09000424 */  addiu      $a0, $zero, 0x9
    /* 4D00 80068060 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4D04 80068064 A4C1000C */  jal        CdControlF
    /* 4D08 80068068 21280000 */   addu      $a1, $zero, $zero
    /* 4D0C 8006806C 5C44000C */  jal        Task_DefaultDestroy
    /* 4D10 80068070 21200002 */   addu      $a0, $s0, $zero
    /* 4D14 80068074 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4D18 80068078 1000B08F */  lw         $s0, 0x10($sp)
    /* 4D1C 8006807C 0800E003 */  jr         $ra
    /* 4D20 80068080 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068050
