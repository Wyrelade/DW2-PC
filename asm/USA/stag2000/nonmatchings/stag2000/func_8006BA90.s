nonmatching func_8006BA90, 0x30

glabel func_8006BA90
    /* 8730 8006BA90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8734 8006BA94 1000BFAF */  sw         $ra, 0x10($sp)
    /* 8738 8006BA98 1000828C */  lw         $v0, 0x10($a0)
    /* 873C 8006BA9C 00000000 */  nop
    /* 8740 8006BAA0 03004014 */  bnez       $v0, .L8006BAB0
    /* 8744 8006BAA4 00000000 */   nop
    /* 8748 8006BAA8 5145000C */  jal        Task_NextState0
    /* 874C 8006BAAC 00000000 */   nop
  .L8006BAB0:
    /* 8750 8006BAB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 8754 8006BAB4 00000000 */  nop
    /* 8758 8006BAB8 0800E003 */  jr         $ra
    /* 875C 8006BABC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006BA90
