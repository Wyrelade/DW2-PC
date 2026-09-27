nonmatching func_80063B28, 0x48

glabel func_80063B28
    /* 7C8 80063B28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7CC 80063B2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7D0 80063B30 21808000 */  addu       $s0, $a0, $zero
    /* 7D4 80063B34 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7D8 80063B38 0C00058E */  lw         $a1, 0xC($s0)
    /* 7DC 80063B3C 6F7F000C */  jal        Gfx_AttachModel
    /* 7E0 80063B40 00000000 */   nop
    /* 7E4 80063B44 4882000C */  jal        Actor_UpdateTransform
    /* 7E8 80063B48 21200002 */   addu      $a0, $s0, $zero
    /* 7EC 80063B4C 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 7F0 80063B50 21200002 */   addu      $a0, $s0, $zero
    /* 7F4 80063B54 21200002 */  addu       $a0, $s0, $zero
    /* 7F8 80063B58 4481000C */  jal        Gfx_DrawTexModel
    /* 7FC 80063B5C 01000524 */   addiu     $a1, $zero, 0x1
    /* 800 80063B60 1400BF8F */  lw         $ra, 0x14($sp)
    /* 804 80063B64 1000B08F */  lw         $s0, 0x10($sp)
    /* 808 80063B68 0800E003 */  jr         $ra
    /* 80C 80063B6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063B28
