nonmatching _SsTrapIntrVSync, 0x4C

glabel _SsTrapIntrVSync
    /* 25AE4 800352E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25AE8 800352E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25AEC 800352EC 0580103C */  lui        $s0, %hi(D_8004FC54)
    /* 25AF0 800352F0 54FC1026 */  addiu      $s0, $s0, %lo(D_8004FC54)
    /* 25AF4 800352F4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 25AF8 800352F8 0000028E */  lw         $v0, 0x0($s0)
    /* 25AFC 800352FC 00000000 */  nop
    /* 25B00 80035300 03004010 */  beqz       $v0, .L80035310
    /* 25B04 80035304 00000000 */   nop
    /* 25B08 80035308 09F84000 */  jalr       $v0
    /* 25B0C 8003530C 00000000 */   nop
  .L80035310:
    /* 25B10 80035310 FCFF028E */  lw         $v0, -0x4($s0)
    /* 25B14 80035314 00000000 */  nop
    /* 25B18 80035318 09F84000 */  jalr       $v0
    /* 25B1C 8003531C 00000000 */   nop
    /* 25B20 80035320 1400BF8F */  lw         $ra, 0x14($sp)
    /* 25B24 80035324 1000B08F */  lw         $s0, 0x10($sp)
    /* 25B28 80035328 0800E003 */  jr         $ra
    /* 25B2C 8003532C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SsTrapIntrVSync
