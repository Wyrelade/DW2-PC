nonmatching Stg20_LabDigiModelDraw, 0x68

glabel Stg20_LabDigiModelDraw
    /* 737C 8006A6DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7380 8006A6E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7384 8006A6E4 21808000 */  addu       $s0, $a0, $zero
    /* 7388 8006A6E8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 738C 8006A6EC 2C00038E */  lw         $v1, 0x2C($s0)
    /* 7390 8006A6F0 00000000 */  nop
    /* 7394 8006A6F4 2C00628C */  lw         $v0, 0x2C($v1)
    /* 7398 8006A6F8 00000000 */  nop
    /* 739C 8006A6FC 0D004010 */  beqz       $v0, .L8006A734
    /* 73A0 8006A700 00000000 */   nop
    /* 73A4 8006A704 1800658C */  lw         $a1, 0x18($v1)
    /* 73A8 8006A708 6F7F000C */  jal        Gfx_AttachModel
    /* 73AC 8006A70C 00000000 */   nop
    /* 73B0 8006A710 C87C000C */  jal        Anim_StepModelAnim
    /* 73B4 8006A714 21200002 */   addu      $a0, $s0, $zero
    /* 73B8 8006A718 4882000C */  jal        Actor_UpdateTransform
    /* 73BC 8006A71C 21200002 */   addu      $a0, $s0, $zero
    /* 73C0 8006A720 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 73C4 8006A724 21200002 */   addu      $a0, $s0, $zero
    /* 73C8 8006A728 21200002 */  addu       $a0, $s0, $zero
    /* 73CC 8006A72C 4481000C */  jal        Gfx_DrawTexModel
    /* 73D0 8006A730 21280000 */   addu      $a1, $zero, $zero
  .L8006A734:
    /* 73D4 8006A734 1400BF8F */  lw         $ra, 0x14($sp)
    /* 73D8 8006A738 1000B08F */  lw         $s0, 0x10($sp)
    /* 73DC 8006A73C 0800E003 */  jr         $ra
    /* 73E0 8006A740 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_LabDigiModelDraw
