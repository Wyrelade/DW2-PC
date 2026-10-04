nonmatching Stg35_ScaleBarLen, 0x58

glabel Stg35_ScaleBarLen
    /* 2828 80065B88 2A10C500 */  slt        $v0, $a2, $a1
    /* 282C 80065B8C 03004014 */  bnez       $v0, .L80065B9C
    /* 2830 80065B90 18008600 */   mult      $a0, $a2
    /* 2834 80065B94 0800E003 */  jr         $ra
    /* 2838 80065B98 21108000 */   addu      $v0, $a0, $zero
  .L80065B9C:
    /* 283C 80065B9C 12380000 */  mflo       $a3
    /* 2840 80065BA0 00000000 */  nop
    /* 2844 80065BA4 00000000 */  nop
    /* 2848 80065BA8 1A00E500 */  div        $zero, $a3, $a1
    /* 284C 80065BAC 12200000 */  mflo       $a0
    /* 2850 80065BB0 0400C010 */  beqz       $a2, .L80065BC4
    /* 2854 80065BB4 00000000 */   nop
    /* 2858 80065BB8 02008014 */  bnez       $a0, .L80065BC4
    /* 285C 80065BBC 00000000 */   nop
    /* 2860 80065BC0 01000424 */  addiu      $a0, $zero, 0x1
  .L80065BC4:
    /* 2864 80065BC4 04008514 */  bne        $a0, $a1, .L80065BD8
    /* 2868 80065BC8 00000000 */   nop
    /* 286C 80065BCC 02008610 */  beq        $a0, $a2, .L80065BD8
    /* 2870 80065BD0 00000000 */   nop
    /* 2874 80065BD4 FFFF8424 */  addiu      $a0, $a0, -0x1
  .L80065BD8:
    /* 2878 80065BD8 0800E003 */  jr         $ra
    /* 287C 80065BDC 21108000 */   addu      $v0, $a0, $zero
endlabel Stg35_ScaleBarLen
