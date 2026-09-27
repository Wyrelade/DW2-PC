nonmatching func_80067EC4, 0x68

glabel func_80067EC4
    /* 4B64 80067EC4 21280000 */  addu       $a1, $zero, $zero
    /* 4B68 80067EC8 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 4B6C 80067ECC 20E64424 */  addiu      $a0, $v0, %lo(D_8005E620)
    /* 4B70 80067ED0 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* 4B74 80067ED4 C03C4324 */  addiu      $v1, $v0, %lo(D_80073CC0)
  .L80067ED8:
    /* 4B78 80067ED8 18006290 */  lbu        $v0, 0x18($v1)
    /* 4B7C 80067EDC 00000000 */  nop
    /* 4B80 80067EE0 0300422C */  sltiu      $v0, $v0, 0x3
    /* 4B84 80067EE4 0A004014 */  bnez       $v0, .L80067F10
    /* 4B88 80067EE8 00000000 */   nop
    /* 4B8C 80067EEC 00018294 */  lhu        $v0, 0x100($a0)
    /* 4B90 80067EF0 00000000 */  nop
    /* 4B94 80067EF4 340062A4 */  sh         $v0, 0x34($v1)
    /* 4B98 80067EF8 02018294 */  lhu        $v0, 0x102($a0)
    /* 4B9C 80067EFC 00000000 */  nop
    /* 4BA0 80067F00 360062A4 */  sh         $v0, 0x36($v1)
    /* 4BA4 80067F04 04018294 */  lhu        $v0, 0x104($a0)
    /* 4BA8 80067F08 00000000 */  nop
    /* 4BAC 80067F0C 380062A4 */  sh         $v0, 0x38($v1)
  .L80067F10:
    /* 4BB0 80067F10 5C008424 */  addiu      $a0, $a0, 0x5C
    /* 4BB4 80067F14 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4BB8 80067F18 0300A228 */  slti       $v0, $a1, 0x3
    /* 4BBC 80067F1C EEFF4014 */  bnez       $v0, .L80067ED8
    /* 4BC0 80067F20 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 4BC4 80067F24 0800E003 */  jr         $ra
    /* 4BC8 80067F28 00000000 */   nop
endlabel func_80067EC4
