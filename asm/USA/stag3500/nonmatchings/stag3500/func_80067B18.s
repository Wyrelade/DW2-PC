nonmatching func_80067B18, 0x15C

glabel func_80067B18
    /* 47B8 80067B18 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 47BC 80067B1C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 47C0 80067B20 21988000 */  addu       $s3, $a0, $zero
    /* 47C4 80067B24 C4000424 */  addiu      $a0, $zero, 0xC4
    /* 47C8 80067B28 2800BFAF */  sw         $ra, 0x28($sp)
    /* 47CC 80067B2C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 47D0 80067B30 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 47D4 80067B34 1800B0AF */  sw         $s0, 0x18($sp)
    /* 47D8 80067B38 0800628E */  lw         $v0, 0x8($s3)
    /* 47DC 80067B3C 2C00708E */  lw         $s0, 0x2C($s3)
    /* 47E0 80067B40 80100200 */  sll        $v0, $v0, 2
    /* 47E4 80067B44 21100202 */  addu       $v0, $s0, $v0
    /* 47E8 80067B48 5400468C */  lw         $a2, 0x54($v0)
    /* 47EC 80067B4C E296010C */  jal        func_80065B88
    /* 47F0 80067B50 00700524 */   addiu     $a1, $zero, 0x7000
    /* 47F4 80067B54 0800638E */  lw         $v1, 0x8($s3)
    /* 47F8 80067B58 00000000 */  nop
    /* 47FC 80067B5C 03006014 */  bnez       $v1, .L80067B6C
    /* 4800 80067B60 21904000 */   addu      $s2, $v0, $zero
    /* 4804 80067B64 DC9E0108 */  j          .L80067B70
    /* 4808 80067B68 30001126 */   addiu     $s1, $s0, 0x30
  .L80067B6C:
    /* 480C 80067B6C 34001126 */  addiu      $s1, $s0, 0x34
  .L80067B70:
    /* 4810 80067B70 21202002 */  addu       $a0, $s1, $zero
    /* 4814 80067B74 D296010C */  jal        func_80065B48
    /* 4818 80067B78 21284002 */   addu      $a1, $s2, $zero
    /* 481C 80067B7C 21202002 */  addu       $a0, $s1, $zero
    /* 4820 80067B80 60000524 */  addiu      $a1, $zero, 0x60
    /* 4824 80067B84 D896010C */  jal        func_80065B60
    /* 4828 80067B88 2328B200 */   subu      $a1, $a1, $s2
    /* 482C 80067B8C 0800628E */  lw         $v0, 0x8($s3)
    /* 4830 80067B90 00000000 */  nop
    /* 4834 80067B94 80100200 */  sll        $v0, $v0, 2
    /* 4838 80067B98 21100202 */  addu       $v0, $s0, $v0
    /* 483C 80067B9C 5400428C */  lw         $v0, 0x54($v0)
    /* 4840 80067BA0 00000000 */  nop
    /* 4844 80067BA4 00604228 */  slti       $v0, $v0, 0x6000
    /* 4848 80067BA8 12004014 */  bnez       $v0, .L80067BF4
    /* 484C 80067BAC 21202002 */   addu      $a0, $s1, $zero
    /* 4850 80067BB0 21280000 */  addu       $a1, $zero, $zero
    /* 4854 80067BB4 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 4858 80067BB8 19000724 */  addiu      $a3, $zero, 0x19
    /* 485C 80067BBC 02001024 */  addiu      $s0, $zero, 0x2
    /* 4860 80067BC0 C796010C */  jal        func_80065B1C
    /* 4864 80067BC4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4868 80067BC8 21202002 */  addu       $a0, $s1, $zero
    /* 486C 80067BCC 01000524 */  addiu      $a1, $zero, 0x1
    /* 4870 80067BD0 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 4874 80067BD4 19000724 */  addiu      $a3, $zero, 0x19
    /* 4878 80067BD8 C796010C */  jal        func_80065B1C
    /* 487C 80067BDC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4880 80067BE0 21202002 */  addu       $a0, $s1, $zero
    /* 4884 80067BE4 21280002 */  addu       $a1, $s0, $zero
    /* 4888 80067BE8 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 488C 80067BEC 0E9F0108 */  j          .L80067C38
    /* 4890 80067BF0 19000724 */   addiu     $a3, $zero, 0x19
  .L80067BF4:
    /* 4894 80067BF4 21280000 */  addu       $a1, $zero, $zero
    /* 4898 80067BF8 AE000624 */  addiu      $a2, $zero, 0xAE
    /* 489C 80067BFC 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 48A0 80067C00 11001024 */  addiu      $s0, $zero, 0x11
    /* 48A4 80067C04 C796010C */  jal        func_80065B1C
    /* 48A8 80067C08 1000B0AF */   sw        $s0, 0x10($sp)
    /* 48AC 80067C0C 21202002 */  addu       $a0, $s1, $zero
    /* 48B0 80067C10 01000524 */  addiu      $a1, $zero, 0x1
    /* 48B4 80067C14 AE000624 */  addiu      $a2, $zero, 0xAE
    /* 48B8 80067C18 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 48BC 80067C1C C796010C */  jal        func_80065B1C
    /* 48C0 80067C20 1000B0AF */   sw        $s0, 0x10($sp)
    /* 48C4 80067C24 21202002 */  addu       $a0, $s1, $zero
    /* 48C8 80067C28 02000524 */  addiu      $a1, $zero, 0x2
    /* 48CC 80067C2C A4000624 */  addiu      $a2, $zero, 0xA4
    /* 48D0 80067C30 19000724 */  addiu      $a3, $zero, 0x19
    /* 48D4 80067C34 2180A000 */  addu       $s0, $a1, $zero
  .L80067C38:
    /* 48D8 80067C38 C796010C */  jal        func_80065B1C
    /* 48DC 80067C3C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 48E0 80067C40 21202002 */  addu       $a0, $s1, $zero
    /* 48E4 80067C44 03000524 */  addiu      $a1, $zero, 0x3
    /* 48E8 80067C48 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 48EC 80067C4C 19000724 */  addiu      $a3, $zero, 0x19
    /* 48F0 80067C50 C796010C */  jal        func_80065B1C
    /* 48F4 80067C54 1000B0AF */   sw        $s0, 0x10($sp)
    /* 48F8 80067C58 2800BF8F */  lw         $ra, 0x28($sp)
    /* 48FC 80067C5C 2400B38F */  lw         $s3, 0x24($sp)
    /* 4900 80067C60 2000B28F */  lw         $s2, 0x20($sp)
    /* 4904 80067C64 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4908 80067C68 1800B08F */  lw         $s0, 0x18($sp)
    /* 490C 80067C6C 0800E003 */  jr         $ra
    /* 4910 80067C70 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80067B18
