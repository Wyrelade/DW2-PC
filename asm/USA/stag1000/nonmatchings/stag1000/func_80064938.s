nonmatching func_80064938, 0x24

glabel func_80064938
    /* 15D8 80064938 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15DC 8006493C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 15E0 80064940 21288000 */  addu       $a1, $a0, $zero
    /* 15E4 80064944 4DC3000C */  jal        DMACallback
    /* 15E8 80064948 21200000 */   addu      $a0, $zero, $zero
    /* 15EC 8006494C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15F0 80064950 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 15F4 80064954 0800E003 */  jr         $ra
    /* 15F8 80064958 00000000 */   nop
endlabel func_80064938
