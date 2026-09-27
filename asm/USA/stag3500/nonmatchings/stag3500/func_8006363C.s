nonmatching func_8006363C, 0x48

glabel func_8006363C
    /* 2DC 8006363C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E0 80063640 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2E4 80063644 21808000 */  addu       $s0, $a0, $zero
    /* 2E8 80063648 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2EC 8006364C 0C00058E */  lw         $a1, 0xC($s0)
    /* 2F0 80063650 6F7F000C */  jal        Gfx_AttachModel
    /* 2F4 80063654 00000000 */   nop
    /* 2F8 80063658 4882000C */  jal        Actor_UpdateTransform
    /* 2FC 8006365C 21200002 */   addu      $a0, $s0, $zero
    /* 300 80063660 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 304 80063664 21200002 */   addu      $a0, $s0, $zero
    /* 308 80063668 21200002 */  addu       $a0, $s0, $zero
    /* 30C 8006366C 4481000C */  jal        Gfx_DrawTexModel
    /* 310 80063670 01000524 */   addiu     $a1, $zero, 0x1
    /* 314 80063674 1400BF8F */  lw         $ra, 0x14($sp)
    /* 318 80063678 1000B08F */  lw         $s0, 0x10($sp)
    /* 31C 8006367C 0800E003 */  jr         $ra
    /* 320 80063680 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006363C
