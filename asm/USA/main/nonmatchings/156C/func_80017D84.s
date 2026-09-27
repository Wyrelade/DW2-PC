nonmatching func_80017D84, 0x1E8

glabel func_80017D84
    /* 8584 80017D84 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 8588 80017D88 4000B6AF */  sw         $s6, 0x40($sp)
    /* 858C 80017D8C 21B08000 */  addu       $s6, $a0, $zero
    /* 8590 80017D90 3000B2AF */  sw         $s2, 0x30($sp)
    /* 8594 80017D94 21900000 */  addu       $s2, $zero, $zero
    /* 8598 80017D98 2800B0AF */  sw         $s0, 0x28($sp)
    /* 859C 80017D9C 2180C002 */  addu       $s0, $s6, $zero
    /* 85A0 80017DA0 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 85A4 80017DA4 4800BEAF */  sw         $fp, 0x48($sp)
    /* 85A8 80017DA8 4400B7AF */  sw         $s7, 0x44($sp)
    /* 85AC 80017DAC 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 85B0 80017DB0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 85B4 80017DB4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 85B8 80017DB8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 85BC 80017DBC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 85C0 80017DC0 2000A5A3 */  sb         $a1, 0x20($sp)
    /* 85C4 80017DC4 2100A0A3 */  sb         $zero, 0x21($sp)
  .L80017DC8:
    /* 85C8 80017DC8 E26E000C */  jal        Text_Close
    /* 85CC 80017DCC 21200002 */   addu      $a0, $s0, $zero
    /* 85D0 80017DD0 01005226 */  addiu      $s2, $s2, 0x1
    /* 85D4 80017DD4 1000422A */  slti       $v0, $s2, 0x10
    /* 85D8 80017DD8 FBFF4014 */  bnez       $v0, .L80017DC8
    /* 85DC 80017DDC 04001026 */   addiu     $s0, $s0, 0x4
    /* 85E0 80017DE0 21900000 */  addu       $s2, $zero, $zero
    /* 85E4 80017DE4 6D001E24 */  addiu      $fp, $zero, 0x6D
    /* 85E8 80017DE8 08001424 */  addiu      $s4, $zero, 0x8
    /* 85EC 80017DEC 21984002 */  addu       $s3, $s2, $zero
    /* 85F0 80017DF0 32001024 */  addiu      $s0, $zero, 0x32
    /* 85F4 80017DF4 6800C286 */  lh         $v0, 0x68($s6)
    /* 85F8 80017DF8 3E001524 */  addiu      $s5, $zero, 0x3E
    /* 85FC 80017DFC C0100200 */  sll        $v0, $v0, 3
    /* 8600 80017E00 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 8604 80017E04 21B8C202 */  addu       $s7, $s6, $v0
    /* 8608 80017E08 0100F126 */  addiu      $s1, $s7, 0x1
  .L80017E0C:
    /* 860C 80017E0C 0000E392 */  lbu        $v1, 0x0($s7)
    /* 8610 80017E10 01000224 */  addiu      $v0, $zero, 0x1
    /* 8614 80017E14 09006210 */  beq        $v1, $v0, .L80017E3C
    /* 8618 80017E18 02006228 */   slti      $v0, $v1, 0x2
    /* 861C 80017E1C 3E004014 */  bnez       $v0, .L80017F18
    /* 8620 80017E20 02000224 */   addiu     $v0, $zero, 0x2
    /* 8624 80017E24 2C006210 */  beq        $v1, $v0, .L80017ED8
    /* 8628 80017E28 03000224 */   addiu     $v0, $zero, 0x3
    /* 862C 80017E2C 31006210 */  beq        $v1, $v0, .L80017EF4
    /* 8630 80017E30 FD01043C */   lui       $a0, (0x1FD0114 >> 16)
    /* 8634 80017E34 C75F0008 */  j          .L80017F1C
    /* 8638 80017E38 08003126 */   addiu     $s1, $s1, 0x8
  .L80017E3C:
    /* 863C 80017E3C FD01043C */  lui        $a0, (0x1FD0082 >> 16)
    /* 8640 80017E40 82008434 */  ori        $a0, $a0, (0x1FD0082 & 0xFFFF)
    /* 8644 80017E44 1C00BEA7 */  sh         $fp, 0x1C($sp)
    /* 8648 80017E48 688E000C */  jal        Cd_GetFileEntry
    /* 864C 80017E4C 1E00B5A7 */   sh        $s5, 0x1E($sp)
    /* 8650 80017E50 2120D302 */  addu       $a0, $s6, $s3
    /* 8654 80017E54 1000A527 */  addiu      $a1, $sp, 0x10
    /* 8658 80017E58 1C4D000C */  jal        Text_OpenDesc
    /* 865C 80017E5C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 8660 80017E60 FD01043C */  lui        $a0, (0x1FD00BB >> 16)
    /* 8664 80017E64 BB008434 */  ori        $a0, $a0, (0x1FD00BB & 0xFFFF)
    /* 8668 80017E68 D0000624 */  addiu      $a2, $zero, 0xD0
    /* 866C 80017E6C 1C00A6A7 */  sh         $a2, 0x1C($sp)
    /* 8670 80017E70 688E000C */  jal        Cd_GetFileEntry
    /* 8674 80017E74 1E00B5A7 */   sh        $s5, 0x1E($sp)
    /* 8678 80017E78 04006426 */  addiu      $a0, $s3, 0x4
    /* 867C 80017E7C 2120C402 */  addu       $a0, $s6, $a0
    /* 8680 80017E80 1000A527 */  addiu      $a1, $sp, 0x10
    /* 8684 80017E84 1C4D000C */  jal        Text_OpenDesc
    /* 8688 80017E88 1000A2AF */   sw        $v0, 0x10($sp)
    /* 868C 80017E8C 2120D402 */  addu       $a0, $s6, $s4
    /* 8690 80017E90 1C00BEA7 */  sh         $fp, 0x1C($sp)
    /* 8694 80017E94 1E00B0A7 */  sh         $s0, 0x1E($sp)
    /* 8698 80017E98 0300228E */  lw         $v0, 0x3($s1)
    /* 869C 80017E9C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 86A0 80017EA0 4C004224 */  addiu      $v0, $v0, 0x4C
    /* 86A4 80017EA4 1C4D000C */  jal        Text_OpenDesc
    /* 86A8 80017EA8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 86AC 80017EAC D0000624 */  addiu      $a2, $zero, 0xD0
    /* 86B0 80017EB0 1C00A6A7 */  sh         $a2, 0x1C($sp)
    /* 86B4 80017EB4 1E00B0A7 */  sh         $s0, 0x1E($sp)
    /* 86B8 80017EB8 0300228E */  lw         $v0, 0x3($s1)
    /* 86BC 80017EBC 00000000 */  nop
    /* 86C0 80017EC0 01004490 */  lbu        $a0, 0x1($v0)
    /* 86C4 80017EC4 D679000C */  jal        Digi_GetDefaultName
    /* 86C8 80017EC8 00000000 */   nop
    /* 86CC 80017ECC 0C006426 */  addiu      $a0, $s3, 0xC
    /* 86D0 80017ED0 C35F0008 */  j          .L80017F0C
    /* 86D4 80017ED4 2120C402 */   addu      $a0, $s6, $a0
  .L80017ED8:
    /* 86D8 80017ED8 FD01023C */  lui        $v0, (0x1FD00F5 >> 16)
    /* 86DC 80017EDC 1C00BEA7 */  sh         $fp, 0x1C($sp)
    /* 86E0 80017EE0 1E00B0A7 */  sh         $s0, 0x1E($sp)
    /* 86E4 80017EE4 00002492 */  lbu        $a0, 0x0($s1)
    /* 86E8 80017EE8 F5004234 */  ori        $v0, $v0, (0x1FD00F5 & 0xFFFF)
    /* 86EC 80017EEC C05F0008 */  j          .L80017F00
    /* 86F0 80017EF0 21208200 */   addu      $a0, $a0, $v0
  .L80017EF4:
    /* 86F4 80017EF4 14018434 */  ori        $a0, $a0, (0x1FD0114 & 0xFFFF)
    /* 86F8 80017EF8 1C00BEA7 */  sh         $fp, 0x1C($sp)
    /* 86FC 80017EFC 1E00B0A7 */  sh         $s0, 0x1E($sp)
  .L80017F00:
    /* 8700 80017F00 688E000C */  jal        Cd_GetFileEntry
    /* 8704 80017F04 00000000 */   nop
    /* 8708 80017F08 2120D402 */  addu       $a0, $s6, $s4
  .L80017F0C:
    /* 870C 80017F0C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 8710 80017F10 1C4D000C */  jal        Text_OpenDesc
    /* 8714 80017F14 1000A2AF */   sw        $v0, 0x10($sp)
  .L80017F18:
    /* 8718 80017F18 08003126 */  addiu      $s1, $s1, 0x8
  .L80017F1C:
    /* 871C 80017F1C 0800F726 */  addiu      $s7, $s7, 0x8
    /* 8720 80017F20 10009426 */  addiu      $s4, $s4, 0x10
    /* 8724 80017F24 10007326 */  addiu      $s3, $s3, 0x10
    /* 8728 80017F28 21001026 */  addiu      $s0, $s0, 0x21
    /* 872C 80017F2C 01005226 */  addiu      $s2, $s2, 0x1
    /* 8730 80017F30 0400422A */  slti       $v0, $s2, 0x4
    /* 8734 80017F34 B5FF4014 */  bnez       $v0, .L80017E0C
    /* 8738 80017F38 2100B526 */   addiu     $s5, $s5, 0x21
    /* 873C 80017F3C 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 8740 80017F40 4800BE8F */  lw         $fp, 0x48($sp)
    /* 8744 80017F44 4400B78F */  lw         $s7, 0x44($sp)
    /* 8748 80017F48 4000B68F */  lw         $s6, 0x40($sp)
    /* 874C 80017F4C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 8750 80017F50 3800B48F */  lw         $s4, 0x38($sp)
    /* 8754 80017F54 3400B38F */  lw         $s3, 0x34($sp)
    /* 8758 80017F58 3000B28F */  lw         $s2, 0x30($sp)
    /* 875C 80017F5C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 8760 80017F60 2800B08F */  lw         $s0, 0x28($sp)
    /* 8764 80017F64 0800E003 */  jr         $ra
    /* 8768 80017F68 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_80017D84
