nonmatching func_80033C24, 0xB4

glabel func_80033C24
    /* 24424 80033C24 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 24428 80033C28 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2442C 80033C2C 00940400 */  sll        $s2, $a0, 16
    /* 24430 80033C30 03941200 */  sra        $s2, $s2, 16
    /* 24434 80033C34 21204002 */  addu       $a0, $s2, $zero
    /* 24438 80033C38 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2443C 80033C3C 008C0500 */  sll        $s1, $a1, 16
    /* 24440 80033C40 038C1100 */  sra        $s1, $s1, 16
    /* 24444 80033C44 21282002 */  addu       $a1, $s1, $zero
    /* 24448 80033C48 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2444C 80033C4C 00840600 */  sll        $s0, $a2, 16
    /* 24450 80033C50 03841000 */  sra        $s0, $s0, 16
    /* 24454 80033C54 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24458 80033C58 7000B393 */  lbu        $s3, 0x70($sp)
    /* 2445C 80033C5C 21300002 */  addu       $a2, $s0, $zero
    /* 24460 80033C60 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24464 80033C64 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24468 80033C68 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 2446C 80033C6C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24470 80033C70 59D8000C */  jal        func_80036164
    /* 24474 80033C74 21388002 */   addu      $a3, $s4, $zero
    /* 24478 80033C78 5C00A497 */  lhu        $a0, 0x5C($sp)
    /* 2447C 80033C7C 5E00A597 */  lhu        $a1, 0x5E($sp)
    /* 24480 80033C80 C9CE000C */  jal        _SsUtResolveADSR
    /* 24484 80033C84 1000A627 */   addiu     $a2, $sp, 0x10
    /* 24488 80033C88 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2448C 80033C8C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24490 80033C90 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24494 80033C94 01000224 */  addiu      $v0, $zero, 0x1
    /* 24498 80033C98 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 2449C 80033C9C E0CE000C */  jal        _SsUtBuildADSR
    /* 244A0 80033CA0 1000B3A7 */   sh        $s3, 0x10($sp)
    /* 244A4 80033CA4 21204002 */  addu       $a0, $s2, $zero
    /* 244A8 80033CA8 21282002 */  addu       $a1, $s1, $zero
    /* 244AC 80033CAC 21300002 */  addu       $a2, $s0, $zero
    /* 244B0 80033CB0 65D9000C */  jal        func_80036594
    /* 244B4 80033CB4 21388002 */   addu      $a3, $s4, $zero
    /* 244B8 80033CB8 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 244BC 80033CBC 3800B48F */  lw         $s4, 0x38($sp)
    /* 244C0 80033CC0 3400B38F */  lw         $s3, 0x34($sp)
    /* 244C4 80033CC4 3000B28F */  lw         $s2, 0x30($sp)
    /* 244C8 80033CC8 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 244CC 80033CCC 2800B08F */  lw         $s0, 0x28($sp)
    /* 244D0 80033CD0 0800E003 */  jr         $ra
    /* 244D4 80033CD4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80033C24
    /* 244D8 80033CD8 00000000 */  nop
    /* 244DC 80033CDC 00000000 */  nop
    /* 244E0 80033CE0 00000000 */  nop
