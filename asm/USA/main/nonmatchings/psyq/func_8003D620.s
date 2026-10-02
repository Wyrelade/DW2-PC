nonmatching func_8003D620, 0x90

glabel func_8003D620
    /* 2DE20 8003D620 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2DE24 8003D624 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DE28 8003D628 21808000 */  addu       $s0, $a0, $zero
    /* 2DE2C 8003D62C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DE30 8003D630 2188A000 */  addu       $s1, $a1, $zero
    /* 2DE34 8003D634 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DE38 8003D638 2190C000 */  addu       $s2, $a2, $zero
    /* 2DE3C 8003D63C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2DE40 8003D640 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2DE44 8003D644 59F6000C */  jal        func_8003D964
    /* 2DE48 8003D648 2198E000 */   addu      $s3, $a3, $zero
    /* 2DE4C 8003D64C F19B000C */  jal        EnterCriticalSection
    /* 2DE50 8003D650 00000000 */   nop
    /* 2DE54 8003D654 3BF6000C */  jal        func_8003D8EC
    /* 2DE58 8003D658 00000000 */   nop
    /* 2DE5C 8003D65C F59B000C */  jal        ExitCriticalSection
    /* 2DE60 8003D660 00000000 */   nop
    /* 2DE64 8003D664 31C3000C */  jal        ChangeClearPAD
    /* 2DE68 8003D668 21200000 */   addu      $a0, $zero, $zero
    /* 2DE6C 8003D66C DCF5000C */  jal        func_8003D770
    /* 2DE70 8003D670 00000000 */   nop
    /* 2DE74 8003D674 21200002 */  addu       $a0, $s0, $zero
    /* 2DE78 8003D678 21282002 */  addu       $a1, $s1, $zero
    /* 2DE7C 8003D67C 21304002 */  addu       $a2, $s2, $zero
    /* 2DE80 8003D680 2DF6000C */  jal        PAD_init
    /* 2DE84 8003D684 21386002 */   addu      $a3, $s3, $zero
    /* 2DE88 8003D688 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DE8C 8003D68C 0580013C */  lui        $at, %hi(D_800506B8)
    /* 2DE90 8003D690 B80622AC */  sw         $v0, %lo(D_800506B8)($at)
    /* 2DE94 8003D694 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2DE98 8003D698 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2DE9C 8003D69C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DEA0 8003D6A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DEA4 8003D6A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DEA8 8003D6A8 0800E003 */  jr         $ra
    /* 2DEAC 8003D6AC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003D620
