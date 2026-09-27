nonmatching Gfx_ResetModelBones, 0x80

glabel Gfx_ResetModelBones
    /* FDE8 8001F5E8 3C00858C */  lw         $a1, 0x3C($a0)
    /* FDEC 8001F5EC 00000000 */  nop
    /* FDF0 8001F5F0 0800A28C */  lw         $v0, 0x8($a1)
    /* FDF4 8001F5F4 7800A48C */  lw         $a0, 0x78($a1)
    /* FDF8 8001F5F8 19004018 */  blez       $v0, .L8001F660
    /* FDFC 8001F5FC 21180000 */   addu      $v1, $zero, $zero
    /* FE00 8001F600 0480063C */  lui        $a2, %hi(D_80043714)
  .L8001F604:
    /* FE04 8001F604 01006324 */  addiu      $v1, $v1, 0x1
    /* FE08 8001F608 1437CA24 */  addiu      $t2, $a2, %lo(D_80043714)
    /* FE0C 8001F60C 0000478D */  lw         $a3, 0x0($t2)
    /* FE10 8001F610 0400488D */  lw         $t0, 0x4($t2)
    /* FE14 8001F614 0800498D */  lw         $t1, 0x8($t2)
    /* FE18 8001F618 600087AC */  sw         $a3, 0x60($a0)
    /* FE1C 8001F61C 640088AC */  sw         $t0, 0x64($a0)
    /* FE20 8001F620 680089AC */  sw         $t1, 0x68($a0)
    /* FE24 8001F624 0C00478D */  lw         $a3, 0xC($t2)
    /* FE28 8001F628 1000488D */  lw         $t0, 0x10($t2)
    /* FE2C 8001F62C 1400498D */  lw         $t1, 0x14($t2)
    /* FE30 8001F630 6C0087AC */  sw         $a3, 0x6C($a0)
    /* FE34 8001F634 700088AC */  sw         $t0, 0x70($a0)
    /* FE38 8001F638 740089AC */  sw         $t1, 0x74($a0)
    /* FE3C 8001F63C 1800478D */  lw         $a3, 0x18($t2)
    /* FE40 8001F640 1C00488D */  lw         $t0, 0x1C($t2)
    /* FE44 8001F644 780087AC */  sw         $a3, 0x78($a0)
    /* FE48 8001F648 7C0088AC */  sw         $t0, 0x7C($a0)
    /* FE4C 8001F64C 0800A28C */  lw         $v0, 0x8($a1)
    /* FE50 8001F650 00000000 */  nop
    /* FE54 8001F654 2A106200 */  slt        $v0, $v1, $v0
    /* FE58 8001F658 EAFF4014 */  bnez       $v0, .L8001F604
    /* FE5C 8001F65C 84008424 */   addiu     $a0, $a0, 0x84
  .L8001F660:
    /* FE60 8001F660 0800E003 */  jr         $ra
    /* FE64 8001F664 00000000 */   nop
endlabel Gfx_ResetModelBones
