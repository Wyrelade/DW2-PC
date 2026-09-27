nonmatching func_800654F4, 0x28

glabel func_800654F4
    /* 2194 800654F4 0780023C */  lui        $v0, %hi(D_8006935C)
    /* 2198 800654F8 5C93468C */  lw         $a2, %lo(D_8006935C)($v0)
    /* 219C 800654FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21A0 80065500 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21A4 80065504 5494010C */  jal        func_80065150
    /* 21A8 80065508 00000000 */   nop
    /* 21AC 8006550C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21B0 80065510 00000000 */  nop
    /* 21B4 80065514 0800E003 */  jr         $ra
    /* 21B8 80065518 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800654F4
