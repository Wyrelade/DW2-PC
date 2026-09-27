nonmatching SpuInit, 0x20

glabel SpuInit
    /* 2A834 8003A034 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A838 8003A038 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A83C 8003A03C 15E8000C */  jal        _SpuInit
    /* 2A840 8003A040 21200000 */   addu      $a0, $zero, $zero
    /* 2A844 8003A044 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A848 8003A048 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2A84C 8003A04C 0800E003 */  jr         $ra
    /* 2A850 8003A050 00000000 */   nop
endlabel SpuInit
