nonmatching Stg20_WalkerDraw, 0x78

glabel Stg20_WalkerDraw
    /* 8468 8006B7C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 846C 8006B7CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8470 8006B7D0 21808000 */  addu       $s0, $a0, $zero
    /* 8474 8006B7D4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8478 8006B7D8 2C00038E */  lw         $v1, 0x2C($s0)
    /* 847C 8006B7DC 00000000 */  nop
    /* 8480 8006B7E0 6400628C */  lw         $v0, 0x64($v1)
    /* 8484 8006B7E4 00000000 */  nop
    /* 8488 8006B7E8 11004010 */  beqz       $v0, .L8006B830
    /* 848C 8006B7EC 00000000 */   nop
    /* 8490 8006B7F0 2000658C */  lw         $a1, 0x20($v1)
    /* 8494 8006B7F4 6F7F000C */  jal        Gfx_AttachModel
    /* 8498 8006B7F8 00000000 */   nop
    /* 849C 8006B7FC C87C000C */  jal        Anim_StepModelAnim
    /* 84A0 8006B800 21200002 */   addu      $a0, $s0, $zero
    /* 84A4 8006B804 4882000C */  jal        Actor_UpdateTransform
    /* 84A8 8006B808 21200002 */   addu      $a0, $s0, $zero
    /* 84AC 8006B80C 7E82000C */  jal        Actor_ProjectToScreen
    /* 84B0 8006B810 21200002 */   addu      $a0, $s0, $zero
    /* 84B4 8006B814 06004014 */  bnez       $v0, .L8006B830
    /* 84B8 8006B818 00000000 */   nop
    /* 84BC 8006B81C 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 84C0 8006B820 21200002 */   addu      $a0, $s0, $zero
    /* 84C4 8006B824 21200002 */  addu       $a0, $s0, $zero
    /* 84C8 8006B828 4481000C */  jal        Gfx_DrawTexModel
    /* 84CC 8006B82C 21280000 */   addu      $a1, $zero, $zero
  .L8006B830:
    /* 84D0 8006B830 1400BF8F */  lw         $ra, 0x14($sp)
    /* 84D4 8006B834 1000B08F */  lw         $s0, 0x10($sp)
    /* 84D8 8006B838 0800E003 */  jr         $ra
    /* 84DC 8006B83C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_WalkerDraw
