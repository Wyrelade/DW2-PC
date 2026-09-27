nonmatching func_8006A320, 0x44

glabel func_8006A320
    /* 6FC0 8006A320 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6FC4 8006A324 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FC8 8006A328 21808000 */  addu       $s0, $a0, $zero
    /* 6FCC 8006A32C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6FD0 8006A330 6F7F000C */  jal        Gfx_AttachModel
    /* 6FD4 8006A334 F7020524 */   addiu     $a1, $zero, 0x2F7
    /* 6FD8 8006A338 4882000C */  jal        Actor_UpdateTransform
    /* 6FDC 8006A33C 21200002 */   addu      $a0, $s0, $zero
    /* 6FE0 8006A340 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 6FE4 8006A344 21200002 */   addu      $a0, $s0, $zero
    /* 6FE8 8006A348 21200002 */  addu       $a0, $s0, $zero
    /* 6FEC 8006A34C 4481000C */  jal        Gfx_DrawTexModel
    /* 6FF0 8006A350 01000524 */   addiu     $a1, $zero, 0x1
    /* 6FF4 8006A354 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6FF8 8006A358 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FFC 8006A35C 0800E003 */  jr         $ra
    /* 7000 8006A360 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A320
