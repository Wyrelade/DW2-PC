nonmatching CdControlF, 0x134

glabel CdControlF
    /* 20E90 80030690 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 20E94 80030694 1400B1AF */  sw         $s1, 0x14($sp)
    /* 20E98 80030698 2188A000 */  addu       $s1, $a1, $zero
    /* 20E9C 8003069C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 20EA0 800306A0 21988000 */  addu       $s3, $a0, $zero
    /* 20EA4 800306A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 20EA8 800306A8 03001024 */  addiu      $s0, $zero, 0x3
    /* 20EAC 800306AC 3000BEAF */  sw         $fp, 0x30($sp)
    /* 20EB0 800306B0 01001E24 */  addiu      $fp, $zero, 0x1
    /* 20EB4 800306B4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 20EB8 800306B8 FF007232 */  andi       $s2, $s3, 0xFF
    /* 20EBC 800306BC 0580033C */  lui        $v1, %hi(D_8004E9E0)
    /* 20EC0 800306C0 E0E96324 */  addiu      $v1, $v1, %lo(D_8004E9E0)
    /* 20EC4 800306C4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 20EC8 800306C8 0580143C */  lui        $s4, %hi(D_8004E6C8)
    /* 20ECC 800306CC C8E6948E */  lw         $s4, %lo(D_8004E6C8)($s4)
    /* 20ED0 800306D0 80101200 */  sll        $v0, $s2, 2
    /* 20ED4 800306D4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 20ED8 800306D8 21A84300 */  addu       $s5, $v0, $v1
    /* 20EDC 800306DC 2800B6AF */  sw         $s6, 0x28($sp)
    /* 20EE0 800306E0 21B00000 */  addu       $s6, $zero, $zero
    /* 20EE4 800306E4 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 20EE8 800306E8 FFFF1724 */  addiu      $s7, $zero, -0x1
    /* 20EEC 800306EC 3400BFAF */  sw         $ra, 0x34($sp)
  .L800306F0:
    /* 20EF0 800306F0 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 20EF4 800306F4 0B005E12 */  beq        $s2, $fp, .L80030724
    /* 20EF8 800306F8 C8E620AC */   sw        $zero, %lo(D_8004E6C8)($at)
    /* 20EFC 800306FC 0580023C */  lui        $v0, %hi(D_8004E6D4)
    /* 20F00 80030700 D4E64290 */  lbu        $v0, %lo(D_8004E6D4)($v0)
    /* 20F04 80030704 00000000 */  nop
    /* 20F08 80030708 10004230 */  andi       $v0, $v0, 0x10
    /* 20F0C 8003070C 05004010 */  beqz       $v0, .L80030724
    /* 20F10 80030710 01000424 */   addiu     $a0, $zero, 0x1
    /* 20F14 80030714 21280000 */  addu       $a1, $zero, $zero
    /* 20F18 80030718 21300000 */  addu       $a2, $zero, $zero
    /* 20F1C 8003071C 18BE000C */  jal        CD_cw
    /* 20F20 80030720 21380000 */   addu      $a3, $zero, $zero
  .L80030724:
    /* 20F24 80030724 0B002012 */  beqz       $s1, .L80030754
    /* 20F28 80030728 00000000 */   nop
    /* 20F2C 8003072C 0000A28E */  lw         $v0, 0x0($s5)
    /* 20F30 80030730 00000000 */  nop
    /* 20F34 80030734 07004010 */  beqz       $v0, .L80030754
    /* 20F38 80030738 02000424 */   addiu     $a0, $zero, 0x2
    /* 20F3C 8003073C 21282002 */  addu       $a1, $s1, $zero
    /* 20F40 80030740 21300000 */  addu       $a2, $zero, $zero
    /* 20F44 80030744 18BE000C */  jal        CD_cw
    /* 20F48 80030748 21380000 */   addu      $a3, $zero, $zero
    /* 20F4C 8003074C 0A004014 */  bnez       $v0, .L80030778
    /* 20F50 80030750 00000000 */   nop
  .L80030754:
    /* 20F54 80030754 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 20F58 80030758 C8E634AC */  sw         $s4, %lo(D_8004E6C8)($at)
    /* 20F5C 8003075C FF006432 */  andi       $a0, $s3, 0xFF
    /* 20F60 80030760 21282002 */  addu       $a1, $s1, $zero
    /* 20F64 80030764 21300000 */  addu       $a2, $zero, $zero
    /* 20F68 80030768 18BE000C */  jal        CD_cw
    /* 20F6C 8003076C 01000724 */   addiu     $a3, $zero, 0x1
    /* 20F70 80030770 08004010 */  beqz       $v0, .L80030794
    /* 20F74 80030774 0100C226 */   addiu     $v0, $s6, 0x1
  .L80030778:
    /* 20F78 80030778 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 20F7C 8003077C DCFF1716 */  bne        $s0, $s7, .L800306F0
    /* 20F80 80030780 00000000 */   nop
    /* 20F84 80030784 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 20F88 80030788 C8E634AC */  sw         $s4, %lo(D_8004E6C8)($at)
    /* 20F8C 8003078C FFFF1624 */  addiu      $s6, $zero, -0x1
    /* 20F90 80030790 0100C226 */  addiu      $v0, $s6, 0x1
  .L80030794:
    /* 20F94 80030794 3400BF8F */  lw         $ra, 0x34($sp)
    /* 20F98 80030798 3000BE8F */  lw         $fp, 0x30($sp)
    /* 20F9C 8003079C 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 20FA0 800307A0 2800B68F */  lw         $s6, 0x28($sp)
    /* 20FA4 800307A4 2400B58F */  lw         $s5, 0x24($sp)
    /* 20FA8 800307A8 2000B48F */  lw         $s4, 0x20($sp)
    /* 20FAC 800307AC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 20FB0 800307B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 20FB4 800307B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 20FB8 800307B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 20FBC 800307BC 0800E003 */  jr         $ra
    /* 20FC0 800307C0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel CdControlF
