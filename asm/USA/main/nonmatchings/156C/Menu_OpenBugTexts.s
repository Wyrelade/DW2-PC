nonmatching Menu_OpenBugTexts, 0xFC

glabel Menu_OpenBugTexts
    /* 5BF4 800153F4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5BF8 800153F8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5BFC 800153FC 21A8A000 */  addu       $s5, $a1, $zero
    /* 5C00 80015400 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5C04 80015404 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5C08 80015408 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5C0C 8001540C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5C10 80015410 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5C14 80015414 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5C18 80015418 2C00948C */  lw         $s4, 0x2C($a0)
    /* 5C1C 8001541C 1305043C */  lui        $a0, (0x5130016 >> 16)
    /* 5C20 80015420 688E000C */  jal        Cd_GetFileEntry
    /* 5C24 80015424 16008434 */   ori       $a0, $a0, (0x5130016 & 0xFFFF)
    /* 5C28 80015428 21800000 */  addu       $s0, $zero, $zero
    /* 5C2C 8001542C 60001224 */  addiu      $s2, $zero, 0x60
    /* 5C30 80015430 21884000 */  addu       $s1, $v0, $zero
    /* 5C34 80015434 21980002 */  addu       $s3, $s0, $zero
  .L80015438:
    /* 5C38 80015438 03000224 */  addiu      $v0, $zero, 0x3
    /* 5C3C 8001543C 05000216 */  bne        $s0, $v0, .L80015454
    /* 5C40 80015440 00000000 */   nop
    /* 5C44 80015444 5887000C */  jal        Bug_GetMaxMemBugLevel
    /* 5C48 80015448 00000000 */   nop
    /* 5C4C 8001544C 1A550008 */  j          .L80015468
    /* 5C50 80015450 00000000 */   nop
  .L80015454:
    /* 5C54 80015454 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* 5C58 80015458 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* 5C5C 8001545C 00000000 */  nop
    /* 5C60 80015460 21105000 */  addu       $v0, $v0, $s0
    /* 5C64 80015464 A50B4290 */  lbu        $v0, 0xBA5($v0)
  .L80015468:
    /* 5C68 80015468 00000000 */  nop
    /* 5C6C 8001546C 0F004010 */  beqz       $v0, .L800154AC
    /* 5C70 80015470 FD01043C */   lui       $a0, (0x1FD00EC >> 16)
    /* 5C74 80015474 EC008434 */  ori        $a0, $a0, (0x1FD00EC & 0xFFFF)
    /* 5C78 80015478 21204400 */  addu       $a0, $v0, $a0
    /* 5C7C 8001547C 688E000C */  jal        Cd_GetFileEntry
    /* 5C80 80015480 21206402 */   addu      $a0, $s3, $a0
    /* 5C84 80015484 21209202 */  addu       $a0, $s4, $s2
    /* 5C88 80015488 21284000 */  addu       $a1, $v0, $zero
    /* 5C8C 8001548C 2130A002 */  addu       $a2, $s5, $zero
    /* 5C90 80015490 02002796 */  lhu        $a3, 0x2($s1)
    /* 5C94 80015494 00002296 */  lhu        $v0, 0x0($s1)
    /* 5C98 80015498 003C0700 */  sll        $a3, $a3, 16
    /* 5C9C 8001549C 3E4D000C */  jal        Text_OpenPacked
    /* 5CA0 800154A0 25384700 */   or        $a3, $v0, $a3
    /* 5CA4 800154A4 2E550008 */  j          .L800154B8
    /* 5CA8 800154A8 04005226 */   addiu     $s2, $s2, 0x4
  .L800154AC:
    /* 5CAC 800154AC E26E000C */  jal        Text_Close
    /* 5CB0 800154B0 21209202 */   addu      $a0, $s4, $s2
    /* 5CB4 800154B4 04005226 */  addiu      $s2, $s2, 0x4
  .L800154B8:
    /* 5CB8 800154B8 04003126 */  addiu      $s1, $s1, 0x4
    /* 5CBC 800154BC 01001026 */  addiu      $s0, $s0, 0x1
    /* 5CC0 800154C0 0400022A */  slti       $v0, $s0, 0x4
    /* 5CC4 800154C4 DCFF4014 */  bnez       $v0, .L80015438
    /* 5CC8 800154C8 03007326 */   addiu     $s3, $s3, 0x3
    /* 5CCC 800154CC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5CD0 800154D0 2400B58F */  lw         $s5, 0x24($sp)
    /* 5CD4 800154D4 2000B48F */  lw         $s4, 0x20($sp)
    /* 5CD8 800154D8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5CDC 800154DC 1800B28F */  lw         $s2, 0x18($sp)
    /* 5CE0 800154E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 5CE4 800154E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 5CE8 800154E8 0800E003 */  jr         $ra
    /* 5CEC 800154EC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Menu_OpenBugTexts
