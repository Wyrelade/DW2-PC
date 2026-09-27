nonmatching func_8001E758, 0x44

glabel func_8001E758
    /* EF58 8001E758 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EF5C 8001E75C 1400B1AF */  sw         $s1, 0x14($sp)
    /* EF60 8001E760 21888000 */  addu       $s1, $a0, $zero
    /* EF64 8001E764 1800BFAF */  sw         $ra, 0x18($sp)
    /* EF68 8001E768 AA79000C */  jal        func_8001E6A8
    /* EF6C 8001E76C 1000B0AF */   sw        $s0, 0x10($sp)
    /* EF70 8001E770 0000508C */  lw         $s0, 0x0($v0)
    /* EF74 8001E774 9F79000C */  jal        func_8001E67C
    /* EF78 8001E778 21202002 */   addu      $a0, $s1, $zero
    /* EF7C 8001E77C 828E000C */  jal        Cd_GetFileOrNull
    /* EF80 8001E780 21204000 */   addu      $a0, $v0, $zero
    /* EF84 8001E784 1800BF8F */  lw         $ra, 0x18($sp)
    /* EF88 8001E788 1400B18F */  lw         $s1, 0x14($sp)
    /* EF8C 8001E78C 21100202 */  addu       $v0, $s0, $v0
    /* EF90 8001E790 1000B08F */  lw         $s0, 0x10($sp)
    /* EF94 8001E794 0800E003 */  jr         $ra
    /* EF98 8001E798 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001E758
