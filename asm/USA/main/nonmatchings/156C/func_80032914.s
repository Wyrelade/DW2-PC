nonmatching func_80032914, 0x38

glabel func_80032914
    /* 23114 80032914 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23118 80032918 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2311C 8003291C 35C3000C */  jal        ResetCallback
    /* 23120 80032920 00000000 */   nop
    /* 23124 80032924 0DE8000C */  jal        SpuInit
    /* 23128 80032928 00000000 */   nop
    /* 2312C 8003292C E9F0000C */  jal        SpuClearReverbWorkArea
    /* 23130 80032930 07000424 */   addiu     $a0, $zero, 0x7
    /* 23134 80032934 1DCA000C */  jal        func_80032874
    /* 23138 80032938 00000000 */   nop
    /* 2313C 8003293C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23140 80032940 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 23144 80032944 0800E003 */  jr         $ra
    /* 23148 80032948 00000000 */   nop
endlabel func_80032914
    /* 2314C 8003294C 00000000 */  nop
    /* 23150 80032950 00000000 */  nop
