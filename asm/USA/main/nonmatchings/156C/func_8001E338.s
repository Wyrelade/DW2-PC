nonmatching func_8001E338, 0x58

glabel func_8001E338
    /* EB38 8001E338 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EB3C 8001E33C 1000B0AF */  sw         $s0, 0x10($sp)
    /* EB40 8001E340 21808000 */  addu       $s0, $a0, $zero
    /* EB44 8001E344 0680023C */  lui        $v0, %hi(D_8005D560)
    /* EB48 8001E348 60D5448C */  lw         $a0, %lo(D_8005D560)($v0)
    /* EB4C 8001E34C 1400B1AF */  sw         $s1, 0x14($sp)
    /* EB50 8001E350 2188A000 */  addu       $s1, $a1, $zero
    /* EB54 8001E354 1800BFAF */  sw         $ra, 0x18($sp)
    /* EB58 8001E358 00240400 */  sll        $a0, $a0, 16
    /* EB5C 8001E35C 688E000C */  jal        Cd_GetFileEntry
    /* EB60 8001E360 02008434 */   ori       $a0, $a0, 0x2
    /* EB64 8001E364 21801102 */  addu       $s0, $s0, $s1
    /* EB68 8001E368 0C000492 */  lbu        $a0, 0xC($s0)
    /* EB6C 8001E36C 1800BF8F */  lw         $ra, 0x18($sp)
    /* EB70 8001E370 1400B18F */  lw         $s1, 0x14($sp)
    /* EB74 8001E374 1000B08F */  lw         $s0, 0x10($sp)
    /* EB78 8001E378 40180400 */  sll        $v1, $a0, 1
    /* EB7C 8001E37C 21186400 */  addu       $v1, $v1, $a0
    /* EB80 8001E380 C0180300 */  sll        $v1, $v1, 3
    /* EB84 8001E384 21104300 */  addu       $v0, $v0, $v1
    /* EB88 8001E388 0800E003 */  jr         $ra
    /* EB8C 8001E38C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001E338
