nonmatching func_8001ECE4, 0x5C

glabel func_8001ECE4
    /* F4E4 8001ECE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F4E8 8001ECE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* F4EC 8001ECEC 21808000 */  addu       $s0, $a0, $zero
    /* F4F0 8001ECF0 1400BFAF */  sw         $ra, 0x14($sp)
    /* F4F4 8001ECF4 2C00028E */  lw         $v0, 0x2C($s0)
    /* F4F8 8001ECF8 00000000 */  nop
    /* F4FC 8001ECFC 0400428C */  lw         $v0, 0x4($v0)
    /* F500 8001ED00 00000000 */  nop
    /* F504 8001ED04 0A004010 */  beqz       $v0, .L8001ED30
    /* F508 8001ED08 00000000 */   nop
    /* F50C 8001ED0C 6F7F000C */  jal        Gfx_AttachModel
    /* F510 8001ED10 5B000524 */   addiu     $a1, $zero, 0x5B
    /* F514 8001ED14 4882000C */  jal        func_80020920
    /* F518 8001ED18 21200002 */   addu      $a0, $s0, $zero
    /* F51C 8001ED1C 3480000C */  jal        func_800200D0
    /* F520 8001ED20 21200002 */   addu      $a0, $s0, $zero
    /* F524 8001ED24 21200002 */  addu       $a0, $s0, $zero
    /* F528 8001ED28 4481000C */  jal        func_80020510
    /* F52C 8001ED2C 01000524 */   addiu     $a1, $zero, 0x1
  .L8001ED30:
    /* F530 8001ED30 1400BF8F */  lw         $ra, 0x14($sp)
    /* F534 8001ED34 1000B08F */  lw         $s0, 0x10($sp)
    /* F538 8001ED38 0800E003 */  jr         $ra
    /* F53C 8001ED3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001ECE4
