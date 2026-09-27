nonmatching func_8003A614, 0xBC

glabel func_8003A614
    /* 2AE14 8003A614 0580023C */  lui        $v0, %hi(D_8004FE78)
    /* 2AE18 8003A618 78FE428C */  lw         $v0, %lo(D_8004FE78)($v0)
    /* 2AE1C 8003A61C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2AE20 8003A620 03004014 */  bnez       $v0, .L8003A630
    /* 2AE24 8003A624 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2AE28 8003A628 2BEB000C */  jal        func_8003ACAC
    /* 2AE2C 8003A62C 00000000 */   nop
  .L8003A630:
    /* 2AE30 8003A630 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2AE34 8003A634 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2AE38 8003A638 00000000 */  nop
    /* 2AE3C 8003A63C AA018294 */  lhu        $v0, 0x1AA($a0)
    /* 2AE40 8003A640 00000000 */  nop
    /* 2AE44 8003A644 CFFF4230 */  andi       $v0, $v0, 0xFFCF
    /* 2AE48 8003A648 AA0182A4 */  sh         $v0, 0x1AA($a0)
    /* 2AE4C 8003A64C AA018294 */  lhu        $v0, 0x1AA($a0)
    /* 2AE50 8003A650 00000000 */  nop
    /* 2AE54 8003A654 30004230 */  andi       $v0, $v0, 0x30
    /* 2AE58 8003A658 0A004010 */  beqz       $v0, .L8003A684
    /* 2AE5C 8003A65C 21180000 */   addu      $v1, $zero, $zero
    /* 2AE60 8003A660 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A664:
    /* 2AE64 8003A664 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2AE68 8003A668 06004010 */  beqz       $v0, .L8003A684
    /* 2AE6C 8003A66C 00000000 */   nop
    /* 2AE70 8003A670 AA018294 */  lhu        $v0, 0x1AA($a0)
    /* 2AE74 8003A674 00000000 */  nop
    /* 2AE78 8003A678 30004230 */  andi       $v0, $v0, 0x30
    /* 2AE7C 8003A67C F9FF4014 */  bnez       $v0, .L8003A664
    /* 2AE80 8003A680 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A684:
    /* 2AE84 8003A684 0580023C */  lui        $v0, %hi(D_8004FE60)
    /* 2AE88 8003A688 60FE428C */  lw         $v0, %lo(D_8004FE60)($v0)
    /* 2AE8C 8003A68C 00000000 */  nop
    /* 2AE90 8003A690 08004010 */  beqz       $v0, .L8003A6B4
    /* 2AE94 8003A694 00F0043C */   lui       $a0, (0xF0000009 >> 16)
    /* 2AE98 8003A698 0580023C */  lui        $v0, %hi(D_8004FE60)
    /* 2AE9C 8003A69C 60FE428C */  lw         $v0, %lo(D_8004FE60)($v0)
    /* 2AEA0 8003A6A0 00000000 */  nop
    /* 2AEA4 8003A6A4 09F84000 */  jalr       $v0
    /* 2AEA8 8003A6A8 00000000 */   nop
    /* 2AEAC 8003A6AC B0E90008 */  j          .L8003A6C0
    /* 2AEB0 8003A6B0 00000000 */   nop
  .L8003A6B4:
    /* 2AEB4 8003A6B4 09008434 */  ori        $a0, $a0, (0xF0000009 & 0xFFFF)
    /* 2AEB8 8003A6B8 55B7000C */  jal        DeliverEvent
    /* 2AEBC 8003A6BC 20000524 */   addiu     $a1, $zero, 0x20
  .L8003A6C0:
    /* 2AEC0 8003A6C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2AEC4 8003A6C4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2AEC8 8003A6C8 0800E003 */  jr         $ra
    /* 2AECC 8003A6CC 00000000 */   nop
endlabel func_8003A614
