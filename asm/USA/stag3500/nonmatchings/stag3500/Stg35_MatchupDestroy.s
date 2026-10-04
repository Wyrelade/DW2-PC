nonmatching Stg35_MatchupDestroy, 0x80

glabel Stg35_MatchupDestroy
    /* 1790 80064AF0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1794 80064AF4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1798 80064AF8 21988000 */  addu       $s3, $a0, $zero
    /* 179C 80064AFC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 17A0 80064B00 1800B2AF */  sw         $s2, 0x18($sp)
    /* 17A4 80064B04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 17A8 80064B08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17AC 80064B0C 2C00728E */  lw         $s2, 0x2C($s3)
    /* 17B0 80064B10 21800000 */  addu       $s0, $zero, $zero
    /* 17B4 80064B14 21884002 */  addu       $s1, $s2, $zero
  .L80064B18:
    /* 17B8 80064B18 5A98010C */  jal        Stg35_PartsFree
    /* 17BC 80064B1C 21202002 */   addu      $a0, $s1, $zero
    /* 17C0 80064B20 01001026 */  addiu      $s0, $s0, 0x1
    /* 17C4 80064B24 FCFF001A */  blez       $s0, .L80064B18
    /* 17C8 80064B28 04003126 */   addiu     $s1, $s1, 0x4
    /* 17CC 80064B2C 21800000 */  addu       $s0, $zero, $zero
    /* 17D0 80064B30 04001124 */  addiu      $s1, $zero, 0x4
  .L80064B34:
    /* 17D4 80064B34 C695010C */  jal        Stg35_TextFree
    /* 17D8 80064B38 21205102 */   addu      $a0, $s2, $s1
    /* 17DC 80064B3C 01001026 */  addiu      $s0, $s0, 0x1
    /* 17E0 80064B40 0E00022A */  slti       $v0, $s0, 0xE
    /* 17E4 80064B44 FBFF4014 */  bnez       $v0, .L80064B34
    /* 17E8 80064B48 04003126 */   addiu     $s1, $s1, 0x4
    /* 17EC 80064B4C 5C44000C */  jal        Task_DefaultDestroy
    /* 17F0 80064B50 21206002 */   addu      $a0, $s3, $zero
    /* 17F4 80064B54 2000BF8F */  lw         $ra, 0x20($sp)
    /* 17F8 80064B58 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 17FC 80064B5C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1800 80064B60 1400B18F */  lw         $s1, 0x14($sp)
    /* 1804 80064B64 1000B08F */  lw         $s0, 0x10($sp)
    /* 1808 80064B68 0800E003 */  jr         $ra
    /* 180C 80064B6C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg35_MatchupDestroy
