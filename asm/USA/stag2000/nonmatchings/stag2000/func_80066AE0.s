nonmatching func_80066AE0, 0x68

glabel func_80066AE0
    /* 3780 80066AE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3784 80066AE4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3788 80066AE8 21280000 */  addu       $a1, $zero, $zero
    /* 378C 80066AEC 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 3790 80066AF0 20E64324 */  addiu      $v1, $v0, %lo(Save_GameState)
  .L80066AF4:
    /* 3794 80066AF4 E4006290 */  lbu        $v0, 0xE4($v1)
    /* 3798 80066AF8 00000000 */  nop
    /* 379C 80066AFC 0200422C */  sltiu      $v0, $v0, 0x2
    /* 37A0 80066B00 07004014 */  bnez       $v0, .L80066B20
    /* 37A4 80066B04 00000000 */   nop
    /* 37A8 80066B08 E5006290 */  lbu        $v0, 0xE5($v1)
    /* 37AC 80066B0C 00000000 */  nop
    /* 37B0 80066B10 04004414 */  bne        $v0, $a0, .L80066B24
    /* 37B4 80066B14 0100A524 */   addiu     $a1, $a1, 0x1
    /* 37B8 80066B18 CC9A0108 */  j          .L80066B30
    /* 37BC 80066B1C E40060A0 */   sb        $zero, 0xE4($v1)
  .L80066B20:
    /* 37C0 80066B20 0100A524 */  addiu      $a1, $a1, 0x1
  .L80066B24:
    /* 37C4 80066B24 2400A228 */  slti       $v0, $a1, 0x24
    /* 37C8 80066B28 F2FF4014 */  bnez       $v0, .L80066AF4
    /* 37CC 80066B2C 5C006324 */   addiu     $v1, $v1, 0x5C
  .L80066B30:
    /* 37D0 80066B30 B98A000C */  jal        Digi_SortRoster
    /* 37D4 80066B34 00000000 */   nop
    /* 37D8 80066B38 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37DC 80066B3C 00000000 */  nop
    /* 37E0 80066B40 0800E003 */  jr         $ra
    /* 37E4 80066B44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80066AE0
