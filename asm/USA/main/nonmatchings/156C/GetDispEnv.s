nonmatching GetDispEnv, 0x34

glabel GetDispEnv
    /* 189A8 800281A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 189AC 800281AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 189B0 800281B0 21808000 */  addu       $s0, $a0, $zero
    /* 189B4 800281B4 0580053C */  lui        $a1, %hi(D_80048F7C)
    /* 189B8 800281B8 7C8FA524 */  addiu      $a1, $a1, %lo(D_80048F7C)
    /* 189BC 800281BC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 189C0 800281C0 119C000C */  jal        func_80027044
    /* 189C4 800281C4 14000624 */   addiu     $a2, $zero, 0x14
    /* 189C8 800281C8 21100002 */  addu       $v0, $s0, $zero
    /* 189CC 800281CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 189D0 800281D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 189D4 800281D4 0800E003 */  jr         $ra
    /* 189D8 800281D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetDispEnv
