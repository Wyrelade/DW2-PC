nonmatching Menu_StatusDraw, 0x1E8

glabel Menu_StatusDraw
    /* 54BC 80014CBC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 54C0 80014CC0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 54C4 80014CC4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 54C8 80014CC8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 54CC 80014CCC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 54D0 80014CD0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 54D4 80014CD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 54D8 80014CD8 2C00948C */  lw         $s4, 0x2C($a0)
    /* 54DC 80014CDC 00000000 */  nop
    /* 54E0 80014CE0 7000828E */  lw         $v0, 0x70($s4)
    /* 54E4 80014CE4 00000000 */  nop
    /* 54E8 80014CE8 66004010 */  beqz       $v0, .L80014E84
    /* 54EC 80014CEC 00000000 */   nop
    /* 54F0 80014CF0 1305043C */  lui        $a0, (0x513000E >> 16)
    /* 54F4 80014CF4 688E000C */  jal        Cd_GetFileEntry
    /* 54F8 80014CF8 0E008434 */   ori       $a0, $a0, (0x513000E & 0xFFFF)
    /* 54FC 80014CFC 21204000 */  addu       $a0, $v0, $zero
    /* 5500 80014D00 0000828C */  lw         $v0, 0x0($a0)
    /* 5504 80014D04 00000000 */  nop
    /* 5508 80014D08 5E004010 */  beqz       $v0, .L80014E84
    /* 550C 80014D0C 21980000 */   addu      $s3, $zero, $zero
    /* 5510 80014D10 21908000 */  addu       $s2, $a0, $zero
  .L80014D14:
    /* 5514 80014D14 0000448E */  lw         $a0, 0x0($s2)
    /* 5518 80014D18 688E000C */  jal        Cd_GetFileEntry
    /* 551C 80014D1C 00000000 */   nop
    /* 5520 80014D20 26006016 */  bnez       $s3, .L80014DBC
    /* 5524 80014D24 21884000 */   addu      $s1, $v0, $zero
    /* 5528 80014D28 21202002 */  addu       $a0, $s1, $zero
    /* 552C 80014D2C 0580023C */  lui        $v0, %hi(D_80050720)
    /* 5530 80014D30 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 5534 80014D34 02000524 */  addiu      $a1, $zero, 0x2
    /* 5538 80014D38 0800478C */  lw         $a3, 0x8($v0)
    /* 553C 80014D3C 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5540 80014D40 08000624 */   addiu     $a2, $zero, 0x8
    /* 5544 80014D44 21202002 */  addu       $a0, $s1, $zero
    /* 5548 80014D48 0580023C */  lui        $v0, %hi(D_80050720)
    /* 554C 80014D4C 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 5550 80014D50 04000524 */  addiu      $a1, $zero, 0x4
    /* 5554 80014D54 26004784 */  lh         $a3, 0x26($v0)
    /* 5558 80014D58 6D75000C */  jal        Gfx_SetPartsNumber
    /* 555C 80014D5C 2130A000 */   addu      $a2, $a1, $zero
    /* 5560 80014D60 21202002 */  addu       $a0, $s1, $zero
    /* 5564 80014D64 0580023C */  lui        $v0, %hi(D_80050720)
    /* 5568 80014D68 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 556C 80014D6C 08000524 */  addiu      $a1, $zero, 0x8
    /* 5570 80014D70 24004784 */  lh         $a3, 0x24($v0)
    /* 5574 80014D74 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5578 80014D78 04000624 */   addiu     $a2, $zero, 0x4
    /* 557C 80014D7C 21202002 */  addu       $a0, $s1, $zero
    /* 5580 80014D80 0580023C */  lui        $v0, %hi(D_80050720)
    /* 5584 80014D84 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 5588 80014D88 10000524 */  addiu      $a1, $zero, 0x10
    /* 558C 80014D8C 2A004784 */  lh         $a3, 0x2A($v0)
    /* 5590 80014D90 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5594 80014D94 04000624 */   addiu     $a2, $zero, 0x4
    /* 5598 80014D98 21202002 */  addu       $a0, $s1, $zero
    /* 559C 80014D9C 0580023C */  lui        $v0, %hi(D_80050720)
    /* 55A0 80014DA0 2007428C */  lw         $v0, %lo(D_80050720)($v0)
    /* 55A4 80014DA4 20000524 */  addiu      $a1, $zero, 0x20
    /* 55A8 80014DA8 28004784 */  lh         $a3, 0x28($v0)
    /* 55AC 80014DAC 6D75000C */  jal        Gfx_SetPartsNumber
    /* 55B0 80014DB0 04000624 */   addiu     $a2, $zero, 0x4
    /* 55B4 80014DB4 97530008 */  j          .L80014E5C
    /* 55B8 80014DB8 21202002 */   addu      $a0, $s1, $zero
  .L80014DBC:
    /* 55BC 80014DBC AC008286 */  lh         $v0, 0xAC($s4)
    /* 55C0 80014DC0 FFFF6326 */  addiu      $v1, $s3, -0x1
    /* 55C4 80014DC4 2A106200 */  slt        $v0, $v1, $v0
    /* 55C8 80014DC8 1F004010 */  beqz       $v0, .L80014E48
    /* 55CC 80014DCC 80100300 */   sll       $v0, $v1, 2
    /* 55D0 80014DD0 21202002 */  addu       $a0, $s1, $zero
    /* 55D4 80014DD4 21108202 */  addu       $v0, $s4, $v0
    /* 55D8 80014DD8 A000508C */  lw         $s0, 0xA0($v0)
    /* 55DC 80014DDC 02000524 */  addiu      $a1, $zero, 0x2
    /* 55E0 80014DE0 14000786 */  lh         $a3, 0x14($s0)
    /* 55E4 80014DE4 6D75000C */  jal        Gfx_SetPartsNumber
    /* 55E8 80014DE8 03000624 */   addiu     $a2, $zero, 0x3
    /* 55EC 80014DEC 21202002 */  addu       $a0, $s1, $zero
    /* 55F0 80014DF0 04000524 */  addiu      $a1, $zero, 0x4
    /* 55F4 80014DF4 16000786 */  lh         $a3, 0x16($s0)
    /* 55F8 80014DF8 6D75000C */  jal        Gfx_SetPartsNumber
    /* 55FC 80014DFC 03000624 */   addiu     $a2, $zero, 0x3
    /* 5600 80014E00 21202002 */  addu       $a0, $s1, $zero
    /* 5604 80014E04 08000524 */  addiu      $a1, $zero, 0x8
    /* 5608 80014E08 18000786 */  lh         $a3, 0x18($s0)
    /* 560C 80014E0C 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5610 80014E10 03000624 */   addiu     $a2, $zero, 0x3
    /* 5614 80014E14 21202002 */  addu       $a0, $s1, $zero
    /* 5618 80014E18 10000524 */  addiu      $a1, $zero, 0x10
    /* 561C 80014E1C 1A000786 */  lh         $a3, 0x1A($s0)
    /* 5620 80014E20 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5624 80014E24 03000624 */   addiu     $a2, $zero, 0x3
    /* 5628 80014E28 21202002 */  addu       $a0, $s1, $zero
    /* 562C 80014E2C 20000524 */  addiu      $a1, $zero, 0x20
    /* 5630 80014E30 0D000792 */  lbu        $a3, 0xD($s0)
    /* 5634 80014E34 6D75000C */  jal        Gfx_SetPartsNumber
    /* 5638 80014E38 02000624 */   addiu     $a2, $zero, 0x2
    /* 563C 80014E3C 21202002 */  addu       $a0, $s1, $zero
    /* 5640 80014E40 94530008 */  j          .L80014E50
    /* 5644 80014E44 21280000 */   addu      $a1, $zero, $zero
  .L80014E48:
    /* 5648 80014E48 21202002 */  addu       $a0, $s1, $zero
    /* 564C 80014E4C FFFF0534 */  ori        $a1, $zero, 0xFFFF
  .L80014E50:
    /* 5650 80014E50 4175000C */  jal        Gfx_HidePartsByMask
    /* 5654 80014E54 00000000 */   nop
    /* 5658 80014E58 21202002 */  addu       $a0, $s1, $zero
  .L80014E5C:
    /* 565C 80014E5C 00100524 */  addiu      $a1, $zero, 0x1000
    /* 5660 80014E60 7000868E */  lw         $a2, 0x70($s4)
    /* 5664 80014E64 5475000C */  jal        Gfx_SetPartsScale
    /* 5668 80014E68 04005226 */   addiu     $s2, $s2, 0x4
    /* 566C 80014E6C 2176000C */  jal        Gfx_DrawParts
    /* 5670 80014E70 21202002 */   addu      $a0, $s1, $zero
    /* 5674 80014E74 0000428E */  lw         $v0, 0x0($s2)
    /* 5678 80014E78 00000000 */  nop
    /* 567C 80014E7C A5FF4014 */  bnez       $v0, .L80014D14
    /* 5680 80014E80 01007326 */   addiu     $s3, $s3, 0x1
  .L80014E84:
    /* 5684 80014E84 2400BF8F */  lw         $ra, 0x24($sp)
    /* 5688 80014E88 2000B48F */  lw         $s4, 0x20($sp)
    /* 568C 80014E8C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5690 80014E90 1800B28F */  lw         $s2, 0x18($sp)
    /* 5694 80014E94 1400B18F */  lw         $s1, 0x14($sp)
    /* 5698 80014E98 1000B08F */  lw         $s0, 0x10($sp)
    /* 569C 80014E9C 0800E003 */  jr         $ra
    /* 56A0 80014EA0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Menu_StatusDraw
