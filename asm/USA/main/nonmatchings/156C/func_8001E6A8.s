nonmatching func_8001E6A8, 0x5C

glabel func_8001E6A8
    /* EEA8 8001E6A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EEAC 8001E6AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* EEB0 8001E6B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* EEB4 8001E6B4 9F79000C */  jal        func_8001E67C
    /* EEB8 8001E6B8 21808000 */   addu      $s0, $a0, $zero
    /* EEBC 8001E6BC 688E000C */  jal        Cd_GetFileEntry
    /* EEC0 8001E6C0 00240200 */   sll       $a0, $v0, 16
    /* EEC4 8001E6C4 21184000 */  addu       $v1, $v0, $zero
  .L8001E6C8:
    /* EEC8 8001E6C8 0400628C */  lw         $v0, 0x4($v1)
    /* EECC 8001E6CC 00000000 */  nop
    /* EED0 8001E6D0 42100200 */  srl        $v0, $v0, 1
    /* EED4 8001E6D4 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* EED8 8001E6D8 05004010 */  beqz       $v0, .L8001E6F0
    /* EEDC 8001E6DC 00000000 */   nop
    /* EEE0 8001E6E0 04005010 */  beq        $v0, $s0, .L8001E6F4
    /* EEE4 8001E6E4 21106000 */   addu      $v0, $v1, $zero
    /* EEE8 8001E6E8 B2790008 */  j          .L8001E6C8
    /* EEEC 8001E6EC 28006324 */   addiu     $v1, $v1, 0x28
  .L8001E6F0:
    /* EEF0 8001E6F0 21100000 */  addu       $v0, $zero, $zero
  .L8001E6F4:
    /* EEF4 8001E6F4 1400BF8F */  lw         $ra, 0x14($sp)
    /* EEF8 8001E6F8 1000B08F */  lw         $s0, 0x10($sp)
    /* EEFC 8001E6FC 0800E003 */  jr         $ra
    /* EF00 8001E700 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E6A8
