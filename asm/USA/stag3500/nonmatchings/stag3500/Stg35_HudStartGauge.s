nonmatching Stg35_HudStartGauge, 0x8C

glabel Stg35_HudStartGauge
    /* 57B0 80068B10 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 57B4 80068B14 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 57B8 80068B18 21988000 */  addu       $s3, $a0, $zero
    /* 57BC 80068B1C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 57C0 80068B20 2190A000 */  addu       $s2, $a1, $zero
    /* 57C4 80068B24 08070424 */  addiu      $a0, $zero, 0x708
    /* 57C8 80068B28 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 57CC 80068B2C 2130A000 */  addu       $a2, $a1, $zero
    /* 57D0 80068B30 2000BFAF */  sw         $ra, 0x20($sp)
    /* 57D4 80068B34 1400B1AF */  sw         $s1, 0x14($sp)
    /* 57D8 80068B38 4445000C */  jal        Task_FindFirst
    /* 57DC 80068B3C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 57E0 80068B40 21884000 */  addu       $s1, $v0, $zero
    /* 57E4 80068B44 0E002012 */  beqz       $s1, .L80068B80
    /* 57E8 80068B48 21202002 */   addu      $a0, $s1, $zero
    /* 57EC 80068B4C 2C00308E */  lw         $s0, 0x2C($s1)
    /* 57F0 80068B50 7745000C */  jal        Task_SetState1
    /* 57F4 80068B54 02000524 */   addiu     $a1, $zero, 0x2
    /* 57F8 80068B58 21180000 */  addu       $v1, $zero, $zero
    /* 57FC 80068B5C 21284002 */  addu       $a1, $s2, $zero
    /* 5800 80068B60 080033AE */  sw         $s3, 0x8($s1)
  .L80068B64:
    /* 5804 80068B64 0000A28C */  lw         $v0, 0x0($a1)
    /* 5808 80068B68 0400A524 */  addiu      $a1, $a1, 0x4
    /* 580C 80068B6C 01006324 */  addiu      $v1, $v1, 0x1
    /* 5810 80068B70 5C0002AE */  sw         $v0, 0x5C($s0)
    /* 5814 80068B74 06006228 */  slti       $v0, $v1, 0x6
    /* 5818 80068B78 FAFF4014 */  bnez       $v0, .L80068B64
    /* 581C 80068B7C 04001026 */   addiu     $s0, $s0, 0x4
  .L80068B80:
    /* 5820 80068B80 2000BF8F */  lw         $ra, 0x20($sp)
    /* 5824 80068B84 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5828 80068B88 1800B28F */  lw         $s2, 0x18($sp)
    /* 582C 80068B8C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5830 80068B90 1000B08F */  lw         $s0, 0x10($sp)
    /* 5834 80068B94 0800E003 */  jr         $ra
    /* 5838 80068B98 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg35_HudStartGauge
