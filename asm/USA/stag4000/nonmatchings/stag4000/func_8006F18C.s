nonmatching func_8006F18C, 0x3C

glabel func_8006F18C
    /* BE2C 8006F18C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BE30 8006F190 1000B0AF */  sw         $s0, 0x10($sp)
    /* BE34 8006F194 21808000 */  addu       $s0, $a0, $zero
    /* BE38 8006F198 1400BFAF */  sw         $ra, 0x14($sp)
    /* BE3C 8006F19C 60070286 */  lh         $v0, 0x760($s0)
    /* BE40 8006F1A0 00000000 */  nop
    /* BE44 8006F1A4 04004010 */  beqz       $v0, .L8006F1B8
    /* BE48 8006F1A8 50070426 */   addiu     $a0, $s0, 0x750
    /* BE4C 8006F1AC CB9D000C */  jal        LoadImage
    /* BE50 8006F1B0 40000526 */   addiu     $a1, $s0, 0x40
    /* BE54 8006F1B4 600700A6 */  sh         $zero, 0x760($s0)
  .L8006F1B8:
    /* BE58 8006F1B8 1400BF8F */  lw         $ra, 0x14($sp)
    /* BE5C 8006F1BC 1000B08F */  lw         $s0, 0x10($sp)
    /* BE60 8006F1C0 0800E003 */  jr         $ra
    /* BE64 8006F1C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F18C
