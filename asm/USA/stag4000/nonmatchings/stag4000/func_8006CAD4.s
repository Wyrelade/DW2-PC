nonmatching func_8006CAD4, 0x248

glabel func_8006CAD4
    /* 9774 8006CAD4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9778 8006CAD8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 977C 8006CADC 21908000 */  addu       $s2, $a0, $zero
    /* 9780 8006CAE0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 9784 8006CAE4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 9788 8006CAE8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 978C 8006CAEC 2C00518E */  lw         $s1, 0x2C($s2)
    /* 9790 8006CAF0 00000000 */  nop
    /* 9794 8006CAF4 2C00308E */  lw         $s0, 0x2C($s1)
    /* 9798 8006CAF8 00000000 */  nop
    /* 979C 8006CAFC 18000486 */  lh         $a0, 0x18($s0)
    /* 97A0 8006CB00 1A000586 */  lh         $a1, 0x1A($s0)
    /* 97A4 8006CB04 3FC2010C */  jal        func_800708FC
    /* 97A8 8006CB08 21300000 */   addu      $a2, $zero, $zero
    /* 97AC 8006CB0C 0000028E */  lw         $v0, 0x0($s0)
    /* 97B0 8006CB10 00000000 */  nop
    /* 97B4 8006CB14 00104230 */  andi       $v0, $v0, 0x1000
    /* 97B8 8006CB18 07004010 */  beqz       $v0, .L8006CB38
    /* 97BC 8006CB1C FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 97C0 8006CB20 18000486 */  lh         $a0, 0x18($s0)
    /* 97C4 8006CB24 1A000586 */  lh         $a1, 0x1A($s0)
    /* 97C8 8006CB28 08000292 */  lbu        $v0, 0x8($s0)
    /* 97CC 8006CB2C 2138C000 */  addu       $a3, $a2, $zero
    /* 97D0 8006CB30 FDBA010C */  jal        func_8006EBF4
    /* 97D4 8006CB34 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006CB38:
    /* 97D8 8006CB38 1000028E */  lw         $v0, 0x10($s0)
    /* 97DC 8006CB3C 00000000 */  nop
    /* 97E0 8006CB40 01004590 */  lbu        $a1, 0x1($v0)
    /* 97E4 8006CB44 21202002 */  addu       $a0, $s1, $zero
    /* 97E8 8006CB48 F3B1010C */  jal        func_8006C7CC
    /* 97EC 8006CB4C FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 97F0 8006CB50 1400438E */  lw         $v1, 0x14($s2)
    /* 97F4 8006CB54 00000000 */  nop
    /* 97F8 8006CB58 0700622C */  sltiu      $v0, $v1, 0x7
    /* 97FC 8006CB5C 08004010 */  beqz       $v0, .L8006CB80
    /* 9800 8006CB60 0680023C */   lui       $v0, %hi(jtbl_8006354C)
    /* 9804 8006CB64 4C354224 */  addiu      $v0, $v0, %lo(jtbl_8006354C)
    /* 9808 8006CB68 80180300 */  sll        $v1, $v1, 2
    /* 980C 8006CB6C 21186200 */  addu       $v1, $v1, $v0
    /* 9810 8006CB70 0000628C */  lw         $v0, 0x0($v1)
    /* 9814 8006CB74 00000000 */  nop
    /* 9818 8006CB78 08004000 */  jr         $v0
    /* 981C 8006CB7C 00000000 */   nop
  jlabel .L8006CB80
    /* 9820 8006CB80 0000028E */  lw         $v0, 0x0($s0)
    /* 9824 8006CB84 FFBF0324 */  addiu      $v1, $zero, -0x4001
    /* 9828 8006CB88 24184300 */  and        $v1, $v0, $v1
    /* 982C 8006CB8C 00104230 */  andi       $v0, $v0, 0x1000
    /* 9830 8006CB90 03004010 */  beqz       $v0, .L8006CBA0
    /* 9834 8006CB94 000003AE */   sw        $v1, 0x0($s0)
    /* 9838 8006CB98 00406234 */  ori        $v0, $v1, 0x4000
    /* 983C 8006CB9C 000002AE */  sw         $v0, 0x0($s0)
  .L8006CBA0:
    /* 9840 8006CBA0 21204002 */  addu       $a0, $s2, $zero
    /* 9844 8006CBA4 3FB30108 */  j          .L8006CCFC
    /* 9848 8006CBA8 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006CBAC
    /* 984C 8006CBAC 18000486 */  lh         $a0, 0x18($s0)
    /* 9850 8006CBB0 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9854 8006CBB4 5DC2010C */  jal        func_80070974
    /* 9858 8006CBB8 00000000 */   nop
    /* 985C 8006CBBC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 9860 8006CBC0 18000686 */  lh         $a2, 0x18($s0)
    /* 9864 8006CBC4 1A000786 */  lh         $a3, 0x1A($s0)
    /* 9868 8006CBC8 08000292 */  lbu        $v0, 0x8($s0)
    /* 986C 8006CBCC 21288000 */  addu       $a1, $a0, $zero
    /* 9870 8006CBD0 FDBA010C */  jal        func_8006EBF4
    /* 9874 8006CBD4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9878 8006CBD8 21204002 */  addu       $a0, $s2, $zero
    /* 987C 8006CBDC 03000524 */  addiu      $a1, $zero, 0x3
    /* 9880 8006CBE0 7045000C */  jal        Task_SetState0
    /* 9884 8006CBE4 000000AE */   sw        $zero, 0x0($s0)
    /* 9888 8006CBE8 41B30108 */  j          .L8006CD04
    /* 988C 8006CBEC 00000000 */   nop
  jlabel .L8006CBF0
    /* 9890 8006CBF0 1800438E */  lw         $v1, 0x18($s2)
    /* 9894 8006CBF4 00000000 */  nop
    /* 9898 8006CBF8 03006010 */  beqz       $v1, .L8006CC08
    /* 989C 8006CBFC 01000224 */   addiu     $v0, $zero, 0x1
    /* 98A0 8006CC00 09006210 */  beq        $v1, $v0, .L8006CC28
    /* 98A4 8006CC04 00000000 */   nop
  .L8006CC08:
    /* 98A8 8006CC08 21204002 */  addu       $a0, $s2, $zero
    /* 98AC 8006CC0C 0000028E */  lw         $v0, 0x0($s0)
    /* 98B0 8006CC10 28000524 */  addiu      $a1, $zero, 0x28
    /* 98B4 8006CC14 00504234 */  ori        $v0, $v0, 0x5000
    /* 98B8 8006CC18 37B9010C */  jal        func_8006E4DC
    /* 98BC 8006CC1C 000002AE */   sw        $v0, 0x0($s0)
    /* 98C0 8006CC20 36B30108 */  j          .L8006CCD8
    /* 98C4 8006CC24 00000000 */   nop
  .L8006CC28:
    /* 98C8 8006CC28 1C00428E */  lw         $v0, 0x1C($s2)
    /* 98CC 8006CC2C 00000000 */  nop
    /* 98D0 8006CC30 21184000 */  addu       $v1, $v0, $zero
    /* 98D4 8006CC34 01004224 */  addiu      $v0, $v0, 0x1
    /* 98D8 8006CC38 06006328 */  slti       $v1, $v1, 0x6
    /* 98DC 8006CC3C 31006014 */  bnez       $v1, .L8006CD04
    /* 98E0 8006CC40 1C0042AE */   sw        $v0, 0x1C($s2)
    /* 98E4 8006CC44 3EB30108 */  j          .L8006CCF8
    /* 98E8 8006CC48 21204002 */   addu      $a0, $s2, $zero
  jlabel .L8006CC4C
    /* 98EC 8006CC4C 1800518E */  lw         $s1, 0x18($s2)
    /* 98F0 8006CC50 00000000 */  nop
    /* 98F4 8006CC54 03002012 */  beqz       $s1, .L8006CC64
    /* 98F8 8006CC58 01000224 */   addiu     $v0, $zero, 0x1
    /* 98FC 8006CC5C 09002212 */  beq        $s1, $v0, .L8006CC84
    /* 9900 8006CC60 00000000 */   nop
  .L8006CC64:
    /* 9904 8006CC64 21204002 */  addu       $a0, $s2, $zero
    /* 9908 8006CC68 0000028E */  lw         $v0, 0x0($s0)
    /* 990C 8006CC6C 2C000524 */  addiu      $a1, $zero, 0x2C
    /* 9910 8006CC70 00504234 */  ori        $v0, $v0, 0x5000
    /* 9914 8006CC74 37B9010C */  jal        func_8006E4DC
    /* 9918 8006CC78 000002AE */   sw        $v0, 0x0($s0)
    /* 991C 8006CC7C 36B30108 */  j          .L8006CCD8
    /* 9920 8006CC80 00000000 */   nop
  .L8006CC84:
    /* 9924 8006CC84 62B9010C */  jal        func_8006E588
    /* 9928 8006CC88 21204002 */   addu      $a0, $s2, $zero
    /* 992C 8006CC8C 1D005114 */  bne        $v0, $s1, .L8006CD04
    /* 9930 8006CC90 21204002 */   addu      $a0, $s2, $zero
    /* 9934 8006CC94 37B9010C */  jal        func_8006E4DC
    /* 9938 8006CC98 28000524 */   addiu     $a1, $zero, 0x28
    /* 993C 8006CC9C 21204002 */  addu       $a0, $s2, $zero
    /* 9940 8006CCA0 3FB30108 */  j          .L8006CCFC
    /* 9944 8006CCA4 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006CCA8
    /* 9948 8006CCA8 1800508E */  lw         $s0, 0x18($s2)
    /* 994C 8006CCAC 00000000 */  nop
    /* 9950 8006CCB0 03000012 */  beqz       $s0, .L8006CCC0
    /* 9954 8006CCB4 01000224 */   addiu     $v0, $zero, 0x1
    /* 9958 8006CCB8 0B000212 */  beq        $s0, $v0, .L8006CCE8
    /* 995C 8006CCBC 00000000 */   nop
  .L8006CCC0:
    /* 9960 8006CCC0 21204002 */  addu       $a0, $s2, $zero
    /* 9964 8006CCC4 37B9010C */  jal        func_8006E4DC
    /* 9968 8006CCC8 2B000524 */   addiu     $a1, $zero, 0x2B
    /* 996C 8006CCCC 36000424 */  addiu      $a0, $zero, 0x36
    /* 9970 8006CCD0 A369000C */  jal        Snd_PlayById
    /* 9974 8006CCD4 21280000 */   addu      $a1, $zero, $zero
  .L8006CCD8:
    /* 9978 8006CCD8 6045000C */  jal        Task_NextState2
    /* 997C 8006CCDC 21204002 */   addu      $a0, $s2, $zero
    /* 9980 8006CCE0 41B30108 */  j          .L8006CD04
    /* 9984 8006CCE4 00000000 */   nop
  .L8006CCE8:
    /* 9988 8006CCE8 62B9010C */  jal        func_8006E588
    /* 998C 8006CCEC 21204002 */   addu      $a0, $s2, $zero
    /* 9990 8006CCF0 04005014 */  bne        $v0, $s0, .L8006CD04
    /* 9994 8006CCF4 21204002 */   addu      $a0, $s2, $zero
  .L8006CCF8:
    /* 9998 8006CCF8 02000524 */  addiu      $a1, $zero, 0x2
  .L8006CCFC:
    /* 999C 8006CCFC 7745000C */  jal        Task_SetState1
    /* 99A0 8006CD00 00000000 */   nop
  jlabel .L8006CD04
    /* 99A4 8006CD04 2400BF8F */  lw         $ra, 0x24($sp)
    /* 99A8 8006CD08 2000B28F */  lw         $s2, 0x20($sp)
    /* 99AC 8006CD0C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 99B0 8006CD10 1800B08F */  lw         $s0, 0x18($sp)
    /* 99B4 8006CD14 0800E003 */  jr         $ra
    /* 99B8 8006CD18 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CAD4
