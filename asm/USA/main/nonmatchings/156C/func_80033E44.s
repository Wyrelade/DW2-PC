nonmatching func_80033E44, 0xB0

glabel func_80033E44
    /* 24644 80033E44 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 24648 80033E48 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2464C 80033E4C 00940400 */  sll        $s2, $a0, 16
    /* 24650 80033E50 03941200 */  sra        $s2, $s2, 16
    /* 24654 80033E54 21204002 */  addu       $a0, $s2, $zero
    /* 24658 80033E58 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2465C 80033E5C 008C0500 */  sll        $s1, $a1, 16
    /* 24660 80033E60 038C1100 */  sra        $s1, $s1, 16
    /* 24664 80033E64 21282002 */  addu       $a1, $s1, $zero
    /* 24668 80033E68 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2466C 80033E6C 00840600 */  sll        $s0, $a2, 16
    /* 24670 80033E70 03841000 */  sra        $s0, $s0, 16
    /* 24674 80033E74 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24678 80033E78 7000B393 */  lbu        $s3, 0x70($sp)
    /* 2467C 80033E7C 21300002 */  addu       $a2, $s0, $zero
    /* 24680 80033E80 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24684 80033E84 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24688 80033E88 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 2468C 80033E8C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24690 80033E90 59D8000C */  jal        SsUtGetVagAtr
    /* 24694 80033E94 21388002 */   addu      $a3, $s4, $zero
    /* 24698 80033E98 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 2469C 80033E9C 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 246A0 80033EA0 C9CE000C */  jal        _SsUtResolveADSR
    /* 246A4 80033EA4 1000A627 */   addiu     $a2, $sp, 0x10
    /* 246A8 80033EA8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 246AC 80033EAC 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 246B0 80033EB0 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 246B4 80033EB4 1C00A0A7 */  sh         $zero, 0x1C($sp)
    /* 246B8 80033EB8 E0CE000C */  jal        _SsUtBuildADSR
    /* 246BC 80033EBC 1600B3A7 */   sh        $s3, 0x16($sp)
    /* 246C0 80033EC0 21204002 */  addu       $a0, $s2, $zero
    /* 246C4 80033EC4 21282002 */  addu       $a1, $s1, $zero
    /* 246C8 80033EC8 21300002 */  addu       $a2, $s0, $zero
    /* 246CC 80033ECC 65D9000C */  jal        SsUtSetVagAtr
    /* 246D0 80033ED0 21388002 */   addu      $a3, $s4, $zero
    /* 246D4 80033ED4 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 246D8 80033ED8 3800B48F */  lw         $s4, 0x38($sp)
    /* 246DC 80033EDC 3400B38F */  lw         $s3, 0x34($sp)
    /* 246E0 80033EE0 3000B28F */  lw         $s2, 0x30($sp)
    /* 246E4 80033EE4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 246E8 80033EE8 2800B08F */  lw         $s0, 0x28($sp)
    /* 246EC 80033EEC 0800E003 */  jr         $ra
    /* 246F0 80033EF0 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80033E44
