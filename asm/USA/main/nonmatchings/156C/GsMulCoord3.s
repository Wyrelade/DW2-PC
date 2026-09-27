nonmatching GsMulCoord3, 0x80

glabel GsMulCoord3
    /* 1C8E4 8002C0E4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1C8E8 8002C0E8 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1C8EC 8002C0EC 21808000 */  addu       $s0, $a0, $zero
    /* 1C8F0 8002C0F0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1C8F4 8002C0F4 2188A000 */  addu       $s1, $a1, $zero
    /* 1C8F8 8002C0F8 14002526 */  addiu      $a1, $s1, 0x14
    /* 1C8FC 8002C0FC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1C900 8002C100 DDB3000C */  jal        ApplyMatrixLV
    /* 1C904 8002C104 1000A627 */   addiu     $a2, $sp, 0x10
    /* 1C908 8002C108 21200002 */  addu       $a0, $s0, $zero
    /* 1C90C 8002C10C 89B4000C */  jal        MulMatrix
    /* 1C910 8002C110 21282002 */   addu      $a1, $s1, $zero
    /* 1C914 8002C114 1000A28F */  lw         $v0, 0x10($sp)
    /* 1C918 8002C118 1400038E */  lw         $v1, 0x14($s0)
    /* 1C91C 8002C11C 00000000 */  nop
    /* 1C920 8002C120 21104300 */  addu       $v0, $v0, $v1
    /* 1C924 8002C124 140002AE */  sw         $v0, 0x14($s0)
    /* 1C928 8002C128 1400A28F */  lw         $v0, 0x14($sp)
    /* 1C92C 8002C12C 1800038E */  lw         $v1, 0x18($s0)
    /* 1C930 8002C130 00000000 */  nop
    /* 1C934 8002C134 21104300 */  addu       $v0, $v0, $v1
    /* 1C938 8002C138 180002AE */  sw         $v0, 0x18($s0)
    /* 1C93C 8002C13C 1800A28F */  lw         $v0, 0x18($sp)
    /* 1C940 8002C140 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1C944 8002C144 00000000 */  nop
    /* 1C948 8002C148 21104300 */  addu       $v0, $v0, $v1
    /* 1C94C 8002C14C 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 1C950 8002C150 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1C954 8002C154 2400B18F */  lw         $s1, 0x24($sp)
    /* 1C958 8002C158 2000B08F */  lw         $s0, 0x20($sp)
    /* 1C95C 8002C15C 0800E003 */  jr         $ra
    /* 1C960 8002C160 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel GsMulCoord3
