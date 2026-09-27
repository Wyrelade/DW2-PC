nonmatching func_800646C0, 0x34

glabel func_800646C0
    /* 1360 800646C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1364 800646C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1368 800646C8 21808000 */  addu       $s0, $a0, $zero
    /* 136C 800646CC 03000016 */  bnez       $s0, .L800646DC
    /* 1370 800646D0 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1374 800646D4 35C3000C */  jal        ResetCallback
    /* 1378 800646D8 00000000 */   nop
  .L800646DC:
    /* 137C 800646DC 6092010C */  jal        func_80064980
    /* 1380 800646E0 21200002 */   addu      $a0, $s0, $zero
    /* 1384 800646E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1388 800646E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 138C 800646EC 0800E003 */  jr         $ra
    /* 1390 800646F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800646C0
