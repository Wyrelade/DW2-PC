nonmatching Stg20_CameraDraw, 0x5C

glabel Stg20_CameraDraw
    /* C890 8006FBF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C894 8006FBF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* C898 8006FBF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* C89C 8006FBFC 2C00908C */  lw         $s0, 0x2C($a0)
    /* C8A0 8006FC00 00000000 */  nop
    /* C8A4 8006FC04 84000426 */  addiu      $a0, $s0, 0x84
    /* C8A8 8006FC08 D1B5000C */  jal        RotMatrixYXZ
    /* C8AC 8006FC0C 24000526 */   addiu     $a1, $s0, 0x24
    /* C8B0 8006FC10 7000048E */  lw         $a0, 0x70($s0)
    /* C8B4 8006FC14 7400028E */  lw         $v0, 0x74($s0)
    /* C8B8 8006FC18 7800038E */  lw         $v1, 0x78($s0)
    /* C8BC 8006FC1C 7C00058E */  lw         $a1, 0x7C($s0)
    /* C8C0 8006FC20 200000AE */  sw         $zero, 0x20($s0)
    /* C8C4 8006FC24 380002AE */  sw         $v0, 0x38($s0)
    /* C8C8 8006FC28 3C0003AE */  sw         $v1, 0x3C($s0)
    /* C8CC 8006FC2C 51AD000C */  jal        GsSetProjection
    /* C8D0 8006FC30 400005AE */   sw        $a1, 0x40($s0)
    /* C8D4 8006FC34 59B0000C */  jal        GsSetRefView2
    /* C8D8 8006FC38 21200002 */   addu      $a0, $s0, $zero
    /* C8DC 8006FC3C 1400BF8F */  lw         $ra, 0x14($sp)
    /* C8E0 8006FC40 1000B08F */  lw         $s0, 0x10($sp)
    /* C8E4 8006FC44 0800E003 */  jr         $ra
    /* C8E8 8006FC48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_CameraDraw
