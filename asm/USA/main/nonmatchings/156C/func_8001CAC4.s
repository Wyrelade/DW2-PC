nonmatching func_8001CAC4, 0xBC

glabel func_8001CAC4
    /* D2C4 8001CAC4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* D2C8 8001CAC8 2400B1AF */  sw         $s1, 0x24($sp)
    /* D2CC 8001CACC 21888000 */  addu       $s1, $a0, $zero
    /* D2D0 8001CAD0 2800BFAF */  sw         $ra, 0x28($sp)
    /* D2D4 8001CAD4 2000B0AF */  sw         $s0, 0x20($sp)
    /* D2D8 8001CAD8 0000248E */  lw         $a0, 0x0($s1)
    /* D2DC 8001CADC 688E000C */  jal        Cd_GetFileEntry
    /* D2E0 8001CAE0 00000000 */   nop
    /* D2E4 8001CAE4 04005024 */  addiu      $s0, $v0, 0x4
    /* D2E8 8001CAE8 0000028E */  lw         $v0, 0x0($s0)
    /* D2EC 8001CAEC 04001026 */  addiu      $s0, $s0, 0x4
    /* D2F0 8001CAF0 08004330 */  andi       $v1, $v0, 0x8
    /* D2F4 8001CAF4 10006010 */  beqz       $v1, .L8001CB38
    /* D2F8 8001CAF8 07004230 */   andi      $v0, $v0, 0x7
    /* D2FC 8001CAFC 0B004010 */  beqz       $v0, .L8001CB2C
    /* D300 8001CB00 1000A427 */   addiu     $a0, $sp, 0x10
    /* D304 8001CB04 0C000526 */  addiu      $a1, $s0, 0xC
    /* D308 8001CB08 1000A0A7 */  sh         $zero, 0x10($sp)
    /* D30C 8001CB0C 14002296 */  lhu        $v0, 0x14($s1)
    /* D310 8001CB10 00010324 */  addiu      $v1, $zero, 0x100
    /* D314 8001CB14 1400A3A7 */  sh         $v1, 0x14($sp)
    /* D318 8001CB18 01000324 */  addiu      $v1, $zero, 0x1
    /* D31C 8001CB1C 1600A3A7 */  sh         $v1, 0x16($sp)
    /* D320 8001CB20 E0014224 */  addiu      $v0, $v0, 0x1E0
    /* D324 8001CB24 CB9D000C */  jal        LoadImage
    /* D328 8001CB28 1200A2A7 */   sh        $v0, 0x12($sp)
  .L8001CB2C:
    /* D32C 8001CB2C 0000028E */  lw         $v0, 0x0($s0)
    /* D330 8001CB30 00000000 */  nop
    /* D334 8001CB34 21800202 */  addu       $s0, $s0, $v0
  .L8001CB38:
    /* D338 8001CB38 18002296 */  lhu        $v0, 0x18($s1)
    /* D33C 8001CB3C 00000000 */  nop
    /* D340 8001CB40 1800A2A7 */  sh         $v0, 0x18($sp)
    /* D344 8001CB44 1C002296 */  lhu        $v0, 0x1C($s1)
    /* D348 8001CB48 00000000 */  nop
    /* D34C 8001CB4C 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* D350 8001CB50 08000296 */  lhu        $v0, 0x8($s0)
    /* D354 8001CB54 1800A427 */  addiu      $a0, $sp, 0x18
    /* D358 8001CB58 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* D35C 8001CB5C 0A000296 */  lhu        $v0, 0xA($s0)
    /* D360 8001CB60 0C000526 */  addiu      $a1, $s0, 0xC
    /* D364 8001CB64 CB9D000C */  jal        LoadImage
    /* D368 8001CB68 1E00A2A7 */   sh        $v0, 0x1E($sp)
    /* D36C 8001CB6C 2800BF8F */  lw         $ra, 0x28($sp)
    /* D370 8001CB70 2400B18F */  lw         $s1, 0x24($sp)
    /* D374 8001CB74 2000B08F */  lw         $s0, 0x20($sp)
    /* D378 8001CB78 0800E003 */  jr         $ra
    /* D37C 8001CB7C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8001CAC4
