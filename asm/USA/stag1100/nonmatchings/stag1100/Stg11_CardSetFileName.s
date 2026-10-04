nonmatching Stg11_CardSetFileName, 0x48

glabel Stg11_CardSetFileName
    /* 44D8 80067838 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 44DC 8006783C 0780023C */  lui        $v0, %hi(Stg11_CardTask)
    /* 44E0 80067840 D085428C */  lw         $v0, %lo(Stg11_CardTask)($v0)
    /* 44E4 80067844 21188000 */  addu       $v1, $a0, $zero
    /* 44E8 80067848 1400B1AF */  sw         $s1, 0x14($sp)
    /* 44EC 8006784C 2188A000 */  addu       $s1, $a1, $zero
    /* 44F0 80067850 1800BFAF */  sw         $ra, 0x18($sp)
    /* 44F4 80067854 1000B0AF */  sw         $s0, 0x10($sp)
    /* 44F8 80067858 2C00508C */  lw         $s0, 0x2C($v0)
    /* 44FC 8006785C 21286000 */  addu       $a1, $v1, $zero
    /* 4500 80067860 2D9C000C */  jal        strcpy
    /* 4504 80067864 0C000426 */   addiu     $a0, $s0, 0xC
    /* 4508 80067868 210011A2 */  sb         $s1, 0x21($s0)
    /* 450C 8006786C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4510 80067870 1400B18F */  lw         $s1, 0x14($sp)
    /* 4514 80067874 1000B08F */  lw         $s0, 0x10($sp)
    /* 4518 80067878 0800E003 */  jr         $ra
    /* 451C 8006787C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_CardSetFileName
