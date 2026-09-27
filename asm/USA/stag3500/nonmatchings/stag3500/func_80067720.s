nonmatching func_80067720, 0x28

glabel func_80067720
    /* 43C0 80067720 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 43C4 80067724 0780043C */  lui        $a0, %hi(D_8006AA88)
    /* 43C8 80067728 88AA8424 */  addiu      $a0, $a0, %lo(D_8006AA88)
    /* 43CC 8006772C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 43D0 80067730 E38B000C */  jal        Mem_Zero
    /* 43D4 80067734 58030524 */   addiu     $a1, $zero, 0x358
    /* 43D8 80067738 1000BF8F */  lw         $ra, 0x10($sp)
    /* 43DC 8006773C 00000000 */  nop
    /* 43E0 80067740 0800E003 */  jr         $ra
    /* 43E4 80067744 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80067720
