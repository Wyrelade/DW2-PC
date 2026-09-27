nonmatching func_80033FB4, 0xB0

glabel func_80033FB4
    /* 247B4 80033FB4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 247B8 80033FB8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 247BC 80033FBC 00940400 */  sll        $s2, $a0, 16
    /* 247C0 80033FC0 03941200 */  sra        $s2, $s2, 16
    /* 247C4 80033FC4 21204002 */  addu       $a0, $s2, $zero
    /* 247C8 80033FC8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 247CC 80033FCC 008C0500 */  sll        $s1, $a1, 16
    /* 247D0 80033FD0 038C1100 */  sra        $s1, $s1, 16
    /* 247D4 80033FD4 21282002 */  addu       $a1, $s1, $zero
    /* 247D8 80033FD8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 247DC 80033FDC 00840600 */  sll        $s0, $a2, 16
    /* 247E0 80033FE0 03841000 */  sra        $s0, $s0, 16
    /* 247E4 80033FE4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 247E8 80033FE8 7000B393 */  lbu        $s3, 0x70($sp)
    /* 247EC 80033FEC 21300002 */  addu       $a2, $s0, $zero
    /* 247F0 80033FF0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 247F4 80033FF4 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 247F8 80033FF8 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 247FC 80033FFC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24800 80034000 59D8000C */  jal        SsUtGetVagAtr
    /* 24804 80034004 21388002 */   addu      $a3, $s4, $zero
    /* 24808 80034008 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 2480C 8003400C 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 24810 80034010 C9CE000C */  jal        _SsUtResolveADSR
    /* 24814 80034014 1000A627 */   addiu     $a2, $sp, 0x10
    /* 24818 80034018 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2481C 8003401C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24820 80034020 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24824 80034024 1E00A0A7 */  sh         $zero, 0x1E($sp)
    /* 24828 80034028 E0CE000C */  jal        _SsUtBuildADSR
    /* 2482C 8003402C 1800B3A7 */   sh        $s3, 0x18($sp)
    /* 24830 80034030 21204002 */  addu       $a0, $s2, $zero
    /* 24834 80034034 21282002 */  addu       $a1, $s1, $zero
    /* 24838 80034038 21300002 */  addu       $a2, $s0, $zero
    /* 2483C 8003403C 65D9000C */  jal        SsUtSetVagAtr
    /* 24840 80034040 21388002 */   addu      $a3, $s4, $zero
    /* 24844 80034044 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24848 80034048 3800B48F */  lw         $s4, 0x38($sp)
    /* 2484C 8003404C 3400B38F */  lw         $s3, 0x34($sp)
    /* 24850 80034050 3000B28F */  lw         $s2, 0x30($sp)
    /* 24854 80034054 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24858 80034058 2800B08F */  lw         $s0, 0x28($sp)
    /* 2485C 8003405C 0800E003 */  jr         $ra
    /* 24860 80034060 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80033FB4
