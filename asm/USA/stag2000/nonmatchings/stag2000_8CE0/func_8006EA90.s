nonmatching func_8006EA90, 0x294

glabel func_8006EA90
    /* B730 8006EA90 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* B734 8006EA94 2000B2AF */  sw         $s2, 0x20($sp)
    /* B738 8006EA98 21900000 */  addu       $s2, $zero, $zero
    /* B73C 8006EA9C FD000724 */  addiu      $a3, $zero, 0xFD
    /* B740 8006EAA0 0B000B24 */  addiu      $t3, $zero, 0xB
    /* B744 8006EAA4 12000A24 */  addiu      $t2, $zero, 0x12
    /* B748 8006EAA8 1D000924 */  addiu      $t1, $zero, 0x1D
    /* B74C 8006EAAC FF000824 */  addiu      $t0, $zero, 0xFF
    /* B750 8006EAB0 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* B754 8006EAB4 3800BEAF */  sw         $fp, 0x38($sp)
    /* B758 8006EAB8 3400B7AF */  sw         $s7, 0x34($sp)
    /* B75C 8006EABC 3000B6AF */  sw         $s6, 0x30($sp)
    /* B760 8006EAC0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* B764 8006EAC4 2800B4AF */  sw         $s4, 0x28($sp)
    /* B768 8006EAC8 2400B3AF */  sw         $s3, 0x24($sp)
    /* B76C 8006EACC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* B770 8006EAD0 1800B0AF */  sw         $s0, 0x18($sp)
    /* B774 8006EAD4 2C00918C */  lw         $s1, 0x2C($a0)
    /* B778 8006EAD8 21304002 */  addu       $a2, $s2, $zero
    /* B77C 8006EADC 21202002 */  addu       $a0, $s1, $zero
  .L8006EAE0:
    /* B780 8006EAE0 21180000 */  addu       $v1, $zero, $zero
    /* B784 8006EAE4 2128C000 */  addu       $a1, $a2, $zero
    /* B788 8006EAE8 21106500 */  addu       $v0, $v1, $a1
  .L8006EAEC:
    /* B78C 8006EAEC 21102202 */  addu       $v0, $s1, $v0
    /* B790 8006EAF0 380047A0 */  sb         $a3, 0x38($v0)
    /* B794 8006EAF4 01006324 */  addiu      $v1, $v1, 0x1
    /* B798 8006EAF8 18006228 */  slti       $v0, $v1, 0x18
    /* B79C 8006EAFC FBFF4014 */  bnez       $v0, .L8006EAEC
    /* B7A0 8006EB00 21106500 */   addu      $v0, $v1, $a1
    /* B7A4 8006EB04 4C008BA0 */  sb         $t3, 0x4C($a0)
    /* B7A8 8006EB08 4D008AA0 */  sb         $t2, 0x4D($a0)
    /* B7AC 8006EB0C 4E0089A0 */  sb         $t1, 0x4E($a0)
    /* B7B0 8006EB10 4F0088A0 */  sb         $t0, 0x4F($a0)
    /* B7B4 8006EB14 20008424 */  addiu      $a0, $a0, 0x20
    /* B7B8 8006EB18 01005226 */  addiu      $s2, $s2, 0x1
    /* B7BC 8006EB1C 0600422A */  slti       $v0, $s2, 0x6
    /* B7C0 8006EB20 EFFF4014 */  bnez       $v0, .L8006EAE0
    /* B7C4 8006EB24 2000C624 */   addiu     $a2, $a2, 0x20
    /* B7C8 8006EB28 21900000 */  addu       $s2, $zero, $zero
    /* B7CC 8006EB2C 0780023C */  lui        $v0, %hi(D_800706D4)
    /* B7D0 8006EB30 D4065E24 */  addiu      $fp, $v0, %lo(D_800706D4)
    /* B7D4 8006EB34 49001724 */  addiu      $s7, $zero, 0x49
    /* B7D8 8006EB38 1000B627 */  addiu      $s6, $sp, 0x10
    /* B7DC 8006EB3C 0F001524 */  addiu      $s5, $zero, 0xF
    /* B7E0 8006EB40 21A04002 */  addu       $s4, $s2, $zero
    /* B7E4 8006EB44 21982002 */  addu       $s3, $s1, $zero
  .L8006EB48:
    /* B7E8 8006EB48 80101200 */  sll        $v0, $s2, 2
    /* B7EC 8006EB4C 21105E00 */  addu       $v0, $v0, $fp
    /* B7F0 8006EB50 06800C3C */  lui        $t4, %hi(Save_GameState)
    /* B7F4 8006EB54 0000428C */  lw         $v0, 0x0($v0)
    /* B7F8 8006EB58 20E68C25 */  addiu      $t4, $t4, %lo(Save_GameState)
    /* B7FC 8006EB5C 40100200 */  sll        $v0, $v0, 1
    /* B800 8006EB60 21104C00 */  addu       $v0, $v0, $t4
    /* B804 8006EB64 2C005094 */  lhu        $s0, 0x2C($v0)
    /* B808 8006EB68 00000000 */  nop
    /* B80C 8006EB6C 1E000012 */  beqz       $s0, .L8006EBE8
    /* B810 8006EB70 540070AE */   sw        $s0, 0x54($s3)
    /* B814 8006EB74 1278000C */  jal        Item_GetNameText
    /* B818 8006EB78 21200002 */   addu      $a0, $s0, $zero
    /* B81C 8006EB7C 21284000 */  addu       $a1, $v0, $zero
    /* B820 8006EB80 0000A490 */  lbu        $a0, 0x0($a1)
    /* B824 8006EB84 FF000224 */  addiu      $v0, $zero, 0xFF
    /* B828 8006EB88 0B008210 */  beq        $a0, $v0, .L8006EBB8
    /* B82C 8006EB8C 21180000 */   addu      $v1, $zero, $zero
    /* B830 8006EB90 21308002 */  addu       $a2, $s4, $zero
    /* B834 8006EB94 21384000 */  addu       $a3, $v0, $zero
  .L8006EB98:
    /* B838 8006EB98 0100A524 */  addiu      $a1, $a1, 0x1
    /* B83C 8006EB9C 21106600 */  addu       $v0, $v1, $a2
    /* B840 8006EBA0 21102202 */  addu       $v0, $s1, $v0
    /* B844 8006EBA4 380044A0 */  sb         $a0, 0x38($v0)
    /* B848 8006EBA8 0000A490 */  lbu        $a0, 0x0($a1)
    /* B84C 8006EBAC 00000000 */  nop
    /* B850 8006EBB0 F9FF8714 */  bne        $a0, $a3, .L8006EB98
    /* B854 8006EBB4 01006324 */   addiu     $v1, $v1, 0x1
  .L8006EBB8:
    /* B858 8006EBB8 7ABA010C */  jal        func_8006E9E8
    /* B85C 8006EBBC 21200002 */   addu      $a0, $s0, $zero
    /* B860 8006EBC0 12004010 */  beqz       $v0, .L8006EC0C
    /* B864 8006EBC4 00000000 */   nop
    /* B868 8006EBC8 6078000C */  jal        Item_GetPrice
    /* B86C 8006EBCC 01000426 */   addiu     $a0, $s0, 0x1
    /* B870 8006EBD0 21200002 */  addu       $a0, $s0, $zero
    /* B874 8006EBD4 6078000C */  jal        Item_GetPrice
    /* B878 8006EBD8 21804000 */   addu      $s0, $v0, $zero
    /* B87C 8006EBDC 23800202 */  subu       $s0, $s0, $v0
    /* B880 8006EBE0 04BB0108 */  j          .L8006EC10
    /* B884 8006EBE4 500070AE */   sw        $s0, 0x50($s3)
  .L8006EBE8:
    /* B888 8006EBE8 21180000 */  addu       $v1, $zero, $zero
    /* B88C 8006EBEC 21208002 */  addu       $a0, $s4, $zero
    /* B890 8006EBF0 21106400 */  addu       $v0, $v1, $a0
  .L8006EBF4:
    /* B894 8006EBF4 21102202 */  addu       $v0, $s1, $v0
    /* B898 8006EBF8 380057A0 */  sb         $s7, 0x38($v0)
    /* B89C 8006EBFC 01006324 */  addiu      $v1, $v1, 0x1
    /* B8A0 8006EC00 0A006228 */  slti       $v0, $v1, 0xA
    /* B8A4 8006EC04 FBFF4014 */  bnez       $v0, .L8006EBF4
    /* B8A8 8006EC08 21106400 */   addu      $v0, $v1, $a0
  .L8006EC0C:
    /* B8AC 8006EC0C 500060AE */  sw         $zero, 0x50($s3)
  .L8006EC10:
    /* B8B0 8006EC10 5000668E */  lw         $a2, 0x50($s3)
    /* B8B4 8006EC14 00000000 */  nop
    /* B8B8 8006EC18 2700C010 */  beqz       $a2, .L8006ECB8
    /* B8BC 8006EC1C 04000524 */   addiu     $a1, $zero, 0x4
    /* B8C0 8006EC20 6666073C */  lui        $a3, (0x66666667 >> 16)
    /* B8C4 8006EC24 6766E734 */  ori        $a3, $a3, (0x66666667 & 0xFFFF)
    /* B8C8 8006EC28 FFFF0824 */  addiu      $t0, $zero, -0x1
  .L8006EC2C:
    /* B8CC 8006EC2C 1800C700 */  mult       $a2, $a3
    /* B8D0 8006EC30 2120C502 */  addu       $a0, $s6, $a1
    /* B8D4 8006EC34 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* B8D8 8006EC38 C3170600 */  sra        $v0, $a2, 31
    /* B8DC 8006EC3C 10600000 */  mfhi       $t4
    /* B8E0 8006EC40 83180C00 */  sra        $v1, $t4, 2
    /* B8E4 8006EC44 23186200 */  subu       $v1, $v1, $v0
    /* B8E8 8006EC48 80100300 */  sll        $v0, $v1, 2
    /* B8EC 8006EC4C 21104300 */  addu       $v0, $v0, $v1
    /* B8F0 8006EC50 40100200 */  sll        $v0, $v0, 1
    /* B8F4 8006EC54 2310C200 */  subu       $v0, $a2, $v0
    /* B8F8 8006EC58 000082A0 */  sb         $v0, 0x0($a0)
    /* B8FC 8006EC5C F3FFA814 */  bne        $a1, $t0, .L8006EC2C
    /* B900 8006EC60 21306000 */   addu      $a2, $v1, $zero
    /* B904 8006EC64 01000624 */  addiu      $a2, $zero, 0x1
    /* B908 8006EC68 21280000 */  addu       $a1, $zero, $zero
    /* B90C 8006EC6C 2138A002 */  addu       $a3, $s5, $zero
    /* B910 8006EC70 2120C002 */  addu       $a0, $s6, $zero
  .L8006EC74:
    /* B914 8006EC74 0500C010 */  beqz       $a2, .L8006EC8C
    /* B918 8006EC78 00000000 */   nop
    /* B91C 8006EC7C 00008290 */  lbu        $v0, 0x0($a0)
    /* B920 8006EC80 00000000 */  nop
    /* B924 8006EC84 06004010 */  beqz       $v0, .L8006ECA0
    /* B928 8006EC88 00000000 */   nop
  .L8006EC8C:
    /* B92C 8006EC8C 21300000 */  addu       $a2, $zero, $zero
    /* B930 8006EC90 2110A700 */  addu       $v0, $a1, $a3
    /* B934 8006EC94 00008390 */  lbu        $v1, 0x0($a0)
    /* B938 8006EC98 21102202 */  addu       $v0, $s1, $v0
    /* B93C 8006EC9C 380043A0 */  sb         $v1, 0x38($v0)
  .L8006ECA0:
    /* B940 8006ECA0 0100A524 */  addiu      $a1, $a1, 0x1
    /* B944 8006ECA4 0500A228 */  slti       $v0, $a1, 0x5
    /* B948 8006ECA8 F2FF4014 */  bnez       $v0, .L8006EC74
    /* B94C 8006ECAC 01008424 */   addiu     $a0, $a0, 0x1
    /* B950 8006ECB0 38BB0108 */  j          .L8006ECE0
    /* B954 8006ECB4 2000B526 */   addiu     $s5, $s5, 0x20
  .L8006ECB8:
    /* B958 8006ECB8 21280000 */  addu       $a1, $zero, $zero
    /* B95C 8006ECBC 2118A002 */  addu       $v1, $s5, $zero
    /* B960 8006ECC0 2110A300 */  addu       $v0, $a1, $v1
  .L8006ECC4:
    /* B964 8006ECC4 21102202 */  addu       $v0, $s1, $v0
    /* B968 8006ECC8 380057A0 */  sb         $s7, 0x38($v0)
    /* B96C 8006ECCC 0100A524 */  addiu      $a1, $a1, 0x1
    /* B970 8006ECD0 0500A228 */  slti       $v0, $a1, 0x5
    /* B974 8006ECD4 FBFF4014 */  bnez       $v0, .L8006ECC4
    /* B978 8006ECD8 2110A300 */   addu      $v0, $a1, $v1
    /* B97C 8006ECDC 2000B526 */  addiu      $s5, $s5, 0x20
  .L8006ECE0:
    /* B980 8006ECE0 20009426 */  addiu      $s4, $s4, 0x20
    /* B984 8006ECE4 01005226 */  addiu      $s2, $s2, 0x1
    /* B988 8006ECE8 0600422A */  slti       $v0, $s2, 0x6
    /* B98C 8006ECEC 96FF4014 */  bnez       $v0, .L8006EB48
    /* B990 8006ECF0 20007326 */   addiu     $s3, $s3, 0x20
    /* B994 8006ECF4 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* B998 8006ECF8 3800BE8F */  lw         $fp, 0x38($sp)
    /* B99C 8006ECFC 3400B78F */  lw         $s7, 0x34($sp)
    /* B9A0 8006ED00 3000B68F */  lw         $s6, 0x30($sp)
    /* B9A4 8006ED04 2C00B58F */  lw         $s5, 0x2C($sp)
    /* B9A8 8006ED08 2800B48F */  lw         $s4, 0x28($sp)
    /* B9AC 8006ED0C 2400B38F */  lw         $s3, 0x24($sp)
    /* B9B0 8006ED10 2000B28F */  lw         $s2, 0x20($sp)
    /* B9B4 8006ED14 1C00B18F */  lw         $s1, 0x1C($sp)
    /* B9B8 8006ED18 1800B08F */  lw         $s0, 0x18($sp)
    /* B9BC 8006ED1C 0800E003 */  jr         $ra
    /* B9C0 8006ED20 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8006EA90
