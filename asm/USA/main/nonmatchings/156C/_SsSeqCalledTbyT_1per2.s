nonmatching _SsSeqCalledTbyT_1per2, 0x48

glabel _SsSeqCalledTbyT_1per2
    /* 25B30 80035330 0580023C */  lui        $v0, %hi(D_8004FC5C)
    /* 25B34 80035334 5CFC428C */  lw         $v0, %lo(D_8004FC5C)($v0)
    /* 25B38 80035338 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25B3C 8003533C 05004014 */  bnez       $v0, .L80035354
    /* 25B40 80035340 1000BFAF */   sw        $ra, 0x10($sp)
    /* 25B44 80035344 01000224 */  addiu      $v0, $zero, 0x1
    /* 25B48 80035348 0580013C */  lui        $at, %hi(D_8004FC5C)
    /* 25B4C 8003534C DAD40008 */  j          .L80035368
    /* 25B50 80035350 5CFC22AC */   sw        $v0, %lo(D_8004FC5C)($at)
  .L80035354:
    /* 25B54 80035354 0580023C */  lui        $v0, %hi(D_8004FC50)
    /* 25B58 80035358 50FC428C */  lw         $v0, %lo(D_8004FC50)($v0)
    /* 25B5C 8003535C 0580013C */  lui        $at, %hi(D_8004FC5C)
    /* 25B60 80035360 09F84000 */  jalr       $v0
    /* 25B64 80035364 5CFC20AC */   sw        $zero, %lo(D_8004FC5C)($at)
  .L80035368:
    /* 25B68 80035368 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25B6C 8003536C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 25B70 80035370 0800E003 */  jr         $ra
    /* 25B74 80035374 00000000 */   nop
endlabel _SsSeqCalledTbyT_1per2
    /* 25B78 80035378 00000000 */  nop
    /* 25B7C 8003537C 00000000 */  nop
    /* 25B80 80035380 00000000 */  nop
