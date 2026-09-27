nonmatching func_8003EE14, 0x108

glabel func_8003EE14
    /* 2F614 8003EE14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2F618 8003EE18 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F61C 8003EE1C 21888000 */  addu       $s1, $a0, $zero
    /* 2F620 8003EE20 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2F624 8003EE24 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F628 8003EE28 0000238E */  lw         $v1, 0x0($s1)
    /* 2F62C 8003EE2C 0A001024 */  addiu      $s0, $zero, 0xA
    /* 2F630 8003EE30 14007010 */  beq        $v1, $s0, .L8003EE84
    /* 2F634 8003EE34 0B006228 */   slti      $v0, $v1, 0xB
    /* 2F638 8003EE38 05004010 */  beqz       $v0, .L8003EE50
    /* 2F63C 8003EE3C 0B000224 */   addiu     $v0, $zero, 0xB
    /* 2F640 8003EE40 09006010 */  beqz       $v1, .L8003EE68
    /* 2F644 8003EE44 21100000 */   addu      $v0, $zero, $zero
    /* 2F648 8003EE48 C2FB0008 */  j          .L8003EF08
    /* 2F64C 8003EE4C 00000000 */   nop
  .L8003EE50:
    /* 2F650 8003EE50 1C006210 */  beq        $v1, $v0, .L8003EEC4
    /* 2F654 8003EE54 14000224 */   addiu     $v0, $zero, 0x14
    /* 2F658 8003EE58 21006210 */  beq        $v1, $v0, .L8003EEE0
    /* 2F65C 8003EE5C 21100000 */   addu      $v0, $zero, $zero
    /* 2F660 8003EE60 C2FB0008 */  j          .L8003EF08
    /* 2F664 8003EE64 00000000 */   nop
  .L8003EE68:
    /* 2F668 8003EE68 0480043C */  lui        $a0, %hi(func_8003DE18)
    /* 2F66C 8003EE6C 18DE8424 */  addiu      $a0, $a0, %lo(func_8003DE18)
    /* 2F670 8003EE70 0580013C */  lui        $at, %hi(D_800506DC)
    /* 2F674 8003EE74 89FE000C */  jal        func_8003FA24
    /* 2F678 8003EE78 DC0620AC */   sw        $zero, %lo(D_800506DC)($at)
    /* 2F67C 8003EE7C C1FB0008 */  j          .L8003EF04
    /* 2F680 8003EE80 000030AE */   sw        $s0, 0x0($s1)
  .L8003EE84:
    /* 2F684 8003EE84 0680103C */  lui        $s0, %hi(D_80062F84)
    /* 2F688 8003EE88 842F1026 */  addiu      $s0, $s0, %lo(D_80062F84)
    /* 2F68C 8003EE8C 0000028E */  lw         $v0, 0x0($s0)
    /* 2F690 8003EE90 00000000 */  nop
    /* 2F694 8003EE94 1C004014 */  bnez       $v0, .L8003EF08
    /* 2F698 8003EE98 01000224 */   addiu     $v0, $zero, 0x1
    /* 2F69C 8003EE9C 20000426 */  addiu      $a0, $s0, 0x20
    /* 2F6A0 8003EEA0 5DFD000C */  jal        open
    /* 2F6A4 8003EEA4 01800534 */   ori       $a1, $zero, 0x8001
    /* 2F6A8 8003EEA8 06004104 */  bgez       $v0, .L8003EEC4
    /* 2F6AC 8003EEAC 100002AE */   sw        $v0, 0x10($s0)
    /* 2F6B0 8003EEB0 FCFF0326 */  addiu      $v1, $s0, -0x4
    /* 2F6B4 8003EEB4 05000224 */  addiu      $v0, $zero, 0x5
    /* 2F6B8 8003EEB8 040062AC */  sw         $v0, 0x4($v1)
    /* 2F6BC 8003EEBC C2FB0008 */  j          .L8003EF08
    /* 2F6C0 8003EEC0 01000224 */   addiu     $v0, $zero, 0x1
  .L8003EEC4:
    /* 2F6C4 8003EEC4 14000224 */  addiu      $v0, $zero, 0x14
    /* 2F6C8 8003EEC8 0480043C */  lui        $a0, %hi(func_8003E930)
    /* 2F6CC 8003EECC 30E98424 */  addiu      $a0, $a0, %lo(func_8003E930)
    /* 2F6D0 8003EED0 89FE000C */  jal        func_8003FA24
    /* 2F6D4 8003EED4 000022AE */   sw        $v0, 0x0($s1)
    /* 2F6D8 8003EED8 C2FB0008 */  j          .L8003EF08
    /* 2F6DC 8003EEDC 21100000 */   addu      $v0, $zero, $zero
  .L8003EEE0:
    /* 2F6E0 8003EEE0 0680103C */  lui        $s0, %hi(D_80062F94)
    /* 2F6E4 8003EEE4 942F1026 */  addiu      $s0, $s0, %lo(D_80062F94)
    /* 2F6E8 8003EEE8 0000048E */  lw         $a0, 0x0($s0)
    /* 2F6EC 8003EEEC 69FD000C */  jal        close
    /* 2F6F0 8003EEF0 00000000 */   nop
    /* 2F6F4 8003EEF4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F6F8 8003EEF8 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 2F6FC 8003EEFC C2FB0008 */  j          .L8003EF08
    /* 2F700 8003EF00 000003AE */   sw        $v1, 0x0($s0)
  .L8003EF04:
    /* 2F704 8003EF04 21100000 */  addu       $v0, $zero, $zero
  .L8003EF08:
    /* 2F708 8003EF08 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2F70C 8003EF0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F710 8003EF10 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F714 8003EF14 0800E003 */  jr         $ra
    /* 2F718 8003EF18 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003EE14
