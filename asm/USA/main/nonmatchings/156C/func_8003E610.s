nonmatching func_8003E610, 0xB8

glabel func_8003E610
    /* 2EE10 8003E610 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2EE14 8003E614 0680073C */  lui        $a3, %hi(D_80062F94)
    /* 2EE18 8003E618 942FE724 */  addiu      $a3, $a3, %lo(D_80062F94)
    /* 2EE1C 8003E61C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2EE20 8003E620 0000E28C */  lw         $v0, 0x0($a3)
    /* 2EE24 8003E624 00000000 */  nop
    /* 2EE28 8003E628 04004104 */  bgez       $v0, .L8003E63C
    /* 2EE2C 8003E62C 21408000 */   addu      $t0, $a0, $zero
    /* 2EE30 8003E630 0180043C */  lui        $a0, %hi(D_80010C98)
    /* 2EE34 8003E634 ABF90008 */  j          .L8003E6AC
    /* 2EE38 8003E638 980C8424 */   addiu     $a0, $a0, %lo(D_80010C98)
  .L8003E63C:
    /* 2EE3C 8003E63C ECFFE28C */  lw         $v0, -0x14($a3)
    /* 2EE40 8003E640 00000000 */  nop
    /* 2EE44 8003E644 04004018 */  blez       $v0, .L8003E658
    /* 2EE48 8003E648 ECFFE324 */   addiu     $v1, $a3, -0x14
    /* 2EE4C 8003E64C 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2EE50 8003E650 ABF90008 */  j          .L8003E6AC
    /* 2EE54 8003E654 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
  .L8003E658:
    /* 2EE58 8003E658 7F00C230 */  andi       $v0, $a2, 0x7F
    /* 2EE5C 8003E65C 04004010 */  beqz       $v0, .L8003E670
    /* 2EE60 8003E660 7F00A230 */   andi      $v0, $a1, 0x7F
    /* 2EE64 8003E664 0180043C */  lui        $a0, %hi(D_80010CBC)
    /* 2EE68 8003E668 ABF90008 */  j          .L8003E6AC
    /* 2EE6C 8003E66C BC0C8424 */   addiu     $a0, $a0, %lo(D_80010CBC)
  .L8003E670:
    /* 2EE70 8003E670 0C004014 */  bnez       $v0, .L8003E6A4
    /* 2EE74 8003E674 05000224 */   addiu     $v0, $zero, 0x5
    /* 2EE78 8003E678 0480043C */  lui        $a0, %hi(Card_ReadDataTask)
    /* 2EE7C 8003E67C C8E68424 */  addiu      $a0, $a0, %lo(Card_ReadDataTask)
    /* 2EE80 8003E680 ECFFE2AC */  sw         $v0, -0x14($a3)
    /* 2EE84 8003E684 040060AC */  sw         $zero, 0x4($v1)
    /* 2EE88 8003E688 080060AC */  sw         $zero, 0x8($v1)
    /* 2EE8C 8003E68C 180065AC */  sw         $a1, 0x18($v1)
    /* 2EE90 8003E690 200068AC */  sw         $t0, 0x20($v1)
    /* 2EE94 8003E694 89FE000C */  jal        Card_PushTask
    /* 2EE98 8003E698 1C0066AC */   sw        $a2, 0x1C($v1)
    /* 2EE9C 8003E69C AEF90008 */  j          .L8003E6B8
    /* 2EEA0 8003E6A0 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E6A4:
    /* 2EEA4 8003E6A4 0180043C */  lui        $a0, %hi(D_80010CE8)
    /* 2EEA8 8003E6A8 E80C8424 */  addiu      $a0, $a0, %lo(D_80010CE8)
  .L8003E6AC:
    /* 2EEAC 8003E6AC 05A8000C */  jal        printf
    /* 2EEB0 8003E6B0 00000000 */   nop
    /* 2EEB4 8003E6B4 21100000 */  addu       $v0, $zero, $zero
  .L8003E6B8:
    /* 2EEB8 8003E6B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2EEBC 8003E6BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2EEC0 8003E6C0 0800E003 */  jr         $ra
    /* 2EEC4 8003E6C4 00000000 */   nop
endlabel func_8003E610
