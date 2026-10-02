nonmatching func_8006D418, 0xC8

glabel func_8006D418
    /* A0B8 8006D418 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* A0BC 8006D41C 1000BFAF */  sw         $ra, 0x10($sp)
    /* A0C0 8006D420 2C00858C */  lw         $a1, 0x2C($a0)
    /* A0C4 8006D424 00000000 */  nop
    /* A0C8 8006D428 2C00A28C */  lw         $v0, 0x2C($a1)
    /* A0CC 8006D42C 00000000 */  nop
    /* A0D0 8006D430 08004290 */  lbu        $v0, 0x8($v0)
    /* A0D4 8006D434 00000000 */  nop
    /* A0D8 8006D438 FEFF4324 */  addiu      $v1, $v0, -0x2
    /* A0DC 8006D43C 0B00622C */  sltiu      $v0, $v1, 0xB
    /* A0E0 8006D440 08004010 */  beqz       $v0, .L8006D464
    /* A0E4 8006D444 0680023C */   lui       $v0, %hi(jtbl_800635CC)
    /* A0E8 8006D448 CC354224 */  addiu      $v0, $v0, %lo(jtbl_800635CC)
    /* A0EC 8006D44C 80180300 */  sll        $v1, $v1, 2
    /* A0F0 8006D450 21186200 */  addu       $v1, $v1, $v0
    /* A0F4 8006D454 0000628C */  lw         $v0, 0x0($v1)
    /* A0F8 8006D458 00000000 */  nop
    /* A0FC 8006D45C 08004000 */  jr         $v0
    /* A100 8006D460 00000000 */   nop
  jlabel .L8006D464
    /* A104 8006D464 2C00A38C */  lw         $v1, 0x2C($a1)
    /* A108 8006D468 00000000 */  nop
    /* A10C 8006D46C 0E006294 */  lhu        $v0, 0xE($v1)
    /* A110 8006D470 34B50108 */  j          .L8006D4D0
    /* A114 8006D474 00000000 */   nop
  jlabel .L8006D478
    /* A118 8006D478 47B3010C */  jal        func_8006CD1C
    /* A11C 8006D47C 00000000 */   nop
    /* A120 8006D480 34B50108 */  j          .L8006D4D0
    /* A124 8006D484 00000000 */   nop
  jlabel .L8006D488
    /* A128 8006D488 D5B3010C */  jal        func_8006CF54
    /* A12C 8006D48C 00000000 */   nop
    /* A130 8006D490 34B50108 */  j          .L8006D4D0
    /* A134 8006D494 00000000 */   nop
  jlabel .L8006D498
    /* A138 8006D498 B5B2010C */  jal        func_8006CAD4
    /* A13C 8006D49C 00000000 */   nop
    /* A140 8006D4A0 34B50108 */  j          .L8006D4D0
    /* A144 8006D4A4 00000000 */   nop
  jlabel .L8006D4A8
    /* A148 8006D4A8 3AB4010C */  jal        func_8006D0E8
    /* A14C 8006D4AC 00000000 */   nop
    /* A150 8006D4B0 34B50108 */  j          .L8006D4D0
    /* A154 8006D4B4 00000000 */   nop
  jlabel .L8006D4B8
    /* A158 8006D4B8 13B2010C */  jal        func_8006C84C
    /* A15C 8006D4BC 00000000 */   nop
    /* A160 8006D4C0 34B50108 */  j          .L8006D4D0
    /* A164 8006D4C4 00000000 */   nop
  jlabel .L8006D4C8
    /* A168 8006D4C8 B1B1010C */  jal        func_8006C6C4
    /* A16C 8006D4CC 00000000 */   nop
  .L8006D4D0:
    /* A170 8006D4D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* A174 8006D4D4 00000000 */  nop
    /* A178 8006D4D8 0800E003 */  jr         $ra
    /* A17C 8006D4DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006D418
