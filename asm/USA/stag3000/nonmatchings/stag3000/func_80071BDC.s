nonmatching func_80071BDC, 0x38

glabel func_80071BDC
    /* E87C 80071BDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E880 80071BE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* E884 80071BE4 21808000 */  addu       $s0, $a0, $zero
    /* E888 80071BE8 1400BFAF */  sw         $ra, 0x14($sp)
    /* E88C 80071BEC 2C00048E */  lw         $a0, 0x2C($s0)
    /* E890 80071BF0 0E000524 */  addiu      $a1, $zero, 0xE
    /* E894 80071BF4 2C70000C */  jal        Text_CloseArray
    /* E898 80071BF8 24008424 */   addiu     $a0, $a0, 0x24
    /* E89C 80071BFC 5C44000C */  jal        Task_DefaultDestroy
    /* E8A0 80071C00 21200002 */   addu      $a0, $s0, $zero
    /* E8A4 80071C04 1400BF8F */  lw         $ra, 0x14($sp)
    /* E8A8 80071C08 1000B08F */  lw         $s0, 0x10($sp)
    /* E8AC 80071C0C 0800E003 */  jr         $ra
    /* E8B0 80071C10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80071BDC
