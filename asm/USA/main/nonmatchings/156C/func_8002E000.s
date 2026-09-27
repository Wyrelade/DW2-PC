nonmatching func_8002E000, 0x58

glabel func_8002E000
    /* 1E800 8002E000 0680023C */  lui        $v0, %hi(D_80061B98)
    /* 1E804 8002E004 981B428C */  lw         $v0, %lo(D_80061B98)($v0)
    /* 1E808 8002E008 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E80C 8002E00C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1E810 8002E010 21808000 */  addu       $s0, $a0, $zero
    /* 1E814 8002E014 0B004014 */  bnez       $v0, .L8002E044
    /* 1E818 8002E018 1400BFAF */   sw        $ra, 0x14($sp)
    /* 1E81C 8002E01C 0680043C */  lui        $a0, %hi(D_80061B40)
    /* 1E820 8002E020 59B7000C */  jal        CdPosToInt
    /* 1E824 8002E024 401B8424 */   addiu     $a0, $a0, %lo(D_80061B40)
    /* 1E828 8002E028 01004424 */  addiu      $a0, $v0, 0x1
    /* 1E82C 8002E02C E5C0000C */  jal        CdIntToPos
    /* 1E830 8002E030 21280002 */   addu      $a1, $s0, $zero
    /* 1E834 8002E034 0680023C */  lui        $v0, %hi(D_80061B44)
    /* 1E838 8002E038 441B428C */  lw         $v0, %lo(D_80061B44)($v0)
    /* 1E83C 8002E03C 12B80008 */  j          .L8002E048
    /* 1E840 8002E040 00000000 */   nop
  .L8002E044:
    /* 1E844 8002E044 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8002E048:
    /* 1E848 8002E048 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1E84C 8002E04C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E850 8002E050 0800E003 */  jr         $ra
    /* 1E854 8002E054 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E000
    /* 1E858 8002E058 00000000 */  nop
    /* 1E85C 8002E05C 00000000 */  nop
    /* 1E860 8002E060 00000000 */  nop
