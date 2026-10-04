nonmatching Stg10_EndScreenDraw, 0x64

glabel Stg10_EndScreenDraw
    /* AC4 80063E24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AC8 80063E28 1400BFAF */  sw         $ra, 0x14($sp)
    /* ACC 80063E2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* AD0 80063E30 2C00908C */  lw         $s0, 0x2C($a0)
    /* AD4 80063E34 688E000C */  jal        Cd_GetFileEntry
    /* AD8 80063E38 760D043C */   lui       $a0, (0xD760000 >> 16)
    /* ADC 80063E3C 21204000 */  addu       $a0, $v0, $zero
    /* AE0 80063E40 0000828C */  lw         $v0, 0x0($a0)
    /* AE4 80063E44 00000000 */  nop
    /* AE8 80063E48 09004010 */  beqz       $v0, .L80063E70
    /* AEC 80063E4C 21188000 */   addu      $v1, $a0, $zero
  .L80063E50:
    /* AF0 80063E50 00000292 */  lbu        $v0, 0x0($s0)
    /* AF4 80063E54 00000000 */  nop
    /* AF8 80063E58 0C0062A0 */  sb         $v0, 0xC($v1)
    /* AFC 80063E5C 28006324 */  addiu      $v1, $v1, 0x28
    /* B00 80063E60 0000628C */  lw         $v0, 0x0($v1)
    /* B04 80063E64 00000000 */  nop
    /* B08 80063E68 F9FF4014 */  bnez       $v0, .L80063E50
    /* B0C 80063E6C 00000000 */   nop
  .L80063E70:
    /* B10 80063E70 2976000C */  jal        func_8001D8A4
    /* B14 80063E74 00000000 */   nop
    /* B18 80063E78 1400BF8F */  lw         $ra, 0x14($sp)
    /* B1C 80063E7C 1000B08F */  lw         $s0, 0x10($sp)
    /* B20 80063E80 0800E003 */  jr         $ra
    /* B24 80063E84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg10_EndScreenDraw
