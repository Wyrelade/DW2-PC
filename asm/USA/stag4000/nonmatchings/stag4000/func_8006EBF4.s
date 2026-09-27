nonmatching func_8006EBF4, 0xDC

glabel func_8006EBF4
    /* B894 8006EBF4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* B898 8006EBF8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B89C 8006EBFC 4000B38F */  lw         $s3, 0x40($sp)
    /* B8A0 8006EC00 2000B4AF */  sw         $s4, 0x20($sp)
    /* B8A4 8006EC04 21A08000 */  addu       $s4, $a0, $zero
    /* B8A8 8006EC08 2400B5AF */  sw         $s5, 0x24($sp)
    /* B8AC 8006EC0C 21A8A000 */  addu       $s5, $a1, $zero
    /* B8B0 8006EC10 1000B0AF */  sw         $s0, 0x10($sp)
    /* B8B4 8006EC14 2180C000 */  addu       $s0, $a2, $zero
    /* B8B8 8006EC18 1400B1AF */  sw         $s1, 0x14($sp)
    /* B8BC 8006EC1C 2188E000 */  addu       $s1, $a3, $zero
    /* B8C0 8006EC20 1800B2AF */  sw         $s2, 0x18($sp)
    /* B8C4 8006EC24 FFFF1224 */  addiu      $s2, $zero, -0x1
    /* B8C8 8006EC28 09001212 */  beq        $s0, $s2, .L8006EC50
    /* B8CC 8006EC2C 2800BFAF */   sw        $ra, 0x28($sp)
    /* B8D0 8006EC30 21200002 */  addu       $a0, $s0, $zero
    /* B8D4 8006EC34 F8C0010C */  jal        func_800703E0
    /* B8D8 8006EC38 21282002 */   addu      $a1, $s1, $zero
    /* B8DC 8006EC3C 21200002 */  addu       $a0, $s0, $zero
    /* B8E0 8006EC40 21282002 */  addu       $a1, $s1, $zero
    /* B8E4 8006EC44 42130200 */  srl        $v0, $v0, 13
    /* B8E8 8006EC48 E1BA010C */  jal        func_8006EB84
    /* B8EC 8006EC4C 01004630 */   andi      $a2, $v0, 0x1
  .L8006EC50:
    /* B8F0 8006EC50 16009212 */  beq        $s4, $s2, .L8006ECAC
    /* B8F4 8006EC54 0500622E */   sltiu     $v0, $s3, 0x5
    /* B8F8 8006EC58 10004010 */  beqz       $v0, .L8006EC9C
    /* B8FC 8006EC5C 0680023C */   lui       $v0, %hi(jtbl_80063678)
    /* B900 8006EC60 78364224 */  addiu      $v0, $v0, %lo(jtbl_80063678)
    /* B904 8006EC64 80181300 */  sll        $v1, $s3, 2
    /* B908 8006EC68 21186200 */  addu       $v1, $v1, $v0
    /* B90C 8006EC6C 0000628C */  lw         $v0, 0x0($v1)
    /* B910 8006EC70 00000000 */  nop
    /* B914 8006EC74 08004000 */  jr         $v0
    /* B918 8006EC78 00000000 */   nop
  jlabel .L8006EC7C
    /* B91C 8006EC7C 28BB0108 */  j          .L8006ECA0
    /* B920 8006EC80 0E000624 */   addiu     $a2, $zero, 0xE
  jlabel .L8006EC84
    /* B924 8006EC84 28BB0108 */  j          .L8006ECA0
    /* B928 8006EC88 0D000624 */   addiu     $a2, $zero, 0xD
  jlabel .L8006EC8C
    /* B92C 8006EC8C 28BB0108 */  j          .L8006ECA0
    /* B930 8006EC90 0A000624 */   addiu     $a2, $zero, 0xA
  jlabel .L8006EC94
    /* B934 8006EC94 28BB0108 */  j          .L8006ECA0
    /* B938 8006EC98 0B000624 */   addiu     $a2, $zero, 0xB
  .L8006EC9C:
    /* B93C 8006EC9C 0C000624 */  addiu      $a2, $zero, 0xC
  .L8006ECA0:
    /* B940 8006ECA0 21208002 */  addu       $a0, $s4, $zero
    /* B944 8006ECA4 E1BA010C */  jal        func_8006EB84
    /* B948 8006ECA8 2128A002 */   addu      $a1, $s5, $zero
  .L8006ECAC:
    /* B94C 8006ECAC 2800BF8F */  lw         $ra, 0x28($sp)
    /* B950 8006ECB0 2400B58F */  lw         $s5, 0x24($sp)
    /* B954 8006ECB4 2000B48F */  lw         $s4, 0x20($sp)
    /* B958 8006ECB8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B95C 8006ECBC 1800B28F */  lw         $s2, 0x18($sp)
    /* B960 8006ECC0 1400B18F */  lw         $s1, 0x14($sp)
    /* B964 8006ECC4 1000B08F */  lw         $s0, 0x10($sp)
    /* B968 8006ECC8 0800E003 */  jr         $ra
    /* B96C 8006ECCC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006EBF4
