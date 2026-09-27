nonmatching func_8001E048, 0x3C

glabel func_8001E048
    /* E848 8001E048 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E84C 8001E04C 1000B0AF */  sw         $s0, 0x10($sp)
    /* E850 8001E050 21808000 */  addu       $s0, $a0, $zero
    /* E854 8001E054 1400BFAF */  sw         $ra, 0x14($sp)
    /* E858 8001E058 828E000C */  jal        Cd_GetFileOrNull
    /* E85C 8001E05C 5E040424 */   addiu     $a0, $zero, 0x45E
    /* E860 8001E060 21200002 */  addu       $a0, $s0, $zero
    /* E864 8001E064 FD77000C */  jal        func_8001DFF4
    /* E868 8001E068 21804000 */   addu      $s0, $v0, $zero
    /* E86C 8001E06C 0800428C */  lw         $v0, 0x8($v0)
    /* E870 8001E070 1400BF8F */  lw         $ra, 0x14($sp)
    /* E874 8001E074 21105000 */  addu       $v0, $v0, $s0
    /* E878 8001E078 1000B08F */  lw         $s0, 0x10($sp)
    /* E87C 8001E07C 0800E003 */  jr         $ra
    /* E880 8001E080 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E048
