nonmatching _SsSetNrpnVabAttr9, 0xB4

glabel _SsSetNrpnVabAttr9
    /* 246F4 80033EF4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 246F8 80033EF8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 246FC 80033EFC 00940400 */  sll        $s2, $a0, 16
    /* 24700 80033F00 03941200 */  sra        $s2, $s2, 16
    /* 24704 80033F04 21204002 */  addu       $a0, $s2, $zero
    /* 24708 80033F08 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2470C 80033F0C 008C0500 */  sll        $s1, $a1, 16
    /* 24710 80033F10 038C1100 */  sra        $s1, $s1, 16
    /* 24714 80033F14 21282002 */  addu       $a1, $s1, $zero
    /* 24718 80033F18 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2471C 80033F1C 00840600 */  sll        $s0, $a2, 16
    /* 24720 80033F20 03841000 */  sra        $s0, $s0, 16
    /* 24724 80033F24 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24728 80033F28 7000B393 */  lbu        $s3, 0x70($sp)
    /* 2472C 80033F2C 21300002 */  addu       $a2, $s0, $zero
    /* 24730 80033F30 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24734 80033F34 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24738 80033F38 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 2473C 80033F3C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24740 80033F40 59D8000C */  jal        SsUtGetVagAtr
    /* 24744 80033F44 21388002 */   addu      $a3, $s4, $zero
    /* 24748 80033F48 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 2474C 80033F4C 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 24750 80033F50 C9CE000C */  jal        _SsUtResolveADSR
    /* 24754 80033F54 1000A627 */   addiu     $a2, $sp, 0x10
    /* 24758 80033F58 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2475C 80033F5C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24760 80033F60 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24764 80033F64 01000224 */  addiu      $v0, $zero, 0x1
    /* 24768 80033F68 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 2476C 80033F6C E0CE000C */  jal        _SsUtBuildADSR
    /* 24770 80033F70 1600B3A7 */   sh        $s3, 0x16($sp)
    /* 24774 80033F74 21204002 */  addu       $a0, $s2, $zero
    /* 24778 80033F78 21282002 */  addu       $a1, $s1, $zero
    /* 2477C 80033F7C 21300002 */  addu       $a2, $s0, $zero
    /* 24780 80033F80 65D9000C */  jal        SsUtSetVagAtr
    /* 24784 80033F84 21388002 */   addu      $a3, $s4, $zero
    /* 24788 80033F88 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 2478C 80033F8C 3800B48F */  lw         $s4, 0x38($sp)
    /* 24790 80033F90 3400B38F */  lw         $s3, 0x34($sp)
    /* 24794 80033F94 3000B28F */  lw         $s2, 0x30($sp)
    /* 24798 80033F98 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2479C 80033F9C 2800B08F */  lw         $s0, 0x28($sp)
    /* 247A0 80033FA0 0800E003 */  jr         $ra
    /* 247A4 80033FA4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _SsSetNrpnVabAttr9
    /* 247A8 80033FA8 00000000 */  nop
    /* 247AC 80033FAC 00000000 */  nop
    /* 247B0 80033FB0 00000000 */  nop
