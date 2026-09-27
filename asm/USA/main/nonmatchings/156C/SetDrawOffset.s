nonmatching SetDrawOffset, 0x40

glabel SetDrawOffset
    /* 18A8C 8002828C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 18A90 80028290 1000B0AF */  sw         $s0, 0x10($sp)
    /* 18A94 80028294 21808000 */  addu       $s0, $a0, $zero
    /* 18A98 80028298 02000224 */  addiu      $v0, $zero, 0x2
    /* 18A9C 8002829C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 18AA0 800282A0 030002A2 */  sb         $v0, 0x3($s0)
    /* 18AA4 800282A4 0000A484 */  lh         $a0, 0x0($a1)
    /* 18AA8 800282A8 0200A584 */  lh         $a1, 0x2($a1)
    /* 18AAC 800282AC 21A2000C */  jal        get_ofs
    /* 18AB0 800282B0 00000000 */   nop
    /* 18AB4 800282B4 040002AE */  sw         $v0, 0x4($s0)
    /* 18AB8 800282B8 080000AE */  sw         $zero, 0x8($s0)
    /* 18ABC 800282BC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 18AC0 800282C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 18AC4 800282C4 0800E003 */  jr         $ra
    /* 18AC8 800282C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SetDrawOffset
