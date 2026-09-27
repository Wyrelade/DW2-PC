nonmatching func_8006799C, 0x34

glabel func_8006799C
    /* 463C 8006799C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4640 800679A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4644 800679A4 21808000 */  addu       $s0, $a0, $zero
    /* 4648 800679A8 09000424 */  addiu      $a0, $zero, 0x9
    /* 464C 800679AC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4650 800679B0 A4C1000C */  jal        CdControlF
    /* 4654 800679B4 21280000 */   addu      $a1, $zero, $zero
    /* 4658 800679B8 5C44000C */  jal        Task_DefaultDestroy
    /* 465C 800679BC 21200002 */   addu      $a0, $s0, $zero
    /* 4660 800679C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4664 800679C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 4668 800679C8 0800E003 */  jr         $ra
    /* 466C 800679CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006799C
