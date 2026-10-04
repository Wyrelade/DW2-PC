nonmatching func_8001EEA4, 0x98

glabel func_8001EEA4
    /* F6A4 8001EEA4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F6A8 8001EEA8 1000B0AF */  sw         $s0, 0x10($sp)
    /* F6AC 8001EEAC 2180A000 */  addu       $s0, $a1, $zero
    /* F6B0 8001EEB0 1800B2AF */  sw         $s2, 0x18($sp)
    /* F6B4 8001EEB4 2190C000 */  addu       $s2, $a2, $zero
    /* F6B8 8001EEB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* F6BC 8001EEBC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* F6C0 8001EEC0 507B000C */  jal        Skill_FindById
    /* F6C4 8001EEC4 2188E000 */   addu      $s1, $a3, $zero
    /* F6C8 8001EEC8 21384000 */  addu       $a3, $v0, $zero
    /* F6CC 8001EECC 40801000 */  sll        $s0, $s0, 1
    /* F6D0 8001EED0 21300000 */  addu       $a2, $zero, $zero
    /* F6D4 8001EED4 01000326 */  addiu      $v1, $s0, 0x1
    /* F6D8 8001EED8 40100300 */  sll        $v0, $v1, 1
    /* F6DC 8001EEDC 21104300 */  addu       $v0, $v0, $v1
    /* F6E0 8001EEE0 40280200 */  sll        $a1, $v0, 1
    /* F6E4 8001EEE4 40101000 */  sll        $v0, $s0, 1
    /* F6E8 8001EEE8 21105000 */  addu       $v0, $v0, $s0
    /* F6EC 8001EEEC 40200200 */  sll        $a0, $v0, 1
  .L8001EEF0:
    /* F6F0 8001EEF0 2118E500 */  addu       $v1, $a3, $a1
    /* F6F4 8001EEF4 0200A524 */  addiu      $a1, $a1, 0x2
    /* F6F8 8001EEF8 2110E400 */  addu       $v0, $a3, $a0
    /* F6FC 8001EEFC 02008424 */  addiu      $a0, $a0, 0x2
    /* F700 8001EF00 2C004294 */  lhu        $v0, 0x2C($v0)
    /* F704 8001EF04 0100C624 */  addiu      $a2, $a2, 0x1
    /* F708 8001EF08 000042A6 */  sh         $v0, 0x0($s2)
    /* F70C 8001EF0C 2C006294 */  lhu        $v0, 0x2C($v1)
    /* F710 8001EF10 02005226 */  addiu      $s2, $s2, 0x2
    /* F714 8001EF14 000022A6 */  sh         $v0, 0x0($s1)
    /* F718 8001EF18 0300C228 */  slti       $v0, $a2, 0x3
    /* F71C 8001EF1C F4FF4014 */  bnez       $v0, .L8001EEF0
    /* F720 8001EF20 02003126 */   addiu     $s1, $s1, 0x2
    /* F724 8001EF24 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* F728 8001EF28 1800B28F */  lw         $s2, 0x18($sp)
    /* F72C 8001EF2C 1400B18F */  lw         $s1, 0x14($sp)
    /* F730 8001EF30 1000B08F */  lw         $s0, 0x10($sp)
    /* F734 8001EF34 0800E003 */  jr         $ra
    /* F738 8001EF38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001EEA4
