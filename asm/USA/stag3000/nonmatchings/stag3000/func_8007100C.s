nonmatching func_8007100C, 0x38

glabel func_8007100C
    /* DCAC 8007100C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DCB0 80071010 1000B0AF */  sw         $s0, 0x10($sp)
    /* DCB4 80071014 21808000 */  addu       $s0, $a0, $zero
    /* DCB8 80071018 1400BFAF */  sw         $ra, 0x14($sp)
    /* DCBC 8007101C 2C00048E */  lw         $a0, 0x2C($s0)
    /* DCC0 80071020 02000524 */  addiu      $a1, $zero, 0x2
    /* DCC4 80071024 2C70000C */  jal        Text_CloseArray
    /* DCC8 80071028 0C008424 */   addiu     $a0, $a0, 0xC
    /* DCCC 8007102C 5C44000C */  jal        Task_DefaultDestroy
    /* DCD0 80071030 21200002 */   addu      $a0, $s0, $zero
    /* DCD4 80071034 1400BF8F */  lw         $ra, 0x14($sp)
    /* DCD8 80071038 1000B08F */  lw         $s0, 0x10($sp)
    /* DCDC 8007103C 0800E003 */  jr         $ra
    /* DCE0 80071040 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007100C
