nonmatching SetDefDrawEnv, 0xB4

glabel SetDefDrawEnv
    /* 1B1F4 8002A9F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1B1F8 8002A9F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1B1FC 8002A9FC 3800B28F */  lw         $s2, 0x38($sp)
    /* 1B200 8002AA00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B204 8002AA04 21888000 */  addu       $s1, $a0, $zero
    /* 1B208 8002AA08 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1B20C 8002AA0C 2198A000 */  addu       $s3, $a1, $zero
    /* 1B210 8002AA10 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1B214 8002AA14 21A0C000 */  addu       $s4, $a2, $zero
    /* 1B218 8002AA18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B21C 8002AA1C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1B220 8002AA20 0EC6000C */  jal        GetVideoMode
    /* 1B224 8002AA24 2180E000 */   addu      $s0, $a3, $zero
    /* 1B228 8002AA28 01000324 */  addiu      $v1, $zero, 0x1
    /* 1B22C 8002AA2C 000033A6 */  sh         $s3, 0x0($s1)
    /* 1B230 8002AA30 020034A6 */  sh         $s4, 0x2($s1)
    /* 1B234 8002AA34 040030A6 */  sh         $s0, 0x4($s1)
    /* 1B238 8002AA38 0C0020A6 */  sh         $zero, 0xC($s1)
    /* 1B23C 8002AA3C 0E0020A6 */  sh         $zero, 0xE($s1)
    /* 1B240 8002AA40 100020A6 */  sh         $zero, 0x10($s1)
    /* 1B244 8002AA44 120020A6 */  sh         $zero, 0x12($s1)
    /* 1B248 8002AA48 190020A2 */  sb         $zero, 0x19($s1)
    /* 1B24C 8002AA4C 1A0020A2 */  sb         $zero, 0x1A($s1)
    /* 1B250 8002AA50 1B0020A2 */  sb         $zero, 0x1B($s1)
    /* 1B254 8002AA54 160023A2 */  sb         $v1, 0x16($s1)
    /* 1B258 8002AA58 03004010 */  beqz       $v0, .L8002AA68
    /* 1B25C 8002AA5C 060032A6 */   sh        $s2, 0x6($s1)
    /* 1B260 8002AA60 9BAA0008 */  j          .L8002AA6C
    /* 1B264 8002AA64 2101422A */   slti      $v0, $s2, 0x121
  .L8002AA68:
    /* 1B268 8002AA68 0101422A */  slti       $v0, $s2, 0x101
  .L8002AA6C:
    /* 1B26C 8002AA6C 170022A2 */  sb         $v0, 0x17($s1)
    /* 1B270 8002AA70 21102002 */  addu       $v0, $s1, $zero
    /* 1B274 8002AA74 0A000324 */  addiu      $v1, $zero, 0xA
    /* 1B278 8002AA78 080053A4 */  sh         $s3, 0x8($v0)
    /* 1B27C 8002AA7C 0A0054A4 */  sh         $s4, 0xA($v0)
    /* 1B280 8002AA80 140043A4 */  sh         $v1, 0x14($v0)
    /* 1B284 8002AA84 180040A0 */  sb         $zero, 0x18($v0)
    /* 1B288 8002AA88 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1B28C 8002AA8C 2000B48F */  lw         $s4, 0x20($sp)
    /* 1B290 8002AA90 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1B294 8002AA94 1800B28F */  lw         $s2, 0x18($sp)
    /* 1B298 8002AA98 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B29C 8002AA9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B2A0 8002AAA0 0800E003 */  jr         $ra
    /* 1B2A4 8002AAA4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel SetDefDrawEnv
    /* 1B2A8 8002AAA8 00000000 */  nop
    /* 1B2AC 8002AAAC 00000000 */  nop
    /* 1B2B0 8002AAB0 00000000 */  nop
