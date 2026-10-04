nonmatching Stg35_FighterSetAnim, 0x38

glabel Stg35_FighterSetAnim
    /* 3470 800667D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3474 800667D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3478 800667D8 2C00838C */  lw         $v1, 0x2C($a0)
    /* 347C 800667DC 00000000 */  nop
    /* 3480 800667E0 3400628C */  lw         $v0, 0x34($v1)
    /* 3484 800667E4 00000000 */  nop
    /* 3488 800667E8 03004510 */  beq        $v0, $a1, .L800667F8
    /* 348C 800667EC 00000000 */   nop
    /* 3490 800667F0 6A7C000C */  jal        Anim_SetModelAnim
    /* 3494 800667F4 340065AC */   sw        $a1, 0x34($v1)
  .L800667F8:
    /* 3498 800667F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 349C 800667FC 00000000 */  nop
    /* 34A0 80066800 0800E003 */  jr         $ra
    /* 34A4 80066804 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_FighterSetAnim
