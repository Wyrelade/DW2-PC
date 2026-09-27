nonmatching func_8003E6C8, 0x1B0

glabel func_8003E6C8
    /* 2EEC8 8003E6C8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2EECC 8003E6CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2EED0 8003E6D0 21888000 */  addu       $s1, $a0, $zero
    /* 2EED4 8003E6D4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2EED8 8003E6D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2EEDC 8003E6DC 0000238E */  lw         $v1, 0x0($s1)
    /* 2EEE0 8003E6E0 0A001024 */  addiu      $s0, $zero, 0xA
    /* 2EEE4 8003E6E4 15007010 */  beq        $v1, $s0, .L8003E73C
    /* 2EEE8 8003E6E8 0B006228 */   slti      $v0, $v1, 0xB
    /* 2EEEC 8003E6EC 05004010 */  beqz       $v0, .L8003E704
    /* 2EEF0 8003E6F0 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 2EEF4 8003E6F4 09006010 */  beqz       $v1, .L8003E71C
    /* 2EEF8 8003E6F8 21100000 */   addu      $v0, $zero, $zero
    /* 2EEFC 8003E6FC 19FA0008 */  j          .L8003E864
    /* 2EF00 8003E700 00000000 */   nop
  .L8003E704:
    /* 2EF04 8003E704 29006210 */  beq        $v1, $v0, .L8003E7AC
    /* 2EF08 8003E708 20000224 */   addiu     $v0, $zero, 0x20
    /* 2EF0C 8003E70C 4D006210 */  beq        $v1, $v0, .L8003E844
    /* 2EF10 8003E710 21100000 */   addu      $v0, $zero, $zero
    /* 2EF14 8003E714 19FA0008 */  j          .L8003E864
    /* 2EF18 8003E718 00000000 */   nop
  .L8003E71C:
    /* 2EF1C 8003E71C 0480043C */  lui        $a0, %hi(func_8003DE18)
    /* 2EF20 8003E720 18DE8424 */  addiu      $a0, $a0, %lo(func_8003DE18)
    /* 2EF24 8003E724 0580013C */  lui        $at, %hi(D_800506D0)
    /* 2EF28 8003E728 D00620AC */  sw         $zero, %lo(D_800506D0)($at)
    /* 2EF2C 8003E72C 89FE000C */  jal        func_8003FA24
    /* 2EF30 8003E730 000030AE */   sw        $s0, 0x0($s1)
    /* 2EF34 8003E734 19FA0008 */  j          .L8003E864
    /* 2EF38 8003E738 21100000 */   addu      $v0, $zero, $zero
  .L8003E73C:
    /* 2EF3C 8003E73C 0680043C */  lui        $a0, %hi(D_80062F84)
    /* 2EF40 8003E740 842F8424 */  addiu      $a0, $a0, %lo(D_80062F84)
    /* 2EF44 8003E744 0000828C */  lw         $v0, 0x0($a0)
    /* 2EF48 8003E748 00000000 */  nop
    /* 2EF4C 8003E74C 45004014 */  bnez       $v0, .L8003E864
    /* 2EF50 8003E750 01000224 */   addiu     $v0, $zero, 0x1
    /* 2EF54 8003E754 10009024 */  addiu      $s0, $a0, 0x10
  .L8003E758:
    /* 2EF58 8003E758 0000048E */  lw         $a0, 0x0($s0)
    /* 2EF5C 8003E75C 0400058E */  lw         $a1, 0x4($s0)
    /* 2EF60 8003E760 61FD000C */  jal        lseek
    /* 2EF64 8003E764 21300000 */   addu      $a2, $zero, $zero
    /* 2EF68 8003E768 0400038E */  lw         $v1, 0x4($s0)
    /* 2EF6C 8003E76C 00000000 */  nop
    /* 2EF70 8003E770 F9FF4314 */  bne        $v0, $v1, .L8003E758
    /* 2EF74 8003E774 00000000 */   nop
    /* 2EF78 8003E778 A9FF000C */  jal        func_8003FEA4
    /* 2EF7C 8003E77C 00000000 */   nop
    /* 2EF80 8003E780 0680103C */  lui        $s0, %hi(D_80062F94)
    /* 2EF84 8003E784 942F1026 */  addiu      $s0, $s0, %lo(D_80062F94)
  .L8003E788:
    /* 2EF88 8003E788 0000048E */  lw         $a0, 0x0($s0)
    /* 2EF8C 8003E78C 0C00058E */  lw         $a1, 0xC($s0)
    /* 2EF90 8003E790 0800068E */  lw         $a2, 0x8($s0)
    /* 2EF94 8003E794 65FD000C */  jal        read
    /* 2EF98 8003E798 00000000 */   nop
    /* 2EF9C 8003E79C FAFF4014 */  bnez       $v0, .L8003E788
    /* 2EFA0 8003E7A0 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 2EFA4 8003E7A4 18FA0008 */  j          .L8003E860
    /* 2EFA8 8003E7A8 000022AE */   sw        $v0, 0x0($s1)
  .L8003E7AC:
    /* 2EFAC 8003E7AC 5700010C */  jal        func_8004015C
    /* 2EFB0 8003E7B0 00000000 */   nop
    /* 2EFB4 8003E7B4 2B004010 */  beqz       $v0, .L8003E864
    /* 2EFB8 8003E7B8 21100000 */   addu      $v0, $zero, $zero
    /* 2EFBC 8003E7BC EBFF000C */  jal        func_8003FFAC
    /* 2EFC0 8003E7C0 00000000 */   nop
    /* 2EFC4 8003E7C4 21204000 */  addu       $a0, $v0, $zero
    /* 2EFC8 8003E7C8 17008010 */  beqz       $a0, .L8003E828
    /* 2EFCC 8003E7CC 00000000 */   nop
    /* 2EFD0 8003E7D0 0580023C */  lui        $v0, %hi(D_800506D0)
    /* 2EFD4 8003E7D4 D006428C */  lw         $v0, %lo(D_800506D0)($v0)
    /* 2EFD8 8003E7D8 00000000 */  nop
    /* 2EFDC 8003E7DC 01004224 */  addiu      $v0, $v0, 0x1
    /* 2EFE0 8003E7E0 0580013C */  lui        $at, %hi(D_800506D0)
    /* 2EFE4 8003E7E4 D00622AC */  sw         $v0, %lo(D_800506D0)($at)
    /* 2EFE8 8003E7E8 04004228 */  slti       $v0, $v0, 0x4
    /* 2EFEC 8003E7EC 03004010 */  beqz       $v0, .L8003E7FC
    /* 2EFF0 8003E7F0 04000224 */   addiu     $v0, $zero, 0x4
    /* 2EFF4 8003E7F4 18FA0008 */  j          .L8003E860
    /* 2EFF8 8003E7F8 000030AE */   sw        $s0, 0x0($s1)
  .L8003E7FC:
    /* 2EFFC 8003E7FC 0A008214 */  bne        $a0, $v0, .L8003E828
    /* 2F000 8003E800 00000000 */   nop
    /* 2F004 8003E804 A9FF000C */  jal        func_8003FEA4
    /* 2F008 8003E808 00000000 */   nop
    /* 2F00C 8003E80C 0680043C */  lui        $a0, %hi(D_80062F90)
    /* 2F010 8003E810 902F848C */  lw         $a0, %lo(D_80062F90)($a0)
    /* 2F014 8003E814 6DFE000C */  jal        _card_clear
    /* 2F018 8003E818 00000000 */   nop
    /* 2F01C 8003E81C 20000224 */  addiu      $v0, $zero, 0x20
    /* 2F020 8003E820 18FA0008 */  j          .L8003E860
    /* 2F024 8003E824 000022AE */   sw        $v0, 0x0($s1)
  .L8003E828:
    /* 2F028 8003E828 06FD000C */  jal        func_8003F418
    /* 2F02C 8003E82C 00000000 */   nop
    /* 2F030 8003E830 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2F034 8003E834 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2F038 8003E838 040062AC */  sw         $v0, 0x4($v1)
    /* 2F03C 8003E83C 19FA0008 */  j          .L8003E864
    /* 2F040 8003E840 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E844:
    /* 2F044 8003E844 6600010C */  jal        Card_GetHwEventBits
    /* 2F048 8003E848 00000000 */   nop
    /* 2F04C 8003E84C 05004010 */  beqz       $v0, .L8003E864
    /* 2F050 8003E850 21100000 */   addu      $v0, $zero, $zero
    /* 2F054 8003E854 2100010C */  jal        func_80040084
    /* 2F058 8003E858 00000000 */   nop
    /* 2F05C 8003E85C 000020AE */  sw         $zero, 0x0($s1)
  .L8003E860:
    /* 2F060 8003E860 21100000 */  addu       $v0, $zero, $zero
  .L8003E864:
    /* 2F064 8003E864 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2F068 8003E868 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F06C 8003E86C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F070 8003E870 0800E003 */  jr         $ra
    /* 2F074 8003E874 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003E6C8
