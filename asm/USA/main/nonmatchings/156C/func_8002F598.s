nonmatching func_8002F598, 0x2C8

glabel func_8002F598
    /* 1FD98 8002F598 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 1FD9C 8002F59C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 1FDA0 8002F5A0 21B88000 */  addu       $s7, $a0, $zero
    /* 1FDA4 8002F5A4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1FDA8 8002F5A8 2198A000 */  addu       $s3, $a1, $zero
    /* 1FDAC 8002F5AC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1FDB0 8002F5B0 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 1FDB4 8002F5B4 3800BEAF */  sw         $fp, 0x38($sp)
    /* 1FDB8 8002F5B8 3000B6AF */  sw         $s6, 0x30($sp)
    /* 1FDBC 8002F5BC 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 1FDC0 8002F5C0 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1FDC4 8002F5C4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1FDC8 8002F5C8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1FDCC 8002F5CC ADC2000C */  jal        func_80030AB4
    /* 1FDD0 8002F5D0 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1FDD4 8002F5D4 05801E3C */  lui        $fp, %hi(D_8004E6EC)
    /* 1FDD8 8002F5D8 ECE6DE27 */  addiu      $fp, $fp, %lo(D_8004E6EC)
    /* 1FDDC 8002F5DC 0580153C */  lui        $s5, %hi(D_8004E76C)
    /* 1FDE0 8002F5E0 6CE7B526 */  addiu      $s5, $s5, %lo(D_8004E76C)
    /* 1FDE4 8002F5E4 0580123C */  lui        $s2, %hi(D_8004E9A4)
    /* 1FDE8 8002F5E8 A4E95226 */  addiu      $s2, $s2, %lo(D_8004E9A4)
    /* 1FDEC 8002F5EC 01005626 */  addiu      $s6, $s2, 0x1
    /* 1FDF0 8002F5F0 02005426 */  addiu      $s4, $s2, 0x2
    /* 1FDF4 8002F5F4 C0034224 */  addiu      $v0, $v0, 0x3C0
    /* 1FDF8 8002F5F8 0680013C */  lui        $at, %hi(D_80061B80)
    /* 1FDFC 8002F5FC 801B22AC */  sw         $v0, %lo(D_80061B80)($at)
    /* 1FE00 8002F600 0180023C */  lui        $v0, %hi(D_800108E0)
    /* 1FE04 8002F604 E0084224 */  addiu      $v0, $v0, %lo(D_800108E0)
    /* 1FE08 8002F608 0680013C */  lui        $at, %hi(D_80061B84)
    /* 1FE0C 8002F60C 841B20AC */  sw         $zero, %lo(D_80061B84)($at)
    /* 1FE10 8002F610 0680013C */  lui        $at, %hi(D_80061B88)
    /* 1FE14 8002F614 881B22AC */  sw         $v0, %lo(D_80061B88)($at)
  .L8002F618:
    /* 1FE18 8002F618 ADC2000C */  jal        func_80030AB4
    /* 1FE1C 8002F61C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1FE20 8002F620 0680033C */  lui        $v1, %hi(D_80061B80)
    /* 1FE24 8002F624 801B638C */  lw         $v1, %lo(D_80061B80)($v1)
    /* 1FE28 8002F628 00000000 */  nop
    /* 1FE2C 8002F62C 2A186200 */  slt        $v1, $v1, $v0
    /* 1FE30 8002F630 0C006014 */  bnez       $v1, .L8002F664
    /* 1FE34 8002F634 00000000 */   nop
    /* 1FE38 8002F638 0680023C */  lui        $v0, %hi(D_80061B84)
    /* 1FE3C 8002F63C 841B428C */  lw         $v0, %lo(D_80061B84)($v0)
    /* 1FE40 8002F640 00000000 */  nop
    /* 1FE44 8002F644 21184000 */  addu       $v1, $v0, $zero
    /* 1FE48 8002F648 01004224 */  addiu      $v0, $v0, 0x1
    /* 1FE4C 8002F64C 0680013C */  lui        $at, %hi(D_80061B84)
    /* 1FE50 8002F650 841B22AC */  sw         $v0, %lo(D_80061B84)($at)
    /* 1FE54 8002F654 3C00023C */  lui        $v0, (0x3C0000 >> 16)
    /* 1FE58 8002F658 2A104300 */  slt        $v0, $v0, $v1
    /* 1FE5C 8002F65C 1B004010 */  beqz       $v0, .L8002F6CC
    /* 1FE60 8002F660 00000000 */   nop
  .L8002F664:
    /* 1FE64 8002F664 0180043C */  lui        $a0, %hi(D_80010850)
    /* 1FE68 8002F668 CDC0000C */  jal        Debug_PutString
    /* 1FE6C 8002F66C 50088424 */   addiu     $a0, $a0, %lo(D_80010850)
    /* 1FE70 8002F670 00004492 */  lbu        $a0, 0x0($s2)
    /* 1FE74 8002F674 01004292 */  lbu        $v0, 0x1($s2)
    /* 1FE78 8002F678 0680053C */  lui        $a1, %hi(D_80061B88)
    /* 1FE7C 8002F67C 881BA58C */  lw         $a1, %lo(D_80061B88)($a1)
    /* 1FE80 8002F680 80100200 */  sll        $v0, $v0, 2
    /* 1FE84 8002F684 21105500 */  addu       $v0, $v0, $s5
    /* 1FE88 8002F688 80200400 */  sll        $a0, $a0, 2
    /* 1FE8C 8002F68C 0000438C */  lw         $v1, 0x0($v0)
    /* 1FE90 8002F690 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 1FE94 8002F694 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 1FE98 8002F698 21209500 */  addu       $a0, $a0, $s5
    /* 1FE9C 8002F69C 80100200 */  sll        $v0, $v0, 2
    /* 1FEA0 8002F6A0 21105E00 */  addu       $v0, $v0, $fp
    /* 1FEA4 8002F6A4 1000A3AF */  sw         $v1, 0x10($sp)
    /* 1FEA8 8002F6A8 0000468C */  lw         $a2, 0x0($v0)
    /* 1FEAC 8002F6AC 0000878C */  lw         $a3, 0x0($a0)
    /* 1FEB0 8002F6B0 0180043C */  lui        $a0, %hi(D_80010860)
    /* 1FEB4 8002F6B4 05A8000C */  jal        printf
    /* 1FEB8 8002F6B8 60088424 */   addiu     $a0, $a0, %lo(D_80010860)
    /* 1FEBC 8002F6BC 3DBF000C */  jal        CD_flush
    /* 1FEC0 8002F6C0 00000000 */   nop
    /* 1FEC4 8002F6C4 B4BD0008 */  j          .L8002F6D0
    /* 1FEC8 8002F6C8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002F6CC:
    /* 1FECC 8002F6CC 21100000 */  addu       $v0, $zero, $zero
  .L8002F6D0:
    /* 1FED0 8002F6D0 57004014 */  bnez       $v0, .L8002F830
    /* 1FED4 8002F6D4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1FED8 8002F6D8 8AC3000C */  jal        CheckCallback
    /* 1FEDC 8002F6DC 00000000 */   nop
    /* 1FEE0 8002F6E0 29004010 */  beqz       $v0, .L8002F788
    /* 1FEE4 8002F6E4 00000000 */   nop
    /* 1FEE8 8002F6E8 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1FEEC 8002F6EC 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1FEF0 8002F6F0 00000000 */  nop
    /* 1FEF4 8002F6F4 00004290 */  lbu        $v0, 0x0($v0)
    /* 1FEF8 8002F6F8 00000000 */  nop
    /* 1FEFC 8002F6FC 03005130 */  andi       $s1, $v0, 0x3
  .L8002F700:
    /* 1FF00 8002F700 6DBB000C */  jal        func_8002EDB4
    /* 1FF04 8002F704 00000000 */   nop
    /* 1FF08 8002F708 21804000 */  addu       $s0, $v0, $zero
    /* 1FF0C 8002F70C 1A000012 */  beqz       $s0, .L8002F778
    /* 1FF10 8002F710 04000232 */   andi      $v0, $s0, 0x4
    /* 1FF14 8002F714 0B004010 */  beqz       $v0, .L8002F744
    /* 1FF18 8002F718 02000232 */   andi      $v0, $s0, 0x2
    /* 1FF1C 8002F71C 0580023C */  lui        $v0, %hi(D_8004E6CC)
    /* 1FF20 8002F720 CCE6428C */  lw         $v0, %lo(D_8004E6CC)($v0)
    /* 1FF24 8002F724 00000000 */  nop
    /* 1FF28 8002F728 05004010 */  beqz       $v0, .L8002F740
    /* 1FF2C 8002F72C 00000000 */   nop
    /* 1FF30 8002F730 0000C492 */  lbu        $a0, 0x0($s6)
    /* 1FF34 8002F734 0680053C */  lui        $a1, %hi(D_80061B70)
    /* 1FF38 8002F738 09F84000 */  jalr       $v0
    /* 1FF3C 8002F73C 701BA524 */   addiu     $a1, $a1, %lo(D_80061B70)
  .L8002F740:
    /* 1FF40 8002F740 02000232 */  andi       $v0, $s0, 0x2
  .L8002F744:
    /* 1FF44 8002F744 EEFF4010 */  beqz       $v0, .L8002F700
    /* 1FF48 8002F748 00000000 */   nop
    /* 1FF4C 8002F74C 0580023C */  lui        $v0, %hi(D_8004E6C8)
    /* 1FF50 8002F750 C8E6428C */  lw         $v0, %lo(D_8004E6C8)($v0)
    /* 1FF54 8002F754 00000000 */  nop
    /* 1FF58 8002F758 E9FF4010 */  beqz       $v0, .L8002F700
    /* 1FF5C 8002F75C 00000000 */   nop
    /* 1FF60 8002F760 00004492 */  lbu        $a0, 0x0($s2)
    /* 1FF64 8002F764 0680053C */  lui        $a1, %hi(D_80061B68)
    /* 1FF68 8002F768 09F84000 */  jalr       $v0
    /* 1FF6C 8002F76C 681BA524 */   addiu     $a1, $a1, %lo(D_80061B68)
    /* 1FF70 8002F770 C0BD0008 */  j          .L8002F700
    /* 1FF74 8002F774 00000000 */   nop
  .L8002F778:
    /* 1FF78 8002F778 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1FF7C 8002F77C 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1FF80 8002F780 00000000 */  nop
    /* 1FF84 8002F784 000051A0 */  sb         $s1, 0x0($v0)
  .L8002F788:
    /* 1FF88 8002F788 00008292 */  lbu        $v0, 0x0($s4)
    /* 1FF8C 8002F78C 00000000 */  nop
    /* 1FF90 8002F790 FF004630 */  andi       $a2, $v0, 0xFF
    /* 1FF94 8002F794 1000C010 */  beqz       $a2, .L8002F7D8
    /* 1FF98 8002F798 00000000 */   nop
    /* 1FF9C 8002F79C 020040A2 */  sb         $zero, 0x2($s2)
    /* 1FFA0 8002F7A0 0680043C */  lui        $a0, %hi(D_80061B78)
    /* 1FFA4 8002F7A4 781B8424 */  addiu      $a0, $a0, %lo(D_80061B78)
    /* 1FFA8 8002F7A8 1D006012 */  beqz       $s3, .L8002F820
    /* 1FFAC 8002F7AC 21286002 */   addu      $a1, $s3, $zero
    /* 1FFB0 8002F7B0 07000324 */  addiu      $v1, $zero, 0x7
    /* 1FFB4 8002F7B4 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8002F7B8:
    /* 1FFB8 8002F7B8 00008290 */  lbu        $v0, 0x0($a0)
    /* 1FFBC 8002F7BC 01008424 */  addiu      $a0, $a0, 0x1
    /* 1FFC0 8002F7C0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1FFC4 8002F7C4 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 1FFC8 8002F7C8 FBFF6714 */  bne        $v1, $a3, .L8002F7B8
    /* 1FFCC 8002F7CC 0100A524 */   addiu     $a1, $a1, 0x1
    /* 1FFD0 8002F7D0 0CBE0008 */  j          .L8002F830
    /* 1FFD4 8002F7D4 2110C000 */   addu      $v0, $a2, $zero
  .L8002F7D8:
    /* 1FFD8 8002F7D8 FFFF8292 */  lbu        $v0, -0x1($s4)
    /* 1FFDC 8002F7DC 00000000 */  nop
    /* 1FFE0 8002F7E0 FF004630 */  andi       $a2, $v0, 0xFF
    /* 1FFE4 8002F7E4 1000C010 */  beqz       $a2, .L8002F828
    /* 1FFE8 8002F7E8 00000000 */   nop
    /* 1FFEC 8002F7EC 010040A2 */  sb         $zero, 0x1($s2)
    /* 1FFF0 8002F7F0 21286002 */  addu       $a1, $s3, $zero
    /* 1FFF4 8002F7F4 0680043C */  lui        $a0, %hi(D_80061B70)
    /* 1FFF8 8002F7F8 701B8424 */  addiu      $a0, $a0, %lo(D_80061B70)
    /* 1FFFC 8002F7FC 0800A010 */  beqz       $a1, .L8002F820
    /* 20000 8002F800 07000324 */   addiu     $v1, $zero, 0x7
    /* 20004 8002F804 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8002F808:
    /* 20008 8002F808 00008290 */  lbu        $v0, 0x0($a0)
    /* 2000C 8002F80C 01008424 */  addiu      $a0, $a0, 0x1
    /* 20010 8002F810 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 20014 8002F814 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 20018 8002F818 FBFF6714 */  bne        $v1, $a3, .L8002F808
    /* 2001C 8002F81C 0100A524 */   addiu     $a1, $a1, 0x1
  .L8002F820:
    /* 20020 8002F820 0CBE0008 */  j          .L8002F830
    /* 20024 8002F824 2110C000 */   addu      $v0, $a2, $zero
  .L8002F828:
    /* 20028 8002F828 7BFFE012 */  beqz       $s7, .L8002F618
    /* 2002C 8002F82C 21100000 */   addu      $v0, $zero, $zero
  .L8002F830:
    /* 20030 8002F830 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 20034 8002F834 3800BE8F */  lw         $fp, 0x38($sp)
    /* 20038 8002F838 3400B78F */  lw         $s7, 0x34($sp)
    /* 2003C 8002F83C 3000B68F */  lw         $s6, 0x30($sp)
    /* 20040 8002F840 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 20044 8002F844 2800B48F */  lw         $s4, 0x28($sp)
    /* 20048 8002F848 2400B38F */  lw         $s3, 0x24($sp)
    /* 2004C 8002F84C 2000B28F */  lw         $s2, 0x20($sp)
    /* 20050 8002F850 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 20054 8002F854 1800B08F */  lw         $s0, 0x18($sp)
    /* 20058 8002F858 0800E003 */  jr         $ra
    /* 2005C 8002F85C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8002F598
