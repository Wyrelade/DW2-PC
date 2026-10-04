nonmatching Stg35_TextFree, 0x48

glabel Stg35_TextFree
    /* 23B8 80065718 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23BC 8006571C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23C0 80065720 21808000 */  addu       $s0, $a0, $zero
    /* 23C4 80065724 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23C8 80065728 0000048E */  lw         $a0, 0x0($s0)
    /* 23CC 8006572C 00000000 */  nop
    /* 23D0 80065730 07008010 */  beqz       $a0, .L80065750
    /* 23D4 80065734 00000000 */   nop
    /* 23D8 80065738 E26E000C */  jal        Text_Close
    /* 23DC 8006573C 00000000 */   nop
    /* 23E0 80065740 0000048E */  lw         $a0, 0x0($s0)
    /* 23E4 80065744 618B000C */  jal        Mem_Free
    /* 23E8 80065748 00000000 */   nop
    /* 23EC 8006574C 000000AE */  sw         $zero, 0x0($s0)
  .L80065750:
    /* 23F0 80065750 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23F4 80065754 1000B08F */  lw         $s0, 0x10($sp)
    /* 23F8 80065758 0800E003 */  jr         $ra
    /* 23FC 8006575C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_TextFree
