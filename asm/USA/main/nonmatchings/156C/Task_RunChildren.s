nonmatching Task_RunChildren, 0x6C

glabel Task_RunChildren
    /* 1638 80010E38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 163C 80010E3C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1640 80010E40 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1644 80010E44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1648 80010E48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 164C 80010E4C 3000928C */  lw         $s2, 0x30($a0)
    /* 1650 80010E50 3400828C */  lw         $v0, 0x34($a0)
    /* 1654 80010E54 0D00401A */  blez       $s2, .L80010E8C
    /* 1658 80010E58 21880000 */   addu      $s1, $zero, $zero
    /* 165C 80010E5C 21804000 */  addu       $s0, $v0, $zero
  .L80010E60:
    /* 1660 80010E60 0000048E */  lw         $a0, 0x0($s0)
    /* 1664 80010E64 00000000 */  nop
    /* 1668 80010E68 04008010 */  beqz       $a0, .L80010E7C
    /* 166C 80010E6C 00000000 */   nop
    /* 1670 80010E70 C943000C */  jal        Task_Run
    /* 1674 80010E74 00000000 */   nop
    /* 1678 80010E78 000002AE */  sw         $v0, 0x0($s0)
  .L80010E7C:
    /* 167C 80010E7C 01003126 */  addiu      $s1, $s1, 0x1
    /* 1680 80010E80 2A103202 */  slt        $v0, $s1, $s2
    /* 1684 80010E84 F6FF4014 */  bnez       $v0, .L80010E60
    /* 1688 80010E88 04001026 */   addiu     $s0, $s0, 0x4
  .L80010E8C:
    /* 168C 80010E8C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1690 80010E90 1800B28F */  lw         $s2, 0x18($sp)
    /* 1694 80010E94 1400B18F */  lw         $s1, 0x14($sp)
    /* 1698 80010E98 1000B08F */  lw         $s0, 0x10($sp)
    /* 169C 80010E9C 0800E003 */  jr         $ra
    /* 16A0 80010EA0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Task_RunChildren
