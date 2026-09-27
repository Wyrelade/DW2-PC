/* Handwritten function */
nonmatching Gfx_CalcNormalColors, 0xC0

glabel Gfx_CalcNormalColors
    /* 11710 80020F10 00008784 */  lh         $a3, 0x0($a0)
    /* 11714 80020F14 3400A284 */  lh         $v0, 0x34($a1)
    /* 11718 80020F18 7400A68C */  lw         $a2, 0x74($a1)
    /* 1171C 80020F1C 0E004010 */  beqz       $v0, .L80020F58
    /* 11720 80020F20 06008424 */   addiu     $a0, $a0, 0x6
    /* 11724 80020F24 0A00E018 */  blez       $a3, .L80020F50
    /* 11728 80020F28 21180000 */   addu      $v1, $zero, $zero
  .L80020F2C:
    /* 1172C 80020F2C 3B00A888 */  lwl        $t0, 0x3B($a1)
    /* 11730 80020F30 3800A898 */  lwr        $t0, 0x38($a1)
    /* 11734 80020F34 00000000 */  nop
    /* 11738 80020F38 0300C8A8 */  swl        $t0, 0x3($a2)
    /* 1173C 80020F3C 0000C8B8 */  swr        $t0, 0x0($a2)
    /* 11740 80020F40 01006324 */  addiu      $v1, $v1, 0x1
    /* 11744 80020F44 2A106700 */  slt        $v0, $v1, $a3
    /* 11748 80020F48 F8FF4014 */  bnez       $v0, .L80020F2C
    /* 1174C 80020F4C 0400C624 */   addiu     $a2, $a2, 0x4
  .L80020F50:
    /* 11750 80020F50 0800E003 */  jr         $ra
    /* 11754 80020F54 00000000 */   nop
  .L80020F58:
    /* 11758 80020F58 03008C88 */  lwl        $t4, 0x3($a0)
    /* 1175C 80020F5C 00008C98 */  lwr        $t4, 0x0($a0)
    /* 11760 80020F60 04008D94 */  lhu        $t5, 0x4($a0)
    /* 11764 80020F64 00008C48 */  mtc2       $t4, $0 /* handwritten instruction */
    /* 11768 80020F68 00088D48 */  mtc2       $t5, $1 /* handwritten instruction */
    /* 1176C 80020F6C 00000000 */  nop
    /* 11770 80020F70 00000000 */  nop
    /* 11774 80020F74 1E04C84A */  ncs
    /* 11778 80020F78 0000D6E8 */  swc2       $22, 0x0($a2)
    /* 1177C 80020F7C 01000324 */  addiu      $v1, $zero, 0x1
    /* 11780 80020F80 2A106700 */  slt        $v0, $v1, $a3
    /* 11784 80020F84 F2FF4010 */  beqz       $v0, .L80020F50
    /* 11788 80020F88 06008424 */   addiu     $a0, $a0, 0x6
  .L80020F8C:
    /* 1178C 80020F8C 03008C88 */  lwl        $t4, 0x3($a0)
    /* 11790 80020F90 00008C98 */  lwr        $t4, 0x0($a0)
    /* 11794 80020F94 04008D94 */  lhu        $t5, 0x4($a0)
    /* 11798 80020F98 00008C48 */  mtc2       $t4, $0 /* handwritten instruction */
    /* 1179C 80020F9C 00088D48 */  mtc2       $t5, $1 /* handwritten instruction */
    /* 117A0 80020FA0 00000000 */  nop
    /* 117A4 80020FA4 00000000 */  nop
    /* 117A8 80020FA8 1E04C84A */  ncs
    /* 117AC 80020FAC 06008424 */  addiu      $a0, $a0, 0x6
    /* 117B0 80020FB0 0400C624 */  addiu      $a2, $a2, 0x4
    /* 117B4 80020FB4 01006324 */  addiu      $v1, $v1, 0x1
    /* 117B8 80020FB8 0000D6E8 */  swc2       $22, 0x0($a2)
    /* 117BC 80020FBC 2A106700 */  slt        $v0, $v1, $a3
    /* 117C0 80020FC0 F2FF4014 */  bnez       $v0, .L80020F8C
    /* 117C4 80020FC4 00000000 */   nop
    /* 117C8 80020FC8 0800E003 */  jr         $ra
    /* 117CC 80020FCC 00000000 */   nop
endlabel Gfx_CalcNormalColors
