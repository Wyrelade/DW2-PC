nonmatching _SsSetNrpnVabAttr3, 0x8C

glabel _SsSetNrpnVabAttr3
    /* 241E4 800339E4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 241E8 800339E8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 241EC 800339EC 00940400 */  sll        $s2, $a0, 16
    /* 241F0 800339F0 03941200 */  sra        $s2, $s2, 16
    /* 241F4 800339F4 21204002 */  addu       $a0, $s2, $zero
    /* 241F8 800339F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 241FC 800339FC 008C0500 */  sll        $s1, $a1, 16
    /* 24200 80033A00 038C1100 */  sra        $s1, $s1, 16
    /* 24204 80033A04 21282002 */  addu       $a1, $s1, $zero
    /* 24208 80033A08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2420C 80033A0C 00840600 */  sll        $s0, $a2, 16
    /* 24210 80033A10 03841000 */  sra        $s0, $s0, 16
    /* 24214 80033A14 2000B4AF */  sw         $s4, 0x20($sp)
    /* 24218 80033A18 5800B48F */  lw         $s4, 0x58($sp)
    /* 2421C 80033A1C 21300002 */  addu       $a2, $s0, $zero
    /* 24220 80033A20 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 24224 80033A24 3400B327 */  addiu      $s3, $sp, 0x34
    /* 24228 80033A28 3400A7AF */  sw         $a3, 0x34($sp)
    /* 2422C 80033A2C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 24230 80033A30 59D8000C */  jal        SsUtGetVagAtr
    /* 24234 80033A34 21386002 */   addu      $a3, $s3, $zero
    /* 24238 80033A38 21204002 */  addu       $a0, $s2, $zero
    /* 2423C 80033A3C 21282002 */  addu       $a1, $s1, $zero
    /* 24240 80033A40 21300002 */  addu       $a2, $s0, $zero
    /* 24244 80033A44 21386002 */  addu       $a3, $s3, $zero
    /* 24248 80033A48 65D9000C */  jal        SsUtSetVagAtr
    /* 2424C 80033A4C 3B00B4A3 */   sb        $s4, 0x3B($sp)
    /* 24250 80033A50 2400BF8F */  lw         $ra, 0x24($sp)
    /* 24254 80033A54 2000B48F */  lw         $s4, 0x20($sp)
    /* 24258 80033A58 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2425C 80033A5C 1800B28F */  lw         $s2, 0x18($sp)
    /* 24260 80033A60 1400B18F */  lw         $s1, 0x14($sp)
    /* 24264 80033A64 1000B08F */  lw         $s0, 0x10($sp)
    /* 24268 80033A68 0800E003 */  jr         $ra
    /* 2426C 80033A6C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _SsSetNrpnVabAttr3
    /* 24270 80033A70 00000000 */  nop
