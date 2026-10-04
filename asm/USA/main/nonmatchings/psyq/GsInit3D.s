nonmatching GsInit3D, 0x74

glabel GsInit3D
    /* 1BCC4 8002B4C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BCC8 8002B4C8 0680023C */  lui        $v0, %hi(D_80061990)
    /* 1BCCC 8002B4CC 9019428C */  lw         $v0, %lo(D_80061990)($v0)
    /* 1BCD0 8002B4D0 0680043C */  lui        $a0, %hi(D_80061900)
    /* 1BCD4 8002B4D4 00198424 */  addiu      $a0, $a0, %lo(D_80061900)
    /* 1BCD8 8002B4D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1BCDC 8002B4DC C21F0200 */  srl        $v1, $v0, 31
    /* 1BCE0 8002B4E0 21104300 */  addu       $v0, $v0, $v1
    /* 1BCE4 8002B4E4 0680033C */  lui        $v1, %hi(D_80061994)
    /* 1BCE8 8002B4E8 9419638C */  lw         $v1, %lo(D_80061994)($v1)
    /* 1BCEC 8002B4EC 43100200 */  sra        $v0, $v0, 1
    /* 1BCF0 8002B4F0 000082A4 */  sh         $v0, 0x0($a0)
    /* 1BCF4 8002B4F4 C2170300 */  srl        $v0, $v1, 31
    /* 1BCF8 8002B4F8 21186200 */  addu       $v1, $v1, $v0
    /* 1BCFC 8002B4FC 43180300 */  sra        $v1, $v1, 1
    /* 1BD00 8002B500 69AC000C */  jal        GsSetDrawBuffOffset
    /* 1BD04 8002B504 020083A4 */   sh        $v1, 0x2($a0)
    /* 1BD08 8002B508 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1BD0C 8002B50C 0680013C */  lui        $at, %hi(D_800619A0)
    /* 1BD10 8002B510 A01922AC */  sw         $v0, %lo(D_800619A0)($at)
    /* 1BD14 8002B514 FF3F0224 */  addiu      $v0, $zero, 0x3FFF
    /* 1BD18 8002B518 0680013C */  lui        $at, %hi(D_8006199C)
    /* 1BD1C 8002B51C 9C1920AC */  sw         $zero, %lo(D_8006199C)($at)
    /* 1BD20 8002B520 0680013C */  lui        $at, %hi(D_80061998)
    /* 1BD24 8002B524 981922AC */  sw         $v0, %lo(D_80061998)($at)
    /* 1BD28 8002B528 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BD2C 8002B52C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1BD30 8002B530 0800E003 */  jr         $ra
    /* 1BD34 8002B534 00000000 */   nop
endlabel GsInit3D
    /* 1BD38 8002B538 00000000 */  nop
    /* 1BD3C 8002B53C 00000000 */  nop
    /* 1BD40 8002B540 00000000 */  nop
