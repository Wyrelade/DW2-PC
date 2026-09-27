nonmatching func_8006BA5C, 0x34

glabel func_8006BA5C
    /* 86FC 8006BA5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8700 8006BA60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8704 8006BA64 21808000 */  addu       $s0, $a0, $zero
    /* 8708 8006BA68 09000424 */  addiu      $a0, $zero, 0x9
    /* 870C 8006BA6C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8710 8006BA70 A4C1000C */  jal        CdControlF
    /* 8714 8006BA74 21280000 */   addu      $a1, $zero, $zero
    /* 8718 8006BA78 5C44000C */  jal        Task_DefaultDestroy
    /* 871C 8006BA7C 21200002 */   addu      $a0, $s0, $zero
    /* 8720 8006BA80 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8724 8006BA84 1000B08F */  lw         $s0, 0x10($sp)
    /* 8728 8006BA88 0800E003 */  jr         $ra
    /* 872C 8006BA8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006BA5C
