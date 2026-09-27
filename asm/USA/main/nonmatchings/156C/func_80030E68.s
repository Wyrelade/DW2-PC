nonmatching func_80030E68, 0xD8

glabel func_80030E68
    /* 21668 80030E68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2166C 80030E6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21670 80030E70 0580103C */  lui        $s0, %hi(D_8004EAF8)
    /* 21674 80030E74 F8EA1026 */  addiu      $s0, $s0, %lo(D_8004EAF8)
    /* 21678 80030E78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2167C 80030E7C 00000296 */  lhu        $v0, 0x0($s0)
    /* 21680 80030E80 00000000 */  nop
    /* 21684 80030E84 2A004014 */  bnez       $v0, .L80030F30
    /* 21688 80030E88 21100000 */   addu      $v0, $zero, $zero
    /* 2168C 80030E8C 0580033C */  lui        $v1, %hi(D_8004FB84)
    /* 21690 80030E90 84FB638C */  lw         $v1, %lo(D_8004FB84)($v1)
    /* 21694 80030E94 0580023C */  lui        $v0, %hi(D_8004FB88)
    /* 21698 80030E98 88FB428C */  lw         $v0, %lo(D_8004FB88)($v0)
    /* 2169C 80030E9C 3333053C */  lui        $a1, (0x33333333 >> 16)
    /* 216A0 80030EA0 000040A4 */  sh         $zero, 0x0($v0)
    /* 216A4 80030EA4 00004294 */  lhu        $v0, 0x0($v0)
    /* 216A8 80030EA8 3333A534 */  ori        $a1, $a1, (0x33333333 & 0xFFFF)
    /* 216AC 80030EAC 000062A4 */  sh         $v0, 0x0($v1)
    /* 216B0 80030EB0 0580023C */  lui        $v0, %hi(D_8004FB8C)
    /* 216B4 80030EB4 8CFB428C */  lw         $v0, %lo(D_8004FB8C)($v0)
    /* 216B8 80030EB8 21200002 */  addu       $a0, $s0, $zero
    /* 216BC 80030EBC 000045AC */  sw         $a1, 0x0($v0)
    /* 216C0 80030EC0 DCC4000C */  jal        func_80031370
    /* 216C4 80030EC4 1A040524 */   addiu     $a1, $zero, 0x41A
    /* 216C8 80030EC8 F9C4000C */  jal        setjmp
    /* 216CC 80030ECC 38000426 */   addiu     $a0, $s0, 0x38
    /* 216D0 80030ED0 03004010 */  beqz       $v0, .L80030EE0
    /* 216D4 80030ED4 00000000 */   nop
    /* 216D8 80030ED8 D0C3000C */  jal        func_80030F40
    /* 216DC 80030EDC 00000000 */   nop
  .L80030EE0:
    /* 216E0 80030EE0 0580103C */  lui        $s0, %hi(D_8004EB34)
    /* 216E4 80030EE4 34EB1026 */  addiu      $s0, $s0, %lo(D_8004EB34)
    /* 216E8 80030EE8 FCFF0426 */  addiu      $a0, $s0, -0x4
    /* 216EC 80030EEC DC0F0226 */  addiu      $v0, $s0, 0xFDC
    /* 216F0 80030EF0 F5C4000C */  jal        HookEntryInt
    /* 216F4 80030EF4 000002AE */   sw        $v0, 0x0($s0)
    /* 216F8 80030EF8 01000224 */  addiu      $v0, $zero, 0x1
    /* 216FC 80030EFC 19C5000C */  jal        func_80031464
    /* 21700 80030F00 C4FF02A6 */   sh        $v0, -0x3C($s0)
    /* 21704 80030F04 0580033C */  lui        $v1, %hi(D_8004FB80)
    /* 21708 80030F08 80FB638C */  lw         $v1, %lo(D_8004FB80)($v1)
    /* 2170C 80030F0C 61C5000C */  jal        func_80031584
    /* 21710 80030F10 140062AC */   sw        $v0, 0x14($v1)
    /* 21714 80030F14 0580043C */  lui        $a0, %hi(D_8004FB80)
    /* 21718 80030F18 80FB848C */  lw         $a0, %lo(D_8004FB80)($a0)
    /* 2171C 80030F1C E7C4000C */  jal        _96_remove
    /* 21720 80030F20 040082AC */   sw        $v0, 0x4($a0)
    /* 21724 80030F24 F59B000C */  jal        ExitCriticalSection
    /* 21728 80030F28 C4FF1026 */   addiu     $s0, $s0, -0x3C
    /* 2172C 80030F2C 21100002 */  addu       $v0, $s0, $zero
  .L80030F30:
    /* 21730 80030F30 1400BF8F */  lw         $ra, 0x14($sp)
    /* 21734 80030F34 1000B08F */  lw         $s0, 0x10($sp)
    /* 21738 80030F38 0800E003 */  jr         $ra
    /* 2173C 80030F3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80030E68
