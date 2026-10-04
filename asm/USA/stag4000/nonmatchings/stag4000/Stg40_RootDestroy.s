nonmatching Stg40_RootDestroy, 0x48

glabel Stg40_RootDestroy
    /* 14D8 80064838 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14DC 8006483C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14E0 80064840 21808000 */  addu       $s0, $a0, $zero
    /* 14E4 80064844 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14E8 80064848 62BB010C */  jal        Stg40_SyncVisitedBits
    /* 14EC 8006484C 21200000 */   addu      $a0, $zero, $zero
    /* 14F0 80064850 CABF010C */  jal        Stg40_FreeCellGrid
    /* 14F4 80064854 00000000 */   nop
    /* 14F8 80064858 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 14FC 8006485C 602B448C */  lw         $a0, %lo(D_80072B60)($v0)
    /* 1500 80064860 618B000C */  jal        Mem_Free
    /* 1504 80064864 00000000 */   nop
    /* 1508 80064868 5C44000C */  jal        Task_DefaultDestroy
    /* 150C 8006486C 21200002 */   addu      $a0, $s0, $zero
    /* 1510 80064870 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1514 80064874 1000B08F */  lw         $s0, 0x10($sp)
    /* 1518 80064878 0800E003 */  jr         $ra
    /* 151C 8006487C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_RootDestroy
