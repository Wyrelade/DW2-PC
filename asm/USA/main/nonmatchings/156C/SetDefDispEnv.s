nonmatching SetDefDispEnv, 0x3C

glabel SetDefDispEnv
    /* 1B2B4 8002AAB4 1000A38F */  lw         $v1, 0x10($sp)
    /* 1B2B8 8002AAB8 21108000 */  addu       $v0, $a0, $zero
    /* 1B2BC 8002AABC 000045A4 */  sh         $a1, 0x0($v0)
    /* 1B2C0 8002AAC0 020046A4 */  sh         $a2, 0x2($v0)
    /* 1B2C4 8002AAC4 040047A4 */  sh         $a3, 0x4($v0)
    /* 1B2C8 8002AAC8 080040A4 */  sh         $zero, 0x8($v0)
    /* 1B2CC 8002AACC 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 1B2D0 8002AAD0 0C0040A4 */  sh         $zero, 0xC($v0)
    /* 1B2D4 8002AAD4 0E0040A4 */  sh         $zero, 0xE($v0)
    /* 1B2D8 8002AAD8 110040A0 */  sb         $zero, 0x11($v0)
    /* 1B2DC 8002AADC 100040A0 */  sb         $zero, 0x10($v0)
    /* 1B2E0 8002AAE0 130040A0 */  sb         $zero, 0x13($v0)
    /* 1B2E4 8002AAE4 120040A0 */  sb         $zero, 0x12($v0)
    /* 1B2E8 8002AAE8 0800E003 */  jr         $ra
    /* 1B2EC 8002AAEC 060043A4 */   sh        $v1, 0x6($v0)
endlabel SetDefDispEnv
    /* 1B2F0 8002AAF0 00000000 */  nop
