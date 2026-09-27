nonmatching func_80069FD4, 0xAC

glabel func_80069FD4
    /* 6C74 80069FD4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6C78 80069FD8 3400BFAF */  sw         $ra, 0x34($sp)
    /* 6C7C 80069FDC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 6C80 80069FE0 2C00908C */  lw         $s0, 0x2C($a0)
    /* 6C84 80069FE4 00000000 */  nop
    /* 6C88 80069FE8 7C000426 */  addiu      $a0, $s0, 0x7C
    /* 6C8C 80069FEC D1B5000C */  jal        RotMatrixYXZ
    /* 6C90 80069FF0 20000526 */   addiu     $a1, $s0, 0x20
    /* 6C94 80069FF4 6C00028E */  lw         $v0, 0x6C($s0)
    /* 6C98 80069FF8 7000038E */  lw         $v1, 0x70($s0)
    /* 6C9C 80069FFC 7400048E */  lw         $a0, 0x74($s0)
    /* 6CA0 8006A000 0000058E */  lw         $a1, 0x0($s0)
    /* 6CA4 8006A004 1C0000AE */  sw         $zero, 0x1C($s0)
    /* 6CA8 8006A008 340002AE */  sw         $v0, 0x34($s0)
    /* 6CAC 8006A00C 380003AE */  sw         $v1, 0x38($s0)
    /* 6CB0 8006A010 3C0004AE */  sw         $a0, 0x3C($s0)
    /* 6CB4 8006A014 1000A5AF */  sw         $a1, 0x10($sp)
    /* 6CB8 8006A018 0400028E */  lw         $v0, 0x4($s0)
    /* 6CBC 8006A01C 00000000 */  nop
    /* 6CC0 8006A020 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6CC4 8006A024 0800028E */  lw         $v0, 0x8($s0)
    /* 6CC8 8006A028 00000000 */  nop
    /* 6CCC 8006A02C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 6CD0 8006A030 0C00028E */  lw         $v0, 0xC($s0)
    /* 6CD4 8006A034 00000000 */  nop
    /* 6CD8 8006A038 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 6CDC 8006A03C 1000028E */  lw         $v0, 0x10($s0)
    /* 6CE0 8006A040 00000000 */  nop
    /* 6CE4 8006A044 2000A2AF */  sw         $v0, 0x20($sp)
    /* 6CE8 8006A048 1400038E */  lw         $v1, 0x14($s0)
    /* 6CEC 8006A04C 1C000226 */  addiu      $v0, $s0, 0x1C
    /* 6CF0 8006A050 2800A0AF */  sw         $zero, 0x28($sp)
    /* 6CF4 8006A054 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 6CF8 8006A058 2400A3AF */  sw         $v1, 0x24($sp)
    /* 6CFC 8006A05C 1800048E */  lw         $a0, 0x18($s0)
    /* 6D00 8006A060 51AD000C */  jal        GsSetProjection
    /* 6D04 8006A064 00000000 */   nop
    /* 6D08 8006A068 59B0000C */  jal        GsSetRefView2
    /* 6D0C 8006A06C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 6D10 8006A070 3400BF8F */  lw         $ra, 0x34($sp)
    /* 6D14 8006A074 3000B08F */  lw         $s0, 0x30($sp)
    /* 6D18 8006A078 0800E003 */  jr         $ra
    /* 6D1C 8006A07C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80069FD4
