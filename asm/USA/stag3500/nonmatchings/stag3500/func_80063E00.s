nonmatching func_80063E00, 0x74

glabel func_80063E00
    /* AA0 80063E00 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* AA4 80063E04 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* AA8 80063E08 1800B2AF */  sw         $s2, 0x18($sp)
    /* AAC 80063E0C 1400B1AF */  sw         $s1, 0x14($sp)
    /* AB0 80063E10 1000B0AF */  sw         $s0, 0x10($sp)
    /* AB4 80063E14 2C00928C */  lw         $s2, 0x2C($a0)
    /* AB8 80063E18 00000000 */  nop
    /* ABC 80063E1C E002428E */  lw         $v0, 0x2E0($s2)
    /* AC0 80063E20 00000000 */  nop
    /* AC4 80063E24 0D004018 */  blez       $v0, .L80063E5C
    /* AC8 80063E28 21800000 */   addu      $s0, $zero, $zero
    /* ACC 80063E2C 21884002 */  addu       $s1, $s2, $zero
  .L80063E30:
    /* AD0 80063E30 6002248E */  lw         $a0, 0x260($s1)
    /* AD4 80063E34 00000000 */  nop
    /* AD8 80063E38 03008010 */  beqz       $a0, .L80063E48
    /* ADC 80063E3C 00000000 */   nop
    /* AE0 80063E40 888F000C */  jal        Cd_FreeFile
    /* AE4 80063E44 00000000 */   nop
  .L80063E48:
    /* AE8 80063E48 E002428E */  lw         $v0, 0x2E0($s2)
    /* AEC 80063E4C 01001026 */  addiu      $s0, $s0, 0x1
    /* AF0 80063E50 2A100202 */  slt        $v0, $s0, $v0
    /* AF4 80063E54 F6FF4014 */  bnez       $v0, .L80063E30
    /* AF8 80063E58 04003126 */   addiu     $s1, $s1, 0x4
  .L80063E5C:
    /* AFC 80063E5C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* B00 80063E60 1800B28F */  lw         $s2, 0x18($sp)
    /* B04 80063E64 1400B18F */  lw         $s1, 0x14($sp)
    /* B08 80063E68 1000B08F */  lw         $s0, 0x10($sp)
    /* B0C 80063E6C 0800E003 */  jr         $ra
    /* B10 80063E70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80063E00
