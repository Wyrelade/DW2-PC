nonmatching Mem_Alloc, 0x50

glabel Mem_Alloc
    /* 1373C 80022F3C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 13740 80022F40 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13744 80022F44 21808000 */  addu       $s0, $a0, $zero
    /* 13748 80022F48 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1374C 80022F4C 2188A000 */  addu       $s1, $a1, $zero
    /* 13750 80022F50 1800BFAF */  sw         $ra, 0x18($sp)
    /* 13754 80022F54 21200002 */  addu       $a0, $s0, $zero
  .L80022F58:
    /* 13758 80022F58 A48B000C */  jal        Mem_TryAlloc
    /* 1375C 80022F5C 21282002 */   addu      $a1, $s1, $zero
    /* 13760 80022F60 05004014 */  bnez       $v0, .L80022F78
    /* 13764 80022F64 00000000 */   nop
    /* 13768 80022F68 EC8E000C */  jal        Cd_EvictLruFile
    /* 1376C 80022F6C 00000000 */   nop
    /* 13770 80022F70 D68B0008 */  j          .L80022F58
    /* 13774 80022F74 21200002 */   addu      $a0, $s0, $zero
  .L80022F78:
    /* 13778 80022F78 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1377C 80022F7C 1400B18F */  lw         $s1, 0x14($sp)
    /* 13780 80022F80 1000B08F */  lw         $s0, 0x10($sp)
    /* 13784 80022F84 0800E003 */  jr         $ra
    /* 13788 80022F88 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Mem_Alloc
