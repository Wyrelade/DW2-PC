nonmatching func_80064AFC, 0xDC

glabel func_80064AFC
    /* 179C 80064AFC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17A0 80064B00 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17A4 80064B04 21808000 */  addu       $s0, $a0, $zero
    /* 17A8 80064B08 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17AC 80064B0C 2C00068E */  lw         $a2, 0x2C($s0)
    /* 17B0 80064B10 00000000 */  nop
    /* 17B4 80064B14 2000C38C */  lw         $v1, 0x20($a2)
    /* 17B8 80064B18 00000000 */  nop
    /* 17BC 80064B1C 2C00628C */  lw         $v0, 0x2C($v1)
    /* 17C0 80064B20 00000000 */  nop
    /* 17C4 80064B24 34004284 */  lh         $v0, 0x34($v0)
    /* 17C8 80064B28 00000000 */  nop
    /* 17CC 80064B2C 26004010 */  beqz       $v0, .L80064BC8
    /* 17D0 80064B30 00000000 */   nop
    /* 17D4 80064B34 3800048E */  lw         $a0, 0x38($s0)
    /* 17D8 80064B38 3800628C */  lw         $v0, 0x38($v1)
    /* 17DC 80064B3C 21188000 */  addu       $v1, $a0, $zero
    /* 17E0 80064B40 90004524 */  addiu      $a1, $v0, 0x90
  .L80064B44:
    /* 17E4 80064B44 0000478C */  lw         $a3, 0x0($v0)
    /* 17E8 80064B48 0400488C */  lw         $t0, 0x4($v0)
    /* 17EC 80064B4C 0800498C */  lw         $t1, 0x8($v0)
    /* 17F0 80064B50 0C004A8C */  lw         $t2, 0xC($v0)
    /* 17F4 80064B54 000067AC */  sw         $a3, 0x0($v1)
    /* 17F8 80064B58 040068AC */  sw         $t0, 0x4($v1)
    /* 17FC 80064B5C 080069AC */  sw         $t1, 0x8($v1)
    /* 1800 80064B60 0C006AAC */  sw         $t2, 0xC($v1)
    /* 1804 80064B64 10004224 */  addiu      $v0, $v0, 0x10
    /* 1808 80064B68 F6FF4514 */  bne        $v0, $a1, .L80064B44
    /* 180C 80064B6C 10006324 */   addiu     $v1, $v1, 0x10
    /* 1810 80064B70 3400828C */  lw         $v0, 0x34($a0)
    /* 1814 80064B74 440080A4 */  sh         $zero, 0x44($a0)
    /* 1818 80064B78 400080A4 */  sh         $zero, 0x40($a0)
    /* 181C 80064B7C 420080A4 */  sh         $zero, 0x42($a0)
    /* 1820 80064B80 2800C38C */  lw         $v1, 0x28($a2)
    /* 1824 80064B84 00000000 */  nop
    /* 1828 80064B88 21104300 */  addu       $v0, $v0, $v1
    /* 182C 80064B8C 340082AC */  sw         $v0, 0x34($a0)
    /* 1830 80064B90 1400C58C */  lw         $a1, 0x14($a2)
    /* 1834 80064B94 6F7F000C */  jal        Gfx_AttachModel
    /* 1838 80064B98 21200002 */   addu      $a0, $s0, $zero
    /* 183C 80064B9C 21200002 */  addu       $a0, $s0, $zero
    /* 1840 80064BA0 03000324 */  addiu      $v1, $zero, 0x3
    /* 1844 80064BA4 C87C000C */  jal        Anim_StepModelAnim
    /* 1848 80064BA8 3C0043AC */   sw        $v1, 0x3C($v0)
    /* 184C 80064BAC 4882000C */  jal        Actor_UpdateTransform
    /* 1850 80064BB0 21200002 */   addu      $a0, $s0, $zero
    /* 1854 80064BB4 3480000C */  jal        Gfx_CalcModelBoneMatrices
    /* 1858 80064BB8 21200002 */   addu      $a0, $s0, $zero
    /* 185C 80064BBC 21200002 */  addu       $a0, $s0, $zero
    /* 1860 80064BC0 4481000C */  jal        Gfx_DrawTexModel
    /* 1864 80064BC4 21280000 */   addu      $a1, $zero, $zero
  .L80064BC8:
    /* 1868 80064BC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 186C 80064BCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1870 80064BD0 0800E003 */  jr         $ra
    /* 1874 80064BD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80064AFC
