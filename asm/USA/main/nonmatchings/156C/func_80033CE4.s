nonmatching func_80033CE4, 0xAC

glabel func_80033CE4
    /* 244E4 80033CE4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 244E8 80033CE8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 244EC 80033CEC 00940400 */  sll        $s2, $a0, 16
    /* 244F0 80033CF0 03941200 */  sra        $s2, $s2, 16
    /* 244F4 80033CF4 21204002 */  addu       $a0, $s2, $zero
    /* 244F8 80033CF8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 244FC 80033CFC 008C0500 */  sll        $s1, $a1, 16
    /* 24500 80033D00 038C1100 */  sra        $s1, $s1, 16
    /* 24504 80033D04 21282002 */  addu       $a1, $s1, $zero
    /* 24508 80033D08 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2450C 80033D0C 00840600 */  sll        $s0, $a2, 16
    /* 24510 80033D10 03841000 */  sra        $s0, $s0, 16
    /* 24514 80033D14 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24518 80033D18 7000B393 */  lbu        $s3, 0x70($sp)
    /* 2451C 80033D1C 21300002 */  addu       $a2, $s0, $zero
    /* 24520 80033D20 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24524 80033D24 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24528 80033D28 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 2452C 80033D2C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24530 80033D30 59D8000C */  jal        SsUtGetVagAtr
    /* 24534 80033D34 21388002 */   addu      $a3, $s4, $zero
    /* 24538 80033D38 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 2453C 80033D3C 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 24540 80033D40 C9CE000C */  jal        _SsUtResolveADSR
    /* 24544 80033D44 1000A627 */   addiu     $a2, $sp, 0x10
    /* 24548 80033D48 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2454C 80033D4C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24550 80033D50 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24554 80033D54 E0CE000C */  jal        _SsUtBuildADSR
    /* 24558 80033D58 1200B3A7 */   sh        $s3, 0x12($sp)
    /* 2455C 80033D5C 21204002 */  addu       $a0, $s2, $zero
    /* 24560 80033D60 21282002 */  addu       $a1, $s1, $zero
    /* 24564 80033D64 21300002 */  addu       $a2, $s0, $zero
    /* 24568 80033D68 65D9000C */  jal        SsUtSetVagAtr
    /* 2456C 80033D6C 21388002 */   addu      $a3, $s4, $zero
    /* 24570 80033D70 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24574 80033D74 3800B48F */  lw         $s4, 0x38($sp)
    /* 24578 80033D78 3400B38F */  lw         $s3, 0x34($sp)
    /* 2457C 80033D7C 3000B28F */  lw         $s2, 0x30($sp)
    /* 24580 80033D80 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24584 80033D84 2800B08F */  lw         $s0, 0x28($sp)
    /* 24588 80033D88 0800E003 */  jr         $ra
    /* 2458C 80033D8C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80033CE4
    /* 24590 80033D90 00000000 */  nop
