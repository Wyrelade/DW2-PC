nonmatching func_80064930, 0x40

glabel func_80064930
    /* 15D0 80064930 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 15D4 80064934 1000B0AF */  sw         $s0, 0x10($sp)
    /* 15D8 80064938 21808000 */  addu       $s0, $a0, $zero
    /* 15DC 8006493C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 15E0 80064940 2188A000 */  addu       $s1, $a1, $zero
    /* 15E4 80064944 1800BFAF */  sw         $ra, 0x18($sp)
    /* 15E8 80064948 7045000C */  jal        Task_SetState0
    /* 15EC 8006494C 02000524 */   addiu     $a1, $zero, 0x2
    /* 15F0 80064950 21200002 */  addu       $a0, $s0, $zero
    /* 15F4 80064954 7745000C */  jal        Task_SetState1
    /* 15F8 80064958 FF002532 */   andi      $a1, $s1, 0xFF
    /* 15FC 8006495C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1600 80064960 1400B18F */  lw         $s1, 0x14($sp)
    /* 1604 80064964 1000B08F */  lw         $s0, 0x10($sp)
    /* 1608 80064968 0800E003 */  jr         $ra
    /* 160C 8006496C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80064930
