/* Handwritten function */
nonmatching func_8003D8EC, 0x70

glabel func_8003D8EC
    /* 2E0EC 8003D8EC 0680013C */  lui        $at, %hi(D_80062F10)
    /* 2E0F0 8003D8F0 102F3FAC */  sw         $ra, %lo(D_80062F10)($at)
    /* 2E0F4 8003D8F4 F19B000C */  jal        EnterCriticalSection
    /* 2E0F8 8003D8F8 00000000 */   nop
    /* 2E0FC 8003D8FC 57000924 */  addiu      $t1, $zero, 0x57
    /* 2E100 8003D900 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E104 8003D904 09F84001 */  jalr       $t2
    /* 2E108 8003D908 00000000 */   nop
    /* 2E10C 8003D90C 6C01428C */  lw         $v0, 0x16C($v0)
    /* 2E110 8003D910 0B000924 */  addiu      $t1, $zero, 0xB
    /* 2E114 8003D914 84084320 */  addi       $v1, $v0, 0x884 /* handwritten instruction */
    /* 2E118 8003D918 0680013C */  lui        $at, %hi(jtbl_80062F18)
    /* 2E11C 8003D91C 182F23AC */  sw         $v1, %lo(jtbl_80062F18)($at)
    /* 2E120 8003D920 94084320 */  addi       $v1, $v0, 0x894 /* handwritten instruction */
    /* 2E124 8003D924 0680013C */  lui        $at, %hi(jtbl_80062F1C)
    /* 2E128 8003D928 1C2F23AC */  sw         $v1, %lo(jtbl_80062F1C)($at)
  .L8003D92C:
    /* 2E12C 8003D92C 940540AC */  sw         $zero, 0x594($v0)
    /* 2E130 8003D930 04004224 */  addiu      $v0, $v0, 0x4
    /* 2E134 8003D934 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 2E138 8003D938 FCFF2015 */  bnez       $t1, .L8003D92C
    /* 2E13C 8003D93C 00000000 */   nop
    /* 2E140 8003D940 E9B6000C */  jal        FlushCache
    /* 2E144 8003D944 00000000 */   nop
    /* 2E148 8003D948 06801F3C */  lui        $ra, %hi(D_80062F10)
    /* 2E14C 8003D94C 102FFF8F */  lw         $ra, %lo(D_80062F10)($ra)
    /* 2E150 8003D950 00000000 */  nop
    /* 2E154 8003D954 0800E003 */  jr         $ra
    /* 2E158 8003D958 00000000 */   nop
endlabel func_8003D8EC
    /* 2E15C 8003D95C 00000000 */  nop
    /* 2E160 8003D960 00000000 */  nop
