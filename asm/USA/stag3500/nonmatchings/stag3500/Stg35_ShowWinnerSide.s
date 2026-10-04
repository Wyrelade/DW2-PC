nonmatching Stg35_ShowWinnerSide, 0xA4

glabel Stg35_ShowWinnerSide
    /* 1850 80064BB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1854 80064BB4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1858 80064BB8 2190A000 */  addu       $s2, $a1, $zero
    /* 185C 80064BBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1860 80064BC0 21880000 */  addu       $s1, $zero, $zero
    /* 1864 80064BC4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1868 80064BC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 186C 80064BCC 3400908C */  lw         $s0, 0x34($a0)
  .L80064BD0:
    /* 1870 80064BD0 00000000 */  nop
    /* 1874 80064BD4 2C00048E */  lw         $a0, 0x2C($s0)
    /* 1878 80064BD8 00000000 */  nop
    /* 187C 80064BDC 12008010 */  beqz       $a0, .L80064C28
    /* 1880 80064BE0 00000000 */   nop
    /* 1884 80064BE4 05004016 */  bnez       $s2, .L80064BFC
    /* 1888 80064BE8 0300222A */   slti      $v0, $s1, 0x3
    /* 188C 80064BEC 0C004010 */  beqz       $v0, .L80064C20
    /* 1890 80064BF0 00000000 */   nop
    /* 1894 80064BF4 01930108 */  j          .L80064C04
    /* 1898 80064BF8 00000000 */   nop
  .L80064BFC:
    /* 189C 80064BFC 08004014 */  bnez       $v0, .L80064C20
    /* 18A0 80064C00 00000000 */   nop
  .L80064C04:
    /* 18A4 80064C04 359D010C */  jal        Stg35_FighterSetVisible
    /* 18A8 80064C08 01000524 */   addiu     $a1, $zero, 0x1
    /* 18AC 80064C0C 2C00048E */  lw         $a0, 0x2C($s0)
    /* 18B0 80064C10 3E9D010C */  jal        Stg35_FighterQueueHomeReset
    /* 18B4 80064C14 04001026 */   addiu     $s0, $s0, 0x4
    /* 18B8 80064C18 0C930108 */  j          .L80064C30
    /* 18BC 80064C1C 01003126 */   addiu     $s1, $s1, 0x1
  .L80064C20:
    /* 18C0 80064C20 359D010C */  jal        Stg35_FighterSetVisible
    /* 18C4 80064C24 21280000 */   addu      $a1, $zero, $zero
  .L80064C28:
    /* 18C8 80064C28 04001026 */  addiu      $s0, $s0, 0x4
    /* 18CC 80064C2C 01003126 */  addiu      $s1, $s1, 0x1
  .L80064C30:
    /* 18D0 80064C30 0600222A */  slti       $v0, $s1, 0x6
    /* 18D4 80064C34 E6FF4014 */  bnez       $v0, .L80064BD0
    /* 18D8 80064C38 00000000 */   nop
    /* 18DC 80064C3C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 18E0 80064C40 1800B28F */  lw         $s2, 0x18($sp)
    /* 18E4 80064C44 1400B18F */  lw         $s1, 0x14($sp)
    /* 18E8 80064C48 1000B08F */  lw         $s0, 0x10($sp)
    /* 18EC 80064C4C 0800E003 */  jr         $ra
    /* 18F0 80064C50 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg35_ShowWinnerSide
