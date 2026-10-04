nonmatching Skill_FindById, 0x44

glabel Skill_FindById
    /* F540 8001ED40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F544 8001ED44 1000B0AF */  sw         $s0, 0x10($sp)
    /* F548 8001ED48 21808000 */  addu       $s0, $a0, $zero
    /* F54C 8001ED4C 1400BFAF */  sw         $ra, 0x14($sp)
    /* F550 8001ED50 688E000C */  jal        Cd_GetFileEntry
    /* F554 8001ED54 5B02043C */   lui       $a0, (0x25B0000 >> 16)
  .L8001ED58:
    /* F558 8001ED58 00004384 */  lh         $v1, 0x0($v0)
    /* F55C 8001ED5C 00000000 */  nop
    /* F560 8001ED60 04007010 */  beq        $v1, $s0, .L8001ED74
    /* F564 8001ED64 00000000 */   nop
    /* F568 8001ED68 FBFF6014 */  bnez       $v1, .L8001ED58
    /* F56C 8001ED6C 44004224 */   addiu     $v0, $v0, 0x44
    /* F570 8001ED70 21100000 */  addu       $v0, $zero, $zero
  .L8001ED74:
    /* F574 8001ED74 1400BF8F */  lw         $ra, 0x14($sp)
    /* F578 8001ED78 1000B08F */  lw         $s0, 0x10($sp)
    /* F57C 8001ED7C 0800E003 */  jr         $ra
    /* F580 8001ED80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_FindById
