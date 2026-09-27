nonmatching func_8003F5C4, 0x19C

glabel func_8003F5C4
    /* 2FDC4 8003F5C4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2FDC8 8003F5C8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2FDCC 8003F5CC 21908000 */  addu       $s2, $a0, $zero
    /* 2FDD0 8003F5D0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2FDD4 8003F5D4 2198A000 */  addu       $s3, $a1, $zero
    /* 2FDD8 8003F5D8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2FDDC 8003F5DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2FDE0 8003F5E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2FDE4 8003F5E4 00004282 */  lb         $v0, 0x0($s2)
    /* 2FDE8 8003F5E8 0680043C */  lui        $a0, %hi(D_80062FE8)
    /* 2FDEC 8003F5EC E82F8424 */  addiu      $a0, $a0, %lo(D_80062FE8)
    /* 2FDF0 8003F5F0 3B004228 */  slti       $v0, $v0, 0x3B
    /* 2FDF4 8003F5F4 09004014 */  bnez       $v0, .L8003F61C
    /* 2FDF8 8003F5F8 21184002 */   addu      $v1, $s2, $zero
  .L8003F5FC:
    /* 2FDFC 8003F5FC 00006290 */  lbu        $v0, 0x0($v1)
    /* 2FE00 8003F600 01006324 */  addiu      $v1, $v1, 0x1
    /* 2FE04 8003F604 000082A0 */  sb         $v0, 0x0($a0)
    /* 2FE08 8003F608 00006280 */  lb         $v0, 0x0($v1)
    /* 2FE0C 8003F60C 00000000 */  nop
    /* 2FE10 8003F610 3B004228 */  slti       $v0, $v0, 0x3B
    /* 2FE14 8003F614 F9FF4010 */  beqz       $v0, .L8003F5FC
    /* 2FE18 8003F618 01008424 */   addiu     $a0, $a0, 0x1
  .L8003F61C:
    /* 2FE1C 8003F61C 000080A0 */  sb         $zero, 0x0($a0)
    /* 2FE20 8003F620 5401038C */  lw         $v1, 0x154($zero)
    /* 2FE24 8003F624 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 2FE28 8003F628 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 2FE2C 8003F62C 19006200 */  multu      $v1, $v0
    /* 2FE30 8003F630 5001108C */  lw         $s0, 0x150($zero)
    /* 2FE34 8003F634 10300000 */  mfhi       $a2
    /* 2FE38 8003F638 82190600 */  srl        $v1, $a2, 6
    /* 2FE3C 8003F63C 80100300 */  sll        $v0, $v1, 2
    /* 2FE40 8003F640 21104300 */  addu       $v0, $v0, $v1
    /* 2FE44 8003F644 00110200 */  sll        $v0, $v0, 4
    /* 2FE48 8003F648 21180202 */  addu       $v1, $s0, $v0
    /* 2FE4C 8003F64C 2B100302 */  sltu       $v0, $s0, $v1
    /* 2FE50 8003F650 0F004010 */  beqz       $v0, .L8003F690
    /* 2FE54 8003F654 00000000 */   nop
    /* 2FE58 8003F658 21886000 */  addu       $s1, $v1, $zero
  .L8003F65C:
    /* 2FE5C 8003F65C 0000048E */  lw         $a0, 0x0($s0)
    /* 2FE60 8003F660 00000000 */  nop
    /* 2FE64 8003F664 06008010 */  beqz       $a0, .L8003F680
    /* 2FE68 8003F668 00000000 */   nop
    /* 2FE6C 8003F66C 0680053C */  lui        $a1, %hi(D_80062FE8)
    /* 2FE70 8003F670 49FE000C */  jal        func_8003F924
    /* 2FE74 8003F674 E82FA524 */   addiu     $a1, $a1, %lo(D_80062FE8)
    /* 2FE78 8003F678 0A004010 */  beqz       $v0, .L8003F6A4
    /* 2FE7C 8003F67C 00000000 */   nop
  .L8003F680:
    /* 2FE80 8003F680 50001026 */  addiu      $s0, $s0, 0x50
    /* 2FE84 8003F684 2B101102 */  sltu       $v0, $s0, $s1
    /* 2FE88 8003F688 F4FF4014 */  bnez       $v0, .L8003F65C
    /* 2FE8C 8003F68C 00000000 */   nop
  .L8003F690:
    /* 2FE90 8003F690 21180000 */  addu       $v1, $zero, $zero
  .L8003F694:
    /* 2FE94 8003F694 0C006014 */  bnez       $v1, .L8003F6C8
    /* 2FE98 8003F698 21100000 */   addu      $v0, $zero, $zero
    /* 2FE9C 8003F69C D1FD0008 */  j          .L8003F744
    /* 2FEA0 8003F6A0 00000000 */   nop
  .L8003F6A4:
    /* 2FEA4 8003F6A4 3400028E */  lw         $v0, 0x34($s0)
    /* 2FEA8 8003F6A8 0680013C */  lui        $at, %hi(D_80062FE0)
    /* 2FEAC 8003F6AC E02F22AC */  sw         $v0, %lo(D_80062FE0)($at)
    /* 2FEB0 8003F6B0 A5FD0008 */  j          .L8003F694
    /* 2FEB4 8003F6B4 01000324 */   addiu     $v1, $zero, 0x1
  .L8003F6B8:
    /* 2FEB8 8003F6B8 0480023C */  lui        $v0, %hi(func_8003F760)
    /* 2FEBC 8003F6BC 60F74224 */  addiu      $v0, $v0, %lo(func_8003F760)
    /* 2FEC0 8003F6C0 CEFD0008 */  j          .L8003F738
    /* 2FEC4 8003F6C4 340002AE */   sw        $v0, 0x34($s0)
  .L8003F6C8:
    /* 2FEC8 8003F6C8 5401038C */  lw         $v1, 0x154($zero)
    /* 2FECC 8003F6CC CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 2FED0 8003F6D0 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 2FED4 8003F6D4 19006200 */  multu      $v1, $v0
    /* 2FED8 8003F6D8 5001108C */  lw         $s0, 0x150($zero)
    /* 2FEDC 8003F6DC 10300000 */  mfhi       $a2
    /* 2FEE0 8003F6E0 82190600 */  srl        $v1, $a2, 6
    /* 2FEE4 8003F6E4 80100300 */  sll        $v0, $v1, 2
    /* 2FEE8 8003F6E8 21104300 */  addu       $v0, $v0, $v1
    /* 2FEEC 8003F6EC 00110200 */  sll        $v0, $v0, 4
    /* 2FEF0 8003F6F0 21180202 */  addu       $v1, $s0, $v0
    /* 2FEF4 8003F6F4 2B100302 */  sltu       $v0, $s0, $v1
    /* 2FEF8 8003F6F8 10004010 */  beqz       $v0, .L8003F73C
    /* 2FEFC 8003F6FC 21204002 */   addu      $a0, $s2, $zero
    /* 2FF00 8003F700 21886000 */  addu       $s1, $v1, $zero
  .L8003F704:
    /* 2FF04 8003F704 0000048E */  lw         $a0, 0x0($s0)
    /* 2FF08 8003F708 00000000 */  nop
    /* 2FF0C 8003F70C 06008010 */  beqz       $a0, .L8003F728
    /* 2FF10 8003F710 00000000 */   nop
    /* 2FF14 8003F714 0680053C */  lui        $a1, %hi(D_80062FE8)
    /* 2FF18 8003F718 49FE000C */  jal        func_8003F924
    /* 2FF1C 8003F71C E82FA524 */   addiu     $a1, $a1, %lo(D_80062FE8)
    /* 2FF20 8003F720 E5FF4010 */  beqz       $v0, .L8003F6B8
    /* 2FF24 8003F724 00000000 */   nop
  .L8003F728:
    /* 2FF28 8003F728 50001026 */  addiu      $s0, $s0, 0x50
    /* 2FF2C 8003F72C 2B101102 */  sltu       $v0, $s0, $s1
    /* 2FF30 8003F730 F4FF4014 */  bnez       $v0, .L8003F704
    /* 2FF34 8003F734 00000000 */   nop
  .L8003F738:
    /* 2FF38 8003F738 21204002 */  addu       $a0, $s2, $zero
  .L8003F73C:
    /* 2FF3C 8003F73C 19FE000C */  jal        firstfile
    /* 2FF40 8003F740 21286002 */   addu      $a1, $s3, $zero
  .L8003F744:
    /* 2FF44 8003F744 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2FF48 8003F748 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2FF4C 8003F74C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2FF50 8003F750 1400B18F */  lw         $s1, 0x14($sp)
    /* 2FF54 8003F754 1000B08F */  lw         $s0, 0x10($sp)
    /* 2FF58 8003F758 0800E003 */  jr         $ra
    /* 2FF5C 8003F75C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003F5C4
