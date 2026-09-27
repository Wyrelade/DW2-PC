nonmatching func_80019E50, 0x90

glabel func_80019E50
    /* A650 80019E50 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* A654 80019E54 1800B2AF */  sw         $s2, 0x18($sp)
    /* A658 80019E58 21908000 */  addu       $s2, $a0, $zero
    /* A65C 80019E5C 2000BFAF */  sw         $ra, 0x20($sp)
    /* A660 80019E60 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A664 80019E64 1400B1AF */  sw         $s1, 0x14($sp)
    /* A668 80019E68 1000B0AF */  sw         $s0, 0x10($sp)
    /* A66C 80019E6C 1000428E */  lw         $v0, 0x10($s2)
    /* A670 80019E70 00000000 */  nop
    /* A674 80019E74 13004014 */  bnez       $v0, .L80019EC4
    /* A678 80019E78 FFFF1324 */   addiu     $s3, $zero, -0x1
    /* A67C 80019E7C 2C00428E */  lw         $v0, 0x2C($s2)
    /* A680 80019E80 3400438E */  lw         $v1, 0x34($s2)
    /* A684 80019E84 0000448C */  lw         $a0, 0x0($v0)
    /* A688 80019E88 828E000C */  jal        Cd_GetFileOrNull
    /* A68C 80019E8C 21886000 */   addu      $s1, $v1, $zero
    /* A690 80019E90 21804000 */  addu       $s0, $v0, $zero
  .L80019E94:
    /* A694 80019E94 0000048E */  lw         $a0, 0x0($s0)
    /* A698 80019E98 00000000 */  nop
    /* A69C 80019E9C 07009310 */  beq        $a0, $s3, .L80019EBC
    /* A6A0 80019EA0 21282002 */   addu      $a1, $s1, $zero
    /* A6A4 80019EA4 1F44000C */  jal        Task_Create
    /* A6A8 80019EA8 10000626 */   addiu     $a2, $s0, 0x10
    /* A6AC 80019EAC 0C00028E */  lw         $v0, 0xC($s0)
    /* A6B0 80019EB0 04003126 */  addiu      $s1, $s1, 0x4
    /* A6B4 80019EB4 A5670008 */  j          .L80019E94
    /* A6B8 80019EB8 21800202 */   addu      $s0, $s0, $v0
  .L80019EBC:
    /* A6BC 80019EBC 5145000C */  jal        Task_NextState0
    /* A6C0 80019EC0 21204002 */   addu      $a0, $s2, $zero
  .L80019EC4:
    /* A6C4 80019EC4 2000BF8F */  lw         $ra, 0x20($sp)
    /* A6C8 80019EC8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A6CC 80019ECC 1800B28F */  lw         $s2, 0x18($sp)
    /* A6D0 80019ED0 1400B18F */  lw         $s1, 0x14($sp)
    /* A6D4 80019ED4 1000B08F */  lw         $s0, 0x10($sp)
    /* A6D8 80019ED8 0800E003 */  jr         $ra
    /* A6DC 80019EDC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80019E50
