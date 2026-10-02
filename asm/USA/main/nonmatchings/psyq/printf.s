nonmatching printf, 0x3C

glabel printf
    /* 1A814 8002A014 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1A818 8002A018 1C00A227 */  addiu      $v0, $sp, 0x1C
    /* 1A81C 8002A01C 1800A4AF */  sw         $a0, 0x18($sp)
    /* 1A820 8002A020 01000424 */  addiu      $a0, $zero, 0x1
    /* 1A824 8002A024 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1A828 8002A028 1C00A5AF */  sw         $a1, 0x1C($sp)
    /* 1A82C 8002A02C 040046AC */  sw         $a2, 0x4($v0)
    /* 1A830 8002A030 080047AC */  sw         $a3, 0x8($v0)
    /* 1A834 8002A034 1800A58F */  lw         $a1, 0x18($sp)
    /* 1A838 8002A038 15A8000C */  jal        Debug_VPrintf
    /* 1A83C 8002A03C 21304000 */   addu      $a2, $v0, $zero
    /* 1A840 8002A040 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1A844 8002A044 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1A848 8002A048 0800E003 */  jr         $ra
    /* 1A84C 8002A04C 00000000 */   nop
endlabel printf
    /* 1A850 8002A050 00000000 */  nop
