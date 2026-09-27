nonmatching func_8006374C, 0x30

glabel func_8006374C
    /* 3EC 8006374C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3F0 80063750 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3F4 80063754 1000828C */  lw         $v0, 0x10($a0)
    /* 3F8 80063758 00000000 */  nop
    /* 3FC 8006375C 03004014 */  bnez       $v0, .L8006376C
    /* 400 80063760 00000000 */   nop
    /* 404 80063764 5145000C */  jal        Task_NextState0
    /* 408 80063768 00000000 */   nop
  .L8006376C:
    /* 40C 8006376C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 410 80063770 00000000 */  nop
    /* 414 80063774 0800E003 */  jr         $ra
    /* 418 80063778 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006374C
