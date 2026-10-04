nonmatching func_80071DC4, 0x1D8

glabel func_80071DC4
    /* EA64 80071DC4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* EA68 80071DC8 3800BEAF */  sw         $fp, 0x38($sp)
    /* EA6C 80071DCC 21F00000 */  addu       $fp, $zero, $zero
    /* EA70 80071DD0 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* EA74 80071DD4 3400B7AF */  sw         $s7, 0x34($sp)
    /* EA78 80071DD8 3000B6AF */  sw         $s6, 0x30($sp)
    /* EA7C 80071DDC 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* EA80 80071DE0 2800B4AF */  sw         $s4, 0x28($sp)
    /* EA84 80071DE4 2400B3AF */  sw         $s3, 0x24($sp)
    /* EA88 80071DE8 2000B2AF */  sw         $s2, 0x20($sp)
    /* EA8C 80071DEC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* EA90 80071DF0 1800B0AF */  sw         $s0, 0x18($sp)
    /* EA94 80071DF4 1000A0AF */  sw         $zero, 0x10($sp)
    /* EA98 80071DF8 2C00938C */  lw         $s3, 0x2C($a0)
    /* EA9C 80071DFC 21A8C003 */  addu       $s5, $fp, $zero
    /* EAA0 80071E00 21A06002 */  addu       $s4, $s3, $zero
  .L80071E04:
    /* EAA4 80071E04 21880000 */  addu       $s1, $zero, $zero
    /* EAA8 80071E08 21B8A002 */  addu       $s7, $s5, $zero
    /* EAAC 80071E0C B000888E */  lw         $t0, 0xB0($s4)
    /* EAB0 80071E10 21B0C003 */  addu       $s6, $fp, $zero
    /* EAB4 80071E14 1400A8AF */  sw         $t0, 0x14($sp)
    /* EAB8 80071E18 2190F102 */  addu       $s2, $s7, $s1
  .L80071E1C:
    /* EABC 80071E1C 80101200 */  sll        $v0, $s2, 2
    /* EAC0 80071E20 14004224 */  addiu      $v0, $v0, 0x14
    /* EAC4 80071E24 21806202 */  addu       $s0, $s3, $v0
    /* EAC8 80071E28 E26E000C */  jal        Text_Close
    /* EACC 80071E2C 21200002 */   addu      $a0, $s0, $zero
    /* EAD0 80071E30 1400A88F */  lw         $t0, 0x14($sp)
    /* EAD4 80071E34 00000000 */  nop
    /* EAD8 80071E38 21102802 */  addu       $v0, $s1, $t0
    /* EADC 80071E3C 40100200 */  sll        $v0, $v0, 1
    /* EAE0 80071E40 21105600 */  addu       $v0, $v0, $s6
    /* EAE4 80071E44 21106202 */  addu       $v0, $s3, $v0
    /* EAE8 80071E48 74004484 */  lh         $a0, 0x74($v0)
    /* EAEC 80071E4C 00000000 */  nop
    /* EAF0 80071E50 10008010 */  beqz       $a0, .L80071E94
    /* EAF4 80071E54 00000000 */   nop
    /* EAF8 80071E58 617B000C */  jal        Skill_GetNameText
    /* EAFC 80071E5C 00000000 */   nop
    /* EB00 80071E60 21200002 */  addu       $a0, $s0, $zero
    /* EB04 80071E64 21284000 */  addu       $a1, $v0, $zero
    /* EB08 80071E68 21300000 */  addu       $a2, $zero, $zero
    /* EB0C 80071E6C 04004226 */  addiu      $v0, $s2, 0x4
    /* EB10 80071E70 80100200 */  sll        $v0, $v0, 2
    /* EB14 80071E74 0780083C */  lui        $t0, %hi(D_80073730)
    /* EB18 80071E78 30370825 */  addiu      $t0, $t0, %lo(D_80073730)
    /* EB1C 80071E7C 21104800 */  addu       $v0, $v0, $t0
    /* EB20 80071E80 02004794 */  lhu        $a3, 0x2($v0)
    /* EB24 80071E84 00004294 */  lhu        $v0, 0x0($v0)
    /* EB28 80071E88 003C0700 */  sll        $a3, $a3, 16
    /* EB2C 80071E8C 3E4D000C */  jal        Text_OpenPacked
    /* EB30 80071E90 25384700 */   or        $a3, $v0, $a3
  .L80071E94:
    /* EB34 80071E94 01003126 */  addiu      $s1, $s1, 0x1
    /* EB38 80071E98 0A00222A */  slti       $v0, $s1, 0xA
    /* EB3C 80071E9C DFFF4014 */  bnez       $v0, .L80071E1C
    /* EB40 80071EA0 2190F102 */   addu      $s2, $s7, $s1
    /* EB44 80071EA4 1800DE27 */  addiu      $fp, $fp, 0x18
    /* EB48 80071EA8 0A00B526 */  addiu      $s5, $s5, 0xA
    /* EB4C 80071EAC 1000A88F */  lw         $t0, 0x10($sp)
    /* EB50 80071EB0 04009426 */  addiu      $s4, $s4, 0x4
    /* EB54 80071EB4 01000825 */  addiu      $t0, $t0, 0x1
    /* EB58 80071EB8 02000229 */  slti       $v0, $t0, 0x2
    /* EB5C 80071EBC D1FF4014 */  bnez       $v0, .L80071E04
    /* EB60 80071EC0 1000A8AF */   sw        $t0, 0x10($sp)
    /* EB64 80071EC4 70007126 */  addiu      $s1, $s3, 0x70
    /* EB68 80071EC8 E26E000C */  jal        Text_Close
    /* EB6C 80071ECC 21202002 */   addu      $a0, $s1, $zero
    /* EB70 80071ED0 A400648E */  lw         $a0, 0xA4($s3)
    /* EB74 80071ED4 00000000 */  nop
    /* EB78 80071ED8 80100400 */  sll        $v0, $a0, 2
    /* EB7C 80071EDC 21106202 */  addu       $v0, $s3, $v0
    /* EB80 80071EE0 B000438C */  lw         $v1, 0xB0($v0)
    /* EB84 80071EE4 A800428C */  lw         $v0, 0xA8($v0)
    /* EB88 80071EE8 00000000 */  nop
    /* EB8C 80071EEC 21186200 */  addu       $v1, $v1, $v0
    /* EB90 80071EF0 40180300 */  sll        $v1, $v1, 1
    /* EB94 80071EF4 40100400 */  sll        $v0, $a0, 1
    /* EB98 80071EF8 21104400 */  addu       $v0, $v0, $a0
    /* EB9C 80071EFC C0100200 */  sll        $v0, $v0, 3
    /* EBA0 80071F00 21186200 */  addu       $v1, $v1, $v0
    /* EBA4 80071F04 21186302 */  addu       $v1, $s3, $v1
    /* EBA8 80071F08 74007084 */  lh         $s0, 0x74($v1)
    /* EBAC 80071F0C 00000000 */  nop
    /* EBB0 80071F10 15000012 */  beqz       $s0, .L80071F68
    /* EBB4 80071F14 00000000 */   nop
    /* EBB8 80071F18 C800628E */  lw         $v0, 0xC8($s3)
    /* EBBC 80071F1C 00000000 */  nop
    /* EBC0 80071F20 11004014 */  bnez       $v0, .L80071F68
    /* EBC4 80071F24 00000000 */   nop
    /* EBC8 80071F28 757B000C */  jal        Skill_GetDescText
    /* EBCC 80071F2C 21200002 */   addu      $a0, $s0, $zero
    /* EBD0 80071F30 21202002 */  addu       $a0, $s1, $zero
    /* EBD4 80071F34 21284000 */  addu       $a1, $v0, $zero
    /* EBD8 80071F38 21300000 */  addu       $a2, $zero, $zero
    /* EBDC 80071F3C 0780023C */  lui        $v0, %hi(D_80073730)
    /* EBE0 80071F40 30374224 */  addiu      $v0, $v0, %lo(D_80073730)
    /* EBE4 80071F44 6E004794 */  lhu        $a3, 0x6E($v0)
    /* EBE8 80071F48 6C004294 */  lhu        $v0, 0x6C($v0)
    /* EBEC 80071F4C 003C0700 */  sll        $a3, $a3, 16
    /* EBF0 80071F50 3E4D000C */  jal        Text_OpenPacked
    /* EBF4 80071F54 25384700 */   or        $a3, $v0, $a3
    /* EBF8 80071F58 A07B000C */  jal        Skill_GetMpCost
    /* EBFC 80071F5C 21200002 */   addu      $a0, $s0, $zero
    /* EC00 80071F60 DBC70108 */  j          .L80071F6C
    /* EC04 80071F64 C00062AE */   sw        $v0, 0xC0($s3)
  .L80071F68:
    /* EC08 80071F68 C00060AE */  sw         $zero, 0xC0($s3)
  .L80071F6C:
    /* EC0C 80071F6C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* EC10 80071F70 3800BE8F */  lw         $fp, 0x38($sp)
    /* EC14 80071F74 3400B78F */  lw         $s7, 0x34($sp)
    /* EC18 80071F78 3000B68F */  lw         $s6, 0x30($sp)
    /* EC1C 80071F7C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* EC20 80071F80 2800B48F */  lw         $s4, 0x28($sp)
    /* EC24 80071F84 2400B38F */  lw         $s3, 0x24($sp)
    /* EC28 80071F88 2000B28F */  lw         $s2, 0x20($sp)
    /* EC2C 80071F8C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* EC30 80071F90 1800B08F */  lw         $s0, 0x18($sp)
    /* EC34 80071F94 0800E003 */  jr         $ra
    /* EC38 80071F98 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80071DC4
