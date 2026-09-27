nonmatching func_8006FE5C, 0x34

glabel func_8006FE5C
    /* CAFC 8006FE5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* CB00 8006FE60 1000B0AF */  sw         $s0, 0x10($sp)
    /* CB04 8006FE64 21808000 */  addu       $s0, $a0, $zero
    /* CB08 8006FE68 1400BFAF */  sw         $ra, 0x14($sp)
    /* CB0C 8006FE6C 2C00048E */  lw         $a0, 0x2C($s0)
    /* CB10 8006FE70 E3BC010C */  jal        func_8006F38C
    /* CB14 8006FE74 00000000 */   nop
    /* CB18 8006FE78 5C44000C */  jal        Task_DefaultDestroy
    /* CB1C 8006FE7C 21200002 */   addu      $a0, $s0, $zero
    /* CB20 8006FE80 1400BF8F */  lw         $ra, 0x14($sp)
    /* CB24 8006FE84 1000B08F */  lw         $s0, 0x10($sp)
    /* CB28 8006FE88 0800E003 */  jr         $ra
    /* CB2C 8006FE8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006FE5C
