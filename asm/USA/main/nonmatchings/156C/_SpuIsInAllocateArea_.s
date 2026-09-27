nonmatching _SpuIsInAllocateArea_, 0x8C

glabel _SpuIsInAllocateArea_
    /* 2C104 8003B904 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2C108 8003B908 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2C10C 8003B90C 0580033C */  lui        $v1, %hi(Spu_MemList)
    /* 2C110 8003B910 90FE638C */  lw         $v1, %lo(Spu_MemList)($v1)
    /* 2C114 8003B914 00000000 */  nop
    /* 2C118 8003B918 03006014 */  bnez       $v1, .L8003B928
    /* 2C11C 8003B91C 04204400 */   sllv      $a0, $a0, $v0
    /* 2C120 8003B920 62EE0008 */  j          .L8003B988
    /* 2C124 8003B924 21100000 */   addu      $v0, $zero, $zero
  .L8003B928:
    /* 2C128 8003B928 0080083C */  lui        $t0, (0x80000000 >> 16)
    /* 2C12C 8003B92C 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* 2C130 8003B930 FF0F063C */  lui        $a2, (0xFFFFFFF >> 16)
    /* 2C134 8003B934 FFFFC634 */  ori        $a2, $a2, (0xFFFFFFF & 0xFFFF)
    /* 2C138 8003B938 21286000 */  addu       $a1, $v1, $zero
  .L8003B93C:
    /* 2C13C 8003B93C 0000A38C */  lw         $v1, 0x0($a1)
    /* 2C140 8003B940 00000000 */  nop
    /* 2C144 8003B944 24106800 */  and        $v0, $v1, $t0
    /* 2C148 8003B948 0C004014 */  bnez       $v0, .L8003B97C
    /* 2C14C 8003B94C 24106700 */   and       $v0, $v1, $a3
    /* 2C150 8003B950 0C004014 */  bnez       $v0, .L8003B984
    /* 2C154 8003B954 24186600 */   and       $v1, $v1, $a2
    /* 2C158 8003B958 2B106400 */  sltu       $v0, $v1, $a0
    /* 2C15C 8003B95C 0A004010 */  beqz       $v0, .L8003B988
    /* 2C160 8003B960 01000224 */   addiu     $v0, $zero, 0x1
    /* 2C164 8003B964 0400A28C */  lw         $v0, 0x4($a1)
    /* 2C168 8003B968 00000000 */  nop
    /* 2C16C 8003B96C 21106200 */  addu       $v0, $v1, $v0
    /* 2C170 8003B970 2B108200 */  sltu       $v0, $a0, $v0
    /* 2C174 8003B974 04004014 */  bnez       $v0, .L8003B988
    /* 2C178 8003B978 01000224 */   addiu     $v0, $zero, 0x1
  .L8003B97C:
    /* 2C17C 8003B97C 4FEE0008 */  j          .L8003B93C
    /* 2C180 8003B980 0800A524 */   addiu     $a1, $a1, 0x8
  .L8003B984:
    /* 2C184 8003B984 21100000 */  addu       $v0, $zero, $zero
  .L8003B988:
    /* 2C188 8003B988 0800E003 */  jr         $ra
    /* 2C18C 8003B98C 00000000 */   nop
endlabel _SpuIsInAllocateArea_
    /* 2C190 8003B990 00000000 */  nop
