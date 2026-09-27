nonmatching func_8006AD8C, 0x6C

glabel func_8006AD8C
    /* 7A2C 8006AD8C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7A30 8006AD90 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7A34 8006AD94 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7A38 8006AD98 2C00908C */  lw         $s0, 0x2C($a0)
    /* 7A3C 8006AD9C 419D010C */  jal        func_80067504
    /* 7A40 8006ADA0 00000000 */   nop
    /* 7A44 8006ADA4 03004588 */  lwl        $a1, 0x3($v0)
    /* 7A48 8006ADA8 00004598 */  lwr        $a1, 0x0($v0)
    /* 7A4C 8006ADAC 00000000 */  nop
    /* 7A50 8006ADB0 1300A5AB */  swl        $a1, 0x13($sp)
    /* 7A54 8006ADB4 1000A5BB */  swr        $a1, 0x10($sp)
    /* 7A58 8006ADB8 1000A297 */  lhu        $v0, 0x10($sp)
    /* 7A5C 8006ADBC 00000000 */  nop
    /* 7A60 8006ADC0 040002A6 */  sh         $v0, 0x4($s0)
    /* 7A64 8006ADC4 1200A397 */  lhu        $v1, 0x12($sp)
    /* 7A68 8006ADC8 01000224 */  addiu      $v0, $zero, 0x1
    /* 7A6C 8006ADCC 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 7A70 8006ADD0 080002A6 */  sh         $v0, 0x8($s0)
    /* 7A74 8006ADD4 01000224 */  addiu      $v0, $zero, 0x1
    /* 7A78 8006ADD8 740002AE */  sw         $v0, 0x74($s0)
    /* 7A7C 8006ADDC 5C0000AE */  sw         $zero, 0x5C($s0)
    /* 7A80 8006ADE0 180000AE */  sw         $zero, 0x18($s0)
    /* 7A84 8006ADE4 060003A6 */  sh         $v1, 0x6($s0)
    /* 7A88 8006ADE8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7A8C 8006ADEC 1800B08F */  lw         $s0, 0x18($sp)
    /* 7A90 8006ADF0 0800E003 */  jr         $ra
    /* 7A94 8006ADF4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006AD8C
