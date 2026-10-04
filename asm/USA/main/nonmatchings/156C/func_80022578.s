nonmatching func_80022578, 0x4C

glabel func_80022578
    /* 12D78 80022578 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12D7C 8002257C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12D80 80022580 21800000 */  addu       $s0, $zero, $zero
    /* 12D84 80022584 1400BFAF */  sw         $ra, 0x14($sp)
    /* 12D88 80022588 4689000C */  jal        Beetle_GetPart
    /* 12D8C 8002258C 02000424 */   addiu     $a0, $zero, 0x2
    /* 12D90 80022590 D1FF4324 */  addiu      $v1, $v0, -0x2F
    /* 12D94 80022594 0600622C */  sltiu      $v0, $v1, 0x6
    /* 12D98 80022598 04004010 */  beqz       $v0, .L800225AC
    /* 12D9C 8002259C 0480023C */   lui       $v0, %hi(Beetle_PartDigiCapacity)
    /* 12DA0 800225A0 FC164224 */  addiu      $v0, $v0, %lo(Beetle_PartDigiCapacity)
    /* 12DA4 800225A4 21106200 */  addu       $v0, $v1, $v0
    /* 12DA8 800225A8 00005090 */  lbu        $s0, 0x0($v0)
  .L800225AC:
    /* 12DAC 800225AC 00000000 */  nop
    /* 12DB0 800225B0 21100002 */  addu       $v0, $s0, $zero
    /* 12DB4 800225B4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 12DB8 800225B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 12DBC 800225BC 0800E003 */  jr         $ra
    /* 12DC0 800225C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80022578
