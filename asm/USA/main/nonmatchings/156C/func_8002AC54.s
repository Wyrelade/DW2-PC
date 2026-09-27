nonmatching func_8002AC54, 0x74

glabel func_8002AC54
    /* 1B454 8002AC54 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1B458 8002AC58 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1B45C 8002AC5C FFFF9130 */  andi       $s1, $a0, 0xFFFF
    /* 1B460 8002AC60 21202002 */  addu       $a0, $s1, $zero
    /* 1B464 8002AC64 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1B468 8002AC68 FFFFB030 */  andi       $s0, $a1, 0xFFFF
    /* 1B46C 8002AC6C 21280002 */  addu       $a1, $s0, $zero
    /* 1B470 8002AC70 FFFFC630 */  andi       $a2, $a2, 0xFFFF
    /* 1B474 8002AC74 3800A297 */  lhu        $v0, 0x38($sp)
    /* 1B478 8002AC78 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 1B47C 8002AC7C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1B480 8002AC80 32AB000C */  jal        func_8002ACC8
    /* 1B484 8002AC84 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1B488 8002AC88 E1AE000C */  jal        func_8002BB84
    /* 1B48C 8002AC8C 00000000 */   nop
    /* 1B490 8002AC90 21202002 */  addu       $a0, $s1, $zero
    /* 1B494 8002AC94 0680013C */  lui        $at, %hi(D_8006198C)
    /* 1B498 8002AC98 8C1920A4 */  sh         $zero, %lo(D_8006198C)($at)
    /* 1B49C 8002AC9C 93AB000C */  jal        func_8002AE4C
    /* 1B4A0 8002ACA0 21280002 */   addu      $a1, $s0, $zero
    /* 1B4A4 8002ACA4 ADAC000C */  jal        GsSetDrawBuffClip
    /* 1B4A8 8002ACA8 00000000 */   nop
    /* 1B4AC 8002ACAC 69AC000C */  jal        GsSetDrawBuffOffset
    /* 1B4B0 8002ACB0 00000000 */   nop
    /* 1B4B4 8002ACB4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1B4B8 8002ACB8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1B4BC 8002ACBC 1800B08F */  lw         $s0, 0x18($sp)
    /* 1B4C0 8002ACC0 0800E003 */  jr         $ra
    /* 1B4C4 8002ACC4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002AC54
