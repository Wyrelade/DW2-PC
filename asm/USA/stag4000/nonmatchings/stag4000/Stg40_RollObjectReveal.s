nonmatching Stg40_RollObjectReveal, 0x19C

glabel Stg40_RollObjectReveal
    /* EA54 80071DB4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* EA58 80071DB8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* EA5C 80071DBC 0580133C */  lui        $s3, %hi(Dung_StatePtr)
    /* EA60 80071DC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* EA64 80071DC4 1C07718E */  lw         $s1, %lo(Dung_StatePtr)($s3)
    /* EA68 80071DC8 0D000424 */  addiu      $a0, $zero, 0xD
    /* EA6C 80071DCC 3000BFAF */  sw         $ra, 0x30($sp)
    /* EA70 80071DD0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* EA74 80071DD4 2800B6AF */  sw         $s6, 0x28($sp)
    /* EA78 80071DD8 2400B5AF */  sw         $s5, 0x24($sp)
    /* EA7C 80071DDC 2000B4AF */  sw         $s4, 0x20($sp)
    /* EA80 80071DE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* EA84 80071DE4 16BA010C */  jal        Stg40_GetPartLevel
    /* EA88 80071DE8 1000B0AF */   sw        $s0, 0x10($sp)
    /* EA8C 80071DEC 21804000 */  addu       $s0, $v0, $zero
    /* EA90 80071DF0 03000106 */  bgez       $s0, .L80071E00
    /* EA94 80071DF4 18003226 */   addiu     $s2, $s1, 0x18
    /* EA98 80071DF8 21100000 */  addu       $v0, $zero, $zero
    /* EA9C 80071DFC 21804000 */  addu       $s0, $v0, $zero
  .L80071E00:
    /* EAA0 80071E00 16BA010C */  jal        Stg40_GetPartLevel
    /* EAA4 80071E04 0E000424 */   addiu     $a0, $zero, 0xE
    /* EAA8 80071E08 21A04000 */  addu       $s4, $v0, $zero
    /* EAAC 80071E0C 02008106 */  bgez       $s4, .L80071E18
    /* EAB0 80071E10 21188002 */   addu      $v1, $s4, $zero
    /* EAB4 80071E14 21180000 */  addu       $v1, $zero, $zero
  .L80071E18:
    /* EAB8 80071E18 1C07628E */  lw         $v0, %lo(Dung_StatePtr)($s3)
    /* EABC 80071E1C 21A06000 */  addu       $s4, $v1, $zero
    /* EAC0 80071E20 0C004284 */  lh         $v0, 0xC($v0)
    /* EAC4 80071E24 00000000 */  nop
    /* EAC8 80071E28 3E004018 */  blez       $v0, .L80071F24
    /* EACC 80071E2C 21980000 */   addu      $s3, $zero, $zero
    /* EAD0 80071E30 0780023C */  lui        $v0, %hi(Stg40_HazardRevealChance)
    /* EAD4 80071E34 582A5724 */  addiu      $s7, $v0, %lo(Stg40_HazardRevealChance)
    /* EAD8 80071E38 80101000 */  sll        $v0, $s0, 2
    /* EADC 80071E3C 21105000 */  addu       $v0, $v0, $s0
    /* EAE0 80071E40 FFFF5524 */  addiu      $s5, $v0, -0x1
    /* EAE4 80071E44 0780023C */  lui        $v0, %hi(Stg40_BugNestRevealChance)
    /* EAE8 80071E48 782A5624 */  addiu      $s6, $v0, %lo(Stg40_BugNestRevealChance)
    /* EAEC 80071E4C 28003126 */  addiu      $s1, $s1, 0x28
  .L80071E50:
    /* EAF0 80071E50 0000428E */  lw         $v0, 0x0($s2)
    /* EAF4 80071E54 00000000 */  nop
    /* EAF8 80071E58 00804230 */  andi       $v0, $v0, 0x8000
    /* EAFC 80071E5C 28004010 */  beqz       $v0, .L80071F00
    /* EB00 80071E60 08000224 */   addiu     $v0, $zero, 0x8
    /* EB04 80071E64 F8FF2392 */  lbu        $v1, -0x8($s1)
    /* EB08 80071E68 00000000 */  nop
    /* EB0C 80071E6C 0D006210 */  beq        $v1, $v0, .L80071EA4
    /* EB10 80071E70 00000000 */   nop
    /* EB14 80071E74 09006228 */  slti       $v0, $v1, 0x9
    /* EB18 80071E78 05004010 */  beqz       $v0, .L80071E90
    /* EB1C 80071E7C 06000224 */   addiu     $v0, $zero, 0x6
    /* EB20 80071E80 08006210 */  beq        $v1, $v0, .L80071EA4
    /* EB24 80071E84 00000000 */   nop
    /* EB28 80071E88 C1C70108 */  j          .L80071F04
    /* EB2C 80071E8C 48003126 */   addiu     $s1, $s1, 0x48
  .L80071E90:
    /* EB30 80071E90 0D006228 */  slti       $v0, $v1, 0xD
    /* EB34 80071E94 1A004010 */  beqz       $v0, .L80071F00
    /* EB38 80071E98 40181400 */   sll       $v1, $s4, 1
    /* EB3C 80071E9C B0C70108 */  j          .L80071EC0
    /* EB40 80071EA0 21187400 */   addu      $v1, $v1, $s4
  .L80071EA4:
    /* EB44 80071EA4 0000228E */  lw         $v0, 0x0($s1)
    /* EB48 80071EA8 00000000 */  nop
    /* EB4C 80071EAC 01004290 */  lbu        $v0, 0x1($v0)
    /* EB50 80071EB0 00000000 */  nop
    /* EB54 80071EB4 21105500 */  addu       $v0, $v0, $s5
    /* EB58 80071EB8 B6C70108 */  j          .L80071ED8
    /* EB5C 80071EBC 21105700 */   addu      $v0, $v0, $s7
  .L80071EC0:
    /* EB60 80071EC0 0000228E */  lw         $v0, 0x0($s1)
    /* EB64 80071EC4 00000000 */  nop
    /* EB68 80071EC8 01004290 */  lbu        $v0, 0x1($v0)
    /* EB6C 80071ECC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* EB70 80071ED0 21104300 */  addu       $v0, $v0, $v1
    /* EB74 80071ED4 21105600 */  addu       $v0, $v0, $s6
  .L80071ED8:
    /* EB78 80071ED8 00005090 */  lbu        $s0, 0x0($v0)
    /* EB7C 80071EDC 60C4010C */  jal        Stg40_RandPercent
    /* EB80 80071EE0 00000000 */   nop
    /* EB84 80071EE4 2A105000 */  slt        $v0, $v0, $s0
    /* EB88 80071EE8 05004010 */  beqz       $v0, .L80071F00
    /* EB8C 80071EEC 00000000 */   nop
    /* EB90 80071EF0 0000428E */  lw         $v0, 0x0($s2)
    /* EB94 80071EF4 00000000 */  nop
    /* EB98 80071EF8 00104234 */  ori        $v0, $v0, 0x1000
    /* EB9C 80071EFC 000042AE */  sw         $v0, 0x0($s2)
  .L80071F00:
    /* EBA0 80071F00 48003126 */  addiu      $s1, $s1, 0x48
  .L80071F04:
    /* EBA4 80071F04 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* EBA8 80071F08 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* EBAC 80071F0C 00000000 */  nop
    /* EBB0 80071F10 0C004284 */  lh         $v0, 0xC($v0)
    /* EBB4 80071F14 01007326 */  addiu      $s3, $s3, 0x1
    /* EBB8 80071F18 2A106202 */  slt        $v0, $s3, $v0
    /* EBBC 80071F1C CCFF4014 */  bnez       $v0, .L80071E50
    /* EBC0 80071F20 48005226 */   addiu     $s2, $s2, 0x48
  .L80071F24:
    /* EBC4 80071F24 3000BF8F */  lw         $ra, 0x30($sp)
    /* EBC8 80071F28 2C00B78F */  lw         $s7, 0x2C($sp)
    /* EBCC 80071F2C 2800B68F */  lw         $s6, 0x28($sp)
    /* EBD0 80071F30 2400B58F */  lw         $s5, 0x24($sp)
    /* EBD4 80071F34 2000B48F */  lw         $s4, 0x20($sp)
    /* EBD8 80071F38 1C00B38F */  lw         $s3, 0x1C($sp)
    /* EBDC 80071F3C 1800B28F */  lw         $s2, 0x18($sp)
    /* EBE0 80071F40 1400B18F */  lw         $s1, 0x14($sp)
    /* EBE4 80071F44 1000B08F */  lw         $s0, 0x10($sp)
    /* EBE8 80071F48 0800E003 */  jr         $ra
    /* EBEC 80071F4C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg40_RollObjectReveal
