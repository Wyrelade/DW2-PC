nonmatching func_80019BF4, 0x24C

glabel func_80019BF4
    /* A3F4 80019BF4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* A3F8 80019BF8 3000B6AF */  sw         $s6, 0x30($sp)
    /* A3FC 80019BFC 21B08000 */  addu       $s6, $a0, $zero
    /* A400 80019C00 3800BFAF */  sw         $ra, 0x38($sp)
    /* A404 80019C04 3400B7AF */  sw         $s7, 0x34($sp)
    /* A408 80019C08 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* A40C 80019C0C 2800B4AF */  sw         $s4, 0x28($sp)
    /* A410 80019C10 2400B3AF */  sw         $s3, 0x24($sp)
    /* A414 80019C14 2000B2AF */  sw         $s2, 0x20($sp)
    /* A418 80019C18 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* A41C 80019C1C 1800B0AF */  sw         $s0, 0x18($sp)
    /* A420 80019C20 2C00D18E */  lw         $s1, 0x2C($s6)
    /* A424 80019C24 00000000 */  nop
    /* A428 80019C28 A800228E */  lw         $v0, 0xA8($s1)
    /* A42C 80019C2C 00000000 */  nop
    /* A430 80019C30 78004010 */  beqz       $v0, .L80019E14
    /* A434 80019C34 00000000 */   nop
    /* A438 80019C38 1305043C */  lui        $a0, (0x5130026 >> 16)
    /* A43C 80019C3C 688E000C */  jal        Cd_GetFileEntry
    /* A440 80019C40 26008434 */   ori       $a0, $a0, (0x5130026 & 0xFFFF)
    /* A444 80019C44 21204000 */  addu       $a0, $v0, $zero
    /* A448 80019C48 0000828C */  lw         $v0, 0x0($a0)
    /* A44C 80019C4C 00000000 */  nop
    /* A450 80019C50 70004010 */  beqz       $v0, .L80019E14
    /* A454 80019C54 21A00000 */   addu      $s4, $zero, $zero
    /* A458 80019C58 01001524 */  addiu      $s5, $zero, 0x1
    /* A45C 80019C5C 0480023C */  lui        $v0, %hi(D_80040F98)
    /* A460 80019C60 980F5724 */  addiu      $s7, $v0, %lo(D_80040F98)
    /* A464 80019C64 21988000 */  addu       $s3, $a0, $zero
  .L80019C68:
    /* A468 80019C68 0000648E */  lw         $a0, 0x0($s3)
    /* A46C 80019C6C 688E000C */  jal        Cd_GetFileEntry
    /* A470 80019C70 00000000 */   nop
    /* A474 80019C74 05008012 */  beqz       $s4, .L80019C8C
    /* A478 80019C78 21904000 */   addu      $s2, $v0, $zero
    /* A47C 80019C7C 2C009512 */  beq        $s4, $s5, .L80019D30
    /* A480 80019C80 21204002 */   addu      $a0, $s2, $zero
    /* A484 80019C84 7C670008 */  j          .L80019DF0
    /* A488 80019C88 00100524 */   addiu     $a1, $zero, 0x1000
  .L80019C8C:
    /* A48C 80019C8C 1401268E */  lw         $a2, 0x114($s1)
    /* A490 80019C90 00000000 */  nop
    /* A494 80019C94 40100600 */  sll        $v0, $a2, 1
    /* A498 80019C98 21185700 */  addu       $v1, $v0, $s7
    /* A49C 80019C9C 21104600 */  addu       $v0, $v0, $a2
    /* A4A0 80019CA0 80380200 */  sll        $a3, $v0, 2
    /* A4A4 80019CA4 2110E600 */  addu       $v0, $a3, $a2
    /* A4A8 80019CA8 40100200 */  sll        $v0, $v0, 1
    /* A4AC 80019CAC 21102202 */  addu       $v0, $s1, $v0
    /* A4B0 80019CB0 AC004284 */  lh         $v0, 0xAC($v0)
    /* A4B4 80019CB4 00007094 */  lhu        $s0, 0x0($v1)
    /* A4B8 80019CB8 19004010 */  beqz       $v0, .L80019D20
    /* A4BC 80019CBC 00400524 */   addiu     $a1, $zero, 0x4000
    /* A4C0 80019CC0 21204002 */  addu       $a0, $s2, $zero
    /* A4C4 80019CC4 80100600 */  sll        $v0, $a2, 2
    /* A4C8 80019CC8 21102202 */  addu       $v0, $s1, $v0
    /* A4CC 80019CCC 1000A627 */  addiu      $a2, $sp, 0x10
    /* A4D0 80019CD0 6400E724 */  addiu      $a3, $a3, 0x64
    /* A4D4 80019CD4 57004C88 */  lwl        $t4, 0x57($v0)
    /* A4D8 80019CD8 54004C98 */  lwr        $t4, 0x54($v0)
    /* A4DC 80019CDC 00000000 */  nop
    /* A4E0 80019CE0 1300ACAB */  swl        $t4, 0x13($sp)
    /* A4E4 80019CE4 1000ACBB */  swr        $t4, 0x10($sp)
    /* A4E8 80019CE8 56004394 */  lhu        $v1, 0x56($v0)
    /* A4EC 80019CEC 94004294 */  lhu        $v0, 0x94($v0)
    /* A4F0 80019CF0 21382702 */  addu       $a3, $s1, $a3
    /* A4F4 80019CF4 23186200 */  subu       $v1, $v1, $v0
    /* A4F8 80019CF8 CF4D000C */  jal        Menu_SetPartsGridPos
    /* A4FC 80019CFC 1200A3A7 */   sh        $v1, 0x12($sp)
    /* A500 80019D00 21204002 */  addu       $a0, $s2, $zero
    /* A504 80019D04 2800C68E */  lw         $a2, 0x28($s6)
    /* A508 80019D08 00400524 */  addiu      $a1, $zero, 0x4000
    /* A50C 80019D0C 83300600 */  sra        $a2, $a2, 2
    /* A510 80019D10 EE4D000C */  jal        func_800137B8
    /* A514 80019D14 0300C630 */   andi      $a2, $a2, 0x3
    /* A518 80019D18 4A670008 */  j          .L80019D28
    /* A51C 80019D1C 21204002 */   addu      $a0, $s2, $zero
  .L80019D20:
    /* A520 80019D20 00401036 */  ori        $s0, $s0, 0x4000
    /* A524 80019D24 21204002 */  addu       $a0, $s2, $zero
  .L80019D28:
    /* A528 80019D28 78670008 */  j          .L80019DE0
    /* A52C 80019D2C FFFF0532 */   andi      $a1, $s0, 0xFFFF
  .L80019D30:
    /* A530 80019D30 0F00053C */  lui        $a1, (0xFFFFF >> 16)
    /* A534 80019D34 FFFFA534 */  ori        $a1, $a1, (0xFFFFF & 0xFFFF)
    /* A538 80019D38 21200000 */  addu       $a0, $zero, $zero
    /* A53C 80019D3C 03000B24 */  addiu      $t3, $zero, 0x3
    /* A540 80019D40 21302002 */  addu       $a2, $s1, $zero
    /* A544 80019D44 21508000 */  addu       $t2, $a0, $zero
    /* A548 80019D48 21482002 */  addu       $t1, $s1, $zero
    /* A54C 80019D4C 02000824 */  addiu      $t0, $zero, 0x2
    /* A550 80019D50 01000724 */  addiu      $a3, $zero, 0x1
  .L80019D54:
    /* A554 80019D54 9400C28C */  lw         $v0, 0x94($a2)
    /* A558 80019D58 00000000 */  nop
    /* A55C 80019D5C 07004010 */  beqz       $v0, .L80019D7C
    /* A560 80019D60 00000000 */   nop
    /* A564 80019D64 1401228E */  lw         $v0, 0x114($s1)
    /* A568 80019D68 00000000 */  nop
    /* A56C 80019D6C 02004414 */  bne        $v0, $a0, .L80019D78
    /* A570 80019D70 04101501 */   sllv      $v0, $s5, $t0
    /* A574 80019D74 0410F500 */  sllv       $v0, $s5, $a3
  .L80019D78:
    /* A578 80019D78 2328A200 */  subu       $a1, $a1, $v0
  .L80019D7C:
    /* A57C 80019D7C 66002285 */  lh         $v0, 0x66($t1)
    /* A580 80019D80 9400C38C */  lw         $v1, 0x94($a2)
    /* A584 80019D84 00000000 */  nop
    /* A588 80019D88 23104300 */  subu       $v0, $v0, $v1
    /* A58C 80019D8C 04004228 */  slti       $v0, $v0, 0x4
    /* A590 80019D90 09004014 */  bnez       $v0, .L80019DB8
    /* A594 80019D94 00000000 */   nop
    /* A598 80019D98 1401228E */  lw         $v0, 0x114($s1)
    /* A59C 80019D9C 00000000 */  nop
    /* A5A0 80019DA0 03004414 */  bne        $v0, $a0, .L80019DB0
    /* A5A4 80019DA4 04004225 */   addiu     $v0, $t2, 0x4
    /* A5A8 80019DA8 6D670008 */  j          .L80019DB4
    /* A5AC 80019DAC 04107501 */   sllv      $v0, $s5, $t3
  .L80019DB0:
    /* A5B0 80019DB0 04105500 */  sllv       $v0, $s5, $v0
  .L80019DB4:
    /* A5B4 80019DB4 2328A200 */  subu       $a1, $a1, $v0
  .L80019DB8:
    /* A5B8 80019DB8 04006B25 */  addiu      $t3, $t3, 0x4
    /* A5BC 80019DBC 0400C624 */  addiu      $a2, $a2, 0x4
    /* A5C0 80019DC0 04004A25 */  addiu      $t2, $t2, 0x4
    /* A5C4 80019DC4 0C002925 */  addiu      $t1, $t1, 0xC
    /* A5C8 80019DC8 04000825 */  addiu      $t0, $t0, 0x4
    /* A5CC 80019DCC 01008424 */  addiu      $a0, $a0, 0x1
    /* A5D0 80019DD0 04008228 */  slti       $v0, $a0, 0x4
    /* A5D4 80019DD4 DFFF4014 */  bnez       $v0, .L80019D54
    /* A5D8 80019DD8 0400E724 */   addiu     $a3, $a3, 0x4
    /* A5DC 80019DDC 21204002 */  addu       $a0, $s2, $zero
  .L80019DE0:
    /* A5E0 80019DE0 4175000C */  jal        Gfx_HidePartsByMask
    /* A5E4 80019DE4 00000000 */   nop
    /* A5E8 80019DE8 21204002 */  addu       $a0, $s2, $zero
    /* A5EC 80019DEC 00100524 */  addiu      $a1, $zero, 0x1000
  .L80019DF0:
    /* A5F0 80019DF0 A800268E */  lw         $a2, 0xA8($s1)
    /* A5F4 80019DF4 5475000C */  jal        Gfx_SetPartsScale
    /* A5F8 80019DF8 04007326 */   addiu     $s3, $s3, 0x4
    /* A5FC 80019DFC 2176000C */  jal        func_8001D884
    /* A600 80019E00 21204002 */   addu      $a0, $s2, $zero
    /* A604 80019E04 0000628E */  lw         $v0, 0x0($s3)
    /* A608 80019E08 00000000 */  nop
    /* A60C 80019E0C 96FF4014 */  bnez       $v0, .L80019C68
    /* A610 80019E10 01009426 */   addiu     $s4, $s4, 0x1
  .L80019E14:
    /* A614 80019E14 3800BF8F */  lw         $ra, 0x38($sp)
    /* A618 80019E18 3400B78F */  lw         $s7, 0x34($sp)
    /* A61C 80019E1C 3000B68F */  lw         $s6, 0x30($sp)
    /* A620 80019E20 2C00B58F */  lw         $s5, 0x2C($sp)
    /* A624 80019E24 2800B48F */  lw         $s4, 0x28($sp)
    /* A628 80019E28 2400B38F */  lw         $s3, 0x24($sp)
    /* A62C 80019E2C 2000B28F */  lw         $s2, 0x20($sp)
    /* A630 80019E30 1C00B18F */  lw         $s1, 0x1C($sp)
    /* A634 80019E34 1800B08F */  lw         $s0, 0x18($sp)
    /* A638 80019E38 0800E003 */  jr         $ra
    /* A63C 80019E3C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80019BF4
