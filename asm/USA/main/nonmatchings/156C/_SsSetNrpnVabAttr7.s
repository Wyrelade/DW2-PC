nonmatching _SsSetNrpnVabAttr7, 0xAC

glabel _SsSetNrpnVabAttr7
    /* 24594 80033D94 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 24598 80033D98 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2459C 80033D9C 00940400 */  sll        $s2, $a0, 16
    /* 245A0 80033DA0 03941200 */  sra        $s2, $s2, 16
    /* 245A4 80033DA4 21204002 */  addu       $a0, $s2, $zero
    /* 245A8 80033DA8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 245AC 80033DAC 008C0500 */  sll        $s1, $a1, 16
    /* 245B0 80033DB0 038C1100 */  sra        $s1, $s1, 16
    /* 245B4 80033DB4 21282002 */  addu       $a1, $s1, $zero
    /* 245B8 80033DB8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 245BC 80033DBC 00840600 */  sll        $s0, $a2, 16
    /* 245C0 80033DC0 03841000 */  sra        $s0, $s0, 16
    /* 245C4 80033DC4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 245C8 80033DC8 7000B393 */  lbu        $s3, 0x70($sp)
    /* 245CC 80033DCC 21300002 */  addu       $a2, $s0, $zero
    /* 245D0 80033DD0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 245D4 80033DD4 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 245D8 80033DD8 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 245DC 80033DDC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 245E0 80033DE0 59D8000C */  jal        SsUtGetVagAtr
    /* 245E4 80033DE4 21388002 */   addu      $a3, $s4, $zero
    /* 245E8 80033DE8 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 245EC 80033DEC 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 245F0 80033DF0 C9CE000C */  jal        _SsUtResolveADSR
    /* 245F4 80033DF4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 245F8 80033DF8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 245FC 80033DFC 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24600 80033E00 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24604 80033E04 E0CE000C */  jal        _SsUtBuildADSR
    /* 24608 80033E08 1400B3A7 */   sh        $s3, 0x14($sp)
    /* 2460C 80033E0C 21204002 */  addu       $a0, $s2, $zero
    /* 24610 80033E10 21282002 */  addu       $a1, $s1, $zero
    /* 24614 80033E14 21300002 */  addu       $a2, $s0, $zero
    /* 24618 80033E18 65D9000C */  jal        SsUtSetVagAtr
    /* 2461C 80033E1C 21388002 */   addu      $a3, $s4, $zero
    /* 24620 80033E20 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24624 80033E24 3800B48F */  lw         $s4, 0x38($sp)
    /* 24628 80033E28 3400B38F */  lw         $s3, 0x34($sp)
    /* 2462C 80033E2C 3000B28F */  lw         $s2, 0x30($sp)
    /* 24630 80033E30 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24634 80033E34 2800B08F */  lw         $s0, 0x28($sp)
    /* 24638 80033E38 0800E003 */  jr         $ra
    /* 2463C 80033E3C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _SsSetNrpnVabAttr7
    /* 24640 80033E40 00000000 */  nop
