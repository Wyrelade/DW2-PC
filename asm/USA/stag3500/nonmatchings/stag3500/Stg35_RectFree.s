nonmatching Stg35_RectFree, 0x3C

glabel Stg35_RectFree
    /* 2594 800658F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2598 800658F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 259C 800658FC 21808000 */  addu       $s0, $a0, $zero
    /* 25A0 80065900 1400BFAF */  sw         $ra, 0x14($sp)
    /* 25A4 80065904 0000048E */  lw         $a0, 0x0($s0)
    /* 25A8 80065908 00000000 */  nop
    /* 25AC 8006590C 04008010 */  beqz       $a0, .L80065920
    /* 25B0 80065910 00000000 */   nop
    /* 25B4 80065914 618B000C */  jal        Mem_Free
    /* 25B8 80065918 00000000 */   nop
    /* 25BC 8006591C 000000AE */  sw         $zero, 0x0($s0)
  .L80065920:
    /* 25C0 80065920 1400BF8F */  lw         $ra, 0x14($sp)
    /* 25C4 80065924 1000B08F */  lw         $s0, 0x10($sp)
    /* 25C8 80065928 0800E003 */  jr         $ra
    /* 25CC 8006592C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_RectFree
