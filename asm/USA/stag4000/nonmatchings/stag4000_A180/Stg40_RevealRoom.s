nonmatching Stg40_RevealRoom, 0x238

glabel Stg40_RevealRoom
    /* C094 8006F3F4 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* C098 8006F3F8 3000B0AF */  sw         $s0, 0x30($sp)
    /* C09C 8006F3FC 0580103C */  lui        $s0, %hi(D_8005071C)
    /* C0A0 8006F400 1C07028E */  lw         $v0, %lo(D_8005071C)($s0)
    /* C0A4 8006F404 5400BFAF */  sw         $ra, 0x54($sp)
    /* C0A8 8006F408 5000BEAF */  sw         $fp, 0x50($sp)
    /* C0AC 8006F40C 4C00B7AF */  sw         $s7, 0x4C($sp)
    /* C0B0 8006F410 4800B6AF */  sw         $s6, 0x48($sp)
    /* C0B4 8006F414 4400B5AF */  sw         $s5, 0x44($sp)
    /* C0B8 8006F418 4000B4AF */  sw         $s4, 0x40($sp)
    /* C0BC 8006F41C 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* C0C0 8006F420 3800B2AF */  sw         $s2, 0x38($sp)
    /* C0C4 8006F424 3400B1AF */  sw         $s1, 0x34($sp)
    /* C0C8 8006F428 540E428C */  lw         $v0, 0xE54($v0)
    /* C0CC 8006F42C 2120A000 */  addu       $a0, $a1, $zero
    /* C0D0 8006F430 00005E84 */  lh         $fp, 0x0($v0)
    /* C0D4 8006F434 02004284 */  lh         $v0, 0x2($v0)
    /* C0D8 8006F438 2128C000 */  addu       $a1, $a2, $zero
    /* C0DC 8006F43C 0EC1010C */  jal        Stg40_GetCell
    /* C0E0 8006F440 2400A2AF */   sw        $v0, 0x24($sp)
    /* C0E4 8006F444 02004290 */  lbu        $v0, 0x2($v0)
    /* C0E8 8006F448 00000000 */  nop
    /* C0EC 8006F44C FF004330 */  andi       $v1, $v0, 0xFF
    /* C0F0 8006F450 2000A2A3 */  sb         $v0, 0x20($sp)
    /* C0F4 8006F454 FF000224 */  addiu      $v0, $zero, 0xFF
    /* C0F8 8006F458 68006210 */  beq        $v1, $v0, .L8006F5FC
    /* C0FC 8006F45C 42210300 */   srl       $a0, $v1, 5
    /* C100 8006F460 1F006230 */  andi       $v0, $v1, 0x1F
    /* C104 8006F464 01000324 */  addiu      $v1, $zero, 0x1
    /* C108 8006F468 04284300 */  sllv       $a1, $v1, $v0
    /* C10C 8006F46C 08008228 */  slti       $v0, $a0, 0x8
    /* C110 8006F470 0A004010 */  beqz       $v0, .L8006F49C
    /* C114 8006F474 80180400 */   sll       $v1, $a0, 2
    /* C118 8006F478 1C07028E */  lw         $v0, %lo(D_8005071C)($s0)
    /* C11C 8006F47C 00000000 */  nop
    /* C120 8006F480 21204300 */  addu       $a0, $v0, $v1
    /* C124 8006F484 5C0E838C */  lw         $v1, 0xE5C($a0)
    /* C128 8006F488 00000000 */  nop
    /* C12C 8006F48C 24106500 */  and        $v0, $v1, $a1
    /* C130 8006F490 5A004014 */  bnez       $v0, .L8006F5FC
    /* C134 8006F494 25106500 */   or        $v0, $v1, $a1
    /* C138 8006F498 5C0E82AC */  sw         $v0, 0xE5C($a0)
  .L8006F49C:
    /* C13C 8006F49C 1C07028E */  lw         $v0, %lo(D_8005071C)($s0)
    /* C140 8006F4A0 2400A88F */  lw         $t0, 0x24($sp)
    /* C144 8006F4A4 580E578C */  lw         $s7, 0xE58($v0)
    /* C148 8006F4A8 54000019 */  blez       $t0, .L8006F5FC
    /* C14C 8006F4AC 21B00000 */   addu      $s6, $zero, $zero
    /* C150 8006F4B0 1000A927 */  addiu      $t1, $sp, 0x10
    /* C154 8006F4B4 2800A9AF */  sw         $t1, 0x28($sp)
    /* C158 8006F4B8 2C00A0AF */  sw         $zero, 0x2C($sp)
  .L8006F4BC:
    /* C15C 8006F4BC 4800C01B */  blez       $fp, .L8006F5E0
    /* C160 8006F4C0 21900000 */   addu      $s2, $zero, $zero
  .L8006F4C4:
    /* C164 8006F4C4 2C00AA8F */  lw         $t2, 0x2C($sp)
    /* C168 8006F4C8 00000000 */  nop
    /* C16C 8006F4CC 21104A02 */  addu       $v0, $s2, $t2
    /* C170 8006F4D0 80100200 */  sll        $v0, $v0, 2
    /* C174 8006F4D4 21385700 */  addu       $a3, $v0, $s7
    /* C178 8006F4D8 0200E390 */  lbu        $v1, 0x2($a3)
    /* C17C 8006F4DC 2000A293 */  lbu        $v0, 0x20($sp)
    /* C180 8006F4E0 00000000 */  nop
    /* C184 8006F4E4 3A006214 */  bne        $v1, $v0, .L8006F5D0
    /* C188 8006F4E8 21204002 */   addu      $a0, $s2, $zero
    /* C18C 8006F4EC 2128C002 */  addu       $a1, $s6, $zero
    /* C190 8006F4F0 01000624 */  addiu      $a2, $zero, 0x1
    /* C194 8006F4F4 21A80000 */  addu       $s5, $zero, $zero
    /* C198 8006F4F8 02001424 */  addiu      $s4, $zero, 0x2
    /* C19C 8006F4FC 0000E294 */  lhu        $v0, 0x0($a3)
    /* C1A0 8006F500 2800B38F */  lw         $s3, 0x28($sp)
    /* C1A4 8006F504 00204234 */  ori        $v0, $v0, 0x2000
    /* C1A8 8006F508 E1BA010C */  jal        Stg40_AutomapSetCell
    /* C1AC 8006F50C 0000E2A4 */   sh        $v0, 0x0($a3)
    /* C1B0 8006F510 0680023C */  lui        $v0, %hi(D_8006368C)
    /* C1B4 8006F514 8C364A24 */  addiu      $t2, $v0, %lo(D_8006368C)
    /* C1B8 8006F518 03004B89 */  lwl        $t3, 0x3($t2)
    /* C1BC 8006F51C 00004B99 */  lwr        $t3, 0x0($t2)
    /* C1C0 8006F520 07004889 */  lwl        $t0, 0x7($t2)
    /* C1C4 8006F524 04004899 */  lwr        $t0, 0x4($t2)
    /* C1C8 8006F528 0B004989 */  lwl        $t1, 0xB($t2)
    /* C1CC 8006F52C 08004999 */  lwr        $t1, 0x8($t2)
    /* C1D0 8006F530 1300ABAB */  swl        $t3, 0x13($sp)
    /* C1D4 8006F534 1000ABBB */  swr        $t3, 0x10($sp)
    /* C1D8 8006F538 1700A8AB */  swl        $t0, 0x17($sp)
    /* C1DC 8006F53C 1400A8BB */  swr        $t0, 0x14($sp)
    /* C1E0 8006F540 1B00A9AB */  swl        $t1, 0x1B($sp)
    /* C1E4 8006F544 1800A9BB */  swr        $t1, 0x18($sp)
    /* C1E8 8006F548 0F004B89 */  lwl        $t3, 0xF($t2)
    /* C1EC 8006F54C 0C004B99 */  lwr        $t3, 0xC($t2)
    /* C1F0 8006F550 00000000 */  nop
    /* C1F4 8006F554 1F00ABAB */  swl        $t3, 0x1F($sp)
    /* C1F8 8006F558 1C00ABBB */  swr        $t3, 0x1C($sp)
  .L8006F55C:
    /* C1FC 8006F55C 00006286 */  lh         $v0, 0x0($s3)
    /* C200 8006F560 2800AB8F */  lw         $t3, 0x28($sp)
    /* C204 8006F564 21884202 */  addu       $s1, $s2, $v0
    /* C208 8006F568 21107401 */  addu       $v0, $t3, $s4
    /* C20C 8006F56C 00004284 */  lh         $v0, 0x0($v0)
    /* C210 8006F570 21202002 */  addu       $a0, $s1, $zero
    /* C214 8006F574 2180C202 */  addu       $s0, $s6, $v0
    /* C218 8006F578 F8C0010C */  jal        Stg40_GetCellFlags
    /* C21C 8006F57C 21280002 */   addu      $a1, $s0, $zero
    /* C220 8006F580 00C04230 */  andi       $v0, $v0, 0xC000
    /* C224 8006F584 00800334 */  ori        $v1, $zero, 0x8000
    /* C228 8006F588 0C004314 */  bne        $v0, $v1, .L8006F5BC
    /* C22C 8006F58C 1800D003 */   mult      $fp, $s0
    /* C230 8006F590 21202002 */  addu       $a0, $s1, $zero
    /* C234 8006F594 21280002 */  addu       $a1, $s0, $zero
    /* C238 8006F598 12400000 */  mflo       $t0
    /* C23C 8006F59C 21188800 */  addu       $v1, $a0, $t0
    /* C240 8006F5A0 80180300 */  sll        $v1, $v1, 2
    /* C244 8006F5A4 21187700 */  addu       $v1, $v1, $s7
    /* C248 8006F5A8 00006294 */  lhu        $v0, 0x0($v1)
    /* C24C 8006F5AC 01000624 */  addiu      $a2, $zero, 0x1
    /* C250 8006F5B0 00204234 */  ori        $v0, $v0, 0x2000
    /* C254 8006F5B4 E1BA010C */  jal        Stg40_AutomapSetCell
    /* C258 8006F5B8 000062A4 */   sh        $v0, 0x0($v1)
  .L8006F5BC:
    /* C25C 8006F5BC 04009426 */  addiu      $s4, $s4, 0x4
    /* C260 8006F5C0 0100B526 */  addiu      $s5, $s5, 0x1
    /* C264 8006F5C4 0400A22A */  slti       $v0, $s5, 0x4
    /* C268 8006F5C8 E4FF4014 */  bnez       $v0, .L8006F55C
    /* C26C 8006F5CC 04007326 */   addiu     $s3, $s3, 0x4
  .L8006F5D0:
    /* C270 8006F5D0 01005226 */  addiu      $s2, $s2, 0x1
    /* C274 8006F5D4 2A105E02 */  slt        $v0, $s2, $fp
    /* C278 8006F5D8 BAFF4014 */  bnez       $v0, .L8006F4C4
    /* C27C 8006F5DC 00000000 */   nop
  .L8006F5E0:
    /* C280 8006F5E0 0100D626 */  addiu      $s6, $s6, 0x1
    /* C284 8006F5E4 2C00A98F */  lw         $t1, 0x2C($sp)
    /* C288 8006F5E8 2400AA8F */  lw         $t2, 0x24($sp)
    /* C28C 8006F5EC 21483E01 */  addu       $t1, $t1, $fp
    /* C290 8006F5F0 2A10CA02 */  slt        $v0, $s6, $t2
    /* C294 8006F5F4 B1FF4014 */  bnez       $v0, .L8006F4BC
    /* C298 8006F5F8 2C00A9AF */   sw        $t1, 0x2C($sp)
  .L8006F5FC:
    /* C29C 8006F5FC 5400BF8F */  lw         $ra, 0x54($sp)
    /* C2A0 8006F600 5000BE8F */  lw         $fp, 0x50($sp)
    /* C2A4 8006F604 4C00B78F */  lw         $s7, 0x4C($sp)
    /* C2A8 8006F608 4800B68F */  lw         $s6, 0x48($sp)
    /* C2AC 8006F60C 4400B58F */  lw         $s5, 0x44($sp)
    /* C2B0 8006F610 4000B48F */  lw         $s4, 0x40($sp)
    /* C2B4 8006F614 3C00B38F */  lw         $s3, 0x3C($sp)
    /* C2B8 8006F618 3800B28F */  lw         $s2, 0x38($sp)
    /* C2BC 8006F61C 3400B18F */  lw         $s1, 0x34($sp)
    /* C2C0 8006F620 3000B08F */  lw         $s0, 0x30($sp)
    /* C2C4 8006F624 0800E003 */  jr         $ra
    /* C2C8 8006F628 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel Stg40_RevealRoom
