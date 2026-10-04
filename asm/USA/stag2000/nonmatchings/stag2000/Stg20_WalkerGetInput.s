nonmatching Stg20_WalkerGetInput, 0x208

glabel Stg20_WalkerGetInput
    /* 77AC 8006AB0C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 77B0 8006AB10 1800B2AF */  sw         $s2, 0x18($sp)
    /* 77B4 8006AB14 21908000 */  addu       $s2, $a0, $zero
    /* 77B8 8006AB18 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 77BC 8006AB1C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 77C0 8006AB20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 77C4 8006AB24 0400428E */  lw         $v0, 0x4($s2)
    /* 77C8 8006AB28 2C00508E */  lw         $s0, 0x2C($s2)
    /* 77CC 8006AB2C 17004014 */  bnez       $v0, .L8006AB8C
    /* 77D0 8006AB30 0780023C */   lui       $v0, %hi(Stg20_TalkActive)
    /* 77D4 8006AB34 B409428C */  lw         $v0, %lo(Stg20_TalkActive)($v0)
    /* 77D8 8006AB38 00000000 */  nop
    /* 77DC 8006AB3C 13004014 */  bnez       $v0, .L8006AB8C
    /* 77E0 8006AB40 00000000 */   nop
    /* 77E4 8006AB44 0800448E */  lw         $a0, 0x8($s2)
    /* 77E8 8006AB48 00000000 */  nop
    /* 77EC 8006AB4C 03008010 */  beqz       $a0, .L8006AB5C
    /* 77F0 8006AB50 01000224 */   addiu     $v0, $zero, 0x1
    /* 77F4 8006AB54 07008210 */  beq        $a0, $v0, .L8006AB74
    /* 77F8 8006AB58 00000000 */   nop
  .L8006AB5C:
    /* 77FC 8006AB5C 0680023C */  lui        $v0, %hi(Pad_Held)
    /* 7800 8006AB60 28F74294 */  lhu        $v0, %lo(Pad_Held)($v0)
    /* 7804 8006AB64 00000000 */  nop
    /* 7808 8006AB68 280002AE */  sw         $v0, 0x28($s0)
    /* 780C 8006AB6C 3FAB0108 */  j          .L8006ACFC
    /* 7810 8006AB70 240002AE */   sw        $v0, 0x24($s0)
  .L8006AB74:
    /* 7814 8006AB74 2800028E */  lw         $v0, 0x28($s0)
    /* 7818 8006AB78 00000000 */  nop
    /* 781C 8006AB7C 00F04230 */  andi       $v0, $v0, 0xF000
    /* 7820 8006AB80 10004234 */  ori        $v0, $v0, 0x10
    /* 7824 8006AB84 3FAB0108 */  j          .L8006ACFC
    /* 7828 8006AB88 240002AE */   sw        $v0, 0x24($s0)
  .L8006AB8C:
    /* 782C 8006AB8C 08000286 */  lh         $v0, 0x8($s0)
    /* 7830 8006AB90 00000000 */  nop
    /* 7834 8006AB94 05004014 */  bnez       $v0, .L8006ABAC
    /* 7838 8006AB98 00000000 */   nop
    /* 783C 8006AB9C 7400028E */  lw         $v0, 0x74($s0)
    /* 7840 8006ABA0 00000000 */  nop
    /* 7844 8006ABA4 54004014 */  bnez       $v0, .L8006ACF8
    /* 7848 8006ABA8 00000000 */   nop
  .L8006ABAC:
    /* 784C 8006ABAC 5C00028E */  lw         $v0, 0x5C($s0)
    /* 7850 8006ABB0 00000000 */  nop
    /* 7854 8006ABB4 03004010 */  beqz       $v0, .L8006ABC4
    /* 7858 8006ABB8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 785C 8006ABBC 3FAB0108 */  j          .L8006ACFC
    /* 7860 8006ABC0 5C0002AE */   sw        $v0, 0x5C($s0)
  .L8006ABC4:
    /* 7864 8006ABC4 419D010C */  jal        Stg20_GetActorCell
    /* 7868 8006ABC8 21204002 */   addu      $a0, $s2, $zero
    /* 786C 8006ABCC 1800038E */  lw         $v1, 0x18($s0)
    /* 7870 8006ABD0 21884000 */  addu       $s1, $v0, $zero
    /* 7874 8006ABD4 80180300 */  sll        $v1, $v1, 2
    /* 7878 8006ABD8 21200302 */  addu       $a0, $s0, $v1
    /* 787C 8006ABDC 00002386 */  lh         $v1, 0x0($s1)
    /* 7880 8006ABE0 04008284 */  lh         $v0, 0x4($a0)
    /* 7884 8006ABE4 00000000 */  nop
    /* 7888 8006ABE8 29006214 */  bne        $v1, $v0, .L8006AC90
    /* 788C 8006ABEC 00000000 */   nop
    /* 7890 8006ABF0 02002386 */  lh         $v1, 0x2($s1)
    /* 7894 8006ABF4 06008284 */  lh         $v0, 0x6($a0)
    /* 7898 8006ABF8 00000000 */  nop
    /* 789C 8006ABFC 24006214 */  bne        $v1, $v0, .L8006AC90
    /* 78A0 8006AC00 00000000 */   nop
    /* 78A4 8006AC04 5A9D010C */  jal        Stg20_IsOnCellCenter
    /* 78A8 8006AC08 21204002 */   addu      $a0, $s2, $zero
    /* 78AC 8006AC0C 20004010 */  beqz       $v0, .L8006AC90
    /* 78B0 8006AC10 00000000 */   nop
    /* 78B4 8006AC14 1800028E */  lw         $v0, 0x18($s0)
    /* 78B8 8006AC18 00000000 */  nop
    /* 78BC 8006AC1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 78C0 8006AC20 180002AE */  sw         $v0, 0x18($s0)
    /* 78C4 8006AC24 80100200 */  sll        $v0, $v0, 2
    /* 78C8 8006AC28 21100202 */  addu       $v0, $s0, $v0
    /* 78CC 8006AC2C 04004384 */  lh         $v1, 0x4($v0)
    /* 78D0 8006AC30 00000000 */  nop
    /* 78D4 8006AC34 04006010 */  beqz       $v1, .L8006AC48
    /* 78D8 8006AC38 01000224 */   addiu     $v0, $zero, 0x1
    /* 78DC 8006AC3C 03006214 */  bne        $v1, $v0, .L8006AC4C
    /* 78E0 8006AC40 00000000 */   nop
    /* 78E4 8006AC44 740003AE */  sw         $v1, 0x74($s0)
  .L8006AC48:
    /* 78E8 8006AC48 180000AE */  sw         $zero, 0x18($s0)
  .L8006AC4C:
    /* 78EC 8006AC4C 448E000C */  jal        Rand_Next
    /* 78F0 8006AC50 00000000 */   nop
    /* 78F4 8006AC54 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 78F8 8006AC58 8888033C */  lui        $v1, (0x88888889 >> 16)
    /* 78FC 8006AC5C 89886334 */  ori        $v1, $v1, (0x88888889 & 0xFFFF)
    /* 7900 8006AC60 19004300 */  multu      $v0, $v1
    /* 7904 8006AC64 240000AE */  sw         $zero, 0x24($s0)
    /* 7908 8006AC68 10280000 */  mfhi       $a1
    /* 790C 8006AC6C 42210500 */  srl        $a0, $a1, 5
    /* 7910 8006AC70 00190400 */  sll        $v1, $a0, 4
    /* 7914 8006AC74 23186400 */  subu       $v1, $v1, $a0
    /* 7918 8006AC78 80180300 */  sll        $v1, $v1, 2
    /* 791C 8006AC7C 23104300 */  subu       $v0, $v0, $v1
    /* 7920 8006AC80 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 7924 8006AC84 0F004224 */  addiu      $v0, $v0, 0xF
    /* 7928 8006AC88 3FAB0108 */  j          .L8006ACFC
    /* 792C 8006AC8C 5C0002AE */   sw        $v0, 0x5C($s0)
  .L8006AC90:
    /* 7930 8006AC90 1800028E */  lw         $v0, 0x18($s0)
    /* 7934 8006AC94 00000000 */  nop
    /* 7938 8006AC98 80100200 */  sll        $v0, $v0, 2
    /* 793C 8006AC9C 04004224 */  addiu      $v0, $v0, 0x4
    /* 7940 8006ACA0 21200202 */  addu       $a0, $s0, $v0
    /* 7944 8006ACA4 02002286 */  lh         $v0, 0x2($s1)
    /* 7948 8006ACA8 02008384 */  lh         $v1, 0x2($a0)
    /* 794C 8006ACAC 00000000 */  nop
    /* 7950 8006ACB0 05004310 */  beq        $v0, $v1, .L8006ACC8
    /* 7954 8006ACB4 2A104300 */   slt       $v0, $v0, $v1
    /* 7958 8006ACB8 02004014 */  bnez       $v0, .L8006ACC4
    /* 795C 8006ACBC 00400224 */   addiu     $v0, $zero, 0x4000
    /* 7960 8006ACC0 00100224 */  addiu      $v0, $zero, 0x1000
  .L8006ACC4:
    /* 7964 8006ACC4 240002AE */  sw         $v0, 0x24($s0)
  .L8006ACC8:
    /* 7968 8006ACC8 00002286 */  lh         $v0, 0x0($s1)
    /* 796C 8006ACCC 00008384 */  lh         $v1, 0x0($a0)
    /* 7970 8006ACD0 00000000 */  nop
    /* 7974 8006ACD4 09004310 */  beq        $v0, $v1, .L8006ACFC
    /* 7978 8006ACD8 2A104300 */   slt       $v0, $v0, $v1
    /* 797C 8006ACDC 03004014 */  bnez       $v0, .L8006ACEC
    /* 7980 8006ACE0 00800234 */   ori       $v0, $zero, 0x8000
    /* 7984 8006ACE4 3FAB0108 */  j          .L8006ACFC
    /* 7988 8006ACE8 240002AE */   sw        $v0, 0x24($s0)
  .L8006ACEC:
    /* 798C 8006ACEC 00200224 */  addiu      $v0, $zero, 0x2000
    /* 7990 8006ACF0 3FAB0108 */  j          .L8006ACFC
    /* 7994 8006ACF4 240002AE */   sw        $v0, 0x24($s0)
  .L8006ACF8:
    /* 7998 8006ACF8 240000AE */  sw         $zero, 0x24($s0)
  .L8006ACFC:
    /* 799C 8006ACFC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 79A0 8006AD00 1800B28F */  lw         $s2, 0x18($sp)
    /* 79A4 8006AD04 1400B18F */  lw         $s1, 0x14($sp)
    /* 79A8 8006AD08 1000B08F */  lw         $s0, 0x10($sp)
    /* 79AC 8006AD0C 0800E003 */  jr         $ra
    /* 79B0 8006AD10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_WalkerGetInput
