nonmatching func_80011B64, 0x4C

glabel func_80011B64
    /* 2364 80011B64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2368 80011B68 1000B0AF */  sw         $s0, 0x10($sp)
    /* 236C 80011B6C 21808000 */  addu       $s0, $a0, $zero
    /* 2370 80011B70 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2374 80011B74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2378 80011B78 1000028E */  lw         $v0, 0x10($s0)
    /* 237C 80011B7C 2C00118E */  lw         $s1, 0x2C($s0)
    /* 2380 80011B80 06004014 */  bnez       $v0, .L80011B9C
    /* 2384 80011B84 00000000 */   nop
    /* 2388 80011B88 6A73000C */  jal        Gfx_ReserveTexSlot
    /* 238C 80011B8C 00000000 */   nop
    /* 2390 80011B90 000022AE */  sw         $v0, 0x0($s1)
    /* 2394 80011B94 5145000C */  jal        Task_NextState0
    /* 2398 80011B98 21200002 */   addu      $a0, $s0, $zero
  .L80011B9C:
    /* 239C 80011B9C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 23A0 80011BA0 1400B18F */  lw         $s1, 0x14($sp)
    /* 23A4 80011BA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 23A8 80011BA8 0800E003 */  jr         $ra
    /* 23AC 80011BAC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80011B64
