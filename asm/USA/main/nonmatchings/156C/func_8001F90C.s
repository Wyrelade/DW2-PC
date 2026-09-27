nonmatching func_8001F90C, 0x64

glabel func_8001F90C
    /* 1010C 8001F90C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 10110 8001F910 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10114 8001F914 21800000 */  addu       $s0, $zero, $zero
    /* 10118 8001F918 0480023C */  lui        $v0, %hi(D_800416CC)
    /* 1011C 8001F91C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 10120 8001F920 CC165124 */  addiu      $s1, $v0, %lo(D_800416CC)
    /* 10124 8001F924 1800BFAF */  sw         $ra, 0x18($sp)
  .L8001F928:
    /* 10128 8001F928 21200002 */  addu       $a0, $s0, $zero
    /* 1012C 8001F92C 59AD000C */  jal        func_8002B564
    /* 10130 8001F930 21282002 */   addu      $a1, $s1, $zero
    /* 10134 8001F934 01001026 */  addiu      $s0, $s0, 0x1
    /* 10138 8001F938 0300022A */  slti       $v0, $s0, 0x3
    /* 1013C 8001F93C FAFF4014 */  bnez       $v0, .L8001F928
    /* 10140 8001F940 10003126 */   addiu     $s1, $s1, 0x10
    /* 10144 8001F944 CC040424 */  addiu      $a0, $zero, 0x4CC
    /* 10148 8001F948 21288000 */  addu       $a1, $a0, $zero
    /* 1014C 8001F94C D5AE000C */  jal        GsSetAmbient
    /* 10150 8001F950 21308000 */   addu      $a2, $a0, $zero
    /* 10154 8001F954 B5AE000C */  jal        GsSetLightMode
    /* 10158 8001F958 21200000 */   addu      $a0, $zero, $zero
    /* 1015C 8001F95C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 10160 8001F960 1400B18F */  lw         $s1, 0x14($sp)
    /* 10164 8001F964 1000B08F */  lw         $s0, 0x10($sp)
    /* 10168 8001F968 0800E003 */  jr         $ra
    /* 1016C 8001F96C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001F90C
