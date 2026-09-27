nonmatching func_80072250, 0x68

glabel func_80072250
    /* EEF0 80072250 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EEF4 80072254 1400BFAF */  sw         $ra, 0x14($sp)
    /* EEF8 80072258 1000B0AF */  sw         $s0, 0x10($sp)
    /* EEFC 8007225C 2C00908C */  lw         $s0, 0x2C($a0)
    /* EF00 80072260 00000000 */  nop
    /* EF04 80072264 B800028E */  lw         $v0, 0xB8($s0)
    /* EF08 80072268 00000000 */  nop
    /* EF0C 8007226C 0E004010 */  beqz       $v0, .L800722A8
    /* EF10 80072270 00000000 */   nop
    /* EF14 80072274 B400048E */  lw         $a0, 0xB4($s0)
    /* EF18 80072278 00000000 */  nop
    /* EF1C 8007227C 0000858C */  lw         $a1, 0x0($a0)
    /* EF20 80072280 0400868C */  lw         $a2, 0x4($a0)
    /* EF24 80072284 0800878C */  lw         $a3, 0x8($a0)
    /* EF28 80072288 4BC8010C */  jal        func_8007212C
    /* EF2C 8007228C 0C008424 */   addiu     $a0, $a0, 0xC
    /* EF30 80072290 B800028E */  lw         $v0, 0xB8($s0)
    /* EF34 80072294 B400038E */  lw         $v1, 0xB4($s0)
    /* EF38 80072298 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* EF3C 8007229C 2C006324 */  addiu      $v1, $v1, 0x2C
    /* EF40 800722A0 B80002AE */  sw         $v0, 0xB8($s0)
    /* EF44 800722A4 B40003AE */  sw         $v1, 0xB4($s0)
  .L800722A8:
    /* EF48 800722A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* EF4C 800722AC 1000B08F */  lw         $s0, 0x10($sp)
    /* EF50 800722B0 0800E003 */  jr         $ra
    /* EF54 800722B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80072250
