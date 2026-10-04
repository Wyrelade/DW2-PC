nonmatching Stg20_ShopBitsUpdate, 0x74

glabel Stg20_ShopBitsUpdate
    /* 881C 8006BB7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 8820 8006BB80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8824 8006BB84 21888000 */  addu       $s1, $a0, $zero
    /* 8828 8006BB88 1800BFAF */  sw         $ra, 0x18($sp)
    /* 882C 8006BB8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8830 8006BB90 1000228E */  lw         $v0, 0x10($s1)
    /* 8834 8006BB94 2C00308E */  lw         $s0, 0x2C($s1)
    /* 8838 8006BB98 10004014 */  bnez       $v0, .L8006BBDC
    /* 883C 8006BB9C 00000000 */   nop
    /* 8840 8006BBA0 21200002 */  addu       $a0, $s0, $zero
    /* 8844 8006BBA4 2270000C */  jal        Mem_FillWordsNeg1
    /* 8848 8006BBA8 01000524 */   addiu     $a1, $zero, 0x1
    /* 884C 8006BBAC 21200002 */  addu       $a0, $s0, $zero
    /* 8850 8006BBB0 0680033C */  lui        $v1, %hi(D_80063588)
    /* 8854 8006BBB4 88356224 */  addiu      $v0, $v1, %lo(D_80063588)
    /* 8858 8006BBB8 5F000524 */  addiu      $a1, $zero, 0x5F
    /* 885C 8006BBBC 21300000 */  addu       $a2, $zero, $zero
    /* 8860 8006BBC0 02004794 */  lhu        $a3, 0x2($v0)
    /* 8864 8006BBC4 88356294 */  lhu        $v0, %lo(D_80063588)($v1)
    /* 8868 8006BBC8 003C0700 */  sll        $a3, $a3, 16
    /* 886C 8006BBCC F26F000C */  jal        Text_OpenById
    /* 8870 8006BBD0 25384700 */   or        $a3, $v0, $a3
    /* 8874 8006BBD4 5145000C */  jal        Task_NextState0
    /* 8878 8006BBD8 21202002 */   addu      $a0, $s1, $zero
  .L8006BBDC:
    /* 887C 8006BBDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 8880 8006BBE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 8884 8006BBE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 8888 8006BBE8 0800E003 */  jr         $ra
    /* 888C 8006BBEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_ShopBitsUpdate
