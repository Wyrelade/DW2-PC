nonmatching func_8001ED84, 0x50

glabel func_8001ED84
    /* F584 8001ED84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F588 8001ED88 1000B0AF */  sw         $s0, 0x10($sp)
    /* F58C 8001ED8C 21808000 */  addu       $s0, $a0, $zero
    /* F590 8001ED90 1400BFAF */  sw         $ra, 0x14($sp)
    /* F594 8001ED94 828E000C */  jal        Cd_GetFileOrNull
    /* F598 8001ED98 5B020424 */   addiu     $a0, $zero, 0x25B
    /* F59C 8001ED9C 21200002 */  addu       $a0, $s0, $zero
    /* F5A0 8001EDA0 507B000C */  jal        func_8001ED40
    /* F5A4 8001EDA4 21804000 */   addu      $s0, $v0, $zero
    /* F5A8 8001EDA8 03004014 */  bnez       $v0, .L8001EDB8
    /* F5AC 8001EDAC 00000000 */   nop
    /* F5B0 8001EDB0 717B0008 */  j          .L8001EDC4
    /* F5B4 8001EDB4 21100000 */   addu      $v0, $zero, $zero
  .L8001EDB8:
    /* F5B8 8001EDB8 2400428C */  lw         $v0, 0x24($v0)
    /* F5BC 8001EDBC 00000000 */  nop
    /* F5C0 8001EDC0 21105000 */  addu       $v0, $v0, $s0
  .L8001EDC4:
    /* F5C4 8001EDC4 1400BF8F */  lw         $ra, 0x14($sp)
    /* F5C8 8001EDC8 1000B08F */  lw         $s0, 0x10($sp)
    /* F5CC 8001EDCC 0800E003 */  jr         $ra
    /* F5D0 8001EDD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001ED84
