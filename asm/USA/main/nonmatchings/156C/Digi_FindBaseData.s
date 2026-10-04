nonmatching Digi_FindBaseData, 0x4C

glabel Digi_FindBaseData
    /* E0C4 8001D8C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E0C8 8001D8C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* E0CC 8001D8CC 21808000 */  addu       $s0, $a0, $zero
    /* E0D0 8001D8D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* E0D4 8001D8D4 828E000C */  jal        Cd_GetFileOrNull
    /* E0D8 8001D8D8 6C0C0424 */   addiu     $a0, $zero, 0xC6C
  .L8001D8DC:
    /* E0DC 8001D8DC 00004384 */  lh         $v1, 0x0($v0)
    /* E0E0 8001D8E0 00000000 */  nop
    /* E0E4 8001D8E4 05006010 */  beqz       $v1, .L8001D8FC
    /* E0E8 8001D8E8 00000000 */   nop
    /* E0EC 8001D8EC 04007010 */  beq        $v1, $s0, .L8001D900
    /* E0F0 8001D8F0 00000000 */   nop
    /* E0F4 8001D8F4 37760008 */  j          .L8001D8DC
    /* E0F8 8001D8F8 12004224 */   addiu     $v0, $v0, 0x12
  .L8001D8FC:
    /* E0FC 8001D8FC 21100000 */  addu       $v0, $zero, $zero
  .L8001D900:
    /* E100 8001D900 1400BF8F */  lw         $ra, 0x14($sp)
    /* E104 8001D904 1000B08F */  lw         $s0, 0x10($sp)
    /* E108 8001D908 0800E003 */  jr         $ra
    /* E10C 8001D90C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_FindBaseData
