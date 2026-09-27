nonmatching func_800679C8, 0x88

glabel func_800679C8
    /* 4668 800679C8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 466C 800679CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4670 800679D0 21808000 */  addu       $s0, $a0, $zero
    /* 4674 800679D4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4678 800679D8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 467C 800679DC 2C00118E */  lw         $s1, 0x2C($s0)
    /* 4680 800679E0 00000000 */  nop
    /* 4684 800679E4 1400258E */  lw         $a1, 0x14($s1)
    /* 4688 800679E8 6F7F000C */  jal        Gfx_AttachModel
    /* 468C 800679EC 00000000 */   nop
    /* 4690 800679F0 C87C000C */  jal        Anim_StepModelAnim
    /* 4694 800679F4 21200002 */   addu      $a0, $s0, $zero
    /* 4698 800679F8 4882000C */  jal        Actor_UpdateTransform
    /* 469C 800679FC 21200002 */   addu      $a0, $s0, $zero
    /* 46A0 80067A00 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 46A4 80067A04 21200002 */   addu      $a0, $s0, $zero
    /* 46A8 80067A08 2000228E */  lw         $v0, 0x20($s1)
    /* 46AC 80067A0C 00000000 */  nop
    /* 46B0 80067A10 03004010 */  beqz       $v0, .L80067A20
    /* 46B4 80067A14 21200002 */   addu      $a0, $s0, $zero
    /* 46B8 80067A18 4481000C */  jal        Gfx_DrawTexModel
    /* 46BC 80067A1C 21280000 */   addu      $a1, $zero, $zero
  .L80067A20:
    /* 46C0 80067A20 2400228E */  lw         $v0, 0x24($s1)
    /* 46C4 80067A24 00000000 */  nop
    /* 46C8 80067A28 04004010 */  beqz       $v0, .L80067A3C
    /* 46CC 80067A2C 21200002 */   addu      $a0, $s0, $zero
    /* 46D0 80067A30 21280000 */  addu       $a1, $zero, $zero
    /* 46D4 80067A34 DA81000C */  jal        Gfx_DrawWireModel
    /* 46D8 80067A38 28002626 */   addiu     $a2, $s1, 0x28
  .L80067A3C:
    /* 46DC 80067A3C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 46E0 80067A40 1400B18F */  lw         $s1, 0x14($sp)
    /* 46E4 80067A44 1000B08F */  lw         $s0, 0x10($sp)
    /* 46E8 80067A48 0800E003 */  jr         $ra
    /* 46EC 80067A4C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800679C8
