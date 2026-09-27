nonmatching func_800676E0, 0x40

glabel func_800676E0
    /* 4380 800676E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4384 800676E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4388 800676E8 21880000 */  addu       $s1, $zero, $zero
    /* 438C 800676EC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4390 800676F0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4394 800676F4 2C00908C */  lw         $s0, 0x2C($a0)
  .L800676F8:
    /* 4398 800676F8 6C98010C */  jal        func_800661B0
    /* 439C 800676FC 21200002 */   addu      $a0, $s0, $zero
    /* 43A0 80067700 01003126 */  addiu      $s1, $s1, 0x1
    /* 43A4 80067704 FCFF201A */  blez       $s1, .L800676F8
    /* 43A8 80067708 04001026 */   addiu     $s0, $s0, 0x4
    /* 43AC 8006770C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 43B0 80067710 1400B18F */  lw         $s1, 0x14($sp)
    /* 43B4 80067714 1000B08F */  lw         $s0, 0x10($sp)
    /* 43B8 80067718 0800E003 */  jr         $ra
    /* 43BC 8006771C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800676E0
