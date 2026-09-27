nonmatching Card_CloseFile, 0x44

glabel Card_CloseFile
    /* 2EDCC 8003E5CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2EDD0 8003E5D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2EDD4 8003E5D4 0680103C */  lui        $s0, %hi(D_80062F94)
    /* 2EDD8 8003E5D8 942F1026 */  addiu      $s0, $s0, %lo(D_80062F94)
    /* 2EDDC 8003E5DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2EDE0 8003E5E0 0000048E */  lw         $a0, 0x0($s0)
    /* 2EDE4 8003E5E4 00000000 */  nop
    /* 2EDE8 8003E5E8 05008004 */  bltz       $a0, .L8003E600
    /* 2EDEC 8003E5EC 00000000 */   nop
    /* 2EDF0 8003E5F0 69FD000C */  jal        close
    /* 2EDF4 8003E5F4 00000000 */   nop
    /* 2EDF8 8003E5F8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2EDFC 8003E5FC 000002AE */  sw         $v0, 0x0($s0)
  .L8003E600:
    /* 2EE00 8003E600 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2EE04 8003E604 1000B08F */  lw         $s0, 0x10($sp)
    /* 2EE08 8003E608 0800E003 */  jr         $ra
    /* 2EE0C 8003E60C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Card_CloseFile
