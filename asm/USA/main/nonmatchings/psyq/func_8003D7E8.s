nonmatching func_8003D7E8, 0x68

glabel func_8003D7E8
    /* 2DFE8 8003D7E8 0580023C */  lui        $v0, %hi(D_800506BC)
    /* 2DFEC 8003D7EC BC06428C */  lw         $v0, %lo(D_800506BC)($v0)
    /* 2DFF0 8003D7F0 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 2DFF4 8003D7F4 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 2DFF8 8003D7F8 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2DFFC 8003D7FC 0000A2AF */  sw         $v0, 0x0($sp)
    /* 2E000 8003D800 0000A28F */  lw         $v0, 0x0($sp)
    /* 2E004 8003D804 00000000 */  nop
    /* 2E008 8003D808 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2E00C 8003D80C 0000A2AF */  sw         $v0, 0x0($sp)
    /* 2E010 8003D810 0000A38F */  lw         $v1, 0x0($sp)
    /* 2E014 8003D814 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2E018 8003D818 0A006210 */  beq        $v1, $v0, .L8003D844
    /* 2E01C 8003D81C 21100000 */   addu      $v0, $zero, $zero
    /* 2E020 8003D820 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8003D824:
    /* 2E024 8003D824 0000A28F */  lw         $v0, 0x0($sp)
    /* 2E028 8003D828 00000000 */  nop
    /* 2E02C 8003D82C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2E030 8003D830 0000A2AF */  sw         $v0, 0x0($sp)
    /* 2E034 8003D834 0000A28F */  lw         $v0, 0x0($sp)
    /* 2E038 8003D838 00000000 */  nop
    /* 2E03C 8003D83C F9FF4314 */  bne        $v0, $v1, .L8003D824
    /* 2E040 8003D840 21100000 */   addu      $v0, $zero, $zero
  .L8003D844:
    /* 2E044 8003D844 1000BD27 */  addiu      $sp, $sp, 0x10
    /* 2E048 8003D848 0800E003 */  jr         $ra
    /* 2E04C 8003D84C 00000000 */   nop
endlabel func_8003D7E8
