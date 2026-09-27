nonmatching func_800711C4, 0x40

glabel func_800711C4
    /* DE64 800711C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DE68 800711C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* DE6C 800711CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* DE70 800711D0 448E000C */  jal        Rand_Next
    /* DE74 800711D4 21808000 */   addu      $s0, $a0, $zero
    /* DE78 800711D8 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* DE7C 800711DC 18005000 */  mult       $v0, $s0
    /* DE80 800711E0 12100000 */  mflo       $v0
    /* DE84 800711E4 02004104 */  bgez       $v0, .L800711F0
    /* DE88 800711E8 00000000 */   nop
    /* DE8C 800711EC FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L800711F0:
    /* DE90 800711F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* DE94 800711F4 1000B08F */  lw         $s0, 0x10($sp)
    /* DE98 800711F8 03130200 */  sra        $v0, $v0, 12
    /* DE9C 800711FC 0800E003 */  jr         $ra
    /* DEA0 80071200 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800711C4
