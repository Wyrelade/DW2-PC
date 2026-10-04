nonmatching Stg11_ModeMenuUpdate, 0x34C

glabel Stg11_ModeMenuUpdate
    /* 55C 800638BC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 560 800638C0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 564 800638C4 21888000 */  addu       $s1, $a0, $zero
    /* 568 800638C8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 56C 800638CC 01001224 */  addiu      $s2, $zero, 0x1
    /* 570 800638D0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 574 800638D4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 578 800638D8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 57C 800638DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 580 800638E0 2C00308E */  lw         $s0, 0x2C($s1)
    /* 584 800638E4 1000238E */  lw         $v1, 0x10($s1)
    /* 588 800638E8 3400338E */  lw         $s3, 0x34($s1)
    /* 58C 800638EC 20007210 */  beq        $v1, $s2, .L80063970
    /* 590 800638F0 02006228 */   slti      $v0, $v1, 0x2
    /* 594 800638F4 03004014 */  bnez       $v0, .L80063904
    /* 598 800638F8 02000224 */   addiu     $v0, $zero, 0x2
    /* 59C 800638FC A4006210 */  beq        $v1, $v0, .L80063B90
    /* 5A0 80063900 00000000 */   nop
  .L80063904:
    /* 5A4 80063904 688E000C */  jal        Cd_GetFileEntry
    /* 5A8 80063908 280D043C */   lui       $a0, (0xD280000 >> 16)
    /* 5AC 8006390C 21200002 */  addu       $a0, $s0, $zero
    /* 5B0 80063910 20008684 */  lh         $a2, 0x20($a0)
    /* 5B4 80063914 00000000 */  nop
    /* 5B8 80063918 40180600 */  sll        $v1, $a2, 1
    /* 5BC 8006391C 21186600 */  addu       $v1, $v1, $a2
    /* 5C0 80063920 80180300 */  sll        $v1, $v1, 2
    /* 5C4 80063924 21186200 */  addu       $v1, $v1, $v0
    /* 5C8 80063928 F7FF6888 */  lwl        $t0, -0x9($v1)
    /* 5CC 8006392C F4FF6898 */  lwr        $t0, -0xC($v1)
    /* 5D0 80063930 FBFF6988 */  lwl        $t1, -0x5($v1)
    /* 5D4 80063934 F8FF6998 */  lwr        $t1, -0x8($v1)
    /* 5D8 80063938 FFFF6A88 */  lwl        $t2, -0x1($v1)
    /* 5DC 8006393C FCFF6A98 */  lwr        $t2, -0x4($v1)
    /* 5E0 80063940 170088A8 */  swl        $t0, 0x17($a0)
    /* 5E4 80063944 140088B8 */  swr        $t0, 0x14($a0)
    /* 5E8 80063948 1B0089A8 */  swl        $t1, 0x1B($a0)
    /* 5EC 8006394C 180089B8 */  swr        $t1, 0x18($a0)
    /* 5F0 80063950 1F008AA8 */  swl        $t2, 0x1F($a0)
    /* 5F4 80063954 1C008AB8 */  swr        $t2, 0x1C($a0)
    /* 5F8 80063958 2270000C */  jal        Mem_FillWordsNeg1
    /* 5FC 8006395C 04000524 */   addiu     $a1, $zero, 0x4
    /* 600 80063960 5145000C */  jal        Task_NextState0
    /* 604 80063964 21202002 */   addu      $a0, $s1, $zero
    /* 608 80063968 FA8E0108 */  j          .L80063BE8
    /* 60C 8006396C 00000000 */   nop
  .L80063970:
    /* 610 80063970 280D043C */  lui        $a0, (0xD280003 >> 16)
    /* 614 80063974 20000586 */  lh         $a1, 0x20($s0)
    /* 618 80063978 03008434 */  ori        $a0, $a0, (0xD280003 & 0xFFFF)
    /* 61C 8006397C AC4E000C */  jal        Cd_GetFileEntrySubPtr
    /* 620 80063980 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 624 80063984 1400238E */  lw         $v1, 0x14($s1)
    /* 628 80063988 00000000 */  nop
    /* 62C 8006398C 24007210 */  beq        $v1, $s2, .L80063A20
    /* 630 80063990 21A04000 */   addu      $s4, $v0, $zero
    /* 634 80063994 02006228 */  slti       $v0, $v1, 0x2
    /* 638 80063998 04004014 */  bnez       $v0, .L800639AC
    /* 63C 8006399C 21202002 */   addu      $a0, $s1, $zero
    /* 640 800639A0 02000224 */  addiu      $v0, $zero, 0x2
    /* 644 800639A4 48006210 */  beq        $v1, $v0, .L80063AC8
    /* 648 800639A8 00000000 */   nop
  .L800639AC:
    /* 64C 800639AC B94D000C */  jal        Math_RampToOne
    /* 650 800639B0 28000526 */   addiu     $a1, $s0, 0x28
    /* 654 800639B4 8C004014 */  bnez       $v0, .L80063BE8
    /* 658 800639B8 280D043C */   lui       $a0, (0xD280001 >> 16)
    /* 65C 800639BC 20000586 */  lh         $a1, 0x20($s0)
    /* 660 800639C0 01008434 */  ori        $a0, $a0, (0xD280001 & 0xFFFF)
    /* 664 800639C4 AC4E000C */  jal        Cd_GetFileEntrySubPtr
    /* 668 800639C8 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 66C 800639CC 21200002 */  addu       $a0, $s0, $zero
    /* 670 800639D0 21284000 */  addu       $a1, $v0, $zero
    /* 674 800639D4 564D000C */  jal        Text_PrintIdList
    /* 678 800639D8 02000624 */   addiu     $a2, $zero, 0x2
    /* 67C 800639DC FD01023C */  lui        $v0, (0x1FD01A2 >> 16)
    /* 680 800639E0 20000486 */  lh         $a0, 0x20($s0)
    /* 684 800639E4 A2014234 */  ori        $v0, $v0, (0x1FD01A2 & 0xFFFF)
    /* 688 800639E8 688E000C */  jal        Cd_GetFileEntry
    /* 68C 800639EC 21208200 */   addu      $a0, $a0, $v0
    /* 690 800639F0 0C000426 */  addiu      $a0, $s0, 0xC
    /* 694 800639F4 21284000 */  addu       $a1, $v0, $zero
    /* 698 800639F8 81000624 */  addiu      $a2, $zero, 0x81
    /* 69C 800639FC 0780033C */  lui        $v1, %hi(Stg11_ModeHelpPos)
    /* 6A0 80063A00 B8816224 */  addiu      $v0, $v1, %lo(Stg11_ModeHelpPos)
    /* 6A4 80063A04 02004794 */  lhu        $a3, 0x2($v0)
    /* 6A8 80063A08 B8816294 */  lhu        $v0, %lo(Stg11_ModeHelpPos)($v1)
    /* 6AC 80063A0C 003C0700 */  sll        $a3, $a3, 16
    /* 6B0 80063A10 3E4D000C */  jal        Text_OpenPacked
    /* 6B4 80063A14 25384700 */   or        $a3, $v0, $a3
    /* 6B8 80063A18 EE8E0108 */  j          .L80063BB8
    /* 6BC 80063A1C 00000000 */   nop
  .L80063A20:
    /* 6C0 80063A20 10001326 */  addiu      $s3, $s0, 0x10
    /* 6C4 80063A24 21206002 */  addu       $a0, $s3, $zero
    /* 6C8 80063A28 24000686 */  lh         $a2, 0x24($s0)
    /* 6CC 80063A2C 14001226 */  addiu      $s2, $s0, 0x14
    /* 6D0 80063A30 304E000C */  jal        Menu_MoveGridCursor
    /* 6D4 80063A34 21284002 */   addu      $a1, $s2, $zero
    /* 6D8 80063A38 1F004014 */  bnez       $v0, .L80063AB8
    /* 6DC 80063A3C 0C000424 */   addiu     $a0, $zero, 0xC
    /* 6E0 80063A40 0680023C */  lui        $v0, %hi(Pad_State)
    /* 6E4 80063A44 24000386 */  lh         $v1, 0x24($s0)
    /* 6E8 80063A48 F0F64224 */  addiu      $v0, $v0, %lo(Pad_State)
    /* 6EC 80063A4C 80190300 */  sll        $v1, $v1, 6
    /* 6F0 80063A50 21186200 */  addu       $v1, $v1, $v0
    /* 6F4 80063A54 1400628C */  lw         $v0, 0x14($v1)
    /* 6F8 80063A58 00000000 */  nop
    /* 6FC 80063A5C 0D004018 */  blez       $v0, .L80063A94
    /* 700 80063A60 21206002 */   addu      $a0, $s3, $zero
    /* 704 80063A64 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 708 80063A68 21284002 */   addu      $a1, $s2, $zero
    /* 70C 80063A6C 80100200 */  sll        $v0, $v0, 2
    /* 710 80063A70 21105400 */  addu       $v0, $v0, $s4
    /* 714 80063A74 00004384 */  lh         $v1, 0x0($v0)
    /* 718 80063A78 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 71C 80063A7C 5A006210 */  beq        $v1, $v0, .L80063BE8
    /* 720 80063A80 0A000424 */   addiu     $a0, $zero, 0xA
    /* 724 80063A84 A369000C */  jal        Snd_PlayById
    /* 728 80063A88 21280000 */   addu      $a1, $zero, $zero
    /* 72C 80063A8C EE8E0108 */  j          .L80063BB8
    /* 730 80063A90 00000000 */   nop
  .L80063A94:
    /* 734 80063A94 1C00628C */  lw         $v0, 0x1C($v1)
    /* 738 80063A98 00000000 */  nop
    /* 73C 80063A9C 52004018 */  blez       $v0, .L80063BE8
    /* 740 80063AA0 0B000424 */   addiu     $a0, $zero, 0xB
    /* 744 80063AA4 A369000C */  jal        Snd_PlayById
    /* 748 80063AA8 21280000 */   addu      $a1, $zero, $zero
    /* 74C 80063AAC 21202002 */  addu       $a0, $s1, $zero
    /* 750 80063AB0 F88E0108 */  j          .L80063BE0
    /* 754 80063AB4 02000524 */   addiu     $a1, $zero, 0x2
  .L80063AB8:
    /* 758 80063AB8 A369000C */  jal        Snd_PlayById
    /* 75C 80063ABC 21280000 */   addu      $a1, $zero, $zero
    /* 760 80063AC0 FA8E0108 */  j          .L80063BE8
    /* 764 80063AC4 00000000 */   nop
  .L80063AC8:
    /* 768 80063AC8 1800228E */  lw         $v0, 0x18($s1)
    /* 76C 80063ACC 00000000 */  nop
    /* 770 80063AD0 03004010 */  beqz       $v0, .L80063AE0
    /* 774 80063AD4 10000426 */   addiu     $a0, $s0, 0x10
    /* 778 80063AD8 0F005210 */  beq        $v0, $s2, .L80063B18
    /* 77C 80063ADC 00000000 */   nop
  .L80063AE0:
    /* 780 80063AE0 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 784 80063AE4 14000526 */   addiu     $a1, $s0, 0x14
    /* 788 80063AE8 80100200 */  sll        $v0, $v0, 2
    /* 78C 80063AEC 21105400 */  addu       $v0, $v0, $s4
    /* 790 80063AF0 00004484 */  lh         $a0, 0x0($v0)
    /* 794 80063AF4 02004684 */  lh         $a2, 0x2($v0)
    /* 798 80063AF8 1F44000C */  jal        Task_Create
    /* 79C 80063AFC 21286002 */   addu      $a1, $s3, $zero
    /* 7A0 80063B00 E26E000C */  jal        Text_Close
    /* 7A4 80063B04 0C000426 */   addiu     $a0, $s0, 0xC
    /* 7A8 80063B08 6045000C */  jal        Task_NextState2
    /* 7AC 80063B0C 21202002 */   addu      $a0, $s1, $zero
    /* 7B0 80063B10 FA8E0108 */  j          .L80063BE8
    /* 7B4 80063B14 00000000 */   nop
  .L80063B18:
    /* 7B8 80063B18 0000628E */  lw         $v0, 0x0($s3)
    /* 7BC 80063B1C 00000000 */  nop
    /* 7C0 80063B20 31004014 */  bnez       $v0, .L80063BE8
    /* 7C4 80063B24 0780023C */   lui       $v0, %hi(Stg11_LoadDone)
    /* 7C8 80063B28 C8854284 */  lh         $v0, %lo(Stg11_LoadDone)($v0)
    /* 7CC 80063B2C 00000000 */  nop
    /* 7D0 80063B30 15004014 */  bnez       $v0, .L80063B88
    /* 7D4 80063B34 21202002 */   addu      $a0, $s1, $zero
    /* 7D8 80063B38 FD01023C */  lui        $v0, (0x1FD01A2 >> 16)
    /* 7DC 80063B3C 20000486 */  lh         $a0, 0x20($s0)
    /* 7E0 80063B40 A2014234 */  ori        $v0, $v0, (0x1FD01A2 & 0xFFFF)
    /* 7E4 80063B44 688E000C */  jal        Cd_GetFileEntry
    /* 7E8 80063B48 21208200 */   addu      $a0, $a0, $v0
    /* 7EC 80063B4C 0C000426 */  addiu      $a0, $s0, 0xC
    /* 7F0 80063B50 21284000 */  addu       $a1, $v0, $zero
    /* 7F4 80063B54 81000624 */  addiu      $a2, $zero, 0x81
    /* 7F8 80063B58 0780033C */  lui        $v1, %hi(Stg11_ModeHelpPos)
    /* 7FC 80063B5C B8816224 */  addiu      $v0, $v1, %lo(Stg11_ModeHelpPos)
    /* 800 80063B60 02004794 */  lhu        $a3, 0x2($v0)
    /* 804 80063B64 B8816294 */  lhu        $v0, %lo(Stg11_ModeHelpPos)($v1)
    /* 808 80063B68 003C0700 */  sll        $a3, $a3, 16
    /* 80C 80063B6C 3E4D000C */  jal        Text_OpenPacked
    /* 810 80063B70 25384700 */   or        $a3, $v0, $a3
    /* 814 80063B74 21202002 */  addu       $a0, $s1, $zero
    /* 818 80063B78 7745000C */  jal        Task_SetState1
    /* 81C 80063B7C 01000524 */   addiu     $a1, $zero, 0x1
    /* 820 80063B80 FA8E0108 */  j          .L80063BE8
    /* 824 80063B84 00000000 */   nop
  .L80063B88:
    /* 828 80063B88 F88E0108 */  j          .L80063BE0
    /* 82C 80063B8C 02000524 */   addiu     $a1, $zero, 0x2
  .L80063B90:
    /* 830 80063B90 1400228E */  lw         $v0, 0x14($s1)
    /* 834 80063B94 00000000 */  nop
    /* 838 80063B98 03004010 */  beqz       $v0, .L80063BA8
    /* 83C 80063B9C 21200002 */   addu      $a0, $s0, $zero
    /* 840 80063BA0 09005210 */  beq        $v0, $s2, .L80063BC8
    /* 844 80063BA4 00000000 */   nop
  .L80063BA8:
    /* 848 80063BA8 2C70000C */  jal        Text_CloseArray
    /* 84C 80063BAC 04000524 */   addiu     $a1, $zero, 0x4
    /* 850 80063BB0 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 854 80063BB4 20000424 */   addiu     $a0, $zero, 0x20
  .L80063BB8:
    /* 858 80063BB8 5945000C */  jal        Task_NextState1
    /* 85C 80063BBC 21202002 */   addu      $a0, $s1, $zero
    /* 860 80063BC0 FA8E0108 */  j          .L80063BE8
    /* 864 80063BC4 00000000 */   nop
  .L80063BC8:
    /* 868 80063BC8 21202002 */  addu       $a0, $s1, $zero
    /* 86C 80063BCC C54D000C */  jal        Math_RampToZero
    /* 870 80063BD0 28000526 */   addiu     $a1, $s0, 0x28
    /* 874 80063BD4 04004014 */  bnez       $v0, .L80063BE8
    /* 878 80063BD8 21202002 */   addu      $a0, $s1, $zero
    /* 87C 80063BDC 03000524 */  addiu      $a1, $zero, 0x3
  .L80063BE0:
    /* 880 80063BE0 7045000C */  jal        Task_SetState0
    /* 884 80063BE4 00000000 */   nop
  .L80063BE8:
    /* 888 80063BE8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 88C 80063BEC 2000B48F */  lw         $s4, 0x20($sp)
    /* 890 80063BF0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 894 80063BF4 1800B28F */  lw         $s2, 0x18($sp)
    /* 898 80063BF8 1400B18F */  lw         $s1, 0x14($sp)
    /* 89C 80063BFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 8A0 80063C00 0800E003 */  jr         $ra
    /* 8A4 80063C04 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg11_ModeMenuUpdate
