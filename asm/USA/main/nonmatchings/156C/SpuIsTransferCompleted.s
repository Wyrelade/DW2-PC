nonmatching SpuIsTransferCompleted, 0xA4

glabel SpuIsTransferCompleted
    /* 2D004 8003C804 0580023C */  lui        $v0, %hi(D_8004FDB8)
    /* 2D008 8003C808 B8FD428C */  lw         $v0, %lo(D_8004FDB8)($v0)
    /* 2D00C 8003C80C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D010 8003C810 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2D014 8003C814 21888000 */  addu       $s1, $a0, $zero
    /* 2D018 8003C818 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2D01C 8003C81C 01001024 */  addiu      $s0, $zero, 0x1
    /* 2D020 8003C820 06005010 */  beq        $v0, $s0, .L8003C83C
    /* 2D024 8003C824 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2D028 8003C828 0580023C */  lui        $v0, %hi(Spu_InTransfer)
    /* 2D02C 8003C82C 5CFE428C */  lw         $v0, %lo(Spu_InTransfer)($v0)
    /* 2D030 8003C830 00000000 */  nop
    /* 2D034 8003C834 03005014 */  bne        $v0, $s0, .L8003C844
    /* 2D038 8003C838 00000000 */   nop
  .L8003C83C:
    /* 2D03C 8003C83C 25F20008 */  j          .L8003C894
    /* 2D040 8003C840 01000224 */   addiu     $v0, $zero, 0x1
  .L8003C844:
    /* 2D044 8003C844 0580043C */  lui        $a0, %hi(_spu_EVdma)
    /* 2D048 8003C848 B0FD848C */  lw         $a0, %lo(_spu_EVdma)($a0)
    /* 2D04C 8003C84C 2DF2000C */  jal        TestEvent
    /* 2D050 8003C850 00000000 */   nop
    /* 2D054 8003C854 0B003016 */  bne        $s1, $s0, .L8003C884
    /* 2D058 8003C858 00000000 */   nop
    /* 2D05C 8003C85C 0B004014 */  bnez       $v0, .L8003C88C
    /* 2D060 8003C860 01000224 */   addiu     $v0, $zero, 0x1
  .L8003C864:
    /* 2D064 8003C864 0580043C */  lui        $a0, %hi(_spu_EVdma)
    /* 2D068 8003C868 B0FD848C */  lw         $a0, %lo(_spu_EVdma)($a0)
    /* 2D06C 8003C86C 2DF2000C */  jal        TestEvent
    /* 2D070 8003C870 00000000 */   nop
    /* 2D074 8003C874 FBFF4010 */  beqz       $v0, .L8003C864
    /* 2D078 8003C878 01000224 */   addiu     $v0, $zero, 0x1
    /* 2D07C 8003C87C 23F20008 */  j          .L8003C88C
    /* 2D080 8003C880 00000000 */   nop
  .L8003C884:
    /* 2D084 8003C884 03005014 */  bne        $v0, $s0, .L8003C894
    /* 2D088 8003C888 00000000 */   nop
  .L8003C88C:
    /* 2D08C 8003C88C 0580013C */  lui        $at, %hi(Spu_InTransfer)
    /* 2D090 8003C890 5CFE22AC */  sw         $v0, %lo(Spu_InTransfer)($at)
  .L8003C894:
    /* 2D094 8003C894 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2D098 8003C898 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D09C 8003C89C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D0A0 8003C8A0 0800E003 */  jr         $ra
    /* 2D0A4 8003C8A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SpuIsTransferCompleted
    /* 2D0A8 8003C8A8 00000000 */  nop
    /* 2D0AC 8003C8AC 00000000 */  nop
    /* 2D0B0 8003C8B0 00000000 */  nop
