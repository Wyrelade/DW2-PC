nonmatching Stg20_OpenText, 0x84

glabel Stg20_OpenText
    /* 4120 80067480 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 4124 80067484 4000B0AF */  sw         $s0, 0x40($sp)
    /* 4128 80067488 21808000 */  addu       $s0, $a0, $zero
    /* 412C 8006748C 4400B1AF */  sw         $s1, 0x44($sp)
    /* 4130 80067490 2188E000 */  addu       $s1, $a3, $zero
    /* 4134 80067494 0300C014 */  bnez       $a2, .L800674A4
    /* 4138 80067498 4800BFAF */   sw        $ra, 0x48($sp)
    /* 413C 8006749C 2D9D0108 */  j          .L800674B4
    /* 4140 800674A0 2400A5AF */   sw        $a1, 0x24($sp)
  .L800674A4:
    /* 4144 800674A4 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* 4148 800674A8 688E000C */  jal        Cd_GetFileEntry
    /* 414C 800674AC 2120C400 */   addu      $a0, $a2, $a0
    /* 4150 800674B0 2400A2AF */  sw         $v0, 0x24($sp)
  .L800674B4:
    /* 4154 800674B4 21200002 */  addu       $a0, $s0, $zero
    /* 4158 800674B8 6000A28F */  lw         $v0, 0x60($sp)
    /* 415C 800674BC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4160 800674C0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 4164 800674C4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 4168 800674C8 0C000224 */  addiu      $v0, $zero, 0xC
    /* 416C 800674CC 0300238A */  lwl        $v1, 0x3($s1)
    /* 4170 800674D0 0000239A */  lwr        $v1, 0x0($s1)
    /* 4174 800674D4 00000000 */  nop
    /* 4178 800674D8 1B00A3AB */  swl        $v1, 0x1B($sp)
    /* 417C 800674DC 1800A3BB */  swr        $v1, 0x18($sp)
    /* 4180 800674E0 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 4184 800674E4 2000A2AF */  sw         $v0, 0x20($sp)
    /* 4188 800674E8 096F000C */  jal        Text_Open
    /* 418C 800674EC 2800A0AF */   sw        $zero, 0x28($sp)
    /* 4190 800674F0 4800BF8F */  lw         $ra, 0x48($sp)
    /* 4194 800674F4 4400B18F */  lw         $s1, 0x44($sp)
    /* 4198 800674F8 4000B08F */  lw         $s0, 0x40($sp)
    /* 419C 800674FC 0800E003 */  jr         $ra
    /* 41A0 80067500 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel Stg20_OpenText
