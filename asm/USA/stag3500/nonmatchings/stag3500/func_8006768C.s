nonmatching func_8006768C, 0x54

glabel func_8006768C
    /* 432C 8006768C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4330 80067690 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4334 80067694 21908000 */  addu       $s2, $a0, $zero
    /* 4338 80067698 1400B1AF */  sw         $s1, 0x14($sp)
    /* 433C 8006769C 21880000 */  addu       $s1, $zero, $zero
    /* 4340 800676A0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4344 800676A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4348 800676A8 2C00508E */  lw         $s0, 0x2C($s2)
  .L800676AC:
    /* 434C 800676AC 5A98010C */  jal        func_80066168
    /* 4350 800676B0 21200002 */   addu      $a0, $s0, $zero
    /* 4354 800676B4 01003126 */  addiu      $s1, $s1, 0x1
    /* 4358 800676B8 FCFF201A */  blez       $s1, .L800676AC
    /* 435C 800676BC 04001026 */   addiu     $s0, $s0, 0x4
    /* 4360 800676C0 5C44000C */  jal        Task_DefaultDestroy
    /* 4364 800676C4 21204002 */   addu      $a0, $s2, $zero
    /* 4368 800676C8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 436C 800676CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 4370 800676D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 4374 800676D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 4378 800676D8 0800E003 */  jr         $ra
    /* 437C 800676DC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006768C
