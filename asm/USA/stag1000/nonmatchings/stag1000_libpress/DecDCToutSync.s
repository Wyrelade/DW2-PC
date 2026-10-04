nonmatching DecDCToutSync, 0x48

glabel DecDCToutSync
    /* 1590 800648F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1594 800648F4 05008014 */  bnez       $a0, .L8006490C
    /* 1598 800648F8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 159C 800648FC 0893010C */  jal        MDEC_out_sync
    /* 15A0 80064900 00000000 */   nop
    /* 15A4 80064904 4A920108 */  j          .L80064928
    /* 15A8 80064908 00000000 */   nop
  .L8006490C:
    /* 15AC 8006490C 0680023C */  lui        $v0, %hi(D_8006537C)
    /* 15B0 80064910 7C53428C */  lw         $v0, %lo(D_8006537C)($v0)
    /* 15B4 80064914 00000000 */  nop
    /* 15B8 80064918 0000428C */  lw         $v0, 0x0($v0)
    /* 15BC 8006491C 00000000 */  nop
    /* 15C0 80064920 02160200 */  srl        $v0, $v0, 24
    /* 15C4 80064924 01004230 */  andi       $v0, $v0, 0x1
  .L80064928:
    /* 15C8 80064928 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15CC 8006492C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 15D0 80064930 0800E003 */  jr         $ra
    /* 15D4 80064934 00000000 */   nop
endlabel DecDCToutSync
