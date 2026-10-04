nonmatching Stg00_FightBgDraw, 0x44

glabel Stg00_FightBgDraw
    /* 2258 800655B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 225C 800655BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2260 800655C0 21808000 */  addu       $s0, $a0, $zero
    /* 2264 800655C4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2268 800655C8 6F7F000C */  jal        Gfx_AttachModel
    /* 226C 800655CC 78000524 */   addiu     $a1, $zero, 0x78
    /* 2270 800655D0 4882000C */  jal        Actor_UpdateTransform
    /* 2274 800655D4 21200002 */   addu      $a0, $s0, $zero
    /* 2278 800655D8 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 227C 800655DC 21200002 */   addu      $a0, $s0, $zero
    /* 2280 800655E0 21200002 */  addu       $a0, $s0, $zero
    /* 2284 800655E4 4481000C */  jal        Gfx_DrawTexModel
    /* 2288 800655E8 01000524 */   addiu     $a1, $zero, 0x1
    /* 228C 800655EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2290 800655F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2294 800655F4 0800E003 */  jr         $ra
    /* 2298 800655F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg00_FightBgDraw
