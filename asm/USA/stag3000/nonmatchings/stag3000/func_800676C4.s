nonmatching func_800676C4, 0x30

glabel func_800676C4
    /* 4364 800676C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4368 800676C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 436C 800676CC 21808000 */  addu       $s0, $a0, $zero
    /* 4370 800676D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4374 800676D4 307C000C */  jal        Skill_GetRank
    /* 4378 800676D8 FF00A430 */   andi      $a0, $a1, 0xFF
    /* 437C 800676DC 2A800202 */  slt        $s0, $s0, $v0
    /* 4380 800676E0 0100023A */  xori       $v0, $s0, 0x1
    /* 4384 800676E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4388 800676E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 438C 800676EC 0800E003 */  jr         $ra
    /* 4390 800676F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800676C4
