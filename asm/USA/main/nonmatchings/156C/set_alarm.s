nonmatching set_alarm, 0x34

glabel set_alarm
    /* 1A184 80029984 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1A188 80029988 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1A18C 8002998C ADC2000C */  jal        VSync
    /* 1A190 80029990 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1A194 80029994 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1A198 80029998 0580013C */  lui        $at, %hi(D_8004904C)
    /* 1A19C 8002999C 4C9022AC */  sw         $v0, %lo(D_8004904C)($at)
    /* 1A1A0 800299A0 0580013C */  lui        $at, %hi(D_80049050)
    /* 1A1A4 800299A4 509020AC */  sw         $zero, %lo(D_80049050)($at)
    /* 1A1A8 800299A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1A1AC 800299AC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1A1B0 800299B0 0800E003 */  jr         $ra
    /* 1A1B4 800299B4 00000000 */   nop
endlabel set_alarm
