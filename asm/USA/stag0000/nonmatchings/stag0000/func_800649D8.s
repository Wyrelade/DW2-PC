nonmatching func_800649D8, 0xFC

glabel func_800649D8
    /* 1678 800649D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 167C 800649DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1680 800649E0 21888000 */  addu       $s1, $a0, $zero
    /* 1684 800649E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1688 800649E8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 168C 800649EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1690 800649F0 1000248E */  lw         $a0, 0x10($s1)
    /* 1694 800649F4 2C00308E */  lw         $s0, 0x2C($s1)
    /* 1698 800649F8 1D008210 */  beq        $a0, $v0, .L80064A70
    /* 169C 800649FC 02008228 */   slti      $v0, $a0, 0x2
    /* 16A0 80064A00 03004014 */  bnez       $v0, .L80064A10
    /* 16A4 80064A04 02000224 */   addiu     $v0, $zero, 0x2
    /* 16A8 80064A08 2D008210 */  beq        $a0, $v0, .L80064AC0
    /* 16AC 80064A0C 00000000 */   nop
  .L80064A10:
    /* 16B0 80064A10 40010424 */  addiu      $a0, $zero, 0x140
    /* 16B4 80064A14 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 16B8 80064A18 21300000 */  addu       $a2, $zero, $zero
    /* 16BC 80064A1C 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 16C0 80064A20 2138C000 */   addu      $a3, $a2, $zero
    /* 16C4 80064A24 21200000 */  addu       $a0, $zero, $zero
    /* 16C8 80064A28 21288000 */  addu       $a1, $a0, $zero
    /* 16CC 80064A2C 6570000C */  jal        Gpu_SetBgClearColor
    /* 16D0 80064A30 21308000 */   addu      $a2, $a0, $zero
    /* 16D4 80064A34 4170000C */  jal        Gpu_ClearScreens
    /* 16D8 80064A38 00000000 */   nop
    /* 16DC 80064A3C 3271000C */  jal        Gfx_FadeInFromBlack
    /* 16E0 80064A40 20000424 */   addiu     $a0, $zero, 0x20
    /* 16E4 80064A44 9E93010C */  jal        func_80064E78
    /* 16E8 80064A48 00000000 */   nop
    /* 16EC 80064A4C 9393010C */  jal        func_80064E4C
    /* 16F0 80064A50 21200000 */   addu      $a0, $zero, $zero
    /* 16F4 80064A54 21202002 */  addu       $a0, $s1, $zero
    /* 16F8 80064A58 000000A6 */  sh         $zero, 0x0($s0)
    /* 16FC 80064A5C 020000A6 */  sh         $zero, 0x2($s0)
    /* 1700 80064A60 5145000C */  jal        Task_NextState0
    /* 1704 80064A64 060000A6 */   sh        $zero, 0x6($s0)
    /* 1708 80064A68 B0920108 */  j          .L80064AC0
    /* 170C 80064A6C 00000000 */   nop
  .L80064A70:
    /* 1710 80064A70 1400238E */  lw         $v1, 0x14($s1)
    /* 1714 80064A74 00000000 */  nop
    /* 1718 80064A78 0A006410 */  beq        $v1, $a0, .L80064AA4
    /* 171C 80064A7C 02006228 */   slti      $v0, $v1, 0x2
    /* 1720 80064A80 04004014 */  bnez       $v0, .L80064A94
    /* 1724 80064A84 21202002 */   addu      $a0, $s1, $zero
    /* 1728 80064A88 02000224 */  addiu      $v0, $zero, 0x2
    /* 172C 80064A8C 0A006210 */  beq        $v1, $v0, .L80064AB8
    /* 1730 80064A90 00000000 */   nop
  .L80064A94:
    /* 1734 80064A94 7890010C */  jal        func_800641E0
    /* 1738 80064A98 21280002 */   addu      $a1, $s0, $zero
    /* 173C 80064A9C B0920108 */  j          .L80064AC0
    /* 1740 80064AA0 00000000 */   nop
  .L80064AA4:
    /* 1744 80064AA4 21202002 */  addu       $a0, $s1, $zero
    /* 1748 80064AA8 AF90010C */  jal        func_800642BC
    /* 174C 80064AAC 21280002 */   addu      $a1, $s0, $zero
    /* 1750 80064AB0 B0920108 */  j          .L80064AC0
    /* 1754 80064AB4 00000000 */   nop
  .L80064AB8:
    /* 1758 80064AB8 2F92010C */  jal        func_800648BC
    /* 175C 80064ABC 21280002 */   addu      $a1, $s0, $zero
  .L80064AC0:
    /* 1760 80064AC0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1764 80064AC4 1400B18F */  lw         $s1, 0x14($sp)
    /* 1768 80064AC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 176C 80064ACC 0800E003 */  jr         $ra
    /* 1770 80064AD0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800649D8
