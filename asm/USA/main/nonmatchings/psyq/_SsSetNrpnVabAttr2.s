nonmatching _SsSetNrpnVabAttr2, 0x8C

glabel _SsSetNrpnVabAttr2
    /* 24154 80033954 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 24158 80033958 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2415C 8003395C 00940400 */  sll        $s2, $a0, 16
    /* 24160 80033960 03941200 */  sra        $s2, $s2, 16
    /* 24164 80033964 21204002 */  addu       $a0, $s2, $zero
    /* 24168 80033968 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2416C 8003396C 008C0500 */  sll        $s1, $a1, 16
    /* 24170 80033970 038C1100 */  sra        $s1, $s1, 16
    /* 24174 80033974 21282002 */  addu       $a1, $s1, $zero
    /* 24178 80033978 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2417C 8003397C 00840600 */  sll        $s0, $a2, 16
    /* 24180 80033980 03841000 */  sra        $s0, $s0, 16
    /* 24184 80033984 2000B4AF */  sw         $s4, 0x20($sp)
    /* 24188 80033988 5800B48F */  lw         $s4, 0x58($sp)
    /* 2418C 8003398C 21300002 */  addu       $a2, $s0, $zero
    /* 24190 80033990 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 24194 80033994 3400B327 */  addiu      $s3, $sp, 0x34
    /* 24198 80033998 3400A7AF */  sw         $a3, 0x34($sp)
    /* 2419C 8003399C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 241A0 800339A0 59D8000C */  jal        SsUtGetVagAtr
    /* 241A4 800339A4 21386002 */   addu      $a3, $s3, $zero
    /* 241A8 800339A8 21204002 */  addu       $a0, $s2, $zero
    /* 241AC 800339AC 21282002 */  addu       $a1, $s1, $zero
    /* 241B0 800339B0 21300002 */  addu       $a2, $s0, $zero
    /* 241B4 800339B4 21386002 */  addu       $a3, $s3, $zero
    /* 241B8 800339B8 65D9000C */  jal        SsUtSetVagAtr
    /* 241BC 800339BC 3A00B4A3 */   sb        $s4, 0x3A($sp)
    /* 241C0 800339C0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 241C4 800339C4 2000B48F */  lw         $s4, 0x20($sp)
    /* 241C8 800339C8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 241CC 800339CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 241D0 800339D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 241D4 800339D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 241D8 800339D8 0800E003 */  jr         $ra
    /* 241DC 800339DC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _SsSetNrpnVabAttr2
    /* 241E0 800339E0 00000000 */  nop
