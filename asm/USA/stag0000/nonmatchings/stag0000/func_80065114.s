nonmatching func_80065114, 0x3C

glabel func_80065114
    /* 1DB4 80065114 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DB8 80065118 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DBC 8006511C 0780103C */  lui        $s0, %hi(D_80069360)
    /* 1DC0 80065120 6093028E */  lw         $v0, %lo(D_80069360)($s0)
    /* 1DC4 80065124 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1DC8 80065128 D008448C */  lw         $a0, 0x8D0($v0)
    /* 1DCC 8006512C A073000C */  jal        Gfx_ReleaseTexSlot
    /* 1DD0 80065130 00000000 */   nop
    /* 1DD4 80065134 6093048E */  lw         $a0, %lo(D_80069360)($s0)
    /* 1DD8 80065138 618B000C */  jal        Mem_Free
    /* 1DDC 8006513C 00000000 */   nop
    /* 1DE0 80065140 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1DE4 80065144 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DE8 80065148 0800E003 */  jr         $ra
    /* 1DEC 8006514C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80065114
