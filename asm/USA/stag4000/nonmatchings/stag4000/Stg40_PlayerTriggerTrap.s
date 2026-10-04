nonmatching Stg40_PlayerTriggerTrap, 0x184

glabel Stg40_PlayerTriggerTrap
    /* 74E8 8006A848 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 74EC 8006A84C 602B438C */  lw         $v1, %lo(Stg40_RootState)($v0)
    /* 74F0 8006A850 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 74F4 8006A854 1000B0AF */  sw         $s0, 0x10($sp)
    /* 74F8 8006A858 21808000 */  addu       $s0, $a0, $zero
    /* 74FC 8006A85C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 7500 8006A860 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7504 8006A864 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7508 8006A868 1800B2AF */  sw         $s2, 0x18($sp)
    /* 750C 8006A86C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7510 8006A870 1800058E */  lw         $a1, 0x18($s0)
    /* 7514 8006A874 4000648C */  lw         $a0, 0x40($v1)
    /* 7518 8006A878 3C00748C */  lw         $s4, 0x3C($v1)
    /* 751C 8006A87C 08008290 */  lbu        $v0, 0x8($a0)
    /* 7520 8006A880 1000938C */  lw         $s3, 0x10($a0)
    /* 7524 8006A884 04004238 */  xori       $v0, $v0, 0x4
    /* 7528 8006A888 2B880200 */  sltu       $s1, $zero, $v0
    /* 752C 8006A88C 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 7530 8006A890 08004010 */  beqz       $v0, .L8006A8B4
    /* 7534 8006A894 0680023C */   lui       $v0, %hi(jtbl_80063424)
    /* 7538 8006A898 24344224 */  addiu      $v0, $v0, %lo(jtbl_80063424)
    /* 753C 8006A89C 80180500 */  sll        $v1, $a1, 2
    /* 7540 8006A8A0 21186200 */  addu       $v1, $v1, $v0
    /* 7544 8006A8A4 0000628C */  lw         $v0, 0x0($v1)
    /* 7548 8006A8A8 00000000 */  nop
    /* 754C 8006A8AC 08004000 */  jr         $v0
    /* 7550 8006A8B0 00000000 */   nop
  jlabel .L8006A8B4
    /* 7554 8006A8B4 A5C4010C */  jal        Stg40_RollTrapEffect
    /* 7558 8006A8B8 0780123C */   lui       $s2, %hi(Stg40_RootState)
    /* 755C 8006A8BC 602B438E */  lw         $v1, %lo(Stg40_RootState)($s2)
    /* 7560 8006A8C0 00000000 */  nop
    /* 7564 8006A8C4 540062AC */  sw         $v0, 0x54($v1)
    /* 7568 8006A8C8 10000324 */  addiu      $v1, $zero, 0x10
    /* 756C 8006A8CC 0B004310 */  beq        $v0, $v1, .L8006A8FC
    /* 7570 8006A8D0 21200002 */   addu      $a0, $s0, $zero
    /* 7574 8006A8D4 37B9010C */  jal        Stg40_ObjSetAnim
    /* 7578 8006A8D8 2C000524 */   addiu     $a1, $zero, 0x2C
    /* 757C 8006A8DC 21200002 */  addu       $a0, $s0, $zero
    /* 7580 8006A8E0 209E010C */  jal        Stg40_ObjStartFlash
    /* 7584 8006A8E4 01000524 */   addiu     $a1, $zero, 0x1
    /* 7588 8006A8E8 602B428E */  lw         $v0, %lo(Stg40_RootState)($s2)
    /* 758C 8006A8EC 01006592 */  lbu        $a1, 0x1($s3)
    /* 7590 8006A8F0 5400448C */  lw         $a0, 0x54($v0)
    /* 7594 8006A8F4 0BC5010C */  jal        Stg40_ApplyTrapEffect
    /* 7598 8006A8F8 00000000 */   nop
  .L8006A8FC:
    /* 759C 8006A8FC 03002012 */  beqz       $s1, .L8006A90C
    /* 75A0 8006A900 21208002 */   addu      $a0, $s4, $zero
    /* 75A4 8006A904 7745000C */  jal        Task_SetState1
    /* 75A8 8006A908 04000524 */   addiu     $a1, $zero, 0x4
  .L8006A90C:
    /* 75AC 8006A90C 34000424 */  addiu      $a0, $zero, 0x34
    /* 75B0 8006A910 21280000 */  addu       $a1, $zero, $zero
    /* 75B4 8006A914 01006292 */  lbu        $v0, 0x1($s3)
    /* 75B8 8006A918 2C00038E */  lw         $v1, 0x2C($s0)
    /* 75BC 8006A91C 01004224 */  addiu      $v0, $v0, 0x1
    /* 75C0 8006A920 A369000C */  jal        Snd_PlayById
    /* 75C4 8006A924 360062A4 */   sh        $v0, 0x36($v1)
    /* 75C8 8006A928 60AA0108 */  j          .L8006A980
    /* 75CC 8006A92C 00000000 */   nop
  jlabel .L8006A930
    /* 75D0 8006A930 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 75D4 8006A934 21200002 */   addu      $a0, $s0, $zero
    /* 75D8 8006A938 01000324 */  addiu      $v1, $zero, 0x1
    /* 75DC 8006A93C 1B004314 */  bne        $v0, $v1, .L8006A9AC
    /* 75E0 8006A940 21200002 */   addu      $a0, $s0, $zero
    /* 75E4 8006A944 37B9010C */  jal        Stg40_ObjSetAnim
    /* 75E8 8006A948 28000524 */   addiu     $a1, $zero, 0x28
    /* 75EC 8006A94C 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 75F0 8006A950 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 75F4 8006A954 00000000 */  nop
    /* 75F8 8006A958 5400458C */  lw         $a1, 0x54($v0)
    /* 75FC 8006A95C C4C4010C */  jal        Stg40_ShowTrapEffectMsg
    /* 7600 8006A960 21202002 */   addu      $a0, $s1, $zero
    /* 7604 8006A964 60AA0108 */  j          .L8006A980
    /* 7608 8006A968 00000000 */   nop
  jlabel .L8006A96C
    /* 760C 8006A96C C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 7610 8006A970 01000424 */   addiu     $a0, $zero, 0x1
    /* 7614 8006A974 01000324 */  addiu      $v1, $zero, 0x1
    /* 7618 8006A978 0C004314 */  bne        $v0, $v1, .L8006A9AC
    /* 761C 8006A97C 00000000 */   nop
  jlabel .L8006A980
    /* 7620 8006A980 6045000C */  jal        Task_NextState2
    /* 7624 8006A984 21200002 */   addu      $a0, $s0, $zero
    /* 7628 8006A988 6BAA0108 */  j          .L8006A9AC
    /* 762C 8006A98C 00000000 */   nop
  jlabel .L8006A990
    /* 7630 8006A990 03002016 */  bnez       $s1, .L8006A9A0
    /* 7634 8006A994 21200002 */   addu      $a0, $s0, $zero
    /* 7638 8006A998 69AA0108 */  j          .L8006A9A4
    /* 763C 8006A99C 15000524 */   addiu     $a1, $zero, 0x15
  .L8006A9A0:
    /* 7640 8006A9A0 06000524 */  addiu      $a1, $zero, 0x6
  .L8006A9A4:
    /* 7644 8006A9A4 7745000C */  jal        Task_SetState1
    /* 7648 8006A9A8 00000000 */   nop
  .L8006A9AC:
    /* 764C 8006A9AC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 7650 8006A9B0 2000B48F */  lw         $s4, 0x20($sp)
    /* 7654 8006A9B4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7658 8006A9B8 1800B28F */  lw         $s2, 0x18($sp)
    /* 765C 8006A9BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 7660 8006A9C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 7664 8006A9C4 0800E003 */  jr         $ra
    /* 7668 8006A9C8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_PlayerTriggerTrap
