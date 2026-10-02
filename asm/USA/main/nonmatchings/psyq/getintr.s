nonmatching getintr, 0x564

glabel getintr
    /* 1F5B4 8002EDB4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1F5B8 8002EDB8 0580033C */  lui        $v1, %hi(D_8004E98C)
    /* 1F5BC 8002EDBC 8CE9638C */  lw         $v1, %lo(D_8004E98C)($v1)
    /* 1F5C0 8002EDC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F5C4 8002EDC4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1F5C8 8002EDC8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1F5CC 8002EDCC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1F5D0 8002EDD0 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F5D4 8002EDD4 0580043C */  lui        $a0, %hi(D_8004E990)
    /* 1F5D8 8002EDD8 90E9848C */  lw         $a0, %lo(D_8004E990)($a0)
    /* 1F5DC 8002EDDC 00000000 */  nop
    /* 1F5E0 8002EDE0 00008290 */  lbu        $v0, 0x0($a0)
    /* 1F5E4 8002EDE4 00000000 */  nop
    /* 1F5E8 8002EDE8 07004230 */  andi       $v0, $v0, 0x7
    /* 1F5EC 8002EDEC 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 1F5F0 8002EDF0 1000A293 */  lbu        $v0, 0x10($sp)
    /* 1F5F4 8002EDF4 00000000 */  nop
    /* 1F5F8 8002EDF8 41014010 */  beqz       $v0, .L8002F300
    /* 1F5FC 8002EDFC 21880000 */   addu      $s1, $zero, $zero
    /* 1F600 8002EE00 86BB0008 */  j          .L8002EE18
    /* 1F604 8002EE04 00000000 */   nop
  .L8002EE08:
    /* 1F608 8002EE08 00008290 */  lbu        $v0, 0x0($a0)
    /* 1F60C 8002EE0C 00000000 */  nop
    /* 1F610 8002EE10 07004230 */  andi       $v0, $v0, 0x7
    /* 1F614 8002EE14 1000A2A3 */  sb         $v0, 0x10($sp)
  .L8002EE18:
    /* 1F618 8002EE18 00008290 */  lbu        $v0, 0x0($a0)
    /* 1F61C 8002EE1C 1000A393 */  lbu        $v1, 0x10($sp)
    /* 1F620 8002EE20 07004230 */  andi       $v0, $v0, 0x7
    /* 1F624 8002EE24 F8FF6214 */  bne        $v1, $v0, .L8002EE08
    /* 1F628 8002EE28 21800000 */   addu      $s0, $zero, $zero
    /* 1F62C 8002EE2C 1800A427 */  addiu      $a0, $sp, 0x18
  .L8002EE30:
    /* 1F630 8002EE30 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1F634 8002EE34 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1F638 8002EE38 00000000 */  nop
    /* 1F63C 8002EE3C 00004290 */  lbu        $v0, 0x0($v0)
    /* 1F640 8002EE40 00000000 */  nop
    /* 1F644 8002EE44 20004230 */  andi       $v0, $v0, 0x20
    /* 1F648 8002EE48 0A004010 */  beqz       $v0, .L8002EE74
    /* 1F64C 8002EE4C 21189000 */   addu      $v1, $a0, $s0
    /* 1F650 8002EE50 0580023C */  lui        $v0, %hi(D_8004E998)
    /* 1F654 8002EE54 98E9428C */  lw         $v0, %lo(D_8004E998)($v0)
    /* 1F658 8002EE58 00000000 */  nop
    /* 1F65C 8002EE5C 00004290 */  lbu        $v0, 0x0($v0)
    /* 1F660 8002EE60 01001026 */  addiu      $s0, $s0, 0x1
    /* 1F664 8002EE64 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F668 8002EE68 0800022A */  slti       $v0, $s0, 0x8
    /* 1F66C 8002EE6C F0FF4014 */  bnez       $v0, .L8002EE30
    /* 1F670 8002EE70 00000000 */   nop
  .L8002EE74:
    /* 1F674 8002EE74 0800022A */  slti       $v0, $s0, 0x8
    /* 1F678 8002EE78 08004010 */  beqz       $v0, .L8002EE9C
    /* 1F67C 8002EE7C 21180002 */   addu      $v1, $s0, $zero
    /* 1F680 8002EE80 1800A427 */  addiu      $a0, $sp, 0x18
    /* 1F684 8002EE84 21108300 */  addu       $v0, $a0, $v1
  .L8002EE88:
    /* 1F688 8002EE88 000040A0 */  sb         $zero, 0x0($v0)
    /* 1F68C 8002EE8C 01006324 */  addiu      $v1, $v1, 0x1
    /* 1F690 8002EE90 08006228 */  slti       $v0, $v1, 0x8
    /* 1F694 8002EE94 FCFF4014 */  bnez       $v0, .L8002EE88
    /* 1F698 8002EE98 21108300 */   addu      $v0, $a0, $v1
  .L8002EE9C:
    /* 1F69C 8002EE9C 0580033C */  lui        $v1, %hi(D_8004E98C)
    /* 1F6A0 8002EEA0 8CE9638C */  lw         $v1, %lo(D_8004E98C)($v1)
    /* 1F6A4 8002EEA4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F6A8 8002EEA8 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F6AC 8002EEAC 0580023C */  lui        $v0, %hi(D_8004E990)
    /* 1F6B0 8002EEB0 90E9428C */  lw         $v0, %lo(D_8004E990)($v0)
    /* 1F6B4 8002EEB4 07000324 */  addiu      $v1, $zero, 0x7
    /* 1F6B8 8002EEB8 000043A0 */  sb         $v1, 0x0($v0)
    /* 1F6BC 8002EEBC 0580023C */  lui        $v0, %hi(D_8004E99C)
    /* 1F6C0 8002EEC0 9CE9428C */  lw         $v0, %lo(D_8004E99C)($v0)
    /* 1F6C4 8002EEC4 00000000 */  nop
    /* 1F6C8 8002EEC8 000043A0 */  sb         $v1, 0x0($v0)
    /* 1F6CC 8002EECC 1000A393 */  lbu        $v1, 0x10($sp)
    /* 1F6D0 8002EED0 03000224 */  addiu      $v0, $zero, 0x3
    /* 1F6D4 8002EED4 0B006214 */  bne        $v1, $v0, .L8002EF04
    /* 1F6D8 8002EED8 00000000 */   nop
    /* 1F6DC 8002EEDC 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 1F6E0 8002EEE0 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 1F6E4 8002EEE4 00000000 */  nop
    /* 1F6E8 8002EEE8 80100200 */  sll        $v0, $v0, 2
    /* 1F6EC 8002EEEC 0580013C */  lui        $at, %hi(D_8004E88C)
    /* 1F6F0 8002EEF0 21082200 */  addu       $at, $at, $v0
    /* 1F6F4 8002EEF4 8CE8228C */  lw         $v0, %lo(D_8004E88C)($at)
    /* 1F6F8 8002EEF8 00000000 */  nop
    /* 1F6FC 8002EEFC 1A004010 */  beqz       $v0, .L8002EF68
    /* 1F700 8002EF00 00000000 */   nop
  .L8002EF04:
    /* 1F704 8002EF04 0580023C */  lui        $v0, %hi(D_8004E6D4)
    /* 1F708 8002EF08 D4E6428C */  lw         $v0, %lo(D_8004E6D4)($v0)
    /* 1F70C 8002EF0C 00000000 */  nop
    /* 1F710 8002EF10 10004230 */  andi       $v0, $v0, 0x10
    /* 1F714 8002EF14 0C004014 */  bnez       $v0, .L8002EF48
    /* 1F718 8002EF18 00000000 */   nop
    /* 1F71C 8002EF1C 1800A293 */  lbu        $v0, 0x18($sp)
    /* 1F720 8002EF20 00000000 */  nop
    /* 1F724 8002EF24 10004230 */  andi       $v0, $v0, 0x10
    /* 1F728 8002EF28 07004010 */  beqz       $v0, .L8002EF48
    /* 1F72C 8002EF2C 00000000 */   nop
    /* 1F730 8002EF30 0580023C */  lui        $v0, %hi(D_8004E6DC)
    /* 1F734 8002EF34 DCE6428C */  lw         $v0, %lo(D_8004E6DC)($v0)
    /* 1F738 8002EF38 00000000 */  nop
    /* 1F73C 8002EF3C 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F740 8002EF40 0580013C */  lui        $at, %hi(D_8004E6DC)
    /* 1F744 8002EF44 DCE622AC */  sw         $v0, %lo(D_8004E6DC)($at)
  .L8002EF48:
    /* 1F748 8002EF48 1800A293 */  lbu        $v0, 0x18($sp)
    /* 1F74C 8002EF4C 1900A393 */  lbu        $v1, 0x19($sp)
    /* 1F750 8002EF50 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1F754 8002EF54 1D005130 */  andi       $s1, $v0, 0x1D
    /* 1F758 8002EF58 0580013C */  lui        $at, %hi(D_8004E6D4)
    /* 1F75C 8002EF5C D4E622AC */  sw         $v0, %lo(D_8004E6D4)($at)
    /* 1F760 8002EF60 0580013C */  lui        $at, %hi(D_8004E6D8)
    /* 1F764 8002EF64 D8E623AC */  sw         $v1, %lo(D_8004E6D8)($at)
  .L8002EF68:
    /* 1F768 8002EF68 1000A393 */  lbu        $v1, 0x10($sp)
    /* 1F76C 8002EF6C 05000224 */  addiu      $v0, $zero, 0x5
    /* 1F770 8002EF70 1D006214 */  bne        $v1, $v0, .L8002EFE8
    /* 1F774 8002EF74 00000000 */   nop
    /* 1F778 8002EF78 0580023C */  lui        $v0, %hi(D_8004E6D0)
    /* 1F77C 8002EF7C D0E6428C */  lw         $v0, %lo(D_8004E6D0)($v0)
    /* 1F780 8002EF80 00000000 */  nop
    /* 1F784 8002EF84 03004228 */  slti       $v0, $v0, 0x3
    /* 1F788 8002EF88 17004014 */  bnez       $v0, .L8002EFE8
    /* 1F78C 8002EF8C 00000000 */   nop
    /* 1F790 8002EF90 0180043C */  lui        $a0, %hi(D_8001087C)
    /* 1F794 8002EF94 05A8000C */  jal        printf
    /* 1F798 8002EF98 7C088424 */   addiu     $a0, $a0, %lo(D_8001087C)
    /* 1F79C 8002EF9C 0580023C */  lui        $v0, %hi(D_8004E6D0)
    /* 1F7A0 8002EFA0 D0E6428C */  lw         $v0, %lo(D_8004E6D0)($v0)
    /* 1F7A4 8002EFA4 00000000 */  nop
    /* 1F7A8 8002EFA8 03004228 */  slti       $v0, $v0, 0x3
    /* 1F7AC 8002EFAC 0E004014 */  bnez       $v0, .L8002EFE8
    /* 1F7B0 8002EFB0 00000000 */   nop
    /* 1F7B4 8002EFB4 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 1F7B8 8002EFB8 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 1F7BC 8002EFBC 0580063C */  lui        $a2, %hi(D_8004E6D4)
    /* 1F7C0 8002EFC0 D4E6C68C */  lw         $a2, %lo(D_8004E6D4)($a2)
    /* 1F7C4 8002EFC4 0580073C */  lui        $a3, %hi(D_8004E6D8)
    /* 1F7C8 8002EFC8 D8E6E78C */  lw         $a3, %lo(D_8004E6D8)($a3)
    /* 1F7CC 8002EFCC 80100200 */  sll        $v0, $v0, 2
    /* 1F7D0 8002EFD0 0580053C */  lui        $a1, %hi(D_8004E6EC)
    /* 1F7D4 8002EFD4 2128A200 */  addu       $a1, $a1, $v0
    /* 1F7D8 8002EFD8 ECE6A58C */  lw         $a1, %lo(D_8004E6EC)($a1)
    /* 1F7DC 8002EFDC 0180043C */  lui        $a0, %hi(D_80010888)
    /* 1F7E0 8002EFE0 05A8000C */  jal        printf
    /* 1F7E4 8002EFE4 88088424 */   addiu     $a0, $a0, %lo(D_80010888)
  .L8002EFE8:
    /* 1F7E8 8002EFE8 1000A293 */  lbu        $v0, 0x10($sp)
    /* 1F7EC 8002EFEC 00000000 */  nop
    /* 1F7F0 8002EFF0 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 1F7F4 8002EFF4 0500622C */  sltiu      $v0, $v1, 0x5
    /* 1F7F8 8002EFF8 BA004010 */  beqz       $v0, .L8002F2E4
    /* 1F7FC 8002EFFC 80100300 */   sll       $v0, $v1, 2
    /* 1F800 8002F000 0180013C */  lui        $at, %hi(jtbl_800108C4)
    /* 1F804 8002F004 21082200 */  addu       $at, $at, $v0
    /* 1F808 8002F008 C408228C */  lw         $v0, %lo(jtbl_800108C4)($at)
    /* 1F80C 8002F00C 00000000 */  nop
    /* 1F810 8002F010 08004000 */  jr         $v0
    /* 1F814 8002F014 00000000 */   nop
  jlabel .L8002F018
    /* 1F818 8002F018 12002012 */  beqz       $s1, .L8002F064
    /* 1F81C 8002F01C 05000224 */   addiu     $v0, $zero, 0x5
    /* 1F820 8002F020 0580033C */  lui        $v1, %hi(D_8004E9A4)
    /* 1F824 8002F024 A4E96324 */  addiu      $v1, $v1, %lo(D_8004E9A4)
    /* 1F828 8002F028 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F82C 8002F02C 0680033C */  lui        $v1, %hi(D_80061B68)
    /* 1F830 8002F030 681B6324 */  addiu      $v1, $v1, %lo(D_80061B68)
    /* 1F834 8002F034 49006010 */  beqz       $v1, .L8002F15C
    /* 1F838 8002F038 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1F83C 8002F03C 07000424 */  addiu      $a0, $zero, 0x7
    /* 1F840 8002F040 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F044:
    /* 1F844 8002F044 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1F848 8002F048 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1F84C 8002F04C FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F850 8002F050 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F854 8002F054 FBFF8614 */  bne        $a0, $a2, .L8002F044
    /* 1F858 8002F058 01006324 */   addiu     $v1, $v1, 0x1
    /* 1F85C 8002F05C C1BC0008 */  j          .L8002F304
    /* 1F860 8002F060 02000224 */   addiu     $v0, $zero, 0x2
  .L8002F064:
    /* 1F864 8002F064 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 1F868 8002F068 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 1F86C 8002F06C 00000000 */  nop
    /* 1F870 8002F070 80100200 */  sll        $v0, $v0, 2
    /* 1F874 8002F074 0580013C */  lui        $at, %hi(D_8004E78C)
    /* 1F878 8002F078 21082200 */  addu       $at, $at, $v0
    /* 1F87C 8002F07C 8CE7228C */  lw         $v0, %lo(D_8004E78C)($at)
    /* 1F880 8002F080 00000000 */  nop
    /* 1F884 8002F084 12004010 */  beqz       $v0, .L8002F0D0
    /* 1F888 8002F088 03000224 */   addiu     $v0, $zero, 0x3
    /* 1F88C 8002F08C 0580033C */  lui        $v1, %hi(D_8004E9A4)
    /* 1F890 8002F090 A4E96324 */  addiu      $v1, $v1, %lo(D_8004E9A4)
    /* 1F894 8002F094 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F898 8002F098 0680033C */  lui        $v1, %hi(D_80061B68)
    /* 1F89C 8002F09C 681B6324 */  addiu      $v1, $v1, %lo(D_80061B68)
    /* 1F8A0 8002F0A0 09006010 */  beqz       $v1, .L8002F0C8
    /* 1F8A4 8002F0A4 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1F8A8 8002F0A8 07000424 */  addiu      $a0, $zero, 0x7
    /* 1F8AC 8002F0AC FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F0B0:
    /* 1F8B0 8002F0B0 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1F8B4 8002F0B4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1F8B8 8002F0B8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F8BC 8002F0BC 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F8C0 8002F0C0 FBFF8614 */  bne        $a0, $a2, .L8002F0B0
    /* 1F8C4 8002F0C4 01006324 */   addiu     $v1, $v1, 0x1
  .L8002F0C8:
    /* 1F8C8 8002F0C8 C1BC0008 */  j          .L8002F304
    /* 1F8CC 8002F0CC 01000224 */   addiu     $v0, $zero, 0x1
  .L8002F0D0:
    /* 1F8D0 8002F0D0 0580033C */  lui        $v1, %hi(D_8004E9A4)
    /* 1F8D4 8002F0D4 A4E96324 */  addiu      $v1, $v1, %lo(D_8004E9A4)
    /* 1F8D8 8002F0D8 02000224 */  addiu      $v0, $zero, 0x2
    /* 1F8DC 8002F0DC 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F8E0 8002F0E0 0680033C */  lui        $v1, %hi(D_80061B68)
    /* 1F8E4 8002F0E4 681B6324 */  addiu      $v1, $v1, %lo(D_80061B68)
    /* 1F8E8 8002F0E8 1C006010 */  beqz       $v1, .L8002F15C
    /* 1F8EC 8002F0EC 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1F8F0 8002F0F0 07000424 */  addiu      $a0, $zero, 0x7
    /* 1F8F4 8002F0F4 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F0F8:
    /* 1F8F8 8002F0F8 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1F8FC 8002F0FC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1F900 8002F100 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F904 8002F104 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F908 8002F108 FBFF8614 */  bne        $a0, $a2, .L8002F0F8
    /* 1F90C 8002F10C 01006324 */   addiu     $v1, $v1, 0x1
    /* 1F910 8002F110 C1BC0008 */  j          .L8002F304
    /* 1F914 8002F114 02000224 */   addiu     $v0, $zero, 0x2
  jlabel .L8002F118
    /* 1F918 8002F118 02002012 */  beqz       $s1, .L8002F124
    /* 1F91C 8002F11C 02000224 */   addiu     $v0, $zero, 0x2
    /* 1F920 8002F120 05000224 */  addiu      $v0, $zero, 0x5
  .L8002F124:
    /* 1F924 8002F124 0580013C */  lui        $at, %hi(D_8004E9A4)
    /* 1F928 8002F128 A4E922A0 */  sb         $v0, %lo(D_8004E9A4)($at)
    /* 1F92C 8002F12C 0680033C */  lui        $v1, %hi(D_80061B68)
    /* 1F930 8002F130 681B6324 */  addiu      $v1, $v1, %lo(D_80061B68)
    /* 1F934 8002F134 09006010 */  beqz       $v1, .L8002F15C
    /* 1F938 8002F138 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1F93C 8002F13C 07000424 */  addiu      $a0, $zero, 0x7
    /* 1F940 8002F140 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F144:
    /* 1F944 8002F144 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1F948 8002F148 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1F94C 8002F14C FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F950 8002F150 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F954 8002F154 FBFF8614 */  bne        $a0, $a2, .L8002F144
    /* 1F958 8002F158 01006324 */   addiu     $v1, $v1, 0x1
  .L8002F15C:
    /* 1F95C 8002F15C C1BC0008 */  j          .L8002F304
    /* 1F960 8002F160 02000224 */   addiu     $v0, $zero, 0x2
  jlabel .L8002F164
    /* 1F964 8002F164 04002012 */  beqz       $s1, .L8002F178
    /* 1F968 8002F168 01000224 */   addiu     $v0, $zero, 0x1
    /* 1F96C 8002F16C 02000216 */  bne        $s0, $v0, .L8002F178
    /* 1F970 8002F170 00000000 */   nop
    /* 1F974 8002F174 21880000 */  addu       $s1, $zero, $zero
  .L8002F178:
    /* 1F978 8002F178 02002012 */  beqz       $s1, .L8002F184
    /* 1F97C 8002F17C 01000324 */   addiu     $v1, $zero, 0x1
    /* 1F980 8002F180 05000324 */  addiu      $v1, $zero, 0x5
  .L8002F184:
    /* 1F984 8002F184 0580023C */  lui        $v0, %hi(D_8004E9A4)
    /* 1F988 8002F188 A4E94224 */  addiu      $v0, $v0, %lo(D_8004E9A4)
    /* 1F98C 8002F18C 010043A0 */  sb         $v1, 0x1($v0)
    /* 1F990 8002F190 0680033C */  lui        $v1, %hi(D_80061B70)
    /* 1F994 8002F194 701B6324 */  addiu      $v1, $v1, %lo(D_80061B70)
    /* 1F998 8002F198 09006010 */  beqz       $v1, .L8002F1C0
    /* 1F99C 8002F19C 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1F9A0 8002F1A0 07000424 */  addiu      $a0, $zero, 0x7
    /* 1F9A4 8002F1A4 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F1A8:
    /* 1F9A8 8002F1A8 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1F9AC 8002F1AC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1F9B0 8002F1B0 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1F9B4 8002F1B4 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F9B8 8002F1B8 FBFF8614 */  bne        $a0, $a2, .L8002F1A8
    /* 1F9BC 8002F1BC 01006324 */   addiu     $v1, $v1, 0x1
  .L8002F1C0:
    /* 1F9C0 8002F1C0 0580023C */  lui        $v0, %hi(D_8004E98C)
    /* 1F9C4 8002F1C4 8CE9428C */  lw         $v0, %lo(D_8004E98C)($v0)
    /* 1F9C8 8002F1C8 00000000 */  nop
    /* 1F9CC 8002F1CC 000040A0 */  sb         $zero, 0x0($v0)
    /* 1F9D0 8002F1D0 0580033C */  lui        $v1, %hi(D_8004E990)
    /* 1F9D4 8002F1D4 90E9638C */  lw         $v1, %lo(D_8004E990)($v1)
    /* 1F9D8 8002F1D8 04000224 */  addiu      $v0, $zero, 0x4
    /* 1F9DC 8002F1DC C1BC0008 */  j          .L8002F304
    /* 1F9E0 8002F1E0 000060A0 */   sb        $zero, 0x0($v1)
  jlabel .L8002F1E4
    /* 1F9E4 8002F1E4 0680043C */  lui        $a0, %hi(D_80061B78)
    /* 1F9E8 8002F1E8 781B8424 */  addiu      $a0, $a0, %lo(D_80061B78)
    /* 1F9EC 8002F1EC 0580023C */  lui        $v0, %hi(D_8004E9A4)
    /* 1F9F0 8002F1F0 A4E94224 */  addiu      $v0, $v0, %lo(D_8004E9A4)
    /* 1F9F4 8002F1F4 04000324 */  addiu      $v1, $zero, 0x4
    /* 1F9F8 8002F1F8 020043A0 */  sb         $v1, 0x2($v0)
    /* 1F9FC 8002F1FC 02004390 */  lbu        $v1, 0x2($v0)
    /* 1FA00 8002F200 1800A527 */  addiu      $a1, $sp, 0x18
    /* 1FA04 8002F204 010043A0 */  sb         $v1, 0x1($v0)
    /* 1FA08 8002F208 08008010 */  beqz       $a0, .L8002F22C
    /* 1FA0C 8002F20C 07000324 */   addiu     $v1, $zero, 0x7
    /* 1FA10 8002F210 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F214:
    /* 1FA14 8002F214 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1FA18 8002F218 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1FA1C 8002F21C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1FA20 8002F220 000082A0 */  sb         $v0, 0x0($a0)
    /* 1FA24 8002F224 FBFF6614 */  bne        $v1, $a2, .L8002F214
    /* 1FA28 8002F228 01008424 */   addiu     $a0, $a0, 0x1
  .L8002F22C:
    /* 1FA2C 8002F22C 0680033C */  lui        $v1, %hi(D_80061B70)
    /* 1FA30 8002F230 701B6324 */  addiu      $v1, $v1, %lo(D_80061B70)
    /* 1FA34 8002F234 09006010 */  beqz       $v1, .L8002F25C
    /* 1FA38 8002F238 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1FA3C 8002F23C 07000424 */  addiu      $a0, $zero, 0x7
    /* 1FA40 8002F240 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F244:
    /* 1FA44 8002F244 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1FA48 8002F248 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1FA4C 8002F24C FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1FA50 8002F250 000062A0 */  sb         $v0, 0x0($v1)
    /* 1FA54 8002F254 FBFF8614 */  bne        $a0, $a2, .L8002F244
    /* 1FA58 8002F258 01006324 */   addiu     $v1, $v1, 0x1
  .L8002F25C:
    /* 1FA5C 8002F25C C1BC0008 */  j          .L8002F304
    /* 1FA60 8002F260 04000224 */   addiu     $v0, $zero, 0x4
  jlabel .L8002F264
    /* 1FA64 8002F264 0680043C */  lui        $a0, %hi(D_80061B68)
    /* 1FA68 8002F268 681B8424 */  addiu      $a0, $a0, %lo(D_80061B68)
    /* 1FA6C 8002F26C 0580023C */  lui        $v0, %hi(D_8004E9A4)
    /* 1FA70 8002F270 A4E94224 */  addiu      $v0, $v0, %lo(D_8004E9A4)
    /* 1FA74 8002F274 05000324 */  addiu      $v1, $zero, 0x5
    /* 1FA78 8002F278 010043A0 */  sb         $v1, 0x1($v0)
    /* 1FA7C 8002F27C 01004390 */  lbu        $v1, 0x1($v0)
    /* 1FA80 8002F280 1800A527 */  addiu      $a1, $sp, 0x18
    /* 1FA84 8002F284 000043A0 */  sb         $v1, 0x0($v0)
    /* 1FA88 8002F288 08008010 */  beqz       $a0, .L8002F2AC
    /* 1FA8C 8002F28C 07000324 */   addiu     $v1, $zero, 0x7
    /* 1FA90 8002F290 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F294:
    /* 1FA94 8002F294 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1FA98 8002F298 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1FA9C 8002F29C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1FAA0 8002F2A0 000082A0 */  sb         $v0, 0x0($a0)
    /* 1FAA4 8002F2A4 FBFF6614 */  bne        $v1, $a2, .L8002F294
    /* 1FAA8 8002F2A8 01008424 */   addiu     $a0, $a0, 0x1
  .L8002F2AC:
    /* 1FAAC 8002F2AC 0680033C */  lui        $v1, %hi(D_80061B70)
    /* 1FAB0 8002F2B0 701B6324 */  addiu      $v1, $v1, %lo(D_80061B70)
    /* 1FAB4 8002F2B4 09006010 */  beqz       $v1, .L8002F2DC
    /* 1FAB8 8002F2B8 1800A527 */   addiu     $a1, $sp, 0x18
    /* 1FABC 8002F2BC 07000424 */  addiu      $a0, $zero, 0x7
    /* 1FAC0 8002F2C0 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8002F2C4:
    /* 1FAC4 8002F2C4 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1FAC8 8002F2C8 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1FACC 8002F2CC FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 1FAD0 8002F2D0 000062A0 */  sb         $v0, 0x0($v1)
    /* 1FAD4 8002F2D4 FBFF8614 */  bne        $a0, $a2, .L8002F2C4
    /* 1FAD8 8002F2D8 01006324 */   addiu     $v1, $v1, 0x1
  .L8002F2DC:
    /* 1FADC 8002F2DC C1BC0008 */  j          .L8002F304
    /* 1FAE0 8002F2E0 06000224 */   addiu     $v0, $zero, 0x6
  .L8002F2E4:
    /* 1FAE4 8002F2E4 0180043C */  lui        $a0, %hi(D_800108A4)
    /* 1FAE8 8002F2E8 CDC0000C */  jal        Debug_PutString
    /* 1FAEC 8002F2EC A4088424 */   addiu     $a0, $a0, %lo(D_800108A4)
    /* 1FAF0 8002F2F0 1000A593 */  lbu        $a1, 0x10($sp)
    /* 1FAF4 8002F2F4 0180043C */  lui        $a0, %hi(D_800108B8)
    /* 1FAF8 8002F2F8 05A8000C */  jal        printf
    /* 1FAFC 8002F2FC B8088424 */   addiu     $a0, $a0, %lo(D_800108B8)
  .L8002F300:
    /* 1FB00 8002F300 21100000 */  addu       $v0, $zero, $zero
  .L8002F304:
    /* 1FB04 8002F304 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1FB08 8002F308 2400B18F */  lw         $s1, 0x24($sp)
    /* 1FB0C 8002F30C 2000B08F */  lw         $s0, 0x20($sp)
    /* 1FB10 8002F310 0800E003 */  jr         $ra
    /* 1FB14 8002F314 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel getintr
