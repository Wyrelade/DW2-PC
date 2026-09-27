nonmatching func_8006A168, 0x168

glabel func_8006A168
    /* 6E08 8006A168 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 6E0C 8006A16C 40100400 */  sll        $v0, $a0, 1
    /* 6E10 8006A170 21104400 */  addu       $v0, $v0, $a0
    /* 6E14 8006A174 C0180200 */  sll        $v1, $v0, 3
    /* 6E18 8006A178 23186400 */  subu       $v1, $v1, $a0
    /* 6E1C 8006A17C 80180300 */  sll        $v1, $v1, 2
    /* 6E20 8006A180 0780053C */  lui        $a1, %hi(D_8006AABA)
    /* 6E24 8006A184 BAAAA524 */  addiu      $a1, $a1, %lo(D_8006AABA)
    /* 6E28 8006A188 5000B4AF */  sw         $s4, 0x50($sp)
    /* 6E2C 8006A18C 21A06500 */  addu       $s4, $v1, $a1
    /* 6E30 8006A190 80100200 */  sll        $v0, $v0, 2
    /* 6E34 8006A194 23104400 */  subu       $v0, $v0, $a0
    /* 6E38 8006A198 80100200 */  sll        $v0, $v0, 2
    /* 6E3C 8006A19C 0602A524 */  addiu      $a1, $a1, 0x206
    /* 6E40 8006A1A0 4800B2AF */  sw         $s2, 0x48($sp)
    /* 6E44 8006A1A4 21904500 */  addu       $s2, $v0, $a1
    /* 6E48 8006A1A8 4000B0AF */  sw         $s0, 0x40($sp)
    /* 6E4C 8006A1AC 21800000 */  addu       $s0, $zero, $zero
    /* 6E50 8006A1B0 64000424 */  addiu      $a0, $zero, 0x64
    /* 6E54 8006A1B4 1800A327 */  addiu      $v1, $sp, 0x18
    /* 6E58 8006A1B8 5400BFAF */  sw         $ra, 0x54($sp)
    /* 6E5C 8006A1BC 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 6E60 8006A1C0 4400B1AF */  sw         $s1, 0x44($sp)
  .L8006A1C4:
    /* 6E64 8006A1C4 21105002 */  addu       $v0, $s2, $s0
    /* 6E68 8006A1C8 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 6E6C 8006A1CC 000064AC */  sw         $a0, 0x0($v1)
    /* 6E70 8006A1D0 01001026 */  addiu      $s0, $s0, 0x1
    /* 6E74 8006A1D4 0600022A */  slti       $v0, $s0, 0x6
    /* 6E78 8006A1D8 FAFF4014 */  bnez       $v0, .L8006A1C4
    /* 6E7C 8006A1DC 04006324 */   addiu     $v1, $v1, 0x4
    /* 6E80 8006A1E0 21980000 */  addu       $s3, $zero, $zero
    /* 6E84 8006A1E4 21806002 */  addu       $s0, $s3, $zero
    /* 6E88 8006A1E8 21889002 */  addu       $s1, $s4, $s0
  .L8006A1EC:
    /* 6E8C 8006A1EC 00002292 */  lbu        $v0, 0x0($s1)
    /* 6E90 8006A1F0 00000000 */  nop
    /* 6E94 8006A1F4 1E004010 */  beqz       $v0, .L8006A270
    /* 6E98 8006A1F8 21204000 */   addu      $a0, $v0, $zero
    /* 6E9C 8006A1FC 3C00A227 */  addiu      $v0, $sp, 0x3C
    /* 6EA0 8006A200 3000A527 */  addiu      $a1, $sp, 0x30
    /* 6EA4 8006A204 3400A627 */  addiu      $a2, $sp, 0x34
    /* 6EA8 8006A208 3800A727 */  addiu      $a3, $sp, 0x38
    /* 6EAC 8006A20C 35A8010C */  jal        func_8006A0D4
    /* 6EB0 8006A210 1000A2AF */   sw        $v0, 0x10($sp)
    /* 6EB4 8006A214 3000A58F */  lw         $a1, 0x30($sp)
    /* 6EB8 8006A218 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6EBC 8006A21C 1400A210 */  beq        $a1, $v0, .L8006A270
    /* 6EC0 8006A220 80100500 */   sll       $v0, $a1, 2
    /* 6EC4 8006A224 1800A327 */  addiu      $v1, $sp, 0x18
    /* 6EC8 8006A228 21186200 */  addu       $v1, $v1, $v0
    /* 6ECC 8006A22C 0000628C */  lw         $v0, 0x0($v1)
    /* 6ED0 8006A230 3400A48F */  lw         $a0, 0x34($sp)
    /* 6ED4 8006A234 00000000 */  nop
    /* 6ED8 8006A238 2A108200 */  slt        $v0, $a0, $v0
    /* 6EDC 8006A23C 0C004010 */  beqz       $v0, .L8006A270
    /* 6EE0 8006A240 21104502 */   addu      $v0, $s2, $a1
    /* 6EE4 8006A244 000064AC */  sw         $a0, 0x0($v1)
    /* 6EE8 8006A248 00002392 */  lbu        $v1, 0x0($s1)
    /* 6EEC 8006A24C 01001324 */  addiu      $s3, $zero, 0x1
    /* 6EF0 8006A250 0C0043A0 */  sb         $v1, 0xC($v0)
    /* 6EF4 8006A254 3000A28F */  lw         $v0, 0x30($sp)
    /* 6EF8 8006A258 3C00A397 */  lhu        $v1, 0x3C($sp)
    /* 6EFC 8006A25C 3800A497 */  lhu        $a0, 0x38($sp)
    /* 6F00 8006A260 04106202 */  sllv       $v0, $v0, $s3
    /* 6F04 8006A264 21104202 */  addu       $v0, $s2, $v0
    /* 6F08 8006A268 1E0043A4 */  sh         $v1, 0x1E($v0)
    /* 6F0C 8006A26C 120044A4 */  sh         $a0, 0x12($v0)
  .L8006A270:
    /* 6F10 8006A270 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F14 8006A274 0C00022A */  slti       $v0, $s0, 0xC
    /* 6F18 8006A278 DCFF4014 */  bnez       $v0, .L8006A1EC
    /* 6F1C 8006A27C 21889002 */   addu      $s1, $s4, $s0
    /* 6F20 8006A280 0B006016 */  bnez       $s3, .L8006A2B0
    /* 6F24 8006A284 0780023C */   lui       $v0, %hi(D_8006A6DC)
    /* 6F28 8006A288 DCA64224 */  addiu      $v0, $v0, %lo(D_8006A6DC)
    /* 6F2C 8006A28C 06004390 */  lbu        $v1, 0x6($v0)
    /* 6F30 8006A290 00000000 */  nop
    /* 6F34 8006A294 0C0043A2 */  sb         $v1, 0xC($s2)
    /* 6F38 8006A298 08004394 */  lhu        $v1, 0x8($v0)
    /* 6F3C 8006A29C 00000000 */  nop
    /* 6F40 8006A2A0 1E0043A6 */  sh         $v1, 0x1E($s2)
    /* 6F44 8006A2A4 0A004294 */  lhu        $v0, 0xA($v0)
    /* 6F48 8006A2A8 00000000 */  nop
    /* 6F4C 8006A2AC 120042A6 */  sh         $v0, 0x12($s2)
  .L8006A2B0:
    /* 6F50 8006A2B0 5400BF8F */  lw         $ra, 0x54($sp)
    /* 6F54 8006A2B4 5000B48F */  lw         $s4, 0x50($sp)
    /* 6F58 8006A2B8 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 6F5C 8006A2BC 4800B28F */  lw         $s2, 0x48($sp)
    /* 6F60 8006A2C0 4400B18F */  lw         $s1, 0x44($sp)
    /* 6F64 8006A2C4 4000B08F */  lw         $s0, 0x40($sp)
    /* 6F68 8006A2C8 0800E003 */  jr         $ra
    /* 6F6C 8006A2CC 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_8006A168
