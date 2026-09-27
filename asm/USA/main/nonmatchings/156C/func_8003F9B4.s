nonmatching func_8003F9B4, 0x34

glabel func_8003F9B4
    /* 301B4 8003F9B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 301B8 8003F9B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 301BC 8003F9BC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 301C0 8003F9C0 81FE000C */  jal        _new_card
    /* 301C4 8003F9C4 21808000 */   addu      $s0, $a0, $zero
    /* 301C8 8003F9C8 21200002 */  addu       $a0, $s0, $zero
    /* 301CC 8003F9CC 3F000524 */  addiu      $a1, $zero, 0x3F
    /* 301D0 8003F9D0 7DFE000C */  jal        _card_write
    /* 301D4 8003F9D4 21300000 */   addu      $a2, $zero, $zero
    /* 301D8 8003F9D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 301DC 8003F9DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 301E0 8003F9E0 0800E003 */  jr         $ra
    /* 301E4 8003F9E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003F9B4
    /* 301E8 8003F9E8 00000000 */  nop
    /* 301EC 8003F9EC 00000000 */  nop
    /* 301F0 8003F9F0 00000000 */  nop
