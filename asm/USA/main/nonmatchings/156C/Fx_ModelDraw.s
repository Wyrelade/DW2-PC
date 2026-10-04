nonmatching Fx_ModelDraw, 0x64

glabel Fx_ModelDraw
    /* 14C10 80024410 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14C14 80024414 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14C18 80024418 21808000 */  addu       $s0, $a0, $zero
    /* 14C1C 8002441C 01000324 */  addiu      $v1, $zero, 0x1
    /* 14C20 80024420 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14C24 80024424 1000028E */  lw         $v0, 0x10($s0)
    /* 14C28 80024428 2C00058E */  lw         $a1, 0x2C($s0)
    /* 14C2C 8002442C 0D004314 */  bne        $v0, $v1, .L80024464
    /* 14C30 80024430 00000000 */   nop
    /* 14C34 80024434 0000A58C */  lw         $a1, 0x0($a1)
    /* 14C38 80024438 6F7F000C */  jal        Gfx_AttachModel
    /* 14C3C 8002443C 00000000 */   nop
    /* 14C40 80024440 C87C000C */  jal        Anim_StepModelAnim
    /* 14C44 80024444 21200002 */   addu      $a0, $s0, $zero
    /* 14C48 80024448 4882000C */  jal        Actor_UpdateTransform
    /* 14C4C 8002444C 21200002 */   addu      $a0, $s0, $zero
    /* 14C50 80024450 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 14C54 80024454 21200002 */   addu      $a0, $s0, $zero
    /* 14C58 80024458 21200002 */  addu       $a0, $s0, $zero
    /* 14C5C 8002445C 4481000C */  jal        Gfx_DrawTexModel
    /* 14C60 80024460 21280000 */   addu      $a1, $zero, $zero
  .L80024464:
    /* 14C64 80024464 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14C68 80024468 1000B08F */  lw         $s0, 0x10($sp)
    /* 14C6C 8002446C 0800E003 */  jr         $ra
    /* 14C70 80024470 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Fx_ModelDraw
