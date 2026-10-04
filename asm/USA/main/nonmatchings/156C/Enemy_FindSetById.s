nonmatching Enemy_FindSetById, 0x50

glabel Enemy_FindSetById
    /* E318 8001DB18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E31C 8001DB1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* E320 8001DB20 21808000 */  addu       $s0, $a0, $zero
    /* E324 8001DB24 1400BFAF */  sw         $ra, 0x14($sp)
    /* E328 8001DB28 828E000C */  jal        Cd_GetFileOrNull
    /* E32C 8001DB2C 6F0C0424 */   addiu     $a0, $zero, 0xC6F
    /* E330 8001DB30 21184000 */  addu       $v1, $v0, $zero
  .L8001DB34:
    /* E334 8001DB34 00006290 */  lbu        $v0, 0x0($v1)
    /* E338 8001DB38 00000000 */  nop
    /* E33C 8001DB3C 05004010 */  beqz       $v0, .L8001DB54
    /* E340 8001DB40 00000000 */   nop
    /* E344 8001DB44 04005010 */  beq        $v0, $s0, .L8001DB58
    /* E348 8001DB48 21106000 */   addu      $v0, $v1, $zero
    /* E34C 8001DB4C CD760008 */  j          .L8001DB34
    /* E350 8001DB50 64006324 */   addiu     $v1, $v1, 0x64
  .L8001DB54:
    /* E354 8001DB54 21100000 */  addu       $v0, $zero, $zero
  .L8001DB58:
    /* E358 8001DB58 1400BF8F */  lw         $ra, 0x14($sp)
    /* E35C 8001DB5C 1000B08F */  lw         $s0, 0x10($sp)
    /* E360 8001DB60 0800E003 */  jr         $ra
    /* E364 8001DB64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Enemy_FindSetById
