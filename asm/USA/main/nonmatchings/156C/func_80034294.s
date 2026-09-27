nonmatching func_80034294, 0x9C

glabel func_80034294
    /* 24A94 80034294 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 24A98 80034298 3000B2AF */  sw         $s2, 0x30($sp)
    /* 24A9C 8003429C 00940400 */  sll        $s2, $a0, 16
    /* 24AA0 800342A0 03941200 */  sra        $s2, $s2, 16
    /* 24AA4 800342A4 21204002 */  addu       $a0, $s2, $zero
    /* 24AA8 800342A8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 24AAC 800342AC 008C0500 */  sll        $s1, $a1, 16
    /* 24AB0 800342B0 038C1100 */  sra        $s1, $s1, 16
    /* 24AB4 800342B4 21282002 */  addu       $a1, $s1, $zero
    /* 24AB8 800342B8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 24ABC 800342BC 00840600 */  sll        $s0, $a2, 16
    /* 24AC0 800342C0 03841000 */  sra        $s0, $s0, 16
    /* 24AC4 800342C4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24AC8 800342C8 7000B38F */  lw         $s3, 0x70($sp)
    /* 24ACC 800342CC 21300002 */  addu       $a2, $s0, $zero
    /* 24AD0 800342D0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24AD4 800342D4 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24AD8 800342D8 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 24ADC 800342DC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24AE0 800342E0 59D8000C */  jal        func_80036164
    /* 24AE4 800342E4 21388002 */   addu      $a3, $s4, $zero
    /* 24AE8 800342E8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 24AEC 800342EC 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24AF0 800342F0 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24AF4 800342F4 E0CE000C */  jal        _SsUtBuildADSR
    /* 24AF8 800342F8 5600B3A3 */   sb        $s3, 0x56($sp)
    /* 24AFC 800342FC 21204002 */  addu       $a0, $s2, $zero
    /* 24B00 80034300 21282002 */  addu       $a1, $s1, $zero
    /* 24B04 80034304 21300002 */  addu       $a2, $s0, $zero
    /* 24B08 80034308 65D9000C */  jal        func_80036594
    /* 24B0C 8003430C 21388002 */   addu      $a3, $s4, $zero
    /* 24B10 80034310 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24B14 80034314 3800B48F */  lw         $s4, 0x38($sp)
    /* 24B18 80034318 3400B38F */  lw         $s3, 0x34($sp)
    /* 24B1C 8003431C 3000B28F */  lw         $s2, 0x30($sp)
    /* 24B20 80034320 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24B24 80034324 2800B08F */  lw         $s0, 0x28($sp)
    /* 24B28 80034328 0800E003 */  jr         $ra
    /* 24B2C 8003432C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80034294
    /* 24B30 80034330 00000000 */  nop
