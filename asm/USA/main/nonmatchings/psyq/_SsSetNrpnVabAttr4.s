nonmatching _SsSetNrpnVabAttr4, 0xB0

glabel _SsSetNrpnVabAttr4
    /* 24274 80033A74 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 24278 80033A78 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2427C 80033A7C 00940400 */  sll        $s2, $a0, 16
    /* 24280 80033A80 03941200 */  sra        $s2, $s2, 16
    /* 24284 80033A84 21204002 */  addu       $a0, $s2, $zero
    /* 24288 80033A88 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2428C 80033A8C 008C0500 */  sll        $s1, $a1, 16
    /* 24290 80033A90 038C1100 */  sra        $s1, $s1, 16
    /* 24294 80033A94 21282002 */  addu       $a1, $s1, $zero
    /* 24298 80033A98 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2429C 80033A9C 00840600 */  sll        $s0, $a2, 16
    /* 242A0 80033AA0 03841000 */  sra        $s0, $s0, 16
    /* 242A4 80033AA4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 242A8 80033AA8 7000B393 */  lbu        $s3, 0x70($sp)
    /* 242AC 80033AAC 21300002 */  addu       $a2, $s0, $zero
    /* 242B0 80033AB0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 242B4 80033AB4 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 242B8 80033AB8 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 242BC 80033ABC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 242C0 80033AC0 59D8000C */  jal        SsUtGetVagAtr
    /* 242C4 80033AC4 21388002 */   addu      $a3, $s4, $zero
    /* 242C8 80033AC8 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 242CC 80033ACC 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 242D0 80033AD0 C9CE000C */  jal        _SsUtResolveADSR
    /* 242D4 80033AD4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 242D8 80033AD8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 242DC 80033ADC 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 242E0 80033AE0 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 242E4 80033AE4 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 242E8 80033AE8 E0CE000C */  jal        _SsUtBuildADSR
    /* 242EC 80033AEC 1000B3A7 */   sh        $s3, 0x10($sp)
    /* 242F0 80033AF0 21204002 */  addu       $a0, $s2, $zero
    /* 242F4 80033AF4 21282002 */  addu       $a1, $s1, $zero
    /* 242F8 80033AF8 21300002 */  addu       $a2, $s0, $zero
    /* 242FC 80033AFC 65D9000C */  jal        SsUtSetVagAtr
    /* 24300 80033B00 21388002 */   addu      $a3, $s4, $zero
    /* 24304 80033B04 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24308 80033B08 3800B48F */  lw         $s4, 0x38($sp)
    /* 2430C 80033B0C 3400B38F */  lw         $s3, 0x34($sp)
    /* 24310 80033B10 3000B28F */  lw         $s2, 0x30($sp)
    /* 24314 80033B14 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24318 80033B18 2800B08F */  lw         $s0, 0x28($sp)
    /* 2431C 80033B1C 0800E003 */  jr         $ra
    /* 24320 80033B20 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _SsSetNrpnVabAttr4
