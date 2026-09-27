nonmatching _SsSetNrpnVabAttr13, 0x9C

glabel _SsSetNrpnVabAttr13
    /* 249F4 800341F4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 249F8 800341F8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 249FC 800341FC 00940400 */  sll        $s2, $a0, 16
    /* 24A00 80034200 03941200 */  sra        $s2, $s2, 16
    /* 24A04 80034204 21204002 */  addu       $a0, $s2, $zero
    /* 24A08 80034208 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 24A0C 8003420C 008C0500 */  sll        $s1, $a1, 16
    /* 24A10 80034210 038C1100 */  sra        $s1, $s1, 16
    /* 24A14 80034214 21282002 */  addu       $a1, $s1, $zero
    /* 24A18 80034218 2800B0AF */  sw         $s0, 0x28($sp)
    /* 24A1C 8003421C 00840600 */  sll        $s0, $a2, 16
    /* 24A20 80034220 03841000 */  sra        $s0, $s0, 16
    /* 24A24 80034224 3400B3AF */  sw         $s3, 0x34($sp)
    /* 24A28 80034228 7000B38F */  lw         $s3, 0x70($sp)
    /* 24A2C 8003422C 21300002 */  addu       $a2, $s0, $zero
    /* 24A30 80034230 3800B4AF */  sw         $s4, 0x38($sp)
    /* 24A34 80034234 4C00B427 */  addiu      $s4, $sp, 0x4C
    /* 24A38 80034238 4C00A7AF */  sw         $a3, 0x4C($sp)
    /* 24A3C 8003423C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 24A40 80034240 59D8000C */  jal        SsUtGetVagAtr
    /* 24A44 80034244 21388002 */   addu      $a3, $s4, $zero
    /* 24A48 80034248 1000A427 */  addiu      $a0, $sp, 0x10
    /* 24A4C 8003424C 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 24A50 80034250 5E00A627 */  addiu      $a2, $sp, 0x5E
    /* 24A54 80034254 E0CE000C */  jal        _SsUtBuildADSR
    /* 24A58 80034258 5500B3A3 */   sb        $s3, 0x55($sp)
    /* 24A5C 8003425C 21204002 */  addu       $a0, $s2, $zero
    /* 24A60 80034260 21282002 */  addu       $a1, $s1, $zero
    /* 24A64 80034264 21300002 */  addu       $a2, $s0, $zero
    /* 24A68 80034268 65D9000C */  jal        SsUtSetVagAtr
    /* 24A6C 8003426C 21388002 */   addu      $a3, $s4, $zero
    /* 24A70 80034270 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 24A74 80034274 3800B48F */  lw         $s4, 0x38($sp)
    /* 24A78 80034278 3400B38F */  lw         $s3, 0x34($sp)
    /* 24A7C 8003427C 3000B28F */  lw         $s2, 0x30($sp)
    /* 24A80 80034280 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 24A84 80034284 2800B08F */  lw         $s0, 0x28($sp)
    /* 24A88 80034288 0800E003 */  jr         $ra
    /* 24A8C 8003428C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _SsSetNrpnVabAttr13
    /* 24A90 80034290 00000000 */  nop
