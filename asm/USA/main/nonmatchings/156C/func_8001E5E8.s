nonmatching func_8001E5E8, 0x4C

glabel func_8001E5E8
    /* EDE8 8001E5E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EDEC 8001E5EC 1400BFAF */  sw         $ra, 0x14($sp)
    /* EDF0 8001E5F0 3379000C */  jal        func_8001E4CC
    /* EDF4 8001E5F4 1000B0AF */   sw        $s0, 0x10($sp)
    /* EDF8 8001E5F8 0680033C */  lui        $v1, %hi(D_8005D560)
    /* EDFC 8001E5FC 60D5648C */  lw         $a0, %lo(D_8005D560)($v1)
    /* EE00 8001E600 21804000 */  addu       $s0, $v0, $zero
    /* EE04 8001E604 00240400 */  sll        $a0, $a0, 16
    /* EE08 8001E608 688E000C */  jal        Cd_GetFileEntry
    /* EE0C 8001E60C 01008434 */   ori       $a0, $a0, 0x1
    /* EE10 8001E610 04000492 */  lbu        $a0, 0x4($s0)
    /* EE14 8001E614 1400BF8F */  lw         $ra, 0x14($sp)
    /* EE18 8001E618 1000B08F */  lw         $s0, 0x10($sp)
    /* EE1C 8001E61C 40180400 */  sll        $v1, $a0, 1
    /* EE20 8001E620 21186400 */  addu       $v1, $v1, $a0
    /* EE24 8001E624 80180300 */  sll        $v1, $v1, 2
    /* EE28 8001E628 21104300 */  addu       $v0, $v0, $v1
    /* EE2C 8001E62C 0800E003 */  jr         $ra
    /* EE30 8001E630 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E5E8
