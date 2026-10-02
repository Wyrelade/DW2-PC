nonmatching func_8002BB84, 0x4C

glabel func_8002BB84
    /* 1C384 8002BB84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C388 8002BB88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C38C 8002BB8C 97B3000C */  jal        func_8002CE5C
    /* 1C390 8002BB90 00000000 */   nop
    /* 1C394 8002BB94 21200000 */  addu       $a0, $zero, $zero
    /* 1C398 8002BB98 21280000 */  addu       $a1, $zero, $zero
    /* 1C39C 8002BB9C A1B5000C */  jal        SetFarColor
    /* 1C3A0 8002BBA0 21300000 */   addu      $a2, $zero, $zero
    /* 1C3A4 8002BBA4 21200000 */  addu       $a0, $zero, $zero
    /* 1C3A8 8002BBA8 A9B5000C */  jal        SetGeomOffset
    /* 1C3AC 8002BBAC 21280000 */   addu      $a1, $zero, $zero
    /* 1C3B0 8002BBB0 0680013C */  lui        $at, %hi(D_8006197E)
    /* 1C3B4 8002BBB4 7E1920A4 */  sh         $zero, %lo(D_8006197E)($at)
    /* 1C3B8 8002BBB8 0680013C */  lui        $at, %hi(D_8006197C)
    /* 1C3BC 8002BBBC 7C1920A4 */  sh         $zero, %lo(D_8006197C)($at)
    /* 1C3C0 8002BBC0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C3C4 8002BBC4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C3C8 8002BBC8 0800E003 */  jr         $ra
    /* 1C3CC 8002BBCC 00000000 */   nop
endlabel func_8002BB84
    /* 1C3D0 8002BBD0 00000000 */  nop
