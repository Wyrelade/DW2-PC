nonmatching func_8003D6B0, 0x90

glabel func_8003D6B0
    /* 2DEB0 8003D6B0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2DEB4 8003D6B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DEB8 8003D6B8 21808000 */  addu       $s0, $a0, $zero
    /* 2DEBC 8003D6BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DEC0 8003D6C0 2188A000 */  addu       $s1, $a1, $zero
    /* 2DEC4 8003D6C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DEC8 8003D6C8 2190C000 */  addu       $s2, $a2, $zero
    /* 2DECC 8003D6CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2DED0 8003D6D0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2DED4 8003D6D4 59F6000C */  jal        func_8003D964
    /* 2DED8 8003D6D8 2198E000 */   addu      $s3, $a3, $zero
    /* 2DEDC 8003D6DC F19B000C */  jal        EnterCriticalSection
    /* 2DEE0 8003D6E0 00000000 */   nop
    /* 2DEE4 8003D6E4 3BF6000C */  jal        func_8003D8EC
    /* 2DEE8 8003D6E8 00000000 */   nop
    /* 2DEEC 8003D6EC F59B000C */  jal        ExitCriticalSection
    /* 2DEF0 8003D6F0 00000000 */   nop
    /* 2DEF4 8003D6F4 31C3000C */  jal        ChangeClearPAD
    /* 2DEF8 8003D6F8 21200000 */   addu      $a0, $zero, $zero
    /* 2DEFC 8003D6FC DCF5000C */  jal        func_8003D770
    /* 2DF00 8003D700 00000000 */   nop
    /* 2DF04 8003D704 21200002 */  addu       $a0, $s0, $zero
    /* 2DF08 8003D708 21282002 */  addu       $a1, $s1, $zero
    /* 2DF0C 8003D70C 21304002 */  addu       $a2, $s2, $zero
    /* 2DF10 8003D710 25F6000C */  jal        InitPAD
    /* 2DF14 8003D714 21386002 */   addu      $a3, $s3, $zero
    /* 2DF18 8003D718 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DF1C 8003D71C 0580013C */  lui        $at, %hi(D_800506B8)
    /* 2DF20 8003D720 B80622AC */  sw         $v0, %lo(D_800506B8)($at)
    /* 2DF24 8003D724 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2DF28 8003D728 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2DF2C 8003D72C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DF30 8003D730 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DF34 8003D734 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DF38 8003D738 0800E003 */  jr         $ra
    /* 2DF3C 8003D73C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003D6B0
