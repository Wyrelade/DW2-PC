nonmatching func_80029FB4, 0x28

glabel func_80029FB4
    /* 1A7B4 80029FB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1A7B8 80029FB8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1A7BC 80029FBC 0380053C */  lui        $a1, %hi(func_800294AC)
    /* 1A7C0 80029FC0 AC94A524 */  addiu      $a1, $a1, %lo(func_800294AC)
    /* 1A7C4 80029FC4 4DC3000C */  jal        DMACallback
    /* 1A7C8 80029FC8 02000424 */   addiu     $a0, $zero, 0x2
    /* 1A7CC 80029FCC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1A7D0 80029FD0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1A7D4 80029FD4 0800E003 */  jr         $ra
    /* 1A7D8 80029FD8 00000000 */   nop
endlabel func_80029FB4
