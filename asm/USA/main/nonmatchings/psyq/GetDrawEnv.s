nonmatching GetDrawEnv, 0x34

glabel GetDrawEnv
    /* 1847C 80027C7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 18480 80027C80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 18484 80027C84 21808000 */  addu       $s0, $a0, $zero
    /* 18488 80027C88 0580053C */  lui        $a1, %hi(D_80048F20)
    /* 1848C 80027C8C 208FA524 */  addiu      $a1, $a1, %lo(D_80048F20)
    /* 18490 80027C90 1400BFAF */  sw         $ra, 0x14($sp)
    /* 18494 80027C94 119C000C */  jal        memcpy
    /* 18498 80027C98 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 1849C 80027C9C 21100002 */  addu       $v0, $s0, $zero
    /* 184A0 80027CA0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 184A4 80027CA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 184A8 80027CA8 0800E003 */  jr         $ra
    /* 184AC 80027CAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetDrawEnv
