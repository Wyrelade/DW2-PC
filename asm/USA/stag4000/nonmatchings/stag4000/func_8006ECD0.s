nonmatching func_8006ECD0, 0x8C

glabel func_8006ECD0
    /* B970 8006ECD0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B974 8006ECD4 1400B1AF */  sw         $s1, 0x14($sp)
    /* B978 8006ECD8 2000BFAF */  sw         $ra, 0x20($sp)
    /* B97C 8006ECDC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B980 8006ECE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* B984 8006ECE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* B988 8006ECE8 68079384 */  lh         $s3, 0x768($a0)
    /* B98C 8006ECEC 66079284 */  lh         $s2, 0x766($a0)
    /* B990 8006ECF0 1300601A */  blez       $s3, .L8006ED40
    /* B994 8006ECF4 21880000 */   addu      $s1, $zero, $zero
  .L8006ECF8:
    /* B998 8006ECF8 0D00401A */  blez       $s2, .L8006ED30
    /* B99C 8006ECFC 21800000 */   addu      $s0, $zero, $zero
    /* B9A0 8006ED00 21200002 */  addu       $a0, $s0, $zero
  .L8006ED04:
    /* B9A4 8006ED04 F8C0010C */  jal        func_800703E0
    /* B9A8 8006ED08 21282002 */   addu      $a1, $s1, $zero
    /* B9AC 8006ED0C 21200002 */  addu       $a0, $s0, $zero
    /* B9B0 8006ED10 21282002 */  addu       $a1, $s1, $zero
    /* B9B4 8006ED14 42130200 */  srl        $v0, $v0, 13
    /* B9B8 8006ED18 E1BA010C */  jal        func_8006EB84
    /* B9BC 8006ED1C 01004630 */   andi      $a2, $v0, 0x1
    /* B9C0 8006ED20 01001026 */  addiu      $s0, $s0, 0x1
    /* B9C4 8006ED24 2A101202 */  slt        $v0, $s0, $s2
    /* B9C8 8006ED28 F6FF4014 */  bnez       $v0, .L8006ED04
    /* B9CC 8006ED2C 21200002 */   addu      $a0, $s0, $zero
  .L8006ED30:
    /* B9D0 8006ED30 01003126 */  addiu      $s1, $s1, 0x1
    /* B9D4 8006ED34 2A103302 */  slt        $v0, $s1, $s3
    /* B9D8 8006ED38 EFFF4014 */  bnez       $v0, .L8006ECF8
    /* B9DC 8006ED3C 00000000 */   nop
  .L8006ED40:
    /* B9E0 8006ED40 2000BF8F */  lw         $ra, 0x20($sp)
    /* B9E4 8006ED44 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B9E8 8006ED48 1800B28F */  lw         $s2, 0x18($sp)
    /* B9EC 8006ED4C 1400B18F */  lw         $s1, 0x14($sp)
    /* B9F0 8006ED50 1000B08F */  lw         $s0, 0x10($sp)
    /* B9F4 8006ED54 0800E003 */  jr         $ra
    /* B9F8 8006ED58 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006ECD0
